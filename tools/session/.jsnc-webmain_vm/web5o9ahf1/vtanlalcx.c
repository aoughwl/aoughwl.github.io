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
typedef struct MethodIndexEntry_0_sempjk6bn1 MethodIndexEntry_0_sempjk6bn1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct seq_0_Idl3iy1_comaa5xpt1{
  NI32 len_0;
  MethodIndexEntry_0_sempjk6bn1* data_0;}
seq_0_Idl3iy1_comaa5xpt1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
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
typedef struct TypeDecl_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 body_0;}
TypeDecl_0_decqocs071;
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
typedef struct MethodIndexEntry_0_sempjk6bn1{
  NU32 fn_0;
  NU32 signature_0;}
MethodIndexEntry_0_sempjk6bn1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
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
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef NU8 TagClass_0_nifb6mq6y1;

#define Anything_0_nifb6mq6y1 ((NU8)0)
#define AnyExpr_0_nifb6mq6y1 ((NU8)1)
#define AnyStmt_0_nifb6mq6y1 ((NU8)2)
#define AnyType_0_nifb6mq6y1 ((NU8)3)
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
static inline void add_0_Izy6sw41_vtanlalcx(seq_0_Idl3iy1_comaa5xpt1* s_7, MethodIndexEntry_0_sempjk6bn1 elem_3);
NB8 resize_0_I1ya9sv1_vtanlalcx(seq_0_Idl3iy1_comaa5xpt1* dest_2, NI32 addedElements_2);
static inline void eQwasMoved_1_Ibnkc9q_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1* s_382);
extern void eQdestroy_1_Iph9dp4_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_381);
static inline seq_0_Idl3iy1_comaa5xpt1 newSeqUninit_0_Itwybvv1_comaa5xpt1(NI32 size_114);
extern LoadResult_0_prorcx25w1 tryLoadSym_0_prorcx25w1(NU32 s_5);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern TypeDecl_0_decqocs071 asTypeDecl_0_decqocs071(Cursor_0_nifb6mq6y1 c_10);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern LongString_0_sysvq0asl const strlit_0_I15608149751057510534_explnj22x1;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline NimonyPragma_0_nimry5ra91 pragmaKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_4);
static inline NimonyOther_0_nimry5ra91 substructureKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_6);
extern string_0_sysvq0asl dollarX60Q_NimonyOther_0_nimry5ra91(NimonyOther_0_nimry5ra91 e_3);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NimonyStmt_0_nimry5ra91 stmtKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_3);
extern string_0_sysvq0asl dollarX60Q_NimonyStmt_0_nimry5ra91(NimonyStmt_0_nimry5ra91 e_1);
static inline NimonyExpr_0_nimry5ra91 exprKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_10);
extern string_0_sysvq0asl dollarX60Q_NimonyExpr_0_nimry5ra91(NimonyExpr_0_nimry5ra91 e_0);
static inline NimonyType_0_nimry5ra91 typeKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_7);
extern string_0_sysvq0asl dollarX60Q_NimonyType_0_nimry5ra91(NimonyType_0_nimry5ra91 e_2);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern LongString_0_sysvq0asl const strlit_0_I3094246681334826409_sig6uoro1;
extern LongString_0_sysvq0asl const strlit_0_I5519984301460876928_sig6uoro1;
extern LongString_0_sysvq0asl const strlit_0_I919094343993954774_sig6uoro1;
extern LongString_0_sysvq0asl const strlit_0_I16803564321623345030_sig6uoro1;
extern LongString_0_sysvq0asl const strlit_0_I5712266299568913059_sig6uoro1;
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7);
static inline NB8 tagClassMatches_0_nifb6mq6y1(NifKind_0_nif81dubp1 k_1, TagClass_0_nifb6mq6y1 expected_0);
extern string_0_sysvq0asl dollarX60Q_TagClass_0_nifb6mq6y1(TagClass_0_nifb6mq6y1 e_1);
extern LongString_0_sysvq0asl const strlit_0_I5400270834280783131_nim30udrv;
extern LongString_0_sysvq0asl const strlit_0_I4775150051315309461_decqocs071;
extern LongString_0_sysvq0asl const strlit_0_I3085349504904670868_decqocs071;
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
extern LongString_0_sysvq0asl const strlit_0_I13237575353761119172_explnj22x1;
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern void eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071(TypeDecl_0_decqocs071* dest_0);
static inline NI32 capInBytes_0_Irxk45k1_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_391);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_Ikui0mk_comaa5xpt1(NI32 size_115);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_nifa1znj21(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_trellwskh(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_typ6lv6cu1(void);
extern void X60Qini_0_renqb5hy11(void);
extern void X60Qini_0_sigekpubi1(void);
extern void X60Qini_0_sempjk6bn1(void);
extern void X60Qini_0_typurxiqa1(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_typ9rqp2b(void);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline NB8 rawTagIsNimonyPragma_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_4);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
extern NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3);
static inline NimonyOther_0_nimry5ra91 substructureKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_5);
static inline NimonyStmt_0_nimry5ra91 stmtKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_2);
static inline NimonyExpr_0_nimry5ra91 exprKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_9);
static inline NB8 rawTagIsNimonyType_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_2);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline NB8 rawTagIsNimonyOther_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_3);
static inline NB8 rawTagIsNimonyStmt_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_1);
static inline NB8 rawTagIsNimonyExpr_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_0);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern NU32 const ErrT_0_nifh7u8pu1;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
NB8 X60QiniGuard_0_vtanlalcx;
seq_0_Idl3iy1_comaa5xpt1 loadVTable_0_vtanlalcx(NU32 typ_0){
  seq_0_Idl3iy1_comaa5xpt1 result_4;
  eQwasMoved_1_Ibnkc9q_comaa5xpt1((&result_4));
  eQdestroy_1_Iph9dp4_comaa5xpt1(result_4);
  seq_0_Idl3iy1_comaa5xpt1 X60Qx_16 = newSeqUninit_0_Itwybvv1_comaa5xpt1(0);
  result_4 = X60Qx_16;
  LoadResult_0_prorcx25w1 res_0 = tryLoadSym_0_prorcx25w1(typ_0);
  if ((!(res_0.status_0 == 3))){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_4;}
  TypeDecl_0_decqocs071 typeDecl_0 = asTypeDecl_0_decqocs071(res_0.decl_0);
  Cursor_0_nifb6mq6y1 pragmas_0 = typeDecl_0.pragmas_0;
  eQwasMoved_0_nifb6mq6y1((&typeDecl_0.pragmas_0));
  NifKind_0_nif81dubp1 X60Qx_17 = kind_0_nifb6mq6y1(pragmas_0);
  if (X60Qx_17 == 11){
    NifKind_0_nif81dubp1 X60Qx_18 = kind_0_nifb6mq6y1(pragmas_0);
    if ((!(X60Qx_18 == 11))){
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
      );
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I15608149751057510534_explnj22x1)}
      );
      write_7_syn1lfpjv(stdout, (NC8)'\012');
      quit_0_syn1lfpjv(1);}
    inc_0_nifb6mq6y1((&pragmas_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_19 = kind_0_nifb6mq6y1(pragmas_0);
        if ((!(X60Qx_19 == 12))){
          NB8 X60Qx_20;
          NifKind_0_nif81dubp1 X60Qx_21 = kind_0_nifb6mq6y1(pragmas_0);
          if (X60Qx_21 == 11){
            NimonyPragma_0_nimry5ra91 X60Qx_22 = pragmaKind_0_nim30udrv(pragmas_0);
            X60Qx_20 = (X60Qx_22 == 331);}
          else {
            X60Qx_20 = NIM_FALSE;}
          if (X60Qx_20){
            NifKind_0_nif81dubp1 X60Qx_23 = kind_0_nifb6mq6y1(pragmas_0);
            if ((!(X60Qx_23 == 11))){
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
              );
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I15608149751057510534_explnj22x1)}
              );
              write_7_syn1lfpjv(stdout, (NC8)'\012');
              quit_0_syn1lfpjv(1);}
            inc_0_nifb6mq6y1((&pragmas_0));
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_24 = kind_0_nifb6mq6y1(pragmas_0);
                if ((!(X60Qx_24 == 12))){
                  NB8 X60Qx_25;
                  NifKind_0_nif81dubp1 X60Qx_26 = kind_0_nifb6mq6y1(pragmas_0);
                  if (X60Qx_26 == 11){
                    NimonyOther_0_nimry5ra91 X60Qx_27 = substructureKind_1_nim30udrv(pragmas_0);
                    X60Qx_25 = (X60Qx_27 == 30);}
                  else {
                    X60Qx_25 = NIM_FALSE;}
                  if (X60Qx_25){
                    NimonyOther_0_nimry5ra91 X60Qx_28 = substructureKind_1_nim30udrv(pragmas_0);
                    if ((!(X60Qx_28 == 30))){
                      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                      );
                      string_0_sysvq0asl X60Qdesugar_2 = dollarX60Q_NimonyOther_0_nimry5ra91(30);
                      NifKind_0_nif81dubp1 X60Qx_29 = kind_0_nifb6mq6y1(pragmas_0);
                      string_0_sysvq0asl X60Qdesugar_3 = dollarX60Q_NifKind_0_nif81dubp1(X60Qx_29);
                      NimonyStmt_0_nimry5ra91 X60Qx_30 = stmtKind_1_nim30udrv(pragmas_0);
                      string_0_sysvq0asl X60Qdesugar_4 = dollarX60Q_NimonyStmt_0_nimry5ra91(X60Qx_30);
                      NimonyExpr_0_nimry5ra91 X60Qx_31 = exprKind_1_nim30udrv(pragmas_0);
                      string_0_sysvq0asl X60Qdesugar_5 = dollarX60Q_NimonyExpr_0_nimry5ra91(X60Qx_31);
                      NimonyType_0_nimry5ra91 X60Qx_32 = typeKind_0_nim30udrv(pragmas_0);
                      string_0_sysvq0asl X60Qdesugar_6 = dollarX60Q_NimonyType_0_nimry5ra91(X60Qx_32);
                      NI32 X60Qx_33 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I3094246681334826409_sig6uoro1)}
                      );
                      NI32 X60Qx_34 = len_4_sysvq0asl(X60Qdesugar_2);
                      NI32 X60Qx_35 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I5519984301460876928_sig6uoro1)}
                      );
                      NI32 X60Qx_36 = len_4_sysvq0asl(X60Qdesugar_3);
                      NI32 X60Qx_37 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1932009726u, .more_0 = (&strlit_0_I919094343993954774_sig6uoro1)}
                      );
                      NI32 X60Qx_38 = len_4_sysvq0asl(X60Qdesugar_4);
                      NI32 X60Qx_39 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2019893502u, .more_0 = (&strlit_0_I16803564321623345030_sig6uoro1)}
                      );
                      NI32 X60Qx_40 = len_4_sysvq0asl(X60Qdesugar_5);
                      NI32 X60Qx_41 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2037653758u, .more_0 = (&strlit_0_I5712266299568913059_sig6uoro1)}
                      );
                      NI32 X60Qx_42 = len_4_sysvq0asl(X60Qdesugar_6);
                      NI32 X60Qx_43 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 10497u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_33 + X60Qx_34)) + X60Qx_35)) + X60Qx_36)) + X60Qx_37)) + X60Qx_38)) + X60Qx_39)) + X60Qx_40)) + X60Qx_41)) + X60Qx_42)) + X60Qx_43)));
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I3094246681334826409_sig6uoro1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_2);
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I5519984301460876928_sig6uoro1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_3);
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 1932009726u, .more_0 = (&strlit_0_I919094343993954774_sig6uoro1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_4);
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 2019893502u, .more_0 = (&strlit_0_I16803564321623345030_sig6uoro1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_5);
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 2037653758u, .more_0 = (&strlit_0_I5712266299568913059_sig6uoro1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
                      add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
                        .bytes_0 = 10497u, .more_0 = NIM_NIL}
                      );
                      write_0_syn1lfpjv(stdout, X60Qdesugar_7);
                      write_7_syn1lfpjv(stdout, (NC8)'\012');
                      quit_0_syn1lfpjv(1);
                      nimStrDestroy(X60Qdesugar_7);
                      nimStrDestroy(X60Qdesugar_6);
                      nimStrDestroy(X60Qdesugar_5);
                      nimStrDestroy(X60Qdesugar_4);
                      nimStrDestroy(X60Qdesugar_3);
                      nimStrDestroy(X60Qdesugar_2);}
                    NifKind_0_nif81dubp1 X60Qx_44 = kind_0_nifb6mq6y1(pragmas_0);
                    if ((!(X60Qx_44 == 11))){
                      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                      );
                      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I15608149751057510534_explnj22x1)}
                      );
                      write_7_syn1lfpjv(stdout, (NC8)'\012');
                      quit_0_syn1lfpjv(1);}
                    inc_0_nifb6mq6y1((&pragmas_0));
                    NB8 X60Qx_45;
                    NifKind_0_nif81dubp1 X60Qx_46 = kind_0_nifb6mq6y1(pragmas_0);
                    if ((!(X60Qx_46 == 12))){
                      NifKind_0_nif81dubp1 X60Qx_47 = kind_0_nifb6mq6y1(pragmas_0);
                      X60Qx_45 = (X60Qx_47 == 6);}
                    else {
                      X60Qx_45 = NIM_FALSE;}
                    if (X60Qx_45){
                      NU32 signature_11 = litId_0_nifb6mq6y1(pragmas_0);
                      NifKind_0_nif81dubp1 X60Qx_48 = kind_0_nifb6mq6y1(pragmas_0);
                      NB8 X60Qx_49 = tagClassMatches_0_nifb6mq6y1(X60Qx_48, 1);
                      if ((!X60Qx_49)){
                        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                          .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                        );
                        string_0_sysvq0asl X60Qdesugar_8 = dollarX60Q_TagClass_0_nifb6mq6y1(1);
                        NifKind_0_nif81dubp1 X60Qx_50 = kind_0_nifb6mq6y1(pragmas_0);
                        string_0_sysvq0asl X60Qdesugar_9 = dollarX60Q_NifKind_0_nif81dubp1(X60Qx_50);
                        NI32 X60Qx_51 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I5400270834280783131_nim30udrv)}
                        );
                        NI32 X60Qx_52 = len_4_sysvq0asl(X60Qdesugar_8);
                        NI32 X60Qx_53 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I4775150051315309461_decqocs071)}
                        );
                        NI32 X60Qx_54 = len_4_sysvq0asl(X60Qdesugar_9);
                        NI32 X60Qx_55 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I3085349504904670868_decqocs071)}
                        );
                        string_0_sysvq0asl X60Qdesugar_10 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_51 + X60Qx_52)) + X60Qx_53)) + X60Qx_54)) + X60Qx_55)));
                        add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
                          .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I5400270834280783131_nim30udrv)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_10), X60Qdesugar_8);
                        add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
                          .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I4775150051315309461_decqocs071)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_10), X60Qdesugar_9);
                        add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
                          .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I3085349504904670868_decqocs071)}
                        );
                        write_0_syn1lfpjv(stdout, X60Qdesugar_10);
                        write_7_syn1lfpjv(stdout, (NC8)'\012');
                        quit_0_syn1lfpjv(1);
                        nimStrDestroy(X60Qdesugar_10);
                        nimStrDestroy(X60Qdesugar_9);
                        nimStrDestroy(X60Qdesugar_8);}
                      inc_0_nifb6mq6y1((&pragmas_0));
                      NB8 X60Qx_56;
                      NifKind_0_nif81dubp1 X60Qx_57 = kind_0_nifb6mq6y1(pragmas_0);
                      if ((!(X60Qx_57 == 12))){
                        NifKind_0_nif81dubp1 X60Qx_58 = kind_0_nifb6mq6y1(pragmas_0);
                        X60Qx_56 = (X60Qx_58 == 4);}
                      else {
                        X60Qx_56 = NIM_FALSE;}
                      if (X60Qx_56){
                        NU32 methodSym_11 = symId_0_nifb6mq6y1(pragmas_0);
                        add_0_Izy6sw41_vtanlalcx((&result_4), (MethodIndexEntry_0_sempjk6bn1){
                          .fn_0 = methodSym_11, .signature_0 = signature_11}
                        );
                        NifKind_0_nif81dubp1 X60Qx_59 = kind_0_nifb6mq6y1(pragmas_0);
                        NB8 X60Qx_60 = tagClassMatches_0_nifb6mq6y1(X60Qx_59, 1);
                        if ((!X60Qx_60)){
                          write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                            .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                          );
                          string_0_sysvq0asl X60Qdesugar_11 = dollarX60Q_TagClass_0_nifb6mq6y1(1);
                          NifKind_0_nif81dubp1 X60Qx_61 = kind_0_nifb6mq6y1(pragmas_0);
                          string_0_sysvq0asl X60Qdesugar_12 = dollarX60Q_NifKind_0_nif81dubp1(X60Qx_61);
                          NI32 X60Qx_62 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I5400270834280783131_nim30udrv)}
                          );
                          NI32 X60Qx_63 = len_4_sysvq0asl(X60Qdesugar_11);
                          NI32 X60Qx_64 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I4775150051315309461_decqocs071)}
                          );
                          NI32 X60Qx_65 = len_4_sysvq0asl(X60Qdesugar_12);
                          NI32 X60Qx_66 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I3085349504904670868_decqocs071)}
                          );
                          string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_62 + X60Qx_63)) + X60Qx_64)) + X60Qx_65)) + X60Qx_66)));
                          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                            .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I5400270834280783131_nim30udrv)}
                          );
                          add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_11);
                          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                            .bytes_0 = 1663056638u, .more_0 = (&strlit_0_I4775150051315309461_decqocs071)}
                          );
                          add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
                          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                            .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I3085349504904670868_decqocs071)}
                          );
                          write_0_syn1lfpjv(stdout, X60Qdesugar_13);
                          write_7_syn1lfpjv(stdout, (NC8)'\012');
                          quit_0_syn1lfpjv(1);
                          nimStrDestroy(X60Qdesugar_13);
                          nimStrDestroy(X60Qdesugar_12);
                          nimStrDestroy(X60Qdesugar_11);}
                        inc_0_nifb6mq6y1((&pragmas_0));}}
                    {
                      while (NIM_TRUE){
                        NifKind_0_nif81dubp1 X60Qx_67 = kind_0_nifb6mq6y1(pragmas_0);
                        if ((!(X60Qx_67 == 12))){
                          skip_0_nifb6mq6y1((&pragmas_0));}
                        else {
                          break;}}}
                    whileStmtLabel_2: ;
                    NifKind_0_nif81dubp1 X60Qx_68 = kind_0_nifb6mq6y1(pragmas_0);
                    if ((!(X60Qx_68 == 12))){
                      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                      );
                      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I13237575353761119172_explnj22x1)}
                      );
                      write_7_syn1lfpjv(stdout, (NC8)'\012');
                      quit_0_syn1lfpjv(1);}
                    inc_0_nifb6mq6y1((&pragmas_0));}
                  else {
                    skip_0_nifb6mq6y1((&pragmas_0));}}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            NifKind_0_nif81dubp1 X60Qx_69 = kind_0_nifb6mq6y1(pragmas_0);
            if ((!(X60Qx_69 == 12))){
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
              );
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I13237575353761119172_explnj22x1)}
              );
              write_7_syn1lfpjv(stdout, (NC8)'\012');
              quit_0_syn1lfpjv(1);}
            inc_0_nifb6mq6y1((&pragmas_0));}
          else {
            skip_0_nifb6mq6y1((&pragmas_0));}}
        else {
          break;}}}
    whileStmtLabel_0: ;
    NifKind_0_nif81dubp1 X60Qx_70 = kind_0_nifb6mq6y1(pragmas_0);
    if ((!(X60Qx_70 == 12))){
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
      );
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I13237575353761119172_explnj22x1)}
      );
      write_7_syn1lfpjv(stdout, (NC8)'\012');
      quit_0_syn1lfpjv(1);}
    inc_0_nifb6mq6y1((&pragmas_0));}
  eQdestroy_0_nifb6mq6y1((&pragmas_0));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&typeDecl_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_4;
  eQdestroy_0_nifb6mq6y1((&pragmas_0));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&typeDecl_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_4;}
static inline void add_0_Izy6sw41_vtanlalcx(seq_0_Idl3iy1_comaa5xpt1* s_7, MethodIndexEntry_0_sempjk6bn1 elem_3){
  NI32 L_0 = (*s_7).len_0;
  NI32 X60Qx_87 = capInBytes_0_Irxk45k1_comaa5xpt1((*s_7));
  if (X60Qx_87 < ((NI32)(((NI32)(L_0 * sizeof(MethodIndexEntry_0_sempjk6bn1))) + sizeof(MethodIndexEntry_0_sempjk6bn1)))){
    NB8 X60Qx_88 = resize_0_I1ya9sv1_vtanlalcx(s_7, 1);
    if ((!X60Qx_88)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_7).len_0));
  (*s_7).data_0[L_0] = elem_3;}
NB8 resize_0_I1ya9sv1_vtanlalcx(seq_0_Idl3iy1_comaa5xpt1* dest_2, NI32 addedElements_2){
  NB8 result_12;
  NI32 X60Qx_103 = capInBytes_0_Irxk45k1_comaa5xpt1((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_103 / sizeof(MethodIndexEntry_0_sempjk6bn1)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_1 = memSizeInBytes_0_Ikui0mk_comaa5xpt1(newCap_0);
  void* X60Qx_104 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_1);
  (*dest_2).data_0 = ((MethodIndexEntry_0_sempjk6bn1*)X60Qx_104);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_1);
    result_12 = NIM_FALSE;}
  else {
    result_12 = NIM_TRUE;}
  return result_12;}
void X60Qini_0_vtanlalcx(void){
  if (X60QiniGuard_0_vtanlalcx){
    return;}
  X60QiniGuard_0_vtanlalcx = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_nifa1znj21();
  X60Qini_0_symkyk35i1();
  X60Qini_0_trellwskh();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_prorcx25w1();
  X60Qini_0_typ6lv6cu1();
  X60Qini_0_renqb5hy11();
  X60Qini_0_sigekpubi1();
  X60Qini_0_sempjk6bn1();
  X60Qini_0_typurxiqa1();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_typ9rqp2b();}
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
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
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
static inline NimonyPragma_0_nimry5ra91 pragmaKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_4){
  NimonyPragma_0_nimry5ra91 result_2;
  NifKind_0_nif81dubp1 X60Qx_15 = kind_0_nifb6mq6y1(c_4);
  if (X60Qx_15 == 11){
    NU32 X60Qx_16 = tag_0_nifb6mq6y1(c_4);
    TagEnum_0_tagygirdh1 e_1 = ((TagEnum_0_tagygirdh1)X60Qx_16);
    NB8 X60Qx_17 = rawTagIsNimonyPragma_0_nimry5ra91(e_1);
    if (X60Qx_17){
      result_2 = ((NimonyPragma_0_nimry5ra91)e_1);}
    else {
      result_2 = 0;}}
  else {
    NifKind_0_nif81dubp1 X60Qx_18 = kind_0_nifb6mq6y1(c_4);
    if (X60Qx_18 == 3){
      NU32 X60Qx_19 = litId_0_nifb6mq6y1(c_4);
      string_0_sysvq0asl* X60Qx_20 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_19);
      NU32 tagId_0 = getOrIncl_0_Is83dq9_buiyylk1h1((&pool_0_nifh7u8pu1.tags_0), (*X60Qx_20));
      NB8 X60Qx_21;
      NB8 X60Qx_22;
      if (0 <= ((NI32)tagId_0)){
        X60Qx_22 = (((NI32)tagId_0) <= ((NI32)341));}
      else {
        X60Qx_22 = NIM_FALSE;}
      if (X60Qx_22){
        NB8 X60Qx_23 = rawTagIsNimonyPragma_0_nimry5ra91(((TagEnum_0_tagygirdh1)tagId_0));
        X60Qx_21 = X60Qx_23;}
      else {
        X60Qx_21 = NIM_FALSE;}
      if (X60Qx_21){
        result_2 = ((NimonyPragma_0_nimry5ra91)tagId_0);}
      else {
        result_2 = 0;}}
    else {
      result_2 = 0;}}
  return result_2;}
static inline NimonyOther_0_nimry5ra91 substructureKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_6){
  NimonyOther_0_nimry5ra91 result_4;
  PackedToken_0_nifh7u8pu1 X60Qx_28 = load_0_nifb6mq6y1(c_6);
  NimonyOther_0_nimry5ra91 X60Qx_29 = substructureKind_0_nim30udrv(X60Qx_28);
  result_4 = X60Qx_29;
  return result_4;}
static inline NimonyStmt_0_nimry5ra91 stmtKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_3){
  NimonyStmt_0_nimry5ra91 result_1;
  PackedToken_0_nifh7u8pu1 X60Qx_13 = load_0_nifb6mq6y1(c_3);
  NimonyStmt_0_nimry5ra91 X60Qx_14 = stmtKind_0_nim30udrv(X60Qx_13);
  result_1 = X60Qx_14;
  return result_1;}
static inline NimonyExpr_0_nimry5ra91 exprKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_10){
  NimonyExpr_0_nimry5ra91 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_46 = load_0_nifb6mq6y1(c_10);
  NimonyExpr_0_nimry5ra91 X60Qx_47 = exprKind_0_nim30udrv(X60Qx_46);
  result_8 = X60Qx_47;
  return result_8;}
static inline NimonyType_0_nimry5ra91 typeKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_7){
  NimonyType_0_nimry5ra91 result_5;
  NifKind_0_nif81dubp1 X60Qx_30 = kind_0_nifb6mq6y1(c_7);
  if (X60Qx_30 == 11){
    NU32 X60Qx_31 = tag_0_nifb6mq6y1(c_7);
    NB8 X60Qx_32 = rawTagIsNimonyType_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_31));
    if (X60Qx_32){
      NU32 X60Qx_33 = tag_0_nifb6mq6y1(c_7);
      result_5 = ((NimonyType_0_nimry5ra91)((TagEnum_0_tagygirdh1)X60Qx_33));}
    else {
      result_5 = 0;}}
  else {
    NifKind_0_nif81dubp1 X60Qx_34 = kind_0_nifb6mq6y1(c_7);
    if (X60Qx_34 == 2){
      result_5 = 118;}
    else {
      result_5 = 0;}}
  return result_5;}
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
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7){
  NU32 result_10;
  PackedToken_0_nifh7u8pu1 X60Qx_24 = load_0_nifb6mq6y1(c_7);
  NU32 X60Qx_25 = litId_0_nifh7u8pu1(X60Qx_24);
  result_10 = X60Qx_25;
  return result_10;}
static inline NB8 tagClassMatches_0_nifb6mq6y1(NifKind_0_nif81dubp1 k_1, TagClass_0_nifb6mq6y1 expected_0){
  NB8 result_51;
  NB8 X60Qx_3;
  switch (expected_0){
    case 0:
    {
      X60Qx_3 = (!(k_1 == 1));}
    break;
    case 1:
    {
      NU16 X60Qdesugar_24 = 4098u;
      NU64 X60Qdesugar_25 = ((NU)k_1);
      X60Qx_3 = (!(((NU16)(X60Qdesugar_24 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_25 & 15u)))))) != 0u));}
    break;
    case 2:
    {
      NU16 X60Qdesugar_26 = 2052u;
      NU64 X60Qdesugar_27 = ((NU)k_1);
      X60Qx_3 = (((NU16)(X60Qdesugar_26 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_27 & 15u)))))) != 0u);}
    break;
    case 3:
    {
      NU16 X60Qdesugar_28 = 2076u;
      NU64 X60Qdesugar_29 = ((NU)k_1);
      X60Qx_3 = (((NU16)(X60Qdesugar_28 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_29 & 15u)))))) != 0u);}
    break;}
  result_51 = X60Qx_3;
  return result_51;}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
static inline NB8 rawTagIsNimonyPragma_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_4){
  NB8 result_9;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_8 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 1u, 128u, 0u, 0u, 4u, 0u, 0u, 2u, 0u, 0u, 112u, 202u, 2u, 0u, 2u, 0u, 0u, 0u, 0u, 16u, 254u, 255u, 255u, 7u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 128u, 255u, 127u, 240u, 255u, 31u}}
  ;
  NU64 X60Qdesugar_9 = ((NU)raw_4);
  result_9 = (((NU8)(X60Qdesugar_8.a[((NU)(X60Qdesugar_9 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_9 & 7u)))))) != 0u);
  return result_9;}
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
static inline NimonyOther_0_nimry5ra91 substructureKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_5){
  NimonyOther_0_nimry5ra91 result_3;
  NB8 X60Qx_24;
  if (((NifKind_0_nif81dubp1)((NU32)(c_5.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_25 = tag_0_nifh7u8pu1(c_5);
    NB8 X60Qx_26 = rawTagIsNimonyOther_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_25));
    X60Qx_24 = X60Qx_26;}
  else {
    X60Qx_24 = NIM_FALSE;}
  if (X60Qx_24){
    NU32 X60Qx_27 = tag_0_nifh7u8pu1(c_5);
    result_3 = ((NimonyOther_0_nimry5ra91)X60Qx_27);}
  else {
    result_3 = 0;}
  return result_3;}
static inline NimonyStmt_0_nimry5ra91 stmtKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_2){
  NimonyStmt_0_nimry5ra91 result_0;
  NB8 X60Qx_9;
  if (((NifKind_0_nif81dubp1)((NU32)(c_2.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_10 = tag_0_nifh7u8pu1(c_2);
    NB8 X60Qx_11 = rawTagIsNimonyStmt_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_10));
    X60Qx_9 = X60Qx_11;}
  else {
    X60Qx_9 = NIM_FALSE;}
  if (X60Qx_9){
    NU32 X60Qx_12 = tag_0_nifh7u8pu1(c_2);
    result_0 = ((NimonyStmt_0_nimry5ra91)((TagEnum_0_tagygirdh1)X60Qx_12));}
  else {
    result_0 = 0;}
  return result_0;}
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
static inline NB8 rawTagIsNimonyType_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_2){
  NB8 result_5;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_4 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      10u, 0u, 22u, 0u, 0u, 0u, 0u, 0u, 192u, 31u, 0u, 0u, 0u, 28u, 254u, 1u, 0u, 2u, 0u, 0u, 8u, 0u, 0u, 254u, 255u, 255u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_5 = ((NU)raw_2);
  result_5 = (((NU8)(X60Qdesugar_4.a[((NU)(X60Qdesugar_5 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_5 & 7u)))))) != 0u);
  return result_5;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
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
static inline NB8 rawTagIsNimonyOther_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_3){
  NB8 result_7;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 14u, 0u, 192u, 0u, 0u, 48u, 2u, 62u, 0u, 0u, 15u, 134u, 1u, 0u, 0u, 0u, 16u, 0u, 0u, 0u, 96u, 188u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_7 = ((NU)raw_3);
  result_7 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_7 & 7u)))))) != 0u);
  return result_7;}
static inline NB8 rawTagIsNimonyStmt_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_1){
  NB8 result_3;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 204u, 253u, 193u, 127u, 204u, 241u, 227u, 0u, 0u, 0u, 0u, 48u, 252u, 251u, 0u, 0u, 64u, 0u, 0u, 0u, 0u, 0u, 48u, 0u, 0u, 30u, 0u, 0u, 0u, 0u, 0u, 63u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_3 = ((NU)raw_1);
  result_3 = (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u);
  return result_3;}
static inline NB8 rawTagIsNimonyExpr_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_0){
  NB8 result_1;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      254u, 243u, 255u, 127u, 255u, 255u, 15u, 0u, 0u, 0u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 32u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 248u, 255u, 255u, 255u, 255u, 255u, 255u, 127u, 0u, 0u, 128u, 15u, 0u, 32u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)raw_0);
  result_1 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u);
  return result_1;}
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
