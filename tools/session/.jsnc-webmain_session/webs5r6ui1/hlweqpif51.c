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
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct ParamShape_0_hlweqpif51 ParamShape_0_hlweqpif51;
typedef struct Branch_0_hlweqpif51 Branch_0_hlweqpif51;
typedef struct CaseBranch_0_hlweqpif51 CaseBranch_0_hlweqpif51;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct LocalShape_0_hlweqpif51{
  NU32 name_0;
  Cursor_0_nifb6mq6y1 typ_0;
  NB8 hasInit_0;
  Cursor_0_nifb6mq6y1 init_0;}
LocalShape_0_hlweqpif51;
typedef struct ParamShape_0_hlweqpif51{
  NU32 name_0;
  NB8 byRef_0;}
ParamShape_0_hlweqpif51;
typedef struct ProcShape_0_hlweqpif51{
  NU32 name_0;
  NB8 hasParams_0;
  Cursor_0_nifb6mq6y1 params_0;
  NB8 hasBody_0;
  Cursor_0_nifb6mq6y1 body_0;}
ProcShape_0_hlweqpif51;
typedef struct Branch_0_hlweqpif51{
  NB8 isElse_0;
  Cursor_0_nifb6mq6y1 cond_0;
  Cursor_0_nifb6mq6y1 body_0;}
Branch_0_hlweqpif51;
typedef struct CaseBranch_0_hlweqpif51{
  NB8 isElse_0;
  Cursor_0_nifb6mq6y1 ranges_0;
  Cursor_0_nifb6mq6y1 body_0;}
CaseBranch_0_hlweqpif51;
typedef struct seq_0_I504q6j1_hlweqpif51{
  NI32 len_0;
  ParamShape_0_hlweqpif51* data_0;}
seq_0_I504q6j1_hlweqpif51;
typedef struct seq_0_I5xzhce1_hlweqpif51{
  NI32 len_0;
  Branch_0_hlweqpif51* data_0;}
seq_0_I5xzhce1_hlweqpif51;
typedef struct seq_0_Inh5osa1_hlweqpif51{
  NI32 len_0;
  CaseBranch_0_hlweqpif51* data_0;}
seq_0_Inh5osa1_hlweqpif51;
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
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline seq_0_I5xzhce1_hlweqpif51 newSeqUninit_0_I95x2wv_hlweqpif51(NI32 size_5);
static inline void add_0_Inocw0d1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* s_5, Branch_0_hlweqpif51 elem_4);
static inline seq_0_Inh5osa1_hlweqpif51 newSeqUninit_0_Ig6qvjx_hlweqpif51(NI32 size_7);
static inline void add_0_Icwnjir_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* s_7, CaseBranch_0_hlweqpif51 elem_5);
static inline NI32 memSizeInBytes_0_Inp3cnc1_hlweqpif51(NI32 size_10);
static inline NI32 capInBytes_0_Iuvfr8b1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51 s_10);
NB8 resize_0_Ipti41j1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* dest_4, NI32 addedElements_4);
static inline NI32 memSizeInBytes_0_Ibxa6o91_hlweqpif51(NI32 size_11);
static inline NI32 capInBytes_0_Ir6djzo1_hlweqpif51(seq_0_Inh5osa1_hlweqpif51 s_11);
NB8 resize_0_It66q7d1_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* dest_5, NI32 addedElements_5);
void eQdestroy_1_Iaemmbd1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51 s_20);
static inline void eQwasMoved_1_Igtufva1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* s_21);
void eQdestroy_1_Ihg20371_hlweqpif51(seq_0_Inh5osa1_hlweqpif51 s_22);
static inline void eQwasMoved_1_Icglbyy_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* s_23);
void eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51(Branch_0_hlweqpif51* dest_0);
void eQwasmovedQ_SX42ranch0hlweqpif51_0_hlweqpif51(Branch_0_hlweqpif51* dest_0);
void eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* dest_0);
void eQwasmovedQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* dest_0);
CaseBranch_0_hlweqpif51 eQdupQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* src_0);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline void consumeParRi_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_19);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_tagygirdh1(void);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
extern LongString_0_sysvq0asl const strlit_0_I17128882682348225350_nifb6mq6y1;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern NU32 const ErrT_0_nifh7u8pu1;
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
NB8 X60QiniGuard_0_hlweqpif51;
seq_0_I5xzhce1_hlweqpif51 decodeIf_0_hlweqpif51(Cursor_0_nifb6mq6y1* n_4){
  seq_0_I5xzhce1_hlweqpif51 result_4;
  eQwasMoved_1_Igtufva1_hlweqpif51((&result_4));
  eQdestroy_1_Iaemmbd1_hlweqpif51(result_4);
  seq_0_I5xzhce1_hlweqpif51 X60Qx_34 = newSeqUninit_0_I95x2wv_hlweqpif51(0);
  result_4 = X60Qx_34;
  inc_0_nifb6mq6y1(n_4);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_35 = kind_0_nifb6mq6y1((*n_4));
      if ((!(X60Qx_35 == 12))){
        NB8 X60Qx_36;
        NifKind_0_nif81dubp1 X60Qx_37 = kind_0_nifb6mq6y1((*n_4));
        if (X60Qx_37 == 11){
          NU32 X60Qx_38 = tag_0_nifb6mq6y1((*n_4));
          X60Qx_36 = (((TagEnum_0_tagygirdh1)X60Qx_38) == 89);}
        else {
          X60Qx_36 = NIM_FALSE;}
        if (X60Qx_36){
          inc_0_nifb6mq6y1(n_4);
          Branch_0_hlweqpif51 br_0 = (Branch_0_hlweqpif51){
            .isElse_0 = NIM_FALSE, .cond_0 = (Cursor_0_nifb6mq6y1){
              .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
            , .body_0 = (Cursor_0_nifb6mq6y1){
              .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
          ;
          Cursor_0_nifb6mq6y1* X60Qlhs_4 = (&br_0.cond_0);
          eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_4)));
          Cursor_0_nifb6mq6y1 X60Qx_39 = eQdup_0_nifb6mq6y1((*n_4));
          (*X60Qlhs_4) = X60Qx_39;
          skip_0_nifb6mq6y1(n_4);
          Cursor_0_nifb6mq6y1* X60Qlhs_5 = (&br_0.body_0);
          eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_5)));
          Cursor_0_nifb6mq6y1 X60Qx_40 = eQdup_0_nifb6mq6y1((*n_4));
          (*X60Qlhs_5) = X60Qx_40;
          {
            while (NIM_TRUE){
              NifKind_0_nif81dubp1 X60Qx_41 = kind_0_nifb6mq6y1((*n_4));
              if ((!(X60Qx_41 == 12))){
                skip_0_nifb6mq6y1(n_4);}
              else {
                break;}}}
          whileStmtLabel_1: ;
          consumeParRi_0_nifb6mq6y1(n_4);
          Branch_0_hlweqpif51 X60Qtmp_6 = br_0;
          eQwasmovedQ_SX42ranch0hlweqpif51_0_hlweqpif51((&br_0));
          add_0_Inocw0d1_hlweqpif51((&result_4), X60Qtmp_6);
          eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51((&br_0));}
        else {
          NB8 X60Qx_42;
          NifKind_0_nif81dubp1 X60Qx_43 = kind_0_nifb6mq6y1((*n_4));
          if (X60Qx_43 == 11){
            NU32 X60Qx_44 = tag_0_nifb6mq6y1((*n_4));
            X60Qx_42 = (((TagEnum_0_tagygirdh1)X60Qx_44) == 90);}
          else {
            X60Qx_42 = NIM_FALSE;}
          if (X60Qx_42){
            inc_0_nifb6mq6y1(n_4);
            Branch_0_hlweqpif51 br_1 = (Branch_0_hlweqpif51){
              .isElse_0 = NIM_TRUE, .cond_0 = (Cursor_0_nifb6mq6y1){
                .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
              , .body_0 = (Cursor_0_nifb6mq6y1){
                .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
            ;
            Cursor_0_nifb6mq6y1* X60Qlhs_7 = (&br_1.body_0);
            eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_7)));
            Cursor_0_nifb6mq6y1 X60Qx_45 = eQdup_0_nifb6mq6y1((*n_4));
            (*X60Qlhs_7) = X60Qx_45;
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_46 = kind_0_nifb6mq6y1((*n_4));
                if ((!(X60Qx_46 == 12))){
                  skip_0_nifb6mq6y1(n_4);}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            consumeParRi_0_nifb6mq6y1(n_4);
            Branch_0_hlweqpif51 X60Qtmp_8 = br_1;
            eQwasmovedQ_SX42ranch0hlweqpif51_0_hlweqpif51((&br_1));
            add_0_Inocw0d1_hlweqpif51((&result_4), X60Qtmp_8);
            eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51((&br_1));}
          else {
            skip_0_nifb6mq6y1(n_4);}}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_4);
  return result_4;}
seq_0_Inh5osa1_hlweqpif51 decodeCase_0_hlweqpif51(Cursor_0_nifb6mq6y1* n_5, Cursor_0_nifb6mq6y1* sel_0){
  seq_0_Inh5osa1_hlweqpif51 result_5;
  eQwasMoved_1_Icglbyy_hlweqpif51((&result_5));
  eQdestroy_1_Ihg20371_hlweqpif51(result_5);
  seq_0_Inh5osa1_hlweqpif51 X60Qx_47 = newSeqUninit_0_Ig6qvjx_hlweqpif51(0);
  result_5 = X60Qx_47;
  inc_0_nifb6mq6y1(n_5);
  Cursor_0_nifb6mq6y1 X60Qlhs_9 = (*sel_0);
  Cursor_0_nifb6mq6y1 X60Qx_48 = eQdup_0_nifb6mq6y1((*n_5));
  (*sel_0) = X60Qx_48;
  eQdestroy_0_nifb6mq6y1((&X60Qlhs_9));
  skip_0_nifb6mq6y1(n_5);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_49 = kind_0_nifb6mq6y1((*n_5));
      if ((!(X60Qx_49 == 12))){
        NB8 X60Qx_50;
        NifKind_0_nif81dubp1 X60Qx_51 = kind_0_nifb6mq6y1((*n_5));
        if (X60Qx_51 == 11){
          NU32 X60Qx_52 = tag_0_nifb6mq6y1((*n_5));
          X60Qx_50 = (((TagEnum_0_tagygirdh1)X60Qx_52) == 98);}
        else {
          X60Qx_50 = NIM_FALSE;}
        if (X60Qx_50){
          inc_0_nifb6mq6y1(n_5);
          CaseBranch_0_hlweqpif51 br_2 = (CaseBranch_0_hlweqpif51){
            .isElse_0 = NIM_FALSE, .ranges_0 = (Cursor_0_nifb6mq6y1){
              .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
            , .body_0 = (Cursor_0_nifb6mq6y1){
              .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
          ;
          Cursor_0_nifb6mq6y1* X60Qlhs_10 = (&br_2.ranges_0);
          eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_10)));
          Cursor_0_nifb6mq6y1 X60Qx_53 = eQdup_0_nifb6mq6y1((*n_5));
          (*X60Qlhs_10) = X60Qx_53;
          skip_0_nifb6mq6y1(n_5);
          Cursor_0_nifb6mq6y1* X60Qlhs_11 = (&br_2.body_0);
          eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_11)));
          Cursor_0_nifb6mq6y1 X60Qx_54 = eQdup_0_nifb6mq6y1((*n_5));
          (*X60Qlhs_11) = X60Qx_54;
          {
            while (NIM_TRUE){
              NifKind_0_nif81dubp1 X60Qx_55 = kind_0_nifb6mq6y1((*n_5));
              if ((!(X60Qx_55 == 12))){
                skip_0_nifb6mq6y1(n_5);}
              else {
                break;}}}
          whileStmtLabel_1: ;
          consumeParRi_0_nifb6mq6y1(n_5);
          CaseBranch_0_hlweqpif51 X60Qtmp_12 = br_2;
          eQwasmovedQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&br_2));
          add_0_Icwnjir_hlweqpif51((&result_5), X60Qtmp_12);
          eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&br_2));}
        else {
          NB8 X60Qx_56;
          NifKind_0_nif81dubp1 X60Qx_57 = kind_0_nifb6mq6y1((*n_5));
          if (X60Qx_57 == 11){
            NU32 X60Qx_58 = tag_0_nifb6mq6y1((*n_5));
            X60Qx_56 = (((TagEnum_0_tagygirdh1)X60Qx_58) == 90);}
          else {
            X60Qx_56 = NIM_FALSE;}
          if (X60Qx_56){
            inc_0_nifb6mq6y1(n_5);
            CaseBranch_0_hlweqpif51 br_3 = (CaseBranch_0_hlweqpif51){
              .isElse_0 = NIM_TRUE, .ranges_0 = (Cursor_0_nifb6mq6y1){
                .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
              , .body_0 = (Cursor_0_nifb6mq6y1){
                .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
            ;
            Cursor_0_nifb6mq6y1* X60Qlhs_13 = (&br_3.body_0);
            eQdestroy_0_nifb6mq6y1((&(*X60Qlhs_13)));
            Cursor_0_nifb6mq6y1 X60Qx_59 = eQdup_0_nifb6mq6y1((*n_5));
            (*X60Qlhs_13) = X60Qx_59;
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_60 = kind_0_nifb6mq6y1((*n_5));
                if ((!(X60Qx_60 == 12))){
                  skip_0_nifb6mq6y1(n_5);}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            consumeParRi_0_nifb6mq6y1(n_5);
            CaseBranch_0_hlweqpif51 X60Qtmp_14 = br_3;
            eQwasmovedQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&br_3));
            add_0_Icwnjir_hlweqpif51((&result_5), X60Qtmp_14);
            eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&br_3));}
          else {
            skip_0_nifb6mq6y1(n_5);}}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_5);
  return result_5;}
static inline seq_0_I5xzhce1_hlweqpif51 newSeqUninit_0_I95x2wv_hlweqpif51(NI32 size_5){
  seq_0_I5xzhce1_hlweqpif51 result_7;
  if (size_5 == 0){
    result_7 = (seq_0_I5xzhce1_hlweqpif51){
      .len_0 = size_5, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Inp3cnc1_hlweqpif51(size_5);
    void* X60Qx_65 = alloc_1_sysvq0asl(memSize_1);
    result_7 = (seq_0_I5xzhce1_hlweqpif51){
      .len_0 = size_5, .data_0 = ((Branch_0_hlweqpif51*)X60Qx_65)}
    ;
    if ((!(result_7.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_66 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_7.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_7;}
static inline void add_0_Inocw0d1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* s_5, Branch_0_hlweqpif51 elem_4){
  NI32 L_1 = (*s_5).len_0;
  NI32 X60Qx_67 = capInBytes_0_Iuvfr8b1_hlweqpif51((*s_5));
  if (X60Qx_67 < ((NI32)(((NI32)(L_1 * sizeof(Branch_0_hlweqpif51))) + sizeof(Branch_0_hlweqpif51)))){
    NB8 X60Qx_68 = resize_0_Ipti41j1_hlweqpif51(s_5, 1);
    if ((!X60Qx_68)){
      eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51((&elem_4));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_5).len_0));
  (*s_5).data_0[L_1] = elem_4;}
static inline seq_0_Inh5osa1_hlweqpif51 newSeqUninit_0_Ig6qvjx_hlweqpif51(NI32 size_7){
  seq_0_Inh5osa1_hlweqpif51 result_8;
  if (size_7 == 0){
    result_8 = (seq_0_Inh5osa1_hlweqpif51){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Ibxa6o91_hlweqpif51(size_7);
    void* X60Qx_69 = alloc_1_sysvq0asl(memSize_2);
    result_8 = (seq_0_Inh5osa1_hlweqpif51){
      .len_0 = size_7, .data_0 = ((CaseBranch_0_hlweqpif51*)X60Qx_69)}
    ;
    if ((!(result_8.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_70 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_8.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_8;}
static inline void add_0_Icwnjir_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* s_7, CaseBranch_0_hlweqpif51 elem_5){
  NI32 L_2 = (*s_7).len_0;
  NI32 X60Qx_71 = capInBytes_0_Ir6djzo1_hlweqpif51((*s_7));
  if (X60Qx_71 < ((NI32)(((NI32)(L_2 * sizeof(CaseBranch_0_hlweqpif51))) + sizeof(CaseBranch_0_hlweqpif51)))){
    NB8 X60Qx_72 = resize_0_It66q7d1_hlweqpif51(s_7, 1);
    if ((!X60Qx_72)){
      eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&elem_5));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_7).len_0));
  (*s_7).data_0[L_2] = elem_5;}
static inline NI32 memSizeInBytes_0_Inp3cnc1_hlweqpif51(NI32 size_10){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_12;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_10, sizeof(Branch_0_hlweqpif51), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_12 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_12 = ((NI32)2147483647);}
  return result_12;}
static inline NI32 capInBytes_0_Iuvfr8b1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51 s_10){
  NI32 result_13;
  NI32 X60Qx_1;
  if ((!(s_10.data_0 == NIM_NIL))){
    NI32 X60Qx_76 = allocatedSize_0_sysvq0asl(((void*)((void*)s_10.data_0)));
    X60Qx_1 = X60Qx_76;}
  else {
    X60Qx_1 = 0;}
  result_13 = X60Qx_1;
  return result_13;}
NB8 resize_0_Ipti41j1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* dest_4, NI32 addedElements_4){
  NB8 result_14;
  NI32 X60Qx_77 = capInBytes_0_Iuvfr8b1_hlweqpif51((*dest_4));
  NI32 oldCap_1 = ((NI32)(X60Qx_77 / sizeof(Branch_0_hlweqpif51)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_4);
  NI32 memSize_4 = memSizeInBytes_0_Inp3cnc1_hlweqpif51(newCap_1);
  void* X60Qx_78 = realloc_1_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_4);
  (*dest_4).data_0 = ((Branch_0_hlweqpif51*)X60Qx_78);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_4);
    result_14 = NIM_FALSE;}
  else {
    result_14 = NIM_TRUE;}
  return result_14;}
static inline NI32 memSizeInBytes_0_Ibxa6o91_hlweqpif51(NI32 size_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_15;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_11, sizeof(CaseBranch_0_hlweqpif51), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_15 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_15 = ((NI32)2147483647);}
  return result_15;}
static inline NI32 capInBytes_0_Ir6djzo1_hlweqpif51(seq_0_Inh5osa1_hlweqpif51 s_11){
  NI32 result_16;
  NI32 X60Qx_2;
  if ((!(s_11.data_0 == NIM_NIL))){
    NI32 X60Qx_79 = allocatedSize_0_sysvq0asl(((void*)((void*)s_11.data_0)));
    X60Qx_2 = X60Qx_79;}
  else {
    X60Qx_2 = 0;}
  result_16 = X60Qx_2;
  return result_16;}
NB8 resize_0_It66q7d1_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* dest_5, NI32 addedElements_5){
  NB8 result_17;
  NI32 X60Qx_80 = capInBytes_0_Ir6djzo1_hlweqpif51((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_80 / sizeof(CaseBranch_0_hlweqpif51)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_5 = memSizeInBytes_0_Ibxa6o91_hlweqpif51(newCap_2);
  void* X60Qx_81 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((CaseBranch_0_hlweqpif51*)X60Qx_81);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_17 = NIM_FALSE;}
  else {
    result_17 = NIM_TRUE;}
  return result_17;}
void eQdestroy_1_Iaemmbd1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51 s_20){
  if ((!(s_20.data_0 == NIM_NIL))){
    NI32 i_4 = 0;
    {
      while (i_4 < s_20.len_0){
        eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51((&s_20.data_0[i_4]));
        inc_1_I6wjjge_aow2h993l1((&i_4));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_20.data_0)));}}
static inline void eQwasMoved_1_Igtufva1_hlweqpif51(seq_0_I5xzhce1_hlweqpif51* s_21){
  (*s_21).len_0 = 0;
  (*s_21).data_0 = NIM_NIL;}
void eQdestroy_1_Ihg20371_hlweqpif51(seq_0_Inh5osa1_hlweqpif51 s_22){
  if ((!(s_22.data_0 == NIM_NIL))){
    NI32 i_8 = 0;
    {
      while (i_8 < s_22.len_0){
        eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&s_22.data_0[i_8]));
        inc_1_I6wjjge_aow2h993l1((&i_8));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_22.data_0)));}}
static inline void eQwasMoved_1_Icglbyy_hlweqpif51(seq_0_Inh5osa1_hlweqpif51* s_23){
  (*s_23).len_0 = 0;
  (*s_23).data_0 = NIM_NIL;}
seq_0_Inh5osa1_hlweqpif51 eQdup_1_I6s2r0d_hlweqpif51(seq_0_Inh5osa1_hlweqpif51 a_5){
  seq_0_Inh5osa1_hlweqpif51 result_20;
  seq_0_Inh5osa1_hlweqpif51 X60Qx_92 = newSeqUninit_0_Ig6qvjx_hlweqpif51(a_5.len_0);
  result_20 = X60Qx_92;
  NI32 i_9 = 0;
  {
    while (i_9 < a_5.len_0){
      CaseBranch_0_hlweqpif51 X60Qx_93 = eQdupQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51((&a_5.data_0[i_9]));
      result_20.data_0[i_9] = X60Qx_93;
      inc_1_I6wjjge_aow2h993l1((&i_9));}}
  whileStmtLabel_0: ;
  return result_20;}
void eQdestroyQ_SX42ranch0hlweqpif51_0_hlweqpif51(Branch_0_hlweqpif51* dest_0){
  eQdestroy_0_nifb6mq6y1((&(*dest_0).body_0));
  eQdestroy_0_nifb6mq6y1((&(*dest_0).cond_0));}
void eQwasmovedQ_SX42ranch0hlweqpif51_0_hlweqpif51(Branch_0_hlweqpif51* dest_0){
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).cond_0));
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).body_0));}
void eQdestroyQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* dest_0){
  eQdestroy_0_nifb6mq6y1((&(*dest_0).body_0));
  eQdestroy_0_nifb6mq6y1((&(*dest_0).ranges_0));}
void eQwasmovedQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* dest_0){
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).ranges_0));
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).body_0));}
CaseBranch_0_hlweqpif51 eQdupQ_SX43aseX42ranch0hlweqpif51_0_hlweqpif51(CaseBranch_0_hlweqpif51* src_0){
  CaseBranch_0_hlweqpif51 dest_0;
  dest_0.isElse_0 = (*src_0).isElse_0;
  Cursor_0_nifb6mq6y1 X60Qx_104 = eQdup_0_nifb6mq6y1((*src_0).ranges_0);
  dest_0.ranges_0 = X60Qx_104;
  Cursor_0_nifb6mq6y1 X60Qx_105 = eQdup_0_nifb6mq6y1((*src_0).body_0);
  dest_0.body_0 = X60Qx_105;
  return dest_0;}
void X60Qini_0_hlweqpif51(void){
  if (X60QiniGuard_0_hlweqpif51){
    return;}
  X60QiniGuard_0_hlweqpif51 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_tagygirdh1();}
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
  dec_1_I0nzoz91_aow7lb5cq1((&(*c_18).rem_0));}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
