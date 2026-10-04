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
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49zov3yo_ide5ljwgh1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49zov3yo_ide5ljwgh1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX4eimonyX50ragma0nimry5ra91_ide5ljwgh1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX4eimonyX50ragma0nimry5ra91_ide5ljwgh1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct seq_0_Ih84czw_ide5ljwgh1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49zov3yo_ide5ljwgh1* data_0;}
seq_0_Ih84czw_ide5ljwgh1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Ifffgxj1_ide5ljwgh1{
  seq_0_Ih84czw_ide5ljwgh1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ifffgxj1_ide5ljwgh1;
typedef struct openArray_0_Imjppfb_ide5ljwgh1{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Imjppfb_ide5ljwgh1;
typedef struct seq_0_I4qk1cc1_ide5ljwgh1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX4eimonyX50ragma0nimry5ra91_ide5ljwgh1* data_0;}
seq_0_I4qk1cc1_ide5ljwgh1;
typedef struct Table_0_Iszoog6_ide5ljwgh1{
  seq_0_I4qk1cc1_ide5ljwgh1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iszoog6_ide5ljwgh1;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49zov3yo_ide5ljwgh1{
  NU32 fld_0;
  seq_0_Izov3yo_ast8ri79k fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49zov3yo_ide5ljwgh1;
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
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX4eimonyX50ragma0nimry5ra91_ide5ljwgh1{
  NU32 fld_0;
  NimonyPragma_0_nimry5ra91 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX4eimonyX50ragma0nimry5ra91_ide5ljwgh1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
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
static inline NI32 capInBytes_0_I2v1dsn1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_29);
extern NB8 resize_0_Itvf2zj1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* dest_3, NI32 addedElements_3);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_tagygirdh1(void);
extern void X60Qini_0_nimry5ra91(void);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
Table_0_Ifffgxj1_ide5ljwgh1 styleGroups_0_ide5ljwgh1;
Table_0_Iszoog6_ide5ljwgh1 pragmaStyleIndex_0_ide5ljwgh1;
NB8 X60QiniGuard_0_ide5ljwgh1;
static inline void add_0_Ixkocf1_ide5ljwgh1(seq_0_Izov3yo_ast8ri79k* s_14, NU32 elem_6){
  NI32 L_0 = (*s_14).len_0;
  NI32 X60Qx_51 = capInBytes_0_I2v1dsn1_ast8ri79k((*s_14));
  if (X60Qx_51 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_52 = resize_0_Itvf2zj1_ast8ri79k(s_14, 1);
    if ((!X60Qx_52)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_14).len_0));
  (*s_14).data_0[L_0] = elem_6;}
static inline void eQwasMoved_1_Ipckk9c1_ide5ljwgh1(seq_0_Ih84czw_ide5ljwgh1* s_73){
  (*s_73).len_0 = 0;
  (*s_73).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_In9sz18_ide5ljwgh1(seq_0_I4qk1cc1_ide5ljwgh1* s_75){
  (*s_75).len_0 = 0;
  (*s_75).data_0 = NIM_NIL;}
void eQwasmovedQ_SX54able0X49fffgxj1_0_ide5ljwgh1(Table_0_Ifffgxj1_ide5ljwgh1* dest_0){
  eQwasMoved_1_Ipckk9c1_ide5ljwgh1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQwasmovedQ_SX54able0X49szoog6_0_ide5ljwgh1(Table_0_Iszoog6_ide5ljwgh1* dest_0){
  eQwasMoved_1_In9sz18_ide5ljwgh1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void X60Qini_0_ide5ljwgh1(void){
  if (X60QiniGuard_0_ide5ljwgh1){
    return;}
  X60QiniGuard_0_ide5ljwgh1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_tagygirdh1();
  X60Qini_0_nimry5ra91();
  eQwasmovedQ_SX54able0X49fffgxj1_0_ide5ljwgh1((&styleGroups_0_ide5ljwgh1));
  eQwasmovedQ_SX54able0X49szoog6_0_ide5ljwgh1((&pragmaStyleIndex_0_ide5ljwgh1));}
static inline NI32 capInBytes_0_I2v1dsn1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_29){
  NI32 result_21;
  NI32 X60Qx_1;
  if ((!(s_29.data_0 == NIM_NIL))){
    NI32 X60Qx_76 = allocatedSize_0_sysvq0asl(((void*)((void*)s_29.data_0)));
    X60Qx_1 = X60Qx_76;}
  else {
    X60Qx_1 = 0;}
  result_21 = X60Qx_1;
  return result_21;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
