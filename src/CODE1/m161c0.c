/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
char B0003892f_eu[89];
struct find_t B00038904_eu;
/* BSS end */
/* Module: FUN_000161c0, FUN_000161d0, FUN_00016200, FUN_00016220, FUN_0001624c, FUN_00016270, FUN_0001627c, FUN_000162a8, FUN_000162c0, FUN_000162d8, FUN_000162f0, FUN_00016304, FUN_00016320, FUN_0001633c, FUN_00016358, FUN_000163a4, FUN_000163b8, FUN_000163d8, FUN_000163f4, FUN_0001640c, FUN_00016424, FUN_00016490 */
#include "vmode.h"
#define DAT_000323d7 (VID_000323d4.w)
#include <dos.h>
#include <io.h>
#include <direct.h>
#include <ctype.h>
/* ---- from build/var/mod/parts/p161c0.c */
extern unsigned char DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_000161c0 @ 000161c0: BIOS timer tick count (0x46c) */
int FUN_000161c0(void) { return *(int *)0x46c; }

/* ---- from build/var/mod/parts/p161d0.c */
/* FUN_000161d0 @ 000161d0: print the string s through DOS (int 21h, AH=9): '$' inside it becomes '*', the string is
   terminated with '$' for the call and restored afterwards. The load of s is coded as bytes in the pragma (the
   original has the 32-bit displacement form, which the pragma assembler does not produce from "mov edx, [ebp+8]") */
void dos_print(void);
#pragma aux dos_print = 0x8b 0x95 0x08 0x00 0x00 0x00 "mov ah, 9" "int 21h" modify [eax edx];
void FUN_000161d0(char *s)
{
    char *p;
    p = s;
    while (*p) { if (*p == '$') *p = '*'; p++; }
    *p = '$';
    dos_print();
    *p = 0;
}

/* ---- from build/var/mod/parts/p16200.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_00016200 @ 00016200 */
int FUN_00016200(int a, unsigned short b) { return access((char *)a, b) == 0; }

/* ---- from build/var/mod/parts/p16220.c */
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern struct find_t B00038904_eu;
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
/* FUN_00016220 @ 00016220 */
char *FUN_00016220(int a, unsigned short b) { if (_dos_findfirst((char *)a, b, &B00038904_eu)) return 0; return B00038904_eu.name; }

/* ---- from build/var/mod/parts/p1624c.c */
extern short *DAT_00032a9c; extern unsigned short **B00038988_eu;
extern void FUN_000185d4(int, int, int, int, int), FUN_0001864c(int, int, int, int, int), FUN_0001a010(int, int, int), FUN_0001a2b0(int, int);
extern unsigned short **FUN_0001954c(int, int);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_0001624c @ 0001624c */
char *FUN_0001624c(void) { if (_dos_findnext(&B00038904_eu)) return 0; return B00038904_eu.name; }

/* ---- from build/var/mod/parts/p16270.c */
extern unsigned char DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00016270 @ 00016270 */
#define B00038919_eu (B00038904_eu.attrib) /* STANDIN: the attribute byte of the find record carries a name of its own (0x38919) */
unsigned char FUN_00016270(void) { return B00038919_eu; }

/* ---- from build/var/mod/parts/p1627c.c */
/* FUN_0001627c */

long FUN_0001627c(char *path) { if (!_dos_findfirst(path, 0, &B00038904_eu)) return B00038904_eu.size; return -1; }

/* ---- from build/var/mod/parts/p162a8.c */
/* FUN_000162a8 */
int open(const char *, int, ...);
int FUN_000162a8(char *name) { return open(name, 0x200); }

/* ---- from build/var/mod/parts/p162c0.c */
/* FUN_000162c0 */
int open(const char *, int, ...);
int FUN_000162c0(char *name) { return open(name, 0x202); }

/* ---- from build/var/mod/parts/p162d8.c */
/* FUN_000162d8 */
int creat(const char *, int);
int FUN_000162d8(char *name) { return creat(name, 0x180); }

/* ---- from build/var/mod/parts/p162f0.c */
/* FUN_000162f0 @ 000162f0: close file fd */
int close(int);
void FUN_000162f0(int fd) { close(fd); }

/* ---- from build/var/mod/parts/p16304.c */
/* FUN_00016304 */
int read(int, void *, unsigned);
int FUN_00016304(void *buf, unsigned n, int fd) { return read(fd, buf, n); }

/* ---- from build/var/mod/parts/p16320.c */
/* FUN_00016320 */
extern int FUN_0001d686(int, void *, unsigned);
int FUN_00016320(void *buf, unsigned n, int fd) { return write(fd, buf, n); }

/* ---- from build/var/mod/parts/p1633c.c */
/* FUN_0001633c */
extern int FUN_0001d85f(int, int, int);
int FUN_0001633c(int pos, int how, int fd) { return lseek(fd, pos, how); }

/* ---- from build/var/mod/parts/p16358.c */
/* FUN_00016358 */
extern void FUN_0001633c(int, int, int), FUN_00016304(void *, int, int);
void FUN_00016358(int k, int f) { volatile int v; FUN_0001633c(k * 4 + 4, 0, f); FUN_00016304((void *)&v, 4, f); FUN_0001633c(v, 0, f); }

/* ---- from build/var/mod/parts/p163a4.c */
/* FUN_000163a4 */
int unlink(const char *);
void FUN_000163a4(char *s) { unlink(s); }

/* ---- from build/var/mod/parts/p163b8.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_000163b8 @ 000163b8 */
int FUN_000163b8(int a) { int v; _dos_setdrive(a, (unsigned *)&v); return v; }

/* ---- from build/var/mod/parts/p163d8.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_000163d8 @ 000163d8 */
int FUN_000163d8(void) { int v; _dos_getdrive((unsigned *)&v); return v; }

/* ---- from build/var/mod/parts/p163f4.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_000163f4 @ 000163f4 */
void FUN_000163f4(void) { FUN_000163b8(FUN_000163d8()); }

/* ---- from build/var/mod/parts/p1640c.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_0001640c @ 0001640c */
void FUN_0001640c(void) { getcwd(B0003892f_eu, 0x50); }

/* ---- from build/var/mod/parts/p16424.c */
struct CB { char b[0x18]; };
extern struct CB DAT_0003240c[]; extern int DAT_0003246c;
extern void FUN_0001da18(void), FUN_0001da1a(void), FUN_000163b8(int);
extern int FUN_00016a04(int, int, int, unsigned char *, int, struct CB *), FUN_0001da48(int, unsigned *), FUN_000163d8(void), FUN_0001d991(int), FUN_0001d9a6(signed char *);
 extern char *FUN_00016fc0(unsigned short);
/* FUN_00016424 @ 00016424: change to drive and directory path ("X:dir"); restores the drive on failure */
int FUN_00016424(signed char *path) { int d, cur, r; cur = FUN_000163d8(); if (path[1] == ':') { d = toupper(path[0]) - 'A'; FUN_000163b8(d); if (FUN_000163d8() != d) return -1; path += 2; } r = chdir((char *)path); if (r == -1) FUN_000163b8(cur); return r; }

/* ---- from build/var/mod/parts/p16490.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_00016490 @ 00016490 */
void FUN_00016490(int a) { mkdir((char *)a); }

