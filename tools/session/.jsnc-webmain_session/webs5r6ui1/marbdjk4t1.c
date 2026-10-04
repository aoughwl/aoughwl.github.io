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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef NU8 MarshalClass_0_marbdjk4t1;

#define mcScalar_0_marbdjk4t1 ((NU8)0)
#define mcPod_0_marbdjk4t1 ((NU8)1)
#define mcString_0_marbdjk4t1 ((NU8)2)
#define mcSeq_0_marbdjk4t1 ((NU8)3)
#define mcRef_0_marbdjk4t1 ((NU8)4)
#define mcClosure_0_marbdjk4t1 ((NU8)5)
#define mcUnsafe_0_marbdjk4t1 ((NU8)6)
typedef NU8 JsRepr_0_marbdjk4t1;

#define jsNumber_0_marbdjk4t1 ((NU8)0)
#define jsBigInt_0_marbdjk4t1 ((NU8)1)
#define jsBoolean_0_marbdjk4t1 ((NU8)2)
#define jsCharString_0_marbdjk4t1 ((NU8)3)
#define jsString_0_marbdjk4t1 ((NU8)4)
#define jsArray_0_marbdjk4t1 ((NU8)5)
#define jsObject_0_marbdjk4t1 ((NU8)6)
#define jsRefBox_0_marbdjk4t1 ((NU8)7)
#define jsSet_0_marbdjk4t1 ((NU8)8)
typedef struct openArray_0_I3ca6t4_layptix6a1{
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** a_0;
  NI32 len_0;}
openArray_0_I3ca6t4_layptix6a1;
typedef struct seq_0_I3ump14_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** data_0;}
seq_0_I3ump14_aow7lb5cq1;
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
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1{
  NI r_00;
  TypeDesc_Obj_0_layptix6a1 d_00;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
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
extern NI32 setSizeInBytes_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_4);
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8);
static inline NI32 len_6_I0tpktl1_layptix6a1(openArray_0_I3ca6t4_layptix6a1 a_18);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_10_Ikixp7k_layptix6a1(openArray_0_I3ca6t4_layptix6a1 x_3, NI32 idx_2);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_layptix6a1(void);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
LongString_0_sysvq0asl const strlit_0_I990882640025799687_marbdjk4t1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcScalar"}
;
LongString_0_sysvq0asl const strlit_0_I3470422228391514573_marbdjk4t1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcPod"}
;
LongString_0_sysvq0asl const strlit_0_I696057604909997793_marbdjk4t1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcString"}
;
LongString_0_sysvq0asl const strlit_0_I17665588267585860306_marbdjk4t1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcSeq"}
;
LongString_0_sysvq0asl const strlit_0_I8160649543150574237_marbdjk4t1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcRef"}
;
LongString_0_sysvq0asl const strlit_0_I12549307355442489107_marbdjk4t1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcClosure"}
;
LongString_0_sysvq0asl const strlit_0_I3538386510047344326_marbdjk4t1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mcUnsafe"}
;
NB8 X60QiniGuard_0_marbdjk4t1;
static inline NB8 setIsSized_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_0){
  NB8 result_1;
  NI32 X60Qx_6 = setSizeInBytes_0_layptix6a1((*t_0).d_00.elem_0);
  result_1 = (0 < X60Qx_6);
  return result_1;}
NB8 isPodAggregate_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_1){
  NB8 result_2;
  switch ((*t_1).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      result_2 = NIM_TRUE;}
    break;
    case 16:
    {
      NB8 X60Qx_7 = setIsSized_0_marbdjk4t1(t_1);
      result_2 = X60Qx_7;}
    break;
    case 17:
    {
      NB8 X60Qx_8;
      if ((!((*t_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_9 = isPodAggregate_0_marbdjk4t1((*t_1).d_00.elem_0);
        X60Qx_8 = X60Qx_9;}
      else {
        X60Qx_8 = NIM_FALSE;}
      result_2 = X60Qx_8;}
    break;
    case 5:
    {
      result_2 = NIM_FALSE;}
    break;
    case 13:
    {
      NB8 X60Qx_10;
      if ((!((*t_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_11 = isPodAggregate_0_marbdjk4t1((*t_1).d_00.elem_0);
        X60Qx_10 = X60Qx_11;}
      else {
        X60Qx_10 = NIM_FALSE;}
      result_2 = X60Qx_10;}
    break;
    case 9:
    {
      NB8 X60Qx_12;
      if ((!((*t_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_13 = isPodAggregate_0_marbdjk4t1((*t_1).d_00.elem_0);
        X60Qx_12 = X60Qx_13;}
      else {
        X60Qx_12 = NIM_FALSE;}
      result_2 = X60Qx_12;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_14;
      if ((*t_1).d_00.kind_0 == 10){
        X60Qx_14 = (*t_1).d_00.incomplete_0;}
      else {
        X60Qx_14 = NIM_FALSE;}
      if (X60Qx_14){
        return NIM_FALSE;}
      NB8 X60Qx_15;
      if ((*t_1).d_00.kind_0 == 10){
        X60Qx_15 = (*t_1).d_00.union_0;}
      else {
        X60Qx_15 = NIM_FALSE;}
      if (X60Qx_15){
        return NIM_FALSE;}
      NB8 X60Qx_16;
      NB8 X60Qx_17;
      if ((*t_1).d_00.kind_0 == 10){
        X60Qx_17 = (!((*t_1).d_00.base_0 == NIM_NIL));}
      else {
        X60Qx_17 = NIM_FALSE;}
      if (X60Qx_17){
        NB8 X60Qx_18 = isPodAggregate_0_marbdjk4t1((*t_1).d_00.base_0);
        X60Qx_16 = (!X60Qx_18);}
      else {
        X60Qx_16 = NIM_FALSE;}
      if (X60Qx_16){
        return NIM_FALSE;}
      result_2 = NIM_TRUE;
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_0 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_1).d_00.fields_0);
        NI32 X60Qlf_1 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_19 = len_6_I0tpktl1_layptix6a1(X60Qlf_0);
            if (X60Qlf_1 < X60Qx_19){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_0, X60Qlf_1);
                NB8 X60Qx_20 = isPodAggregate_0_marbdjk4t1((*X60Qii_2));
                if ((!X60Qx_20)){
                  return NIM_FALSE;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    break;
    case 12:
    {
      result_2 = NIM_FALSE;}
    break;
    case 14:
    case 15:
    {
      result_2 = NIM_FALSE;}
    break;
    case 18:
    {
      result_2 = NIM_FALSE;}
    break;
    case 6:
    case 7:
    {
      result_2 = NIM_FALSE;}
    break;}
  return result_2;}
NB8 hasPtrLeaf_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_2){
  NB8 result_3;
  switch ((*t_2).d_00.kind_0){
    case 5:
    {
      result_3 = NIM_TRUE;}
    break;
    case 13:
    case 9:
    case 17:
    {
      NB8 X60Qx_21;
      if ((!((*t_2).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_22 = hasPtrLeaf_0_marbdjk4t1((*t_2).d_00.elem_0);
        X60Qx_21 = X60Qx_22;}
      else {
        X60Qx_21 = NIM_FALSE;}
      result_3 = X60Qx_21;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_23;
      NB8 X60Qx_24;
      if ((*t_2).d_00.kind_0 == 10){
        X60Qx_24 = (!((*t_2).d_00.base_0 == NIM_NIL));}
      else {
        X60Qx_24 = NIM_FALSE;}
      if (X60Qx_24){
        NB8 X60Qx_25 = hasPtrLeaf_0_marbdjk4t1((*t_2).d_00.base_0);
        X60Qx_23 = X60Qx_25;}
      else {
        X60Qx_23 = NIM_FALSE;}
      if (X60Qx_23){
        return NIM_TRUE;}
      result_3 = NIM_FALSE;
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_2 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_2).d_00.fields_0);
        NI32 X60Qlf_3 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_26 = len_6_I0tpktl1_layptix6a1(X60Qlf_2);
            if (X60Qlf_3 < X60Qx_26){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_2, X60Qlf_3);
                NB8 X60Qx_27 = hasPtrLeaf_0_marbdjk4t1((*X60Qii_2));
                if (X60Qx_27){
                  return NIM_TRUE;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    break;
    default:
    {
      result_3 = NIM_FALSE;}
    break;}
  return result_3;}
NB8 podOrPtrAggregate_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3){
  NB8 result_4;
  switch ((*t_3).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    case 5:
    {
      result_4 = NIM_TRUE;}
    break;
    case 16:
    {
      NB8 X60Qx_28 = setIsSized_0_marbdjk4t1(t_3);
      result_4 = X60Qx_28;}
    break;
    case 13:
    case 9:
    case 17:
    {
      NB8 X60Qx_29;
      if ((!((*t_3).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_30 = podOrPtrAggregate_0_marbdjk4t1((*t_3).d_00.elem_0);
        X60Qx_29 = X60Qx_30;}
      else {
        X60Qx_29 = NIM_FALSE;}
      result_4 = X60Qx_29;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_31;
      if ((*t_3).d_00.kind_0 == 10){
        NB8 X60Qx_32;
        if ((*t_3).d_00.union_0){
          X60Qx_32 = NIM_TRUE;}
        else {
          X60Qx_32 = (*t_3).d_00.incomplete_0;}
        X60Qx_31 = X60Qx_32;}
      else {
        X60Qx_31 = NIM_FALSE;}
      if (X60Qx_31){
        return NIM_FALSE;}
      NB8 X60Qx_33;
      NB8 X60Qx_34;
      if ((*t_3).d_00.kind_0 == 10){
        X60Qx_34 = (!((*t_3).d_00.base_0 == NIM_NIL));}
      else {
        X60Qx_34 = NIM_FALSE;}
      if (X60Qx_34){
        NB8 X60Qx_35 = podOrPtrAggregate_0_marbdjk4t1((*t_3).d_00.base_0);
        X60Qx_33 = (!X60Qx_35);}
      else {
        X60Qx_33 = NIM_FALSE;}
      if (X60Qx_33){
        return NIM_FALSE;}
      result_4 = NIM_TRUE;
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_4 = toOpenArray_1_I0zz6qv1_layptix6a1((*t_3).d_00.fields_0);
        NI32 X60Qlf_5 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_36 = len_6_I0tpktl1_layptix6a1(X60Qlf_4);
            if (X60Qlf_5 < X60Qx_36){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_4, X60Qlf_5);
                NB8 X60Qx_37 = podOrPtrAggregate_0_marbdjk4t1((*X60Qii_2));
                if ((!X60Qx_37)){
                  return NIM_FALSE;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    break;
    default:
    {
      result_4 = NIM_FALSE;}
    break;}
  return result_4;}
NB8 isArenaPtrAggregate_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_7){
  NB8 result_8;
  NB8 X60Qx_65;
  NB8 X60Qx_66;
  NB8 X60Qx_67;
  NB8 X60Qx_68;
  if ((*t_7).d_00.kind_0 == 10){
    X60Qx_68 = NIM_TRUE;}
  else {
    X60Qx_68 = ((*t_7).d_00.kind_0 == 11);}
  if (X60Qx_68){
    X60Qx_67 = NIM_TRUE;}
  else {
    X60Qx_67 = ((*t_7).d_00.kind_0 == 13);}
  if (X60Qx_67){
    NB8 X60Qx_69 = podOrPtrAggregate_0_marbdjk4t1(t_7);
    X60Qx_66 = X60Qx_69;}
  else {
    X60Qx_66 = NIM_FALSE;}
  if (X60Qx_66){
    NB8 X60Qx_70 = hasPtrLeaf_0_marbdjk4t1(t_7);
    X60Qx_65 = X60Qx_70;}
  else {
    X60Qx_65 = NIM_FALSE;}
  result_8 = X60Qx_65;
  return result_8;}
MarshalClass_0_marbdjk4t1 marshalClass_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_8){
  MarshalClass_0_marbdjk4t1 result_9;
  switch ((*t_8).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      result_9 = 0;}
    break;
    case 17:
    {
      MarshalClass_0_marbdjk4t1 X60Qx_0;
      if ((!((*t_8).d_00.elem_0 == NIM_NIL))){
        MarshalClass_0_marbdjk4t1 X60Qx_71 = marshalClass_0_marbdjk4t1((*t_8).d_00.elem_0);
        X60Qx_0 = X60Qx_71;}
      else {
        X60Qx_0 = 6;}
      result_9 = X60Qx_0;}
    break;
    case 16:
    {
      MarshalClass_0_marbdjk4t1 X60Qx_1;
      NI32 X60Qx_72 = setSizeInBytes_0_layptix6a1((*t_8).d_00.elem_0);
      if (0 < X60Qx_72){
        X60Qx_1 = 1;}
      else {
        X60Qx_1 = 6;}
      result_9 = X60Qx_1;}
    break;
    case 18:
    {
      result_9 = 6;}
    break;
    case 5:
    {
      result_9 = 0;}
    break;
    case 6:
    {
      result_9 = 4;}
    break;
    case 7:
    {
      result_9 = 5;}
    break;
    case 13:
    {
      MarshalClass_0_marbdjk4t1 X60Qx_2;
      if ((!((*t_8).d_00.elem_0 == NIM_NIL))){
        MarshalClass_0_marbdjk4t1 X60Qx_73 = marshalClass_0_marbdjk4t1((*t_8).d_00.elem_0);
        X60Qx_2 = X60Qx_73;}
      else {
        X60Qx_2 = 6;}
      result_9 = X60Qx_2;}
    break;
    case 14:
    {
      result_9 = 2;}
    break;
    case 15:
    {
      result_9 = 3;}
    break;
    case 9:
    case 11:
    case 10:
    {
      MarshalClass_0_marbdjk4t1 X60Qx_3;
      NB8 X60Qx_74 = isPodAggregate_0_marbdjk4t1(t_8);
      if (X60Qx_74){
        X60Qx_3 = 1;}
      else {
        X60Qx_3 = 6;}
      result_9 = X60Qx_3;}
    break;
    case 12:
    {
      result_9 = 6;}
    break;}
  return result_9;}
void X60Qini_0_marbdjk4t1(void){
  if (X60QiniGuard_0_marbdjk4t1){
    return;}
  X60QiniGuard_0_marbdjk4t1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_layptix6a1();}
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8){
  openArray_0_I3ca6t4_layptix6a1 result_23;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_193 = rawData_0_I2xua2q_layptix6a1(s_8);
  result_23 = (openArray_0_I3ca6t4_layptix6a1){
    .a_0 = X60Qx_193, .len_0 = s_8.len_0}
  ;
  return result_23;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_33;
  result_33 = s_20.data_0;
  return result_33;}
