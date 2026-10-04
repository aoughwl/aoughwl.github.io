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
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <poll.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_Iowv1l61_hos9jnsbq1{
  NI32 len_0;
  int* data_0;}
seq_0_Iowv1l61_hos9jnsbq1;
typedef struct X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1{
  NU8 a[128];}
X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1;
typedef struct X60Qt_0_IAarrayAuS8ZS65536_hos9jnsbq1{
  NU8 a[65536];}
X60Qt_0_IAarrayAuS8ZS65536_hos9jnsbq1;
typedef struct X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1{
  struct pollfd a[256];}
X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1;
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
static inline NI32 len_3_I5p4l001_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_8);
static inline int* getQ_7_Itbh6l31_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_9, NI32 i_13);
static inline void add_0_I05nls4_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* s_10, int elem_4);
static inline void putQ_7_I4a1m13_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* s_12, NI32 i_14, int elem_5);
static inline X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 default_23_If5mx7o1_hos9jnsbq1(void);
static inline X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1 default_23_I4zcfwx1_hos9jnsbq1(void);
static inline NI32 memSizeInBytes_0_Ivblwj61_hos9jnsbq1(NI32 size_6);
static inline NI32 capInBytes_0_Iahcimz_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_18);
NB8 resize_0_Iznnnie1_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* dest_2, NI32 addedElements_2);
extern NB8 capsDeniedOn_1_iop7yt73v(NI32 need_1, string_0_sysvq0asl path_1);
extern void recordViolation_1_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_iop7yt73v(void);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I9518793374256204879_hos9jnsbq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "socket(2)"}
;
LongString_0_sysvq0asl const strlit_0_I4857855780691622415_hos9jnsbq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bind(2)"}
;
LongString_0_sysvq0asl const strlit_0_I17360080512707145951_hos9jnsbq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "connect(2)"}
;
LongString_0_sysvq0asl const strlit_0_I12079828352756861660_hos9jnsbq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "listen(2)"}
;
LongString_0_sysvq0asl const strlit_0_I146127019739471779_hos9jnsbq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "accept(2)"}
;
LongString_0_sysvq0asl const strlit_0_I7381915608971509873_hos9jnsbq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setsockopt(2)"}
;
LongString_0_sysvq0asl const strlit_0_I11925656366307075894_hos9jnsbq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "send(2)"}
;
LongString_0_sysvq0asl const strlit_0_I13552952660311706383_hos9jnsbq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "recv(2)"}
;
NI32 gSockErrno_0_hos9jnsbq1 = 0;
seq_0_Iowv1l61_hos9jnsbq1 gSockReal_0_hos9jnsbq1;
X60Qt_0_IAarrayAuS8ZS65536_hos9jnsbq1 gIoBuf_0_hos9jnsbq1;
NB8 X60QiniGuard_0_hos9jnsbq1;
NI32 hostSockErrno_0_hos9jnsbq1(void){
  NI32 result_0;
  result_0 = gSockErrno_0_hos9jnsbq1;
  return result_0;}
void capture_0_hos9jnsbq1(void){
  int* p_0 = __errno_location();
  NI32 X60Qx_0;
  if ((!(p_0 == NIM_NIL))){
    X60Qx_0 = ((NI32)(*p_0));}
  else {
    X60Qx_0 = 0;}
  gSockErrno_0_hos9jnsbq1 = X60Qx_0;}
NB8 denied_0_hos9jnsbq1(string_0_sysvq0asl name_0){
  NB8 result_1;
  NB8 X60Qx_13 = capsDeniedOn_1_iop7yt73v(((NI32)32), (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  if (X60Qx_13){
    recordViolation_1_iop7yt73v(name_0, ((NI32)32));
    gSockErrno_0_hos9jnsbq1 = 1;
    result_1 = NIM_TRUE;}
  else {
    result_1 = NIM_FALSE;}
  return result_1;}
NB8 isSockHandle_0_hos9jnsbq1(NI32 h_0){
  NB8 result_2;
  NB8 X60Qx_14;
  NB8 X60Qx_15;
  if (((NI32)1000000) <= h_0){
    NI32 X60Qx_16 = len_3_I5p4l001_hos9jnsbq1(gSockReal_0_hos9jnsbq1);
    X60Qx_15 = (((NI32)(h_0 - ((NI32)1000000))) < X60Qx_16);}
  else {
    X60Qx_15 = NIM_FALSE;}
  if (X60Qx_15){
    int* X60Qx_17 = getQ_7_Itbh6l31_hos9jnsbq1(gSockReal_0_hos9jnsbq1, ((NI32)(h_0 - ((NI32)1000000))));
    X60Qx_14 = (((int)0) <= (*X60Qx_17));}
  else {
    X60Qx_14 = NIM_FALSE;}
  result_2 = X60Qx_14;
  return result_2;}
int realOf_0_hos9jnsbq1(NI32 h_1){
  int result_3;
  int X60Qx_1;
  NB8 X60Qx_18 = isSockHandle_0_hos9jnsbq1(h_1);
  if (X60Qx_18){
    int* X60Qx_19 = getQ_7_Itbh6l31_hos9jnsbq1(gSockReal_0_hos9jnsbq1, ((NI32)(h_1 - ((NI32)1000000))));
    X60Qx_1 = (*X60Qx_19);}
  else {
    X60Qx_1 = ((int)-1);}
  result_3 = X60Qx_1;
  return result_3;}
NI32 publish_0_hos9jnsbq1(int fd_14){
  NI32 result_4;
  add_0_I05nls4_hos9jnsbq1((&gSockReal_0_hos9jnsbq1), fd_14);
  NI32 X60Qx_20 = len_3_I5p4l001_hos9jnsbq1(gSockReal_0_hos9jnsbq1);
  result_4 = ((NI32)(((NI32)(((NI32)1000000) + X60Qx_20)) - 1));
  return result_4;}
NI32 hostSocket_0_hos9jnsbq1(NI32 domain_1, NI32 typ_1, NI32 protocol_1){
  NI32 result_5;
  NB8 X60Qx_21 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1668248574u, .more_0 = (&strlit_0_I9518793374256204879_hos9jnsbq1)}
  );
  if (X60Qx_21){
    return -1;}
  int fd_16 = socket(((int)domain_1), ((int)typ_1), ((int)protocol_1));
  capture_0_hos9jnsbq1();
  NI64 X60Qx_2;
  if (fd_16 < ((int)0)){
    X60Qx_2 = -1;}
  else {
    NI32 X60Qx_22 = publish_0_hos9jnsbq1(fd_16);
    X60Qx_2 = X60Qx_22;}
  result_5 = X60Qx_2;
  return result_5;}
NI32 hostSockClose_0_hos9jnsbq1(NI32 h_2){
  NI32 result_6;
  int fd_17 = realOf_0_hos9jnsbq1(h_2);
  if (fd_17 < ((int)0)){
    return -1;}
  int rc_0 = close(fd_17);
  capture_0_hos9jnsbq1();
  putQ_7_I4a1m13_hos9jnsbq1((&gSockReal_0_hos9jnsbq1), ((NI32)(h_2 - ((NI32)1000000))), ((int)-1));
  result_6 = ((NI32)rc_0);
  return result_6;}
NI32 hostBind_0_hos9jnsbq1(NI32 h_3, string_0_sysvq0asl sa_5){
  NI32 result_7;
  NB8 X60Qx_23 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I4857855780691622415_hos9jnsbq1)}
  );
  if (X60Qx_23){
    return -1;}
  int fd_18 = realOf_0_hos9jnsbq1(h_3);
  NB8 X60Qx_24;
  if (fd_18 < ((int)0)){
    X60Qx_24 = NIM_TRUE;}
  else {
    NI32 X60Qx_25 = len_4_sysvq0asl(sa_5);
    X60Qx_24 = (X60Qx_25 == 0);}
  if (X60Qx_24){
    return -1;}
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_2 = default_23_If5mx7o1_hos9jnsbq1();
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_26;
      NI32 X60Qx_27 = len_4_sysvq0asl(sa_5);
      if (i_2 < X60Qx_27){
        X60Qx_26 = (i_2 < 128);}
      else {
        X60Qx_26 = NIM_FALSE;}
      if (X60Qx_26){
        NI32 X60Qx_28 = nimIcheckB(i_2, 127);
        NC8 X60Qx_29 = getQ_9_sysvq0asl(sa_5, i_2);
        buf_2.a[X60Qx_28] = ((NU8)((NU8)X60Qx_29));
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_30 = nimIcheckB(0, 127);
  NI32 X60Qx_31 = len_4_sysvq0asl(sa_5);
  int rc_1 = bind(fd_18, ((void*)(&buf_2.a[X60Qx_30])), ((unsigned int)X60Qx_31));
  capture_0_hos9jnsbq1();
  result_7 = ((NI32)rc_1);
  return result_7;}
NI32 hostConnect_0_hos9jnsbq1(NI32 h_4, string_0_sysvq0asl sa_6){
  NI32 result_8;
  NB8 X60Qx_32 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I17360080512707145951_hos9jnsbq1)}
  );
  if (X60Qx_32){
    return -1;}
  int fd_19 = realOf_0_hos9jnsbq1(h_4);
  NB8 X60Qx_33;
  if (fd_19 < ((int)0)){
    X60Qx_33 = NIM_TRUE;}
  else {
    NI32 X60Qx_34 = len_4_sysvq0asl(sa_6);
    X60Qx_33 = (X60Qx_34 == 0);}
  if (X60Qx_33){
    return -1;}
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_3 = default_23_If5mx7o1_hos9jnsbq1();
  NI32 i_3 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_35;
      NI32 X60Qx_36 = len_4_sysvq0asl(sa_6);
      if (i_3 < X60Qx_36){
        X60Qx_35 = (i_3 < 128);}
      else {
        X60Qx_35 = NIM_FALSE;}
      if (X60Qx_35){
        NI32 X60Qx_37 = nimIcheckB(i_3, 127);
        NC8 X60Qx_38 = getQ_9_sysvq0asl(sa_6, i_3);
        buf_3.a[X60Qx_37] = ((NU8)((NU8)X60Qx_38));
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_39 = nimIcheckB(0, 127);
  NI32 X60Qx_40 = len_4_sysvq0asl(sa_6);
  int rc_2 = connect(fd_19, ((void*)(&buf_3.a[X60Qx_39])), ((unsigned int)X60Qx_40));
  capture_0_hos9jnsbq1();
  result_8 = ((NI32)rc_2);
  return result_8;}
NI32 hostListen_0_hos9jnsbq1(NI32 h_5, NI32 backlog_1){
  NI32 result_9;
  NB8 X60Qx_41 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1936289022u, .more_0 = (&strlit_0_I12079828352756861660_hos9jnsbq1)}
  );
  if (X60Qx_41){
    return -1;}
  int fd_20 = realOf_0_hos9jnsbq1(h_5);
  if (fd_20 < ((int)0)){
    return -1;}
  int rc_3 = listen(fd_20, ((int)backlog_1));
  capture_0_hos9jnsbq1();
  result_9 = ((NI32)rc_3);
  return result_9;}
NI32 hostAccept_0_hos9jnsbq1(NI32 h_6, string_0_sysvq0asl* peer_0){
  NI32 result_10;
  NB8 X60Qx_42 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1667457534u, .more_0 = (&strlit_0_I146127019739471779_hos9jnsbq1)}
  );
  if (X60Qx_42){
    return -1;}
  int fd_21 = realOf_0_hos9jnsbq1(h_6);
  nimStrDestroy((*peer_0));
  (*peer_0) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (fd_21 < ((int)0)){
    return -1;}
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_4 = default_23_If5mx7o1_hos9jnsbq1();
  unsigned int slen_5 = ((unsigned int)128);
  NI32 X60Qx_43 = nimIcheckB(0, 127);
  int nfd_0 = accept(fd_21, ((void*)(&buf_4.a[X60Qx_43])), (&slen_5));
  capture_0_hos9jnsbq1();
  if (nfd_0 < ((int)0)){
    return -1;}
  NI32 i_4 = 0;
  NI32 X60Qx_3;
  if (((NI32)slen_5) < 128){
    X60Qx_3 = ((NI32)slen_5);}
  else {
    X60Qx_3 = 128;}
  NI32 n_2 = X60Qx_3;
  {
    while (i_4 < n_2){
      NI32 X60Qx_44 = nimIcheckB(i_4, 127);
      add_1_sysvq0asl(peer_0, ((NC8)buf_4.a[X60Qx_44]));
      inc_1_I6wjjge_aow2h993l1((&i_4));}}
  whileStmtLabel_0: ;
  NI32 X60Qx_45 = publish_0_hos9jnsbq1(nfd_0);
  result_10 = X60Qx_45;
  return result_10;}
NI32 sockNameInto_0_hos9jnsbq1(int fd_15, NB8 peerSide_0, string_0_sysvq0asl* sa_7){
  NI32 result_11;
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_5 = default_23_If5mx7o1_hos9jnsbq1();
  unsigned int slen_6 = ((unsigned int)128);
  int X60Qx_4;
  if (peerSide_0){
    NI32 X60Qx_46 = nimIcheckB(0, 127);
    int X60Qx_47 = getpeername(fd_15, ((void*)(&buf_5.a[X60Qx_46])), (&slen_6));
    X60Qx_4 = X60Qx_47;}
  else {
    NI32 X60Qx_48 = nimIcheckB(0, 127);
    int X60Qx_49 = getsockname(fd_15, ((void*)(&buf_5.a[X60Qx_48])), (&slen_6));
    X60Qx_4 = X60Qx_49;}
  int rc_4 = X60Qx_4;
  capture_0_hos9jnsbq1();
  nimStrDestroy((*sa_7));
  (*sa_7) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (rc_4 < ((int)0)){
    return -1;}
  NI32 i_5 = 0;
  NI32 X60Qx_5;
  if (((NI32)slen_6) < 128){
    X60Qx_5 = ((NI32)slen_6);}
  else {
    X60Qx_5 = 128;}
  NI32 n_3 = X60Qx_5;
  {
    while (i_5 < n_3){
      NI32 X60Qx_50 = nimIcheckB(i_5, 127);
      add_1_sysvq0asl(sa_7, ((NC8)buf_5.a[X60Qx_50]));
      inc_1_I6wjjge_aow2h993l1((&i_5));}}
  whileStmtLabel_0: ;
  result_11 = 0;
  return result_11;}
NI32 hostGetsockname_0_hos9jnsbq1(NI32 h_7, string_0_sysvq0asl* sa_8){
  NI32 result_12;
  int fd_22 = realOf_0_hos9jnsbq1(h_7);
  nimStrDestroy((*sa_8));
  (*sa_8) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (fd_22 < ((int)0)){
    return -1;}
  NI32 X60Qx_51 = sockNameInto_0_hos9jnsbq1(fd_22, NIM_FALSE, sa_8);
  result_12 = X60Qx_51;
  return result_12;}
NI32 hostGetpeername_0_hos9jnsbq1(NI32 h_8, string_0_sysvq0asl* sa_9){
  NI32 result_13;
  int fd_23 = realOf_0_hos9jnsbq1(h_8);
  nimStrDestroy((*sa_9));
  (*sa_9) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (fd_23 < ((int)0)){
    return -1;}
  NI32 X60Qx_52 = sockNameInto_0_hos9jnsbq1(fd_23, NIM_TRUE, sa_9);
  result_13 = X60Qx_52;
  return result_13;}
NI32 hostSetsockopt_0_hos9jnsbq1(NI32 h_9, NI32 level_2, NI32 opt_2, string_0_sysvq0asl val_2){
  NI32 result_14;
  NB8 X60Qx_53 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I7381915608971509873_hos9jnsbq1)}
  );
  if (X60Qx_53){
    return -1;}
  int fd_24 = realOf_0_hos9jnsbq1(h_9);
  if (fd_24 < ((int)0)){
    return -1;}
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_6 = default_23_If5mx7o1_hos9jnsbq1();
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_54;
      NI32 X60Qx_55 = len_4_sysvq0asl(val_2);
      if (i_6 < X60Qx_55){
        X60Qx_54 = (i_6 < 128);}
      else {
        X60Qx_54 = NIM_FALSE;}
      if (X60Qx_54){
        NI32 X60Qx_56 = nimIcheckB(i_6, 127);
        NC8 X60Qx_57 = getQ_9_sysvq0asl(val_2, i_6);
        buf_6.a[X60Qx_56] = ((NU8)((NU8)X60Qx_57));
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_58 = nimIcheckB(0, 127);
  NI32 X60Qx_59 = len_4_sysvq0asl(val_2);
  int rc_5 = setsockopt(fd_24, ((int)level_2), ((int)opt_2), ((void*)(&buf_6.a[X60Qx_58])), ((unsigned int)X60Qx_59));
  capture_0_hos9jnsbq1();
  result_14 = ((NI32)rc_5);
  return result_14;}
NI32 hostGetsockopt_0_hos9jnsbq1(NI32 h_10, NI32 level_3, NI32 opt_3, NI32 want_0, string_0_sysvq0asl* val_3){
  NI32 result_15;
  int fd_25 = realOf_0_hos9jnsbq1(h_10);
  nimStrDestroy((*val_3));
  (*val_3) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (fd_25 < ((int)0)){
    return -1;}
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 buf_7 = default_23_If5mx7o1_hos9jnsbq1();
  NI32 X60Qx_6;
  if (want_0 < 128){
    X60Qx_6 = want_0;}
  else {
    X60Qx_6 = 128;}
  unsigned int slen_7 = ((unsigned int)X60Qx_6);
  NI32 X60Qx_60 = nimIcheckB(0, 127);
  int rc_6 = getsockopt(fd_25, ((int)level_3), ((int)opt_3), ((void*)(&buf_7.a[X60Qx_60])), (&slen_7));
  capture_0_hos9jnsbq1();
  if (rc_6 < ((int)0)){
    return -1;}
  NI32 i_7 = 0;
  NI32 X60Qx_7;
  if (((NI32)slen_7) < 128){
    X60Qx_7 = ((NI32)slen_7);}
  else {
    X60Qx_7 = 128;}
  NI32 n_4 = X60Qx_7;
  {
    while (i_7 < n_4){
      NI32 X60Qx_61 = nimIcheckB(i_7, 127);
      add_1_sysvq0asl(val_3, ((NC8)buf_7.a[X60Qx_61]));
      inc_1_I6wjjge_aow2h993l1((&i_7));}}
  whileStmtLabel_0: ;
  result_15 = 0;
  return result_15;}
NI32 hostSend_0_hos9jnsbq1(NI32 h_11, string_0_sysvq0asl data_0, NI32 flags_2){
  NI32 result_16;
  NB8 X60Qx_62 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1852142590u, .more_0 = (&strlit_0_I11925656366307075894_hos9jnsbq1)}
  );
  if (X60Qx_62){
    return -1;}
  int fd_26 = realOf_0_hos9jnsbq1(h_11);
  if (fd_26 < ((int)0)){
    return -1;}
  NI32 n_5 = len_4_sysvq0asl(data_0);
  if (65536 < n_5){
    n_5 = 65536;}
  if (n_5 == 0){
    gSockErrno_0_hos9jnsbq1 = 0;
    return 0;}
  NI32 i_8 = 0;
  {
    while (i_8 < n_5){
      NI32 X60Qx_63 = nimIcheckB(i_8, 65535);
      NC8 X60Qx_64 = getQ_9_sysvq0asl(data_0, i_8);
      gIoBuf_0_hos9jnsbq1.a[X60Qx_63] = ((NU8)((NU8)X60Qx_64));
      inc_1_I6wjjge_aow2h993l1((&i_8));}}
  whileStmtLabel_0: ;
  NI32 X60Qx_65 = nimIcheckB(0, 65535);
  NI32 rc_7 = send(fd_26, ((void*)(&gIoBuf_0_hos9jnsbq1.a[X60Qx_65])), ((size_t)n_5), ((int)flags_2));
  capture_0_hos9jnsbq1();
  result_16 = rc_7;
  return result_16;}
NI32 hostRecv_0_hos9jnsbq1(NI32 h_12, NI32 want_1, NI32 flags_3, string_0_sysvq0asl* data_1){
  NI32 result_17;
  NB8 X60Qx_66 = denied_0_hos9jnsbq1((string_0_sysvq0asl){
    .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I13552952660311706383_hos9jnsbq1)}
  );
  if (X60Qx_66){
    return -1;}
  int fd_27 = realOf_0_hos9jnsbq1(h_12);
  nimStrDestroy((*data_1));
  (*data_1) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (fd_27 < ((int)0)){
    return -1;}
  NI32 n_6 = want_1;
  if (65536 < n_6){
    n_6 = 65536;}
  if (n_6 <= 0){
    gSockErrno_0_hos9jnsbq1 = 0;
    return 0;}
  NI32 X60Qx_67 = nimIcheckB(0, 65535);
  NI32 rc_8 = recv(fd_27, ((void*)(&gIoBuf_0_hos9jnsbq1.a[X60Qx_67])), ((size_t)n_6), ((int)flags_3));
  capture_0_hos9jnsbq1();
  if (rc_8 <= 0){
    return rc_8;}
  NI32 i_9 = 0;
  {
    while (i_9 < rc_8){
      NI32 X60Qx_68 = nimIcheckB(i_9, 65535);
      add_1_sysvq0asl(data_1, ((NC8)gIoBuf_0_hos9jnsbq1.a[X60Qx_68]));
      inc_1_I6wjjge_aow2h993l1((&i_9));}}
  whileStmtLabel_0: ;
  result_17 = rc_8;
  return result_17;}
NI32 hostShutdown_0_hos9jnsbq1(NI32 h_13, NI32 how_1){
  NI32 result_18;
  int fd_28 = realOf_0_hos9jnsbq1(h_13);
  if (fd_28 < ((int)0)){
    return -1;}
  int rc_9 = shutdown(fd_28, ((int)how_1));
  capture_0_hos9jnsbq1();
  result_18 = ((NI32)rc_9);
  return result_18;}
NI32 hostSockFcntl_0_hos9jnsbq1(NI32 h_14, NI32 cmd_2, NI32 arg_1, NB8 hasArg_0){
  NI32 result_19;
  int fd_29 = realOf_0_hos9jnsbq1(h_14);
  if (fd_29 < ((int)0)){
    return -1;}
  int X60Qx_8;
  if (hasArg_0){
    int X60Qx_69 = fcntl(fd_29, ((int)cmd_2), ((int)arg_1));
    X60Qx_8 = X60Qx_69;}
  else {
    int X60Qx_70 = fcntl(fd_29, ((int)cmd_2));
    X60Qx_8 = X60Qx_70;}
  int rc_10 = X60Qx_8;
  capture_0_hos9jnsbq1();
  result_19 = ((NI32)rc_10);
  return result_19;}
NI32 hostPoll_0_hos9jnsbq1(seq_0_Ift2sne_aow7lb5cq1 handles_0, seq_0_Ift2sne_aow7lb5cq1 events_0, seq_0_Ift2sne_aow7lb5cq1* revents_0, NI32 timeout_1){
  NI32 result_20;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*revents_0));
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_71 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  (*revents_0) = X60Qx_71;
  NI32 n_7 = len_3_I0v1j8d_aow7lb5cq1(handles_0);
  NI32 i_10 = 0;
  {
    while (i_10 < n_7){
      add_0_I8kd4i4_aow7lb5cq1(revents_0, 0);
      inc_1_I6wjjge_aow2h993l1((&i_10));}}
  whileStmtLabel_0: ;
  if (n_7 == 0){
    return 0;}
  if (256 < n_7){
    gSockErrno_0_hos9jnsbq1 = 22;
    return -1;}
  X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1 pfds_0 = default_23_I4zcfwx1_hos9jnsbq1();
  i_10 = 0;
  NI32 live_0 = 0;
  {
    while (i_10 < n_7){
      NI32* X60Qx_72 = getQ_7_Ir8kccm_aow7lb5cq1(handles_0, i_10);
      int fd_30 = realOf_0_hos9jnsbq1((*X60Qx_72));
      NI32 X60Qx_73 = nimIcheckB(i_10, 255);
      pfds_0.a[X60Qx_73].fd = fd_30;
      NI32 X60Qx_9;
      NI32 X60Qx_74 = len_3_I0v1j8d_aow7lb5cq1(events_0);
      if (i_10 < X60Qx_74){
        NI32* X60Qx_75 = getQ_7_Ir8kccm_aow7lb5cq1(events_0, i_10);
        X60Qx_9 = (*X60Qx_75);}
      else {
        X60Qx_9 = 0;}
      NI32 X60Qx_76 = nimIcheckB(i_10, 255);
      pfds_0.a[X60Qx_76].events = ((short)X60Qx_9);
      NI32 X60Qx_77 = nimIcheckB(i_10, 255);
      pfds_0.a[X60Qx_77].revents = ((short)0);
      if (((int)0) <= fd_30){
        inc_1_I6wjjge_aow2h993l1((&live_0));}
      inc_1_I6wjjge_aow2h993l1((&i_10));}}
  whileStmtLabel_1: ;
  if (live_0 == 0){
    i_10 = 0;
    {
      while (i_10 < n_7){
        putQ_7_Ifvyck5_aow7lb5cq1(revents_0, i_10, 32);
        inc_1_I6wjjge_aow2h993l1((&i_10));}}
    whileStmtLabel_2: ;
    return n_7;}
  NI32 X60Qx_78 = nimIcheckB(0, 255);
  int rc_11 = poll(((void*)(&pfds_0.a[X60Qx_78])), ((unsigned long)n_7), ((int)timeout_1));
  capture_0_hos9jnsbq1();
  i_10 = 0;
  {
    while (i_10 < n_7){
      NI64 X60Qx_10;
      NI32 X60Qx_79 = nimIcheckB(i_10, 255);
      if (pfds_0.a[X60Qx_79].fd < ((int)0)){
        X60Qx_10 = 32;}
      else {
        NI32 X60Qx_80 = nimIcheckB(i_10, 255);
        X60Qx_10 = ((NI32)pfds_0.a[X60Qx_80].revents);}
      putQ_7_Ifvyck5_aow7lb5cq1(revents_0, i_10, X60Qx_10);
      inc_1_I6wjjge_aow2h993l1((&i_10));}}
  whileStmtLabel_3: ;
  result_20 = ((NI32)rc_11);
  return result_20;}
NI32 hostHtons_0_hos9jnsbq1(NI32 x_4){
  NI32 result_21;
  unsigned short X60Qx_81 = htons(((unsigned short)((NU16)x_4)));
  result_21 = ((NI32)((NU16)X60Qx_81));
  return result_21;}
NI32 hostHtonl_0_hos9jnsbq1(NI32 x_5){
  NI32 result_22;
  NU32 X60Qx_82 = htonl(((NU32)x_5));
  result_22 = ((NI32)((NU32)X60Qx_82));
  return result_22;}
NI32 hostNtohs_0_hos9jnsbq1(NI32 x_6){
  NI32 result_23;
  unsigned short X60Qx_83 = ntohs(((unsigned short)((NU16)x_6)));
  result_23 = ((NI32)((NU16)X60Qx_83));
  return result_23;}
NI32 hostNtohl_0_hos9jnsbq1(NI32 x_7){
  NI32 result_24;
  NU32 X60Qx_84 = ntohl(((NU32)x_7));
  result_24 = ((NI32)((NU32)X60Qx_84));
  return result_24;}
static inline seq_0_Iowv1l61_hos9jnsbq1 newSeqUninit_0_I2jc8gi_hos9jnsbq1(NI32 size_2){
  seq_0_Iowv1l61_hos9jnsbq1 result_25;
  if (size_2 == 0){
    result_25 = (seq_0_Iowv1l61_hos9jnsbq1){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Ivblwj61_hos9jnsbq1(size_2);
    void* X60Qx_85 = alloc_1_sysvq0asl(memSize_0);
    result_25 = (seq_0_Iowv1l61_hos9jnsbq1){
      .len_0 = size_2, .data_0 = ((int*)X60Qx_85)}
    ;
    if ((!(result_25.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_86 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_25.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_25;}
static inline NI32 len_3_I5p4l001_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_8){
  NI32 result_26;
  result_26 = s_8.len_0;
  return result_26;}
static inline int* getQ_7_Itbh6l31_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_9, NI32 i_13){
  NB8 X60Qx_87;
  if (i_13 < s_9.len_0){
    X60Qx_87 = (0 <= i_13);}
  else {
    X60Qx_87 = NIM_FALSE;}
  if ((!X60Qx_87)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  int* result_27;
  result_27 = (&s_9.data_0[i_13]);
  return result_27;}
static inline void add_0_I05nls4_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* s_10, int elem_4){
  NI32 L_0 = (*s_10).len_0;
  NI32 X60Qx_88 = capInBytes_0_Iahcimz_hos9jnsbq1((*s_10));
  if (X60Qx_88 < ((NI32)(((NI32)(L_0 * sizeof(int))) + sizeof(int)))){
    NB8 X60Qx_89 = resize_0_Iznnnie1_hos9jnsbq1(s_10, 1);
    if ((!X60Qx_89)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_10).len_0));
  (*s_10).data_0[L_0] = elem_4;}
static inline void putQ_7_I4a1m13_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* s_12, NI32 i_14, int elem_5){
  NB8 X60Qx_90;
  if (i_14 < (*s_12).len_0){
    X60Qx_90 = (0 <= i_14);}
  else {
    X60Qx_90 = NIM_FALSE;}
  if ((!X60Qx_90)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_12).data_0[i_14] = elem_5;}
static inline X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 default_23_If5mx7o1_hos9jnsbq1(void){
  X60Qt_0_IAarrayAuS8ZS128_hos9jnsbq1 result_28;
  {
    NI32 X60Qlf_0 = ((NI32)0);
    NI32 X60Qlf_1 = ((NI32)127);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          NI32 X60Qx_91 = nimIcheckB(X60Qlf_2, 127);
          result_28.a[X60Qx_91] = ((NU8)0u);}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_28;}
static inline X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1 default_23_I4zcfwx1_hos9jnsbq1(void){
  X60Qt_0_IAarraySX50ollX46dX430hos9jnsbq1S256_hos9jnsbq1 result_31;
  {
    NI32 X60Qlf_3 = ((NI32)0);
    NI32 X60Qlf_4 = ((NI32)255);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 <= X60Qlf_4){
        {
          NI32 X60Qx_96 = nimIcheckB(X60Qlf_5, 255);
          result_31.a[X60Qx_96] = (struct pollfd){
            .fd = ((NI32)0), .events = ((NI16)0), .revents = ((NI16)0)}
          ;}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_31;}
static inline NI32 memSizeInBytes_0_Ivblwj61_hos9jnsbq1(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(int), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
static inline NI32 capInBytes_0_Iahcimz_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1 s_18){
  NI32 result_34;
  NI32 X60Qx_11;
  if ((!(s_18.data_0 == NIM_NIL))){
    NI32 X60Qx_99 = allocatedSize_0_sysvq0asl(((void*)((void*)s_18.data_0)));
    X60Qx_11 = X60Qx_99;}
  else {
    X60Qx_11 = 0;}
  result_34 = X60Qx_11;
  return result_34;}
NB8 resize_0_Iznnnie1_hos9jnsbq1(seq_0_Iowv1l61_hos9jnsbq1* dest_2, NI32 addedElements_2){
  NB8 result_35;
  NI32 X60Qx_100 = capInBytes_0_Iahcimz_hos9jnsbq1((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_100 / sizeof(int)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_2 = memSizeInBytes_0_Ivblwj61_hos9jnsbq1(newCap_0);
  void* X60Qx_101 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_2);
  (*dest_2).data_0 = ((int*)X60Qx_101);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_2);
    result_35 = NIM_FALSE;}
  else {
    result_35 = NIM_TRUE;}
  return result_35;}
void X60Qini_0_hos9jnsbq1(void){
  if (X60QiniGuard_0_hos9jnsbq1){
    return;}
  X60QiniGuard_0_hos9jnsbq1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_iop7yt73v();
  gSockReal_0_hos9jnsbq1 = newSeqUninit_0_I2jc8gi_hos9jnsbq1(0);}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22){
  NI32 result_159;
  NB8 X60Qx_327;
  if (0 <= i_19){
    X60Qx_327 = (i_19 <= b_22);}
  else {
    X60Qx_327 = NIM_FALSE;}
  if (X60Qx_327){
    result_159 = i_19;}
  else {
    result_159 = 0;
    raiseIndexError3_0_I113jpc1_sysvq0asl(i_19, 0, b_22);}
  return result_159;}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_67;
  result_67 = s_45.len_0;
  return result_67;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36){
  NB8 X60Qx_1442;
  if (i_36 < s_46.len_0){
    X60Qx_1442 = (0 <= i_36);}
  else {
    X60Qx_1442 = NIM_FALSE;}
  if ((!X60Qx_1442)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_68;
  result_68 = (&s_46.data_0[i_36]);
  return result_68;}
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15){
  NB8 X60Qx_1452;
  if (i_38 < (*s_52).len_0){
    X60Qx_1452 = (0 <= i_38);}
  else {
    X60Qx_1452 = NIM_FALSE;}
  if ((!X60Qx_1452)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_52).data_0[i_38] = elem_15;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
