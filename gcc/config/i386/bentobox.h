/* Useful if you wish to make target-specific GCC changes. */
#undef TARGET_BENTOBOX
#define TARGET_BENTOBOX 1

/* Default arguments you want when running your
   i686-myos-gcc/x86_64-myos-gcc toolchain */
#undef LIB_SPEC
#define LIB_SPEC "-lc" /* link against C standard library */

/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: %{static-pie|pie|!no-pie:Scrt1.o%s;:crt1.o%s}} crti.o%s %{shared|static-pie|pie|!no-pie:crtbeginS.o%s;:crtbegin.o%s}"

/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "%{shared|static-pie|pie|!no-pie:crtendS.o%s;:crtend.o%s} crtn.o%s"

#define GNU_USER_LINK_EMULATION32 "elf_i386"
#define GNU_USER_LINK_EMULATION64 "elf_x86_64"
#define GNU_USER_LINK_EMULATIONX32 "elf32_x86_64"

#define GNU_USER_DYNAMIC_LINKER32 "/does_not_exist"
#define GNU_USER_DYNAMIC_LINKER64 "/usr/lib/ld.so"
#define GNU_USER_DYNAMIC_LINKERX32 "/does_not_exist"

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__bentobox__");      \
    builtin_define ("__unix__");      \
    builtin_assert ("system=bentobox");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);
