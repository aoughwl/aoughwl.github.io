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
typedef NU16 NimonyStmt_0_nimry5ra91;

#define NoStmt_0_nimry5ra91 ((NU16)0)
#define CallS_0_nimry5ra91 ((NU16)50)
#define CmdS_0_nimry5ra91 ((NU16)51)
#define GvarS_0_nimry5ra91 ((NU16)54)
#define TvarS_0_nimry5ra91 ((NU16)55)
#define VarS_0_nimry5ra91 ((NU16)56)
#define ConstS_0_nimry5ra91 ((NU16)58)
#define ResultS_0_nimry5ra91 ((NU16)59)
#define GletS_0_nimry5ra91 ((NU16)60)
#define TletS_0_nimry5ra91 ((NU16)61)
#define LetS_0_nimry5ra91 ((NU16)62)
#define CursorS_0_nimry5ra91 ((NU16)63)
#define PatternvarS_0_nimry5ra91 ((NU16)64)
#define ProcS_0_nimry5ra91 ((NU16)70)
#define FuncS_0_nimry5ra91 ((NU16)71)
#define IteratorS_0_nimry5ra91 ((NU16)72)
#define ConverterS_0_nimry5ra91 ((NU16)73)
#define MethodS_0_nimry5ra91 ((NU16)74)
#define MacroS_0_nimry5ra91 ((NU16)75)
#define TemplateS_0_nimry5ra91 ((NU16)76)
#define TypeS_0_nimry5ra91 ((NU16)77)
#define BlockS_0_nimry5ra91 ((NU16)78)
#define EmitS_0_nimry5ra91 ((NU16)82)
#define AsgnS_0_nimry5ra91 ((NU16)83)
#define ScopeS_0_nimry5ra91 ((NU16)86)
#define IfS_0_nimry5ra91 ((NU16)87)
#define WhenS_0_nimry5ra91 ((NU16)88)
#define BreakS_0_nimry5ra91 ((NU16)92)
#define ContinueS_0_nimry5ra91 ((NU16)93)
#define ForS_0_nimry5ra91 ((NU16)94)
#define WhileS_0_nimry5ra91 ((NU16)95)
#define CoroforS_0_nimry5ra91 ((NU16)96)
#define CaseS_0_nimry5ra91 ((NU16)97)
#define RetS_0_nimry5ra91 ((NU16)101)
#define YldS_0_nimry5ra91 ((NU16)102)
#define StmtsS_0_nimry5ra91 ((NU16)103)
#define PragmasS_0_nimry5ra91 ((NU16)140)
#define PragmaxS_0_nimry5ra91 ((NU16)141)
#define InclS_0_nimry5ra91 ((NU16)146)
#define ExclS_0_nimry5ra91 ((NU16)147)
#define IncludeS_0_nimry5ra91 ((NU16)148)
#define ImportS_0_nimry5ra91 ((NU16)149)
#define ImportasS_0_nimry5ra91 ((NU16)150)
#define FromimportS_0_nimry5ra91 ((NU16)151)
#define ImportexceptS_0_nimry5ra91 ((NU16)152)
#define ExportS_0_nimry5ra91 ((NU16)153)
#define ExportexceptS_0_nimry5ra91 ((NU16)155)
#define CommentS_0_nimry5ra91 ((NU16)156)
#define DiscardS_0_nimry5ra91 ((NU16)157)
#define TryS_0_nimry5ra91 ((NU16)158)
#define RaiseS_0_nimry5ra91 ((NU16)159)
#define UnpackdeclS_0_nimry5ra91 ((NU16)182)
#define AssumeS_0_nimry5ra91 ((NU16)228)
#define AssertS_0_nimry5ra91 ((NU16)229)
#define CallstrlitS_0_nimry5ra91 ((NU16)249)
#define InfixS_0_nimry5ra91 ((NU16)250)
#define PrefixS_0_nimry5ra91 ((NU16)251)
#define HcallS_0_nimry5ra91 ((NU16)252)
#define StaticstmtS_0_nimry5ra91 ((NU16)296)
#define BindS_0_nimry5ra91 ((NU16)297)
#define MixinS_0_nimry5ra91 ((NU16)298)
#define UsingS_0_nimry5ra91 ((NU16)299)
#define AsmS_0_nimry5ra91 ((NU16)300)
#define DeferS_0_nimry5ra91 ((NU16)301)
typedef NU8 NimonyType_0_nimry5ra91;

#define NoType_0_nimry5ra91 ((NU8)0)
#define ErrT_0_nimry5ra91 ((NU8)1)
#define AtT_0_nimry5ra91 ((NU8)3)
#define AndT_0_nimry5ra91 ((NU8)17)
#define OrT_0_nimry5ra91 ((NU8)18)
#define NotT_0_nimry5ra91 ((NU8)20)
#define ProcT_0_nimry5ra91 ((NU8)70)
#define FuncT_0_nimry5ra91 ((NU8)71)
#define IteratorT_0_nimry5ra91 ((NU8)72)
#define ConverterT_0_nimry5ra91 ((NU8)73)
#define MethodT_0_nimry5ra91 ((NU8)74)
#define MacroT_0_nimry5ra91 ((NU8)75)
#define TemplateT_0_nimry5ra91 ((NU8)76)
#define ObjectT_0_nimry5ra91 ((NU8)106)
#define EnumT_0_nimry5ra91 ((NU8)107)
#define ProctypeT_0_nimry5ra91 ((NU8)108)
#define IT_0_nimry5ra91 ((NU8)113)
#define UT_0_nimry5ra91 ((NU8)114)
#define FT_0_nimry5ra91 ((NU8)115)
#define CT_0_nimry5ra91 ((NU8)116)
#define BoolT_0_nimry5ra91 ((NU8)117)
#define VoidT_0_nimry5ra91 ((NU8)118)
#define PtrT_0_nimry5ra91 ((NU8)119)
#define ArrayT_0_nimry5ra91 ((NU8)120)
#define VarargsT_0_nimry5ra91 ((NU8)137)
#define StaticT_0_nimry5ra91 ((NU8)163)
#define TupleT_0_nimry5ra91 ((NU8)185)
#define OnumT_0_nimry5ra91 ((NU8)186)
#define AnumT_0_nimry5ra91 ((NU8)187)
#define RefT_0_nimry5ra91 ((NU8)188)
#define MutT_0_nimry5ra91 ((NU8)189)
#define OutT_0_nimry5ra91 ((NU8)190)
#define LentT_0_nimry5ra91 ((NU8)191)
#define SinkT_0_nimry5ra91 ((NU8)192)
#define NiltT_0_nimry5ra91 ((NU8)193)
#define ConceptT_0_nimry5ra91 ((NU8)194)
#define DistinctT_0_nimry5ra91 ((NU8)195)
#define ItertypeT_0_nimry5ra91 ((NU8)196)
#define RangetypeT_0_nimry5ra91 ((NU8)197)
#define UarrayT_0_nimry5ra91 ((NU8)198)
#define SetT_0_nimry5ra91 ((NU8)199)
#define AutoT_0_nimry5ra91 ((NU8)200)
#define SymkindT_0_nimry5ra91 ((NU8)201)
#define TypekindT_0_nimry5ra91 ((NU8)202)
#define TypedescT_0_nimry5ra91 ((NU8)203)
#define UntypedT_0_nimry5ra91 ((NU8)204)
#define TypedT_0_nimry5ra91 ((NU8)205)
#define CstringT_0_nimry5ra91 ((NU8)206)
#define PointerT_0_nimry5ra91 ((NU8)207)
#define OrdinalT_0_nimry5ra91 ((NU8)208)
typedef NU8 NimonyOther_0_nimry5ra91;

#define NoSub_0_nimry5ra91 ((NU8)0)
#define NilU_0_nimry5ra91 ((NU8)9)
#define NotnilU_0_nimry5ra91 ((NU8)10)
#define UncheckedU_0_nimry5ra91 ((NU8)11)
#define KvU_0_nimry5ra91 ((NU8)30)
#define VvU_0_nimry5ra91 ((NU8)31)
#define RangeU_0_nimry5ra91 ((NU8)52)
#define RangesU_0_nimry5ra91 ((NU8)53)
#define ParamU_0_nimry5ra91 ((NU8)57)
#define TypevarU_0_nimry5ra91 ((NU8)65)
#define StaticTypevarU_0_nimry5ra91 ((NU8)66)
#define EfldU_0_nimry5ra91 ((NU8)67)
#define FldU_0_nimry5ra91 ((NU8)68)
#define GfldU_0_nimry5ra91 ((NU8)69)
#define WhenU_0_nimry5ra91 ((NU8)88)
#define ElifU_0_nimry5ra91 ((NU8)89)
#define ElseU_0_nimry5ra91 ((NU8)90)
#define TypevarsU_0_nimry5ra91 ((NU8)91)
#define CaseU_0_nimry5ra91 ((NU8)97)
#define OfU_0_nimry5ra91 ((NU8)98)
#define StmtsU_0_nimry5ra91 ((NU8)103)
#define ParamsU_0_nimry5ra91 ((NU8)104)
#define PragmasU_0_nimry5ra91 ((NU8)140)
#define EitherU_0_nimry5ra91 ((NU8)173)
#define JoinU_0_nimry5ra91 ((NU8)174)
#define UnpackflatU_0_nimry5ra91 ((NU8)178)
#define UnpacktupU_0_nimry5ra91 ((NU8)179)
#define CallargsU_0_nimry5ra91 ((NU8)180)
#define ForcallU_0_nimry5ra91 ((NU8)181)
#define ExceptU_0_nimry5ra91 ((NU8)183)
#define FinU_0_nimry5ra91 ((NU8)184)
typedef NU16 NimonyPragma_0_nimry5ra91;

#define NoPragma_0_nimry5ra91 ((NU16)0)
#define CastP_0_nimry5ra91 ((NU16)48)
#define CursorP_0_nimry5ra91 ((NU16)63)
#define EmitP_0_nimry5ra91 ((NU16)82)
#define UnionP_0_nimry5ra91 ((NU16)105)
#define InlineP_0_nimry5ra91 ((NU16)132)
#define NoinlineP_0_nimry5ra91 ((NU16)133)
#define ClosureP_0_nimry5ra91 ((NU16)134)
#define VarargsP_0_nimry5ra91 ((NU16)137)
#define SelectanyP_0_nimry5ra91 ((NU16)139)
#define AlignP_0_nimry5ra91 ((NU16)142)
#define BitsP_0_nimry5ra91 ((NU16)143)
#define NodeclP_0_nimry5ra91 ((NU16)145)
#define RaisesP_0_nimry5ra91 ((NU16)161)
#define UntypedP_0_nimry5ra91 ((NU16)204)
#define MagicP_0_nimry5ra91 ((NU16)209)
#define ImportcP_0_nimry5ra91 ((NU16)210)
#define ImportcppP_0_nimry5ra91 ((NU16)211)
#define DynlibP_0_nimry5ra91 ((NU16)212)
#define ExportcP_0_nimry5ra91 ((NU16)213)
#define HeaderP_0_nimry5ra91 ((NU16)214)
#define ThreadvarP_0_nimry5ra91 ((NU16)215)
#define GlobalP_0_nimry5ra91 ((NU16)216)
#define DiscardableP_0_nimry5ra91 ((NU16)217)
#define NoreturnP_0_nimry5ra91 ((NU16)218)
#define BorrowP_0_nimry5ra91 ((NU16)219)
#define NoSideEffectP_0_nimry5ra91 ((NU16)220)
#define NodestroyP_0_nimry5ra91 ((NU16)221)
#define PluginP_0_nimry5ra91 ((NU16)222)
#define BycopyP_0_nimry5ra91 ((NU16)223)
#define ByrefP_0_nimry5ra91 ((NU16)224)
#define NoinitP_0_nimry5ra91 ((NU16)225)
#define RequiresP_0_nimry5ra91 ((NU16)226)
#define EnsuresP_0_nimry5ra91 ((NU16)227)
#define AssumeP_0_nimry5ra91 ((NU16)228)
#define AssertP_0_nimry5ra91 ((NU16)229)
#define BuildP_0_nimry5ra91 ((NU16)230)
#define FeatureP_0_nimry5ra91 ((NU16)231)
#define StringP_0_nimry5ra91 ((NU16)232)
#define ViewP_0_nimry5ra91 ((NU16)233)
#define IncompleteStructP_0_nimry5ra91 ((NU16)234)
#define InjectP_0_nimry5ra91 ((NU16)303)
#define GensymP_0_nimry5ra91 ((NU16)304)
#define DirtyP_0_nimry5ra91 ((NU16)305)
#define ErrorP_0_nimry5ra91 ((NU16)306)
#define ReportP_0_nimry5ra91 ((NU16)307)
#define TagsP_0_nimry5ra91 ((NU16)308)
#define DeprecatedP_0_nimry5ra91 ((NU16)309)
#define SideEffectP_0_nimry5ra91 ((NU16)310)
#define KeepOverflowFlagP_0_nimry5ra91 ((NU16)311)
#define SemanticsP_0_nimry5ra91 ((NU16)312)
#define InheritableP_0_nimry5ra91 ((NU16)313)
#define BaseP_0_nimry5ra91 ((NU16)314)
#define PureP_0_nimry5ra91 ((NU16)315)
#define FinalP_0_nimry5ra91 ((NU16)316)
#define AcyclicP_0_nimry5ra91 ((NU16)317)
#define PragmaP_0_nimry5ra91 ((NU16)318)
#define PackedP_0_nimry5ra91 ((NU16)324)
#define PassiveP_0_nimry5ra91 ((NU16)325)
#define PushP_0_nimry5ra91 ((NU16)326)
#define CallConvP_0_nimry5ra91 ((NU16)327)
#define PopP_0_nimry5ra91 ((NU16)328)
#define PassLP_0_nimry5ra91 ((NU16)329)
#define PassCP_0_nimry5ra91 ((NU16)330)
#define MethodsP_0_nimry5ra91 ((NU16)331)
#define SizeP_0_nimry5ra91 ((NU16)332)
#define UncheckedAccessP_0_nimry5ra91 ((NU16)333)
#define UncheckedAssignP_0_nimry5ra91 ((NU16)334)
#define ProfilerP_0_nimry5ra91 ((NU16)335)
#define StacktraceP_0_nimry5ra91 ((NU16)336)
#define GcsafeP_0_nimry5ra91 ((NU16)337)
#define UsedP_0_nimry5ra91 ((NU16)338)
#define CompileP_0_nimry5ra91 ((NU16)339)
#define BundleP_0_nimry5ra91 ((NU16)340)
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
typedef NU16 HookKind_0_nimry5ra91;

#define NoHook_0_nimry5ra91 ((NU16)0)
#define DestroyH_0_nimry5ra91 ((NU16)289)
#define DupH_0_nimry5ra91 ((NU16)290)
#define CopyH_0_nimry5ra91 ((NU16)291)
#define WasmovedH_0_nimry5ra91 ((NU16)292)
#define SinkhH_0_nimry5ra91 ((NU16)293)
#define TraceH_0_nimry5ra91 ((NU16)294)
typedef NU8 ControlFlowKind_0_nimry5ra91;

#define NoControlFlow_0_nimry5ra91 ((NU8)0)
#define IteF_0_nimry5ra91 ((NU8)164)
#define GraphF_0_nimry5ra91 ((NU8)175)
#define ForbindF_0_nimry5ra91 ((NU8)176)
#define KillF_0_nimry5ra91 ((NU8)177)
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern LongString_0_sysvq0asl const strlit_0_I8939511674443647382_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9557201018976274010_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I186799702831424311_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3372626016653902757_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I8572766038233537570_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14042222260391466396_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7084116572891045059_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17573272885368898989_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14055597598996035090_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I10209608037894561257_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6041839086284145320_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13909093427330098489_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2501487269769466366_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I1707222714195181991_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17199005983847516849_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4196580491060784277_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14457488926480995039_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17469384850928897790_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9268166327583521131_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12337342044224817361_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17716058327968275251_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7358334719788826533_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4543393450896359795_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I710932595938440230_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9667346611828510523_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9217337746930322866_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I8390060478375454995_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I8954722698363393223_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12061648672903694946_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4161172010043268705_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3485566669610392440_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I358872489388858575_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14418907618963914168_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11512946405431690565_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13798915436014509391_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3001676635385606767_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I5323221927989235116_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12557166611382145809_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I896709357113617264_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6462229405280805082_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11168045910199617169_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17580784255599249694_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7755216903854853291_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6438757400198936067_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17286088029172964552_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I655215872312446365_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7330775407653057337_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12823858650579995313_nim30udrv;
extern LongString_0_sysvq0asl const strlit_0_I6996188409796059230_nim30udrv;
extern LongString_0_sysvq0asl const strlit_0_I10163392937326623266_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13264932728578201327_nim30udrv;
extern LongString_0_sysvq0asl const strlit_0_I14845204679832807538_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I1281801651151844468_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13046452236886743244_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12999086881046019782_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2416437014800228590_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I5723805845286553140_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7233319822780473912_nif12fhfr1;
extern LongString_0_sysvq0asl const strlit_0_I17735862253056247523_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3786558325628924612_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I5316556160589403975_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9991102891510134496_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9071657656589967445_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6864681898360807206_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6517805684605582485_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3777428167486794959_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I17987658270787974407_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9830314142150548690_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2681092370707159476_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I8380221545607033154_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2210116261907819816_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13200118161122656888_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4956278306908871092_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13752166055203769914_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7023501325319911082_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14732757010146030568_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2784804726569183623_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3312144845751804851_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I10578126245728228512_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I16948548629793503007_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6313045265747232047_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7395289177220351871_nif12fhfr1;
extern LongString_0_sysvq0asl const strlit_0_I18257730313531980409_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2956720964102846418_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6137881024046402116_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I18337270522941735704_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I15803870852433253359_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I11155032387348830029_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I3225181402180923291_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6008424852838151324_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I5595596763809202512_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14845240230376595005_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I16393544569146403439_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2984705338531181753_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I2419004569819514924_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I1016912281706840257_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I6300154543333844069_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I12905769428011359788_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I16597999082088934835_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I9792473688321036479_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I2171368188661376471_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13424873862977158440_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4167480082662538754_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14656641239204103783_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I1237672436915077942_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I16264910594287870354_comaa5xpt1;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tagygirdh1(void);
LongString_0_sysvq0asl const strlit_0_I6770022523893788160_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NoExpr"}
;
LongString_0_sysvq0asl const strlit_0_I6690414846038512979_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "alignof"}
;
LongString_0_sysvq0asl const strlit_0_I16910581458008155537_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "offsetof"}
;
LongString_0_sysvq0asl const strlit_0_I14293528690183020870_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "curlyat"}
;
LongString_0_sysvq0asl const strlit_0_I12320098920117258102_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitand"}
;
LongString_0_sysvq0asl const strlit_0_I8344472873800577395_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitor"}
;
LongString_0_sysvq0asl const strlit_0_I1868900624481666580_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitxor"}
;
LongString_0_sysvq0asl const strlit_0_I7132977312474535290_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cchoice"}
;
LongString_0_sysvq0asl const strlit_0_I7981495708050792894_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ochoice"}
;
LongString_0_sysvq0asl const strlit_0_I1290833423478922541_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "quoted"}
;
LongString_0_sysvq0asl const strlit_0_I16361658452647583931_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tabconstr"}
;
LongString_0_sysvq0asl const strlit_0_I4333440046835585584_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ashr"}
;
LongString_0_sysvq0asl const strlit_0_I15519800790444264650_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "compiles"}
;
LongString_0_sysvq0asl const strlit_0_I11246488655541728238_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "declared"}
;
LongString_0_sysvq0asl const strlit_0_I15630474019274232734_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "defined"}
;
LongString_0_sysvq0asl const strlit_0_I8057664036378742595_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "astToStr"}
;
LongString_0_sysvq0asl const strlit_0_I3906464809106688102_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bindSym"}
;
LongString_0_sysvq0asl const strlit_0_I7173319946579796093_nimry5ra91 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bindSymName"}
;
LongString_0_sysvq0asl const strlit_0_I8566804573867139999_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "high"}
;
LongString_0_sysvq0asl const strlit_0_I15370501250081784507_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typeof"}
;
LongString_0_sysvq0asl const strlit_0_I17316263578118871722_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unpack"}
;
LongString_0_sysvq0asl const strlit_0_I11931178963942483173_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fields"}
;
LongString_0_sysvq0asl const strlit_0_I5007098554778156607_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fieldpairs"}
;
LongString_0_sysvq0asl const strlit_0_I6307085774546006824_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "enumtostr"}
;
LongString_0_sysvq0asl const strlit_0_I15215329021599148827_nimry5ra91 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ismainmodule"}
;
LongString_0_sysvq0asl const strlit_0_I2499004453702072445_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "defaultobj"}
;
LongString_0_sysvq0asl const strlit_0_I10155087370267137835_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "defaulttup"}
;
LongString_0_sysvq0asl const strlit_0_I5057369592842021125_nimry5ra91 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "defaultdistinct"}
;
LongString_0_sysvq0asl const strlit_0_I12773303473659224661_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sinkh"}
;
LongString_0_sysvq0asl const strlit_0_I6548618541054097076_nimry5ra91 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "internalTypeName"}
;
LongString_0_sysvq0asl const strlit_0_I17367998397186134261_nimry5ra91 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "internalFieldPairs"}
;
LongString_0_sysvq0asl const strlit_0_I1529704942889178144_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "envp"}
;
LongString_0_sysvq0asl const strlit_0_I10191413032959885349_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "toClosure"}
;
LongString_0_sysvq0asl const strlit_0_I4969208532963544146_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NoStmt"}
;
LongString_0_sysvq0asl const strlit_0_I1572551130627868563_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "emit"}
;
LongString_0_sysvq0asl const strlit_0_I110166545589372112_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "scope"}
;
LongString_0_sysvq0asl const strlit_0_I14781640258047403316_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "when"}
;
LongString_0_sysvq0asl const strlit_0_I10030898066311664679_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "corofor"}
;
LongString_0_sysvq0asl const strlit_0_I9191034391941917241_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importas"}
;
LongString_0_sysvq0asl const strlit_0_I3199637833187763350_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fromimport"}
;
LongString_0_sysvq0asl const strlit_0_I7731358638274129439_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unpackdecl"}
;
LongString_0_sysvq0asl const strlit_0_I4604789051338433811_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "assume"}
;
LongString_0_sysvq0asl const strlit_0_I12559108835900458521_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "assert"}
;
LongString_0_sysvq0asl const strlit_0_I4843651051758684618_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "staticstmt"}
;
LongString_0_sysvq0asl const strlit_0_I6669728318263290480_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mixin"}
;
LongString_0_sysvq0asl const strlit_0_I4167773820130397069_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "defer"}
;
LongString_0_sysvq0asl const strlit_0_I5260123237436279273_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NoType"}
;
LongString_0_sysvq0asl const strlit_0_I1995551610468546737_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proctype"}
;
LongString_0_sysvq0asl const strlit_0_I14150474136931533575_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "varargs"}
;
LongString_0_sysvq0asl const strlit_0_I17569086427026686584_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static"}
;
LongString_0_sysvq0asl const strlit_0_I12023767949489687491_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "anum"}
;
LongString_0_sysvq0asl const strlit_0_I2544717250931810611_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "concept"}
;
LongString_0_sysvq0asl const strlit_0_I15938251790995683266_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "itertype"}
;
LongString_0_sysvq0asl const strlit_0_I8265071425581872233_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "symkind"}
;
LongString_0_sysvq0asl const strlit_0_I567478400955764617_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typekind"}
;
LongString_0_sysvq0asl const strlit_0_I13460298547546882036_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedesc"}
;
LongString_0_sysvq0asl const strlit_0_I9456292052054236016_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typed"}
;
LongString_0_sysvq0asl const strlit_0_I6616374312433163100_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ordinal"}
;
LongString_0_sysvq0asl const strlit_0_I4902053646279049009_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NoSub"}
;
LongString_0_sysvq0asl const strlit_0_I1477227973970526752_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unchecked"}
;
LongString_0_sysvq0asl const strlit_0_I10760563625686142994_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ranges"}
;
LongString_0_sysvq0asl const strlit_0_I3759916806223351059_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typevar"}
;
LongString_0_sysvq0asl const strlit_0_I15385401366416332649_nimry5ra91 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "staticTypevar"}
;
LongString_0_sysvq0asl const strlit_0_I17496857845421750549_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gfld"}
;
LongString_0_sysvq0asl const strlit_0_I5367917178860180580_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "params"}
;
LongString_0_sysvq0asl const strlit_0_I18223875966347257259_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "either"}
;
LongString_0_sysvq0asl const strlit_0_I7603755693199836480_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "join"}
;
LongString_0_sysvq0asl const strlit_0_I13179338205702368459_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unpackflat"}
;
LongString_0_sysvq0asl const strlit_0_I11688738934238820917_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callargs"}
;
LongString_0_sysvq0asl const strlit_0_I2573631453468209738_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "forcall"}
;
LongString_0_sysvq0asl const strlit_0_I3302612697625453930_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "union"}
;
LongString_0_sysvq0asl const strlit_0_I9300717802679998862_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "noinline"}
;
LongString_0_sysvq0asl const strlit_0_I2120471692824576765_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "selectany"}
;
LongString_0_sysvq0asl const strlit_0_I3912769065629684841_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "align"}
;
LongString_0_sysvq0asl const strlit_0_I4965478555169759111_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bits"}
;
LongString_0_sysvq0asl const strlit_0_I9354196862430236195_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nodecl"}
;
LongString_0_sysvq0asl const strlit_0_I10609090264569208189_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "raises"}
;
LongString_0_sysvq0asl const strlit_0_I15788046494547023735_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "magic"}
;
LongString_0_sysvq0asl const strlit_0_I3957309170640276402_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importc"}
;
LongString_0_sysvq0asl const strlit_0_I6761535509221812916_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importcpp"}
;
LongString_0_sysvq0asl const strlit_0_I4382311971321061249_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dynlib"}
;
LongString_0_sysvq0asl const strlit_0_I4862850237857511107_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "exportc"}
;
LongString_0_sysvq0asl const strlit_0_I11401871840194716403_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "threadvar"}
;
LongString_0_sysvq0asl const strlit_0_I5696226971518331620_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "global"}
;
LongString_0_sysvq0asl const strlit_0_I1655448968826648425_nimry5ra91 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "discardable"}
;
LongString_0_sysvq0asl const strlit_0_I14428456701869004983_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "noreturn"}
;
LongString_0_sysvq0asl const strlit_0_I14004803080881083620_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "borrow"}
;
LongString_0_sysvq0asl const strlit_0_I113550637689326195_nimry5ra91 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "noSideEffect"}
;
LongString_0_sysvq0asl const strlit_0_I8745041498576622223_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nodestroy"}
;
LongString_0_sysvq0asl const strlit_0_I757997984781066323_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "plugin"}
;
LongString_0_sysvq0asl const strlit_0_I4859700805551129371_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bycopy"}
;
LongString_0_sysvq0asl const strlit_0_I17285089853291426062_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "byref"}
;
LongString_0_sysvq0asl const strlit_0_I3179792478750962635_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "noinit"}
;
LongString_0_sysvq0asl const strlit_0_I16730393376288644638_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "requires"}
;
LongString_0_sysvq0asl const strlit_0_I5451065444311437237_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ensures"}
;
LongString_0_sysvq0asl const strlit_0_I4207864124720532554_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "feature"}
;
LongString_0_sysvq0asl const strlit_0_I17993691144359452798_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "view"}
;
LongString_0_sysvq0asl const strlit_0_I3557287941175077387_nimry5ra91 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "incompleteStruct"}
;
LongString_0_sysvq0asl const strlit_0_I15673079640947746121_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inject"}
;
LongString_0_sysvq0asl const strlit_0_I18017358057866442883_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gensym"}
;
LongString_0_sysvq0asl const strlit_0_I694217339896490792_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dirty"}
;
LongString_0_sysvq0asl const strlit_0_I15516388950515943933_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "error"}
;
LongString_0_sysvq0asl const strlit_0_I15352605387219570985_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "report"}
;
LongString_0_sysvq0asl const strlit_0_I57893748219682234_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tags"}
;
LongString_0_sysvq0asl const strlit_0_I7770279929706659123_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "deprecated"}
;
LongString_0_sysvq0asl const strlit_0_I6214469262558903647_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sideEffect"}
;
LongString_0_sysvq0asl const strlit_0_I4798194433225830700_nimry5ra91 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "semantics"}
;
LongString_0_sysvq0asl const strlit_0_I13657782612448101767_nimry5ra91 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inheritable"}
;
LongString_0_sysvq0asl const strlit_0_I7138112740281612668_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "base"}
;
LongString_0_sysvq0asl const strlit_0_I3788100829446300327_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pure"}
;
LongString_0_sysvq0asl const strlit_0_I6579479052981869920_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "final"}
;
LongString_0_sysvq0asl const strlit_0_I6244821402565232963_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "acyclic"}
;
LongString_0_sysvq0asl const strlit_0_I18424387959777996651_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pragma"}
;
LongString_0_sysvq0asl const strlit_0_I17844812131497141662_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "packed"}
;
LongString_0_sysvq0asl const strlit_0_I13747405705720498495_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "push"}
;
LongString_0_sysvq0asl const strlit_0_I16441971418298468310_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callConv"}
;
LongString_0_sysvq0asl const strlit_0_I12645659207852971310_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "passL"}
;
LongString_0_sysvq0asl const strlit_0_I10542467331015004416_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "passC"}
;
LongString_0_sysvq0asl const strlit_0_I17913492178188134841_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "methods"}
;
LongString_0_sysvq0asl const strlit_0_I6332049561104653135_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "size"}
;
LongString_0_sysvq0asl const strlit_0_I5677487675071849914_nimry5ra91 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uncheckedAccess"}
;
LongString_0_sysvq0asl const strlit_0_I658303038766644256_nimry5ra91 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uncheckedAssign"}
;
LongString_0_sysvq0asl const strlit_0_I16836303070383946558_nimry5ra91 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "profiler"}
;
LongString_0_sysvq0asl const strlit_0_I17551943502627385610_nimry5ra91 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stacktrace"}
;
LongString_0_sysvq0asl const strlit_0_I17279576536099861747_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gcsafe"}
;
LongString_0_sysvq0asl const strlit_0_I14680152901758819216_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "used"}
;
LongString_0_sysvq0asl const strlit_0_I8457648535047856405_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "compile"}
;
LongString_0_sysvq0asl const strlit_0_I15358474783062118651_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NoSym"}
;
LongString_0_sysvq0asl const strlit_0_I6605162211648777506_nimry5ra91 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "module"}
;
LongString_0_sysvq0asl const strlit_0_I6285446155132737146_nimry5ra91 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "graph"}
;
LongString_0_sysvq0asl const strlit_0_I16485414215621593826_nimry5ra91 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "forbind"}
;
LongString_0_sysvq0asl const strlit_0_I10406234210653353301_nimry5ra91 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "kill"}
;
NB8 X60QiniGuard_0_nimry5ra91;
string_0_sysvq0asl dollarX60Q_NimonyExpr_0_nimry5ra91(NimonyExpr_0_nimry5ra91 e_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  switch (e_0){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1164922622u, .more_0 = (&strlit_0_I6770022523893788160_nimry5ra91)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920099587u, .more_0 = NIM_NIL}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1718973187u, .more_0 = NIM_NIL}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7627010u, .more_0 = NIM_NIL}
      ;}
    break;
    case 4:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_comaa5xpt1)}
      ;}
    break;
    case 5:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
      ;}
    break;
    case 6:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
      ;}
    break;
    case 7:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918988291u, .more_0 = NIM_NIL}
      ;}
    break;
    case 8:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684300286u, .more_0 = (&strlit_0_I9557201018976274010_comaa5xpt1)}
      ;}
    break;
    case 9:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
      ;}
    break;
    case 12:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1718511875u, .more_0 = NIM_NIL}
      ;}
    break;
    case 13:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1734700798u, .more_0 = (&strlit_0_I186799702831424311_comaa5xpt1)}
      ;}
    break;
    case 14:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1851878915u, .more_0 = NIM_NIL}
      ;}
    break;
    case 15:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_comaa5xpt1)}
      ;}
    break;
    case 16:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_comaa5xpt1)}
      ;}
    break;
    case 17:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684955395u, .more_0 = NIM_NIL}
      ;}
    break;
    case 18:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7499522u, .more_0 = NIM_NIL}
      ;}
    break;
    case 19:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919907843u, .more_0 = NIM_NIL}
      ;}
    break;
    case 20:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953459715u, .more_0 = NIM_NIL}
      ;}
    break;
    case 21:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1734700547u, .more_0 = NIM_NIL}
      ;}
    break;
    case 22:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I14042222260391466396_comaa5xpt1)}
      ;}
    break;
    case 23:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768710654u, .more_0 = (&strlit_0_I6690414846038512979_nimry5ra91)}
      ;}
    break;
    case 24:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717989374u, .more_0 = (&strlit_0_I16910581458008155537_nimry5ra91)}
      ;}
    break;
    case 25:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_comaa5xpt1)}
      ;}
    break;
    case 26:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_comaa5xpt1)}
      ;}
    break;
    case 27:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634886398u, .more_0 = (&strlit_0_I14055597598996035090_comaa5xpt1)}
      ;}
    break;
    case 28:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I10209608037894561257_comaa5xpt1)}
      ;}
    break;
    case 29:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I14293528690183020870_nimry5ra91)}
      ;}
    break;
    case 30:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7760642u, .more_0 = NIM_NIL}
      ;}
    break;
    case 32:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1719037699u, .more_0 = NIM_NIL}
      ;}
    break;
    case 33:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
      ;}
    break;
    case 34:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1651864323u, .more_0 = NIM_NIL}
      ;}
    break;
    case 35:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1819634947u, .more_0 = NIM_NIL}
      ;}
    break;
    case 36:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1986618371u, .more_0 = NIM_NIL}
      ;}
    break;
    case 37:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
      ;}
    break;
    case 38:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919447811u, .more_0 = NIM_NIL}
      ;}
    break;
    case 39:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818784515u, .more_0 = NIM_NIL}
      ;}
    break;
    case 40:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I12320098920117258102_nimry5ra91)}
      ;}
    break;
    case 41:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I8344472873800577395_nimry5ra91)}
      ;}
    break;
    case 42:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I1868900624481666580_nimry5ra91)}
      ;}
    break;
    case 43:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I6041839086284145320_comaa5xpt1)}
      ;}
    break;
    case 44:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7431426u, .more_0 = NIM_NIL}
      ;}
    break;
    case 45:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1902472707u, .more_0 = NIM_NIL}
      ;}
    break;
    case 46:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 6646786u, .more_0 = NIM_NIL}
      ;}
    break;
    case 47:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7629826u, .more_0 = NIM_NIL}
      ;}
    break;
    case 48:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_comaa5xpt1)}
      ;}
    break;
    case 49:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_comaa5xpt1)}
      ;}
    break;
    case 50:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_comaa5xpt1)}
      ;}
    break;
    case 51:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
      ;}
    break;
    case 80:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1751344126u, .more_0 = (&strlit_0_I7132977312474535290_nimry5ra91)}
      ;}
    break;
    case 81:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1751347198u, .more_0 = (&strlit_0_I7981495708050792894_nimry5ra91)}
      ;}
    break;
    case 141:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I17199005983847516849_comaa5xpt1)}
      ;}
    break;
    case 235:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869967870u, .more_0 = (&strlit_0_I1290833423478922541_nimry5ra91)}
      ;}
    break;
    case 236:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
      ;}
    break;
    case 237:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_comaa5xpt1)}
      ;}
    break;
    case 238:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684105470u, .more_0 = (&strlit_0_I17469384850928897790_comaa5xpt1)}
      ;}
    break;
    case 239:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I9268166327583521131_comaa5xpt1)}
      ;}
    break;
    case 240:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I12337342044224817361_comaa5xpt1)}
      ;}
    break;
    case 241:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886745603u, .more_0 = NIM_NIL}
      ;}
    break;
    case 242:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I17716058327968275251_comaa5xpt1)}
      ;}
    break;
    case 243:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I7358334719788826533_comaa5xpt1)}
      ;}
    break;
    case 244:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1650554110u, .more_0 = (&strlit_0_I16361658452647583931_nimry5ra91)}
      ;}
    break;
    case 245:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1752392190u, .more_0 = (&strlit_0_I4333440046835585584_nimry5ra91)}
      ;}
    break;
    case 246:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1935762174u, .more_0 = (&strlit_0_I4543393450896359795_comaa5xpt1)}
      ;}
    break;
    case 247:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_comaa5xpt1)}
      ;}
    break;
    case 248:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868784894u, .more_0 = (&strlit_0_I9667346611828510523_comaa5xpt1)}
      ;}
    break;
    case 249:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_comaa5xpt1)}
      ;}
    break;
    case 250:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_comaa5xpt1)}
      ;}
    break;
    case 251:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_comaa5xpt1)}
      ;}
    break;
    case 252:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_comaa5xpt1)}
      ;}
    break;
    case 253:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I15519800790444264650_nimry5ra91)}
      ;}
    break;
    case 254:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1667589374u, .more_0 = (&strlit_0_I11246488655541728238_nimry5ra91)}
      ;}
    break;
    case 255:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I15630474019274232734_nimry5ra91)}
      ;}
    break;
    case 256:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953718782u, .more_0 = (&strlit_0_I8057664036378742595_nimry5ra91)}
      ;}
    break;
    case 257:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I3906464809106688102_nimry5ra91)}
      ;}
    break;
    case 258:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I7173319946579796093_nimry5ra91)}
      ;}
    break;
    case 259:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I4161172010043268705_comaa5xpt1)}
      ;}
    break;
    case 260:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I3485566669610392440_comaa5xpt1)}
      ;}
    break;
    case 261:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1734961406u, .more_0 = (&strlit_0_I8566804573867139999_nimry5ra91)}
      ;}
    break;
    case 262:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2003790851u, .more_0 = NIM_NIL}
      ;}
    break;
    case 263:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I15370501250081784507_nimry5ra91)}
      ;}
    break;
    case 264:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I17316263578118871722_nimry5ra91)}
      ;}
    break;
    case 265:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I11931178963942483173_nimry5ra91)}
      ;}
    break;
    case 266:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I5007098554778156607_nimry5ra91)}
      ;}
    break;
    case 267:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I6307085774546006824_nimry5ra91)}
      ;}
    break;
    case 268:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836280318u, .more_0 = (&strlit_0_I15215329021599148827_nimry5ra91)}
      ;}
    break;
    case 269:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I2499004453702072445_nimry5ra91)}
      ;}
    break;
    case 270:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I10155087370267137835_nimry5ra91)}
      ;}
    break;
    case 271:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I5057369592842021125_nimry5ra91)}
      ;}
    break;
    case 272:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I358872489388858575_comaa5xpt1)}
      ;}
    break;
    case 273:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I14418907618963914168_comaa5xpt1)}
      ;}
    break;
    case 274:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1937077246u, .more_0 = (&strlit_0_I11512946405431690565_comaa5xpt1)}
      ;}
    break;
    case 275:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I13798915436014509391_comaa5xpt1)}
      ;}
    break;
    case 276:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7300098u, .more_0 = NIM_NIL}
      ;}
    break;
    case 277:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
      ;}
    break;
    case 278:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I5323221927989235116_comaa5xpt1)}
      ;}
    break;
    case 279:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970041086u, .more_0 = (&strlit_0_I12557166611382145809_comaa5xpt1)}
      ;}
    break;
    case 280:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852403198u, .more_0 = (&strlit_0_I896709357113617264_comaa5xpt1)}
      ;}
    break;
    case 281:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1819635198u, .more_0 = (&strlit_0_I6462229405280805082_comaa5xpt1)}
      ;}
    break;
    case 282:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919908094u, .more_0 = (&strlit_0_I11168045910199617169_comaa5xpt1)}
      ;}
    break;
    case 283:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936811518u, .more_0 = (&strlit_0_I17580784255599249694_comaa5xpt1)}
      ;}
    break;
    case 284:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936026878u, .more_0 = (&strlit_0_I7755216903854853291_comaa5xpt1)}
      ;}
    break;
    case 285:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1937009918u, .more_0 = (&strlit_0_I6438757400198936067_comaa5xpt1)}
      ;}
    break;
    case 286:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I17286088029172964552_comaa5xpt1)}
      ;}
    break;
    case 287:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918985214u, .more_0 = (&strlit_0_I655215872312446365_comaa5xpt1)}
      ;}
    break;
    case 288:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869440510u, .more_0 = (&strlit_0_I7330775407653057337_comaa5xpt1)}
      ;}
    break;
    case 289:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936024830u, .more_0 = (&strlit_0_I12823858650579995313_nim30udrv)}
      ;}
    break;
    case 290:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886741507u, .more_0 = NIM_NIL}
      ;}
    break;
    case 291:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I6996188409796059230_nim30udrv)}
      ;}
    break;
    case 292:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1935767550u, .more_0 = (&strlit_0_I10163392937326623266_comaa5xpt1)}
      ;}
    break;
    case 293:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I12773303473659224661_nimry5ra91)}
      ;}
    break;
    case 294:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634891006u, .more_0 = (&strlit_0_I13264932728578201327_nim30udrv)}
      ;}
    break;
    case 319:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I6548618541054097076_nimry5ra91)}
      ;}
    break;
    case 320:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I17367998397186134261_nimry5ra91)}
      ;}
    break;
    case 321:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1767991038u, .more_0 = (&strlit_0_I14845204679832807538_comaa5xpt1)}
      ;}
    break;
    case 322:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7563522u, .more_0 = NIM_NIL}
      ;}
    break;
    case 323:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1986946558u, .more_0 = (&strlit_0_I1529704942889178144_nimry5ra91)}
      ;}
    break;
    case 341:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131377918u, .more_0 = (&strlit_0_I10191413032959885349_nimry5ra91)}
      ;}
    break;}
  return result_0;}
static inline NB8 rawTagIsNimonyExpr_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_0){
  NB8 result_1;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      254u, 243u, 255u, 127u, 255u, 255u, 15u, 0u, 0u, 0u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 32u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 248u, 255u, 255u, 255u, 255u, 255u, 255u, 127u, 0u, 0u, 128u, 15u, 0u, 32u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)raw_0);
  result_1 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u);
  return result_1;}
string_0_sysvq0asl dollarX60Q_NimonyStmt_0_nimry5ra91(NimonyStmt_0_nimry5ra91 e_1){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  switch (e_1){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399803646u, .more_0 = (&strlit_0_I4969208532963544146_nimry5ra91)}
      ;}
    break;
    case 50:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_comaa5xpt1)}
      ;}
    break;
    case 51:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
      ;}
    break;
    case 54:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
      ;}
    break;
    case 55:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_comaa5xpt1)}
      ;}
    break;
    case 56:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
      ;}
    break;
    case 58:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_comaa5xpt1)}
      ;}
    break;
    case 59:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936028414u, .more_0 = (&strlit_0_I2416437014800228590_comaa5xpt1)}
      ;}
    break;
    case 60:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
      ;}
    break;
    case 61:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701606654u, .more_0 = (&strlit_0_I7233319822780473912_nif12fhfr1)}
      ;}
    break;
    case 62:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
      ;}
    break;
    case 63:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
      ;}
    break;
    case 64:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952542974u, .more_0 = (&strlit_0_I3786558325628924612_comaa5xpt1)}
      ;}
    break;
    case 70:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_comaa5xpt1)}
      ;}
    break;
    case 71:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_comaa5xpt1)}
      ;}
    break;
    case 72:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I9071657656589967445_comaa5xpt1)}
      ;}
    break;
    case 73:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I6864681898360807206_comaa5xpt1)}
      ;}
    break;
    case 74:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
      ;}
    break;
    case 75:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1667329534u, .more_0 = (&strlit_0_I3777428167486794959_comaa5xpt1)}
      ;}
    break;
    case 76:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1835365630u, .more_0 = (&strlit_0_I17987658270787974407_comaa5xpt1)}
      ;}
    break;
    case 77:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      ;}
    break;
    case 78:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869374206u, .more_0 = (&strlit_0_I9830314142150548690_comaa5xpt1)}
      ;}
    break;
    case 82:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768777214u, .more_0 = (&strlit_0_I1572551130627868563_nimry5ra91)}
      ;}
    break;
    case 83:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1735614974u, .more_0 = (&strlit_0_I2681092370707159476_comaa5xpt1)}
      ;}
    break;
    case 86:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1868788734u, .more_0 = (&strlit_0_I110166545589372112_nimry5ra91)}
      ;}
    break;
    case 87:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 6711554u, .more_0 = NIM_NIL}
      ;}
    break;
    case 88:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701345278u, .more_0 = (&strlit_0_I14781640258047403316_nimry5ra91)}
      ;}
    break;
    case 92:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701995262u, .more_0 = (&strlit_0_I8380221545607033154_comaa5xpt1)}
      ;}
    break;
    case 93:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2210116261907819816_comaa5xpt1)}
      ;}
    break;
    case 94:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919903235u, .more_0 = NIM_NIL}
      ;}
    break;
    case 95:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I13200118161122656888_comaa5xpt1)}
      ;}
    break;
    case 96:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919902718u, .more_0 = (&strlit_0_I10030898066311664679_nimry5ra91)}
      ;}
    break;
    case 97:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
      ;}
    break;
    case 101:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952805379u, .more_0 = NIM_NIL}
      ;}
    break;
    case 102:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684830467u, .more_0 = NIM_NIL}
      ;}
    break;
    case 103:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
      ;}
    break;
    case 140:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
      ;}
    break;
    case 141:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I17199005983847516849_comaa5xpt1)}
      ;}
    break;
    case 146:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I14732757010146030568_comaa5xpt1)}
      ;}
    break;
    case 147:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1668834814u, .more_0 = (&strlit_0_I2784804726569183623_comaa5xpt1)}
      ;}
    break;
    case 148:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I3312144845751804851_comaa5xpt1)}
      ;}
    break;
    case 149:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I10578126245728228512_comaa5xpt1)}
      ;}
    break;
    case 150:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I9191034391941917241_nimry5ra91)}
      ;}
    break;
    case 151:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869768446u, .more_0 = (&strlit_0_I3199637833187763350_nimry5ra91)}
      ;}
    break;
    case 152:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I16948548629793503007_comaa5xpt1)}
      ;}
    break;
    case 153:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I6313045265747232047_comaa5xpt1)}
      ;}
    break;
    case 155:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I7395289177220351871_nif12fhfr1)}
      ;}
    break;
    case 156:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I18257730313531980409_comaa5xpt1)}
      ;}
    break;
    case 157:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I2956720964102846418_comaa5xpt1)}
      ;}
    break;
    case 158:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2037543939u, .more_0 = NIM_NIL}
      ;}
    break;
    case 159:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1767994110u, .more_0 = (&strlit_0_I6137881024046402116_comaa5xpt1)}
      ;}
    break;
    case 182:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I7731358638274129439_nimry5ra91)}
      ;}
    break;
    case 228:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936941566u, .more_0 = (&strlit_0_I4604789051338433811_nimry5ra91)}
      ;}
    break;
    case 229:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936941566u, .more_0 = (&strlit_0_I12559108835900458521_nimry5ra91)}
      ;}
    break;
    case 249:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_comaa5xpt1)}
      ;}
    break;
    case 250:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_comaa5xpt1)}
      ;}
    break;
    case 251:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_comaa5xpt1)}
      ;}
    break;
    case 252:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_comaa5xpt1)}
      ;}
    break;
    case 296:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I4843651051758684618_nimry5ra91)}
      ;}
    break;
    case 297:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I18337270522941735704_iop7yt73v)}
      ;}
    break;
    case 298:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2020175358u, .more_0 = (&strlit_0_I6669728318263290480_nimry5ra91)}
      ;}
    break;
    case 299:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1769174526u, .more_0 = (&strlit_0_I15803870852433253359_comaa5xpt1)}
      ;}
    break;
    case 300:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836278019u, .more_0 = NIM_NIL}
      ;}
    break;
    case 301:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I4167773820130397069_nimry5ra91)}
      ;}
    break;}
  return result_2;}
static inline NB8 rawTagIsNimonyStmt_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_1){
  NB8 result_3;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 204u, 253u, 193u, 127u, 204u, 241u, 227u, 0u, 0u, 0u, 0u, 48u, 252u, 251u, 0u, 0u, 64u, 0u, 0u, 0u, 0u, 0u, 48u, 0u, 0u, 30u, 0u, 0u, 0u, 0u, 0u, 63u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_3 = ((NU)raw_1);
  result_3 = (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u);
  return result_3;}
string_0_sysvq0asl dollarX60Q_NimonyType_0_nimry5ra91(NimonyType_0_nimry5ra91 e_2){
  string_0_sysvq0asl result_4;
  nimStrWasMoved((&result_4));
  switch (e_2){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1416580862u, .more_0 = (&strlit_0_I5260123237436279273_nimry5ra91)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920099587u, .more_0 = NIM_NIL}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7627010u, .more_0 = NIM_NIL}
      ;}
    break;
    case 17:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684955395u, .more_0 = NIM_NIL}
      ;}
    break;
    case 18:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7499522u, .more_0 = NIM_NIL}
      ;}
    break;
    case 20:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953459715u, .more_0 = NIM_NIL}
      ;}
    break;
    case 70:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_comaa5xpt1)}
      ;}
    break;
    case 71:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_comaa5xpt1)}
      ;}
    break;
    case 72:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I9071657656589967445_comaa5xpt1)}
      ;}
    break;
    case 73:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I6864681898360807206_comaa5xpt1)}
      ;}
    break;
    case 74:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
      ;}
    break;
    case 75:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1667329534u, .more_0 = (&strlit_0_I3777428167486794959_comaa5xpt1)}
      ;}
    break;
    case 76:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1835365630u, .more_0 = (&strlit_0_I17987658270787974407_comaa5xpt1)}
      ;}
    break;
    case 106:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
      ;}
    break;
    case 107:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
      ;}
    break;
    case 108:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I1995551610468546737_nimry5ra91)}
      ;}
    break;
    case 113:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      ;}
    break;
    case 114:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 29953u, .more_0 = NIM_NIL}
      ;}
    break;
    case 115:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      ;}
    break;
    case 116:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 25345u, .more_0 = NIM_NIL}
      ;}
    break;
    case 117:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
      ;}
    break;
    case 118:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_buiyylk1h1)}
      ;}
    break;
    case 119:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      ;}
    break;
    case 120:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
      ;}
    break;
    case 137:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I14150474136931533575_nimry5ra91)}
      ;}
    break;
    case 163:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I17569086427026686584_nimry5ra91)}
      ;}
    break;
    case 185:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
      ;}
    break;
    case 186:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
      ;}
    break;
    case 187:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1970168318u, .more_0 = (&strlit_0_I12023767949489687491_nimry5ra91)}
      ;}
    break;
    case 188:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      ;}
    break;
    case 189:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
      ;}
    break;
    case 190:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
      ;}
    break;
    case 191:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852140798u, .more_0 = (&strlit_0_I6008424852838151324_comaa5xpt1)}
      ;}
    break;
    case 192:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_comaa5xpt1)}
      ;}
    break;
    case 193:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I14845240230376595005_buiyylk1h1)}
      ;}
    break;
    case 194:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2544717250931810611_nimry5ra91)}
      ;}
    break;
    case 195:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
      ;}
    break;
    case 196:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I15938251790995683266_nimry5ra91)}
      ;}
    break;
    case 197:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_comaa5xpt1)}
      ;}
    break;
    case 198:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918989822u, .more_0 = (&strlit_0_I2984705338531181753_buiyylk1h1)}
      ;}
    break;
    case 199:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
      ;}
    break;
    case 200:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953849854u, .more_0 = (&strlit_0_I2419004569819514924_buiyylk1h1)}
      ;}
    break;
    case 201:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836676094u, .more_0 = (&strlit_0_I8265071425581872233_nimry5ra91)}
      ;}
    break;
    case 202:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I567478400955764617_nimry5ra91)}
      ;}
    break;
    case 203:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13460298547546882036_nimry5ra91)}
      ;}
    break;
    case 204:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953396222u, .more_0 = (&strlit_0_I1016912281706840257_buiyylk1h1)}
      ;}
    break;
    case 205:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I9456292052054236016_nimry5ra91)}
      ;}
    break;
    case 206:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
      ;}
    break;
    case 207:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_comaa5xpt1)}
      ;}
    break;
    case 208:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1685221374u, .more_0 = (&strlit_0_I6616374312433163100_nimry5ra91)}
      ;}
    break;}
  return result_4;}
static inline NB8 rawTagIsNimonyType_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_2){
  NB8 result_5;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_4 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      10u, 0u, 22u, 0u, 0u, 0u, 0u, 0u, 192u, 31u, 0u, 0u, 0u, 28u, 254u, 1u, 0u, 2u, 0u, 0u, 8u, 0u, 0u, 254u, 255u, 255u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_5 = ((NU)raw_2);
  result_5 = (((NU8)(X60Qdesugar_4.a[((NU)(X60Qdesugar_5 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_5 & 7u)))))) != 0u);
  return result_5;}
string_0_sysvq0asl dollarX60Q_NimonyOther_0_nimry5ra91(NimonyOther_0_nimry5ra91 e_3){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  switch (e_3){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399803646u, .more_0 = (&strlit_0_I4902053646279049009_nimry5ra91)}
      ;}
    break;
    case 9:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
      ;}
    break;
    case 10:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953459966u, .more_0 = (&strlit_0_I12905769428011359788_buiyylk1h1)}
      ;}
    break;
    case 11:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1668183550u, .more_0 = (&strlit_0_I1477227973970526752_nimry5ra91)}
      ;}
    break;
    case 30:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7760642u, .more_0 = NIM_NIL}
      ;}
    break;
    case 31:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 7763458u, .more_0 = NIM_NIL}
      ;}
    break;
    case 52:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_comaa5xpt1)}
      ;}
    break;
    case 53:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I10760563625686142994_nimry5ra91)}
      ;}
    break;
    case 57:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_comaa5xpt1)}
      ;}
    break;
    case 65:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3759916806223351059_nimry5ra91)}
      ;}
    break;
    case 66:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I15385401366416332649_nimry5ra91)}
      ;}
    break;
    case 67:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
      ;}
    break;
    case 68:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
      ;}
    break;
    case 69:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818650622u, .more_0 = (&strlit_0_I17496857845421750549_nimry5ra91)}
      ;}
    break;
    case 88:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701345278u, .more_0 = (&strlit_0_I14781640258047403316_nimry5ra91)}
      ;}
    break;
    case 89:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768711678u, .more_0 = (&strlit_0_I13424873862977158440_comaa5xpt1)}
      ;}
    break;
    case 90:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
      ;}
    break;
    case 91:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I14656641239204103783_fiepkwzpc)}
      ;}
    break;
    case 97:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
      ;}
    break;
    case 98:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 6713090u, .more_0 = NIM_NIL}
      ;}
    break;
    case 103:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
      ;}
    break;
    case 104:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_nimry5ra91)}
      ;}
    break;
    case 140:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
      ;}
    break;
    case 173:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953064446u, .more_0 = (&strlit_0_I18223875966347257259_nimry5ra91)}
      ;}
    break;
    case 174:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1768909566u, .more_0 = (&strlit_0_I7603755693199836480_nimry5ra91)}
      ;}
    break;
    case 178:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I13179338205702368459_nimry5ra91)}
      ;}
    break;
    case 179:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I1237672436915077942_comaa5xpt1)}
      ;}
    break;
    case 180:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I11688738934238820917_nimry5ra91)}
      ;}
    break;
    case 181:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I2573631453468209738_nimry5ra91)}
      ;}
    break;
    case 183:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1668834814u, .more_0 = (&strlit_0_I16264910594287870354_comaa5xpt1)}
      ;}
    break;
    case 184:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852401155u, .more_0 = NIM_NIL}
      ;}
    break;}
  return result_6;}
static inline NB8 rawTagIsNimonyOther_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_3){
  NB8 result_7;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 14u, 0u, 192u, 0u, 0u, 48u, 2u, 62u, 0u, 0u, 15u, 134u, 1u, 0u, 0u, 0u, 16u, 0u, 0u, 0u, 96u, 188u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_7 = ((NU)raw_3);
  result_7 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_7 & 7u)))))) != 0u);
  return result_7;}
static inline NB8 rawTagIsNimonyPragma_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_4){
  NB8 result_9;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_8 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 1u, 128u, 0u, 0u, 4u, 0u, 0u, 2u, 0u, 0u, 112u, 202u, 2u, 0u, 2u, 0u, 0u, 0u, 0u, 16u, 254u, 255u, 255u, 7u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 128u, 255u, 127u, 240u, 255u, 31u}}
  ;
  NU64 X60Qdesugar_9 = ((NU)raw_4);
  result_9 = (((NU8)(X60Qdesugar_8.a[((NU)(X60Qdesugar_9 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_9 & 7u)))))) != 0u);
  return result_9;}
string_0_sysvq0asl dollarX60Q_NimonySym_0_nimry5ra91(NimonySym_0_nimry5ra91 e_5){
  string_0_sysvq0asl result_10;
  nimStrWasMoved((&result_10));
  switch (e_5){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399803646u, .more_0 = (&strlit_0_I15358474783062118651_nimry5ra91)}
      ;}
    break;
    case 54:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
      ;}
    break;
    case 55:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_comaa5xpt1)}
      ;}
    break;
    case 56:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
      ;}
    break;
    case 57:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_comaa5xpt1)}
      ;}
    break;
    case 58:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_comaa5xpt1)}
      ;}
    break;
    case 59:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1936028414u, .more_0 = (&strlit_0_I2416437014800228590_comaa5xpt1)}
      ;}
    break;
    case 60:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
      ;}
    break;
    case 61:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701606654u, .more_0 = (&strlit_0_I7233319822780473912_nif12fhfr1)}
      ;}
    break;
    case 62:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
      ;}
    break;
    case 63:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
      ;}
    break;
    case 64:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952542974u, .more_0 = (&strlit_0_I3786558325628924612_comaa5xpt1)}
      ;}
    break;
    case 65:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3759916806223351059_nimry5ra91)}
      ;}
    break;
    case 66:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I15385401366416332649_nimry5ra91)}
      ;}
    break;
    case 67:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
      ;}
    break;
    case 68:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
      ;}
    break;
    case 69:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1818650622u, .more_0 = (&strlit_0_I17496857845421750549_nimry5ra91)}
      ;}
    break;
    case 70:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_comaa5xpt1)}
      ;}
    break;
    case 71:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_comaa5xpt1)}
      ;}
    break;
    case 72:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I9071657656589967445_comaa5xpt1)}
      ;}
    break;
    case 73:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I6864681898360807206_comaa5xpt1)}
      ;}
    break;
    case 74:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
      ;}
    break;
    case 75:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1667329534u, .more_0 = (&strlit_0_I3777428167486794959_comaa5xpt1)}
      ;}
    break;
    case 76:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1835365630u, .more_0 = (&strlit_0_I17987658270787974407_comaa5xpt1)}
      ;}
    break;
    case 77:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      ;}
    break;
    case 78:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869374206u, .more_0 = (&strlit_0_I9830314142150548690_comaa5xpt1)}
      ;}
    break;
    case 79:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I6605162211648777506_nimry5ra91)}
      ;}
    break;
    case 80:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1751344126u, .more_0 = (&strlit_0_I7132977312474535290_nimry5ra91)}
      ;}
    break;}
  return result_10;}
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5){
  NB8 result_11;
  NB8 X60Qx_0;
  if (54 <= raw_5){
    X60Qx_0 = (raw_5 <= 80);}
  else {
    X60Qx_0 = NIM_FALSE;}
  result_11 = X60Qx_0;
  return result_11;}
void X60Qini_0_nimry5ra91(void){
  if (X60QiniGuard_0_nimry5ra91){
    return;}
  X60QiniGuard_0_nimry5ra91 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tagygirdh1();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
