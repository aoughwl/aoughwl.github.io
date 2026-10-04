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
typedef struct RenderTok_0_renqb5hy11 RenderTok_0_renqb5hy11;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef NU8 TokType_0_renqb5hy11;

#define tkInvalid_0_renqb5hy11 ((NU8)0)
#define tkEof_0_renqb5hy11 ((NU8)1)
#define tkSymbol_0_renqb5hy11 ((NU8)2)
#define tkAddr_0_renqb5hy11 ((NU8)3)
#define tkAnd_0_renqb5hy11 ((NU8)4)
#define tkAs_0_renqb5hy11 ((NU8)5)
#define tkAsm_0_renqb5hy11 ((NU8)6)
#define tkBind_0_renqb5hy11 ((NU8)7)
#define tkBlock_0_renqb5hy11 ((NU8)8)
#define tkBreak_0_renqb5hy11 ((NU8)9)
#define tkCase_0_renqb5hy11 ((NU8)10)
#define tkCast_0_renqb5hy11 ((NU8)11)
#define tkConcept_0_renqb5hy11 ((NU8)12)
#define tkConst_0_renqb5hy11 ((NU8)13)
#define tkContinue_0_renqb5hy11 ((NU8)14)
#define tkConverter_0_renqb5hy11 ((NU8)15)
#define tkDefer_0_renqb5hy11 ((NU8)16)
#define tkDiscard_0_renqb5hy11 ((NU8)17)
#define tkDistinct_0_renqb5hy11 ((NU8)18)
#define tkDiv_0_renqb5hy11 ((NU8)19)
#define tkDo_0_renqb5hy11 ((NU8)20)
#define tkElif_0_renqb5hy11 ((NU8)21)
#define tkElse_0_renqb5hy11 ((NU8)22)
#define tkEnd_0_renqb5hy11 ((NU8)23)
#define tkEnum_0_renqb5hy11 ((NU8)24)
#define tkExcept_0_renqb5hy11 ((NU8)25)
#define tkExport_0_renqb5hy11 ((NU8)26)
#define tkFinally_0_renqb5hy11 ((NU8)27)
#define tkFor_0_renqb5hy11 ((NU8)28)
#define tkFrom_0_renqb5hy11 ((NU8)29)
#define tkFunc_0_renqb5hy11 ((NU8)30)
#define tkIf_0_renqb5hy11 ((NU8)31)
#define tkImport_0_renqb5hy11 ((NU8)32)
#define tkIn_0_renqb5hy11 ((NU8)33)
#define tkInclude_0_renqb5hy11 ((NU8)34)
#define tkInterface_0_renqb5hy11 ((NU8)35)
#define tkIs_0_renqb5hy11 ((NU8)36)
#define tkIsnot_0_renqb5hy11 ((NU8)37)
#define tkIterator_0_renqb5hy11 ((NU8)38)
#define tkLet_0_renqb5hy11 ((NU8)39)
#define tkMacro_0_renqb5hy11 ((NU8)40)
#define tkMethod_0_renqb5hy11 ((NU8)41)
#define tkMixin_0_renqb5hy11 ((NU8)42)
#define tkMod_0_renqb5hy11 ((NU8)43)
#define tkNil_0_renqb5hy11 ((NU8)44)
#define tkNot_0_renqb5hy11 ((NU8)45)
#define tkNotin_0_renqb5hy11 ((NU8)46)
#define tkObject_0_renqb5hy11 ((NU8)47)
#define tkOf_0_renqb5hy11 ((NU8)48)
#define tkOr_0_renqb5hy11 ((NU8)49)
#define tkOut_0_renqb5hy11 ((NU8)50)
#define tkProc_0_renqb5hy11 ((NU8)51)
#define tkPtr_0_renqb5hy11 ((NU8)52)
#define tkRaise_0_renqb5hy11 ((NU8)53)
#define tkRef_0_renqb5hy11 ((NU8)54)
#define tkReturn_0_renqb5hy11 ((NU8)55)
#define tkShl_0_renqb5hy11 ((NU8)56)
#define tkShr_0_renqb5hy11 ((NU8)57)
#define tkStatic_0_renqb5hy11 ((NU8)58)
#define tkTemplate_0_renqb5hy11 ((NU8)59)
#define tkTry_0_renqb5hy11 ((NU8)60)
#define tkTuple_0_renqb5hy11 ((NU8)61)
#define tkType_0_renqb5hy11 ((NU8)62)
#define tkUsing_0_renqb5hy11 ((NU8)63)
#define tkVar_0_renqb5hy11 ((NU8)64)
#define tkWhen_0_renqb5hy11 ((NU8)65)
#define tkWhile_0_renqb5hy11 ((NU8)66)
#define tkXor_0_renqb5hy11 ((NU8)67)
#define tkYield_0_renqb5hy11 ((NU8)68)
#define tkIntLit_0_renqb5hy11 ((NU8)69)
#define tkInt8Lit_0_renqb5hy11 ((NU8)70)
#define tkInt16Lit_0_renqb5hy11 ((NU8)71)
#define tkInt32Lit_0_renqb5hy11 ((NU8)72)
#define tkInt64Lit_0_renqb5hy11 ((NU8)73)
#define tkUIntLit_0_renqb5hy11 ((NU8)74)
#define tkUInt8Lit_0_renqb5hy11 ((NU8)75)
#define tkUInt16Lit_0_renqb5hy11 ((NU8)76)
#define tkUInt32Lit_0_renqb5hy11 ((NU8)77)
#define tkUInt64Lit_0_renqb5hy11 ((NU8)78)
#define tkFloatLit_0_renqb5hy11 ((NU8)79)
#define tkFloat32Lit_0_renqb5hy11 ((NU8)80)
#define tkFloat64Lit_0_renqb5hy11 ((NU8)81)
#define tkFloat128Lit_0_renqb5hy11 ((NU8)82)
#define tkStrLit_0_renqb5hy11 ((NU8)83)
#define tkRStrLit_0_renqb5hy11 ((NU8)84)
#define tkTripleStrLit_0_renqb5hy11 ((NU8)85)
#define tkGStrLit_0_renqb5hy11 ((NU8)86)
#define tkGTripleStrLit_0_renqb5hy11 ((NU8)87)
#define tkCharLit_0_renqb5hy11 ((NU8)88)
#define tkCustomLit_0_renqb5hy11 ((NU8)89)
#define tkParLe_0_renqb5hy11 ((NU8)90)
#define tkParRi_0_renqb5hy11 ((NU8)91)
#define tkBracketLe_0_renqb5hy11 ((NU8)92)
#define tkBracketRi_0_renqb5hy11 ((NU8)93)
#define tkCurlyLe_0_renqb5hy11 ((NU8)94)
#define tkCurlyRi_0_renqb5hy11 ((NU8)95)
#define tkBracketDotLe_0_renqb5hy11 ((NU8)96)
#define tkBracketDotRi_0_renqb5hy11 ((NU8)97)
#define tkCurlyDotLe_0_renqb5hy11 ((NU8)98)
#define tkCurlyDotRi_0_renqb5hy11 ((NU8)99)
#define tkParDotLe_0_renqb5hy11 ((NU8)100)
#define tkParDotRi_0_renqb5hy11 ((NU8)101)
#define tkComma_0_renqb5hy11 ((NU8)102)
#define tkSemiColon_0_renqb5hy11 ((NU8)103)
#define tkColon_0_renqb5hy11 ((NU8)104)
#define tkColonColon_0_renqb5hy11 ((NU8)105)
#define tkEquals_0_renqb5hy11 ((NU8)106)
#define tkDot_0_renqb5hy11 ((NU8)107)
#define tkDotDot_0_renqb5hy11 ((NU8)108)
#define tkBracketLeColon_0_renqb5hy11 ((NU8)109)
#define tkOpr_0_renqb5hy11 ((NU8)110)
#define tkComment_0_renqb5hy11 ((NU8)111)
#define tkAccent_0_renqb5hy11 ((NU8)112)
#define tkSpaces_0_renqb5hy11 ((NU8)113)
#define tkInfixOpr_0_renqb5hy11 ((NU8)114)
#define tkPrefixOpr_0_renqb5hy11 ((NU8)115)
#define tkPostfixOpr_0_renqb5hy11 ((NU8)116)
#define tkHideableStart_0_renqb5hy11 ((NU8)117)
#define tkHideableEnd_0_renqb5hy11 ((NU8)118)
typedef NU8 RenderFlag_0_renqb5hy11;

#define renderNone_0_renqb5hy11 ((NU8)0)
#define renderNoBody_0_renqb5hy11 ((NU8)1)
#define renderNoComments_0_renqb5hy11 ((NU8)2)
#define renderDocComments_0_renqb5hy11 ((NU8)3)
#define renderNoPragmas_0_renqb5hy11 ((NU8)4)
#define renderIds_0_renqb5hy11 ((NU8)5)
#define renderNoProcDefs_0_renqb5hy11 ((NU8)6)
#define renderSyms_0_renqb5hy11 ((NU8)7)
#define renderRunnableExamples_0_renqb5hy11 ((NU8)8)
#define renderIr_0_renqb5hy11 ((NU8)9)
#define renderNonExportedFields_0_renqb5hy11 ((NU8)10)
#define renderExpandUsing_0_renqb5hy11 ((NU8)11)
#define renderNoPostfix_0_renqb5hy11 ((NU8)12)
typedef struct RenderTok_0_renqb5hy11{
  TokType_0_renqb5hy11 kind_0;
  NI16 length_0;
  NU32 sym_0;
  NB8 isDef_0;}
RenderTok_0_renqb5hy11;
typedef NU8 Section_0_renqb5hy11;

#define GenericParams_0_renqb5hy11 ((NU8)0)
#define ObjectDef_0_renqb5hy11 ((NU8)1)
typedef struct seq_0_I5vqb3x_renqb5hy11{
  NI32 len_0;
  RenderTok_0_renqb5hy11* data_0;}
seq_0_I5vqb3x_renqb5hy11;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct SrcGen_0_renqb5hy11{
  NI32 indent_0;
  NI32 lineLen_0;
  NI32 col_0;
  NI32 pos_0;
  NI32 idx_0;
  seq_0_I5vqb3x_renqb5hy11 tokens_0;
  string_0_sysvq0asl buf_0;
  NI32 pendingNL_0;
  NI32 pendingWhitespace_0;
  NU16 flags_0;
  NU8 inside_0;
  NB8 checkAnon_0;
  NI32 inPragma_0;
  seq_0_In6doa_ast8ri79k mangler_0;}
SrcGen_0_renqb5hy11;
typedef NU8 SubFlag_0_renqb5hy11;

#define rfLongMode_0_renqb5hy11 ((NU8)0)
#define rfInConstExpr_0_renqb5hy11 ((NU8)1)
typedef NU8 BracketKind_0_renqb5hy11;

#define bkNone_0_renqb5hy11 ((NU8)0)
#define bkBracket_0_renqb5hy11 ((NU8)1)
#define bkBracketAsgn_0_renqb5hy11 ((NU8)2)
#define bkCurly_0_renqb5hy11 ((NU8)3)
#define bkCurlyAsgn_0_renqb5hy11 ((NU8)4)
#define bkPar_0_renqb5hy11 ((NU8)5)
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
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
typedef struct X60Qt_0_IAtupleAiS32ZAsetSX53ubX46lag0renqb5hy11_renqb5hy11{
  NI32 fld_0;
  NU8 fld_1;}
X60Qt_0_IAtupleAiS32ZAsetSX53ubX46lag0renqb5hy11_renqb5hy11;
typedef struct X60Qt_0_IAarrayAuS8ZS15_renqb5hy11{
  NU8 a[15];}
X60Qt_0_IAarrayAuS8ZS15_renqb5hy11;
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
typedef struct X60Qt_0_IAarrayAuS8ZS24_nim30udrv{
  NU8 a[24];}
X60Qt_0_IAarrayAuS8ZS24_nim30udrv;
typedef struct X60Qt_0_IAarrayAuS8ZS27_decqocs071{
  NU8 a[27];}
X60Qt_0_IAarrayAuS8ZS27_decqocs071;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1{
  string_0_sysvq0asl a[2];}
X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_filqx2b6r1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_njv44qpu9(void);
extern void X60Qini_0_njvhmst99(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_for2ybv4p1(void);
LongString_0_sysvq0asl const strlit_0_I18357185398770638485_renqb5hy11 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint"}
;
LongString_0_sysvq0asl const strlit_0_I11643015150811461308_renqb5hy11 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "float"}
;
LongString_0_sysvq0asl const strlit_0_I3703322799828345117_renqb5hy11 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "char"}
;
NB8 X60QiniGuard_0_renqb5hy11;
void X60Qini_0_renqb5hy11(void){
  if (X60QiniGuard_0_renqb5hy11){
    return;}
  X60QiniGuard_0_renqb5hy11 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_filqx2b6r1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_njv44qpu9();
  X60Qini_0_njvhmst99();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_str7j0ifg();
  X60Qini_0_assy765wm();
  X60Qini_0_for2ybv4p1();}
