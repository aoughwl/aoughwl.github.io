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
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1 X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
typedef struct seq_0_I3ump14_aow7lb5cq1 seq_0_I3ump14_aow7lb5cq1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef NU8 AbiKind_0_layptix6a1;

#define akInt_0_layptix6a1 ((NU8)0)
#define akUInt_0_layptix6a1 ((NU8)1)
#define akFloat_0_layptix6a1 ((NU8)2)
#define akChar_0_layptix6a1 ((NU8)3)
#define akBool_0_layptix6a1 ((NU8)4)
#define akPtr_0_layptix6a1 ((NU8)5)
#define akRef_0_layptix6a1 ((NU8)6)
#define akClosure_0_layptix6a1 ((NU8)7)
#define akEnum_0_layptix6a1 ((NU8)8)
#define akArray_0_layptix6a1 ((NU8)9)
#define akObject_0_layptix6a1 ((NU8)10)
#define akTuple_0_layptix6a1 ((NU8)11)
#define akVariant_0_layptix6a1 ((NU8)12)
#define akDistinct_0_layptix6a1 ((NU8)13)
#define akString_0_layptix6a1 ((NU8)14)
#define akSeq_0_layptix6a1 ((NU8)15)
#define akSet_0_layptix6a1 ((NU8)16)
#define akRange_0_layptix6a1 ((NU8)17)
#define akUnchecked_0_layptix6a1 ((NU8)18)
typedef struct seq_0_I3ump14_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** data_0;}
seq_0_I3ump14_aow7lb5cq1;
typedef struct seq_0_Ie088gc_heapjafyf1{
  NI32 len_0;
  seq_0_I3ump14_aow7lb5cq1* data_0;}
seq_0_Ie088gc_heapjafyf1;
typedef struct TypeDesc_Obj_0_layptix6a1{
  AbiKind_0_layptix6a1 kind_0;
  NI32 bits_0;
  NI32 count_0;
  NI32 enumLo_0;
  NI32 enumHi_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_0;
  NB8 rtti_0;
  NB8 packed_0;
  NB8 union_0;
  NB8 incomplete_0;
  seq_0_I3ump14_aow7lb5cq1 fields_0;
  seq_0_Ie088gc_heapjafyf1 branches_0;}
TypeDesc_Obj_0_layptix6a1;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct openArray_0_I3ca6t4_layptix6a1{
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** a_0;
  NI32 len_0;}
openArray_0_I3ca6t4_layptix6a1;
typedef struct openArray_0_Iwtfxrw_layptix6a1{
  seq_0_I3ump14_aow7lb5cq1* a_0;
  NI32 len_0;}
openArray_0_Iwtfxrw_layptix6a1;
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1{
  NI r_00;
  TypeDesc_Obj_0_layptix6a1 d_00;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAuS8ZS3_aow2h993l1{
  NU8 a[3];}
X60Qt_0_IAarrayAuS8ZS3_aow2h993l1;
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
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sizeAlign_1_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3, NI32 ptrSize_2);
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8);
static inline openArray_0_Iwtfxrw_layptix6a1 toOpenArray_1_I5d1kzx1_layptix6a1(seq_0_Ie088gc_heapjafyf1 s_10);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20);
static inline NI32 len_6_I0tpktl1_layptix6a1(openArray_0_I3ca6t4_layptix6a1 a_18);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_10_Ikixp7k_layptix6a1(openArray_0_I3ca6t4_layptix6a1 x_3, NI32 idx_2);
static inline seq_0_I3ump14_aow7lb5cq1* rawData_0_I2kxyg9_layptix6a1(seq_0_Ie088gc_heapjafyf1 s_21);
static inline NI32 len_6_Ia8vzko1_layptix6a1(openArray_0_Iwtfxrw_layptix6a1 a_19);
static inline seq_0_I3ump14_aow7lb5cq1* getQ_10_Ih94lt3_layptix6a1(openArray_0_Iwtfxrw_layptix6a1 x_5, NI32 idx_3);
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0);
void eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_I3ump14_aow7lb5cq1 newSeqUninit_0_I978ktq1_aow7lb5cq1(NI32 size_30);
static inline seq_0_Ie088gc_heapjafyf1 newSeqUninit_0_Inwn9fa_heapjafyf1(NI32 size_4);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern void eQdestroy_1_I87nkt8_heapjafyf1(seq_0_Ie088gc_heapjafyf1 s_7);
extern void eQdestroy_1_Iqg9snl1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_105);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void X60Qini_0_sysvq0asl(void);
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 memSizeInBytes_0_Ilxpm6v1_heapjafyf1(NI32 size_7);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
LongString_0_sysvq0asl const strlit_0_I7735454720947104390_layptix6a1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akInt"}
;
LongString_0_sysvq0asl const strlit_0_I6565186732712923749_layptix6a1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akUInt"}
;
LongString_0_sysvq0asl const strlit_0_I13689394416128398256_layptix6a1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akFloat"}
;
LongString_0_sysvq0asl const strlit_0_I9666933501308160785_layptix6a1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akChar"}
;
LongString_0_sysvq0asl const strlit_0_I14108734714730971356_layptix6a1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akBool"}
;
LongString_0_sysvq0asl const strlit_0_I12048625666331340961_layptix6a1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akPtr"}
;
LongString_0_sysvq0asl const strlit_0_I2040604839393697855_layptix6a1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akRef"}
;
LongString_0_sysvq0asl const strlit_0_I18285299094003008571_layptix6a1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akClosure"}
;
LongString_0_sysvq0asl const strlit_0_I14990720797570973303_layptix6a1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akEnum"}
;
LongString_0_sysvq0asl const strlit_0_I16169708038146955003_layptix6a1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akArray"}
;
LongString_0_sysvq0asl const strlit_0_I13885868964772759675_layptix6a1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akObject"}
;
LongString_0_sysvq0asl const strlit_0_I9668535620207736932_layptix6a1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akTuple"}
;
LongString_0_sysvq0asl const strlit_0_I2485001036664277524_layptix6a1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akVariant"}
;
LongString_0_sysvq0asl const strlit_0_I5380251706626467957_layptix6a1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akDistinct"}
;
LongString_0_sysvq0asl const strlit_0_I3585514175062331962_layptix6a1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akString"}
;
LongString_0_sysvq0asl const strlit_0_I5217741920119826479_layptix6a1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akSeq"}
;
LongString_0_sysvq0asl const strlit_0_I8624607063947935631_layptix6a1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akSet"}
;
LongString_0_sysvq0asl const strlit_0_I8154487068008003501_layptix6a1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akRange"}
;
LongString_0_sysvq0asl const strlit_0_I5476738314670072395_layptix6a1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "akUnchecked"}
;
NB8 X60QiniGuard_0_layptix6a1;
string_0_sysvq0asl dollarX60Q_AbiKind_0_layptix6a1(AbiKind_0_layptix6a1 e_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  switch (e_0){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1231774206u, .more_0 = (&strlit_0_I7735454720947104390_layptix6a1)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1433100798u, .more_0 = (&strlit_0_I6565186732712923749_layptix6a1)}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1181442558u, .more_0 = (&strlit_0_I13689394416128398256_layptix6a1)}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131110910u, .more_0 = (&strlit_0_I9666933501308160785_layptix6a1)}
      ;}
    break;
    case 4:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1114333694u, .more_0 = (&strlit_0_I14108734714730971356_layptix6a1)}
      ;}
    break;
    case 5:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1349214718u, .more_0 = (&strlit_0_I12048625666331340961_layptix6a1)}
      ;}
    break;
    case 6:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1382769150u, .more_0 = (&strlit_0_I2040604839393697855_layptix6a1)}
      ;}
    break;
    case 7:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131110910u, .more_0 = (&strlit_0_I18285299094003008571_layptix6a1)}
      ;}
    break;
    case 8:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1164665342u, .more_0 = (&strlit_0_I14990720797570973303_layptix6a1)}
      ;}
    break;
    case 9:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1097556478u, .more_0 = (&strlit_0_I16169708038146955003_layptix6a1)}
      ;}
    break;
    case 10:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1332437502u, .more_0 = (&strlit_0_I13885868964772759675_layptix6a1)}
      ;}
    break;
    case 11:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1416323582u, .more_0 = (&strlit_0_I9668535620207736932_layptix6a1)}
      ;}
    break;
    case 12:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1449878014u, .more_0 = (&strlit_0_I2485001036664277524_layptix6a1)}
      ;}
    break;
    case 13:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1147888126u, .more_0 = (&strlit_0_I5380251706626467957_layptix6a1)}
      ;}
    break;
    case 14:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399546366u, .more_0 = (&strlit_0_I3585514175062331962_layptix6a1)}
      ;}
    break;
    case 15:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399546366u, .more_0 = (&strlit_0_I5217741920119826479_layptix6a1)}
      ;}
    break;
    case 16:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399546366u, .more_0 = (&strlit_0_I8624607063947935631_layptix6a1)}
      ;}
    break;
    case 17:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1382769150u, .more_0 = (&strlit_0_I8154487068008003501_layptix6a1)}
      ;}
    break;
    case 18:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1433100798u, .more_0 = (&strlit_0_I5476738314670072395_layptix6a1)}
      ;}
    break;}
  return result_0;}
static inline NI32 align_0_layptix6a1(NI32 address_0, NI32 alignment_0){
  NI32 result_1;
  result_1 = ((NI32)(((NI32)(address_0 + ((NI32)(alignment_0 - 1)))) & ((NI32) ~ ((NI32)(alignment_0 - 1)))));
  return result_1;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* enumDesc_0_layptix6a1(NI32 lo_0, NI32 hi_0, NI32 bits_1){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* result_3;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((&result_3));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(result_3);
  void* X60Qx_25 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_1 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_25);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_26 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_27 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_1) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 8, .bits_0 = bits_1, .count_0 = ((NI32)0), .enumLo_0 = lo_0, .enumHi_0 = hi_0, .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_26, .branches_0 = X60Qx_27}}
  ;
  result_3 = X60Qtmp_1;
  return result_3;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 enumSizeAlign_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_0){
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 result_12;
  if (0 < (*t_0).d_00.bits_0){
    NI32 b_0 = ((NI32)((*t_0).d_00.bits_0 / 8));
    result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
      .fld_0 = b_0, .fld_1 = b_0}
    ;
    return result_12;}
  if ((*t_0).d_00.enumLo_0 < 0){
    result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
      .fld_0 = 4, .fld_1 = 4}
    ;
    return result_12;}
  if ((*t_0).d_00.enumHi_0 < ((NI32)(1 << 8))){
    result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
      .fld_0 = 1, .fld_1 = 1}
    ;
    return result_12;}
  else {
    if ((*t_0).d_00.enumHi_0 < ((NI32)(1 << 16))){
      result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = 2, .fld_1 = 2}
      ;
      return result_12;}
    else {
      if (((NI64)(*t_0).d_00.enumHi_0) < ((NI64)(((NI64)1) << 32))){
        result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
          .fld_0 = 4, .fld_1 = 4}
        ;
        return result_12;}
      else {
        result_12 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
          .fld_0 = 8, .fld_1 = 8}
        ;
        return result_12;}}}
  return result_12;}
NI32 div8Roundup_0_layptix6a1(NI32 a_0){
  NI32 result_13;
  NI32 X60Qx_0;
  if (((NI32)(a_0 & 7)) == 0){
    X60Qx_0 = ((NI32)(((NI32)a_0) >> ((NU32)3)));}
  else {
    X60Qx_0 = ((NI32)(((NI32)(((NI32)a_0) >> ((NU32)3))) + 1));}
  result_13 = X60Qx_0;
  return result_13;}
NI32 setSizeInBytes_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_4){
  NI32 result_14;
  if (base_4 == NIM_NIL){
    return 0;}
  NI64 X60Qx_1;
  switch ((*base_4).d_00.kind_0){
    case 0:
    case 1:
    {
      NI64 X60Qx_2;
      if ((*base_4).d_00.bits_0 <= 0){
        X60Qx_2 = 0;}
      else {
        X60Qx_2 = (*base_4).d_00.bits_0;}
      NI32 bits_2 = X60Qx_2;
      NI64 X60Qx_3;
      NB8 X60Qx_59;
      if (bits_2 <= 0){
        X60Qx_59 = NIM_TRUE;}
      else {
        X60Qx_59 = (24 < bits_2);}
      if (X60Qx_59){
        X60Qx_3 = 0;}
      else {
        X60Qx_3 = ((NI32)(1 << ((NI32)(bits_2 - 3))));}
      X60Qx_1 = X60Qx_3;}
    break;
    case 3:
    {
      X60Qx_1 = ((NI32)(256 / 8));}
    break;
    case 4:
    {
      X60Qx_1 = 1;}
    break;
    case 8:
    {
      NI64 X60Qx_4;
      if ((*base_4).d_00.enumHi_0 < 0){
        X60Qx_4 = 0;}
      else {
        NB8 X60Qx_60;
        NB8 X60Qx_61;
        if ((*base_4).d_00.bits_0 <= 0){
          X60Qx_61 = ((*base_4).d_00.enumHi_0 == 0);}
        else {
          X60Qx_61 = NIM_FALSE;}
        if (X60Qx_61){
          X60Qx_60 = ((*base_4).d_00.enumLo_0 == 0);}
        else {
          X60Qx_60 = NIM_FALSE;}
        if (X60Qx_60){
          X60Qx_4 = 0;}
        else {
          NI32 n_0 = div8Roundup_0_layptix6a1(((NI32)((*base_4).d_00.enumHi_0 + 1)));
          NI32 baseBytes_0 = ((NI32)((*base_4).d_00.bits_0 / 8));
          NB8 X60Qx_62;
          if (n_0 < baseBytes_0){
            X60Qx_62 = (0 <= (*base_4).d_00.enumLo_0);}
          else {
            X60Qx_62 = NIM_FALSE;}
          if (X60Qx_62){
            n_0 = baseBytes_0;}
          X60Qx_4 = n_0;}}
      X60Qx_1 = X60Qx_4;}
    break;
    case 17:
    {
      NI64 X60Qx_5;
      if ((*base_4).d_00.enumHi_0 < 0){
        X60Qx_5 = 0;}
      else {
        NI32 X60Qx_63 = div8Roundup_0_layptix6a1(((NI32)((*base_4).d_00.enumHi_0 + 1)));
        X60Qx_5 = X60Qx_63;}
      X60Qx_1 = X60Qx_5;}
    break;
    case 13:
    {
      NI32 X60Qx_64 = setSizeInBytes_0_layptix6a1((*base_4).d_00.elem_0);
      X60Qx_1 = X60Qx_64;}
    break;
    default:
    {
      X60Qx_1 = 0;}
    break;}
  result_14 = X60Qx_1;
  return result_14;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 objectPrefix_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_2, NI32 ptrSize_1){
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 result_15;
  if ((!((*t_2).d_00.base_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_65 = sizeAlign_1_layptix6a1((*t_2).d_00.base_0, ptrSize_1);
    result_15 = X60Qx_65;
    NI32 X60Qx_66 = max_2_sysvq0asl(result_15.fld_1, 1);
    result_15.fld_1 = X60Qx_66;}
  else {
    if ((*t_2).d_00.rtti_0){
      result_15 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = ptrSize_1, .fld_1 = ptrSize_1}
      ;}
    else {
      result_15 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = 0, .fld_1 = 1}
      ;}}
  return result_15;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sizeAlign_1_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3, NI32 ptrSize_2){
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 result_16;
  switch ((*t_3).d_00.kind_0){
    case 0:
    case 1:
    {
      NI32 X60Qx_6;
      if ((*t_3).d_00.bits_0 <= 0){
        X60Qx_6 = ptrSize_2;}
      else {
        X60Qx_6 = ((NI32)((*t_3).d_00.bits_0 / 8));}
      NI32 b_1 = X60Qx_6;
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = b_1, .fld_1 = b_1}
      ;}
    break;
    case 2:
    {
      NI64 X60Qx_7;
      if ((*t_3).d_00.bits_0 <= 0){
        X60Qx_7 = 8;}
      else {
        X60Qx_7 = ((NI32)((*t_3).d_00.bits_0 / 8));}
      NI32 b_2 = X60Qx_7;
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = b_2, .fld_1 = b_2}
      ;}
    break;
    case 3:
    case 4:
    {
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = 1, .fld_1 = 1}
      ;}
    break;
    case 5:
    case 6:
    {
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = ptrSize_2, .fld_1 = ptrSize_2}
      ;}
    break;
    case 7:
    {
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = ((NI32)(2 * ptrSize_2)), .fld_1 = ptrSize_2}
      ;}
    break;
    case 8:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_67 = enumSizeAlign_0_layptix6a1(t_3);
      result_16 = X60Qx_67;}
    break;
    case 13:
    case 17:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_68 = sizeAlign_1_layptix6a1((*t_3).d_00.elem_0, ptrSize_2);
      result_16 = X60Qx_68;}
    break;
    case 16:
    {
      NI32 X60Qx_69 = setSizeInBytes_0_layptix6a1((*t_3).d_00.elem_0);
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = X60Qx_69, .fld_1 = 1}
      ;}
    break;
    case 18:
    {
      NI32 X60Qx_8;
      if ((!((*t_3).d_00.elem_0 == NIM_NIL))){
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_70 = sizeAlign_1_layptix6a1((*t_3).d_00.elem_0, ptrSize_2);
        X60Qx_8 = X60Qx_70.fld_1;}
      else {
        X60Qx_8 = 1;}
      NI32 a_1 = X60Qx_8;
      NI32 X60Qx_9;
      if (0 < a_1){
        X60Qx_9 = a_1;}
      else {
        X60Qx_9 = 1;}
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = 0, .fld_1 = X60Qx_9}
      ;}
    break;
    case 14:
    case 15:
    {
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = ((NI32)(2 * ptrSize_2)), .fld_1 = ptrSize_2}
      ;}
    break;
    case 9:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_0 = sizeAlign_1_layptix6a1((*t_3).d_00.elem_0, ptrSize_2);
      NI32 X60Qx_10;
      if (0 < sa_0.fld_1){
        X60Qx_10 = sa_0.fld_1;}
      else {
        X60Qx_10 = 1;}
      NI32 stride_0 = align_0_layptix6a1(sa_0.fld_0, X60Qx_10);
      if ((*t_3).d_00.count_0 <= 0){
        result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
          .fld_0 = 0, .fld_1 = sa_0.fld_1}
        ;}
      else {
        result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
          .fld_0 = ((NI32)(stride_0 * (*t_3).d_00.count_0)), .fld_1 = sa_0.fld_1}
        ;}}
    break;
    case 10:
    case 11:
    {
      NI32 offset_0 = 0;
      NI32 maxAlign_0 = 1;
      if ((*t_3).d_00.kind_0 == 10){
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 pre_0 = objectPrefix_0_layptix6a1(t_3, ptrSize_2);
        offset_0 = pre_0.fld_0;
        if (maxAlign_0 < pre_0.fld_1){
          maxAlign_0 = pre_0.fld_1;}}
      if ((*t_3).d_00.union_0){
        NI32 usize_0 = 0;
        {
          openArray_0_I3ca6t4_layptix6a1 X60Qlf_0 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_3).d_00.fields_0);
          NI32 X60Qlf_1 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_71 = len_6_I0tpktl1_layptix6a1(X60Qlf_0);
              if (X60Qlf_1 < X60Qx_71){
                {
                  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_0, X60Qlf_1);
                  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qii_3 = sizeAlign_1_layptix6a1((*X60Qii_2), ptrSize_2);
                  NI32 X60Qx_11;
                  if (0 < X60Qii_3.fld_1){
                    X60Qx_11 = X60Qii_3.fld_1;}
                  else {
                    X60Qx_11 = 1;}
                  NI32 X60Qii_4 = X60Qx_11;
                  if (usize_0 < X60Qii_3.fld_0){
                    usize_0 = X60Qii_3.fld_0;}
                  if (maxAlign_0 < X60Qii_4){
                    maxAlign_0 = X60Qii_4;}}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
              else {
                break;}}}
          whileStmtLabel_1: ;}
        forStmtLabel_0: ;
        NI32 X60Qx_72 = align_0_layptix6a1(((NI32)(offset_0 + usize_0)), maxAlign_0);
        result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
          .fld_0 = X60Qx_72, .fld_1 = maxAlign_0}
        ;}
      else {
        if ((*t_3).d_00.packed_0){
          {
            openArray_0_I3ca6t4_layptix6a1 X60Qlf_2 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_3).d_00.fields_0);
            NI32 X60Qlf_3 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_73 = len_6_I0tpktl1_layptix6a1(X60Qlf_2);
                if (X60Qlf_3 < X60Qx_73){
                  {
                    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_7 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_2, X60Qlf_3);
                    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_74 = sizeAlign_1_layptix6a1((*X60Qii_7), ptrSize_2);
                    offset_0 = ((NI32)(offset_0 + X60Qx_74.fld_0));}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
                else {
                  break;}}}
            whileStmtLabel_6: ;}
          forStmtLabel_5: ;
          result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
            .fld_0 = offset_0, .fld_1 = 1}
          ;}
        else {
          {
            openArray_0_I3ca6t4_layptix6a1 X60Qlf_4 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_3).d_00.fields_0);
            NI32 X60Qlf_5 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_75 = len_6_I0tpktl1_layptix6a1(X60Qlf_4);
                if (X60Qlf_5 < X60Qx_75){
                  {
                    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_10 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_4, X60Qlf_5);
                    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qii_11 = sizeAlign_1_layptix6a1((*X60Qii_10), ptrSize_2);
                    NI32 X60Qx_12;
                    if (0 < X60Qii_11.fld_1){
                      X60Qx_12 = X60Qii_11.fld_1;}
                    else {
                      X60Qx_12 = 1;}
                    NI32 X60Qii_12 = X60Qx_12;
                    NI32 X60Qx_76 = align_0_layptix6a1(offset_0, X60Qii_12);
                    offset_0 = ((NI32)(X60Qx_76 + X60Qii_11.fld_0));
                    if (maxAlign_0 < X60Qii_12){
                      maxAlign_0 = X60Qii_12;}}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
                else {
                  break;}}}
            whileStmtLabel_9: ;}
          forStmtLabel_8: ;
          NI32 X60Qx_77 = align_0_layptix6a1(offset_0, maxAlign_0);
          result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
            .fld_0 = X60Qx_77, .fld_1 = maxAlign_0}
          ;}}}
    break;
    case 12:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 pre_1 = objectPrefix_0_layptix6a1(t_3, ptrSize_2);
      NI32 offset_1 = pre_1.fld_0;
      NI32 maxAlign_1 = max_2_sysvq0asl(1, pre_1.fld_1);
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_6 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_3).d_00.fields_0);
        NI32 X60Qlf_7 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_78 = len_6_I0tpktl1_layptix6a1(X60Qlf_6);
            if (X60Qlf_7 < X60Qx_78){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_15 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_6, X60Qlf_7);
                X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qii_16 = sizeAlign_1_layptix6a1((*X60Qii_15), ptrSize_2);
                NI32 X60Qx_13;
                if (0 < X60Qii_16.fld_1){
                  X60Qx_13 = X60Qii_16.fld_1;}
                else {
                  X60Qx_13 = 1;}
                NI32 X60Qii_17 = X60Qx_13;
                NI32 X60Qx_79 = align_0_layptix6a1(offset_1, X60Qii_17);
                offset_1 = ((NI32)(X60Qx_79 + X60Qii_16.fld_0));
                if (maxAlign_1 < X60Qii_17){
                  maxAlign_1 = X60Qii_17;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
            else {
              break;}}}
        whileStmtLabel_14: ;}
      forStmtLabel_13: ;
      NI32 branchSize_0 = 0;
      NI32 branchAlign_0 = 1;
      {
        openArray_0_Iwtfxrw_layptix6a1 X60Qlf_8 = toOpenArray_1_I5d1kzx1_layptix6a1((*t_3).d_00.branches_0);
        NI32 X60Qlf_9 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_80 = len_6_Ia8vzko1_layptix6a1(X60Qlf_8);
            if (X60Qlf_9 < X60Qx_80){
              {
                seq_0_I3ump14_aow7lb5cq1* X60Qii_20 = getQ_10_Ih94lt3_layptix6a1(X60Qlf_8, X60Qlf_9);
                NI32 X60Qii_21 = 0;
                NI32 X60Qii_22 = 1;
                {
                  openArray_0_I3ca6t4_layptix6a1 X60Qlf_10 = toOpenArray_1_I0zz6qv1_layptix6a1((*X60Qii_20));
                  NI32 X60Qlf_11 = 0;
                  {
                    while (NIM_TRUE){
                      NI32 X60Qx_81 = len_6_I0tpktl1_layptix6a1(X60Qlf_10);
                      if (X60Qlf_11 < X60Qx_81){
                        {
                          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_25 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_10, X60Qlf_11);
                          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qii_26 = sizeAlign_1_layptix6a1((*X60Qii_25), ptrSize_2);
                          NI32 X60Qx_14;
                          if (0 < X60Qii_26.fld_1){
                            X60Qx_14 = X60Qii_26.fld_1;}
                          else {
                            X60Qx_14 = 1;}
                          NI32 X60Qii_27 = X60Qx_14;
                          NI32 X60Qx_82 = align_0_layptix6a1(X60Qii_21, X60Qii_27);
                          X60Qii_21 = ((NI32)(X60Qx_82 + X60Qii_26.fld_0));
                          if (maxAlign_1 < X60Qii_27){
                            maxAlign_1 = X60Qii_27;}
                          if (X60Qii_22 < X60Qii_27){
                            X60Qii_22 = X60Qii_27;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
                      else {
                        break;}}}
                  whileStmtLabel_24: ;}
                forStmtLabel_23: ;
                NI32 X60Qx_83 = align_0_layptix6a1(X60Qii_21, X60Qii_22);
                X60Qii_21 = X60Qx_83;
                if (branchSize_0 < X60Qii_21){
                  branchSize_0 = X60Qii_21;}
                if (branchAlign_0 < X60Qii_22){
                  branchAlign_0 = X60Qii_22;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
            else {
              break;}}}
        whileStmtLabel_19: ;}
      forStmtLabel_18: ;
      if (maxAlign_1 < branchAlign_0){
        maxAlign_1 = branchAlign_0;}
      NI32 X60Qx_84 = align_0_layptix6a1(offset_1, branchAlign_0);
      offset_1 = ((NI32)(X60Qx_84 + branchSize_0));
      NI32 X60Qx_85 = align_0_layptix6a1(offset_1, maxAlign_1);
      result_16 = (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
        .fld_0 = X60Qx_85, .fld_1 = maxAlign_1}
      ;}
    break;}
  return result_16;}
seq_0_Ift2sne_aow7lb5cq1 fieldOffsets_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_4, NI32 ptrSize_3){
  seq_0_Ift2sne_aow7lb5cq1 result_17;
  eQwasMoved_1_Ix88qzs1_aow7lb5cq1((&result_17));
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(result_17);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_86 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  result_17 = X60Qx_86;
  X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
    .a = {
      0u, 28u, 0u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)(*t_4).d_00.kind_0);
  if ((!(((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u))){
    return result_17;}
  NI32 offset_2 = 0;
  if ((!((*t_4).d_00.kind_0 == 11))){
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_87 = objectPrefix_0_layptix6a1(t_4, ptrSize_3);
    offset_2 = X60Qx_87.fld_0;}
  {
    openArray_0_I3ca6t4_layptix6a1 X60Qlf_12 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_4).d_00.fields_0);
    NI32 X60Qlf_13 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_88 = len_6_I0tpktl1_layptix6a1(X60Qlf_12);
        if (X60Qlf_13 < X60Qx_88){
          {
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_12, X60Qlf_13);
            X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qii_3 = sizeAlign_1_layptix6a1((*X60Qii_2), ptrSize_3);
            NI32 X60Qx_15;
            if (0 < X60Qii_3.fld_1){
              X60Qx_15 = X60Qii_3.fld_1;}
            else {
              X60Qx_15 = 1;}
            NI32 X60Qii_4 = X60Qx_15;
            if ((*t_4).d_00.union_0){
              add_0_I8kd4i4_aow7lb5cq1((&result_17), offset_2);}
            else {
              if ((*t_4).d_00.packed_0){
                add_0_I8kd4i4_aow7lb5cq1((&result_17), offset_2);
                offset_2 = ((NI32)(offset_2 + X60Qii_3.fld_0));}
              else {
                NI32 X60Qx_89 = align_0_layptix6a1(offset_2, X60Qii_4);
                offset_2 = X60Qx_89;
                add_0_I8kd4i4_aow7lb5cq1((&result_17), offset_2);
                offset_2 = ((NI32)(offset_2 + X60Qii_3.fld_0));}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_17;}
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8){
  openArray_0_I3ca6t4_layptix6a1 result_23;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_193 = rawData_0_I2xua2q_layptix6a1(s_8);
  result_23 = (openArray_0_I3ca6t4_layptix6a1){
    .a_0 = X60Qx_193, .len_0 = s_8.len_0}
  ;
  return result_23;}
static inline openArray_0_Iwtfxrw_layptix6a1 toOpenArray_1_I5d1kzx1_layptix6a1(seq_0_Ie088gc_heapjafyf1 s_10){
  openArray_0_Iwtfxrw_layptix6a1 result_24;
  seq_0_I3ump14_aow7lb5cq1* X60Qx_194 = rawData_0_I2kxyg9_layptix6a1(s_10);
  result_24 = (openArray_0_Iwtfxrw_layptix6a1){
    .a_0 = X60Qx_194, .len_0 = s_10.len_0}
  ;
  return result_24;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_33;
  result_33 = s_20.data_0;
  return result_33;}
static inline NI32 len_6_I0tpktl1_layptix6a1(openArray_0_I3ca6t4_layptix6a1 a_18){
  NI32 result_34;
  result_34 = a_18.len_0;
  return result_34;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_10_Ikixp7k_layptix6a1(openArray_0_I3ca6t4_layptix6a1 x_3, NI32 idx_2){
  NB8 X60Qx_205;
  if (0 <= idx_2){
    X60Qx_205 = (idx_2 < x_3.len_0);}
  else {
    X60Qx_205 = NIM_FALSE;}
  if ((!X60Qx_205)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_35;
  result_35 = (&x_3.a_0[idx_2]);
  return result_35;}
static inline seq_0_I3ump14_aow7lb5cq1* rawData_0_I2kxyg9_layptix6a1(seq_0_Ie088gc_heapjafyf1 s_21){
  seq_0_I3ump14_aow7lb5cq1* result_36;
  result_36 = s_21.data_0;
  return result_36;}
static inline NI32 len_6_Ia8vzko1_layptix6a1(openArray_0_Iwtfxrw_layptix6a1 a_19){
  NI32 result_37;
  result_37 = a_19.len_0;
  return result_37;}
static inline seq_0_I3ump14_aow7lb5cq1* getQ_10_Ih94lt3_layptix6a1(openArray_0_Iwtfxrw_layptix6a1 x_5, NI32 idx_3){
  NB8 X60Qx_206;
  if (0 <= idx_3){
    X60Qx_206 = (idx_3 < x_5.len_0);}
  else {
    X60Qx_206 = NIM_FALSE;}
  if ((!X60Qx_206)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  seq_0_I3ump14_aow7lb5cq1* result_38;
  result_38 = (&x_5.a_0[idx_3]);
  return result_38;}
void eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(TypeDesc_Obj_0_layptix6a1* dest_0){
  eQdestroy_1_I87nkt8_heapjafyf1((*dest_0).branches_0);
  eQdestroy_1_Iqg9snl1_aow7lb5cq1((*dest_0).fields_0);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((*dest_0).base_0);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((*dest_0).elem_0);}
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_242 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_242){
      eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_layptix6a1(void){
  if (X60QiniGuard_0_layptix6a1){
    return;}
  X60QiniGuard_0_layptix6a1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline seq_0_I3ump14_aow7lb5cq1 newSeqUninit_0_I978ktq1_aow7lb5cq1(NI32 size_30){
  seq_0_I3ump14_aow7lb5cq1 result_122;
  if (size_30 == 0){
    result_122 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_21 = memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(size_30);
    void* X60Qx_1537 = alloc_1_sysvq0asl(memSize_21);
    result_122 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1**)X60Qx_1537)}
    ;
    if ((!(result_122.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1538 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_122.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_21);}}
  return result_122;}
static inline seq_0_Ie088gc_heapjafyf1 newSeqUninit_0_Inwn9fa_heapjafyf1(NI32 size_4){
  seq_0_Ie088gc_heapjafyf1 result_19;
  if (size_4 == 0){
    result_19 = (seq_0_Ie088gc_heapjafyf1){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ilxpm6v1_heapjafyf1(size_4);
    void* X60Qx_23 = alloc_1_sysvq0asl(memSize_1);
    result_19 = (seq_0_Ie088gc_heapjafyf1){
      .len_0 = size_4, .data_0 = ((seq_0_I3ump14_aow7lb5cq1*)X60Qx_23)}
    ;
    if ((!(result_19.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_24 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_19.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_19;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95){
  (*s_95).len_0 = 0;
  (*s_95).data_0 = NIM_NIL;}
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_69;
  if (size_10 == 0){
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_1443 = alloc_1_sysvq0asl(memSize_2);
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_1443)}
    ;
    if ((!(result_69.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1444 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_69.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_69;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_124;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_124 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_124 = ((NI32)2147483647);}
  return result_124;}
static inline NI32 memSizeInBytes_0_Ilxpm6v1_heapjafyf1(NI32 size_7){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_22;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_7, sizeof(seq_0_I3ump14_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_22 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_22 = ((NI32)2147483647);}
  return result_22;}
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_93;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_93 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_93 = ((NI32)2147483647);}
  return result_93;}
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68){
  NI32 result_94;
  NI32 X60Qx_13;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_1476 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_13 = X60Qx_1476;}
  else {
    X60Qx_13 = 0;}
  result_94 = X60Qx_13;
  return result_94;}
