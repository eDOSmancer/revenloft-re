#include "farproc.h"
/* Module: FUN_00047590, FUN_000475f0 */
/* ---- from build/var/mod/parts/p47590.c */
/* FUN_00047590 @ 00047590: read a length-prefixed packed block from fd: allocate n + 2 bytes, keep n in the first
   word and unpack the data behind it through the level-file byte reader; FUN_000475f0 frees one */
extern void *FUN_0004104c(int); extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000410b0(void *);
extern void FUN_0003f960(int), FUN_0003f96c(void), FUN_0003fb04(int, int, int, int, unsigned char);
unsigned short *FUN_00047590(int unused, int fd)
{
    unsigned short n; unsigned short *p;
    FUN_000412ec(&n, 2, fd);
    p = FUN_0004104c(n + 2);
    *p = n;
    FUN_0003f960(fd);
    FUN_0003f96c();
    FUN_0003fb04(0, 0, (int)(p + 1), n, 0);
    return p;
}

/* ---- from build/var/mod/parts/p475f0.c */
void FUN_000475f0(void *p) { FUN_000410b0(p); }

