/* Module: FUN_00040d80, FUN_00040de8, FUN_00040e20, FUN_00040e30, FUN_00040e64, FUN_00040ee0, FUN_00040f1c, FUN_00040f8c, FUN_00040fcc, FUN_00041014, FUN_00041044, FUN_0004104c, FUN_000410b0 */
#include <dos.h>
#include <stdlib.h>
/* ---- from build/var/mod/parts/p40d80.c */
/* FUN_00040d80 @ 00040d80: DPMI 0100h, allocate DOS memory */
#include <i86.h>
int FUN_00040d80(int size, int *seg, unsigned short *sel)
{
    union REGS in, out;
    in.x.ebx = (size + 16) / 16;
    in.x.eax = 0x100;
    int386(0x31, &in, &out);
    if (out.x.cflag & 1) return 0;
    *sel = out.w.dx;
    *seg = out.x.eax << 16;
    return out.x.eax << 4;
}

/* ---- from build/var/mod/parts/p40de8.c */
/* FUN_00040de8 @ 00040de8: DPMI 0101h: free the DOS memory block with selector sel; 0 on success, -1 on error */
#include <i86.h>
int FUN_00040de8(int sel)
{
    union REGS r, o;
    r.w.dx = sel;
    r.x.eax = 0x101;
    int386(0x31, &r, &o);
    return ((o.x.cflag & 1) == 0) - 1;
}

/* ---- from build/var/mod/parts/p40e20.c */
/* FUN_00040e20 @ 00040e20: free the DOS memory block of segment v */
int FUN_00040e20(unsigned short v) { return _dos_freemem(v); }

/* ---- from build/var/mod/parts/p40e30.c */
/* FUN_00040e30 @ 00040e30: linear base address of selector sel (DPMI 0006h) */
#include <i86.h>
int FUN_00040e30(int sel)
{
    union REGS r;
    r.w.bx = sel;
    r.w.ax = 6;
    int386(0x31, &r, &r);
    return (r.x.ecx << 16) + r.w.dx;
}

/* ---- from build/var/mod/parts/p40e64.c */
/* FUN_00040e64 @ 00040e64: allocate n bytes of DOS memory with a 6-byte header (segment) (n is reused for the paragraph count) */
#include <i86.h>
char *FUN_00040e64(int n)
{
    union REGS r; unsigned seg; char *p;
    n = (n + 15) / 16;
    if (n > 0xffff) p = 0;
    else {
        if (_dos_allocmem(n, (unsigned short *)&seg)) return 0;
        r.w.bx = seg;
        r.w.ax = 6;
        int386(0x31, &r, &r);
        p = (char *)((r.x.ecx << 16) + r.w.dx);
        *(short *)p = seg;
        *(int *)(p + 2) = 0;
    }
    return p;
}

/* ---- from build/var/mod/parts/p40ee0.c */
/* FUN_00040ee0, FUN_00040f1c: free / allocate a DPMI memory block with a 6-byte header (handle) */
#include <i86.h>
int FUN_00040ee0(int h)
{
    union REGS r;
    r.w.si = h >> 16;
    r.w.di = h;
    r.w.ax = 0x502;
    int386(0x31, &r, &r);
    return (r.x.cflag & 1) != 0;
}

/* ---- from build/var/mod/parts/p40f1c.c */
char *FUN_00040f1c(int size)
{
    union REGS r; char *p; int h;
    r.w.bx = size >> 16;
    r.w.cx = size;
    r.w.ax = 0x501;
    int386(0x31, &r, &r);
    if (r.x.cflag & 1) return 0;
    p = (char *)((r.x.ebx << 16) + r.w.cx);
    *(short *)p = 0;
    h = r.x.esi << 16;
    *(int *)(p + 2) = h + r.w.di;
    return p;
}

/* ---- from build/var/mod/parts/p40f8c.c */
/* FUN_00040f8c @ 00040f8c: size in bytes of the largest free DOS memory block (DPMI 0100h with bx = ffffh) */
#include <i86.h>
int FUN_00040f8c(void)
{
    union REGS r, o;
    r.x.eax = 0x100;
    r.x.ebx = 0xffff;
    int386(0x31, &r, &o);
    if (o.x.cflag & 1) return o.x.ebx << 4;
    return 0;
}

/* ---- from build/var/mod/parts/p40fcc.c */
/* FUN_00040fcc @ 00040fcc: DPMI 0500h free memory information; returns the largest free block in bytes */
#include <i86.h>
#include <string.h>
unsigned FUN_00040fcc(void)
{
    unsigned info[12]; union REGS r; struct SREGS s;
    r.x.eax = 0x500;
    memset(&s, 0, sizeof s);
    s.es = FP_SEG((void __far *)info);
    r.x.edi = (unsigned)info;
    int386x(0x31, &r, &r, &s);
    return info[0];
}

/* ---- from build/var/mod/parts/p41014.c */
/* FUN_00041014 @ 00041014 */
extern void FUN_000390f4(int); extern void FUN_000411e8(const char *); extern void FUN_00043b44(void); extern void FUN_00040c38(void); extern void FUN_0003f540(int);

void FUN_00041014(void)
{
    FUN_000390f4(0xff);
    FUN_000411e8("Terminal Error: Trouble in memory management.\n\r");
    FUN_00043b44();
    FUN_00040c38();
    FUN_0003f540(10);
}

/* ---- from build/var/mod/parts/p41044.c */
/* FUN_00041044: tail call to the C library routine at 0x47afc (labelled _memmax in the function list) */
extern unsigned _memmax(void);
unsigned FUN_00041044(void) { return _memmax(); }

/* ---- from build/var/mod/parts/p4104c.c */
/* FUN_0004104c @ 0004104c: allocate n bytes behind a 10-byte header; on failure free caches step by step and retry */
extern int FUN_0003f0b4(int); extern void FUN_0003f1e4(void), FUN_0003e9cc(void), FUN_00041014(void);
void *FUN_0004104c(int n)
{
    char *p; unsigned char tries = 0;
    do {
        p = malloc(n + 10);
        if (p == 0 && FUN_0003f0b4(1) == 0) {
            switch (tries) {
            case 0: FUN_0003f1e4(); tries++; break;
            case 1: FUN_0003e9cc(); tries++; break;
            case 2: FUN_00041014(); break;
            }
        }
    } while (p == 0);
    *(int *)(p + 6) = 0x12345678;
    return p + 10;
}

/* ---- from build/var/mod/parts/p410b0.c */
/* FUN_000410b0 @ 000410b0: checked free: the block header (10 bytes before p) carries a magic word */
extern void FUN_0003f5f4(char *, char *), FUN_0003f580(char *);
void FUN_000410b0(void *p)
{
    char *q = (char *)p - 10;
    if (q == 0) { FUN_0003f5f4("Memory Warning: Attempt to free NULL pointer", q); return; }
    if (*(int *)(q + 6) == 0xabcdef98) { FUN_0003f580("Attempt to free dealloc ptr."); return; }
    if (*(int *)(q + 6) != 0x12345678) { FUN_0003f580("Attempt to free unalloc ptr."); return; }
    *(int *)(q + 6) = 0xabcdef98;
    free(q);
}


/* ---- module data _DATA 0005f6f8-0005f6fc: the error code FUN_0003f2e0 (m3e340) stores; no module reads it. It lies after rand.o's
   `next` and before __iob, where this module is loaded and has no other _DATA; the owner is inferred (round 76), as for its
   CODE.1 twin DAT_000323d0 in m164b0. */
unsigned DAT_0005f6f8 = 0;
/* ---- end of module data _DATA */
