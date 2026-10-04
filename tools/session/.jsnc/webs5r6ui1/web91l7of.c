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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct seq_0_Ilvi9zw_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* data_0;}
seq_0_Ilvi9zw_intzsnzax;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Isfp6gt1_intzsnzax{
  seq_0_Ilvi9zw_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Isfp6gt1_intzsnzax;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI32 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1)(VfsBlob_0_vfsc9jn7*);
typedef struct VfsBlob_0_vfsc9jn7{
  void* data_0;
  NI32 size_0;
  MemFile_0_memlzdyby mf_0;
  void* cookie_0;
  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0;}
VfsBlob_0_vfsc9jn7;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef N_NIMCALL_PTR(VfsBlob_0_vfsc9jn7,  X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7)(string_0_sysvq0asl, string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_ISstring0sysvq0aslAiS64ZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_IAiS64ZAnimcallZAfalseZAR15_vfsc9jn7)(void);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSEAnimcallZAfalseZAR28_vfsc9jn7)(string_0_sysvq0asl);
static inline NB8 hasKey_0_Iizizmq_web91l7of(Table_0_Isfp6gt1_intzsnzax t_7, string_0_sysvq0asl k_9);
string_0_sysvq0asl getOrDefault_0_Ipybg2h_web91l7of(Table_0_Isfp6gt1_intzsnzax t_9, string_0_sysvq0asl k_11);
void del_0_Ishh44u_web91l7of(Table_0_Isfp6gt1_intzsnzax* t_10, string_0_sysvq0asl k_12);
static inline NB8 contains_0_Is0iq21_web91l7of(Table_0_Isfp6gt1_intzsnzax t_14, string_0_sysvq0asl k_15);
static inline void putQ_7_Igg23ho1_web91l7of(seq_0_Ilvi9zw_intzsnzax* s_13, NI32 i_11, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_3);
void shrink_0_Iywnxt4_web91l7of(seq_0_Ilvi9zw_intzsnzax* s_14, NI32 newLen_2);
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0);
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 eQdupQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 src_0);
void eQwasmovedQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* dest_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void putQ_0_Ielboco_intzsnzax(Table_0_Isfp6gt1_intzsnzax* t_89, string_0_sysvq0asl k_80, string_0_sysvq0asl v_50);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void dealloc_1_sysvq0asl(void* p_20);
extern VfsBlob_0_vfsc9jn7 initBlob_0_vfsc9jn7(void* data_0, NI32 size_0, void* cookie_0, X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void* alloc_1_sysvq0asl(NI32 size_24);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7 openMmapRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7 readBytesRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7 writeBytesRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7 existsRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslAiS64ZAnimcallZAfalseZAR32_vfsc9jn7 mtimeRelay_0_vfsc9jn7;
extern X60Qt_0_IAiS64ZAnimcallZAfalseZAR15_vfsc9jn7 nowRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslSEAnimcallZAfalseZAR28_vfsc9jn7 removeRelay_0_vfsc9jn7;
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
static inline NC8 chr_0_sysvq0asl(NI32 u_0);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern LongString_0_sysvq0asl const strlit_0_I5065733472155119234_modzy18mg1;
extern LongString_0_sysvq0asl const strlit_0_I16810923556642427947_modzy18mg1;
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
extern NI32 rawGet_0_Isrbv9r_intzsnzax(Table_0_Isfp6gt1_intzsnzax t_126, string_0_sysvq0asl k_105, NU32 kh_19);
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Iu7lf0h1_intzsnzax(seq_0_Ilvi9zw_intzsnzax s_240, NI32 i_138);
static inline NI32 len_3_I5oa9x61_intzsnzax(seq_0_Ilvi9zw_intzsnzax s_239);
extern void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
extern seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
extern void shrink_0_Io47po81_prorcx25w1(seq_0_Ikxuplm1_der823rwr1* s_102, NI32 newLen_6);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline void eQwasMoved_1_Iqkhh121_intzsnzax(seq_0_Ilvi9zw_intzsnzax* s_509);
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_vfsc9jn7(void);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I11201514831099767300_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_46);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
LongString_0_sysvq0asl const strlit_0_I16952481534133288743_web91l7of = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "webmod"}
;
LongString_0_sysvq0asl const strlit_0_I7372337277955000691_web91l7of = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(.nif27)\012(index\012)\012"}
;
Table_0_Isfp6gt1_intzsnzax webFs_0_web91l7of;
NB8 X60QiniGuard_0_web91l7of;
void webPut_0_web91l7of(string_0_sysvq0asl path_0, string_0_sysvq0asl content_0){
  string_0_sysvq0asl X60Qx_6 = nimStrDup(path_0);
  string_0_sysvq0asl X60Qx_7 = nimStrDup(content_0);
  putQ_0_Ielboco_intzsnzax((&webFs_0_web91l7of), X60Qx_6, X60Qx_7);}
NB8 webHas_0_web91l7of(string_0_sysvq0asl path_1){
  NB8 result_0;
  NB8 X60Qx_8 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_1);
  result_0 = X60Qx_8;
  return result_0;}
N_NIMCALL(string_0_sysvq0asl, webRead_0_web91l7of)(string_0_sysvq0asl path_2){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  string_0_sysvq0asl X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  NB8 X60Qx_9 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_2);
  if (X60Qx_9){
    nimStrDestroy(X60Qx_0);
    string_0_sysvq0asl X60Qx_10 = getOrDefault_0_Ipybg2h_web91l7of(webFs_0_web91l7of, path_2);
    X60Qx_0 = X60Qx_10;}
  else {
    nimStrDestroy(X60Qx_0);
    X60Qx_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_1);
  result_1 = X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  nimStrDestroy(X60Qx_0);
  return result_1;
  nimStrDestroy(X60Qx_0);
  return result_1;}
N_NIMCALL(void, webWrite_0_web91l7of)(string_0_sysvq0asl path_3, string_0_sysvq0asl content_1){
  string_0_sysvq0asl X60Qx_11 = nimStrDup(path_3);
  string_0_sysvq0asl X60Qx_12 = nimStrDup(content_1);
  putQ_0_Ielboco_intzsnzax((&webFs_0_web91l7of), X60Qx_11, X60Qx_12);}
N_NIMCALL(NB8, webExists_0_web91l7of)(string_0_sysvq0asl path_4){
  NB8 result_2;
  NB8 X60Qx_13 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_4);
  result_2 = X60Qx_13;
  return result_2;}
N_NIMCALL(NI64, webMtime_0_web91l7of)(string_0_sysvq0asl path_5){
  NI64 result_3;
  NI64 X60Qx_1;
  NB8 X60Qx_14 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_5);
  if (X60Qx_14){
    X60Qx_1 = ((NI64)1);}
  else {
    X60Qx_1 = ((NI64)0);}
  result_3 = X60Qx_1;
  return result_3;}
N_NIMCALL(NI64, webNow_0_web91l7of)(void){
  NI64 result_4;
  result_4 = ((NI64)2);
  return result_4;}
N_NIMCALL(void, webRemove_0_web91l7of)(string_0_sysvq0asl path_6){
  NB8 X60Qx_15 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_6);
  if (X60Qx_15){
    del_0_Ishh44u_web91l7of((&webFs_0_web91l7of), path_6);}}
N_NIMCALL(void, webBlobCleanup_0_web91l7of)(VfsBlob_0_vfsc9jn7* b_0){
  if ((!((*b_0).cookie_0 == NIM_NIL))){
    dealloc_1_sysvq0asl((*b_0).cookie_0);}}
N_NIMCALL(VfsBlob_0_vfsc9jn7, webOpenMmap_0_web91l7of)(string_0_sysvq0asl path_7){
  VfsBlob_0_vfsc9jn7 result_5;
  NB8 X60Qx_16 = hasKey_0_Iizizmq_web91l7of(webFs_0_web91l7of, path_7);
  if ((!X60Qx_16)){
    VfsBlob_0_vfsc9jn7 X60Qx_17 = initBlob_0_vfsc9jn7(NIM_NIL, 0, NIM_NIL, NIM_NIL);
    result_5 = X60Qx_17;
    return result_5;}
  string_0_sysvq0asl content_2 = getOrDefault_0_Ipybg2h_web91l7of(webFs_0_web91l7of, path_7);
  NI32 n_0 = len_4_sysvq0asl(content_2);
  if (n_0 == 0){
    VfsBlob_0_vfsc9jn7 X60Qx_18 = initBlob_0_vfsc9jn7(NIM_NIL, 0, NIM_NIL, NIM_NIL);
    result_5 = X60Qx_18;
    nimStrDestroy(content_2);
    return result_5;}
  void* buf_0 = alloc_1_sysvq0asl(n_0);
  NC8* dst_0 = ((NC8*)buf_0);
  {
    NI32 X60Qlf_0 = 0;
    NI32 X60Qlf_1 = n_0;
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 < X60Qlf_1){
        {
          NC8 X60Qx_19 = getQ_9_sysvq0asl(content_2, X60Qlf_2);
          dst_0[X60Qlf_2] = X60Qx_19;}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  VfsBlob_0_vfsc9jn7 X60Qx_20 = initBlob_0_vfsc9jn7(buf_0, n_0, buf_0, webBlobCleanup_0_web91l7of);
  result_5 = X60Qx_20;
  nimStrDestroy(content_2);
  return result_5;
  nimStrDestroy(content_2);
  return result_5;}
void installWebVfs_0_web91l7of(void){
  openMmapRelay_0_vfsc9jn7 = webOpenMmap_0_web91l7of;
  readBytesRelay_0_vfsc9jn7 = webRead_0_web91l7of;
  writeBytesRelay_0_vfsc9jn7 = webWrite_0_web91l7of;
  existsRelay_0_vfsc9jn7 = webExists_0_web91l7of;
  mtimeRelay_0_vfsc9jn7 = webMtime_0_web91l7of;
  nowRelay_0_vfsc9jn7 = webNow_0_web91l7of;
  removeRelay_0_vfsc9jn7 = webRemove_0_web91l7of;}
NI32 hexNib_0_web91l7of(NC8 c_0){
  NI32 result_6;
  NI32 X60Qx_2;
  NB8 X60Qx_21;
  if ((NC8)'0' <= c_0){
    X60Qx_21 = (c_0 <= (NC8)'9');}
  else {
    X60Qx_21 = NIM_FALSE;}
  if (X60Qx_21){
    X60Qx_2 = ((NI32)(((NI32)c_0) - ((NI32)(NC8)'0')));}
  else {
    NB8 X60Qx_22;
    if ((NC8)'A' <= c_0){
      X60Qx_22 = (c_0 <= (NC8)'F');}
    else {
      X60Qx_22 = NIM_FALSE;}
    if (X60Qx_22){
      X60Qx_2 = ((NI32)(10 + ((NI32)(((NI32)c_0) - ((NI32)(NC8)'A')))));}
    else {
      NB8 X60Qx_23;
      if ((NC8)'a' <= c_0){
        X60Qx_23 = (c_0 <= (NC8)'f');}
      else {
        X60Qx_23 = NIM_FALSE;}
      if (X60Qx_23){
        X60Qx_2 = ((NI32)(10 + ((NI32)(((NI32)c_0) - ((NI32)(NC8)'a')))));}
      else {
        X60Qx_2 = 0;}}}
  result_6 = X60Qx_2;
  return result_6;}
NI32 parseInt10_0_web91l7of(string_0_sysvq0asl s_0){
  NI32 result_7;
  result_7 = 0;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_3 = toOpenArray_2_sysvq0asl((&s_0));
    NI32 X60Qlf_4 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_24 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_3);
        if (X60Qlf_4 < X60Qx_24){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_3, X60Qlf_4);
            NB8 X60Qx_25;
            if ((NC8)'0' <= (*X60Qii_2)){
              X60Qx_25 = ((*X60Qii_2) <= (NC8)'9');}
            else {
              X60Qx_25 = NIM_FALSE;}
            if (X60Qx_25){
              result_7 = ((NI32)(((NI32)(result_7 * 10)) + ((NI32)(((NI32)(*X60Qii_2)) - ((NI32)(NC8)'0')))));}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_4));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_7;}
string_0_sysvq0asl unescapeTransport_0_web91l7of(string_0_sysvq0asl body_0){
  string_0_sysvq0asl result_8;
  nimStrWasMoved((&result_8));
  nimStrDestroy(result_8);
  NI32 X60Qx_26 = len_4_sysvq0asl(body_0);
  string_0_sysvq0asl X60Qx_27 = newStringOfCap_0_sysvq0asl(X60Qx_26);
  result_8 = X60Qx_27;
  NI32 k_4 = 0;
  NI32 m_0 = len_4_sysvq0asl(body_0);
  {
    while (k_4 < m_0){
      NB8 X60Qx_28;
      NB8 X60Qx_29;
      if (((NI32)(k_4 + 3)) < m_0){
        NC8 X60Qx_30 = getQ_9_sysvq0asl(body_0, k_4);
        X60Qx_29 = (X60Qx_30 == (NC8)'\\');}
      else {
        X60Qx_29 = NIM_FALSE;}
      if (X60Qx_29){
        NC8 X60Qx_31 = getQ_9_sysvq0asl(body_0, ((NI32)(k_4 + 1)));
        X60Qx_28 = (X60Qx_31 == (NC8)'x');}
      else {
        X60Qx_28 = NIM_FALSE;}
      if (X60Qx_28){
        NC8 X60Qx_32 = getQ_9_sysvq0asl(body_0, ((NI32)(k_4 + 2)));
        NI32 X60Qx_33 = hexNib_0_web91l7of(X60Qx_32);
        NC8 X60Qx_34 = getQ_9_sysvq0asl(body_0, ((NI32)(k_4 + 3)));
        NI32 X60Qx_35 = hexNib_0_web91l7of(X60Qx_34);
        NC8 X60Qx_36 = chr_0_sysvq0asl(((NI32)(((NI32)(X60Qx_33 * 16)) + X60Qx_35)));
        add_1_sysvq0asl((&result_8), X60Qx_36);
        plusQeQ_0_Iz7fdp7_emi78vuj01((&k_4), 4);}
      else {
        NC8 X60Qx_37 = getQ_9_sysvq0asl(body_0, k_4);
        add_1_sysvq0asl((&result_8), X60Qx_37);
        inc_1_I6wjjge_aow2h993l1((&k_4));}}}
  whileStmtLabel_0: ;
  return result_8;}
void loadWebModules_0_web91l7of(string_0_sysvq0asl framed_0){
  NI32 i_1 = 0;
  NI32 n_1 = len_4_sysvq0asl(framed_0);
  {
    while (i_1 < n_1){
      string_0_sysvq0asl name_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_38;
          if (i_1 < n_1){
            NC8 X60Qx_39 = getQ_9_sysvq0asl(framed_0, i_1);
            X60Qx_38 = (!(X60Qx_39 == (NC8)'\011'));}
          else {
            X60Qx_38 = NIM_FALSE;}
          if (X60Qx_38){
            NC8 X60Qx_40 = getQ_9_sysvq0asl(framed_0, i_1);
            add_1_sysvq0asl((&name_0), X60Qx_40);
            inc_1_I6wjjge_aow2h993l1((&i_1));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      inc_1_I6wjjge_aow2h993l1((&i_1));
      string_0_sysvq0asl lenStr_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_41;
          if (i_1 < n_1){
            NC8 X60Qx_42 = getQ_9_sysvq0asl(framed_0, i_1);
            X60Qx_41 = (!(X60Qx_42 == (NC8)'\012'));}
          else {
            X60Qx_41 = NIM_FALSE;}
          if (X60Qx_41){
            NC8 X60Qx_43 = getQ_9_sysvq0asl(framed_0, i_1);
            add_1_sysvq0asl((&lenStr_0), X60Qx_43);
            inc_1_I6wjjge_aow2h993l1((&i_1));}
          else {
            break;}}}
      whileStmtLabel_2: ;
      inc_1_I6wjjge_aow2h993l1((&i_1));
      NI32 blen_0 = parseInt10_0_web91l7of(lenStr_0);
      string_0_sysvq0asl body_1 = newString_0_sysvq0asl(blen_0);
      {
        NI32 X60Qlf_5 = 0;
        NI32 X60Qlf_6 = blen_0;
        NI32 X60Qlf_7 = X60Qlf_5;
        {
          while (X60Qlf_7 < X60Qlf_6){
            {
              if (((NI32)(i_1 + X60Qlf_7)) < n_1){
                NC8 X60Qx_44 = getQ_9_sysvq0asl(framed_0, ((NI32)(i_1 + X60Qlf_7)));
                putQ_9_sysvq0asl((&body_1), X60Qlf_7, X60Qx_44);}}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}}
        whileStmtLabel_4: ;}
      forStmtLabel_3: ;
      plusQeQ_0_Iz7fdp7_emi78vuj01((&i_1), blen_0);
      NI32 X60Qx_45 = len_4_sysvq0asl(name_0);
      if (0 < X60Qx_45){
        NI32 X60Qx_46 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7810818u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_47 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 12033u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_48 = len_4_sysvq0asl(name_0);
        string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_46 + X60Qx_47)) + X60Qx_48)));
        add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
          .bytes_0 = 7810818u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
          .bytes_0 = 12033u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_0), name_0);
        string_0_sysvq0asl X60Qtmp_0 = unescapeTransport_0_web91l7of(body_1);
        webPut_0_web91l7of(X60Qdesugar_0, X60Qtmp_0);
        nimStrDestroy(X60Qtmp_0);
        nimStrDestroy(X60Qdesugar_0);}
      nimStrDestroy(body_1);
      nimStrDestroy(lenStr_0);
      nimStrDestroy(name_0);}}
  whileStmtLabel_0: ;}
void publishMainModule_0_web91l7of(string_0_sysvq0asl src_0){
  NI32 X60Qx_49 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_50 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_51 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  NI32 X60Qx_52 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_49 + X60Qx_50)) + X60Qx_51)) + X60Qx_52)));
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  string_0_sysvq0asl nif_0 = X60Qdesugar_1;
  nimStrWasMoved((&X60Qdesugar_1));
  NB8 X60Qx_53 = webHas_0_web91l7of(nif_0);
  if ((!X60Qx_53)){
    webPut_0_web91l7of(nif_0, src_0);}
  NI32 X60Qx_54 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_55 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_56 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  NI32 X60Qx_57 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I16810923556642427947_modzy18mg1)}
  );
  string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_54 + X60Qx_55)) + X60Qx_56)) + X60Qx_57)));
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I16810923556642427947_modzy18mg1)}
  );
  string_0_sysvq0asl idx_0 = X60Qdesugar_2;
  nimStrWasMoved((&X60Qdesugar_2));
  NB8 X60Qx_58 = webHas_0_web91l7of(idx_0);
  if ((!X60Qx_58)){
    webPut_0_web91l7of(idx_0, (string_0_sysvq0asl){
      .bytes_0 = 1848518910u, .more_0 = (&strlit_0_I7372337277955000691_web91l7of)}
    );}
  nimStrDestroy(idx_0);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(nif_0);
  nimStrDestroy(X60Qdesugar_1);}
static inline NB8 hasKey_0_Iizizmq_web91l7of(Table_0_Isfp6gt1_intzsnzax t_7, string_0_sysvq0asl k_9){
  NB8 result_9;
  NB8 X60Qx_60 = contains_0_Is0iq21_web91l7of(t_7, k_9);
  result_9 = X60Qx_60;
  return result_9;}
string_0_sysvq0asl getOrDefault_0_Ipybg2h_web91l7of(Table_0_Isfp6gt1_intzsnzax t_9, string_0_sysvq0asl k_11){
  string_0_sysvq0asl result_10;
  nimStrWasMoved((&result_10));
  NU32 X60Qx_61 = hash_1_has9tn57v(k_11);
  NI32 idx_2 = rawGet_0_Isrbv9r_intzsnzax(t_9, k_11, X60Qx_61);
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  if (0 <= idx_2){
    nimStrDestroy(X60Qx_3);
    X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_62 = getQ_7_Iu7lf0h1_intzsnzax(t_9.data_0, idx_2);
    string_0_sysvq0asl X60Qx_63 = nimStrDup((*X60Qx_62).fld_1);
    X60Qx_3 = X60Qx_63;}
  else {
    nimStrDestroy(X60Qx_3);
    X60Qx_3 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_10);
  result_10 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_10;
  nimStrDestroy(X60Qx_3);
  return result_10;}
void del_0_Ishh44u_web91l7of(Table_0_Isfp6gt1_intzsnzax* t_10, string_0_sysvq0asl k_12){
  NU32 X60Qx_64 = hash_1_has9tn57v(k_12);
  NI32 idx_3 = rawGet_0_Isrbv9r_intzsnzax((*t_10), k_12, X60Qx_64);
  if (idx_3 < 0){
    return;}
  NI32 j_0 = idx_3;
  {
    while (NIM_TRUE){
      NI32 X60Qx_65 = len_3_I5oa9x61_intzsnzax((*t_10).data_0);
      if (j_0 < ((NI32)(X60Qx_65 - 1))){
        X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_66 = getQ_7_Iu7lf0h1_intzsnzax((*t_10).data_0, ((NI32)(j_0 + 1)));
        X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 next_0 = eQdupQ_AtupleSstring0sysvq0aslSR6_0_web91l7of((*X60Qx_66));
        X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qtmp_5 = next_0;
        eQwasmovedQ_AtupleSstring0sysvq0aslSR6_0_web91l7of((&next_0));
        putQ_7_Igg23ho1_web91l7of((&(*t_10).data_0), j_0, X60Qtmp_5);
        inc_1_I6wjjge_aow2h993l1((&j_0));
        eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(next_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_67 = len_3_I5oa9x61_intzsnzax((*t_10).data_0);
  shrink_0_Iywnxt4_web91l7of((&(*t_10).data_0), ((NI32)(X60Qx_67 - 1)));
  if (((NI32)4) < (*t_10).data_0.len_0){
    NI32 size_0 = ((NI32)(((NI32)4) * 2));
    {
      while (NIM_TRUE){
        NI32 X60Qx_68 = len_3_I5oa9x61_intzsnzax((*t_10).data_0);
        if (size_0 < ((NI32)(X60Qx_68 * 2))){
          size_0 = ((NI32)(size_0 * 2));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    seq_0_Ikxuplm1_der823rwr1* X60Qlhs_6 = (&(*t_10).hashes_0);
    eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_6));
    seq_0_Ikxuplm1_der823rwr1 X60Qx_69 = newSeq_0_Iv3lu2h1_der823rwr1(size_0);
    (*X60Qlhs_6) = X60Qx_69;
    {
      NI32 X60Qlf_8 = 0;
      NI32 X60Qlf_9 = len_3_I5oa9x61_intzsnzax((*t_10).data_0);
      NI32 X60Qlf_10 = X60Qlf_8;
      {
        while (X60Qlf_10 < X60Qlf_9){
          {
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_70 = getQ_7_Iu7lf0h1_intzsnzax((*t_10).data_0, X60Qlf_10);
            NU32 X60Qii_4 = hash_1_has9tn57v((*X60Qx_70).fld_0);
            NI32 X60Qx_71 = high_3_Iyuup9h1_der823rwr1((*t_10).hashes_0);
            NU32 X60Qii_5 = ((NU32)(X60Qii_4 & ((NU32)X60Qx_71)));
            while (NIM_TRUE){
              HashEntry_0_tabcr240b1* X60Qx_72 = getQ_8_Imt2zi01_der823rwr1((*t_10).hashes_0, X60Qii_5);
              NB8 X60Qx_73 = isFilled_0_tabcr240b1((*X60Qx_72));
              if (X60Qx_73){
                NI32 X60Qx_74 = high_3_Iyuup9h1_der823rwr1((*t_10).hashes_0);
                NU32 X60Qx_75 = nextTry_0_has9tn57v(X60Qii_5, X60Qx_74);
                X60Qii_5 = X60Qx_75;}
              else {
                break;}}
            putQ_8_Ipchg2a_der823rwr1((&(*t_10).hashes_0), X60Qii_5, (HashEntry_0_tabcr240b1){
              .fullhash_0 = X60Qii_4, .position_0 = ((NI32)(X60Qlf_10 + 1))}
            );}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_10));}}
      whileStmtLabel_3: ;}
    forStmtLabel_2: ;}
  else {
    shrink_0_Io47po81_prorcx25w1((&(*t_10).hashes_0), 0);}}
static inline NB8 contains_0_Is0iq21_web91l7of(Table_0_Isfp6gt1_intzsnzax t_14, string_0_sysvq0asl k_15){
  NB8 result_13;
  NU32 X60Qx_99 = hash_1_has9tn57v(k_15);
  NI32 X60Qx_100 = rawGet_0_Isrbv9r_intzsnzax(t_14, k_15, X60Qx_99);
  result_13 = (0 <= X60Qx_100);
  return result_13;}
static inline void putQ_7_Igg23ho1_web91l7of(seq_0_Ilvi9zw_intzsnzax* s_13, NI32 i_11, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_3){
  NB8 X60Qx_101;
  if (i_11 < (*s_13).len_0){
    X60Qx_101 = (0 <= i_11);}
  else {
    X60Qx_101 = NIM_FALSE;}
  if ((!X60Qx_101)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qlhs_9 = (&(*s_13).data_0[i_11]);
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qlhs_10 = elem_3;
  eQwasmovedQ_AtupleSstring0sysvq0aslSR6_0_web91l7of((&elem_3));
  eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of((*X60Qlhs_9));
  (*X60Qlhs_9) = X60Qlhs_10;
  eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(elem_3);}
void shrink_0_Iywnxt4_web91l7of(seq_0_Ilvi9zw_intzsnzax* s_14, NI32 newLen_2){
  NI32 i_12 = ((NI32)((*s_14).len_0 - 1));
  {
    while (newLen_2 <= i_12){
      eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of((*s_14).data_0[i_12]);
      dec_1_I0nzoz91_aow7lb5cq1((&i_12));}}
  whileStmtLabel_0: ;
  (*s_14).len_0 = newLen_2;}
void eQwasmovedQ_SX54able0X49sfp6gt1_0_web91l7of(Table_0_Isfp6gt1_intzsnzax* dest_0){
  eQwasMoved_1_Iqkhh121_intzsnzax((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0){
  nimStrDestroy(dest_0.fld_0);
  nimStrDestroy(dest_0.fld_1);}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 eQdupQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 src_0){
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0;
  string_0_sysvq0asl X60Qx_133 = nimStrDup(src_0.fld_0);
  dest_0.fld_0 = X60Qx_133;
  string_0_sysvq0asl X60Qx_134 = nimStrDup(src_0.fld_1);
  dest_0.fld_1 = X60Qx_134;
  return dest_0;}
void eQwasmovedQ_AtupleSstring0sysvq0aslSR6_0_web91l7of(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* dest_0){
  nimStrWasMoved((&(*dest_0).fld_0));
  nimStrWasMoved((&(*dest_0).fld_1));}
void X60Qini_0_web91l7of(void){
  if (X60QiniGuard_0_web91l7of){
    return;}
  X60QiniGuard_0_web91l7of = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_vfsc9jn7();
  eQwasmovedQ_SX54able0X49sfp6gt1_0_web91l7of((&webFs_0_web91l7of));}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
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
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27){
  NI32 result_83;
  result_83 = a_27.len_0;
  return result_83;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_1466;
  if (0 <= idx_6){
    X60Qx_1466 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_1466 = NIM_FALSE;}
  if ((!X60Qx_1466)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_84;
  result_84 = (&x_12.a_0[idx_6]);
  return result_84;}
static inline NC8 chr_0_sysvq0asl(NI32 u_0){
  NC8 result_168;
  result_168 = ((NC8)((NI32)u_0));
  return result_168;}
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1){
  (*x_18) = ((NI32)((*x_18) + y_1));}
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15){
  NB8 X60Qx_259;
  NI32 X60Qx_260 = len_4_sysvq0asl((*s_55));
  if (i_15 < X60Qx_260){
    X60Qx_259 = (0 <= i_15);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if ((!X60Qx_259)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I11201514831099767300_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_55);
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_55).bytes_0))))){
    (*(*s_55).more_0).data_0[i_15] = c_15;
    if (i_15 < ((NI32)3)){
      ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
  else {
    ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Iu7lf0h1_intzsnzax(seq_0_Ilvi9zw_intzsnzax s_240, NI32 i_138){
  NB8 X60Qx_3780;
  if (i_138 < s_240.len_0){
    X60Qx_3780 = (0 <= i_138);}
  else {
    X60Qx_3780 = NIM_FALSE;}
  if ((!X60Qx_3780)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* result_248;
  result_248 = (&s_240.data_0[i_138]);
  return result_248;}
static inline NI32 len_3_I5oa9x61_intzsnzax(seq_0_Ilvi9zw_intzsnzax s_239){
  NI32 result_247;
  result_247 = s_239.len_0;
  return result_247;}
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28){
  NI32 result_35;
  result_35 = ((NI32)(s_28.len_0 - 1));
  return result_35;}
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17){
  if ((!(i_17 < ((NU32)s_29.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  HashEntry_0_tabcr240b1* result_36;
  result_36 = (&s_29.data_0[((NI32)i_17)]);
  return result_36;}
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2){
  NB8 result_1;
  result_1 = (0 < a_2.position_0);
  return result_1;}
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0){
  NU32 result_14;
  result_14 = ((NU32)(((NU32)(h_2 + 1u)) & ((NU32)maxHash_0)));
  return result_14;}
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7){
  if ((!(i_19 < ((NU32)(*s_33).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_33).data_0[((NI32)i_19)] = elem_7;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline void eQwasMoved_1_Iqkhh121_intzsnzax(seq_0_Ilvi9zw_intzsnzax* s_509){
  (*s_509).len_0 = 0;
  (*s_509).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
