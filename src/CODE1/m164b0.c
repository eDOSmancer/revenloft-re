/* Module: FUN_000164b0, FUN_000164dc, FUN_00016588, FUN_000165a4, FUN_000165c0, FUN_000165e8, FUN_00016618, FUN_00016634, FUN_00016654, FUN_00016674, FUN_00016694, FUN_000166a8, FUN_000166c0, FUN_00016744, FUN_000167c8, FUN_000167f4, FUN_00016824, FUN_00016854, FUN_00016a04, FUN_00016bc0, FUN_00016c44, FUN_00016c60, FUN_00016c98, FUN_00016d00, FUN_00016d54, FUN_00016dac, FUN_00016de8, FUN_00016e50, FUN_00016eb0 */
#include "vmode.h"
#define DAT_000323d4 (VID_000323d4.mode)   /* the object itself is the record */
#define DAT_000323d7 (VID_000323d4.w)
#define DAT_000323d9 (VID_000323d4.h)
#define DAT_000323db (VID_000323d4.fdb)
#define DAT_000323dd (VID_000323d4.fdd)
#define DAT_000323df (VID_000323d4.fdf)
#define DAT_000323e5 (VID_000323d4.fe5)
#define DAT_000323e6 (VID_000323d4.fe6)
#define DAT_000323ed (VID_000323d4.l)
#define DAT_000323f1 (VID_000323d4.r)
#define DAT_000323f5 (VID_000323d4.t)
#define DAT_000323f9 (VID_000323d4.b)
#define DAT_00032401 (VID_000323d4.cx)
#define DAT_00032403 (VID_000323d4.cy)
#define DAT_00032405 (VID_000323d4.cw)
#define DAT_00032407 (VID_000323d4.ch)
/* ---- from build/var/mod/parts/p164b0.c */
/* FUN_000164b0: seed the random generator (0: from the BIOS tick count); returns the seed */
void srand(unsigned);
unsigned short FUN_000164b0(unsigned short seed) { if (!seed) seed = *(unsigned short *)0x46c; srand(seed); return seed; }

/* ---- from build/var/mod/parts/p164dc.c */
/* FUN_000164dc */
extern void FUN_00019df4(void), FUN_0001a474(int), FUN_00016588(int), FUN_000165a4(int), FUN_00016bc0(int, int, int, int); extern unsigned char FUN_00019ca0(int, unsigned char *);  
void FUN_000164dc(int mode) { unsigned char r; if (mode == 0xff) { FUN_00019df4(); DAT_000323d4 = 0xff; return; } r = FUN_00019ca0((unsigned char)mode, &DAT_000323d4); DAT_000323db = 0x100; DAT_000323dd = (r & 4) != 0; if (DAT_000323df < 0xff) FUN_0001a474(0xff); DAT_000323e6 = 0; DAT_000323e5 = 0; FUN_00016588(0); FUN_000165a4(0); FUN_00016bc0(0, 0, DAT_000323d7 - 1, DAT_000323d9 - 1); DAT_000323d4 = mode & 0x7f; }

/* ---- from build/var/mod/parts/p16588.c */
/* FUN_00016588 */
extern void FUN_0001a35c(int); 
void FUN_00016588(unsigned char c) { FUN_0001a35c(c); DAT_000323e5 = c; }

/* ---- from build/var/mod/parts/p165a4.c */
/* FUN_000165a4 */
extern void FUN_0001a36c(int); 
void FUN_000165a4(unsigned char c) { FUN_0001a36c(c); DAT_000323e6 = c; }

/* ---- from build/var/mod/parts/p165c0.c */
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char DAT_00038904[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000165c0 @ 000165c0: vertical line of length c at (a, b) */
void FUN_000165c0(int a, int b, int c, unsigned char d) { FUN_0001a05c(a, b, a, b + c - 1, d); }

/* ---- from build/var/mod/parts/p165e8.c */
#define SB T5_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char DAT_00038904[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000165e8 @ 000165e8: horizontal line of length c at (a, b) */
void FUN_000165e8(int a, int b, int c, unsigned char d) { if (c) FUN_0001a05c(a, b, a + c - 1, b, d); }

#undef SB
/* ---- from build/var/mod/parts/p16618.c */
/* FUN_00016618 */
extern void FUN_0001a010(void *, int, int);
void FUN_00016618(void *p) { FUN_0001a010(p, 0, 0x300); }

/* ---- from build/var/mod/parts/p16634.c */
extern short *DAT_00032a9c; extern unsigned short **DAT_00038988; extern char DAT_00038904[], DAT_00038922[];
extern void FUN_000185d4(int, int, int, int, int), FUN_0001864c(int, int, int, int, int), FUN_0001a010(void *, int, int), FUN_0001a2b0(int, int);
extern unsigned short **FUN_0001954c(int, int); extern int FUN_0001d2ad(char *);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_00016634 @ 00016634 */
void FUN_00016634(int a, int b, int c) { FUN_0001a010((void *)c, a, b * 2 + b); }

/* ---- from build/var/mod/parts/p16654.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char DAT_0003892f[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_00016654 @ 00016654 */
void FUN_00016654(int x) { FUN_0001a2b0(DAT_000323d7 - x, x); }

/* ---- from build/var/mod/parts/p16674.c */
#define SR T9_SR
extern short *DAT_00032a9c; extern unsigned short **DAT_00038988; extern char DAT_00038904[], DAT_00038922[];
extern void FUN_000185d4(int, int, int, int, int), FUN_0001864c(int, int, int, int, int), FUN_0001a010(void *, int, int), FUN_0001a2b0(int, int);
extern unsigned short **FUN_0001954c(int, int); extern int FUN_0001d2ad(char *);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_00016674 @ 00016674 */
void FUN_00016674(int x) { FUN_0001a2b0(DAT_000323d7 - x, x - DAT_000323d7); }

#undef SR
/* ---- from build/var/mod/parts/p16694.c */
extern unsigned char DAT_00038919, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00016694 @ 00016694 */
void FUN_00016694(int a) { FUN_0001a21c(a); }

/* ---- from build/var/mod/parts/p166a8.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char DAT_0003892f[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_000166a8 @ 000166a8 */
void FUN_000166a8(int a) { FUN_0001a21c(-a); }

/* ---- from build/var/mod/parts/p166c0.c */
/* FUN_000166c0 */
extern void FUN_0001a484(int, int, int, int, int); 
void FUN_000166c0(int c, int x, int y, int w, int h) { if (x < 0) { w += x; x = 0; } if (y < 0) { h += y; y = 0; } if (x + w > DAT_000323d7) w = DAT_000323d7 - x; if (y + h > DAT_000323d9) h = DAT_000323d9 - y; if (w > 0 && h > 0) FUN_0001a484(c, x, y, w, h); }

/* ---- from build/var/mod/parts/p16744.c */
/* FUN_00016744 */
extern void FUN_0001a4e8(int, int, int, int, int); 
void FUN_00016744(int c, int x, int y, int w, int h) { if (x < 0) { w += x; x = 0; } if (y < 0) { h += y; y = 0; } if (x + w > DAT_000323d7) w = DAT_000323d7 - x; if (y + h > DAT_000323d9) h = DAT_000323d9 - y; if (w > 0 && h >= 0) FUN_0001a4e8(c, x, y, w, h); }

/* ---- from build/var/mod/parts/p167c8.c */
/* FUN_000167c8 */
extern void FUN_0001a6f0(int, int, int, void *), FUN_00018960(void);
void FUN_000167c8(int a, int b, int c, int d) { if (d) { FUN_0001a6f0(a, b, c, (void *)d); FUN_00018960(); } }

/* ---- from build/var/mod/parts/p167f4.c */
#define SB T15_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char DAT_00038904[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000167f4 @ 000167f4 */
void FUN_000167f4(int a, int b, int c, int d, unsigned char e) { if (d) { FUN_0001a7e8(a, b, c, (unsigned char *)d, e); FUN_00018960(); } }

#undef SB
/* ---- from build/var/mod/parts/p16824.c */
/* FUN_00016824 */
extern void FUN_0001a8f4(int, int, int, void *, int), FUN_00018960(void);
void FUN_00016824(int a, int b, int c, int d, int e) { if (d) { FUN_0001a8f4(a, b, c, (void *)d, e); FUN_00018960(); } }

/* ---- from build/var/mod/parts/p16854.c */
struct S { int id; unsigned short w; unsigned char rows; };
struct C { int skipl, skipr, w, skipt, skipb, h; };
extern void FUN_00018960(void), FUN_0001aa20(int, int, int, struct C *, struct S *);


int FUN_00016854(int pg, int x, int y, struct S *s, struct C *c)
{
    int d;
    FUN_00018960();
    if (!s) return 0;
    c->w = s->w;
    c->skipl = 0;
    c->skipr = 0;
    d = DAT_000323ed - x;
    if (d > 0) {
        c->w -= d;
        c->skipl = d * (s->rows * 8);
        x = DAT_000323ed;
    }
    d = x + c->w - 1 - DAT_000323f1;
    if (d > 0) {
        c->w -= d;
        c->skipr = d * (s->rows * 8);
    }
    c->h = s->rows * 8;
    c->skipt = 0;
    c->skipb = 0;
    d = DAT_000323f5 - y;
    if (d > 0) {
        c->h -= d;
        c->skipt = d;
        y = DAT_000323f5;
    }
    d = y + c->h - 1 - DAT_000323f9;
    if (d > 0) {
        c->h -= d;
        c->skipb = d;
    }
    DAT_00032401 = x;
    DAT_00032403 = y;
    DAT_00032405 = c->w;
    DAT_00032407 = c->h;
    if (s->w == c->w && s->rows * 8 == c->h) {
        FUN_0001a6f0(pg, x, y, s);
        return 2;
    }
    if (c->w > 0 && c->h > 0) {
        FUN_0001aa20(pg, x, y, c, s);
        return 1;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p16a04.c */
/* FUN_00016a04 @ 00016a04: draw sprite img at (x, y) on page pg clipped to the window: 2 = unclipped, 1 = clipped, 0 = nothing drawn (CODE.2 FUN_00039564) */
struct R { int l, r, w, t, b, h; };
extern void FUN_00018960(void), FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_0001ac10(int, int, int, struct R *, unsigned char *, int);
 
int FUN_00016a04(int pg, int x, int y, unsigned char *img, unsigned char c, struct R *r)
{
    int d;
    FUN_00018960();
    if (img) {
        r->w = *(unsigned short *)(img + 4);
        r->l = 0;
        r->r = 0;
        d = DAT_000323ed - x;
        if (d > 0) {
            r->w -= d;
            r->l = d * (img[6] * 8);
            x = DAT_000323ed;
        }
        d = x + r->w - 1 - DAT_000323f1;
        if (d > 0) {
            r->w -= d;
            r->r = d * (img[6] * 8);
        }
        r->h = img[6] * 8;
        r->t = 0;
        r->b = 0;
        d = DAT_000323f5 - y;
        if (d > 0) {
            r->h -= d;
            r->t = d;
            y = DAT_000323f5;
        }
        d = y + r->h - 1 - DAT_000323f9;
        if (d > 0) {
            r->h -= d;
            r->b = d;
        }
        DAT_00032401 = x;
        DAT_00032403 = y;
        DAT_00032405 = r->w;
        DAT_00032407 = r->h;
        if (*(unsigned short *)(img + 4) == r->w && img[6] * 8 == r->h) {
            FUN_0001a7e8(pg, x, y, img, c);
            return 2;
        }
        if (r->w > 0 && r->h > 0) {
            FUN_0001ac10(pg, x, y, r, img, c);
            return 1;
        }
    }
    return 0;
}

/* ---- from build/var/mod/parts/p16bc0.c */
/* FUN_00016bc0 */
 
void FUN_00016bc0(int l, int t, int r, int b) { if (l < 0) l = 0; if (t < 0) t = 0; if (r >= DAT_000323d7) r = DAT_000323d7 - 1; if (b >= DAT_000323d9) b = DAT_000323d9 - 1; t &= ~3; b = b / 4 * 4 + 3; DAT_000323ed = l; DAT_000323f5 = t; DAT_000323f1 = r; DAT_000323f9 = b; }

/* ---- from build/var/mod/parts/p16c44.c */
/* FUN_00016c44 */
void *memcpy(void *, const void *, unsigned);
void FUN_00016c44(void *p) { memcpy(p, &DAT_000323ed, 0x10); }

/* ---- from build/var/mod/parts/p16c60.c */
/* FUN_00016c60 */
extern void *FUN_0001954c(int, int); extern void FUN_00018960(void);
void FUN_00016c60(int a, int b, int c, int id, int sub) { void *p = FUN_0001954c(id, sub); if (p) { FUN_0001a6f0(a, b, c, p); FUN_00018960(); } }

/* ---- from build/var/mod/parts/p16c98.c */
/* FUN_00016c98 */
struct S24 { char b[0x18]; };
extern void _disable(void), _enable(void);  extern void *FUN_0001954c(int, int); extern int DAT_0003246c; extern struct S24 DAT_0003240c[];
int FUN_00016c98(int a, int b, int c, int id, int sub) { struct S24 *p; int r; _disable(); p = &DAT_0003240c[DAT_0003246c++]; _enable(); r = FUN_00016854(a, b, c, FUN_0001954c(id, sub), (struct C *)p); _disable(); DAT_0003246c--; _enable(); return r; }

/* ---- from build/var/mod/parts/p16d00.c */
#pragma pack(1)
struct RE { unsigned char lo, f1, f2; unsigned short f3; int f5; };
#pragma pack()
struct RF { int fh, n, count; struct RE *tab; };
extern int DAT_0003246c;
extern unsigned char *FUN_0001954c(int, int); extern void _disable(void), _enable(void), FUN_0001862c(int, int, unsigned char *);
/* FUN_00016d00 @ 00016d00: draw resource (c, d) at (a, b) with interrupts briefly masked around the busy counter */
void FUN_00016d00(int a, int b, int c, int d) { unsigned char *p; p = FUN_0001954c(c, d); if (p) { _disable(); DAT_0003246c++; _enable(); FUN_0001862c(a, b, p); _disable(); DAT_0003246c--; _enable(); } }

#pragma pack()
/* ---- from build/var/mod/parts/p16d54.c */
/* FUN_00016d54 */
int FUN_00016d54(int a, int b, int c, int d) { struct S24 *p; int r; _disable(); p = &DAT_0003240c[DAT_0003246c++]; _enable(); r = FUN_00016854(a, b, c, (struct S *)d, (struct C *)p); _disable(); DAT_0003246c--; _enable(); return r; }

/* ---- from build/var/mod/parts/p16dac.c */
#include <i86.h>
#include <string.h>
extern unsigned char *FUN_0001954c(int, int); extern void FUN_0001a7e8(int, int, int, unsigned char *, int), FUN_00018960(void);
extern int FUN_0001da1c(int, union REGS *, union REGS *), FUN_0001cec8(int, union REGS *, union REGS *, struct SREGS *);
/* FUN_00016dac @ 00016dac: draw resource sprite (d, e) at (a, b) with mode c and colour k, then poll the keyboard */
void FUN_00016dac(int a, int b, int c, int d, int e, unsigned char k) { unsigned char *p; p = FUN_0001954c(d, e); if (p) { FUN_0001a7e8(a, b, c, p, k); FUN_00018960(); } }

/* ---- from build/var/mod/parts/p16de8.c */
extern void _disable(void), _enable(void), FUN_000163b8(int);
extern int FUN_0001da48(int, unsigned *), FUN_000163d8(void), FUN_0001d991(int), FUN_0001d9a6(char *);
extern unsigned char *FUN_0001954c(int, int); extern char *FUN_00016fc0(unsigned short);
/* FUN_00016de8 @ 00016de8: as FUN_00016e50, the image given as resource (d, e) */
int FUN_00016de8(int a, int b, int c, int d, int e, unsigned char k) { struct S24 *p; int r; _disable(); p = &DAT_0003240c[DAT_0003246c++]; _enable(); r = FUN_00016a04(a, b, c, FUN_0001954c(d, e), k, (struct R *)p); _disable(); DAT_0003246c--; _enable(); return r; }

/* ---- from build/var/mod/parts/p16e50.c */
extern void _disable(void), _enable(void), FUN_000186a4(int, int, int), FUN_0001c7a0(int, int, int, int, int), FUN_0001c8c4(int, int, int, int, int);

/* FUN_00016e50 @ 00016e50: call FUN_00016a04 with the next free context block (taken and released with interrupts masked) */
int FUN_00016e50(int a, int b, int c, int d, unsigned char e) { struct S24 *p; int r; _disable(); p = &DAT_0003240c[DAT_0003246c++]; _enable(); r = FUN_00016a04(a, b, c, (unsigned char *)d, e, (struct R *)p); _disable(); DAT_0003246c--; _enable(); return r; }

/* ---- from build/var/mod/parts/p16eb0.c */
/* FUN_00016eb0 */
extern void *FUN_0001954c(int, int); extern void FUN_00018960(void);
void FUN_00016eb0(int a, int b, int c, int id, int sub, int e) { void *p = FUN_0001954c(id, sub); if (p) { FUN_0001a8f4(a, b, c, p, e); FUN_00018960(); } }

/* ---- module data _DATA 000323d0-00032470 (docs/data/dataown.CODE1.csv: certain (ref; some shared)), generated by tools/data2c.py */
int DAT_000323d0 = 0;   /* type from another module's declaration */
struct VMODE VID_000323d4 = { 0 };
unsigned char DAT_00032409[3] = { 0x72, 0x63, 0x65 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
struct S24 DAT_0003240c[4] = { 0 };
int DAT_0003246c = 0;
/* ---- end of module data _DATA */
