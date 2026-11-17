/* Module: FUN_00029c80, FUN_00029cc4, FUN_00029ccc, FUN_00029cf4, FUN_00029d18, FUN_0002a064, FUN_0002a0b0,
   FUN_0002a1d0, FUN_0002a1f4, FUN_0002a220, FUN_0002a344, FUN_0002a3b8, FUN_0002a510, FUN_0002a5b0,
   FUN_0002a724, FUN_0002a8c8, FUN_0002a9f8, FUN_0002aacc, FUN_0002ab20, FUN_0002a288, FUN_0002ac0c,
   FUN_0002ac38, FUN_0002ae30 */
/* STANDIN: the cursor record (0x585fc) and the mouse record (0x59e31) are defined here as their first member's bytes
   followed by the members other modules name as scalars (DAT_00058600 / 58602, DAT_00059e33 / 35 / 37 / 39: -oa memory
   nodes there); this module reads them as records through the first symbol's address, which gives the same code as a
   record declaration (no -oa node) */
#define CURSV (*(struct CURSOR *)DAT_000585fc)
#define MOUSEV (*(struct MOUSE *)DAT_00059e31)
/* ---- from build/var/mod/parts/p29c80.c */
/* FUN_00029c80 @ 00029c80 */
extern unsigned FUN_00040700(void); extern void FUN_00032ce0(int, int, int);
extern unsigned char DAT_0005a79c; extern unsigned DAT_0005a790; extern int DAT_0005a794, DAT_0005a798, DAT_0005a7e8, DAT_0005a7e4;
void FUN_00029c80(void)
{
    if (DAT_0005a79c) {
        if (FUN_00040700() > DAT_0005a790) {
            FUN_00032ce0(DAT_0005a794, DAT_0005a798, 2);
            DAT_0005a79c = 0;
        }
    }
    if (DAT_0005a7e8) DAT_0005a7e4++;
}

/* ---- from build/var/mod/parts/p29cc4.c */
/* FUN_00029cc4 @ 00029cc4: getter */
extern int DAT_0005a7e4;
int FUN_00029cc4(void) { return DAT_0005a7e4; }

/* ---- from build/var/mod/parts/p29ccc.c */
/* FUN_00029ccc @ 00029ccc: push onto a small undo stack (14 entries) */
extern unsigned char DAT_0005a7ec;
extern int DAT_0005a7e8;
extern unsigned char B000640a0_hC[];
void FUN_00029ccc(int v)
{
    if (DAT_0005a7ec < 14) {
        B000640a0_hC[DAT_0005a7ec] = DAT_0005a7e8;
        DAT_0005a7ec++;
        DAT_0005a7e8 = v;
    }
}

/* ---- from build/var/mod/parts/p29cf4.c */
/* FUN_00029cf4 @ 00029cf4: pop from the undo stack (module flag -oa caches the counter in dl) */
extern unsigned char DAT_0005a7ec;
extern int DAT_0005a7e8;
extern unsigned char B000640a0_hC[];
void FUN_00029cf4(void)
{
    if (DAT_0005a7ec) DAT_0005a7e8 = B000640a0_hC[--DAT_0005a7ec];
}

/* ---- from build/var/mod/parts/p29d18.c */
extern void FUN_0002aacc(void); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* FUN_00029d18 @ 00029d18: mouse driver event callback (event mask ev, buttons btn, position x/y or the joystick record p): queue clicks, auto-repeat the map clicks, turn joystick deflection into cursor keys and redraw the cursor (saves every register but eax) */
#include "records.h"
#define FUN_00040700 ((int (*)(void))FUN_00040700)
extern unsigned char DAT_00059e31[2]; extern struct CLIPR DAT_0005ef69;
extern int FUN_0003e34c(void); extern void FUN_0002f820(void), FUN_00032ce0(int, int, int), FUN_00040748(int), FUN_000407f0(int), FUN_00039738(void *), FUN_000396c0(int, int, int, int);
extern short DAT_0005a6be, DAT_0005a6bc, DAT_0005cf48, DAT_0005a6ba, DAT_0005a6b4, DAT_0005a6b6, DAT_0005a6b8, DAT_0005a6c2, DAT_0005a6c4, DAT_0005a6c6, DAT_0005a6c8, DAT_0005a6ca;
extern unsigned char DAT_0005d680, DAT_0005a79c, DAT_0005c025; extern unsigned DAT_0005a790; extern int DAT_0005a794, DAT_0005a798, DAT_0005a6cc, DAT_0005a6d0, DAT_0005a6d4, DAT_0005a6d8;
#pragma aux FUN_00029d18 modify exact [eax gs];
void FUN_00029d18(int ev, int btn, int x, int y, short *p)
{
    int t, e;
    t = FUN_0003e34c();
    x >>= 1;
    if (t) {
        y = ((p[1] + 0x1fc0) * 0x18f + 0x1fa0) / 0x3f40;
        x = ((p[0] + 0x1fc0) * 0x13f + 0x1fa0) / 0x3f40;
    }
    if (!(btn & 3)) {
        DAT_0005a6be = 0;
        DAT_0005a6bc = 0;
        FUN_0002f820();
    }
    if (!DAT_0005d680 && DAT_0005cf48 == 1 && (ev & 8) && y > 0x113) {
        e = ev & ~8;
        if (!DAT_0005a79c) {
            DAT_0005a79c = 1;
            t = FUN_00040700();
            ev = e;
            DAT_0005a794 = y;
            DAT_0005a798 = x;
            DAT_0005a790 = t + DAT_0005c025;
        } else if ((unsigned)FUN_00040700() < DAT_0005a790) {
            FUN_00032ce0(DAT_0005a794, DAT_0005a798, 8);
            DAT_0005a79c = 0;
            ev = e;
        }
    }
    if (DAT_0005cf48 == 1 && (ev & 0xa)) FUN_00032ce0(y, x, btn);
    if (ev & 0xff80) {
        if (ev & 0x1000) {
            FUN_00040748(0x48);
            FUN_00040748(0x50);
            if (p[3] < -1000) FUN_000407f0(0x48);
            if (p[3] > 1000) FUN_000407f0(0x50);
        }
        if (ev & 0x4000) {
            FUN_00040748(0x47);
            FUN_00040748(0x49);
            if (p[5] < -1000) FUN_000407f0(0x49);
            if (p[5] > 1000) FUN_000407f0(0x47);
        }
        if (ev & 0x2000) {
            FUN_00040748(0x4f);
            FUN_00040748(0x51);
            if (p[4] > 1000) FUN_000407f0(0x4f);
            if (p[4] < -1000) FUN_000407f0(0x51);
        }
    }
    if (MOUSEV.on >= 1 && DAT_0005cf48 == 1 && !DAT_0005a6ba) {
        if (MOUSEV.x != y || MOUSEV.y != x) {
            DAT_0005a6b8 = btn;
            DAT_0005a6c4 = DAT_0005ef69.x;
            DAT_0005a6c6 = DAT_0005ef69.y;
            DAT_0005a6c8 = DAT_0005ef69.w;
            DAT_0005a6b4 = y;
            DAT_0005a6ca = DAT_0005ef69.h;
            DAT_0005a6b6 = x;
            FUN_00039738(&DAT_0005a6cc);
            FUN_000396c0(0, 0, 0x18f, 0x13f);
            FUN_0002aacc();
            FUN_0002a288();
            FUN_000396c0(DAT_0005a6cc, DAT_0005a6d4, DAT_0005a6d0, DAT_0005a6d8);
            DAT_0005ef69.x = DAT_0005a6c4;
            DAT_0005ef69.y = DAT_0005a6c6;
            DAT_0005ef69.w = DAT_0005a6c8;
            DAT_0005ef69.h = DAT_0005a6ca;
        }
        DAT_0005a6b8 = btn;
        if (!MOUSEV.x) DAT_0005a6c2 = 1;
    }
}

#undef FUN_00040700
/* ---- from build/var/mod/parts/p2a064.c */
/* FUN_0002a064 @ 0002a064: install the mouse event handler for event mask m (INT 33h function 0Ch) */
#include <i86.h>
extern union REGS DAT_0005a7ac, DAT_0005a7c8; extern struct SREGS DAT_0005a79e;
extern void __far FUN_00037894();
#pragma aux FUN_0002a064 modify [eax];
void FUN_0002a064(int m)
{
    void (__far *h)() = FUN_00037894;
    DAT_0005a7ac.w.ax = 0xc;
    DAT_0005a7ac.w.cx = m;
    DAT_0005a7ac.x.edx = FP_OFF(h);
    DAT_0005a79e.es = FP_SEG(h);
    int386x(0x33, &DAT_0005a7ac, &DAT_0005a7c8, &DAT_0005a79e);
}

/* ---- from build/var/mod/parts/p2a0b0.c */
extern void FUN_0002a064(int m); /* module prototype */
extern void FUN_0002aacc(void); /* module prototype */
/* FUN_0002a0b0 @ 0002a0b0: initialise the mouse driver and the cursor state */
#include "records.h"
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
void *memmove(void *, const void *, unsigned);
extern int FUN_0003e340(void); extern void FUN_00043d38(int, int), FUN_00043d18(int, int), FUN_00043c90(int, int), FUN_000396c0(int, int, int, int); extern char *FUN_00043cb0(void); extern void *FUN_0003f29c(int, int);
extern short DAT_0005a6b8, DAT_0005a6b4, DAT_0005a6b6; extern unsigned char DAT_00059e21[]; extern unsigned char DAT_0005ef4e, DAT_0005880d[]; extern int B000758dc_cl;
void FUN_0002a0b0(void)
{
    int k, j; char *p; void *q; short mx, my;
    CURSV.on = FUN_0003e340();
    if (CURSV.on) {
        FUN_00043d38(0, 0x18f);
        FUN_00043d18(0, 0x27e);
        FUN_00043c90(0xc8, 0xa0);
        p = FUN_00043cb0();
        MOUSEV.on = 0;
        DAT_0005a6b8 = 0;
        MOUSEV.b = 0;
        CURSV.spr = -1;
        CURSV.id = -1;
        CURSV.f = 0;
        mx = *(short *)(p + 6);
        my = *(short *)(p + 4);
        DAT_0005a6b4 = mx;
        DAT_0005a6b6 = my;
        MOUSEV.y = my;
        MOUSEV.pg = DAT_0005ef4e;
        MOUSEV.x = mx;
        for (k = 0; k < 2; k++)
            for (j = 0; j < 4; j++) *(short *)((char *)&DAT_00059e21 + (k * 8 + j * 2)) = -1;
        q = FUN_0003f29c(B000758dc_cl + 0x2f, 0);
        memmove(DAT_0005880d, q, 0x1614);
        FUN_000396c0(0, 0, 0x18f, 0x13f);
        FUN_0002a064(0xffff);
    }
}

extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern int FUN_0003e340(void); extern void FUN_00043d38(int, int), FUN_00043d18(int, int), FUN_00043c90(int, int), FUN_000396c0(int, int, int, int); extern char *FUN_00043cb0(void); extern void *FUN_0003f29c(int, int);
extern short DAT_0005a6b8, DAT_0005a6b4, DAT_0005a6b6; extern unsigned char DAT_00059e21[]; extern unsigned char DAT_0005ef4e, DAT_0005880d[]; extern int B000758dc_cl;

extern void FUN_00043b44(void);
/* FUN_0002a1d0 @ 0002a1d0: refresh the mouse cursor (redraw it when it is shown) */
void FUN_0002a1d0(void)
{
    if (CURSV.on) {
        if (MOUSEV.on) FUN_0002aacc();
        FUN_00043b44();
    }
}

/* ---- from build/var/mod/parts/p2a1f4.c */
/* FUN_0002a1f4 @ 0002a1f4: poll the mouse buttons (stored in DAT_00059e35); returns the left/right bits */
#include "records.h"
#define FUN_00043cb0 ((short *(*)(void))FUN_00043cb0)
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_0003f868(void); 

int FUN_0002a1f4(void)
{
    FUN_0003f868();
    if (CURSV.on) {
        short *p = FUN_00043cb0();
        MOUSEV.b = *p;
        return *p & 3;
    }
    return 0;
}

#undef FUN_00043cb0
/* ---- from build/var/mod/parts/p2a220.c */
extern void FUN_0002aacc(void); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* m2a220: FUN_0002a220 ends in a call of FUN_0002a288 (defined in f2a9f8.c after FUN_0002ab20), which 10.0a turns into a jump
   and lays FUN_0002a288's head behind (see the note there). */
#include "records.h"
extern unsigned char DAT_00059e31[2];
extern void FUN_00043c90(int, int);
extern short DAT_0005cf48; extern int DAT_0005a7f0, DAT_0005a7f4;

void mouse_motion(void);
#pragma aux mouse_motion = 0xb8 0x0b 0x00 0x00 0x00 0xcd 0x33 modify [eax ecx edx];
/* FUN_0002a220 @ 0002a220: toggle mouse capture: restore or save the cursor position, reset the motion counters, redraw the cursor (falls into FUN_0002a288) */
void FUN_0002a220(void)
{
    FUN_0002aacc();
    DAT_0005cf48 ^= 1;
    if (DAT_0005cf48 == 1) {
        FUN_00043c90(DAT_0005a7f0, DAT_0005a7f4);
        MOUSEV.x = DAT_0005a7f0;
        MOUSEV.y = DAT_0005a7f4;
    } else {
        DAT_0005a7f0 = MOUSEV.x;
        DAT_0005a7f4 = MOUSEV.y;
    }
    mouse_motion();
    FUN_0002a288();
}

/* ---- from build/var/mod/parts/p2a344.c */
extern void FUN_0002aacc(void); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* FUN_0002a344 @ 0002a344: select the item held in hand (tail-calls FUN_0002a288) */
#include "records.h"
extern short DAT_000585fc[2];
#include "world.h"
void *memmove(void *, const void *, unsigned);
 extern void *FUN_0003f29c(int, int);
extern unsigned char DAT_00058603[];  
void FUN_0002a344(short a, unsigned char b)
{
    void *p;
    FUN_0002aacc();
    CURSV.f = 0;
    CURSV.spr = CURSV.id = a;
    if (a != -1) {
        CURSV.spr = *(short *)(((char *)B000755d8_aw) + a * 0x41 + 0x2d);
        CURSV.f = b;
        p = FUN_0003f29c(CURSV.spr, 1);
        memmove(DAT_00058603, p, 0x20a);
    }
    FUN_0002a288();
}

/* ---- from build/var/mod/parts/p2a3b8.c */
/* FUN_0002a3b8 @ 0002a3b8: read the mouse position, clamping it to the active region; returns 1 when it was clamped/active */
extern void FUN_00043c90(int, int), FUN_0002f820(void);
extern unsigned char DAT_0005d680; extern short DAT_0005a6be, DAT_0005a6bc, DAT_0005a6b4, DAT_0005a6b6, DAT_0005a6b8;
int FUN_0002a3b8(short *px, short *py, short *pb)
{
    int r, x, y;
    r = 0;
    if (DAT_0005d680 == 0) {
        if (DAT_0005a6be) {
            if (DAT_0005a6b4 < 0x124) DAT_0005a6b4 = 0x124;
            else if (DAT_0005a6b4 > 0x187) DAT_0005a6b4 = 0x187;
            if (DAT_0005a6b6 < 0x7e) DAT_0005a6b6 = 0x7e;
            else if (DAT_0005a6b6 > 0xc3) DAT_0005a6b6 = 0xc3;
            FUN_00043c90(DAT_0005a6b4, DAT_0005a6b6);
            r = 1;
        }
        if (DAT_0005a6bc) {
            x = DAT_0005a6b4;
            y = DAT_0005a6b6;
            if (x < 4) x = 4;
            else if (x >= 0x104) x = 0x103;
            if (y < 0x11) y = 0x11;
            else if (y >= 0x120) y = 0x11f;
            if (DAT_0005a6b4 != x || DAT_0005a6b6 != y) {
                FUN_00043c90(x, y);
                DAT_0005a6b4 = x;
                DAT_0005a6b6 = y;
            }
            r = 1;
        }
    } else {
        DAT_0005a6be = 0;
        DAT_0005a6bc = 0;
        FUN_0002f820();
    }
    *px = DAT_0005a6b4;
    *py = DAT_0005a6b6;
    *pb = DAT_0005a6b8;
    return r;
}

/* ---- from build/var/mod/parts/p2a510.c */
extern void FUN_0002ab20(int x, int y); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* FUN_0002a510 @ 0002a510: show page p; with the mouse cursor active, hide it on the old page and redraw it on the new one */
#include "records.h"
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_000391c8(unsigned char);
extern short DAT_0005a6ba; 
void FUN_0002a510(int p)
{
    int x, y;
    if (CURSV.on && MOUSEV.on >= 1) {
        DAT_0005a6ba = 1;
        x = MOUSEV.x;
        MOUSEV.on = 0;
        y = MOUSEV.y;
        MOUSEV.pg = p;
        FUN_0002a288();
        FUN_000391c8(p);
        MOUSEV.pg = p ^ 1;
        FUN_0002ab20(x, y);
        MOUSEV.on = 1;
        DAT_0005a6ba = 0;
    } else {
        FUN_000391c8(p);
    }
    MOUSEV.pg = p;
}

/* ---- from build/var/mod/parts/p2a5b0.c */
extern void FUN_0002ab20(int x, int y); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* MATCH in round 47 (module 0x29c80 -oa) with the held item and its flag as one record (struct HELD DAT_00058600, .id / .f; include/records.h): the two scalars were -oa memory nodes whose presence ordered the 4-savings tie group (round 38's tietrace class A, t32 before t28); as members they are none. No other change. */
/* NEAR MISS Round 38 (module 0x29c80, real 10.0a): q is an int. 10.0a narrows `x ^ 1` to the narrowest register part (xor al,1 in the else branch, also for an int argument); in ESI, which has no byte part, that is the 16-bit xor si,1, used unextended because q is 32-bit: the original's mov esi,ebx before the call / xor si,1 / push esi / index without movsx come out exactly (24 -> 31 lines only by a 1-byte shift: same size 372). Left: the memmove destination address is formed in ESI in place (orig: mov eax,esi and the address in EAX); tietrace class A: forcing the 4-savings group with t32 before t28 gives 0 lines; tiewhat: insert a node of savings 0-1 at pre-sort 3 or 11, or 5-19 at 13/14/22; sibling spellings (DAT_00058600 != spr, 1 <= DAT_00059e37, 1 ^ pg: 7 combinations) neutral. */
/* Round 18 (module 0x29c80, 9 lines): FUN_0003a020 takes a byte page (the else branch pushes eax after xor al,1), while the if branch computes q with xor si,1 and indexes DAT_00059e3a with esi unextended. FUN_0003a020(short) / (unsigned char) with q short, unsigned short or int: 11-23 lines (worse). Round 27 (re-derived, 0 compiles): the original loads pg as a dword into ebx; FUN_000391c8 gets movzx bl (unsigned char parameter), FUN_0003e590 ebx (int), FUN_0003a020 a char-typed value pushed unextended (else: mov eax,ebx; xor al,1); in the if branch q = pg ^ 1 is formed by a 16-bit xor si,1 and used unextended both as the FUN_0003a020 argument and as the DAT_00059e3a index (mov eax,esi; shl eax,10). An index used without movsx/movzx after a 16-bit op is what 10.0a does for a value whose upper half it knows (copy of the dword pg): the candidates are q as a 16-bit view of a copy of pg (e.g. union or q = pg; ((short *)&q)[0] ^= 1), not tested for lack of budget. */
/* NEAR MISS 372/372 (-3s -ox -oe -oa -ot, module 0x29c80; the other differences in context are call targets shifted by the parked FUN_0002a288). 2026-11-10 (module round, task B4): first difference at 0x2a679: the original copies pg to esi (q) before FUN_0003e590(pg), xors si 16-bit after the call, pushes esi unextended and indexes the memmove destination through eax = esi; ours computes q after the call (mov eax,ebx; xor al,1; movsx esi,ax). Q1: FUN_0003e590 preserves esi in both. Q2: q is live from before the call in the original (assigned before it). Q3: n/a. Q4: n/a. Tried (3): int q + FUN_0003a020(short) + q = pg before the call, q ^= 1 after (38 lines); short q with the same statements (12, unchanged); short q + short prototype (17). */
/* NEAR MISS ~8 instr: same open problem as wip/f2a724.c. The original does q = pg in esi before FUN_0003e590(pg), then a 16-bit `xor si,1`, pushes esi unextended to FUN_0003a020, and indexes DAT_00059e3a with esi copied to eax (no extension). Findings: a short q fixes the spr*0x41 operand order; a FUN_0003a020(short) prototype pushes a short unextended; int q gives xor si,1 only with the short prototype. No combination tried gives all three */
/* FUN_0002a5b0 @ 0002a5b0: flip to page pg with the mouse cursor showing item spr (shape c); copies the palette page across */
#include "world.h"
#include "records.h"
void *memmove(void *, const void *, unsigned);
extern void FUN_000391c8(unsigned char), FUN_0003e590(int), FUN_0003a078(int, int, int, int, int, int, int), FUN_0003e5d4(void);
extern void *FUN_0003f29c(int, int);
extern short DAT_0005a6ba;
extern unsigned char DAT_00058603[], DAT_00059e3a[][0x400]; extern unsigned char DAT_00059e31[2];
extern void FUN_0003a020(int);
extern short DAT_000585fc[2];
void FUN_0002a5b0(int pg, short spr, unsigned char c)
{
    int mx, my; int q; void *img;
    if (CURSV.on && MOUSEV.on >= 1) {
        DAT_0005a6ba = 1;
        if (spr != CURSV.id) {
            CURSV.id = spr;
            CURSV.spr = spr;
            if (spr != -1) {
                CURSV.spr = *(short *)(((char *)B000755d8_aw) + spr * 0x41 + 0x2d);
                img = FUN_0003f29c(CURSV.spr, 1);
                memmove(DAT_00058603, img, 0x20a);
            }
        }
        CURSV.f = c;
        mx = MOUSEV.x;
        MOUSEV.on = 0;
        my = MOUSEV.y;
        MOUSEV.pg = pg;
        FUN_0002a288();
        FUN_000391c8(pg);
        FUN_0003e590(pg);
        q = pg ^ 1;
        FUN_0003a020(q);
        MOUSEV.pg = pg ^ 1;
        memmove(DAT_00059e3a[q], DAT_00059e3a[pg], 0x400);
        FUN_0002ab20(mx, my);
        FUN_0003e5d4();
        MOUSEV.on = 1;
        DAT_0005a6ba = 0;
        MOUSEV.pg = pg;
    } else {
        FUN_000391c8(pg);
        FUN_0003e590(pg);
        FUN_0003a020(pg ^ 1);
        MOUSEV.pg = pg ^ 1;
        FUN_0003e5d4();
    }
}

/* ---- from build/var/mod/parts/p2a724.c */
extern void FUN_0002ab20(int x, int y); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* MATCH (round 47, module 0x29c80 -oa): the cursor record (struct CURSOR DAT_000585fc: on, spr, id, f) and the mouse record (struct MOUSE DAT_00059e31: x, y, b, on, pg) as one symbol each (include/records.h). As eight scalars they were eight -oa memory nodes; the grid of round 47 (which of them are members) gives 0 lines for this function and for FUN_0002a5b0 only with all eight as members. No other change; the notes below describe the scalar forms. */
/* NEAR MISS (round 47) 10 -> 6 instruction lines, 416 -> 420/420 bytes in module 0x29c80: the held item and its flag as one record (struct HELD, as FUN_0002a5b0 which matches with it): spr is in esi at entry as the original and everything equals it except the memmove destination: the original copies q (mov eax,esi; shl eax,0xa; add eax,OFFSET; push eax), ours shifts esi in place. Named with the real trace: the shift temp t36 has EAX and ESI at moves-saved 2 only if the + OFFSET temp t40 was allocated before it (as t32 before t28 in FUN_0002a5b0); here t36 precedes t40 in the 4-savings tie group. Replay (tw.py): removing mx or my or one of the temps of the image block, or inserting one node of any savings at pre-sort 17..33 (the memory nodes and parameters) gives it. 22 compiles, none: six sibling spellings and their combination, the three final stores in the listing's order, q assigned in the argument, pg ^ 1 in the else branch (all the same 6); 0x585fc / 0x585fe as members of the held record (8-15), the mouse position / state 0x59e31..0x59e39 as one record (8-18). Most likely untested cause: one more global of this function is a scalar memory node in the original (or the held flag is not in the record while the id is), i.e. the exact extent of the 0x585fc.. and 0x59e31.. records. */
/* NEAR MISS Round 38 (module 0x29c80 with FUN_0002a5b0's int q, real 10.0a): the whole q / memmove / else tail now equals the original (int q: xor si,1, address through eax); the 86 lines (416/420 bytes) are only the top: spr in EAX/AX here, ESI in the original (FUN_0002a5b0's spr takes EDX in both), and the encodings that follow from it (cwde vs movsx eax,si, ax vs si stores: the 4 bytes). tietrace class C (no tie order: spr t3 savings 4); 7 sibling spellings from FUN_0002a5b0 (spr != DAT_00059e37 >= 1, declaration order) neutral. */
/* NEAR MISS (round 19): 9 lines in module 0x29c80 (-oa). First difference: spr is loaded into esi at entry in the original (ours eax, the DAT_00059e37 temp then takes esi instead of eax), and the original converts spr with `movsx eax,si` between the two stores DAT_00058600 = spr / DAT_000585fe = spr (the int copy conflicts with spr, so they get two registers); ours stores both and widens in place (cwde). Then the item-table address operand tie of recipe 42. Not explained: what keeps eax..ecx from spr in the original. Tried: DAT_000585fe = DAT_00058600 = spr (9), the DAT_000585fe store moved after the -1 test head (9). 3 real compiles. Round 27 (re-derived, 0 compiles): the original loads pg as a dword into ebx; FUN_000391c8 gets movzx bl (unsigned char parameter), FUN_0003e590 ebx (int), FUN_0003a020 a char-typed value pushed unextended (else: mov eax,ebx; xor al,1); in the if branch q = pg ^ 1 is formed by a 16-bit xor si,1 and used unextended both as the FUN_0003a020 argument and as the DAT_00059e3a index (mov eax,esi; shl eax,10). An index used without movsx/movzx after a 16-bit op is what 10.0a does for a value whose upper half it knows (copy of the dword pg): the candidates are q as a 16-bit view of a copy of pg (e.g. union or q = pg; ((short *)&q)[0] ^= 1), not tested for lack of budget. */
/* NEAR MISS 416/420 under the module's -oa (40 lines), 420/420 without (18 lines; module 0x29c80). 2026-11-10 (module round, task B4): same problem as FUN_0002a5b0 (q = pg ^ 1 kept in esi, the memmove destination formed in eax from a copy); not worked separately. Q1: no clobber. Q2: q is not live after the memmove in the original either, so the copy is not a longer range. Q3/Q4: n/a. Tried: none this round (shares FUN_0002a5b0's 3 experiments). */
/* NEAR MISS 1 byte: everything matches except the memmove destination: the original copies q (pg ^ 1, in esi) to eax before the shift, this version shifts esi in place. Needed: sprite pointer through a local, q an int variable (gives the 16-bit xor si,1 and the push esi). Tried: q unsigned, char-pointer address form */
/* 2026-11-10: with my = DAT_00059e31; mx = DAT_00059e33; FUN_0002ab20(my, mx) (names then swapped; this file) the mouse slots match and only the 1-byte memmove destination is left (shift in place vs mov eax,esi copy; classify SHAPE 8/18 because of the address shift). q types, pg types, no q (CSE of pg ^ 1), &x[q][0] and *(x + q) forms do not change it */
/* [2026-11-09: declaration order from an automatic sweep, 25 diff lines with -3s -ox -oe -ot -w0] */
/* FUN_0002a724 @ 0002a724: copy region (x, y, w, h) of page pg to the other page with the mouse cursor showing item spr (shape c) */
#include "world.h"
#include "records.h"
void *memmove(void *, const void *, unsigned);
extern void FUN_000391c8(unsigned char), FUN_0003e590(int), FUN_0003a078(int, int, int, int, int, int, int), FUN_0003e5d4(void);
extern void *FUN_0003f29c(int, int);
extern short DAT_0005a6ba;
extern unsigned char DAT_00058603[], DAT_00059e3a[][0x400]; extern unsigned char DAT_00059e31[2];
extern short DAT_000585fc[2];
void FUN_0002a724(int pg, short spr, unsigned char c, int x, int y, int w, int h)
{
    void *img; int mx; int my; int q;
    if (CURSV.on && 1 <= MOUSEV.on) {
        DAT_0005a6ba = 1;
        if (CURSV.id != spr) {
            CURSV.id = spr;
            CURSV.spr = spr;
            if (spr != -1) {
                CURSV.spr = *(short *)(((char *)B000755d8_aw) + spr * 0x41 + 0x2d);
                img = FUN_0003f29c(CURSV.spr, 1);
                memmove(DAT_00058603, img, 0x20a);
            }
        }
        CURSV.f = c;
        mx = MOUSEV.x;
        my = MOUSEV.y;
        MOUSEV.on = 0;
        MOUSEV.pg = pg;
        FUN_0002a288();
        FUN_000391c8(pg);
        FUN_0003e590(pg);
        q = pg ^ 1;
        FUN_0003a078(q, x, y, x, y, w, h);
        MOUSEV.pg = 1 ^ pg;
        memmove(DAT_00059e3a[q], DAT_00059e3a[pg], 0x400);
        FUN_0002ab20(mx, my);
        FUN_0003e5d4();
        MOUSEV.pg = pg;
        MOUSEV.on = 1;
        DAT_0005a6ba = 0;
    } else {
        FUN_000391c8(pg);
        FUN_0003e590(pg);
        FUN_0003a078(1 ^ pg, x, y, x, y, w, h);
        MOUSEV.pg = 1 ^ pg;
        FUN_0003e5d4();
    }
}

/* ---- from build/var/mod/parts/p2a8c8.c */
extern void FUN_0002ab20(int x, int y); /* module prototype */
extern void FUN_0002a288(void); /* module prototype */
/* FUN_0002a8c8 @ 0002a8c8: copy region (x, y, w, h) of page pg to the other page, keeping the mouse cursor intact when it overlaps */
#include "records.h"
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
void *memmove(void *, const void *, unsigned);
extern void FUN_0003a078(int, int, int, int, int, int, int);
extern short DAT_0005a6ba; extern unsigned char DAT_00059e3a[][0x400];
void FUN_0002a8c8(int pg, int x, int y, int w, int h)
{
    int cx, cy, old;
    if (CURSV.on && MOUSEV.on >= 1) {
        cx = MOUSEV.x;
        DAT_0005a6ba = 1;
        if (cx + 0x20 < x || cx > x + w || (cy = MOUSEV.y) + 0x10 < y || cy > y + h) {
            FUN_0003a078(pg ^ 1, x, y, x, y, w, h);
        } else {
            old = MOUSEV.pg;
            MOUSEV.on--;
            MOUSEV.pg = pg;
            FUN_0002a288();
            FUN_0003a078(pg ^ 1, x, y, x, y, w, h);
            memmove(DAT_00059e3a[pg ^ 1], DAT_00059e3a[pg], 0x400);
            FUN_0002ab20(cx, cy);
            MOUSEV.on++;
            MOUSEV.pg = old;
        }
        DAT_0005a6ba = 0;
    } else {
        FUN_0003a078(pg ^ 1, x, y, x, y, w, h);
    }
}

/* ---- from build/var/mod/parts/p2a9f8.c */
extern int FUN_0002a3b8(short *px, short *py, short *pb); /* module prototype */
/* FUN_0002a9f8 @ 0002a9f8: show the back page; with the mouse cursor active, copy the cursor save area to the new page */
#include "records.h"
#define FUN_0003a020 ((void (*)(unsigned char))FUN_0003a020)
#define FUN_0003e590 ((void (*)(unsigned char))FUN_0003e590)
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
void *memmove(void *, const void *, unsigned);
extern void FUN_0002aacc(void), FUN_0003e5d4(void);
extern short DAT_0005a6ba; extern unsigned char DAT_0005ef4e, DAT_00059e3a[][0x400];
void FUN_0002a9f8(void)
{
    int old;
    if (CURSV.on && MOUSEV.on >= 1) {
        DAT_0005a6ba = 1;
        old = MOUSEV.pg;
        FUN_0003e590(DAT_0005ef4e);
        FUN_0003a020(DAT_0005ef4e ^ 1);
        MOUSEV.pg = DAT_0005ef4e ^ 1;
        memmove(DAT_00059e3a[MOUSEV.pg], DAT_00059e3a[old], 0x400);
        FUN_0002aacc();
        FUN_0003e5d4();
        DAT_0005a6ba = 0;
        MOUSEV.on++;
        MOUSEV.pg = old;
    } else {
        FUN_0003e590(DAT_0005ef4e);
        FUN_0003a020(DAT_0005ef4e ^ 1);
        FUN_0003e5d4();
    }
}

extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_0002aacc(void), FUN_0003e5d4(void);
extern short DAT_0005a6ba; extern unsigned char DAT_0005ef4e, DAT_00059e3a[][0x400];

extern void FUN_0003932c(unsigned char *, int, int, int, int); 
/* FUN_0002aacc: hide the mouse cursor (restore the saved background) when the last show is undone */
void FUN_0002aacc(void)
{
    if (!CURSV.on) return;
    if (--MOUSEV.on) return;
    FUN_0003e590(MOUSEV.pg);
    FUN_0003932c(DAT_00059e3a[MOUSEV.pg], MOUSEV.x, MOUSEV.y, 0x20, 0x10);
    FUN_0003e5d4();
}

extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_0002aacc(void), FUN_0003e5d4(void);
extern short DAT_0005a6ba; extern unsigned char DAT_0005ef4e, DAT_00059e3a[][0x400];

/* FUN_0002ab20: the same at an explicit position */
void FUN_0002ab20(int x, int y)
{
    if (!CURSV.on) return;
    if (--MOUSEV.on) return;
    FUN_0003e590(MOUSEV.pg);
    FUN_0003932c(DAT_00059e3a[MOUSEV.pg], x, y, 0x20, 0x10);
    FUN_0003e5d4();
}

extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_0002aacc(void), FUN_0003e5d4(void);
extern short DAT_0005a6ba; extern unsigned char DAT_0005ef4e, DAT_00059e3a[][0x400];

extern void FUN_00039804(int, int, int, unsigned char *); extern short DAT_0005a6bc; extern unsigned char DAT_0005880d[], DAT_00058603[];
 extern void FUN_000392bc(void *, int, int, int, int); extern int FUN_0003ae30(int, int);
extern short DAT_0005a6c0;
/* FUN_0002a288 @ 0002a288: show the mouse cursor (the first show saves the background and draws the cursor in the shape for
   the spot under it). Defined here, after FUN_0002ab20, although its entry is at 0x2a288: FUN_0002a220 ends in a call of it,
   which 10.0a turns into a jump (call + ret), and the optimiser's StraightenCode hauls the code at the jump target up behind
   that jump as far as the first unconditional transfer (the `jmp` of the r == 2 case). The rest of the body stays here,
   at 0x2ab6c, where the source defines the function (round 49). */
void FUN_0002a288(void)
{
    int r;
    if (!CURSV.on) return;
    if (!MOUSEV.on) {
        FUN_0003e590(MOUSEV.pg);
        FUN_0002a3b8(&MOUSEV.x, &MOUSEV.y, &MOUSEV.b);
        FUN_000392bc(DAT_00059e3a[MOUSEV.pg], MOUSEV.x, MOUSEV.y, 0x20, 0x10);
        r = FUN_0003ae30(MOUSEV.x, MOUSEV.y);
        if (DAT_0005a6c0) {
            if (r == 2) FUN_00039804(1, MOUSEV.x, MOUSEV.y, DAT_0005880d);
            else if (r == 1) FUN_00039804(2, MOUSEV.x, MOUSEV.y, DAT_0005880d);
            else if (CURSV.spr != -1) {
                FUN_00039804(0, MOUSEV.x, MOUSEV.y, DAT_0005880d);
                FUN_00039804(0, MOUSEV.x, MOUSEV.y, DAT_00058603);
            } else if (DAT_0005a6bc >= 3) FUN_00039804(DAT_0005a6bc, MOUSEV.x, MOUSEV.y, DAT_0005880d);
            else FUN_00039804(0, MOUSEV.x, MOUSEV.y, DAT_0005880d);
        }
        FUN_0003e5d4();
    }
    MOUSEV.on++;
}

#undef FUN_0003a020
#undef FUN_0003e590
/* ---- from build/var/mod/parts/p2ac0c.c */
/* FUN_0002ac0c @ 0002ac0c: set a flag word */
extern short DAT_0005a6bc;
void FUN_0002ac0c(void) { DAT_0005a6bc = 1; }

/* ---- from build/var/mod/parts/p2ac38.c */
/* FUN_0002ac38 @ 0002ac38: click at (x, y) on the movement panel (big compass) or on the map's scroll arrows: set the move direction, scroll the map */
struct R { short x0, y0, x1, y1, dx, dy; };
extern struct R DAT_0005a6dc[7], DAT_0005a730[8];
extern short DAT_0005a6bc, DAT_0005a6be, B000758fc_kL, B000758fe_j6;
extern void FUN_0002f7f8(int, int);
void FUN_0002ac38(int x, int y)
{
    int i;
    if (!DAT_0005a6bc && x >= 0x124 && x <= 0x187 && y >= 0x7e && y <= 0xc3) {
        DAT_0005a6be = 1;
        for (i = 0; i < 7; i++) {
            if (x >= DAT_0005a6dc[i].x0 && x <= DAT_0005a6dc[i].x1 && y >= DAT_0005a6dc[i].y0 && y <= DAT_0005a6dc[i].y1) {
                B000758fc_kL = DAT_0005a6dc[i].dx;
                B000758fe_j6 = DAT_0005a6dc[i].dy;
                return;
            }
        }
    } else if (DAT_0005a6bc && x >= 4 && x < 0x104 && y >= 0x11 && y < 0x120) {
        DAT_0005a6bc = 1;
        for (i = 0; i < 8; i++) {
            if (x >= DAT_0005a730[i].x0 && x <= DAT_0005a730[i].x1 && y >= DAT_0005a730[i].y0 && y <= DAT_0005a730[i].y1) {
                B000758fc_kL = DAT_0005a730[i].dx;
                B000758fe_j6 = DAT_0005a730[i].dy;
                switch (i) {
                case 0: FUN_0002f7f8(0, 0x56 - (x - 4)); FUN_0002f7f8(1, 0x56 - (y - 0x20)); break;
                case 1: FUN_0002f7f8(0, 0x56 - (x - 4)); break;
                case 2: FUN_0002f7f8(0, 0x56 - (x - 4)); FUN_0002f7f8(1, 0x56 - (0x120 - y)); break;
                case 3: FUN_0002f7f8(1, 0x56 - (y - 0x20)); break;
                case 4: FUN_0002f7f8(1, 0x56 - (0x120 - y)); break;
                case 5: FUN_0002f7f8(2, 0x56 - y + 0x20); break;
                case 6: FUN_0002f7f8(0, 0x56 - (0x104 - x)); break;
                case 7: FUN_0002f7f8(2, 0x56 - (0x120 - y)); break;
                }
                DAT_0005a6bc = i + 3;
                return;
            }
        }
    }
}

/* ---- from build/var/mod/parts/p2ae30.c */
extern void FUN_0002ac38(int x, int y); /* module prototype */
/* FUN_0002ae30 @ 0002ae30: poll the mouse: buttons into DAT_00059e35; in capture mode read the motion counters (x clamped to +-160, right button drags it), otherwise act on the left button */
#include "records.h"
#define FUN_00043cb0 ((short *(*)(void))FUN_00043cb0)
extern short DAT_000585fc[2];
extern unsigned char DAT_00059e31[2];
extern void FUN_0003f868(void), FUN_0002f820(void); 
extern short DAT_0005cf48, DAT_0005a6be, DAT_0005a6bc;
extern int DAT_0005c6e8, DAT_0005c6ec, DAT_0005c6f0, DAT_0005c04c;
short mickeys(void);
#pragma aux mickeys = 0xb8 0x0b 0x00 0x00 0x00 0xcd 0x33 value [dx] modify [eax];
short mickeys_y(void);
#pragma aux mickeys_y = value [cx];
void FUN_0002ae30(void)
{
    if (CURSV.on) {
        FUN_0003f868();
        if (CURSV.on) MOUSEV.b = *FUN_00043cb0();
        if (!DAT_0005cf48) {
            DAT_0005c6e8 = mickeys();
            DAT_0005c6ec = mickeys_y();
            DAT_0005c6f0 = 0;
            if (MOUSEV.b & 2) {
                if (!DAT_0005c04c) DAT_0005c04c = DAT_0005c6e8;
                DAT_0005c04c -= 8;
                DAT_0005c6e8 = DAT_0005c04c;
            } else DAT_0005c04c = 0;
            if (DAT_0005c6e8 < -0xa0) DAT_0005c6e8 = -0xa0;
            if (DAT_0005c6e8 > 0xa0) DAT_0005c6e8 = 0xa0;
            return;
        }
        DAT_0005c6ec = 0;
        DAT_0005c6e8 = 0;
        DAT_0005c6f0 = 0;
        if (MOUSEV.b) {
            if (MOUSEV.b & 1) FUN_0002ac38(MOUSEV.x, MOUSEV.y);
        } else {
            DAT_0005a6be = 0;
            if (DAT_0005a6bc) {
                DAT_0005a6bc = 0;
                FUN_0002f820();
            }
        }
        return;
    }
    DAT_0005c6ec = 0;
    DAT_0005c6e8 = 0;
    DAT_0005c6f0 = 0;
}

#undef FUN_00043cb0

/* ---- module data _DATA 000585fc-0005a7f8 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
short DAT_000585fc[2] = { 0 };
short DAT_00058600 = 0;   /* type from another module's declaration */
unsigned char DAT_00058602 = 0;   /* type from another module's declaration */
unsigned char DAT_00058603[522] = { 0 };
unsigned char DAT_0005880d[5652] = { 0 };
unsigned char DAT_00059e21[2] = { 0 };
unsigned char DAT_00059e23[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_00059e25[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_00059e27[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_00059e29[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_00059e31[2] = { 0 };
unsigned char DAT_00059e33[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_00059e35[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_00059e37[2] = { 0, 0 };   /* no name in the sources */
unsigned char DAT_00059e39 = 0;   /* type from another module's declaration */
unsigned char DAT_00059e3a[2][0x400] = { 0 };
unsigned char DAT_0005a63a[122] = { 0 };   /* only other modules name it: bytes */
short DAT_0005a6b4 = 0;
short DAT_0005a6b6 = 0;
short DAT_0005a6b8 = 0;
short DAT_0005a6ba = 0;
short DAT_0005a6bc = 0;
short DAT_0005a6be = 0;
short DAT_0005a6c0 = 1;
short DAT_0005a6c2 = 0;
short DAT_0005a6c4 = 0;
short DAT_0005a6c6 = 0;
short DAT_0005a6c8 = 0;
short DAT_0005a6ca = 0;
int DAT_0005a6cc = 0;
int DAT_0005a6d0 = 0;
int DAT_0005a6d4 = 0;
int DAT_0005a6d8 = 0;
struct R DAT_0005a6dc[7] = {
    0x124, 0x95, 0x144, 0xab, 3, -1,
    0x135, 0x7e, 0x155, 0x94, 1, -1,
    0x135, 0xac, 0x155, 0xc2, 1, 1,
    0x145, 0x95, 0x165, 0xab, 0, -1,
    0x156, 0x7e, 0x175, 0x94, 2, -1,
    0x156, 0xac, 0x175, 0xc2, 2, 1,
    0x166, 0x95, 0x185, 0xab, 0, 1
};
struct R DAT_0005a730[8] = {
    4, 0x11, 0x58, 0x74, 4, -1,
    4, 0x75, 0x58, 0xca, 0, -1,
    4, 0xcb, 0x58, 0x11f, 4, 1,
    0x58, 0x11, 0xae, 0x74, 1, -1,
    0x58, 0xcb, 0xae, 0x11f, 1, 1,
    0xaf, 0x11, 0x103, 0x74, 2, -1,
    0xaf, 0x75, 0x103, 0xca, 0, 1,
    0xaf, 0xcb, 0x103, 0x11f, 2, 1
};
unsigned DAT_0005a790 = 0;
int DAT_0005a794 = 0;
int DAT_0005a798 = 0;
unsigned char DAT_0005a79c = 0;
unsigned char DAT_0005a79d = 0;   /* type from another module's declaration */
struct SREGS DAT_0005a79e = { 0 };
unsigned char DAT_0005a7aa[2] = { 1, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
union REGS DAT_0005a7ac = { 0 };
union REGS DAT_0005a7c8 = { 0 };
int DAT_0005a7e4 = 0;
int DAT_0005a7e8 = 0;
unsigned char DAT_0005a7ec = 0;
unsigned char DAT_0005a7ed[3] = { 0, 0xca, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005a7f0 = 0;
int DAT_0005a7f4 = 0;
/* ---- end of module data _DATA */
