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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct PathGrant_0_iop7yt73v{
  string_0_sysvq0asl prefix_0;
  NI32 caps_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_0;}
PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v{
  string_0_sysvq0asl path_0;
  NU64 hash_0;
  NI32 size_0;
  NB8 hashed_0;}
ReadRecord_0_iop7yt73v;
typedef struct seq_0_Iq7pam4_iop7yt73v{
  NI32 len_0;
  PathGrant_0_iop7yt73v* data_0;}
seq_0_Iq7pam4_iop7yt73v;
typedef struct seq_0_Iero8tq_iop7yt73v{
  NI32 len_0;
  ReadRecord_0_iop7yt73v* data_0;}
seq_0_Iero8tq_iop7yt73v;
typedef struct IoPolicy_Obj_0_iop7yt73v{
  NB8 on_0;
  NI32 granted_0;
  seq_0_Iq7pam4_iop7yt73v grants_0;
  NB8 sealed_0;
  string_0_sysvq0asl owner_0;
  NB8 auditReads_0;
  seq_0_Iero8tq_iop7yt73v reads_0;
  NI32 violations_0;
  string_0_sysvq0asl violNative_0;
  NI32 violNeeded_0;}
IoPolicy_Obj_0_iop7yt73v;
typedef struct openArray_0_I2u6yr01_iop7yt73v{
  ReadRecord_0_iop7yt73v* a_0;
  NI32 len_0;}
openArray_0_I2u6yr01_iop7yt73v;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax{
  NI r_00;
  IoPolicy_Obj_0_iop7yt73v d_00;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 len_3_I1rs8q11_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_22);
static inline PathGrant_0_iop7yt73v* getQ_7_Iane2hm1_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_23, NI32 i_12);
static inline NI32 len_3_Ifa3bd_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_24);
static inline ReadRecord_0_iop7yt73v* getQ_7_Iylxa0x_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_25, NI32 i_13);
static inline void add_0_Ijr069w1_iop7yt73v(seq_0_Iero8tq_iop7yt73v* s_26, ReadRecord_0_iop7yt73v elem_5);
static inline NI32 memSizeInBytes_0_Izkmv63_iop7yt73v(NI32 size_9);
static inline NI32 memSizeInBytes_0_I057n0g1_iop7yt73v(NI32 size_10);
static inline NI32 capInBytes_0_Ibi6vw11_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_34);
NB8 resize_0_Ipdnn431_iop7yt73v(seq_0_Iero8tq_iop7yt73v* dest_5, NI32 addedElements_5);
void eQdestroyQ_SX50athX47rant0iop7yt73v_0_iop7yt73v(PathGrant_0_iop7yt73v dest_0);
void eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(ReadRecord_0_iop7yt73v dest_0);
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0);
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* src_0);
void eQwasmovedQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax** dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern LongString_0_sysvq0asl const strlit_0_I8446236512461598146_croph25r5;
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11626809062896146847_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I4303973984874128508_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I17971560687400798064_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I15418518599716865203_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I2723496349315214549_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I11697234225982197076_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I12542130669033277445_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I4718597432102153922_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I9592449470941440445_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I13735625106940001307_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I2912131129587157308_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I900530018976380608_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I4050815769175754417_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I14251590839437571501_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I13565819874765507459_croph25r5;
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
extern void setLen_0_Iejjsiw_intzsnzax(seq_0_Ixdx2fh1_aow7lb5cq1* s_210, NI32 newLen_30);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern LongString_0_sysvq0asl const strlit_0_I7383674803287968507_hos1fpv3m1;
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I10980672052437566323_iop7yt73v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fs.read"}
;
LongString_0_sysvq0asl const strlit_0_I7666624814036398774_iop7yt73v = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fs.write"}
;
LongString_0_sysvq0asl const strlit_0_I17118443558071152766_iop7yt73v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fs.meta"}
;
LongString_0_sysvq0asl const strlit_0_I4406216718368404848_iop7yt73v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "process"}
;
LongString_0_sysvq0asl const strlit_0_I11216437567223755660_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "delEnv"}
;
LongString_0_sysvq0asl const strlit_0_I4300154733488353634_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getEnv"}
;
LongString_0_sysvq0asl const strlit_0_I3006705858755300605_iop7yt73v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getEnvVarsC"}
;
LongString_0_sysvq0asl const strlit_0_I17563301282676592437_iop7yt73v = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fstat"}
;
LongString_0_sysvq0asl const strlit_0_I885514587362827984_iop7yt73v = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "lstat"}
;
LongString_0_sysvq0asl const strlit_0_I18337270522941735704_iop7yt73v = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bind"}
;
LongString_0_sysvq0asl const strlit_0_I4398256179715674167_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "accept"}
;
LongString_0_sysvq0asl const strlit_0_I10138590777481088495_iop7yt73v = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "closedir"}
;
LongString_0_sysvq0asl const strlit_0_I9620132962526484305_iop7yt73v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "connect"}
;
LongString_0_sysvq0asl const strlit_0_I754749039837241777_iop7yt73v = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fopen"}
;
LongString_0_sysvq0asl const strlit_0_I7616721286816756_iop7yt73v = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "existsEnv"}
;
LongString_0_sysvq0asl const strlit_0_I15031238125720431605_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "listen"}
;
LongString_0_sysvq0asl const strlit_0_I12278932653354239625_iop7yt73v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readdir"}
;
LongString_0_sysvq0asl const strlit_0_I17150237903071301653_iop7yt73v = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "realpath"}
;
LongString_0_sysvq0asl const strlit_0_I1187689770688346212_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rename"}
;
LongString_0_sysvq0asl const strlit_0_I8779604385735337050_iop7yt73v = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "recv"}
;
LongString_0_sysvq0asl const strlit_0_I17106851413817154788_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "putEnv"}
;
LongString_0_sysvq0asl const strlit_0_I13696262612503621358_iop7yt73v = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "send"}
;
LongString_0_sysvq0asl const strlit_0_I399834492833889323_iop7yt73v = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setsockopt"}
;
LongString_0_sysvq0asl const strlit_0_I10217866098611558294_iop7yt73v = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stat"}
;
LongString_0_sysvq0asl const strlit_0_I15415642409673360391_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "socket"}
;
LongString_0_sysvq0asl const strlit_0_I17663818852377669490_iop7yt73v = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: policy violation: \'"}
;
LongString_0_sysvq0asl const strlit_0_I16137639778510327014_iop7yt73v = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' needs capability "}
;
LongString_0_sysvq0asl const strlit_0_I16651577260944187724_iop7yt73v = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "; this run grants "}
;
LongString_0_sysvq0asl const strlit_0_I3188702685911042556_iop7yt73v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " plus "}
;
LongString_0_sysvq0asl const strlit_0_I9020742201384713734_iop7yt73v = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " path grant(s)"}
;
LongString_0_sysvq0asl const strlit_0_I2364452291923173386_iop7yt73v = {
  .fullLen_0 = 45, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ". Denied \342\200\224 the call did not reach the host."}
;
LongString_0_sysvq0asl const strlit_0_I13007304069900691547_iop7yt73v = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " [policy: "}
;
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* gProcess_0_iop7yt73v;
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* gCur_0_iop7yt73v;
NB8 gCurOn_0_iop7yt73v = NIM_FALSE;
NB8 gPerInterp_0_iop7yt73v = NIM_FALSE;
NB8 X60QiniGuard_0_iop7yt73v;
string_0_sysvq0asl capName_0_iop7yt73v(NI32 c_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  string_0_sysvq0asl s_1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(((NI32)(c_0 & ((NI32)1))) == 0))){
    string_0_sysvq0asl X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NI32 X60Qx_13 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_13){
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_0 = X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NI32 X60Qx_14 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_15 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_16 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I10980672052437566323_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_14 + X60Qx_15)) + X60Qx_16)));
    add_2_sysvq0asl((&X60Qdesugar_1), s_1);
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I10980672052437566323_iop7yt73v)}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    nimStrDestroy(X60Qx_0);}
  if ((!(((NI32)(c_0 & ((NI32)2))) == 0))){
    string_0_sysvq0asl X60Qx_1;
    nimStrWasMoved((&X60Qx_1));
    NI32 X60Qx_17 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_17){
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_2 = X60Qx_1;
    nimStrWasMoved((&X60Qx_1));
    NI32 X60Qx_18 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_19 = len_4_sysvq0asl(X60Qdesugar_2);
    NI32 X60Qx_20 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I7666624814036398774_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_18 + X60Qx_19)) + X60Qx_20)));
    add_2_sysvq0asl((&X60Qdesugar_3), s_1);
    add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I7666624814036398774_iop7yt73v)}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_3;
    nimStrWasMoved((&X60Qdesugar_3));
    nimStrDestroy(X60Qdesugar_3);
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qx_1);}
  if ((!(((NI32)(c_0 & ((NI32)4))) == 0))){
    string_0_sysvq0asl X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    NI32 X60Qx_21 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_21){
      nimStrDestroy(X60Qx_2);
      X60Qx_2 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_2);
      X60Qx_2 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_4 = X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    NI32 X60Qx_22 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_23 = len_4_sysvq0asl(X60Qdesugar_4);
    NI32 X60Qx_24 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I17118443558071152766_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_22 + X60Qx_23)) + X60Qx_24)));
    add_2_sysvq0asl((&X60Qdesugar_5), s_1);
    add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
    add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I17118443558071152766_iop7yt73v)}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_5;
    nimStrWasMoved((&X60Qdesugar_5));
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);
    nimStrDestroy(X60Qx_2);}
  if ((!(((NI32)(c_0 & ((NI32)8))) == 0))){
    string_0_sysvq0asl X60Qx_3;
    nimStrWasMoved((&X60Qx_3));
    NI32 X60Qx_25 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_25){
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_6 = X60Qx_3;
    nimStrWasMoved((&X60Qx_3));
    NI32 X60Qx_26 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_27 = len_4_sysvq0asl(X60Qdesugar_6);
    NI32 X60Qx_28 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_26 + X60Qx_27)) + X60Qx_28)));
    add_2_sysvq0asl((&X60Qdesugar_7), s_1);
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_7;
    nimStrWasMoved((&X60Qdesugar_7));
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qx_3);}
  if ((!(((NI32)(c_0 & ((NI32)16))) == 0))){
    string_0_sysvq0asl X60Qx_4;
    nimStrWasMoved((&X60Qx_4));
    NI32 X60Qx_29 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_29){
      nimStrDestroy(X60Qx_4);
      X60Qx_4 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_4);
      X60Qx_4 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_8 = X60Qx_4;
    nimStrWasMoved((&X60Qx_4));
    NI32 X60Qx_30 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_31 = len_4_sysvq0asl(X60Qdesugar_8);
    NI32 X60Qx_32 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_30 + X60Qx_31)) + X60Qx_32)));
    add_2_sysvq0asl((&X60Qdesugar_9), s_1);
    add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_8);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_9;
    nimStrWasMoved((&X60Qdesugar_9));
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qx_4);}
  if ((!(((NI32)(c_0 & ((NI32)32))) == 0))){
    string_0_sysvq0asl X60Qx_5;
    nimStrWasMoved((&X60Qx_5));
    NI32 X60Qx_33 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_33){
      nimStrDestroy(X60Qx_5);
      X60Qx_5 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_5);
      X60Qx_5 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_10 = X60Qx_5;
    nimStrWasMoved((&X60Qx_5));
    NI32 X60Qx_34 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_35 = len_4_sysvq0asl(X60Qdesugar_10);
    NI32 X60Qx_36 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1952804355u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_34 + X60Qx_35)) + X60Qx_36)));
    add_2_sysvq0asl((&X60Qdesugar_11), s_1);
    add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
    add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
      .bytes_0 = 1952804355u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_11;
    nimStrWasMoved((&X60Qdesugar_11));
    nimStrDestroy(X60Qdesugar_11);
    nimStrDestroy(X60Qdesugar_10);
    nimStrDestroy(X60Qx_5);}
  if ((!(((NI32)(c_0 & ((NI32)64))) == 0))){
    string_0_sysvq0asl X60Qx_6;
    nimStrWasMoved((&X60Qx_6));
    NI32 X60Qx_37 = len_4_sysvq0asl(s_1);
    if (0 < X60Qx_37){
      nimStrDestroy(X60Qx_6);
      X60Qx_6 = (string_0_sysvq0asl){
        .bytes_0 = 11009u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_6);
      X60Qx_6 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qdesugar_12 = X60Qx_6;
    nimStrWasMoved((&X60Qx_6));
    NI32 X60Qx_38 = len_4_sysvq0asl(s_1);
    NI32 X60Qx_39 = len_4_sysvq0asl(X60Qdesugar_12);
    NI32 X60Qx_40 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1768318467u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_38 + X60Qx_39)) + X60Qx_40)));
    add_2_sysvq0asl((&X60Qdesugar_13), s_1);
    add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
    add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
      .bytes_0 = 1768318467u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qdesugar_13;
    nimStrWasMoved((&X60Qdesugar_13));
    nimStrDestroy(X60Qdesugar_13);
    nimStrDestroy(X60Qdesugar_12);
    nimStrDestroy(X60Qx_6);}
  string_0_sysvq0asl X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  NI32 X60Qx_41 = len_4_sysvq0asl(s_1);
  if (X60Qx_41 == 0){
    nimStrDestroy(X60Qx_7);
    X60Qx_7 = (string_0_sysvq0asl){
      .bytes_0 = 1852796670u, .more_0 = (&strlit_0_I8446236512461598146_croph25r5)}
    ;}
  else {
    nimStrDestroy(X60Qx_7);
    X60Qx_7 = s_1;
    nimStrWasMoved((&s_1));}
  nimStrDestroy(result_0);
  result_0 = X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  nimStrDestroy(X60Qx_7);
  nimStrDestroy(s_1);
  return result_0;
  nimStrDestroy(X60Qx_7);
  nimStrDestroy(s_1);
  return result_0;}
NI32 capsNeeded_0_iop7yt73v(string_0_sysvq0asl name_0){
  NI32 result_1;
  NB8 X60Qtc_9 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'m');
  if (X60Qtc_9){
    NB8 X60Qtc_10 = nimStrAtLe_0_sysvq0asl(name_0, 3, (NC8)'c');
    if (X60Qtc_10){
      NB8 X60Qtc_11 = nimStrAtLe_0_sysvq0asl(name_0, 3, (NC8)'F');
      if (X60Qtc_11){
        NB8 X60Qtc_12 = nimStrAtLe_0_sysvq0asl(name_0, 5, (NC8)'r');
        if (X60Qtc_12){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I11626809062896146847_croph25r5)}
          )){
            goto X60Qsc_5;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4303973984874128508_intzsnzax)}
          )){
            goto X60Qsc_5;}}
        else {
          NB8 X60Qtc_13 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'d');
          if (X60Qtc_13){
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I11216437567223755660_iop7yt73v)}
            )){
              goto X60Qsc_7;}}
          else {
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4300154733488353634_iop7yt73v)}
            )){
              goto X60Qsc_7;}
            else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I3006705858755300605_iop7yt73v)}
            )){
              goto X60Qsc_7;}}}}
      else {
        NB8 X60Qtc_14 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'f');
        if (X60Qtc_14){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1953720062u, .more_0 = (&strlit_0_I17563301282676592437_iop7yt73v)}
          )){
            goto X60Qsc_5;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I17971560687400798064_intzsnzax)}
          )){
            goto X60Qsc_5;}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1953721598u, .more_0 = (&strlit_0_I885514587362827984_iop7yt73v)}
          )){
            goto X60Qsc_5;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15418518599716865203_hos1fpv3m1)}
          )){
            goto X60Qsc_5;}}}}
    else {
      NB8 X60Qtc_15 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'c');
      if (X60Qtc_15){
        NB8 X60Qtc_16 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'b');
        if (X60Qtc_16){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I18337270522941735704_iop7yt73v)}
          )){
            goto X60Qsc_8;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1667457534u, .more_0 = (&strlit_0_I4398256179715674167_iop7yt73v)}
          )){
            goto X60Qsc_8;}}
        else {
          NB8 X60Qtc_17 = nimStrAtLe_0_sysvq0asl(name_0, 1, (NC8)'l');
          if (X60Qtc_17){
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I10138590777481088495_iop7yt73v)}
            )){
              goto X60Qsc_1;}
            else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1684562942u, .more_0 = (&strlit_0_I2723496349315214549_hos1fpv3m1)}
            )){
              goto X60Qsc_4;}}
          else {
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I9620132962526484305_iop7yt73v)}
            )){
              goto X60Qsc_8;}}}}
      else {
        NB8 X60Qtc_18 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'f');
        if (X60Qtc_18){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1886349054u, .more_0 = (&strlit_0_I754749039837241777_iop7yt73v)}
          )){
            goto X60Qsc_2;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1769498110u, .more_0 = (&strlit_0_I7616721286816756_iop7yt73v)}
          )){
            goto X60Qsc_7;}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
          )){
            goto X60Qsc_4;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1936289022u, .more_0 = (&strlit_0_I15031238125720431605_iop7yt73v)}
          )){
            goto X60Qsc_8;}}}}}
  else {
    NB8 X60Qtc_19 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'r');
    if (X60Qtc_19){
      NB8 X60Qtc_20 = nimStrAtLe_0_sysvq0asl(name_0, 1, (NC8)'e');
      if (X60Qtc_20){
        NB8 X60Qtc_21 = nimStrAtLe_0_sysvq0asl(name_0, 2, (NC8)'a');
        if (X60Qtc_21){
          NB8 X60Qtc_22 = nimStrAtLe_0_sysvq0asl(name_0, 3, (NC8)'d');
          if (X60Qtc_22){
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12542130669033277445_croph25r5)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12278932653354239625_iop7yt73v)}
            )){
              goto X60Qsc_1;}}
          else {
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I17150237903071301653_iop7yt73v)}
            )){
              goto X60Qsc_5;}}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1852142334u, .more_0 = (&strlit_0_I1187689770688346212_iop7yt73v)}
          )){
            goto X60Qsc_4;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I8779604385735337050_iop7yt73v)}
          )){
            goto X60Qsc_8;}}}
      else {
        NB8 X60Qtc_23 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'o');
        if (X60Qtc_23){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
          )){
            goto X60Qsc_1;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
          )){
            goto X60Qsc_2;}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
          )){
            goto X60Qsc_4;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I17106851413817154788_iop7yt73v)}
          )){
            goto X60Qsc_7;}}}}
    else {
      NB8 X60Qtc_24 = nimStrAtLe_0_sysvq0asl(name_0, 1, (NC8)'n');
      if (X60Qtc_24){
        NB8 X60Qtc_25 = nimStrAtLe_0_sysvq0asl(name_0, 2, (NC8)'n');
        if (X60Qtc_25){
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I2912131129587157308_hos1fpv3m1)}
          )){
            goto X60Qsc_4;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1852142590u, .more_0 = (&strlit_0_I13696262612503621358_iop7yt73v)}
          )){
            goto X60Qsc_8;}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I900530018976380608_intzsnzax)}
          )){
            goto X60Qsc_4;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I399834492833889323_iop7yt73v)}
          )){
            goto X60Qsc_8;}}}
      else {
        NB8 X60Qtc_26 = nimStrAtLe_0_sysvq0asl(name_0, 0, (NC8)'s');
        if (X60Qtc_26){
          NB8 X60Qtc_27 = nimStrAtLe_0_sysvq0asl(name_0, 1, (NC8)'t');
          if (X60Qtc_27){
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
            )){
              goto X60Qsc_5;}
            else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1668248574u, .more_0 = (&strlit_0_I15415642409673360391_iop7yt73v)}
            )){
              goto X60Qsc_8;}}
          else {
            if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
              .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4050815769175754417_hos1fpv3m1)}
            )){
              goto X60Qsc_6;}}}
        else {
          if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 2037544190u, .more_0 = (&strlit_0_I14251590839437571501_intzsnzax)}
          )){
            goto X60Qsc_1;}
          else if (equalStrings_0_sysvq0asl(name_0, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I13565819874765507459_croph25r5)}
          )){
            goto X60Qsc_3;}}}}}
  goto X60Qsc_29;
  X60Qsc_0: ;
  result_1 = ((NI32)1);
  goto X60Qsc_28;
  X60Qsc_1: ;
  result_1 = ((NI32)1);
  goto X60Qsc_28;
  X60Qsc_2: ;
  result_1 = ((NI32)(((NI32)1) | ((NI32)2)));
  goto X60Qsc_28;
  X60Qsc_3: ;
  result_1 = ((NI32)2);
  goto X60Qsc_28;
  X60Qsc_4: ;
  result_1 = ((NI32)2);
  goto X60Qsc_28;
  X60Qsc_5: ;
  result_1 = ((NI32)4);
  goto X60Qsc_28;
  X60Qsc_6: ;
  result_1 = ((NI32)8);
  goto X60Qsc_28;
  X60Qsc_7: ;
  result_1 = ((NI32)16);
  goto X60Qsc_28;
  X60Qsc_8: ;
  result_1 = ((NI32)32);
  goto X60Qsc_28;
  X60Qsc_29: ;
  result_1 = ((NI32)0);
  X60Qsc_28: ;
  return result_1;}
NB8 perInterpPolicies_0_iop7yt73v(void){
  NB8 result_3;
  result_3 = gPerInterp_0_iop7yt73v;
  return result_3;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* currentIoPolicy_0_iop7yt73v(void){
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* result_5;
  eQwasmovedQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v((&result_5));
  eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(result_5);
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qx_54 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
  result_5 = X60Qx_54;
  return result_5;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* useIoPolicy_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_0){
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* result_6;
  eQwasmovedQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v((&result_6));
  eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(result_6);
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qx_55 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
  result_6 = X60Qx_55;
  if (p_0 == NIM_NIL){
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
    X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qx_56 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gProcess_0_iop7yt73v);
    gCur_0_iop7yt73v = X60Qx_56;}
  else {
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
    X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qx_57 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_0);
    gCur_0_iop7yt73v = X60Qx_57;}
  gCurOn_0_iop7yt73v = (*gCur_0_iop7yt73v).d_00.on_0;
  return result_6;}
NB8 isSep_0_iop7yt73v(NC8 c_1){
  NB8 result_7;
  NB8 X60Qx_58;
  if (c_1 == (NC8)'/'){
    X60Qx_58 = NIM_TRUE;}
  else {
    X60Qx_58 = (c_1 == (NC8)'\\');}
  result_7 = X60Qx_58;
  return result_7;}
NC8 foldc_0_iop7yt73v(NC8 c_2){
  NC8 result_8;
  result_8 = c_2;
  return result_8;}
seq_0_Ixdx2fh1_aow7lb5cq1 pathParts_0_iop7yt73v(string_0_sysvq0asl p_1){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_9;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_9));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_9);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_59 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_9 = X60Qx_59;
  NI32 i_0 = 0;
  string_0_sysvq0asl cur_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 rooted_0 = NIM_FALSE;
  NB8 uncRoot_0 = NIM_FALSE;
  NB8 X60Qx_60;
  NB8 X60Qx_61;
  NB8 X60Qx_62;
  NI32 X60Qx_63 = len_4_sysvq0asl(p_1);
  if (3 <= X60Qx_63){
    NC8 X60Qx_64 = getQ_9_sysvq0asl(p_1, 1);
    X60Qx_62 = (X60Qx_64 == (NC8)':');}
  else {
    X60Qx_62 = NIM_FALSE;}
  if (X60Qx_62){
    NC8 X60Qx_65 = getQ_9_sysvq0asl(p_1, 2);
    NB8 X60Qx_66 = isSep_0_iop7yt73v(X60Qx_65);
    X60Qx_61 = X60Qx_66;}
  else {
    X60Qx_61 = NIM_FALSE;}
  if (X60Qx_61){
    NB8 X60Qx_67;
    NB8 X60Qx_68;
    NC8 X60Qx_69 = getQ_9_sysvq0asl(p_1, 0);
    if ((NC8)'a' <= X60Qx_69){
      NC8 X60Qx_70 = getQ_9_sysvq0asl(p_1, 0);
      X60Qx_68 = (X60Qx_70 <= (NC8)'z');}
    else {
      X60Qx_68 = NIM_FALSE;}
    if (X60Qx_68){
      X60Qx_67 = NIM_TRUE;}
    else {
      NB8 X60Qx_71;
      NC8 X60Qx_72 = getQ_9_sysvq0asl(p_1, 0);
      if ((NC8)'A' <= X60Qx_72){
        NC8 X60Qx_73 = getQ_9_sysvq0asl(p_1, 0);
        X60Qx_71 = (X60Qx_73 <= (NC8)'Z');}
      else {
        X60Qx_71 = NIM_FALSE;}
      X60Qx_67 = X60Qx_71;}
    X60Qx_60 = X60Qx_67;}
  else {
    X60Qx_60 = NIM_FALSE;}
  NB8 driveAbs_0 = X60Qx_60;
  if (driveAbs_0){
    string_0_sysvq0asl drive_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NC8 X60Qx_74 = getQ_9_sysvq0asl(p_1, 0);
    NC8 X60Qx_75 = foldc_0_iop7yt73v(X60Qx_74);
    add_1_sysvq0asl((&drive_0), X60Qx_75);
    add_1_sysvq0asl((&drive_0), (NC8)':');
    string_0_sysvq0asl X60Qtmp_3 = drive_0;
    nimStrWasMoved((&drive_0));
    add_0_Ig6072n_aow7lb5cq1((&result_9), X60Qtmp_3);
    rooted_0 = NIM_TRUE;
    i_0 = 3;
    nimStrDestroy(drive_0);}
  else {
    if (uncRoot_0){
      add_0_Ig6072n_aow7lb5cq1((&result_9), (string_0_sysvq0asl){
        .bytes_0 = 6052866u, .more_0 = NIM_NIL}
      );
      rooted_0 = NIM_TRUE;
      i_0 = 2;}
    else {
      NB8 X60Qx_76;
      NI32 X60Qx_77 = len_4_sysvq0asl(p_1);
      if (1 <= X60Qx_77){
        NC8 X60Qx_78 = getQ_9_sysvq0asl(p_1, 0);
        NB8 X60Qx_79 = isSep_0_iop7yt73v(X60Qx_78);
        X60Qx_76 = X60Qx_79;}
      else {
        X60Qx_76 = NIM_FALSE;}
      if (X60Qx_76){
        add_0_Ig6072n_aow7lb5cq1((&result_9), (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        rooted_0 = NIM_TRUE;
        i_0 = 1;}}}
  {
    while (NIM_TRUE){
      NI32 X60Qx_80 = len_4_sysvq0asl(p_1);
      if (i_0 <= X60Qx_80){
        NB8 X60Qx_81;
        NI32 X60Qx_82 = len_4_sysvq0asl(p_1);
        if (i_0 == X60Qx_82){
          X60Qx_81 = NIM_TRUE;}
        else {
          NC8 X60Qx_83 = getQ_9_sysvq0asl(p_1, i_0);
          NB8 X60Qx_84 = isSep_0_iop7yt73v(X60Qx_83);
          X60Qx_81 = X60Qx_84;}
        if (X60Qx_81){
          NB8 X60Qx_85;
          NI32 X60Qx_86 = len_4_sysvq0asl(cur_0);
          if (0 < X60Qx_86){
            NB8 X60Qx_87 = eqQ_20_sysvq0asl(cur_0, (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            X60Qx_85 = (!X60Qx_87);}
          else {
            X60Qx_85 = NIM_FALSE;}
          if (X60Qx_85){
            NB8 X60Qx_88 = eqQ_20_sysvq0asl(cur_0, (string_0_sysvq0asl){
              .bytes_0 = 3026434u, .more_0 = NIM_NIL}
            );
            if (X60Qx_88){
              NB8 X60Qx_8;
              NI64 X60Qx_9;
              if (rooted_0){
                X60Qx_9 = 1;}
              else {
                X60Qx_9 = 0;}
              if (X60Qx_9 < result_9.len_0){
                string_0_sysvq0asl* X60Qx_89 = getQ_7_Ir6d0tw_aow7lb5cq1(result_9, ((NI32)(result_9.len_0 - 1)));
                NB8 X60Qx_90 = eqQ_20_sysvq0asl((*X60Qx_89), (string_0_sysvq0asl){
                  .bytes_0 = 3026434u, .more_0 = NIM_NIL}
                );
                X60Qx_8 = (!X60Qx_90);}
              else {
                X60Qx_8 = NIM_FALSE;}
              if (X60Qx_8){
                NI32 X60Qx_91 = len_3_Ixq6taz_aow7lb5cq1(result_9);
                setLen_0_Iejjsiw_intzsnzax((&result_9), ((NI32)(X60Qx_91 - 1)));}
              else {
                if ((!rooted_0)){
                  add_0_Ig6072n_aow7lb5cq1((&result_9), (string_0_sysvq0asl){
                    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
                  );}}}
            else {
              string_0_sysvq0asl X60Qtmp_4 = cur_0;
              nimStrWasMoved((&cur_0));
              add_0_Ig6072n_aow7lb5cq1((&result_9), X60Qtmp_4);}}
          nimStrDestroy(cur_0);
          cur_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;}
        else {
          NC8 X60Qx_92 = getQ_9_sysvq0asl(p_1, i_0);
          NC8 X60Qx_93 = foldc_0_iop7yt73v(X60Qx_92);
          add_1_sysvq0asl((&cur_0), X60Qx_93);}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(cur_0);
  return result_9;
  nimStrDestroy(cur_0);
  return result_9;}
NB8 partsCoverPath_0_iop7yt73v(seq_0_Ixdx2fh1_aow7lb5cq1 gp_0, seq_0_Ixdx2fh1_aow7lb5cq1 pp_0){
  NB8 result_10;
  NI32 X60Qx_94 = len_3_Ixq6taz_aow7lb5cq1(gp_0);
  if (X60Qx_94 == 0){
    return NIM_FALSE;}
  if (pp_0.len_0 < gp_0.len_0){
    return NIM_FALSE;}
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_95 = len_3_Ixq6taz_aow7lb5cq1(gp_0);
      if (i_2 < X60Qx_95){
        string_0_sysvq0asl* X60Qx_96 = getQ_7_Ir6d0tw_aow7lb5cq1(gp_0, i_2);
        string_0_sysvq0asl* X60Qx_97 = getQ_7_Ir6d0tw_aow7lb5cq1(pp_0, i_2);
        NB8 X60Qx_98 = eqQ_20_sysvq0asl((*X60Qx_96), (*X60Qx_97));
        if ((!X60Qx_98)){
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_10 = NIM_TRUE;
  return result_10;}
NB8 policyOn_0_iop7yt73v(void){
  NB8 result_13;
  result_13 = gCurOn_0_iop7yt73v;
  return result_13;}
NB8 capsDeniedOn_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_8, NI32 need_0, string_0_sysvq0asl path_0){
  NB8 result_18;
  if ((!(*p_8).d_00.on_0)){
    return NIM_FALSE;}
  if (need_0 == 0){
    return NIM_FALSE;}
  if (((NI32)(need_0 & (*p_8).d_00.granted_0)) == need_0){
    return NIM_FALSE;}
  NB8 X60Qx_109;
  NI32 X60Qx_110 = len_4_sysvq0asl(path_0);
  if (0 < X60Qx_110){
    X60Qx_109 = (0 < (*p_8).d_00.grants_0.len_0);}
  else {
    X60Qx_109 = NIM_FALSE;}
  if (X60Qx_109){
    seq_0_Ixdx2fh1_aow7lb5cq1 pp_1 = pathParts_0_iop7yt73v(path_0);
    NI32 i_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_111 = len_3_I1rs8q11_iop7yt73v((*p_8).d_00.grants_0);
        if (i_3 < X60Qx_111){
          NB8 X60Qx_112;
          PathGrant_0_iop7yt73v* X60Qx_113 = getQ_7_Iane2hm1_iop7yt73v((*p_8).d_00.grants_0, i_3);
          if (((NI32)((*X60Qx_113).caps_0 & need_0)) == need_0){
            PathGrant_0_iop7yt73v* X60Qx_114 = getQ_7_Iane2hm1_iop7yt73v((*p_8).d_00.grants_0, i_3);
            NB8 X60Qx_115 = partsCoverPath_0_iop7yt73v((*X60Qx_114).parts_0, pp_1);
            X60Qx_112 = X60Qx_115;}
          else {
            X60Qx_112 = NIM_FALSE;}
          if (X60Qx_112){
            eQdestroy_1_Ivioh0a_aow7lb5cq1(pp_1);
            return NIM_FALSE;}
          inc_1_I6wjjge_aow2h993l1((&i_3));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(pp_1);}
  result_18 = NIM_TRUE;
  return result_18;}
NB8 capsDeniedOn_1_iop7yt73v(NI32 need_1, string_0_sysvq0asl path_1){
  NB8 result_19;
  NB8 X60Qx_116 = capsDeniedOn_0_iop7yt73v(gCur_0_iop7yt73v, need_1, path_1);
  result_19 = X60Qx_116;
  return result_19;}
NB8 policyDeniesPath_0_iop7yt73v(string_0_sysvq0asl name_2, string_0_sysvq0asl path_2, NI32* needed_1){
  NB8 result_20;
  NI32 X60Qx_117 = capsNeeded_0_iop7yt73v(name_2);
  (*needed_1) = X60Qx_117;
  NB8 X60Qx_118 = capsDeniedOn_0_iop7yt73v(gCur_0_iop7yt73v, (*needed_1), path_2);
  result_20 = X60Qx_118;
  return result_20;}
NB8 readAuditOn_0_iop7yt73v(void){
  NB8 result_21;
  result_21 = (*gCur_0_iop7yt73v).d_00.auditReads_0;
  return result_21;}
NU64 fnv1a_0_iop7yt73v(string_0_sysvq0asl s_0){
  NU64 result_22;
  result_22 = ((NU64)14695981039346656037ull);
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_119 = len_4_sysvq0asl(s_0);
      if (i_5 < X60Qx_119){
        NC8 X60Qx_120 = getQ_9_sysvq0asl(s_0, i_5);
        result_22 = ((NU64)(result_22 ^ ((NU64)((NU8)X60Qx_120))));
        result_22 = ((NU64)(result_22 * ((NU64)1099511628211ull)));
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_22;}
void recordRead_0_iop7yt73v(string_0_sysvq0asl path_3, string_0_sysvq0asl content_0){
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_17 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
  if ((!(*p_17).d_00.auditReads_0)){
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_17);
    return;}
  NU64 h_0 = fnv1a_0_iop7yt73v(content_0);
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_121 = len_3_Ifa3bd_iop7yt73v((*p_17).d_00.reads_0);
      if (i_6 < X60Qx_121){
        NB8 X60Qx_122;
        NB8 X60Qx_123;
        ReadRecord_0_iop7yt73v* X60Qx_124 = getQ_7_Iylxa0x_iop7yt73v((*p_17).d_00.reads_0, i_6);
        if ((*X60Qx_124).hashed_0){
          ReadRecord_0_iop7yt73v* X60Qx_125 = getQ_7_Iylxa0x_iop7yt73v((*p_17).d_00.reads_0, i_6);
          NB8 X60Qx_126 = eqQ_20_sysvq0asl((*X60Qx_125).path_0, path_3);
          X60Qx_123 = X60Qx_126;}
        else {
          X60Qx_123 = NIM_FALSE;}
        if (X60Qx_123){
          ReadRecord_0_iop7yt73v* X60Qx_127 = getQ_7_Iylxa0x_iop7yt73v((*p_17).d_00.reads_0, i_6);
          X60Qx_122 = ((*X60Qx_127).hash_0 == h_0);}
        else {
          X60Qx_122 = NIM_FALSE;}
        if (X60Qx_122){
          eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_17);
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_128 = nimStrDup(path_3);
  NI32 X60Qx_129 = len_4_sysvq0asl(content_0);
  add_0_Ijr069w1_iop7yt73v((&(*p_17).d_00.reads_0), (ReadRecord_0_iop7yt73v){
    .path_0 = X60Qx_128, .hash_0 = h_0, .size_0 = X60Qx_129, .hashed_0 = NIM_TRUE}
  );
  eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_17);}
void recordOpen_0_iop7yt73v(string_0_sysvq0asl path_4){
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_18 = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gCur_0_iop7yt73v);
  if ((!(*p_18).d_00.auditReads_0)){
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_18);
    return;}
  NI32 i_8 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_130 = len_3_Ifa3bd_iop7yt73v((*p_18).d_00.reads_0);
      if (i_8 < X60Qx_130){
        NB8 X60Qx_131;
        ReadRecord_0_iop7yt73v* X60Qx_132 = getQ_7_Iylxa0x_iop7yt73v((*p_18).d_00.reads_0, i_8);
        if ((!(*X60Qx_132).hashed_0)){
          ReadRecord_0_iop7yt73v* X60Qx_133 = getQ_7_Iylxa0x_iop7yt73v((*p_18).d_00.reads_0, i_8);
          NB8 X60Qx_134 = eqQ_20_sysvq0asl((*X60Qx_133).path_0, path_4);
          X60Qx_131 = X60Qx_134;}
        else {
          X60Qx_131 = NIM_FALSE;}
        if (X60Qx_131){
          eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_18);
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_8));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_135 = nimStrDup(path_4);
  add_0_Ijr069w1_iop7yt73v((&(*p_18).d_00.reads_0), (ReadRecord_0_iop7yt73v){
    .path_0 = X60Qx_135, .hash_0 = ((NU64)0u), .size_0 = 0, .hashed_0 = NIM_FALSE}
  );
  eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(p_18);}
void recordViolation_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_12, string_0_sysvq0asl name_3, NI32 needed_2){
  inc_1_I6wjjge_aow2h993l1((&(*p_12).d_00.violations_0));
  if ((*p_12).d_00.violations_0 == 1){
    string_0_sysvq0asl* X60Qlhs_10 = (&(*p_12).d_00.violNative_0);
    string_0_sysvq0asl X60Qlhs_11 = (*p_12).d_00.violNative_0;
    string_0_sysvq0asl X60Qx_153 = nimStrDup(name_3);
    (*X60Qlhs_10) = X60Qx_153;
    nimStrDestroy(X60Qlhs_11);
    (*p_12).d_00.violNeeded_0 = needed_2;}}
void recordViolation_1_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3){
  recordViolation_0_iop7yt73v(gCur_0_iop7yt73v, name_4, needed_3);}
string_0_sysvq0asl policyMessage_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_16, string_0_sysvq0asl name_5, NI32 needed_4, string_0_sysvq0asl path_5){
  string_0_sysvq0asl result_34;
  nimStrWasMoved((&result_34));
  string_0_sysvq0asl X60Qdesugar_20 = capName_0_iop7yt73v(needed_4);
  NI32 X60Qx_156 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17663818852377669490_iop7yt73v)}
  );
  NI32 X60Qx_157 = len_4_sysvq0asl(name_5);
  NI32 X60Qx_158 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I16137639778510327014_iop7yt73v)}
  );
  NI32 X60Qx_159 = len_4_sysvq0asl(X60Qdesugar_20);
  string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_156 + X60Qx_157)) + X60Qx_158)) + X60Qx_159)));
  add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17663818852377669490_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_21), name_5);
  add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I16137639778510327014_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_21), X60Qdesugar_20);
  nimStrDestroy(result_34);
  result_34 = X60Qdesugar_21;
  nimStrWasMoved((&X60Qdesugar_21));
  NI32 X60Qx_160 = len_4_sysvq0asl(path_5);
  if (0 < X60Qx_160){
    NI32 X60Qx_161 = len_4_sysvq0asl(result_34);
    NI32 X60Qx_162 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
    );
    NI32 X60Qx_163 = len_4_sysvq0asl(path_5);
    NI32 X60Qx_164 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_22 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_161 + X60Qx_162)) + X60Qx_163)) + X60Qx_164)));
    add_2_sysvq0asl((&X60Qdesugar_22), result_34);
    add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_22), path_5);
    add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(result_34);
    result_34 = X60Qdesugar_22;
    nimStrWasMoved((&X60Qdesugar_22));
    nimStrDestroy(X60Qdesugar_22);}
  string_0_sysvq0asl X60Qdesugar_23 = capName_0_iop7yt73v((*p_16).d_00.granted_0);
  NI32 X60Qx_165 = len_4_sysvq0asl(result_34);
  NI32 X60Qx_166 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1948269566u, .more_0 = (&strlit_0_I16651577260944187724_iop7yt73v)}
  );
  NI32 X60Qx_167 = len_4_sysvq0asl(X60Qdesugar_23);
  string_0_sysvq0asl X60Qdesugar_24 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_165 + X60Qx_166)) + X60Qx_167)));
  add_2_sysvq0asl((&X60Qdesugar_24), result_34);
  add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
    .bytes_0 = 1948269566u, .more_0 = (&strlit_0_I16651577260944187724_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_24), X60Qdesugar_23);
  nimStrDestroy(result_34);
  result_34 = X60Qdesugar_24;
  nimStrWasMoved((&X60Qdesugar_24));
  if (0 < (*p_16).d_00.grants_0.len_0){
    NI32 X60Qx_168 = len_3_I1rs8q11_iop7yt73v((*p_16).d_00.grants_0);
    string_0_sysvq0asl X60Qdesugar_25 = dollarQ_2_sysvq0asl(X60Qx_168);
    NI32 X60Qx_169 = len_4_sysvq0asl(result_34);
    NI32 X60Qx_170 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1819287806u, .more_0 = (&strlit_0_I3188702685911042556_iop7yt73v)}
    );
    NI32 X60Qx_171 = len_4_sysvq0asl(X60Qdesugar_25);
    NI32 X60Qx_172 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1634738430u, .more_0 = (&strlit_0_I9020742201384713734_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_169 + X60Qx_170)) + X60Qx_171)) + X60Qx_172)));
    add_2_sysvq0asl((&X60Qdesugar_26), result_34);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 1819287806u, .more_0 = (&strlit_0_I3188702685911042556_iop7yt73v)}
    );
    add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_25);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 1634738430u, .more_0 = (&strlit_0_I9020742201384713734_iop7yt73v)}
    );
    nimStrDestroy(result_34);
    result_34 = X60Qdesugar_26;
    nimStrWasMoved((&X60Qdesugar_26));
    nimStrDestroy(X60Qdesugar_26);
    nimStrDestroy(X60Qdesugar_25);}
  string_0_sysvq0asl X60Qlhs_12 = ampQ_0_sysvq0asl(result_34, (string_0_sysvq0asl){
    .bytes_0 = 1142959870u, .more_0 = (&strlit_0_I2364452291923173386_iop7yt73v)}
  );
  nimStrDestroy(result_34);
  result_34 = X60Qlhs_12;
  NB8 X60Qx_173;
  NI32 X60Qx_174 = len_4_sysvq0asl((*p_16).d_00.owner_0);
  if (0 < X60Qx_174){
    NB8 X60Qx_175 = eqQ_20_sysvq0asl((*p_16).d_00.owner_0, (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
    );
    X60Qx_173 = (!X60Qx_175);}
  else {
    X60Qx_173 = NIM_FALSE;}
  if (X60Qx_173){
    string_0_sysvq0asl X60Qdesugar_27 = nimStrDup((*p_16).d_00.owner_0);
    NI32 X60Qx_176 = len_4_sysvq0asl(result_34);
    NI32 X60Qx_177 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1885020414u, .more_0 = (&strlit_0_I13007304069900691547_iop7yt73v)}
    );
    NI32 X60Qx_178 = len_4_sysvq0asl(X60Qdesugar_27);
    NI32 X60Qx_179 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_28 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_176 + X60Qx_177)) + X60Qx_178)) + X60Qx_179)));
    add_2_sysvq0asl((&X60Qdesugar_28), result_34);
    add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
      .bytes_0 = 1885020414u, .more_0 = (&strlit_0_I13007304069900691547_iop7yt73v)}
    );
    add_2_sysvq0asl((&X60Qdesugar_28), X60Qdesugar_27);
    add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(result_34);
    result_34 = X60Qdesugar_28;
    nimStrWasMoved((&X60Qdesugar_28));
    nimStrDestroy(X60Qdesugar_28);
    nimStrDestroy(X60Qdesugar_27);}
  string_0_sysvq0asl X60Qlhs_13 = ampQ_0_sysvq0asl(result_34, (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(result_34);
  result_34 = X60Qlhs_13;
  nimStrDestroy(X60Qdesugar_24);
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_21);
  nimStrDestroy(X60Qdesugar_20);
  return result_34;
  nimStrDestroy(X60Qdesugar_24);
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_21);
  nimStrDestroy(X60Qdesugar_20);
  return result_34;}
string_0_sysvq0asl policyMessage_1_iop7yt73v(string_0_sysvq0asl name_6, NI32 needed_5, string_0_sysvq0asl path_6){
  string_0_sysvq0asl result_35;
  nimStrWasMoved((&result_35));
  nimStrDestroy(result_35);
  string_0_sysvq0asl X60Qx_180 = policyMessage_0_iop7yt73v(gCur_0_iop7yt73v, name_6, needed_5, path_6);
  result_35 = X60Qx_180;
  return result_35;}
static inline seq_0_Iq7pam4_iop7yt73v newSeqUninit_0_I8eutte_iop7yt73v(NI32 size_3){
  seq_0_Iq7pam4_iop7yt73v result_36;
  if (size_3 == 0){
    result_36 = (seq_0_Iq7pam4_iop7yt73v){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Izkmv63_iop7yt73v(size_3);
    void* X60Qx_181 = alloc_1_sysvq0asl(memSize_0);
    result_36 = (seq_0_Iq7pam4_iop7yt73v){
      .len_0 = size_3, .data_0 = ((PathGrant_0_iop7yt73v*)X60Qx_181)}
    ;
    if ((!(result_36.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_182 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_36.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_36;}
static inline seq_0_Iero8tq_iop7yt73v newSeqUninit_0_Inl2vj4_iop7yt73v(NI32 size_5){
  seq_0_Iero8tq_iop7yt73v result_37;
  if (size_5 == 0){
    result_37 = (seq_0_Iero8tq_iop7yt73v){
      .len_0 = size_5, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I057n0g1_iop7yt73v(size_5);
    void* X60Qx_183 = alloc_1_sysvq0asl(memSize_1);
    result_37 = (seq_0_Iero8tq_iop7yt73v){
      .len_0 = size_5, .data_0 = ((ReadRecord_0_iop7yt73v*)X60Qx_183)}
    ;
    if ((!(result_37.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_184 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_37.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_37;}
static inline NI32 len_3_I1rs8q11_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_22){
  NI32 result_41;
  result_41 = s_22.len_0;
  return result_41;}
static inline PathGrant_0_iop7yt73v* getQ_7_Iane2hm1_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_23, NI32 i_12){
  NB8 X60Qx_192;
  if (i_12 < s_23.len_0){
    X60Qx_192 = (0 <= i_12);}
  else {
    X60Qx_192 = NIM_FALSE;}
  if ((!X60Qx_192)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  PathGrant_0_iop7yt73v* result_42;
  result_42 = (&s_23.data_0[i_12]);
  return result_42;}
static inline NI32 len_3_Ifa3bd_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_24){
  NI32 result_43;
  result_43 = s_24.len_0;
  return result_43;}
static inline ReadRecord_0_iop7yt73v* getQ_7_Iylxa0x_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_25, NI32 i_13){
  NB8 X60Qx_193;
  if (i_13 < s_25.len_0){
    X60Qx_193 = (0 <= i_13);}
  else {
    X60Qx_193 = NIM_FALSE;}
  if ((!X60Qx_193)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  ReadRecord_0_iop7yt73v* result_44;
  result_44 = (&s_25.data_0[i_13]);
  return result_44;}
static inline void add_0_Ijr069w1_iop7yt73v(seq_0_Iero8tq_iop7yt73v* s_26, ReadRecord_0_iop7yt73v elem_5){
  NI32 L_2 = (*s_26).len_0;
  NI32 X60Qx_194 = capInBytes_0_Ibi6vw11_iop7yt73v((*s_26));
  if (X60Qx_194 < ((NI32)(((NI32)(L_2 * sizeof(ReadRecord_0_iop7yt73v))) + sizeof(ReadRecord_0_iop7yt73v)))){
    NB8 X60Qx_195 = resize_0_Ipdnn431_iop7yt73v(s_26, 1);
    if ((!X60Qx_195)){
      eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(elem_5);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_26).len_0));
  (*s_26).data_0[L_2] = elem_5;}
static inline NI32 memSizeInBytes_0_Izkmv63_iop7yt73v(NI32 size_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_46;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_9, sizeof(PathGrant_0_iop7yt73v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_46 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_46 = ((NI32)2147483647);}
  return result_46;}
static inline NI32 memSizeInBytes_0_I057n0g1_iop7yt73v(NI32 size_10){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_47;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_10, sizeof(ReadRecord_0_iop7yt73v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_47 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_47 = ((NI32)2147483647);}
  return result_47;}
static inline NI32 capInBytes_0_Ibi6vw11_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_34){
  NI32 result_53;
  NI32 X60Qx_12;
  if ((!(s_34.data_0 == NIM_NIL))){
    NI32 X60Qx_205 = allocatedSize_0_sysvq0asl(((void*)((void*)s_34.data_0)));
    X60Qx_12 = X60Qx_205;}
  else {
    X60Qx_12 = 0;}
  result_53 = X60Qx_12;
  return result_53;}
NB8 resize_0_Ipdnn431_iop7yt73v(seq_0_Iero8tq_iop7yt73v* dest_5, NI32 addedElements_5){
  NB8 result_54;
  NI32 X60Qx_206 = capInBytes_0_Ibi6vw11_iop7yt73v((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_206 / sizeof(ReadRecord_0_iop7yt73v)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_5 = memSizeInBytes_0_I057n0g1_iop7yt73v(newCap_2);
  void* X60Qx_207 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((ReadRecord_0_iop7yt73v*)X60Qx_207);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_54 = NIM_FALSE;}
  else {
    result_54 = NIM_TRUE;}
  return result_54;}
void eQdestroy_1_I4erhdv1_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_44){
  if ((!(s_44.data_0 == NIM_NIL))){
    NI32 i_20 = 0;
    {
      while (i_20 < s_44.len_0){
        eQdestroyQ_SX50athX47rant0iop7yt73v_0_iop7yt73v(s_44.data_0[i_20]);
        inc_1_I6wjjge_aow2h993l1((&i_20));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_44.data_0)));}}
void eQdestroy_1_I5kozgw_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_46){
  if ((!(s_46.data_0 == NIM_NIL))){
    NI32 i_24 = 0;
    {
      while (i_24 < s_46.len_0){
        eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(s_46.data_0[i_24]);
        inc_1_I6wjjge_aow2h993l1((&i_24));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_46.data_0)));}}
void eQdestroyQ_SX50athX47rant0iop7yt73v_0_iop7yt73v(PathGrant_0_iop7yt73v dest_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.parts_0);
  nimStrDestroy(dest_0.prefix_0);}
void eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(ReadRecord_0_iop7yt73v dest_0){
  nimStrDestroy(dest_0.path_0);}
void eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(IoPolicy_Obj_0_iop7yt73v* dest_0){
  nimStrDestroy((*dest_0).violNative_0);
  eQdestroy_1_I5kozgw_iop7yt73v((*dest_0).reads_0);
  nimStrDestroy((*dest_0).owner_0);
  eQdestroy_1_I4erhdv1_iop7yt73v((*dest_0).grants_0);}
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_235 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_235){
      eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* src_0){
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_iop7yt73v(void){
  if (X60QiniGuard_0_iop7yt73v){
    return;}
  X60QiniGuard_0_iop7yt73v = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  void* X60Qx_42 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax));
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qtmp_0 = ((X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax*)X60Qx_42);
  seq_0_Iq7pam4_iop7yt73v X60Qx_43 = newSeqUninit_0_I8eutte_iop7yt73v(0);
  seq_0_Iero8tq_iop7yt73v X60Qx_44 = newSeqUninit_0_Inl2vj4_iop7yt73v(0);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax){
    .r_00 = 0, .d_00 = (IoPolicy_Obj_0_iop7yt73v){
      .on_0 = NIM_FALSE, .granted_0 = ((NI32)127), .grants_0 = X60Qx_43, .sealed_0 = NIM_FALSE, .owner_0 = (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
      , .auditReads_0 = NIM_FALSE, .reads_0 = X60Qx_44, .violations_0 = 0, .violNative_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .violNeeded_0 = 0}}
  ;
  gProcess_0_iop7yt73v = X60Qtmp_0;
  gCur_0_iop7yt73v = eQdupQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(gProcess_0_iop7yt73v);}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_59;
  if (size_8 == 0){
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I7me00i_aow7lb5cq1(size_8);
    void* X60Qx_1432 = alloc_1_sysvq0asl(memSize_1);
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = ((string_0_sysvq0asl*)X60Qx_1432)}
    ;
    if ((!(result_59.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1433 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_59.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_59;}
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
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9){
  NI32 L_0 = (*s_35).len_0;
  NI32 X60Qx_1434 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*s_35));
  if (X60Qx_1434 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_1435 = resize_0_I4buliy_aow7lb5cq1(s_35, 1);
    if ((!X60Qx_1435)){
      nimStrDestroy(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_0] = elem_9;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33){
  NB8 X60Qx_1436;
  if (i_33 < s_38.len_0){
    X60Qx_1436 = (0 <= i_33);}
  else {
    X60Qx_1436 = NIM_FALSE;}
  if ((!X60Qx_1436)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_61;
  result_61 = (&s_38.data_0[i_33]);
  return result_61;}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_60;
  result_60 = s_37.len_0;
  return result_60;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_82;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_82 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_82 = ((NI32)2147483647);}
  return result_82;}
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65){
  NI32 result_85;
  NI32 X60Qx_11;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_1467 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_11 = X60Qx_1467;}
  else {
    X60Qx_11 = 0;}
  result_85 = X60Qx_11;
  return result_85;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
