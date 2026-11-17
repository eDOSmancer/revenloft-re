#include "farproc.h"
/* Module: FUN_000474e0, FUN_0004757c */
/* ---- from build/var/mod/parts/p474e0.c */
/* FUN_000474e0 @ 000474e0: read a sound bank entry: copy the 0x1c-byte header that hdr+5 points at into a new
   block of 0x1b + size bytes and read the data after it from fd (CODE.1 twin FUN_0001e0d0); FUN_0004757c frees one */
struct H { short a[11]; int size; char c1, c2; };
extern void *FUN_0004104c(int); extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000410b0(void *);
struct H *FUN_000474e0(char *hdr, int fd)
{
    struct H *s, *p;
    s = *(struct H **)(hdr + 5);
    p = FUN_0004104c(0x1b + s->size);
    p->a[0] = s->a[0]; p->a[1] = s->a[1]; p->a[2] = s->a[2]; p->a[3] = s->a[3]; p->a[4] = s->a[4]; p->a[5] = s->a[5];
    p->a[6] = s->a[6]; p->a[7] = s->a[7]; p->a[8] = s->a[8]; p->a[9] = s->a[9]; p->a[10] = s->a[10];
    p->size = s->size; p->c1 = s->c1; p->c2 = s->c2;
    FUN_000412ec(p + 1, p->size - 1, fd);
    return p;
}

/* ---- from build/var/mod/parts/p4757c.c */
void FUN_0004757c(void *p) { FUN_000410b0(p); }

