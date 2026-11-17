/* Module: FUN_00033df0, FUN_00033e1c, FUN_00033e58, FUN_00033eac, FUN_00033ee4, FUN_00033f34, FUN_00033f50,
   FUN_00033fc4, FUN_00034060, FUN_000340a8, FUN_000343e0, FUN_00034478, FUN_00034a9c, FUN_00034b48,
   FUN_00034bf4, FUN_00034cc8, FUN_00034f60, FUN_000351a0, FUN_000353f8, FUN_000354d4, FUN_000356c4,
   FUN_00035798, FUN_000358f8, FUN_00035a10, FUN_00035acc, FUN_00035c38, FUN_00035cac, FUN_00035d24,
   FUN_00036018 */
/* names inside DAT_00057330 (tools/dataview.py): views of the object its module defines */
#define DAT_00057334 (((struct G *)&DAT_00057330)->kind)
#define PTR_DAT_00057335 (((struct G *)&DAT_00057330)->slots)
/* ---- from build/var/mod/parts/p33df0.c */
/* Module: FUN_00033df0, FUN_00033e1c, FUN_00033e58, FUN_00033eac, FUN_00033ee4, FUN_00033f34, FUN_00033f50,
   FUN_00033fc4 */
#include "world.h"
/* ---- from build/var/mod/parts/p33df0.c */
#include "chars.h"
#define B000718f0_hO (&B000718e0_iO[0].fl)
#define B00071b38_c0 (&B000718e0_iO[1].fl)
extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);
/* FUN_00033df0 @ 00033df0: leave the current view: redraw, stop the sound, play effect 10 and switch to screen 0xc */
void FUN_00033df0(void)
{
    DAT_0005bf38 = 0;
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038168();
    FUN_00023ef8(10);
    FUN_000305b4(0xc);
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);

/* FUN_00033e1c @ 00033e1c: 0 when outdoors with n >= 2 and one of the first two members still standing, else 1 */
int FUN_00033e1c(int n)
{
    if (B00075618_b1.solo == 0xff && n >= 2 && (B000718f0_hO[0] < 0x4000 || B00071b38_c0[0] < 0x4000)) return 0;
    return 1;
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33e58.c */
/* FUN_00033e58 @ 00033e58 */
/* 2026-11-10: 0x33df0..0x373e7 is one module (record order, docs/MODULES.md "Boundary review"), and its flag set is
   plain -ox -oe -ot. There this function fails only by the item-table tie of recipe 42: the original forms k*0x41 in
   eax and loads the item-table pointer into edx ([edx+eax+0x2f]), ours k*0x41 in edx and the pointer in eax. Q1 no clobber, Q2 no
   live-range difference, Q3 an equal-savings pair whose order the conflict list decides (recipe 28), Q4 no. Tried in the
   merged module: (p + k*0x41)[0x2f], *(p + k*0x41 + 0x2f), p[0x2f + k*0x41], k * 65 + 47, (p + 0x2f)[k*0x41], a local
   pointer copy, a local offset (7; none changes it). It matches under -oa (m33df0 was promoted on that basis).
   Round 27: matches under plain -ox too with the kind read written in each compare (no variable t: the CSE'd load is
   a temp, not t's cross-block node, which orders the k*0x41 / pointer tie; instrument, then 10.0a in the module). */
int FUN_00033e58(unsigned k)
{
    if (k >= 0x7e && k <= 0x86) return 1;
    if (((unsigned char *)B000755d8_aw)[k * 0x41 + 0x2f] == 9 || ((unsigned char *)B000755d8_aw)[k * 0x41 + 0x2f] == 10 || ((unsigned char *)B000755d8_aw)[k * 0x41 + 0x2f] == 11) return 1;
    if (k == 0x30) return 1;
    return 0;
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33eac.c */
/* FUN_00033eac @ 00033eac */

#define B000718f5_h2 (*(signed char *)((char *)&B000718e0_iO + 21)) /* STANDIN: view, B000718e0_iO + 0x15 */
#define B000718f6_h5 (*(signed char *)((char *)&B000718e0_iO + 22)) /* STANDIN: view, B000718e0_iO + 0x16 */
#define B000718f7_h4 (*(signed char *)((char *)&B000718e0_iO + 23)) /* STANDIN: view, B000718e0_iO + 0x17 */

int FUN_00033eac(int i, int v)
{
    if (*((signed char *)&B000718f5_h2 + i * 0x248) == v || *((signed char *)&B000718f6_h5 + i * 0x248) == v || *((signed char *)&B000718f7_h4 + i * 0x248) == v) return 1;
    return 0;
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33ee4.c */
/* FUN_00033ee4 @ 00033ee4: true for the six special item numbers */
int FUN_00033ee4(int v)
{
    if (v == 0x2b) return 1;
    if (v == 0x59) return 1;
    if (v == 0x68) return 1;
    if (v == 0x9f) return 1;
    if (v == 0x102) return 1;
    if (v == 0x103) return 1;
    return 0;
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33f34.c */
/* FUN_00033f34 */
int FUN_00033f34(unsigned x) { if (x >= 0x7e && x <= 0x86) return 1; return 0; }

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33f50.c */
/* FUN_00033f50 @ 00033f50: is item k a thrown / missile item */

int FUN_00033f50(int k)
{
    int c;
    if (k == 0x2e) return 1;
    if (k == 0x2f) return 1;
    if (k == 0x41) return 1;
    if (k == 0x57) return 1;
    if (k == 0x59) return 1;
    if (k == 0x5a) return 1;
    c = (unsigned char)((char *)B000755d8_aw)[k * 0x41 + 0x2f];
    if (c == 0xf) return 1;
    if (c == 0xd) return 1;
    return 0;
}

extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);


/* ---- from build/var/mod/parts/p33fc4.c */
extern int FUN_00033ee4(int v); /* module prototype */
extern int FUN_00033f50(int k); /* module prototype */
/* FUN_00033fc4 @ 00033fc4: is item k a weapon that cannot be thrown */

int FUN_00033fc4(int k)
{
    int r;
    if ((unsigned)k >= 0x7e && (unsigned)k <= 0x86) return 1;
    r = FUN_00033f50(k);
    if (r) return 1;
    r = FUN_00033ee4(k);
    if (r) return 1;
    if (k == 0x30 || k == 0x29 || k == 0xfe || k == 0xff || k == 0x28 || k == 0xfc || k == 0xfd || k == 0x27 || k == 0xfa || k == 0xfb || k == 0x26 || k == 0xf8 || k == 0xf9) return 1;
    return r;
}

/* ---- from build/var/mod/parts/p34060.c */
extern int FUN_00033ee4(int v); /* module prototype */
/* FUN_00034060: first function of the module at 0x34060. It calls FUN_00033ee4 (small enough to be expanded if it were visible), which
   is part of the evidence that a module boundary lies at 0x34060 */

int FUN_00034060(unsigned k)
{
    return (k >= 0x7e && k <= 0x86) || FUN_00033ee4(k) || k == 0x31 || k == 0x5b || k == 0x26 || k == 0xf8 || k == 0xf9;
}

/* ---- from build/var/mod/parts/p340a8.c */
extern int FUN_00033e58(unsigned k); /* module prototype */
extern int FUN_00033eac(int i, int v); /* module prototype */
extern int FUN_00033f50(int k); /* module prototype */
extern int FUN_00033fc4(int k); /* module prototype */
extern int FUN_00034060(unsigned k); /* module prototype */
/* the module declaration (seen through a cast view below) */ 
/* FUN_000340a8 @ 000340a8: (round 20: character record, item table and the solo flag in the list-count block as structs; matches under both flag sets; under -oa two allocation ties remain) may party member p use item it (class, level and solo-character rules); the it == -1 case of the solo rule jumps with goto into the final ok = 0 block */
#include "world.h"
#define M000718e0_iO ((struct CHR *)&B000718e0_iO)

struct F2 { unsigned short f : 2, rest : 14; };
struct IT { char name[0x2f]; unsigned char cls, wt; signed char sub; unsigned char p0, p1; signed char acb; unsigned short fk : 2, fr : 14; unsigned char ac, d[6], y[3]; };   
struct CHR { char p0[0x10]; unsigned short st; char p12[3]; signed char cls[3]; char p18[8]; short lvl[3]; char p26[0x222]; };

#define CL(p, n) M000718e0_iO[p].cls[n]
#define LV(p, n) M000718e0_iO[p].lvl[n]
int FUN_000340a8(int p, int it, int *kind)
{
    int ok = 1, t;
    *kind = FUN_00033e58(it);
    if (!*kind) *kind = FUN_00033f50(it);
    if (*kind == 1) {
        if (it != -1) {
            if (FUN_00033eac(p, 4)) {
                if (!FUN_00033eac(p, 0) && !FUN_00033eac(p, 5) && !FUN_00033eac(p, 1)) ok = FUN_00034060(it);
                if (FUN_00033eac(p, 5)) {
                    t = !FUN_00033eac(p, 0) && !FUN_00033eac(p, 1);
                    if (t) {
                    ok = FUN_00034060(it);
                    ok |= FUN_00033fc4(it);
                    }
                }
            } else if (FUN_00033eac(p, 5)) {
                t = !FUN_00033eac(p, 0) && !FUN_00033eac(p, 1) && !FUN_00033eac(p, 3);
                if (t) ok = FUN_00033fc4(it);
            }
            if (FUN_00033eac(p, 3) && ((struct IT *)B000755d8_aw)[it].cls == 10) ok = 0;
        }
        if (B00075618_b1.solo == 0xff && p >= 2 && (M000718e0_iO[0].st != 0x8000 || M000718e0_iO[1].st != 0x8000)) {
            if (it == -1) goto zero;
            if (((struct IT *)B000755d8_aw)[it].fk != 2 && !FUN_00033f50(it)) ok = 0;
        }
        return ok;
    }
    if (it >= 0xa7 && it <= 0xc9) {
        if (CL(p, 0) != 4 && CL(p, 1) != 4 && CL(p, 2) != 4 && (CL(p, 0) != 5 || LV(p, 0) < 10) && (CL(p, 1) != 5 || LV(p, 1) < 10) && (CL(p, 2) != 5 || LV(p, 2) < 10)) ok = 0;
    } else if (it >= 0xca && it <= 0xe4 || it == 0x12d) {
        if (CL(p, 0) != 3 && CL(p, 1) != 3 && CL(p, 2) != 3 && (CL(p, 0) != 5 || LV(p, 0) < 10) && (CL(p, 1) != 5 || LV(p, 1) < 10) && (CL(p, 2) != 5 || LV(p, 2) < 10)) {
        zero:
            ok = 0;
        }
    }
    return ok;
}

#undef M000718e0_iO
#undef CL
#undef LV
/* ---- from build/var/mod/parts/p343e0.c */
extern int FUN_00033e58(unsigned k); /* module prototype */
extern int FUN_00033f50(int k); /* module prototype */
/* FUN_000343e0 @ 000343e0: may party member i change the item in equipment slot k (the slot offset is
   added first: k * 2 + base + i * 0x248) */
/* FUN_000343e0 @ 000343e0: may party member i change the item in equipment slot k */
#include "chars.h"
#include "world.h"
#define M000718f0_hO (B000718e0_iO[0].fl)
#define M00071b38_c0 (B000718e0_iO[1].fl)

#define B0007193c_aB (*(short *)((char *)&B000718e0_iO + 92)) /* STANDIN: view, B000718e0_iO + 0x5c */
  
int FUN_000343e0(int i, int k)
{
    int item = *(short *)(k * 2 + (char *)&B0007193c_aB + i * 0x248);
    int r, ok;
    r = FUN_00033e58(item);
    if (!r) r = FUN_00033f50(item);
    if (!r) {
        if ((unsigned)item >= 0x7e && (unsigned)item <= 0x86) r = 1;
        else r = 0;
    }
    if (!r && item == -1) {
        r = 1;
        if (B00075618_b1.solo == 0xff && i >= 2 && (M000718f0_hO < 0x4000 || M00071b38_c0 < 0x4000)) ok = 0;
        else ok = 1;
        if (!ok) r = 0;
    }
    return r;
}

#undef M000718f0_hO
#undef M00071b38_c0
/* ---- from build/var/mod/parts/p34478.c */
extern int FUN_000340a8(int p, int it, int *kind); /* module prototype */
/* (the eight helpers this function expands in line are defined above in this module) */
/* MATCH (lane BF, round 66, unforced, real 10.0a, -3s -ox -oe -ot -w0): lane AY pq1.c plus list levers found by an offline
   ShellSort search over the pass-1 conflict list (build/var/r66bf): five FUN_00033e1c call sites written out as the
   -oe expansion (if/else into c, code identical) with named loads copied out and back (+4 savings each on the
   in-block load nodes of those expansions), a copy chain on q2 (+1 savings-4 node in B2), one more copy-back on to2,
   and the declaration order res first (model search; fixes the res / table-base slot tie at rough savings 3). */
#include "world.h"
/* ---- from build/var/mod/parts/p33df0.c */
extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);
/* FUN_00033df0 @ 00033df0: leave the current view: redraw, stop the sound, play effect 10 and switch to screen 0xc */


extern unsigned char DAT_0005bf38; 
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);

/* FUN_00033e1c @ 00033e1c: 0 when outdoors with n >= 2 and one of the first two members still standing, else 1 */


/* ---- from build/var/mod/parts/p33e58.c */
/* FUN_00033e58 @ 00033e58 */
/* 2026-11-10: 0x33df0..0x373e7 is one module (record order, docs/MODULES.md "Boundary review"), and its flag set is
   plain -ox -oe -ot. There this function fails only by the item-table tie of recipe 42: the original forms k*0x41 in
   eax and loads the item-table pointer into edx ([edx+eax+0x2f]), ours k*0x41 in edx and the pointer in eax. Q1 no clobber, Q2 no
   live-range difference, Q3 an equal-savings pair whose order the conflict list decides (recipe 28), Q4 no. Tried in the
   merged module: (p + k*0x41)[0x2f], *(p + k*0x41 + 0x2f), p[0x2f + k*0x41], k * 65 + 47, (p + 0x2f)[k*0x41], a local
   pointer copy, a local offset (7; none changes it). It matches under -oa (m33df0 was promoted on that basis).
   Round 27: matches under plain -ox too with the kind read written in each compare (no variable t: the CSE'd load is
   a temp, not t's cross-block node, which orders the k*0x41 / pointer tie; instrument, then 10.0a in the module). */


/* ---- from build/var/mod/parts/p33eac.c */
/* FUN_00033eac @ 00033eac */



/* ---- from build/var/mod/parts/p33ee4.c */
/* FUN_00033ee4 @ 00033ee4: true for the six special item numbers */


/* ---- from build/var/mod/parts/p33f34.c */
/* FUN_00033f34 */


/* ---- from build/var/mod/parts/p33f50.c */
/* FUN_00033f50 @ 00033f50: is item k a thrown / missile item */



/* ---- from build/var/mod/parts/p33fc4.c */
extern int FUN_00033ee4(int v); /* module prototype */
extern int FUN_00033f50(int k); /* module prototype */
/* FUN_00033fc4 @ 00033fc4: is item k a weapon that cannot be thrown */




/* ---- lane P draft */
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)



int FUN_00034478(int who, int hand)
{
    int res, b, r, lt, a, l, rt; /* STANDIN: declaration order (searched; res first decides the res / table-base slot tie, the rest the remaining ties) */
    l = M000718e0_iO[who].inv[14];
    r = M000718e0_iO[who].inv[15];
    lt = 0;
    rt = 0;
    a = FUN_000340a8(who, l, &lt);
    b = FUN_000340a8(who, r, &rt);
    if (l == -1 && l == r) {
        { int c, s, cc; if ((s = B00075618_b1.solo, cc = s, s = cc, s) == 0xff && who >= 2 && (B000718f0_hO[0] < 0x4000 || B00071b38_c0[0] < 0x4000)) c = 0; else c = 1; if (!c) { a = 0; b = 0; } } /* STANDIN: FUN_00033e1c(who) written out as its expansion; named loads copied out and back raise their conflict savings (B5 tie order) */
    } else if (FUN_00033f34(l) && FUN_00033f34(r)) {
        b = a = 1;
        { int c, x, y, cc; if (B00075618_b1.solo == 0xff && who >= 2 && ((x = B000718f0_hO[0], cc = x, x = cc, x) < 0x4000 || (y = B00071b38_c0[0], cc = y, y = cc, y) < 0x4000)) c = 0; else c = 1; if (!c) { a = 0; b = 0; } } /* STANDIN: FUN_00033e1c(who) written out as its expansion; named loads copied out and back raise their conflict savings (B5 tie order) */
    } else {
        if (M000718e0_iO[who].fl & 0x7240) { a = 0; b = 0; }
        if (l == -1) {
            { int c, s, x, y, cc; if ((s = B00075618_b1.solo, cc = s, s = cc, s) == 0xff && who >= 2 && ((x = B000718f0_hO[0], cc = x, x = cc, x) < 0x4000 || (y = B00071b38_c0[0], cc = y, y = cc, y) < 0x4000)) c = 0; else c = 1; if (!c) a = 0; } /* STANDIN: FUN_00033e1c(who) written out as its expansion; named loads copied out and back raise their conflict savings (B5 tie order) */
        }
        if (r == -1) {
            { int c, s, cc; if ((s = B00075618_b1.solo, cc = s, s = cc, s) == 0xff && who >= 2 && (B000718f0_hO[0] < 0x4000 || B00071b38_c0[0] < 0x4000)) c = 0; else c = 1; if (!c) b = 0; } /* STANDIN: FUN_00033e1c(who) written out as its expansion; named loads copied out and back raise their conflict savings (B5 tie order) */
        }
        if (FUN_00033f34(l)) { int c, s, y, cc; if ((s = B00075618_b1.solo, cc = s, s = cc, s) == 0xff && who >= 2 && (B000718f0_hO[0] < 0x4000 || (y = B00071b38_c0[0], cc = y, y = cc, cc = y, y = cc, y) < 0x4000)) c = 0; else c = 1; a = c; } /* STANDIN: FUN_00033e1c(who) written out as its expansion; named loads copied out and back raise their conflict savings (B5 tie order) */
        if (FUN_00033f34(r)) b = FUN_00033e1c(who);
        if (lt && rt) {
            if (ITEMS[l].kind == ITEMS[r].kind) {
                if (ITEMS[l].kind == 2) b = a = 0;
                else if (ITEMS[r].kind == 2) b = a = 0;
                else if (FUN_00033eac(who, 0) || FUN_00033eac(who, 2) || FUN_00033eac(who, 5) || FUN_00033eac(who, 1)) {
                    if (!FUN_00033ee4(l) || !FUN_00033ee4(r)) {
                        if (ITEMS[r].wt >= ITEMS[l].wt) b = 0;
                        else if (ITEMS[l].wt >= ITEMS[r].wt) a = 0;
                    }
                } else {
                    { struct ITEM *q2, *c2q, *d2q; q2 = ITEMS + r; c2q = q2; d2q = c2q; q2 = d2q; /* STANDIN: named r address, copy out and back lifts it above the l copy; the chain through d2q adds one savings-4 node (B5 tie order) */ if (q2->wt >= ITEMS[l].wt) b = 0;
                    else { struct ITEM *p2, *c2p; p2 = ITEMS + l; c2p = p2; p2 = c2p; /* STANDIN: named l address, copy out and back lifts it above the r copy */ if (p2->wt >= ITEMS[r].wt) a = 0; } } /* STANDIN: closes the blocks */
                }
            } else if (ITEMS[l].kind > ITEMS[r].kind) {
                if (ITEMS[l].kind == 2) { a = 0; b = 0; }
                else if (ITEMS[r].kind == 2) { a = 0; b = 0; }
                else if (FUN_00033eac(who, 0) || FUN_00033eac(who, 2) || FUN_00033eac(who, 5) || FUN_00033eac(who, 1)) {
                    if (!FUN_00033ee4(l) || !FUN_00033ee4(r)) {
                        { struct ITEM *q3, *c3; q3 = ITEMS + r; c3 = q3; q3 = c3; /* STANDIN: named r address lifted by a copy out and back */ if (q3->wt >= ITEMS[l].wt) b = 0; }
                    }
                } else {
                    { struct ITEM *q4, *c4; q4 = ITEMS + r; c4 = q4; q4 = c4; c4 = q4; q4 = c4; /* STANDIN: named r address, copy out and back puts it first (it takes EBP) */ if (q4->wt >= ITEMS[l].wt) b = 0;
                    else if (ITEMS[l].wt >= q4->wt) a = 0; } /* STANDIN: closes the block */
                }
            } else {
                if (ITEMS[l].kind == 2) { a = 0; b = 0; }
                else if (ITEMS[r].kind == 2) { a = 0; b = 0; }
                else if (FUN_00033eac(who, 0) || FUN_00033eac(who, 2) || FUN_00033eac(who, 5) || FUN_00033eac(who, 1)) {
                    if (!FUN_00033ee4(l) || !FUN_00033ee4(r)) {
                        { struct ITEM *q5; q5 = ITEMS + l; /* STANDIN: named l address */ if (q5->wt == ITEMS[r].wt) a = 0; }
                    }
                } else {
                    { struct ITEM *p6, *q6, *c6; p6 = ITEMS; q6 = p6 + r; c6 = q6; q6 = c6; p6 += l; /* STANDIN: table base and l address in one local (it takes EBP first) */ if (q6->wt >= p6->wt) b = 0;
                    else if (p6->wt >= q6->wt) a = 0; } /* STANDIN: closes the block */
                }
            }
        } else if (lt) {
            { struct ITEM *tb1, *tc1; int to1; to1 = l * 0x41; tb1 = ITEMS; tc1 = tb1; tb1 = tc1; /* STANDIN: table base loaded after the product, copy out and back lifts it above the product */ if (((struct ITEM *)((char *)tb1 + to1))->kind == 2) b = 0; }
        } else if (rt) {
            { int to2, c2; to2 = r * 0x41; c2 = to2; to2 = c2; c2 = to2; to2 = c2; /* STANDIN: named item offset, copy out and back lifts it above the table base (second pair: B5 tie order) */ if (((struct ITEM *)((char *)ITEMS + to2))->kind == 2) a = 0; }
        }
    }
    if (M000718e0_iO[who].r10b[0]) a = 0;
    if (M000718e0_iO[who].r10b[1]) b = 0;
    if (hand == 0) res = a;
    if (hand == 1) res = b;
    return res;
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p34a9c.c */
#define M0007193c_aB ((char *)&B0007193c_aB)
/* FUN_00034a9c @ 00034a9c: empty inventory slot s of party member who and redraw it on the panel */
extern void FUN_0001f238(int, int, int), FUN_000391b0(unsigned char), FUN_0002ea90(int, int, int), FUN_0002a8c8(int, int, int, int, int);
extern int DAT_0005c050; 
void FUN_00034a9c(int who, int s)
{
    int o, x;
    o = s * 0x21;
    x = o + 4 + who % 2 * 0x35 + who / 2 * 0xd3;
    *(short *)(M0007193c_aB + who * 0x248 + s * 2) = -1;
    FUN_0001f238(who, s + 0xe, 0);
    FUN_000391b0(DAT_0005c050);
    FUN_0002ea90(who, s, -1);
    FUN_0002a8c8(DAT_0005c050, 0x113, x, 0x7d, 0x35);
}

#undef M0007193c_aB
/* ---- from build/var/mod/parts/p34b48.c */
/* FUN_00034b48 @ 00034b48: show a status icon for party member i and arm its timer */
#include "chars.h"
extern void FUN_000391b0(unsigned char), FUN_0002ea90(int, int, int), FUN_0002a8c8(int, int, int, int, int); extern int FUN_00029cc4(void);
#define B000719eb_cp (*(int *)((char *)&B000718e0_iO + 267)) /* STANDIN: view, B000718e0_iO + 0x10b */
extern int DAT_0005c050;
void FUN_00034b48(int i, int k, int c, int dur)
{
    int idx = k * 33 + 4 + (i % 2) * 53 + (i / 2) * 211;
    FUN_000391b0(DAT_0005c050);
    FUN_0002ea90(i, k, c);
    FUN_0002a8c8(DAT_0005c050, 0x114, idx, 0x20, 0x10);
    if (dur) ((int *)((char *)&B000719eb_cp + i * 0x248))[k] = dur + FUN_00029cc4();
}

/* ---- from build/var/mod/parts/p34bf4.c */
/* FUN_00034bf4 @ 00034bf4: compute and save the screen rectangle behind a portrait popup */
extern void FUN_000391b0(unsigned char); extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050;
int FUN_00034bf4(int x, int y, int *px, int *py, int *pw, int *ph)
{
    int x0 = x - 7, y0 = y - 0x1d, w = 0x55, h = 0xa0, t, r;
    if (x0 < 0) { w += x0; x0 = 0; }
    if (y0 < 0) { h += y0; y0 = 0; }
    if (y0 & 3) { t = y0 & 3; y0 &= ~3; h += t; }
    if (h & 7) h = (h + 7) & ~7;
    if (x0 + w > 400) w = 400 - x0;
    if (y0 + h > 0x140) h = 0x140 - y0;
    if (h & 7) { y0 -= h & 7; h = (h + 7) & ~7; }
    FUN_000391b0(DAT_0005c050);
    r = FUN_00040070(x0, y0, w, h, 0xff);
    *px = x0;
    *py = y0;
    *pw = w;
    *ph = h;
    return r;
}

/* ---- from build/var/mod/parts/p34cc8.c */
extern int FUN_00034bf4(int x, int y, int *px, int *py, int *pw, int *ph); /* module prototype */
/* FUN_00034cc8: magnifying glass over the picture on screen: grab the screen in columns, then follow the mouse with a
   lens window (the background behind it saved and restored on each of the two pages) until a button is pressed */
extern void *FUN_0004104c(int); extern void FUN_000410b0(void *);
extern void FUN_000391b0(unsigned char), FUN_0002a9f8(void), FUN_0003939c(int, int, int, int), FUN_00040040(int);
extern void FUN_00039738(int *), FUN_000396c0(int, int, int, int), FUN_00039804(int, int, int, int);
extern void FUN_0003978c(int, int, int, int, int), FUN_0002a510(int), FUN_0003f868(void);
extern void FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char);
extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050, DAT_0005a6c0, B000758dc_cl;
extern short DAT_00059e31, DAT_00059e33, DAT_00059e35;
extern unsigned char DAT_0005c054[];
void FUN_00034cc8(void)
{
    int *col, k;
    int clip[4], save[2], sx[2], used[2], sw[2], sy[2], sh[2];
    int wait, i, my, mx, x, y;
    col = FUN_0004104c(400 * sizeof(int));
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 400; k++) col[k] = FUN_00040070(k, 0, 1, 0x140, 0xff);
    FUN_0002a9f8();
    wait = 2;
    used[1] = 0;
    used[0] = 0;
    DAT_0005a6c0 = 0;
    mx = DAT_00059e31;
    my = DAT_00059e33;
    while (DAT_00059e35 == 0) {
        y = my & ~3;
        FUN_000391b0(DAT_0005c050);
        x = mx;
        if (wait == 0) {
            FUN_0003939c(0, sx[DAT_0005c050], sy[DAT_0005c050], save[DAT_0005c050]);
            FUN_00040040(save[DAT_0005c050]);
        } else wait--;
        save[DAT_0005c050] = FUN_00034bf4(x, y, &sx[DAT_0005c050], &sy[DAT_0005c050], &sw[DAT_0005c050], &sh[DAT_0005c050]);
        used[DAT_0005c050] = 1;
        FUN_00039738(clip);
        FUN_000396c0(x, y, x + 0x27, y + 0x63);
        for (i = 0; i < 0x28; i++) {
            if (x + i < 400) FUN_00039804(0, x + i, 0, col[x + i]);
        }
        FUN_000396c0(clip[0], clip[2], clip[1], clip[3]);
        FUN_0003978c(0, x - 7, y - 0x1d, B000758dc_cl + 0x4c, 0);
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        if (wait == 1) FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
        while (x == mx && (my & ~3) == y) {
            mx = DAT_00059e31;
            my = DAT_00059e33;
            FUN_0003f868();
            if (DAT_00059e35) break;
        }
        FUN_0003f868();
    }
    DAT_0005a6c0 = 1;
    if (used[0]) FUN_00040040(save[0]);
    if (used[1]) FUN_00040040(save[1]);
    for (i = 0; i < 400; i++) FUN_00040040(col[i]);
    FUN_000410b0(col);
}

/* ---- from build/var/mod/parts/p34f60.c */
extern void FUN_00034cc8(void); /* module prototype */
/* Round 54: MATCH in module 0x33df0 (-3s -ox -oe -ot): two source errors fixed from the listing - the text box position is (c + sx, d + sy) and the decremented parameter is b (the string id: dec [esp+0x30] runs before the call's add esp, 8, so it addresses b), not d; tx / ty / ww assigned inside the FUN_00023fd4 argument list (the values are pushed from registers and stored to their slots after the push); b-- as a statement before the FUN_0003f29c call (its scheduled place follows); declarations climbed (ww last, sy before sx). Earlier notes: d-- / ww / tx-ty differences were read as scheduling and registers (rounds 22, structural round). */
/* [2026-11-09: declaration order from an automatic sweep, 191 diff lines with -3s -oimert -oe -s -w0] */
/* FUN_00034f60 @ 00034f60: show a full-screen picture with a text box (a scroll/letter): fade in, wait, fade out */
#include "snd.h"
extern int FUN_00039050(void), FUN_00039048(void); extern void FUN_000391b0(unsigned char), FUN_00039b40(int, int, int, int, int), FUN_0003e4f4(int, int, unsigned char *), FUN_0002c368(void *, int), FUN_00023fd4(int, int, int, int, int, unsigned char *, int), FUN_0002a510(int), FUN_0003e404(unsigned char *, unsigned char *), FUN_0004059c(unsigned char *), FUN_0003efd0(int, int), FUN_0002f8fc(void), FUN_00032d70(void); extern void FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char); extern void FUN_00042220(unsigned char *, int, int, unsigned char, unsigned char, unsigned char);
extern unsigned char DAT_0005c054[], DAT_0005759c[], DAT_0005d470[]; extern int DAT_0005c050;
void FUN_00034f60(int a, int b, int c, int d, int e)
{
    int w8; int v; int tx; unsigned char *img; int sy; int sx; int saved; int wd; int ty; int ww;
    saved = FUN_00039050();
    v = FUN_00039048();
    FUN_00038dcc(0x9c4);
    FUN_00038ef0();
    FUN_00038e58(e, 1, 0x9c4);
    b--;
    img = (unsigned char *)FUN_0003f29c(a + 0xc, 9);
    wd = *(unsigned short *)(img + 2);
    w8 = img[6] * 8;
    sx = 0x84 - wd * *(unsigned short *)(img + 4) / 2;
    sy = 0xa0 - w8 / 2;
    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    FUN_000391b0(DAT_0005c050);
    FUN_00039b40(0, 0, 0x190, 0x140, 0);
    FUN_0003e4f4(sx, sy, img);
    FUN_0002c368(DAT_0005759c, b + 0x360);
    FUN_00023fd4(0, tx = c + sx, ty = d + sy, 0x12, ww = w8 - d * 2, DAT_0005759c, 4);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    FUN_0003e404(DAT_0005d470, img);
    FUN_0004059c(DAT_0005d470);
    FUN_000391b0(DAT_0005c050);
    FUN_00039b40(0, 0, 0x190, 0x140, 0);
    FUN_0003e4f4(sx, sy, img);
    FUN_00023fd4(0, tx, ty, 0x12, ww, DAT_0005759c, 3);
    FUN_0004059c(0);
    FUN_00034cc8();
    FUN_0003efd0(a + 0xc, 9);
    FUN_00038dcc(0x9c4);
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    FUN_0002f8fc();
    FUN_00032d70();
    FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
    FUN_00038ef0();
    if (saved != -1) FUN_00038c54(saved, v);
}

/* ---- from build/var/mod/parts/p351a0.c */
#define FUN_00023fd4 ((int (*)(int, int, int, int, int, unsigned char *, int))FUN_00023fd4)
#define FUN_0002c368 ((void (*)(unsigned char *, int))FUN_0002c368)
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)
/* FUN_000351a0 @ 000351a0: show picture p (with caption string s and music m), marks on the map picture (5), wait for a click, then restore the music */
extern int FUN_00039050(void), FUN_00039048(void), FUN_0002c1dc(int), FUN_0002a1f4(void), FUN_00040b40(void);
extern void FUN_00038dcc(int), FUN_00038ef0(void), FUN_00038c54(int, int), FUN_000391b0(unsigned char), FUN_0003e4f4(int, int, unsigned char *);
extern void FUN_0003e510(int, int, int, int), FUN_0002a510(int), FUN_0003f868(void), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void); 
extern int DAT_0005c050; extern unsigned char DAT_0005759c[], DAT_00058602; extern short DAT_00058600;
void FUN_000351a0(int p, int s, int dx, int dy, int m)
{
    int song, pos, x, y, h, lines; unsigned char *img;
    pos = FUN_00039050();
    song = FUN_00039048();
    FUN_00038dcc(0x9c4);
    FUN_00038ef0();
    FUN_00038c54(m, 1);
    img = FUN_0003f29c(p + 0xc, 9);
    h = img[6] * 8;
    x = 0x84 - *(unsigned short *)(img + 2) * *(unsigned short *)(img + 4) / 2;
    y = 0xa0 - h / 2;
    s--;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    FUN_000391b0(DAT_0005c050);
    FUN_0003e4f4(x, y, FUN_0003f29c(p + 0xc, 9));
    lines = 3;
    if (s == 5 || s == 2) lines = 4;
    if (s != -1) {
        FUN_0002c368(DAT_0005759c, s + 0x360);
        FUN_00023fd4(0, x + dx, y + dy, 0x12, h - dy * 2, DAT_0005759c, lines);
    }
    if (p == 5) {
        if (FUN_0002c1dc(0)) FUN_0003e510(3, 0x26, 0x1b, 9);
        if (FUN_0002c1dc(1)) FUN_0003e510(4, 0x5c, 0x1c, 9);
        if (FUN_0002c1dc(2)) FUN_0003e510(0x81, 0x1b, 0x1d, 9);
        if (FUN_0002c1dc(3)) FUN_0003e510(0x10d, 0x37, 0x1e, 9);
    }
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    while (FUN_0002a1f4()) FUN_0003f868();
    while (!FUN_0002a1f4() && !FUN_00040b40()) FUN_0003f868();
    while (FUN_0002a1f4() || FUN_00040b40()) FUN_0003f868();
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
    FUN_00032d70();
    FUN_00038dcc(0x9c4);
    FUN_00038ef0();
    if (pos != -1) FUN_00038c54(pos, song);
}

#undef FUN_00023fd4
#undef FUN_0002c368
#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p353f8.c */
/* FUN_000353f8 @ 000353f8: take one arrow out of the quiver of party member i */
/* r69bp: module 0x33df0 plain set (-3s -ox -oe -ot -w0): the quiver slot item read once into a named local q
   (cross-block named node instead of the unnamed load temp t6, which tied t46 at 48 and lost EAX). Matches under plain
   alone and in the merged module. */
#include "chars.h"
#include "world.h"
extern void FUN_0002c21c(char *), FUN_00038110(void *, int, int, int), FUN_00033d84(int, int, int, int), FUN_0001f290(int, int, int); extern unsigned char FUN_0001f274(int, int);
extern char *PTR_s_YOU_DO_NOT_HAVE_A_QUIVER_0005d8c0, *PTR_s_YOU_DO_NOT_HAVE_ANY_ARROWS_0005d8c4, *B000758bc_al;
#pragma pack(1)
struct G { unsigned char n, cols, maxw, y0, kind; short *slots; unsigned char mask; };
#pragma pack()
extern struct G DAT_00057330[];
void FUN_000353f8(int i)
{
    int t, k, q;
    q = *(short *)(CHAR_REC(i) + 0x66);
    if (q == -1) { FUN_0002c21c(PTR_s_YOU_DO_NOT_HAVE_A_QUIVER_0005d8c0); return; }
    t = *(signed char *)(q * 0x41 + ((int)B000755d8_aw) + 0x31);
    for (k = 0; k < DAT_00057330[t].n; k++) {
        if (DAT_00057330[t].slots[k] != -1) {
            FUN_00038110(B000758bc_al + 8, 0xff, 1, 2);
            FUN_00033d84(DAT_00057330[t].slots[k], FUN_0001f274(t, k), 0x80, i);
            DAT_00057330[t].slots[k] = -1;
            FUN_0001f290(t, k, 0);
            break;
        }
    }
    if (k == DAT_00057330[t].n) FUN_0002c21c(PTR_s_YOU_DO_NOT_HAVE_ANY_ARROWS_0005d8c4);
}

#pragma pack()
/* ---- from build/var/mod/parts/p354d4.c */
extern void FUN_00034a9c(int who, int s); /* module prototype */
/* MATCH (round 47, module 0x33df0 plain): the mixed form. One symbol each for the character record (`B000718e0_iO[i].inv[14 + slot]`), the draw list (`B00077148_eJ[page][k].ord`, `rec = &B00077148_eJ[page][k]`: hoists page base + table as the original) and the monster record; the item record is read where it is used (`ITEMS[wid].cls` twice, `ITEMS[wid].sub`) with NO local for the record address or the class (recipe 6): the named `mon` / `c` were two entries of the temp list whose length parity decides how TempAllocBefore's ShellSort leaves the three slotted temps (n / v / item); the container stays on the byte offset `t = n * 10` (struct CONT without t: 9 lines, slots again). Measured in round 47 (cast views in the merged module): draw list alone 16, + inv 13 (slots only), + no mon 2 (item-address tie), + no c 0. */
/* Round 46: the all-struct form (docs/data/r46/f354d4.struct.c: hands `B000718e0_iO[i].inv[14 + slot]`, struct ITEM *mon, `DAT_00057330[n].kind / .n / .slots[k]` without the explicit `t = n * 10`, the draw list `B00077148_eJ[page][k].ord` / `rec->f8 / ->mon / ->id` as struct DRAWE [2][400], `B00064d80_ay[rec->mon].type`) is 496/496 with every instruction equal except frame-slot numbers (9 fdiff lines, worklist 8, all `[esp + N]`: the original has n at [esp+8] where that form has [esp]; item / v / sel permuted likewise); the structural difference of rounds 38 / 45 (table base added in the inner-loop preheader) is gone in it. Not kept as the source because the line count rises (2 -> 8) and no declaration order moves the slots (climb 36 + pair swaps 66); this per-field form stays until the slots are explained. */
/* Round 42: both scan loops index by k (recipes 125 / 127; no offset variable), declaration order re-climbed: the same 3 instruction lines (496/496) as the stepped-offset form. Left: the page base + B00077148_eJ hoisted into edi (rec = B00077148_eJ + page * 0x2260 + k * 0x16 gives it, then the n / v / item slots rotate: climb + 78 pair swaps best 9 lines, not kept). */
/* Round 39 (real 10.0a, module m33df0 plain): `slot * 2 + i * 0x248` in the wid read gives the original imul eax / [eax + edx*2] (85 -> 82 lines, 496/496). The loop part needs rec = k * 0x16 + ((DAT_0005c050 ^ 1) * 0x2260 + B00077148_eJ) (the page base plus B00077148_eJ hoisted into edi, then add eax, edi, as the original), but then the entry temps flip (152 lines; tietrace class C: t77 3362 / t78 3322, no tie; all 5 wid groupings 149-152): not kept. */
/* Round 29 (real 10.0a, module m33df0 plain): in module 85 lines; the round-18 rec form B00077148_eJ + page * 0x2260 + k * 0x16 fixes the entry registers but gives 149 (frame slots n/item/v and a 2-byte size change); tietrace on it: first difference is not a register, no forced tie order of 8 groups helps. Not attempted further. */
/* Round 18: with FUN_0001dacc's `rec = B00077148_eJ + (DAT_0005c050 ^ 1) * 0x2260 + k * 0x16` only item and n exchange frame slots (orig item@0 v@4 n@8); swapping their declarations, the reversed list, `int v, item, n` / `int n, v, item` first: no change. Not kept (classify shape 9 -> 13). */
/* Structural round 2026-11-10 (module 0x33df0, plain; 17 lines under -oa, 20 plain): the original hoists B00077148_eJ + page * 0x2260 out of the target loop (add edi, base before the loop): rec = B00077148_eJ + (DAT_0005c050 ^ 1) * 0x2260 + k * 0x16 gives that and also the original eax/edx at entry, leaving only frame-slot differences (n, item, v permuted) - but 20 -> 32 byte lines, size -1 -> -2 (the slot encodings), so by the acceptance rule it is not kept; apply it together with the slot order. */
/* NEAR MISS 494/496: declaration order from a sweep, both scan loops step offset before counter, and FUN_0001f274 takes n (the signed byte at mon + 0x31) as its first argument, not i; left: the spill slots of n and the other spilled locals ([esp+8] in the original) */
/* FUN_000354d4 @ 000354d4: fire the held sling (slot) of party member i at the monster under the cursor; needs a sling and stones */
#include "world.h"
extern unsigned char FUN_0001f218(int, int), FUN_0001f274(int, int); extern void FUN_00033d84(int, int, int, int), FUN_0001f290(int, int, int), FUN_0002c21c(char *);
#include "records.h"
#define DAT_00057330 (*(unsigned char *)&DAT_00057330)
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
 extern int DAT_0005c050;   extern unsigned short DAT_0005f038[]; extern struct DRAWE B00077148_eJ[][400]; extern struct MONR B00064d80_ay[];
extern char *PTR_s_YOU_HAVE_NO_STONES_IN_YO_0005d8c8, *PTR_s_YOU_MUST_HOLD_A_SLING_ST_0005d8cc;
void FUN_000354d4(int i, int b, int slot)
{
    int item; int j; int v; int sel; int found; int wid; int id; int t; int n; struct DRAWE *rec; int k;
    sel = -1;
    wid = M000718e0_iO[i].inv[14 + slot];
    if (wid != -1) {
        found = 0;
        if (ITEMS[wid].cls == 0xd) {
            found = 1;
            item = wid;
            v = FUN_0001f218(i, slot + 0xe);
            sel = 99;
        } else if (ITEMS[wid].cls == 1) {
            n = ITEMS[wid].sub;
            t = n * 10;
            if ((&DAT_00057334)[t] == 3) {
                for (k = 0; k < (&DAT_00057330)[t]; k++) {
                    id = (*(short **)((char *)&PTR_DAT_00057335 + t))[k];
                    if (id != -1) {
                        found = 1;
                        item = id;
                        v = FUN_0001f274(n, k);
                        sel = k;
                        break;
                    }
                }
            }
        }
        if (found) {
            if (b == 0x31) {
                FUN_00033d84(item, v, 0x80, i);
            } else {
                for (j = DAT_0005f038[DAT_0005c050 ^ 1] - 1; j >= 0; j--) {
                    for (k = 0; k < DAT_0005f038[DAT_0005c050 ^ 1]; k++) {
                        if (B00077148_eJ[DAT_0005c050 ^ 1][k].ord == j) break;
                    }
                    rec = &B00077148_eJ[DAT_0005c050 ^ 1][k];
                    if (rec->f8 == 0 && B00064d80_ay[rec->mon].type < 0x22) {
                        FUN_00033d84(item, v, rec->id, i);
                        break;
                    }
                }
                if (j == -1) sel = -1;
            }
            if (sel == 99) {
                FUN_00034a9c(i, slot);
                return;
            }
            if (sel == -1) return;
            *(short *)((char *)*(short **)((char *)&PTR_DAT_00057335 + n * 10) + sel * 2) = -1;
            FUN_0001f290(n, sel, 0);
            return;
        }
        FUN_0002c21c(PTR_s_YOU_HAVE_NO_STONES_IN_YO_0005d8c8);
        return;
    }
    FUN_0002c21c(PTR_s_YOU_MUST_HOLD_A_SLING_ST_0005d8cc);
}

#undef DAT_00057330
#undef M000718e0_iO
/* ---- from build/var/mod/parts/p356c4.c */
/* FUN_000356c4 @ 000356c4: remove the 0x9b door whose cell flag is set and update the 0x29/0x2a/0x2c entities */
 
#include "world.h"
void *memmove(void *, const void *, unsigned);
extern void FUN_0002c124(int);
#define B00064d8b_a7 (*(int *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
 extern unsigned short B00072246_dJ, B00072244_c8, B000698e0_b7; extern unsigned char B00072238_dL[]; 
#define DR_KIND(i) (*(unsigned short *)((char *)&B00072246_dJ + (i) * 0x16))
#define DR_CELL(i) (*(unsigned short *)((char *)&B00072244_c8 + (i) * 0x16))
#define CELLF(c) (*(int *)((char *)&B000698e0_b7 + (c) * 2))
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
void FUN_000356c4(void)
{
    int i, j;
    for (i = 0; i < B00075618_b1.ndoor; i++) {
        if (DR_KIND(i) == 0x9b && (CELLF(DR_CELL(i)) & 0x40)) {
            memmove(B00072238_dL + i * 0x16, B00072238_dL + (i + 1) * 0x16, (B00075618_b1.ndoor - 1 - i) * 0x16);
            B00075618_b1.ndoor--;
            FUN_0002c124(0x30);
            for (j = 0; j < B00075618_b1.nent; j++) {
                if (ENT_ID(j) == 0x2c) ENT_FL(j) &= ~2;
                if (ENT_ID(j) == 0x29) ENT_FL(j) |= 2;
                if (ENT_ID(j) == 0x2a) ENT_FL(j) &= ~2;
            }
            return;
        }
    }
}

#undef DR_KIND
#undef DR_CELL
#undef CELLF
#undef ENT_ID
#undef ENT_FL
/* ---- from build/var/mod/parts/p35798.c */
extern void FUN_000351a0(int p, int s, int dx, int dy, int m); /* module prototype */
/* FUN_00035798 @ 00035798: the hidden-switch puzzle: when all switches are set, open the 0x39 doors and lock the others */
 
#include "world.h"
extern int FUN_0002c1dc(int); extern void FUN_0002c124(int), FUN_00026524(int);
#define B00064d8c_bX (*(unsigned short *)((char *)&B00064d80_ay + 12)) /* STANDIN: view, B00064d80_ay + 0xc */
 extern unsigned short B000698e0_b7; extern int DAT_0005bf44;
#define ENT_ID(o) (*(unsigned short *)((char *)&B00064d8e_a6 + (o)))
#define ENT_CELL(o) (*(unsigned short *)((char *)&B00064d8c_bX + (o)))
#define ENT_FL(o) (*(int *)((char *)&B00064d8b_a7 + (o)))
#define CELLF(c) (*(int *)((char *)&B000698e0_b7 + (c) * 2))
void FUN_00035798(void)
{
    int k, off, j, o2;
    if (FUN_0002c1dc(0x2c) == 0 && FUN_0002c1dc(0) == 1 && FUN_0002c1dc(1) == 1 && FUN_0002c1dc(2) == 1 && FUN_0002c1dc(2) == 1) {
        for (k = 0, off = 0; k < B00075618_b1.nent; off += 0x16, k++) {
            if (ENT_ID(off) == 0x39 && (CELLF(ENT_CELL(off)) & 0x40)) {
                FUN_0002c124(0x2c);
                FUN_00026524(0x17);
                for (j = 0, o2 = 0; j < B00075618_b1.nent; o2 += 0x16, j++) {
                    if (ENT_ID(o2) == 0x29) ENT_FL(o2) |= 2;
                    if (ENT_ID(o2) == 0x2a) ENT_FL(o2) &= ~2;
                    if (ENT_ID(o2) == 0x39) ENT_FL(o2) |= 2;
                    if (ENT_ID(o2) == 0x3a) ENT_FL(o2) &= ~2;
                }
                break;
            }
        }
        if (k == B00075618_b1.nent) DAT_0005bf44 = 0x19;
    } else {
        k = B00075618_b1.nent;
    }
    if (k == B00075618_b1.nent) FUN_000351a0(5, 4, 0x40, 0x37, 0xf);
}

#undef ENT_ID
#undef ENT_CELL
#undef ENT_FL
#undef CELLF
/* ---- from build/var/mod/parts/p358f8.c */
extern void FUN_00034a9c(int who, int s); /* module prototype */
/* Round 53 (module 0x33df0 plain, 2 compiles): body under `if (FUN_0002c1dc(0x27) != 1) { ... }` instead of the early return (3, identical) and j declared in the lever block (3, identical). The replay (remove any node at 1-22 / insert 0..209 at 0-12) stands; the function matches under -oa (module flag question). */
/* r69bp: module 0x33df0 plain set (-3s -ox -oe -ot -w0). Under plain a, b and c tie at savings 238 and c took EBP
   (under -oa the memory node DAT_0005bf44 flipped the sort); one copy out and back on the parameter c lowers its pass-1
   savings to 236, so b sorts first and keeps EBP as in the original. */
#include "world.h"
extern int FUN_0002c1dc(int); extern void FUN_0002c124(int), FUN_00026524(int);
 extern unsigned short B000698e0_b7; extern int DAT_0005bf44;
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_CELL(i) (*(unsigned short *)((char *)&B00064d8c_bX + (i) * 0x16))
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
#define CELLF(c) (*(int *)((char *)&B000698e0_b7 + (c) * 2))
void FUN_000358f8(int a, int b, int c)
{
    int k, j, found;
    if (FUN_0002c1dc(0x27) == 1) return;
    { int t; t = c; c = t; }   /* STANDIN: copy out and back on parameter c: its pass-1 savings 238 -> 236, so b wins the a/b/c tie for EBP */
    found = 0;
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (ENT_ID(k) == 0x37 && (CELLF(ENT_CELL(k)) & 0x40) && FUN_0002c1dc(0x43) == 1) {
            FUN_0002c124(a);
            FUN_00034a9c(b, c);
            found = 1;
            if (FUN_0002c1dc(0x32) == 1 && FUN_0002c1dc(0x33) == 1 && FUN_0002c1dc(0x34) == 1) {
                FUN_0002c124(0x27);
                FUN_00026524(0x15);
                for (j = 0; j < B00075618_b1.nent; j++) {
                    if (ENT_ID(j) == 0x37) ENT_FL(j) |= 2;
                }
                break;
            }
        }
    }
    if (k == B00075618_b1.nent && found == 0) DAT_0005bf44 = 0x15;
}

#undef ENT_ID
#undef ENT_CELL
#undef ENT_FL
#undef CELLF
/* ---- from build/var/mod/parts/p35a10.c */
extern void FUN_00034a9c(int who, int s); /* module prototype */
/* FUN_00035a10 @ 00035a10: open the two secret doors of the map when their switches are set */
 
#include "world.h"
extern int FUN_0002c1dc(int); extern void FUN_00026524(int), FUN_0002c124(int);
 extern unsigned short B000698e0_b7;
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_CELL(i) (*(unsigned short *)((char *)&B00064d8c_bX + (i) * 0x16))
#define CELLF(c) (*(int *)((char *)&B000698e0_b7 + (c) * 2))
void FUN_00035a10(int a, int b)
{
    int k;
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (ENT_ID(k) == 0x3b && FUN_0002c1dc(0x35) == 0) {
            if (CELLF(ENT_CELL(k)) & 0x40) {
                FUN_00026524(0x19);
                FUN_0002c124(0x35);
                FUN_00034a9c(a, b);
            }
        } else if (ENT_ID(k) == 0x3c && FUN_0002c1dc(0x36) == 0) {
            if (CELLF(ENT_CELL(k)) & 0x40) {
                FUN_00026524(0x1a);
                FUN_0002c124(0x36);
                FUN_00034a9c(a, b);
            }
        }
    }
}

#undef ENT_ID
#undef ENT_CELL
#undef CELLF
/* ---- from build/var/mod/parts/p35acc.c */
#define CHR T17_CHR
/* MATCH (round 36): one store DAT_0005cf5a[who] = 1 at the end for every path; the code generator copies the store + epilogue into the r == 0 and r == -2 paths (tail duplication after allocation), so the allocator sees who with two references fewer (savings 18 -> 14 = the &mem[slot] address temp) and the address temp takes EBX first as in the original. The three stores written out had given who 18 (savings arithmetic, recipe 104). */
/* Round 29 (real 10.0a, module m33df0 plain, 7 compiles): 15 lines; who (savings 18) takes EBX and the &mem[slot] address temp ESI; the original the reverse (who ESI, address EBX), so the address temp must outrank who. A short *p for the slot (3 placements): 128-131 lines; 0xffff store, unsigned who / slot: no change. */
/* NEAR MISS (round 22): under -oa in module 215 lines (no). Not changed. */
/* NEAR MISS 30 lines, size equal: only who and the slot offset swap esi/ebx (the original keeps who in esi, slot*2 + who*0x248 in ebx). Character record struct, hoisted name pointer, declaration orders (720 with a slot copy), parameter copies tried Module round 2026-11-10 (0x33df0, plain, 15 lines in context): Q1 no clobber, Q2 equal, Q3 tie between who (esi in the original) and the slot address temporary who*0x248 + slot*2 (ebx), recipe 28; Q4 no. Tried: a short *m to the slot (102 lines), short saved (96). */
/* FUN_00035acc @ 00035acc: cast spell sp memorised by member who in slot: clear the slot, resolve the spell and report "<name> CASTS <spell>", "THE INCANTATION FAILS" or (aborted) "THE SPELL IS ABORTED" with the slot restored; marks the member as having acted */
#include <string.h>
#include <stdio.h>
#define DAT_0005759c ((char *)DAT_0005759c)
#define M000718e0_iO ((struct CHR *)&B000718e0_iO)
#define FUN_0002c368 ((void (*)(char *, char *))FUN_0002c368)
struct CHR { char name[0x5c]; short mem[0xf6]; };
 extern char *DAT_0005d89c, *DAT_0005d8a0, *DAT_0005d8a4; extern unsigned char DAT_0005cf5a[];
extern unsigned char FUN_0001f218(int, int); extern void FUN_0001f238(int, int, int), FUN_0002c21c(char *); extern int FUN_0001b950(char *, int);
void FUN_00035acc(char *sp, int who, int slot)
{
    int t; char *cn; char *nm; int saved; int r;
    saved = M000718e0_iO[who].mem[slot];
    t = FUN_0001f218(who, slot + 0xe);
    M000718e0_iO[who].mem[slot] = -1;
    FUN_0001f238(who, slot + 0xe, 0);
    r = FUN_0001b950(sp, who);
    nm = sp + 0x42;
    cn = M000718e0_iO[who].name;
    if (r == 1) {
        sprintf(DAT_0005759c, DAT_0005d89c, cn);
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), nm);
        FUN_0002c21c(DAT_0005759c);
    } else if (r == 0) {
        FUN_0002c21c(DAT_0005d8a0);
    } else if (r == -2) {
        sprintf(DAT_0005759c, DAT_0005d89c, cn);
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), nm);
        FUN_0002c21c(DAT_0005759c);
    } else {
        FUN_0002c21c(DAT_0005d8a4);
        M000718e0_iO[who].mem[slot] = saved;
        FUN_0001f238(who, slot + 0xe, t);
    }
    DAT_0005cf5a[who] = 1;
}

#undef CHR
#undef DAT_0005759c
#undef M000718e0_iO
#undef FUN_0002c368
/* ---- from build/var/mod/parts/p35c38.c */
/* FUN_00035c38 @ 00035c38 */
extern int FUN_0002c1dc(int); extern void FUN_0003195c(int, int, int, int, int, int, int); extern void FUN_0002c124(int);
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */
extern int DAT_0005c6c8, B000755d0_ao, B000755d4_ak; 
void FUN_00035c38(void)
{
    if (FUN_0002c1dc(0x40) == 0 && DAT_0005c6c8 == 0xb && B000755d2_ai >= 2 && B000755d2_ai <= 4 && B000755d6_ae >= 0x77 && B000755d6_ae <= 0x79) {
        FUN_0003195c(0x80, 0x71, 0, B000755d0_ao, B000755d4_ak, 1, 0);
        FUN_0002c124(0x40);
        FUN_0002c124(0x9d);
    }
}

/* ---- from build/var/mod/parts/p35cac.c */
/* FUN_00035cac @ 00035cac: move an item from the pack into an equipment slot.  Both record fields must be
   addressed through the same base symbol, otherwise the compiler reorders the two stores. */
#include "chars.h"
extern unsigned char FUN_0001f218(int, int); extern void FUN_0001f238(int, int, int);
extern unsigned char DAT_0005cf5a[];
#define SLOT(i,k) (*(short *)(CHAR_REC(i) + 0x40 + (k) * 2))
#define EQUIP(i,k) (*(short *)(CHAR_REC(i) + 0x5c + (k) * 2))
void FUN_00035cac(int i, int slot, int item)
{
    int k;
    for (k = 0; k < 12; k++) {
        if (SLOT(i, k) == item) {
            EQUIP(i, slot) = item;
            SLOT(i, k) = -1;
            FUN_0001f238(i, slot + 0xe, FUN_0001f218(i, k));
            FUN_0001f238(i, k, 0);
            DAT_0005cf5a[i] = 1;
            return;
        }
    }
}

#undef SLOT
#undef EQUIP
/* ---- from build/var/mod/parts/p35d24.c */
extern void FUN_00034a9c(int who, int s); /* module prototype */
extern void FUN_00034b48(int i, int k, int c, int dur); /* module prototype */
/* FUN_00035d24 @ 00035d24: heal party member i by n hit points (n is a short parameter) */
#include "chars.h"
#define DAT_0005759c ((char *)DAT_0005759c)
int sprintf(char *, const char *, ...);
extern void FUN_0002c21c(char *), FUN_00038110(void *, int, int, int);
extern char *PTR_s_does_not_need_healing_0005d8d0, *PTR_s_feels_better_0005d8d4, *B000758bc_al; extern unsigned char DAT_0005cf5a[];
#define CW(i, o) (*(short *)(CHAR_REC(i) + (o)))
void FUN_00035d24(int i, int b, short n)
{
    if (CW(i, 0x1c) == CW(i, 0x1e)) {
        sprintf(DAT_0005759c, PTR_s_does_not_need_healing_0005d8d0, CHAR_REC(i));
        FUN_0002c21c(DAT_0005759c);
        return;
    }
    FUN_00038110(B000758bc_al + 2, 0xff, 1, 1);
    sprintf(DAT_0005759c, PTR_s_feels_better_0005d8d4, CHAR_REC(i));
    FUN_0002c21c(DAT_0005759c);
    CW(i, 0x1c) += n;
    if (CW(i, 0x1c) > CW(i, 0x1e)) CW(i, 0x1c) = CW(i, 0x1e);
    FUN_00034a9c(i, b);
    DAT_0005cf5a[i] = 1;
    FUN_00034b48(i, b, 0, 10);
}

#undef DAT_0005759c
#undef CW
/* ---- from build/var/mod/parts/p36018.c */
extern int FUN_00033f50(int k); /* module prototype */
extern void FUN_00034a9c(int who, int s); /* module prototype */
extern void FUN_00034b48(int i, int k, int c, int dur); /* module prototype */
extern void FUN_00034f60(int a, int b, int c, int d, int e); /* module prototype */
extern void FUN_000351a0(int p, int s, int dx, int dy, int m); /* module prototype */
extern void FUN_000353f8(int i); /* module prototype */
extern void FUN_000354d4(int i, int b, int slot); /* module prototype */
extern void FUN_000356c4(void); /* module prototype */
extern void FUN_00035798(void); /* module prototype */
extern void FUN_000358f8(int a, int b, int c); /* module prototype */
extern void FUN_00035a10(int a, int b); /* module prototype */
extern void FUN_00035acc(char *sp, int who, int slot); /* module prototype */
extern void FUN_00035c38(void); /* module prototype */
extern void FUN_00035cac(int i, int slot, int item); /* module prototype */
extern void FUN_00035d24(int i, int b, short n); /* module prototype */
/* lane AY round 65: MATCH unforced under -3s -ox -oe -ot -w0 (real 10.0a emulated). Ties turned into strict orderings: lines marked STANDIN exist only for the bytes. */
/* (FUN_00033df0, which the original expands in line, is written out as its five calls in case 0x79, as in r62z) */
/* HISTORY (lane AN, round 65; superseded by lane AY, now MATCH): 5070/5071, 38 masked lines under the real sort; INSTRUCTION STREAM IS RIGHT:
   forcing the pass-1 tie order in build/var/r65an/final/f36018.force gives MATCH 5071/5071 with this exact text.
   Stage A fixes (this file vs r62z v6): FUN_00035d24 declared with its definition's (int, int, short) and called through an
   int-argument cast (no cwde); case 0x4e direction in its own local d2 (no store to dir's frame slot); case 0x4b reads the
   charge index into s before DAT_0005f03e++ (inc after the movsx as in the original). No `id -= 0xa7` needed: the
   sub ebp,0xa7 / push eax site is a tie (switch-index temp before the copy temp).
   Tie pairs still needed (13, each necessary; names of this file's dump): ok<t293, ok<t292, ok<t291, ok<t340 (ok = t8),
   t12<t17, t12<t14 (i*0x248 after the call in EAX), t115<t116, t230<t231, t270<t272, t191<t190, t212<t213, t281<t283,
   t341<t337 (item product/base ties). Best single list edit (insert/remove/savings change) leaves 8; declaration orders
   of id,type,ok,dir: none. */
#include <stdio.h>
#include "records.h"
#include "world.h"
#include "dice.h"
#define DAT_0005759c ((char *)DAT_0005759c)
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
#define B000758bc_al (*(int *)&B000758bc_al)
#define FUN_00038110 ((void (*)(int, int, int, int))FUN_00038110)

int rand(void);
extern void FUN_00029ccc(int), FUN_00029cf4(void), FUN_00033d84(int, int, int, int);
extern void FUN_0001e5f0(int, int, int, int);


extern void FUN_0002c124(int), FUN_00031db4(int), FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void), FUN_00023ef8(int), FUN_000305b4(int);
extern void FUN_00018a80(int, int, int, int, int), FUN_00013634(int), FUN_0001e578(int), FUN_0002c21c(char *), FUN_0002c77c(int, int);
extern void FUN_0001b02c(int a0, int a1, int range, int dmg, int mask, int mark, int kind, int snd, int px, int py);
extern int FUN_0001f4b0(int), FUN_00019418(int), FUN_000195c0(void), FUN_00029cc4(void), FUN_0002202c(int, int), FUN_00019d90(int, int, int);
extern unsigned char FUN_0001f218(int, int);
extern int DAT_0005bf44, B000755d0_ao, B000755d4_ak, DAT_0005c658;
extern unsigned char DAT_0005bf38, DAT_0005cf5a[];
extern signed char DAT_000567ec[];
extern short DAT_0005f03e;
extern char *DAT_0005d8d8;
extern struct MONR B00064d80_ay[];
void FUN_00036018(int i, int j, int tgt)
{
    struct ITEM *tc3, *tb3; int o5, o2, k279, o3, id, type, dir, o4, k, ok, o, o6, to3, k272; /* STANDIN: declaration order (searched; decides the remaining switch-index and record-product ties) */
    FUN_00029ccc(0);
    { int c; k = i * 0x248; c = k; k = c; } /* STANDIN: named i*0x248, copy out and back lifts it above the two index temps */ if (((struct PC *)((char *)M000718e0_iO + k))->r10b[j]) return;
    id = ((struct PC *)((char *)M000718e0_iO + k))->inv[14 + j]; /* STANDIN: uses the named offset above */
    type = ITEMS[id].cls;
    if (id == -1) type = 10;
    if (FUN_00033f50(id)) {
        FUN_00033d84(id, FUN_0001f218(i, j + 0xe), 0x80, i);
        FUN_00034a9c(i, j);
        FUN_00035cac(i, j, id);
        FUN_00034b48(i, j, 0, 0x12);
    } else switch (type) {
    case 9: case 10: case 11:
        FUN_0001e5f0(i, j, id, tgt);
        break;
    case 0xe:
        switch (id) {
            case 0x114: FUN_000358f8(0x32, i, j); break;
            case 0x115: FUN_000358f8(0x33, i, j); break;
            case 0x128: FUN_000358f8(0x34, i, j); break;
            case 0xa7: FUN_00035acc(0, i, j); break;
            case 0xa8: FUN_00035acc(0x1, i, j); break;
            case 0xa9: FUN_00035acc(0x2, i, j); break;
            case 0xaa: FUN_00035acc(0x3, i, j); break;
            case 0xab: FUN_00035acc(0x4, i, j); break;
            case 0xac: FUN_00035acc(0x5, i, j); break;
            case 0xad: FUN_00035acc(0x6, i, j); break;
            case 0xae: FUN_00035acc(0xa, i, j); break;
            case 0xaf: FUN_00035acc(0xb, i, j); break;
            case 0xb0: FUN_00035acc(0xc, i, j); break;
            case 0xb1: FUN_00035acc(0xd, i, j); break;
            case 0xb2: FUN_00035acc(0xe, i, j); break;
            case 0xb3: FUN_00035acc(0xf, i, j); break;
            case 0xb4: FUN_00035acc(0x14, i, j); break;
            case 0xb5: FUN_00035acc(0x15, i, j); break;
            case 0xb6: FUN_00035acc(0x16, i, j); break;
            case 0xb7: FUN_00035acc(0x17, i, j); break;
            case 0xb8: FUN_00035acc(0x18, i, j); break;
            case 0xb9: case 0xd3: FUN_00035acc(0x19, i, j); break;
            case 0xba: FUN_00035acc(0x1a, i, j); break;
            case 0xbb: FUN_00035acc(0x1b, i, j); break;
            case 0xbc: FUN_00035acc(0x1c, i, j); break;
            case 0xbd: FUN_00035acc(0x1d, i, j); break;
            case 0xbe: FUN_00035acc(0x1e, i, j); break;
            case 0xbf: FUN_00035acc(0x1f, i, j); break;
            case 0xc0: FUN_00035acc(0x20, i, j); break;
            case 0xc1: FUN_00035acc(0x21, i, j); break;
            case 0xc2: FUN_00035acc(0x28, i, j); break;
            case 0xc3: FUN_00035acc(0x29, i, j); break;
            case 0xc4: FUN_00035acc(0x32, i, j); break;
            case 0xc5: FUN_00035acc(0x33, i, j); break;
            case 0xc6: FUN_00035acc(0x34, i, j); break;
            case 0xc7: FUN_00035acc(0x35, i, j); break;
            case 0xc8: FUN_00035acc(0x36, i, j); break;
            case 0xc9: FUN_00035acc(0x37, i, j); break;
            case 0xca: FUN_00035acc(0x50, i, j); break;
            case 0xcb: FUN_00035acc(0x51, i, j); break;
            case 0xcc: FUN_00035acc(0x52, i, j); break;
            case 0xcd: FUN_00035acc(0x53, i, j); break;
            case 0xce: FUN_00035acc(0x54, i, j); break;
            case 0xcf: FUN_00035acc(0x55, i, j); break;
            case 0xd0: FUN_00035acc(0x56, i, j); break;
            case 0xd1: FUN_00035acc(0x5a, i, j); break;
            case 0xd2: FUN_00035acc(0x5b, i, j); break;
            case 0xd4: FUN_00035acc(0x5d, i, j); break;
            case 0xd5: FUN_00035acc(0x5e, i, j); break;
            case 0xd6: FUN_00035acc(0x5f, i, j); break;
            case 0xd7: FUN_00035acc(0x64, i, j); break;
            case 0xd8: FUN_00035acc(0x65, i, j); break;
            case 0xd9: FUN_00035acc(0x66, i, j); break;
            case 0xda: FUN_00035acc(0x67, i, j); break;
            case 0xdb: FUN_00035acc(0x68, i, j); break;
            case 0xdc: FUN_00035acc(0x6e, i, j); break;
            case 0xdd: FUN_00035acc(0x6f, i, j); break;
            case 0xde: FUN_00035acc(0x70, i, j); break;
            case 0xdf: FUN_00035acc(0x71, i, j); break;
            case 0xe0: FUN_00035acc(0x78, i, j); break;
            case 0xe1: FUN_00035acc(0x79, i, j); break;
            case 0xe2: FUN_00035acc(0x7a, i, j); break;
            case 0xe3: FUN_00035acc(0x82, i, j); break;
            case 0xe4: FUN_00035acc(0x83, i, j); break;
            case 0x12d: FUN_00035acc(0x7b, i, j); break;
        }
        break;
    default:
        switch (id) {
        case 0x7f: case 0x81: case 0x82: case 0x83: case 0x84:
            FUN_0001e5f0(i, j, id, tgt);
            FUN_00034a9c(i, j);
            DAT_0005cf5a[i] = 1;
            break;
        case 0x4c: case 0x14a: case 0x14b: case 0x14c: case 0x14d:
            if (DAT_000567ec[ITEMS[id].sub]) {
                dir = FUN_00019418(1);
                FUN_00018a80(0, dir, i, B000755d4_ak, B000755d0_ao);
                if (!--DAT_000567ec[ITEMS[id].sub]) FUN_00034a9c(i, j);
            }
            FUN_00034b48(i, j, 0, 0x12);
            break;
        case 0x61: case 0x62: case 0x63: case 0x64:
            DAT_0005bf44 = 0x1a;
            break;
        case 0x49:
            FUN_000356c4();
            break;
        case 0x35:
            FUN_00035798();
            break;
        case 0x30:
            FUN_000353f8(i);
            o = id << 6; o += id; /* STANDIN: item offset in two statements (product node before the table base) */
            FUN_00034b48(i, j, 0, ((struct ITEM *)((char *)ITEMS + o))->speed * 9); /* STANDIN: uses the named offset above */
            break;
        case 0x31: case 0x5b:
            FUN_000354d4(i, id, j ^ 1);
            { struct ITEM *tb, *tc; int to; to = id * 0x41; tb = ITEMS; tc = tb; tb = tc; /* STANDIN: table base loaded after the product, in a block local */ FUN_00034b48(i, j, 0, ((struct ITEM *)((char *)tb + to))->speed * 9); }
            break;
        case 0x38:
            FUN_000351a0(2, 1, 0x20, 0x1e, 0xe);
            FUN_0002c124(0x53);
            break;
        case 0x126:
            FUN_00031db4(0x1f);
            break;
        case 0x78:
            FUN_000351a0(3, 2, 0x34, 0xf, 0xe);
            break;
        case 0x79:
            if (FUN_0001f4b0(0x74) && FUN_0001f4b0(0x5c) && FUN_0001f4b0(0x76) && FUN_0001f4b0(0x8b) && FUN_0001f4b0(0x77)) {
                DAT_0005bf38 = 0;
                FUN_0002f1c8();
                FUN_0002ea78();
                FUN_00038168();
                FUN_00023ef8(0xa);
                FUN_000305b4(0xc);
            } else DAT_0005bf44 = 0x35;
            break;
        case 0x113:
            FUN_000351a0(0xe, 0xf, 0x20, 0x1e, 0xe);
            FUN_0002c124(0x4a);
            DAT_0005bf44 = 0x6b;
            break;
        case 0x8c:
            FUN_000351a0(0xa, 0xa, 0x20, 0x1e, 0xf);
            break;
        case 0x8d:
            FUN_000351a0(0xb, 0xb, 0x20, 0x1e, 0xf);
            break;
        case 0x8e:
            FUN_000351a0(0xc, 0xd, 0x20, 0x1e, 0xf);
            FUN_0002c124(0x49);
            break;
        case 0x8f:
            FUN_000351a0(7, 7, 0x10, 0x1e, 0xf);
            break;
        case 0xe5:
            FUN_000351a0(8, 8, 0x66, 0x1e, 0xe);
            break;
        case 0xe6:
            if (M000718e0_iO[i].inv[(j + 0xe) ^ 1] == 0x7a) FUN_00034f60(6, 6, 0x40, 0x1e, 0xf);
            else FUN_000351a0(6, 6, 0x40, 0x1e, 0xe);
            break;
        case 0xe7:
            if (M000718e0_iO[i].inv[(j + 0xe) ^ 1] == 0x7a) FUN_00034f60(4, 3, 0x40, 0x1e, 0xf);
            else FUN_000351a0(4, 3, 0x40, 0x1e, 0xe);
            break;
        case 0x7a:
            if (M000718e0_iO[i].inv[(j + 0xe) ^ 1] == 0xe6) FUN_00034f60(6, 6, 0x40, 0x1e, 0xf);
            { int x, c; x = (j + 0xe) ^ 1; c = x; x = c; /* STANDIN: named slot index, copy out and back lifts it above j + 0xe */ if (M000718e0_iO[i].inv[x] == 0xe7) {
                FUN_00034f60(4, 3, 0x40, 0x1e, 0xf);
                FUN_0002c124(0x4f);
            } } /* STANDIN: closes the block of the named slot index */
            break;
        case 0xe8:
            FUN_000351a0(0, 5, 0x20, 0x1e, 0xe);
            break;
        case 0xe9:
            FUN_000351a0(9, 9, 0x20, 0x1e, 0xe);
            break;
        case 0xea:
            FUN_000351a0(8, 0xc, 0x3e, 0x1e, 0xe);
            break;
        case 0xeb:
            FUN_000351a0(0xd, 0xe, 0x34, 0x1e, 0xe);
            break;
        case 0x4b:
            to3 = id * 0x41; tb3 = ITEMS; tc3 = tb3; tb3 = tc3; /* STANDIN: table base loaded after the product, copy out and back */ if (DAT_000567ec[((struct ITEM *)((char *)tb3 + to3))->sub]) {
                M000718e0_iO[i].f132 |= 0x2000000;
                { int v, c; v = FUN_00029cc4() + 0x708; c = v; v = c; /* STANDIN: copy out and back lifts the sum above i*0x248 */ M000718e0_iO[i].t[25] = v; }
                o4 = id << 6; o4 += id; /* STANDIN: item offset in two statements (product node before the table base) */
                { int s = ((struct ITEM *)((char *)ITEMS + o4))->sub; DAT_0005f03e++; /* STANDIN: the charge index is read before the counter is bumped */
                if (!--DAT_000567ec[s]) FUN_00034a9c(i, j); }
                FUN_00013634(0);
            }
            FUN_00034b48(i, j, 0, 0x12);
            break;
        case 0x4e:
            o5 = id << 6; o5 += id; /* STANDIN: item offset in two statements (product node before the table base) */
            if (DAT_000567ec[((struct ITEM *)((char *)ITEMS + o5))->sub]) { /* STANDIN: uses the named offset above */
                { int d2 = FUN_00019418(1); /* STANDIN: own local for case 0x4e's direction (no store to dir's slot) */
                FUN_00018a80(6, d2, i, B000755d4_ak, B000755d0_ao); }
                o2 = id << 6; o2 += id; /* STANDIN: item offset in two statements (product node before the table base) */
                if (!--DAT_000567ec[((struct ITEM *)((char *)ITEMS + o2))->sub]) FUN_00034a9c(i, j); /* STANDIN: uses the named offset above */
            }
            FUN_00034b48(i, j, 0, 0x12);
            break;
        case 0x4d: case 0x14e: case 0x14f:
            if (DAT_000567ec[ITEMS[id].sub]) {
                dir = FUN_00019418(1);
                FUN_00018a80(3, dir, i, B000755d4_ak, B000755d0_ao);
                if (!--DAT_000567ec[ITEMS[id].sub]) FUN_00034a9c(i, j);
            }
            FUN_00034b48(i, j, 0, 0x12);
            break;
        case 0x4f:
            o3 = id << 6; o3 += id; /* STANDIN: item offset in two statements (product node before the table base) */
            if (DAT_000567ec[((struct ITEM *)((char *)ITEMS + o3))->sub]) { /* STANDIN: uses the named offset above */
                type = FUN_000195c0();
                if (type != -1) {
                    if (B00064d80_ay[type].type != 8) {
                        B00064d80_ay[type].f8 |= 8;
                        B00064d80_ay[type].timer = ((unsigned)(rand() * 5) >> 15) * 180;
                    }
                    o6 = id << 6; o6 += id; /* STANDIN: item offset in two statements (product node before the table base) */
                    if (!--DAT_000567ec[((struct ITEM *)((char *)ITEMS + o6))->sub]) FUN_00034a9c(i, j); /* STANDIN: uses the named offset above */
                }
            }
            FUN_00034b48(i, j, 0, 0x12);
            break;
        case 0x3d:
            FUN_00038110(B000758bc_al + 2, 0xff, 1, 1);
            M000718e0_iO[i].f132 |= 0x80000;
            M000718e0_iO[i].t[19] = FUN_0002c328(1, 4, 0, 4) * 0x2a30 + FUN_00029cc4();
            FUN_00034a9c(i, j);
            DAT_0005cf5a[i] = 1;
            break;
        case 0x3e:
            FUN_00038110(B000758bc_al + 2, 0xff, 1, 1);
            { int v2, c2; v2 = FUN_0002202c(i, 0x14); c2 = v2; v2 = c2; /* STANDIN: as above */ M000718e0_iO[i].f1be = v2; }
            M000718e0_iO[i].f132 |= 0x800000;
            k272 = FUN_0002c328(1, 4, 0, 4); k272 *= 0x2a30; /* STANDIN: product in two statements (product node before the call result) */ M000718e0_iO[i].t[23] = k272 + FUN_00029cc4();
            FUN_00034a9c(i, j);
            DAT_0005cf5a[i] = 1;
            break;
        case 0x40:
            FUN_00038110(B000758bc_al + 2, 0xff, 1, 1);
            M000718e0_iO[i].f132 |= 0x1000000;
            k279 = FUN_0002c328(1, 4, 0, 4); k279 *= 0x2a30; /* STANDIN: product in two statements (product node before the call result) */ M000718e0_iO[i].t[24] = k279 + FUN_00029cc4();
            FUN_00034a9c(i, j);
            DAT_0005cf5a[i] = 1;
            break;
        case 0x3f:
            ((void (*)(int, int, int))FUN_00035d24)(i, j, FUN_0002c328(2, 4, 2, 0)); /* STANDIN: called as the int-argument callee the original pushes (no cwde); FUN_00035d24 keeps its short prototype */
            break;
        case 0x3c:
            ((void (*)(int, int, int))FUN_00035d24)(i, j, FUN_0002c328(3, 8, 3, 0)); /* STANDIN: as above */
            break;
        case 0x42:
            ok = 0;
            if (M000718e0_iO[i].hp != M000718e0_iO[i].maxhp || !(M000718e0_iO[i].fl & 0xc00)) {
                FUN_00034a9c(i, j);
                FUN_00019d90(-1, i, i);
                ok = 1;
                DAT_0005cf5a[i] = 1;
            }
            { int c; c = ok; ok = c; } /* STANDIN: copy out and back lifts ok above the party-record temps */
            if (ok) sprintf(DAT_0005759c, PTR_s_feels_better_0005d8d4, M000718e0_iO[i].name);
            else sprintf(DAT_0005759c, DAT_0005d8d8, M000718e0_iO[i].name);
            FUN_0002c21c(DAT_0005759c);
            break;
        case 0x7e: case 0x80: case 0x85: case 0x86:
            FUN_0001e5f0(i, j, id, tgt);
            DAT_0005cf5a[i] = 1;
            break;
        case 0x7c:
            FUN_00035a10(i, j);
            break;
        case 0x7b:
            FUN_00038110(B000758bc_al + 2, 0xff, 1, 1);
            FUN_00034a9c(i, j);
            DAT_0005cf5a[i] = 1;
            FUN_0002c124(0x3e);
            FUN_0002c77c(i, 0x31e);
            break;
        case 0x65:
            FUN_00035c38();
            break;
        case 0x73:
            dir = FUN_00019418(1);
            FUN_0001e578(i);
            FUN_0001b02c(dir - DAT_0005c658, dir - DAT_0005c658, 0x14, FUN_0002c328(3, 6, 0, 0), 0x2100, 0, 0xb, 0, B000755d0_ao, B000755d4_ak);
            { struct ITEM *tb2, *tc2; int to2; to2 = id * 0x41; tb2 = ITEMS; tc2 = tb2; tb2 = tc2; /* STANDIN: table base loaded after the product, in a block local */ FUN_00034b48(i, j, 0, ((struct ITEM *)((char *)tb2 + to2))->speed * 9); }
            break;
        }
    }
    FUN_00029cf4();
}

#undef DAT_0005759c
#undef M000718e0_iO
#undef B000758bc_al
#undef FUN_00038110

/* ---- module data _DATA 0005d8c0-0005d8e0 (docs/data/dataown.CODE2.csv: certain), generated by tools/data2c.py */
char *PTR_s_YOU_DO_NOT_HAVE_A_QUIVER_0005d8c0 = "YOU DO NOT HAVE A QUIVER EQUIPPED";
char *PTR_s_YOU_DO_NOT_HAVE_ANY_ARROWS_0005d8c4 = "YOU DO NOT HAVE ANY ARROWS IN YOUR QUIVER";
char *PTR_s_YOU_HAVE_NO_STONES_IN_YO_0005d8c8 = "YOU HAVE NO STONES IN YOUR POUCH";
char *PTR_s_YOU_MUST_HOLD_A_SLING_ST_0005d8cc = "YOU MUST HOLD A SLING STONE OR SLING POUCH IN THE OTHER HAND.";
char *PTR_s_does_not_need_healing_0005d8d0 = "%s does not need healing.";
char *PTR_s_feels_better_0005d8d4 = "%s feels better.";
char *DAT_0005d8d8 = "%s does not need keoghtom's ointment";
unsigned char DAT_0005d8dc[4] = { 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
