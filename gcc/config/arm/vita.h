/* vita.h - Custom GCC configuration for arm-vita-eabi */


/* Default to little-endian */
#ifndef TARGET_ENDIAN_DEFAULT
#define TARGET_ENDIAN_DEFAULT 0
#endif

/* __vita__ preprocessor macro */
#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()                \
  do {                                          \
    builtin_define ("__vita__");                \
    builtin_define_std ("vita");                \
    builtin_define ("__VITA__");                \
    builtin_define_std ("VITA");                \
    builtin_define ("__psp2__");                \
    builtin_define_std ("psp2");                \
  } while (0)

/* Default: -fno-short-enums */
#undef  ARM_DEFAULT_SHORT_ENUMS
#define ARM_DEFAULT_SHORT_ENUMS false

/* Default: signed char */
#undef  DEFAULT_SIGNED_CHAR
#define DEFAULT_SIGNED_CHAR 1

/* Default: short wchar (2 bytes) */
#undef  WCHAR_TYPE
#define WCHAR_TYPE "short unsigned int"
#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 16

/* Vita-specific library spec */
#undef  LIB_SPEC
#define LIB_SPEC "%{!shared:%{g*:-lg} \
  %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}} \
  %{pthread:--whole-archive -lpthread --no-whole-archive} \
  -lSceRtc_stub -lSceSysmem_stub -lSceKernelThreadMgr_stub \
  -lSceKernelModulemgr_stub -lSceIofilemgr_stub -lSceProcessmgr_stub \
  -lSceLibKernel_stub -lSceNet_stub -lSceNetCtl_stub -lSceSysmodule_stub"

