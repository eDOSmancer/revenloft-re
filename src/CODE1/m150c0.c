/* Module: FUN_000150c0, FUN_00015230, FUN_0001527c, FUN_000152ac, FUN_0001538c, FUN_000153b4, FUN_000153e4,
   FUN_00015454, FUN_0001550c, FUN_000155dc, FUN_000156dc, FUN_00015780, FUN_000157dc */
#include "vmode.h"
#define DAT_000323e6 (VID_000323d4.fe6)
#define DAT_00032401 (*(struct CRECT *)&VID_000323d4.cx)
/* ---- from build/var/mod/parts/p150c0.c */
extern void FUN_00015780(void); /* module prototype */
extern void FUN_000157dc(void); /* module prototype */
struct CRECT { short x, y, w, h; };   /* 0x32401: cursor rectangle */

struct CSAVE { int x1, x2, y1, y2; struct CRECT save; };   /* 0x37178: clip rectangle (FUN_00016c44) and the saved cursor rectangle */
extern struct CSAVE DAT_00037178;
struct MCUR { short shape, y, x; };   /* 0x371d4: mouse cursor shape and position (round 24: one symbol, record cuts of 0x150c0) */
extern struct MCUR DAT_000371d4;
extern int FUN_000184e0(void), DAT_0003097c;
extern void FUN_00016c44(int *), FUN_00016bc0(int, int, int, int);
extern short DAT_000373ec, DAT_000373e6, DAT_000373e8;
void FUN_000150c0(int ev, int shape, int y, int x, short *pos)
{
    y >>= 1;
    if (FUN_000184e0()) {
        x = ((pos[1] + 0x1fc0) * 0x18f + 0x1fa0) / 0x3f40;
        y = ((pos[0] + 0x1fc0) * 0x13f + 0x1fa0) / 0x3f40;
    }
    if (DAT_000373ec >= 1 && !DAT_0003097c) {
        if (DAT_000373e6 != x || DAT_000373e8 != y) {
            DAT_000371d4.x = x;
            DAT_000371d4.y = y;
            DAT_000371d4.shape = shape;
            DAT_00037178.save.x = DAT_00032401.x;
            DAT_00037178.save.y = DAT_00032401.y;
            DAT_00037178.save.w = DAT_00032401.w;
            DAT_00037178.save.h = DAT_00032401.h;
            FUN_00016c44(&DAT_00037178.x1);
            FUN_00016bc0(0, 0, 0x18f, 0x13f);
            FUN_00015780();
            FUN_000157dc();
            FUN_00016bc0(DAT_00037178.x1, DAT_00037178.y1, DAT_00037178.x2, DAT_00037178.y2);
            DAT_00032401.x = DAT_00037178.save.x;
            DAT_00032401.y = DAT_00037178.save.y;
            DAT_00032401.w = DAT_00037178.save.w;
            DAT_00032401.h = DAT_00037178.save.h;
        }
        DAT_000371d4.shape = shape;
    }
}

/* ---- from build/var/mod/parts/p15230.c */
/* FUN_00015230: installs the mouse handler (int 33h, function 0Ch). FP_OFF/FP_SEG of the far handler directly, no local far pointer: with a `void (__far *h)()` local 9.5b gives the object an empty paragraph-aligned _BSS that moves _BSS from 0x355f8 to 0x35600 in the WLINK link (round 25); same code */
#include <i86.h>
extern union REGS DAT_000371ac, DAT_00037190; extern struct SREGS DAT_000371c8;
extern void __far FUN_00016104();
void FUN_00015230(int m) { DAT_000371ac.w.ax = 0xc; DAT_000371ac.w.cx = m; DAT_000371ac.x.edx = FP_OFF(FUN_00016104); DAT_000371c8.es = FP_SEG(FUN_00016104); int386x(0x33, &DAT_000371ac, &DAT_00037190, &DAT_000371c8); }

/* ---- from build/var/mod/parts/p1527c.c */
/* FUN_0001527c */
/* struct MCUR: defined above */   /* 0x371d4: mouse cursor shape and position (round 24: one symbol, record cuts of 0x150c0) */
extern struct MCUR DAT_000371d4;
void FUN_0001527c(short *a, short *b, short *c) { *a = DAT_000371d4.x; *b = DAT_000371d4.y; *c = DAT_000371d4.shape; }

/* ---- from build/var/mod/parts/p152ac.c */
extern void FUN_00015230(int m); /* module prototype */
/* FUN_000152ac */
/* struct MCUR: defined above */   /* 0x371d4: mouse cursor shape and position (round 24: one symbol, record cuts of 0x150c0) */
extern struct MCUR DAT_000371d4;
void *memmove(void *, const void *, unsigned); extern short FUN_000184d0(void); extern void FUN_0001d130(int, int), FUN_0001d10c(int, int), FUN_0001d08c(int, int), FUN_00016bc0(int, int, int, int); extern short *FUN_0001d0b4(void); extern void *FUN_0001954c(int, int); extern short DAT_000371da, DAT_000373e6, DAT_000373e8, DAT_000373ec, DAT_000373ea; extern unsigned char DAT_000373ee; extern int DAT_00037134; extern char DAT_000371dc[];
void FUN_000152ac(void) { short *p; void *q; if (DAT_000371da = FUN_000184d0()) { FUN_0001d130(0, 0x18f); FUN_0001d10c(0, 0x27e); FUN_0001d08c(0xc8, 0xa0); p = FUN_0001d0b4(); DAT_000373e6 = DAT_000371d4.x = p[3]; DAT_000373e8 = DAT_000371d4.y = p[2]; DAT_000373ec = 0; DAT_000371d4.shape = 0; DAT_000373ea = 0; DAT_000373ee = DAT_000323e6; q = FUN_0001954c(DAT_00037134 + 0x2f, 0); memmove(DAT_000371dc, q, 0x20a); FUN_00016bc0(0, 0, 0x18f, 0x13f); FUN_00015230(0xffff); } }

/* ---- from build/var/mod/parts/p1538c.c */
extern void FUN_00015780(void); /* module prototype */
/* FUN_0001538c */
extern void FUN_0001cf98(void); extern short DAT_000371da, DAT_000373ec;
void FUN_0001538c(void) { if (DAT_000371da) { if (DAT_000373ec) FUN_00015780(); FUN_0001cf98(); } }

/* ---- from build/var/mod/parts/p153b4.c */
/* FUN_000153b4: poll the input device; its current value (0 without one) */
extern void FUN_00019ae8(void); extern short *FUN_0001d0b4(void); extern short DAT_000371da, DAT_000373ea;
int FUN_000153b4(void) { short *p; FUN_00019ae8(); if (DAT_000371da) { p = FUN_0001d0b4(); DAT_000373ea = *p; return *p; } return 0; }

/* ---- from build/var/mod/parts/p153e4.c */
extern void FUN_00015780(void); /* module prototype */
extern void FUN_000157dc(void); /* module prototype */
/* FUN_000153e4: old-style definition (the callers push an int, the body reads the byte; a prototype with unsigned char makes them narrow it) */
extern void FUN_00019ae8(void), FUN_000165a4(int); extern short DAT_000371da, DAT_000373ec; extern int DAT_0003097c; extern unsigned char DAT_000373ee;
void FUN_000153e4(pg) unsigned char pg; { FUN_00019ae8(); if (DAT_000371da) { DAT_0003097c = 1; DAT_000373ee = pg; DAT_000373ec = 0; FUN_000157dc(); FUN_000165a4(pg); DAT_000373ee = pg ^ 1; FUN_00015780(); DAT_000373ee = pg; DAT_000373ec = 1; DAT_0003097c = 0; } }

/* ---- from build/var/mod/parts/p15454.c */
extern void FUN_00015780(void); /* module prototype */
extern void FUN_000157dc(void); /* module prototype */
#define FUN_000165a4 ((void (*)(unsigned char))FUN_000165a4)
/* FUN_00015454 */
void *memmove(void *, const void *, unsigned); extern void FUN_00019ae8(void), FUN_00018740(int), FUN_0001a390(int), FUN_00018788(void); extern short DAT_000371da, DAT_000373ec; extern int DAT_0003097c; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400];
void FUN_00015454(int pg) { FUN_00019ae8(); if (DAT_000371da) { DAT_0003097c = 1; DAT_000373ee = pg; DAT_000373ec = 0; FUN_000157dc(); FUN_000165a4(pg); FUN_00018740(pg); FUN_0001a390(pg ^ 1); DAT_000373ee = pg ^ 1; memmove(DAT_000373ef[pg ^ 1], DAT_000373ef[pg], 0x400); FUN_00015780(); FUN_00018788(); DAT_000373ee = pg; DAT_000373ec = 1; DAT_0003097c = 0; } }

#undef FUN_000165a4
/* ---- from build/var/mod/parts/p1550c.c */
extern void FUN_00015780(void); /* module prototype */
extern void FUN_000157dc(void); /* module prototype */
#define FUN_000165a4 ((void (*)(unsigned char))FUN_000165a4)
/* FUN_0001550c */
void *memmove(void *, const void *, unsigned); extern void FUN_00019ae8(void), FUN_00018740(int), FUN_0001a3e8(int, int, int, int, int, int, int), FUN_00018788(void); extern short DAT_000371da, DAT_000373ec; extern int DAT_0003097c; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400];
void FUN_0001550c(int pg, int x, int y, int w, int h) { FUN_00019ae8(); if (DAT_000371da) { DAT_0003097c = 1; DAT_000373ee = pg; DAT_000373ec = 0; FUN_000157dc(); FUN_000165a4(pg); FUN_00018740(pg); FUN_0001a3e8(pg ^ 1, x, y, x, y, w, h); DAT_000373ee = pg ^ 1; memmove(DAT_000373ef[pg ^ 1], DAT_000373ef[pg], 0x400); FUN_00015780(); FUN_00018788(); DAT_000373ee = pg; DAT_000373ec = 1; DAT_0003097c = 0; } }

#undef FUN_000165a4
/* ---- from build/var/mod/parts/p155dc.c */
extern void FUN_00015780(void); /* module prototype */
extern void FUN_000157dc(void); /* module prototype */
void *memmove(void *, const void *, unsigned); extern void FUN_0001a3e8(int, int, int, int, int, int, int); extern short DAT_000371da, DAT_000373ec, DAT_000373e6, DAT_000373e8; extern int DAT_0003097c; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400];
void FUN_000155dc(int pg, int x, int y, int w, int h) { int old; if (DAT_000371da) { DAT_0003097c = 1; if (DAT_000373e6 + 0x20 < x || DAT_000373e6 > x + w || DAT_000373e8 + 0x10 < y || DAT_000373e8 > y + h) FUN_0001a3e8(pg ^ 1, x, y, x, y, w, h); else { old = DAT_000373ee; DAT_000373ee = pg; DAT_000373ec--; FUN_000157dc(); FUN_0001a3e8(pg ^ 1, x, y, x, y, w, h); memmove(DAT_000373ef[pg ^ 1], DAT_000373ef[pg], 0x400); FUN_00015780(); DAT_000373ee = old; DAT_000373ec++; } DAT_0003097c = 0; } }

/* ---- from build/var/mod/parts/p156dc.c */
extern void FUN_00015780(void); /* module prototype */
/* FUN_000156dc */
void *memmove(void *, const void *, unsigned); extern void FUN_00018740(int), FUN_0001a390(int), FUN_00018788(void); extern short DAT_000371da, DAT_000373ec; extern int DAT_0003097c; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400];
void FUN_000156dc(void) { int old; if (DAT_000371da) { old = DAT_000373ee; DAT_0003097c = 1; FUN_00018740(DAT_000323e6); FUN_0001a390(DAT_000323e6 ^ 1); DAT_000373ee = DAT_000323e6 ^ 1; memmove(DAT_000373ef[DAT_000373ee], DAT_000373ef[old], 0x400); FUN_00015780(); FUN_00018788(); DAT_000373ee = old; DAT_0003097c = 0; DAT_000373ec++; } }

/* ---- from build/var/mod/parts/p15780.c */
/* FUN_00015780 */
extern void FUN_00018740(int), FUN_00016744(unsigned char *, int, int, int, int), FUN_00018788(void); extern short DAT_000371da, DAT_000373ec, DAT_000373e6, DAT_000373e8; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400];
void FUN_00015780(void) { if (DAT_000371da && !--DAT_000373ec) { FUN_00018740(DAT_000373ee); FUN_00016744(DAT_000373ef[DAT_000373ee], DAT_000373e6, DAT_000373e8, 0x20, 0x10); FUN_00018788(); } }

/* ---- from build/var/mod/parts/p157dc.c */
extern void FUN_0001527c(short *a, short *b, short *c); /* module prototype */
/* FUN_000157dc */
extern void FUN_00018740(int), FUN_000166c0(unsigned char *, int, int, int, int), FUN_00016d54(int, int, int, void *), FUN_00018788(void); extern short DAT_000371da, DAT_000373ec, DAT_000373e6, DAT_000373e8, DAT_000373ea; extern unsigned char DAT_000373ee, DAT_000373ef[][0x400]; extern char DAT_000371dc[];
void FUN_000157dc(void) { if (DAT_000371da) { if (!DAT_000373ec) { FUN_00018740(DAT_000373ee); FUN_0001527c(&DAT_000373e6, &DAT_000373e8, &DAT_000373ea); FUN_000166c0(DAT_000373ef[DAT_000373ee], DAT_000373e6, DAT_000373e8, 0x20, 0x10); FUN_00016d54(0, DAT_000373e6, DAT_000373e8, DAT_000371dc); FUN_00018788(); } DAT_000373ec++; } }

/* ---- module data _DATA 0003097c-00030980 (docs/data/dataown.CODE1.csv: certain), generated by tools/data2c.py */
int DAT_0003097c = 0;
/* ---- end of module data _DATA */
