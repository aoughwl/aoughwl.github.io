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
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct PathGrant_0_iop7yt73v{
  string_0_sysvq0asl prefix_0;
  NI32 caps_0;}
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
typedef struct openArray_0_I824o9o1_iop7yt73v{
  PathGrant_0_iop7yt73v* a_0;
  NI32 len_0;}
openArray_0_I824o9o1_iop7yt73v;
typedef struct seq_0_Iero8tq_iop7yt73v{
  NI32 len_0;
  ReadRecord_0_iop7yt73v* data_0;}
seq_0_Iero8tq_iop7yt73v;
typedef struct openArray_0_I2u6yr01_iop7yt73v{
  ReadRecord_0_iop7yt73v* a_0;
  NI32 len_0;}
openArray_0_I2u6yr01_iop7yt73v;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 len_3_I1rs8q11_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_11);
static inline openArray_0_I824o9o1_iop7yt73v toOpenArray_1_Izchoiu1_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_12);
static inline openArray_0_I2u6yr01_iop7yt73v toOpenArray_1_Ikfcd4n1_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_14);
static inline void add_0_Ijr069w1_iop7yt73v(seq_0_Iero8tq_iop7yt73v* s_16, ReadRecord_0_iop7yt73v elem_3);
static inline NI32 memSizeInBytes_0_Izkmv63_iop7yt73v(NI32 size_6);
static inline PathGrant_0_iop7yt73v* rawData_0_I061llw_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_20);
static inline NI32 len_6_Idr48lb_iop7yt73v(openArray_0_I824o9o1_iop7yt73v a_6);
static inline PathGrant_0_iop7yt73v* getQ_10_Ih11uqp1_iop7yt73v(openArray_0_I824o9o1_iop7yt73v x_5, NI32 idx_2);
static inline NI32 memSizeInBytes_0_I057n0g1_iop7yt73v(NI32 size_7);
static inline ReadRecord_0_iop7yt73v* rawData_0_I7yh2vv1_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_21);
static inline NI32 len_6_Iey6va4_iop7yt73v(openArray_0_I2u6yr01_iop7yt73v a_7);
static inline ReadRecord_0_iop7yt73v* getQ_10_I3tvo3j1_iop7yt73v(openArray_0_I2u6yr01_iop7yt73v x_6, NI32 idx_3);
static inline NI32 capInBytes_0_Ibi6vw11_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_22);
NB8 resize_0_Ipdnn431_iop7yt73v(seq_0_Iero8tq_iop7yt73v* dest_3, NI32 addedElements_3);
void eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(ReadRecord_0_iop7yt73v dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern LongString_0_sysvq0asl const strlit_0_I8446236512461598146_croph25r5;
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11626809062896146847_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I15418518599716865203_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I2723496349315214549_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I11697234225982197076_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I12542130669033277445_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I4718597432102153922_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I9592449470941440445_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13735625106940001307_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I2912131129587157308_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I4050815769175754417_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I13565819874765507459_croph25r5;
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern LongString_0_sysvq0asl const strlit_0_I7383674803287968507_hos1fpv3m1;
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void X60Qini_0_sysvq0asl(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
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
LongString_0_sysvq0asl const strlit_0_I4303973984874128508_iop7yt73v = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getCurrentDir"}
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
LongString_0_sysvq0asl const strlit_0_I17971560687400798064_iop7yt73v = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expandFilename"}
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
LongString_0_sysvq0asl const strlit_0_I900530018976380608_iop7yt73v = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setCurrentDir"}
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
LongString_0_sysvq0asl const strlit_0_I14251590839437571501_iop7yt73v = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tryNextDir"}
;
LongString_0_sysvq0asl const strlit_0_I6105018409752412263_iop7yt73v = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "0123456789abcdef"}
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
LongString_0_sysvq0asl const strlit_0_I3907820794765637452_iop7yt73v = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ". Denied \342\200\224 the call did not reach the host.\012"}
;
seq_0_Iq7pam4_iop7yt73v gPathGrants_0_iop7yt73v;
NB8 gPolicyOn_0_iop7yt73v = NIM_FALSE;
NI32 gGranted_0_iop7yt73v = ((NI32)127);
NI32 gViolations_0_iop7yt73v = 0;
string_0_sysvq0asl gViolNative_0_iop7yt73v = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
NI32 gViolNeeded_0_iop7yt73v = 0;
NB8 gAuditReads_0_iop7yt73v = NIM_FALSE;
seq_0_Iero8tq_iop7yt73v gReads_0_iop7yt73v;
NB8 X60QiniGuard_0_iop7yt73v;
string_0_sysvq0asl capName_0_iop7yt73v(NI32 c_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  string_0_sysvq0asl s_2 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(((NI32)(c_0 & ((NI32)1))) == 0))){
    string_0_sysvq0asl X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NI32 X60Qx_10 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_10){
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
    NI32 X60Qx_11 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_12 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_13 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I10980672052437566323_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_11 + X60Qx_12)) + X60Qx_13)));
    add_2_sysvq0asl((&X60Qdesugar_1), s_2);
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I10980672052437566323_iop7yt73v)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    nimStrDestroy(X60Qx_0);}
  if ((!(((NI32)(c_0 & ((NI32)2))) == 0))){
    string_0_sysvq0asl X60Qx_1;
    nimStrWasMoved((&X60Qx_1));
    NI32 X60Qx_14 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_14){
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
    NI32 X60Qx_15 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_16 = len_4_sysvq0asl(X60Qdesugar_2);
    NI32 X60Qx_17 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I7666624814036398774_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_15 + X60Qx_16)) + X60Qx_17)));
    add_2_sysvq0asl((&X60Qdesugar_3), s_2);
    add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I7666624814036398774_iop7yt73v)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_3;
    nimStrWasMoved((&X60Qdesugar_3));
    nimStrDestroy(X60Qdesugar_3);
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qx_1);}
  if ((!(((NI32)(c_0 & ((NI32)4))) == 0))){
    string_0_sysvq0asl X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    NI32 X60Qx_18 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_18){
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
    NI32 X60Qx_19 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_20 = len_4_sysvq0asl(X60Qdesugar_4);
    NI32 X60Qx_21 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I17118443558071152766_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_19 + X60Qx_20)) + X60Qx_21)));
    add_2_sysvq0asl((&X60Qdesugar_5), s_2);
    add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
    add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
      .bytes_0 = 779314942u, .more_0 = (&strlit_0_I17118443558071152766_iop7yt73v)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_5;
    nimStrWasMoved((&X60Qdesugar_5));
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);
    nimStrDestroy(X60Qx_2);}
  if ((!(((NI32)(c_0 & ((NI32)8))) == 0))){
    string_0_sysvq0asl X60Qx_3;
    nimStrWasMoved((&X60Qx_3));
    NI32 X60Qx_22 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_22){
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
    NI32 X60Qx_23 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_24 = len_4_sysvq0asl(X60Qdesugar_6);
    NI32 X60Qx_25 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_23 + X60Qx_24)) + X60Qx_25)));
    add_2_sysvq0asl((&X60Qdesugar_7), s_2);
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I4406216718368404848_iop7yt73v)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_7;
    nimStrWasMoved((&X60Qdesugar_7));
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qx_3);}
  if ((!(((NI32)(c_0 & ((NI32)16))) == 0))){
    string_0_sysvq0asl X60Qx_4;
    nimStrWasMoved((&X60Qx_4));
    NI32 X60Qx_26 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_26){
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
    NI32 X60Qx_27 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_28 = len_4_sysvq0asl(X60Qdesugar_8);
    NI32 X60Qx_29 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_27 + X60Qx_28)) + X60Qx_29)));
    add_2_sysvq0asl((&X60Qdesugar_9), s_2);
    add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_8);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1986946307u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_9;
    nimStrWasMoved((&X60Qdesugar_9));
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qx_4);}
  if ((!(((NI32)(c_0 & ((NI32)32))) == 0))){
    string_0_sysvq0asl X60Qx_5;
    nimStrWasMoved((&X60Qx_5));
    NI32 X60Qx_30 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_30){
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
    NI32 X60Qx_31 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_32 = len_4_sysvq0asl(X60Qdesugar_10);
    NI32 X60Qx_33 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1952804355u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_31 + X60Qx_32)) + X60Qx_33)));
    add_2_sysvq0asl((&X60Qdesugar_11), s_2);
    add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
    add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
      .bytes_0 = 1952804355u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_11;
    nimStrWasMoved((&X60Qdesugar_11));
    nimStrDestroy(X60Qdesugar_11);
    nimStrDestroy(X60Qdesugar_10);
    nimStrDestroy(X60Qx_5);}
  if ((!(((NI32)(c_0 & ((NI32)64))) == 0))){
    string_0_sysvq0asl X60Qx_6;
    nimStrWasMoved((&X60Qx_6));
    NI32 X60Qx_34 = len_4_sysvq0asl(s_2);
    if (0 < X60Qx_34){
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
    NI32 X60Qx_35 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_36 = len_4_sysvq0asl(X60Qdesugar_12);
    NI32 X60Qx_37 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1768318467u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_35 + X60Qx_36)) + X60Qx_37)));
    add_2_sysvq0asl((&X60Qdesugar_13), s_2);
    add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
    add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
      .bytes_0 = 1768318467u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_13;
    nimStrWasMoved((&X60Qdesugar_13));
    nimStrDestroy(X60Qdesugar_13);
    nimStrDestroy(X60Qdesugar_12);
    nimStrDestroy(X60Qx_6);}
  string_0_sysvq0asl X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  NI32 X60Qx_38 = len_4_sysvq0asl(s_2);
  if (X60Qx_38 == 0){
    nimStrDestroy(X60Qx_7);
    X60Qx_7 = (string_0_sysvq0asl){
      .bytes_0 = 1852796670u, .more_0 = (&strlit_0_I8446236512461598146_croph25r5)}
    ;}
  else {
    nimStrDestroy(X60Qx_7);
    X60Qx_7 = s_2;
    nimStrWasMoved((&s_2));}
  nimStrDestroy(result_0);
  result_0 = X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  nimStrDestroy(X60Qx_7);
  nimStrDestroy(s_2);
  return result_0;
  nimStrDestroy(X60Qx_7);
  nimStrDestroy(s_2);
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
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4303973984874128508_iop7yt73v)}
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
            .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I17971560687400798064_iop7yt73v)}
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
            .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_comaa5xpt1)}
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
            .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I900530018976380608_iop7yt73v)}
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
            .bytes_0 = 2037544190u, .more_0 = (&strlit_0_I14251590839437571501_iop7yt73v)}
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
NB8 hasPrefix_0_iop7yt73v(string_0_sysvq0asl s_0, string_0_sysvq0asl p_0){
  NB8 result_3;
  NB8 X60Qx_41;
  NI32 X60Qx_42 = len_4_sysvq0asl(p_0);
  if (X60Qx_42 == 0){
    X60Qx_41 = NIM_TRUE;}
  else {
    NI32 X60Qx_43 = len_4_sysvq0asl(s_0);
    NI32 X60Qx_44 = len_4_sysvq0asl(p_0);
    X60Qx_41 = (X60Qx_43 < X60Qx_44);}
  if (X60Qx_41){
    return NIM_FALSE;}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_45 = len_4_sysvq0asl(p_0);
      if (i_0 < X60Qx_45){
        NC8 X60Qx_46 = getQ_9_sysvq0asl(s_0, i_0);
        NC8 X60Qx_47 = getQ_9_sysvq0asl(p_0, i_0);
        if ((!(X60Qx_46 == X60Qx_47))){
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_3 = NIM_TRUE;
  return result_3;}
NB8 policyOn_0_iop7yt73v(void){
  NB8 result_4;
  result_4 = gPolicyOn_0_iop7yt73v;
  return result_4;}
NB8 capsDeniedOn_0_iop7yt73v(NI32 need_0, string_0_sysvq0asl path_0){
  NB8 result_7;
  if ((!gPolicyOn_0_iop7yt73v)){
    return NIM_FALSE;}
  if (need_0 == 0){
    return NIM_FALSE;}
  if (((NI32)(need_0 & gGranted_0_iop7yt73v)) == need_0){
    return NIM_FALSE;}
  NI32 X60Qx_50 = len_4_sysvq0asl(path_0);
  if (0 < X60Qx_50){
    {
      openArray_0_I824o9o1_iop7yt73v X60Qlf_0 = toOpenArray_1_Izchoiu1_iop7yt73v(gPathGrants_0_iop7yt73v);
      NI32 X60Qlf_1 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_51 = len_6_Idr48lb_iop7yt73v(X60Qlf_0);
          if (X60Qlf_1 < X60Qx_51){
            {
              PathGrant_0_iop7yt73v* X60Qii_2 = getQ_10_Ih11uqp1_iop7yt73v(X60Qlf_0, X60Qlf_1);
              NB8 X60Qx_52;
              if (((NI32)((*X60Qii_2).caps_0 & need_0)) == need_0){
                NB8 X60Qx_53 = hasPrefix_0_iop7yt73v(path_0, (*X60Qii_2).prefix_0);
                X60Qx_52 = X60Qx_53;}
              else {
                X60Qx_52 = NIM_FALSE;}
              if (X60Qx_52){
                return NIM_FALSE;}}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  result_7 = NIM_TRUE;
  return result_7;}
NB8 policyDeniesPath_0_iop7yt73v(string_0_sysvq0asl name_2, string_0_sysvq0asl path_1, NI32* needed_1){
  NB8 result_8;
  NI32 X60Qx_54 = capsNeeded_0_iop7yt73v(name_2);
  (*needed_1) = X60Qx_54;
  NB8 X60Qx_55 = capsDeniedOn_0_iop7yt73v((*needed_1), path_1);
  result_8 = X60Qx_55;
  return result_8;}
NB8 readAuditOn_0_iop7yt73v(void){
  NB8 result_9;
  result_9 = gAuditReads_0_iop7yt73v;
  return result_9;}
NU64 fnv1a_0_iop7yt73v(string_0_sysvq0asl s_1){
  NU64 result_10;
  result_10 = ((NU64)14695981039346656037ull);
  NI32 i_1 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_56 = len_4_sysvq0asl(s_1);
      if (i_1 < X60Qx_56){
        NC8 X60Qx_57 = getQ_9_sysvq0asl(s_1, i_1);
        result_10 = ((NU64)(result_10 ^ ((NU64)((NU8)X60Qx_57))));
        result_10 = ((NU64)(result_10 * ((NU64)1099511628211ull)));
        inc_1_I6wjjge_aow2h993l1((&i_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_10;}
void recordRead_0_iop7yt73v(string_0_sysvq0asl path_2, string_0_sysvq0asl content_0){
  if ((!gAuditReads_0_iop7yt73v)){
    return;}
  NU64 h_0 = fnv1a_0_iop7yt73v(content_0);
  {
    openArray_0_I2u6yr01_iop7yt73v X60Qlf_2 = toOpenArray_1_Ikfcd4n1_iop7yt73v(gReads_0_iop7yt73v);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_58 = len_6_Iey6va4_iop7yt73v(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_58){
          {
            ReadRecord_0_iop7yt73v* X60Qii_2 = getQ_10_I3tvo3j1_iop7yt73v(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_59;
            NB8 X60Qx_60;
            if ((*X60Qii_2).hashed_0){
              NB8 X60Qx_61 = eqQ_20_sysvq0asl((*X60Qii_2).path_0, path_2);
              X60Qx_60 = X60Qx_61;}
            else {
              X60Qx_60 = NIM_FALSE;}
            if (X60Qx_60){
              X60Qx_59 = ((*X60Qii_2).hash_0 == h_0);}
            else {
              X60Qx_59 = NIM_FALSE;}
            if (X60Qx_59){
              return;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_62 = nimStrDup(path_2);
  NI32 X60Qx_63 = len_4_sysvq0asl(content_0);
  add_0_Ijr069w1_iop7yt73v((&gReads_0_iop7yt73v), (ReadRecord_0_iop7yt73v){
    .path_0 = X60Qx_62, .hash_0 = h_0, .size_0 = X60Qx_63, .hashed_0 = NIM_TRUE}
  );}
void recordOpen_0_iop7yt73v(string_0_sysvq0asl path_3){
  if ((!gAuditReads_0_iop7yt73v)){
    return;}
  {
    openArray_0_I2u6yr01_iop7yt73v X60Qlf_4 = toOpenArray_1_Ikfcd4n1_iop7yt73v(gReads_0_iop7yt73v);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_64 = len_6_Iey6va4_iop7yt73v(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_64){
          {
            ReadRecord_0_iop7yt73v* X60Qii_2 = getQ_10_I3tvo3j1_iop7yt73v(X60Qlf_4, X60Qlf_5);
            NB8 X60Qx_65;
            if ((!(*X60Qii_2).hashed_0)){
              NB8 X60Qx_66 = eqQ_20_sysvq0asl((*X60Qii_2).path_0, path_3);
              X60Qx_65 = X60Qx_66;}
            else {
              X60Qx_65 = NIM_FALSE;}
            if (X60Qx_65){
              return;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_67 = nimStrDup(path_3);
  add_0_Ijr069w1_iop7yt73v((&gReads_0_iop7yt73v), (ReadRecord_0_iop7yt73v){
    .path_0 = X60Qx_67, .hash_0 = ((NU64)0u), .size_0 = 0, .hashed_0 = NIM_FALSE}
  );}
void recordViolation_0_iop7yt73v(string_0_sysvq0asl name_3, NI32 needed_2){
  inc_1_I6wjjge_aow2h993l1((&gViolations_0_iop7yt73v));
  if (gViolations_0_iop7yt73v == 1){
    nimStrDestroy(gViolNative_0_iop7yt73v);
    string_0_sysvq0asl X60Qx_83 = nimStrDup(name_3);
    gViolNative_0_iop7yt73v = X60Qx_83;
    gViolNeeded_0_iop7yt73v = needed_2;}}
string_0_sysvq0asl policyMessage_0_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3, string_0_sysvq0asl path_4){
  string_0_sysvq0asl result_17;
  nimStrWasMoved((&result_17));
  string_0_sysvq0asl X60Qdesugar_20 = capName_0_iop7yt73v(needed_3);
  NI32 X60Qx_85 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17663818852377669490_iop7yt73v)}
  );
  NI32 X60Qx_86 = len_4_sysvq0asl(name_4);
  NI32 X60Qx_87 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I16137639778510327014_iop7yt73v)}
  );
  NI32 X60Qx_88 = len_4_sysvq0asl(X60Qdesugar_20);
  string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_85 + X60Qx_86)) + X60Qx_87)) + X60Qx_88)));
  add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17663818852377669490_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_21), name_4);
  add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
    .bytes_0 = 1847601150u, .more_0 = (&strlit_0_I16137639778510327014_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_21), X60Qdesugar_20);
  nimStrDestroy(result_17);
  result_17 = X60Qdesugar_21;
  nimStrWasMoved((&X60Qdesugar_21));
  NI32 X60Qx_89 = len_4_sysvq0asl(path_4);
  if (0 < X60Qx_89){
    NI32 X60Qx_90 = len_4_sysvq0asl(result_17);
    NI32 X60Qx_91 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
    );
    NI32 X60Qx_92 = len_4_sysvq0asl(path_4);
    NI32 X60Qx_93 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_22 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_90 + X60Qx_91)) + X60Qx_92)) + X60Qx_93)));
    add_2_sysvq0asl((&X60Qdesugar_22), result_17);
    add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_22), path_4);
    add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(result_17);
    result_17 = X60Qdesugar_22;
    nimStrWasMoved((&X60Qdesugar_22));
    nimStrDestroy(X60Qdesugar_22);}
  string_0_sysvq0asl X60Qdesugar_23 = capName_0_iop7yt73v(gGranted_0_iop7yt73v);
  NI32 X60Qx_94 = len_4_sysvq0asl(result_17);
  NI32 X60Qx_95 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1948269566u, .more_0 = (&strlit_0_I16651577260944187724_iop7yt73v)}
  );
  NI32 X60Qx_96 = len_4_sysvq0asl(X60Qdesugar_23);
  string_0_sysvq0asl X60Qdesugar_24 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_94 + X60Qx_95)) + X60Qx_96)));
  add_2_sysvq0asl((&X60Qdesugar_24), result_17);
  add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
    .bytes_0 = 1948269566u, .more_0 = (&strlit_0_I16651577260944187724_iop7yt73v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_24), X60Qdesugar_23);
  nimStrDestroy(result_17);
  result_17 = X60Qdesugar_24;
  nimStrWasMoved((&X60Qdesugar_24));
  if (0 < gPathGrants_0_iop7yt73v.len_0){
    NI32 X60Qx_97 = len_3_I1rs8q11_iop7yt73v(gPathGrants_0_iop7yt73v);
    string_0_sysvq0asl X60Qdesugar_25 = dollarQ_2_sysvq0asl(X60Qx_97);
    NI32 X60Qx_98 = len_4_sysvq0asl(result_17);
    NI32 X60Qx_99 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1819287806u, .more_0 = (&strlit_0_I3188702685911042556_iop7yt73v)}
    );
    NI32 X60Qx_100 = len_4_sysvq0asl(X60Qdesugar_25);
    NI32 X60Qx_101 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1634738430u, .more_0 = (&strlit_0_I9020742201384713734_iop7yt73v)}
    );
    string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_98 + X60Qx_99)) + X60Qx_100)) + X60Qx_101)));
    add_2_sysvq0asl((&X60Qdesugar_26), result_17);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 1819287806u, .more_0 = (&strlit_0_I3188702685911042556_iop7yt73v)}
    );
    add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_25);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 1634738430u, .more_0 = (&strlit_0_I9020742201384713734_iop7yt73v)}
    );
    nimStrDestroy(result_17);
    result_17 = X60Qdesugar_26;
    nimStrWasMoved((&X60Qdesugar_26));
    nimStrDestroy(X60Qdesugar_26);
    nimStrDestroy(X60Qdesugar_25);}
  string_0_sysvq0asl X60Qlhs_1 = ampQ_0_sysvq0asl(result_17, (string_0_sysvq0asl){
    .bytes_0 = 1142959870u, .more_0 = (&strlit_0_I3907820794765637452_iop7yt73v)}
  );
  nimStrDestroy(result_17);
  result_17 = X60Qlhs_1;
  nimStrDestroy(X60Qdesugar_24);
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_21);
  nimStrDestroy(X60Qdesugar_20);
  return result_17;
  nimStrDestroy(X60Qdesugar_24);
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_21);
  nimStrDestroy(X60Qdesugar_20);
  return result_17;}
static inline seq_0_Iq7pam4_iop7yt73v newSeqUninit_0_I8eutte_iop7yt73v(NI32 size_2){
  seq_0_Iq7pam4_iop7yt73v result_18;
  if (size_2 == 0){
    result_18 = (seq_0_Iq7pam4_iop7yt73v){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Izkmv63_iop7yt73v(size_2);
    void* X60Qx_102 = alloc_1_sysvq0asl(memSize_0);
    result_18 = (seq_0_Iq7pam4_iop7yt73v){
      .len_0 = size_2, .data_0 = ((PathGrant_0_iop7yt73v*)X60Qx_102)}
    ;
    if ((!(result_18.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_103 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_18.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_18;}
static inline NI32 len_3_I1rs8q11_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_11){
  NI32 result_19;
  result_19 = s_11.len_0;
  return result_19;}
static inline openArray_0_I824o9o1_iop7yt73v toOpenArray_1_Izchoiu1_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_12){
  openArray_0_I824o9o1_iop7yt73v result_20;
  PathGrant_0_iop7yt73v* X60Qx_106 = rawData_0_I061llw_iop7yt73v(s_12);
  result_20 = (openArray_0_I824o9o1_iop7yt73v){
    .a_0 = X60Qx_106, .len_0 = s_12.len_0}
  ;
  return result_20;}
static inline seq_0_Iero8tq_iop7yt73v newSeqUninit_0_Inl2vj4_iop7yt73v(NI32 size_4){
  seq_0_Iero8tq_iop7yt73v result_21;
  if (size_4 == 0){
    result_21 = (seq_0_Iero8tq_iop7yt73v){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I057n0g1_iop7yt73v(size_4);
    void* X60Qx_107 = alloc_1_sysvq0asl(memSize_1);
    result_21 = (seq_0_Iero8tq_iop7yt73v){
      .len_0 = size_4, .data_0 = ((ReadRecord_0_iop7yt73v*)X60Qx_107)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_108 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_21;}
static inline openArray_0_I2u6yr01_iop7yt73v toOpenArray_1_Ikfcd4n1_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_14){
  openArray_0_I2u6yr01_iop7yt73v result_22;
  ReadRecord_0_iop7yt73v* X60Qx_109 = rawData_0_I7yh2vv1_iop7yt73v(s_14);
  result_22 = (openArray_0_I2u6yr01_iop7yt73v){
    .a_0 = X60Qx_109, .len_0 = s_14.len_0}
  ;
  return result_22;}
static inline void add_0_Ijr069w1_iop7yt73v(seq_0_Iero8tq_iop7yt73v* s_16, ReadRecord_0_iop7yt73v elem_3){
  NI32 L_1 = (*s_16).len_0;
  NI32 X60Qx_110 = capInBytes_0_Ibi6vw11_iop7yt73v((*s_16));
  if (X60Qx_110 < ((NI32)(((NI32)(L_1 * sizeof(ReadRecord_0_iop7yt73v))) + sizeof(ReadRecord_0_iop7yt73v)))){
    NB8 X60Qx_111 = resize_0_Ipdnn431_iop7yt73v(s_16, 1);
    if ((!X60Qx_111)){
      eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_16).len_0));
  (*s_16).data_0[L_1] = elem_3;}
static inline NI32 memSizeInBytes_0_Izkmv63_iop7yt73v(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_24;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(PathGrant_0_iop7yt73v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_24 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_24 = ((NI32)2147483647);}
  return result_24;}
static inline PathGrant_0_iop7yt73v* rawData_0_I061llw_iop7yt73v(seq_0_Iq7pam4_iop7yt73v s_20){
  PathGrant_0_iop7yt73v* result_27;
  result_27 = s_20.data_0;
  return result_27;}
static inline NI32 len_6_Idr48lb_iop7yt73v(openArray_0_I824o9o1_iop7yt73v a_6){
  NI32 result_28;
  result_28 = a_6.len_0;
  return result_28;}
static inline PathGrant_0_iop7yt73v* getQ_10_Ih11uqp1_iop7yt73v(openArray_0_I824o9o1_iop7yt73v x_5, NI32 idx_2){
  NB8 X60Qx_115;
  if (0 <= idx_2){
    X60Qx_115 = (idx_2 < x_5.len_0);}
  else {
    X60Qx_115 = NIM_FALSE;}
  if ((!X60Qx_115)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  PathGrant_0_iop7yt73v* result_29;
  result_29 = (&x_5.a_0[idx_2]);
  return result_29;}
static inline NI32 memSizeInBytes_0_I057n0g1_iop7yt73v(NI32 size_7){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_30;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_7, sizeof(ReadRecord_0_iop7yt73v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_30 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_30 = ((NI32)2147483647);}
  return result_30;}
static inline ReadRecord_0_iop7yt73v* rawData_0_I7yh2vv1_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_21){
  ReadRecord_0_iop7yt73v* result_31;
  result_31 = s_21.data_0;
  return result_31;}
static inline NI32 len_6_Iey6va4_iop7yt73v(openArray_0_I2u6yr01_iop7yt73v a_7){
  NI32 result_32;
  result_32 = a_7.len_0;
  return result_32;}
static inline ReadRecord_0_iop7yt73v* getQ_10_I3tvo3j1_iop7yt73v(openArray_0_I2u6yr01_iop7yt73v x_6, NI32 idx_3){
  NB8 X60Qx_116;
  if (0 <= idx_3){
    X60Qx_116 = (idx_3 < x_6.len_0);}
  else {
    X60Qx_116 = NIM_FALSE;}
  if ((!X60Qx_116)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  ReadRecord_0_iop7yt73v* result_33;
  result_33 = (&x_6.a_0[idx_3]);
  return result_33;}
static inline NI32 capInBytes_0_Ibi6vw11_iop7yt73v(seq_0_Iero8tq_iop7yt73v s_22){
  NI32 result_34;
  NI32 X60Qx_9;
  if ((!(s_22.data_0 == NIM_NIL))){
    NI32 X60Qx_117 = allocatedSize_0_sysvq0asl(((void*)((void*)s_22.data_0)));
    X60Qx_9 = X60Qx_117;}
  else {
    X60Qx_9 = 0;}
  result_34 = X60Qx_9;
  return result_34;}
NB8 resize_0_Ipdnn431_iop7yt73v(seq_0_Iero8tq_iop7yt73v* dest_3, NI32 addedElements_3){
  NB8 result_35;
  NI32 X60Qx_118 = capInBytes_0_Ibi6vw11_iop7yt73v((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_118 / sizeof(ReadRecord_0_iop7yt73v)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_3 = memSizeInBytes_0_I057n0g1_iop7yt73v(newCap_1);
  void* X60Qx_119 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_3);
  (*dest_3).data_0 = ((ReadRecord_0_iop7yt73v*)X60Qx_119);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_3);
    result_35 = NIM_FALSE;}
  else {
    result_35 = NIM_TRUE;}
  return result_35;}
void eQdestroyQ_SX52eadX52ecord0iop7yt73v_0_iop7yt73v(ReadRecord_0_iop7yt73v dest_0){
  nimStrDestroy(dest_0.path_0);}
void X60Qini_0_iop7yt73v(void){
  if (X60QiniGuard_0_iop7yt73v){
    return;}
  X60QiniGuard_0_iop7yt73v = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  gPathGrants_0_iop7yt73v = newSeqUninit_0_I8eutte_iop7yt73v(0);
  gReads_0_iop7yt73v = newSeqUninit_0_Inl2vj4_iop7yt73v(0);}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
