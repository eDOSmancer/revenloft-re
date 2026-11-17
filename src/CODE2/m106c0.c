/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
short B00062756_ff;
short B00062754_gp;
int B00062750_gl;
int B0006274c_dc;
int B00062748_f3;
int B00062744_fp;
int B00062740_gK;
/* BSS end */
/* Module: FUN_000106c0, FUN_00010700, FUN_00010794, FUN_000107e4, FUN_0001083c, FUN_00010934, FUN_000109b0,
   FUN_00010b6c, FUN_00010bfc, FUN_00010cb0, FUN_000110c4, FUN_000111a8, FUN_00011228, FUN_0001139c,
   FUN_00011558, FUN_00011834, FUN_00011c08, FUN_00011c28, FUN_00011c50, FUN_00011ca8, FUN_00011ce4,
   FUN_00011f6c, FUN_0001207c, FUN_000121d8, FUN_00012354, FUN_000123b8, FUN_00012474, FUN_000126e8,
   FUN_00012a34, FUN_00012ae8, FUN_00012db0, FUN_000134b0, FUN_00013634 */
/* ---- from build/var/mod/parts/p106c0.c */
/* FUN_000106c0 @ 000106c0: centre the automap scroll origin on the party (24 cells up/left), clamped at -40; -oa caches the column B00062744_fp in edx, the row is written through (it loses the candidate tie) */
/* Round 60: the row is a scalar (world.h); with the party cells read as the high halves of the 16.16 positions 0x755d0 / 0x755d4
   (the cast view FUN_0001083c uses for y) the two party nodes are one each and the column wins the row / column tie at savings 4 as
   in the original; with the short scalars 0x755d2 / 0x755d6 the row wins (11 lines). */
#include "world.h"
extern unsigned short B000755d0_ao, B000755d4_ak;
void FUN_000106c0(void)
{
    B00062744_fp = ((short *)&B000755d0_ao)[1] - 0x18;
    B00062740_gK = ((short *)&B000755d4_ak)[1] - 0x18;
    if (B00062744_fp < -0x28) B00062744_fp = -0x28;
    if (B00062740_gK < -0x28) B00062740_gK = -0x28;
}

/* ---- from build/var/mod/parts/p10700.c */
/* Round 57 (module 0x106c0, -3s -ox -oe -oa -ot, 4 compiles + trace): real gap -15 -> 0, 29 -> 7 lines. The gap was the return temp
   coalesced with k: with one `return -1` after the if/else every exit fed one return temp (2 moves from k, so it took k's EDX and the
   exit copied it); `return -1;` written at the end of the first branch as well gives each branch its own exit, the return value goes
   straight to EAX (`mov eax,edx` at each `return k`, the second loop's own epilogue copy) as in the original. Structure now equal; left:
   x / y in EDI / ESI (orig ESI / EDI), a pass-1 tie at savings 118 (tw.py: 40 single edits, among them removing the DAT_00055fcb memory
   node). Recorded, not kept: DAT_00055fcb declared volatile (as f12db0 / f13634 declare it) gives MATCH with no other function of the
   module lost; as a non-volatile record with 0x55fca it matches too but f12db0 / f13634 then fail. */
/* Round 41 (3 compiles): the 14 bytes are the return value: the original moves k to eax at each `return k` (the second with its own epilogue copy), ours keeps the return temp in edx with one move at the exit. Separate counters per loop and a named entry pointer compile identically. Note: both write DAT_00056048 back from ebp at the exits (-oa). */
/* NEAR MISS (round 40: both loops count a local k = i (module 0x106c0, -3s -ox -oe -oa -ot): block layout now the original's (je to the else loop, jmp to the first loop's test, the else preheader mov ebx,eax ahead of its body), k in edx, k*0x16 in eax; 61 -> 46 masked lines, 132/146 unchanged. Left, both allocation: (1) x/y in edi/esi, the original esi/edi (tie t3(y), t1(x) at savings 118: x first gives 37 lines; old-style definition, operand order of the compares, register k: no change); (2) the return temp: ours coalesces it with k in edx (mov edx,-1; shared mov eax,edx - the 14 missing bytes), the original has it in eax (mov eax,edx in each found block, the second with the duplicated epilogue, mov eax,-1 at the end); r / break forms put r in memory (148-152), k = -1; return k is the same code as return -1. tietrace class C (no forced order of the four tie groups).) */
/* NEAR MISS (round 23, module 0x106c0 -oa, 37 worklist lines) a. first difference: block layout - ours places the else loop first (jne to the first loop), the loop tests are N > i (cmp N,i; jg) where the original has i < N (cmp i,N; jl), i in eax (orig edx); decision: the operand order of the loop conditions (recipe 61) and the layout of the two found-returns. c. i < N in both loops: 37 -> 31 lines (1 real); the found tests as != ... continue: same code. Left: the else loop placed first and the shared found-return tail. FUN_00010700 near miss (127-129/146, -oa): the original gives the second loop its own epilogue and does not thread the entry jump of the first loop. 2026-11-08: one counter k = i for both loops gives the shared i*0x16 and the frame (131/146, -oa); left: the compiler threads both found-returns into one mov eax,edx tail, the original jumps from the first loop to the store/epilogue and gives the second loop its own. Mixed counters, r/break forms tried */
/* FUN_00010700 @ 00010700: find the door/entry at (x, y) starting from index i (-oa module: the table pointer is cached in EBP) */
#include "world.h"
extern volatile unsigned char DAT_00055fcb; extern short DAT_0005604c, B0007223a_et, B0007223e_dx; extern char *DAT_00056048;
#define DR_X(i) (*(short *)((char *)&B0007223e_dx + (i) * 0x16))
#define DR_Y(i) (*(short *)((char *)&B0007223a_et + (i) * 0x16))
int FUN_00010700(int x, int y, int i)
{
    int k;
    if (DAT_00055fcb) {
        for (k = i; k < B00075618_b1.ndoor; k++)
            if (DR_X(k) == x && DR_Y(k) == y) return k;
        return -1;
    } else {
        for (k = i; k < DAT_0005604c; k++)
            if (*(short *)(DAT_00056048 + k * 0x16 + 6) == x && *(short *)(DAT_00056048 + k * 0x16 + 2) == y) return k;
    }
    return -1;
}

#undef DR_X
#undef DR_Y
/* ---- from build/var/mod/parts/p10794.c */
/* FUN_00010794 @ 00010794: index of the first floor object at (x, y) from object i on, or -1 (a separate loop counter k = i, not i itself) (the count is a member of struct LCNT, recipe 27: not cached under the module's -oa) */
 
#include "world.h"
extern unsigned char B00067618_e7[];
#define B0006761a_hN (*(short *)((char *)&B00067618_e7 + 2)) /* STANDIN: view, B00067618_e7 + 0x2 */
#define B0006761c_g8 (*(unsigned char (*)[])((char *)&B00067618_e7 + 4)) /* STANDIN: view, B00067618_e7 + 0x4 */

#define B0006761e_g2 (*(short *)((char *)&B0006761c_g8 + 2)) /* STANDIN: view, B0006761c_g8 + 0x2 */
extern volatile unsigned char DAT_00055fcb; 
#define OBJ_Y(i) (*(short *)((char *)&B0006761a_hN + (i) * 0x16))
#define OBJ_X(i) (*(short *)((char *)&B0006761e_g2 + (i) * 0x16))
int FUN_00010794(int x, int y, int i)
{
    int k;
    if (DAT_00055fcb) {
        for (k = i; k < B00075618_b1.n4; k++)
            if (OBJ_X(k) == x && OBJ_Y(k) == y) return k;
    }
    return -1;
}

#undef OBJ_Y
#undef OBJ_X
/* ---- from build/var/mod/parts/p107e4.c */
/* FUN_000107e4 @ 000107e4: index of the first door of kind 0x54 at (x, y) from door i on, or -1 (separate loop counter k = i) (the count is a member of struct LCNT, recipe 27: not cached under the module's -oa) */
 
#include "world.h"
extern short B0007223a_et, B0007223e_dx; extern unsigned short B00072246_dJ;
#define DR_KIND(i) (*(unsigned short *)((char *)&B00072246_dJ + (i) * 0x16))
#define DR_X(i)    (*(short *)((char *)&B0007223e_dx + (i) * 0x16))
#define DR_Y(i)    (*(short *)((char *)&B0007223a_et + (i) * 0x16))
int FUN_000107e4(int x, int y, int i)
{
    int k;
    for (k = i; k < B00075618_b1.ndoor; k++)
        if (DR_KIND(k) == 0x54 && DR_X(k) == x && DR_Y(k) == y) return k;
    return -1;
}

#undef DR_KIND
#undef DR_X
#undef DR_Y
/* ---- from build/var/mod/parts/p1083c.c */
/* MATCH (round 22): alone and in module 0x106c0. The party y in the second distance test is the cast view ((short *)&B000755d4_ak)[1] of the int (more nodes, so it changes the conflict list the way the original's declaration did), the party x stays the short scalar B000755d2_ai - the same split as FUN_00019368 (MODULES.md contradiction 1). 1 real compile. Round 21 note: lost with the shared level header (nent as a member); best was 18 lines. */
/* FUN_0001083c matches in module 0x106c0 (round 15): `int ok = 0;` - the initialiser (a dead store, removed) is a statement
   of its own ahead of the loop, so the parameter loads stay in the entry block in their own order (y, then i) and the
   induction multiply i * 0x16 is scheduled in the next block; without it all three share one block and the bottom-up
   scheduler puts the y load next to the imul. Found with the instrument, confirmed by 10.0a. */
/* NEAR MISS 2 instr with -oa (flags.csv): only the parameter load order (orig ebp=y before edi=i). Tried: loop copy k, while, early return, break, no ok, compare operand order; a local copy of i (any declaration order) fixes the load order but then x is cached in ebp instead of y, compare operand orders do not change that */
/* FUN_0001083c near miss (242-246/245): the parameters y and i are assigned the other callee-saved registers (original y=EBP, i=EDI) and the second abs() loads the global before the entity field */
/* FUN_0001083c @ 0001083c: find a visible, reachable map entity at (x, y) starting from index i */
#include "world.h"
int abs(int);
#pragma intrinsic(abs)
extern int FUN_0003acdc(int);
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
#define B00064d8c_bX (*(unsigned short *)((char *)&B00064d80_ay + 12)) /* STANDIN: view, B00064d80_ay + 0xc */
#define B00064d8b_a7 (*(int *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
extern unsigned short B00064d80_ay;
#define B00064d82_aG (*(short *)((char *)&B00064d80_ay + 2)) /* STANDIN: view, B00064d80_ay + 0x2 */
#define B00064d86_aC (*(short *)((char *)&B00064d80_ay + 6)) /* STANDIN: view, B00064d80_ay + 0x6 */
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
extern short DAT_0005f03e, DAT_0005f03c; extern unsigned short B000755d4_ak;  extern unsigned short B000698e0_b7; extern char *B00072230_c4;
#define ENT_Y(i)  (*(short *)((char *)&B00064d82_aG + (i) * 0x16))
#define ENT_X(i)  (*(short *)((char *)&B00064d86_aC + (i) * 0x16))
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_CELL(i) (*(unsigned short *)((char *)&B00064d8c_bX + (i) * 0x16))
#define CELLF(c) (*(int *)((char *)&B000698e0_b7 + (c) * 2))
int FUN_0001083c(int x, int y, int i)
{
    int ok = 0;
    { extern int B000755e0_bo; int d; d = B000755e0_bo; } /* STANDIN: dead reads of scalars this function does not use - zero-savings -oa memory nodes in the pass-1 conflict list, in place of the nodes the party cell words 0x755d2 / 0x755d6 had as globals of their own (they are views of the position ints) */
    for (; i < B00075618_b1.nent; i++) {
        ok = 0;
        if (!(ENT_FL(i) & 2)) {
            if (FUN_0003acdc(ENT_ID(i)) && ENT_X(i) == x && ENT_Y(i) == y) {
                if (DAT_0005f03e) ok = 1;
                else if (DAT_0005f03c) {
                    if (*(int *)(B00072230_c4 + ENT_ID(i) * 0x45 + 0x3a) & 0x20) ok = 1;
                } else {
                    if ((CELLF(ENT_CELL(i)) & 0x40) && abs(ENT_X(i) - B000755d2_ai) <= 10 && abs(ENT_Y(i) - ((short *)&B000755d4_ak)[1]) <= 10) ok = 1;
                }
            }
            if (ok) return i;
        }
    }
    return -1;
}

#undef ENT_Y
#undef ENT_X
#undef ENT_FL
#undef ENT_ID
#undef ENT_CELL
#undef CELLF
/* ---- from build/var/mod/parts/p10934.c */
/* FUN_00010934 @ 00010934: find a visible map entity at (x, y) starting from index i (the count is a member of struct LCNT, recipe 27: not cached under the module's -oa) */
 
#include "world.h"
extern int FUN_0003ad18(int), FUN_0003ade0(int);
  
#define ENT_Y(k)  (*(short *)((char *)&B00064d82_aG + (k) * 0x16))
#define ENT_X(k)  (*(short *)((char *)&B00064d86_aC + (k) * 0x16))
#define ENT_FL(k) (*(int *)((char *)&B00064d8b_a7 + (k) * 0x16))
#define ENT_ID(k) (*(unsigned short *)((char *)&B00064d8e_a6 + (k) * 0x16))
int FUN_00010934(int x, int y, int i)
{
    int k;
    for (k = i; k < B00075618_b1.nent; k++) {
        if (!(ENT_FL(k) & 2)) {
            if (FUN_0003ad18(ENT_ID(k)) || FUN_0003ade0(ENT_ID(k))) {
                if (ENT_X(k) == x && ENT_Y(k) == y) return k;
            }
        }
    }
    return -1;
}

#undef ENT_Y
#undef ENT_X
#undef ENT_FL
#undef ENT_ID
/* ---- from build/var/mod/parts/p109b0.c */
/* FUN_000109b0 @ 000109b0: automap tile picker: from the four neighbours of map cell p (x,y) choose the wall/door tile to draw */
#include "world.h"
extern unsigned char DAT_00051760[];  extern unsigned DAT_00055ff0[];
unsigned FUN_000109b0(int p, int x, int y)
{
    unsigned m, n; int c;
    m = 0;
    n = 0;
    if (x != 0) {
        if (DAT_00051760[p - 1] < 0x20) m = 1;
        if (DAT_00051760[p - 1] == '/' || DAT_00051760[p - 1] == '.') n++;
    }
    if (x < B00062756_ff - 1) {
        if (DAT_00051760[p + 1] < 0x20) m += 8;
        if (DAT_00051760[p + 1] == '/' || DAT_00051760[p + 1] == '.') n += 8;
    }
    if (y != 0) {
        if (DAT_00051760[p - B00062756_ff] < 0x20) m += 2;
        if (DAT_00051760[p - B00062756_ff] == '/' || DAT_00051760[p - B00062756_ff] == '.') n += 2;
    }
    if (y < B00062754_gp - 1) {
        if (DAT_00051760[p + B00062756_ff] < 0x20) m += 4;
        if (DAT_00051760[p + B00062756_ff] == '/' || DAT_00051760[p + B00062756_ff] == '.') n += 4;
    }
    c = DAT_00051760[p];
    if (c == 1) return DAT_00055ff0[m];
    if (c == 2) {
        if (m == 6) m = 0x29;
        if (m != 9) return m;
        return 0x2b;
    }
    if (c == 3) {
        if (n == 1) return 0x21;
        if (n == 2) return 0x23;
        if (n == 4) return 0x22;
        if (n == 8) return 0x20;
        if (n & 9) return 0x20;
        if (n & 6) return 0x22;
        return m;
    }
    if (c == 4) {
        if (m == 6) m = 0x28;
        if (m != 9) return m;
        return 0x2a;
    }
    if (c != 5) return m;
    if ((n & 6) == 6) return 0x33;
    if ((n & 9) == 9) return 0x33;
    return DAT_00055ff0[m];
}

/* ---- from build/var/mod/parts/p10b6c.c */
extern unsigned FUN_000109b0(int p, int x, int y); /* module prototype */
/* Round 54: MATCH in module 0x106c0 (-oa): the product W * y is first kept in t (`t = B00062756_ff * y; i = x + t;`), so x is loaded into the sum's own register (mov ebx,[x] / add ebx,eax); with `i = W * y; i += x;` the rest of the function was right already (4 lines), with the expression form the product took the sum's register and w / the two height bytes moved to other registers. Earlier notes (rounds 22 and before) described that cascade. */
/* FUN_00010b6c @ 00010b6c: draw automap cell (x, y) at screen (sx, sy) with the colours of its wall type */
#include "world.h"
#define M000698e0_b7 ((unsigned short *)&B000698e0_b7)
 extern void FUN_0003975c(int, int, int, int, int);
extern unsigned char DAT_00051760[], DAT_0005764d, DAT_00057651;
  extern int B000758dc_cl;
void FUN_00010b6c(int x, int y, int sx, int sy)
{
    int i, t; unsigned short w;
    t = B00062756_ff * y;
    i = x + t;
    t = DAT_00051760[i];
    if (t == 0xff) return;
    if (t < 0x20) t = FUN_000109b0(i, x, y);
    w = M000698e0_b7[i] & 0x3f;
    DAT_0005764d = B00075618_b1.u[w * 2];
    DAT_00057651 = (B00075618_b1.u + 1)[w * 2];
    FUN_0003975c(t, sx, sy, B000758dc_cl + 0x34, 0);
    DAT_0005764d = 0xb1;
    DAT_00057651 = 0xb5;
}

#undef M000698e0_b7
/* ---- from build/var/mod/parts/p10bfc.c */
/* FUN_00010bfc @ 00010bfc: draw the facing-direction marker on the automap (16.16 fixed point kept in a
   union; the zero stores precede the high-word stores in the original order) */
/* FUN_00010bfc @ 00010bfc: draw the facing-direction marker on the automap */
union FIX { int v; struct { short lo, hi; } h; };
extern void FUN_0003975c(int, int, int, int, int), FUN_0003df2c(int *, int *, int, int), FUN_00039cec(int, int, int, int, int);
extern int B000758dc_cl, DAT_0005c658;
void FUN_00010bfc(int x, int y)
{
    union FIX py, px; int dx, dy, k;
    FUN_0003975c(0x34, x - 2, y, B000758dc_cl + 0x34, 0);
    FUN_0003df2c(&dx, &dy, 0x10000, DAT_0005c658);
    py.h.lo = 0; px.h.hi = x;
    px.h.lo = 0; py.h.hi = y;
    for (k = 0; k < 8; k++) { px.v += dx; py.v += dy; }
    if (px.h.hi >= 0 && py.h.hi >= 0 && px.h.hi <= 0x18f) FUN_00039cec(x, y, px.h.hi, py.h.hi, 0xff);
}

/* ---- from build/var/mod/parts/p10cb0.c */
extern int FUN_00010700(int x, int y, int i); /* module prototype */
extern int FUN_00010794(int x, int y, int i); /* module prototype */
extern int FUN_000107e4(int x, int y, int i); /* module prototype */
extern int FUN_0001083c(int x, int y, int i); /* module prototype */
extern int FUN_00010934(int x, int y, int i); /* module prototype */
extern void FUN_00010bfc(int x, int y); /* module prototype */
/* FUN_00010cb0 (module 0x106c0, -3s -ox -oe -oa -ot -j -w0): MATCH with stand-ins (round 63 lane AG): the k loop written as a guarded do-while with the hoisted px - 1 as a block-scoped local qk; see the STANDIN comments */
#include "world.h"
extern void FUN_0003975c(int, int, int, int, int);

extern volatile unsigned char DAT_00055fcb;
extern unsigned char DAT_00051760[];
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */


extern char *DAT_00056048;
#define B00064d84_aE (*(unsigned short *)((char *)&B00064d80_ay + 4)) /* STANDIN: view, B00064d80_ay + 0x4 */
extern unsigned short B00072238_dL, B0007223c_dz, B00072246_dJ, B00064d80_ay;
#define IT(o, i) (*(unsigned short *)((char *)&o + (i) * 0x16))
#define PT(o, i) (*(unsigned short *)(DAT_00056048 + (i) * 0x16 + (o)))
void FUN_00010cb0(int x, int y, int px, int py)
{
    int i, j, k, m, n, s1, s2;
    { extern int B000755e0_bo, B000755e4_bk, B000755e8_ag, B000755ec_aH; int d; d = B000755e0_bo; d = B000755e4_bk; d = B000755e8_ag; d = B000755ec_aH; } /* STANDIN: dead reads of scalars this function does not use - zero-savings -oa memory nodes in the pass-1 conflict list, in place of the nodes the party cell words 0x755d2 / 0x755d6 had as globals of their own (they are views of the position ints) */
    if (DAT_00051760[x + B00062756_ff * y] != 0xff) {
        for (i = FUN_00010700(x, y, 0); i != -1; i = FUN_00010700(x, y, i + 1)) {
            if (DAT_00055fcb) {
                if (IT(B00072246_dJ, i) >= 0x3c && IT(B00072246_dJ, i) <= 0x43) s1 = 0x35;
                else if (IT(B00072246_dJ, i) == 0xad) s1 = 0x31;
                else s1 = 0x38;
                FUN_0003975c(s1, px - 1 + IT(B0007223c_dz, i) / 0x2000, IT(B00072238_dL, i) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0);
            } else {
                if (PT(0xe, i) >= 0x3c && PT(0xe, i) <= 0x43) s2 = 0x35;
                else if (IT(B00072246_dJ, i) == 0xad) s2 = 0x31;
                else s2 = 0x38;
                FUN_0003975c(s2, px - 1 + PT(4, i) / 0x2000, PT(0, i) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0);
            }
        }
        if (DAT_00055fcb)
            for (j = FUN_00010794(x, y, 0); j != -1; j = FUN_00010794(x, y, j + 1))
                FUN_0003975c(0x32, px - 1 + IT(B00064d84_aE, j) / 0x2000, IT(B00064d80_ay, j) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0);
        if (DAT_00055fcb)
            if ((k = FUN_000107e4(x, y, 0)) != -1) { /* STANDIN: the k loop as guard + do-while (same as the for) so qk can sit in the preheader */
                int qk = px - 1; /* STANDIN: the hoisted px - 1 of the k loop as a block-scoped local: its id comes after the compiler's own temps, which moves it (and k) in the RoughSortTemps order - frame slots k/n (0x18/0x14) and the k/n-loop px - 1 temps (0xc/8) as in the original */
                do FUN_0003975c(0x30, qk + IT(B0007223c_dz, k) / 0x2000, IT(B00072238_dL, k) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0); /* STANDIN: qk for px - 1 */
                while ((k = FUN_000107e4(x, y, k + 1)) != -1); /* STANDIN: do-while half of the guarded loop */
            }
        for (m = FUN_00010934(x, y, 0); m != -1; m = FUN_00010934(x, y, m + 1))
            FUN_0003975c(0x37, px - 1 + IT(B00064d84_aE, m) / 0x2000, IT(B00064d80_ay, m) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0);
    }
    if (DAT_00055fcb)
        for (n = FUN_0001083c(x, y, 0); n != -1; n = FUN_0001083c(x, y, n + 1))
            FUN_0003975c(0x36, px - 1 + IT(B00064d84_aE, n) / 0x2000, IT(B00064d80_ay, n) / 0x3333 + py, (int)(*(char **)&B000758dc_cl + 0x34), 0);
    if (DAT_00055fcb && B000755d2_ai == x && B000755d6_ae == y)
        FUN_00010bfc(px + B000755d0_ao / 0x2000, B000755d4_ak / 0x3333 + py);
}

#undef IT
#undef PT
/* ---- from build/var/mod/parts/p110c4.c */
/* FUN_000110c4 @ 000110c4: draw the eight compass/frame pieces of the main view */
extern void FUN_0003975c(int, int, int, int, int); extern int B000758dc_cl;
void FUN_000110c4(void)
{
    FUN_0003975c(0, 0, 0x67, B000758dc_cl + 0x3c, 0);
    FUN_0003975c(1, 0x170, 0x67, B000758dc_cl + 0x3c, 0);
    FUN_0003975c(0, 0xa4, 0, B000758dc_cl + 0x3d, 0);
    FUN_0003975c(1, 0xa4, 0xe4, B000758dc_cl + 0x3d, 0);
    FUN_0003975c(0, 8, 0x75, B000758dc_cl + 0x36, 0);
    FUN_0003975c(1, 0x17a, 0x75, B000758dc_cl + 0x36, 0);
    FUN_0003975c(2, 0xc0, 4, B000758dc_cl + 0x36, 0);
    FUN_0003975c(3, 0xc0, 0xe9, B000758dc_cl + 0x36, 0);
}

/* ---- from build/var/mod/parts/p111a8.c */
/* FUN_000111a8 @ 000111a8 */
extern void FUN_000396c0(int, int, int, int); extern void FUN_000391b0(unsigned char); extern void FUN_0003978c(int, int, int, int, int);
extern int DAT_0005c050, B000758dc_cl;
void FUN_000111a8(void)
{
    int k;
    FUN_000396c0(6, 4, 0x189, 0xef);
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 3; k++) {
        FUN_0003978c(0, 0, k * 0x60, B000758dc_cl + 0x3e, 0);
        FUN_0003978c(0, 0xc8, k * 0x60, B000758dc_cl + 0x3e, 0);
    }
    FUN_000396c0(0, 0, 0x18f, 0x13f);
}

/* ---- from build/var/mod/parts/p11228.c */
/* FUN_00011228 @ 00011228: draw the scroll text records that fall inside the visible window (vertical text, CR = next column) */
struct REC { short x, y, n; };
extern char *FUN_0003f29c(int, int); extern void FUN_000396c0(int, int, int, int), FUN_00039804(int, int, int, int); extern int FUN_000402cc(char *, int, int);
extern char DAT_00055760[];
void FUN_00011228(int a, int b)
{
    int x0, b5, x1, y1, x, y, h, k, ys, xs; char *p, *font; unsigned char *c; struct REC *q;
    x0 = a * 8;
    b5 = b * 5;
    x1 = x0 + 0x184;
    y1 = b5 + 0xec;
    p = DAT_00055760;
    font = FUN_0003f29c(1, 0);
    FUN_000396c0(6, 4, 0x189, 0xef);
    while (1) {
        q = (struct REC *)p;
        p += 6;
        if (q->n == 0) break;
        x = q->x;
        xs = x;
        y = q->y;
        ys = y;
        h = FUN_000402cc(p, 1, q->n);
        if (x >= x0 && x <= x1 && ((b5 <= y && y1 >= y) || (y + h >= b5 && y + h <= y1))) {
            y -= b5;
            x -= x0;
            xs -= x0;
            ys -= b5;
            for (k = 0, c = (unsigned char *)p; k < q->n; c = c + 1, k++) {
                if (*c == '\r') {
                    xs += 12;
                    y = ys;
                    x = xs;
                } else {
                    FUN_00039804(*c, x, y, *(int *)font);
                    y += (unsigned char)font[*c + 4];
                }
            }
        }
        p += q->n;
    }
    FUN_000396c0(0, 0, 0x18f, 0x13f);
}

/* ---- from build/var/mod/parts/p1139c.c */
extern void FUN_00010b6c(int x, int y, int sx, int sy); /* module prototype */
extern void FUN_00010cb0(int x, int y, int px, int py); /* module prototype */
extern void FUN_000110c4(void); /* module prototype */
extern void FUN_000111a8(void); /* module prototype */
extern void FUN_00011228(int a, int b); /* module prototype */
/* FUN_0001139c @ 0001139c: redraw automap cells x0..x0+w-1, y0..y0+h-1 (floors, then walls), the coordinates, and with t the area title */
#include "world.h"
extern void FUN_0002c368(unsigned char *, int), FUN_00040508(int, int, int, unsigned char *, int);
 extern unsigned char DAT_00055fd9, DAT_00056058[]; extern int B0006274c_dc;
void FUN_0001139c(int x0, int y0, int w, int h, int t)
{
    int x, y;
    FUN_000111a8();
    for (x = x0; x < x0 + w; x++) {
        if (x < 0 || x >= B00062756_ff) continue;
        for (y = y0; y < y0 + h; y++) {
            if (y < 0 || y >= B00062754_gp) continue;
            FUN_00010b6c(x, y, (x - x0) * 8 + 6, (y - y0) * 5 + 4);
        }
    }
    for (x = x0; x < x0 + w; x++) {
        if (x < 0 || x >= B00062756_ff) continue;
        for (y = y0; y < y0 + h; y++) {
            if (y < 0 || y >= B00062754_gp) continue;
            FUN_00010cb0(x, y, (x - x0) * 8 + 6, (y - y0) * 5 + 4);
        }
    }
    if (DAT_00055fd9) FUN_00011228(x0, y0);
    if (t) {
        if (!DAT_00056058[0]) FUN_0002c368(DAT_00056058, B0006274c_dc + 0x26d);
        FUN_00040508(0x26, 4, 0xec, DAT_00056058, 1);
    }
    if (t) FUN_000110c4();
}

/* ---- from build/var/mod/parts/p11558.c */
/* module FUN_00011558 .. FUN_00011c50 (one -oa file: FUN_00011c50's exits jump to FUN_00011558's epilogue) */
/* FUN_00011558 @ 00011558: build the automap: classify every cell (party marker, unexplored, wall kinds, doors, open floor next to explored floor) into DAT_00051760 */
#include "world.h"
#define M000698e0_b7 ((struct T *)&B000698e0_b7)
#define FUN_0002c368 ((void (*)(char *, int))FUN_0002c368)
struct T { unsigned short wall : 6, b6 : 1, door : 1, b8 : 2, seen : 1, mark : 1, rest : 4; };


extern unsigned char DAT_00051760[];
extern int FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);
#define W B00062756_ff
#define H B00062754_gp
#define OPEN(c) (M000698e0_b7[c].seen && !M000698e0_b7[c].wall)
void FUN_00011558(void)
{
    int x, y, i, v;
    struct T *t;
    W = B00075618_b1.w;
    H = B00075618_b1.h;
    for (x = 0; x < W; x++)
        for (y = 0; y < H; y++) {
            i = W * y + x;
            v = 0xff;
            t = &M000698e0_b7[i];
            if (y == B000755d6_ae && x == B000755d2_ai) {
                if (B00075618_b1.solo == 0xff) v = 0x2f; else v = 0x2e;
            } else if (t->seen) {
                if (t->wall && B00075618_b1.t0[t->wall] != 0x93) {
                    if (t->mark) v = 5;
                    else if (t->door) {
                        if (!FUN_0002e8c8(x, y)) v = 3;
                        else if (FUN_0002e930(i) == 0x8000) v = 4;
                        else v = 2;
                    } else v = 1;
                } else {
                    if (B00075618_b1.solo == 0xff) v = 0x2f; else v = 0x2e;
                }
            } else if (t->wall) {
                if (B00075618_b1.t0[t->wall] == 0x93) {
                    if (B00075618_b1.solo == 0xff) v = 0x2f; else v = 0x2e;
                } else {
                    if (x > 0) {
                        if (y > 0 && OPEN(i - 1 - W)) v = 1;
                        if (OPEN(i - 1)) v = 1;
                        if (y < H - 1 && OPEN(W + i - 1)) v = 1;
                    }
                    if (y > 0 && OPEN(i - W)) v = 1;
                    if (y < H - 1 && OPEN(W + i)) v = 1;
                    if (x < W - 1) {
                        if (y > 0 && OPEN(i + 1 - W)) v = 1;
                        if (OPEN(i + 1)) v = 1;
                        if (y < H - 1 && OPEN(W + i + 1)) v = 1;
                    }
                }
            }
            DAT_00051760[i] = v;
        }
}



extern unsigned char DAT_00051760[];
extern int FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);

/* FUN_00011834 @ 00011834: draw the automap screen frame: backdrop, random floor strip, the 13 legend icons with their labels, the stone border and the fixed decorations */
int rand(void);
extern unsigned short FUN_000390d0(unsigned short); extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0004060c(int, int, char *, int);
extern int FUN_00040700(void);
extern unsigned char DAT_00055fcc[], DAT_00055fd9;
extern int B000758dc_cl, B00062748_f3, B00062750_gl;
extern char DAT_0005769c[];
void FUN_00011834(void)
{
    int y, x, k, n;
    FUN_000391b0(DAT_0005c050);
    for (y = 0; y != 0x120; y += 0x60) {
        FUN_0003975c(0, 0, y, B000758dc_cl + 0x3e, 0);
        FUN_0003975c(0, 0xc8, y, B000758dc_cl + 0x3e, 0);
    }
    B00062748_f3 = FUN_00040700();
    FUN_000390d0(B00062748_f3);
    for (y = 0xf0; y < 0x140; y += 8)
        for (x = 0; x < 0x190; x += 0x10) FUN_0003975c((unsigned)rand() * 4 >> 15, x, y, B000758dc_cl + 0x35, 0);
    for (k = 0, x = 0x1a, n = 0xe2; k < 0xd; k++, n++) {
        if (k == 9 && B00075618_b1.solo != 0xff) continue;
        FUN_0002c368(DAT_0005769c, n);
        FUN_0003975c(DAT_00055fcc[k], x, 0xf6, B000758dc_cl + 0x34, 0);
        FUN_0004060c(x, 0xff, DAT_0005769c, 1);
        x += 10;
    }
    B00062750_gl = FUN_00040700();
    FUN_000390d0(B00062750_gl);
    for (y = 8; y < 0x138; y += 8) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 9, 0, y, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 5, 0x180, y, B000758dc_cl + 0x35, 0);
    }
    for (x = 0x10; x < 0x180; x += 0x10) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xc, x, 0, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0x12, x, 0xf0, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xe, x, 0x138, B000758dc_cl + 0x35, 0);
    }
    FUN_0003975c(8, 0, 0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(0xb, 0, 0x138, B000758dc_cl + 0x35, 0);
    FUN_0003975c(4, 0x180, 0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(7, 0x180, 0x138, B000758dc_cl + 0x35, 0);
    FUN_0003975c(0x10, 0, 0xf0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(0x11, 0x180, 0xf0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(0, 0x11d, 0xf0, B000758dc_cl + 0x37, 0);
    FUN_0003975c(1, 0x11d, 0x130, B000758dc_cl + 0x37, 0);
    FUN_0003975c(DAT_00055fd9, 0x11a, 0x100, B000758dc_cl + 0x38, 0);
    for (k = 2, x = 0x136; k != 8; k += 2, x += 0x1c) FUN_0003975c(k, x, 0x100, B000758dc_cl + 0x38, 0);
    FUN_0003975c(0, 3, 0xf3, B000758dc_cl + 0x39, 0);
    FUN_0003975c(0, 0xae, 0x120, B000758dc_cl + 0x3a, 0);
    FUN_0003975c(0, 0xa8, 0xf8, B000758dc_cl + 0x3b, 0);
    FUN_0003975c(0, 0xf3, 0xf5, B000758dc_cl + 0x3f, 0);
}



extern unsigned char DAT_00051760[];
extern int FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);

/* FUN_00011c08, FUN_00011c28: walk a chain of variable-length records at DAT_00055760.
   TODO types: the (int) cast in FUN_00011c08 only lifts its node count from 20 to 21 (tools/nodecount.py), so -oe
   does not expand it into its callers in the module (the original calls it from FUN_00011ce4, FUN_000121d8,
   FUN_00012ae8 and FUN_000271fc); the original spelling with more than 20 nodes is not known. */
extern char DAT_00055760[];
char *FUN_00011c08(void)
{
    char *p = DAT_00055760;
    if (*(short *)(p + 4) != 0)
        do { p = p + 6 + (int)*(short *)(p + 4); } while (*(short *)(p + 4) != 0);
    return p;
}



extern unsigned char DAT_00051760[];
extern int FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);

int FUN_00011c28(void)
{
    char *p = DAT_00055760;
    if (*(short *)(p + 4) != 0)
        do { p = p + 6 + *(short *)(p + 4); } while (*(short *)(p + 4) != 0);
    return p - DAT_00055760;
}



extern unsigned char DAT_00051760[];
extern int FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);

extern int FUN_0004058c(void), FUN_00040594(void); extern void FUN_000404f4(int, int), FUN_00040354(int, int);
/* FUN_00011c50 @ 00011c50: print n characters of s at the text cursor (CR moves down 12 pixels) */
void FUN_00011c50(char *s, int c, int n)
{
    int x, y;
    x = FUN_0004058c();
    y = FUN_00040594();
    if (s == 0) return;
    while (1) {
        if (*s == 0) return;
        if (n == 0) return;
        if (*s == 0xd) FUN_000404f4(x += 0xc, y);
        else FUN_00040354(*s, c);
        s++;
        n--;
    }
}

#undef M000698e0_b7
#undef FUN_0002c368
#undef W
#undef H
#undef OPEN
/* ---- from build/var/mod/parts/p11ca8.c */
/* FUN_00011ca8 @ 00011ca8: pixel width of a string (while(1)/break keeps the loop top-tested) */
extern int FUN_00040318(char, int);
int FUN_00011ca8(unsigned char *s, int font)
{
    int w = 0;
    if (s) {
        while (1) {
            if (*s == 0) break;
            if (*s == '\r') w = 0;
            else w += FUN_00040318(*s, font);
            s++;
        }
    }
    return w;
}

/* ---- from build/var/mod/parts/p11ce4.c */
extern char *FUN_00011c08(void); /* module prototype */
extern void FUN_00011c50(char *s, int c, int n); /* module prototype */
extern int FUN_00011ca8(unsigned char *s, int font); /* module prototype */
/* FUN_00011ce4 (module 0x106c0, -3s -ox -oe -oa -ot -j -w0): MATCH (round 66 lane BC). The frame slots needed a size-2 register temp created between the 0xd branch's call result and its subtraction: the call is a statement of its own, the test and body sit in an inner block whose short local s holds the old e->len; block-local order ht, ym, nm, wd. */
#include <ctype.h>
#include "world.h"
struct NOTE { short x, y, len; char p[1]; };
extern char DAT_00055760[];
extern int DAT_0005c050;

extern int FUN_00040aec(void);
extern void FUN_0003a380(int, int, int, void *), FUN_000404f4(int, int), FUN_00040354(int, int);
extern void FUN_0002a8c8(int, int, int, int, int);
void FUN_00011ce4(int x, int y, int n, void *save)
{
    struct NOTE *e;
    char *p;
    int key, redraw, lines;
    key = 0;
    redraw = 1;
    p = DAT_00055760;
    lines = 0;
    if (*(short *)(p + 4) != 0)
        do { p = p + 6 + *(short *)(p + 4); } while (*(short *)(p + 4) != 0);
    if (FUN_00011c08() - DAT_00055760 < 0x7ee) {
        e = (struct NOTE *)p;
        e->x = x + B00062744_fp * 8;
        e->y = y + B00062740_gK * 5;
        e->len = 0;
        p += 6;
        p[0] = 0;
        if (key != 0x1b) {
            int ht, ym, nm, wd; /* STANDIN: declaration order decides the nm/wd/ym/ht slot tie */
            nm = n - 1;
            ym = y & ~7;
            wd = 0x140 - y;
            ht = n * 12;
            do {
                if (redraw) {
                    FUN_0003a380(0, x, ym, save);
                    FUN_000404f4(x, y);
                    FUN_00011c50(p, 1, e->len);
                    FUN_00040354(0x7c, 1);
                    redraw = 0;
                    FUN_0002a8c8(DAT_0005c050, x, y, ht, wd);
                }
                key = FUN_00040aec();
                if (key == 8) {
                    if (e->len != 0) {
                        e->len--;
                        p[e->len] = 0;
                        redraw = 1;
                    }
                } else if (key == 0xd) {
                    char *c; /* STANDIN: call result named so the call temp is made before the inner block */
                    c = FUN_00011c08(); /* STANDIN: call split from the test (same code) */
                    { /* STANDIN: inner block so s takes its id after the call temp */
                        short s; /* STANDIN: size-2 register temp between call and subtraction (frame slot order) */
                        if (c - DAT_00055760 < 0x7ee) {
                            if (lines < nm) {
                                s = e->len; /* STANDIN: p[e->len++] = 0xd through s (same code) */
                                e->len++;
                                p[s] = 0xd;
                                redraw = 1;
                                lines++;
                            } else key = 0x1b;
                        }
                    }
                } else if ((isalnum(key) || ispunct(key) || key == ' ')
                           && FUN_00011c08() - DAT_00055760 < 0x7ee && FUN_00011ca8(p, 1) + y < 0xe3) {
                    p[e->len++] = key;
                    p[e->len] = 0;
                    redraw = 1;
                }
            } while (key != 0x1b);
        }
        if (e->len == 0) {
            p[0] = 0;
            e->len = 0;
            e->x = e->y = e->len;
        }
        FUN_0003a380(0, x, y & ~7, save);
        FUN_000404f4(x, y);
        FUN_00011c50(p, 1, e->len);
        FUN_0002a8c8(DAT_0005c050, x, y, n * 12, 0x140 - y);
    }
}

/* ---- from build/var/mod/parts/p11f6c.c */
extern void FUN_0001139c(int x0, int y0, int w, int h, int t); /* module prototype */
/* FUN_00011f6c @ 00011f6c: draw the random stone border of the automap window */
#include "world.h"
int rand(void);
extern unsigned short FUN_000390d0(unsigned short); extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0002a510(int);
extern int DAT_0005c050, B000758dc_cl;
void FUN_00011f6c(int a)
{
    int x, y;
    FUN_000391b0(DAT_0005c050);
    FUN_000390d0(B00062750_gl);
    for (y = 8; y < 0xb8; y += 8) {
        FUN_0003975c(((unsigned)(rand() * 2) >> 15) + 9, 0, y, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)(rand() * 2) >> 15) + 5, 0x180, y, B000758dc_cl + 0x35, 0);
    }
    for (x = 0x10; x < 0x180; x += 0x10) {
        FUN_0003975c(((unsigned)(rand() * 2) >> 15) + 12, x, 0, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)(rand() * 2) >> 15) + 18, x, 0xf0, B000758dc_cl + 0x35, 0);
    }
    FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, a);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
}

/* ---- from build/var/mod/parts/p1207c.c */
extern void FUN_00011ce4(int x, int y, int n, void *save); /* module prototype */
extern void FUN_00011f6c(int a); /* module prototype */
extern int FUN_0002a1f4(void);
extern void FUN_000391b0(unsigned char), FUN_00032d70(void), FUN_0002aacc(void);
extern void FUN_0003e590(unsigned char), FUN_0003a020(unsigned char), FUN_0003e5d4(void), FUN_0002a288(void);
extern void *FUN_00040070(int, int, int, int, int);
extern void FUN_00040040(void *);

extern short DAT_00059e31, DAT_00059e33;
extern short DAT_00055f82, DAT_00055f84, DAT_00055f86, DAT_00055f88;
extern int DAT_0005c050;
extern unsigned char DAT_0005ef4e;
void FUN_0001207c(void)
{
    int n, y;
    void *p;
    while (FUN_0002a1f4()) ;
    FUN_00011f6c(0);
    FUN_000391b0(DAT_0005c050);
    for (;;) {
        while (!FUN_0002a1f4()) ;
        if (DAT_00059e31 >= DAT_00055f82 && DAT_00059e31 < DAT_00055f86
            && DAT_00059e33 >= DAT_00055f84 && DAT_00059e33 < DAT_00055f88)
            break;
        if (DAT_00059e31 >= 8 && DAT_00059e31 <= 0x188 && DAT_00059e33 >= 4 && DAT_00059e33 <= 0xce) {
            FUN_0002aacc();
            FUN_0003e590(DAT_0005ef4e);
            FUN_0003a020(DAT_0005ef4e ^ 1);
            n = 0x188 - DAT_00059e31;
            n /= 12;
            if (n == 0) {
                FUN_0003e5d4();
                FUN_0002a288();
            } else {
                if (n > 4) n = 4;
                y = DAT_00059e33 & ~7;
                p = FUN_00040070(DAT_00059e31, y, n * 12, 0x140 - y, 0xff);
                FUN_0003e5d4();
                FUN_00011ce4(DAT_00059e31, DAT_00059e33, n, p);
                FUN_00040040(p);
                FUN_0002a288();
            }
        }
    }
    FUN_00011f6c(1);
    FUN_00032d70();
}

/* ---- from build/var/mod/parts/p121d8.c */
extern void FUN_0001139c(int x0, int y0, int w, int h, int t); /* module prototype */
extern char *FUN_00011c08(void); /* module prototype */
#include "world.h"
#define FUN_000402cc ((int (*)(short *, int, int))FUN_000402cc)
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
extern short DAT_00055f8a, DAT_00055f8c, DAT_00055f8e, DAT_00055f90;
extern short DAT_00059e31, DAT_00059e33;

extern int DAT_0005c050;
extern int FUN_0002a1f4(void);

extern void FUN_00032d70(void), FUN_0002a510(int);
void FUN_000121d8(void)
{
    short *p, *q, *found;
    int used, off, mx, my, x, y, px, py, h, size, n;
    while (FUN_0002a1f4()) ;
    for (;;) {
        while (!FUN_0002a1f4()) ;
        mx = DAT_00059e31;
        my = DAT_00059e33;
        if (mx >= DAT_00055f8a && mx < DAT_00055f8e && my >= DAT_00055f8c && my < DAT_00055f90)
            break;
        if (mx >= 0x20 && mx <= 0x16f && my >= 0x10 && my <= 0xe3) {
            q = (short *)DAT_00055760;
            x = mx + B00062744_fp * 8;
            y = my + B00062740_gK * 5;
            found = 0;
            while (1) {
                p = q;
                if (p[2] == 0) break;
                q += 3;
                px = p[0];
                py = p[1];
                h = FUN_000402cc(q, 1, p[2]);
                if (px < x && px + 11 > x && py < y && h + py > y) found = p;
                q = (short *)((char *)q + p[2]);
            }
            if (found) {
                size = found[2] + 6;
                used = FUN_00011c08() - DAT_00055760;
                off = (char *)found + size - DAT_00055760;
                n = used - off;
                memmove(found, (char *)found + size, n);
                memset((char *)found + n, 0, size);
                FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
                FUN_0002a510(DAT_0005c050);
                DAT_0005c050 ^= 1;
            }
        }
    }
    FUN_00032d70();
}

#undef FUN_000402cc
/* ---- from build/var/mod/parts/p12354.c */
/* FUN_00012354 @ 00012354: printer ready? (INT 17h, AH=2) */
#include <i86.h>
int FUN_00012354(void)
{
    union REGS r;
    r.w.ax = 0x200;
    r.w.dx = 0;
    int386(0x17, &r, &r);
    if ((r.h.ah & 0x80) && !(r.h.ah & 0x20) && (r.h.ah & 0x10) && !(r.h.ah & 8)) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p123b8.c */
/* FUN_000123b8 @ 000123b8: find the automap note at (x, y) and produce its two-letter label */

int FUN_000123b8(int x, int y, char *out)
{
    short *p, *q = (short *)DAT_00055760;
    int found = 0, q1, q2; unsigned char c1 = 'A', c2 = ' ';
    while (1) {
        p = q;
        q += 3;
        if (p[2] == 0) break;
        q1 = p[0] / 8;
        q2 = p[1] / 5;
        if (q1 == x && q2 == y) { found = 1; break; }
        if (c1 == 'Z') {
            c1 = 'A';
            if (c2 == ' ') c2 = 'A';
            else c2++;
        } else c1++;
        q = (short *)((char *)q + p[2]);
    }
    out[0] = c1;
    out[1] = c2;
    return found;
}

/* ---- from build/var/mod/parts/p12474.c */
/* MATCH (round 65, lane AZ): slots of line / i from loop-weighted copy-out-and-back stand-ins (rough savings of i above line's, s raised with it so the register allocation stays); flags -3s -ox -oe -oa -ot -j -w0 */
#include <stdio.h>
void *memset(void *, int, unsigned);
extern char *FUN_0004104c(int);
extern void FUN_000410b0(void *), FUN_00041304(void *, int, FILE *);
extern unsigned char DAT_00055f60[];
extern char DAT_00055760[];
void FUN_00012474(FILE *fp, FILE *out, int tofile)
{
    unsigned char *line, *s;
    char *p, *q;
    unsigned char c2, c1;
    int i, k, col, had;
    c1 = 'A';
    c2 = ' ';
    q = DAT_00055760;
    line = FUN_0004104c(0x4f);
    while (1) {
        p = q;
        q += 6;
        had = 0;
        if (*(short *)(p + 4) == 0) break;
        memset(line, ' ', 0x4f);
        line[0] = c1;
        line[1] = c2;
        line[2] = ':';
        if (c1 == 'Z') {
            c1 = 'A';
            if (c2 == ' ') c2 = 'A';
            else c2++;
        } else c1++;
        col = 4;
        for (i = 0, s = q; i < *(short *)(p + 4); i++, s++) {
            if (*s == '\r') {
                if (!tofile) {
                    for (k = 0; k < 0x4f; k++) fputc(line[k], fp);
                    fputc(DAT_00055f60[0], fp);
                    fputc(DAT_00055f60[1], fp);
                    had = 0;
                } else {
                    FUN_00041304(line, 0x4f, out);
                    FUN_00041304(DAT_00055f60, 2, out);
                    had = 0;
                }
                memset(line, ' ', 0x4f);
                { int c; c = i; i = c; } /* STANDIN: copy out and back, +2 depth-2 refs of i (rough 1220 -> 2820 with the other one), no code */
                { unsigned char *c; c = s; s = c; } /* STANDIN: copy out and back, s's savings +800 so s keeps EBP against i, no code */
                col = 4;
            } else {
                { int c; c = i; i = c; } /* STANDIN: copy out and back, +2 depth-2 refs of i (rough 1220 -> 2820 with the other one), no code */
                line[col++] = *s;
                had = 1;
            }
        }
        if (!tofile) {
            if (had) {
                for (k = 0; k < 0x4f; k++) fputc(line[k], fp);
                fputc(DAT_00055f60[0], fp);
                fputc(DAT_00055f60[1], fp);
            }
            fputc(DAT_00055f60[0], fp);
            fputc(DAT_00055f60[1], fp);
        } else {
            if (had) {
                FUN_00041304(line, 0x4f, out);
                FUN_00041304(DAT_00055f60, 2, out);
            }
            line[0] = '\n';
            FUN_00041304(line, 1, out);
        }
        q += *(short *)(p + 4);
    }
    if (!tofile) {
        fputc(DAT_00055f60[0], fp);
        fputc(DAT_00055f60[1], fp);
    } else FUN_00041304(DAT_00055f60, 2, out);
    FUN_000410b0(line);
}

/* ---- from build/var/mod/parts/p126e8.c */
extern int FUN_00010700(int x, int y, int i); /* module prototype */
extern unsigned FUN_000109b0(int p, int x, int y); /* module prototype */
extern int FUN_00012354(void); /* module prototype */
extern int FUN_000123b8(int x, int y, char *out); /* module prototype */
extern void FUN_00012474(FILE *fp, FILE *out, int tofile); /* module prototype */
/* FUN_000126e8 @ 000126e8: print the automap to the printer (fp) or write it to a file (out); under the module's -oa the merge loop walks ln[2] with p and ln[0] with a; with the shared declarations (world.h) b declared before a gives the original registers of the merge loop (round 21; the old fit copied fp into a local) */
#include <stdio.h>
#include "world.h"
#define B00072246_dJ ((unsigned short *)&B00072246_dJ)
 
extern void FUN_0003e6d0(void), FUN_000410b0(void *), FUN_00041304(void *, int, FILE *);
extern char *FUN_0004104c(int);
void *memset(void *, int, unsigned);

extern unsigned char DAT_00051760[], DAT_00056011[], DAT_00056030, DAT_00055f60[];

#define W B00062756_ff
#define H B00062754_gp
void FUN_000126e8(FILE *fp, FILE *out, int tofile)
{
    unsigned char *ln[3]; char ch[2];
    unsigned char *b, *a, *p, *q;
    int x, y, v, i, k;
    if (!tofile) {
        if (!FUN_00012354()) {
            FUN_0003e6d0();
            return;
        }
        if (B00075618_b1.h > 0x50) fputc(0xf, fp);
    }
    ch[0] = 'A';
    ch[1] = ' ';
    ln[1] = FUN_0004104c(H);
    ln[2] = FUN_0004104c(H);
    ln[0] = FUN_0004104c(H);
    for (x = 0; x < W; x++) {
        memset(ln[1], ' ', H);
        memset(ln[2], ' ', H);
        memset(ln[0], ' ', H);
        for (y = 0, p = ln[1]; y < H; p++, y++) {
            i = W * y + x;
            v = DAT_00051760[i];
            if (v != 0xff) {
                if (v < 0x20) {
                    v = FUN_000109b0(i, x, y);
                    if (v >= 0x20 && v <= 0x33) *p = DAT_00056011[v];
                    else *p = DAT_00056030;
                    continue;
                }
                if (v >= 0x20 && v <= 0x33) {
                    *p = DAT_00056011[v];
                    continue;
                }
            }
            *p = ' ';
        }
        for (y = 0, p = ln[2]; y < H; p++, y++)
            if (DAT_00051760[x + W * y] != 0xff)
                for (k = FUN_00010700(x, y, 0); k != -1; k = FUN_00010700(x, y, k + 1))
                    if (*(unsigned short *)((char *)B00072246_dJ + k * 0x16) >= 0x3c && *(unsigned short *)((char *)B00072246_dJ + k * 0x16) <= 0x41) *p = '*';
                    else *p = 0xfe;
        for (y = 0, q = ln[0]; y < H; q++, y++)
            if (FUN_000123b8(x, y, ch)) {
                q[0] = ch[0];
                q[1] = ch[1];
                q += 2;
            }
        if (!tofile) {
            for (y = 0, p = ln[1]; y < H; y++) fputc(*p++, fp);
            fputc('\r', fp);
            for (y = 0, p = ln[2]; y < H; y++) fputc(*p++, fp);
            fputc('\r', fp);
            for (y = 0, p = ln[0]; y < H; y++) fputc(*p++, fp);
            fputc(DAT_00055f60[0], fp);
            fputc(DAT_00055f60[1], fp);
        } else {
            for (y = 0, p = ln[2], a = ln[0], b = ln[1]; y < H; p++, a++, b++, y++) {
                if (*p != ' ') *b = *p;
                if (*a != ' ') *b = *a;
            }
            FUN_00041304(ln[1], H, out);
            FUN_00041304(DAT_00055f60, 2, out);
        }
    }
    FUN_00012474(fp, out, tofile);
    if (!tofile) {
        fputc(0xc, fp);
        fflush(fp);
    }
    FUN_000410b0(ln[1]);
    FUN_000410b0(ln[2]);
    FUN_000410b0(ln[0]);
}

#undef B00072246_dJ
#undef W
#undef H
/* ---- from build/var/mod/parts/p12a34.c */
extern void FUN_000126e8(FILE *fp, FILE *out, int tofile); /* module prototype */
#define FUN_000126e8 ((void (*)(int, int, int))FUN_000126e8)
/* FUN_00012a34 @ 00012a34: save automap n to AUTOMAPS\AUTOnnn.MAP */
extern void FUN_00041380(char *), FUN_000412dc(int), FUN_0003e6d0(void); extern int FUN_000412c8(char *), FUN_000412b4(char *);
extern char s_AUTOMAPS_AUTO_MAP_00055fda[];
void FUN_00012a34(int n)
{
    int h;
    s_AUTOMAPS_AUTO_MAP_00055fda[0xd] = n / 100 + '0';
    s_AUTOMAPS_AUTO_MAP_00055fda[0xe] = n % 10 + '0';
    s_AUTOMAPS_AUTO_MAP_00055fda[0xf] = (n - n / 100 * 100) / 10 + '0';
    FUN_00041380(s_AUTOMAPS_AUTO_MAP_00055fda);
    FUN_000412dc(FUN_000412c8(s_AUTOMAPS_AUTO_MAP_00055fda));
    h = FUN_000412b4(s_AUTOMAPS_AUTO_MAP_00055fda);
    if (h == -1) { FUN_0003e6d0(); return; }
    FUN_000126e8(0, h, 1);
    FUN_000412dc(h);
}

#undef FUN_000126e8
/* ---- from build/var/mod/parts/p12ae8.c */
extern void FUN_00011558(void); /* module prototype */
extern char *FUN_00011c08(void); /* module prototype */
/* FUN_00012ae8 @ 00012ae8: load the automap of level lev from WORK\LEVnnn.DAT (or restore the current level's live map); 0 when the file is missing */
/* In module 0x106c0 (-ox -oe -oa -ot, 2026-11-10): the module defines FUN_00011c08 (20 nodes) and -oe expanded it
   here; the original calls it (f11558.c now spells it with 21 nodes, TODO there). Left under -oa: in the level size
   B00062756_ff * B00062754_gp the original loads w into edx and h into eax (result in h's register); ours puts the
   result in w's register, and with the operands swapped the loads come in the other order. Q1 no; Q2 no; Q3 the
   register of a commutative product (without -oa the original form matches); Q4 -. Tried: operands swapped,
   struct WH for the two shorts (recipe 27). Round 27: matches in the module with the saved map 0x56050/0x56054 as one
   record (world.h struct SAVM): two zero-savings -oa nodes fewer flip the tie of the two loads (instrument, tiemodel). */
#include "world.h"
#define DAT_00051760 ((char *)DAT_00051760)
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
 extern void *FUN_0004104c(int); extern void FUN_0002c368(unsigned char *, int), FUN_000410b0(void *), FUN_000412ec(void *, unsigned, int), FUN_0004131c(int, int, int), FUN_000412dc(int); extern int FUN_000412a0(char *);
extern int DAT_0005c6c8; extern char DAT_00055760[], DAT_0005819c[]; extern unsigned char DAT_00056058[]; extern short DAT_0005604c;
int FUN_00012ae8(int lev)
{
    int fd, n, q, c;
    if (DAT_00056050.p == 0) {
        DAT_00056050.n = FUN_00011c08() - DAT_00055760;
        DAT_00056050.p = FUN_0004104c(DAT_00056050.n);
        memmove(DAT_00056050.p, DAT_00055760, DAT_00056050.n);
    }
    memset(DAT_00051760, 0xff, 0x4000);
    memset(DAT_00055760, 0, 0x800);
    FUN_0002c368(DAT_00056058, lev + 0x26d);
    if (lev == DAT_0005c6c8) {
        FUN_00011558();
        memset(DAT_00055760, 0, 0x800);
        memmove(DAT_00055760, DAT_00056050.p, DAT_00056050.n);
        DAT_00056050.n = 0;
        FUN_000410b0(DAT_00056050.p);
        DAT_00056050.p = 0;
    } else {
        q = lev / 100;
        c = q + '0';
        DAT_0005819c[8] = c;
        DAT_0005819c[10] = lev % 10 + '0';
        DAT_0005819c[9] = (lev - q * 100) / 10 + '0';
        fd = FUN_000412a0(DAT_0005819c);
        if (fd == -1) return 0;
        if (DAT_00056048) {
            FUN_000410b0(DAT_00056048);
            DAT_00056048 = 0;
        }
        FUN_0004131c(0xd, 0, fd);
        FUN_000412ec(&n, 4, fd);
        FUN_0004131c(n, 0, fd);
        FUN_000412ec(&DAT_0005604c, 2, fd);
        if (DAT_0005604c) {
            DAT_00056048 = FUN_0004104c(DAT_0005604c * 0x16);
            FUN_000412ec(DAT_00056048, DAT_0005604c * 0x16, fd);
        }
        FUN_0004131c(0x19, 0, fd);
        FUN_000412ec(&n, 4, fd);
        FUN_0004131c(n, 0, fd);
        FUN_000412ec(&B00062756_ff, 2, fd);
        FUN_000412ec(&B00062754_gp, 2, fd);
        FUN_000412ec(DAT_00051760, B00062756_ff * B00062754_gp, fd);
        FUN_000412ec(&n, 4, fd);
        if (n < 0x7ff) FUN_000412ec(DAT_00055760, n, fd);
        FUN_000412dc(fd);
    }
    return 1;
}

#undef DAT_00051760
/* ---- from build/var/mod/parts/p12db0.c */
extern void FUN_0001139c(int x0, int y0, int w, int h, int t); /* module prototype */
extern void FUN_0001207c(void); /* module prototype */
extern void FUN_000121d8(void); /* module prototype */
extern void FUN_000126e8(FILE *fp, FILE *out, int tofile); /* module prototype */
extern void FUN_00012a34(int n); /* module prototype */
extern int FUN_00012ae8(int lev); /* module prototype */
/* FUN_00012db0 @ 00012db0: automap screen: button under (x, y) with mouse buttons m: zoom level, notes, previous/next level, marks, exit */
#include "world.h"
struct B { short x0, y0, x1, y1; };
extern struct B DAT_00055f62[];
extern volatile unsigned char DAT_00055fcb; extern unsigned char DAT_00055fca, DAT_00055fd9, DAT_0005d370[];
extern int B0006274c_dc, DAT_0005c6c8, DAT_0005c050, B000758dc_cl; 
extern void FUN_000391b0(unsigned char), FUN_000398f0(int, int, int, int, int, unsigned char *), FUN_0003975c(int, int, int, int, int), FUN_0002a8c8(int, int, int, int, int);
extern void FUN_0002a510(int), FUN_0002f8fc(void), FUN_0002ae30(void);

void FUN_00012db0(int x, int y, int m)
{
    int k;
    { extern int B000755e0_bo, B000755e4_bk; int d; d = B000755e0_bo; d = B000755e4_bk; } /* STANDIN: dead reads of scalars this function does not use - zero-savings -oa memory nodes in the pass-1 conflict list, in place of the nodes the party cell words 0x755d2 / 0x755d6 had as globals of their own (they are views of the position ints) */
    for (k = 0; DAT_00055f62[k].x0 != -1; k++) {
        if (x >= DAT_00055f62[k].x0 && x <= DAT_00055f62[k].x1 && y >= DAT_00055f62[k].y0 && y <= DAT_00055f62[k].y1) break;
    }
    if (DAT_00055f62[k].x0 == -1) {
        if (!(m & 2)) return;
        k = 11;
    } else if (m & 2) {
        if (k < 0 || k > 3) k = 11;
        else k += 12;
    }
    switch (k) {
    case 0: case 1: case 2: case 3: DAT_00055fca = 1 << k; break;
    case 12: case 13: case 14: case 15: DAT_00055fca = 1 << (k - 8); break;
    case 4:
        if (DAT_00055fd9 && DAT_00055fcb) {
            FUN_000391b0(DAT_0005c050);
            FUN_000398f0(0, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x3b, 0, DAT_0005d370);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x3f, 0x28);
            FUN_0001207c();
            FUN_000391b0(DAT_0005c050);
            FUN_0003975c(0, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x3b, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x3f, 0x28);
        }
        break;
    case 5:
        if (DAT_00055fd9 && DAT_00055fcb) {
            FUN_000391b0(DAT_0005c050);
            FUN_000398f0(0, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x3f, 0, DAT_0005d370);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x1a, 0x28);
            FUN_000121d8();
            FUN_000391b0(DAT_0005c050);
            FUN_0003975c(0, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x3f, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x1a, 0x28);
        }
        break;
    case 6:
        do {
            if (++B0006274c_dc > 0x1f) B0006274c_dc = 0;
            DAT_00055fcb = B0006274c_dc == DAT_0005c6c8;
            if (DAT_00055fcb) {
                B00062744_fp = B000755d2_ai - 0x18;
                B00062740_gK = B000755d6_ae - 0x18;
                if (B00062744_fp < -40) B00062744_fp = -40;
                if (B00062740_gK < -40) B00062740_gK = -40;
            } else {
                B00062740_gK = -4;
                B00062744_fp = -4;
            }
        } while (!FUN_00012ae8(B0006274c_dc));
        FUN_000391b0(DAT_0005c050);
        FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        break;
    case 7:
        do {
            if (--B0006274c_dc < 0) B0006274c_dc = 0x1f;
            DAT_00055fcb = B0006274c_dc == DAT_0005c6c8;
            if (DAT_00055fcb) {
                B00062744_fp = B000755d2_ai - 0x18;
                B00062740_gK = B000755d6_ae - 0x18;
                if (B00062744_fp < -40) B00062744_fp = -40;
                if (B00062740_gK < -40) B00062740_gK = -40;
            } else {
                B00062740_gK = -4;
                B00062744_fp = -4;
            }
        } while (!FUN_00012ae8(B0006274c_dc));
        FUN_000391b0(DAT_0005c050);
        FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        break;
    case 8:
        DAT_00055fd9 ^= 1;
        FUN_000391b0(DAT_0005c050);
        FUN_0003975c(DAT_00055fd9, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
        FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
        FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        break;
    case 9:
        if (DAT_00055fcb) {
            FUN_000391b0(DAT_0005c050);
            FUN_0003975c(3, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
            FUN_000126e8(stdprn, 0, 0);
            FUN_0003975c(2, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
        }
        break;
    case 10:
        if (DAT_00055fcb) {
            FUN_000391b0(DAT_0005c050);
            FUN_0003975c(5, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
            FUN_00012a34(DAT_0005c6c8);
            FUN_0003975c(4, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
            FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
        }
        break;
    case 11:
        FUN_000391b0(DAT_0005c050);
        FUN_0003975c(7, DAT_00055f62[k].x0, DAT_00055f62[k].y0, B000758dc_cl + 0x38, 0);
        FUN_0002a8c8(DAT_0005c050, DAT_00055f62[k].x0, DAT_00055f62[k].y0, 0x20, 0x30);
        DAT_00055fca = 0;
        FUN_0002f8fc();
        FUN_0002ae30();
        break;
    }
}

/* ---- from build/var/mod/parts/p134b0.c */
extern void FUN_0001139c(int x0, int y0, int w, int h, int t); /* module prototype */
/* MATCH (round 60, module 0x106c0 -3s -ox -oe -oa -ot): the row B00062740_gK a plain scalar as the original's store-back / dead reload
   show (world.h, every file of the module), and the two clamps written without the `lim` local (its cross-block node, savings 6, put
   the column ahead of the row in the savings-8 tie: tietrace class A, row first needed). */
/* Round 57 (real gap +29, 6 compiles + trace): with the row a scalar in the whole module (world.h `int B00062740_gK`) this function is
   385/385 (61 lines: row / column EBX / ESI swapped, extern order no help) and only FUN_000106c0 is lost: its row and column tie at
   savings 4 and the row wins; tw.py: removing the B000755d2_ai memory node fixes it, and with the party position 0x755d0..0x755d7 as one
   record (unsigned short fx; short x; unsigned short fy; short y) FUN_000106c0 matches, but FUN_0001083c and FUN_00012db0 then flip
   their ties (contradiction 1). Not changed. */
/* NEAR MISS (round 23, module 0x106c0 -oa, 68 worklist lines: a. first difference: the original caches the automap row B00062740_gK in ebx (load at entry, store back) where world.h's element form keeps it in memory; decision: contradiction 2 of "Shared declarations" (FUN_000106c0 needs the element form); no compile spent) 385/385 with -oa (-3s -ox -oe -oa -ot): the two cached globals swap registers (orig B00062740_gK in ebx, B00062744_fp in esi); automap module is -oa; 2026-11-08: extern order, symbol names and the module context (after FUN_00012db0, which matches with the same caching) do not change the cache registers; explicit locals y = B00062740_gK, x = B00062744_fp get ebx/esi right but lose the reloads at the FUN_0001139c call (29 lines) */
/* FUN_000134b0 @ 000134b0: scroll the automap by the arrow/page keys and redraw it */
#include "world.h"
extern void FUN_000391b0(unsigned char), FUN_0002a510(int);
extern unsigned char DAT_00055fca; extern int DAT_0005c050; 
void FUN_000134b0(void)
{
    if (DAT_00055fca & 1) {
        if (B00062740_gK > -0x28) B00062740_gK -= 4;
    } else if (DAT_00055fca & 2) {
        if (B00062740_gK < B00062754_gp - 0x2b || B00062740_gK < -4) B00062740_gK += 4;
    } else if (DAT_00055fca & 4) {
        if (B00062744_fp > -0x28) B00062744_fp -= 4;
    } else if (DAT_00055fca & 8) {
        if (B00062744_fp < B00062756_ff - 0x2c || B00062744_fp < -4) B00062744_fp += 4;
    } else if (DAT_00055fca & 0x10) {
        B00062740_gK -= 0x28;
        if (B00062740_gK < -0x28) B00062740_gK = -0x28;
    } else if (DAT_00055fca & 0x20) {
        B00062740_gK += 0x28;
        if (B00062740_gK > B00062754_gp - 0x2f) B00062740_gK = B00062754_gp - 0x2f;
    } else if (DAT_00055fca & 0x40) {
        B00062744_fp -= 0x28;
        if (B00062744_fp < -0x28) B00062744_fp = -0x28;
    } else if (DAT_00055fca & 0x80) {
        B00062744_fp += 0x28;
        if (B00062744_fp > B00062756_ff - 0x30) B00062744_fp = B00062756_ff - 0x30;
    }
    FUN_000391b0(DAT_0005c050);
    FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
}

/* ---- from build/var/mod/parts/p13634.c */
extern void FUN_0001139c(int x0, int y0, int w, int h, int t); /* module prototype */
extern void FUN_00011558(void); /* module prototype */
extern void FUN_00011834(void); /* module prototype */
extern void FUN_000134b0(void); /* module prototype */
/* FUN_00013634 @ 00013634: the automap screen: build the map, run the scroll/click loop, then free the note buffers */
#include "world.h"
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
extern void FUN_00029ccc(int), FUN_0002a9f8(void), FUN_000391b0(unsigned char), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void), FUN_00032d8c(void), FUN_000410b0(void *), FUN_00029cf4(void);
extern unsigned char DAT_0005759c[], DAT_0005d680; extern volatile unsigned char DAT_00055fcb; extern unsigned char DAT_00058602, DAT_00051760[]; extern int B0006274c_dc, DAT_0005c6c8, DAT_0005c050; extern short DAT_00058600, DAT_00059e35, DAT_0005604c; extern char DAT_00055760[];
void FUN_00013634(int unused)
{
    int k;
    FUN_00029ccc(0);
    for (k = 0; k < 0x100; k++) DAT_0005759c[k] = k;
    DAT_00056058[0] = 0;
    FUN_0002a9f8();
    FUN_000391b0(DAT_0005c050);
    B00062744_fp = B000755d2_ai - 0x18;
    B00062740_gK = B000755d6_ae - 0x18;
    if (B00062744_fp < -0x28) B00062744_fp = -0x28;
    if (B00062740_gK < -0x28) B00062740_gK = -0x28;
    B00062756_ff = B00075618_b1.w;
    B00062754_gp = B00075618_b1.h;
    B0006274c_dc = DAT_0005c6c8;
    DAT_00055fcb = 1;
    memset(DAT_00051760, 0xff, B00062756_ff * B00062754_gp);
    FUN_00011558();
    FUN_00011834();
    FUN_0001139c(B00062744_fp, B00062740_gK, 0x30, 0x2f, 1);
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
    FUN_00032d70();
    DAT_0005d680 = 4;
    while (1) {
        if (DAT_0005d680 != 4) break;
        if ((*(volatile unsigned char *)&DAT_00055fca)) FUN_000134b0();
        if (DAT_00059e35 == 0) DAT_00055fca = 0;
        FUN_00032d8c();
    }
    if (DAT_00056050.p) {
        memset(DAT_00055760, 0, 0x800);
        memmove(DAT_00055760, DAT_00056050.p, DAT_00056050.n);
        FUN_000410b0(DAT_00056050.p);
        DAT_00056050.p = 0;
        DAT_00056050.n = 0;
    }
    if (DAT_00056048) {
        FUN_000410b0(DAT_00056048);
        DAT_00056048 = 0;
        DAT_0005604c = 0;
    }
    FUN_00029cf4();
}

/* ---- module data _DATA 00051760-0005608c (docs/data/dataown.CODE2.csv: range given by hand, see docs/MODULES.md Data round), generated by tools/data2c.py */
unsigned char DAT_00051760[16384] = { 0 };
char DAT_00055760[2048] = { 0 };
unsigned char DAT_00055f60[2] = { 0xd, 10 };
struct B DAT_00055f62[4] = { 0xb4, 3, 0xda, 0xc, 0xb4, 0xe7, 0xda, 0xf0, 6, 0x6e, 0x18, 0x84, 0x177, 0x6e, 0x18a, 0x84 };
short DAT_00055f82 = 0xa8;
short DAT_00055f84 = 0xf8;
short DAT_00055f86 = 0xe5;
short DAT_00055f88 = 0x119;
short DAT_00055f8a = 0xf3;
short DAT_00055f8c = 0xf5;
short DAT_00055f8e = 0x10e;
short DAT_00055f90 = 0x11e;
unsigned char DAT_00055f92[56] = { 0xae, 0, 0x24, 1, 0xbb, 0, 0x2e, 1, 0xf3, 0, 0x24, 1, 0, 1, 0x2e, 1, 0x1a, 1, 0, 1, 0x32, 1, 0x2f, 1, 0x36, 1, 0, 1, 0x4e, 1, 0x2f, 1, 0x52, 1, 0, 1, 0x6a, 1, 0x2f, 1, 0x6e, 1, 0, 1, 0x86, 1, 0x2f, 1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };   /* no name in the sources */
unsigned char DAT_00055fca = 0;
volatile unsigned char DAT_00055fcb = 1;
unsigned char DAT_00055fcc[13] = { 6, 0x22, 0x2a, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38 };
unsigned char DAT_00055fd9 = 1;
char s_AUTOMAPS_AUTO_MAP_00055fda[22] = {
    0x41, 0x55, 0x54, 0x4f, 0x4d, 0x41, 0x50, 0x53, 0x5c, 0x41, 0x55, 0x54, 0x4f, 0x3f, 0x3f, 0x3f,
    0x2e, 0x4d, 0x41, 0x50, 0, 0x6f
};
unsigned DAT_00055ff0[8] = { 6, 0xf, 0xe, 5, 0xc, 4, 0, 10 };
unsigned char DAT_00056010[1] = { 0xd };   /* no name in the sources */
unsigned char DAT_00056011[31] = { 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 9, 0, 0, 0, 2, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0, 0xb };
unsigned char DAT_00056030 = 0xdb;
unsigned char DAT_00056031[23] = { 0xdf, 0xdc, 0xdd, 0xde, 0xdf, 0xdc, 0xdd, 0xde, 0xcd, 0xcd, 0xba, 0xba, 0xfa, 0xfa, 0xfa, 0xfa, 0xe9, 0xb0, 9, 0xb2, 1, 0xf3, 0 };   /* no name in the sources */
char *DAT_00056048 = 0;
short DAT_0005604c = 0;
unsigned char DAT_0005604e[2] = { 0x1a, 1 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
struct SAVM DAT_00056050 = { 0 };
unsigned char DAT_00056058[52] = { 0 };
/* ---- end of module data _DATA */
