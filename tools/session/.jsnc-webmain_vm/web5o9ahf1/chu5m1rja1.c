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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct Instr_0_chu5m1rja1 Instr_0_chu5m1rja1;
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
typedef struct GlobalSeed_0_chu5m1rja1 GlobalSeed_0_chu5m1rja1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
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
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct ObjSpec_0_chu5m1rja1{
  NU32 typeSym_0;
  NB8 isRef_0;
  seq_0_In6doa_ast8ri79k fields_0;}
ObjSpec_0_chu5m1rja1;
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct ConvSpec_0_chu5m1rja1{
  NI32 mode_0;
  NI32 bits_0;
  NB8 signed_0;
  TCode_0_valzr1t4f code_0;
  NU32 etype_0;}
ConvSpec_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;}
ObjInfo_0_chu5m1rja1;
typedef struct MethodSite_0_chu5m1rja1{
  NU32 staticFn_0;
  NI32 fallbackIdx_0;}
MethodSite_0_chu5m1rja1;
typedef struct GatedCall_0_chu5m1rja1{
  NI32 nat_0;
  NI32 fallback_0;
  NB8 dollarScalar_0;}
GatedCall_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1{
  NU32 sym_0;
  NI32 idx_0;}
MethodEntry_0_chu5m1rja1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct GlobalSeed_0_chu5m1rja1{
  NI32 slot_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl cname_0;
  Value_0_valzr1t4f v_0;}
GlobalSeed_0_chu5m1rja1;
typedef struct seq_0_Izok7jt1_chu5m1rja1{
  NI32 len_0;
  Instr_0_chu5m1rja1* data_0;}
seq_0_Izok7jt1_chu5m1rja1;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
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
typedef struct seq_0_Ir067xu1_chu5m1rja1{
  NI32 len_0;
  MethodSite_0_chu5m1rja1* data_0;}
seq_0_Ir067xu1_chu5m1rja1;
typedef struct seq_0_I88k8j01_chu5m1rja1{
  NI32 len_0;
  MethodEntry_0_chu5m1rja1* data_0;}
seq_0_I88k8j01_chu5m1rja1;
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
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
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
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
static inline seq_0_Izok7jt1_chu5m1rja1 newSeqUninit_0_I82j90d_chu5m1rja1(NI32 size_30);
static inline NI32 memSizeInBytes_0_I58le2f1_chu5m1rja1(NI32 size_31);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
static inline seq_0_Inaua171_chu5m1rja1 newSeqUninit_0_Isa1q0a_chu5m1rja1(NI32 size_34);
static inline NI32 memSizeInBytes_0_Iq7wi6a_chu5m1rja1(NI32 size_35);
static inline seq_0_I50urnw_chu5m1rja1 newSeqUninit_0_I8oufjc_chu5m1rja1(NI32 size_36);
static inline NI32 memSizeInBytes_0_Itmy7ww1_chu5m1rja1(NI32 size_37);
static inline seq_0_Ie9rikd_chu5m1rja1 newSeqUninit_0_Iqh1pff1_chu5m1rja1(NI32 size_38);
static inline NI32 memSizeInBytes_0_Ikrq3db1_chu5m1rja1(NI32 size_39);
static inline seq_0_Iknt7a3_chu5m1rja1 newSeqUninit_0_I16oi801_chu5m1rja1(NI32 size_40);
static inline NI32 memSizeInBytes_0_I3p8ndy_chu5m1rja1(NI32 size_41);
static inline seq_0_Id5h4uf_chu5m1rja1 newSeqUninit_0_Ii76u2d1_chu5m1rja1(NI32 size_44);
static inline NI32 memSizeInBytes_0_Ifccb5x1_chu5m1rja1(NI32 size_45);
static inline seq_0_I2neof81_chu5m1rja1 newSeqUninit_0_In1bf9z_chu5m1rja1(NI32 size_46);
static inline NI32 memSizeInBytes_0_I6hayax_chu5m1rja1(NI32 size_47);
static inline seq_0_Isww99s_chu5m1rja1 newSeqUninit_0_Iuxy4sp1_chu5m1rja1(NI32 size_48);
static inline NI32 memSizeInBytes_0_Ie1nwe7_chu5m1rja1(NI32 size_49);
static inline seq_0_Ir067xu1_chu5m1rja1 newSeqUninit_0_Im7kjnr_chu5m1rja1(NI32 size_50);
static inline NI32 memSizeInBytes_0_Iqssf4e1_chu5m1rja1(NI32 size_51);
static inline seq_0_I88k8j01_chu5m1rja1 newSeqUninit_0_I0s7mv21_chu5m1rja1(NI32 size_52);
static inline NI32 memSizeInBytes_0_Ij5c7dh1_chu5m1rja1(NI32 size_53);
static inline seq_0_Iioxqbu_chu5m1rja1 newSeqUninit_0_Iqy0tna1_chu5m1rja1(NI32 size_54);
static inline NI32 memSizeInBytes_0_Iywqtuz_chu5m1rja1(NI32 size_55);
void eQdestroyQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 dest_0);
ObjSpec_0_chu5m1rja1 eQdupQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 src_0);
void eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 dest_0);
ObjInfo_0_chu5m1rja1 eQdupQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 src_0);
void eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* dest_0);
GlobalSeed_0_chu5m1rja1 eQdupQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* src_0);
void eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0);
Proc_0_chu5m1rja1 eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* src_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
extern void eQdestroy_1_Iscb4i31_ast8ri79k(seq_0_In6doa_ast8ri79k s_65);
extern seq_0_In6doa_ast8ri79k eQdup_1_Idg8rf9_ast8ri79k(seq_0_In6doa_ast8ri79k a_17);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47);
extern seq_0_Ixdx2fh1_ast8ri79k eQdup_1_Imq0s4c_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k a_10);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
LongString_0_sysvq0asl const strlit_0_I14095655799529196805_chu5m1rja1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opDeref"}
;
LongString_0_sysvq0asl const strlit_0_I4203653505119668623_chu5m1rja1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opCallIndirect"}
;
LongString_0_sysvq0asl const strlit_0_I11387783988347383465_chu5m1rja1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opLoadEnv"}
;
LongString_0_sysvq0asl const strlit_0_I6978519596239417483_chu5m1rja1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opStoreEnv"}
;
LongString_0_sysvq0asl const strlit_0_I4520676207223615416_chu5m1rja1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opLoadEnvAddr"}
;
LongString_0_sysvq0asl const strlit_0_I15083592761932316767_chu5m1rja1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opLoadField"}
;
LongString_0_sysvq0asl const strlit_0_I5291897204707904471_chu5m1rja1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opTupIndex"}
;
LongString_0_sysvq0asl const strlit_0_I8241163739446522972_chu5m1rja1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opIndexGet"}
;
NB8 X60QiniGuard_0_chu5m1rja1;
void eQdestroy_1_Ipa2mag1_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 s_31){
  if ((!(s_31.data_0 == NIM_NIL))){
    NI32 i_4 = 0;
    {
      while (i_4 < s_31.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_4));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_31.data_0)));}}
static inline void eQwasMoved_1_Ik2628i_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1* s_32){
  (*s_32).len_0 = 0;
  (*s_32).data_0 = NIM_NIL;}
seq_0_Izok7jt1_chu5m1rja1 eQdup_1_Ir0cadv1_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 a_15){
  seq_0_Izok7jt1_chu5m1rja1 result_2;
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_18 = newSeqUninit_0_I82j90d_chu5m1rja1(a_15.len_0);
  result_2 = X60Qx_18;
  NI32 i_5 = 0;
  {
    while (i_5 < a_15.len_0){
      result_2.data_0[i_5] = a_15.data_0[i_5];
      inc_1_I6wjjge_aow2h993l1((&i_5));}}
  whileStmtLabel_0: ;
  return result_2;}
void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34){
  if ((!(s_34.data_0 == NIM_NIL))){
    NI32 i_8 = 0;
    {
      while (i_8 < s_34.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_8));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_34.data_0)));}}
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
seq_0_Ift2sne_chu5m1rja1 eQdup_1_Iplow11_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 a_16){
  seq_0_Ift2sne_chu5m1rja1 result_3;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_22 = newSeqUninit_0_Iggfvwp_chu5m1rja1(a_16.len_0);
  result_3 = X60Qx_22;
  NI32 i_9 = 0;
  {
    while (i_9 < a_16.len_0){
      result_3.data_0[i_9] = a_16.data_0[i_9];
      inc_1_I6wjjge_aow2h993l1((&i_9));}}
  whileStmtLabel_0: ;
  return result_3;}
void eQdestroy_1_Iwhufig1_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 s_37){
  if ((!(s_37.data_0 == NIM_NIL))){
    NI32 i_12 = 0;
    {
      while (i_12 < s_37.len_0){
        eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&s_37.data_0[i_12]));
        inc_1_I6wjjge_aow2h993l1((&i_12));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_37.data_0)));}}
static inline void eQwasMoved_1_Iwfxwnm_chu5m1rja1(seq_0_Inaua171_chu5m1rja1* s_38){
  (*s_38).len_0 = 0;
  (*s_38).data_0 = NIM_NIL;}
seq_0_Inaua171_chu5m1rja1 eQdup_1_Iz0ujbh_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 a_17){
  seq_0_Inaua171_chu5m1rja1 result_4;
  seq_0_Inaua171_chu5m1rja1 X60Qx_26 = newSeqUninit_0_Isa1q0a_chu5m1rja1(a_17.len_0);
  result_4 = X60Qx_26;
  NI32 i_13 = 0;
  {
    while (i_13 < a_17.len_0){
      Proc_0_chu5m1rja1 X60Qx_27 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&a_17.data_0[i_13]));
      result_4.data_0[i_13] = X60Qx_27;
      inc_1_I6wjjge_aow2h993l1((&i_13));}}
  whileStmtLabel_0: ;
  return result_4;}
void eQdestroy_1_Inxd7ue1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_40){
  if ((!(s_40.data_0 == NIM_NIL))){
    NI32 i_16 = 0;
    {
      while (i_16 < s_40.len_0){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_40.data_0[i_16]));
        inc_1_I6wjjge_aow2h993l1((&i_16));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_40.data_0)));}}
static inline void eQwasMoved_1_Ivxly0t1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1* s_41){
  (*s_41).len_0 = 0;
  (*s_41).data_0 = NIM_NIL;}
seq_0_I50urnw_chu5m1rja1 eQdup_1_I28mx5s1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 a_18){
  seq_0_I50urnw_chu5m1rja1 result_5;
  seq_0_I50urnw_chu5m1rja1 X60Qx_32 = newSeqUninit_0_I8oufjc_chu5m1rja1(a_18.len_0);
  result_5 = X60Qx_32;
  NI32 i_17 = 0;
  {
    while (i_17 < a_18.len_0){
      Value_0_valzr1t4f X60Qx_33 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_18.data_0[i_17]));
      result_5.data_0[i_17] = X60Qx_33;
      inc_1_I6wjjge_aow2h993l1((&i_17));}}
  whileStmtLabel_0: ;
  return result_5;}
void eQdestroy_1_Is2um9k1_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 s_43){
  if ((!(s_43.data_0 == NIM_NIL))){
    NI32 i_20 = 0;
    {
      while (i_20 < s_43.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_20));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_43.data_0)));}}
static inline void eQwasMoved_1_Iveo00a_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1* s_44){
  (*s_44).len_0 = 0;
  (*s_44).data_0 = NIM_NIL;}
seq_0_Ie9rikd_chu5m1rja1 eQdup_1_Ivlbiyc_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 a_19){
  seq_0_Ie9rikd_chu5m1rja1 result_6;
  seq_0_Ie9rikd_chu5m1rja1 X60Qx_38 = newSeqUninit_0_Iqh1pff1_chu5m1rja1(a_19.len_0);
  result_6 = X60Qx_38;
  NI32 i_21 = 0;
  {
    while (i_21 < a_19.len_0){
      result_6.data_0[i_21] = a_19.data_0[i_21];
      inc_1_I6wjjge_aow2h993l1((&i_21));}}
  whileStmtLabel_0: ;
  return result_6;}
void eQdestroy_1_Ik9jljs1_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 s_46){
  if ((!(s_46.data_0 == NIM_NIL))){
    NI32 i_24 = 0;
    {
      while (i_24 < s_46.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_24));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_46.data_0)));}}
static inline void eQwasMoved_1_Ilr05dk1_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1* s_47){
  (*s_47).len_0 = 0;
  (*s_47).data_0 = NIM_NIL;}
seq_0_Iknt7a3_chu5m1rja1 eQdup_1_Iivi5nx1_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 a_20){
  seq_0_Iknt7a3_chu5m1rja1 result_7;
  seq_0_Iknt7a3_chu5m1rja1 X60Qx_42 = newSeqUninit_0_I16oi801_chu5m1rja1(a_20.len_0);
  result_7 = X60Qx_42;
  NI32 i_25 = 0;
  {
    while (i_25 < a_20.len_0){
      result_7.data_0[i_25] = a_20.data_0[i_25];
      inc_1_I6wjjge_aow2h993l1((&i_25));}}
  whileStmtLabel_0: ;
  return result_7;}
void eQdestroy_1_Iwyaew9_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 s_52){
  if ((!(s_52.data_0 == NIM_NIL))){
    NI32 i_32 = 0;
    {
      while (i_32 < s_52.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_32));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_52.data_0)));}}
static inline void eQwasMoved_1_Iwhqrp3_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1* s_53){
  (*s_53).len_0 = 0;
  (*s_53).data_0 = NIM_NIL;}
seq_0_Id5h4uf_chu5m1rja1 eQdup_1_I00ryxj_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 a_22){
  seq_0_Id5h4uf_chu5m1rja1 result_9;
  seq_0_Id5h4uf_chu5m1rja1 X60Qx_52 = newSeqUninit_0_Ii76u2d1_chu5m1rja1(a_22.len_0);
  result_9 = X60Qx_52;
  NI32 i_33 = 0;
  {
    while (i_33 < a_22.len_0){
      result_9.data_0[i_33] = a_22.data_0[i_33];
      inc_1_I6wjjge_aow2h993l1((&i_33));}}
  whileStmtLabel_0: ;
  return result_9;}
void eQdestroy_1_Icae6hi1_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 s_55){
  if ((!(s_55.data_0 == NIM_NIL))){
    NI32 i_36 = 0;
    {
      while (i_36 < s_55.len_0){
        eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(s_55.data_0[i_36]);
        inc_1_I6wjjge_aow2h993l1((&i_36));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_55.data_0)));}}
static inline void eQwasMoved_1_Icqvtyb_chu5m1rja1(seq_0_I2neof81_chu5m1rja1* s_56){
  (*s_56).len_0 = 0;
  (*s_56).data_0 = NIM_NIL;}
seq_0_I2neof81_chu5m1rja1 eQdup_1_I09s8x31_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 a_23){
  seq_0_I2neof81_chu5m1rja1 result_10;
  seq_0_I2neof81_chu5m1rja1 X60Qx_56 = newSeqUninit_0_In1bf9z_chu5m1rja1(a_23.len_0);
  result_10 = X60Qx_56;
  NI32 i_37 = 0;
  {
    while (i_37 < a_23.len_0){
      ObjInfo_0_chu5m1rja1 X60Qx_57 = eQdupQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(a_23.data_0[i_37]);
      result_10.data_0[i_37] = X60Qx_57;
      inc_1_I6wjjge_aow2h993l1((&i_37));}}
  whileStmtLabel_0: ;
  return result_10;}
void eQdestroy_1_Iymp2mv1_chu5m1rja1(seq_0_Isww99s_chu5m1rja1 s_58){
  if ((!(s_58.data_0 == NIM_NIL))){
    NI32 i_40 = 0;
    {
      while (i_40 < s_58.len_0){
        eQdestroyQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(s_58.data_0[i_40]);
        inc_1_I6wjjge_aow2h993l1((&i_40));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_58.data_0)));}}
static inline void eQwasMoved_1_Ieg6kxd1_chu5m1rja1(seq_0_Isww99s_chu5m1rja1* s_59){
  (*s_59).len_0 = 0;
  (*s_59).data_0 = NIM_NIL;}
seq_0_Isww99s_chu5m1rja1 eQdup_1_I41eryb1_chu5m1rja1(seq_0_Isww99s_chu5m1rja1 a_24){
  seq_0_Isww99s_chu5m1rja1 result_11;
  seq_0_Isww99s_chu5m1rja1 X60Qx_62 = newSeqUninit_0_Iuxy4sp1_chu5m1rja1(a_24.len_0);
  result_11 = X60Qx_62;
  NI32 i_41 = 0;
  {
    while (i_41 < a_24.len_0){
      ObjSpec_0_chu5m1rja1 X60Qx_63 = eQdupQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(a_24.data_0[i_41]);
      result_11.data_0[i_41] = X60Qx_63;
      inc_1_I6wjjge_aow2h993l1((&i_41));}}
  whileStmtLabel_0: ;
  return result_11;}
void eQdestroy_1_Ivzn3k81_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 s_61){
  if ((!(s_61.data_0 == NIM_NIL))){
    NI32 i_44 = 0;
    {
      while (i_44 < s_61.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_44));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_61.data_0)));}}
static inline void eQwasMoved_1_Ihxtwi71_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1* s_62){
  (*s_62).len_0 = 0;
  (*s_62).data_0 = NIM_NIL;}
seq_0_Ir067xu1_chu5m1rja1 eQdup_1_I85r9nd1_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 a_25){
  seq_0_Ir067xu1_chu5m1rja1 result_12;
  seq_0_Ir067xu1_chu5m1rja1 X60Qx_68 = newSeqUninit_0_Im7kjnr_chu5m1rja1(a_25.len_0);
  result_12 = X60Qx_68;
  NI32 i_45 = 0;
  {
    while (i_45 < a_25.len_0){
      result_12.data_0[i_45] = a_25.data_0[i_45];
      inc_1_I6wjjge_aow2h993l1((&i_45));}}
  whileStmtLabel_0: ;
  return result_12;}
void eQdestroy_1_Id0rxta_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 s_64){
  if ((!(s_64.data_0 == NIM_NIL))){
    NI32 i_48 = 0;
    {
      while (i_48 < s_64.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_48));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_64.data_0)));}}
static inline void eQwasMoved_1_Izuqbjq1_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1* s_65){
  (*s_65).len_0 = 0;
  (*s_65).data_0 = NIM_NIL;}
seq_0_I88k8j01_chu5m1rja1 eQdup_1_Ishf7nq1_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 a_26){
  seq_0_I88k8j01_chu5m1rja1 result_13;
  seq_0_I88k8j01_chu5m1rja1 X60Qx_72 = newSeqUninit_0_I0s7mv21_chu5m1rja1(a_26.len_0);
  result_13 = X60Qx_72;
  NI32 i_49 = 0;
  {
    while (i_49 < a_26.len_0){
      result_13.data_0[i_49] = a_26.data_0[i_49];
      inc_1_I6wjjge_aow2h993l1((&i_49));}}
  whileStmtLabel_0: ;
  return result_13;}
void eQdestroy_1_I6lze041_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 s_67){
  if ((!(s_67.data_0 == NIM_NIL))){
    NI32 i_52 = 0;
    {
      while (i_52 < s_67.len_0){
        eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1((&s_67.data_0[i_52]));
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_67.data_0)));}}
static inline void eQwasMoved_1_Ilt02ww1_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1* s_68){
  (*s_68).len_0 = 0;
  (*s_68).data_0 = NIM_NIL;}
seq_0_Iioxqbu_chu5m1rja1 eQdup_1_Iwrxt2p_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 a_27){
  seq_0_Iioxqbu_chu5m1rja1 result_14;
  seq_0_Iioxqbu_chu5m1rja1 X60Qx_76 = newSeqUninit_0_Iqy0tna1_chu5m1rja1(a_27.len_0);
  result_14 = X60Qx_76;
  NI32 i_53 = 0;
  {
    while (i_53 < a_27.len_0){
      GlobalSeed_0_chu5m1rja1 X60Qx_77 = eQdupQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1((&a_27.data_0[i_53]));
      result_14.data_0[i_53] = X60Qx_77;
      inc_1_I6wjjge_aow2h993l1((&i_53));}}
  whileStmtLabel_0: ;
  return result_14;}
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
void eQdestroyQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 dest_0){
  eQdestroy_1_Iscb4i31_ast8ri79k(dest_0.fields_0);}
ObjSpec_0_chu5m1rja1 eQdupQ_SX4fbjX53pec0chu5m1rja1_0_chu5m1rja1(ObjSpec_0_chu5m1rja1 src_0){
  ObjSpec_0_chu5m1rja1 dest_0;
  dest_0.typeSym_0 = src_0.typeSym_0;
  dest_0.isRef_0 = src_0.isRef_0;
  seq_0_In6doa_ast8ri79k X60Qx_124 = eQdup_1_Idg8rf9_ast8ri79k(src_0.fields_0);
  dest_0.fields_0 = X60Qx_124;
  return dest_0;}
void eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 dest_0){
  eQdestroy_1_Iscb4i31_ast8ri79k(dest_0.fieldSyms_0);}
ObjInfo_0_chu5m1rja1 eQdupQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 src_0){
  ObjInfo_0_chu5m1rja1 dest_0;
  dest_0.typeSym_0 = src_0.typeSym_0;
  seq_0_In6doa_ast8ri79k X60Qx_125 = eQdup_1_Idg8rf9_ast8ri79k(src_0.fieldSyms_0);
  dest_0.fieldSyms_0 = X60Qx_125;
  return dest_0;}
void eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).v_0));
  nimStrDestroy((*dest_0).cname_0);
  nimStrDestroy((*dest_0).name_0);}
GlobalSeed_0_chu5m1rja1 eQdupQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* src_0){
  GlobalSeed_0_chu5m1rja1 dest_0;
  dest_0.slot_0 = (*src_0).slot_0;
  string_0_sysvq0asl X60Qx_126 = nimStrDup((*src_0).name_0);
  dest_0.name_0 = X60Qx_126;
  string_0_sysvq0asl X60Qx_127 = nimStrDup((*src_0).cname_0);
  dest_0.cname_0 = X60Qx_127;
  Value_0_valzr1t4f X60Qx_128 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*src_0).v_0));
  dest_0.v_0 = X60Qx_128;
  return dest_0;}
void eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0){
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).slotSyms_0);
  nimStrDestroy((*dest_0).name_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).lines_0);
  eQdestroy_1_Ipa2mag1_chu5m1rja1((*dest_0).code_0);}
void eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0){
  eQwasMoved_1_Ik2628i_chu5m1rja1((&(*dest_0).code_0));
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&(*dest_0).lines_0));
  nimStrWasMoved((&(*dest_0).name_0));
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).slotSyms_0));}
Proc_0_chu5m1rja1 eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* src_0){
  Proc_0_chu5m1rja1 dest_0;
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_129 = eQdup_1_Ir0cadv1_chu5m1rja1((*src_0).code_0);
  dest_0.code_0 = X60Qx_129;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_130 = eQdup_1_Iplow11_chu5m1rja1((*src_0).lines_0);
  dest_0.lines_0 = X60Qx_130;
  dest_0.numParams_0 = (*src_0).numParams_0;
  dest_0.numLocals_0 = (*src_0).numLocals_0;
  dest_0.resultSlot_0 = (*src_0).resultSlot_0;
  string_0_sysvq0asl X60Qx_131 = nimStrDup((*src_0).name_0);
  dest_0.name_0 = X60Qx_131;
  dest_0.isPassive_0 = (*src_0).isPassive_0;
  seq_0_In6doa_ast8ri79k X60Qx_132 = eQdup_1_Idg8rf9_ast8ri79k((*src_0).slotSyms_0);
  dest_0.slotSyms_0 = X60Qx_132;
  return dest_0;}
void eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0){
  eQdestroy_1_I6lze041_chu5m1rja1((*dest_0).globalSeeds_0);
  eQdestroy_1_Iwhufig1_chu5m1rja1((*dest_0).inits_0);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&(*dest_0).top_0));
  eQdestroy_1_Id0rxta_chu5m1rja1((*dest_0).methodTable_0);
  eQdestroy_1_Ivzn3k81_chu5m1rja1((*dest_0).methodSites_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).envSyms_0);
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
void eQwasmovedQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0){
  eQwasMoved_1_Iwfxwnm_chu5m1rja1((&(*dest_0).procs_0));
  eQwasMoved_1_Ivxly0t1_chu5m1rja1((&(*dest_0).consts_0));
  eQwasMoved_1_Iveo00a_chu5m1rja1((&(*dest_0).magics_0));
  eQwasMoved_1_Ilr05dk1_chu5m1rja1((&(*dest_0).convs_0));
  eQwasMoved_1_I5vdnla_ast8ri79k((&(*dest_0).natives_0));
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).enumWraps_0));
  eQwasMoved_1_Iwhqrp3_chu5m1rja1((&(*dest_0).gatedCalls_0));
  eQwasMoved_1_Icqvtyb_chu5m1rja1((&(*dest_0).objInfos_0));
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).fieldSyms_0));
  eQwasMoved_1_Ieg6kxd1_chu5m1rja1((&(*dest_0).objSpecs_0));
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).typeSyms_0));
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).envSyms_0));
  eQwasMoved_1_Ihxtwi71_chu5m1rja1((&(*dest_0).methodSites_0));
  eQwasMoved_1_Izuqbjq1_chu5m1rja1((&(*dest_0).methodTable_0));
  eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&(*dest_0).top_0));
  eQwasMoved_1_Iwfxwnm_chu5m1rja1((&(*dest_0).inits_0));
  eQwasMoved_1_Ilt02ww1_chu5m1rja1((&(*dest_0).globalSeeds_0));}
VmProgram_0_chu5m1rja1 eQdupQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* src_0){
  VmProgram_0_chu5m1rja1 dest_0;
  seq_0_Inaua171_chu5m1rja1 X60Qx_133 = eQdup_1_Iz0ujbh_chu5m1rja1((*src_0).procs_0);
  dest_0.procs_0 = X60Qx_133;
  seq_0_I50urnw_chu5m1rja1 X60Qx_134 = eQdup_1_I28mx5s1_chu5m1rja1((*src_0).consts_0);
  dest_0.consts_0 = X60Qx_134;
  seq_0_Ie9rikd_chu5m1rja1 X60Qx_135 = eQdup_1_Ivlbiyc_chu5m1rja1((*src_0).magics_0);
  dest_0.magics_0 = X60Qx_135;
  seq_0_Iknt7a3_chu5m1rja1 X60Qx_136 = eQdup_1_Iivi5nx1_chu5m1rja1((*src_0).convs_0);
  dest_0.convs_0 = X60Qx_136;
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_137 = eQdup_1_Imq0s4c_ast8ri79k((*src_0).natives_0);
  dest_0.natives_0 = X60Qx_137;
  seq_0_In6doa_ast8ri79k X60Qx_138 = eQdup_1_Idg8rf9_ast8ri79k((*src_0).enumWraps_0);
  dest_0.enumWraps_0 = X60Qx_138;
  seq_0_Id5h4uf_chu5m1rja1 X60Qx_139 = eQdup_1_I00ryxj_chu5m1rja1((*src_0).gatedCalls_0);
  dest_0.gatedCalls_0 = X60Qx_139;
  seq_0_I2neof81_chu5m1rja1 X60Qx_140 = eQdup_1_I09s8x31_chu5m1rja1((*src_0).objInfos_0);
  dest_0.objInfos_0 = X60Qx_140;
  seq_0_In6doa_ast8ri79k X60Qx_141 = eQdup_1_Idg8rf9_ast8ri79k((*src_0).fieldSyms_0);
  dest_0.fieldSyms_0 = X60Qx_141;
  seq_0_Isww99s_chu5m1rja1 X60Qx_142 = eQdup_1_I41eryb1_chu5m1rja1((*src_0).objSpecs_0);
  dest_0.objSpecs_0 = X60Qx_142;
  seq_0_In6doa_ast8ri79k X60Qx_143 = eQdup_1_Idg8rf9_ast8ri79k((*src_0).typeSyms_0);
  dest_0.typeSyms_0 = X60Qx_143;
  seq_0_In6doa_ast8ri79k X60Qx_144 = eQdup_1_Idg8rf9_ast8ri79k((*src_0).envSyms_0);
  dest_0.envSyms_0 = X60Qx_144;
  seq_0_Ir067xu1_chu5m1rja1 X60Qx_145 = eQdup_1_I85r9nd1_chu5m1rja1((*src_0).methodSites_0);
  dest_0.methodSites_0 = X60Qx_145;
  seq_0_I88k8j01_chu5m1rja1 X60Qx_146 = eQdup_1_Ishf7nq1_chu5m1rja1((*src_0).methodTable_0);
  dest_0.methodTable_0 = X60Qx_146;
  Proc_0_chu5m1rja1 X60Qx_147 = eQdupQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&(*src_0).top_0));
  dest_0.top_0 = X60Qx_147;
  seq_0_Inaua171_chu5m1rja1 X60Qx_148 = eQdup_1_Iz0ujbh_chu5m1rja1((*src_0).inits_0);
  dest_0.inits_0 = X60Qx_148;
  dest_0.numGlobals_0 = (*src_0).numGlobals_0;
  seq_0_Iioxqbu_chu5m1rja1 X60Qx_149 = eQdup_1_Iwrxt2p_chu5m1rja1((*src_0).globalSeeds_0);
  dest_0.globalSeeds_0 = X60Qx_149;
  return dest_0;}
void X60Qini_0_chu5m1rja1(void){
  if (X60QiniGuard_0_chu5m1rja1){
    return;}
  X60QiniGuard_0_chu5m1rja1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_valzr1t4f();
  X60Qini_0_nimry5ra91();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66){
  (*s_66).len_0 = 0;
  (*s_66).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47){
  (*s_47).len_0 = 0;
  (*s_47).data_0 = NIM_NIL;}
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
