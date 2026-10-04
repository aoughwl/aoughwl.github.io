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
#include <string.h>
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
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
typedef struct FilePos_0_nif81dubp1{
  NI32 col_0;
  NI32 line_0;}
FilePos_0_nif81dubp1;
typedef NU8 TokenFlag_0_nif81dubp1;

#define TokenHasEscapes_0_nif81dubp1 ((NU8)0)
#define FilenameHasEscapes_0_nif81dubp1 ((NU8)1)
#define TokenHasModuleSuffixExpansion_0_nif81dubp1 ((NU8)2)
#define CommentHasEscapes_0_nif81dubp1 ((NU8)3)
typedef struct StringView_0_strdllfw2{
  NC8* p_0;
  NI32 len_0;}
StringView_0_strdllfw2;
typedef struct ExpandedToken_0_nif81dubp1{
  NifKind_0_nif81dubp1 tk_0;
  NU8 flags_0;
  NU16 kind_0;
  StringView_0_strdllfw2 data_0;
  FilePos_0_nif81dubp1 pos_0;
  StringView_0_strdllfw2 filename_0;
  StringView_0_strdllfw2 comment_0;}
ExpandedToken_0_nif81dubp1;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct Reader_0_nif81dubp1{
  NC8* p_0;
  void* eof_0;
  VfsBlob_0_vfsc9jn7 f_0;
  string_0_sysvq0asl buf_0;
  string_0_sysvq0asl thisModule_0;
  NI32 line_0;
  NI32 indexAt_0;
  ExpandedToken_0_nif81dubp1 unusedNameHint_0;}
Reader_0_nif81dubp1;
typedef NU8 DirectivesResult_0_nif81dubp1;

#define WrongHeader_0_nif81dubp1 ((NU8)0)
#define WrongMeta_0_nif81dubp1 ((NU8)1)
#define Success_0_nif81dubp1 ((NU8)2)
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(VfsBlob_0_vfsc9jn7,  X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7)(string_0_sysvq0asl);
openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_3_Inpmq9h_nif81dubp1(NC8* x_4, NI32 first_1, NI32 last_1);
void eQdestroyQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0);
void eQwasmovedQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0);
void integerOutOfRangeError_0_nif81dubp1(void);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
extern NC8* beginStore_0_sysvq0asl(string_0_sysvq0asl* s_47, NI32 newLen_7, NI32 start_2);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_48);
extern NI32 parseBiggestFloat_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_6, NF64* number_4);
extern NI32 parseBiggestUInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_5, NU64* number_3);
extern NI32 parseBiggestInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_3, NI64* number_2);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern NB8 eqQ_1_strdllfw2(StringView_0_strdllfw2 a_1, string_0_sysvq0asl b_1);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
static inline VfsBlob_0_vfsc9jn7 vfsOpenMmap_0_vfsc9jn7(string_0_sysvq0asl path_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void quit_1_syn1lfpjv(string_0_sysvq0asl msg_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_memlzdyby(void);
extern void X60Qini_0_party5a2l1(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_strdllfw2(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_syn1lfpjv(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7 openMmapRelay_0_vfsc9jn7;
LongString_0_sysvq0asl const strlit_0_I15885164768026998599_nif81dubp1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "UnknownToken"}
;
LongString_0_sysvq0asl const strlit_0_I10315536999831874058_nif81dubp1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EofToken"}
;
LongString_0_sysvq0asl const strlit_0_I934207063279194918_nif81dubp1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "DotToken"}
;
LongString_0_sysvq0asl const strlit_0_I15846002265446469276_nif81dubp1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "Ident"}
;
LongString_0_sysvq0asl const strlit_0_I7416088036152788789_nif81dubp1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "Symbol"}
;
LongString_0_sysvq0asl const strlit_0_I15873059642980454073_nif81dubp1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SymbolDef"}
;
LongString_0_sysvq0asl const strlit_0_I7185474113853794403_nif81dubp1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "StringLit"}
;
LongString_0_sysvq0asl const strlit_0_I2368852795644526164_nif81dubp1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "CharLit"}
;
LongString_0_sysvq0asl const strlit_0_I17216697482861734393_nif81dubp1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IntLit"}
;
LongString_0_sysvq0asl const strlit_0_I16169252050837114447_nif81dubp1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "UIntLit"}
;
LongString_0_sysvq0asl const strlit_0_I2526583260401622044_nif81dubp1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "FloatLit"}
;
LongString_0_sysvq0asl const strlit_0_I3677393315539012384_nif81dubp1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ParLe"}
;
LongString_0_sysvq0asl const strlit_0_I2186592322655248559_nif81dubp1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ParRi"}
;
LongString_0_sysvq0asl const strlit_0_I11191788154693975321_nif81dubp1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<unknown token>"}
;
LongString_0_sysvq0asl const strlit_0_I7773138664102327703_nif81dubp1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "Parsed integer outside of valid range"}
;
LongString_0_sysvq0asl const strlit_0_I10426215507333234367_nif81dubp1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "keep it as UnknownToken"}
;
LongString_0_sysvq0asl const strlit_0_I397779028761265335_nif81dubp1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".indexat"}
;
LongString_0_sysvq0asl const strlit_0_I12979507887005580180_nif81dubp1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".unusedname"}
;
LongString_0_sysvq0asl const strlit_0_I18095058983225952061_nif81dubp1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "[Error] cannot open: "}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const ControlChars_0_nif81dubp1 = {
  .a = {
    0u, 0u, 0u, 0u, 140u, 3u, 0u, 4u, 1u, 0u, 0u, 40u, 0u, 0u, 0u, 104u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const ControlCharsOrWhite_0_nif81dubp1 = {
  .a = {
    0u, 38u, 0u, 0u, 141u, 3u, 0u, 4u, 1u, 0u, 0u, 40u, 0u, 0u, 0u, 104u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const HexChars_0_nif81dubp1 = {
  .a = {
    0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 126u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const Digits_0_nif81dubp1 = {
  .a = {
    0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const B62Digits_0_nif81dubp1 = {
  .a = {
    0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 254u, 255u, 255u, 7u, 254u, 255u, 255u, 7u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
;
NB8 X60QiniGuard_0_nif81dubp1;
string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  switch (e_0){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1802393086u, .more_0 = (&strlit_0_I15885164768026998599_nif81dubp1)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1718568446u, .more_0 = (&strlit_0_I10315536999831874058_nif81dubp1)}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953449214u, .more_0 = (&strlit_0_I934207063279194918_nif81dubp1)}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1701071358u, .more_0 = (&strlit_0_I15846002265446469276_nif81dubp1)}
      ;}
    break;
    case 4:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836667902u, .more_0 = (&strlit_0_I7416088036152788789_nif81dubp1)}
      ;}
    break;
    case 5:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1836667902u, .more_0 = (&strlit_0_I15873059642980454073_nif81dubp1)}
      ;}
    break;
    case 6:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1920226302u, .more_0 = (&strlit_0_I7185474113853794403_nif81dubp1)}
      ;}
    break;
    case 7:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1634223102u, .more_0 = (&strlit_0_I2368852795644526164_nif81dubp1)}
      ;}
    break;
    case 8:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1953384958u, .more_0 = (&strlit_0_I17216697482861734393_nif81dubp1)}
      ;}
    break;
    case 9:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1850299902u, .more_0 = (&strlit_0_I16169252050837114447_nif81dubp1)}
      ;}
    break;
    case 10:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1869367038u, .more_0 = (&strlit_0_I2526583260401622044_nif81dubp1)}
      ;}
    break;
    case 11:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918980350u, .more_0 = (&strlit_0_I3677393315539012384_nif81dubp1)}
      ;}
    break;
    case 12:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1918980350u, .more_0 = (&strlit_0_I2186592322655248559_nif81dubp1)}
      ;}
    break;}
  return result_5;}
void skipWhitespace_0_nif81dubp1(Reader_0_nif81dubp1* r_1){
  NC8* p_5 = (*r_1).p_0;
  void* eof_0 = (*r_1).eof_0;
  {
    while (((void*)p_5) < eof_0){
      switch (p_5[0]){
        case (NC8)' ':
        case (NC8)'\011':
        case (NC8)'\015':
        {
          p_5 = ((NC8*)((NI32)(((NI32)p_5) + 1)));}
        break;
        case (NC8)'\012':
        {
          p_5 = ((NC8*)((NI32)(((NI32)p_5) + 1)));
          inc_1_I6wjjge_aow2h993l1((&(*r_1).line_0));}
        break;
        default:
        {
          goto whileStmtLabel_0;}
        break;}}}
  whileStmtLabel_0: ;
  (*r_1).p_0 = p_5;}
static inline void captureComment_0_nif81dubp1(Reader_0_nif81dubp1* r_2, ExpandedToken_0_nif81dubp1* result_0){
  (*result_0).comment_0.p_0 = (*r_2).p_0;
  NC8* p_6 = (*r_2).p_0;
  void* eof_1 = (*r_2).eof_0;
  NC8* start_1 = p_6;
  {
    while (((void*)p_6) < eof_1){
      if (p_6[0] == (NC8)'#'){
        (*result_0).comment_0.len_0 = ((NI32)(((NI32)p_6) - ((NI32)start_1)));
        p_6 = ((NC8*)((NI32)(((NI32)p_6) + 1)));
        goto whileStmtLabel_0;}
      else {
        if (p_6[0] == (NC8)'\012'){
          p_6 = ((NC8*)((NI32)(((NI32)p_6) + 1)));
          inc_1_I6wjjge_aow2h993l1((&(*r_2).line_0));}
        else {
          if (p_6[0] == (NC8)'\\'){
            NU8* X60Qdesugar_3 = (&(*result_0).flags_0);
            TokenFlag_0_nif81dubp1 X60Qdesugar_4 = 3;
            (*X60Qdesugar_3) = ((NU8)((*X60Qdesugar_3) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_4 & 7))))));}
          p_6 = ((NC8*)((NI32)(((NI32)p_6) + 1)));}}}}
  whileStmtLabel_0: ;
  (*r_2).p_0 = p_6;}
NC8 handleHex_0_nif81dubp1(NC8* p_3){
  NC8 result_8;
  NI32 output_0 = 0;
  switch (p_3[0]){
    case (NC8)'0' ... (NC8)'9':
    {
      output_0 = ((NI32)(((NI32)(output_0 << 4)) | ((NI32)(((NI32)p_3[0]) - ((NI32)(NC8)'0')))));}
    break;
    case (NC8)'A' ... (NC8)'F':
    {
      output_0 = ((NI32)(((NI32)(output_0 << 4)) | ((NI32)(((NI32)(((NI32)p_3[0]) - ((NI32)(NC8)'A'))) + 10))));}
    break;
    default:
    {
      }
    break;}
  switch (p_3[1]){
    case (NC8)'0' ... (NC8)'9':
    {
      output_0 = ((NI32)(((NI32)(output_0 << 4)) | ((NI32)(((NI32)p_3[1]) - ((NI32)(NC8)'0')))));}
    break;
    case (NC8)'A' ... (NC8)'F':
    {
      output_0 = ((NI32)(((NI32)(output_0 << 4)) | ((NI32)(((NI32)(((NI32)p_3[1]) - ((NI32)(NC8)'A'))) + 10))));}
    break;
    default:
    {
      }
    break;}
  result_8 = ((NC8)output_0);
  return result_8;}
static inline NC8 decodeEscape_0_nif81dubp1(NC8** p_4){
  NC8 result_9;
  switch ((*p_4)[0]){
    case (NC8)'n':
    {
      result_9 = (NC8)'\012';
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 1)));}
    break;
    case (NC8)'t':
    {
      result_9 = (NC8)'\011';
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 1)));}
    break;
    case (NC8)'r':
    {
      result_9 = (NC8)'\015';
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 1)));}
    break;
    case (NC8)'|':
    {
      result_9 = (NC8)'\\';
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 1)));}
    break;
    case (NC8)'^':
    {
      result_9 = (NC8)'\"';
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 1)));}
    break;
    default:
    {
      NC8 X60Qx_15 = handleHex_0_nif81dubp1((*p_4));
      result_9 = X60Qx_15;
      (*p_4) = ((NC8*)((NI32)(((NI32)(*p_4)) + 2)));}
    break;}
  return result_9;}
NC8 decodeChar_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_1){
  NC8 result_10;
  if ((!((*t_1).tk_0 == 7))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_10 = (*t_1).data_0.p_0[0];
  if (result_10 == (NC8)'\\'){
    NC8* p_7 = (*t_1).data_0.p_0;
    p_7 = ((NC8*)((NI32)(((NI32)p_7) + 1)));
    NC8 X60Qx_16 = decodeEscape_0_nif81dubp1((&p_7));
    result_10 = X60Qx_16;}
  return result_10;}
string_0_sysvq0asl decodeStr_0_nif81dubp1(Reader_0_nif81dubp1* r_3, ExpandedToken_0_nif81dubp1* t_2){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  NU8 X60Qdesugar_5 = (*t_2).flags_0;
  NU64 X60Qdesugar_6 = ((NU)0);
  if (((NU8)(X60Qdesugar_5 & ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_6 & 7u)))))) != 0u){
    nimStrDestroy(result_11);
    result_11 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NC8* p_8 = (*t_2).data_0.p_0;
    NC8* sentinel_0 = ((NC8*)((NI32)(((NI32)p_8) + (*t_2).data_0.len_0)));
    {
      while (((void*)p_8) < ((void*)sentinel_0)){
        if (p_8[0] == (NC8)'\\'){
          p_8 = ((NC8*)((NI32)(((NI32)p_8) + 1)));
          NC8 X60Qx_17 = decodeEscape_0_nif81dubp1((&p_8));
          add_1_sysvq0asl((&result_11), X60Qx_17);}
        else {
          add_1_sysvq0asl((&result_11), p_8[0]);
          p_8 = ((NC8*)((NI32)(((NI32)p_8) + 1)));}}}
    whileStmtLabel_0: ;
    NU8 X60Qdesugar_7 = (*t_2).flags_0;
    NU64 X60Qdesugar_8 = ((NU)2);
    if (((NU8)(X60Qdesugar_7 & ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_8 & 7u)))))) != 0u){
      NI32 X60Qx_18 = len_4_sysvq0asl((*r_3).thisModule_0);
      if ((!(0 < X60Qx_18))){
        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
          .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
        );
        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        write_7_syn1lfpjv(stdout, (NC8)'\012');
        quit_0_syn1lfpjv(1);}
      add_2_sysvq0asl((&result_11), (*r_3).thisModule_0);}}
  else {
    NU8 X60Qdesugar_9 = (*t_2).flags_0;
    NU64 X60Qdesugar_10 = ((NU)2);
    if (((NU8)(X60Qdesugar_9 & ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_10 & 7u)))))) != 0u){
      NI32 X60Qx_19 = len_4_sysvq0asl((*r_3).thisModule_0);
      if ((!(0 < X60Qx_19))){
        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
          .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
        );
        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        write_7_syn1lfpjv(stdout, (NC8)'\012');
        quit_0_syn1lfpjv(1);}
      nimStrDestroy(result_11);
      NI32 X60Qx_20 = len_4_sysvq0asl((*r_3).thisModule_0);
      string_0_sysvq0asl X60Qx_21 = newString_0_sysvq0asl(((NI32)((*t_2).data_0.len_0 + X60Qx_20)));
      result_11 = X60Qx_21;
      if (0 < (*t_2).data_0.len_0){
        NI32 X60Qx_22 = len_4_sysvq0asl(result_11);
        NC8* X60Qx_23 = beginStore_0_sysvq0asl((&result_11), X60Qx_22, 0);
        copyMem_0_sysvq0asl(((void*)X60Qx_23), ((void*)(*t_2).data_0.p_0), (*t_2).data_0.len_0);
        NI32 X60Qx_24 = len_4_sysvq0asl(result_11);
        NC8* X60Qx_25 = beginStore_0_sysvq0asl((&result_11), X60Qx_24, (*t_2).data_0.len_0);
        NC8* X60Qx_26 = readRawData_0_sysvq0asl((&(*r_3).thisModule_0), 0);
        NI32 X60Qx_27 = len_4_sysvq0asl((*r_3).thisModule_0);
        copyMem_0_sysvq0asl(((void*)X60Qx_25), ((void*)X60Qx_26), X60Qx_27);
        endStore_0_sysvq0asl((&result_11));}}
    else {
      nimStrDestroy(result_11);
      string_0_sysvq0asl X60Qx_28 = newString_0_sysvq0asl((*t_2).data_0.len_0);
      result_11 = X60Qx_28;
      if (0 < (*t_2).data_0.len_0){
        NI32 X60Qx_29 = len_4_sysvq0asl(result_11);
        NC8* X60Qx_30 = beginStore_0_sysvq0asl((&result_11), X60Qx_29, 0);
        copyMem_0_sysvq0asl(((void*)X60Qx_30), ((void*)(*t_2).data_0.p_0), (*t_2).data_0.len_0);
        endStore_0_sysvq0asl((&result_11));}}}
  return result_11;}
string_0_sysvq0asl decodeComment_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_3){
  string_0_sysvq0asl result_12;
  nimStrWasMoved((&result_12));
  if ((*t_3).comment_0.len_0 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NU8 X60Qdesugar_11 = (*t_3).flags_0;
  NU64 X60Qdesugar_12 = ((NU)3);
  if ((!(((NU8)(X60Qdesugar_11 & ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_12 & 7u)))))) != 0u))){
    nimStrDestroy(result_12);
    string_0_sysvq0asl X60Qx_31 = newString_0_sysvq0asl((*t_3).comment_0.len_0);
    result_12 = X60Qx_31;
    NI32 X60Qx_32 = len_4_sysvq0asl(result_12);
    NC8* X60Qx_33 = beginStore_0_sysvq0asl((&result_12), X60Qx_32, 0);
    copyMem_0_sysvq0asl(((void*)X60Qx_33), ((void*)(*t_3).comment_0.p_0), (*t_3).comment_0.len_0);
    endStore_0_sysvq0asl((&result_12));
    return result_12;}
  nimStrDestroy(result_12);
  result_12 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NC8* p_9 = (*t_3).comment_0.p_0;
  NC8* sentinel_1 = ((NC8*)((NI32)(((NI32)p_9) + (*t_3).comment_0.len_0)));
  {
    while (((void*)p_9) < ((void*)sentinel_1)){
      if (p_9[0] == (NC8)'\\'){
        p_9 = ((NC8*)((NI32)(((NI32)p_9) + 1)));
        NC8 X60Qx_34 = decodeEscape_0_nif81dubp1((&p_9));
        add_1_sysvq0asl((&result_12), X60Qx_34);}
      else {
        add_1_sysvq0asl((&result_12), p_9[0]);
        p_9 = ((NC8*)((NI32)(((NI32)p_9) + 1)));}}}
  whileStmtLabel_0: ;
  return result_12;}
string_0_sysvq0asl decodeFilename_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_4){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  NU8 X60Qdesugar_13 = (*t_4).flags_0;
  NU64 X60Qdesugar_14 = ((NU)1);
  if (((NU8)(X60Qdesugar_13 & ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_14 & 7u)))))) != 0u){
    nimStrDestroy(result_13);
    result_13 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NC8* p_10 = (*t_4).filename_0.p_0;
    NC8* sentinel_2 = ((NC8*)((NI32)(((NI32)p_10) + (*t_4).filename_0.len_0)));
    {
      while (((void*)p_10) < ((void*)sentinel_2)){
        if (p_10[0] == (NC8)'\\'){
          p_10 = ((NC8*)((NI32)(((NI32)p_10) + 1)));
          NC8 X60Qx_35 = decodeEscape_0_nif81dubp1((&p_10));
          add_1_sysvq0asl((&result_13), X60Qx_35);}
        else {
          add_1_sysvq0asl((&result_13), p_10[0]);
          p_10 = ((NC8*)((NI32)(((NI32)p_10) + 1)));}}}
    whileStmtLabel_0: ;}
  else {
    nimStrDestroy(result_13);
    string_0_sysvq0asl X60Qx_36 = newString_0_sysvq0asl((*t_4).filename_0.len_0);
    result_13 = X60Qx_36;
    NI32 X60Qx_37 = len_4_sysvq0asl(result_13);
    NC8* X60Qx_38 = beginStore_0_sysvq0asl((&result_13), X60Qx_37, 0);
    copyMem_0_sysvq0asl(((void*)X60Qx_38), ((void*)(*t_4).filename_0.p_0), (*t_4).filename_0.len_0);
    endStore_0_sysvq0asl((&result_13));}
  return result_13;}
NF64 decodeFloat_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_5){
  NF64 result_14;
  result_14 = 0.0;
  if ((!((*t_5).tk_0 == 10))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qx_39 = toOpenArray_3_Inpmq9h_nif81dubp1((*t_5).data_0.p_0, 0, ((NI32)((*t_5).data_0.len_0 - 1)));
  NI32 res_0 = parseBiggestFloat_0_party5a2l1(X60Qx_39, (&result_14));
  if ((!(res_0 == (*t_5).data_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  return result_14;}
NU64 decodeUInt_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_6){
  NU64 result_15;
  result_15 = ((NU64)0);
  if ((!((*t_6).tk_0 == 9))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qx_40 = toOpenArray_3_Inpmq9h_nif81dubp1((*t_6).data_0.p_0, 0, ((NI32)((*t_6).data_0.len_0 - 1)));
  NI32 res_1 = parseBiggestUInt_0_party5a2l1(X60Qx_40, (&result_15));
  if ((!(res_1 == (*t_6).data_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  return result_15;}
NI64 decodeInt_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_7){
  NI64 result_16;
  result_16 = ((NI64)0);
  if ((!((*t_7).tk_0 == 8))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qx_41 = toOpenArray_3_Inpmq9h_nif81dubp1((*t_7).data_0.p_0, 0, ((NI32)((*t_7).data_0.len_0 - 1)));
  NI32 res_2 = parseBiggestInt_0_party5a2l1(X60Qx_41, (&result_16));
  if ((!(res_2 == (*t_7).data_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  return result_16;}
void handleNumber_0_nif81dubp1(Reader_0_nif81dubp1* r_4, ExpandedToken_0_nif81dubp1* result_1){
  NC8* p_11 = (*r_4).p_0;
  void* eof_2 = (*r_4).eof_0;
  NB8 X60Qx_0;
  if (((void*)p_11) < eof_2){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_15 = Digits_0_nif81dubp1;
    NU64 X60Qdesugar_16 = ((NU)p_11[0]);
    X60Qx_0 = (((NU8)(X60Qdesugar_15.a[((NU)(X60Qdesugar_16 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_16 & 7u)))))) != 0u);}
  else {
    X60Qx_0 = NIM_FALSE;}
  if (X60Qx_0){
    (*result_1).tk_0 = 8;
    {
      while (NIM_TRUE){
        NB8 X60Qx_1;
        if (((void*)p_11) < eof_2){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_17 = Digits_0_nif81dubp1;
          NU64 X60Qdesugar_18 = ((NU)p_11[0]);
          X60Qx_1 = (((NU8)(X60Qdesugar_17.a[((NU)(X60Qdesugar_18 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_18 & 7u)))))) != 0u);}
        else {
          X60Qx_1 = NIM_FALSE;}
        if (X60Qx_1){
          p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
          inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    NB8 X60Qx_42;
    if (((void*)p_11) < eof_2){
      X60Qx_42 = (p_11[0] == (NC8)'.');}
    else {
      X60Qx_42 = NIM_FALSE;}
    if (X60Qx_42){
      (*result_1).tk_0 = 10;
      p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
      inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));
      {
        while (NIM_TRUE){
          NB8 X60Qx_2;
          if (((void*)p_11) < eof_2){
            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_19 = Digits_0_nif81dubp1;
            NU64 X60Qdesugar_20 = ((NU)p_11[0]);
            X60Qx_2 = (((NU8)(X60Qdesugar_19.a[((NU)(X60Qdesugar_20 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_20 & 7u)))))) != 0u);}
          else {
            X60Qx_2 = NIM_FALSE;}
          if (X60Qx_2){
            p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
            inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    NB8 X60Qx_43;
    if (((void*)p_11) < eof_2){
      X60Qx_43 = (p_11[0] == (NC8)'E');}
    else {
      X60Qx_43 = NIM_FALSE;}
    if (X60Qx_43){
      (*result_1).tk_0 = 10;
      p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
      inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));
      if (((void*)p_11) < eof_2){
        NB8 X60Qx_44;
        if (p_11[0] == (NC8)'-'){
          X60Qx_44 = NIM_TRUE;}
        else {
          X60Qx_44 = (p_11[0] == (NC8)'+');}
        if (X60Qx_44){
          p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
          inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));}}
      {
        while (NIM_TRUE){
          NB8 X60Qx_3;
          if (((void*)p_11) < eof_2){
            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_21 = Digits_0_nif81dubp1;
            NU64 X60Qdesugar_22 = ((NU)p_11[0]);
            X60Qx_3 = (((NU8)(X60Qdesugar_21.a[((NU)(X60Qdesugar_22 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_22 & 7u)))))) != 0u);}
          else {
            X60Qx_3 = NIM_FALSE;}
          if (X60Qx_3){
            p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));
            inc_1_I6wjjge_aow2h993l1((&(*result_1).data_0.len_0));}
          else {
            break;}}}
      whileStmtLabel_2: ;}
    NB8 X60Qx_45;
    if (((void*)p_11) < eof_2){
      X60Qx_45 = (p_11[0] == (NC8)'u');}
    else {
      X60Qx_45 = NIM_FALSE;}
    if (X60Qx_45){
      (*result_1).tk_0 = 9;
      p_11 = ((NC8*)((NI32)(((NI32)p_11) + 1)));}}
  (*r_4).p_0 = p_11;}
static inline NI32 decodeB62_0_nif81dubp1(NC8 c_0){
  NI32 result_17;
  if (c_0 <= (NC8)'9'){
    result_17 = ((NI32)(((NI32)c_0) - ((NI32)(NC8)'0')));}
  else {
    if (c_0 <= (NC8)'Z'){
      result_17 = ((NI32)(((NI32)(((NI32)c_0) - ((NI32)(NC8)'A'))) + 10));}
    else {
      result_17 = ((NI32)(((NI32)(((NI32)c_0) - ((NI32)(NC8)'a'))) + 36));}}
  return result_17;}
void handleLineInfo_0_nif81dubp1(Reader_0_nif81dubp1* r_5, ExpandedToken_0_nif81dubp1* result_2){
  NC8* p_12 = (*r_5).p_0;
  void* eof_3 = (*r_5).eof_0;
  NI32 col_1 = 0;
  NB8 negative_1 = NIM_FALSE;
  NB8 X60Qx_46;
  if (((void*)p_12) < eof_3){
    X60Qx_46 = (p_12[0] == (NC8)'~');}
  else {
    X60Qx_46 = NIM_FALSE;}
  if (X60Qx_46){
    p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));
    negative_1 = NIM_TRUE;}
  {
    while (NIM_TRUE){
      NB8 X60Qx_4;
      if (((void*)p_12) < eof_3){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_23 = B62Digits_0_nif81dubp1;
        NU64 X60Qdesugar_24 = ((NU)p_12[0]);
        X60Qx_4 = (((NU8)(X60Qdesugar_23.a[((NU)(X60Qdesugar_24 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_24 & 7u)))))) != 0u);}
      else {
        X60Qx_4 = NIM_FALSE;}
      if (X60Qx_4){
        NI32 c_3 = decodeB62_0_nif81dubp1(p_12[0]);
        if (((NI32)(((NI32)(((NI32)(-2147483647 -1)) + c_3)) / 62)) <= col_1){
          col_1 = ((NI32)(((NI32)(col_1 * 62)) - c_3));}
        else {
          integerOutOfRangeError_0_nif81dubp1();}
        p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if ((!negative_1)){
    if (col_1 == ((NI32)(-2147483647 -1))){
      integerOutOfRangeError_0_nif81dubp1();}
    col_1 = ((NI32)-col_1);}
  NI32 line_1 = 0;
  negative_1 = NIM_FALSE;
  NB8 X60Qx_47;
  if (((void*)p_12) < eof_3){
    X60Qx_47 = (p_12[0] == (NC8)',');}
  else {
    X60Qx_47 = NIM_FALSE;}
  if (X60Qx_47){
    p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));
    NB8 X60Qx_48;
    if (((void*)p_12) < eof_3){
      X60Qx_48 = (p_12[0] == (NC8)'~');}
    else {
      X60Qx_48 = NIM_FALSE;}
    if (X60Qx_48){
      p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));
      negative_1 = NIM_TRUE;}
    {
      while (NIM_TRUE){
        NB8 X60Qx_5;
        if (((void*)p_12) < eof_3){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_25 = B62Digits_0_nif81dubp1;
          NU64 X60Qdesugar_26 = ((NU)p_12[0]);
          X60Qx_5 = (((NU8)(X60Qdesugar_25.a[((NU)(X60Qdesugar_26 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_26 & 7u)))))) != 0u);}
        else {
          X60Qx_5 = NIM_FALSE;}
        if (X60Qx_5){
          NI32 c_4 = decodeB62_0_nif81dubp1(p_12[0]);
          if (((NI32)(((NI32)(((NI32)(-2147483647 -1)) + c_4)) / 62)) <= line_1){
            line_1 = ((NI32)(((NI32)(line_1 * 62)) - c_4));}
          else {
            integerOutOfRangeError_0_nif81dubp1();}
          p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    if ((!negative_1)){
      if (line_1 == ((NI32)(-2147483647 -1))){
        integerOutOfRangeError_0_nif81dubp1();}
      line_1 = ((NI32)-line_1);}}
  (*result_2).pos_0 = (FilePos_0_nif81dubp1){
    .col_0 = ((NI32)col_1), .line_0 = ((NI32)line_1)}
  ;
  NB8 X60Qx_49;
  if (((void*)p_12) < eof_3){
    X60Qx_49 = (p_12[0] == (NC8)',');}
  else {
    X60Qx_49 = NIM_FALSE;}
  if (X60Qx_49){
    p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));
    (*result_2).filename_0.p_0 = p_12;
    {
      while (((void*)p_12) < eof_3){
        NC8 ch_1 = p_12[0];
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_27 = ControlCharsOrWhite_0_nif81dubp1;
        NU64 X60Qdesugar_28 = ((NU)ch_1);
        if (((NU8)(X60Qdesugar_27.a[((NU)(X60Qdesugar_28 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_28 & 7u)))))) != 0u){
          goto whileStmtLabel_2;}
        else {
          if (ch_1 == (NC8)'\\'){
            NU8* X60Qdesugar_29 = (&(*result_2).flags_0);
            TokenFlag_0_nif81dubp1 X60Qdesugar_30 = 1;
            (*X60Qdesugar_29) = ((NU8)((*X60Qdesugar_29) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_30 & 7))))));}
          else {
            if (ch_1 == (NC8)'\012'){
              inc_1_I6wjjge_aow2h993l1((&(*r_5).line_0));}}}
        inc_1_I6wjjge_aow2h993l1((&(*result_2).filename_0.len_0));
        p_12 = ((NC8*)((NI32)(((NI32)p_12) + 1)));}}
    whileStmtLabel_2: ;}
  (*r_5).p_0 = p_12;}
static inline void handleSuffix_0_nif81dubp1(Reader_0_nif81dubp1* r_6, ExpandedToken_0_nif81dubp1* result_3){
  if (((void*)(*r_6).p_0) < (*r_6).eof_0){
    NC8 ch_2 = (*r_6).p_0[0];
    if (ch_2 == (NC8)'@'){
      (*r_6).p_0 = ((NC8*)((NI32)(((NI32)(*r_6).p_0) + 1)));
      handleLineInfo_0_nif81dubp1(r_6, result_3);}
    else {
      if (ch_2 == (NC8)'~'){
        handleLineInfo_0_nif81dubp1(r_6, result_3);}}}
  NB8 X60Qx_50;
  if (((void*)(*r_6).p_0) < (*r_6).eof_0){
    X60Qx_50 = ((*r_6).p_0[0] == (NC8)'#');}
  else {
    X60Qx_50 = NIM_FALSE;}
  if (X60Qx_50){
    (*r_6).p_0 = ((NC8*)((NI32)(((NI32)(*r_6).p_0) + 1)));
    captureComment_0_nif81dubp1(r_6, result_3);}}
void next_0_nif81dubp1(Reader_0_nif81dubp1* r_7, ExpandedToken_0_nif81dubp1* result_4){
  (*result_4) = (ExpandedToken_0_nif81dubp1){
    .tk_0 = 0, .flags_0 = 0u, .kind_0 = ((NU16)0u), .data_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .pos_0 = (FilePos_0_nif81dubp1){
      .col_0 = ((NI32)0), .line_0 = ((NI32)0)}
    , .filename_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .comment_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}}
  ;
  skipWhitespace_0_nif81dubp1(r_7);
  if ((*r_7).eof_0 <= ((void*)(*r_7).p_0)){
    (*result_4).tk_0 = 1;
    return;}
  switch ((*r_7).p_0[0]){
    case (NC8)'(':
    {
      (*result_4).tk_0 = 11;
      NC8* p_13 = (*r_7).p_0;
      void* eof_4 = (*r_7).eof_0;
      p_13 = ((NC8*)((NI32)(((NI32)p_13) + 1)));
      (*result_4).data_0.p_0 = p_13;
      (*result_4).data_0.len_0 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_6;
          if (((void*)p_13) < eof_4){
            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_31 = ControlCharsOrWhite_0_nif81dubp1;
            NU64 X60Qdesugar_32 = ((NU)p_13[0]);
            X60Qx_6 = (!(((NU8)(X60Qdesugar_31.a[((NU)(X60Qdesugar_32 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_32 & 7u)))))) != 0u));}
          else {
            X60Qx_6 = NIM_FALSE;}
          if (X60Qx_6){
            inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
            p_13 = ((NC8*)((NI32)(((NI32)p_13) + 1)));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      (*r_7).p_0 = p_13;
      handleSuffix_0_nif81dubp1(r_7, result_4);}
    break;
    case (NC8)')':
    {
      (*result_4).tk_0 = 12;
      (*result_4).data_0.p_0 = (*r_7).p_0;
      inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
      (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));}
    break;
    case (NC8)'.':
    {
      (*result_4).tk_0 = 2;
      (*result_4).data_0.p_0 = (*r_7).p_0;
      inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
      (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
      handleSuffix_0_nif81dubp1(r_7, result_4);}
    break;
    case (NC8)'\"':
    {
      NC8* p_14 = (*r_7).p_0;
      void* eof_5 = (*r_7).eof_0;
      p_14 = ((NC8*)((NI32)(((NI32)p_14) + 1)));
      (*result_4).tk_0 = 6;
      (*result_4).data_0.p_0 = p_14;
      (*result_4).data_0.len_0 = 0;
      {
        while (((void*)p_14) < eof_5){
          NC8 ch_4 = p_14[0];
          if (ch_4 == (NC8)'\"'){
            p_14 = ((NC8*)((NI32)(((NI32)p_14) + 1)));
            goto whileStmtLabel_1;}
          else {
            if (ch_4 == (NC8)'\\'){
              NU8* X60Qdesugar_33 = (&(*result_4).flags_0);
              TokenFlag_0_nif81dubp1 X60Qdesugar_34 = 0;
              (*X60Qdesugar_33) = ((NU8)((*X60Qdesugar_33) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_34 & 7))))));}
            else {
              if (ch_4 == (NC8)'\012'){
                inc_1_I6wjjge_aow2h993l1((&(*r_7).line_0));}}}
          inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
          p_14 = ((NC8*)((NI32)(((NI32)p_14) + 1)));}}
      whileStmtLabel_1: ;
      (*r_7).p_0 = p_14;
      handleSuffix_0_nif81dubp1(r_7, result_4);}
    break;
    case (NC8)'\'':
    {
      (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
      (*result_4).data_0.p_0 = (*r_7).p_0;
      if ((*r_7).p_0[0] == (NC8)'\\'){
        NU8* X60Qdesugar_35 = (&(*result_4).flags_0);
        TokenFlag_0_nif81dubp1 X60Qdesugar_36 = 0;
        (*X60Qdesugar_35) = ((NU8)((*X60Qdesugar_35) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_36 & 7))))));
        (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
        NB8 X60Qx_7;
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_37 = HexChars_0_nif81dubp1;
        NU64 X60Qdesugar_38 = ((NU)(*r_7).p_0[0]);
        if (((NU8)(X60Qdesugar_37.a[((NU)(X60Qdesugar_38 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_38 & 7u)))))) != 0u){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_39 = HexChars_0_nif81dubp1;
          NU64 X60Qdesugar_40 = ((NU)(*r_7).p_0[1]);
          X60Qx_7 = (((NU8)(X60Qdesugar_39.a[((NU)(X60Qdesugar_40 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_40 & 7u)))))) != 0u);}
        else {
          X60Qx_7 = NIM_FALSE;}
        if (X60Qx_7){
          (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 2)));
          if ((*r_7).p_0[0] == (NC8)'\''){
            (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
            (*result_4).tk_0 = 7;}}}
      else {
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_41 = ControlChars_0_nif81dubp1;
        NU64 X60Qdesugar_42 = ((NU)(*r_7).p_0[0]);
        if (((NU8)(X60Qdesugar_41.a[((NU)(X60Qdesugar_42 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_42 & 7u)))))) != 0u){
          string_0_sysvq0asl X60Qx_51 = (string_0_sysvq0asl){
            .bytes_0 = 1701145598u, .more_0 = (&strlit_0_I10426215507333234367_nif81dubp1)}
          ;}
        else {
          (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
          if ((*r_7).p_0[0] == (NC8)'\''){
            (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
            (*result_4).tk_0 = 7;}}}
      if ((*result_4).tk_0 == 7){
        handleSuffix_0_nif81dubp1(r_7, result_4);}}
    break;
    case (NC8)':':
    {
      NC8* p_15 = (*r_7).p_0;
      void* eof_6 = (*r_7).eof_0;
      p_15 = ((NC8*)((NI32)(((NI32)p_15) + 1)));
      (*result_4).data_0.p_0 = p_15;
      {
        while (NIM_TRUE){
          NB8 X60Qx_8;
          if (((void*)p_15) < eof_6){
            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_43 = ControlCharsOrWhite_0_nif81dubp1;
            NU64 X60Qdesugar_44 = ((NU)p_15[0]);
            X60Qx_8 = (!(((NU8)(X60Qdesugar_43.a[((NU)(X60Qdesugar_44 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_44 & 7u)))))) != 0u));}
          else {
            X60Qx_8 = NIM_FALSE;}
          if (X60Qx_8){
            if (p_15[0] == (NC8)'\\'){
              NU8* X60Qdesugar_45 = (&(*result_4).flags_0);
              TokenFlag_0_nif81dubp1 X60Qdesugar_46 = 0;
              (*X60Qdesugar_45) = ((NU8)((*X60Qdesugar_45) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_46 & 7))))));}
            inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
            p_15 = ((NC8*)((NI32)(((NI32)p_15) + 1)));}
          else {
            break;}}}
      whileStmtLabel_2: ;
      (*r_7).p_0 = p_15;
      if (0 < (*result_4).data_0.len_0){
        (*result_4).tk_0 = 5;
        if ((*result_4).data_0.p_0[((NI32)((*result_4).data_0.len_0 - 1))] == (NC8)'.'){
          NU8* X60Qdesugar_47 = (&(*result_4).flags_0);
          TokenFlag_0_nif81dubp1 X60Qdesugar_48 = 2;
          (*X60Qdesugar_47) = ((NU8)((*X60Qdesugar_47) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_48 & 7))))));}
        handleSuffix_0_nif81dubp1(r_7, result_4);}}
    break;
    case (NC8)'-':
    {
      (*result_4).data_0.p_0 = (*r_7).p_0;
      (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));
      inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
      handleNumber_0_nif81dubp1(r_7, result_4);
      handleSuffix_0_nif81dubp1(r_7, result_4);}
    break;
    case (NC8)'0' ... (NC8)'9':
    {
      NC8* p_16 = (*r_7).p_0;
      void* eof_7 = (*r_7).eof_0;
      (*result_4).data_0.p_0 = p_16;
      (*result_4).data_0.len_0 = 0;
      (*r_7).p_0 = p_16;
      handleNumber_0_nif81dubp1(r_7, result_4);
      handleSuffix_0_nif81dubp1(r_7, result_4);}
    break;
    default:
    {
      NC8* p_17 = (*r_7).p_0;
      void* eof_8 = (*r_7).eof_0;
      (*result_4).data_0.p_0 = p_17;
      NB8 hasDot_1 = NIM_FALSE;
      {
        while (NIM_TRUE){
          NB8 X60Qx_9;
          if (((void*)p_17) < eof_8){
            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_49 = ControlCharsOrWhite_0_nif81dubp1;
            NU64 X60Qdesugar_50 = ((NU)p_17[0]);
            X60Qx_9 = (!(((NU8)(X60Qdesugar_49.a[((NU)(X60Qdesugar_50 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_50 & 7u)))))) != 0u));}
          else {
            X60Qx_9 = NIM_FALSE;}
          if (X60Qx_9){
            if (p_17[0] == (NC8)'\\'){
              NU8* X60Qdesugar_51 = (&(*result_4).flags_0);
              TokenFlag_0_nif81dubp1 X60Qdesugar_52 = 0;
              (*X60Qdesugar_51) = ((NU8)((*X60Qdesugar_51) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_52 & 7))))));}
            else {
              if (p_17[0] == (NC8)'.'){
                hasDot_1 = NIM_TRUE;}}
            inc_1_I6wjjge_aow2h993l1((&(*result_4).data_0.len_0));
            p_17 = ((NC8*)((NI32)(((NI32)p_17) + 1)));}
          else {
            break;}}}
      whileStmtLabel_3: ;
      (*r_7).p_0 = p_17;
      if (0 < (*result_4).data_0.len_0){
        if (hasDot_1){
          (*result_4).tk_0 = 4;
          if ((*result_4).data_0.p_0[((NI32)((*result_4).data_0.len_0 - 1))] == (NC8)'.'){
            NU8* X60Qdesugar_53 = (&(*result_4).flags_0);
            TokenFlag_0_nif81dubp1 X60Qdesugar_54 = 2;
            (*X60Qdesugar_53) = ((NU8)((*X60Qdesugar_53) | ((NU8)(((NU8)1) << ((NU)(X60Qdesugar_54 & 7))))));}}
        else {
          (*result_4).tk_0 = 3;}
        handleSuffix_0_nif81dubp1(r_7, result_4);}
      else {
        (*result_4).data_0.p_0 = (*r_7).p_0;
        (*result_4).data_0.len_0 = 1;
        (*r_7).p_0 = ((NC8*)((NI32)(((NI32)(*r_7).p_0) + 1)));}}
    break;}}
NB8 startsWith_0_nif81dubp1(Reader_0_nif81dubp1* r_9, string_0_sysvq0asl prefix_0){
  NB8 result_20;
  NI32 prefixLen_0 = len_4_sysvq0asl(prefix_0);
  NI32 i_0 = 0;
  NC8* p_18 = (*r_9).p_0;
  {
    while (NIM_TRUE){
      if (prefixLen_0 <= i_0){
        return NIM_TRUE;}
      NB8 X60Qx_52;
      if ((*r_9).eof_0 <= ((void*)p_18)){
        X60Qx_52 = NIM_TRUE;}
      else {
        NC8 X60Qx_53 = getQ_9_sysvq0asl(prefix_0, i_0);
        X60Qx_52 = (!(p_18[0] == X60Qx_53));}
      if (X60Qx_52){
        return NIM_FALSE;}
      p_18 = ((NC8*)((NI32)(((NI32)p_18) + 1)));
      inc_1_I6wjjge_aow2h993l1((&i_0));}}
  whileStmtLabel_0: ;
  return NIM_FALSE;
  return result_20;}
void readDirectives_0_nif81dubp1(Reader_0_nif81dubp1* r_10){
  ExpandedToken_0_nif81dubp1 tok_0 = (ExpandedToken_0_nif81dubp1){
    .tk_0 = 0, .flags_0 = 0u, .kind_0 = ((NU16)0u), .data_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .pos_0 = (FilePos_0_nif81dubp1){
      .col_0 = ((NI32)0), .line_0 = ((NI32)0)}
    , .filename_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .comment_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}}
  ;
  {
    while (NIM_TRUE){
      skipWhitespace_0_nif81dubp1(r_10);
      NB8 X60Qx_54 = startsWith_0_nif81dubp1((&(*r_10)), (string_0_sysvq0asl){
        .bytes_0 = 3024898u, .more_0 = NIM_NIL}
      );
      if (X60Qx_54){
        next_0_nif81dubp1(r_10, (&tok_0));
        if ((!(tok_0.tk_0 == 11))){
          write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
            .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
          );
          write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          );
          write_7_syn1lfpjv(stdout, (NC8)'\012');
          quit_0_syn1lfpjv(1);}
        NB8 X60Qx_55 = eqQ_1_strdllfw2(tok_0.data_0, (string_0_sysvq0asl){
          .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I397779028761265335_nif81dubp1)}
        );
        if (X60Qx_55){
          next_0_nif81dubp1(r_10, (&tok_0));
          if (tok_0.tk_0 == 8){
            NI64 X60Qx_56 = decodeInt_0_nif81dubp1((&tok_0));
            (*r_10).indexAt_0 = ((NI32)X60Qx_56);}}
        else {
          NB8 X60Qx_57 = eqQ_1_strdllfw2(tok_0.data_0, (string_0_sysvq0asl){
            .bytes_0 = 1853173502u, .more_0 = (&strlit_0_I12979507887005580180_nif81dubp1)}
          );
          if (X60Qx_57){
            next_0_nif81dubp1(r_10, (&tok_0));
            if (tok_0.tk_0 == 4){
              (*r_10).unusedNameHint_0 = tok_0;}}}
        NI32 nested_0 = 0;
        {
          while (NIM_TRUE){
            next_0_nif81dubp1(r_10, (&tok_0));
            switch (tok_0.tk_0){
              case 11:
              {
                inc_1_I6wjjge_aow2h993l1((&nested_0));}
              break;
              case 12:
              {
                if (nested_0 == 0){
                  goto whileStmtLabel_1;}
                dec_1_I0nzoz91_aow7lb5cq1((&nested_0));}
              break;
              case 1:
              {
                goto whileStmtLabel_1;}
              break;
              default:
              {
                }
              break;}}}
        whileStmtLabel_1: ;}
      else {
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;}
string_0_sysvq0asl extractModuleSuffix_0_nif81dubp1(string_0_sysvq0asl filename_0){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  nimStrDestroy(result_21);
  result_21 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 skip_0 = NIM_FALSE;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_0 = toOpenArray_2_sysvq0asl((&filename_0));
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_58 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_58){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_59;
            if ((*X60Qii_2) == (NC8)'/'){
              X60Qx_59 = NIM_TRUE;}
            else {
              X60Qx_59 = ((*X60Qii_2) == (NC8)'\\');}
            if (X60Qx_59){
              setLen_1_sysvq0asl((&result_21), 0);
              skip_0 = NIM_FALSE;}
            else {
              if ((*X60Qii_2) == (NC8)'.'){
                skip_0 = NIM_TRUE;}
              else {
                if ((!skip_0)){
                  add_1_sysvq0asl((&result_21), (*X60Qii_2));}}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_21;}
Reader_0_nif81dubp1 open_0_nif81dubp1(string_0_sysvq0asl filename_1){
  Reader_0_nif81dubp1 result_22;
  eQwasmovedQ_SX52eader0nif81dubp1_0_nif81dubp1((&result_22));
  VfsBlob_0_vfsc9jn7 X60Qx_10;
  VfsBlob_0_vfsc9jn7 X60Qx_60 = vfsOpenMmap_0_vfsc9jn7(filename_1);
  X60Qx_10 = X60Qx_60;
  if (NIM_FALSE){
    X60Qexlab_0: ;
    string_0_sysvq0asl X60Qtmp_1 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1917148158u, .more_0 = (&strlit_0_I18095058983225952061_nif81dubp1)}
    , filename_1);
    quit_1_syn1lfpjv(X60Qtmp_1);
    nimStrDestroy(X60Qtmp_1);}
  VfsBlob_0_vfsc9jn7 f_0 = X60Qx_10;
  eQdestroyQ_SX52eader0nif81dubp1_0_nif81dubp1((&result_22));
  string_0_sysvq0asl X60Qx_61 = extractModuleSuffix_0_nif81dubp1(filename_1);
  result_22 = (Reader_0_nif81dubp1){
    .p_0 = NIM_NIL, .eof_0 = NIM_NIL, .f_0 = f_0, .buf_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .thisModule_0 = X60Qx_61, .line_0 = ((NI32)0), .indexAt_0 = ((NI32)0), .unusedNameHint_0 = (ExpandedToken_0_nif81dubp1){
      .tk_0 = 0, .flags_0 = 0u, .kind_0 = ((NU16)0u), .data_0 = (StringView_0_strdllfw2){
        .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
      , .pos_0 = (FilePos_0_nif81dubp1){
        .col_0 = ((NI32)0), .line_0 = ((NI32)0)}
      , .filename_0 = (StringView_0_strdllfw2){
        .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
      , .comment_0 = (StringView_0_strdllfw2){
        .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}}}
  ;
  result_22.p_0 = ((NC8*)result_22.f_0.data_0);
  result_22.eof_0 = ((void*)((NC8*)((NI32)(((NI32)result_22.p_0) + result_22.f_0.size_0))));
  readDirectives_0_nif81dubp1((&result_22));
  return result_22;}
DirectivesResult_0_nif81dubp1 processDirectives_0_nif81dubp1(Reader_0_nif81dubp1* r_11){
  DirectivesResult_0_nif81dubp1 result_24;
  result_24 = 2;
  return result_24;}
static inline NI32 offset_0_nif81dubp1(Reader_0_nif81dubp1* r_13){
  NI32 result_26;
  result_26 = ((NI32)(((NI32)(*r_13).p_0) - ((NI32)((NC8*)(*r_13).f_0.data_0))));
  return result_26;}
static inline void jumpTo_0_nif81dubp1(Reader_0_nif81dubp1* r_14, NI32 offset_0){
  (*r_14).p_0 = ((NC8*)((NI32)(((NI32)((NC8*)(*r_14).f_0.data_0)) + offset_0)));
  NB8 X60Qx_64;
  if ((*r_14).f_0.data_0 <= ((void*)(*r_14).p_0)){
    X60Qx_64 = (((void*)((void*)(*r_14).p_0)) < (*r_14).eof_0);}
  else {
    X60Qx_64 = NIM_FALSE;}
  if ((!X60Qx_64)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}}
NI32 indexStartsAt_0_nif81dubp1(Reader_0_nif81dubp1* r_15){
  NI32 result_27;
  result_27 = (*r_15).indexAt_0;
  return result_27;}
openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_3_Inpmq9h_nif81dubp1(NC8* x_4, NI32 first_1, NI32 last_1){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_29;
  result_29 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = ((NC8*)((NU32)(((NU32)x_4) + ((NU32)((NI32)(first_1 * sizeof(NC8))))))), .len_0 = ((NI32)(((NI32)(last_1 - first_1)) + 1))}
  ;
  return result_29;}
void eQdestroyQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0){
  nimStrDestroy((*dest_0).thisModule_0);
  nimStrDestroy((*dest_0).buf_0);}
void eQwasmovedQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0){
  nimStrWasMoved((&(*dest_0).buf_0));
  nimStrWasMoved((&(*dest_0).thisModule_0));}
void integerOutOfRangeError_0_nif81dubp1(void){
  quit_1_syn1lfpjv((string_0_sysvq0asl){
    .bytes_0 = 1918980350u, .more_0 = (&strlit_0_I7773138664102327703_nif81dubp1)}
  );}
void X60Qini_0_nif81dubp1(void){
  if (X60QiniGuard_0_nif81dubp1){
    return;}
  X60QiniGuard_0_nif81dubp1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_memlzdyby();
  X60Qini_0_party5a2l1();
  X60Qini_0_assy765wm();
  X60Qini_0_strdllfw2();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_syn1lfpjv();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_48){
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_48).bytes_0))))){
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_48).bytes_0)) + 1u)))), ((void*)(&(*(*s_48).more_0).data_0[0])), ((NI32)3));}}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29){
  NI32 result_100;
  result_100 = a_29.len_0;
  return result_100;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_2313;
  if (0 <= idx_6){
    X60Qx_2313 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_2313 = NIM_FALSE;}
  if ((!X60Qx_2313)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_101;
  result_101 = (&x_12.a_0[idx_6]);
  return result_101;}
static inline VfsBlob_0_vfsc9jn7 vfsOpenMmap_0_vfsc9jn7(string_0_sysvq0asl path_0){
  VfsBlob_0_vfsc9jn7 result_13;
  VfsBlob_0_vfsc9jn7 X60Qx_15 = openMmapRelay_0_vfsc9jn7(path_0);
  result_13 = X60Qx_15;
  return result_13;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
