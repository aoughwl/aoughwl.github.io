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
typedef struct Proc_0_chu5m1rja1 Proc_0_chu5m1rja1;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct MagicSpec_0_chu5m1rja1 MagicSpec_0_chu5m1rja1;
typedef struct ConvSpec_0_chu5m1rja1 ConvSpec_0_chu5m1rja1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct GatedCall_0_chu5m1rja1 GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1 ObjInfo_0_chu5m1rja1;
typedef struct ObjSpec_0_chu5m1rja1 ObjSpec_0_chu5m1rja1;
typedef struct MethodSite_0_chu5m1rja1 MethodSite_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1 MethodEntry_0_chu5m1rja1;
typedef struct Instr_0_chu5m1rja1 Instr_0_chu5m1rja1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct GlobalSeed_0_chu5m1rja1 GlobalSeed_0_chu5m1rja1;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001 X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001;
typedef struct X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6 X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct Handler_0_vmtuaxp6 Handler_0_vmtuaxp6;
typedef struct Pending_0_vmtuaxp6 Pending_0_vmtuaxp6;
typedef struct MethodIndexEntry_0_sempjk6bn1 MethodIndexEntry_0_sempjk6bn1;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_I50urnw_chu5m1rja1 seq_0_I50urnw_chu5m1rja1;
typedef struct CallEvent_0_trakthy001 CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001 EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001 BranchEvent_0_trakthy001;
typedef struct Step_0_trakthy001 Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct VmCoro_Obj_0_vmtuaxp6 VmCoro_Obj_0_vmtuaxp6;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
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
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
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
typedef struct seq_0_Ir067xu1_chu5m1rja1{
  NI32 len_0;
  MethodSite_0_chu5m1rja1* data_0;}
seq_0_Ir067xu1_chu5m1rja1;
typedef struct seq_0_I88k8j01_chu5m1rja1{
  NI32 len_0;
  MethodEntry_0_chu5m1rja1* data_0;}
seq_0_I88k8j01_chu5m1rja1;
typedef struct seq_0_Izok7jt1_chu5m1rja1{
  NI32 len_0;
  Instr_0_chu5m1rja1* data_0;}
seq_0_Izok7jt1_chu5m1rja1;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct seq_0_Iioxqbu_chu5m1rja1{
  NI32 len_0;
  GlobalSeed_0_chu5m1rja1* data_0;}
seq_0_Iioxqbu_chu5m1rja1;
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
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
typedef struct seq_0_Iflf8jf1_fiepkwzpc{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_fiepkwzpc;
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
typedef struct VM_Obj_0_vmtuaxp6{
  VmProgram_0_chu5m1rja1 prog_0;
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0;
  seq_0_Iw8xl5b1_flaksyopx1 globals_0;
  seq_0_Ixdx2fh1_ast8ri79k unboundImportc_0;
  seq_0_Ixdx2fh1_ast8ri79k unboundImportcNim_0;
  seq_0_Iflf8jf1_fiepkwzpc globalInited_0;
  NB8 raised_0;
  Value_0_valzr1t4f excVal_0;
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* trace_0;
  NB8 poolStoppedFlag_0;
  NI32 keepOvf_0;
  NB8 overflowFlag_0;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* curCoro_0;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* pendingChild_0;
  NI32 coroStep_0;
  Value_0_valzr1t4f scheduler_0;}
VM_Obj_0_vmtuaxp6;
typedef struct Handler_0_vmtuaxp6{
  NI32 catchIp_0;
  NI32 finallyIp_0;
  NI32 sp_0;}
Handler_0_vmtuaxp6;
typedef struct Pending_0_vmtuaxp6{
  NI32 kind_0;
  Value_0_valzr1t4f val_0;}
Pending_0_vmtuaxp6;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct seq_0_Ifq4s5b1_vmtuaxp6{
  NI32 len_0;
  Handler_0_vmtuaxp6* data_0;}
seq_0_Ifq4s5b1_vmtuaxp6;
typedef struct seq_0_I32zqoq1_vmtuaxp6{
  NI32 len_0;
  Pending_0_vmtuaxp6* data_0;}
seq_0_I32zqoq1_vmtuaxp6;
typedef struct VmCoro_Obj_0_vmtuaxp6{
  CoroRef_Obj_0_valzr1t4f Q;
  seq_0_Izok7jt1_chu5m1rja1 code_0;
  seq_0_Ift2sne_chu5m1rja1 lines_0;
  seq_0_Iw8xl5b1_flaksyopx1 locals_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* myEnvCell_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* destCell_0;
  Value_0_valzr1t4f stepFn_0;
  Value_0_valzr1t4f itVal_0;
  seq_0_In6doa_ast8ri79k slotSyms_0;
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_0;
  seq_0_I50urnw_chu5m1rja1 stack_0;
  seq_0_Ifq4s5b1_vmtuaxp6 handlers_0;
  seq_0_I32zqoq1_vmtuaxp6 pendings_0;
  NI32 ip_0;
  NB8 started_0;
  NB8 done_0;
  NB8 suspended_0;
  Value_0_valzr1t4f lastVal_0;
  NB8 isPassive_0;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* caller_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* retCell_0;
  Value_0_valzr1t4f retVal_0;
  NB8 awaitingPark_0;
  NB8 parked_0;
  NB8 finished_0;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* retToCoro_0;
  NI32 retToIdx_0;}
VmCoro_Obj_0_vmtuaxp6;
typedef struct openArray_0_In1h8lr1_comaa5xpt1{
  MethodIndexEntry_0_sempjk6bn1* a_0;
  NI32 len_0;}
openArray_0_In1h8lr1_comaa5xpt1;
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
typedef struct seq_0_Idl3iy1_comaa5xpt1{
  NI32 len_0;
  MethodIndexEntry_0_sempjk6bn1* data_0;}
seq_0_Idl3iy1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6{
  NI r_00;
  VM_Obj_0_vmtuaxp6 d_00;}
X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_chu5m1rja1, NB8*);
typedef struct OutSink_Obj_0_natd5co251{
  string_0_sysvq0asl outBuf_0;
  string_0_sysvq0asl errBuf_0;
  NI32 exitCode_0;
  NB8 didQQuit_0;
  string_0_sysvq0asl inBuf_0;
  NI32 inPos_0;
  NB8 inLoaded_0;
  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251 inLoad_0;
  string_0_sysvq0asl progName_0;
  seq_0_Ixdx2fh1_ast8ri79k argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_ast8ri79k envKeys_0;
  seq_0_Ixdx2fh1_ast8ri79k envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_ast8ri79k failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;}
OutSink_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef NU8 TraceMode_0_trakthy001;

#define tmOff_0_trakthy001 ((NU8)0)
#define tmCalls_0_trakthy001 ((NU8)1)
#define tmFull_0_trakthy001 ((NU8)2)
#define tmProfile_0_trakthy001 ((NU8)3)
typedef struct seq_0_I00yatg_trakthy001{
  NI32 len_0;
  CallEvent_0_trakthy001* data_0;}
seq_0_I00yatg_trakthy001;
typedef struct seq_0_Ins76rj1_trakthy001{
  NI32 len_0;
  EvalEvent_0_trakthy001* data_0;}
seq_0_Ins76rj1_trakthy001;
typedef struct seq_0_Iuignwf1_trakthy001{
  NI32 len_0;
  BranchEvent_0_trakthy001* data_0;}
seq_0_Iuignwf1_trakthy001;
typedef struct seq_0_Is6l9yr_trakthy001{
  NI32 len_0;
  Step_0_trakthy001* data_0;}
seq_0_Is6l9yr_trakthy001;
typedef struct seq_0_Ix7ee6h_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* data_0;}
seq_0_Ix7ee6h_sempjk6bn1;
typedef struct seq_0_Ikxuplm1_filqx2b6r1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_filqx2b6r1;
typedef struct Table_0_Idzlvr_sempjk6bn1{
  seq_0_Ix7ee6h_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Idzlvr_sempjk6bn1;
typedef struct Trace_Obj_0_trakthy001{
  TraceMode_0_trakthy001 mode_0;
  NI32 depth_0;
  string_0_sysvq0asl text_0;
  seq_0_I00yatg_trakthy001 calls_0;
  seq_0_Ins76rj1_trakthy001 evals_0;
  seq_0_Iuignwf1_trakthy001 branches_0;
  seq_0_Is6l9yr_trakthy001 steps_0;
  NI32 nCalls_0;
  NI32 maxDepth_0;
  NB8 truncated_0;
  NI32 lines_0;
  seq_0_Ift2sne_chu5m1rja1 frames_0;
  Table_0_Idzlvr_sempjk6bn1 prof_0;
  NI32 maxRecordDepth_0;
  seq_0_Iflf8jf1_fiepkwzpc recStack_0;}
Trace_Obj_0_trakthy001;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001{
  NI r_00;
  Trace_Obj_0_trakthy001 d_00;}
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001;
typedef struct X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6{
  NI r_00;
  VmCoro_Obj_0_vmtuaxp6 d_00;}
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6;
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
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
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k names_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1{
  Value_0_valzr1t4f fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
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
typedef struct X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S2_vmtuaxp6{
  NU32 a[2];}
X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S2_vmtuaxp6;
typedef struct X60Qt_0_IAarrayArefSX43ellX4fbj0valzr1t4fZS2_vmtuaxp6{
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* a[2];}
X60Qt_0_IAarrayArefSX43ellX4fbj0valzr1t4fZS2_vmtuaxp6;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6{
  Value_0_valzr1t4f a[1];}
X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6;
typedef struct X60Qt_0_IAarrayAuS8ZS3_aow2h993l1{
  NU8 a[3];}
X60Qt_0_IAarrayAuS8ZS3_aow2h993l1;
typedef struct X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1{
  NB8 fld_0;
  Value_0_valzr1t4f fld_1;}
X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX56mX43oroX4fbj0vmtuaxp6SEAnimcallZAfalseZAR36_vmtuaxp6)(VmCoro_Obj_0_vmtuaxp6*);
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct ConvSpec_0_chu5m1rja1{
  NI32 mode_0;
  NI32 bits_0;
  NB8 signed_0;
  TCode_0_valzr1t4f code_0;
  NU32 etype_0;}
ConvSpec_0_chu5m1rja1;
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
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
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
  BiTable_0_Ieutpr21_nifh7u8pu1 files_0;
  BiTable_0_I0ksat5_ast8ri79k syms_0;
  BiTable_0_Ipgo74p_ast8ri79k strings_0;
  BiTable_0_Itvq7bk_ast8ri79k integers_0;
  BiTable_0_Itxao711_ast8ri79k uintegers_0;
  BiTable_0_Iojfwmy1_ast8ri79k floats_0;}
Literals_0_nifh7u8pu1;
typedef struct MethodSite_0_chu5m1rja1{
  NU32 staticFn_0;
  NI32 fallbackIdx_0;}
MethodSite_0_chu5m1rja1;
typedef struct MethodIndexEntry_0_sempjk6bn1{
  NU32 fn_0;
  NU32 signature_0;}
MethodIndexEntry_0_sempjk6bn1;
typedef struct MethodEntry_0_chu5m1rja1{
  NU32 sym_0;
  NI32 idx_0;}
MethodEntry_0_chu5m1rja1;
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
typedef struct GatedCall_0_chu5m1rja1{
  NI32 nat_0;
  NI32 fallback_0;
  NB8 dollarScalar_0;}
GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;}
ObjInfo_0_chu5m1rja1;
typedef struct ObjSpec_0_chu5m1rja1{
  NU32 typeSym_0;
  NB8 isRef_0;
  seq_0_In6doa_ast8ri79k fields_0;}
ObjSpec_0_chu5m1rja1;
typedef struct GlobalSeed_0_chu5m1rja1{
  NI32 slot_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl cname_0;
  Value_0_valzr1t4f v_0;}
GlobalSeed_0_chu5m1rja1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct PipeBuf_Obj_0_natd5co251{
  string_0_sysvq0asl data_0;
  NI32 rpos_0;
  NI32 writeFd_0;
  NB8 writeClosed_0;}
PipeBuf_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11{
  NI r_00;
  PipeBuf_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct CallEvent_0_trakthy001{
  string_0_sysvq0asl callee_0;
  seq_0_I50urnw_chu5m1rja1 args_0;
  seq_0_Ixdx2fh1_ast8ri79k argsR_0;
  Value_0_valzr1t4f ret_0;
  string_0_sysvq0asl retR_0;
  NI32 depth_0;
  NI32 line_0;
  string_0_sysvq0asl file_0;}
CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001{
  string_0_sysvq0asl code_0;
  NI32 line_0;
  NI32 col_0;
  Value_0_valzr1t4f val_0;}
EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001{
  string_0_sysvq0asl form_0;
  string_0_sysvq0asl sel_0;
  string_0_sysvq0asl chose_0;
  string_0_sysvq0asl callee_0;
  NI32 line_0;
  NI32 depth_0;}
BranchEvent_0_trakthy001;
typedef NU8 StepKind_0_trakthy001;

#define skEnter_0_trakthy001 ((NU8)0)
#define skExit_0_trakthy001 ((NU8)1)
#define skBranch_0_trakthy001 ((NU8)2)
typedef struct Step_0_trakthy001{
  StepKind_0_trakthy001 kind_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl site_0;}
Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
Value_0_valzr1t4f contFieldVm_1_vmtuaxp6(Value_0_valzr1t4f* v_6, string_0_sysvq0asl name_4);
void drivePoolContVm_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_13, Value_0_valzr1t4f* cont_1);
string_0_sysvq0asl mBaseName_1_vmtuaxp6(NU32 s_3);
Value_0_valzr1t4f runProc_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_16, NI32 procIdx_1, seq_0_I50urnw_chu5m1rja1 args_4, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_7);
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* makeCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_17, NI32 pidx_2, seq_0_I50urnw_chu5m1rja1 args_5, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_8);
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 resumeCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_18, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* coro_3);
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* makePassiveCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_19, NI32 pidx_3, seq_0_I50urnw_chu5m1rja1 args_6, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_9);
void drivePassiveVm_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_21, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* start_1);
void setLen_0_I8wiqgg_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_66, NI32 newLen_3);
seq_0_In6doa_ast8ri79k atQ_0_Il22x2g_vmtuaxp6(X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S2_vmtuaxp6 a_12);
seq_0_Iw8xl5b1_flaksyopx1 atQ_0_Ikzen43_vmtuaxp6(X60Qt_0_IAarrayArefSX43ellX4fbj0valzr1t4fZS2_vmtuaxp6 a_13);
seq_0_I50urnw_chu5m1rja1 atQ_0_I4e31uy1_vmtuaxp6(X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6* a_14);
static inline NI32 len_3_Ikc9pid1_vmtuaxp6(seq_0_Idl3iy1_comaa5xpt1 s_80);
static inline MethodIndexEntry_0_sempjk6bn1* getQ_7_I7nrp45_vmtuaxp6(seq_0_Idl3iy1_comaa5xpt1 s_81, NI32 i_56);
static inline seq_0_Ifq4s5b1_vmtuaxp6 newSeqUninit_0_Ipt20ij1_vmtuaxp6(NI32 size_13);
static inline seq_0_I32zqoq1_vmtuaxp6 newSeqUninit_0_Im62ogf1_vmtuaxp6(NI32 size_15);
static inline NI32 len_3_I4ido3x_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_86);
static inline Handler_0_vmtuaxp6* getQ_7_I4z6e5u1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_87, NI32 i_58);
void setLen_0_I80tc5k_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_88, NI32 newLen_7);
static inline void add_0_Igw9l8t1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_91, Pending_0_vmtuaxp6 elem_15);
static inline MagicSpec_0_chu5m1rja1* getQ_7_Io8qdfc_vmtuaxp6(seq_0_Ie9rikd_chu5m1rja1 s_102, NI32 i_66);
static inline ConvSpec_0_chu5m1rja1* getQ_7_Ij8ai9r_vmtuaxp6(seq_0_Iknt7a3_chu5m1rja1 s_103, NI32 i_67);
static inline Proc_0_chu5m1rja1* getQ_7_I7rdp401_vmtuaxp6(seq_0_Inaua171_chu5m1rja1 s_104, NI32 i_68);
static inline MethodSite_0_chu5m1rja1* getQ_7_Ig0gjeo1_vmtuaxp6(seq_0_Ir067xu1_chu5m1rja1 s_105, NI32 i_69);
static inline GatedCall_0_chu5m1rja1* getQ_7_Ij0vr9r_vmtuaxp6(seq_0_Id5h4uf_chu5m1rja1 s_106, NI32 i_70);
static inline ObjInfo_0_chu5m1rja1* getQ_7_Ia248tr_vmtuaxp6(seq_0_I2neof81_chu5m1rja1 s_108, NI32 i_72);
static inline void inc_1_Irn1g7r1_vmtuaxp6(NI64* x_11);
static inline ObjSpec_0_chu5m1rja1* getQ_7_I7ms12l_vmtuaxp6(seq_0_Isww99s_chu5m1rja1 s_109, NI32 i_73);
static inline void add_0_Iwiwppi1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_110, Handler_0_vmtuaxp6 elem_19);
static inline NI32 len_3_I98fzqt_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_112);
static inline Pending_0_vmtuaxp6* getQ_7_Iqkk0ey1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_113, NI32 i_74);
void setLen_0_Iibupod1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_114, NI32 newLen_10);
void shrink_0_Iphcl5v1_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_125, NI32 newLen_13);
void growUnsafe_0_Ifrz0b21_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_126, NI32 newLen_14);
static inline NI32 memSizeInBytes_0_I52ofsr1_vmtuaxp6(NI32 size_24);
static inline NI32 memSizeInBytes_0_I4b0tmb1_vmtuaxp6(NI32 size_25);
void shrink_0_Iwq7tiu_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_138, NI32 newLen_19);
void growUnsafe_0_Ias0bor1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_139, NI32 newLen_20);
static inline NI32 capInBytes_0_Ic38p5c1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_140);
NB8 resize_0_I31y2kd1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* dest_10, NI32 addedElements_10);
static inline NI32 capInBytes_0_Imq3jn61_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_141);
NB8 resize_0_Iu85c9p_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* dest_11, NI32 addedElements_11);
void shrink_0_Iq4ka8y_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_142, NI32 newLen_21);
void growUnsafe_0_Iz3767g_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_143, NI32 newLen_22);
void eQdestroy_1_I3wpak31_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_205);
static inline void eQwasMoved_1_Itejfoj_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_206);
seq_0_Ifq4s5b1_vmtuaxp6 eQdup_1_Iqqsrms1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 a_47);
void eQdestroy_1_Iuu2ern1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_207);
static inline void eQwasMoved_1_Ifc721e1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_208);
seq_0_I32zqoq1_vmtuaxp6 eQdup_1_Iyywo9a1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 a_48);
void eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6(Pending_0_vmtuaxp6* dest_0);
Pending_0_vmtuaxp6 eQdupQ_SX50ending0vmtuaxp6_0_vmtuaxp6(Pending_0_vmtuaxp6* src_0);
void eQdestroyQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(VmCoro_Obj_0_vmtuaxp6* dest_0);
void eQtraceQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(VmCoro_Obj_0_vmtuaxp6* dest_0, void* src_0);
void eQdestroyQ_ArefSX56X4dX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* dest_0);
void eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* dest_0);
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0);
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0);
void eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** dest_0);
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* eQdupQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* src_0);
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* eQdupQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* src_0);
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* src_0);
void eQtraceQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** dest_0, void* src_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* dest_0);
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** dest_0);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* src_0);
void eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0);
void eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** dest_0, void* src_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* dest_0);
void eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689** dest_0);
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0);
void eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* dest_0);
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* src_0);
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_vmtuaxp6(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void doQQuit_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_14, NI32 code_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56);
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_24, NI32 i_31);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_natd5co251(seq_0_I50urnw_chu5m1rja1 s_29, NI32 i_13);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern NF64 toFloatVal_0_runot4689(Value_0_valzr1t4f* v_16);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_4);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern NU64 ptrToAddr_0_flaksyopx1(Value_0_valzr1t4f* v_20);
extern Value_0_valzr1t4f reinterpToInt_0_flaksyopx1(NU64 raw_0, NI32 tbits_0, NB8 tsigned_0);
extern xint_0_xinat3x34 createXint_0_xinat3x34(NI64 x_4);
extern xint_0_xinat3x34 mask_0_xinat3x34(xint_0_xinat3x34 a_14, NI32 bits_0, NB8 signed_0);
extern Value_0_valzr1t4f vUIntX_0_valzr1t4f(xint_0_xinat3x34 x_5, NI32 bits_3);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern Value_0_valzr1t4f vIntX_0_valzr1t4f(xint_0_xinat3x34 x_3, NI32 bits_1);
extern NB8 isMintedCellAddr_0_flaksyopx1(NU64 a_4);
extern X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 addrToCellPtrAt_0_flaksyopx1(NU64 a_3, NI32 bits_6, TCode_0_valzr1t4f code_2, NU32 etype_2);
extern string_0_sysvq0asl cellAddrProblem_0_flaksyopx1(NU64 a_5);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void failUnported_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_4, string_0_sysvq0asl name_4, string_0_sysvq0asl ctx_2);
extern Value_0_valzr1t4f addrToRegionPtr_0_flaksyopx1(NU64 a_0, NI32 bits_5, TCode_0_valzr1t4f code_1, NU32 etype_1);
extern Value_0_valzr1t4f flCastPtr_0_flaksyopx1(Value_0_valzr1t4f* v_13, NI32 tbits_2, TCode_0_valzr1t4f tcode_2, NU32 etype_0);
extern Value_0_valzr1t4f flLoadObj_1_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_11, NI32 off_8, NU32 tsym_1, NI32 depth_3);
extern X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* flOverlayBox_0_flaksyopx1(Value_0_valzr1t4f* v_17);
extern Value_0_valzr1t4f fieldSeedValue_0_runot4689(NU32 fsym_0);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0);
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
static inline NI32 len_3_I83dzei_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_23);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern LongString_0_sysvq0asl const strlit_0_I11614695157650328859_sysvq0asl;
extern LongString_0_sysvq0asl const strlit_0_I16845119709590674135_sysvq0asl;
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32);
static inline seq_0_Iw8xl5b1_flaksyopx1 newSeqUninit_0_I1tbjnk1_flaksyopx1(NI32 size_7);
extern NU32 getOrIncl_0_Inyo00c_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_5, string_0_sysvq0asl v_4);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
extern LongString_0_sysvq0asl const strlit_0_I16529829149455363342_buiyylk1h1;
extern void eQdestroy_1_Inxd7ue1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_40);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I10157464168546919252_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14683201540015467042_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11023901819970991276_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11614359337083319489_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7262382801534885590_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17069683611453604721_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9151517089334711309_comaa5xpt1;
extern Value_0_valzr1t4f deepCopyValue_0_valzr1t4f(Value_0_valzr1t4f* v_1);
extern Value_0_valzr1t4f detachedDefault_0_valzr1t4f(Value_0_valzr1t4f* v_3);
extern LongString_0_sysvq0asl const strlit_0_I15541155848264557133_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3798637678053249641_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I16581638230773281198_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I1232877487365112244_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13045133590002807130_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12770529794932993973_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I8602794362013704992_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11010039520288330211_comaa5xpt1;
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern LongString_0_sysvq0asl const strlit_0_I10257712218960831919_comaa5xpt1;
extern Value_0_valzr1t4f crossNativeValue_0_croph25r5(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, string_0_sysvq0asl base_5, seq_0_I50urnw_chu5m1rja1 args_3);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
extern NU32 objTypeOf_0_runot4689(Value_0_valzr1t4f* v_18);
extern seq_0_Idl3iy1_comaa5xpt1 loadVTable_0_vtanlalcx(NU32 typ_0);
static inline openArray_0_In1h8lr1_comaa5xpt1 toOpenArray_1_Ivm9z5a_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_204);
static inline NI32 len_6_I8gnayb_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 a_36);
static inline MethodIndexEntry_0_sempjk6bn1* getQ_10_Izev5kw1_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 x_25, NI32 idx_26);
extern void eQdestroy_1_Iph9dp4_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_381);
extern NU32 objBaseSym_0_runot4689(NU32 typeSym_0);
static inline NB8 eqQ_1_nifh7u8pu1(NU32 a_1, NU32 b_1);
static inline NI32 len_3_I2qk2yu1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_202);
static inline MethodEntry_0_chu5m1rja1* getQ_7_I8226yy1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_203, NI32 i_59);
extern NB8 isGenericRoutine_0_runot4689(NU32 fn_0);
static inline void eQwasMoved_1_Ivxly0t1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1* s_41);
static inline seq_0_I50urnw_chu5m1rja1 newSeqUninit_0_I8oufjc_chu5m1rja1(NI32 size_36);
static inline void add_0_Itre92n_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* s_122, Value_0_valzr1t4f elem_30);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
extern seq_0_I50urnw_chu5m1rja1 eQdup_1_I28mx5s1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 a_18);
static inline Instr_0_chu5m1rja1* getQ_7_Iuezo3v1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1 s_119, NI32 i_38);
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
extern void traceStep_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_6, string_0_sysvq0asl code_0, NI32 line_1, NI32 col_0);
extern Value_0_valzr1t4f emptySeqVal_0_runot4689(void);
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
extern void failUnboundImportcGlobal_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_10, string_0_sysvq0asl cname_7, string_0_sysvq0asl bn_0);
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7);
static inline void putQ_7_Iiblebk_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc* s_59, NI32 i_30, NB8 elem_14);
extern Value_0_valzr1t4f flDeref_0_flaksyopx1(Value_0_valzr1t4f* v_9);
extern string_0_sysvq0asl dollarX60Q_ValueKind_0_valzr1t4f(ValueKind_0_valzr1t4f e_0);
extern LongString_0_sysvq0asl const strlit_0_I14095655799529196805_chu5m1rja1;
extern Value_0_valzr1t4f copyOnAssign_0_valzr1t4f(Value_0_valzr1t4f* v_2);
static inline void putQ_7_I4hmt511_runot4689(seq_0_I50urnw_chu5m1rja1* s_71, NI32 i_71, Value_0_valzr1t4f elem_13);
extern void flStoreDeref_0_flaksyopx1(Value_0_valzr1t4f* v_12, Value_0_valzr1t4f* val_1);
extern NB8 arithOverflows_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_6, Value_0_valzr1t4f* a_13, Value_0_valzr1t4f* b_12, NI32 bits_5, NB8 signed_4);
extern NB8 valueEquals_0_runot4689(Value_0_valzr1t4f* a_0, Value_0_valzr1t4f* b_0);
extern NB8 isDivByZero_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_3, Value_0_valzr1t4f* a_10, Value_0_valzr1t4f* b_10);
extern Value_0_valzr1t4f binMagic_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_4, Value_0_valzr1t4f* a_11, Value_0_valzr1t4f* b_11, NI32 bits_2, NB8 signed_2);
extern Value_0_valzr1t4f unMagic_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_5, Value_0_valzr1t4f* a_12, NI32 bits_3, NB8 signed_3);
extern string_0_sysvq0asl enumFieldName_0_runot4689(NU32 enumType_0, NI32 ord_0);
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0, string_0_sysvq0asl name_0);
extern NB8 truthy_0_valzr1t4f(Value_0_valzr1t4f* v_5);
static inline NB8 enabled_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_1);
extern void traceEnter_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_4, string_0_sysvq0asl callee_0, seq_0_I50urnw_chu5m1rja1 args_1, NI32 line_0, string_0_sysvq0asl file_0);
extern void traceExit_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_5, Value_0_valzr1t4f* ret_0, NB8 raised_0);
extern LongString_0_sysvq0asl const strlit_0_I11387783988347383465_chu5m1rja1;
extern LongString_0_sysvq0asl const strlit_0_I6978519596239417483_chu5m1rja1;
extern LongString_0_sysvq0asl const strlit_0_I4520676207223615416_chu5m1rja1;
extern LongString_0_sysvq0asl const strlit_0_I4203653505119668623_chu5m1rja1;
extern NB8 gateAllowsNative_0_runot4689(string_0_sysvq0asl base_3, Value_0_valzr1t4f* v_15);
extern NB8 isStreamGatableIO_0_runot4689(string_0_sysvq0asl base_2);
extern NB8 argIsStream_0_runot4689(Value_0_valzr1t4f* v_13);
static inline void eQwasMoved_1_I4kgdoh1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_72);
extern void eQdestroy_1_I8k3d0z1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_71);
static inline void putQ_7_I41w2p9_runot4689(seq_0_Iw8xl5b1_flaksyopx1* s_83, NI32 i_76, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_15);
extern Value_0_valzr1t4f flIndexGet_0_flaksyopx1(Value_0_valzr1t4f* v_10, NI32 i_1);
extern LongString_0_sysvq0asl const strlit_0_I8241163739446522972_chu5m1rja1;
extern NI32 regionElemBytes_0_flaksyopx1(Value_0_valzr1t4f* v_15);
extern Value_0_valzr1t4f flAddrOfIndex_0_flaksyopx1(Value_0_valzr1t4f* recv_0, NI32 i_3);
extern void flStoreAt_0_flaksyopx1(Value_0_valzr1t4f* v_11, NI32 i_2, Value_0_valzr1t4f* val_0);
extern void failNilIndex_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0, string_0_sysvq0asl ctx_1);
extern ObjInfo_0_chu5m1rja1 eQdupQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 src_0);
extern void eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 dest_0);
extern X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1 flFieldPtr_0_flaksyopx1(Value_0_valzr1t4f* v_6, NU32 fsym_2);
extern LongString_0_sysvq0asl const strlit_0_I15083592761932316767_chu5m1rja1;
extern LongString_0_sysvq0asl const strlit_0_I5291897204707904471_chu5m1rja1;
extern void setBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* sb_0, NI64 x_0);
extern void clearBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* sb_1, NI64 x_1);
extern NB8 hasBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* sb_2, NI64 x_2);
extern NI32 setCard_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* sb_3);
extern ObjSpec_0_chu5m1rja1 eQdupQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 src_0);
extern void eQdestroyQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 dest_0);
extern NB8 isSubtype_0_runot4689(NU32 concrete_0, NU32 target_0);
extern Proc_0_chu5m1rja1 eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* src_0);
extern void eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0);
static inline void eQwasMoved_1_Ik2628i_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1* s_32);
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35);
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66);
extern seq_0_Iw8xl5b1_flaksyopx1 eQdup_1_Io30l171_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 a_28);
extern VmProgram_0_chu5m1rja1 eQdupQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* src_0);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9);
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7);
static inline NI32 len_3_Iuz7erf_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_151);
static inline GlobalSeed_0_chu5m1rja1* getQ_7_Ijx02qt_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_152, NI32 i_43);
extern GlobalSeed_0_chu5m1rja1 eQdupQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* src_0);
extern Value_0_valzr1t4f importcGlobalSeed_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_11, string_0_sysvq0asl cname_8, string_0_sysvq0asl bn_1, NB8* found_2, NB8 quiet_0);
extern NB8 isAllowedUnboundImportc_0_runot4689(string_0_sysvq0asl cname_6);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
static inline void putQ_7_Ild9iim_croph25r5(seq_0_Ixdx2fh1_ast8ri79k* s_23, NI32 i_11, string_0_sysvq0asl elem_9);
extern LongString_0_sysvq0asl const strlit_0_I13880079574436425354_runot4689;
extern void registerErrnoCell_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1);
extern LongString_0_sysvq0asl const strlit_0_I274569611119625799_runot4689;
extern void registerEnvironmentCell_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_0);
extern void eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* dest_0);
static inline NI32 len_3_I05nxx61_comaa5xpt1(seq_0_Inaua171_chu5m1rja1 s_148);
extern LongString_0_sysvq0asl const strlit_0_I16529604172406501048_runot4689;
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
extern string_0_sysvq0asl renderValueReadable_0_valzr1t4f(Value_0_valzr1t4f* v_9, NI32 budget_3);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 capInBytes_0_Ihvsegh1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_74);
extern NB8 resize_0_Iz8tg361_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* dest_24, NI32 addedElements_24);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_I7a20g9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_69);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
extern void eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0);
extern void eQdestroy_1_Iscb4i31_ast8ri79k(seq_0_In6doa_ast8ri79k s_65);
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
extern void eQdestroy_1_Ipa2mag1_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 s_31);
extern void eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0, void* src_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001(Trace_Obj_0_trakthy001* dest_0);
extern void eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251(OutSink_Obj_0_natd5co251* dest_0);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(ClosureEnv_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_vtanlalcx(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_aow2h993l1(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_chu5m1rja1(void);
extern void X60Qini_0_trakthy001(void);
extern void X60Qini_0_runot4689(void);
extern void X60Qini_0_flaksyopx1(void);
extern void X60Qini_0_croph25r5(void);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_ast8ri79k* dest_8, NI32 addedElements_8);
static inline NI32 capInBytes_0_Iih34tr1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_49);
extern NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* dest_4, NI32 addedElements_4);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33);
static inline NI32 memSizeInBytes_0_Ixcobep_flaksyopx1(NI32 size_16);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline MethodIndexEntry_0_sempjk6bn1* rawData_0_I0uy4q51_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_253);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
static inline NI32 memSizeInBytes_0_Itmy7ww1_chu5m1rja1(NI32 size_37);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
extern void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17);
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38);
extern NB8 resize_0_I2yw78g1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* dest_7, NI32 addedElements_7);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I4769640576963739090_vmtuaxp6 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_INITAMNESTY"}
;
LongString_0_sysvq0asl const strlit_0_I9638458106971767517_vmtuaxp6 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_LOUDNIL"}
;
LongString_0_sysvq0asl const strlit_0_I1085019656192145846_vmtuaxp6 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: VM value-path hole at "}
;
LongString_0_sysvq0asl const strlit_0_I6103401829163073608_vmtuaxp6 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 would have silently returned nil.\012"}
;
LongString_0_sysvq0asl const strlit_0_I2942840443061141009_vmtuaxp6 = {
  .fullLen_0 = 28, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: VM value-path nil at "}
;
LongString_0_sysvq0asl const strlit_0_I2155691521535803838_vmtuaxp6 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "interp:"}
;
LongString_0_sysvq0asl const strlit_0_I7536719426221232278_vmtuaxp6 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cast[pointer](int)"}
;
LongString_0_sysvq0asl const strlit_0_I2251891484599977817_vmtuaxp6 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cast[ptr T](int)"}
;
LongString_0_sysvq0asl const strlit_0_I8786502555998912973_vmtuaxp6 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "division by zero\012"}
;
LongString_0_sysvq0asl const strlit_0_I10919355893625115164_vmtuaxp6 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "division by zero"}
;
LongString_0_sysvq0asl const strlit_0_I6420956111249849549_vmtuaxp6 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_create"}
;
LongString_0_sysvq0asl const strlit_0_I2011743623608043438_vmtuaxp6 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "workerLoop"}
;
LongString_0_sysvq0asl const strlit_0_I15944996171862775263_vmtuaxp6 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_join"}
;
LongString_0_sysvq0asl const strlit_0_I13023507668929764686_vmtuaxp6 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "epoll_create1"}
;
LongString_0_sysvq0asl const strlit_0_I896784059842111249_vmtuaxp6 = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dereference of nil/unhandled pointer value (kind="}
;
LongString_0_sysvq0asl const strlit_0_I8402133133667695762_vmtuaxp6 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "captured variable \'"}
;
LongString_0_sysvq0asl const strlit_0_I14000276951511883434_vmtuaxp6 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' is not in this frame\'s closure environment"}
;
LongString_0_sysvq0asl const strlit_0_I4313607421916706826_vmtuaxp6 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callee is not a proc value (kind="}
;
LongString_0_sysvq0asl const strlit_0_I1479688777189329103_vmtuaxp6 = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 unsupported closure/iterator/first-class-routine value"}
;
LongString_0_sysvq0asl const strlit_0_I2711403001631354929_vmtuaxp6 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "index "}
;
LongString_0_sysvq0asl const strlit_0_I12553036805083656819_vmtuaxp6 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " out of bounds / unindexable receiver (kind="}
;
LongString_0_sysvq0asl const strlit_0_I13454172589441230177_vmtuaxp6 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vm:opIndexSet"}
;
LongString_0_sysvq0asl const strlit_0_I13854238605625854974_vmtuaxp6 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "field \'"}
;
LongString_0_sysvq0asl const strlit_0_I176574084057763820_vmtuaxp6 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' not found on receiver (kind="}
;
LongString_0_sysvq0asl const strlit_0_I11577963402916336664_vmtuaxp6 = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 missing object field / uninitialized ref"}
;
LongString_0_sysvq0asl const strlit_0_I1180022326161049401_vmtuaxp6 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tuple index "}
;
LongString_0_sysvq0asl const strlit_0_I14838583653064907228_vmtuaxp6 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " out of bounds / non-tuple receiver (kind="}
;
LongString_0_sysvq0asl const strlit_0_I6336233549165567821_vmtuaxp6 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "raised"}
;
LongString_0_sysvq0asl const strlit_0_I6204575006793878320_vmtuaxp6 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli-vm: init amnesty \342\200\224 module init #"}
;
LongString_0_sysvq0asl const strlit_0_I98869477994407991_vmtuaxp6 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", output rolled back and the fault forgiven\012"}
;
LongString_0_sysvq0asl const strlit_0_I14207650632107132323_vmtuaxp6 = {
  .fullLen_0 = 45, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: unhandled exception, program aborted: "}
;
NU32 const VmCoro_Obj_0_dy_vmtuaxp6[] = {
  1294232418u, 2332001562u, 716972470u}
;
Rtti_0_sysvq0asl const VmCoro_Obj_0_vt_vmtuaxp6 = {
  .dl_0 = 3, .dy_0 = ((NU32*)VmCoro_Obj_0_dy_vmtuaxp6), .mt_0 = {
    ((void*)eQdestroyQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6), ((void*)eQtraceQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6), ((void*)eQdestroyQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6), ((void*)eQtraceQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6)}}
;
NI32 initAmnestyCount_0_vmtuaxp6 = 0;
NB8 loudInitAmnesty_0_vmtuaxp6;
NB8 loudNilBreadcrumbs_0_vmtuaxp6;
NB8 X60QiniGuard_0_vmtuaxp6;
void loudNil_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_0, string_0_sysvq0asl opname_0, string_0_sysvq0asl reason_0){
  if ((!(*(*vm_0).d_00.sink_0).d_00.didQQuit_0)){
    NI32 X60Qx_55 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1085019656192145846_vmtuaxp6)}
    );
    NI32 X60Qx_56 = len_4_sysvq0asl(opname_0);
    NI32 X60Qx_57 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_58 = len_4_sysvq0asl(reason_0);
    NI32 X60Qx_59 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6103401829163073608_vmtuaxp6)}
    );
    string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_55 + X60Qx_56)) + X60Qx_57)) + X60Qx_58)) + X60Qx_59)));
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1085019656192145846_vmtuaxp6)}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), opname_0);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), reason_0);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6103401829163073608_vmtuaxp6)}
    );
    add_2_sysvq0asl((&(*(*vm_0).d_00.sink_0).d_00.errBuf_0), X60Qdesugar_0);
    doQQuit_0_natd5co251((*vm_0).d_00.sink_0, 1);
    nimStrDestroy(X60Qdesugar_0);}}
void softNil_0_vmtuaxp6(string_0_sysvq0asl opname_1, string_0_sysvq0asl reason_1){
  if (loudNilBreadcrumbs_0_vmtuaxp6){
    NI32 X60Qx_60 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2942840443061141009_vmtuaxp6)}
    );
    NI32 X60Qx_61 = len_4_sysvq0asl(opname_1);
    NI32 X60Qx_62 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_63 = len_4_sysvq0asl(reason_1);
    NI32 X60Qx_64 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_60 + X60Qx_61)) + X60Qx_62)) + X60Qx_63)) + X60Qx_64)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2942840443061141009_vmtuaxp6)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), opname_1);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), reason_1);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_1);}}
Value_0_valzr1t4f fieldOf_0_vmtuaxp6(Value_0_valzr1t4f* v_0, NU32 fsym_0){
  Value_0_valzr1t4f result_1;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_1 = NIM_NIL;
  switch ((*v_0).kind_0){
    case 11:
    case 10:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_1);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_65 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*v_0).obj_0);
      box_1 = X60Qx_65;}
    break;
    case 12:
    {
      NB8 X60Qx_66;
      if ((!((*v_0).rf_0 == NIM_NIL))){
        NB8 X60Qx_67;
        if ((*(*v_0).rf_0).d_00.v_0.kind_0 == 11){
          X60Qx_67 = NIM_TRUE;}
        else {
          X60Qx_67 = ((*(*v_0).rf_0).d_00.v_0.kind_0 == 10);}
        X60Qx_66 = X60Qx_67;}
      else {
        X60Qx_66 = NIM_FALSE;}
      if (X60Qx_66){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_1);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_68 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*(*v_0).rf_0).d_00.v_0.obj_0);
        box_1 = X60Qx_68;}}
    break;
    default:
    {
      }
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_1));
  Value_0_valzr1t4f X60Qx_69 = vNil_0_valzr1t4f();
  result_1 = X60Qx_69;
  if ((!(box_1 == NIM_NIL))){
    NI32 i_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_70 = len_3_I6y2imo_buiyylk1h1((*box_1).d_00.names_0);
        if (i_1 < X60Qx_70){
          NU32* X60Qx_71 = getQ_7_I2v00yv1_buiyylk1h1((*box_1).d_00.names_0, i_1);
          NB8 X60Qx_72 = eqQ_0_nifh7u8pu1((*X60Qx_71), fsym_0);
          if (X60Qx_72){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_73 = getQ_7_Ii14ync1_flaksyopx1((*box_1).d_00.cells_0, i_1);
            Value_0_valzr1t4f X60Qx_74 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_73)).d_00.v_0));
            result_1 = X60Qx_74;
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_1);
            return result_1;}
          inc_1_I6wjjge_aow2h993l1((&i_1));}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_1);
  return result_1;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_1);
  return result_1;}
Value_0_valzr1t4f popv_0_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_0){
  Value_0_valzr1t4f result_2;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_2));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_2));
  NI32 X60Qx_75 = len_3_I4n9kvq_comaa5xpt1((*s_0));
  Value_0_valzr1t4f* X60Qx_76 = getQ_7_Ine8yq71_natd5co251((*s_0), ((NI32)(X60Qx_75 - 1)));
  Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_76);
  Value_0_valzr1t4f X60Qx_77 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
  result_2 = X60Qx_77;
  NI32 X60Qx_78 = len_3_I4n9kvq_comaa5xpt1((*s_0));
  setLen_0_I8wiqgg_vmtuaxp6(s_0, ((NI32)(X60Qx_78 - 1)));
  return result_2;}
Value_0_valzr1t4f truncToBits_0_vmtuaxp6(NU64 raw_0, NI32 tbits_0, NB8 tsigned_0){
  Value_0_valzr1t4f result_3;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
  NU64 X60Qx_0;
  if (64 <= tbits_0){
    X60Qx_0 = raw_0;}
  else {
    X60Qx_0 = ((NU64)(raw_0 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)tbits_0))) - ((NU64)1u)))));}
  NU64 mval_0 = X60Qx_0;
  if (tsigned_0){
    NI64 sv_0 = ((NI64)mval_0);
    NB8 X60Qx_79;
    if (tbits_0 < 64){
      X60Qx_79 = (!(((NU64)(mval_0 & ((NU64)(((NU64)1u) << ((NU32)((NI32)(tbits_0 - 1))))))) == ((NU64)0u)));}
    else {
      X60Qx_79 = NIM_FALSE;}
    if (X60Qx_79){
      sv_0 = ((NI64)((NU64)(mval_0 | ((NU64) ~ ((NU64)(((NU64)(((NU64)1u) << ((NU32)tbits_0))) - ((NU64)1u)))))));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
    Value_0_valzr1t4f X60Qx_80 = vInt_0_valzr1t4f(sv_0, tbits_0);
    result_3 = X60Qx_80;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
    Value_0_valzr1t4f X60Qx_81 = vUInt_0_valzr1t4f(mval_0, tbits_0);
    result_3 = X60Qx_81;}
  return result_3;}
Value_0_valzr1t4f doConv_0_vmtuaxp6(ConvSpec_0_chu5m1rja1 sp_0, Value_0_valzr1t4f* v_1, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0){
  Value_0_valzr1t4f result_4;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
  switch (sp_0.mode_0){
    case 1:
    {
      NF64 fv_0 = toFloatVal_0_runot4689((&(*v_1)));
      NF64 X60Qx_1;
      if (sp_0.bits_0 == 32){
        X60Qx_1 = ((NF64)((NF32)fv_0));}
      else {
        X60Qx_1 = fv_0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      Value_0_valzr1t4f X60Qx_82 = vFloat_0_valzr1t4f(X60Qx_1, sp_0.bits_0);
      result_4 = X60Qx_82;}
    break;
    case 2:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      NI64 X60Qx_83 = asInt_0_valzr1t4f((&(*v_1)));
      Value_0_valzr1t4f X60Qx_84 = vChar_0_valzr1t4f(((NC8)((NI64)(X60Qx_83 & ((NI64)255)))));
      result_4 = X60Qx_84;}
    break;
    case 3:
    {
      if ((*v_1).kind_0 == 13){
        NU64 a_2 = ptrToAddr_0_flaksyopx1((&(*v_1)));
        if (sp_0.signed_0){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          Value_0_valzr1t4f X60Qx_85 = reinterpToInt_0_flaksyopx1(a_2, sp_0.bits_0, NIM_TRUE);
          result_4 = X60Qx_85;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          xint_0_xinat3x34 X60Qx_86 = createXint_0_xinat3x34(((NI64)a_2));
          xint_0_xinat3x34 X60Qx_87 = mask_0_xinat3x34(X60Qx_86, sp_0.bits_0, NIM_FALSE);
          Value_0_valzr1t4f X60Qx_88 = vUIntX_0_valzr1t4f(X60Qx_87, sp_0.bits_0);
          result_4 = X60Qx_88;}}
      else {
        if ((*v_1).kind_0 == 3){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          Value_0_valzr1t4f X60Qx_89 = truncToBits_0_vmtuaxp6(((NU64)((NI64)(*v_1).fval_0)), sp_0.bits_0, sp_0.signed_0);
          result_4 = X60Qx_89;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          NI64 X60Qx_90 = asInt_0_valzr1t4f((&(*v_1)));
          Value_0_valzr1t4f X60Qx_91 = truncToBits_0_vmtuaxp6(((NU64)X60Qx_90), sp_0.bits_0, sp_0.signed_0);
          result_4 = X60Qx_91;}}}
    break;
    case 4:
    {
      if ((*v_1).kind_0 == 3){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
        Value_0_valzr1t4f X60Qx_92 = vFloat_0_valzr1t4f((*v_1).fval_0, sp_0.bits_0);
        result_4 = X60Qx_92;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
        NI64 X60Qx_93 = asInt_0_valzr1t4f((&(*v_1)));
        NF64 X60Qx_94;
        copyMem_0_sysvq0asl((&X60Qx_94), (&X60Qx_93), sizeof(NF64));
        Value_0_valzr1t4f X60Qx_95 = vFloat_0_valzr1t4f(X60Qx_94, sp_0.bits_0);
        result_4 = X60Qx_95;}}
    break;
    case 5:
    {
      if ((*v_1).kind_0 == 13){
        NU64 a_3 = ptrToAddr_0_flaksyopx1((&(*v_1)));
        if (sp_0.signed_0){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          Value_0_valzr1t4f X60Qx_96 = reinterpToInt_0_flaksyopx1(a_3, sp_0.bits_0, NIM_TRUE);
          result_4 = X60Qx_96;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          xint_0_xinat3x34 X60Qx_97 = createXint_0_xinat3x34(((NI64)a_3));
          xint_0_xinat3x34 X60Qx_98 = mask_0_xinat3x34(X60Qx_97, sp_0.bits_0, NIM_FALSE);
          Value_0_valzr1t4f X60Qx_99 = vUIntX_0_valzr1t4f(X60Qx_98, sp_0.bits_0);
          result_4 = X60Qx_99;}}
      else {
        if ((*v_1).kind_0 == 3){
          NF64 X60Qx_100 = (*v_1).fval_0;
          NI64 X60Qx_101;
          copyMem_0_sysvq0asl((&X60Qx_101), (&X60Qx_100), sizeof(NI64));
          NI64 bitsAsInt_0 = X60Qx_101;
          xint_0_xinat3x34 X60Qx_102 = createXint_0_xinat3x34(bitsAsInt_0);
          xint_0_xinat3x34 m_0 = mask_0_xinat3x34(X60Qx_102, sp_0.bits_0, sp_0.signed_0);
          if (sp_0.signed_0){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
            Value_0_valzr1t4f X60Qx_103 = vIntX_0_valzr1t4f(m_0, sp_0.bits_0);
            result_4 = X60Qx_103;}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
            Value_0_valzr1t4f X60Qx_104 = vUIntX_0_valzr1t4f(m_0, sp_0.bits_0);
            result_4 = X60Qx_104;}}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          NI64 X60Qx_105 = asInt_0_valzr1t4f((&(*v_1)));
          Value_0_valzr1t4f X60Qx_106 = truncToBits_0_vmtuaxp6(((NU64)X60Qx_105), sp_0.bits_0, sp_0.signed_0);
          result_4 = X60Qx_106;}}}
    break;
    case 6:
    {
      if (sp_0.bits_0 == -2){
        NB8 X60Qx_107;
        if ((*v_1).kind_0 == 1){
          X60Qx_107 = NIM_TRUE;}
        else {
          X60Qx_107 = ((*v_1).kind_0 == 2);}
        if (X60Qx_107){
          NI64 X60Qx_108 = asInt_0_valzr1t4f((&(*v_1)));
          NU64 raw_1 = ((NU64)X60Qx_108);
          NB8 X60Qx_109 = isMintedCellAddr_0_flaksyopx1(raw_1);
          if (X60Qx_109){
            X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 X60Qtmptup_0 = addrToCellPtrAt_0_flaksyopx1(raw_1, 8, 3, ((NU32)0u));
            Value_0_valzr1t4f cp_0 = X60Qtmptup_0.fld_0;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_0.fld_0));
            NB8 ok_0 = X60Qtmptup_0.fld_1;
            if (ok_0){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
              result_4 = cp_0;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_0));}
            else {
              string_0_sysvq0asl X60Qtmp_3 = cellAddrProblem_0_flaksyopx1(raw_1);
              string_0_sysvq0asl X60Qtmp_2 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I2155691521535803838_vmtuaxp6)}
              , X60Qtmp_3);
              failUnported_0_runot4689(sink_0, (string_0_sysvq0asl){
                .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I7536719426221232278_vmtuaxp6)}
              , X60Qtmp_2);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
              Value_0_valzr1t4f X60Qx_110 = vNil_0_valzr1t4f();
              result_4 = X60Qx_110;
              nimStrDestroy(X60Qtmp_2);
              nimStrDestroy(X60Qtmp_3);}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_0));
            eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&X60Qtmptup_0));}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
            Value_0_valzr1t4f X60Qx_111 = addrToRegionPtr_0_flaksyopx1(raw_1, 8, 3, ((NU32)0u));
            result_4 = X60Qx_111;}}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
          Value_0_valzr1t4f X60Qx_112 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
          result_4 = X60Qx_112;}}
      else {
        if (sp_0.bits_0 < 0){
          NU64 X60Qx_2;
          NB8 X60Qx_113;
          if ((*v_1).kind_0 == 1){
            X60Qx_113 = NIM_TRUE;}
          else {
            X60Qx_113 = ((*v_1).kind_0 == 2);}
          if (X60Qx_113){
            NI64 X60Qx_114 = asInt_0_valzr1t4f((&(*v_1)));
            X60Qx_2 = ((NU64)X60Qx_114);}
          else {
            X60Qx_2 = ((NU64)0u);}
          NU64 raw_2 = X60Qx_2;
          NB8 X60Qx_115 = isMintedCellAddr_0_flaksyopx1(raw_2);
          if (X60Qx_115){
            X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 X60Qtmptup_1 = addrToCellPtrAt_0_flaksyopx1(raw_2, 8, 3, ((NU32)0u));
            Value_0_valzr1t4f cp_1 = X60Qtmptup_1.fld_0;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_1.fld_0));
            NB8 ok_1 = X60Qtmptup_1.fld_1;
            if (ok_1){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
              result_4 = cp_1;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_1));}
            else {
              string_0_sysvq0asl X60Qtmp_5 = cellAddrProblem_0_flaksyopx1(raw_2);
              string_0_sysvq0asl X60Qtmp_4 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I2155691521535803838_vmtuaxp6)}
              , X60Qtmp_5);
              failUnported_0_runot4689(sink_0, (string_0_sysvq0asl){
                .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I2251891484599977817_vmtuaxp6)}
              , X60Qtmp_4);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
              Value_0_valzr1t4f X60Qx_116 = vNil_0_valzr1t4f();
              result_4 = X60Qx_116;
              nimStrDestroy(X60Qtmp_4);
              nimStrDestroy(X60Qtmp_5);}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_1));
            eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&X60Qtmptup_1));}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
            Value_0_valzr1t4f X60Qx_117 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
            result_4 = X60Qx_117;}}
        else {
          if ((*v_1).kind_0 == 13){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
            Value_0_valzr1t4f X60Qx_118 = flCastPtr_0_flaksyopx1((&(*v_1)), sp_0.bits_0, sp_0.code_0, sp_0.etype_0);
            result_4 = X60Qx_118;}
          else {
            NB8 X60Qx_119;
            if ((*v_1).kind_0 == 1){
              X60Qx_119 = NIM_TRUE;}
            else {
              X60Qx_119 = ((*v_1).kind_0 == 2);}
            if (X60Qx_119){
              NI64 X60Qx_120 = asInt_0_valzr1t4f((&(*v_1)));
              NU64 raw_3 = ((NU64)X60Qx_120);
              NB8 X60Qx_121 = isMintedCellAddr_0_flaksyopx1(raw_3);
              if (X60Qx_121){
                X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 X60Qtmptup_2 = addrToCellPtrAt_0_flaksyopx1(raw_3, sp_0.bits_0, sp_0.code_0, sp_0.etype_0);
                Value_0_valzr1t4f cp_2 = X60Qtmptup_2.fld_0;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_2.fld_0));
                NB8 ok_2 = X60Qtmptup_2.fld_1;
                if (ok_2){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                  result_4 = cp_2;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_2));}
                else {
                  string_0_sysvq0asl X60Qtmp_7 = cellAddrProblem_0_flaksyopx1(raw_3);
                  string_0_sysvq0asl X60Qtmp_6 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I2155691521535803838_vmtuaxp6)}
                  , X60Qtmp_7);
                  failUnported_0_runot4689(sink_0, (string_0_sysvq0asl){
                    .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I2251891484599977817_vmtuaxp6)}
                  , X60Qtmp_6);
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                  Value_0_valzr1t4f X60Qx_122 = vNil_0_valzr1t4f();
                  result_4 = X60Qx_122;
                  nimStrDestroy(X60Qtmp_6);
                  nimStrDestroy(X60Qtmp_7);}
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cp_2));
                eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&X60Qtmptup_2));}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                Value_0_valzr1t4f X60Qx_123 = addrToRegionPtr_0_flaksyopx1(raw_3, sp_0.bits_0, sp_0.code_0, sp_0.etype_0);
                result_4 = X60Qx_123;}}
            else {
              if ((*v_1).kind_0 == 12){
                NB8 X60Qx_124;
                NB8 X60Qx_125;
                NB8 X60Qx_126;
                if ((!((*v_1).rf_0 == NIM_NIL))){
                  NB8 X60Qx_127;
                  if ((*(*v_1).rf_0).d_00.v_0.kind_0 == 11){
                    X60Qx_127 = NIM_TRUE;}
                  else {
                    X60Qx_127 = ((*(*v_1).rf_0).d_00.v_0.kind_0 == 10);}
                  X60Qx_126 = X60Qx_127;}
                else {
                  X60Qx_126 = NIM_FALSE;}
                if (X60Qx_126){
                  X60Qx_125 = (!((*(*v_1).rf_0).d_00.v_0.obj_0 == NIM_NIL));}
                else {
                  X60Qx_125 = NIM_FALSE;}
                if (X60Qx_125){
                  X60Qx_124 = (0 < (*(*(*v_1).rf_0).d_00.v_0.obj_0).d_00.cells_0.len_0);}
                else {
                  X60Qx_124 = NIM_FALSE;}
                if (X60Qx_124){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_128 = getQ_7_Ii14ync1_flaksyopx1((*(*(*v_1).rf_0).d_00.v_0.obj_0).d_00.cells_0, 0);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_129 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_128));
                  result_4 = (Value_0_valzr1t4f){
                    .kind_0 = 13, .loc_0 = X60Qx_129, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
                  ;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                  result_4 = (Value_0_valzr1t4f){
                    .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
                  ;}}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
                Value_0_valzr1t4f X60Qx_130 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
                result_4 = X60Qx_130;}}}}}}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      Value_0_valzr1t4f X60Qx_131 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
      result_4 = X60Qx_131;}
    break;}
  return result_4;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* objOfV_0_vmtuaxp6(Value_0_valzr1t4f* v_2){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* result_5;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&result_5));
  switch ((*v_2).kind_0){
    case 11:
    case 10:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_132 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*v_2).obj_0);
      result_5 = X60Qx_132;}
    break;
    case 12:
    {
      NB8 X60Qx_133;
      if ((!((*v_2).rf_0 == NIM_NIL))){
        NB8 X60Qx_134;
        if ((*(*v_2).rf_0).d_00.v_0.kind_0 == 11){
          X60Qx_134 = NIM_TRUE;}
        else {
          X60Qx_134 = ((*(*v_2).rf_0).d_00.v_0.kind_0 == 10);}
        X60Qx_133 = X60Qx_134;}
      else {
        X60Qx_133 = NIM_FALSE;}
      if (X60Qx_133){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_135 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*(*v_2).rf_0).d_00.v_0.obj_0);
        result_5 = X60Qx_135;}
      else {
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
        result_5 = NIM_NIL;}}
    break;
    case 13:
    {
      NB8 X60Qx_136;
      if ((!((*v_2).region_0 == NIM_NIL))){
        X60Qx_136 = ((*v_2).ecode_0 == 7);}
      else {
        X60Qx_136 = NIM_FALSE;}
      if (X60Qx_136){
        Value_0_valzr1t4f ov_0 = flLoadObj_1_flaksyopx1((*v_2).region_0, ((NI32)(*v_2).foff_0), (*v_2).etype_0, 0);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_3;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&X60Qx_3));
        if (ov_0.kind_0 == 11){
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qx_3);
          X60Qx_3 = ov_0.obj_0;
          eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&ov_0.obj_0));}
        else {
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qx_3);
          X60Qx_3 = NIM_NIL;}
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
        result_5 = X60Qx_3;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&X60Qx_3));
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qx_3);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ov_0));}
      else {
        if ((!((*v_2).loc_0 == NIM_NIL))){
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
          X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_137 = objOfV_0_vmtuaxp6((&(*(*v_2).loc_0).d_00.v_0));
          result_5 = X60Qx_137;}
        else {
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
          result_5 = NIM_NIL;}}}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(result_5);
      result_5 = NIM_NIL;}
    break;}
  return result_5;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* fieldCellV_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_0, NU32 fsym_1){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_6;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&result_6));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_6);
  result_6 = NIM_NIL;
  if ((!(box_0 == NIM_NIL))){
    NI32 i_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_138 = len_3_I6y2imo_buiyylk1h1((*box_0).d_00.names_0);
        if (i_5 < X60Qx_138){
          NU32* X60Qx_139 = getQ_7_I2v00yv1_buiyylk1h1((*box_0).d_00.names_0, i_5);
          NB8 X60Qx_140 = eqQ_0_nifh7u8pu1((*X60Qx_139), fsym_1);
          if (X60Qx_140){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_141 = getQ_7_Ii14ync1_flaksyopx1((*box_0).d_00.cells_0, i_5);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_142 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_141));
            result_6 = X60Qx_142;
            return result_6;}
          inc_1_I6wjjge_aow2h993l1((&i_5));}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  return result_6;}
Value_0_valzr1t4f fieldRecv_0_vmtuaxp6(Value_0_valzr1t4f* v_3){
  Value_0_valzr1t4f result_7;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
  Value_0_valzr1t4f X60Qx_143 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_3)));
  result_7 = X60Qx_143;
  NI32 guard_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_144;
      NB8 X60Qx_145;
      NB8 X60Qx_146;
      NB8 X60Qx_147;
      if (guard_0 < 8){
        X60Qx_147 = (result_7.kind_0 == 13);}
      else {
        X60Qx_147 = NIM_FALSE;}
      if (X60Qx_147){
        X60Qx_146 = (result_7.region_0 == NIM_NIL);}
      else {
        X60Qx_146 = NIM_FALSE;}
      if (X60Qx_146){
        X60Qx_145 = (!(result_7.loc_0 == NIM_NIL));}
      else {
        X60Qx_145 = NIM_FALSE;}
      if (X60Qx_145){
        X60Qx_144 = ((*result_7.loc_0).d_00.v_0.kind_0 == 13);}
      else {
        X60Qx_144 = NIM_FALSE;}
      if (X60Qx_144){
        Value_0_valzr1t4f X60Qlhs_8 = result_7;
        Value_0_valzr1t4f X60Qx_148 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*result_7.loc_0).d_00.v_0));
        result_7 = X60Qx_148;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_8));
        inc_1_I6wjjge_aow2h993l1((&guard_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_7;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* regionFieldCellV_0_vmtuaxp6(Value_0_valzr1t4f* v_4, NU32 fsym_2){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_8;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&result_8));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2 = flOverlayBox_0_flaksyopx1((&(*v_4)));
  if (box_2 == NIM_NIL){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_2);
    return NIM_NIL;}
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_149 = len_3_I6y2imo_buiyylk1h1((*box_2).d_00.names_0);
      if (i_6 < X60Qx_149){
        NU32* X60Qx_150 = getQ_7_I2v00yv1_buiyylk1h1((*box_2).d_00.names_0, i_6);
        NB8 X60Qx_151 = eqQ_0_nifh7u8pu1((*X60Qx_150), fsym_2);
        if (X60Qx_151){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_152 = getQ_7_Ii14ync1_flaksyopx1((*box_2).d_00.cells_0, i_6);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_153 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_152));
          result_8 = X60Qx_153;
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_2);
          return result_8;}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_8);
  Value_0_valzr1t4f X60Qtmp_9 = fieldSeedValue_0_runot4689(fsym_2);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_154 = newCell_0_valzr1t4f((&X60Qtmp_9));
  result_8 = X60Qx_154;
  add_0_I34il1q_comaa5xpt1((&(*box_2).d_00.names_0), fsym_2);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_155 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_8);
  add_0_Ijpw0mu_flaksyopx1((&(*box_2).d_00.cells_0), X60Qx_155);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_9));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_2);
  return result_8;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_9));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_2);
  return result_8;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* indexCell_0_vmtuaxp6(Value_0_valzr1t4f* recv_0, NI32 i_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_9;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&result_9));
  NB8 X60Qx_156;
  if ((*recv_0).kind_0 == 13){
    X60Qx_156 = (!((*recv_0).arrOwn_0 == NIM_NIL));}
  else {
    X60Qx_156 = NIM_FALSE;}
  if (X60Qx_156){
    NI32 k_0 = ((NI32)((*recv_0).base_0 + i_0));
    NB8 X60Qx_157;
    if (0 <= k_0){
      NI32 X60Qx_158 = len_3_I83dzei_flaksyopx1((*(*recv_0).arrOwn_0).d_00.elems_0);
      X60Qx_157 = (k_0 < X60Qx_158);}
    else {
      X60Qx_157 = NIM_FALSE;}
    if (X60Qx_157){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_159 = getQ_7_Ii14ync1_flaksyopx1((*(*recv_0).arrOwn_0).d_00.elems_0, k_0);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_160 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_159));
      result_9 = X60Qx_160;
      return result_9;}
    return NIM_NIL;}
  NB8 X60Qx_161;
  if ((*recv_0).kind_0 == 13){
    X60Qx_161 = (!((*recv_0).seqOwn_0 == NIM_NIL));}
  else {
    X60Qx_161 = NIM_FALSE;}
  if (X60Qx_161){
    NI32 k_1 = ((NI32)((*recv_0).base_0 + i_0));
    NB8 X60Qx_162;
    if (0 <= k_1){
      NI32 X60Qx_163 = len_3_I83dzei_flaksyopx1((*(*recv_0).seqOwn_0).d_00.elems_0);
      X60Qx_162 = (k_1 < X60Qx_163);}
    else {
      X60Qx_162 = NIM_FALSE;}
    if (X60Qx_162){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_164 = getQ_7_Ii14ync1_flaksyopx1((*(*recv_0).seqOwn_0).d_00.elems_0, k_1);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_165 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_164));
      result_9 = X60Qx_165;
      return result_9;}
    return NIM_NIL;}
  Value_0_valzr1t4f recv_1 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*recv_0)));
  NB8 X60Qx_166;
  if (recv_1.kind_0 == 13){
    X60Qx_166 = (!(recv_1.loc_0 == NIM_NIL));}
  else {
    X60Qx_166 = NIM_FALSE;}
  if (X60Qx_166){
    Value_0_valzr1t4f X60Qlhs_10 = recv_1;
    Value_0_valzr1t4f X60Qx_167 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*recv_1.loc_0).d_00.v_0));
    recv_1 = X60Qx_167;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_10));}
  else {
    NB8 X60Qx_168;
    if (recv_1.kind_0 == 12){
      X60Qx_168 = (!(recv_1.rf_0 == NIM_NIL));}
    else {
      X60Qx_168 = NIM_FALSE;}
    if (X60Qx_168){
      Value_0_valzr1t4f X60Qlhs_11 = recv_1;
      Value_0_valzr1t4f X60Qx_169 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*recv_1.rf_0).d_00.v_0));
      recv_1 = X60Qx_169;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_11));}}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_9);
  result_9 = NIM_NIL;
  switch (recv_1.kind_0){
    case 9:
    {
      if ((!(recv_1.arr_0 == NIM_NIL))){
        NI32 ai_0 = ((NI32)(i_0 - (*recv_1.arr_0).d_00.lo_0));
        NB8 X60Qx_170;
        if (0 <= ai_0){
          NI32 X60Qx_171 = len_3_I83dzei_flaksyopx1((*recv_1.arr_0).d_00.elems_0);
          X60Qx_170 = (ai_0 < X60Qx_171);}
        else {
          X60Qx_170 = NIM_FALSE;}
        if (X60Qx_170){
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_9);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_172 = getQ_7_Ii14ync1_flaksyopx1((*recv_1.arr_0).d_00.elems_0, ai_0);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_173 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_172));
          result_9 = X60Qx_173;}}}
    break;
    case 8:
    {
      NB8 X60Qx_174;
      NB8 X60Qx_175;
      if ((!(recv_1.sq_0 == NIM_NIL))){
        X60Qx_175 = (0 <= i_0);}
      else {
        X60Qx_175 = NIM_FALSE;}
      if (X60Qx_175){
        NI32 X60Qx_176 = len_3_I83dzei_flaksyopx1((*recv_1.sq_0).d_00.elems_0);
        X60Qx_174 = (i_0 < X60Qx_176);}
      else {
        X60Qx_174 = NIM_FALSE;}
      if (X60Qx_174){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_9);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_177 = getQ_7_Ii14ync1_flaksyopx1((*recv_1.sq_0).d_00.elems_0, i_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_178 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_177));
        result_9 = X60Qx_178;}}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_179;
      NB8 X60Qx_180;
      if ((!(recv_1.obj_0 == NIM_NIL))){
        X60Qx_180 = (0 <= i_0);}
      else {
        X60Qx_180 = NIM_FALSE;}
      if (X60Qx_180){
        NI32 X60Qx_181 = len_3_I83dzei_flaksyopx1((*recv_1.obj_0).d_00.cells_0);
        X60Qx_179 = (i_0 < X60Qx_181);}
      else {
        X60Qx_179 = NIM_FALSE;}
      if (X60Qx_179){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_9);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_182 = getQ_7_Ii14ync1_flaksyopx1((*recv_1.obj_0).d_00.cells_0, i_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_183 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_182));
        result_9 = X60Qx_183;}}
    break;
    case 6:
    {
      NB8 X60Qx_184;
      NB8 X60Qx_185;
      NI32 X60Qx_186 = len_4_sysvq0asl(recv_1.sval_0);
      if (0 < X60Qx_186){
        X60Qx_185 = (0 <= i_0);}
      else {
        X60Qx_185 = NIM_FALSE;}
      if (X60Qx_185){
        NI32 X60Qx_187 = len_4_sysvq0asl(recv_1.sval_0);
        X60Qx_184 = (i_0 < X60Qx_187);}
      else {
        X60Qx_184 = NIM_FALSE;}
      if (X60Qx_184){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_9);
        NC8 X60Qx_188 = getQ_9_sysvq0asl(recv_1.sval_0, i_0);
        Value_0_valzr1t4f X60Qtmp_12 = vChar_0_valzr1t4f(X60Qx_188);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_189 = newCell_0_valzr1t4f((&X60Qtmp_12));
        result_9 = X60Qx_189;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_12));}}
    break;
    default:
    {
      }
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_1));
  return result_9;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_1));
  return result_9;}
void vmRaiseIndexDefect_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_1, NI32 idx_0, NI32 lo_0, NI32 hi_0){
  if ((*vm_1).d_00.raised_0){
    return;}
  string_0_sysvq0asl X60Qdesugar_2 = dollarQ_2_sysvq0asl(idx_0);
  string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl(lo_0);
  string_0_sysvq0asl X60Qdesugar_4 = dollarQ_2_sysvq0asl(hi_0);
  NI32 X60Qx_190 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  NI32 X60Qx_191 = len_4_sysvq0asl(X60Qdesugar_2);
  NI32 X60Qx_192 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  NI32 X60Qx_193 = len_4_sysvq0asl(X60Qdesugar_3);
  NI32 X60Qx_194 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_195 = len_4_sysvq0asl(X60Qdesugar_4);
  NI32 X60Qx_196 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_190 + X60Qx_191)) + X60Qx_192)) + X60Qx_193)) + X60Qx_194)) + X60Qx_195)) + X60Qx_196)));
  add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_2);
  add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_3);
  add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
  add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&(*(*vm_1).d_00.sink_0).d_00.errBuf_0), X60Qdesugar_5);
  string_0_sysvq0asl X60Qdesugar_6 = dollarQ_2_sysvq0asl(idx_0);
  string_0_sysvq0asl X60Qdesugar_7 = dollarQ_2_sysvq0asl(lo_0);
  string_0_sysvq0asl X60Qdesugar_8 = dollarQ_2_sysvq0asl(hi_0);
  NI32 X60Qx_197 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  NI32 X60Qx_198 = len_4_sysvq0asl(X60Qdesugar_6);
  NI32 X60Qx_199 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  NI32 X60Qx_200 = len_4_sysvq0asl(X60Qdesugar_7);
  NI32 X60Qx_201 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_202 = len_4_sysvq0asl(X60Qdesugar_8);
  string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_197 + X60Qx_198)) + X60Qx_199)) + X60Qx_200)) + X60Qx_201)) + X60Qx_202)));
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_6);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_7);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_8);
  Value_0_valzr1t4f* X60Qlhs_13 = (&(*vm_1).d_00.excVal_0);
  Value_0_valzr1t4f X60Qlhs_14 = vStr_0_valzr1t4f(X60Qdesugar_9);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_13)));
  (*X60Qlhs_13) = X60Qlhs_14;
  (*vm_1).d_00.raised_0 = NIM_TRUE;
  nimStrDestroy(X60Qdesugar_9);
  nimStrDestroy(X60Qdesugar_8);
  nimStrDestroy(X60Qdesugar_7);
  nimStrDestroy(X60Qdesugar_6);
  nimStrDestroy(X60Qdesugar_5);
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);}
void vmRaiseDivByZero_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_2){
  if ((*vm_2).d_00.raised_0){
    return;}
  add_2_sysvq0asl((&(*(*vm_2).d_00.sink_0).d_00.errBuf_0), (string_0_sysvq0asl){
    .bytes_0 = 1986618622u, .more_0 = (&strlit_0_I8786502555998912973_vmtuaxp6)}
  );
  Value_0_valzr1t4f* X60Qlhs_15 = (&(*vm_2).d_00.excVal_0);
  Value_0_valzr1t4f X60Qlhs_16 = vStr_0_valzr1t4f((string_0_sysvq0asl){
    .bytes_0 = 1986618622u, .more_0 = (&strlit_0_I10919355893625115164_vmtuaxp6)}
  );
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_15)));
  (*X60Qlhs_15) = X60Qlhs_16;
  (*vm_2).d_00.raised_0 = NIM_TRUE;}
NB8 vmBoundsRaise_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_3, string_0_sysvq0asl name_0, seq_0_I50urnw_chu5m1rja1 cargs_0){
  NB8 result_10;
  NB8 X60Qx_203;
  NB8 X60Qx_204 = eqQ_20_sysvq0asl(name_0, (string_0_sysvq0asl){
    .bytes_0 = 6118146u, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_204)){
    X60Qx_203 = NIM_TRUE;}
  else {
    NI32 X60Qx_205 = len_3_I4n9kvq_comaa5xpt1(cargs_0);
    X60Qx_203 = (X60Qx_205 < 2);}
  if (X60Qx_203){
    return NIM_FALSE;}
  Value_0_valzr1t4f* X60Qx_206 = getQ_7_Ine8yq71_natd5co251(cargs_0, 0);
  Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_206);
  Value_0_valzr1t4f rv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
  NB8 X60Qx_207;
  if (rv_0.kind_0 == 13){
    X60Qx_207 = (!(rv_0.loc_0 == NIM_NIL));}
  else {
    X60Qx_207 = NIM_FALSE;}
  if (X60Qx_207){
    Value_0_valzr1t4f X60Qlhs_17 = rv_0;
    Value_0_valzr1t4f X60Qx_208 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_0.loc_0).d_00.v_0));
    rv_0 = X60Qx_208;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_17));}
  else {
    NB8 X60Qx_209;
    if (rv_0.kind_0 == 12){
      X60Qx_209 = (!(rv_0.rf_0 == NIM_NIL));}
    else {
      X60Qx_209 = NIM_FALSE;}
    if (X60Qx_209){
      Value_0_valzr1t4f X60Qlhs_18 = rv_0;
      Value_0_valzr1t4f X60Qx_210 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_0.rf_0).d_00.v_0));
      rv_0 = X60Qx_210;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_18));}}
  Value_0_valzr1t4f* X60Qx_211 = getQ_7_Ine8yq71_natd5co251(cargs_0, 1);
  Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_211);
  NI64 X60Qx_212 = asInt_0_valzr1t4f((&X60QconstRefTemp_1));
  NI32 i_7 = ((NI32)X60Qx_212);
  switch (rv_0.kind_0){
    case 8:
    {
      NB8 X60Qx_213;
      if ((!(rv_0.sq_0 == NIM_NIL))){
        NB8 X60Qx_214;
        if (i_7 < 0){
          X60Qx_214 = NIM_TRUE;}
        else {
          X60Qx_214 = ((*rv_0.sq_0).d_00.elems_0.len_0 <= i_7);}
        X60Qx_213 = X60Qx_214;}
      else {
        X60Qx_213 = NIM_FALSE;}
      if (X60Qx_213){
        NI32 X60Qx_215 = len_3_I83dzei_flaksyopx1((*rv_0.sq_0).d_00.elems_0);
        vmRaiseIndexDefect_0_vmtuaxp6(vm_3, i_7, 0, ((NI32)(X60Qx_215 - 1)));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
        return NIM_TRUE;}}
    break;
    case 9:
    {
      if ((!(rv_0.arr_0 == NIM_NIL))){
        NI32 lo_1 = (*rv_0.arr_0).d_00.lo_0;
        NI32 X60Qx_216 = len_3_I83dzei_flaksyopx1((*rv_0.arr_0).d_00.elems_0);
        NI32 hi_1 = ((NI32)(((NI32)(lo_1 + X60Qx_216)) - 1));
        NB8 X60Qx_217;
        if (i_7 < lo_1){
          X60Qx_217 = NIM_TRUE;}
        else {
          X60Qx_217 = (hi_1 < i_7);}
        if (X60Qx_217){
          vmRaiseIndexDefect_0_vmtuaxp6(vm_3, i_7, lo_1, hi_1);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
          return NIM_TRUE;}}}
    break;
    default:
    {
      }
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
  return NIM_FALSE;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
  return result_10;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
  return result_10;}
Value_0_valzr1t4f setCombine_0_vmtuaxp6(Value_0_valzr1t4f* a_0, Value_0_valzr1t4f* b_0, NI32 mode_0){
  Value_0_valzr1t4f result_11;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  void* X60Qx_218 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689));
  X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* X60Qtmp_19 = ((X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689*)X60Qx_218);
  (*X60Qtmp_19) = (X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689){
    .r_00 = 0, .d_00 = (SetBox_Obj_0_valzr1t4f){
      .words_0 = (X60Qt_0_IAarrayAuS64ZS4_runot4689){
        .a = {
          ((NU64)0u), ((NU64)0), ((NU64)0), ((NU64)0)}}}}
  ;
  X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* sb_0 = X60Qtmp_19;
  NB8 X60Qx_219;
  if ((*a_0).kind_0 == 14){
    X60Qx_219 = ((*b_0).kind_0 == 14);}
  else {
    X60Qx_219 = NIM_FALSE;}
  if (X60Qx_219){
    NI32 i_8 = 0;
    {
      while (i_8 < 4){
        switch (mode_0){
          case 0:
          {
            NI32 X60Qx_220 = nimIcheckB(i_8, 3);
            NI32 X60Qx_221 = nimIcheckB(i_8, 3);
            NI32 X60Qx_222 = nimIcheckB(i_8, 3);
            (*sb_0).d_00.words_0.a[X60Qx_220] = ((NU64)((*(*a_0).st_0).d_00.words_0.a[X60Qx_221] | (*(*b_0).st_0).d_00.words_0.a[X60Qx_222]));}
          break;
          case 1:
          {
            NI32 X60Qx_223 = nimIcheckB(i_8, 3);
            NI32 X60Qx_224 = nimIcheckB(i_8, 3);
            NI32 X60Qx_225 = nimIcheckB(i_8, 3);
            (*sb_0).d_00.words_0.a[X60Qx_223] = ((NU64)((*(*a_0).st_0).d_00.words_0.a[X60Qx_224] & ((NU64) ~ (*(*b_0).st_0).d_00.words_0.a[X60Qx_225])));}
          break;
          case 2:
          {
            NI32 X60Qx_226 = nimIcheckB(i_8, 3);
            NI32 X60Qx_227 = nimIcheckB(i_8, 3);
            NI32 X60Qx_228 = nimIcheckB(i_8, 3);
            (*sb_0).d_00.words_0.a[X60Qx_226] = ((NU64)((*(*a_0).st_0).d_00.words_0.a[X60Qx_227] & (*(*b_0).st_0).d_00.words_0.a[X60Qx_228]));}
          break;
          default:
          {
            NI32 X60Qx_229 = nimIcheckB(i_8, 3);
            NI32 X60Qx_230 = nimIcheckB(i_8, 3);
            NI32 X60Qx_231 = nimIcheckB(i_8, 3);
            (*sb_0).d_00.words_0.a[X60Qx_229] = ((NU64)((*(*a_0).st_0).d_00.words_0.a[X60Qx_230] ^ (*(*b_0).st_0).d_00.words_0.a[X60Qx_231]));}
          break;}
        inc_1_I6wjjge_aow2h993l1((&i_8));}}
    whileStmtLabel_0: ;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* X60Qtmp_20 = sb_0;
  eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&sb_0));
  result_11 = (Value_0_valzr1t4f){
    .kind_0 = 14, .st_0 = X60Qtmp_20}
  ;
  eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(sb_0);
  return result_11;
  eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(sb_0);
  return result_11;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* captureFrameEnv_0_vmtuaxp6(seq_0_Iw8xl5b1_flaksyopx1 locals_1, seq_0_In6doa_ast8ri79k slotSyms_1, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_4){
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* result_12;
  eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6((&result_12));
  eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(result_12);
  void* X60Qx_232 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1));
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qtmp_21 = ((X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1*)X60Qx_232);
  seq_0_In6doa_ast8ri79k X60Qx_233 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_234 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  (*X60Qtmp_21) = (X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1){
    .r_00 = 0, .d_00 = (ClosureEnv_Obj_0_valzr1t4f){
      .vars_0 = X60Qx_233, .cells_0 = X60Qx_234, .coro_0 = NIM_NIL, .dest_0 = NIM_NIL}}
  ;
  result_12 = X60Qtmp_21;
  NI32 i_9 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_235;
      NI32 X60Qx_236 = len_3_I6y2imo_buiyylk1h1(slotSyms_1);
      if (i_9 < X60Qx_236){
        NI32 X60Qx_237 = len_3_I83dzei_flaksyopx1(locals_1);
        X60Qx_235 = (i_9 < X60Qx_237);}
      else {
        X60Qx_235 = NIM_FALSE;}
      if (X60Qx_235){
        NU32* X60Qx_238 = getQ_7_I2v00yv1_buiyylk1h1(slotSyms_1, i_9);
        NB8 X60Qx_239 = eqQ_0_nifh7u8pu1((*X60Qx_238), ((NU32)0u));
        if ((!X60Qx_239)){
          NU32* X60Qx_240 = getQ_7_I2v00yv1_buiyylk1h1(slotSyms_1, i_9);
          add_0_I34il1q_comaa5xpt1((&(*result_12).d_00.vars_0), (*X60Qx_240));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_241 = getQ_7_Ii14ync1_flaksyopx1(locals_1, i_9);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_242 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_241));
          add_0_Ijpw0mu_flaksyopx1((&(*result_12).d_00.cells_0), X60Qx_242);}
        inc_1_I6wjjge_aow2h993l1((&i_9));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if ((!(env_4 == NIM_NIL))){
    i_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_243 = len_3_I6y2imo_buiyylk1h1((*env_4).d_00.vars_0);
        if (i_9 < X60Qx_243){
          NU32* X60Qx_244 = getQ_7_I2v00yv1_buiyylk1h1((*env_4).d_00.vars_0, i_9);
          add_0_I34il1q_comaa5xpt1((&(*result_12).d_00.vars_0), (*X60Qx_244));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_245 = getQ_7_Ii14ync1_flaksyopx1((*env_4).d_00.cells_0, i_9);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_246 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_245));
          add_0_Ijpw0mu_flaksyopx1((&(*result_12).d_00.cells_0), X60Qx_246);
          inc_1_I6wjjge_aow2h993l1((&i_9));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  return result_12;}
NU32 contFieldSymVm_0_vmtuaxp6(string_0_sysvq0asl name_1){
  NU32 result_13;
  string_0_sysvq0asl X60Qtmp_22 = ampQ_0_sysvq0asl(name_1, (string_0_sysvq0asl){
    .bytes_0 = 3157506u, .more_0 = NIM_NIL}
  );
  NU32 X60Qx_247 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), X60Qtmp_22);
  result_13 = X60Qx_247;
  nimStrDestroy(X60Qtmp_22);
  return result_13;
  nimStrDestroy(X60Qtmp_22);
  return result_13;}
Value_0_valzr1t4f buildContVm_0_vmtuaxp6(Value_0_valzr1t4f* fnVal_0, Value_0_valzr1t4f* envVal_0){
  Value_0_valzr1t4f result_14;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  void* X60Qx_248 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_23 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_248);
  NU32 X60Qx_34 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), (string_0_sysvq0asl){
    .bytes_0 = 1852785662u, .more_0 = (&strlit_0_I16529829149455363342_buiyylk1h1)}
  );
  NU32 X60Qx_249 = contFieldSymVm_0_vmtuaxp6((string_0_sysvq0asl){
    .bytes_0 = 7235074u, .more_0 = NIM_NIL}
  );
  NU32 X60Qx_250 = contFieldSymVm_0_vmtuaxp6((string_0_sysvq0asl){
    .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
  );
  seq_0_In6doa_ast8ri79k X60Qx_35 = atQ_0_Il22x2g_vmtuaxp6((X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S2_vmtuaxp6){
    .a = {
      X60Qx_249, X60Qx_250}}
  );
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_24 = newCell_0_valzr1t4f((&(*fnVal_0)));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_25 = newCell_0_valzr1t4f((&(*envVal_0)));
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_36 = atQ_0_Ikzen43_vmtuaxp6((X60Qt_0_IAarrayArefSX43ellX4fbj0valzr1t4fZS2_vmtuaxp6){
    .a = {
      X60Qtmp_24, X60Qtmp_25}}
  );
  (*X60Qtmp_23) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
      .typeSym_0 = X60Qx_34, .names_0 = X60Qx_35, .cells_0 = X60Qx_36}}
  ;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_3 = X60Qtmp_23;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_26 = box_3;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_3));
  result_14 = (Value_0_valzr1t4f){
    .kind_0 = 11, .obj_0 = X60Qtmp_26}
  ;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_3);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_25);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_24);
  return result_14;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_3);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_25);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_24);
  return result_14;}
NB8 envEqVm_0_vmtuaxp6(Value_0_valzr1t4f* a_1, Value_0_valzr1t4f* b_1){
  NB8 result_15;
  NB8 X60Qx_251;
  if ((*a_1).kind_0 == 13){
    X60Qx_251 = ((*b_1).kind_0 == 13);}
  else {
    X60Qx_251 = NIM_FALSE;}
  if (X60Qx_251){
    result_15 = ((*a_1).loc_0 == (*b_1).loc_0);}
  else {
    NB8 X60Qx_252;
    if ((*a_1).kind_0 == 0){
      X60Qx_252 = ((*b_1).kind_0 == 0);}
    else {
      X60Qx_252 = NIM_FALSE;}
    if (X60Qx_252){
      result_15 = NIM_TRUE;}
    else {
      result_15 = NIM_FALSE;}}
  return result_15;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 scheduledStep_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_11, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* co_0){
  X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 result_16;
  eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&result_16));
  if ((*co_0).d_00.myEnvCell_0 == NIM_NIL){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_27 = (&(*co_0).d_00.myEnvCell_0);
    Value_0_valzr1t4f X60Qtmp_29 = vNil_0_valzr1t4f();
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_28 = newCell_0_valzr1t4f((&X60Qtmp_29));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qlhs_27));
    (*X60Qlhs_27) = X60Qlhs_28;
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_30 = (&(*co_0).d_00.destCell_0);
    Value_0_valzr1t4f X60Qtmp_32 = vNil_0_valzr1t4f();
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_31 = newCell_0_valzr1t4f((&X60Qtmp_32));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qlhs_30));
    (*X60Qlhs_30) = X60Qlhs_31;
    Value_0_valzr1t4f* X60Qlhs_33 = (&(*co_0).d_00.stepFn_0);
    void* X60Qx_253 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1));
    X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qtmp_35 = ((X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1*)X60Qx_253);
    seq_0_In6doa_ast8ri79k X60Qx_254 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
    seq_0_Iw8xl5b1_flaksyopx1 X60Qx_255 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
    X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_256 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(co_0);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_257 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*co_0).d_00.destCell_0);
    (*X60Qtmp_35) = (X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1){
      .r_00 = 0, .d_00 = (ClosureEnv_Obj_0_valzr1t4f){
        .vars_0 = X60Qx_254, .cells_0 = X60Qx_255, .coro_0 = ((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)X60Qx_256), .dest_0 = X60Qx_257}}
    ;
    Value_0_valzr1t4f X60Qlhs_34 = (Value_0_valzr1t4f){
      .kind_0 = 15, .fn_0 = ((NU32)0u), .pidx_0 = -1, .env_0 = X60Qtmp_35, .resume_0 = ((NI32)0)}
    ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_33)));
    (*X60Qlhs_33) = X60Qlhs_34;
    Value_0_valzr1t4f* X60Qlhs_36 = (&(*co_0).d_00.itVal_0);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_258 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*co_0).d_00.myEnvCell_0);
    Value_0_valzr1t4f X60Qtmp_38 = (Value_0_valzr1t4f){
      .kind_0 = 13, .loc_0 = X60Qx_258, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
    ;
    Value_0_valzr1t4f X60Qlhs_37 = buildContVm_0_vmtuaxp6((&(*co_0).d_00.stepFn_0), (&X60Qtmp_38));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_36)));
    (*X60Qlhs_36) = X60Qlhs_37;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_38));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_32));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_29));}
  {
    while (NIM_TRUE){
      if ((*(*vm_11).d_00.sink_0).d_00.didQQuit_0){
        Value_0_valzr1t4f X60Qx_259 = vNil_0_valzr1t4f();
        result_16 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
          .fld_0 = X60Qx_259, .fld_1 = NIM_TRUE}
        ;
        return result_16;}
      Value_0_valzr1t4f* X60Qlhs_39 = (&(*co_0).d_00.itVal_0);
      X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6 X60QconstRefTemp_0 = (X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6){
        .a = {
          (*co_0).d_00.itVal_0}}
      ;
      seq_0_I50urnw_chu5m1rja1 X60Qtmp_41 = atQ_0_I4e31uy1_vmtuaxp6((&X60QconstRefTemp_0));
      Value_0_valzr1t4f X60Qlhs_40 = runProc_1_vmtuaxp6(vm_11, (*vm_11).d_00.scheduler_0.pidx_0, X60Qtmp_41, (*vm_11).d_00.scheduler_0.env_0);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_39)));
      (*X60Qlhs_39) = X60Qlhs_40;
      if ((*vm_11).d_00.raised_0){
        Value_0_valzr1t4f X60Qx_260 = vNil_0_valzr1t4f();
        result_16 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
          .fld_0 = X60Qx_260, .fld_1 = NIM_TRUE}
        ;
        eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_41);
        return result_16;}
      Value_0_valzr1t4f X60Qtmp_42 = contFieldVm_1_vmtuaxp6((&(*co_0).d_00.itVal_0), (string_0_sysvq0asl){
        .bytes_0 = 7235074u, .more_0 = NIM_NIL}
      );
      if (X60Qtmp_42.kind_0 == 0){
        Value_0_valzr1t4f X60Qx_261 = vNil_0_valzr1t4f();
        result_16 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
          .fld_0 = X60Qx_261, .fld_1 = NIM_TRUE}
        ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_42));
        eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_41);
        return result_16;}
      Value_0_valzr1t4f X60Qtmp_43 = contFieldVm_1_vmtuaxp6((&(*co_0).d_00.itVal_0), (string_0_sysvq0asl){
        .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
      );
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_262 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*co_0).d_00.myEnvCell_0);
      Value_0_valzr1t4f X60Qtmp_44 = (Value_0_valzr1t4f){
        .kind_0 = 13, .loc_0 = X60Qx_262, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
      ;
      NB8 X60Qx_263 = envEqVm_0_vmtuaxp6((&X60Qtmp_43), (&X60Qtmp_44));
      if (X60Qx_263){
        Value_0_valzr1t4f X60Qx_264 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*co_0).d_00.destCell_0).d_00.v_0));
        result_16 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
          .fld_0 = X60Qx_264, .fld_1 = NIM_FALSE}
        ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_44));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_43));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_42));
        eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_41);
        return result_16;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_44));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_43));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_42));
      eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_41);}}
  whileStmtLabel_0: ;
  return result_16;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* envCellOf_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_5, NU32 s_2){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_17;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&result_17));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(result_17);
  result_17 = NIM_NIL;
  if (env_5 == NIM_NIL){
    return result_17;}
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_265 = len_3_I6y2imo_buiyylk1h1((*env_5).d_00.vars_0);
      if (i_10 < X60Qx_265){
        NU32* X60Qx_266 = getQ_7_I2v00yv1_buiyylk1h1((*env_5).d_00.vars_0, i_10);
        NB8 X60Qx_267 = eqQ_0_nifh7u8pu1((*X60Qx_266), s_2);
        if (X60Qx_267){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_268 = getQ_7_Ii14ync1_flaksyopx1((*env_5).d_00.cells_0, i_10);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_269 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_268));
          result_17 = X60Qx_269;
          return result_17;}
        inc_1_I6wjjge_aow2h993l1((&i_10));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_17;}
Value_0_valzr1t4f callNativeVM_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_12, string_0_sysvq0asl name_3, seq_0_I50urnw_chu5m1rja1 args_3){
  Value_0_valzr1t4f result_18;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  if (1 <= args_3.len_0){
    NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(name_3, 1, (NC8)'e');
    if (X60Qtc_6){
      NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(name_3, 2, (NC8)'o');
      if (X60Qtc_7){
        if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1701068286u, .more_0 = (&strlit_0_I10157464168546919252_comaa5xpt1)}
        )){
          goto X60Qsc_1;}
        else if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1868774910u, .more_0 = (&strlit_0_I14683201540015467042_comaa5xpt1)}
        )){
          goto X60Qsc_4;}}
      else {
        if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11023901819970991276_comaa5xpt1)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1969503742u, .more_0 = (&strlit_0_I11614359337083319489_comaa5xpt1)}
        )){
          goto X60Qsc_2;}}}
    else {
      NB8 X60Qtc_8 = nimStrAtLe_0_sysvq0asl(name_3, 1, (NC8)'t');
      if (X60Qtc_8){
        if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1920220670u, .more_0 = (&strlit_0_I7262382801534885590_comaa5xpt1)}
        )){
          goto X60Qsc_1;}
        else if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1769160190u, .more_0 = (&strlit_0_I17069683611453604721_comaa5xpt1)}
        )){
          goto X60Qsc_5;}}
      else {
        if (equalStrings_0_sysvq0asl(name_3, (string_0_sysvq0asl){
          .bytes_0 = 1635204606u, .more_0 = (&strlit_0_I9151517089334711309_comaa5xpt1)}
        )){
          goto X60Qsc_3;}}}
    goto X60Qsc_10;
    X60Qsc_0: ;
    Value_0_valzr1t4f* X60Qlhs_45 = (&(*vm_12).d_00.scheduler_0);
    Value_0_valzr1t4f X60Qlhs_46 = (*vm_12).d_00.scheduler_0;
    Value_0_valzr1t4f* X60Qx_270 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_270);
    Value_0_valzr1t4f X60Qx_271 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
    (*X60Qlhs_45) = X60Qx_271;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_46));
    Value_0_valzr1t4f X60Qx_272 = vNil_0_valzr1t4f();
    result_18 = X60Qx_272;
    return result_18;
    goto X60Qsc_9;
    X60Qsc_1: ;
    Value_0_valzr1t4f X60Qx_273 = vNil_0_valzr1t4f();
    result_18 = X60Qx_273;
    return result_18;
    goto X60Qsc_9;
    X60Qsc_2: ;
    Value_0_valzr1t4f* X60Qx_274 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_274);
    Value_0_valzr1t4f s_13 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_1));
    NB8 X60Qx_275;
    if (s_13.kind_0 == 13){
      X60Qx_275 = (!(s_13.loc_0 == NIM_NIL));}
    else {
      X60Qx_275 = NIM_FALSE;}
    if (X60Qx_275){
      Value_0_valzr1t4f X60Qlhs_47 = s_13;
      Value_0_valzr1t4f X60Qx_276 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*s_13.loc_0).d_00.v_0));
      s_13 = X60Qx_276;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_47));}
    Value_0_valzr1t4f X60Qx_277 = deepCopyValue_0_valzr1t4f((&s_13));
    result_18 = X60Qx_277;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_13));
    return result_18;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_13));
    goto X60Qsc_9;
    X60Qsc_3: ;
    NB8 X60Qx_278;
    Value_0_valzr1t4f* X60Qx_279 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    if ((*X60Qx_279).kind_0 == 13){
      Value_0_valzr1t4f* X60Qx_280 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_278 = (!((*X60Qx_280).loc_0 == NIM_NIL));}
    else {
      X60Qx_278 = NIM_FALSE;}
    if (X60Qx_278){
      Value_0_valzr1t4f* X60Qx_281 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      Value_0_valzr1t4f* X60Qlhs_48 = (&(*(*X60Qx_281).loc_0).d_00.v_0);
      Value_0_valzr1t4f* X60Qx_282 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      Value_0_valzr1t4f X60Qlhs_49 = detachedDefault_0_valzr1t4f((&(*(*X60Qx_282).loc_0).d_00.v_0));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_48)));
      (*X60Qlhs_48) = X60Qlhs_49;}
    Value_0_valzr1t4f X60Qx_283 = vNil_0_valzr1t4f();
    result_18 = X60Qx_283;
    return result_18;
    goto X60Qsc_9;
    X60Qsc_4: ;
    NB8 X60Qx_284;
    NB8 X60Qx_285;
    if (2 <= args_3.len_0){
      Value_0_valzr1t4f* X60Qx_286 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_285 = ((*X60Qx_286).kind_0 == 13);}
    else {
      X60Qx_285 = NIM_FALSE;}
    if (X60Qx_285){
      Value_0_valzr1t4f* X60Qx_287 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_284 = (!((*X60Qx_287).loc_0 == NIM_NIL));}
    else {
      X60Qx_284 = NIM_FALSE;}
    if (X60Qx_284){
      Value_0_valzr1t4f* X60Qx_288 = getQ_7_Ine8yq71_natd5co251(args_3, 1);
      Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_288);
      Value_0_valzr1t4f s_14 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_2));
      NB8 X60Qx_289;
      if (s_14.kind_0 == 13){
        X60Qx_289 = (!(s_14.loc_0 == NIM_NIL));}
      else {
        X60Qx_289 = NIM_FALSE;}
      if (X60Qx_289){
        Value_0_valzr1t4f X60Qlhs_50 = s_14;
        Value_0_valzr1t4f X60Qx_290 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*s_14.loc_0).d_00.v_0));
        s_14 = X60Qx_290;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_50));}
      Value_0_valzr1t4f* X60Qx_291 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      Value_0_valzr1t4f* X60Qlhs_51 = (&(*(*X60Qx_291).loc_0).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_52 = deepCopyValue_0_valzr1t4f((&s_14));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_51)));
      (*X60Qlhs_51) = X60Qlhs_52;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_14));}
    Value_0_valzr1t4f X60Qx_292 = vNil_0_valzr1t4f();
    result_18 = X60Qx_292;
    return result_18;
    goto X60Qsc_9;
    X60Qsc_5: ;
    NB8 X60Qx_293;
    NB8 X60Qx_294;
    if (2 <= args_3.len_0){
      Value_0_valzr1t4f* X60Qx_295 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_294 = ((*X60Qx_295).kind_0 == 13);}
    else {
      X60Qx_294 = NIM_FALSE;}
    if (X60Qx_294){
      Value_0_valzr1t4f* X60Qx_296 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_293 = (!((*X60Qx_296).loc_0 == NIM_NIL));}
    else {
      X60Qx_293 = NIM_FALSE;}
    if (X60Qx_293){
      Value_0_valzr1t4f* X60Qx_297 = getQ_7_Ine8yq71_natd5co251(args_3, 1);
      Value_0_valzr1t4f X60QconstRefTemp_3 = (*X60Qx_297);
      Value_0_valzr1t4f s_15 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_3));
      NB8 X60Qx_298;
      if (s_15.kind_0 == 13){
        X60Qx_298 = (!(s_15.loc_0 == NIM_NIL));}
      else {
        X60Qx_298 = NIM_FALSE;}
      if (X60Qx_298){
        Value_0_valzr1t4f X60Qlhs_53 = s_15;
        Value_0_valzr1t4f X60Qx_299 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*s_15.loc_0).d_00.v_0));
        s_15 = X60Qx_299;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_53));}
      Value_0_valzr1t4f* X60Qx_300 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      Value_0_valzr1t4f* X60Qlhs_54 = (&(*(*X60Qx_300).loc_0).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_55 = s_15;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_15));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_54)));
      (*X60Qlhs_54) = X60Qlhs_55;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_15));}
    Value_0_valzr1t4f X60Qx_301 = vNil_0_valzr1t4f();
    result_18 = X60Qx_301;
    return result_18;
    goto X60Qsc_9;
    X60Qsc_10: ;
    X60Qsc_9: ;}
  NB8 X60Qx_302;
  NB8 X60Qx_303 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I6420956111249849549_vmtuaxp6)}
  );
  if (X60Qx_303){
    X60Qx_302 = (4 <= args_3.len_0);}
  else {
    X60Qx_302 = NIM_FALSE;}
  if (X60Qx_302){
    NB8 X60Qx_37;
    Value_0_valzr1t4f* X60Qx_304 = getQ_7_Ine8yq71_natd5co251(args_3, 2);
    if ((*X60Qx_304).kind_0 == 15){
      Value_0_valzr1t4f* X60Qx_305 = getQ_7_Ine8yq71_natd5co251(args_3, 2);
      string_0_sysvq0asl X60Qtmp_56 = mBaseName_1_vmtuaxp6((*X60Qx_305).fn_0);
      NB8 X60Qx_306 = eqQ_20_sysvq0asl(X60Qtmp_56, (string_0_sysvq0asl){
        .bytes_0 = 1919907838u, .more_0 = (&strlit_0_I2011743623608043438_vmtuaxp6)}
      );
      X60Qx_37 = (!X60Qx_306);
      nimStrDestroy(X60Qtmp_56);}
    else {
      X60Qx_37 = NIM_FALSE;}
    if (X60Qx_37){
      Value_0_valzr1t4f* X60Qx_307 = getQ_7_Ine8yq71_natd5co251(args_3, 3);
      X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6 X60QconstRefTemp_4 = (X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6){
        .a = {
          (*X60Qx_307)}}
      ;
      seq_0_I50urnw_chu5m1rja1 X60Qtmp_58 = atQ_0_I4e31uy1_vmtuaxp6((&X60QconstRefTemp_4));
      Value_0_valzr1t4f* X60Qx_308 = getQ_7_Ine8yq71_natd5co251(args_3, 2);
      Value_0_valzr1t4f X60Qtmp_57 = runProc_1_vmtuaxp6(vm_12, (*X60Qx_308).pidx_0, X60Qtmp_58, NIM_NIL);
      Value_0_valzr1t4f X60Qx_309 = X60Qtmp_57;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_57));
      eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_58);}
    Value_0_valzr1t4f X60Qx_310 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_18 = X60Qx_310;
    return result_18;}
  NB8 X60Qx_311 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I15944996171862775263_vmtuaxp6)}
  );
  if (X60Qx_311){
    Value_0_valzr1t4f X60Qx_312 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_18 = X60Qx_312;
    return result_18;}
  NB8 X60Qx_313;
  NB8 X60Qx_314 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1768843774u, .more_0 = (&strlit_0_I15541155848264557133_comaa5xpt1)}
  );
  if (X60Qx_314){
    X60Qx_313 = NIM_TRUE;}
  else {
    NB8 X60Qx_315 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
      .bytes_0 = 1936614910u, .more_0 = (&strlit_0_I3798637678053249641_comaa5xpt1)}
    );
    X60Qx_313 = X60Qx_315;}
  if (X60Qx_313){
    (*vm_12).d_00.poolStoppedFlag_0 = NIM_FALSE;
    Value_0_valzr1t4f X60Qx_316 = vNil_0_valzr1t4f();
    result_18 = X60Qx_316;
    return result_18;}
  NB8 X60Qx_317;
  NB8 X60Qx_318;
  NB8 X60Qx_319;
  NB8 X60Qx_320 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1651864574u, .more_0 = (&strlit_0_I16581638230773281198_comaa5xpt1)}
  );
  if (X60Qx_320){
    X60Qx_319 = NIM_TRUE;}
  else {
    NB8 X60Qx_321 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I1232877487365112244_comaa5xpt1)}
    );
    X60Qx_319 = X60Qx_321;}
  if (X60Qx_319){
    X60Qx_318 = (1 <= args_3.len_0);}
  else {
    X60Qx_318 = NIM_FALSE;}
  if (X60Qx_318){
    NB8 X60Qx_322;
    NB8 X60Qx_323;
    NB8 X60Qx_324;
    Value_0_valzr1t4f* X60Qx_325 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    if ((*X60Qx_325).kind_0 == 11){
      X60Qx_324 = NIM_TRUE;}
    else {
      Value_0_valzr1t4f* X60Qx_326 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_324 = ((*X60Qx_326).kind_0 == 12);}
    if (X60Qx_324){
      X60Qx_323 = NIM_TRUE;}
    else {
      Value_0_valzr1t4f* X60Qx_327 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_323 = ((*X60Qx_327).kind_0 == 17);}
    if (X60Qx_323){
      X60Qx_322 = NIM_TRUE;}
    else {
      Value_0_valzr1t4f* X60Qx_328 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      X60Qx_322 = ((*X60Qx_328).kind_0 == 13);}
    X60Qx_317 = X60Qx_322;}
  else {
    X60Qx_317 = NIM_FALSE;}
  if (X60Qx_317){
    Value_0_valzr1t4f* X60Qx_329 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    Value_0_valzr1t4f X60QconstRefTemp_5 = (*X60Qx_329);
    drivePoolContVm_1_vmtuaxp6(vm_12, (&X60QconstRefTemp_5));
    Value_0_valzr1t4f X60Qx_330 = vNil_0_valzr1t4f();
    result_18 = X60Qx_330;
    return result_18;}
  NB8 X60Qx_331;
  NB8 X60Qx_332;
  NB8 X60Qx_333 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I13045133590002807130_comaa5xpt1)}
  );
  if (X60Qx_333){
    X60Qx_332 = (1 <= args_3.len_0);}
  else {
    X60Qx_332 = NIM_FALSE;}
  if (X60Qx_332){
    Value_0_valzr1t4f* X60Qx_334 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    X60Qx_331 = ((*X60Qx_334).kind_0 == 17);}
  else {
    X60Qx_331 = NIM_FALSE;}
  if (X60Qx_331){
    Value_0_valzr1t4f* X60Qx_335 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
    if ((!((*X60Qx_335).coro_0 == NIM_NIL))){
      Value_0_valzr1t4f* X60Qx_336 = getQ_7_Ine8yq71_natd5co251(args_3, 0);
      drivePassiveVm_1_vmtuaxp6(vm_12, ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)(*X60Qx_336).coro_0));}
    Value_0_valzr1t4f X60Qx_337 = vNil_0_valzr1t4f();
    result_18 = X60Qx_337;
    return result_18;}
  NB8 X60Qx_338 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I12770529794932993973_comaa5xpt1)}
  );
  if (X60Qx_338){
    Value_0_valzr1t4f X60Qx_339 = vNil_0_valzr1t4f();
    result_18 = X60Qx_339;
    return result_18;}
  NB8 X60Qx_340 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1969779710u, .more_0 = (&strlit_0_I8602794362013704992_comaa5xpt1)}
  );
  if (X60Qx_340){
    (*vm_12).d_00.poolStoppedFlag_0 = NIM_TRUE;
    Value_0_valzr1t4f X60Qx_341 = vNil_0_valzr1t4f();
    result_18 = X60Qx_341;
    return result_18;}
  NB8 X60Qx_342 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1869574398u, .more_0 = (&strlit_0_I11010039520288330211_comaa5xpt1)}
  );
  if (X60Qx_342){
    Value_0_valzr1t4f X60Qx_343 = vBool_0_valzr1t4f((*vm_12).d_00.poolStoppedFlag_0);
    result_18 = X60Qx_343;
    return result_18;}
  NB8 X60Qx_344 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1869574398u, .more_0 = (&strlit_0_I10257712218960831919_comaa5xpt1)}
  );
  if (X60Qx_344){
    Value_0_valzr1t4f X60Qx_345 = vBool_0_valzr1t4f(NIM_FALSE);
    result_18 = X60Qx_345;
    return result_18;}
  NB8 X60Qx_346 = eqQ_20_sysvq0asl(name_3, (string_0_sysvq0asl){
    .bytes_0 = 1869637118u, .more_0 = (&strlit_0_I13023507668929764686_vmtuaxp6)}
  );
  if (X60Qx_346){
    Value_0_valzr1t4f X60Qx_347 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_18 = X60Qx_347;
    return result_18;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  Value_0_valzr1t4f X60Qx_348 = crossNativeValue_0_croph25r5((*vm_12).d_00.sink_0, name_3, args_3);
  result_18 = X60Qx_348;
  return result_18;}
Value_0_valzr1t4f contFieldVm_1_vmtuaxp6(Value_0_valzr1t4f* v_6, string_0_sysvq0asl name_4){
  Value_0_valzr1t4f result_19;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  Value_0_valzr1t4f X60Qx_349 = vNil_0_valzr1t4f();
  result_19 = X60Qx_349;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_4 = NIM_NIL;
  if ((*v_6).kind_0 == 11){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_4);
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_350 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*v_6).obj_0);
    box_4 = X60Qx_350;}
  else {
    NB8 X60Qx_351;
    NB8 X60Qx_352;
    if ((*v_6).kind_0 == 12){
      X60Qx_352 = (!((*v_6).rf_0 == NIM_NIL));}
    else {
      X60Qx_352 = NIM_FALSE;}
    if (X60Qx_352){
      X60Qx_351 = ((*(*v_6).rf_0).d_00.v_0.kind_0 == 11);}
    else {
      X60Qx_351 = NIM_FALSE;}
    if (X60Qx_351){
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_4);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_353 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((*(*v_6).rf_0).d_00.v_0.obj_0);
      box_4 = X60Qx_353;}}
  if ((!(box_4 == NIM_NIL))){
    string_0_sysvq0asl X60Qtmp_59 = ampQ_0_sysvq0asl(name_4, (string_0_sysvq0asl){
      .bytes_0 = 3157506u, .more_0 = NIM_NIL}
    );
    NU32 fsym_3 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), X60Qtmp_59);
    NI32 i_11 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_354 = len_3_I6y2imo_buiyylk1h1((*box_4).d_00.names_0);
        if (i_11 < X60Qx_354){
          NU32* X60Qx_355 = getQ_7_I2v00yv1_buiyylk1h1((*box_4).d_00.names_0, i_11);
          NB8 X60Qx_356 = eqQ_0_nifh7u8pu1((*X60Qx_355), fsym_3);
          if (X60Qx_356){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_357 = getQ_7_Ii14ync1_flaksyopx1((*box_4).d_00.cells_0, i_11);
            Value_0_valzr1t4f X60Qx_358 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_357)).d_00.v_0));
            result_19 = X60Qx_358;
            nimStrDestroy(X60Qtmp_59);
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_4);
            return result_19;}
          inc_1_I6wjjge_aow2h993l1((&i_11));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    nimStrDestroy(X60Qtmp_59);}
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_4);
  return result_19;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_4);
  return result_19;}
void drivePoolContVm_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_13, Value_0_valzr1t4f* cont_1){
  if ((*cont_1).kind_0 == 17){
    if ((!((*cont_1).coro_0 == NIM_NIL))){
      drivePassiveVm_1_vmtuaxp6(vm_13, ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)(*cont_1).coro_0));}
    return;}
  Value_0_valzr1t4f cur_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cont_1)));
  NB8 X60Qx_359;
  if (cur_0.kind_0 == 13){
    X60Qx_359 = (!(cur_0.loc_0 == NIM_NIL));}
  else {
    X60Qx_359 = NIM_FALSE;}
  if (X60Qx_359){
    Value_0_valzr1t4f X60Qlhs_60 = cur_0;
    Value_0_valzr1t4f X60Qx_360 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.loc_0).d_00.v_0));
    cur_0 = X60Qx_360;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_60));}
  NB8 X60Qx_361;
  if (cur_0.kind_0 == 12){
    X60Qx_361 = (!(cur_0.rf_0 == NIM_NIL));}
  else {
    X60Qx_361 = NIM_FALSE;}
  if (X60Qx_361){
    Value_0_valzr1t4f X60Qlhs_61 = cur_0;
    Value_0_valzr1t4f X60Qx_362 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.rf_0).d_00.v_0));
    cur_0 = X60Qx_362;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_61));}
  NI32 steps_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_363;
      if (cur_0.kind_0 == 11){
        X60Qx_363 = (!(cur_0.obj_0 == NIM_NIL));}
      else {
        X60Qx_363 = NIM_FALSE;}
      if (X60Qx_363){
        Value_0_valzr1t4f fnV_0 = contFieldVm_1_vmtuaxp6((&cur_0), (string_0_sysvq0asl){
          .bytes_0 = 7235074u, .more_0 = NIM_NIL}
        );
        if ((!(fnV_0.kind_0 == 15))){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fnV_0));
          goto whileStmtLabel_0;}
        Value_0_valzr1t4f envV_0 = contFieldVm_1_vmtuaxp6((&cur_0), (string_0_sysvq0asl){
          .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
        );
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cur_0));
        X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6 X60QconstRefTemp_0 = (X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6){
          .a = {
            envV_0}}
        ;
        seq_0_I50urnw_chu5m1rja1 X60Qtmp_62 = atQ_0_I4e31uy1_vmtuaxp6((&X60QconstRefTemp_0));
        Value_0_valzr1t4f X60Qx_364 = runProc_1_vmtuaxp6(vm_13, fnV_0.pidx_0, X60Qtmp_62, NIM_NIL);
        cur_0 = X60Qx_364;
        NB8 X60Qx_365;
        if (cur_0.kind_0 == 13){
          X60Qx_365 = (!(cur_0.loc_0 == NIM_NIL));}
        else {
          X60Qx_365 = NIM_FALSE;}
        if (X60Qx_365){
          Value_0_valzr1t4f X60Qlhs_63 = cur_0;
          Value_0_valzr1t4f X60Qx_366 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.loc_0).d_00.v_0));
          cur_0 = X60Qx_366;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_63));}
        NB8 X60Qx_367;
        if (cur_0.kind_0 == 12){
          X60Qx_367 = (!(cur_0.rf_0 == NIM_NIL));}
        else {
          X60Qx_367 = NIM_FALSE;}
        if (X60Qx_367){
          Value_0_valzr1t4f X60Qlhs_64 = cur_0;
          Value_0_valzr1t4f X60Qx_368 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.rf_0).d_00.v_0));
          cur_0 = X60Qx_368;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_64));}
        inc_1_I6wjjge_aow2h993l1((&steps_0));
        if (5000000 < steps_0){
          eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_62);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&envV_0));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fnV_0));
          goto whileStmtLabel_0;}
        eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_62);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&envV_0));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fnV_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cur_0));}
string_0_sysvq0asl mBaseName_1_vmtuaxp6(NU32 s_3){
  string_0_sysvq0asl result_20;
  nimStrWasMoved((&result_20));
  nimStrDestroy(result_20);
  string_0_sysvq0asl* X60Qx_369 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_3);
  string_0_sysvq0asl X60Qx_370 = nimStrDup((*X60Qx_369));
  result_20 = X60Qx_370;
  extractBasename_1_symkyk35i1((&result_20));
  return result_20;}
NI32 dispatchMethodVm_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_14, MethodSite_0_chu5m1rja1 site_0, Value_0_valzr1t4f* receiver_0){
  NI32 result_21;
  result_21 = site_0.fallbackIdx_0;
  NU32 concrete_0 = objTypeOf_0_runot4689((&(*receiver_0)));
  NB8 X60Qx_371 = eqQ_0_nifh7u8pu1(concrete_0, ((NU32)0u));
  if (X60Qx_371){
    return result_21;}
  string_0_sysvq0asl name_5 = mBaseName_1_vmtuaxp6(site_0.staticFn_0);
  NU32 sig_0 = ((NU32)0u);
  NB8 haveSig_0 = NIM_FALSE;
  {
    NU32 sc_0 = concrete_0;
    NI32 sd_0 = 0;
    {
      while (NIM_TRUE){
        NB8 X60Qx_372;
        if (sd_0 < 64){
          NB8 X60Qx_373 = eqQ_0_nifh7u8pu1(sc_0, ((NU32)0u));
          X60Qx_372 = (!X60Qx_373);}
        else {
          X60Qx_372 = NIM_FALSE;}
        if (X60Qx_372){
          {
            seq_0_Idl3iy1_comaa5xpt1 X60Qtmp_65 = loadVTable_0_vtanlalcx(sc_0);
            openArray_0_In1h8lr1_comaa5xpt1 X60Qlf_0 = toOpenArray_1_Ivm9z5a_comaa5xpt1(X60Qtmp_65);
            NI32 X60Qlf_1 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_374 = len_6_I8gnayb_comaa5xpt1(X60Qlf_0);
                if (X60Qlf_1 < X60Qx_374){
                  {
                    MethodIndexEntry_0_sempjk6bn1* X60Qii_3 = getQ_10_Izev5kw1_comaa5xpt1(X60Qlf_0, X60Qlf_1);
                    NB8 X60Qx_375 = eqQ_0_nifh7u8pu1((*X60Qii_3).fn_0, site_0.staticFn_0);
                    if (X60Qx_375){
                      sig_0 = (*X60Qii_3).signature_0;
                      haveSig_0 = NIM_TRUE;
                      eQdestroy_1_Iph9dp4_comaa5xpt1(X60Qtmp_65);
                      goto findSig_0;}}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            eQdestroy_1_Iph9dp4_comaa5xpt1(X60Qtmp_65);}
          forStmtLabel_1: ;
          NU32 b_2 = objBaseSym_0_runot4689(sc_0);
          NB8 X60Qx_376 = eqQ_0_nifh7u8pu1(b_2, sc_0);
          if (X60Qx_376){
            goto whileStmtLabel_0;}
          sc_0 = b_2;
          inc_1_I6wjjge_aow2h993l1((&sd_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  findSig_0: ;
  NU32 cur_1 = concrete_0;
  NI32 depth_0 = 0;
  NI32 genericIdx_0 = -1;
  {
    while (NIM_TRUE){
      NB8 X60Qx_377;
      if (depth_0 < 64){
        NB8 X60Qx_378 = eqQ_0_nifh7u8pu1(cur_1, ((NU32)0u));
        X60Qx_377 = (!X60Qx_378);}
      else {
        X60Qx_377 = NIM_FALSE;}
      if (X60Qx_377){
        seq_0_Idl3iy1_comaa5xpt1 vt_0 = loadVTable_0_vtanlalcx(cur_1);
        NI32 k_2 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_379 = len_3_Ikc9pid1_vmtuaxp6(vt_0);
            if (k_2 < X60Qx_379){
              NB8 X60Qx_38;
              NB8 X60Qx_380;
              if (haveSig_0){
                MethodIndexEntry_0_sempjk6bn1* X60Qx_381 = getQ_7_I7nrp45_vmtuaxp6(vt_0, k_2);
                NB8 X60Qx_382 = eqQ_1_nifh7u8pu1((*X60Qx_381).signature_0, sig_0);
                X60Qx_380 = X60Qx_382;}
              else {
                X60Qx_380 = NIM_FALSE;}
              if (X60Qx_380){
                X60Qx_38 = NIM_TRUE;}
              else {
                MethodIndexEntry_0_sempjk6bn1* X60Qx_383 = getQ_7_I7nrp45_vmtuaxp6(vt_0, k_2);
                string_0_sysvq0asl X60Qtmp_66 = mBaseName_1_vmtuaxp6((*X60Qx_383).fn_0);
                NB8 X60Qx_384 = eqQ_20_sysvq0asl(X60Qtmp_66, name_5);
                X60Qx_38 = X60Qx_384;
                nimStrDestroy(X60Qtmp_66);}
              if (X60Qx_38){
                NI32 i_13 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_385 = len_3_I2qk2yu1_comaa5xpt1((*vm_14).d_00.prog_0.methodTable_0);
                    if (i_13 < X60Qx_385){
                      MethodEntry_0_chu5m1rja1* X60Qx_386 = getQ_7_I8226yy1_comaa5xpt1((*vm_14).d_00.prog_0.methodTable_0, i_13);
                      MethodIndexEntry_0_sempjk6bn1* X60Qx_387 = getQ_7_I7nrp45_vmtuaxp6(vt_0, k_2);
                      NB8 X60Qx_388 = eqQ_0_nifh7u8pu1((*X60Qx_386).sym_0, (*X60Qx_387).fn_0);
                      if (X60Qx_388){
                        MethodIndexEntry_0_sempjk6bn1* X60Qx_389 = getQ_7_I7nrp45_vmtuaxp6(vt_0, k_2);
                        NB8 X60Qx_390 = isGenericRoutine_0_runot4689((*X60Qx_389).fn_0);
                        if (X60Qx_390){
                          if (genericIdx_0 < 0){
                            MethodEntry_0_chu5m1rja1* X60Qx_391 = getQ_7_I8226yy1_comaa5xpt1((*vm_14).d_00.prog_0.methodTable_0, i_13);
                            genericIdx_0 = (*X60Qx_391).idx_0;}}
                        else {
                          MethodEntry_0_chu5m1rja1* X60Qx_392 = getQ_7_I8226yy1_comaa5xpt1((*vm_14).d_00.prog_0.methodTable_0, i_13);
                          result_21 = (*X60Qx_392).idx_0;
                          eQdestroy_1_Iph9dp4_comaa5xpt1(vt_0);
                          nimStrDestroy(name_5);
                          return result_21;}
                        goto whileStmtLabel_6;}
                      inc_1_I6wjjge_aow2h993l1((&i_13));}
                    else {
                      break;}}}
                whileStmtLabel_6: ;}
              inc_1_I6wjjge_aow2h993l1((&k_2));}
            else {
              break;}}}
        whileStmtLabel_5: ;
        NU32 b_3 = objBaseSym_0_runot4689(cur_1);
        NB8 X60Qx_393 = eqQ_0_nifh7u8pu1(b_3, cur_1);
        if (X60Qx_393){
          eQdestroy_1_Iph9dp4_comaa5xpt1(vt_0);
          goto whileStmtLabel_4;}
        cur_1 = b_3;
        inc_1_I6wjjge_aow2h993l1((&depth_0));
        eQdestroy_1_Iph9dp4_comaa5xpt1(vt_0);}
      else {
        break;}}}
  whileStmtLabel_4: ;
  if (0 <= genericIdx_0){
    nimStrDestroy(name_5);
    return genericIdx_0;}
  nimStrDestroy(name_5);
  return result_21;
  nimStrDestroy(name_5);
  return result_21;}
seq_0_I50urnw_chu5m1rja1 popArgs_0_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* stack_0, NI32 argc_0){
  seq_0_I50urnw_chu5m1rja1 result_22;
  eQwasMoved_1_Ivxly0t1_chu5m1rja1((&result_22));
  seq_0_I50urnw_chu5m1rja1 tmp_0 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  NI32 k_3 = 0;
  {
    while (k_3 < argc_0){
      Value_0_valzr1t4f X60Qx_394 = popv_0_vmtuaxp6(stack_0);
      add_0_Itre92n_comaa5xpt1((&tmp_0), X60Qx_394);
      inc_1_I6wjjge_aow2h993l1((&k_3));}}
  whileStmtLabel_0: ;
  eQdestroy_1_Inxd7ue1_chu5m1rja1(result_22);
  seq_0_I50urnw_chu5m1rja1 X60Qx_395 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  result_22 = X60Qx_395;
  NI32 X60Qx_396 = len_3_I4n9kvq_comaa5xpt1(tmp_0);
  NI32 j_0 = ((NI32)(X60Qx_396 - 1));
  {
    while (0 <= j_0){
      Value_0_valzr1t4f* X60Qx_397 = getQ_7_Ine8yq71_natd5co251(tmp_0, j_0);
      Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_397);
      Value_0_valzr1t4f X60Qx_398 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
      add_0_Itre92n_comaa5xpt1((&result_22), X60Qx_398);
      dec_1_I0nzoz91_ast8ri79k((&j_0));}}
  whileStmtLabel_1: ;
  eQdestroy_1_Inxd7ue1_chu5m1rja1(tmp_0);
  return result_22;
  eQdestroy_1_Inxd7ue1_chu5m1rja1(tmp_0);
  return result_22;}
Value_0_valzr1t4f execCode_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_15, seq_0_Izok7jt1_chu5m1rja1 code_1, seq_0_Ift2sne_chu5m1rja1 lines_1, seq_0_Iw8xl5b1_flaksyopx1* locals_2, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* coro_2, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_6, seq_0_In6doa_ast8ri79k slotSyms_2){
  Value_0_valzr1t4f result_23;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
  seq_0_I50urnw_chu5m1rja1 stack_1 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  seq_0_Ifq4s5b1_vmtuaxp6 handlers_0 = newSeqUninit_0_Ipt20ij1_vmtuaxp6(0);
  seq_0_I32zqoq1_vmtuaxp6 pendings_0 = newSeqUninit_0_Im62ogf1_vmtuaxp6(0);
  NI32 ip_0 = 0;
  NI32 lastStepLine_0 = -1;
  NI32 unwinding_0 = 0;
  NI32 finDischarge_0 = 0;
  Value_0_valzr1t4f retval_0 = vNil_0_valzr1t4f();
  if ((!(coro_2 == NIM_NIL))){
    if ((*coro_2).d_00.started_0){
      eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
      seq_0_I50urnw_chu5m1rja1 X60Qx_399 = eQdup_1_I28mx5s1_chu5m1rja1((*coro_2).d_00.stack_0);
      stack_1 = X60Qx_399;
      seq_0_Ifq4s5b1_vmtuaxp6 X60Qlhs_67 = handlers_0;
      seq_0_Ifq4s5b1_vmtuaxp6 X60Qx_400 = eQdup_1_Iqqsrms1_vmtuaxp6((*coro_2).d_00.handlers_0);
      handlers_0 = X60Qx_400;
      eQdestroy_1_I3wpak31_vmtuaxp6(X60Qlhs_67);
      seq_0_I32zqoq1_vmtuaxp6 X60Qlhs_68 = pendings_0;
      seq_0_I32zqoq1_vmtuaxp6 X60Qx_401 = eQdup_1_Iyywo9a1_vmtuaxp6((*coro_2).d_00.pendings_0);
      pendings_0 = X60Qx_401;
      eQdestroy_1_Iuu2ern1_vmtuaxp6(X60Qlhs_68);
      ip_0 = (*coro_2).d_00.ip_0;}
    else {
      (*coro_2).d_00.started_0 = NIM_TRUE;}}
  {
    while (NIM_TRUE){
      {
        if ((*(*vm_15).d_00.sink_0).d_00.didQQuit_0){
          Value_0_valzr1t4f X60Qx_402 = vNil_0_valzr1t4f();
          result_23 = X60Qx_402;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
          eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
          eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
          eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
          return result_23;}
        if ((!(unwinding_0 == 0))){
          NI32 X60Qx_403 = len_3_I4ido3x_vmtuaxp6(handlers_0);
          if (X60Qx_403 == 0){
            if (unwinding_0 == 1){
              Value_0_valzr1t4f X60Qtmp_69 = retval_0;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return X60Qtmp_69;}
            else {
              Value_0_valzr1t4f X60Qx_404 = vNil_0_valzr1t4f();
              result_23 = X60Qx_404;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;}}
          NI32 X60Qx_405 = len_3_I4ido3x_vmtuaxp6(handlers_0);
          Handler_0_vmtuaxp6* X60Qx_406 = getQ_7_I4z6e5u1_vmtuaxp6(handlers_0, ((NI32)(X60Qx_405 - 1)));
          Handler_0_vmtuaxp6 h_0 = (*X60Qx_406);
          NI32 X60Qx_407 = len_3_I4ido3x_vmtuaxp6(handlers_0);
          setLen_0_I80tc5k_vmtuaxp6((&handlers_0), ((NI32)(X60Qx_407 - 1)));
          if (h_0.sp_0 < stack_1.len_0){
            setLen_0_I8wiqgg_vmtuaxp6((&stack_1), h_0.sp_0);}
          NB8 X60Qx_408;
          if (unwinding_0 == 2){
            X60Qx_408 = (0 <= h_0.catchIp_0);}
          else {
            X60Qx_408 = NIM_FALSE;}
          if (X60Qx_408){
            unwinding_0 = 0;
            (*vm_15).d_00.raised_0 = NIM_FALSE;
            ip_0 = h_0.catchIp_0;}
          else {
            if (0 <= h_0.finallyIp_0){
              Value_0_valzr1t4f X60Qx_409 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              add_0_Igw9l8t1_vmtuaxp6((&pendings_0), (Pending_0_vmtuaxp6){
                .kind_0 = unwinding_0, .val_0 = X60Qx_409}
              );
              unwinding_0 = 0;
              ip_0 = h_0.finallyIp_0;}
            else {
              goto continueLabel_1;}}}
        if (code_1.len_0 <= ip_0){
          goto whileStmtLabel_0;}
        Instr_0_chu5m1rja1* X60Qx_410 = getQ_7_Iuezo3v1_comaa5xpt1(code_1, ip_0);
        Instr_0_chu5m1rja1 ins_0 = (*X60Qx_410);
        NI32 X60Qx_4;
        NI32 X60Qx_411 = len_3_I0v1j8d_comaa5xpt1(lines_1);
        if (ip_0 < X60Qx_411){
          NI32* X60Qx_412 = getQ_7_Ir8kccm_comaa5xpt1(lines_1, ip_0);
          X60Qx_4 = (*X60Qx_412);}
        else {
          X60Qx_4 = 0;}
        NI32 curLine_0 = X60Qx_4;
        NB8 X60Qx_413;
        NB8 X60Qx_414;
        if ((*(*vm_15).d_00.trace_0).d_00.mode_0 == 2){
          X60Qx_414 = (0 < curLine_0);}
        else {
          X60Qx_414 = NIM_FALSE;}
        if (X60Qx_414){
          X60Qx_413 = (!(curLine_0 == lastStepLine_0));}
        else {
          X60Qx_413 = NIM_FALSE;}
        if (X60Qx_413){
          traceStep_0_trakthy001((*vm_15).d_00.trace_0, (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , curLine_0, 0);
          lastStepLine_0 = curLine_0;}
        switch (ins_0.op_0){
          case 0:
          {
            Value_0_valzr1t4f* X60Qx_415 = getQ_7_Ine8yq71_natd5co251((*vm_15).d_00.prog_0.consts_0, ins_0.a_0);
            Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_415);
            Value_0_valzr1t4f X60Qx_416 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_416);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 1:
          {
            Value_0_valzr1t4f X60Qx_417 = vNil_0_valzr1t4f();
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_417);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 2:
          {
            Value_0_valzr1t4f X60Qx_418 = emptySeqVal_0_runot4689();
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_418);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 3:
          {
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 6, .sval_0 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 4:
          {
            Value_0_valzr1t4f X60Qtmp_70 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f X60Qx_419 = X60Qtmp_70;
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_70));}
          break;
          case 5:
          {
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_420 = getQ_7_Ii14ync1_flaksyopx1((*locals_2), ins_0.a_0);
            Value_0_valzr1t4f X60Qx_421 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_420)).d_00.v_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_421);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 6:
          {
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_422 = getQ_7_Ii14ync1_flaksyopx1((*locals_2), ins_0.a_0);
            Value_0_valzr1t4f* X60Qlhs_71 = (&(*(*X60Qx_422)).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_72 = popv_0_vmtuaxp6((&stack_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_71)));
            (*X60Qlhs_71) = X60Qlhs_72;
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 7:
          {
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_423 = getQ_7_Ii14ync1_flaksyopx1((*locals_2), ins_0.a_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_424 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_423));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 13, .loc_0 = X60Qx_424, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 8:
          {
            NB8 X60Qx_425;
            NI32 X60Qx_426 = len_3_Ixq6taz_comaa5xpt1((*vm_15).d_00.unboundImportc_0);
            if (ins_0.a_0 < X60Qx_426){
              string_0_sysvq0asl* X60Qx_427 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportc_0, ins_0.a_0);
              NI32 X60Qx_428 = len_4_sysvq0asl((*X60Qx_427));
              X60Qx_425 = (0 < X60Qx_428);}
            else {
              X60Qx_425 = NIM_FALSE;}
            if (X60Qx_425){
              string_0_sysvq0asl* X60Qx_429 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportc_0, ins_0.a_0);
              string_0_sysvq0asl* X60Qx_430 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportcNim_0, ins_0.a_0);
              failUnboundImportcGlobal_0_runot4689((*vm_15).d_00.sink_0, (*X60Qx_429), (*X60Qx_430));
              Value_0_valzr1t4f X60Qx_431 = vNil_0_valzr1t4f();
              result_23 = X60Qx_431;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_432 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            Value_0_valzr1t4f X60Qx_433 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_432)).d_00.v_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_433);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 9:
          {
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_434 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            Value_0_valzr1t4f* X60Qlhs_73 = (&(*(*X60Qx_434)).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_74 = popv_0_vmtuaxp6((&stack_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_73)));
            (*X60Qlhs_73) = X60Qlhs_74;
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 10:
          {
            NB8 X60Qx_435;
            NI32 X60Qx_436 = len_3_Ixq6taz_comaa5xpt1((*vm_15).d_00.unboundImportc_0);
            if (ins_0.a_0 < X60Qx_436){
              string_0_sysvq0asl* X60Qx_437 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportc_0, ins_0.a_0);
              NI32 X60Qx_438 = len_4_sysvq0asl((*X60Qx_437));
              X60Qx_435 = (0 < X60Qx_438);}
            else {
              X60Qx_435 = NIM_FALSE;}
            if (X60Qx_435){
              string_0_sysvq0asl* X60Qx_439 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportc_0, ins_0.a_0);
              string_0_sysvq0asl* X60Qx_440 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.unboundImportcNim_0, ins_0.a_0);
              failUnboundImportcGlobal_0_runot4689((*vm_15).d_00.sink_0, (*X60Qx_439), (*X60Qx_440));
              Value_0_valzr1t4f X60Qx_441 = vNil_0_valzr1t4f();
              result_23 = X60Qx_441;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_442 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_443 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_442));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 13, .loc_0 = X60Qx_443, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 11:
          {
            NB8* X60Qx_444 = getQ_7_Iul1no9_fiepkwzpc((*vm_15).d_00.globalInited_0, ins_0.a_0);
            if ((!(*X60Qx_444))){
              putQ_7_Iiblebk_sigekpubi1((&(*vm_15).d_00.globalInited_0), ins_0.a_0, NIM_TRUE);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_445 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
              Value_0_valzr1t4f* X60Qlhs_75 = (&(*(*X60Qx_445)).d_00.v_0);
              seq_0_I50urnw_chu5m1rja1 X60Qtmp_77 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
              Value_0_valzr1t4f X60Qlhs_76 = runProc_1_vmtuaxp6(vm_15, ins_0.b_0, X60Qtmp_77, NIM_NIL);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_75)));
              (*X60Qlhs_75) = X60Qlhs_76;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_77);}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_446 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            Value_0_valzr1t4f X60Qx_447 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_446)).d_00.v_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_447);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 12:
          {
            NB8* X60Qx_448 = getQ_7_Iul1no9_fiepkwzpc((*vm_15).d_00.globalInited_0, ins_0.a_0);
            if ((!(*X60Qx_448))){
              putQ_7_Iiblebk_sigekpubi1((&(*vm_15).d_00.globalInited_0), ins_0.a_0, NIM_TRUE);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_449 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
              Value_0_valzr1t4f* X60Qlhs_78 = (&(*(*X60Qx_449)).d_00.v_0);
              seq_0_I50urnw_chu5m1rja1 X60Qtmp_80 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
              Value_0_valzr1t4f X60Qlhs_79 = runProc_1_vmtuaxp6(vm_15, ins_0.b_0, X60Qtmp_80, NIM_NIL);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_78)));
              (*X60Qlhs_78) = X60Qlhs_79;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qtmp_80);}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_450 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_451 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_450));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 13, .loc_0 = X60Qx_451, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 13:
          {
            Value_0_valzr1t4f p_0 = popv_0_vmtuaxp6((&stack_1));
            NB8 X60Qx_452;
            if (p_0.kind_0 == 13){
              X60Qx_452 = (!(p_0.region_0 == NIM_NIL));}
            else {
              X60Qx_452 = NIM_FALSE;}
            if (X60Qx_452){
              Value_0_valzr1t4f X60Qx_453 = flDeref_0_flaksyopx1((&p_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_453);}
            else {
              NB8 X60Qx_454;
              if (p_0.kind_0 == 13){
                X60Qx_454 = (!(p_0.loc_0 == NIM_NIL));}
              else {
                X60Qx_454 = NIM_FALSE;}
              if (X60Qx_454){
                Value_0_valzr1t4f X60Qx_455 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*p_0.loc_0).d_00.v_0));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_455);}
              else {
                NB8 X60Qx_456;
                if (p_0.kind_0 == 12){
                  X60Qx_456 = (!(p_0.rf_0 == NIM_NIL));}
                else {
                  X60Qx_456 = NIM_FALSE;}
                if (X60Qx_456){
                  Value_0_valzr1t4f X60Qx_457 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*p_0.rf_0).d_00.v_0));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_457);}
                else {
                  NB8 X60Qx_458;
                  if (p_0.kind_0 == 13){
                    X60Qx_458 = NIM_TRUE;}
                  else {
                    X60Qx_458 = (p_0.kind_0 == 12);}
                  if (X60Qx_458){
                    string_0_sysvq0asl X60Qdesugar_10 = dollarX60Q_ValueKind_0_valzr1t4f(p_0.kind_0);
                    NI32 X60Qx_459 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I896784059842111249_vmtuaxp6)}
                    );
                    NI32 X60Qx_460 = len_4_sysvq0asl(X60Qdesugar_10);
                    NI32 X60Qx_461 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 10497u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_459 + X60Qx_460)) + X60Qx_461)));
                    add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
                      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I896784059842111249_vmtuaxp6)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
                    add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
                      .bytes_0 = 10497u, .more_0 = NIM_NIL}
                    );
                    softNil_0_vmtuaxp6((string_0_sysvq0asl){
                      .bytes_0 = 1148219390u, .more_0 = (&strlit_0_I14095655799529196805_chu5m1rja1)}
                    , X60Qdesugar_11);
                    Value_0_valzr1t4f X60Qx_462 = vNil_0_valzr1t4f();
                    add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_462);
                    nimStrDestroy(X60Qdesugar_11);
                    nimStrDestroy(X60Qdesugar_10);}
                  else {
                    Value_0_valzr1t4f X60Qtmp_81 = p_0;
                    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_0));
                    add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_81);}}}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_0));}
          break;
          case 51:
          {
            if (0 < stack_1.len_0){
              NI32 X60Qx_463 = len_3_I4n9kvq_comaa5xpt1(stack_1);
              NI32 ti_0 = ((NI32)(X60Qx_463 - 1));
              Value_0_valzr1t4f* X60Qx_464 = getQ_7_Ine8yq71_natd5co251(stack_1, ti_0);
              Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_464);
              Value_0_valzr1t4f X60Qx_465 = copyOnAssign_0_valzr1t4f((&X60QconstRefTemp_1));
              putQ_7_I4hmt511_runot4689((&stack_1), ti_0, X60Qx_465);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 14:
          {
            Value_0_valzr1t4f p_1 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f X60Qtmp_82 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f val_0 = copyOnAssign_0_valzr1t4f((&X60Qtmp_82));
            NB8 X60Qx_466;
            if (p_1.kind_0 == 13){
              X60Qx_466 = (!(p_1.region_0 == NIM_NIL));}
            else {
              X60Qx_466 = NIM_FALSE;}
            if (X60Qx_466){
              flStoreDeref_0_flaksyopx1((&p_1), (&val_0));}
            else {
              NB8 X60Qx_467;
              if (p_1.kind_0 == 13){
                X60Qx_467 = (!(p_1.loc_0 == NIM_NIL));}
              else {
                X60Qx_467 = NIM_FALSE;}
              if (X60Qx_467){
                Value_0_valzr1t4f* X60Qlhs_83 = (&(*p_1.loc_0).d_00.v_0);
                Value_0_valzr1t4f X60Qlhs_84 = val_0;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&val_0));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_83)));
                (*X60Qlhs_83) = X60Qlhs_84;}
              else {
                NB8 X60Qx_468;
                if (p_1.kind_0 == 12){
                  X60Qx_468 = (!(p_1.rf_0 == NIM_NIL));}
                else {
                  X60Qx_468 = NIM_FALSE;}
                if (X60Qx_468){
                  Value_0_valzr1t4f* X60Qlhs_85 = (&(*p_1.rf_0).d_00.v_0);
                  Value_0_valzr1t4f X60Qlhs_86 = val_0;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&val_0));
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_85)));
                  (*X60Qlhs_85) = X60Qlhs_86;}}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&val_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_82));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_1));}
          break;
          case 15:
          {
            Value_0_valzr1t4f p_2 = popv_0_vmtuaxp6((&stack_1));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* target_0 = NIM_NIL;
            NB8 X60Qx_469;
            if (p_2.kind_0 == 13){
              X60Qx_469 = (!(p_2.loc_0 == NIM_NIL));}
            else {
              X60Qx_469 = NIM_FALSE;}
            if (X60Qx_469){
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(target_0);
              target_0 = p_2.loc_0;
              eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&p_2.loc_0));}
            NB8 X60Qx_470;
            NB8 X60Qx_471;
            if ((!(target_0 == NIM_NIL))){
              X60Qx_471 = ((*target_0).d_00.v_0.kind_0 == 13);}
            else {
              X60Qx_471 = NIM_FALSE;}
            if (X60Qx_471){
              X60Qx_470 = (!((*target_0).d_00.v_0.loc_0 == NIM_NIL));}
            else {
              X60Qx_470 = NIM_FALSE;}
            if (X60Qx_470){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_87 = target_0;
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_472 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*target_0).d_00.v_0.loc_0);
              target_0 = X60Qx_472;
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qlhs_87);}
            if ((!(target_0 == NIM_NIL))){
              switch ((*target_0).d_00.v_0.kind_0){
                case 6:
                {
                  Value_0_valzr1t4f* X60Qlhs_88 = (&(*target_0).d_00.v_0);
                  Value_0_valzr1t4f X60Qlhs_89 = vStr_0_valzr1t4f((string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_88)));
                  (*X60Qlhs_88) = X60Qlhs_89;}
                break;
                case 8:
                {
                  Value_0_valzr1t4f* X60Qlhs_90 = (&(*target_0).d_00.v_0);
                  void* X60Qx_473 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
                  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_92 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_473);
                  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_474 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
                  (*X60Qtmp_92) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
                    .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
                      .elems_0 = X60Qx_474, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
                  ;
                  Value_0_valzr1t4f X60Qlhs_91 = (Value_0_valzr1t4f){
                    .kind_0 = 8, .sq_0 = X60Qtmp_92}
                  ;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_90)));
                  (*X60Qlhs_90) = X60Qlhs_91;}
                break;
                case 12:
                {
                  Value_0_valzr1t4f* X60Qlhs_93 = (&(*target_0).d_00.v_0);
                  Value_0_valzr1t4f X60Qlhs_94 = (Value_0_valzr1t4f){
                    .kind_0 = 12, .rf_0 = NIM_NIL}
                  ;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_93)));
                  (*X60Qlhs_93) = X60Qlhs_94;}
                break;
                default:
                {
                  }
                break;}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(target_0);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_2));}
          break;
          case 16:
          {
            inc_1_I6wjjge_aow2h993l1((&(*vm_15).d_00.keepOvf_0));
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 17:
          {
            if (0 < (*vm_15).d_00.keepOvf_0){
              dec_1_I0nzoz91_ast8ri79k((&(*vm_15).d_00.keepOvf_0));}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 18:
          {
            Value_0_valzr1t4f X60Qx_475 = vBool_0_valzr1t4f((*vm_15).d_00.overflowFlag_0);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_475);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 19:
          {
            MagicSpec_0_chu5m1rja1* X60Qx_476 = getQ_7_Io8qdfc_vmtuaxp6((*vm_15).d_00.prog_0.magics_0, ins_0.a_0);
            MagicSpec_0_chu5m1rja1 spec_0 = (*X60Qx_476);
            Value_0_valzr1t4f b_4 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f a_8 = popv_0_vmtuaxp6((&stack_1));
            if (0 < (*vm_15).d_00.keepOvf_0){
              NB8 X60Qx_477 = arithOverflows_0_aow2h993l1(spec_0.op_0, (&a_8), (&b_4), spec_0.bits_0, spec_0.signed_0);
              (*vm_15).d_00.overflowFlag_0 = X60Qx_477;}
            if (spec_0.caseEq_0){
              NB8 X60Qx_478 = valueEquals_0_runot4689((&a_8), (&b_4));
              Value_0_valzr1t4f X60Qx_479 = vBool_0_valzr1t4f(X60Qx_478);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_479);
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            else {
              NB8 X60Qx_480 = isDivByZero_0_aow2h993l1(spec_0.op_0, (&a_8), (&b_4));
              if (X60Qx_480){
                vmRaiseDivByZero_0_vmtuaxp6(vm_15);
                unwinding_0 = 2;}
              else {
                Value_0_valzr1t4f X60Qx_481 = binMagic_0_aow2h993l1(spec_0.op_0, (&a_8), (&b_4), spec_0.bits_0, spec_0.signed_0);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_481);
                inc_1_I6wjjge_aow2h993l1((&ip_0));}}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_8));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_4));}
          break;
          case 20:
          {
            MagicSpec_0_chu5m1rja1* X60Qx_482 = getQ_7_Io8qdfc_vmtuaxp6((*vm_15).d_00.prog_0.magics_0, ins_0.a_0);
            MagicSpec_0_chu5m1rja1 spec_1 = (*X60Qx_482);
            Value_0_valzr1t4f a_9 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f X60Qx_483 = unMagic_0_aow2h993l1(spec_1.op_0, (&a_9), spec_1.bits_0, spec_1.signed_0);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_483);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_9));}
          break;
          case 21:
          {
            ConvSpec_0_chu5m1rja1* X60Qx_484 = getQ_7_Ij8ai9r_vmtuaxp6((*vm_15).d_00.prog_0.convs_0, ins_0.a_0);
            ConvSpec_0_chu5m1rja1 sp_1 = (*X60Qx_484);
            Value_0_valzr1t4f v_8 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f X60Qx_485 = doConv_0_vmtuaxp6(sp_1, (&v_8), (*vm_15).d_00.sink_0);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_485);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_8));}
          break;
          case 22:
          {
            Value_0_valzr1t4f v_9 = popv_0_vmtuaxp6((&stack_1));
            switch (v_9.kind_0){
              case 1:
              {
                Value_0_valzr1t4f X60Qx_486 = vIntX_0_valzr1t4f(v_9.ival_0, ins_0.a_0);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_486);}
              break;
              case 2:
              {
                Value_0_valzr1t4f X60Qx_487 = vUIntX_0_valzr1t4f(v_9.ival_0, ins_0.a_0);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_487);}
              break;
              case 3:
              {
                NF64 X60Qx_5;
                if (ins_0.a_0 == 32){
                  X60Qx_5 = ((NF64)((NF32)v_9.fval_0));}
                else {
                  X60Qx_5 = v_9.fval_0;}
                NF64 fv_1 = X60Qx_5;
                Value_0_valzr1t4f X60Qx_488 = vFloat_0_valzr1t4f(fv_1, ins_0.a_0);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_488);}
              break;
              default:
              {
                Value_0_valzr1t4f X60Qtmp_95 = v_9;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_9));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_95);}
              break;}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_9));}
          break;
          case 23:
          {
            NU32* X60Qx_489 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.enumWraps_0, ins_0.a_0);
            NU32 et_0 = (*X60Qx_489);
            Value_0_valzr1t4f X60Qtmp_96 = popv_0_vmtuaxp6((&stack_1));
            NI64 X60Qx_490 = asInt_0_valzr1t4f((&X60Qtmp_96));
            NI32 o_0 = ((NI32)X60Qx_490);
            string_0_sysvq0asl X60Qtmp_97 = enumFieldName_0_runot4689(et_0, o_0);
            Value_0_valzr1t4f X60Qx_491 = vEnum_0_valzr1t4f(o_0, et_0, X60Qtmp_97);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_491);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            nimStrDestroy(X60Qtmp_97);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_96));}
          break;
          case 24:
          {
            ip_0 = ins_0.a_0;}
          break;
          case 25:
          {
            Value_0_valzr1t4f cond_0 = popv_0_vmtuaxp6((&stack_1));
            NB8 X60Qx_492 = truthy_0_valzr1t4f((&cond_0));
            if ((!X60Qx_492)){
              ip_0 = ins_0.a_0;}
            else {
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cond_0));}
          break;
          case 26:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_1 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            NB8 X60Qx_493 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_493){
              Proc_0_chu5m1rja1* X60Qx_494 = getQ_7_I7rdp401_vmtuaxp6((*vm_15).d_00.prog_0.procs_0, ins_0.a_0);
              traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_494).name_0, cargs_1, curLine_0, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );}
            Value_0_valzr1t4f rv_1 = runProc_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_1, NIM_NIL);
            NB8 X60Qx_495 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_495){
              traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_1), (*vm_15).d_00.raised_0);}
            if ((*vm_15).d_00.raised_0){
              unwinding_0 = 2;}
            else {
              Value_0_valzr1t4f X60Qtmp_98 = rv_1;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_1));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_98);
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_1));
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_1);}
          break;
          case 29:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_2 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            NB8 X60Qx_496 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_496){
              Proc_0_chu5m1rja1* X60Qx_497 = getQ_7_I7rdp401_vmtuaxp6((*vm_15).d_00.prog_0.procs_0, ins_0.a_0);
              traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_497).name_0, cargs_2, curLine_0, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );}
            X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qtmp_99 = captureFrameEnv_0_vmtuaxp6((*locals_2), slotSyms_2, env_6);
            Value_0_valzr1t4f rv_2 = runProc_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_2, X60Qtmp_99);
            NB8 X60Qx_498 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_498){
              traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_2), (*vm_15).d_00.raised_0);}
            if ((*vm_15).d_00.raised_0){
              unwinding_0 = 2;}
            else {
              Value_0_valzr1t4f X60Qtmp_100 = rv_2;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_2));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_100);
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_2));
            eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_99);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_2);}
          break;
          case 30:
          {
            NU32* X60Qx_499 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.envSyms_0, ins_0.a_0);
            NU32 s_38 = (*X60Qx_499);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0 = envCellOf_0_vmtuaxp6(env_6, s_38);
            if ((!(cell_0 == NIM_NIL))){
              Value_0_valzr1t4f X60Qx_500 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_0).d_00.v_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_500);}
            else {
              string_0_sysvq0asl X60Qdesugar_12 = mBaseName_1_vmtuaxp6(s_38);
              NI32 X60Qx_501 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              NI32 X60Qx_502 = len_4_sysvq0asl(X60Qdesugar_12);
              NI32 X60Qx_503 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_501 + X60Qx_502)) + X60Qx_503)));
              add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
              add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              loudNil_0_vmtuaxp6(vm_15, (string_0_sysvq0asl){
                .bytes_0 = 1282437118u, .more_0 = (&strlit_0_I11387783988347383465_chu5m1rja1)}
              , X60Qdesugar_13);
              Value_0_valzr1t4f X60Qx_504 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_504);
              nimStrDestroy(X60Qdesugar_13);
              nimStrDestroy(X60Qdesugar_12);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_0);}
          break;
          case 31:
          {
            NU32* X60Qx_505 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.envSyms_0, ins_0.a_0);
            NU32 s_39 = (*X60Qx_505);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_1 = envCellOf_0_vmtuaxp6(env_6, s_39);
            Value_0_valzr1t4f v_10 = popv_0_vmtuaxp6((&stack_1));
            if ((!(cell_1 == NIM_NIL))){
              Value_0_valzr1t4f* X60Qlhs_101 = (&(*cell_1).d_00.v_0);
              Value_0_valzr1t4f X60Qlhs_102 = v_10;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_10));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_101)));
              (*X60Qlhs_101) = X60Qlhs_102;}
            else {
              string_0_sysvq0asl X60Qdesugar_14 = mBaseName_1_vmtuaxp6(s_39);
              NI32 X60Qx_506 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              NI32 X60Qx_507 = len_4_sysvq0asl(X60Qdesugar_14);
              NI32 X60Qx_508 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_506 + X60Qx_507)) + X60Qx_508)));
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              loudNil_0_vmtuaxp6(vm_15, (string_0_sysvq0asl){
                .bytes_0 = 1399877630u, .more_0 = (&strlit_0_I6978519596239417483_chu5m1rja1)}
              , X60Qdesugar_15);
              nimStrDestroy(X60Qdesugar_15);
              nimStrDestroy(X60Qdesugar_14);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_10));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_1);}
          break;
          case 32:
          {
            NU32* X60Qx_509 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.envSyms_0, ins_0.a_0);
            NU32 s_40 = (*X60Qx_509);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_2 = envCellOf_0_vmtuaxp6(env_6, s_40);
            if ((!(cell_2 == NIM_NIL))){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_103 = cell_2;
              eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&cell_2));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 13, .loc_0 = X60Qtmp_103, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
              );}
            else {
              string_0_sysvq0asl X60Qdesugar_16 = mBaseName_1_vmtuaxp6(s_40);
              NI32 X60Qx_510 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              NI32 X60Qx_511 = len_4_sysvq0asl(X60Qdesugar_16);
              NI32 X60Qx_512 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_510 + X60Qx_511)) + X60Qx_512)));
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 1885430782u, .more_0 = (&strlit_0_I8402133133667695762_vmtuaxp6)}
              );
              add_2_sysvq0asl((&X60Qdesugar_17), X60Qdesugar_16);
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I14000276951511883434_vmtuaxp6)}
              );
              loudNil_0_vmtuaxp6(vm_15, (string_0_sysvq0asl){
                .bytes_0 = 1282437118u, .more_0 = (&strlit_0_I4520676207223615416_chu5m1rja1)}
              , X60Qdesugar_17);
              Value_0_valzr1t4f X60Qx_513 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_513);
              nimStrDestroy(X60Qdesugar_17);
              nimStrDestroy(X60Qdesugar_16);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_2);}
          break;
          case 33:
          {
            NB8 X60Qx_514;
            if (0 < stack_1.len_0){
              NI32 X60Qx_515 = len_3_I4n9kvq_comaa5xpt1(stack_1);
              Value_0_valzr1t4f* X60Qx_516 = getQ_7_Ine8yq71_natd5co251(stack_1, ((NI32)(X60Qx_515 - 1)));
              X60Qx_514 = ((*X60Qx_516).kind_0 == 15);}
            else {
              X60Qx_514 = NIM_FALSE;}
            if (X60Qx_514){
              Value_0_valzr1t4f pv_0 = popv_0_vmtuaxp6((&stack_1));
              X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** X60Qlhs_104 = (&pv_0.env_0);
              eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qlhs_104));
              X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qx_517 = captureFrameEnv_0_vmtuaxp6((*locals_2), slotSyms_2, env_6);
              (*X60Qlhs_104) = X60Qx_517;
              Value_0_valzr1t4f X60Qtmp_105 = pv_0;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_105);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_0));}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 27:
          {
            Value_0_valzr1t4f callee_0 = popv_0_vmtuaxp6((&stack_1));
            seq_0_I50urnw_chu5m1rja1 cargs_3 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            NB8 X60Qx_518;
            NB8 X60Qx_519;
            NB8 X60Qx_520;
            if (callee_0.kind_0 == 15){
              X60Qx_520 = (callee_0.pidx_0 < 0);}
            else {
              X60Qx_520 = NIM_FALSE;}
            if (X60Qx_520){
              X60Qx_519 = (!(callee_0.env_0 == NIM_NIL));}
            else {
              X60Qx_519 = NIM_FALSE;}
            if (X60Qx_519){
              X60Qx_518 = (!((*callee_0.env_0).d_00.coro_0 == NIM_NIL));}
            else {
              X60Qx_518 = NIM_FALSE;}
            if (X60Qx_518){
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* co_2 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)(*callee_0.env_0).d_00.coro_0));
              Value_0_valzr1t4f envArg_0 = vNil_0_valzr1t4f();
              if (1 <= cargs_3.len_0){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&envArg_0));
                Value_0_valzr1t4f* X60Qx_521 = getQ_7_Ine8yq71_natd5co251(cargs_3, 0);
                Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_521);
                Value_0_valzr1t4f X60Qx_522 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_2));
                envArg_0 = X60Qx_522;}
              X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 r_0 = resumeCoro_1_vmtuaxp6(vm_15, co_2);
              if (r_0.fld_1){
                Value_0_valzr1t4f X60Qtmp_106 = vNil_0_valzr1t4f();
                Value_0_valzr1t4f X60Qtmp_107 = vNil_0_valzr1t4f();
                Value_0_valzr1t4f X60Qx_523 = buildContVm_0_vmtuaxp6((&X60Qtmp_106), (&X60Qtmp_107));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_523);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_107));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_106));}
              else {
                if ((!((*callee_0.env_0).d_00.dest_0 == NIM_NIL))){
                  Value_0_valzr1t4f* X60Qlhs_108 = (&(*(*callee_0.env_0).d_00.dest_0).d_00.v_0);
                  Value_0_valzr1t4f X60Qlhs_109 = r_0.fld_0;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&r_0.fld_0));
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_108)));
                  (*X60Qlhs_108) = X60Qlhs_109;}
                Value_0_valzr1t4f X60Qx_524 = buildContVm_0_vmtuaxp6((&callee_0), (&envArg_0));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_524);}
              inc_1_I6wjjge_aow2h993l1((&ip_0));
              eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&r_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&envArg_0));
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(co_2);}
            else {
              if (callee_0.kind_0 == 15){
                NB8 X60Qx_525 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
                if (X60Qx_525){
                  Proc_0_chu5m1rja1* X60Qx_526 = getQ_7_I7rdp401_vmtuaxp6((*vm_15).d_00.prog_0.procs_0, callee_0.pidx_0);
                  traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_526).name_0, cargs_3, curLine_0, (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );}
                Value_0_valzr1t4f rv_3 = runProc_1_vmtuaxp6(vm_15, callee_0.pidx_0, cargs_3, callee_0.env_0);
                NB8 X60Qx_527 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
                if (X60Qx_527){
                  traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_3), (*vm_15).d_00.raised_0);}
                if ((*vm_15).d_00.raised_0){
                  unwinding_0 = 2;}
                else {
                  Value_0_valzr1t4f X60Qtmp_110 = rv_3;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_3));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_110);
                  inc_1_I6wjjge_aow2h993l1((&ip_0));}
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_3));}
              else {
                string_0_sysvq0asl X60Qdesugar_18 = dollarX60Q_ValueKind_0_valzr1t4f(callee_0.kind_0);
                NI32 X60Qx_528 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I4313607421916706826_vmtuaxp6)}
                );
                NI32 X60Qx_529 = len_4_sysvq0asl(X60Qdesugar_18);
                NI32 X60Qx_530 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I1479688777189329103_vmtuaxp6)}
                );
                string_0_sysvq0asl X60Qdesugar_19 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_528 + X60Qx_529)) + X60Qx_530)));
                add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
                  .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I4313607421916706826_vmtuaxp6)}
                );
                add_2_sysvq0asl((&X60Qdesugar_19), X60Qdesugar_18);
                add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
                  .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I1479688777189329103_vmtuaxp6)}
                );
                loudNil_0_vmtuaxp6(vm_15, (string_0_sysvq0asl){
                  .bytes_0 = 1131442174u, .more_0 = (&strlit_0_I4203653505119668623_chu5m1rja1)}
                , X60Qdesugar_19);
                Value_0_valzr1t4f X60Qx_531 = vNil_0_valzr1t4f();
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_531);
                inc_1_I6wjjge_aow2h993l1((&ip_0));
                nimStrDestroy(X60Qdesugar_19);
                nimStrDestroy(X60Qdesugar_18);}}
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_3);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&callee_0));}
          break;
          case 73:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_4 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            Value_0_valzr1t4f calleeV_0 = vNil_0_valzr1t4f();
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_3 = NIM_NIL;
            if (ins_0.a_0 == 1){
              Value_0_valzr1t4f pv_1 = popv_0_vmtuaxp6((&stack_1));
              NB8 X60Qx_532;
              if (pv_1.kind_0 == 13){
                X60Qx_532 = (!(pv_1.loc_0 == NIM_NIL));}
              else {
                X60Qx_532 = NIM_FALSE;}
              if (X60Qx_532){
                eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_3);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_533 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(pv_1.loc_0);
                cell_3 = X60Qx_533;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&calleeV_0));
                Value_0_valzr1t4f X60Qx_534 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*pv_1.loc_0).d_00.v_0));
                calleeV_0 = X60Qx_534;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&calleeV_0));
                calleeV_0 = pv_1;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_1));}
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_1));}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&calleeV_0));
              Value_0_valzr1t4f X60Qx_535 = popv_0_vmtuaxp6((&stack_1));
              calleeV_0 = X60Qx_535;}
            NB8 X60Qx_536;
            if (calleeV_0.kind_0 == 15){
              NB8 X60Qx_537 = eqQ_0_nifh7u8pu1(calleeV_0.fn_0, ((NU32)0u));
              X60Qx_536 = (!X60Qx_537);}
            else {
              X60Qx_536 = NIM_FALSE;}
            if (X60Qx_536){
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* coro_4 = NIM_NIL;
              NB8 X60Qx_538;
              if ((!(calleeV_0.env_0 == NIM_NIL))){
                X60Qx_538 = (!((*calleeV_0.env_0).d_00.coro_0 == NIM_NIL));}
              else {
                X60Qx_538 = NIM_FALSE;}
              if (X60Qx_538){
                eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_4);
                X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_539 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)(*calleeV_0.env_0).d_00.coro_0));
                coro_4 = X60Qx_539;}
              if (coro_4 == NIM_NIL){
                eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_4);
                X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_540 = makeCoro_1_vmtuaxp6(vm_15, calleeV_0.pidx_0, cargs_4, calleeV_0.env_0);
                coro_4 = X60Qx_540;
                NB8 X60Qx_541;
                if ((!(cell_3 == NIM_NIL))){
                  X60Qx_541 = ((*cell_3).d_00.v_0.kind_0 == 15);}
                else {
                  X60Qx_541 = NIM_FALSE;}
                if (X60Qx_541){
                  if ((*cell_3).d_00.v_0.env_0 == NIM_NIL){
                    X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** X60Qlhs_111 = (&(*cell_3).d_00.v_0.env_0);
                    void* X60Qx_542 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1));
                    X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qtmp_113 = ((X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1*)X60Qx_542);
                    seq_0_In6doa_ast8ri79k X60Qx_543 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
                    seq_0_Iw8xl5b1_flaksyopx1 X60Qx_544 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
                    X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_545 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_4);
                    (*X60Qtmp_113) = (X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1){
                      .r_00 = 0, .d_00 = (ClosureEnv_Obj_0_valzr1t4f){
                        .vars_0 = X60Qx_543, .cells_0 = X60Qx_544, .coro_0 = ((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)X60Qx_545), .dest_0 = NIM_NIL}}
                    ;
                    X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qlhs_112 = X60Qtmp_113;
                    eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qlhs_111));
                    (*X60Qlhs_111) = X60Qlhs_112;}
                  else {
                    X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f** X60Qlhs_114 = (&(*(*cell_3).d_00.v_0.env_0).d_00.coro_0);
                    X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* X60Qlhs_115 = (*(*cell_3).d_00.v_0.env_0).d_00.coro_0;
                    X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* X60Qx_546 = eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)coro_4));
                    (*X60Qlhs_114) = X60Qx_546;
                    eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(X60Qlhs_115);}}}
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qtmp_116 = coro_4;
              eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&coro_4));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 17, .coro_0 = ((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)X60Qtmp_116)}
              );
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_4);}
            else {
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 17, .coro_0 = NIM_NIL}
              );}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_3);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&calleeV_0));
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_4);}
          break;
          case 74:
          {
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_547 = getQ_7_Ii14ync1_flaksyopx1((*locals_2), ins_0.a_0);
            Value_0_valzr1t4f contV_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_547)).d_00.v_0));
            NB8 X60Qx_548;
            NB8 X60Qx_549;
            if ((*vm_15).d_00.scheduler_0.kind_0 == 15){
              X60Qx_549 = (contV_0.kind_0 == 17);}
            else {
              X60Qx_549 = NIM_FALSE;}
            if (X60Qx_549){
              X60Qx_548 = (!(contV_0.coro_0 == NIM_NIL));}
            else {
              X60Qx_548 = NIM_FALSE;}
            if (X60Qx_548){
              X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 r_1 = scheduledStep_0_vmtuaxp6(vm_15, ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)contV_0.coro_0));
              if (r_1.fld_1){
                Value_0_valzr1t4f X60Qx_550 = vNil_0_valzr1t4f();
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_550);
                Value_0_valzr1t4f X60Qx_551 = vBool_0_valzr1t4f(NIM_FALSE);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_551);}
              else {
                Value_0_valzr1t4f X60Qtmp_117 = r_1.fld_0;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&r_1.fld_0));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_117);
                Value_0_valzr1t4f X60Qx_552 = vBool_0_valzr1t4f(NIM_TRUE);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_552);}
              eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&r_1));}
            else {
              NB8 X60Qx_553;
              if (contV_0.kind_0 == 17){
                X60Qx_553 = (!(contV_0.coro_0 == NIM_NIL));}
              else {
                X60Qx_553 = NIM_FALSE;}
              if (X60Qx_553){
                X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 r_2 = resumeCoro_1_vmtuaxp6(vm_15, ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)contV_0.coro_0));
                if (r_2.fld_1){
                  Value_0_valzr1t4f X60Qx_554 = vNil_0_valzr1t4f();
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_554);
                  Value_0_valzr1t4f X60Qx_555 = vBool_0_valzr1t4f(NIM_FALSE);
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_555);}
                else {
                  Value_0_valzr1t4f X60Qtmp_118 = r_2.fld_0;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&r_2.fld_0));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_118);
                  Value_0_valzr1t4f X60Qx_556 = vBool_0_valzr1t4f(NIM_TRUE);
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_556);}
                eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&r_2));}
              else {
                Value_0_valzr1t4f X60Qx_557 = vNil_0_valzr1t4f();
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_557);
                Value_0_valzr1t4f X60Qx_558 = vBool_0_valzr1t4f(NIM_FALSE);
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_558);}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&contV_0));}
          break;
          case 75:
          {
            Value_0_valzr1t4f handler_0 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f* X60Qlhs_119 = (&(*vm_15).d_00.scheduler_0);
            Value_0_valzr1t4f X60Qlhs_120 = (*vm_15).d_00.scheduler_0;
            Value_0_valzr1t4f X60Qx_559 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&handler_0));
            (*X60Qlhs_119) = X60Qx_559;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_120));
            NB8* X60Qx_560 = getQ_7_Iul1no9_fiepkwzpc((*vm_15).d_00.globalInited_0, ins_0.a_0);
            if ((!(*X60Qx_560))){
              putQ_7_Iiblebk_sigekpubi1((&(*vm_15).d_00.globalInited_0), ins_0.a_0, NIM_TRUE);}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_561 = getQ_7_Ii14ync1_flaksyopx1((*vm_15).d_00.globals_0, ins_0.a_0);
            Value_0_valzr1t4f* X60Qlhs_121 = (&(*(*X60Qx_561)).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_122 = handler_0;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&handler_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_121)));
            (*X60Qlhs_121) = X60Qlhs_122;
            Value_0_valzr1t4f X60Qx_562 = vNil_0_valzr1t4f();
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_562);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&handler_0));}
          break;
          case 28:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_5 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            MethodSite_0_chu5m1rja1* X60Qx_563 = getQ_7_Ig0gjeo1_vmtuaxp6((*vm_15).d_00.prog_0.methodSites_0, ins_0.a_0);
            MethodSite_0_chu5m1rja1 site_1 = (*X60Qx_563);
            NI32 target_1 = site_1.fallbackIdx_0;
            if (1 <= cargs_5.len_0){
              Value_0_valzr1t4f* X60Qx_564 = getQ_7_Ine8yq71_natd5co251(cargs_5, 0);
              Value_0_valzr1t4f X60QconstRefTemp_3 = (*X60Qx_564);
              NI32 X60Qx_565 = dispatchMethodVm_0_vmtuaxp6(vm_15, site_1, (&X60QconstRefTemp_3));
              target_1 = X60Qx_565;}
            NB8 X60Qx_566 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_566){
              Proc_0_chu5m1rja1* X60Qx_567 = getQ_7_I7rdp401_vmtuaxp6((*vm_15).d_00.prog_0.procs_0, target_1);
              traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_567).name_0, cargs_5, curLine_0, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );}
            Value_0_valzr1t4f rv_4 = runProc_1_vmtuaxp6(vm_15, target_1, cargs_5, NIM_NIL);
            NB8 X60Qx_568 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
            if (X60Qx_568){
              traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_4), (*vm_15).d_00.raised_0);}
            if ((*vm_15).d_00.raised_0){
              unwinding_0 = 2;}
            else {
              Value_0_valzr1t4f X60Qtmp_123 = rv_4;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_4));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_123);
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_4));
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_5);}
          break;
          case 34:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_6 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            string_0_sysvq0asl* X60Qx_569 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, ins_0.a_0);
            NB8 X60Qx_570 = vmBoundsRaise_0_vmtuaxp6(vm_15, (*X60Qx_569), cargs_6);
            if (X60Qx_570){
              unwinding_0 = 2;}
            else {
              NB8 X60Qx_571 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
              if (X60Qx_571){
                string_0_sysvq0asl* X60Qx_572 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, ins_0.a_0);
                traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_572), cargs_6, curLine_0, (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                );}
              string_0_sysvq0asl* X60Qx_573 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, ins_0.a_0);
              Value_0_valzr1t4f rv_5 = callNativeVM_0_vmtuaxp6(vm_15, (*X60Qx_573), cargs_6);
              NB8 X60Qx_574 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
              if (X60Qx_574){
                traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_5), NIM_FALSE);}
              Value_0_valzr1t4f X60Qtmp_124 = rv_5;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_5));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_124);
              inc_1_I6wjjge_aow2h993l1((&ip_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_5));}
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_6);}
          break;
          case 35:
          {
            GatedCall_0_chu5m1rja1* X60Qx_575 = getQ_7_Ij0vr9r_vmtuaxp6((*vm_15).d_00.prog_0.gatedCalls_0, ins_0.a_0);
            GatedCall_0_chu5m1rja1 g_0 = (*X60Qx_575);
            seq_0_I50urnw_chu5m1rja1 cargs_7 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            NB8 X60Qx_576;
            if (1 <= cargs_7.len_0){
              string_0_sysvq0asl* X60Qx_577 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
              Value_0_valzr1t4f* X60Qx_578 = getQ_7_Ine8yq71_natd5co251(cargs_7, 0);
              Value_0_valzr1t4f X60QconstRefTemp_4 = (*X60Qx_578);
              NB8 X60Qx_579 = gateAllowsNative_0_runot4689((*X60Qx_577), (&X60QconstRefTemp_4));
              X60Qx_576 = (!X60Qx_579);}
            else {
              X60Qx_576 = NIM_FALSE;}
            NB8 runBody_0 = X60Qx_576;
            NB8 X60Qx_580;
            string_0_sysvq0asl* X60Qx_581 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
            NB8 X60Qx_582 = eqQ_20_sysvq0asl((*X60Qx_581), (string_0_sysvq0asl){
              .bytes_0 = 9217u, .more_0 = NIM_NIL}
            );
            if (X60Qx_582){
              X60Qx_580 = (1 <= cargs_7.len_0);}
            else {
              X60Qx_580 = NIM_FALSE;}
            if (X60Qx_580){
              Value_0_valzr1t4f* X60Qx_583 = getQ_7_Ine8yq71_natd5co251(cargs_7, 0);
              Value_0_valzr1t4f X60QconstRefTemp_5 = (*X60Qx_583);
              Value_0_valzr1t4f a0_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_5));
              NB8 X60Qx_584;
              if (a0_0.kind_0 == 13){
                X60Qx_584 = (!(a0_0.loc_0 == NIM_NIL));}
              else {
                X60Qx_584 = NIM_FALSE;}
              if (X60Qx_584){
                Value_0_valzr1t4f X60Qlhs_125 = a0_0;
                Value_0_valzr1t4f X60Qx_585 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*a0_0.loc_0).d_00.v_0));
                a0_0 = X60Qx_585;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_125));}
              else {
                NB8 X60Qx_586;
                if (a0_0.kind_0 == 12){
                  X60Qx_586 = (!(a0_0.rf_0 == NIM_NIL));}
                else {
                  X60Qx_586 = NIM_FALSE;}
                if (X60Qx_586){
                  Value_0_valzr1t4f X60Qlhs_126 = a0_0;
                  Value_0_valzr1t4f X60Qx_587 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*a0_0.rf_0).d_00.v_0));
                  a0_0 = X60Qx_587;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_126));}}
              NB8 X60Qx_6;
              X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_20 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
                .a = {
                  0u, 15u, 0u}}
              ;
              NU64 X60Qdesugar_21 = ((NU)a0_0.kind_0);
              if (((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_21 & 7u)))))) != 0u){
                X60Qx_6 = NIM_TRUE;}
              else {
                NB8 X60Qx_7;
                if (g_0.dollarScalar_0){
                  X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_22 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
                    .a = {
                      6u, 0u, 0u}}
                  ;
                  NU64 X60Qdesugar_23 = ((NU)a0_0.kind_0);
                  X60Qx_7 = (((NU8)(X60Qdesugar_22.a[((NU)(X60Qdesugar_23 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_23 & 7u)))))) != 0u);}
                else {
                  X60Qx_7 = NIM_FALSE;}
                X60Qx_6 = X60Qx_7;}
              runBody_0 = X60Qx_6;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a0_0));}
            else {
              NB8 X60Qx_588;
              string_0_sysvq0asl* X60Qx_589 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
              NB8 X60Qx_590 = eqQ_20_sysvq0asl((*X60Qx_589), (string_0_sysvq0asl){
                .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I13045133590002807130_comaa5xpt1)}
              );
              if (X60Qx_590){
                X60Qx_588 = (1 <= cargs_7.len_0);}
              else {
                X60Qx_588 = NIM_FALSE;}
              if (X60Qx_588){
                Value_0_valzr1t4f* X60Qx_591 = getQ_7_Ine8yq71_natd5co251(cargs_7, 0);
                runBody_0 = (!((*X60Qx_591).kind_0 == 17));}
              else {
                NB8 X60Qx_592;
                string_0_sysvq0asl* X60Qx_593 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
                NB8 X60Qx_594 = isStreamGatableIO_0_runot4689((*X60Qx_593));
                if (X60Qx_594){
                  X60Qx_592 = (1 <= cargs_7.len_0);}
                else {
                  X60Qx_592 = NIM_FALSE;}
                if (X60Qx_592){
                  Value_0_valzr1t4f* X60Qx_595 = getQ_7_Ine8yq71_natd5co251(cargs_7, 0);
                  Value_0_valzr1t4f X60QconstRefTemp_6 = (*X60Qx_595);
                  NB8 X60Qx_596 = argIsStream_0_runot4689((&X60QconstRefTemp_6));
                  runBody_0 = X60Qx_596;}}}
            if (runBody_0){
              NB8 X60Qx_597 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
              if (X60Qx_597){
                Proc_0_chu5m1rja1* X60Qx_598 = getQ_7_I7rdp401_vmtuaxp6((*vm_15).d_00.prog_0.procs_0, g_0.fallback_0);
                traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_598).name_0, cargs_7, curLine_0, (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                );}
              Value_0_valzr1t4f rv_6 = runProc_1_vmtuaxp6(vm_15, g_0.fallback_0, cargs_7, NIM_NIL);
              NB8 X60Qx_599 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
              if (X60Qx_599){
                traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_6), (*vm_15).d_00.raised_0);}
              if ((*vm_15).d_00.raised_0){
                unwinding_0 = 2;}
              else {
                Value_0_valzr1t4f X60Qtmp_127 = rv_6;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_6));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_127);
                inc_1_I6wjjge_aow2h993l1((&ip_0));}
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_6));}
            else {
              string_0_sysvq0asl* X60Qx_600 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
              NB8 X60Qx_601 = vmBoundsRaise_0_vmtuaxp6(vm_15, (*X60Qx_600), cargs_7);
              if (X60Qx_601){
                unwinding_0 = 2;}
              else {
                NB8 X60Qx_602 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
                if (X60Qx_602){
                  string_0_sysvq0asl* X60Qx_603 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
                  traceEnter_0_trakthy001((*vm_15).d_00.trace_0, (*X60Qx_603), cargs_7, curLine_0, (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );}
                string_0_sysvq0asl* X60Qx_604 = getQ_7_Ir6d0tw_ast8ri79k((*vm_15).d_00.prog_0.natives_0, g_0.nat_0);
                Value_0_valzr1t4f rv_7 = callNativeVM_0_vmtuaxp6(vm_15, (*X60Qx_604), cargs_7);
                NB8 X60Qx_605 = enabled_0_trakthy001((*vm_15).d_00.trace_0);
                if (X60Qx_605){
                  traceExit_0_trakthy001((*vm_15).d_00.trace_0, (&rv_7), NIM_FALSE);}
                Value_0_valzr1t4f X60Qtmp_128 = rv_7;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_7));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_128);
                inc_1_I6wjjge_aow2h993l1((&ip_0));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_7));}}
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_7);}
          break;
          case 45:
          {
            NI32 cnt_0 = ins_0.b_0;
            seq_0_I50urnw_chu5m1rja1 tmp_1 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
            NI32 k_4 = 0;
            {
              while (k_4 < cnt_0){
                Value_0_valzr1t4f X60Qx_606 = popv_0_vmtuaxp6((&stack_1));
                add_0_Itre92n_comaa5xpt1((&tmp_1), X60Qx_606);
                inc_1_I6wjjge_aow2h993l1((&k_4));}}
            whileStmtLabel_2: ;
            seq_0_Iw8xl5b1_flaksyopx1 elems_0 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
            NI32 X60Qx_607 = len_3_I4n9kvq_comaa5xpt1(tmp_1);
            NI32 j_1 = ((NI32)(X60Qx_607 - 1));
            {
              while (0 <= j_1){
                Value_0_valzr1t4f* X60Qx_608 = getQ_7_Ine8yq71_natd5co251(tmp_1, j_1);
                Value_0_valzr1t4f X60QconstRefTemp_7 = (*X60Qx_608);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_609 = newCell_0_valzr1t4f((&X60QconstRefTemp_7));
                add_0_Ijpw0mu_flaksyopx1((&elems_0), X60Qx_609);
                dec_1_I0nzoz91_ast8ri79k((&j_1));}}
            whileStmtLabel_3: ;
            void* X60Qx_610 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_129 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_610);
            seq_0_Iw8xl5b1_flaksyopx1 X60Qtmp_130 = elems_0;
            eQwasMoved_1_I4kgdoh1_flaksyopx1((&elems_0));
            (*X60Qtmp_129) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qtmp_130, .lo_0 = ins_0.a_0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
            ;
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 9, .arr_0 = X60Qtmp_129}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroy_1_I8k3d0z1_flaksyopx1(elems_0);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(tmp_1);}
          break;
          case 46:
          {
            NI32 cnt_1 = ins_0.b_0;
            seq_0_I50urnw_chu5m1rja1 tmp_2 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
            NI32 k_5 = 0;
            {
              while (k_5 < cnt_1){
                Value_0_valzr1t4f X60Qx_611 = popv_0_vmtuaxp6((&stack_1));
                add_0_Itre92n_comaa5xpt1((&tmp_2), X60Qx_611);
                inc_1_I6wjjge_aow2h993l1((&k_5));}}
            whileStmtLabel_4: ;
            seq_0_Iw8xl5b1_flaksyopx1 elems_1 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
            NI32 X60Qx_612 = len_3_I4n9kvq_comaa5xpt1(tmp_2);
            NI32 j_2 = ((NI32)(X60Qx_612 - 1));
            {
              while (0 <= j_2){
                Value_0_valzr1t4f* X60Qx_613 = getQ_7_Ine8yq71_natd5co251(tmp_2, j_2);
                Value_0_valzr1t4f X60QconstRefTemp_8 = (*X60Qx_613);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_614 = newCell_0_valzr1t4f((&X60QconstRefTemp_8));
                add_0_Ijpw0mu_flaksyopx1((&elems_1), X60Qx_614);
                dec_1_I0nzoz91_ast8ri79k((&j_2));}}
            whileStmtLabel_5: ;
            void* X60Qx_615 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_131 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_615);
            seq_0_Iw8xl5b1_flaksyopx1 X60Qtmp_132 = elems_1;
            eQwasMoved_1_I4kgdoh1_flaksyopx1((&elems_1));
            (*X60Qtmp_131) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qtmp_132, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
            ;
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 8, .sq_0 = X60Qtmp_131}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroy_1_I8k3d0z1_flaksyopx1(elems_1);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(tmp_2);}
          break;
          case 47:
          {
            if (0 < stack_1.len_0){
              NI32 X60Qx_616 = len_3_I4n9kvq_comaa5xpt1(stack_1);
              Value_0_valzr1t4f* X60Qx_617 = getQ_7_Ine8yq71_natd5co251(stack_1, ((NI32)(X60Qx_616 - 1)));
              Value_0_valzr1t4f X60QconstRefTemp_9 = (*X60Qx_617);
              Value_0_valzr1t4f s_43 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_9));
              NB8 X60Qx_618;
              NB8 X60Qx_619;
              if (s_43.kind_0 == 8){
                X60Qx_619 = (!(s_43.sq_0 == NIM_NIL));}
              else {
                X60Qx_619 = NIM_FALSE;}
              if (X60Qx_619){
                X60Qx_618 = (0 < (*s_43.sq_0).d_00.elems_0.len_0);}
              else {
                X60Qx_618 = NIM_FALSE;}
              if (X60Qx_618){
                Value_0_valzr1t4f* X60Qx_620 = getQ_7_Ine8yq71_natd5co251((*vm_15).d_00.prog_0.consts_0, ins_0.a_0);
                Value_0_valzr1t4f X60QconstRefTemp_10 = (*X60Qx_620);
                Value_0_valzr1t4f tmpl_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_10));
                NI32 i_27 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_621 = len_3_I83dzei_flaksyopx1((*s_43.sq_0).d_00.elems_0);
                    if (i_27 < X60Qx_621){
                      Value_0_valzr1t4f X60Qtmp_133 = deepCopyValue_0_valzr1t4f((&tmpl_0));
                      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_622 = newCell_0_valzr1t4f((&X60Qtmp_133));
                      putQ_7_I41w2p9_runot4689((&(*s_43.sq_0).d_00.elems_0), i_27, X60Qx_622);
                      inc_1_I6wjjge_aow2h993l1((&i_27));
                      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_133));}
                    else {
                      break;}}}
                whileStmtLabel_6: ;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&tmpl_0));}
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_43));}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 48:
          {
            Value_0_valzr1t4f idx_1 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_2 = popv_0_vmtuaxp6((&stack_1));
            NI64 X60Qx_623 = asInt_0_valzr1t4f((&idx_1));
            NI32 i_29 = ((NI32)X60Qx_623);
            NB8 X60Qx_624;
            if (recv_2.kind_0 == 13){
              X60Qx_624 = (!(recv_2.region_0 == NIM_NIL));}
            else {
              X60Qx_624 = NIM_FALSE;}
            if (X60Qx_624){
              Value_0_valzr1t4f X60Qx_625 = flIndexGet_0_flaksyopx1((&recv_2), i_29);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_625);
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            else {
              NB8 oob_0 = NIM_FALSE;
              if (ins_0.a_0 == 1){
                Value_0_valzr1t4f rv_8 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_2));
                NB8 X60Qx_626;
                if (rv_8.kind_0 == 13){
                  X60Qx_626 = (!(rv_8.loc_0 == NIM_NIL));}
                else {
                  X60Qx_626 = NIM_FALSE;}
                if (X60Qx_626){
                  Value_0_valzr1t4f X60Qlhs_134 = rv_8;
                  Value_0_valzr1t4f X60Qx_627 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_8.loc_0).d_00.v_0));
                  rv_8 = X60Qx_627;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_134));}
                else {
                  NB8 X60Qx_628;
                  if (rv_8.kind_0 == 12){
                    X60Qx_628 = (!(rv_8.rf_0 == NIM_NIL));}
                  else {
                    X60Qx_628 = NIM_FALSE;}
                  if (X60Qx_628){
                    Value_0_valzr1t4f X60Qlhs_135 = rv_8;
                    Value_0_valzr1t4f X60Qx_629 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_8.rf_0).d_00.v_0));
                    rv_8 = X60Qx_629;
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_135));}}
                switch (rv_8.kind_0){
                  case 9:
                  {
                    if ((!(rv_8.arr_0 == NIM_NIL))){
                      NI32 lo_2 = (*rv_8.arr_0).d_00.lo_0;
                      NI32 X60Qx_630 = len_3_I83dzei_flaksyopx1((*rv_8.arr_0).d_00.elems_0);
                      NI32 hi_2 = ((NI32)(((NI32)(lo_2 + X60Qx_630)) - 1));
                      NB8 X60Qx_631;
                      if (i_29 < lo_2){
                        X60Qx_631 = NIM_TRUE;}
                      else {
                        X60Qx_631 = (hi_2 < i_29);}
                      if (X60Qx_631){
                        vmRaiseIndexDefect_0_vmtuaxp6(vm_15, i_29, lo_2, hi_2);
                        oob_0 = NIM_TRUE;}}}
                  break;
                  case 8:
                  {
                    NB8 X60Qx_632;
                    if ((!(rv_8.sq_0 == NIM_NIL))){
                      NB8 X60Qx_633;
                      if (i_29 < 0){
                        X60Qx_633 = NIM_TRUE;}
                      else {
                        X60Qx_633 = ((*rv_8.sq_0).d_00.elems_0.len_0 <= i_29);}
                      X60Qx_632 = X60Qx_633;}
                    else {
                      X60Qx_632 = NIM_FALSE;}
                    if (X60Qx_632){
                      NI32 X60Qx_634 = len_3_I83dzei_flaksyopx1((*rv_8.sq_0).d_00.elems_0);
                      vmRaiseIndexDefect_0_vmtuaxp6(vm_15, i_29, 0, ((NI32)(X60Qx_634 - 1)));
                      oob_0 = NIM_TRUE;}}
                  break;
                  default:
                  {
                    }
                  break;}
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_8));}
              if (oob_0){
                unwinding_0 = 2;}
              else {
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_4 = indexCell_0_vmtuaxp6((&recv_2), i_29);
                if ((!(cell_4 == NIM_NIL))){
                  Value_0_valzr1t4f X60Qx_635 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_4).d_00.v_0));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_635);}
                else {
                  string_0_sysvq0asl X60Qdesugar_24 = dollarQ_2_sysvq0asl(i_29);
                  string_0_sysvq0asl X60Qdesugar_25 = dollarX60Q_ValueKind_0_valzr1t4f(recv_2.kind_0);
                  NI32 X60Qx_636 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I2711403001631354929_vmtuaxp6)}
                  );
                  NI32 X60Qx_637 = len_4_sysvq0asl(X60Qdesugar_24);
                  NI32 X60Qx_638 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I12553036805083656819_vmtuaxp6)}
                  );
                  NI32 X60Qx_639 = len_4_sysvq0asl(X60Qdesugar_25);
                  NI32 X60Qx_640 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 10497u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_636 + X60Qx_637)) + X60Qx_638)) + X60Qx_639)) + X60Qx_640)));
                  add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
                    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I2711403001631354929_vmtuaxp6)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_24);
                  add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
                    .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I12553036805083656819_vmtuaxp6)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_25);
                  add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
                    .bytes_0 = 10497u, .more_0 = NIM_NIL}
                  );
                  softNil_0_vmtuaxp6((string_0_sysvq0asl){
                    .bytes_0 = 1232105470u, .more_0 = (&strlit_0_I8241163739446522972_chu5m1rja1)}
                  , X60Qdesugar_26);
                  Value_0_valzr1t4f X60Qx_641 = vNil_0_valzr1t4f();
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_641);
                  nimStrDestroy(X60Qdesugar_26);
                  nimStrDestroy(X60Qdesugar_25);
                  nimStrDestroy(X60Qdesugar_24);}
                inc_1_I6wjjge_aow2h993l1((&ip_0));
                eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_4);}}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_2));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_1));}
          break;
          case 49:
          {
            Value_0_valzr1t4f idx_2 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_3 = popv_0_vmtuaxp6((&stack_1));
            NI64 X60Qx_642 = asInt_0_valzr1t4f((&idx_2));
            NI32 i_30 = ((NI32)X60Qx_642);
            NB8 X60Qx_643;
            if (recv_3.kind_0 == 13){
              X60Qx_643 = (!(recv_3.region_0 == NIM_NIL));}
            else {
              X60Qx_643 = NIM_FALSE;}
            if (X60Qx_643){
              X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_644 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_vmtuaxp6(recv_3.region_0);
              NI32 X60Qx_645 = regionElemBytes_0_flaksyopx1((&recv_3));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qx_644, .foff_0 = ((NI32)(recv_3.foff_0 + ((NI32)((NI32)(i_30 * X60Qx_645))))), .elemBits_0 = recv_3.elemBits_0, .ecode_0 = recv_3.ecode_0, .etype_0 = recv_3.etype_0}
              );
              inc_1_I6wjjge_aow2h993l1((&ip_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_3));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_2));
              goto continueLabel_1;}
            NB8 X60Qx_646;
            if (recv_3.kind_0 == 13){
              NB8 X60Qx_647;
              if ((!(recv_3.arrOwn_0 == NIM_NIL))){
                X60Qx_647 = NIM_TRUE;}
              else {
                X60Qx_647 = (!(recv_3.seqOwn_0 == NIM_NIL));}
              X60Qx_646 = X60Qx_647;}
            else {
              X60Qx_646 = NIM_FALSE;}
            if (X60Qx_646){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_5 = indexCell_0_vmtuaxp6((&recv_3), i_30);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_136 = cell_5;
              eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&cell_5));
              X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_137 = recv_3.arrOwn_0;
              eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&recv_3.arrOwn_0));
              X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_138 = recv_3.seqOwn_0;
              eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&recv_3.seqOwn_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 13, .loc_0 = X60Qtmp_136, .arrOwn_0 = X60Qtmp_137, .seqOwn_0 = X60Qtmp_138, .base_0 = ((NI32)(recv_3.base_0 + i_30)), .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
              );
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_5);}
            else {
              Value_0_valzr1t4f p_3 = flAddrOfIndex_0_flaksyopx1((&recv_3), i_30);
              NB8 X60Qx_648;
              NB8 X60Qx_649;
              if (p_3.loc_0 == NIM_NIL){
                X60Qx_649 = (p_3.arrOwn_0 == NIM_NIL);}
              else {
                X60Qx_649 = NIM_FALSE;}
              if (X60Qx_649){
                X60Qx_648 = (p_3.seqOwn_0 == NIM_NIL);}
              else {
                X60Qx_648 = NIM_FALSE;}
              if (X60Qx_648){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_3));
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_650 = indexCell_0_vmtuaxp6((&recv_3), i_30);
                p_3 = (Value_0_valzr1t4f){
                  .kind_0 = 13, .loc_0 = X60Qx_650, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
                ;}
              Value_0_valzr1t4f X60Qtmp_139 = p_3;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_3));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_139);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_3));}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_3));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_2));}
          break;
          case 50:
          {
            Value_0_valzr1t4f X60Qtmp_140 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f val_1 = copyOnAssign_0_valzr1t4f((&X60Qtmp_140));
            Value_0_valzr1t4f idx_3 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_4 = popv_0_vmtuaxp6((&stack_1));
            NI64 X60Qx_651 = asInt_0_valzr1t4f((&idx_3));
            NI32 i_31 = ((NI32)X60Qx_651);
            NB8 X60Qx_652;
            if (recv_4.kind_0 == 13){
              X60Qx_652 = (!(recv_4.region_0 == NIM_NIL));}
            else {
              X60Qx_652 = NIM_FALSE;}
            if (X60Qx_652){
              flStoreAt_0_flaksyopx1((&recv_4), i_31, (&val_1));}
            else {
              if (recv_4.kind_0 == 0){
                failNilIndex_0_runot4689((*vm_15).d_00.sink_0, (string_0_sysvq0asl){
                  .bytes_0 = 980252414u, .more_0 = (&strlit_0_I13454172589441230177_vmtuaxp6)}
                );}
              else {
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_6 = indexCell_0_vmtuaxp6((&recv_4), i_31);
                if ((!(cell_6 == NIM_NIL))){
                  Value_0_valzr1t4f* X60Qlhs_141 = (&(*cell_6).d_00.v_0);
                  Value_0_valzr1t4f X60Qlhs_142 = val_1;
                  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&val_1));
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_141)));
                  (*X60Qlhs_141) = X60Qlhs_142;}
                eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_6);}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_4));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_3));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&val_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_140));}
          break;
          case 72:
          {
            Value_0_valzr1t4f X60Qx_8;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));
            if (0 < stack_1.len_0){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));
              Value_0_valzr1t4f X60Qx_653 = popv_0_vmtuaxp6((&stack_1));
              X60Qx_8 = X60Qx_653;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));
              Value_0_valzr1t4f X60Qx_654 = vNil_0_valzr1t4f();
              X60Qx_8 = X60Qx_654;}
            Value_0_valzr1t4f yv_0 = X60Qx_8;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));
            if ((!(coro_2 == NIM_NIL))){
              seq_0_I50urnw_chu5m1rja1* X60Qlhs_143 = (&(*coro_2).d_00.stack_0);
              seq_0_I50urnw_chu5m1rja1 X60Qlhs_144 = stack_1;
              eQwasMoved_1_Ivxly0t1_chu5m1rja1((&stack_1));
              eQdestroy_1_Inxd7ue1_chu5m1rja1((*X60Qlhs_143));
              (*X60Qlhs_143) = X60Qlhs_144;
              seq_0_Ifq4s5b1_vmtuaxp6* X60Qlhs_145 = (&(*coro_2).d_00.handlers_0);
              seq_0_Ifq4s5b1_vmtuaxp6 X60Qlhs_146 = handlers_0;
              eQwasMoved_1_Itejfoj_vmtuaxp6((&handlers_0));
              eQdestroy_1_I3wpak31_vmtuaxp6((*X60Qlhs_145));
              (*X60Qlhs_145) = X60Qlhs_146;
              seq_0_I32zqoq1_vmtuaxp6* X60Qlhs_147 = (&(*coro_2).d_00.pendings_0);
              seq_0_I32zqoq1_vmtuaxp6 X60Qlhs_148 = pendings_0;
              eQwasMoved_1_Ifc721e1_vmtuaxp6((&pendings_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6((*X60Qlhs_147));
              (*X60Qlhs_147) = X60Qlhs_148;
              (*coro_2).d_00.ip_0 = ((NI32)(ip_0 + 1));
              (*coro_2).d_00.suspended_0 = NIM_TRUE;
              Value_0_valzr1t4f* X60Qlhs_149 = (&(*coro_2).d_00.lastVal_0);
              Value_0_valzr1t4f X60Qlhs_150 = (*coro_2).d_00.lastVal_0;
              Value_0_valzr1t4f X60Qx_655 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&yv_0));
              (*X60Qlhs_149) = X60Qx_655;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_150));
              Value_0_valzr1t4f X60Qtmp_151 = yv_0;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&yv_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&yv_0));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return X60Qtmp_151;}
            else {
              inc_1_I6wjjge_aow2h993l1((&ip_0));}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&yv_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_8));}
          break;
          case 76:
          {
            if ((!((*vm_15).d_00.curCoro_0 == NIM_NIL))){
              (*(*vm_15).d_00.curCoro_0).d_00.awaitingPark_0 = NIM_TRUE;
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_656 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*vm_15).d_00.curCoro_0);
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 17, .coro_0 = ((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)X60Qx_656)}
              );}
            else {
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 17, .coro_0 = NIM_NIL}
              );}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 77:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_8 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* child_0 = makePassiveCoro_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_8, NIM_NIL);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qtmp_152 = child_0;
            eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&child_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 17, .coro_0 = ((X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f*)X60Qtmp_152)}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_0);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_8);}
          break;
          case 78:
          {
            NB8 X60Qx_657;
            NB8 X60Qx_658;
            if ((!(coro_2 == NIM_NIL))){
              X60Qx_658 = ((*vm_15).d_00.curCoro_0 == coro_2);}
            else {
              X60Qx_658 = NIM_FALSE;}
            if (X60Qx_658){
              X60Qx_657 = (*coro_2).d_00.awaitingPark_0;}
            else {
              X60Qx_657 = NIM_FALSE;}
            if (X60Qx_657){
              (*coro_2).d_00.awaitingPark_0 = NIM_FALSE;
              seq_0_I50urnw_chu5m1rja1* X60Qlhs_153 = (&(*coro_2).d_00.stack_0);
              seq_0_I50urnw_chu5m1rja1 X60Qlhs_154 = stack_1;
              eQwasMoved_1_Ivxly0t1_chu5m1rja1((&stack_1));
              eQdestroy_1_Inxd7ue1_chu5m1rja1((*X60Qlhs_153));
              (*X60Qlhs_153) = X60Qlhs_154;
              seq_0_Ifq4s5b1_vmtuaxp6* X60Qlhs_155 = (&(*coro_2).d_00.handlers_0);
              seq_0_Ifq4s5b1_vmtuaxp6 X60Qlhs_156 = handlers_0;
              eQwasMoved_1_Itejfoj_vmtuaxp6((&handlers_0));
              eQdestroy_1_I3wpak31_vmtuaxp6((*X60Qlhs_155));
              (*X60Qlhs_155) = X60Qlhs_156;
              seq_0_I32zqoq1_vmtuaxp6* X60Qlhs_157 = (&(*coro_2).d_00.pendings_0);
              seq_0_I32zqoq1_vmtuaxp6 X60Qlhs_158 = pendings_0;
              eQwasMoved_1_Ifc721e1_vmtuaxp6((&pendings_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6((*X60Qlhs_157));
              (*X60Qlhs_157) = X60Qlhs_158;
              (*coro_2).d_00.ip_0 = ((NI32)(ip_0 + 1));
              (*coro_2).d_00.parked_0 = NIM_TRUE;
              (*vm_15).d_00.coroStep_0 = 1;
              Value_0_valzr1t4f X60Qx_659 = vNil_0_valzr1t4f();
              result_23 = X60Qx_659;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;}
            else {
              inc_1_I6wjjge_aow2h993l1((&ip_0));}}
          break;
          case 79:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_9 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            NB8 X60Qx_660;
            if ((!(coro_2 == NIM_NIL))){
              X60Qx_660 = ((*vm_15).d_00.curCoro_0 == coro_2);}
            else {
              X60Qx_660 = NIM_FALSE;}
            if (X60Qx_660){
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* child_1 = makePassiveCoro_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_9, NIM_NIL);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_159 = (&(*child_1).d_00.caller_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_160 = (*child_1).d_00.caller_0;
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_661 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_2);
              (*X60Qlhs_159) = X60Qx_661;
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_160);
              seq_0_I50urnw_chu5m1rja1 snap_0 = stack_1;
              eQwasMoved_1_Ivxly0t1_chu5m1rja1((&stack_1));
              Value_0_valzr1t4f X60Qx_662 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&snap_0), X60Qx_662);
              seq_0_I50urnw_chu5m1rja1* X60Qlhs_161 = (&(*coro_2).d_00.stack_0);
              seq_0_I50urnw_chu5m1rja1 X60Qlhs_162 = (*coro_2).d_00.stack_0;
              seq_0_I50urnw_chu5m1rja1 X60Qx_663 = eQdup_1_I28mx5s1_chu5m1rja1(snap_0);
              (*X60Qlhs_161) = X60Qx_663;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qlhs_162);
              seq_0_Ifq4s5b1_vmtuaxp6* X60Qlhs_163 = (&(*coro_2).d_00.handlers_0);
              seq_0_Ifq4s5b1_vmtuaxp6 X60Qlhs_164 = handlers_0;
              eQwasMoved_1_Itejfoj_vmtuaxp6((&handlers_0));
              eQdestroy_1_I3wpak31_vmtuaxp6((*X60Qlhs_163));
              (*X60Qlhs_163) = X60Qlhs_164;
              seq_0_I32zqoq1_vmtuaxp6* X60Qlhs_165 = (&(*coro_2).d_00.pendings_0);
              seq_0_I32zqoq1_vmtuaxp6 X60Qlhs_166 = pendings_0;
              eQwasMoved_1_Ifc721e1_vmtuaxp6((&pendings_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6((*X60Qlhs_165));
              (*X60Qlhs_165) = X60Qlhs_166;
              (*coro_2).d_00.ip_0 = ((NI32)(ip_0 + 1));
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_167 = (&(*child_1).d_00.retToCoro_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_168 = (*child_1).d_00.retToCoro_0;
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_664 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_2);
              (*X60Qlhs_167) = X60Qx_664;
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_168);
              NI32 X60Qx_665 = len_3_I4n9kvq_comaa5xpt1(snap_0);
              (*child_1).d_00.retToIdx_0 = ((NI32)(X60Qx_665 - 1));
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_169 = (&(*vm_15).d_00.pendingChild_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_170 = child_1;
              eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&child_1));
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*X60Qlhs_169));
              (*X60Qlhs_169) = X60Qlhs_170;
              (*vm_15).d_00.coroStep_0 = 2;
              Value_0_valzr1t4f X60Qx_666 = vNil_0_valzr1t4f();
              result_23 = X60Qx_666;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(snap_0);
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_1);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_9);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(snap_0);
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_1);}
            else {
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* child_2 = makePassiveCoro_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_9, NIM_NIL);
              drivePassiveVm_1_vmtuaxp6(vm_15, child_2);
              inc_1_I6wjjge_aow2h993l1((&ip_0));
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_2);}
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_9);}
          break;
          case 80:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_10 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* start_2 = makePassiveCoro_1_vmtuaxp6(vm_15, ins_0.a_0, cargs_10, NIM_NIL);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* savedCur_0 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*vm_15).d_00.curCoro_0);
            drivePassiveVm_1_vmtuaxp6(vm_15, start_2);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_171 = (&(*vm_15).d_00.curCoro_0);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_172 = savedCur_0;
            eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&savedCur_0));
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*X60Qlhs_171));
            (*X60Qlhs_171) = X60Qlhs_172;
            if ((*start_2).d_00.finished_0){
              Value_0_valzr1t4f X60Qx_667 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*start_2).d_00.retVal_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_667);}
            else {
              Value_0_valzr1t4f X60Qx_668 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_668);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(savedCur_0);
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(start_2);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_10);}
          break;
          case 81:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_11 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            MethodSite_0_chu5m1rja1* X60Qx_669 = getQ_7_Ig0gjeo1_vmtuaxp6((*vm_15).d_00.prog_0.methodSites_0, ins_0.a_0);
            MethodSite_0_chu5m1rja1 site_2 = (*X60Qx_669);
            NI32 target_2 = site_2.fallbackIdx_0;
            if (1 <= cargs_11.len_0){
              Value_0_valzr1t4f* X60Qx_670 = getQ_7_Ine8yq71_natd5co251(cargs_11, 0);
              Value_0_valzr1t4f X60QconstRefTemp_11 = (*X60Qx_670);
              NI32 X60Qx_671 = dispatchMethodVm_0_vmtuaxp6(vm_15, site_2, (&X60QconstRefTemp_11));
              target_2 = X60Qx_671;}
            NB8 X60Qx_672;
            if ((!(coro_2 == NIM_NIL))){
              X60Qx_672 = ((*vm_15).d_00.curCoro_0 == coro_2);}
            else {
              X60Qx_672 = NIM_FALSE;}
            if (X60Qx_672){
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* child_3 = makePassiveCoro_1_vmtuaxp6(vm_15, target_2, cargs_11, NIM_NIL);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_173 = (&(*child_3).d_00.caller_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_174 = (*child_3).d_00.caller_0;
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_673 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_2);
              (*X60Qlhs_173) = X60Qx_673;
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_174);
              seq_0_I50urnw_chu5m1rja1 snap_1 = stack_1;
              eQwasMoved_1_Ivxly0t1_chu5m1rja1((&stack_1));
              Value_0_valzr1t4f X60Qx_674 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&snap_1), X60Qx_674);
              seq_0_I50urnw_chu5m1rja1* X60Qlhs_175 = (&(*coro_2).d_00.stack_0);
              seq_0_I50urnw_chu5m1rja1 X60Qlhs_176 = (*coro_2).d_00.stack_0;
              seq_0_I50urnw_chu5m1rja1 X60Qx_675 = eQdup_1_I28mx5s1_chu5m1rja1(snap_1);
              (*X60Qlhs_175) = X60Qx_675;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(X60Qlhs_176);
              seq_0_Ifq4s5b1_vmtuaxp6* X60Qlhs_177 = (&(*coro_2).d_00.handlers_0);
              seq_0_Ifq4s5b1_vmtuaxp6 X60Qlhs_178 = handlers_0;
              eQwasMoved_1_Itejfoj_vmtuaxp6((&handlers_0));
              eQdestroy_1_I3wpak31_vmtuaxp6((*X60Qlhs_177));
              (*X60Qlhs_177) = X60Qlhs_178;
              seq_0_I32zqoq1_vmtuaxp6* X60Qlhs_179 = (&(*coro_2).d_00.pendings_0);
              seq_0_I32zqoq1_vmtuaxp6 X60Qlhs_180 = pendings_0;
              eQwasMoved_1_Ifc721e1_vmtuaxp6((&pendings_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6((*X60Qlhs_179));
              (*X60Qlhs_179) = X60Qlhs_180;
              (*coro_2).d_00.ip_0 = ((NI32)(ip_0 + 1));
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_181 = (&(*child_3).d_00.retToCoro_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_182 = (*child_3).d_00.retToCoro_0;
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_676 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(coro_2);
              (*X60Qlhs_181) = X60Qx_676;
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_182);
              NI32 X60Qx_677 = len_3_I4n9kvq_comaa5xpt1(snap_1);
              (*child_3).d_00.retToIdx_0 = ((NI32)(X60Qx_677 - 1));
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_183 = (&(*vm_15).d_00.pendingChild_0);
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_184 = child_3;
              eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&child_3));
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*X60Qlhs_183));
              (*X60Qlhs_183) = X60Qlhs_184;
              (*vm_15).d_00.coroStep_0 = 2;
              Value_0_valzr1t4f X60Qx_678 = vNil_0_valzr1t4f();
              result_23 = X60Qx_678;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(snap_1);
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_3);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_11);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
              eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
              eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
              eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
              return result_23;
              eQdestroy_1_Inxd7ue1_chu5m1rja1(snap_1);
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_3);}
            else {
              X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* child_4 = makePassiveCoro_1_vmtuaxp6(vm_15, target_2, cargs_11, NIM_NIL);
              drivePassiveVm_1_vmtuaxp6(vm_15, child_4);
              inc_1_I6wjjge_aow2h993l1((&ip_0));
              eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(child_4);}
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_11);}
          break;
          case 82:
          {
            seq_0_I50urnw_chu5m1rja1 cargs_12 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            MethodSite_0_chu5m1rja1* X60Qx_679 = getQ_7_Ig0gjeo1_vmtuaxp6((*vm_15).d_00.prog_0.methodSites_0, ins_0.a_0);
            MethodSite_0_chu5m1rja1 site_3 = (*X60Qx_679);
            NI32 target_3 = site_3.fallbackIdx_0;
            if (1 <= cargs_12.len_0){
              Value_0_valzr1t4f* X60Qx_680 = getQ_7_Ine8yq71_natd5co251(cargs_12, 0);
              Value_0_valzr1t4f X60QconstRefTemp_12 = (*X60Qx_680);
              NI32 X60Qx_681 = dispatchMethodVm_0_vmtuaxp6(vm_15, site_3, (&X60QconstRefTemp_12));
              target_3 = X60Qx_681;}
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* start_3 = makePassiveCoro_1_vmtuaxp6(vm_15, target_3, cargs_12, NIM_NIL);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* savedCur_1 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*vm_15).d_00.curCoro_0);
            drivePassiveVm_1_vmtuaxp6(vm_15, start_3);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_185 = (&(*vm_15).d_00.curCoro_0);
            X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_186 = savedCur_1;
            eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&savedCur_1));
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*X60Qlhs_185));
            (*X60Qlhs_185) = X60Qlhs_186;
            if ((*start_3).d_00.finished_0){
              Value_0_valzr1t4f X60Qx_682 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*start_3).d_00.retVal_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_682);}
            else {
              Value_0_valzr1t4f X60Qx_683 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_683);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(savedCur_1);
            eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(start_3);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(cargs_12);}
          break;
          case 36:
          {
            Value_0_valzr1t4f X60Qx_9;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_9));
            if (0 < stack_1.len_0){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_9));
              Value_0_valzr1t4f X60Qx_684 = popv_0_vmtuaxp6((&stack_1));
              X60Qx_9 = X60Qx_684;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_9));
              Value_0_valzr1t4f X60Qx_685 = vNil_0_valzr1t4f();
              X60Qx_9 = X60Qx_685;}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
            retval_0 = X60Qx_9;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_9));
            unwinding_0 = 1;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_9));}
          break;
          case 37:
          case 38:
          case 40:
          {
            ObjInfo_0_chu5m1rja1* X60Qx_686 = getQ_7_Ia248tr_vmtuaxp6((*vm_15).d_00.prog_0.objInfos_0, ins_0.a_0);
            ObjInfo_0_chu5m1rja1 info_0 = eQdupQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1((*X60Qx_686));
            seq_0_I50urnw_chu5m1rja1 vals_0 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            void* X60Qx_687 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_187 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_687);
            seq_0_In6doa_ast8ri79k X60Qx_688 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
            seq_0_Iw8xl5b1_flaksyopx1 X60Qx_689 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
            (*X60Qtmp_187) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
                .typeSym_0 = info_0.typeSym_0, .names_0 = X60Qx_688, .cells_0 = X60Qx_689}}
            ;
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_5 = X60Qtmp_187;
            NI32 i_33 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_690 = len_3_I4n9kvq_comaa5xpt1(vals_0);
                if (i_33 < X60Qx_690){
                  NU32* X60Qx_691 = getQ_7_I2v00yv1_buiyylk1h1(info_0.fieldSyms_0, i_33);
                  add_0_I34il1q_comaa5xpt1((&(*box_5).d_00.names_0), (*X60Qx_691));
                  Value_0_valzr1t4f* X60Qx_692 = getQ_7_Ine8yq71_natd5co251(vals_0, i_33);
                  Value_0_valzr1t4f X60QconstRefTemp_13 = (*X60Qx_692);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_693 = newCell_0_valzr1t4f((&X60QconstRefTemp_13));
                  add_0_Ijpw0mu_flaksyopx1((&(*box_5).d_00.cells_0), X60Qx_693);
                  inc_1_I6wjjge_aow2h993l1((&i_33));}
                else {
                  break;}}}
            whileStmtLabel_7: ;
            switch (ins_0.op_0){
              case 37:
              {
                X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_188 = box_5;
                eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_5));
                add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                  .kind_0 = 11, .obj_0 = X60Qtmp_188}
                );}
              break;
              case 38:
              {
                X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_190 = box_5;
                eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_5));
                Value_0_valzr1t4f X60Qtmp_189 = (Value_0_valzr1t4f){
                  .kind_0 = 11, .obj_0 = X60Qtmp_190}
                ;
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_39 = newCell_0_valzr1t4f((&X60Qtmp_189));
                add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                  .kind_0 = 12, .rf_0 = X60Qx_39}
                );
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_189));}
              break;
              default:
              {
                X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_191 = box_5;
                eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_5));
                add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                  .kind_0 = 10, .obj_0 = X60Qtmp_191}
                );}
              break;}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_5);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(vals_0);
            eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(info_0);}
          break;
          case 39:
          {
            Value_0_valzr1t4f initv_0 = popv_0_vmtuaxp6((&stack_1));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_694 = newCell_0_valzr1t4f((&initv_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 12, .rf_0 = X60Qx_694}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&initv_0));}
          break;
          case 41:
          {
            Value_0_valzr1t4f X60Qtmp_192 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_5 = fieldRecv_0_vmtuaxp6((&X60Qtmp_192));
            NB8 X60Qx_10;
            X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_27 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
              .a = {
                64u, 3u, 0u}}
            ;
            NU64 X60Qdesugar_28 = ((NU)recv_5.kind_0);
            if (((NU8)(X60Qdesugar_27.a[((NU)(X60Qdesugar_28 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_28 & 7u)))))) != 0u){
              NU32* X60Qx_695 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
              string_0_sysvq0asl X60Qtmp_193 = mBaseName_1_vmtuaxp6((*X60Qx_695));
              NB8 X60Qx_696 = eqQ_20_sysvq0asl(X60Qtmp_193, (string_0_sysvq0asl){
                .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
              );
              X60Qx_10 = X60Qx_696;
              nimStrDestroy(X60Qtmp_193);}
            else {
              X60Qx_10 = NIM_FALSE;}
            if (X60Qx_10){
              switch (recv_5.kind_0){
                case 8:
                {
                  NI32 X60Qx_697 = len_3_I83dzei_flaksyopx1((*recv_5.sq_0).d_00.elems_0);
                  Value_0_valzr1t4f X60Qx_698 = vInt_0_valzr1t4f(((NI64)X60Qx_697), 64);
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_698);}
                break;
                case 6:
                {
                  NI32 X60Qx_699 = len_4_sysvq0asl(recv_5.sval_0);
                  Value_0_valzr1t4f X60Qx_700 = vInt_0_valzr1t4f(((NI64)X60Qx_699), 64);
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_700);}
                break;
                case 9:
                {
                  NI32 X60Qx_701 = len_3_I83dzei_flaksyopx1((*recv_5.arr_0).d_00.elems_0);
                  Value_0_valzr1t4f X60Qx_702 = vInt_0_valzr1t4f(((NI64)X60Qx_701), 64);
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_702);}
                break;
                default:
                {
                  Value_0_valzr1t4f X60Qx_703 = vNil_0_valzr1t4f();
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_703);}
                break;}}
            else {
              NB8 X60Qx_704;
              if (recv_5.kind_0 == 13){
                X60Qx_704 = (!(recv_5.region_0 == NIM_NIL));}
              else {
                X60Qx_704 = NIM_FALSE;}
              if (X60Qx_704){
                NU32* X60Qx_705 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
                X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1 X60Qtmptup_3 = flFieldPtr_0_flaksyopx1((&recv_5), (*X60Qx_705));
                NB8 isFlat_0 = X60Qtmptup_3.fld_0;
                Value_0_valzr1t4f fp_0 = X60Qtmptup_3.fld_1;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_3.fld_1));
                if (isFlat_0){
                  Value_0_valzr1t4f X60Qx_706 = flDeref_0_flaksyopx1((&fp_0));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_706);}
                else {
                  NU32* X60Qx_707 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_7 = regionFieldCellV_0_vmtuaxp6((&recv_5), (*X60Qx_707));
                  if ((!(cell_7 == NIM_NIL))){
                    Value_0_valzr1t4f X60Qx_708 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_7).d_00.v_0));
                    add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_708);}
                  else {
                    Value_0_valzr1t4f X60Qx_709 = vNil_0_valzr1t4f();
                    add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_709);}
                  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_7);}
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fp_0));
                eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_vmtuaxp6((&X60Qtmptup_3));}
              else {
                X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_194 = objOfV_0_vmtuaxp6((&recv_5));
                NU32* X60Qx_710 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_8 = fieldCellV_0_vmtuaxp6(X60Qtmp_194, (*X60Qx_710));
                if ((!(cell_8 == NIM_NIL))){
                  Value_0_valzr1t4f X60Qx_711 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_8).d_00.v_0));
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_711);}
                else {
                  NU32* X60Qx_712 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
                  string_0_sysvq0asl X60Qdesugar_29 = mBaseName_1_vmtuaxp6((*X60Qx_712));
                  string_0_sysvq0asl X60Qdesugar_30 = dollarX60Q_ValueKind_0_valzr1t4f(recv_5.kind_0);
                  NI32 X60Qx_713 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I13854238605625854974_vmtuaxp6)}
                  );
                  NI32 X60Qx_714 = len_4_sysvq0asl(X60Qdesugar_29);
                  NI32 X60Qx_715 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I176574084057763820_vmtuaxp6)}
                  );
                  NI32 X60Qx_716 = len_4_sysvq0asl(X60Qdesugar_30);
                  NI32 X60Qx_717 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I11577963402916336664_vmtuaxp6)}
                  );
                  string_0_sysvq0asl X60Qdesugar_31 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_713 + X60Qx_714)) + X60Qx_715)) + X60Qx_716)) + X60Qx_717)));
                  add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
                    .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I13854238605625854974_vmtuaxp6)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_31), X60Qdesugar_29);
                  add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
                    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I176574084057763820_vmtuaxp6)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_31), X60Qdesugar_30);
                  add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
                    .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I11577963402916336664_vmtuaxp6)}
                  );
                  softNil_0_vmtuaxp6((string_0_sysvq0asl){
                    .bytes_0 = 1282437118u, .more_0 = (&strlit_0_I15083592761932316767_chu5m1rja1)}
                  , X60Qdesugar_31);
                  Value_0_valzr1t4f X60Qx_718 = vNil_0_valzr1t4f();
                  add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_718);
                  nimStrDestroy(X60Qdesugar_31);
                  nimStrDestroy(X60Qdesugar_30);
                  nimStrDestroy(X60Qdesugar_29);}
                eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_8);
                eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_194);}}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_5));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_192));}
          break;
          case 42:
          {
            Value_0_valzr1t4f X60Qtmp_195 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_6 = fieldRecv_0_vmtuaxp6((&X60Qtmp_195));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_9 = NIM_NIL;
            NB8 X60Qx_719;
            if (recv_6.kind_0 == 13){
              X60Qx_719 = (!(recv_6.region_0 == NIM_NIL));}
            else {
              X60Qx_719 = NIM_FALSE;}
            if (X60Qx_719){
              NU32* X60Qx_720 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
              X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1 X60Qtmptup_4 = flFieldPtr_0_flaksyopx1((&recv_6), (*X60Qx_720));
              NB8 isFlat_1 = X60Qtmptup_4.fld_0;
              Value_0_valzr1t4f fp_1 = X60Qtmptup_4.fld_1;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_4.fld_1));
              if (isFlat_1){
                Value_0_valzr1t4f X60Qtmp_196 = fp_1;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&fp_1));
                add_0_Itre92n_comaa5xpt1((&stack_1), X60Qtmp_196);
                inc_1_I6wjjge_aow2h993l1((&ip_0));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fp_1));
                eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_vmtuaxp6((&X60Qtmptup_4));
                eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_9);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_6));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_195));
                goto continueLabel_1;}
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_9);
              NU32* X60Qx_721 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_722 = regionFieldCellV_0_vmtuaxp6((&recv_6), (*X60Qx_721));
              cell_9 = X60Qx_722;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fp_1));
              eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_vmtuaxp6((&X60Qtmptup_4));}
            else {
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_9);
              X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_197 = objOfV_0_vmtuaxp6((&recv_6));
              NU32* X60Qx_723 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_724 = fieldCellV_0_vmtuaxp6(X60Qtmp_197, (*X60Qx_723));
              cell_9 = X60Qx_724;
              eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qtmp_197);}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_198 = cell_9;
            eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&cell_9));
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 13, .loc_0 = X60Qtmp_198, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(cell_9);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_6));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_195));}
          break;
          case 43:
          {
            Value_0_valzr1t4f idx_4 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_7 = popv_0_vmtuaxp6((&stack_1));
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_6 = objOfV_0_vmtuaxp6((&recv_7));
            NI64 X60Qx_725 = asInt_0_valzr1t4f((&idx_4));
            NI32 i_34 = ((NI32)X60Qx_725);
            NB8 X60Qx_726;
            NB8 X60Qx_727;
            if ((!(box_6 == NIM_NIL))){
              X60Qx_727 = (0 <= i_34);}
            else {
              X60Qx_727 = NIM_FALSE;}
            if (X60Qx_727){
              NI32 X60Qx_728 = len_3_I83dzei_flaksyopx1((*box_6).d_00.cells_0);
              X60Qx_726 = (i_34 < X60Qx_728);}
            else {
              X60Qx_726 = NIM_FALSE;}
            if (X60Qx_726){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_729 = getQ_7_Ii14ync1_flaksyopx1((*box_6).d_00.cells_0, i_34);
              Value_0_valzr1t4f X60Qx_730 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_729)).d_00.v_0));
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_730);}
            else {
              string_0_sysvq0asl X60Qdesugar_32 = dollarQ_2_sysvq0asl(i_34);
              string_0_sysvq0asl X60Qdesugar_33 = dollarX60Q_ValueKind_0_valzr1t4f(recv_7.kind_0);
              NI32 X60Qx_731 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I1180022326161049401_vmtuaxp6)}
              );
              NI32 X60Qx_732 = len_4_sysvq0asl(X60Qdesugar_32);
              NI32 X60Qx_733 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I14838583653064907228_vmtuaxp6)}
              );
              NI32 X60Qx_734 = len_4_sysvq0asl(X60Qdesugar_33);
              NI32 X60Qx_735 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 10497u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_34 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_731 + X60Qx_732)) + X60Qx_733)) + X60Qx_734)) + X60Qx_735)));
              add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
                .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I1180022326161049401_vmtuaxp6)}
              );
              add_2_sysvq0asl((&X60Qdesugar_34), X60Qdesugar_32);
              add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
                .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I14838583653064907228_vmtuaxp6)}
              );
              add_2_sysvq0asl((&X60Qdesugar_34), X60Qdesugar_33);
              add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
                .bytes_0 = 10497u, .more_0 = NIM_NIL}
              );
              softNil_0_vmtuaxp6((string_0_sysvq0asl){
                .bytes_0 = 1416654846u, .more_0 = (&strlit_0_I5291897204707904471_chu5m1rja1)}
              , X60Qdesugar_34);
              Value_0_valzr1t4f X60Qx_736 = vNil_0_valzr1t4f();
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_736);
              nimStrDestroy(X60Qdesugar_34);
              nimStrDestroy(X60Qdesugar_33);
              nimStrDestroy(X60Qdesugar_32);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_6);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_7));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_4));}
          break;
          case 44:
          {
            Value_0_valzr1t4f idx_5 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f recv_8 = popv_0_vmtuaxp6((&stack_1));
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_7 = objOfV_0_vmtuaxp6((&recv_8));
            NI64 X60Qx_737 = asInt_0_valzr1t4f((&idx_5));
            NI32 i_35 = ((NI32)X60Qx_737);
            NB8 X60Qx_738;
            NB8 X60Qx_739;
            if ((!(box_7 == NIM_NIL))){
              X60Qx_739 = (0 <= i_35);}
            else {
              X60Qx_739 = NIM_FALSE;}
            if (X60Qx_739){
              NI32 X60Qx_740 = len_3_I83dzei_flaksyopx1((*box_7).d_00.cells_0);
              X60Qx_738 = (i_35 < X60Qx_740);}
            else {
              X60Qx_738 = NIM_FALSE;}
            if (X60Qx_738){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_741 = getQ_7_Ii14ync1_flaksyopx1((*box_7).d_00.cells_0, i_35);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_742 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*X60Qx_741));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 13, .loc_0 = X60Qx_742, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
              );}
            else {
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
              );}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_7);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_8));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&idx_5));}
          break;
          case 52:
          {
            void* X60Qx_743 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689));
            X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* X60Qtmp_199 = ((X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689*)X60Qx_743);
            (*X60Qtmp_199) = (X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689){
              .r_00 = 0, .d_00 = (SetBox_Obj_0_valzr1t4f){
                .words_0 = (X60Qt_0_IAarrayAuS64ZS4_runot4689){
                  .a = {
                    ((NU64)0u), ((NU64)0), ((NU64)0), ((NU64)0)}}}}
            ;
            add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
              .kind_0 = 14, .st_0 = X60Qtmp_199}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 53:
          {
            Value_0_valzr1t4f x_2 = popv_0_vmtuaxp6((&stack_1));
            NI32 X60Qx_744 = len_3_I4n9kvq_comaa5xpt1(stack_1);
            Value_0_valzr1t4f* X60Qx_745 = getQ_7_Ine8yq71_natd5co251(stack_1, ((NI32)(X60Qx_744 - 1)));
            Value_0_valzr1t4f X60QconstRefTemp_14 = (*X60Qx_745);
            Value_0_valzr1t4f s_46 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_14));
            if (s_46.kind_0 == 14){
              NI64 X60Qx_746 = asInt_0_valzr1t4f((&x_2));
              setBit_0_runot4689(s_46.st_0, X60Qx_746);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_46));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_2));}
          break;
          case 54:
          {
            Value_0_valzr1t4f hi_3 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f lo_3 = popv_0_vmtuaxp6((&stack_1));
            NI32 X60Qx_747 = len_3_I4n9kvq_comaa5xpt1(stack_1);
            Value_0_valzr1t4f* X60Qx_748 = getQ_7_Ine8yq71_natd5co251(stack_1, ((NI32)(X60Qx_747 - 1)));
            Value_0_valzr1t4f X60QconstRefTemp_15 = (*X60Qx_748);
            Value_0_valzr1t4f s_47 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_15));
            if (s_47.kind_0 == 14){
              NI64 x_3 = asInt_0_valzr1t4f((&lo_3));
              NI64 top_0 = asInt_0_valzr1t4f((&hi_3));
              {
                while (x_3 <= top_0){
                  setBit_0_runot4689(s_47.st_0, x_3);
                  inc_1_Irn1g7r1_vmtuaxp6((&x_3));}}
              whileStmtLabel_8: ;}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_47));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lo_3));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&hi_3));}
          break;
          case 55:
          {
            Value_0_valzr1t4f x_5 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f p_4 = popv_0_vmtuaxp6((&stack_1));
            NB8 X60Qx_749;
            NB8 X60Qx_750;
            if (p_4.kind_0 == 13){
              X60Qx_750 = (!(p_4.loc_0 == NIM_NIL));}
            else {
              X60Qx_750 = NIM_FALSE;}
            if (X60Qx_750){
              X60Qx_749 = ((*p_4.loc_0).d_00.v_0.kind_0 == 14);}
            else {
              X60Qx_749 = NIM_FALSE;}
            if (X60Qx_749){
              NI64 X60Qx_751 = asInt_0_valzr1t4f((&x_5));
              setBit_0_runot4689((*p_4.loc_0).d_00.v_0.st_0, X60Qx_751);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_4));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_5));}
          break;
          case 56:
          {
            Value_0_valzr1t4f x_6 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f p_5 = popv_0_vmtuaxp6((&stack_1));
            NB8 X60Qx_752;
            NB8 X60Qx_753;
            if (p_5.kind_0 == 13){
              X60Qx_753 = (!(p_5.loc_0 == NIM_NIL));}
            else {
              X60Qx_753 = NIM_FALSE;}
            if (X60Qx_753){
              X60Qx_752 = ((*p_5.loc_0).d_00.v_0.kind_0 == 14);}
            else {
              X60Qx_752 = NIM_FALSE;}
            if (X60Qx_752){
              NI64 X60Qx_754 = asInt_0_valzr1t4f((&x_6));
              clearBit_0_runot4689((*p_5.loc_0).d_00.v_0.st_0, X60Qx_754);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_5));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_6));}
          break;
          case 57:
          {
            Value_0_valzr1t4f x_7 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f s_48 = popv_0_vmtuaxp6((&stack_1));
            if (s_48.kind_0 == 14){
              NI64 X60Qx_755 = asInt_0_valzr1t4f((&x_7));
              NB8 X60Qx_756 = hasBit_0_runot4689(s_48.st_0, X60Qx_755);
              Value_0_valzr1t4f X60Qx_757 = vBool_0_valzr1t4f(X60Qx_756);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_757);}
            else {
              Value_0_valzr1t4f X60Qx_758 = vBool_0_valzr1t4f(NIM_FALSE);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_758);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_48));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_7));}
          break;
          case 58:
          {
            Value_0_valzr1t4f s_49 = popv_0_vmtuaxp6((&stack_1));
            if (s_49.kind_0 == 14){
              NI32 X60Qx_759 = setCard_0_runot4689(s_49.st_0);
              Value_0_valzr1t4f X60Qx_760 = vInt_0_valzr1t4f(((NI64)X60Qx_759), 64);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_760);}
            else {
              Value_0_valzr1t4f X60Qx_761 = vInt_0_valzr1t4f(((NI64)0), 64);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_761);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_49));}
          break;
          case 59:
          {
            Value_0_valzr1t4f b_5 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f a_10 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f X60Qx_762 = setCombine_0_vmtuaxp6((&a_10), (&b_5), ins_0.a_0);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_762);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_10));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_5));}
          break;
          case 60:
          {
            Value_0_valzr1t4f b_6 = popv_0_vmtuaxp6((&stack_1));
            Value_0_valzr1t4f a_11 = popv_0_vmtuaxp6((&stack_1));
            NB8 res_0 = NIM_FALSE;
            NB8 X60Qx_763;
            if (a_11.kind_0 == 14){
              X60Qx_763 = (b_6.kind_0 == 14);}
            else {
              X60Qx_763 = NIM_FALSE;}
            if (X60Qx_763){
              NB8 subset_0 = NIM_TRUE;
              NB8 equal_0 = NIM_TRUE;
              NI32 i_36 = 0;
              {
                while (i_36 < 4){
                  NI32 X60Qx_764 = nimIcheckB(i_36, 3);
                  NI32 X60Qx_765 = nimIcheckB(i_36, 3);
                  if ((!(((NU64)((*a_11.st_0).d_00.words_0.a[X60Qx_764] & ((NU64) ~ (*b_6.st_0).d_00.words_0.a[X60Qx_765]))) == ((NU64)0u)))){
                    subset_0 = NIM_FALSE;}
                  NI32 X60Qx_766 = nimIcheckB(i_36, 3);
                  NI32 X60Qx_767 = nimIcheckB(i_36, 3);
                  if ((!((*a_11.st_0).d_00.words_0.a[X60Qx_766] == (*b_6.st_0).d_00.words_0.a[X60Qx_767]))){
                    equal_0 = NIM_FALSE;}
                  inc_1_I6wjjge_aow2h993l1((&i_36));}}
              whileStmtLabel_9: ;
              switch (ins_0.a_0){
                case 1:
                {
                  res_0 = subset_0;}
                break;
                case 2:
                {
                  NB8 X60Qx_768;
                  if (subset_0){
                    X60Qx_768 = (!equal_0);}
                  else {
                    X60Qx_768 = NIM_FALSE;}
                  res_0 = X60Qx_768;}
                break;
                default:
                {
                  res_0 = equal_0;}
                break;}}
            Value_0_valzr1t4f X60Qx_769 = vBool_0_valzr1t4f(res_0);
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_769);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_11));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_6));}
          break;
          case 61:
          {
            ObjSpec_0_chu5m1rja1* X60Qx_770 = getQ_7_I7ms12l_vmtuaxp6((*vm_15).d_00.prog_0.objSpecs_0, ins_0.a_0);
            ObjSpec_0_chu5m1rja1 spec_2 = eQdupQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1((*X60Qx_770));
            seq_0_I50urnw_chu5m1rja1 vals_1 = popArgs_0_vmtuaxp6((&stack_1), ins_0.b_0);
            void* X60Qx_771 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_200 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_771);
            seq_0_In6doa_ast8ri79k X60Qx_772 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
            seq_0_Iw8xl5b1_flaksyopx1 X60Qx_773 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
            (*X60Qtmp_200) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
                .typeSym_0 = spec_2.typeSym_0, .names_0 = X60Qx_772, .cells_0 = X60Qx_773}}
            ;
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_8 = X60Qtmp_200;
            NI32 i_38 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_774 = len_3_I6y2imo_buiyylk1h1(spec_2.fields_0);
                if (i_38 < X60Qx_774){
                  NU32* X60Qx_775 = getQ_7_I2v00yv1_buiyylk1h1(spec_2.fields_0, i_38);
                  add_0_I34il1q_comaa5xpt1((&(*box_8).d_00.names_0), (*X60Qx_775));
                  NI32 X60Qx_776 = len_3_I4n9kvq_comaa5xpt1(vals_1);
                  if (i_38 < X60Qx_776){
                    Value_0_valzr1t4f* X60Qx_777 = getQ_7_Ine8yq71_natd5co251(vals_1, i_38);
                    Value_0_valzr1t4f X60QconstRefTemp_16 = (*X60Qx_777);
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_778 = newCell_0_valzr1t4f((&X60QconstRefTemp_16));
                    add_0_Ijpw0mu_flaksyopx1((&(*box_8).d_00.cells_0), X60Qx_778);}
                  else {
                    Value_0_valzr1t4f X60Qtmp_201 = vNil_0_valzr1t4f();
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_779 = newCell_0_valzr1t4f((&X60Qtmp_201));
                    add_0_Ijpw0mu_flaksyopx1((&(*box_8).d_00.cells_0), X60Qx_779);
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_201));}
                  inc_1_I6wjjge_aow2h993l1((&i_38));}
                else {
                  break;}}}
            whileStmtLabel_10: ;
            if (spec_2.isRef_0){
              X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_203 = box_8;
              eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_8));
              Value_0_valzr1t4f X60Qtmp_202 = (Value_0_valzr1t4f){
                .kind_0 = 11, .obj_0 = X60Qtmp_203}
              ;
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_40 = newCell_0_valzr1t4f((&X60Qtmp_202));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 12, .rf_0 = X60Qx_40}
              );
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_202));}
            else {
              X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_204 = box_8;
              eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6((&box_8));
              add_0_Itre92n_comaa5xpt1((&stack_1), (Value_0_valzr1t4f){
                .kind_0 = 11, .obj_0 = X60Qtmp_204}
              );}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(box_8);
            eQdestroy_1_Inxd7ue1_chu5m1rja1(vals_1);
            eQdestroyQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(spec_2);}
          break;
          case 62:
          {
            Value_0_valzr1t4f recv_9 = popv_0_vmtuaxp6((&stack_1));
            NU32* X60Qx_780 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.fieldSyms_0, ins_0.a_0);
            Value_0_valzr1t4f X60Qx_781 = fieldOf_0_vmtuaxp6((&recv_9), (*X60Qx_780));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_781);
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_9));}
          break;
          case 63:
          {
            NU32* X60Qx_782 = getQ_7_I2v00yv1_buiyylk1h1((*vm_15).d_00.prog_0.typeSyms_0, ins_0.a_0);
            NU32 target_4 = (*X60Qx_782);
            Value_0_valzr1t4f v_11 = popv_0_vmtuaxp6((&stack_1));
            NB8 X60Qx_783;
            if (v_11.kind_0 == 0){
              X60Qx_783 = NIM_TRUE;}
            else {
              NB8 X60Qx_784;
              if (v_11.kind_0 == 12){
                X60Qx_784 = (v_11.rf_0 == NIM_NIL);}
              else {
                X60Qx_784 = NIM_FALSE;}
              X60Qx_783 = X60Qx_784;}
            if (X60Qx_783){
              Value_0_valzr1t4f X60Qx_785 = vBool_0_valzr1t4f(NIM_TRUE);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_785);}
            else {
              NU32 ct_0 = objTypeOf_0_runot4689((&v_11));
              NB8 X60Qx_786;
              NB8 X60Qx_787 = eqQ_0_nifh7u8pu1(ct_0, ((NU32)0u));
              if ((!X60Qx_787)){
                NB8 X60Qx_788 = isSubtype_0_runot4689(ct_0, target_4);
                X60Qx_786 = X60Qx_788;}
              else {
                X60Qx_786 = NIM_FALSE;}
              Value_0_valzr1t4f X60Qx_789 = vBool_0_valzr1t4f(X60Qx_786);
              add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_789);}
            inc_1_I6wjjge_aow2h993l1((&ip_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_11));}
          break;
          case 64:
          {
            NI32 X60Qx_790 = len_3_I4n9kvq_comaa5xpt1(stack_1);
            add_0_Iwiwppi1_vmtuaxp6((&handlers_0), (Handler_0_vmtuaxp6){
              .catchIp_0 = ins_0.a_0, .finallyIp_0 = ins_0.b_0, .sp_0 = X60Qx_790}
            );
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 65:
          {
            if (0 < handlers_0.len_0){
              NI32 X60Qx_791 = len_3_I4ido3x_vmtuaxp6(handlers_0);
              setLen_0_I80tc5k_vmtuaxp6((&handlers_0), ((NI32)(X60Qx_791 - 1)));}
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 66:
          {
            Value_0_valzr1t4f X60Qx_11;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_11));
            if (0 < stack_1.len_0){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_11));
              Value_0_valzr1t4f X60Qx_792 = popv_0_vmtuaxp6((&stack_1));
              X60Qx_11 = X60Qx_792;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_11));
              Value_0_valzr1t4f X60Qx_793 = vNil_0_valzr1t4f();
              X60Qx_11 = X60Qx_793;}
            Value_0_valzr1t4f* X60Qlhs_205 = (&(*vm_15).d_00.excVal_0);
            Value_0_valzr1t4f X60Qlhs_206 = X60Qx_11;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_11));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_205)));
            (*X60Qlhs_205) = X60Qlhs_206;
            (*vm_15).d_00.raised_0 = NIM_TRUE;
            unwinding_0 = 2;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_11));}
          break;
          case 67:
          {
            (*vm_15).d_00.raised_0 = NIM_TRUE;
            unwinding_0 = 2;}
          break;
          case 68:
          {
            if (0 < pendings_0.len_0){
              NI32 X60Qx_794 = len_3_I98fzqt_vmtuaxp6(pendings_0);
              Pending_0_vmtuaxp6* X60Qx_795 = getQ_7_Iqkk0ey1_vmtuaxp6(pendings_0, ((NI32)(X60Qx_794 - 1)));
              Pending_0_vmtuaxp6 X60QconstRefTemp_17 = (*X60Qx_795);
              Pending_0_vmtuaxp6 p_6 = eQdupQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&X60QconstRefTemp_17));
              NI32 X60Qx_796 = len_3_I98fzqt_vmtuaxp6(pendings_0);
              setLen_0_Iibupod1_vmtuaxp6((&pendings_0), ((NI32)(X60Qx_796 - 1)));
              if (p_6.kind_0 == 1){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
                retval_0 = p_6.val_0;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&p_6.val_0));
                unwinding_0 = 1;}
              else {
                (*vm_15).d_00.raised_0 = NIM_TRUE;
                unwinding_0 = 2;}
              eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&p_6));}
            else {
              inc_1_I6wjjge_aow2h993l1((&ip_0));}}
          break;
          case 69:
          {
            Value_0_valzr1t4f X60Qx_797 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*vm_15).d_00.excVal_0));
            add_0_Itre92n_comaa5xpt1((&stack_1), X60Qx_797);
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 70:
          {
            inc_1_I6wjjge_aow2h993l1((&finDischarge_0));
            inc_1_I6wjjge_aow2h993l1((&ip_0));}
          break;
          case 71:
          {
            if (0 < finDischarge_0){
              dec_1_I0nzoz91_ast8ri79k((&finDischarge_0));
              ip_0 = ins_0.a_0;}
            else {
              inc_1_I6wjjge_aow2h993l1((&ip_0));}}
          break;}}
      continueLabel_1: ;}}
  whileStmtLabel_0: ;
  if (0 < stack_1.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
    NI32 X60Qx_798 = len_3_I4n9kvq_comaa5xpt1(stack_1);
    Value_0_valzr1t4f* X60Qx_799 = getQ_7_Ine8yq71_natd5co251(stack_1, ((NI32)(X60Qx_798 - 1)));
    Value_0_valzr1t4f X60QconstRefTemp_18 = (*X60Qx_799);
    Value_0_valzr1t4f X60Qx_800 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_18));
    result_23 = X60Qx_800;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
    Value_0_valzr1t4f X60Qx_801 = vNil_0_valzr1t4f();
    result_23 = X60Qx_801;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
  eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
  eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
  eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
  return result_23;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&retval_0));
  eQdestroy_1_Iuu2ern1_vmtuaxp6(pendings_0);
  eQdestroy_1_I3wpak31_vmtuaxp6(handlers_0);
  eQdestroy_1_Inxd7ue1_chu5m1rja1(stack_1);
  return result_23;}
Value_0_valzr1t4f runProc_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_16, NI32 procIdx_1, seq_0_I50urnw_chu5m1rja1 args_4, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_7){
  Value_0_valzr1t4f result_24;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  Proc_0_chu5m1rja1* X60Qx_802 = getQ_7_I7rdp401_vmtuaxp6((*vm_16).d_00.prog_0.procs_0, procIdx_1);
  Proc_0_chu5m1rja1 X60QconstRefTemp_0 = (*X60Qx_802);
  Proc_0_chu5m1rja1 p_7 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&X60QconstRefTemp_0));
  seq_0_Iw8xl5b1_flaksyopx1 locals_3 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  NI32 i_40 = 0;
  {
    while (i_40 < p_7.numLocals_0){
      Value_0_valzr1t4f v_12 = vNil_0_valzr1t4f();
      NB8 X60Qx_803;
      if (i_40 < p_7.numParams_0){
        NI32 X60Qx_804 = len_3_I4n9kvq_comaa5xpt1(args_4);
        X60Qx_803 = (i_40 < X60Qx_804);}
      else {
        X60Qx_803 = NIM_FALSE;}
      if (X60Qx_803){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_12));
        Value_0_valzr1t4f* X60Qx_805 = getQ_7_Ine8yq71_natd5co251(args_4, i_40);
        Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_805);
        Value_0_valzr1t4f X60Qx_806 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_1));
        v_12 = X60Qx_806;}
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_807 = newCell_0_valzr1t4f((&v_12));
      add_0_Ijpw0mu_flaksyopx1((&locals_3), X60Qx_807);
      inc_1_I6wjjge_aow2h993l1((&i_40));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_12));}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  Value_0_valzr1t4f X60Qx_808 = execCode_1_vmtuaxp6(vm_16, p_7.code_0, p_7.lines_0, (&locals_3), NIM_NIL, env_7, p_7.slotSyms_0);
  result_24 = X60Qx_808;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_3);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_7));
  return result_24;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_3);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_7));
  return result_24;}
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* makeCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_17, NI32 pidx_2, seq_0_I50urnw_chu5m1rja1 args_5, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_8){
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* result_25;
  eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&result_25));
  Proc_0_chu5m1rja1* X60Qx_809 = getQ_7_I7rdp401_vmtuaxp6((*vm_17).d_00.prog_0.procs_0, pidx_2);
  Proc_0_chu5m1rja1 X60QconstRefTemp_0 = (*X60Qx_809);
  Proc_0_chu5m1rja1 p_8 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&X60QconstRefTemp_0));
  seq_0_Iw8xl5b1_flaksyopx1 locals_4 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  NI32 i_41 = 0;
  {
    while (i_41 < p_8.numLocals_0){
      Value_0_valzr1t4f v_13 = vNil_0_valzr1t4f();
      NB8 X60Qx_810;
      if (i_41 < p_8.numParams_0){
        NI32 X60Qx_811 = len_3_I4n9kvq_comaa5xpt1(args_5);
        X60Qx_810 = (i_41 < X60Qx_811);}
      else {
        X60Qx_810 = NIM_FALSE;}
      if (X60Qx_810){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_13));
        Value_0_valzr1t4f* X60Qx_812 = getQ_7_Ine8yq71_natd5co251(args_5, i_41);
        Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_812);
        Value_0_valzr1t4f X60Qx_813 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_1));
        v_13 = X60Qx_813;}
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_814 = newCell_0_valzr1t4f((&v_13));
      add_0_Ijpw0mu_flaksyopx1((&locals_4), X60Qx_814);
      inc_1_I6wjjge_aow2h993l1((&i_41));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_13));}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(result_25);
  void* X60Qx_815 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6));
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qtmp_207 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)X60Qx_815);
  seq_0_Izok7jt1_chu5m1rja1 X60Qtmp_208 = p_8.code_0;
  eQwasMoved_1_Ik2628i_chu5m1rja1((&p_8.code_0));
  seq_0_Ift2sne_chu5m1rja1 X60Qtmp_209 = p_8.lines_0;
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&p_8.lines_0));
  seq_0_Iw8xl5b1_flaksyopx1 X60Qtmp_210 = locals_4;
  eQwasMoved_1_I4kgdoh1_flaksyopx1((&locals_4));
  seq_0_In6doa_ast8ri79k X60Qtmp_211 = p_8.slotSyms_0;
  eQwasMoved_1_I2k4kel_ast8ri79k((&p_8.slotSyms_0));
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qx_41 = eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(env_8);
  seq_0_I50urnw_chu5m1rja1 X60Qx_42 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  seq_0_Ifq4s5b1_vmtuaxp6 X60Qx_43 = newSeqUninit_0_Ipt20ij1_vmtuaxp6(0);
  seq_0_I32zqoq1_vmtuaxp6 X60Qx_44 = newSeqUninit_0_Im62ogf1_vmtuaxp6(0);
  Value_0_valzr1t4f X60Qx_45 = vNil_0_valzr1t4f();
  (*X60Qtmp_207) = (X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6){
    .r_00 = 0, .d_00 = (VmCoro_Obj_0_vmtuaxp6){
      (&VmCoro_Obj_0_vt_vmtuaxp6), .code_0 = X60Qtmp_208, .lines_0 = X60Qtmp_209, .locals_0 = X60Qtmp_210, .myEnvCell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .destCell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .stepFn_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .itVal_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .slotSyms_0 = X60Qtmp_211, .env_0 = X60Qx_41, .stack_0 = X60Qx_42, .handlers_0 = X60Qx_43, .pendings_0 = X60Qx_44, .ip_0 = 0, .started_0 = NIM_FALSE, .done_0 = NIM_FALSE, .suspended_0 = NIM_FALSE, .lastVal_0 = X60Qx_45, .isPassive_0 = NIM_FALSE, .caller_0 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)NIM_NIL), .retCell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .retVal_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .awaitingPark_0 = NIM_FALSE, .parked_0 = NIM_FALSE, .finished_0 = NIM_FALSE, .retToCoro_0 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)NIM_NIL), .retToIdx_0 = ((NI32)0)}}
  ;
  result_25 = X60Qtmp_207;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_4);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_8));
  return result_25;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_4);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_8));
  return result_25;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 resumeCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_18, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* coro_3){
  X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 result_26;
  eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&result_26));
  NB8 X60Qx_816;
  if (coro_3 == NIM_NIL){
    X60Qx_816 = NIM_TRUE;}
  else {
    X60Qx_816 = (*coro_3).d_00.done_0;}
  if (X60Qx_816){
    Value_0_valzr1t4f X60Qx_817 = vNil_0_valzr1t4f();
    result_26 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = X60Qx_817, .fld_1 = NIM_TRUE}
    ;
    return result_26;}
  (*coro_3).d_00.suspended_0 = NIM_FALSE;
  seq_0_Iw8xl5b1_flaksyopx1 lc_0 = eQdup_1_Io30l171_flaksyopx1((*coro_3).d_00.locals_0);
  Value_0_valzr1t4f rv_9 = execCode_1_vmtuaxp6(vm_18, (*coro_3).d_00.code_0, (*coro_3).d_00.lines_0, (&lc_0), coro_3, (*coro_3).d_00.env_0, (*coro_3).d_00.slotSyms_0);
  NB8 X60Qx_818;
  NB8 X60Qx_819;
  if ((*coro_3).d_00.suspended_0){
    X60Qx_819 = (!(*(*vm_18).d_00.sink_0).d_00.didQQuit_0);}
  else {
    X60Qx_819 = NIM_FALSE;}
  if (X60Qx_819){
    X60Qx_818 = (!(*vm_18).d_00.raised_0);}
  else {
    X60Qx_818 = NIM_FALSE;}
  if (X60Qx_818){
    eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&result_26));
    Value_0_valzr1t4f X60Qtmp_212 = rv_9;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_9));
    result_26 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = X60Qtmp_212, .fld_1 = NIM_FALSE}
    ;}
  else {
    (*coro_3).d_00.done_0 = NIM_TRUE;
    eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6((&result_26));
    Value_0_valzr1t4f X60Qx_820 = vNil_0_valzr1t4f();
    result_26 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = X60Qx_820, .fld_1 = NIM_TRUE}
    ;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_9));
  eQdestroy_1_I8k3d0z1_flaksyopx1(lc_0);
  return result_26;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_9));
  eQdestroy_1_I8k3d0z1_flaksyopx1(lc_0);
  return result_26;}
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* makePassiveCoro_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_19, NI32 pidx_3, seq_0_I50urnw_chu5m1rja1 args_6, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_9){
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* result_27;
  eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&result_27));
  Proc_0_chu5m1rja1* X60Qx_821 = getQ_7_I7rdp401_vmtuaxp6((*vm_19).d_00.prog_0.procs_0, pidx_3);
  Proc_0_chu5m1rja1 X60QconstRefTemp_0 = (*X60Qx_821);
  Proc_0_chu5m1rja1 p_9 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&X60QconstRefTemp_0));
  seq_0_Iw8xl5b1_flaksyopx1 locals_5 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  NI32 i_42 = 0;
  {
    while (i_42 < p_9.numLocals_0){
      Value_0_valzr1t4f v_14 = vNil_0_valzr1t4f();
      NB8 X60Qx_822;
      if (i_42 < p_9.numParams_0){
        NI32 X60Qx_823 = len_3_I4n9kvq_comaa5xpt1(args_6);
        X60Qx_822 = (i_42 < X60Qx_823);}
      else {
        X60Qx_822 = NIM_FALSE;}
      if (X60Qx_822){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_14));
        Value_0_valzr1t4f* X60Qx_824 = getQ_7_Ine8yq71_natd5co251(args_6, i_42);
        Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_824);
        Value_0_valzr1t4f X60Qx_825 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_1));
        v_14 = X60Qx_825;}
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_826 = newCell_0_valzr1t4f((&v_14));
      add_0_Ijpw0mu_flaksyopx1((&locals_5), X60Qx_826);
      inc_1_I6wjjge_aow2h993l1((&i_42));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_14));}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(result_27);
  void* X60Qx_827 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6));
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qtmp_213 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)X60Qx_827);
  seq_0_Izok7jt1_chu5m1rja1 X60Qtmp_214 = p_9.code_0;
  eQwasMoved_1_Ik2628i_chu5m1rja1((&p_9.code_0));
  seq_0_Ift2sne_chu5m1rja1 X60Qtmp_215 = p_9.lines_0;
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&p_9.lines_0));
  seq_0_Iw8xl5b1_flaksyopx1 X60Qtmp_216 = locals_5;
  eQwasMoved_1_I4kgdoh1_flaksyopx1((&locals_5));
  seq_0_In6doa_ast8ri79k X60Qtmp_217 = p_9.slotSyms_0;
  eQwasMoved_1_I2k4kel_ast8ri79k((&p_9.slotSyms_0));
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* X60Qx_46 = eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(env_9);
  seq_0_I50urnw_chu5m1rja1 X60Qx_47 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  seq_0_Ifq4s5b1_vmtuaxp6 X60Qx_48 = newSeqUninit_0_Ipt20ij1_vmtuaxp6(0);
  seq_0_I32zqoq1_vmtuaxp6 X60Qx_49 = newSeqUninit_0_Im62ogf1_vmtuaxp6(0);
  Value_0_valzr1t4f X60Qx_50 = vNil_0_valzr1t4f();
  Value_0_valzr1t4f X60Qx_51 = vNil_0_valzr1t4f();
  (*X60Qtmp_213) = (X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6){
    .r_00 = 0, .d_00 = (VmCoro_Obj_0_vmtuaxp6){
      (&VmCoro_Obj_0_vt_vmtuaxp6), .code_0 = X60Qtmp_214, .lines_0 = X60Qtmp_215, .locals_0 = X60Qtmp_216, .myEnvCell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .destCell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .stepFn_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .itVal_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .slotSyms_0 = X60Qtmp_217, .env_0 = X60Qx_46, .stack_0 = X60Qx_47, .handlers_0 = X60Qx_48, .pendings_0 = X60Qx_49, .ip_0 = 0, .started_0 = NIM_FALSE, .done_0 = NIM_FALSE, .suspended_0 = NIM_FALSE, .lastVal_0 = X60Qx_50, .isPassive_0 = NIM_TRUE, .caller_0 = NIM_NIL, .retCell_0 = NIM_NIL, .retVal_0 = X60Qx_51, .awaitingPark_0 = NIM_FALSE, .parked_0 = NIM_FALSE, .finished_0 = NIM_FALSE, .retToCoro_0 = NIM_NIL, .retToIdx_0 = -1}}
  ;
  result_27 = X60Qtmp_213;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_5);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_9));
  return result_27;
  eQdestroy_1_I8k3d0z1_flaksyopx1(locals_5);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_9));
  return result_27;}
NI32 runActivationVm_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_20, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* co_1){
  NI32 result_28;
  NB8 X60Qx_828;
  if (co_1 == NIM_NIL){
    X60Qx_828 = NIM_TRUE;}
  else {
    X60Qx_828 = (*co_1).d_00.finished_0;}
  if (X60Qx_828){
    return 0;}
  (*vm_20).d_00.coroStep_0 = 0;
  (*co_1).d_00.parked_0 = NIM_FALSE;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* savedCoro_0 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*vm_20).d_00.curCoro_0);
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_218 = (&(*vm_20).d_00.curCoro_0);
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_219 = (*vm_20).d_00.curCoro_0;
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_829 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(co_1);
  (*X60Qlhs_218) = X60Qx_829;
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_219);
  seq_0_Iw8xl5b1_flaksyopx1 lc_1 = eQdup_1_Io30l171_flaksyopx1((*co_1).d_00.locals_0);
  Value_0_valzr1t4f rv_10 = execCode_1_vmtuaxp6(vm_20, (*co_1).d_00.code_0, (*co_1).d_00.lines_0, (&lc_1), co_1, (*co_1).d_00.env_0, (*co_1).d_00.slotSyms_0);
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_220 = (&(*vm_20).d_00.curCoro_0);
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_221 = savedCoro_0;
  eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&savedCoro_0));
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*X60Qlhs_220));
  (*X60Qlhs_220) = X60Qlhs_221;
  result_28 = (*vm_20).d_00.coroStep_0;
  if (result_28 == 0){
    (*co_1).d_00.finished_0 = NIM_TRUE;
    Value_0_valzr1t4f* X60Qlhs_222 = (&(*co_1).d_00.retVal_0);
    Value_0_valzr1t4f X60Qlhs_223 = rv_10;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_10));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_222)));
    (*X60Qlhs_222) = X60Qlhs_223;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_10));
  eQdestroy_1_I8k3d0z1_flaksyopx1(lc_1);
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(savedCoro_0);
  return result_28;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_10));
  eQdestroy_1_I8k3d0z1_flaksyopx1(lc_1);
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(savedCoro_0);
  return result_28;}
void drivePassiveVm_1_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_21, X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* start_1){
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* cur_2 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(start_1);
  {
    while ((!(cur_2 == NIM_NIL))){
      NB8 X60Qx_830;
      if ((*(*vm_21).d_00.sink_0).d_00.didQQuit_0){
        X60Qx_830 = NIM_TRUE;}
      else {
        X60Qx_830 = (*vm_21).d_00.raised_0;}
      if (X60Qx_830){
        eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(cur_2);
        return;}
      NI32 step_0 = runActivationVm_0_vmtuaxp6(vm_21, cur_2);
      switch (step_0){
        case 1:
        {
          eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(cur_2);
          return;}
        break;
        case 2:
        {
          eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(cur_2);
          X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_831 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*vm_21).d_00.pendingChild_0);
          cur_2 = X60Qx_831;
          X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** X60Qlhs_224 = (&(*vm_21).d_00.pendingChild_0);
          X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_225 = (*vm_21).d_00.pendingChild_0;
          (*X60Qlhs_224) = NIM_NIL;
          eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_225);}
        break;
        default:
        {
          if ((!((*cur_2).d_00.retCell_0 == NIM_NIL))){
            Value_0_valzr1t4f* X60Qlhs_226 = (&(*(*cur_2).d_00.retCell_0).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_227 = (*(*cur_2).d_00.retCell_0).d_00.v_0;
            Value_0_valzr1t4f X60Qx_832 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_2).d_00.retVal_0));
            (*X60Qlhs_226) = X60Qx_832;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_227));}
          NB8 X60Qx_833;
          NB8 X60Qx_834;
          if ((!((*cur_2).d_00.retToCoro_0 == NIM_NIL))){
            X60Qx_834 = (0 <= (*cur_2).d_00.retToIdx_0);}
          else {
            X60Qx_834 = NIM_FALSE;}
          if (X60Qx_834){
            NI32 X60Qx_835 = len_3_I4n9kvq_comaa5xpt1((*(*cur_2).d_00.retToCoro_0).d_00.stack_0);
            X60Qx_833 = ((*cur_2).d_00.retToIdx_0 < X60Qx_835);}
          else {
            X60Qx_833 = NIM_FALSE;}
          if (X60Qx_833){
            Value_0_valzr1t4f X60Qx_836 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_2).d_00.retVal_0));
            putQ_7_I4hmt511_runot4689((&(*(*cur_2).d_00.retToCoro_0).d_00.stack_0), (*cur_2).d_00.retToIdx_0, X60Qx_836);}
          X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qlhs_228 = cur_2;
          X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* X60Qx_837 = eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*cur_2).d_00.caller_0);
          cur_2 = X60Qx_837;
          eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qlhs_228);}
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(cur_2);}
void runProgram_0_vmtuaxp6(VmProgram_0_chu5m1rja1* prog_0, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* tr_0){
  void* X60Qx_838 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6));
  X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* X60Qtmp_229 = ((X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6*)X60Qx_838);
  VmProgram_0_chu5m1rja1 X60Qx_839 = eQdupQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&(*prog_0)));
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* X60Qx_840 = eQdupQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6(sink_1);
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_841 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_842 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_843 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  seq_0_Iflf8jf1_fiepkwzpc X60Qx_844 = newSeqUninit_0_I5mozxi1_fiepkwzpc(0);
  Value_0_valzr1t4f X60Qx_845 = vNil_0_valzr1t4f();
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* X60Qx_846 = eQdupQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6(tr_0);
  (*X60Qtmp_229) = (X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6){
    .r_00 = 0, .d_00 = (VM_Obj_0_vmtuaxp6){
      .prog_0 = X60Qx_839, .sink_0 = X60Qx_840, .globals_0 = X60Qx_841, .unboundImportc_0 = X60Qx_842, .unboundImportcNim_0 = X60Qx_843, .globalInited_0 = X60Qx_844, .raised_0 = NIM_FALSE, .excVal_0 = X60Qx_845, .trace_0 = X60Qx_846, .poolStoppedFlag_0 = NIM_FALSE, .keepOvf_0 = ((NI32)0), .overflowFlag_0 = NIM_FALSE, .curCoro_0 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)NIM_NIL), .pendingChild_0 = ((X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6*)NIM_NIL), .coroStep_0 = ((NI32)0), .scheduler_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}}}
  ;
  X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* vm_22 = X60Qtmp_229;
  NI32 i_43 = 0;
  {
    while (i_43 < (*prog_0).numGlobals_0){
      Value_0_valzr1t4f X60Qtmp_230 = vNil_0_valzr1t4f();
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_847 = newCell_0_valzr1t4f((&X60Qtmp_230));
      add_0_Ijpw0mu_flaksyopx1((&(*vm_22).d_00.globals_0), X60Qx_847);
      add_0_Irnc3p1_fiepkwzpc((&(*vm_22).d_00.globalInited_0), NIM_FALSE);
      inc_1_I6wjjge_aow2h993l1((&i_43));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_230));}}
  whileStmtLabel_0: ;
  NI32 gs_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_848 = len_3_Iuz7erf_comaa5xpt1((*prog_0).globalSeeds_0);
      if (gs_0 < X60Qx_848){
        GlobalSeed_0_chu5m1rja1* X60Qx_849 = getQ_7_Ijx02qt_comaa5xpt1((*prog_0).globalSeeds_0, gs_0);
        GlobalSeed_0_chu5m1rja1 X60QconstRefTemp_0 = (*X60Qx_849);
        GlobalSeed_0_chu5m1rja1 sd_1 = eQdupQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1((&X60QconstRefTemp_0));
        NB8 X60Qx_850;
        if (0 <= sd_1.slot_0){
          NI32 X60Qx_851 = len_3_I83dzei_flaksyopx1((*vm_22).d_00.globals_0);
          X60Qx_850 = (sd_1.slot_0 < X60Qx_851);}
        else {
          X60Qx_850 = NIM_FALSE;}
        if (X60Qx_850){
          NB8 seedFound_0 = NIM_FALSE;
          Value_0_valzr1t4f sv_1 = importcGlobalSeed_0_runot4689(sink_1, sd_1.cname_0, sd_1.name_0, (&seedFound_0), NIM_TRUE);
          Value_0_valzr1t4f X60Qx_12;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_12));
          if (seedFound_0){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_12));
            X60Qx_12 = sv_1;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&sv_1));}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_12));
            X60Qx_12 = sd_1.v_0;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&sd_1.v_0));}
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_852 = getQ_7_Ii14ync1_flaksyopx1((*vm_22).d_00.globals_0, sd_1.slot_0);
          Value_0_valzr1t4f* X60Qlhs_231 = (&(*(*X60Qx_852)).d_00.v_0);
          Value_0_valzr1t4f X60Qlhs_232 = X60Qx_12;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_12));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_231)));
          (*X60Qlhs_231) = X60Qlhs_232;
          NB8 X60Qx_853;
          NB8 X60Qx_854;
          if ((!seedFound_0)){
            NI32 X60Qx_855 = len_4_sysvq0asl(sd_1.cname_0);
            X60Qx_854 = (0 < X60Qx_855);}
          else {
            X60Qx_854 = NIM_FALSE;}
          if (X60Qx_854){
            NB8 X60Qx_856 = isAllowedUnboundImportc_0_runot4689(sd_1.cname_0);
            X60Qx_853 = (!X60Qx_856);}
          else {
            X60Qx_853 = NIM_FALSE;}
          if (X60Qx_853){
            {
              while (NIM_TRUE){
                NI32 X60Qx_857 = len_3_Ixq6taz_comaa5xpt1((*vm_22).d_00.unboundImportc_0);
                if (X60Qx_857 <= sd_1.slot_0){
                  add_0_Ig6072n_ast8ri79k((&(*vm_22).d_00.unboundImportc_0), (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            string_0_sysvq0asl X60Qtmp_233 = sd_1.cname_0;
            nimStrWasMoved((&sd_1.cname_0));
            putQ_7_Ild9iim_croph25r5((&(*vm_22).d_00.unboundImportc_0), sd_1.slot_0, X60Qtmp_233);
            {
              while (NIM_TRUE){
                NI32 X60Qx_858 = len_3_Ixq6taz_comaa5xpt1((*vm_22).d_00.unboundImportcNim_0);
                if (X60Qx_858 <= sd_1.slot_0){
                  add_0_Ig6072n_ast8ri79k((&(*vm_22).d_00.unboundImportcNim_0), (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );}
                else {
                  break;}}}
            whileStmtLabel_3: ;
            string_0_sysvq0asl X60Qx_859 = nimStrDup(sd_1.name_0);
            putQ_7_Ild9iim_croph25r5((&(*vm_22).d_00.unboundImportcNim_0), sd_1.slot_0, X60Qx_859);}
          NB8 X60Qx_860 = eqQ_20_sysvq0asl(sd_1.name_0, (string_0_sysvq0asl){
            .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I13880079574436425354_runot4689)}
          );
          if (X60Qx_860){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_861 = getQ_7_Ii14ync1_flaksyopx1((*vm_22).d_00.globals_0, sd_1.slot_0);
            registerErrnoCell_0_runot4689((*X60Qx_861));}
          else {
            NB8 X60Qx_862 = eqQ_20_sysvq0asl(sd_1.name_0, (string_0_sysvq0asl){
              .bytes_0 = 1986946558u, .more_0 = (&strlit_0_I274569611119625799_runot4689)}
            );
            if (X60Qx_862){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_863 = getQ_7_Ii14ync1_flaksyopx1((*vm_22).d_00.globals_0, sd_1.slot_0);
              registerEnvironmentCell_0_runot4689((*X60Qx_863));}}
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_12));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&sv_1));}
        inc_1_I6wjjge_aow2h993l1((&gs_0));
        eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1((&sd_1));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  NI32 k_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_864 = len_3_I05nxx61_comaa5xpt1((*prog_0).inits_0);
      if (k_6 < X60Qx_864){
        Proc_0_chu5m1rja1* X60Qx_865 = getQ_7_I7rdp401_vmtuaxp6((*prog_0).inits_0, k_6);
        Proc_0_chu5m1rja1 X60QconstRefTemp_1 = (*X60Qx_865);
        Proc_0_chu5m1rja1 ini_0 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&X60QconstRefTemp_1));
        NI32 savedOut_0 = len_4_sysvq0asl((*(*vm_22).d_00.sink_0).d_00.outBuf_0);
        NI32 savedErr_0 = len_4_sysvq0asl((*(*vm_22).d_00.sink_0).d_00.errBuf_0);
        seq_0_Iw8xl5b1_flaksyopx1 iniLocals_0 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
        NI32 m_1 = 0;
        {
          while (m_1 < ini_0.numLocals_0){
            Value_0_valzr1t4f X60Qtmp_234 = vNil_0_valzr1t4f();
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_866 = newCell_0_valzr1t4f((&X60Qtmp_234));
            add_0_Ijpw0mu_flaksyopx1((&iniLocals_0), X60Qx_866);
            inc_1_I6wjjge_aow2h993l1((&m_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_234));}}
        whileStmtLabel_5: ;
        Value_0_valzr1t4f X60Qtmp_235 = execCode_1_vmtuaxp6(vm_22, ini_0.code_0, ini_0.lines_0, (&iniLocals_0), NIM_NIL, NIM_NIL, ini_0.slotSyms_0);
        Value_0_valzr1t4f X60Qx_867 = X60Qtmp_235;
        NB8 X60Qx_868;
        if ((*vm_22).d_00.raised_0){
          X60Qx_868 = NIM_TRUE;}
        else {
          X60Qx_868 = (*(*vm_22).d_00.sink_0).d_00.didQQuit_0;}
        if (X60Qx_868){
          inc_1_I6wjjge_aow2h993l1((&initAmnestyCount_0_vmtuaxp6));
          if (loudInitAmnesty_0_vmtuaxp6){
            string_0_sysvq0asl X60Qdesugar_35 = dollarQ_2_sysvq0asl(k_6);
            string_0_sysvq0asl X60Qx_13;
            nimStrWasMoved((&X60Qx_13));
            if ((*(*vm_22).d_00.sink_0).d_00.didQQuit_0){
              nimStrDestroy(X60Qx_13);
              X60Qx_13 = (string_0_sysvq0asl){
                .bytes_0 = 1769304574u, .more_0 = (&strlit_0_I16529604172406501048_runot4689)}
              ;}
            else {
              nimStrDestroy(X60Qx_13);
              X60Qx_13 = (string_0_sysvq0asl){
                .bytes_0 = 1767994110u, .more_0 = (&strlit_0_I6336233549165567821_vmtuaxp6)}
              ;}
            string_0_sysvq0asl X60Qdesugar_36 = X60Qx_13;
            nimStrWasMoved((&X60Qx_13));
            NI32 X60Qx_869 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I6204575006793878320_vmtuaxp6)}
            );
            NI32 X60Qx_870 = len_4_sysvq0asl(X60Qdesugar_35);
            NI32 X60Qx_871 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_872 = len_4_sysvq0asl(X60Qdesugar_36);
            NI32 X60Qx_873 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1864379646u, .more_0 = (&strlit_0_I98869477994407991_vmtuaxp6)}
            );
            string_0_sysvq0asl X60Qdesugar_37 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_869 + X60Qx_870)) + X60Qx_871)) + X60Qx_872)) + X60Qx_873)));
            add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
              .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I6204575006793878320_vmtuaxp6)}
            );
            add_2_sysvq0asl((&X60Qdesugar_37), X60Qdesugar_35);
            add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_37), X60Qdesugar_36);
            add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
              .bytes_0 = 1864379646u, .more_0 = (&strlit_0_I98869477994407991_vmtuaxp6)}
            );
            write_0_syn1lfpjv(stderr, X60Qdesugar_37);
            nimStrDestroy(X60Qdesugar_37);
            nimStrDestroy(X60Qdesugar_36);
            nimStrDestroy(X60Qx_13);
            nimStrDestroy(X60Qdesugar_35);}
          NI32 X60Qx_874 = len_4_sysvq0asl((*(*vm_22).d_00.sink_0).d_00.outBuf_0);
          if (savedOut_0 < X60Qx_874){
            setLen_1_sysvq0asl((&(*(*vm_22).d_00.sink_0).d_00.outBuf_0), savedOut_0);}
          NI32 X60Qx_875 = len_4_sysvq0asl((*(*vm_22).d_00.sink_0).d_00.errBuf_0);
          if (savedErr_0 < X60Qx_875){
            setLen_1_sysvq0asl((&(*(*vm_22).d_00.sink_0).d_00.errBuf_0), savedErr_0);}
          (*(*vm_22).d_00.sink_0).d_00.didQQuit_0 = NIM_FALSE;
          (*(*vm_22).d_00.sink_0).d_00.exitCode_0 = 0;
          (*vm_22).d_00.raised_0 = NIM_FALSE;
          Value_0_valzr1t4f* X60Qlhs_236 = (&(*vm_22).d_00.excVal_0);
          Value_0_valzr1t4f X60Qlhs_237 = vNil_0_valzr1t4f();
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_236)));
          (*X60Qlhs_236) = X60Qlhs_237;}
        inc_1_I6wjjge_aow2h993l1((&k_6));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_235));
        eQdestroy_1_I8k3d0z1_flaksyopx1(iniLocals_0);
        eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&ini_0));}
      else {
        break;}}}
  whileStmtLabel_4: ;
  seq_0_Iw8xl5b1_flaksyopx1 topLocals_0 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  NI32 j_3 = 0;
  {
    while (j_3 < (*prog_0).top_0.numLocals_0){
      Value_0_valzr1t4f X60Qtmp_238 = vNil_0_valzr1t4f();
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_876 = newCell_0_valzr1t4f((&X60Qtmp_238));
      add_0_Ijpw0mu_flaksyopx1((&topLocals_0), X60Qx_876);
      inc_1_I6wjjge_aow2h993l1((&j_3));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_238));}}
  whileStmtLabel_6: ;
  if ((!(*vm_22).d_00.raised_0)){
    Value_0_valzr1t4f X60Qtmp_239 = execCode_1_vmtuaxp6(vm_22, (*prog_0).top_0.code_0, (*prog_0).top_0.lines_0, (&topLocals_0), NIM_NIL, NIM_NIL, (*prog_0).top_0.slotSyms_0);
    Value_0_valzr1t4f X60Qx_877 = X60Qtmp_239;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_239));}
  NB8 X60Qx_878;
  if ((*vm_22).d_00.raised_0){
    X60Qx_878 = (!(*(*vm_22).d_00.sink_0).d_00.didQQuit_0);}
  else {
    X60Qx_878 = NIM_FALSE;}
  if (X60Qx_878){
    string_0_sysvq0asl X60Qdesugar_38 = renderValueReadable_0_valzr1t4f((&(*vm_22).d_00.excVal_0), ((NI32)1400));
    NI32 X60Qx_879 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I14207650632107132323_vmtuaxp6)}
    );
    NI32 X60Qx_880 = len_4_sysvq0asl(X60Qdesugar_38);
    NI32 X60Qx_881 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_39 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_879 + X60Qx_880)) + X60Qx_881)));
    add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I14207650632107132323_vmtuaxp6)}
    );
    add_2_sysvq0asl((&X60Qdesugar_39), X60Qdesugar_38);
    add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&(*(*vm_22).d_00.sink_0).d_00.errBuf_0), X60Qdesugar_39);
    doQQuit_0_natd5co251((*vm_22).d_00.sink_0, 1);
    nimStrDestroy(X60Qdesugar_39);
    nimStrDestroy(X60Qdesugar_38);}
  eQdestroy_1_I8k3d0z1_flaksyopx1(topLocals_0);
  eQdestroyQ_ArefSX56X4dX4fbj0vmtuaxp6_0_vmtuaxp6(vm_22);}
void setLen_0_I8wiqgg_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_66, NI32 newLen_3){
  if (newLen_3 < (*s_66).len_0){
    shrink_0_Iphcl5v1_vmtuaxp6(s_66, newLen_3);}
  else {
    NI32 i_49 = (*s_66).len_0;
    growUnsafe_0_Ifrz0b21_vmtuaxp6(s_66, newLen_3);
    if ((*s_66).data_0 == NIM_NIL){
      return;}
    {
      while (i_49 < newLen_3){
        (*s_66).data_0[i_49] = (Value_0_valzr1t4f){
          .kind_0 = 0}
        ;
        inc_1_I6wjjge_aow2h993l1((&i_49));}}
    whileStmtLabel_0: ;}}
seq_0_In6doa_ast8ri79k atQ_0_Il22x2g_vmtuaxp6(X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S2_vmtuaxp6 a_12){
  seq_0_In6doa_ast8ri79k result_39;
  seq_0_In6doa_ast8ri79k X60Qx_908 = newSeqUninit_0_Ieodq4s1_ast8ri79k(((NI32)(((NI32)(((NI32)((NI32)1)) - ((NI32)((NI32)0)))) + 1)));
  result_39 = X60Qx_908;
  if ((!(result_39.data_0 == NIM_NIL))){
    NI32 i_52 = 0;
    {
      while (i_52 < result_39.len_0){
        NI32 X60Qx_909 = nimIcheckB(i_52, 1);
        result_39.data_0[i_52] = a_12.a[X60Qx_909];
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;}
  return result_39;}
seq_0_Iw8xl5b1_flaksyopx1 atQ_0_Ikzen43_vmtuaxp6(X60Qt_0_IAarrayArefSX43ellX4fbj0valzr1t4fZS2_vmtuaxp6 a_13){
  seq_0_Iw8xl5b1_flaksyopx1 result_40;
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_910 = newSeqUninit_0_I1tbjnk1_flaksyopx1(((NI32)(((NI32)(((NI32)((NI32)1)) - ((NI32)((NI32)0)))) + 1)));
  result_40 = X60Qx_910;
  if ((!(result_40.data_0 == NIM_NIL))){
    NI32 i_53 = 0;
    {
      while (i_53 < result_40.len_0){
        NI32 X60Qx_911 = nimIcheckB(i_53, 1);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_912 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(a_13.a[X60Qx_911]);
        result_40.data_0[i_53] = X60Qx_912;
        inc_1_I6wjjge_aow2h993l1((&i_53));}}
    whileStmtLabel_0: ;}
  return result_40;}
seq_0_I50urnw_chu5m1rja1 atQ_0_I4e31uy1_vmtuaxp6(X60Qt_0_IAarraySX56alue0valzr1t4fS1_vmtuaxp6* a_14){
  seq_0_I50urnw_chu5m1rja1 result_41;
  seq_0_I50urnw_chu5m1rja1 X60Qx_913 = newSeqUninit_0_I8oufjc_chu5m1rja1(((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1)));
  result_41 = X60Qx_913;
  if ((!(result_41.data_0 == NIM_NIL))){
    NI32 i_54 = 0;
    {
      while (i_54 < result_41.len_0){
        NI32 X60Qx_914 = nimIcheckB(i_54, 0);
        Value_0_valzr1t4f X60Qx_915 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*a_14).a[X60Qx_914]));
        result_41.data_0[i_54] = X60Qx_915;
        inc_1_I6wjjge_aow2h993l1((&i_54));}}
    whileStmtLabel_0: ;}
  return result_41;}
static inline NI32 len_3_Ikc9pid1_vmtuaxp6(seq_0_Idl3iy1_comaa5xpt1 s_80){
  NI32 result_44;
  result_44 = s_80.len_0;
  return result_44;}
static inline MethodIndexEntry_0_sempjk6bn1* getQ_7_I7nrp45_vmtuaxp6(seq_0_Idl3iy1_comaa5xpt1 s_81, NI32 i_56){
  NB8 X60Qx_918;
  if (i_56 < s_81.len_0){
    X60Qx_918 = (0 <= i_56);}
  else {
    X60Qx_918 = NIM_FALSE;}
  if ((!X60Qx_918)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  MethodIndexEntry_0_sempjk6bn1* result_45;
  result_45 = (&s_81.data_0[i_56]);
  return result_45;}
static inline seq_0_Ifq4s5b1_vmtuaxp6 newSeqUninit_0_Ipt20ij1_vmtuaxp6(NI32 size_13){
  seq_0_Ifq4s5b1_vmtuaxp6 result_49;
  if (size_13 == 0){
    result_49 = (seq_0_Ifq4s5b1_vmtuaxp6){
      .len_0 = size_13, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_I52ofsr1_vmtuaxp6(size_13);
    void* X60Qx_924 = alloc_1_sysvq0asl(memSize_3);
    result_49 = (seq_0_Ifq4s5b1_vmtuaxp6){
      .len_0 = size_13, .data_0 = ((Handler_0_vmtuaxp6*)X60Qx_924)}
    ;
    if ((!(result_49.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_925 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_49.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_49;}
static inline seq_0_I32zqoq1_vmtuaxp6 newSeqUninit_0_Im62ogf1_vmtuaxp6(NI32 size_15){
  seq_0_I32zqoq1_vmtuaxp6 result_50;
  if (size_15 == 0){
    result_50 = (seq_0_I32zqoq1_vmtuaxp6){
      .len_0 = size_15, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_I4b0tmb1_vmtuaxp6(size_15);
    void* X60Qx_926 = alloc_1_sysvq0asl(memSize_4);
    result_50 = (seq_0_I32zqoq1_vmtuaxp6){
      .len_0 = size_15, .data_0 = ((Pending_0_vmtuaxp6*)X60Qx_926)}
    ;
    if ((!(result_50.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_927 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_50.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_50;}
static inline NI32 len_3_I4ido3x_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_86){
  NI32 result_51;
  result_51 = s_86.len_0;
  return result_51;}
static inline Handler_0_vmtuaxp6* getQ_7_I4z6e5u1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_87, NI32 i_58){
  NB8 X60Qx_928;
  if (i_58 < s_87.len_0){
    X60Qx_928 = (0 <= i_58);}
  else {
    X60Qx_928 = NIM_FALSE;}
  if ((!X60Qx_928)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Handler_0_vmtuaxp6* result_52;
  result_52 = (&s_87.data_0[i_58]);
  return result_52;}
void setLen_0_I80tc5k_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_88, NI32 newLen_7){
  if (newLen_7 < (*s_88).len_0){
    shrink_0_Iwq7tiu_vmtuaxp6(s_88, newLen_7);}
  else {
    NI32 i_59 = (*s_88).len_0;
    growUnsafe_0_Ias0bor1_vmtuaxp6(s_88, newLen_7);
    if ((*s_88).data_0 == NIM_NIL){
      return;}
    {
      while (i_59 < newLen_7){
        (*s_88).data_0[i_59] = (Handler_0_vmtuaxp6){
          .catchIp_0 = ((NI32)0), .finallyIp_0 = ((NI32)0), .sp_0 = ((NI32)0)}
        ;
        inc_1_I6wjjge_aow2h993l1((&i_59));}}
    whileStmtLabel_0: ;}}
static inline void add_0_Igw9l8t1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_91, Pending_0_vmtuaxp6 elem_15){
  NI32 L_3 = (*s_91).len_0;
  NI32 X60Qx_929 = capInBytes_0_Ic38p5c1_vmtuaxp6((*s_91));
  if (X60Qx_929 < ((NI32)(((NI32)(L_3 * sizeof(Pending_0_vmtuaxp6))) + sizeof(Pending_0_vmtuaxp6)))){
    NB8 X60Qx_930 = resize_0_I31y2kd1_vmtuaxp6(s_91, 1);
    if ((!X60Qx_930)){
      eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&elem_15));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_91).len_0));
  (*s_91).data_0[L_3] = elem_15;}
static inline MagicSpec_0_chu5m1rja1* getQ_7_Io8qdfc_vmtuaxp6(seq_0_Ie9rikd_chu5m1rja1 s_102, NI32 i_66){
  NB8 X60Qx_937;
  if (i_66 < s_102.len_0){
    X60Qx_937 = (0 <= i_66);}
  else {
    X60Qx_937 = NIM_FALSE;}
  if ((!X60Qx_937)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  MagicSpec_0_chu5m1rja1* result_60;
  result_60 = (&s_102.data_0[i_66]);
  return result_60;}
static inline ConvSpec_0_chu5m1rja1* getQ_7_Ij8ai9r_vmtuaxp6(seq_0_Iknt7a3_chu5m1rja1 s_103, NI32 i_67){
  NB8 X60Qx_938;
  if (i_67 < s_103.len_0){
    X60Qx_938 = (0 <= i_67);}
  else {
    X60Qx_938 = NIM_FALSE;}
  if ((!X60Qx_938)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  ConvSpec_0_chu5m1rja1* result_61;
  result_61 = (&s_103.data_0[i_67]);
  return result_61;}
static inline Proc_0_chu5m1rja1* getQ_7_I7rdp401_vmtuaxp6(seq_0_Inaua171_chu5m1rja1 s_104, NI32 i_68){
  NB8 X60Qx_939;
  if (i_68 < s_104.len_0){
    X60Qx_939 = (0 <= i_68);}
  else {
    X60Qx_939 = NIM_FALSE;}
  if ((!X60Qx_939)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Proc_0_chu5m1rja1* result_62;
  result_62 = (&s_104.data_0[i_68]);
  return result_62;}
static inline MethodSite_0_chu5m1rja1* getQ_7_Ig0gjeo1_vmtuaxp6(seq_0_Ir067xu1_chu5m1rja1 s_105, NI32 i_69){
  NB8 X60Qx_940;
  if (i_69 < s_105.len_0){
    X60Qx_940 = (0 <= i_69);}
  else {
    X60Qx_940 = NIM_FALSE;}
  if ((!X60Qx_940)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  MethodSite_0_chu5m1rja1* result_63;
  result_63 = (&s_105.data_0[i_69]);
  return result_63;}
static inline GatedCall_0_chu5m1rja1* getQ_7_Ij0vr9r_vmtuaxp6(seq_0_Id5h4uf_chu5m1rja1 s_106, NI32 i_70){
  NB8 X60Qx_941;
  if (i_70 < s_106.len_0){
    X60Qx_941 = (0 <= i_70);}
  else {
    X60Qx_941 = NIM_FALSE;}
  if ((!X60Qx_941)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  GatedCall_0_chu5m1rja1* result_64;
  result_64 = (&s_106.data_0[i_70]);
  return result_64;}
static inline ObjInfo_0_chu5m1rja1* getQ_7_Ia248tr_vmtuaxp6(seq_0_I2neof81_chu5m1rja1 s_108, NI32 i_72){
  NB8 X60Qx_943;
  if (i_72 < s_108.len_0){
    X60Qx_943 = (0 <= i_72);}
  else {
    X60Qx_943 = NIM_FALSE;}
  if ((!X60Qx_943)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  ObjInfo_0_chu5m1rja1* result_65;
  result_65 = (&s_108.data_0[i_72]);
  return result_65;}
static inline void inc_1_Irn1g7r1_vmtuaxp6(NI64* x_11){
  (*x_11) = ((NI64)((*x_11) + ((NI64)1)));}
static inline ObjSpec_0_chu5m1rja1* getQ_7_I7ms12l_vmtuaxp6(seq_0_Isww99s_chu5m1rja1 s_109, NI32 i_73){
  NB8 X60Qx_944;
  if (i_73 < s_109.len_0){
    X60Qx_944 = (0 <= i_73);}
  else {
    X60Qx_944 = NIM_FALSE;}
  if ((!X60Qx_944)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  ObjSpec_0_chu5m1rja1* result_66;
  result_66 = (&s_109.data_0[i_73]);
  return result_66;}
static inline void add_0_Iwiwppi1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_110, Handler_0_vmtuaxp6 elem_19){
  NI32 L_4 = (*s_110).len_0;
  NI32 X60Qx_945 = capInBytes_0_Imq3jn61_vmtuaxp6((*s_110));
  if (X60Qx_945 < ((NI32)(((NI32)(L_4 * sizeof(Handler_0_vmtuaxp6))) + sizeof(Handler_0_vmtuaxp6)))){
    NB8 X60Qx_946 = resize_0_Iu85c9p_vmtuaxp6(s_110, 1);
    if ((!X60Qx_946)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_110).len_0));
  (*s_110).data_0[L_4] = elem_19;}
static inline NI32 len_3_I98fzqt_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_112){
  NI32 result_67;
  result_67 = s_112.len_0;
  return result_67;}
static inline Pending_0_vmtuaxp6* getQ_7_Iqkk0ey1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_113, NI32 i_74){
  NB8 X60Qx_947;
  if (i_74 < s_113.len_0){
    X60Qx_947 = (0 <= i_74);}
  else {
    X60Qx_947 = NIM_FALSE;}
  if ((!X60Qx_947)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Pending_0_vmtuaxp6* result_68;
  result_68 = (&s_113.data_0[i_74]);
  return result_68;}
void setLen_0_Iibupod1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_114, NI32 newLen_10){
  if (newLen_10 < (*s_114).len_0){
    shrink_0_Iq4ka8y_vmtuaxp6(s_114, newLen_10);}
  else {
    NI32 i_75 = (*s_114).len_0;
    growUnsafe_0_Iz3767g_vmtuaxp6(s_114, newLen_10);
    if ((*s_114).data_0 == NIM_NIL){
      return;}
    {
      while (i_75 < newLen_10){
        (*s_114).data_0[i_75] = (Pending_0_vmtuaxp6){
          .kind_0 = ((NI32)0), .val_0 = (Value_0_valzr1t4f){
            .kind_0 = 0}}
        ;
        inc_1_I6wjjge_aow2h993l1((&i_75));}}
    whileStmtLabel_0: ;}}
void shrink_0_Iphcl5v1_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_125, NI32 newLen_13){
  NI32 i_78 = ((NI32)((*s_125).len_0 - 1));
  {
    while (newLen_13 <= i_78){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*s_125).data_0[i_78]));
      dec_1_I0nzoz91_ast8ri79k((&i_78));}}
  whileStmtLabel_0: ;
  (*s_125).len_0 = newLen_13;}
void growUnsafe_0_Ifrz0b21_vmtuaxp6(seq_0_I50urnw_chu5m1rja1* s_126, NI32 newLen_14){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_14, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_958 = capInBytes_0_Ihvsegh1_chu5m1rja1((*s_126));
  if (X60Qx_958 < newSize_0){
    NB8 X60Qx_959 = resize_0_Iz8tg361_comaa5xpt1(s_126, ((NI32)(newLen_14 - (*s_126).len_0)));
    if ((!X60Qx_959)){
      return;}}
  (*s_126).len_0 = newLen_14;}
static inline NI32 memSizeInBytes_0_I52ofsr1_vmtuaxp6(NI32 size_24){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_88;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_24, sizeof(Handler_0_vmtuaxp6), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_88 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_88 = ((NI32)2147483647);}
  return result_88;}
static inline NI32 memSizeInBytes_0_I4b0tmb1_vmtuaxp6(NI32 size_25){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_89;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_25, sizeof(Pending_0_vmtuaxp6), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_89 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_89 = ((NI32)2147483647);}
  return result_89;}
void shrink_0_Iwq7tiu_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_138, NI32 newLen_19){
  NI32 i_83 = ((NI32)((*s_138).len_0 - 1));
  {
    while (newLen_19 <= i_83){
      dec_1_I0nzoz91_ast8ri79k((&i_83));}}
  whileStmtLabel_0: ;
  (*s_138).len_0 = newLen_19;}
void growUnsafe_0_Ias0bor1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_139, NI32 newLen_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_20, sizeof(Handler_0_vmtuaxp6), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_1 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_980 = capInBytes_0_Imq3jn61_vmtuaxp6((*s_139));
  if (X60Qx_980 < newSize_1){
    NB8 X60Qx_981 = resize_0_Iu85c9p_vmtuaxp6(s_139, ((NI32)(newLen_20 - (*s_139).len_0)));
    if ((!X60Qx_981)){
      return;}}
  (*s_139).len_0 = newLen_20;}
static inline NI32 capInBytes_0_Ic38p5c1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_140){
  NI32 result_90;
  NI32 X60Qx_17;
  if ((!(s_140.data_0 == NIM_NIL))){
    NI32 X60Qx_982 = allocatedSize_0_sysvq0asl(((void*)((void*)s_140.data_0)));
    X60Qx_17 = X60Qx_982;}
  else {
    X60Qx_17 = 0;}
  result_90 = X60Qx_17;
  return result_90;}
NB8 resize_0_I31y2kd1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* dest_10, NI32 addedElements_10){
  NB8 result_91;
  NI32 X60Qx_983 = capInBytes_0_Ic38p5c1_vmtuaxp6((*dest_10));
  NI32 oldCap_3 = ((NI32)(X60Qx_983 / sizeof(Pending_0_vmtuaxp6)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_10);
  NI32 memSize_10 = memSizeInBytes_0_I4b0tmb1_vmtuaxp6(newCap_3);
  void* X60Qx_984 = realloc_1_sysvq0asl(((void*)((void*)(*dest_10).data_0)), memSize_10);
  (*dest_10).data_0 = ((Pending_0_vmtuaxp6*)X60Qx_984);
  if ((*dest_10).data_0 == NIM_NIL){
    (*dest_10).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_91 = NIM_FALSE;}
  else {
    result_91 = NIM_TRUE;}
  return result_91;}
static inline NI32 capInBytes_0_Imq3jn61_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_141){
  NI32 result_92;
  NI32 X60Qx_18;
  if ((!(s_141.data_0 == NIM_NIL))){
    NI32 X60Qx_985 = allocatedSize_0_sysvq0asl(((void*)((void*)s_141.data_0)));
    X60Qx_18 = X60Qx_985;}
  else {
    X60Qx_18 = 0;}
  result_92 = X60Qx_18;
  return result_92;}
NB8 resize_0_Iu85c9p_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* dest_11, NI32 addedElements_11){
  NB8 result_93;
  NI32 X60Qx_986 = capInBytes_0_Imq3jn61_vmtuaxp6((*dest_11));
  NI32 oldCap_4 = ((NI32)(X60Qx_986 / sizeof(Handler_0_vmtuaxp6)));
  NI32 newCap_4 = recalcCap_0_sysvq0asl(oldCap_4, addedElements_11);
  NI32 memSize_11 = memSizeInBytes_0_I52ofsr1_vmtuaxp6(newCap_4);
  void* X60Qx_987 = realloc_1_sysvq0asl(((void*)((void*)(*dest_11).data_0)), memSize_11);
  (*dest_11).data_0 = ((Handler_0_vmtuaxp6*)X60Qx_987);
  if ((*dest_11).data_0 == NIM_NIL){
    (*dest_11).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_11);
    result_93 = NIM_FALSE;}
  else {
    result_93 = NIM_TRUE;}
  return result_93;}
void shrink_0_Iq4ka8y_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_142, NI32 newLen_21){
  NI32 i_84 = ((NI32)((*s_142).len_0 - 1));
  {
    while (newLen_21 <= i_84){
      eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&(*s_142).data_0[i_84]));
      dec_1_I0nzoz91_ast8ri79k((&i_84));}}
  whileStmtLabel_0: ;
  (*s_142).len_0 = newLen_21;}
void growUnsafe_0_Iz3767g_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_143, NI32 newLen_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_22, sizeof(Pending_0_vmtuaxp6), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_2 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_988 = capInBytes_0_Ic38p5c1_vmtuaxp6((*s_143));
  if (X60Qx_988 < newSize_2){
    NB8 X60Qx_989 = resize_0_I31y2kd1_vmtuaxp6(s_143, ((NI32)(newLen_22 - (*s_143).len_0)));
    if ((!X60Qx_989)){
      return;}}
  (*s_143).len_0 = newLen_22;}
void eQdestroy_1_I3wpak31_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 s_205){
  if ((!(s_205.data_0 == NIM_NIL))){
    NI32 i_116 = 0;
    {
      while (i_116 < s_205.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_116));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_205.data_0)));}}
static inline void eQwasMoved_1_Itejfoj_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6* s_206){
  (*s_206).len_0 = 0;
  (*s_206).data_0 = NIM_NIL;}
seq_0_Ifq4s5b1_vmtuaxp6 eQdup_1_Iqqsrms1_vmtuaxp6(seq_0_Ifq4s5b1_vmtuaxp6 a_47){
  seq_0_Ifq4s5b1_vmtuaxp6 result_109;
  seq_0_Ifq4s5b1_vmtuaxp6 X60Qx_1034 = newSeqUninit_0_Ipt20ij1_vmtuaxp6(a_47.len_0);
  result_109 = X60Qx_1034;
  NI32 i_117 = 0;
  {
    while (i_117 < a_47.len_0){
      result_109.data_0[i_117] = a_47.data_0[i_117];
      inc_1_I6wjjge_aow2h993l1((&i_117));}}
  whileStmtLabel_0: ;
  return result_109;}
void eQdestroy_1_Iuu2ern1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 s_207){
  if ((!(s_207.data_0 == NIM_NIL))){
    NI32 i_120 = 0;
    {
      while (i_120 < s_207.len_0){
        eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&s_207.data_0[i_120]));
        inc_1_I6wjjge_aow2h993l1((&i_120));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_207.data_0)));}}
static inline void eQwasMoved_1_Ifc721e1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6* s_208){
  (*s_208).len_0 = 0;
  (*s_208).data_0 = NIM_NIL;}
seq_0_I32zqoq1_vmtuaxp6 eQdup_1_Iyywo9a1_vmtuaxp6(seq_0_I32zqoq1_vmtuaxp6 a_48){
  seq_0_I32zqoq1_vmtuaxp6 result_110;
  seq_0_I32zqoq1_vmtuaxp6 X60Qx_1038 = newSeqUninit_0_Im62ogf1_vmtuaxp6(a_48.len_0);
  result_110 = X60Qx_1038;
  NI32 i_121 = 0;
  {
    while (i_121 < a_48.len_0){
      Pending_0_vmtuaxp6 X60Qx_1039 = eQdupQ_SX50ending0vmtuaxp6_0_vmtuaxp6((&a_48.data_0[i_121]));
      result_110.data_0[i_121] = X60Qx_1039;
      inc_1_I6wjjge_aow2h993l1((&i_121));}}
  whileStmtLabel_0: ;
  return result_110;}
void eQdestroyQ_SX56X4dX4fbj0vmtuaxp6_0_vmtuaxp6(VM_Obj_0_vmtuaxp6* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).scheduler_0));
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*dest_0).pendingChild_0);
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*dest_0).curCoro_0);
  eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6((*dest_0).trace_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).excVal_0));
  eQdestroy_1_I7a20g9_fiepkwzpc((*dest_0).globalInited_0);
  eQdestroy_1_Ivioh0a_ast8ri79k((*dest_0).unboundImportcNim_0);
  eQdestroy_1_Ivioh0a_ast8ri79k((*dest_0).unboundImportc_0);
  eQdestroy_1_I8k3d0z1_flaksyopx1((*dest_0).globals_0);
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6((*dest_0).sink_0);
  eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&(*dest_0).prog_0));}
void eQdestroyQ_SX50ending0vmtuaxp6_0_vmtuaxp6(Pending_0_vmtuaxp6* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).val_0));}
Pending_0_vmtuaxp6 eQdupQ_SX50ending0vmtuaxp6_0_vmtuaxp6(Pending_0_vmtuaxp6* src_0){
  Pending_0_vmtuaxp6 dest_0;
  dest_0.kind_0 = (*src_0).kind_0;
  Value_0_valzr1t4f X60Qx_1147 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*src_0).val_0));
  dest_0.val_0 = X60Qx_1147;
  return dest_0;}
void eQdestroyQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(VmCoro_Obj_0_vmtuaxp6* dest_0){
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*dest_0).retToCoro_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).retVal_0));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*dest_0).retCell_0);
  eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((*dest_0).caller_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).lastVal_0));
  eQdestroy_1_Iuu2ern1_vmtuaxp6((*dest_0).pendings_0);
  eQdestroy_1_I3wpak31_vmtuaxp6((*dest_0).handlers_0);
  eQdestroy_1_Inxd7ue1_chu5m1rja1((*dest_0).stack_0);
  eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6((*dest_0).env_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).slotSyms_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).itVal_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).stepFn_0));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*dest_0).destCell_0);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((*dest_0).myEnvCell_0);
  eQdestroy_1_I8k3d0z1_flaksyopx1((*dest_0).locals_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).lines_0);
  eQdestroy_1_Ipa2mag1_chu5m1rja1((*dest_0).code_0);}
void eQtraceQ_SX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(VmCoro_Obj_0_vmtuaxp6* dest_0, void* src_0){
  eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&(*dest_0).myEnvCell_0), src_0);
  eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&(*dest_0).destCell_0), src_0);
  eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).stepFn_0), src_0);
  eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).itVal_0), src_0);
  eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6((&(*dest_0).env_0), src_0);
  eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).lastVal_0), src_0);
  eQtraceQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&(*dest_0).caller_0), src_0);
  eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6((&(*dest_0).retCell_0), src_0);
  eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).retVal_0), src_0);
  eQtraceQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6((&(*dest_0).retToCoro_0), src_0);}
void eQdestroyQ_ArefSX56X4dX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56X4dX4fbj0vmtuaxp6_vmtuaxp6* dest_0){
  if (dest_0){
    NB8 X60Qx_1170 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1170){
      eQdestroyQ_SX56X4dX4fbj0vmtuaxp6_0_vmtuaxp6((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* dest_0){
  if (dest_0){
    NB8 X60Qx_1171 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1171){
      VmCoro_Obj_0_vmtuaxp6* X60QvtableTemp_1 = (&(*dest_0).d_00);
      ((X60Qt_0_ISX56mX43oroX4fbj0vmtuaxp6SEAnimcallZAfalseZAR36_vmtuaxp6)(*(*X60QvtableTemp_1).Q.Q.vt_00).mt_0[0])((&(*X60QvtableTemp_1)));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0){
  if (dest_0){
    NB8 X60Qx_1172 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1172){
      eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0){
  if (dest_0){
    NB8 X60Qx_1173 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1173){
      eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* eQdupQ_ArefSX4futX53inkX4fbj0natd5co251_0_vmtuaxp6(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* src_0){
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* eQdupQ_ArefSX54raceX4fbj0trakthy001_0_vmtuaxp6(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* src_0){
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* eQdupQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* src_0){
  X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQtraceQ_ArefSX56mX43oroX4fbj0vmtuaxp6_0_vmtuaxp6(X60Qt_0_IArefSX56mX43oroX4fbj0vmtuaxp6_vmtuaxp6** dest_0, void* src_0){
  }
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1174 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1174){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* dest_0){
  if (dest_0){
    NB8 X60Qx_1175 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1175){
      eQdestroyQ_SX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* src_0){
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1** dest_0, void* src_0){
  }
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1176 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1176){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* dest_0){
  if (dest_0){
    NB8 X60Qx_1177 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1177){
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_vmtuaxp6(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0){
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* dest_0){
  if (dest_0){
    NB8 X60Qx_1178 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1178){
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* src_0){
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_vmtuaxp6(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_vmtuaxp6(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_1));}
void X60Qini_0_vmtuaxp6(void){
  if (X60QiniGuard_0_vmtuaxp6){
    return;}
  X60QiniGuard_0_vmtuaxp6 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_envto7w6l1();
  X60Qini_0_xinat3x34();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_prorcx25w1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_vtanlalcx();
  X60Qini_0_valzr1t4f();
  X60Qini_0_aow2h993l1();
  X60Qini_0_natd5co251();
  X60Qini_0_chu5m1rja1();
  X60Qini_0_trakthy001();
  X60Qini_0_runot4689();
  X60Qini_0_flaksyopx1();
  X60Qini_0_croph25r5();
  string_0_sysvq0asl X60Qtmp_0 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I4769640576963739090_vmtuaxp6)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  loudInitAmnesty_0_vmtuaxp6 = eqQ_20_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_1 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I9638458106971767517_vmtuaxp6)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  loudNilBreadcrumbs_0_vmtuaxp6 = eqQ_20_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(X60Qtmp_1);
  nimStrDestroy(X60Qtmp_0);}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_24, NI32 i_31){
  NB8 X60Qx_387;
  if (i_31 < s_24.len_0){
    X60Qx_387 = (0 <= i_31);}
  else {
    X60Qx_387 = NIM_FALSE;}
  if ((!X60Qx_387)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_57;
  result_57 = (&s_24.data_0[i_31]);
  return result_57;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121){
  NI32 result_67;
  result_67 = s_121.len_0;
  return result_67;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_natd5co251(seq_0_I50urnw_chu5m1rja1 s_29, NI32 i_13){
  NB8 X60Qx_108;
  if (i_13 < s_29.len_0){
    X60Qx_108 = (0 <= i_13);}
  else {
    X60Qx_108 = NIM_FALSE;}
  if ((!X60Qx_108)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Value_0_valzr1t4f* result_19;
  result_19 = (&s_29.data_0[i_13]);
  return result_19;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26){
  NI32 L_1 = (*s_112).len_0;
  NI32 X60Qx_1795 = capInBytes_0_Iev6wua1_ast8ri79k((*s_112));
  if (X60Qx_1795 < ((NI32)(((NI32)(L_1 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_1796 = resize_0_I6ho9ve_buiyylk1h1(s_112, 1);
    if ((!X60Qx_1796)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_112).len_0));
  (*s_112).data_0[L_1] = elem_26;}
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8){
  NI32 L_1 = (*s_32).len_0;
  NI32 X60Qx_397 = capInBytes_0_Iih34tr1_flaksyopx1((*s_32));
  if (X60Qx_397 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*))) + sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)))){
    NB8 X60Qx_398 = resize_0_If3pogj_flaksyopx1(s_32, 1);
    if ((!X60Qx_398)){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(elem_8);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_32).len_0));
  (*s_32).data_0[L_1] = elem_8;}
static inline NI32 len_3_I83dzei_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_23){
  NI32 result_56;
  result_56 = s_23.len_0;
  return result_56;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline seq_0_Iw8xl5b1_flaksyopx1 newSeqUninit_0_I1tbjnk1_flaksyopx1(NI32 size_7){
  seq_0_Iw8xl5b1_flaksyopx1 result_61;
  if (size_7 == 0){
    result_61 = (seq_0_Iw8xl5b1_flaksyopx1){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ixcobep_flaksyopx1(size_7);
    void* X60Qx_392 = alloc_1_sysvq0asl(memSize_1);
    result_61 = (seq_0_Iw8xl5b1_flaksyopx1){
      .len_0 = size_7, .data_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1**)X60Qx_392)}
    ;
    if ((!(result_61.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_393 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_61.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_61;}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline openArray_0_In1h8lr1_comaa5xpt1 toOpenArray_1_Ivm9z5a_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_204){
  openArray_0_In1h8lr1_comaa5xpt1 result_112;
  MethodIndexEntry_0_sempjk6bn1* X60Qx_1878 = rawData_0_I0uy4q51_comaa5xpt1(s_204);
  result_112 = (openArray_0_In1h8lr1_comaa5xpt1){
    .a_0 = X60Qx_1878, .len_0 = s_204.len_0}
  ;
  return result_112;}
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
static inline NB8 eqQ_1_nifh7u8pu1(NU32 a_1, NU32 b_1){
  NB8 result_6;
  result_6 = (a_1 == b_1);
  return result_6;}
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
static inline void eQwasMoved_1_Ivxly0t1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1* s_41){
  (*s_41).len_0 = 0;
  (*s_41).data_0 = NIM_NIL;}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
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
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173){
  NI32 result_100;
  result_100 = s_173.len_0;
  return result_100;}
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
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130){
  NI32 result_70;
  result_70 = s_130.len_0;
  return result_70;}
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
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7){
  NB8 X60Qx_148;
  if (i_7 < s_24.len_0){
    X60Qx_148 = (0 <= i_7);}
  else {
    X60Qx_148 = NIM_FALSE;}
  if ((!X60Qx_148)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NB8* result_14;
  result_14 = (&s_24.data_0[i_7]);
  return result_14;}
static inline void putQ_7_Iiblebk_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc* s_59, NI32 i_30, NB8 elem_14){
  NB8 X60Qx_1214;
  if (i_30 < (*s_59).len_0){
    X60Qx_1214 = (0 <= i_30);}
  else {
    X60Qx_1214 = NIM_FALSE;}
  if ((!X60Qx_1214)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_59).data_0[i_30] = elem_14;}
static inline void putQ_7_I4hmt511_runot4689(seq_0_I50urnw_chu5m1rja1* s_71, NI32 i_71, Value_0_valzr1t4f elem_13){
  NB8 X60Qx_2325;
  if (i_71 < (*s_71).len_0){
    X60Qx_2325 = (0 <= i_71);}
  else {
    X60Qx_2325 = NIM_FALSE;}
  if ((!X60Qx_2325)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  Value_0_valzr1t4f* X60Qlhs_274 = (&(*s_71).data_0[i_71]);
  Value_0_valzr1t4f X60Qlhs_275 = elem_13;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_13));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_274)));
  (*X60Qlhs_274) = X60Qlhs_275;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_13));}
static inline NB8 enabled_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_1){
  NB8 result_4;
  result_4 = (!((*t_1).d_00.mode_0 == 0));
  return result_4;}
static inline void eQwasMoved_1_I4kgdoh1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_72){
  (*s_72).len_0 = 0;
  (*s_72).data_0 = NIM_NIL;}
static inline void putQ_7_I41w2p9_runot4689(seq_0_Iw8xl5b1_flaksyopx1* s_83, NI32 i_76, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_15){
  NB8 X60Qx_2336;
  if (i_76 < (*s_83).len_0){
    X60Qx_2336 = (0 <= i_76);}
  else {
    X60Qx_2336 = NIM_FALSE;}
  if ((!X60Qx_2336)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_276 = (&(*s_83).data_0[i_76]);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_277 = elem_15;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&elem_15));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qlhs_276));
  (*X60Qlhs_276) = X60Qlhs_277;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(elem_15);}
static inline void eQwasMoved_1_Ik2628i_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1* s_32){
  (*s_32).len_0 = 0;
  (*s_32).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66){
  (*s_66).len_0 = 0;
  (*s_66).data_0 = NIM_NIL;}
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
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9){
  seq_0_Iflf8jf1_fiepkwzpc result_10;
  if (size_9 == 0){
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Ih4q01h_fiepkwzpc(size_9);
    void* X60Qx_138 = alloc_1_sysvq0asl(memSize_2);
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = ((NB8*)X60Qx_138)}
    ;
    if ((!(result_10.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_139 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_10.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_10;}
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7){
  NI32 L_2 = (*s_19).len_0;
  NI32 X60Qx_144 = capInBytes_0_In1m6ni_fiepkwzpc((*s_19));
  if (X60Qx_144 < ((NI32)(((NI32)(L_2 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_145 = resize_0_I2yw78g1_fiepkwzpc(s_19, 1);
    if ((!X60Qx_145)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_19).len_0));
  (*s_19).data_0[L_2] = elem_7;}
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
static inline void putQ_7_Ild9iim_croph25r5(seq_0_Ixdx2fh1_ast8ri79k* s_23, NI32 i_11, string_0_sysvq0asl elem_9){
  NB8 X60Qx_122;
  if (i_11 < (*s_23).len_0){
    X60Qx_122 = (0 <= i_11);}
  else {
    X60Qx_122 = NIM_FALSE;}
  if ((!X60Qx_122)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  string_0_sysvq0asl* X60Qlhs_5 = (&(*s_23).data_0[i_11]);
  string_0_sysvq0asl X60Qlhs_6 = elem_9;
  nimStrWasMoved((&elem_9));
  nimStrDestroy((*X60Qlhs_5));
  (*X60Qlhs_5) = X60Qlhs_6;
  nimStrDestroy(elem_9);}
static inline NI32 len_3_I05nxx61_comaa5xpt1(seq_0_Inaua171_chu5m1rja1 s_148){
  NI32 result_85;
  result_85 = s_148.len_0;
  return result_85;}
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
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NI32 capInBytes_0_Iih34tr1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_49){
  NI32 result_78;
  NI32 X60Qx_31;
  if ((!(s_49.data_0 == NIM_NIL))){
    NI32 X60Qx_414 = allocatedSize_0_sysvq0asl(((void*)((void*)s_49.data_0)));
    X60Qx_31 = X60Qx_414;}
  else {
    X60Qx_31 = 0;}
  result_78 = X60Qx_31;
  return result_78;}
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
static inline NI32 memSizeInBytes_0_Ixcobep_flaksyopx1(NI32 size_16){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_75;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_16, sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_75 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_75 = ((NI32)2147483647);}
  return result_75;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline MethodIndexEntry_0_sempjk6bn1* rawData_0_I0uy4q51_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_253){
  MethodIndexEntry_0_sempjk6bn1* result_192;
  result_192 = s_253.data_0;
  return result_192;}
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
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_26;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_17, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_26 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_26 = ((NI32)2147483647);}
  return result_26;}
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38){
  NI32 result_31;
  NI32 X60Qx_5;
  if ((!(s_38.data_0 == NIM_NIL))){
    NI32 X60Qx_168 = allocatedSize_0_sysvq0asl(((void*)((void*)s_38.data_0)));
    X60Qx_5 = X60Qx_168;}
  else {
    X60Qx_5 = 0;}
  result_31 = X60Qx_5;
  return result_31;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
