typedef void (__far *PARA_BSS)(); /* STANDIN: the _BSS of this object file is paragraph-aligned in the original (unnamed bytes ahead of it up to the 16-byte boundary); a typedef of a far pointer type raises the alignment, as a far pointer or double variable of any function would (docs/BSS.md) */
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
struct HS *B00062c00_hH;
/* BSS end */
/* Module: FUN_0001eee0, FUN_0001ef14, FUN_0001ef34, FUN_0001ef70, FUN_0001efa0, FUN_0001f168, FUN_0001f218,
   FUN_0001f238, FUN_0001f274, FUN_0001f290, FUN_0001f2b4, FUN_0001f2d4, FUN_0001f308, FUN_0001f368,
   FUN_0001f390, FUN_0001f40c, FUN_0001f4b0, FUN_0001f540, FUN_0001f5f8, FUN_0001f66c, FUN_0001f790,
   FUN_0001fd84, FUN_0001fde4, FUN_0001fe44, FUN_0001fed0, FUN_0001ff3c, FUN_000200c8, FUN_00020108,
   FUN_00020158, FUN_00020a70, FUN_00020bbc, FUN_00020fac, FUN_000210b4, FUN_0002118c, FUN_00021268,
   FUN_000212ec, FUN_000213ac, FUN_00021404, FUN_00021630, FUN_000217a0, FUN_00021ad8, FUN_00021c20,
   FUN_00021c3c, FUN_00021fb0, FUN_0002202c, FUN_00022098, FUN_000220bc, FUN_00022128, FUN_00022180,
   FUN_00022470, FUN_00022724, FUN_00022988, FUN_00022c20, FUN_00022e70, FUN_000230a0, FUN_00023118 */
/* names inside DAT_00057330 (tools/dataview.py): views of the object its module defines */
#define DAT_00057334 ((unsigned char *)((char *)DAT_00057330 + 0x4))
#define VIEW_PTR_DAT_00057335 (*(short * *)((char *)DAT_00057330 + 0x5))
#define PTR_DAT_00057335 VIEW_PTR_DAT_00057335
#define DAT_00057339 (*(unsigned char *)((char *)DAT_00057330 + 0x9))
#pragma pack(1)
struct G { unsigned char n, cols, maxw, y0, kind; short *slots; unsigned char mask; };   /* the container-type table at 0x57330 (62 rows) */
#pragma pack()
extern struct G DAT_00057330[];
/* names inside DAT_00057e8c (tools/dataview.py): views of the object its module defines */
extern unsigned short DAT_00057e8c[][5];
#define DAT_00057e94 (*(unsigned short *)((char *)DAT_00057e8c + 0x8))
/* names inside DAT_00056fa0 (tools/dataview.py): views of the object its module defines */
#define DAT_00056fa1 ((unsigned char *)((char *)DAT_00056fa0 + 0x1))
#define VIEW_DAT_00056fa2 ((signed char *)((char *)DAT_00056fa0 + 0x2))
#define DAT_00056fa2 VIEW_DAT_00056fa2
#define DAT_00056fa3 ((unsigned char *)((char *)DAT_00056fa0 + 0x3))
/* ---- from build/var/mod/parts/p1eee0.c */
/* FUN_0001eee0 and FUN_00021630 in one file (round 62 lane Z): FUN_00021630's auto initialiser range[6][2] is the module's lead data at 0x1eeb0 (the compiler emits it ahead of the first function of the object), so it lands at 0x1eeb0 only when FUN_0001eee0 is the first function of the file; replaces src/CODE2/f1eee0.c and src/CODE2/f21630.c, supersedes asmfb/w1eeb0.asm */
/* FUN_0001eee0 @ 0001eee0 */
#include "world.h"
extern unsigned char B000718e0_iO;
#define B00071940_lM (*(short *)((char *)&B000718e0_iO + 96)) /* STANDIN: view, B000718e0_iO + 0x60 */
 
int FUN_0001eee0(int i)
{
    int t = *(short *)((char *)&B00071940_lM + i * 0x248);
    if (t != -1 && ((unsigned char *)B000755d8_aw)[t * 0x41 + 0x2f] == 4) return 1; /* STANDIN: if / return 1 / return 0 instead of the returned condition - orders the i * 0x248 / t tie as the original under -oa */
    return 0;
}

/* ---- from build/var/mod/parts/p1ef14.c */
/* FUN_0001ef14 @ 0001ef14 */
#define B00071aca_he (*(int *)((char *)&B000718e0_iO + 490)) /* STANDIN: view, B000718e0_iO + 0x1ea */
#define B000719f3_iO (*(int *)((char *)&B000718e0_iO + 275)) /* STANDIN: view, B000718e0_iO + 0x113 */
#define B000718fc_i0 (*(short *)((char *)&B000718e0_iO + 28)) /* STANDIN: view, B000718e0_iO + 0x1c */
 
int FUN_0001ef14(int i)
{
    int r = *(short *)((char *)&B000718fc_i0 + i * 0x248);
    r += *(int *)((char *)&B00071aca_he + i * 0x248);
    r += *(int *)((char *)&B000719f3_iO + i * 0x248);
    return r;
}

/* ---- from build/var/mod/parts/p1ef34.c */
/* round 22: written with a byte pointer (21 expression nodes, so the module calls it as the original does in all six places; with &((struct IT *)B000755d8_aw)[i] it had 19 and FUN_0001ef70/FUN_0001efa0 expanded it, recipe 40). */
/* FUN_0001ef34 @ 0001ef34: magic bonus of item i (minus the enchantment byte for weapon classes 2..8) */
#include "world.h"

int FUN_0001ef34(int i)
{
    unsigned char *p; int r, t;
    if (i == -1) return 0;
    r = 0;
    { int c; c = i; i = c; } /* STANDIN: copy out and back on i, its memory temp gets savings so the item-table load temps keep their order under -oa */
    p = (unsigned char *)B000755d8_aw + i * 0x41;
    t = p[0x2f];
    if (t >= 2 && t <= 8) r = -p[0x37];
    { int c; c = r; r = c; } /* STANDIN: copy out and back, +4 savings for r so it sorts ahead of t and the i copy (EDX as in the original) under -oa */
    return r;
}

/* ---- from build/var/mod/parts/p1ef70.c */
extern int FUN_0001eee0(int i); /* module prototype */
extern int FUN_0001ef34(int i); /* module prototype */
extern int FUN_0001f2d4(int i, int v); /* module prototype */
extern int FUN_0001fe44(int i); /* module prototype */
/* the module declaration (seen through a cast view below) */ extern unsigned char B000718e0_iO;
/* (FUN_0001ef70: defined in this module) */
/* The copy of FUN_0001ef70 ahead of the function is the module's own definition (src/CODE2/f1ef70.c): the original expands it in line here, which needs both in one compile; it goes away when module 0x1eee0 becomes one module file. */
/* FUN_0001ef70 @ 0001ef70: armour bonus of item it (base value plus magic) */
#include "world.h"
 
int FUN_0001ef70(int it)
{
    int r;
    if (it == -1) return 0;
    r = *(signed char *)(((char *)B000755d8_aw) + it * 0x41 + 0x34);
    r += FUN_0001ef34(it);
    return r;
}

 

/* FUN_0001efa0 @ 0001efa0: armour class of party member i (base, armour, shield, dexterity, rings, level and conditions) */
#include "world.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
extern int FUN_00034478(int, int);
 extern signed char DAT_00056fb0[];   /* the table is indexed from 1: 0x56faf = DAT_00056fb0 - 1 */
#define CS(i, o) (*(short *)(M000718e0_iO + (i) * 0x248 + (o)))
extern int FUN_0001ef70(int);
int FUN_0001efa0(int i)
{
    int it, lv, ac, f;
    ac = *(signed char *)(M000718e0_iO + i * 0x248 + 0x1b);
    ac += FUN_0001ef70(CS(i, 0x60));
    if (CS(i, 0x68) == 0x51 && !FUN_0001eee0(i)) {
        if (ac > 5) ac = 5;
        ac += FUN_0001ef34(CS(i, 0x60));
    }
    ac += FUN_0001ef70(CS(i, 0x62));
    ac += (DAT_00056fb0 - 1)[*(unsigned char *)(M000718e0_iO + i * 0x248 + 0x35)];
    it = CS(i, 0x5c);
    if (it != -1 && FUN_00034478(i, 0)) ac += FUN_0001ef70(it);
    it = CS(i, 0x5e);
    if (it != -1 && FUN_00034478(i, 1)) ac += FUN_0001ef70(it);
    lv = FUN_0001fe44(i);
    if (lv == 3) ac++;
    if (lv == 4) ac += 3;
    f = *(int *)(M000718e0_iO + i * 0x248 + 0x132);
    if ((f & 1) && ac > 6 && !FUN_0001eee0(i)) ac = 6;
    if (f & 0x80) ac -= 2;
    if (FUN_0001f2d4(i, 0x46)) ac--;
    return ac;
}

#undef M000718e0_iO
#undef CS
/* ---- from build/var/mod/parts/p1f168.c */
/* FUN_0001f168 @ 0001f168: is item k a key */
int FUN_0001f168(int k)
{
    if (k == 6) return 1;
    if (k == 0x109) return 1;
    if (k == 0x10e) return 1;
    if (k == 0x120) return 1;
    if (k == 0x127) return 1;
    if (k == 0x131) return 1;
    if (k == 0x134) return 1;
    if (k == 0x135) return 1;
    if (k == 0x13b) return 1;
    if (k == 0x13d) return 1;
    if (k == 0x141) return 1;
    if (k == 0x146) return 1;
    if (k == 0x147) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p1f218.c */
/* (FUN_0001f218, FUN_000200c8: defined in this module) */
/* round 62 second blind rewrite; the copies of FUN_0001f218 / FUN_000200c8 are the module definitions, expanded in line here */
/* LAYOUT-ONLY copies of the module's expanded callees (src/CODE2/f1f218.c, f200c8.c) */
#define B00071a0b_ah (*(int *)((char *)&B000718e0_iO + 299)) /* STANDIN: view, B000718e0_iO + 0x12b */

unsigned char FUN_0001f218(int i, int bit) { return (*(int *)((char *)&B00071a0b_ah + i * 0x248) & (1 << bit)) >> bit; }

/* ---- from build/var/mod/parts/p1f238.c */
/* FUN_0001f238 @ 0001f238 */
#define B00071920_bM (*(short *)((char *)&B000718e0_iO + 64)) /* STANDIN: view, B000718e0_iO + 0x40 */
 
void FUN_0001f238(int i, int bit, int val)
{
    if (((short *)((char *)&B00071920_bM + i * 0x248))[bit] != -1) {
        *(int *)((char *)&B00071a0b_ah + i * 0x248) &= ~(1 << bit);
        *(int *)((char *)&B00071a0b_ah + i * 0x248) |= val << bit;
    }
}

/* ---- from build/var/mod/parts/p1f274.c */
/* (FUN_0001f274, FUN_0001f290, FUN_000200c8, FUN_00021c20: defined in this module) */
/* LAYOUT-ONLY copies of the module's expanded callees (src/CODE2/f1f274.c with the unsigned char return of m23f70's
   declaration, f1f290.c, f200c8.c) */

unsigned char FUN_0001f274(int i, int bit) { return (*((unsigned char *)&DAT_00057339 + i * 10) & (1 << bit)) >> bit; }



#define FLAGS(i) (*((unsigned char *)&DAT_00057339 + (i) * 10))
void FUN_0001f290(int i, int bit, int val)
{
    FLAGS(i) &= ~(1 << bit);
    FLAGS(i) |= val << bit;
}

#undef FLAGS
/* ---- from build/var/mod/parts/p1f2b4.c */
/* FUN_0001f2b4 and FUN_00022128 (same module: the first is expanded inline into the second) */
int FUN_0001f2b4(int k)
{
    if (k == 0x10) return 1;
    if (k == 0x5f) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p1f2d4.c */
/* FUN_0001f2d4 @ 0001f2d4 */
#define B00071938_l5 (*(short *)((char *)&B000718e0_iO + 88)) /* STANDIN: view, B000718e0_iO + 0x58 */
#define B0007193a_bl (*(short *)((char *)&B000718e0_iO + 90)) /* STANDIN: view, B000718e0_iO + 0x5a */

int FUN_0001f2d4(int i, int v)
{
    if (*(short *)((char *)&B00071938_l5 + i * 0x248) == v) return 1;
    if (*(short *)((char *)&B0007193a_bl + i * 0x248) == v) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p1f308.c */
/* FUN_0001f308 @ 0001f308 */
#include "world.h"
extern void FUN_000398f0(int, int, int, int, int, void *); extern void FUN_0003975c(int, int, int, int, int);
extern short DAT_00056dae[]; /* STANDIN: declared as an array - under -oa the scalar is a zero-savings memory node that flips the item-offset tie (recipe 244); the element is none, same compare */ extern unsigned char DAT_0005d470[];
void FUN_0001f308(int a, int b, int c, int i)
{
    if (DAT_00056dae[0]) { /* STANDIN: element 0 of the array view */
        unsigned char *m = ((unsigned char *)B000755d8_aw) + i * 0x41;
        if (m[0x37] || *(short *)(m + 0x32)) { FUN_000398f0(0, a, b, c, 1, DAT_0005d470); return; }
    }
    FUN_0003975c(0, a, b, c, 1);
}

/* ---- from build/var/mod/parts/p1f368.c */
/* FUN_0001f368 @ 0001f368: 0 for a member of class 2, 3 or 4 (the party table byte at +0x14 of the 0x248-byte record), else 1.
   The table read is written out in each comparison (recipe 6): the code is the same as with one local, but the function then
   has more than 20 expression nodes, so -oe does not expand it, and the original calls it from FUN_00020bbc and FUN_00022e70
   (round 16; with `int t = ...` it has 16 nodes and is expanded into both callers). */
#define B000718f4_h3 (*(unsigned char *)((char *)&B000718e0_iO + 20)) /* STANDIN: view, B000718e0_iO + 0x14 */

int FUN_0001f368(int i)
{
    if (*((unsigned char *)&B000718f4_h3 + i * 0x248) == 4 || *((unsigned char *)&B000718f4_h3 + i * 0x248) == 3 || *((unsigned char *)&B000718f4_h3 + i * 0x248) == 2) return 0;
    return 1;
}

/* ---- from build/var/mod/parts/p1f390.c */
/* FUN_0001f390 @ 0001f390: is item b inside container item a (recursive) */
#include "world.h"
  extern struct G DAT_00057330[];
int FUN_0001f390(short a, short b)
{
    int k, t; short *p; char *m;
    if (a == b) return 1;
    m = ((char *)B000755d8_aw) + a * 0x41;
    if ((unsigned char)m[0x2f] == 1) {
        t = (signed char)m[0x31];
        { int c; c = t; t = c; } /* STANDIN: copy out and back, +4 savings for t so the item-offset temps keep the original order under -oa */
        p = *(short **)((char *)&PTR_DAT_00057335 + t * 10);
        for (k = 0; k < *((unsigned char *)&DAT_00057330 + t * 10); p++, k++)
            if (*p != -1 && FUN_0001f390(*p, b)) return 1;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p1f40c.c */
extern void FUN_0001f290(int i, int bit, int val); /* module prototype */
/* (FUN_0001f290: defined in this module) */
/* The copy of FUN_0001f290 ahead of the function is the module's own definition (src/CODE2/f1f290.c): the original expands it in line here (-oe), which needs both in one compile; it goes away when module 0x1eee0 becomes one module file. */
/* FUN_0001f290 @ 0001f290 */

#define FLAGS(i) (*((unsigned char *)&DAT_00057339 + (i) * 10))

/* FUN_0001f40c @ 0001f40c: remove item b from inside container item a (recursive) */
#include "world.h"
  extern struct G DAT_00057330[];

int FUN_0001f40c(short a, short b)
{
    int off; short *p; int k; int t;
    off = a * 0x41;
    if ((unsigned char)((char *)B000755d8_aw)[off + 0x2f] == 1) {
        t = (signed char)((char *)B000755d8_aw)[off + 0x31];
        p = *(short **)((char *)&PTR_DAT_00057335 + t * 10);
        for (k = 0; k < *((unsigned char *)&DAT_00057330 + t * 10); p++, k++) {
            if (*p != -1) {
                if (*p == b) {
                    *p = -1;
                    FUN_0001f290(t, k, 0);
                    return 1;
                }
                if (FUN_0001f40c(*p, b)) return 1;
            }
        }
    }
    return 0;
}

#undef FLAGS
/* ---- from build/var/mod/parts/p1f4b0.c */
extern int FUN_0001f390(short a, short b); /* module prototype */
/* FUN_0001f4b0 @ 0001f4b0: does anyone in the party carry item b (in hand or in any slot) */
#include "chars.h"
 extern short DAT_00058600; extern unsigned short B000718f0_hO;
int FUN_0001f4b0(short b)
{
    int off, k;
    if (DAT_00058600 != -1) {
        if (FUN_0001f390(DAT_00058600, b)) return 1;
    }
    for (off = 0; off < 0x920; off += 0x248) {
        if (!(*(unsigned short *)((char *)&B000718f0_hO + off) & 0x8000)) {
            for (k = 0; k < 21; k++) {
                if (*(short *)((char *)&B00071920_bM + off + k * 2) != -1) {
                    if (FUN_0001f390(*(short *)((char *)&B00071920_bM + off + k * 2), b)) return 1;
                }
            }
        }
    }
    return 0;
}

/* ---- from build/var/mod/parts/p1f540.c */
extern void FUN_0001f238(int i, int bit, int val); /* module prototype */
extern int FUN_0001f40c(short a, short b); /* module prototype */
/* FUN_0001f540 @ 0001f540: remove item from the hand or from any party member's pack (also inside containers) */
#include "chars.h"
extern void FUN_0002a344(short, unsigned char); 
extern short DAT_00058600; extern unsigned short B000718f0_hO;
#define SLOT(off, j) (*(short *)((char *)&B00071920_bM + (off) + (j) * 2))
void FUN_0001f540(int item)
{
    int k, j, off;
    if (DAT_00058600 != -1) {
        if (DAT_00058600 == item) { FUN_0002a344(-1, 0); return; }
        if (FUN_0001f40c(DAT_00058600, item)) return;
    }
    for (k = 0, off = 0; k < 4; k++, off += 0x248) {
        if (!(*(unsigned short *)((char *)&B000718f0_hO + off) & 0x8000)) {
            for (j = 0; j < 21; j++) {
                if (SLOT(off, j) != -1) {
                    if (SLOT(off, j) == item) {
                        SLOT(off, j) = -1;
                        FUN_0001f238(k, j, 0);
                    } else if (FUN_0001f40c(SLOT(off, j), item)) return;
                }
            }
        }
    }
}

#undef SLOT
/* ---- from build/var/mod/parts/p1f5f8.c */
/* FUN_0001f5f8 @ 0001f5f8: total weight of the contents of container type t (nested containers count) */
#include "world.h"
#define DAT_00057330 ((unsigned char *)&DAT_00057330)
#undef PTR_DAT_00057335
#define PTR_DAT_00057335 ((char *)&VIEW_PTR_DAT_00057335)
  
int FUN_0001f5f8(int t)
{
    unsigned short w = 0; int k; short *p; unsigned char *m;
    if (t != 0x14) {
        for (k = 0, p = *(short **)(PTR_DAT_00057335 + t * 10); k < DAT_00057330[t * 10]; p++, k++) {
            if (*p != -1) {
                m = ((unsigned char *)B000755d8_aw) + *p * 0x41;
                w += m[0x30];
                if (m[0x2f] == 1) w += FUN_0001f5f8((signed char)m[0x31]);
            }
        }
    } else {
        { unsigned short v; v = (unsigned char)((char *)B000755d8_aw)[0x1480]; w = v; } /* STANDIN: through a named same-width temp - one more in-block node orders the item-offset tie under -oa (recipe 238) */
    }
    return w;
}

#undef DAT_00057330
#undef PTR_DAT_00057335
#define PTR_DAT_00057335 VIEW_PTR_DAT_00057335
/* ---- from build/var/mod/parts/p1f66c.c */
/* FUN_0001f66c @ 0001f66c: draw the decorated title bar with centred text s */
int rand(void);
extern int FUN_00040288(char *, int); extern void FUN_0003975c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int);
void FUN_0001f66c(char *s)
{
    int w, x, x4, lim, lim2;
    w = FUN_00040288(s, 1) + 16;
    w = w / 2 + 3;
    w &= 0xfffc;
    w = 0xa0 - w;
    if (w % 8 == 0) w -= 4;
    if ((w + 4) % 0x50 == 0) w -= 8;
    lim = 0x138 - w;
    lim2 = 0x140 - w;
    for (x = w, x4 = w + 4; x < lim2; x += 8, x4 += 8) {
        if (x == w) FUN_0003975c(0, 0x62, x, 3, 2);
        else if (x < lim) {
            if (x4 % 0x50 == 0) FUN_0003975c(1, 0x62, x, 3, 2);
            else FUN_0003975c(((unsigned)(rand() * 3) >> 15) + 2, 0x62, x, 3, 2);
        } else FUN_0003975c(5, 0x62, x, 3, 2);
    }
    FUN_00040508(0x65, 0, 0x140, s, 1);
}

/* ---- from build/var/mod/parts/p1f790.c */
extern int FUN_0001f5f8(int t); /* module prototype */
extern void FUN_0001f66c(char *s); /* module prototype */
/* FUN_0001f790 @ 0001f790: show the description of item (name, enchantment when identified, damage or armour class, weight, capacity or charges) */
#include <string.h>
#include <stdlib.h>
#include "world.h"
#define DAT_00057330 ((struct G *)&DAT_00057330)
struct IT { char name[0x2f]; unsigned char cls, wt; signed char sub; unsigned char p0, p1; signed char acb; unsigned short fl; unsigned char ac, d[6], y[3]; };
  extern char DAT_0005759c[], *DAT_00056d98; extern unsigned char DAT_00056dac, DAT_000567ec[]; extern void *DAT_00057f68; /* void * as in the module's other files (was int) */
extern void FUN_0003932c(int, int, int, int, int), FUN_0002c368(char *, int); extern char *FUN_0003e6f0(int), *FUN_0003e70c(int);
 extern unsigned FUN_00040700(void);
void FUN_0001f790(int item, int ident)
{
    int hi; int lo; unsigned short w; char t[4]; unsigned char *p; /* STANDIN: hi declared before lo - the declaration order flips the item-pointer load / sum tie (t86 / t87) under -oa */
    FUN_0003932c((int)DAT_00057f68, 0x62, 0, 0x10, 0x140);
    if (DAT_00056dac) {
        FUN_0001f66c(DAT_0005759c);
        return;
    }
    FUN_0002c368(t, 0x3f);
    if (item == -1) return;
    strcpy(DAT_0005759c, ((struct IT *)B000755d8_aw)[item].name);
    if (((struct IT *)B000755d8_aw)[item].ac && ident) {
        strcat(DAT_0005759c, " +");
        strcat(DAT_0005759c, FUN_0003e6f0(((struct IT *)B000755d8_aw)[item].ac));
    }
    strcat(DAT_0005759c, "; ");
    switch (((struct IT *)B000755d8_aw)[item].cls) {
    case 9: case 10: case 11:
        p = ((struct IT *)B000755d8_aw)[item].d;
        lo = p[0] + p[2];
        hi = p[2] + p[0] * p[1];
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), 0x3e);
        strcat(DAT_0005759c, " ");
        strcat(DAT_0005759c, FUN_0003e6f0(lo));
        strcat(DAT_0005759c, "-");
        strcat(DAT_0005759c, FUN_0003e6f0(hi));
        p = ((struct IT *)B000755d8_aw)[item].d + 3;
        lo = p[0] + p[2];
        hi = p[2] + p[0] * p[1];
        strcat(DAT_0005759c, "/");
        strcat(DAT_0005759c, FUN_0003e6f0(lo));
        strcat(DAT_0005759c, "-");
        strcat(DAT_0005759c, FUN_0003e6f0(hi));
        strcat(DAT_0005759c, "; ");
        break;
    case 2: case 3: case 4:
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), 0x40);
        strcat(DAT_0005759c, " ");
        strcat(DAT_0005759c, FUN_0003e6f0(-((struct IT *)B000755d8_aw)[item].acb));
        strcat(DAT_0005759c, "; ");
        break;
    }
    FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), 0x3d);
    w = ((struct IT *)B000755d8_aw)[item].wt;
    if (((struct IT *)B000755d8_aw)[item].cls == 1) w += FUN_0001f5f8(((struct IT *)B000755d8_aw)[item].sub);
    strcat(DAT_0005759c, FUN_0003e70c(w / 2));
    if (w & 1) strcat(DAT_0005759c, ".5");
    if (((struct IT *)B000755d8_aw)[item].cls == 1) {
        if (DAT_00057330[((struct IT *)B000755d8_aw)[item].sub].maxw != 0x7f) {
            strcat(DAT_0005759c, "; ");
            FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), 0x41);
            strcat(DAT_0005759c, " ");
            strcat(DAT_0005759c, FUN_0003e6f0(DAT_00057330[((struct IT *)B000755d8_aw)[item].sub].maxw));
        }
    } else if ((((struct IT *)B000755d8_aw)[item].sub || item == 0x4a) && ident) {
        strcat(DAT_0005759c, DAT_00056d98);
        strcat(DAT_0005759c, FUN_0003e6f0(DAT_000567ec[((struct IT *)B000755d8_aw)[item].sub]));
    }
    srand(item);
    FUN_0001f66c(DAT_0005759c);
    srand(FUN_00040700());
}

#undef DAT_00057330
#pragma pack()
/* ---- from build/var/mod/parts/p1fd84.c */
extern int FUN_0001f5f8(int t); /* module prototype */
/* FUN_0001fd84 @ 0001fd84: half the total weight of the 21 item slots */
#include "world.h"
  
#define MON(s,o) (((char *)B000755d8_aw)[(s) * 0x41 + (o)])
int FUN_0001fd84(int i)
{
    int sum = 0, k, s;
    for (k = 0; k < 21; k++) {
        s = *(short *)((char *)&B00071920_bM + i * 0x248 + k * 2);
        if (s != -1) {
            sum += (unsigned char)MON(s, 0x30);
            if ((unsigned char)MON(s, 0x2f) == 1) sum += FUN_0001f5f8((signed char)MON(s, 0x31));
        }
    }
    return sum / 2;
}

#undef MON
/* ---- from build/var/mod/parts/p1fde4.c */
/* FUN_0001fde4 @ 0001fde4: experience table lookup from class index and level */
#define B00071912_a3 (*(unsigned char *)((char *)&B000718e0_iO + 50)) /* STANDIN: view, B000718e0_iO + 0x32 */
#define B0007191e_dP (*(unsigned char *)((char *)&B000718e0_iO + 62)) /* STANDIN: view, B000718e0_iO + 0x3e */
 
int FUN_0001fde4(int i)
{
    int n = *((unsigned char *)&B00071912_a3 + i * 0x248);
    int lv = *((unsigned char *)&B0007191e_dP + i * 0x248);
    if (lv >= 1 && lv <= 0x32) n += 1;
    if (lv >= 0x33 && lv <= 0x4b) n += 2;
    if (lv >= 0x4c && lv <= 0x5a) n += 3;
    if (lv >= 0x5b && lv <= 0x63) n += 4;
    if (lv == 100) n += 5;
    return *(unsigned short *)((char *)&DAT_00057e94 + (n - 2) * 10);
}

/* ---- from build/var/mod/parts/p1fe44.c */
extern int FUN_0001fd84(int i); /* module prototype */
/* FUN_0001fe44 @ 0001fe44: experience level band (0..4) of party member i; class 0x12 is split by its sub-value */
  extern unsigned short DAT_00057e8c[][5];
int FUN_0001fe44(int i)
{
    int c, v, x, k;
    c = *((unsigned char *)&B00071913_a2 + i * 0x248);
    if (c == 0x12) {
        v = *((unsigned char *)&B0007191f_dW + i * 0x248);
        if (v >= 1 && v <= 0x32) c++;
        if (v >= 0x33 && v <= 0x4b) c += 2;
        if (v >= 0x4c && v <= 0x5a) c += 3;
        if (v >= 0x5b && v <= 0x63) c += 4;
        if (v == 0x64) c += 5;
    }
    c -= 2;
    x = FUN_0001fd84(i);
    for (k = 0; k < 5; k++) if (x <= DAT_00057e8c[c][k]) return k;
    return 4;
}

/* ---- from build/var/mod/parts/p1fed0.c */
extern int FUN_0001efa0(int i); /* module prototype */
extern int FUN_0001fe44(int i); /* module prototype */
#define FUN_00040508 ((void (*)(int, int, int, void *, int))FUN_00040508)
/* FUN_0001fed0 @ 0001fed0 */
 extern void FUN_0003975c(int, int, int, int, int);  extern void *FUN_0003e6f0(int); 
extern int DAT_00057f6c; /* int as in the module's other files (was char *): one declaration for the module */
void FUN_0001fed0(int a)
{
    FUN_0003975c(FUN_0001fe44(a), 0x10, DAT_00057f6c + 0x44, 0x11, 2);
    FUN_0003975c(0, 0x10, DAT_00057f6c + 0x38, 0x10, 2);
    FUN_00040508(0x16, DAT_00057f6c + 0x38, 0xe, FUN_0003e6f0(FUN_0001efa0(a)), 0);
}

#undef FUN_00040508
/* ---- from build/var/mod/parts/p1ff3c.c */
extern void FUN_0001fed0(int a); /* module prototype */
#define M000718e0_iO ((char *)&B000718e0_iO)
#define FUN_000398f0 ((void (*)(int, int, int, int, int, unsigned char *))FUN_000398f0)
/* Round 53 (module 0x1eee0 plain, 6 compiles + trace): the difference is the r * 0x100 temp t24 taking r's dying ECX (original EDX): t24 and r tie at savings 4; tw.py t24<t8 accepts only an insert of a 0/1-savings node at pre-sort 4/9/21/26 or one of 0/1/4 at 31 (cross-block). y before hp (19), r * 0x100 + base (5), hp in one statement (15), mx before hp (5), hp/mx/bar/y declared in the if block (5). Most likely untested cause: one more cross-block value of one use (a 0-savings node: under -oa a memory node, which is why the function matches without -ol / with other node sets). */
/* Round 18 (module 0x1eee0, 5 lines): r * 0x100 is formed in a copy in the original (allocation order of r and its product); r declared last, r or r and pic in an inner block, the call nested in the argument list: no change. Round 27: in module 0x1eee0 it MATCHES under -oa (real 10.0a); under plain -ox (module best set, 36/56 vs 32/56) 181 lines (shift; 1 region). Instrument gate IDENTICAL (plain, truncated module): r = t9 (ECX), r*0x100 = t25 ties with r at savings 4 and follows r into ECX by the move bonus; whatif t25 before r: move r's node or insert a zero-savings node at 4/9/21/26/31 (what the -oa global nodes do); all 720 declaration orders of the six locals: one code. So the function decides for -oa unless a source gives plain -ox one cross-block node more; most likely untested cause: a kept value crossing the pic branch (none found that keeps the code). 0 real, 721 instrument. */
/* FUN_0001ff3c @ 0001ff3c: draw party member i's portrait box: frame, name, portrait, health bar and status icons */
/* In module 0x1eee0 (-ox -oe -ot, 2026-11-10): matches only under -oa. Without it the palette offset r * 0x100 is
   formed in r's own register (shl ecx,8) instead of a copy (mov edx,ecx; shl edx,8), and the record offset then
   takes other registers (181 lines). Q2: in the original r stays live (ecx) past that use. Not attempted further. */
extern void FUN_0003e510(int, int, int, int), FUN_00040508(int, int, int, char *, int), FUN_00039b40(int, int, int, int, int), FUN_0003975c(int, int, int, int, int);
extern int FUN_0002f3fc(int);
extern int DAT_00057f6c, B000758e4_h7;  extern unsigned char DAT_0005cf70[];
#define CB(i, o) (*(unsigned char *)(M000718e0_iO + (i) * 0x248 + (o)))
#define CS(i, o) (*(short *)(M000718e0_iO + (i) * 0x248 + (o)))
#define CU(i, o) (*(unsigned short *)(M000718e0_iO + (i) * 0x248 + (o)))
#define CI(i, o) (*(int *)(M000718e0_iO + (i) * 0x248 + (o)))
void FUN_0001ff3c(int i)
{
    int r, pic, hp, mx, bar, y;
    FUN_0003e510(0, DAT_00057f6c, 0, 2);
    FUN_00040508(2, DAT_00057f6c, 0x50, M000718e0_iO + i * 0x248, 1);
    r = FUN_0002f3fc(i);
    pic = CB(i, 0x13) * 0x17 + B000758e4_h7 + *(signed char *)(M000718e0_iO + i * 0x248 + 0x12);
    if (CU(i, 0x10) & 0x100) pic += 0x2e;
    FUN_000398f0(0, 0x10, DAT_00057f6c + 3, pic, 1, DAT_0005cf70 + r * 0x100);
    if (!(CU(i, 0x10) & 0x4000)) {
        hp = CS(i, 0x1c);
        hp += CI(i, 0x1ea);
        hp += CI(i, 0x113);
        mx = CS(i, 0x1e);
        bar = (hp * 0x50 + (mx >> 1)) / mx;
        y = DAT_00057f6c + 0x2f;
        if (bar > 0x50) FUN_00039b40(0x10, y, 0x50, 4, 0x1b);
        else if (bar > 0x14) FUN_00039b40(0x50 - bar + 0x10, y, bar, 4, 0x43);
        else FUN_00039b40(0x50 - bar + 0x10, y, bar, 4, 0x57);
    }
    FUN_0001fed0(i);
    if (CI(i, 0x132)) FUN_0003975c(0, 0x2a, DAT_00057f6c + 0x44, 0x13, 2);
    if (CU(i, 0x10) & 0x1f00) FUN_0003975c(0, 0x2a, DAT_00057f6c + 0x38, 0x12, 2);
}

#undef M000718e0_iO
#undef FUN_000398f0
#undef CB
#undef CS
#undef CU
#undef CI
/* ---- from build/var/mod/parts/p200c8.c */


extern void FUN_0002a5b0(int, short, unsigned char); extern int DAT_0005bf44, DAT_0005c050;
void FUN_000200c8(unsigned spr, unsigned c)
{
    if (spr >= 0xa7 && spr <= 0xc9) DAT_0005bf44 = 0x3a;
    FUN_0002a5b0(DAT_0005c050, spr, c);
    DAT_0005c050 ^= 1;
}

/* ---- from build/var/mod/parts/p20108.c */
/* (FUN_00020108: defined in this module) */
/* round 61 blind rewrite. The copy of FUN_00020108 ahead of the function is the module's own definition (src/CODE2/f20108.c): the original expands it in line here, which needs both in one compile; it goes away when module 0x1eee0 becomes one module file. */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;
void FUN_00020108(unsigned spr, unsigned c, int x, int y, int w, int h)
{
    if (spr >= 0xa7 && spr <= 0xc9) DAT_0005bf44 = 0x3a;
    FUN_0002a724(DAT_0005c050, spr, c, x, y, w, h);
    DAT_0005c050 ^= 1;
}

/* ---- from build/var/mod/parts/p20158.c */
extern int FUN_0001efa0(int i); /* module prototype */
/* FUN_00020158 @ 00020158: draw the character sheet of party member who: classes, levels, alignment, race and sex, the six ability scores (current and base), armour class, hit points and experience per class */
/* MATCH round 65 lane AP (real 10.0a, -3s -ox -oe -ot -w0, module 0x1eee0 plain). From the round-42 draft: first ability loop rewritten with t / q / o (copies) - the old pair t149 410 / t316 404 was a savings gap; o and q as copies of one product tie at 404; declaration order searched (40 random, 2 MATCH). */
#include <stdio.h>
#include <string.h>
#define M000718e0_iO ((unsigned char *)&B000718e0_iO)
extern char DAT_0005759c[]; extern int DAT_00057f6c; extern unsigned char DAT_00056dac; extern unsigned short DAT_00057d9c[][20];

extern void FUN_0003975c(int, int, int, int, int), FUN_0002c368(char *, int), FUN_00040508(int, int, int, char *, int), FUN_0004060c(int, int, char *, int);
extern void FUN_0003e404(char *, int), FUN_000405a8(int, int, char *, int), FUN_0004059c(char *), FUN_000403c8(char *, int);
extern char *FUN_0003e6f0(int), *FUN_0003e70c(int); extern int *FUN_0003f29c(int, int), FUN_00040288(char *, int);
#define CB(w, o) (*(unsigned char *)(M000718e0_iO + (w) * 0x248 + (o)))
struct PCREC { char b[0x248]; };
#define CBS(w, o) (*(unsigned char *)(M000718e0_iO + (w) * sizeof(struct PCREC) + (o))) /* STANDIN: unsigned product (sizeof) is a different expression from the int product, so the second ability loop does not share its who * 0x248 with the HP section (round 42) */
#define CC(w, o) (*(signed char *)(M000718e0_iO + (w) * 0x248 + (o)))
#define CW(w, o) (*(short *)(M000718e0_iO + (w) * 0x248 + (o)))
#define CI(w, o) (*(int *)(M000718e0_iO + (w) * 0x248 + (o)))
void FUN_00020158(int who)
{
    unsigned o; int n; int y; int k; unsigned t; int x; unsigned q; int pct; /* STANDIN: declaration order (searched) decides the 404-savings tie order: q before o in the first ability loop, the +4 before the +1 induction in the class loop */
    FUN_0003975c(0, 0x45, DAT_00057f6c + 0x38, 0x24, 2);
    DAT_00056dac = 0;
    FUN_0002c368(DAT_0005759c, 0x3a);
    FUN_00040508(0x126, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, 0x3b);
    FUN_00040508(0x15b, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, CC(who, 0x15) + 0x15);
    if (CC(who, 0x16) >= 0) {
        strcat(DAT_0005759c, "/");
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), CC(who, 0x16) + 0x15);
    }
    if (CC(who, 0x17) >= 0) {
        strcat(DAT_0005759c, "/");
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), CC(who, 0x17) + 0x15);
    }
    FUN_00040508(0x7b, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, 0x3c);
    strcat(DAT_0005759c, "  ");
    strcat(DAT_0005759c, FUN_0003e6f0(CW(who, 0x20)));
    if (CW(who, 0x22) > 0) {
        strcat(DAT_0005759c, "/");
        strcat(DAT_0005759c, FUN_0003e6f0(CW(who, 0x22)));
    }
    if (CW(who, 0x24) > 0) {
        strcat(DAT_0005759c, "/");
        strcat(DAT_0005759c, FUN_0003e6f0(CW(who, 0x24)));
    }
    FUN_00040508(0x88, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, CB(who, 0x1a) + 0x1d);
    FUN_00040508(0x95, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, CB(who, 0x14) + 0xf);
    strcat(DAT_0005759c, " ");
    FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), CB(who, 0x13) + 0x1b);
    FUN_00040508(0xa2, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    for (k = 0x2f, y = 0xb8; k != 0x35; k++, y += 0xc) {
        FUN_0002c368(DAT_0005759c, k);
        FUN_0004060c(y, DAT_00057f6c + 0xc, DAT_0005759c, 1);
    }
    for (k = 0; k < 0x100; k++) DAT_0005759c[k] = k;
    DAT_0005759c[0x1b] = 0x45;
    FUN_0003e404(DAT_0005759c, *FUN_0003f29c(1, 0));
    t = who * sizeof(struct PCREC); q = t; o = t; /* STANDIN: o and q both copies of t (q first) give record offset and stepped offset equal savings 404, so q is allocated first (esi) and t coalesces with o (edi) as in the original */
    for (k = 0, y = 0xb8; k < 6; k++, y += 0xc) {
        if (k == 0 && M000718e0_iO[o + 0x33] == 0x12 && M000718e0_iO[o + 0x3f]) sprintf(DAT_0005759c, "%02d/%02d", M000718e0_iO[q + 0x33], M000718e0_iO[o + 0x3f] % 100);
        else sprintf(DAT_0005759c, "%02d", M000718e0_iO[q + 0x33]);
        q += 2; /* STANDIN: explicit stepped record offset q instead of [who].ab[k] (the strength-reduced induction) */
        FUN_000405a8(y, DAT_00057f6c + 0x2c, DAT_0005759c, 1);
    }
    for (k = 0; k < 0x100; k++) DAT_0005759c[k] = k;
    DAT_0005759c[0x45] = 0x1b;
    FUN_0003e404(DAT_0005759c, *FUN_0003f29c(1, 0));
    for (k = 0, y = 0xb8; k < 6; k++, y += 0xc) {
        if (k == 0 && CBS(who, 0x3e)) sprintf(DAT_0005759c, "%02d/%02d", CBS(who, 0x32 + k * 2), CBS(who, 0x3e) % 100);
        else sprintf(DAT_0005759c, "%02d", CBS(who, 0x32 + k * 2));
        FUN_000405a8(y, DAT_00057f6c + 0x43, DAT_0005759c, 1);
    }
    FUN_0002c368(DAT_0005759c, 0x36);
    strcat(DAT_0005759c, " ");
    strcat(DAT_0005759c, FUN_0003e6f0(FUN_0001efa0(who)));
    FUN_00040508(0x104, DAT_00057f6c, 0x50, DAT_0005759c, 1);
    FUN_0002c368(DAT_0005759c, 0x39);
    strcat(DAT_0005759c, " ");
    strcat(DAT_0005759c, FUN_0003e6f0(CW(who, 0x1c)));
    strcat(DAT_0005759c, "/");
    strcat(DAT_0005759c, FUN_0003e6f0(CW(who, 0x1e)));
    x = DAT_00057f6c + 0x28 - FUN_00040288(DAT_0005759c, 1) / 2;
    FUN_0002c368(DAT_0005759c, 0x39);
    strcat(DAT_0005759c, " ");
    FUN_0004060c(0x112, x, DAT_0005759c, 1);
    for (k = 0; k < 0x100; k++) DAT_0005759c[k] = k;
    pct = CW(who, 0x1c) + CI(who, 0x1ea) + CI(who, 0x113); pct = (pct * 80 + (CW(who, 0x1e) >> 1)) / CW(who, 0x1e);
    if (pct > 0x50) DAT_0005759c[0x1b] = 0x1b;
    else DAT_0005759c[0x1b] = 0x43;
    FUN_0004059c(DAT_0005759c);
    FUN_000403c8(FUN_0003e6f0(CW(who, 0x1c)), 1);
    FUN_0004059c(0);
    FUN_000403c8("/", 1);
    FUN_000403c8(FUN_0003e6f0(CW(who, 0x1e)), 1);
    n = 0;
    for (k = 0; k < 3; k++) if (CC(who, 0x15 + k) >= 0) n++;
    y = 0x145 - n * 0xb / 2;
    for (k = 0; k < n; k++, y += 0xb) {
        FUN_0002c368(DAT_0005759c, CC(who, 0x15 + k) + 0x15);
        FUN_000405a8(y, DAT_00057f6c + 0x22, DAT_0005759c, 1);
        FUN_000405a8(y + 0x35, DAT_00057f6c + 0x22, DAT_0005759c, 1);
        FUN_000405a8(y, DAT_00057f6c + 0x43, FUN_0003e70c(CI(who, 0x26 + k * 4)), 1);
        FUN_000405a8(y + 0x35, DAT_00057f6c + 0x43, FUN_0003e70c(DAT_00057d9c[CC(who, 0x15 + k)][CW(who, 0x20 + k * 2)] * 1000 - CI(who, 0x26 + k * 4)), 1);
    }
}

#undef M000718e0_iO
#undef CB
#undef CBS
#undef CC
#undef CW
#undef CI
/* ---- from build/var/mod/parts/p20a70.c */
extern void FUN_0001f308(int a, int b, int c, int i); /* module prototype */
/* FUN_00020a70: draw character c's open container window, part st (1, 2: the frame; 3: the slots with their items) */
#include "world.h"
#include "records.h"
#define DAT_00057330 ((struct CONT *)&DAT_00057330)

extern struct OPENC DAT_00056fa0[];
extern int DAT_00057f6c;
extern void FUN_0003e510(int, int, int, int), FUN_00039b40(int, int, int, int, int);
void FUN_00020a70(int c, int st)
{
    int kind, type, k;
    short *p;
    int tt; /* STANDIN: named same-width temp for the kind copy: +1 pass-1 node (in-block) and one rough-sort entry; flips the t41/t42 tie at savings 162 */
    tt = DAT_00056fa0[c].kind; /* STANDIN: copy routed through tt (see declaration) */
    kind = tt;
    type = DAT_00056fa0[c].type;
    switch (st) {
    case 1:
    case 2:
        FUN_0003e510(0xc4, DAT_00057f6c, kind * 2 + 0x14 + st - 1, 2);
        break;
    case 3:
        kind += 9;
        FUN_0003e510(0xce, DAT_00057f6c, kind, 2);
        p = DAT_00057330[type].slots;
        for (k = 0; k < DAT_00057330[type].n; k++) {
            FUN_00039b40(k / DAT_00057330[type].cols * 0x22 + 0xdb, c * 80 + DAT_00057330[type].y0 + k % DAT_00057330[type].cols * 0x12, 0x20, 0x10, 0);
            if (p[k] != -1)
                FUN_0001f308(k / DAT_00057330[type].cols * 0x22 + 0xdb, c * 80 + DAT_00057330[type].y0 + k % DAT_00057330[type].cols * 0x12, ITEMS[p[k]].f2d, p[k]);
        }
        break;
    }
}

#undef DAT_00057330
/* ---- from build/var/mod/parts/p20bbc.c */
extern int FUN_0001f168(int k); /* module prototype */
extern void FUN_0001f308(int a, int b, int c, int i); /* module prototype */
extern int FUN_0001f368(int i); /* module prototype */
extern void FUN_00020a70(int c, int st); /* module prototype */
/* MATCH (round 70 lane BR, module set -3s -ox -oe -oa -ot -w0, real 10.0a): 1005/1005 standalone and in the merged module 0x1eee0. The two -oa memory nodes the plain list lacks are gone: the item-table pointer B000755d8_aw read through the level record (ITEMP, as in m307e8.c) and DAT_00057f6c read through its neighbour DAT_00057f68's address; with B000758d8_j3 as an array (lane BQ) the -oa list equals the plain list and the original registers follow (the +2 bytes were the register-choice mov/add). Before: lane BQ 1007/1005, 19 masked lines. */
/* MATCH round 65 lane AV (plain -3s -ox -oe -ot -w0, real 10.0a): 1005/1005. From lane AP's 7-line draft (r65ap/best/f20bbc.c).
   The remaining pass-1 ties (class-10 record offsets before the 0x5e m*4 temp and x, the first-block sum, the 0x5c else-arm
   load/copy pair, the 0x5e tail side*0x12 product in esi) were moved by code-neutral node edits, found with a combination
   sweep (build/var/r65av/gen.py specs side1,fd1,L64,L5c,X5e,N6,L58,C5e): side in one statement again; first-block sum in
   named locals a / b; block-local ids in the 0x64, 0x58 and 0x5c-else blocks; the 0x5e else-arm sprite through s6; the 0x5e
   x argument through x5; the 0x5e compare value named c. */
#include "world.h"
#define DAT_00056fa0 ((signed char *)DAT_00056fa0)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)

extern void FUN_0003e510(int, int, int, int), FUN_0003a258(int, unsigned char *), FUN_00039b40(int, int, int, int, int);

extern int DAT_00057f6c, B000758d8_j3[];
extern void *DAT_00057f68;
struct YV { int v; };
#define DAT_00057f6c (((struct YV *)((char *)&DAT_00057f68 + 4))->v) /* STANDIN: DAT_00057f6c read through its neighbour DAT_00057f68's address (same address and bytes): a record access is no -oa memory node */ /* STANDIN: B000758d8_j3 declared as an array - under -oa its scalar is a zero-savings memory node; read as element 0 it is none (recipe 244) */



#define RB(o) ((unsigned char)M000718e0_iO[(o) + m * 0x248])
#define RS(o) (*(short *)(M000718e0_iO + (o) + m * 0x248))
struct IP { unsigned char *p; };
#define ITEMP (((struct IP *)((char *)&B00075618_b1 - 0x40))->p) /* STANDIN: the item-table pointer B000755d8_aw read through the level record B00075618_b1 (0x75618 - 0x40 = 0x755d8, same address and bytes): a record access is no -oa memory node */
#define SPR(i) (*(short *)((ITEMP) + (i) * 0x41 + 0x2d))
void FUN_00020bbc(int m)
{
    int side, it, spr, x;
    unsigned char *g;
    side = FUN_0001f368(m) ^ 1;
    { int a, b; a = side * 2; a += 5; b = RB(0x13); b += a; FUN_0003e510(0x72, DAT_00057f6c, b, 2); } /* STANDIN: first-block sum built in named locals */
    if (RS(0x66) >= 0) FUN_0001f308(side * 0x15 + 0x72, DAT_00057f6c, SPR(6) + B000758d8_j3[0], 6);
    if (RS(0x60) >= 0) {
        it = RS(0x60);
        FUN_0001f308(0x72, DAT_00057f6c, SPR(it) + B000758d8_j3[0] + side, it);
    }
    if (RS(0x64) >= 0) {
        { int i8; i8 = RS(0x64); /* STANDIN: block-local id */
        FUN_0001f308(side * 0x13 + 0x72, DAT_00057f6c, SPR(i8) + B000758d8_j3[0], i8); }
    }
    if (RS(0x62) >= 0) {
        it = RS(0x62);
        FUN_0001f308(side * 0x14 + 0x72, DAT_00057f6c, SPR(it) + B000758d8_j3[0], it);
    }
    if (RS(0x68) >= 0) {
        int x3, i2; /* STANDIN: block-local copies of x / it for the 0x68 block, x3 declared first (slot order) */
        i2 = RS(0x68);
        spr = SPR(i2) + B000758d8_j3[0];
        g = FUN_0003f29c(spr, 1);
        x3 = side * 0x12 + 0x72;
        FUN_0001f308(x3, DAT_00057f6c, spr, i2);
        FUN_0003a258(0, g);
        FUN_0001f308(x3, 0x50 - g[6] * 8 + DAT_00057f6c, spr, i2);
        FUN_0003a258(0, g);
    }
    if (RS(0x58) >= 0) {
        FUN_00039b40(0xf8, DAT_00057f6c + 3, 0x20, 0x10, 0);
        { int i8; i8 = RS(0x58); /* STANDIN: block-local id */
        FUN_0001f308(0xf8, DAT_00057f6c + 3, SPR(i8), i8); }
    }
    if (RS(0x5a) >= 0) {
        FUN_00039b40(0xf8, DAT_00057f6c + 0x3d, 0x20, 0x10, 0);
        it = RS(0x5a);
        FUN_0001f308(0xf8, DAT_00057f6c + 0x3d, SPR(it), it);
    }
    if (RS(0x5c) >= 0) {
        int r;
        r = FUN_0001f168(RS(0x5c)); /* STANDIN: result named before x so x is built after the call */
        x = side * 0x12; x += 0x72; /* STANDIN: two statements raise x's savings above the call result r */
        if (r) FUN_0001f308(x, DAT_00057f6c, SPR(6) + B000758d8_j3[0] + 1, 6);
        else {
            int i5; i5 = RS(0x5c); /* STANDIN: block-local id */
            FUN_0001f308(x, DAT_00057f6c, SPR(i5) + B000758d8_j3[0], i5);
        }
    }
    if (RS(0x5e) >= 0) {
        int c; c = DAT_00056fa0[m * 4]; /* STANDIN: named compare value */
        if (c != -1) FUN_00020a70(m, DAT_00056fa2[m * 4]);
        else {
            if (FUN_0001f168(RS(0x5e))) {
                spr = SPR(6) + B000758d8_j3[0];
                it = 6;
                spr++; /* STANDIN (round 44): add, load 6, then inc - the original order of the then-arm */
            } else {
                int s6; it = RS(0x5e);
                s6 = SPR(it) + B000758d8_j3[0]; spr = s6; /* STANDIN: sprite through a block-local */
            }
            g = FUN_0003f29c(spr, 1);
            FUN_0003a258(0, g);
            { int x5; x5 = side * 0x12 + 0x72; FUN_0001f308(x5, 0x4f - g[6] * 8 + DAT_00057f6c, spr, it); } /* STANDIN: named x */
            FUN_0003a258(0, g);
        }
    }
}

#undef DAT_00056fa0
#undef M000718e0_iO
#undef FUN_0003f29c
#undef DAT_00057f6c
#undef RB
#undef RS
#undef ITEMP
#undef SPR
/* ---- from build/var/mod/parts/p20fac.c */
extern void FUN_00020bbc(int m); /* module prototype */
#define DAT_00056fa0 ((unsigned char *)DAT_00056fa0)
#undef DAT_00056fa2
#define DAT_00056fa2 ((unsigned char *)VIEW_DAT_00056fa2)
/* (FUN_00020108: defined in this module) */
/* Round 69 lane BQ: the static helper is gone - its out-of-line copy shifted the module (every static is emitted, also ahead of the first function); the call goes to the module's own FUN_00020108, which the compiler expands in line (defined earlier, <= 20 nodes). The copy of FUN_00020108 ahead of the function is the module's own definition (src/CODE2/f20108.c): it goes away when module 0x1eee0 becomes one module file. */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;

/* Round 37 (real 10.0a, module m1eee0 plain): the static show is FUN_00020108 expanded; in the merged module `FUN_00020108(DAT_00058600, DAT_00058602, 0xc4, k * 0x50, 100, 0x50);` (the following ^= 1 is the callee's) leaves every matched function unchanged and moves FUN_00020bbc from 1076 to 1004/1005 bytes (show's copy sat in its extent); this function stays 336/264 (structural). */
/* FUN_00020fac @ 00020fac: start portrait animation of slot k (face a, b, c): preload frames, then play four frames */
extern void *FUN_0003f29c(int, int); extern void FUN_000391b0(unsigned char), FUN_0002a724(int, short, unsigned char, int, int, int, int);
extern unsigned char DAT_00058602; extern short DAT_00058600; extern int DAT_0005c050, DAT_0005bf44;
void FUN_00020fac(int k, int a, int b, int c)
{
    int r, i;
    DAT_00056fa0[k * 4] = a;
    DAT_00056fa1[k * 4] = b;
    DAT_00056fa3[k * 4] = c;
    for (r = 0; r < 4; r++) FUN_0003f29c(a * 2 + 0x14 + r, 2);
    for (i = 0; i <= 3; i++) {
        FUN_000391b0(DAT_0005c050);
        DAT_00056fa2[k * 4] = i;
        FUN_00020bbc(k);
        FUN_00020108(DAT_00058600, DAT_00058602, 0xc4, k * 0x50, 100, 0x50);
    }
}

#undef DAT_00056fa0
#undef DAT_00056fa2
#define DAT_00056fa2 VIEW_DAT_00056fa2
/* ---- from build/var/mod/parts/p210b4.c */
extern void FUN_00020bbc(int m); /* module prototype */
/* (FUN_00020108: defined in this module) */
/* Round 71 lane FC: MATCH under the module set -3s -ox -oe -oa -ot -w0 (standalone and in the scratch merge). The call goes to the module's own FUN_00020108, expanded in line (the copy below is the module's definition, src/CODE2/f20108.c; it goes away when module 0x1eee0 becomes one module file). The code was right since round 69; left was the savings-122 tie of the expansion's parameter temps (x must be allocated before w, w before y: EDX / ECX / EDI) and, once that is right, the frame order of the three temps without a register (c, spr, h). Both follow from the order in which the FIRST RoughSortTemps leaves the six parameter temps (all rough savings 40): pass 1 takes its cross-block nodes in the reverse of that order, the slot sort takes its input from it. Three dead helper locals (a, b, c below) are entries of that first sort only: their stores survive InsDead (the helper is read by a later store), are counted by RoughSortTemps, and are deleted by AxeDeadCode before pass 1, so they add no node, no slot and no code. Found with a model of both sorts and of the slot sort (build/var/r71fc/m3.py, slot.py; each reproduces the real lists), then compiled once. In that model nothing smaller works: 0-2 such entries with 0-6 -oa memory nodes, memory-node counts 0-29 alone, dead stores to k / base / idx / i alone, entry-block spellings and declaration orders give no order with both the registers and the slots right (14 memory nodes give the registers but the slots c / h / spr rotated - compiled, p14a.c). */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;

/* FUN_000210b4 @ 000210b4: turn the portrait of party member i through its four frames */
extern void FUN_000391b0(unsigned char), FUN_0002a724(int, short, unsigned char, int, int, int, int);
extern int DAT_0005c050, DAT_0005bf44; extern short DAT_00058600; extern unsigned char DAT_00058602;
#include "records.h"
#define DAT_00056fa0 ((unsigned char *)DAT_00056fa0)
#undef DAT_00056fa2
#define DAT_00056fa2 ((unsigned char *)VIEW_DAT_00056fa2)
extern struct CURSOR DAT_000585fc;
void FUN_000210b4(int i)
{
    int a; /* STANDIN: dead helper declared ahead of k - a first-rough-sort entry (savings 23) between t7 and k */
    int k = 3, base = i * 80, idx = i * 4;
    int b, c; /* STANDIN: dead helpers declared after idx - two first-rough-sort entries (savings 41 each) between idx and i */
    do {
        FUN_000391b0(DAT_0005c050);
        DAT_00056fa2[idx] = k;
        FUN_00020bbc(i);
        a = k; b = k; c = k; /* STANDIN: dead stores, one loop reference each (rough +20); deleted by AxeDeadCode */
        FUN_00020108(DAT_000585fc.id, DAT_00058602, 0xc4, base, 100, 0x50);
        b = k; c = k; /* STANDIN: second loop reference of b and c (rough 40) */
        k--;
    } while (k >= 0);
    DAT_00056fa0[idx] = 0xff;
    DAT_00056fa1[idx] = 0xff;
    DAT_00056fa3[idx] = 0xff;
    base = a; a = b; a = c; /* STANDIN: dead reads that keep a, b, c past InsDead (rough +1 each; base is dead here) */
}

#undef DAT_00056fa0
#undef DAT_00056fa2
#define DAT_00056fa2 VIEW_DAT_00056fa2
/* ---- from build/var/mod/parts/p2118c.c */
extern void FUN_0001f308(int a, int b, int c, int i); /* module prototype */
extern void FUN_00020bbc(int m); /* module prototype */
/* Round 69 lane BQ: matches under the module set -3s -ox -oe -oa -ot -w0 (and plain -ot) with p initialised ahead of the loop. */
/* FUN_0002118c @ 0002118c: draw the inventory panel of party member i: the 12 carried items in a 4 x 3 grid */
/* In module 0x1eee0 (-ox -oe -ot, 2026-11-10): matches only without -ot (file flags -ox -oe). Under -ot the je over the
   loop body to the increment is a near jump (6 bytes, 224/220); every other byte is equal. The loop has a known
   count of 12, and with -ot the code generator aligns labels of such loops (cg DepthAlign), so the jump is sized
   for the worst case. Q1-Q4 do not apply (no register differs). Tried: without the volatile reread (the read is
   then CSE'd: 217/220), the reread through the record address instead of p (worse). Blocked; the volatile is a
   workaround (recipe 2) and the cause of the reread is open. */
#include "world.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
extern void FUN_0003975c(int, int, int, int, int), FUN_0003e510(int, int, int, int);
extern int DAT_00057f6c; 
void FUN_0002118c(int i)
{
    short *p; int k, m;
    FUN_0003975c(0, 0x45, DAT_00057f6c + 0x38, 1, 2);
    FUN_0003e510(0x128, DAT_00057f6c, 4, 2);
    p = (short *)(M000718e0_iO + i * 0x248 + 0x40); /* STANDIN: p set ahead of the for, not in its init - with -ot the skip jump to the increment is then sized short as in the original */
    for (k = 0; k < 0xc; k++, p++) {
        if (*p != -1) {
            m = *p * 0x41;
            if (*(volatile short *)p == 0xa6) FUN_0003975c(0, 0x127, DAT_00057f6c, *(short *)(((char *)B000755d8_aw) + m + 0x2d), 1);
            else FUN_0001f308(k / 4 * 0x22 + 0x129, DAT_00057f6c + 5 + k % 4 * 0x12, *(short *)(((char *)B000755d8_aw) + m + 0x2d), *p);
        }
    }
    FUN_00020bbc(i);
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p21268.c */
extern void FUN_0001ff3c(int i); /* module prototype */
extern void FUN_00020158(int who); /* module prototype */
extern void FUN_0002118c(int i); /* module prototype */
/* FUN_00021268 @ 00021268: redraw a party member's portrait area */
#include "chars.h"
extern void FUN_0003e510(int, int, int, int); extern void FUN_0003e374(int, int, int, int, unsigned char);
extern int DAT_00056f90[], DAT_00057f6c, DAT_00057f70;
void FUN_00021268(int i)
{
    if (*(unsigned short *)(CHAR_REC(i) + 0x10) & 0x8000) FUN_0003e510(0, DAT_00057f6c, 2, 2);
    else {
        FUN_0001ff3c(i);
        if (DAT_00056f90[i]) FUN_00020158(i);
        else FUN_0002118c(i);
    }
    if (i == DAT_00057f70) FUN_0003e374(0, i * 80, 0x190, 0x50, 0x1a);
}

/* ---- from build/var/mod/parts/p212ec.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern void FUN_00021268(int i); /* module prototype */
/* (FUN_000200c8: defined in this module) */
/* Round 69 lane BQ: the static helper is gone - its out-of-line copy shifted the module (every static is emitted, also ahead of the first function); the call goes to the module's own FUN_000200c8, which the compiler expands in line (defined earlier, <= 20 nodes). The copy of FUN_000200c8 ahead of the function is the module's own definition (src/CODE2/f200c8.c): it goes away when module 0x1eee0 becomes one module file. */
extern void FUN_0002a5b0(int, short, unsigned char); extern int DAT_0005bf44, DAT_0005c050;

/* Round 53 (module 0x1eee0 plain, 6 compiles + trace): with the static H replaced by FUN_000200c8 (expanded): 8 lines, the spr / c parameter temps of the expansion exchanged (t10 / t12 at 46): tw.py accepts removing the loop's constant 4, k, t6, t11 or several 46-temps, or inserting at 5-10. k in a block / do-while loop (8), the FUN_0004104c result in a local p before or after the store (8 / 10), assignment inside the argument (14). */
/* Round 37 (real 10.0a, module m1eee0 plain): in the merged module the static H is a device: with H removed and the call written as FUN_000200c8(DAT_00058600, DAT_00058602) (expanded, recipe 26) FUN_00021268 matches in the module as well (37 -> 38/56: H's out-of-line copy had shifted it); FUN_000212ec itself stays at 27 lines (class C: spr's load must take EBX, which k held in the loop; forcing the 46-group, 400 orders: 27). This file keeps H because alone it cannot see FUN_000200c8's body (the module file would). */
/* FUN_000212ec @ 000212ec: redraw the four party portraits, rebuild the side panel and show the page */
/* In module 0x1eee0 (-ox -oe -ot, 2026-11-10): H plus the following `DAT_0005c050 ^= 1` is FUN_000200c8(DAT_00058600,
   DAT_00058602) expanded (recipe 26; FUN_000200c8 and FUN_00020108 are never called in the original, only expanded).
   The static copy H is emitted in the module and shifts its neighbours. With the call to the module's FUN_000200c8
   and its second parameter `unsigned c` (it still matches alone; with `unsigned char c` the byte is loaded with
   mov bl) only the registers of spr/c are swapped (original spr ebx, c eax): Q1 no clobber; Q2 equal; Q3 order of
   the two parameter temporaries of the expansion; Q4 -. Without -oa; with -oa the H form matches. Tried 3
   (real call, unsigned c, int c). Not changed: needs FUN_000200c8 visible, which the file cannot hold alone. */
extern void FUN_000391b0(unsigned char), FUN_000392bc(void *, int, int, int, int), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void);
extern void *FUN_0004104c(int);
extern int DAT_0005c050, DAT_00057f6c, DAT_0005bf44; extern void *DAT_00057f68; extern short DAT_00058600; extern unsigned char DAT_00058602, DAT_0005d680[]; /* STANDIN: DAT_0005d680 declared as an array - under -oa its scalar is a zero-savings memory node that puts t6 ahead of t11 in their tie; the element is none (recipe 244) */
void FUN_000212ec(void)
{
    int k;
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 4; k++) {
        DAT_00057f6c = k * 0x50;
        FUN_00021268(k);
    }
    DAT_00057f68 = FUN_0004104c(0x1400);
    FUN_000392bc(DAT_00057f68, 0x62, 0, 0x10, 0x140);
    FUN_0001f790(DAT_00058600, DAT_00058602);
    FUN_000200c8(DAT_00058600, DAT_00058602);
    FUN_00032d70();
    DAT_0005d680[0] = 1; /* STANDIN: element 0 of the array view */
}

/* ---- from build/var/mod/parts/p213ac.c */
extern int FUN_0001f5f8(int t); /* module prototype */
/* (FUN_0001f290, FUN_000213ac: defined in this module) */
/* LAYOUT-ONLY copies of the module's FUN_0001f290 (src/CODE2/f1f290.c, expanded in line) and FUN_000213ac (src/CODE2/f213ac.c: the original's jump table of FUN_00021404 follows it directly) */

#define FLAGS(i) (*((unsigned char *)&DAT_00057339 + (i) * 10))

int FUN_000213ac(unsigned a, int b)
{
    int r = 0;
    switch (a) {
    case 0: if (b == 5 || b == 3) r = 1; break;
    case 1: if (b != 1 && b != 6 && b != 2) r = 1; break;
    case 2: if (b != 2) r = 1; break;
    }
    return r;
}



/* FUN_00021404: put item n into slot k of the container held in character c's inventory slot s */
#include "world.h"
#include "records.h"
#define DAT_00057330 ((struct CONT *)&DAT_00057330)
#define M000718e0_iO ((struct PC *)&B000718e0_iO)


extern void FUN_000391b0(unsigned char);
extern int FUN_000213ac(unsigned, int);
extern int DAT_0005c050;
int FUN_00021404(int c, int s, int n, int f)
{
    int t, k, w;
    short *p;
    t = M000718e0_iO[c].inv[s];
    t = ITEMS[t].sub;
    p = DAT_00057330[t].slots;
    if (n != -1) {
        switch (DAT_00057330[t].kind) {
        case 3: if (ITEMS[n].cls != 0xd) return 0; break;
        case 4: if (ITEMS[n].cls != 0xe) return 0; break;
        case 5: if (ITEMS[n].cls != 0xc) return 0; break;
        case 6: if (ITEMS[n].cls != 0xf) return 0; break;
        }
    }
    if (DAT_00057330[t].kind >= 2 || n == -1 || !ITEMS[n].kind) {
        if (n != -1 && ITEMS[n].cls == 1 && n != 0x50 && !FUN_000213ac(DAT_00057330[t].kind, DAT_00057330[ITEMS[n].sub].kind)) return 0;
        if (DAT_00057330[t].kind == 4 && (n == 0x114 || n == 0x115 || n == 0x128)) return 0;
        for (k = 0; k < DAT_00057330[t].n; k++)
            if (p[k] == -1) break;
        if (k == DAT_00057330[t].n) return 0;
        w = FUN_0001f5f8(t);
        w -= ITEMS[t].wt;
        if (n != -1) {
            if (ITEMS[n].cls == 1) w += FUN_0001f5f8(ITEMS[n].sub);
            w += ITEMS[n].wt;
        }
        if (w > DAT_00057330[t].maxw * 2) return 0;
        FUN_000391b0(DAT_0005c050);
        p[k] = n;
        FUN_0001f290(t, k, f);
        return 1;
    }
    return 0;
}

#undef DAT_00057330
#undef M000718e0_iO
#undef FLAGS
/* ---- from build/var/mod/parts/p21630.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
 

/* FUN_00021630 @ 00021630: character c reads the mage scroll item n: learn the spell into its empty cell, or say why not; 1 when learnt */
#include <stdio.h>
#include <string.h>
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)

extern void FUN_0002c124(int), FUN_0002c368(char *, int);
extern unsigned FUN_00040700(void);
extern char DAT_0005759c[], *DAT_00056d9c, *DAT_00056da0, *DAT_00056da4;
extern unsigned char DAT_00056153[], DAT_00056dac, DAT_00058602;
extern unsigned DAT_00056da8;
extern short DAT_00058600;
int FUN_00021630(int c, int n)
{
    int range[6][2] = { { 173, 167 }, { 179, 174 }, { 189, 180 }, { 193, 190 }, { 195, 194 }, { 201, 196 } };
    int lvl, k, cnt, idx, max, sp;
    for (lvl = 0; lvl < 6; lvl++) {
        if (n <= range[lvl][0]) {
            idx = n - range[lvl][1];
            break;
        }
    }
    FUN_0002c124(0xba);
    for (cnt = k = 0; k < 10; k++)
        if (M000718e0_iO[c].mage[lvl][k].lo != 0xf) cnt++;
    max = DAT_00056153[M000718e0_iO[c].ab[6]];
    if (cnt == max) {
        sprintf(DAT_0005759c, DAT_00056d9c);
    } else if (M000718e0_iO[c].mage[lvl][idx].lo == 0xf) {
        sp = lvl * 10 + 0x42;
        sp += idx;
        FUN_0002c368(DAT_0005759c, sp);
        strcat(DAT_0005759c, DAT_00056da0);
        DAT_00056dac = 1;
        DAT_00056da8 = FUN_00040700() + 0x36;
        FUN_0001f790(DAT_00058600, DAT_00058602);
        M000718e0_iO[c].mage[lvl][idx].lo = 0;
        M000718e0_iO[c].mage[lvl][idx].hi = 0;
        return 1;
    } else {
        sprintf(DAT_0005759c, DAT_00056da4);
    }
    DAT_00056dac = 1;
    { unsigned v; v = FUN_00040700() + 0x36; DAT_00056da8 = v; } /* STANDIN: the time through a named temp - one more in-block node ahead of the -oa memory nodes puts the hoisted lvl * 10 ahead of idx (idx to the frame as in the original) */
    FUN_0001f790(DAT_00058600, DAT_00058602);
    return 0;
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p217a0.c */
extern void FUN_0001f238(int i, int bit, int val); /* module prototype */
extern int FUN_0001f2d4(int i, int v); /* module prototype */
extern void FUN_0001f308(int a, int b, int c, int i); /* module prototype */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern void FUN_0001fed0(int a); /* module prototype */
extern void FUN_00020bbc(int m); /* module prototype */
extern int FUN_00021404(int c, int s, int n, int f); /* module prototype */
extern int FUN_00021630(int c, int n); /* module prototype */


extern void FUN_0002a5b0(int, short, unsigned char); extern int DAT_0005bf44, DAT_0005c050;

/* FUN_000217a0: exchange the item in hand with character i's inventory slot s */
#include "world.h"
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)

extern struct CURSOR DAT_000585fc;
extern int DAT_00057f6c;
extern void FUN_000391b0(unsigned char), FUN_0002a344(short, unsigned char), FUN_0002c124(int);
extern void FUN_00039b40(int, int, int, int, int);
extern void FUN_00013a78(int, int);
extern int FUN_000150dc(int, int);
void FUN_000217a0(int i, int s, int mode)
{
    unsigned it, h;
    int hf, f, y, x, r;
    it = M000718e0_iO[i].inv[s];
    f = FUN_0001f218(i, s);
    h = DAT_000585fc.id;
    hf = DAT_000585fc.f;
    if (it >= 0x7e && it <= 0x86) return;
    r = FUN_0001f2d4(i, 0x48);
    if (it == 0xa6) {
        if (h >= 0xa7 && h <= 0xc9 && FUN_00021630(i, h)) {
            FUN_0002a344(-1, 0);
            FUN_0001f790(-1, 0);
        }
        return;
    }
    if (it == 0x35 && h >= 0x61 && h <= 0x64) {
        FUN_0002c124(h - 0x61);
        FUN_0002a344(-1, 0);
        FUN_0001f790(-1, 0);
        return;
    }
    if (h != -1 || it != -1) {
        FUN_000391b0(DAT_0005c050);
        if (h != -1 && it != -1 && ITEMS[it].cls == 1 && mode && FUN_00021404(i, s, h, hf)) {
            FUN_0001fed0(i);
            FUN_0001f790(-1, 0);
            FUN_000200c8(-1, 0);
            return;
        }
        M000718e0_iO[i].inv[s] = h;
        FUN_0001f238(i, s, hf);
        if (s < 12) {
            y = s / 4 * 0x22 + 0x129;
            x = DAT_00057f6c + 5 + s % 4 * 0x12;
            FUN_00039b40(y, x, 0x20, 0x10, 0);
            if (h != -1) FUN_0001f308(y, x, ITEMS[h].f2d, M000718e0_iO[i].inv[s]);
        } else FUN_00020bbc(i);
        FUN_0001fed0(i);
        FUN_0001f790(it, f);
        if (it != -1) FUN_000200c8(it, f);
        else FUN_000200c8(-1, 0);
    }
    if (!FUN_0001f2d4(i, 0x48) && r == 1 && FUN_000150dc(1, i))
        FUN_00013a78(i, M000718e0_iO[i].lvl[FUN_000150dc(1, i)]);
    if (M000718e0_iO[i].inv[14] == 0x67 || M000718e0_iO[i].inv[15] == 0x67) M000718e0_iO[i].f132 |= 0x400000;
    else M000718e0_iO[i].f132 &= ~0x400000;
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p21ad8.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern void FUN_00021268(int i); /* module prototype */
/* (FUN_000200c8, FUN_00020108: defined in this module) */
/* round 62 second blind rewrite; the copies of FUN_000200c8 / FUN_00020108 are the module definitions, expanded in line here */
/* LAYOUT-ONLY copies of the module's expanded callees (src/CODE2/f200c8.c, f20108.c) */
extern void FUN_0002a5b0(int, short, unsigned char), FUN_0002a724(int, short, unsigned char, int, int, int, int);
extern int DAT_0005bf44, DAT_0005c050;


#include "records.h"
extern void FUN_000391b0(unsigned char);
extern int DAT_00056f90[], DAT_00057f6c;
extern struct CURSOR DAT_000585fc;
void FUN_00021ad8(int i, int mode)
{
    int k, v;
    if (mode & 2) {
        v = DAT_00056f90[i] ^ 1;
        FUN_000391b0(DAT_0005c050);
        for (k = 0; k < 4; k++) {
            DAT_00057f6c = k * 0x50;
            DAT_00056f90[k] = v;
            FUN_00021268(k);
        }
    } else {
        DAT_00056f90[i] ^= 1;
        FUN_000391b0(DAT_0005c050);
        FUN_00021268(i);
    }
    FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
    if (mode & 2) FUN_000200c8(DAT_000585fc.id, DAT_000585fc.f);
    else FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0, DAT_00057f6c, 400, 0x50);
}

/* ---- from build/var/mod/parts/p21c20.c */
extern int FUN_0001f5f8(int t); /* module prototype */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern void FUN_00020bbc(int m); /* module prototype */


/* FUN_00021c3c: click at (x, y) in character i's open container window: exchange the item in hand with the slot */
#include "world.h"
#include "records.h"
#define DAT_00057330 ((struct CONT *)&DAT_00057330)

extern struct OPENC DAT_00056fa0[];
extern struct CURSOR DAT_000585fc;
extern int DAT_00056f90[];
extern void FUN_000391b0(unsigned char);

/* layout-only copy of src/CODE2/f21c20.c: the original's jump table of FUN_00021c3c follows it directly */
int FUN_00021c20(int mode) { return (mode & 2) == 0; }



int FUN_00021c3c(int i, int x, int y, int mode)
{
    int h, of, row, s, t, w, hf, o;
    short *p;
    if ((mode & 2) || DAT_00056f90[i]) return 0;
    t = DAT_00056fa0[i].type;
    p = DAT_00057330[t].slots;
    if (y >= DAT_00057330[t].y0 && y <= DAT_00057330[t].y0 + DAT_00057330[t].cols * 0x12) {
        hf = DAT_000585fc.f;
        h = DAT_000585fc.id;
        if (h != -1) {
            switch (DAT_00057330[t].kind) {
            case 3: if (ITEMS[h].cls != 0xd) return 1; break;
            case 4: if (ITEMS[h].cls != 0xe) return 1; break;
            case 5: if (ITEMS[h].cls != 0xc) return 1; break;
            case 6: if (ITEMS[h].cls != 0xf) return 1; break;
            }
        }
        if (DAT_00057330[t].kind >= 2 || h == -1 || ITEMS[h].kind < 2) {
            if (h == -1 || ITEMS[h].cls != 1 || DAT_00057330[ITEMS[h].sub].kind != DAT_00057330[t].kind) {
                s = (x - 0xdb) / 0x22;
                s *= DAT_00057330[t].cols; /* STANDIN: ahead of the row division, the cols load conflicts with the idiv registers so the 0x12 divisor and y take ECX as in the original */
                row = (y - DAT_00057330[t].y0) / 0x12;
                if (row >= DAT_00057330[t].cols) return 1; /* STANDIN: an extra def of the return-value temp t9 (savings 16 -> 18, sorted ahead of the t*10 product t21), so EAX is given first and the product takes EAX */
                {
                    s += row;
                    if (s < DAT_00057330[t].n) {
                        o = p[s];
                        of = FUN_0001f274(t, s);
                        if (h != -1 || o != -1) {
                            w = FUN_0001f5f8(t);
                            w -= ITEMS[DAT_00056fa0[i].item].wt;
                            if (o != -1) {
                                if (ITEMS[o].cls == 1) w -= FUN_0001f5f8(ITEMS[o].sub);
                                w -= ITEMS[o].wt;
                            }
                            if (h != -1) {
                                if (ITEMS[h].cls == 1) w += FUN_0001f5f8(ITEMS[h].sub);
                                w += ITEMS[h].wt;
                            }
                            if (w <= DAT_00057330[t].maxw * 2) {
                                FUN_000391b0(DAT_0005c050);
                                p[s] = h;
                                FUN_0001f290(t, s, hf);
                                FUN_00020bbc(i);
                                FUN_0001f790(o, of);
                                if (o != -1) FUN_000200c8(o, of);
                                else FUN_000200c8(-1, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

#undef DAT_00057330
/* ---- from build/var/mod/parts/p21fb0.c */
extern void FUN_000217a0(int i, int s, int mode); /* module prototype */
/* FUN_00021fb0 @ 00021fb0: click on the spell grid of member a at (b, c): select the cell (early return 0, the index accumulated as idx = row * 4; idx += col) */
 extern int DAT_00056f90[];
int FUN_00021fb0(int a, int b, int c, int d)
{
    int idx;
    if ((d & 2) || DAT_00056f90[a] != 0) return 0;
    idx = (b - 0x129) / 0x22 % 0x20 * 4;
    idx += (c - 5) / 0x12 % 0x10;
    FUN_000217a0(a, idx, 1);
    return 1;
}

/* ---- from build/var/mod/parts/p2202c.c */
/* FUN_0002202c @ 0002202c: add n levels/charges, capped at 20 */
#include "chars.h"
#define B00071a96_av (*(int *)((char *)&B000718e0_iO + 438)) /* STANDIN: view, B000718e0_iO + 0x1b6 */
#define B00071948_au (*(short *)((char *)&B000718e0_iO + 104)) /* STANDIN: view, B000718e0_iO + 0x68 */
  
#define CH68(i)  (*(short *)((char *)&B00071948_au + (i) * 0x248))
#define CH33(i)  (*((unsigned char *)&B00071913_a2 + (i) * 0x248))
#define CH1B6(i) (*(int *)((char *)&B00071a96_av + (i) * 0x248))
int FUN_0002202c(int i, int n)
{
    if (CH68(i) == 0x54) {
        if (CH1B6(i) + n > 0x14) n = 0x14 - CH1B6(i);
        CH1B6(i) += n;
        return n;
    }
    if (CH33(i) + n > 0x14) n = 0x14 - CH33(i);
    CH33(i) += n;
    return n;
}

#undef CH68
#undef CH33
#undef CH1B6
/* ---- from build/var/mod/parts/p22098.c */
/* FUN_00022098 @ 00022098 */
  
int FUN_00022098(int i)
{
    if (*(short *)((char *)&B00071948_au + i * 0x248) == 0x54)
        return *(int *)((char *)&B00071a96_av + i * 0x248);
    return *((unsigned char *)&B00071913_a2 + i * 0x248);
}

/* ---- from build/var/mod/parts/p220bc.c */
/* FUN_000220bc @ 000220bc: class change bookkeeping */
#include "chars.h"
#define B00071915_a0 (*(unsigned char *)((char *)&B000718e0_iO + 53)) /* STANDIN: view, B000718e0_iO + 0x35 */
 
#define CH33(i)  (*((unsigned char *)&B00071913_a2 + (i) * 0x248))
#define CH35(i)  (*((unsigned char *)&B00071915_a0 + (i) * 0x248))
#define CH1B6(i) (*(int *)((char *)&B00071a96_av + (i) * 0x248))
void FUN_000220bc(int i, int old, int new)
{
    int t;
    if (old == 0x54) CH33(i) = CH1B6(i);
    if (new == 0x54) { t = CH33(i); CH33(i) = 0x14; CH1B6(i) = t; }
    if (old == 0x53) CH35(i)--;
    if (new == 0x53) CH35(i)++;
}

#undef CH33
#undef CH35
#undef CH1B6
/* ---- from build/var/mod/parts/p22128.c */
int FUN_00022128(int k)
{
    if (FUN_0001f2b4(k) || k == 0xc || k == 0xec || k == 0xee) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p22180.c */
extern int FUN_0001f168(int k); /* module prototype */
extern void FUN_00020fac(int k, int a, int b, int c); /* module prototype */
extern void FUN_000210b4(int i); /* module prototype */
extern void FUN_000217a0(int i, int s, int mode); /* module prototype */
extern void FUN_000220bc(int i, int old, int new); /* module prototype */
extern int FUN_00022128(int k); /* module prototype */
/* FUN_00022180 @ 00022180: drop the item in hand on character c's paper doll at (x, y), or pick the item under (x, y) when the hand is empty; 1 when a slot was used */
/* In module 0x1eee0 (-ox -oe -ot, 2026-11-10): matches only under -oa (490 lines without, from the first item-table
   access on). Not attempted this round. */
#include "world.h"
#define M000718f5_h2 ((signed char *)&B000718f5_h2)
#define M00071920_bM ((short *)&B00071920_bM)
#pragma pack(1)
struct I { char pad[0x2f]; unsigned char type, weight; signed char kind; char p2[3]; unsigned char flags; char rest[0xb]; };
#pragma pack()
struct HS { int slot, mask, x0, y0, x1, y1; };
extern struct HS *B00062c00_hH; extern int DAT_00056f90[]; extern short DAT_00058600;
 
#define B000718f6_h5 (*(signed char (*)[])((char *)&B000718e0_iO + 22)) /* STANDIN: view, B000718e0_iO + 0x16 */
 
extern int FUN_00033eac(int, int);

int FUN_00022180(int c, int x, int y, int mask)
{
    int s, it, k, v;
    s = -1;
    if ((mask & 2) || DAT_00056f90[c]) return 0;
    it = DAT_00058600;
    if (it != -1) {
        switch (((unsigned char *)B000755d8_aw)[it * 0x41 + 0x2f]) {
        case 3: s = 0x11; break;
        case 4:
            s = 0x10;
            if (M000718f5_h2[c * 0x248] == 4 && B000718f6_h5[c * 0x248] == -1) s = -1;
            if (FUN_00033eac(c, 5) && !FUN_00022128(it)) s = -1;
            break;
        case 8: s = 0x10; break;
        case 6: s = 0x12; break;
        case 7: s = 0x14; break;
        case 5: if (y <= 0x28) s = 0xc; else s = 0xd; break;
        default:
            if (y <= 0x28) { s = 0xe; if (FUN_0001f168(it)) s = 0x13; }
            else s = 0xf;
            break;
        }
    } else {
        for (k = 0; k < 10; k++) {
            if (x >= B00062c00_hH[k].x0 && x <= B00062c00_hH[k].x1 && y >= B00062c00_hH[k].y0 && y <= B00062c00_hH[k].y1 && (mask & B00062c00_hH[k].mask)
                && *(short *)((char *)M00071920_bM + (B00062c00_hH[k].slot * 2 + c * 0x248)) != -1) {
                s = B00062c00_hH[k].slot;
                break;
            }
        }
    }
    if (s == -1) return 0;
    v = *(short *)((char *)M00071920_bM + (s * 2 + c * 0x248));
    if ((unsigned)v >= 0x7e && (unsigned)v <= 0x86) return 0;
    if (s == 0xf || s == 0xe) {
        if (s == 0xf && ((unsigned char *)B000755d8_aw)[v * 0x41 + 0x2f] == 1) FUN_000210b4(c);
        FUN_000217a0(c, s, 0);
        if (s == 0xf && ((struct I *)((unsigned char *)B000755d8_aw))[it].type == 1)
            FUN_00020fac(c, DAT_00057334[((struct I *)((unsigned char *)B000755d8_aw))[it].kind * 10], ((struct I *)((unsigned char *)B000755d8_aw))[it].kind, it);
    } else {
        if (s == 0x14) FUN_000220bc(c, v, it);
        FUN_000217a0(c, s, 1);
    }
    return 1;
}

#undef M000718f5_h2
#undef M00071920_bM
#pragma pack()
/* ---- from build/var/mod/parts/p22470.c */
extern void FUN_00021268(int i); /* module prototype */
/* Round 69 lane BQ: converted to the module set -3s -ox -oe -oa -ot -w0 (two copies out and back below). Before: MATCH (round 65 lane AW) FUN_00022470, module 0x1eee0 plain -3s -ox -oe -ot -w0, 691/691 (realcc). From the b1 draft (c/e byte tie): t = a * 0x50 copied through t2 (+1 in-block node, t web savings 94 -> 88), the first a * 0x50 argument as (a + a * 4) << 4 (same lea/add/shl, other multiply temps), and the declaration order pb, tmp, b, k, c, pa, u, e, t (t2 last; searched with the r64ak model). */
#include "world.h"
#define DAT_00056fa0 ((unsigned char (*)[4])DAT_00056fa0)
#define M000718e0_iO ((unsigned char *)&B000718e0_iO)
void *memmove(void *, const void *, unsigned);
struct OB { unsigned short lo : 11, owner : 3, hi : 2; char rest[0x14]; };
extern void FUN_0002a8c8(int, int, int, int, int), FUN_000410b0(void *), FUN_00032d70(void); extern void FUN_000391b0(unsigned char);
extern int FUN_0002a1f4(void);
extern void *FUN_0004104c(int);
extern int DAT_0005c050; extern unsigned char DAT_0005d681, DAT_0005d682;
extern int DAT_00057f70, DAT_00057f6c, DAT_00056f90[], DAT_0005c038;
extern short DAT_00059e33;
extern unsigned char B000748ec_bk[];
#define B00074900_bn ((struct OB *)((char *)&B000748ec_bk + 20)) /* STANDIN: view, B000748ec_bk + 0x14 */
extern unsigned char B00067618_e7[];
#define B0006762c_ey ((struct OB *)((char *)&B00067618_e7 + 20)) /* STANDIN: view, B00067618_e7 + 0x14 */

void FUN_00022470(int a)
{
    unsigned char *pb; /* STANDIN: declaration order pb, tmp, b, k, c, pa, u, e, t (pass-1 tie order) */
    unsigned char *tmp;
    int b;
    int k;
    unsigned char c;
    unsigned char *pa;
    int u;
    unsigned char e;
    int t;
    int t2; /* STANDIN: copy-through temp for t */
    FUN_000391b0(DAT_0005c050);
    DAT_00057f70 = a;
    FUN_00021268(a);
    FUN_0002a8c8(DAT_0005c050, 0, (a + a * 4) << 4, 0x190, 0x50); /* STANDIN: a * 0x50 spelled as its lea/add/shl expansion (other temps) */
    while (FUN_0002a1f4());
    while (!FUN_0002a1f4());
    b = DAT_00059e33 / 0x50;
    DAT_00057f70 = -1;
    if (b == a) {
        FUN_00021268(a);
        FUN_0002a8c8(DAT_0005c050, 0, a * 0x50, 0x190, 0x50);
    } else {
        DAT_0005d681 = 0;
        DAT_0005d682 = 0;
        tmp = FUN_0004104c(0x248);
        pa = M000718e0_iO + a * 0x248;
        memmove(tmp, pa, 0x248);
        pb = M000718e0_iO + b * 0x248;
        memmove(pa, pb, 0x248);
        memmove(pb, tmp, 0x248);
        FUN_000410b0(tmp);
        t = DAT_00056f90[b];
        u = DAT_00056f90[a];
        DAT_00056f90[a] = t;
        { int x; x = u; u = x; } /* STANDIN: copy out and back on u - u leaves the savings-86 tie under -oa (u EAX, t EBX as in the original) */
        DAT_00056f90[b] = u;
        for (k = 0; k < 4; k++) {
            c = DAT_00056fa0[a][k];
            e = DAT_00056fa0[b][k];
            { unsigned char x; x = c; c = x; } /* STANDIN: copy out and back on c (loop depth 1) - c rises past e in the savings-162 byte tie under -oa (c BL, e BH as in the original) */
            DAT_00056fa0[a][k] = e;
            DAT_00056fa0[b][k] = c;
        }
        t2 = a * 0x50; t = t2; /* STANDIN: copy through t2 (+1 in-block node) */
        DAT_00057f6c = t;
        FUN_00021268(a);
        FUN_0002a8c8(DAT_0005c050, 0, t, 0x190, 0x50);
        t = b * 0x50;
        DAT_00057f6c = t;
        FUN_00021268(b);
        FUN_0002a8c8(DAT_0005c050, 0, t, 0x190, 0x50);
        for (k = 0; k < DAT_0005c038; k++) {
            if (B00074900_bn[k].owner == (unsigned short)a) B00074900_bn[k].owner = b;
            else if (B00074900_bn[k].owner == (unsigned short)b) B00074900_bn[k].owner = a;
        }
        for (k = 0; k < B00075618_b1.n4; k++) {
            if (B0006762c_ey[k].owner == (unsigned short)a) B0006762c_ey[k].owner = b;
            else if (B0006762c_ey[k].owner == (unsigned short)b) B0006762c_ey[k].owner = a;
        }
    }
    FUN_00032d70();
}

#undef DAT_00056fa0
#undef M000718e0_iO
/* ---- from build/var/mod/parts/p22724.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern int FUN_0001fd84(int i); /* module prototype */
extern int FUN_0001fde4(int i); /* module prototype */
extern int FUN_0001fe44(int i); /* module prototype */
extern void FUN_0001ff3c(int i); /* module prototype */
extern void FUN_00021268(int i); /* module prototype */
/* (FUN_00020108: defined in this module) */
/* round 62 second blind rewrite; the FUN_00020108 copy is the module definition (src/CODE2/f20108.c), expanded in line here as in f22c20.c */
/* FUN_00022724: show party member i's condition list (copy of the module's FUN_00020108 ahead, expanded in line) */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_0002c368(char *, int);
extern void FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int);
extern void FUN_00040508(int, int, int, char *, int), FUN_00032d70(void);
extern int FUN_0002a1f4(void);
extern char *FUN_0003e6f0(int);
extern int DAT_00057f6c, DAT_00056f90[]; extern unsigned char DAT_00056dac;
extern struct CURSOR DAT_000585fc;
extern char DAT_0005759c[]; extern int B000758dc_cl;
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
 extern struct CURSOR DAT_000585fc;
void FUN_00022724(int i)
{
    int k, m, y, n;
    DAT_00056dac = 0;
    if (M000718e0_iO[i].f132) {
        FUN_000391b0(DAT_0005c050);
        FUN_0001ff3c(i);
        FUN_0003e510(0x73, DAT_00057f6c, 0x25, 2);
        if (!DAT_00056f90[i]) FUN_0003975c(0, 0x45, DAT_00057f6c + 0x38, 1, 2);
        y = 0x88;
        for (k = 0, n = 0, m = 1; m <= 0x2000000 && n < 14; k++, m <<= 1) {
            if (M000718e0_iO[i].f132 & m) {
                FUN_0002c368(DAT_0005759c, 0x24c + k);
                FUN_0003975c(2 + k, y, DAT_00057f6c + 7, B000758dc_cl + 0x4d, 0);
                FUN_0004060c(y + 4, DAT_00057f6c + 0x10, DAT_0005759c, 1);
                n++;
                y += 0x12;
            }
        }
        FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
        FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0x73, i * 0x50, 0x11d, 0x50);
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        FUN_000391b0(DAT_0005c050);
        FUN_00021268(i);
        FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
        FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0, DAT_00057f6c, 400, 0x50);
        while (FUN_0002a1f4()) ;
        FUN_00032d70();
    }
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p22988.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern int FUN_0001fd84(int i); /* module prototype */
extern int FUN_0001fde4(int i); /* module prototype */
extern int FUN_0001fe44(int i); /* module prototype */
extern void FUN_0001ff3c(int i); /* module prototype */
extern void FUN_00021268(int i); /* module prototype */
/* (FUN_00020108: defined in this module) */
/* round 61 blind rewrite. The copy of FUN_00020108 ahead of the function is the module's own definition (src/CODE2/f20108.c): the original expands it in line here, which needs both in one compile; it goes away when module 0x1eee0 becomes one module file. */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_0002c368(char *, int);
extern void FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int);
extern void FUN_00040508(int, int, int, char *, int), FUN_00032d70(void);
extern int FUN_0002a1f4(void);
extern char *FUN_0003e6f0(int);
extern int DAT_00057f6c, DAT_00056f90[]; extern unsigned char DAT_00056dac;
#include "records.h"
extern struct CURSOR DAT_000585fc; /* struct CURSOR from records.h as in the module's other files */
extern char DAT_0005759c[];
void FUN_00022988(int i)
{
    int wt, band, xp;
    DAT_00056dac = 0;
    FUN_000391b0(DAT_0005c050);
    FUN_0001ff3c(i);
    FUN_0003e510(0x73, DAT_00057f6c, 0x25, 2);
    if (!DAT_00056f90[i]) FUN_0003975c(0, 0x45, DAT_00057f6c + 0x38, 1, 2);
    wt = FUN_0001fd84(i);
    band = FUN_0001fe44(i);
    xp = FUN_0001fde4(i);
    FUN_0002c368(DAT_0005759c, 0x266);
    FUN_0004060c(0x88, DAT_00057f6c + 7, DAT_0005759c, 1);
    FUN_000405a8(0x88, DAT_00057f6c + 0x45, FUN_0003e6f0(xp), 1);
    FUN_0002c368(DAT_0005759c, 0x267);
    FUN_0004060c(0x96, DAT_00057f6c + 7, DAT_0005759c, 1);
    FUN_000405a8(0x96, DAT_00057f6c + 0x45, FUN_0003e6f0(wt), 1);
    FUN_0002c368(DAT_0005759c, 0x268 + band);
    FUN_00040508(0xa4, DAT_00057f6c + 6, 0x3c, DAT_0005759c, 1);
    FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
    FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0x73, i * 0x50, 0x11d, 0x50);
    while (FUN_0002a1f4()) ;
    while (!FUN_0002a1f4()) ;
    FUN_000391b0(DAT_0005c050);
    FUN_00021268(i);
    FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
    FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0, DAT_00057f6c, 400, 0x50);
    while (FUN_0002a1f4()) ;
    FUN_00032d70();
}

/* ---- from build/var/mod/parts/p22c20.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern int FUN_0001fd84(int i); /* module prototype */
extern int FUN_0001fde4(int i); /* module prototype */
extern int FUN_0001fe44(int i); /* module prototype */
extern void FUN_0001ff3c(int i); /* module prototype */
extern void FUN_00021268(int i); /* module prototype */
extern void FUN_0002a724(int, short, unsigned char, int, int, int, int); extern int DAT_0005bf44, DAT_0005c050;

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_0002c368(char *, int);
extern void FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int);
extern void FUN_00040508(int, int, int, char *, int), FUN_00032d70(void);
extern int FUN_0002a1f4(void);
extern char *FUN_0003e6f0(int);
extern int DAT_00057f6c, DAT_00056f90[]; extern unsigned char DAT_00056dac;
extern struct CURSOR DAT_000585fc;
extern char DAT_0005759c[]; extern int B000758dc_cl;
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
 extern struct CURSOR DAT_000585fc;
void FUN_00022c20(int i)
{
    int k, m, y;
    DAT_00056dac = 0;
    if (M000718e0_iO[i].fl & 0x1f00) {
        FUN_000391b0(DAT_0005c050);
        FUN_0001ff3c(i);
        FUN_0003e510(0x73, DAT_00057f6c, 0x25, 2);
        if (!DAT_00056f90[i]) FUN_0003975c(0, 0x45, DAT_00057f6c + 0x38, 1, 2);
        y = 0x88;
        for (k = 0, m = 0x100; m <= 0x1000; k++, m <<= 1) {
            if (M000718e0_iO[i].fl & m) {
                FUN_0002c368(DAT_0005759c, 0x28d + k);
                FUN_0003975c(0x1c + k, y, DAT_00057f6c + 7, B000758dc_cl + 0x4d, 0);
                FUN_0004060c(y + 4, DAT_00057f6c + 0x10, DAT_0005759c, 1);
                y += 0x12;
            }
        }
        FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
        FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0x73, i * 0x50, 0x11d, 0x50);
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        FUN_000391b0(DAT_0005c050);
        FUN_00021268(i);
        FUN_0001f790(DAT_000585fc.id, DAT_000585fc.f);
        FUN_00020108(DAT_000585fc.id, DAT_000585fc.f, 0, DAT_00057f6c, 400, 0x50);
        while (FUN_0002a1f4()) ;
        FUN_00032d70();
    }
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p22e70.c */
extern int FUN_0001f368(int i); /* module prototype */
extern void FUN_00021ad8(int i, int mode); /* module prototype */
extern int FUN_00021c3c(int i, int x, int y, int mode); /* module prototype */
extern int FUN_00021fb0(int a, int b, int c, int d); /* module prototype */
extern int FUN_00022180(int c, int x, int y, int mask); /* module prototype */
extern void FUN_00022470(int a); /* module prototype */
extern void FUN_00022724(int i); /* module prototype */
extern void FUN_00022988(int i); /* module prototype */
extern void FUN_00022c20(int i); /* module prototype */
#define DAT_00056fa0 ((signed char *)DAT_00056fa0)
#define M000718e0_iO ((char *)&B000718e0_iO)
/* FUN_00022e70 @ 00022e70: click (x, y) on the party side panel: find the member and the region, run its handler; mode bit 2: free the panel and redraw afterwards */
/* In module 0x1eee0, 2026-11-10: matches alone, not in context: the module defines FUN_0001f368 (16 nodes) and
   -oe expands it here; the original calls it (also from FUN_00020bbc). Every spelling of FUN_0001f368 that matches
   alone has at most 20 nodes (casts 18, CHAR_REC 19, CHAR_REC + (int) 20; tools/nodecount.py); a switch gives
   other code. Open: the original's FUN_0001f368 had more nodes, or lies in another module. Blocked (6 tries). */

extern void FUN_000410b0(void *), FUN_0002f8fc(void), FUN_0002ae30(void);
extern int DAT_00057f6c; extern char DAT_00056ea0[], DAT_00056db0[];
/* struct HS: defined above */ extern struct HS *B00062c00_hH; /* the hot-spot table pointer typed as in FUN_00022180 (was char *): one declaration for the module */  extern void *DAT_00057f68;
static int P(int mode)
{
    return (mode & 2) == 0;
}
void FUN_00022e70(int x, int y, int mode)
{
    int i;
    i = y / 0x50;
    DAT_00057f6c = i * 0x50;
    y -= DAT_00057f6c;
    if (*(unsigned short *)(M000718e0_iO + i * 0x248 + 0x10) & 0x8000) goto done;
    if (!FUN_0001f368(i)) B00062c00_hH = (struct HS *)DAT_00056ea0;
    else B00062c00_hH = (struct HS *)DAT_00056db0;
    if (DAT_00056fa0[i * 4] != -1 && x >= 0xdb && x <= 0x11f && y >= 5 && y <= 0x4d) {
        if (FUN_00021c3c(i, x, y, mode)) return;
    }
    if (x < 0x10) {
        FUN_00022470(i);
        mode = 0;
        DAT_00057f6c = i * 0x50;
    }
    if (x >= 0x10 && x <= 0x5f && y >= 3 && y <= 0x32 && (mode & 1)) {
        if (P(mode)) return;
        goto done;
    }
    if (x >= 0x45 && x <= 0x60 && y >= 0x39 && y <= 0x4d) {
        FUN_00021ad8(i, mode);
        return;
    }
    if (x >= 0x129 && x <= 0x18c && y >= 5 && y <= 0x4a && (mode & 1)) {
        if (FUN_00021fb0(i, x, y, mode)) return;
        goto done;
    }
    if (x >= 0x6e && x <= 0x123 && y >= 2 && y <= 0x4d && (mode & 1)) {
        if (FUN_00022180(i, x, y, mode)) return;
        goto done;
    }
    if (x >= 0x10 && x <= 0x27 && y >= 0x44 && y <= 0x4d && (mode & 1)) { FUN_00022988(i); goto done; }
    if (x >= 0x2b && x <= 0x40 && y >= 0x39 && y <= 0x42 && (mode & 1)) { FUN_00022c20(i); goto done; }
    if (x >= 0x2b && x <= 0x40 && y >= 0x44 && y <= 0x4d && (mode & 1)) FUN_00022724(i);
done:
    if (mode & 2) {
        FUN_000410b0(DAT_00057f68);
        FUN_0002f8fc();
        FUN_0002ae30();
    }
}

#undef DAT_00056fa0
#undef M000718e0_iO
/* ---- from build/var/mod/parts/p230a0.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
/* FUN_000230a0 @ 000230a0: drag the scroll bar with the mouse until a click; a left click jumps there */
extern int FUN_0002a1f4(void); extern void FUN_000391b0(unsigned char), FUN_0002a8c8(int, int, int, int, int), FUN_0002a344(short, unsigned char);
extern short DAT_00059e33; extern int B000758e8_jC, DAT_0005c050;
void FUN_000230a0(void)
{
    int last, v, r;
    last = -1;
    v = 0;
    while (!(r = FUN_0002a1f4())) {
        v = DAT_00059e33;
        if (v == last) continue;
        if (v > B000758e8_jC) v = B000758e8_jC;
        FUN_000391b0(DAT_0005c050);
        FUN_0001f790(v, 0);
        last = v;
        FUN_0002a8c8(DAT_0005c050, 0x62, 0, 0x10, 0x140);
    }
    if (r & 1) FUN_0002a344(v, 0);
}

/* ---- from build/var/mod/parts/p23118.c */
extern void FUN_0001f790(int item, int ident); /* module prototype */
extern void FUN_000212ec(void); /* module prototype */
/* FUN_00023118 @ 00023118: main loop of the inventory/paperdoll screen (tail-calls FUN_00029cf4) */
extern void FUN_00029ccc(int), FUN_0003195c(int, int, int, int, int, int, int), FUN_00032d8c(void), FUN_00029cf4(void); extern int FUN_00040b40(void); extern unsigned FUN_00040700(void);
extern unsigned DAT_00056da8; extern unsigned char DAT_00056dac, DAT_0005d680[], DAT_00058602; /* STANDIN: DAT_0005d680 as an array, as FUN_000212ec declares it (one declaration for the module) */ extern short DAT_00058600; extern int B000755d0_ao, B000755d4_ak;
void FUN_00023118(void)
{
    DAT_00056da8 = 0;
    DAT_00056dac = 0;
    FUN_00029ccc(0);
    FUN_000212ec();
    while (DAT_0005d680[0] == 1) {
        if (FUN_00040b40() == 0x44 && DAT_00058600 != -1)
            FUN_0003195c(0x80, DAT_00058600, DAT_00058602, B000755d0_ao, B000755d4_ak, 1, 1);
        if (DAT_00056dac) {
            if (FUN_00040700() > DAT_00056da8) {
                DAT_00056da8 = 0;
                DAT_00056dac = 0;
                FUN_0001f790(DAT_00058600, DAT_00058602);
            }
        }
        FUN_00032d8c();
    }
    FUN_00029cf4();
}

/* ---- module data _DATA 00056d98-00057f74 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
char *DAT_00056d98 = "; CHARGES: ";
char *DAT_00056d9c = "you do not understand this spell to scribe it.";
char *DAT_00056da0 = " SPELL SCRIBED.";
char *DAT_00056da4 = "that spell is already in your spell book.";
unsigned DAT_00056da8 = 0;
unsigned char DAT_00056dac = 0;
unsigned char DAT_00056dad[1] = { 0x2c };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
short DAT_00056dae[1] = { 0 };
char DAT_00056db0[240] = {
    0x11, 0, 0, 0, 1, 0, 0, 0, -0x80, 0, 0, 0, 0x1e, 0, 0, 0,
    -0x67, 0, 0, 0, 0x31, 0, 0, 0, 0x12, 0, 0, 0, 1, 0, 0, 0,
    -0x66, 0, 0, 0, 0x22, 0, 0, 0, -0x56, 0, 0, 0, 0x2c, 0, 0, 0,
    0x10, 0, 0, 0, 1, 0, 0, 0, -0x66, 0, 0, 0, 0x1b, 0, 0, 0,
    0x23, 1, 0, 0, 0x34, 0, 0, 0, 0x13, 0, 0, 0, 1, 0, 0, 0,
    -0x7e, 0, 0, 0, 0x11, 0, 0, 0, -0x5d, 0, 0, 0, 0x1f, 0, 0, 0,
    0x14, 0, 0, 0, 1, 0, 0, 0, -0x4e, 0, 0, 0, 0x10, 0, 0, 0,
    -0x3d, 0, 0, 0, 0x1b, 0, 0, 0, 0x14, 0, 0, 0, 1, 0, 0, 0,
    -0x4e, 0, 0, 0, 0x34, 0, 0, 0, -0x3d, 0, 0, 0, 0x3f, 0, 0, 0,
    0xc, 0, 0, 0, 1, 0, 0, 0, -8, 0, 0, 0, 3, 0, 0, 0,
    0x17, 1, 0, 0, 0x12, 0, 0, 0, 0xd, 0, 0, 0, 1, 0, 0, 0,
    -8, 0, 0, 0, 0x3d, 0, 0, 0, 0x17, 1, 0, 0, 0x4c, 0, 0, 0,
    0xe, 0, 0, 0, 1, 0, 0, 0, 0x6e, 0, 0, 0, 3, 0, 0, 0,
    0x23, 1, 0, 0, 0x1a, 0, 0, 0, 0xf, 0, 0, 0, 1, 0, 0, 0,
    0x6e, 0, 0, 0, 0x35, 0, 0, 0, 0x23, 1, 0, 0, 0x4c
};
char DAT_00056ea0[240] = {
    0x11, 0, 0, 0, 1, 0, 0, 0, -0x6e, 0, 0, 0, 0x1e, 0, 0, 0,
    -0x55, 0, 0, 0, 0x31, 0, 0, 0, 0x12, 0, 0, 0, 1, 0, 0, 0,
    -0x54, 0, 0, 0, 0x22, 0, 0, 0, -0x44, 0, 0, 0, 0x2c, 0, 0, 0,
    0x10, 0, 0, 0, 1, 0, 0, 0, -0x54, 0, 0, 0, 0x1b, 0, 0, 0,
    0x23, 1, 0, 0, 0x34, 0, 0, 0, 0x13, 0, 0, 0, 1, 0, 0, 0,
    -0x6c, 0, 0, 0, 0x11, 0, 0, 0, -0x4b, 0, 0, 0, 0x1f, 0, 0, 0,
    0x14, 0, 0, 0, 1, 0, 0, 0, -0x3c, 0, 0, 0, 0x10, 0, 0, 0,
    -0x2b, 0, 0, 0, 0x1b, 0, 0, 0, 0x14, 0, 0, 0, 1, 0, 0, 0,
    -0x3c, 0, 0, 0, 0x34, 0, 0, 0, -0x2b, 0, 0, 0, 0x3f, 0, 0, 0,
    0xc, 0, 0, 0, 1, 0, 0, 0, -8, 0, 0, 0, 3, 0, 0, 0,
    0x17, 1, 0, 0, 0x12, 0, 0, 0, 0xd, 0, 0, 0, 1, 0, 0, 0,
    -8, 0, 0, 0, 0x3d, 0, 0, 0, 0x17, 1, 0, 0, 0x4c, 0, 0, 0,
    0xe, 0, 0, 0, 1, 0, 0, 0, -0x80, 0, 0, 0, 3, 0, 0, 0,
    0x23, 1, 0, 0, 0x1a, 0, 0, 0, 0xf, 0, 0, 0, 1, 0, 0, 0,
    -0x80, 0, 0, 0, 0x35, 0, 0, 0, 0x23, 1, 0, 0, 0x4c
};
int DAT_00056f90[1] = { 0 };
int DAT_00056f94 = 0;   /* type from another module's declaration */
int DAT_00056f98 = 0;   /* type from another module's declaration */
int DAT_00056f9c = 0;   /* type from another module's declaration */
struct OPENC DAT_00056fa0[4] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
signed char DAT_00056fb0[896] = {
    5, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2,
    -3, -4, -4, 0, 0x47, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 0x46, 0, -1, -1, -1, -1, -1, -1, 0x45, 0, -1, -1,
    -1, -1, -1, -1, 0x46, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x5d, 0, -1, -1,
    -0x4b, 0, -0x4a, 0, -0x36, 0, -0x21, 0, -1, -1, -1, -1, 0x3c, 0, 0x3f, 0,
    0x41, 0, 0x41, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x2f, 0, 0x2f, 0,
    0x2f, 0, 0x2f, 0, 3, 0, 0x3f, 0, 0x3c, 0, 0x41, 0, 0x3f, 0, 0x3f, 0,
    0x3f, 0, 0x41, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0xe, 0, 0x28, 0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x5d, 0, 10, 0,
    0x12, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x42, 0, 0x3d, 0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -0x2b, 0, -0x2a, 0,
    -0x29, 0, 0x5d, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0x3c, 0, 0x3c, 0,
    0x1b, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x7c, 0, 0x44, 0,
    0x3e, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x5d, 0, 0x2b, 0,
    -0x24, 0, -0x3c, 0, 0x1d, 1, -1, -1, -1, -1, -1, -1, 0x1b, 0, 0x3f, 0,
    0x3f, 0, -0x24, 0, 0x3c, 0, 0x1a, 0, 0x2f, 0, 0x2f, 0, 0x42, 0, -0x27, 0,
    -0x20, 0, -0x25, 0, -1, -1, -1, -1, -1, -1, -1, -1, -0x3b, 0, 0x3f, 0,
    0x3c, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x44, 0, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x56, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0,
    0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, 0x3a, 0, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -0x37, 0, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -0x2e, 0, -0x35, 0, -0x33, 0, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x58, 0, 0x58, 0, 0x58, 0, 0x58, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0, 0x39, 0,
    -0x5c, 0, -0x5c, 0, -0x5c, 0, -0x5c, 0, -0x5c, 0, -0x5c, 0, -0x5c, 0, -0x5c
};
struct G DAT_00057330[62] = {
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 20, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 92, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 188, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 396, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 524, 0,
    6, 3, 0x7f, 0xe, 5, (char *)&DAT_00056fb0 + 620, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 656, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 536, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 672, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 204, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 28, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 688, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 220, 0,
    6, 3, 0x7f, 0xe, 5, (char *)&DAT_00056fb0 + 632, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 236, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 36, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 252, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 44, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 268, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 412, 0,
    8, 4, 0xff, 5, 1, (char *)&DAT_00056fb0 + 880, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 284, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 300, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 316, 0,
    6, 3, 0x7f, 0xe, 5, (char *)&DAT_00056fb0 + 644, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 704, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 332, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 52, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 548, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 720, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 348, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 364, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 108, 0,
    8, 4, 0x64, 5, 2, (char *)&DAT_00056fb0 + 380, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 124, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 428, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 140, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 736, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 60, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 156, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 752, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 768, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 68, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 444, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 460, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 560, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 572, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 784, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 476, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 800, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 76, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 492, 0,
    8, 4, 0x1e, 5, 1, (char *)&DAT_00056fb0 + 172, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 816, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 584, 0,
    8, 4, 0x7f, 5, 3, (char *)&DAT_00056fb0 + 508, 0,
    4, 2, 8, 0xe, 0, (char *)&DAT_00056fb0 + 84, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 596, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 832, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 848, 0,
    6, 3, 0x7f, 0xe, 4, (char *)&DAT_00056fb0 + 608, 0,
    8, 4, 0x7f, 5, 6, (char *)&DAT_00056fb0 + 864
};
char DAT_0005759c[177] = { 0 };
unsigned char DAT_0005764d = 0;   /* type from another module's declaration */
unsigned char DAT_0005764e[3] = { 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_00057651 = 0;   /* type from another module's declaration */
unsigned char DAT_00057652[74] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_0005769c[1790] = { 0 };   /* only other modules name it: bytes */
unsigned char DAT_00057d9a[2] = { 0 };   /* only other modules name it: bytes */
unsigned short DAT_00057d9c[6][20] = {
    0, 2, 4, 8, 0x10, 0x20, 0x40, 0x7d, 0xfa, 0x1f4, 0x2ee, 0x3e8, 0x4e2, 0x5dc, 0x6d6, 0x7d0,
    0x8ca, 0x9c4, 0xabe, 0xbb8, 0, 2, 4, 9, 0x12, 0x24, 0x4b, 0x96, 0x12c, 0x258, 0x384, 0x4b0,
    0x5dc, 0x708, 0x834, 0x960, 0xa8c, 0xbb8, 0xce4, 0xe10, 0, 2, 4, 9, 0x12, 0x24, 0x4b, 0x96,
    0x12c, 0x258, 0x384, 0x4b0, 0x5dc, 0x708, 0x834, 0x960, 0xa8c, 0xbb8, 0xce4, 0xe10, 0, 1, 3, 6,
    0xd, 0x1b, 0x37, 0x6e, 0xe1, 0x1c2, 0x2a3, 0x384, 0x465, 0x546, 0x627, 0x708, 0x7e9, 0x807, 0x9ab, 0xa8c,
    0, 2, 5, 10, 0x14, 0x28, 0x3c, 0x5a, 0x87, 0xfa, 0x177, 0x2ee, 0x465, 0x5dc, 0x753, 0x8ca,
    0xa41, 0xbb8, 0xd2f, 0xea6, 0, 1, 2, 5, 10, 0x14, 0x28, 0x46, 0x6e, 0xa0, 0xdc, 0x1b8,
    0x294, 0x370, 0x44c, 0x528, 0x604, 0x6e0, 0x7bc, 0x898
};
unsigned short DAT_00057e8c[22][5] = {
    1, 2, 3, 4, 6, 5, 6, 7, 9, 10, 10, 0xd, 0x10, 0x13, 0x19, 10,
    0xd, 0x10, 0x13, 0x19, 0x14, 0x1d, 0x26, 0x2e, 0x37, 0x14, 0x1d, 0x26, 0x2e, 0x37, 0x23, 0x32,
    0x41, 0x50, 0x5a, 0x23, 0x32, 0x41, 0x50, 0x5a, 0x28, 0x3a, 0x4c, 0x60, 0x6e, 0x28, 0x3a, 0x4c,
    0x60, 0x6e, 0x2d, 0x45, 0x5d, 0x75, 0x8c, 0x2d, 0x45, 0x5d, 0x75, 0x8c, 0x37, 0x55, 0x73, 0x91,
    0xaa, 0x37, 0x55, 0x73, 0x91, 0xaa, 0x46, 0x64, 0x82, 0xa0, 0xc3, 0x55, 0x79, 0x9d, 0xc1, 0xdc,
    0x6e, 0x95, 0xbc, 0xe3, 0xff, 0x87, 0xae, 0xd5, 0xfc, 0x118, 0xa0, 0xc7, 0xee, 0x115, 0x131, 0xb9,
    0xe0, 0x107, 0x12e, 0x14a, 0xeb, 0x112, 0x139, 0x160, 0x17c, 0x14f, 0x176, 0x19d, 0x1c4, 0x1e0
};
void *DAT_00057f68 = 0;
int DAT_00057f6c = 0;
int DAT_00057f70 = -1;
/* ---- end of module data _DATA */
