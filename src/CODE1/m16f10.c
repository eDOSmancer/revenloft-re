/* Module: FUN_00016f10, FUN_00016f74, FUN_00016fac, FUN_00016fc0, FUN_00016ff4, FUN_0001705c, FUN_0001709c, FUN_000170fc, FUN_0001713c, FUN_00017184, FUN_000171bc, FUN_000171c8, FUN_00017240 */
#include "vmode.h"
#define DAT_000323d7 (VID_000323d4.w)
#include <i86.h>
#include <dos.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/* ---- from build/var/mod/parts/p16f10.c */
/* FUN_00016f10 */
int FUN_00016f10(int n, int *seg, short *sel) { union REGS r; volatile union REGS o; r.x.eax = 0x100; r.x.ebx = (n + 0x10) / 16; int386(0x31, &r, (union REGS *)&o); if (o.x.cflag & 1) return 0; *sel = o.x.edx; *seg = o.x.eax << 16; return o.x.eax << 4; }

/* ---- from build/var/mod/parts/p16f74.c */
/* FUN_00016f74: free DOS memory selector sel (DPMI 0101h); 0, or -1 on failure */
int FUN_00016f74(int sel) { union REGS r; volatile union REGS o; r.x.eax = 0x101; r.w.dx = sel; int386(0x31, &r, (union REGS *)&o); return ((o.x.cflag & 1) == 0) - 1; }

/* ---- from build/var/mod/parts/p16fac.c */
extern unsigned char DAT_00038919, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00016fac @ 00016fac */
void FUN_00016fac(unsigned short a) { _dos_freemem(a); }

/* ---- from build/var/mod/parts/p16fc0.c */
struct RF { int fh, n, count; void *tab; };
extern int DAT_00032b04; extern struct RF *DAT_00032b08;
extern void FUN_0001df13(int), FUN_000187d8(int, int), FUN_0001df73(void), FUN_000161d0(char *), FUN_0001cbf0(int), FUN_00014dc4(void), FUN_00015014(int);
#pragma aux FUN_0001cbf0 aborts;
extern int FUN_00014978(void), FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_00016fc0 @ 00016fc0: DPMI 0006h, linear base address of selector sel */
char *FUN_00016fc0(unsigned short sel) { union REGS r; r.w.bx = sel; r.w.ax = 6; int386(0x31, &r, &r); return (char *)((r.x.ecx << 16) + r.w.dx); }

/* ---- from build/var/mod/parts/p16ff4.c */
struct CB { char b[0x18]; };
extern struct CB DAT_0003240c[]; extern int DAT_0003246c;
extern void FUN_0001da18(void), FUN_0001da1a(void), FUN_000163b8(int);
extern int FUN_00016a04(int, int, int, unsigned char *, int, struct CB *), FUN_0001da48(int, unsigned *), FUN_000163d8(void), FUN_0001d991(int), FUN_0001d9a6(char *);
extern unsigned char *FUN_0001954c(int, int); extern char *FUN_00016fc0(unsigned short);
/* FUN_00016ff4 @ 00016ff4: allocate size bytes of DOS memory; returns its linear address (selector stored in the first word) or 0 */
char *FUN_00016ff4(int size) { unsigned sel; char *p; size = (size + 15) / 16; if (size > 0xffff) return 0; if (_dos_allocmem(size, (unsigned short *)&sel)) return 0; p = FUN_00016fc0(sel); *(short *)p = sel; *(int *)(p + 2) = 0; return p; }

/* ---- from build/var/mod/parts/p1705c.c */
extern int FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_0001705c @ 0001705c: DPMI 0502h, free the memory block with handle h; 1 on error */
int FUN_0001705c(int h) { volatile union REGS r; r.w.si = h >> 16; r.w.di = h; r.w.ax = 0x502; int386(0x31, (union REGS *)&r, (union REGS *)&r); return (r.x.cflag & 1) != 0; }

/* ---- from build/var/mod/parts/p1709c.c */
extern int FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_0001709c @ 0001709c: DPMI 0501h, allocate size bytes; the block starts with a 0 word and the DPMI handle; 0 on error */
char *FUN_0001709c(int size)
{
    union REGS r; char *p;
    r.w.bx = size >> 16;
    r.w.cx = size;
    r.w.ax = 0x501;
    int386(0x31, &r, &r);
    if (r.x.cflag & 1) return 0;
    p = (char *)((r.x.ebx << 16) + r.w.cx);
    *(short *)p = 0;
    *(int *)(p + 2) = (r.x.esi << 16) + r.w.di;
    return p;
}

/* ---- from build/var/mod/parts/p170fc.c */
extern int FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_000170fc @ 000170fc: DPMI 0100h with 0xffff paragraphs: the size of the largest DOS block in bytes */
int FUN_000170fc(void) { volatile union REGS in, out; in.x.eax = 0x100; in.x.ebx = 0xffff; int386(0x31, (union REGS *)&in, (union REGS *)&out); if (out.x.cflag & 1) return out.x.ebx << 4; return 0; }

/* ---- from build/var/mod/parts/p1713c.c */
extern unsigned char *FUN_0001954c(int, int); extern void FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_00018960(void);
extern int FUN_0001da1c(int, union REGS *, union REGS *), FUN_0001cec8(int, union REGS *, union REGS *, struct SREGS *);
/* FUN_0001713c @ 0001713c: DPMI 0500h, the largest free memory block in bytes */
int FUN_0001713c(void) { struct SREGS s; union REGS r; int info[12]; r.x.eax = 0x500; memset(&s, 0, sizeof(s)); s.es = FP_SEG(info); r.x.edi = FP_OFF(info); int386x(0x31, &r, &r, &s); return info[0]; }

/* ---- from build/var/mod/parts/p17184.c */
/* FUN_00017184 */
extern void FUN_000164dc(int), FUN_0001cf98(void), FUN_00018424(void), FUN_000197d4(int);
void FUN_00017184(void) { FUN_000164dc(0xff); FUN_000161d0("Terminal Error: Trouble in memory management.\n\r"); FUN_0001cf98(); FUN_00018424(); FUN_000197d4(10); }

/* ---- from build/var/mod/parts/p171bc.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char DAT_0003892f[]; 
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_000171bc @ 000171bc */
int FUN_000171bc(void) { return _memmax(); }

/* ---- from build/var/mod/parts/p171c8.c */
/* FUN_000171c8: allocate n bytes with a 10-byte guarded header; on failure free caches step by step, then give up */
extern char *FUN_0001dac9(int); extern int FUN_00019378(int); extern void FUN_000194d0(void), FUN_00019520(void), FUN_00017184(void);
void *FUN_000171c8(int n) { unsigned char t = 0; char *p = 0; for (; !p; ) { p = malloc(n + 10); if (p) continue; if (FUN_00019378(1)) continue; switch (t) { case 0: FUN_000194d0(); ++t; break; case 1: FUN_00019520(); ++t; break; case 2: FUN_00017184(); break; } } *(int *)(p + 6) = 0x12345678; return p + 10; }

/* ---- from build/var/mod/parts/p17240.c */
/* FUN_00017240 */
extern void FUN_00019874(char *, int), FUN_00019814(char *), FUN_0001db4b(void *);
void FUN_00017240(int p) { char *q = (char *)p - 10; if (!q) { FUN_00019874("Memory Warning: Attempt to free NULL pointer", 0); return; } if (*(int *)(q + 6) == 0xabcdef98) FUN_00019814("Attempt to free dealloc ptr."); else { if (*(int *)(q + 6) != 0x12345678) { FUN_00019814("Attempt to free unalloc ptr."); return; } *(int *)(q + 6) = 0xabcdef98; free(q); } }

