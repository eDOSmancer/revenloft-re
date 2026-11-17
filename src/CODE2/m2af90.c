/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
short B0006457c_bO;
short B0006457a_ay;
short B00064578_eP;
short B00064576_dR;
short B00064574_eL;
short B00064572_eN;
short B00064570_dX;
unsigned char B000640b0_h3[1216];
/* BSS end */
/* Module: FUN_0002af90, FUN_0002b1c4, FUN_0002b27c, FUN_0002b394, FUN_0002b3f8, FUN_0002b4f8, FUN_0002b6ec,
   FUN_0002b760, FUN_0002bbd8, FUN_0002bdac */
/* ---- from build/var/mod/parts/p2af90.c */
/* FUN_0002af90 @ 0002af90: rank the four step directions towards (dx, dy) (16.16) and return the direction ranked 4 - n (random when n == 4) */
/* Round 70 (lane BS): under the module set -oa (was -oimert -s alone): both signs as `s = d < 0 ? -1 : d > 0;`, dx declared before dy,
   and one copy out and back on dx (dx / dy / sx tie at savings 58; tietrace forced order dx, dy, sx = MATCH). */
#include <stdlib.h>
void *memset(void *, int, unsigned);
extern unsigned char B000640b0_h3[1216];
int FUN_0002af90(int px, int py, int r, int n)
{
    int k; int dx; int dy; int j; int sx; int sy;
    memset(B000640b0_h3, 0, 8);
    dy = py >> 16;
    dx = px >> 16;
    { int c; c = dx; dx = c; } /* STANDIN: copy out and back, dx +4 savings: dx sorts ahead of dy / sx at 58 and takes EBX (original dy ECX, dx EBX, sx ESI) */
    sy = dy < 0 ? -1 : dy > 0;
    sx = dx < 0 ? -1 : dx > 0;
    if (dx == 0) {
        if (sy == -1) { B000640b0_h3[4] = 3; B000640b0_h3[6] = 2; B000640b0_h3[2] = 1; }
        else if (sy == 1) { B000640b0_h3[0] = 3; B000640b0_h3[6] = 2; B000640b0_h3[2] = 1; }
    } else if (dy == 0) {
        if (sx == -1) { B000640b0_h3[6] = 3; B000640b0_h3[4] = 2; B000640b0_h3[0] = 1; }
        else if (sx == 1) { B000640b0_h3[2] = 3; B000640b0_h3[4] = 2; B000640b0_h3[0] = 1; }
    } else if (abs(dx) >= abs(dy)) {
        if (sx == -1) {
            B000640b0_h3[6] = 4;
            if (sy == sx) { B000640b0_h3[4] = 3; B000640b0_h3[0] = 2; B000640b0_h3[2] = 1; }
            else { B000640b0_h3[0] = 3; B000640b0_h3[4] = 2; B000640b0_h3[2] = 1; }
        } else {
            B000640b0_h3[2] = 4;
            if (sy == -1) { B000640b0_h3[4] = 3; B000640b0_h3[0] = 2; B000640b0_h3[6] = 1; }
            else { B000640b0_h3[0] = 3; B000640b0_h3[4] = 2; B000640b0_h3[6] = 1; }
        }
    } else if (abs(dy) > abs(dx)) {
        if (sy == -1) {
            B000640b0_h3[4] = 4;
            if (sx == sy) { B000640b0_h3[6] = 3; B000640b0_h3[2] = 2; B000640b0_h3[0] = 1; }
            else { B000640b0_h3[2] = 3; B000640b0_h3[6] = 2; B000640b0_h3[0] = 1; }
        } else {
            B000640b0_h3[0] = 4;
            if (sx == -1) { B000640b0_h3[6] = 3; B000640b0_h3[2] = 2; }
            else { B000640b0_h3[2] = 3; B000640b0_h3[6] = 2; }
            B000640b0_h3[4] = 1;
        }
    }
    k = 4 - n;
    if (k) {
        for (j = 0; j < 8; j++) {
            if (B000640b0_h3[j] == k) { r = j; break; }
        }
    } else {
        r = (unsigned)(rand() * 8) >> 15;
    }
    return r;
}

/* ---- from build/var/mod/parts/p2b1c4.c */
/* FUN_0002b1c4 @ 0002b1c4: advance a monster's wander step and pick a new random target cell */
union FIX { int v; struct { short lo, hi; } h; };
struct MOB { int a, b; int pad[3]; unsigned short f0 : 6, step : 3, f9 : 5, top : 2; };
int rand(void); extern short FUN_0003d5d0(int, int, int);
void FUN_0002b1c4(struct MOB *m, int b)
{
    union FIX pos2, pos;
    m->step = (m->step + 1) % 6;
    if (m->step == 0) {
        do {
            pos2.h.hi = ((unsigned)(rand() * 12) >> 15) + 0x42;
            pos2.h.lo = (unsigned)(rand() * 0xffff) >> 15;
            pos.h.hi = ((unsigned)(rand() * 14) >> 15) + 0x2d;
            pos.h.lo = (unsigned)(rand() * 0xffff) >> 15;
        } while (FUN_0003d5d0(pos.v, pos2.v, b) == 0);
        m->top = 0;
        m->a = pos.v;
        m->b = pos2.v;
    }
}

/* ---- from build/var/mod/parts/p2b27c.c */
extern int FUN_0002af90(int px, int py, int r, int n); /* module prototype */
extern void FUN_0002b1c4(struct MOB *m, int b); /* module prototype */
#define MOB T2_MOB
/* FUN_0002b27c: turn monster m toward the party, then decide its next mode */
int rand(void);
int abs(int);
#pragma intrinsic(abs)
struct MOB { int a, b; unsigned char c8, c9, ca, cb; short cell, type, s10, cnt; unsigned short f0 : 1, f1 : 1, f2 : 1, dir : 3, step : 3, f9 : 5, top : 2; };
extern int B000755d0_ao, B000755d4_ak;
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */



void FUN_0002b27c(struct MOB *m, int b)
{
    int tx, ty, dx, dy, n;
    { extern int B000755e0_bo, B000755e4_bk, B000755e8_ag, B000755ec_aH; int d; d = B000755e0_bo; d = B000755e4_bk; d = B000755e8_ag; d = B000755ec_aH; } /* STANDIN: dead reads of scalars this function does not use - zero-savings -oa memory nodes in the pass-1 conflict list, in place of the nodes the party cell words 0x755d2 / 0x755d6 had as globals of their own (they are views of the position ints) */
    tx = B000755d0_ao;
    tx -= m->b;
    ty = B000755d4_ak - m->a;
    n = ((short *)m)[3] - B000755d2_ai;
    dx = abs(n);
    n = ((short *)m)[1] - B000755d6_ae;
    dy = abs(n);
    m->dir = FUN_0002af90(tx, ty, m->dir, 0);
    m->f0 = 1;
    if (m->top == 3) {
        FUN_0002b1c4(m, b);
        m->f0 = 0;
    } else if ((int)((unsigned)(rand() * 100) >> 15) > 0x5f) {
        m->top = 3;
        m->f0 = 0;
        m->step = 0;
    } else if (dx <= 1 && dy <= 1) {
        m->f1 = 1;
        m->f0 = 0;
        m->f2 = 0;
        m->top = 0;
        if ((int)((unsigned)(rand() * 100) >> 15) > 0x5a) m->top = 1;
    } else if ((int)((unsigned)(rand() * 100) >> 15) < 0x19) {
        m->f1 = 1;
        m->top = 2;
        m->f0 = 0;
        m->f2 = 0;
    }
}

#undef MOB
/* ---- from build/var/mod/parts/p2b394.c */
/* MATCH (round 65 lane AW) FUN_0002b760, -3s -ox -oe -oa -ot -w0, 1141/1141 (realcc). From q3: all eight -oa memory nodes taken out by record views (pre-sort list -8), the dy load copied through tt (+1 in-block node, the cross order of z/dy), and the sum operand order in the dir step; the pass-1 order then is the forced target. */
/* (FUN_0002b394 is defined in this module) */
/* FUN_0002b760: choose monster m's heading toward (or, when it flees, away from) the party and its next mode */
int rand(void);
int abs(int);
#pragma intrinsic(abs)
struct MB3 { int a, b; int fl; unsigned short cell, type; short s10, s12; unsigned short f0 : 1, f12 : 2, dir : 3, step : 3, f9 : 5, top : 2; }; /* struct MOB under its own tag: FUN_0002b394 is a part of its own in the module merge */
struct MT { char p0[0x19]; unsigned char frames; char p1[0xb]; short wait; char p3[0x16]; unsigned short snd; char p2[6]; };
extern struct MT *B00072230_c4; /* the module declaration; FUN_0002b394 reads the scalar (original: mov edx, [0x72230]) */
struct TBL { int a[12]; struct MT *p; int q; };
extern struct TBL B00072200_ew;
/* STANDIN: the monster-type table pointer B00072230_c4 read as a member (+0x30) of a record view of B00072200_ew: -1 memory node; the module declares B00072230_c4 as a scalar pointer */
void FUN_0002b394(struct MB3 *m)
{
    if ((int)((unsigned)(rand() * 1000) >> 15) >= 0x3cf) {
        m->f12 = 1;
        return;
    }
    m->f12 = 0;
    m->step = (m->step + 1) % B00072230_c4[m->type].frames;
}

/* ---- from build/var/mod/parts/p2b3f8.c */
#define MOB T4_MOB
/* FUN_0002b3f8 @ 0002b3f8: the position one step (0x5000 on the major axis) from monster m toward the party (the party cell is read as the high word of the int position: under the module's -oa a separate short global B000755d2_ai/d6 is a register candidate and moved every register) */
int abs(int);
#pragma intrinsic(abs)
struct MOB { int a, b; };
extern int B000755d0_ao, B000755d4_ak;   /* party position x, y (16.16); the cells are their high words */
void FUN_0002b3f8(int *pb, int *pa, struct MOB *m)
{
    int db, da;
    db = ((short *)&B000755d0_ao)[1] - ((short *)m)[3];
    da = ((short *)&B000755d4_ak)[1] - ((short *)m)[1];
    if (da == 0) {
        if (db == 0) {
            *pb = m->b;
            *pa = m->a;
        } else db = 0x5000;
    } else if (db == 0) {
        if (da == 0) {
            *pb = m->b;
            *pa = m->a;
        } else da = 0x5000;
    } else if (abs(db) > abs(da)) {
        db = 0x5000;
        da = (da * 0x5000 + 0x2800) / 0x5000;
    } else if (abs(da) > abs(db)) {
        da = 0x5000;
        db = (db * 0x5000 + 0x2800) / 0x5000;
    } else {
        db = 0x5000;
        da = db;
    }
    *pb = m->b + db;
    *pa = m->a + da;
}

#undef MOB
/* ---- from build/var/mod/parts/p2b4f8.c */
#define MOB T5_MOB
/* FUN_0002b4f8: move a monster one step along its heading; a sleeping one wakes when the party comes within 4 cells
   (round 63 lane AI: matched with stand-ins - the STANDIN lines only steer the pass-1 conflict list of the register allocator) */
int abs(int);
#pragma intrinsic(abs)
/* struct FIX: defined above */
struct MOB { int a, b; unsigned char c8, c9, ca, cb0 : 1, gone : 1, cb2 : 6; unsigned short cell, type; short s10, cnt; unsigned short f0 : 1, f1 : 1, f2 : 1, dir : 3, step : 3, f9 : 5, top : 2; };
extern void FUN_00038110(int, int, int, int), FUN_0003df2c(int *, int *, int, int);
 /* STANDIN: declared int (the callee returns a short in AX); with the int local below this adds one pass-1 temp in the call block without a cwde */
struct T { unsigned short wall : 6, b6 : 1, door : 1, b8 : 2, seen : 1, mark : 1, rest : 4; };
extern struct T B000698e0_b7[];
#include "world.h"
#define FUN_0003d5d0 ((int (*)(int, int, char *))FUN_0003d5d0)
struct POS { unsigned short f; short i; };
/* STANDIN: party x/y cells read as record members through the level record (0x755d0 = B00075618_b1 - 0x48, 0x755d4 = - 0x44) - removes two zero-savings -oa memory nodes; the module declares the cells as scalars */
#define PX (*(struct POS *)((char *)&B00075618_b1 - 0x48))
#define PY (*(struct POS *)((char *)&B00075618_b1 - 0x44))
/* the map width B00075619_b0 read as the level-record member (world.h): no memory node */
void FUN_0002b4f8(struct MOB *m, char *mon, char *z)
{
    int sp, ang, dx, dy, n; union FIX nx, ny, d1, d0; short xs;
    if (!m->f0) {
        if (B000698e0_b7[m->cell].b6) {
            dx = abs(((short *)m)[3] - PX.i);
            dy = abs(((short *)m)[1] - PY.i);
            if (dx <= 4 && dy <= 4) {
                m->f0 = 1;
                m->step = 0;
                if (m->type == 0x4c) FUN_00038110(0x30, 0xff, 0, 1);
                else if (m->type == 0x4b) FUN_00038110(0x2e, 0xff, 0, 1);
            }
        }
        return;
    }
    if (m->type != 0x51) sp = 0x5000;
    else sp = 0;
    ang = (8 - m->dir) * 45;
    if (ang >= 0x168) ang -= 0x168;
    FUN_0003df2c(&d1.v, &d0.v, sp, ang);
    ny.v = d1.v + m->b;
    nx.v = d0.v + m->a;
    n = FUN_0003d5d0(nx.v, ny.v, z); /* STANDIN: result through the int local n - adds one single-block temp (savings 4) in the call block of the pass-1 list */
    if ((short)n) { /* STANDIN: the cast tests AX as the short return value (test ax, ax) */
        xs = nx.h.hi * B00075618_b1.w;
        m->cell = ny.h.hi + xs;
        m->b = ny.v;
        m->a = nx.v;
        m->step = (m->step + 1) % *(unsigned char *)(mon + 0x19);
        if (m->type == 0x51 && m->step == 3 && m->top == 2) {
            m->top = 0;
            m->gone = 1;
        }
        if (m->step == 0) {
            m->top++;
            if (m->top == 3) {
                m->top = 0;
                m->gone = 1;
            }
        }
    } else m->gone = 1;
}

#undef FUN_0003d5d0
#undef MOB
#undef PX
#undef PY
/* ---- from build/var/mod/parts/p2b6ec.c */
/* FUN_0002b6ec @ 0002b6ec (module 0x2af90, -oa: n is declared before cnt, which gives n ebx and cnt ecx as in the original, and cnt is cleared first; tools/modclimb.py found the order) */
#include "chars.h"
extern unsigned char B000718e0_iO;
#define B00071a12_dx (*(int *)((char *)&B000718e0_iO + 306)) /* STANDIN: view, B000718e0_iO + 0x132 */
extern unsigned short B000718f0_hO;  
/* struct MT: defined above */
extern struct MT *B00072230_c4;
#define CH10(k) (*(unsigned short *)((char *)&B000718f0_hO + (k) * 0x248))
#define CHF(k)  (*(int *)((char *)&B00071a12_dx + (k) * 0x248))
int FUN_0002b6ec(int a)
{
    int any, n, cnt, k;
    any = 0; cnt = 0; n = 0;
    for (k = 0; k < 4; k++) {
        if (CH10(k) < 0x4000) {
            n++;
            if (CHF(k) & 0x20) any = 1;
            if (CHF(k) & 0x200) {
                if ((*(int *)((char *)B00072230_c4 + a * 0x45 + 0x3a) & 0x20) && *(unsigned char *)((char *)B00072230_c4 + a * 0x45 + 0x1d) <= 4) cnt++;
            }
        }
    }
    if (any || cnt == n) return 1;
    return 0;
}

#undef CH10
#undef CHF
/* ---- from build/var/mod/parts/p2b760.c */
extern int FUN_0002af90(int px, int py, int r, int n); /* module prototype */
extern void FUN_0002b27c(struct T2_MOB *m, int b); /* module prototype */
extern int FUN_0002b6ec(int a); /* module prototype */
#define MOB T7_MOB
extern struct MT *B00072230_c4; 
extern struct TBL B00072200_ew;

struct MOB { int a, b; int fl; unsigned short cell, type; short s10, s12; unsigned short f0 : 1, f12 : 2, dir : 3, step : 3, f9 : 5, top : 2; };
/* struct T: defined above */
extern struct T B000698e0_b7[];
struct V1 { int v; };
extern struct V1 B000758c0_kK; /* STANDIN: record view, -1 memory node */
#include "world.h"
#define FUN_0002b27c ((void (*)(struct MOB *, char *))FUN_0002b27c)
union CELL { int w; struct { unsigned short f; short i; } h; };
/* STANDIN: the party cells read as records through the level record (0x755d0 = B00075618_b1 - 0x48, 0x755d4 = - 0x44): -4 memory nodes; the module declares the cells as scalars */
#define CX (*(union CELL *)((char *)&B00075618_b1 - 0x48))
#define CY (*(union CELL *)((char *)&B00075618_b1 - 0x44))
/* the map size as level-record members (world.h), no memory node */
extern short DAT_0005a7f8[];
extern int FUN_000411e0(void);
extern void FUN_000390d0(int), FUN_00038110(int, int, int, int);
void FUN_0002b760(struct MOB *m, char *z, int n)
{
    int dy, dx, d;
    int tt; /* STANDIN: copy-through temp for dy */
    if (m->type == 8) {
        FUN_0002b27c(m, z);
        return;
    }
    if (m->type == 0xf) {
        if (B000698e0_b7[m->cell].b6) FUN_0002b394((struct MB3 *)m);
        return;
    }
    if (m->fl & 0x40000000) {
        m->dir = (unsigned)(rand() * 8) >> 15;
        m->f0 = 1;
        m->s12 = (unsigned)(rand() * 25) >> 15;
        return;
    }
    FUN_000390d0((unsigned short)FUN_000411e0());
    if (FUN_0002b6ec(m->type)) {
        dx = B00075618_b1.w;
        dx *= rand();
        tt = B00075618_b1.h; dy = tt; /* STANDIN: copy through tt (+1 in-block node) */
        dy *= rand();
        dx = CX.w - ((int)((unsigned)dx >> 15) << 16);
        dy = CY.w - ((int)((unsigned)dy >> 15) << 16);
    } else {
        dx = CX.h.i - ((short *)m)[3];
        dy = CY.h.i - ((short *)m)[1];
        dx <<= 16;
        dy <<= 16;
    }
    d = FUN_0002af90(dx, dy, m->dir, n);
    if ((m->fl & 0x10)) d = (d + 4) % 8;
    if (FUN_0002b6ec(m->type)) d = (d + 4) % 8;
    if (abs(dx) == 0 || abs(dy) == 0) m->top = 0;
    if (abs(dx) <= 0xa0000 && abs(dy) <= 0xa0000) {
        if (m->fl & 0x20000000) {
            m->fl &= ~0x30000000;
            m->fl |= 0x10000000;
        }
        m->f0 = 1;
        if (!(m->fl & 0x10)) {
            m->top = 0;
            if ((int)((unsigned)(rand() * 1000) >> 15) > 0x3de)
                FUN_00038110(B00072200_ew.p[m->type].snd + B000758c0_kK.v, 0xff, 0, 1);
            if (abs(dx) <= 0x15000 && abs(dy) <= 0x15000 && n == 0 && m->dir == d) {
                m->f12 = 1;
                m->fl &= ~0x30000000;
                m->fl |= 0x10000000;
                return;
            }
        }
    } else if (abs(dx) >= 0xd0000 || abs(dy) >= 0xd0000) {
        if (m->fl & 0x10000000) {
            m->fl &= ~0x30000000;
            m->f0 = 0;
            m->fl |= 0x20000000;
        }
    } else m->f0 = 1;
    if (m->type == 9 && ((short *)m)[3] == 0x18 && ((short *)m)[1] == 7 && m->dir != d) m->dir = d;
    if (m->top) {
        m->f0 = 1;
        m->top--;
        return;
    }
    if (n && m->type != 0x21) {
        m->dir = d;
        m->top = ((unsigned)(rand() * 2) >> 15) + 1;
        m->f0 = 1;
    }
    if (m->type == 0x21) {
        d = m->dir;
        m->f0 = 0;
    }
    if (m->dir != d) {
        if (m->type == 9) m->dir = d;
        else {
            m->dir = ((int)m->dir + DAT_0005a7f8[(int)(m->dir + 8 - d) % 8]) % 8; /* STANDIN: operand order of the sum (movzx before the table load) */
            m->f0 = 0;
        }
    } else if (!FUN_0002b6ec(m->type)) {
        if (!m->f0) {
            if (n == 0 && (m->fl & 0x30000000)) {
                m->f12 = 1;
                m->fl &= ~0x30000000;
                m->fl |= 0x10000000;
            }
        } else if (m->fl & 0x20000000) m->f0 = 0;
    }
    FUN_000390d0((unsigned short)FUN_000411e0());
}

#undef FUN_0002b27c
#undef MOB
#undef CX
#undef CY
/* ---- from build/var/mod/parts/p2bbd8.c */
extern void FUN_0002b760(struct T7_MOB *m, char *z, int n); /* module prototype */
#define MOB T8_MOB
/* MATCH (round 22): alone and in module 0x2af90. First difference was the dead second `je` after `cmp byte [DAT_0005c02f],0`: two source tests of the same global, `!G || (G && !(step & 1))` (the second cmp is dropped as redundant, its jump stays). Then the type-9 block jumps to the last else's f0 clear: one `m->f0 = 0` at the loop end after if (type 9) {...} else {... if (ok) ... else if (type 8) {top, step, f0} else if (tries < 3) {...; continue;} else {flag}}, which replaces the goto stand-in. Registers of the two w*y products and the ny/nx slots: module 0x2af90 reads the map width/height as short scalars B00075619_b0/B0007561b_io (not world.h's LEV members; FUN_0002b4f8 162 / FUN_0002b760 385 lines with scalars, 276 / 659 as members); `union FIX nx, ny, dy, dx`. 7 real compiles. */
/* history (round 19): the type-9 step is 16-bit (m[3]++; m[6] = xs + m[3]), the success block in FUN_0002b4f8's sibling order (recipe 61), union FIX locals. */
/* FUN_0002bbd8 @ 0002bbd8: move monster m (kind data mon) until its move flag clears: pick a heading, step, retry up to three times when blocked */
#include "world.h"
#define FUN_0003d5d0 ((short (*)(int, int, char *))FUN_0003d5d0)
/* struct FIX: defined above */
struct MOB { int a, b; unsigned char c8, c9, ca, cb0 : 6, held : 1, cb7 : 1; short cell, type, s10, cnt; unsigned short f0 : 1, f1 : 1, f2 : 1, dir : 3, step : 3, f9 : 5, top : 2; };
extern void FUN_0003df2c(int *, int *, int, int); 
#define B00075619_b0 (*(short *)((char *)&B00075618_b1 + 1)) /* STANDIN: view, B00075618_b1 + 0x1 */
extern unsigned char DAT_0005c02f; 
void FUN_0002bbd8(struct MOB *m, char *mon, char *z)
{
    int tries, ang, sp; union FIX nx, ny, dy, dx; short xs;
    { int d; d = B000755d0_ao; } /* STANDIN: dead read of a scalar this function does not use - one zero-savings -oa memory node in the pass-1 conflict list, in place of the node the map width had as a global of its own (it is a view of the level record) */
    tries = 0;
    if (m->held) {
        if (((short *)m)[9] == 0) FUN_0002b760(m, z, 1);
        else {
            ((short *)m)[9]--;
            m->f0 = 1;
        }
    } else FUN_0002b760(m, z, tries);
    while (m->f0) {
        if (((unsigned short *)m)[7] == 9) {
            if (((short *)m)[3] != 0x18 || ((short *)m)[1] != 7)
            {
                xs = ((short *)m)[1] * B00075619_b0;
                ((short *)m)[3]++;
                ((short *)m)[6] = xs + ((short *)m)[3];
            }
        } else {
            if (!DAT_0005c02f || (DAT_0005c02f && !(m->step & 1))) {
                sp = *(unsigned short *)(mon + m->step * 2 + 0x29);
                ang = (8 - m->dir) * 45;
                if (ang >= 0x168) ang -= 0x168;
                FUN_0003df2c(&dy.v, &dx.v, sp, ang);
                ny.v = dy.v + m->b;
                nx.v = dx.v + m->a;
            } else {
                ny.v = m->b;
                nx.v = m->a;
            }
            if (FUN_0003d5d0(nx.v, ny.v, z)) {
                xs = nx.h.hi * B00075619_b0;
                ((short *)m)[6] = ny.h.hi + xs;
                m->b = ny.v;
                m->a = nx.v;
                m->step = (m->step + 1) % *(unsigned char *)(mon + 0x19);
            } else if (((unsigned short *)m)[7] == 8) {
                m->top = 3;
                m->step = 0;
                m->f0 = 0;
            } else if (tries < 3) {
                tries++;
                m->top = 0;
                FUN_0002b760(m, z, tries);
                continue;
            } else {
                *((unsigned char *)m + 8) &= 0xef;
            }
        }
        m->f0 = 0;
    }
}

#undef FUN_0003d5d0
#undef MOB
/* ---- from build/var/mod/parts/p2bdac.c */
extern void FUN_0002b4f8(struct T5_MOB *m, char *mon, char *z); /* module prototype */
extern void FUN_0002bbd8(struct T8_MOB *m, char *mon, char *z); /* module prototype */
#define MOB T9_MOB
/* FUN_0002bdac: per frame, step every monster, missile, timed object and projectile (round 65 lane AO: MATCH under -3s -ox -oe -oa -ot -w0).
   Natural changes against r62aa m2.c: the three list counts as struct LEV members (world.h: B00075618_b1.nent / n4 / ndoor),
   memmove's destination written &B00067618_e7[i] (not m) with the byte count * 0x16.  Stand-ins (tie order only, code unchanged):
   tq (copy of the monster-type record pointer, declared first) and tt (copy of the loop-4 frame remainder). */
/* FUN_0002bdac: per frame, step every monster, missile, timed object and projectile */
#include "world.h"
#define FUN_0002b4f8 ((void (*)(struct MOB *, struct MT *, int))FUN_0002b4f8)
#define FUN_0002bbd8 ((void (*)(struct MOB *, struct MT *, int))FUN_0002bbd8)
void *memmove(void *, const void *, unsigned);
struct MOB { int a, b; int fl; unsigned short cell, type; short s10, s12; unsigned short f0 : 1, f12 : 2, dir : 3, step : 3, del : 1, f10 : 4, top : 2; };
/* struct MT: defined above */
extern struct MT *B00072230_c4;
extern unsigned char *B00072234_hx;
extern struct MOB B00064d80_ay[], B00072238_dL[], B00067618_e7[], B000748ec_bk[];

extern int DAT_0005c038;
extern unsigned char DAT_0005bf38;
extern void FUN_0001d550(struct MOB *, struct MT *, int);
extern void FUN_00032e90(struct MOB *, int), FUN_00018c88(int), FUN_00019070(struct MOB *, int);
extern int FUN_0003388c(struct MOB *, int), FUN_00018cf4(struct MOB *, int);
extern short FUN_0003d5d0(int, int, int);
void FUN_0002bdac(void)
{
    struct MT *tq; /* STANDIN: named temp for the copy below, declared first (rough-sort entry position) */
    unsigned char *ot, *o; int i; struct MOB *m; struct MT *t;
    int tt; /* STANDIN: named temp for the copy below (pass-1 tie order) */
    if (DAT_0005bf38) {
        for (i = 0; i < B00075618_b1.nent; i++) {
            m = &B00064d80_ay[i];
            tq = &B00072230_c4[m->type]; t = tq; /* STANDIN: copy through a named temp - door-loop table pointer in edi */
            if (m->fl & 0x2000000) continue;
            if (m->s10 == 0) {
                if (m->fl & 8) m->fl &= ~8;
                switch (m->f12) {
                case 1:
                    m->f12 = 2;
                    FUN_0001d550(m, t, i);
                    m->s10 = t->wait;
                    if (m->fl & 0x80) m->s10 *= 3;
                    break;
                case 2:
                    m->s10 = 7;
                    m->f12 = 0;
                    if (m->fl & 0x80) m->s10 *= 3;
                    break;
                case 3:
                    m->f12 = 0;
                case 0:
                    if (m->fl & 0x70000000) FUN_0002bbd8(m, t, i);
                    else if (m->fl & 0x4000000) FUN_0002b4f8(m, t, i);
                    else if (t->frames) m->step = (m->step + 1) % t->frames;
                    m->s10 = t->wait;
                    if (m->fl & 0x80) m->s10 *= 3;
                    break;
                }
            } else m->s10--;
        }
    }
    for (i = 0; i < B00075618_b1.ndoor; i++) {
        m = &B00072238_dL[i];
        if (m->type != 0x54) {
            ot = B000755dc_aX + m->type * 7;
            m->step = (m->step + 1) % ot[5];
        }
    }
    for (i = 0; i < B00075618_b1.n4; i++) {
        m = &B00067618_e7[i];
        if (m->del && FUN_0003388c(m, 1)) {
            memmove(&B00067618_e7[i], &B00067618_e7[i + 1], (B00075618_b1.n4 - 1 - i) * 0x16);
            i--;
            B00075618_b1.n4--;
        }
    }
    for (i = 0; i < DAT_0005c038; i++) {
        m = &B000748ec_bk[i];
        o = B00072234_hx + m->type * 7;
        if (m->type < 8) {
            if (DAT_0005bf38) {
                FUN_00032e90(m, 1);
                if (m->f12) {
                    FUN_00018c88(i);
                    i--;
                }
            }
        } else {
            if (DAT_0005bf38) {
                if (!FUN_0003d5d0(m->a, m->b, 0x190)) {
                    if (m->type != 8 || (m->type == 8 && m->step == 0)) {
                        FUN_00019070(m, 1);
                        FUN_00018cf4(m, 1);
                    }
                }
                if (m->type == 8) {
                    if (m->s12 == 0) {
                        FUN_00018c88(i);
                        i--;
                        continue;
                    }
                    m->s12--;
                }
            }
            tt = (m->step + 1) % o[5]; m->step = tt; /* STANDIN: copy through a named temp - loop-4 type in edi, o in ebp */
        }
    }
}

#undef FUN_0002b4f8
#undef FUN_0002bbd8
#undef MOB

/* ---- module data _DATA 0005a7f8-0005bed8 (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
short DAT_0005a7f8[8] = { 0, 7, 7, 7, 1, 1, 1, 1 };
unsigned char DAT_0005a808[5840] = {
    0x47, 0x4c, 0x4f, 0x52, 0x49, 0x41, 0x4e, 0x4e, 0x41, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x11, 1, 5, 4, 0xff, 0xff, 0x96, 0, 2, 10, 0x1e, 0, 0x1e, 0,
    5, 0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x5d, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 10, 10, 0xe, 0xe, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x10, 0x10, 0, 0,
    0xa6, 0, 2, 1, 0x3c, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x26, 0,
    0x5d, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0,
    0, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x56, 0x45, 0x4c, 0x49, 0x4b, 0x41, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x13, 1, 1, 0, 4, 5,
    0x24, 0, 4, 10, 0x1b, 0, 0x1b, 0, 4, 0, 4, 0, 5, 0, 0x10, 0x27,
    0, 0, 0x10, 0x27, 0, 0, 0x10, 0x27, 0, 0, 0xe, 0xe, 0x12, 0x12, 0x10, 0x10,
    0xd, 0xd, 0xc, 0xc, 0x10, 0x10, 0, 0, 0xa6, 0, 0x32, 0, 0x2b, 0, 0x2f, 0,
    0x2f, 0, 0xb0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0, 0xff, 0xff, 0xb, 1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff,
    0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x4d, 0x49, 0x53, 0x43, 0x48, 0x41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x15, 0, 0, 3, 0xff, 0xff, 0x1b, 0, 2, 10, 1, 0, 0x20, 0,
    4, 0, 0xff, 0xff, 0xff, 0xff, 0x40, 0x1f, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf, 0xf, 0xe, 0xe, 0x12, 0x12, 0xf, 0xf, 0x10, 0x10, 0x11, 0x11, 0, 0,
    0x3c, 0, 0x3c, 0, 0xce, 0, 0xd9, 0, 0xd7, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0, 0xff, 0xff,
    0xe, 0, 0x1b, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x56, 0x55, 0x4b, 0x4f, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x14, 0, 0, 5, 0xff, 0xff,
    0x23, 0, 5, 10, 0x20, 0, 0x20, 0, 7, 0, 0xff, 0xff, 0xff, 0xff, 0x28, 0xa0,
    0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe, 0xe, 0x11, 0x11, 0x10, 0x10,
    0xd, 0xd, 0xc, 0xc, 0xe, 0xe, 0, 0, 0x32, 0, 0x2b, 0, 0x2f, 0, 0x2f, 0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0, 0xff, 0xff, 0x5d, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x54, 0x41, 0x54, 0x49, 0x41, 0x4e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x12, 1, 1, 0, 0xff, 0xff, 0x19, 0, 2, 10, 0x1c, 0, 0x1c, 0,
    4, 0, 0xff, 0xff, 0xff, 0xff, 0xd4, 0x30, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc, 0xc, 0xd, 0xd, 0x11, 0x11, 0xc, 0xc, 0xc, 0xc, 0x12, 0x12, 0, 0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x28, 0, 0xff, 0xff,
    8, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x49, 0x52, 0x4d, 0x47, 0x41, 0x52, 0x44, 0x45,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x14, 1, 1, 3, 0xff, 0xff,
    0x1e, 0, 2, 10, 0x22, 0, 0x22, 0, 6, 0, 0xff, 0xff, 0xff, 0xff, 0x30, 0x75,
    0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe, 0xe, 0x11, 0x11, 0x10, 0x10,
    0xe, 0xe, 0x11, 0x11, 0x10, 0x10, 0, 0, 0x31, 0, 0x42, 0, 0x42, 0, 0xcb, 0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x26, 0, 0xff, 0xff, 0xe, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x41, 0x4e, 0x53, 0x48, 0x45, 0x4c, 0x4d, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x13, 0, 0, 0, 0xff, 0xff, 0x24, 0, 4, 10, 0x2b, 0, 0x33, 0,
    6, 0, 0xff, 0xff, 0xff, 0xff, 0xb8, 0x88, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x12, 0x12, 0xd, 0xd, 0x10, 0x10, 0xb, 0xb, 10, 10, 0xe, 0xe, 0x64, 0x64,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x52, 0x59, 0x53, 0x5a, 0x41, 0x52, 0x44, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x12, 0, 0, 4, 0xff, 0xff,
    0x28, 0, 5, 10, 0x12, 0, 0x12, 0, 6, 0, 0xff, 0xff, 0xff, 0xff, 0x80, 0xbb,
    0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 10, 10, 0xc, 0xc, 0xd, 0xd,
    0x11, 0x11, 0x12, 0x12, 0xd, 0xd, 0, 0, 0xa6, 0, 0x41, 0, 0x41, 0, 0x2b, 0,
    0x4c, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 10, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x51, 0, 0, 0, 0xff, 0, 0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0xff, 0xff,
    0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0xff, 0xff,
    0xff, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x56, 0x4c, 0x41, 0x44, 0x49, 0x53, 0x4c, 0x41, 0x56, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x16, 0, 1, 0, 0xff, 0xff, 0x34, 0, 5, 10, 0x41, 0, 0x41, 0,
    7, 0, 0xff, 0xff, 0xff, 0xff, 0xe8, 0xfd, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x11, 0x11, 0xf, 0xf, 0x12, 0x12, 0xf, 0xf, 0xd, 0xd, 0x11, 0x11, 0, 0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0, 0xff, 0xff,
    0x14, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x46, 0x48, 0x41, 0x4c, 0x4b, 0x45, 0x4e, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x11, 0, 0, 0, 0xff, 0xff,
    0x2d, 0, 4, 10, 0x19, 0, 0x22, 0, 5, 0, 0xff, 0xff, 0xff, 0xff, 0x6e, 0x41,
    0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x12, 0x12, 0xd, 0xd, 0xe, 0xe,
    0xc, 0xc, 10, 10, 0xb, 0xb, 0xf, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff
};   /* only other modules name it: bytes */
/* ---- end of module data _DATA */
