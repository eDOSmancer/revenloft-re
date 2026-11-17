#include "farproc.h"
/* Module: FUN_000411e0, FUN_000411e8, FUN_00041218, FUN_00041234, FUN_00041258, FUN_00041274, FUN_0004127c, FUN_000412a0, FUN_000412b4, FUN_000412c8, FUN_000412dc, FUN_000412ec, FUN_00041304, FUN_0004131c, FUN_00041334, FUN_00041380, FUN_00041390, FUN_000413ac, FUN_000413c4, FUN_000413ec, FUN_000413fc, FUN_00041484 */
/* ---- from build/var/mod/parts/p411e0.c */
/* Module: FUN_000411e0 */
/* ---- from build/var/mod/parts/p411e0.c */
/* FUN_000411e0 @ 000411e0: BIOS tick counter at 0040:006C */
int FUN_000411e0(void) { return *(volatile int *)0x46c; }

/* ---- from build/var/mod/parts/p411e8.c */
/* FUN_000411e8 @ 000411e8: print the string s through DOS (int 21h, AH=9), as CODE.1 FUN_000161d0: '$' inside it becomes '*', the
   string is terminated with '$' for the call and restored. The inline code reads s from its frame slot ([ebp+0xc], coded as
   bytes for the 32-bit displacement); "modify [esp]" makes the compiler set up the ebp frame the original has */
void dos_print(void);
#pragma aux dos_print = 0x8b 0x95 0x0c 0x00 0x00 0x00 "mov ah, 9" "int 21h" modify [eax edx esp];
void FUN_000411e8(signed char *s)
{
    while (*s) { if (*s == '$') *s = '*'; s++; }
    *s = '$';
    dos_print();
    *s = 0;
}

/* ---- from build/var/mod/parts/p41218.c */
/* FUN_00041218 @ 00041218 */
int access(const char *, int);
int FUN_00041218(const char *path, unsigned short mode) { return access(path, mode) == 0; }

/* ---- from build/var/mod/parts/p41234.c */
/* FUN_00041234, FUN_00041258: first / next file matching path and attributes; the name, or 0. FUN_00041274: attributes of the found file */
#include <dos.h>
extern struct find_t B0007b6d0_hn;
char *FUN_00041234(char *path, unsigned short attr)
{
    if (_dos_findfirst(path, attr, &B0007b6d0_hn)) return 0;
    return B0007b6d0_hn.name;
}

/* ---- from build/var/mod/parts/p41258.c */
char *FUN_00041258(void)
{
    if (_dos_findnext(&B0007b6d0_hn)) return 0;
    return B0007b6d0_hn.name;
}

/* ---- from build/var/mod/parts/p41274.c */
char FUN_00041274(void)
{
    return B0007b6d0_hn.attrib;
}

/* ---- from build/var/mod/parts/p4127c.c */
/* FUN_0004127c @ 0004127c */
long FUN_0004127c(const char *path)
{
    if (_dos_findfirst(path, 0, &B0007b6d0_hn) == 0) return B0007b6d0_hn.size;
    return -1;
}

/* ---- from build/var/mod/parts/p412a0.c */
/* FUN_000412a0 @ 000412a0: open for reading (binary) */
int open(const char *, int, ...);
int FUN_000412a0(const char *name) { return open(name, 0x200); }

/* ---- from build/var/mod/parts/p412b4.c */
/* FUN_000412b4 @ 000412b4: open for read/write (binary) */
int open(const char *, int, ...);
int FUN_000412b4(const char *name) { return open(name, 0x202); }

/* ---- from build/var/mod/parts/p412c8.c */
/* FUN_000412c8 @ 000412c8: create a file */
int creat(const char *, int);
int FUN_000412c8(const char *name) { return creat(name, 0x180); }

/* ---- from build/var/mod/parts/p412dc.c */
/* FUN_000412dc @ 000412dc: close wrapper */
int close(int);
void FUN_000412dc(int fd) { close(fd); }

/* ---- from build/var/mod/parts/p412ec.c */
/* FUN_000412ec, FUN_00041304, FUN_0004131c: file I/O wrappers with swapped argument order */
int read(int, void *, unsigned); int write(int, const void *, unsigned); long lseek(int, long, int);
int FUN_000412ec(void *buf, unsigned len, int fd) { return read(fd, buf, len); }

/* ---- from build/var/mod/parts/p41304.c */
int FUN_00041304(const void *buf, unsigned len, int fd) { return write(fd, buf, len); }

/* ---- from build/var/mod/parts/p4131c.c */
long FUN_0004131c(long off, int whence, int fd) { return lseek(fd, off, whence); }

/* ---- from build/var/mod/parts/p41334.c */
/* FUN_00041334 @ 00041334: seek to the idx-th entry of a file's offset table */
long lseek(int, long, int); int read(int, void *, unsigned);
void FUN_00041334(int idx, int fd)
{
    long off;
    lseek(fd, idx * 4 + 4, 0);
    read(fd, &off, 4);
    lseek(fd, off, 0);
}

/* ---- from build/var/mod/parts/p41380.c */
/* FUN_00041380 @ 00041380: delete a file */
int unlink(const char *);
void FUN_00041380(const char *name) { unlink(name); }

/* ---- from build/var/mod/parts/p41390.c */
/* FUN_00041390 @ 00041390: _dos_setdrive, the number of drives through an out parameter */
int FUN_00041390(int a) { int r; _dos_setdrive(a, (unsigned *)&r); return r; }

/* ---- from build/var/mod/parts/p413ac.c */
/* Module: FUN_000413ac, FUN_000413c4, FUN_000413ec, FUN_000413fc, FUN_00041484 */
/* ---- from build/var/mod/parts/p413ac.c */
#include <dos.h>
#include <direct.h>
#include <ctype.h>
extern char B0007b6fb_iP[];
/* FUN_000413ac @ 000413ac: current drive (1 = A:) */
unsigned FUN_000413ac(void) { unsigned d; _dos_getdrive(&d); return d; }

/* ---- from build/var/mod/parts/p413c4.c */
/* ---- from build/var/mod/parts/p413c4.c */
/* FUN_000413c4 @ 000413c4: number of drives (re-selects the current drive) */
unsigned FUN_000413c4(void) { unsigned n, d; _dos_getdrive(&d); _dos_setdrive(d, &n); return n; }

/* ---- from build/var/mod/parts/p413ec.c */
/* ---- from build/var/mod/parts/p413ec.c */
/* FUN_000413ec @ 000413ec: remember the current directory in B0007b6fb_iP */
void FUN_000413ec(void) { getcwd(B0007b6fb_iP, 0x50); }

/* ---- from build/var/mod/parts/p413fc.c */
/* ---- from build/var/mod/parts/p413fc.c */
/* FUN_000413fc @ 000413fc: change to drive and directory path ("X:dir"); restores the drive on failure (CODE.2 copy of CODE.1 FUN_00016424) */
int FUN_000413fc(signed char *path) { unsigned save; unsigned n2, now, n, cur; unsigned d; int r; _dos_getdrive(&cur); save = cur; if (path[1] == ':') { d = toupper(path[0]) - 'A'; _dos_setdrive(d, &n); _dos_getdrive(&now); if (now != d) return -1; path += 2; } r = chdir((char *)path); if (r == -1) _dos_setdrive(save, &n2); return r; }

/* ---- from build/var/mod/parts/p41484.c */
/* ---- from build/var/mod/parts/p41484.c */
/* FUN_00041484 @ 00041484 */
int FUN_00041484(char *path) { return mkdir(path); }

