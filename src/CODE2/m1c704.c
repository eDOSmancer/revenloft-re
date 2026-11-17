/* Module: FUN_0001c704, FUN_0001c7c4, FUN_0001c80c, FUN_0001c910, FUN_0001c9a0, FUN_0001ca38, FUN_0001cadc,
   FUN_0001cbc8, FUN_0001ccf4, FUN_0001cd44, FUN_0001cee4, FUN_0001cf2c, FUN_0001cf88, FUN_0001d0b0,
   FUN_0001d1e0, FUN_0001d4e8, FUN_0001d550, FUN_0001dacc, FUN_0001db94, FUN_0001dbd4, FUN_0001dc7c,
   FUN_0001dda4, FUN_0001e028, FUN_0001e0bc, FUN_0001e0f8, FUN_0001e284, FUN_0001e578, FUN_0001e5f0
   Verified module (2026-11-17; was a module file from tools/modfile.py, round 23). */
/* ---- from src/CODE2/f1c704.c */
/* the module declaration (seen through a cast view below) */ extern unsigned char B000718e0_iO;
#define M000718e0_iO ((struct CHR *)&B000718e0_iO)
/* FUN_0001c704 @ 0001c704: advance the active hand (0..7) to the next one holding a usable weapon. Round 20: natural form
   (character record as a struct, declarations in order) matches under the module's -oa; the earlier -oa-less fit needed
   s declared before h and cast views of the record */
struct CHR { char p0[0x10]; unsigned short st; char p12[0x4a]; short hand[2]; char rest[0x248 - 0x60]; };

extern int FUN_00034478(int, int), FUN_00033e58(unsigned), FUN_00033f50(int);
extern unsigned char DAT_0005cf68, DAT_0005cf5a[];
void FUN_0001c704(void)
{
    int start = DAT_0005cf68, k, h, s, item;
    do {
        DAT_0005cf68 = (DAT_0005cf68 + 1) & 7;
        k = DAT_0005cf68;
        h = k / 2;
        s = k % 2;
        if (M000718e0_iO[h].st < 0x2000) {
            if (FUN_00034478(h, s)) {
                item = M000718e0_iO[h].hand[s];
                if (item == -1) break;
                if (FUN_00033e58(item)) break;
                if (FUN_00033f50(item)) break;
            }
        }
    } while (DAT_0005cf68 != start);
    DAT_0005cf5a[DAT_0005cf68 / 2] = 1;
    DAT_0005cf5a[start / 2] = 1;
}

#undef M000718e0_iO
/* ---- from src/CODE2/wip/f1c7c4.c */
/* NEAR MISS (round 22): 16 lines under the module set -oa (module 0x1c704), same shape as without -oa. First difference: the original loads t first into edx and lv into eax (lv reuses the i*0x248 base register); ours loads lv first; with t assigned first (18 lines) t takes eax: instrument: the return-value temp t3 (sav 12) hints eax to t (sav 12) ahead of lv (sav 8). Tried under -oa: both declaration orders x both assignment orders (only the assignment order changes code), lv as the return variable, no lv variable (50), no t variable (worse). 9 real compiles. Open: what lowers t below lv (a use of t the original lacks?). */
#include "chars.h"
extern signed char DAT_00056832[];
/* Round 35: MATCH in module: lv declared first (it outranks t in the tie of the cross-block nodes) and t loaded first, the second compare written t == 0x12 (recipe 91): `int lv, t; t = CH_TYPE(i); lv = CH_LEVEL(i);`; 96 real compiles over declaration form x second compare x zero test x tail form (all 12 forms with lv declared first and assigned second match except the < 0x33 tail). Round 31 (20 real): the original's `cmp edx,edx` is the second `t == 0x12` compare on the path where t == 0x12 holds (MODULES.md recipe 91); `t == 0x12` lowers t's savings 12 -> 10 but lv stays 8: 6 lines; named/unnamed t and lv, both declaration orders, both compare forms: 6-27. Round 29 (real 10.0a in this module, 60 compiles): FUN_0001c7c4 6 lines. The original loads CH_TYPE first (into edx) and CH_LEVEL second (eax, sharing the i*0x248 register); with t declared first the load order is right (9 lines) but t (savings 12) sorts before lv (8) and takes EAX: class C, the original needs lv to outrank t. Types of t/lv (5x5 x 2 orders), CH_TYPE written out, != 0 / ! forms, else-if chain, inverted test: none (6-23). */
int FUN_0001c7c4(int i) { int lv, t; t = CH_TYPE(i); lv = CH_LEVEL(i); if (t != 0x12 || (t == 0x12 && lv == 0)) return DAT_00056832[t]; if (lv <= 0x32) return 1; if (lv <= 0x63) return 2; return 3; }

/* ---- from src/CODE2/f1c80c.c */
extern int FUN_0001c7c4(int i); /* module prototype */
/* MATCH (round 22): alone under the module's -oa set and in module 0x1c704. First difference under -oa was the shape (i loaded after obj, item*0x41 built the other way, the need operands): the `int i = i_p` copy was a stand-in for the flag set; with the parameter used directly under -oa the shape matches and only i/r swapped edi/ebp, a declaration tie: `int bonus, n, need, r, off` (r after need). 7 real compiles. */
/* FUN_0001c80c @ 0001c80c: to-hit roll of a monster against party member i */
#include "chars.h"
#include "dice.h"
#include "world.h"
extern int FUN_0001fe44(int);
#define B00071948_au (*(short *)((char *)&B000718e0_iO + 104)) /* STANDIN: view, B000718e0_iO + 0x68 */
#define B00071a12_dx (*(int *)((char *)&B000718e0_iO + 306)) /* STANDIN: view, B000718e0_iO + 0x132 */
#define B000719ea_cm (*(unsigned char *)((char *)&B000718e0_iO + 266)) /* STANDIN: view, B000718e0_iO + 0x10a */
   
int FUN_0001c80c(int i, char *obj, char *tgt, int item, int flag)
{
    int bonus, n, need, r, off;
    if (*(int *)(obj + 8) & 8) return 1;
    bonus = 0;
    n = 0;
    if (item != -1) { off = item * 0x41; bonus = (unsigned char)((char *)B000755d8_aw)[off + 0x37]; }
    if (flag) bonus -= FUN_0001c7c4(i);
    r = FUN_0001fe44(i);
    if (r == 2) bonus++;
    if (r == 3) bonus += 2;
    if (r == 4) bonus += 4;
    need = *((unsigned char *)&B000719ea_cm + i * 0x248) - (signed char)tgt[0x21] + bonus;
    if (*(int *)(obj + 8) & 0x80) need -= 4;
    if (*(int *)((char *)&B00071a12_dx + i * 0x248) & 0x100) n++;
    if (*(int *)((char *)&B00071a12_dx + i * 0x248) & 0x800) n++;
    if (*(short *)((char *)&B00071948_au + i * 0x248) == 0x54) n += 3;
    r = FUN_0002c328(1, 20, n, 0);
    if (r >= 20) return 1;
    if (r == 1) return 0;
    return r >= need;
}

/* ---- from src/CODE2/f1c910.c */
/* FUN_0001c910 @ 0001c910: damage adjustment against an object's resistances */
/* In module 0x1c6e0 (-ox -oe -ot, 2026-11-10): matches only under -oa. Without it item * 0x41 is formed as
   item += item << 6 (ebx) and the table pointer loaded into edx; the original adds item into the shifted copy (edx)
   and loads the pointer into ebx (2 lines). Q1 no clobber; Q2 item is dead after the product in both; Q3 the order of
   the shifted copy and the item (under -oa ((unsigned char *)B000755d8_aw) joins the conflict list and flips it, recipe 28); Q4 -.
   Same pattern as FUN_00033e58 (0x33df0, an -oa module). Tried: item * 0x41 + ((unsigned char *)B000755d8_aw), &((unsigned char *)B000755d8_aw)[item * 0x41],
   declaration climb of kind/m (best 2 bytes). Blocked. */

#include "world.h"
int FUN_0001c910(int d, char *obj, int item)
{
    int dmg = d;
    unsigned fl = *(unsigned *)(obj + 0x31);
    unsigned kind; unsigned char *m;
    if (item != -1) {
        m = ((unsigned char *)B000755d8_aw) + item * 0x41;
        kind = m[0x2f];
        if (m[0x37]) kind = 0xb;
    } else kind = 9;
    switch (kind) {
    case 9:  if (fl & 0x8000) dmg = 0; break;
    case 10: if (fl & 0x4000) dmg = 0; break;
    case 11:
        if ((fl & 0x20000) && m[0x37] >= -2) dmg = 0;
        if ((fl & 0x40000) && m[0x37] < -2) dmg = 0;
        break;
    }
    if (dmg < 1) dmg = 1;
    return dmg;
}

/* ---- from src/CODE2/f1c9a0.c */
/* FUN_0001c9a0 @ 0001c9a0: to-hit roll of party member i against a monster */
#include "chars.h"
#include "dice.h"
extern int FUN_0001efa0(int); extern void FUN_0001871c(int, unsigned);

int FUN_0001c9a0(int i, unsigned char *obj, char *tgt)
{
    int r, need, ac, x, fl;
    r = FUN_0002c328(1, 20, 0, 0);
    need = r;
    if (r == 20) return 1;
    if (r == 1) return 0;
    ac = FUN_0001efa0(i);
    fl = *(int *)((char *)&B00071a12_dx + i * 0x248);
    if (fl & 0x40) { FUN_0001871c(i, 6); return 0; }
    if (fl & 0x20) need = r - 2;
    if (fl & 0x100) need--;
    if (fl & 8) need -= 2;
    x = obj[0x22] - ac;
    if (*(int *)(tgt + 8) & 0x80) x += 4;
    return need >= x;
}

/* ---- from src/CODE2/f1ca38.c */
/* FUN_0001ca38 @ 0001ca38: drop the inventory of party member who at the party position (front of the floor-object list) */
 
#include "world.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
void *memmove(void *, const void *, unsigned);
struct FB { unsigned short lo : 3, d3 : 3, mid : 3, rest : 7; };
extern int B000755d0_ao;
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
extern int B000755d4_ak;
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */
#define B0006761c_g8 (*(int *)((char *)&B00067618_e7 + 4)) /* STANDIN: view, B00067618_e7 + 0x4 */
extern int B00067618_e7;
#define B00067626_hm (*(short *)((char *)&B00067618_e7 + 14)) /* STANDIN: view, B00067618_e7 + 0xe */
#define B00067624_e3 (*(short *)((char *)&B00067618_e7 + 12)) /* STANDIN: view, B00067618_e7 + 0xc */
 extern int B000755d4_ak, B000755d0_ao, B00067618_e7;
#define B0006762e_es ((char *)((char *)&B00067618_e7 + 22)) /* STANDIN: view, B00067618_e7 + 0x16 */
#define B0006762c_ey (*(struct FB *)((char *)&B00067618_e7 + 20)) /* STANDIN: view, B00067618_e7 + 0x14 */
  struct PC { char pad[0x40]; short inv[21]; char rest[0x248 - 0x40 - 42]; }; 
void FUN_0001ca38(int who)
{
    int k; short c;
    for (k = 0; k < 21; k++) {
        if (M000718e0_iO[who].inv[k] == -1) continue;
        memmove(B0006762e_es, &B00067618_e7, B00075618_b1.n4 * 0x16);
        c = (short)(B000755d6_ae * B00075618_b1.w);
        B00067626_hm = M000718e0_iO[who].inv[k];
        B00067618_e7 = B000755d4_ak;
        B0006762c_ey.d3 = 0;
        B0006762c_ey.mid = 0;
        B0006761c_g8 = B000755d0_ao;
        B00067624_e3 = c + B000755d2_ai;
        if (B00075618_b1.n4 < 100) B00075618_b1.n4++;
    }
}

#undef M000718e0_iO
/* ---- from src/CODE2/f1cadc.c */
/* FUN_0001cadc @ 0001cadc: the 400 falling raindrops/stars animation */
int rand(void);
extern void *FUN_0004104c(int); extern void FUN_000391b0(unsigned char), FUN_0003a078(int, int, int, int, int, int, int), FUN_000410b0(void *);
extern int DAT_0005c050;
void FUN_0001cadc(void)
{
    char *p, *q; int k, done;
    p = FUN_0004104c(3600);
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 400; k++) {
        *(int *)(p + k * 9) = 0;
        *(int *)(p + k * 9 + 4) = ((unsigned)(rand() * 15) >> 15) + 10;
        p[k * 9 + 8] = 0;
    }
    done = 0;
    do {
        k = 0; q = p;
        do {
            if (q[8] == 0) {
                if (*(int *)(q + 4) == 0) {
                    *(int *)(q + 4) = (unsigned)(rand() * 5) >> 15;
                    FUN_000391b0(DAT_0005c050);
                    FUN_0003a078(DAT_0005c050 ^ 1, k, *(int *)q, k, *(int *)q, 1, 4);
                    FUN_000391b0(DAT_0005c050 ^ 1);
                    *(int *)q += 4;
                    if (*(int *)q >= 0x140) { done++; q[8] = 1; }
                } else (*(int *)(q + 4))--;
            }
            k++; q += 9;
        } while (k < 400);
    } while (done != 400);
    FUN_000410b0(p);
}

/* ---- from src/CODE2/f1cbc8.c */
extern void FUN_0001cadc(void); /* module prototype */
/* FUN_0001cbc8 @ 0001cbc8: play the nine-frame animation (frames from the table, a sound on the first, the extra frame and level step at frame 6), then wait for a key press and continue with screen 0xc */
extern int DAT_0005c050, B000758dc_cl, B000758d0_jK;
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_0002f494(int), FUN_00038168(void), FUN_0002a9f8(void), FUN_000391b0(unsigned char);
extern void FUN_0003e608(void), FUN_0003e510(int, int, int, int), FUN_0002ea04(void), FUN_00038c54(int, int), FUN_0002aacc(void), FUN_00037f24(int);
extern void FUN_0002a288(void), FUN_0003e614(unsigned, int), FUN_000305b4(int); extern int FUN_0002a1f4(void);
void FUN_0001cbc8(void)
{
    int fr[9] = { 0, 1, 0, 1, 0, 2, 3, 4, 5 };
    int i;
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_0002f494(1);
    FUN_00038168();
    FUN_0002a9f8();
    FUN_000391b0(DAT_0005c050);
    FUN_0002f494(0);
    for (i = 0; i < 9; i++) {
        FUN_0003e608();
        FUN_000391b0(DAT_0005c050);
        FUN_0003e510(4, 0x20, B000758dc_cl + 0x5d + fr[i], 0);
        FUN_0002ea04();
        if (!i) FUN_00038c54(0x11, 1);
        FUN_0002ea78();
        if (i == 6) {
            FUN_000391b0(DAT_0005c050);
            FUN_0003e510(4, 0x20, fr[i + 1] + (B000758dc_cl + 0x5d), 0);
            FUN_0002ea04();
            FUN_0002aacc();
            FUN_00037f24(B000758d0_jK + 1);
            i++;
            FUN_0001cadc();
            FUN_0002a288();
        } else FUN_0003e614(0x12, 0);
    }
    while (FUN_0002a1f4()) ;
    while (!FUN_0002a1f4()) ;
    FUN_000305b4(0xc);
}

/* ---- from src/CODE2/f1ccf4.c */
extern void FUN_0001cbc8(void); /* module prototype */
/* FUN_0001ccf4 @ 0001ccf4: game over when no party member can act */
 extern unsigned short B000718f0_hO, B00071b38_c0, B00071d80_d5, B00071fc8_l9;
void FUN_0001ccf4(void)
{
    if ((B000718f0_hO & 0xd040) && (B00071b38_c0 & 0xd040) && (B00071d80_d5 & 0xd040) && (B00071fc8_l9 & 0xd040)) FUN_0001cbc8();
}

/* ---- from src/CODE2/wip/f1cd44.c */
extern void FUN_0001cbc8(void); /* module prototype */
#define M000718e0_iO ((char *)&B000718e0_iO)
/* Round 18 (module 0x1c704, 2 lines): the load of the dmg copy is scheduled after imul ebx,edi,0x248 (scheduler order of two independent instructions that feed the first store). Tried: int j = 0 / declared first (recipe 50), dmg assigned instead of initialised, `= dmg = dm`, the first store from dm: no change. */
/* MATCH in module (round 27): no copy of dmg; the all-dead test reads the four flag words through the record array (not four -oa scalar nodes; with one memory node the i/dmg tie goes the original way, tiemodel and instrument, then 10.0a). Earlier: NEAR MISS 416/416, 1 instr placement: a local copy of dmg gives the original registers and one char base for the character record keeps the death-block store order. Left: the copy load mov esi,[esp+0x14] is scheduled after imul ebx,edi,0x248 (original before). Copies of i, both copies and unsigned dmg do not move it */
/* FUN_0001cd44 @ 0001cd44: party member i takes dmg points of damage (absorbed by shields first); handles death and the all-dead check */

extern int FUN_00029cc4(void), FUN_00024a60(char *), FUN_0002c1dc(int); extern void FUN_0001ad24(int);
#define B000718fc_i0 (*(short *)((char *)&B000718e0_iO + 28)) /* STANDIN: view, B000718e0_iO + 0x1c */
#define B00071aca_he (*(int *)((char *)&B000718e0_iO + 490)) /* STANDIN: view, B000718e0_iO + 0x1ea */
#define B000719f3_iO (*(int *)((char *)&B000718e0_iO + 275)) /* STANDIN: view, B000718e0_iO + 0x113 */
extern int DAT_00071a92, DAT_00071a86, DAT_000719f7, DAT_0005bf44, DAT_0005d8a8[]; extern unsigned short B000718f0_hO, B00071b38_c0, B00071d80_d5, B00071fc8_l9;  extern unsigned char DAT_0005d681; extern char s_IRMGARDE_00050578[];
#define CH(sym, i) (*(int *)((char *)&sym + (i) * 0x248))
#define CH16(sym, i) (*(short *)((char *)&sym + (i) * 0x248))
#define CHU16(sym, i) (*(unsigned short *)((char *)&sym + (i) * 0x248))
void FUN_0001cd44(int i, int dmg)
{
    int j;
    (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1b2)) = dmg;
    (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1a6)) = FUN_00029cc4() + 0x36;
    if ((*(int *)(M000718e0_iO + (i) * 0x248 + 0x117)) != 0) {
        (*(int *)(M000718e0_iO + (i) * 0x248 + 0x117)) -= dmg;
        if ((*(int *)(M000718e0_iO + (i) * 0x248 + 0x117)) <= 0) {
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x117)) = 0;
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x132)) &= ~1;
        }
    }
    if ((*(int *)(M000718e0_iO + (i) * 0x248 + 0x1ea)) != 0) {
        if (dmg >= (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1ea))) {
            dmg -= (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1ea));
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1ea)) = 0;
        } else {
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x1ea)) -= dmg;
            dmg = 0;
        }
    }
    if ((*(int *)(M000718e0_iO + (i) * 0x248 + 0x113)) != 0) {
        if (dmg >= (*(int *)(M000718e0_iO + (i) * 0x248 + 0x113))) {
            dmg -= (*(int *)(M000718e0_iO + (i) * 0x248 + 0x113));
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x113)) = 0;
        } else {
            (*(int *)(M000718e0_iO + (i) * 0x248 + 0x113)) -= dmg;
            dmg = 0;
        }
    }
    (*(short *)(M000718e0_iO + (i) * 0x248 + 0x1c)) -= dmg;
    DAT_0005cf5a[i] = 1;
    if ((*(short *)(M000718e0_iO + (i) * 0x248 + 0x1c)) <= 0) {
        (*(short *)(M000718e0_iO + (i) * 0x248 + 0x1c)) = 0;
        (*(unsigned short *)(M000718e0_iO + (i) * 0x248 + 0x10)) |= 0x4000;
        (*(unsigned short *)(M000718e0_iO + (i) * 0x248 + 0x10)) &= 0xe3ff;
        FUN_0001ad24(i);
        j = i / 2;
        if ((&DAT_0005d681)[j] && i == DAT_0005d8a8[j]) {
            DAT_0005cf5a[j * 2] = 1;
            (&DAT_0005d681)[j] = 0;
            DAT_0005cf5a[j * 2 + 1] = 1;
        }
        if (i == FUN_00024a60("IRMGARDE") && FUN_0002c1dc(0x46) == 0) DAT_0005bf44 = 0x6a;
    }
    if (((*(unsigned short *)(M000718e0_iO + 0 * 0x248 + 0x10)) & 0xd040) && ((*(unsigned short *)(M000718e0_iO + 1 * 0x248 + 0x10)) & 0xd040) && ((*(unsigned short *)(M000718e0_iO + 2 * 0x248 + 0x10)) & 0xd040) && ((*(unsigned short *)(M000718e0_iO + 3 * 0x248 + 0x10)) & 0xd040)) FUN_0001cbc8();
}

#undef M000718e0_iO
#undef CH
#undef CH16
#undef CHU16
/* ---- from src/CODE2/m1cee4.c */
/* FUN_0001cee4: saving throw against the class/level table */
#include "chars.h"
#include "dice.h"
extern int DAT_00056888, DAT_00056ab0;
int FUN_0001cee4(int i)
{
    int v = *(int *)((char *)&DAT_00056888 + CH_CLASS_S(i) * 0x5c + CH_LVLIDX(i) * 4);
    return FUN_0002c328(1, 0x14, 0, 0) >= v;
}

/* ---- from src/CODE2/f1cf2c.c */
/* FUN_0001cf2c @ 0001cf2c: skill check: roll 1d20 against the class/level table entry plus bonus; the bonus is added before the roll */
#include "chars.h"
#include "dice.h"
extern int DAT_00056ab0;
int FUN_0001cf2c(int i, int bonus)
{
    int v = *(int *)((char *)&DAT_00056ab0 + CH_CLASS_S(i) * 0x5c + CH_LVLIDX(i) * 4);
    v += bonus;
    return FUN_0002c328(1, 0x14, 0, 0) >= v;
}

/* ---- from src/CODE2/f1cf88.c */
#define M000718f5_h2 ((signed char *)&B000718f5_h2)
#define M00071900_bm ((short *)&B00071900_bm)
/* FUN_0001cf88 @ 0001cf88: average hit points per level over the character's classes (switch on the slot k, an original bug); declaration order and the level load ahead of the end test from tools/sweep/permute.py */
extern signed char DAT_00056821[], DAT_000567fa[];
#define B00071917_a6 ((unsigned char *)((char *)&B000718e0_iO + 55)) /* STANDIN: view, B000718e0_iO + 0x37 */
 
int FUN_0001cf88(int c)
{
    int l, tot, hd, lvl, b, h, k, cl;
    tot = 0;
    for (k = 0; k != 3; k++) {
        cl = M000718f5_h2[c * 0x248 + k];
        lvl = *(short *)((char *)M00071900_bm + c * 0x248 + k * 2);
        if (cl == -1) break;
        hd = DAT_00056821[cl];
        b = DAT_000567fa[cl / 3 * 0x13 + B00071917_a6[c * 0x248]];
        for (l = 1; l <= lvl; l++) {
            switch (k) {
            case 0: case 1: case 2: if (l < 10) h = hd + b; else h = b + 3; break;
            case 4: if (l < 11) h = hd + b; else h = b + 1; break;
            case 3: if (l < 10) h = hd + b; else h = b + 2; break;
            case 5: if (l < 11) h = hd + b; else h = b + 2; break;
            }
            tot += h;
        }
    }
    return tot / k;
}

#undef M000718f5_h2
#undef M00071900_bm
/* ---- from src/CODE2/f1d0b0.c */
extern int FUN_0001cf88(int c); /* module prototype */
#define M000718fc_i0 ((short *)&B000718fc_i0)
/* FUN_0001d0b0 @ 0001d0b0: character c loses the hit points of a level l of class k (level drain): max hit points drop, current ones are clamped */
extern int FUN_0002c328(int, int, int, int);
#pragma aux FUN_0002c328 modify [ebx ecx edx];
extern signed char DAT_00056821[], DAT_000567fa[];
#define B000718fe_ar ((short *)((char *)&B000718e0_iO + 30)) /* STANDIN: view, B000718e0_iO + 0x1e */
 
void FUN_0001d0b0(int c, int k, int l)
{
    int h, s, b, mx;
    mx = FUN_0001cf88(c);
    h = FUN_0002c328(1, DAT_00056821[k], 0, 0);
    b = DAT_000567fa[k / 3 * 0x13 + B00071917_a6[c * 0x248]];
    s = 0;
    switch (k) {
    case 0: case 1: case 2: if (l < 10) s = h + b; else s = b + 3; break;
    case 4: if (l < 11) s = h + b; else s = b + 1; break;
    case 3: if (l < 10) s = h + b; else s = b + 2; break;
    case 5: if (l < 11) s = h + b; else s = b + 2; break;
    }
    if (s < 1) s = 1;
    *(short *)((char *)B000718fe_ar + c * 0x248) -= s;
    if (*(short *)((char *)B000718fe_ar + c * 0x248) < 1) *(short *)((char *)B000718fe_ar + c * 0x248) = 1;
    if (*(short *)((char *)B000718fe_ar + c * 0x248) > mx) *(short *)((char *)B000718fe_ar + c * 0x248) = mx;
    if (*(short *)((char *)M000718fc_i0 + c * 0x248) > *(short *)((char *)B000718fe_ar + c * 0x248)) *(short *)((char *)M000718fc_i0 + c * 0x248) = *(short *)((char *)B000718fe_ar + c * 0x248);
}

#undef M000718fc_i0
/* ---- from src/CODE2/f1d1e0.c */
extern void FUN_0001d0b0(int c, int k, int l); /* module prototype */
#define DAT_0005d681 ((unsigned char *)&DAT_0005d681)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define B000718f0_hO ((char *)&B000718f0_hO)
#define M000718fc_i0 ((char *)&B000718fc_i0)
#define M00071900_bm ((char *)&B00071900_bm)
/* FUN_0001d1e0 @ 0001d1e0: drain one level from party member p: pick the class (highest level, ties at random), lower it and reset its XP to the middle of the new level, update spell/turning tables and announce it; at level 1 the character dies */
int rand(void);
int sprintf(char *, const char *, ...);
struct ST { unsigned char lo : 2, s3 : 3, b5 : 1, dead : 1, b7 : 1; };
extern struct ST DAT_000718f1[];
#define CB(o, i) ((signed char)M000718e0_iO[(i) + (o)])
#define B00071902_aC ((char *)((char *)&B000718e0_iO + 34)) /* STANDIN: view, B000718e0_iO + 0x22 */
#define B00071904_aA ((char *)((char *)&B000718e0_iO + 36)) /* STANDIN: view, B000718e0_iO + 0x24 */
extern char DAT_0005759c[], *PTR_s__s_loses_a_level__000567dc;
#define B00071906_aG ((int *)((char *)&B000718e0_iO + 38)) /* STANDIN: view, B000718e0_iO + 0x26 */
extern int DAT_0005d8a8[];
extern unsigned short DAT_00057d9a[][20], DAT_00057d9c[][20];
extern unsigned char DAT_0005cf5a[];
extern void FUN_00013c04(int, int), FUN_00013a78(int, int), FUN_0002c21c(char *);
#define LV(p, c) (*(short *)(M000718e0_iO + 0x20 + (c) * 2 + (p) * 0x248))
#define L0 (*(short *)(M000718e0_iO + 0x20 + p * 0x248))
#define L1 (*(short *)(M000718e0_iO + 0x22 + p * 0x248))
#define L2 (*(short *)(M000718e0_iO + 0x24 + p * 0x248))
void FUN_0001d1e0(int p)
{
    int c, lv;
    if (CB(0x16, p * 0x248) == -1) c = 0;
    else if (CB(0x17, p * 0x248) == -1) {
        c = (unsigned)rand() * 2 >> 15;
        if (L1 > L0) c = 1;
        if (L0 > L1) c = 0;
    } else {
        c = (unsigned)rand() * 3 >> 15;
        if (L2 > L0 && L2 > L1) c = 2;
        if (L1 > L0 && L1 > L2) c = 1;
        if (L0 > L1 && L0 > L2) c = 0;
    }
    lv = LV(p, c);
    if (lv > 1) {
        LV(p, c)--;
        *(int *)(M000718e0_iO + 0x26 + p * 0x248 + c * 4) = DAT_00057d9a[CB(0x15, p * 0x248 + c)][LV(p, c)] * 1000 + (DAT_00057d9c[CB(0x15, p * 0x248 + c)][LV(p, c)] - DAT_00057d9a[CB(0x15, p * 0x248 + c)][LV(p, c)]) * 1000 / 2;
        if (CB(0x15, p * 0x248) == 1) FUN_00013c04(p, L0);
        if (CB(0x15, p * 0x248) == 4) FUN_00013a78(p, L0);
        if (CB(0x16, p * 0x248) == 4) FUN_00013a78(p, L1);
        if (CB(0x17, p * 0x248) == 4) FUN_00013a78(p, L2);
        if (CB(0x15, p * 0x248) == 3) FUN_00013c04(p, L0);
        if (CB(0x16, p * 0x248) == 3) FUN_00013c04(p, L1);
        if (CB(0x17, p * 0x248) == 3) FUN_00013c04(p, L2);
        DAT_0005cf5a[p] = 1;
        if (DAT_0005d681[p / 2] && DAT_0005d8a8[p / 2] == p) DAT_0005d681[p / 2] = 2;
        sprintf(DAT_0005759c, PTR_s__s_loses_a_level__000567dc, M000718e0_iO + p * 0x248);
        FUN_0002c21c(DAT_0005759c);
        FUN_0001d0b0(p, CB(0x15, c + p * 0x248), lv);
        return;
    }
    if (lv == 1) {
        *(short *)(M000718e0_iO + 0x1c + p * 0x248) = 0;
        LV(p, c) = 0;
        ((struct ST *)(M000718e0_iO + 0x11 + p * 0x248))->dead = 1;
        ((struct ST *)(M000718e0_iO + 0x11 + p * 0x248))->s3 = 0;
        if (DAT_0005d681[p / 2] && DAT_0005d8a8[p / 2] == p) {
            DAT_0005cf5a[p / 2 * 2] = 1;
            DAT_0005d681[p / 2] = 0;
            DAT_0005cf5a[p / 2 * 2 + 1] = 1;
        }
    }
}

#undef DAT_0005d681
#undef M000718e0_iO
#undef B000718f0_hO
#undef M000718fc_i0
#undef M00071900_bm
#undef CB
#undef LV
#undef L0
#undef L1
#undef L2
/* ---- from src/CODE2/f1d4e8.c */
/* FUN_0001d4e8 @ 0001d4e8 */
extern unsigned short B000718f0_hO; 
#define CH_FLAGS(k) (*(int *)((char *)&B00071a12_dx + (k) * 0x248))
int FUN_0001d4e8(int i, unsigned char *m)
{
    int st = *(unsigned short *)((char *)&B000718f0_hO + i * 0x248);
    if (st >= 0x4000) return 1;
    if (CH_FLAGS(i) & 0x20) return 1;
    if ((CH_FLAGS(i) & 0x200) && m[0x1d] <= 4 && (*(int *)(m + 0x3a) & 0x20)) return 1;
    return 0;
}

#undef CH_FLAGS
/* ---- from src/CODE2/wip/f1d550.c */
extern void FUN_0001e284(struct M *m, unsigned char *def, int ctx, int dmg, int mode);
#include <stdlib.h>
#define PC T17_PC
#include "records.h"
#undef PC
#define M000718e0_iO ((struct T17_PC *)&B000718e0_iO)
#define DAT_0005d681 ((unsigned char *)&DAT_0005d681)
#define M T63_M
struct M { int a, b; short w8; unsigned short lo : 9, done : 1, m10 : 2, ai : 2, hi : 2; short wc; unsigned short type; short w10; short hp; unsigned short b0 : 1, fl : 2, dir : 3, mid : 8, st : 2; };
extern unsigned FUN_00040700(void);
extern int FUN_0001f2d4(int, int);
extern void FUN_00018a80(int, int, int, int, int), FUN_0002202c(int, int), FUN_00038110(int, int, int, int);
extern char *B00072230_c4, *DAT_000567e0;
extern int B000758bc_al, B000758c0_kK, DAT_0005c658;
extern unsigned char DAT_0005687e[];
void FUN_0001d550(struct M *m, unsigned char *def, int ctx)
{
    int ang, dmg, k, first, who, h, dy, dx, fl, vlad;
    if (m->type == 0xf) {
        for (k = 0; k < 4; k++)
            if (M000718e0_iO[k].fl < 0x4000 && !FUN_0001cee4(k))
                FUN_0001cd44(k, M000718e0_iO[k].hp + M000718e0_iO[k].f1ea + M000718e0_iO[k].r10b[2]);
        FUN_00038110(*(unsigned short *)(def + 0x3f) + B000758c0_kK, 0xff, 0, 1);
        return;
    }
    if (m->type == 8 && m->st == 2) {
        ang = (8 - m->dir) * 45;
        { int cq; cq = ang; ang = cq; } /* STANDIN: copy out and back, +savings on ang (rough-sort order) so the frame slots come out vlad [esp+8] / fl [esp+4] as in the original */
        if (ang >= 360) ang -= 360;
        FUN_00018a80(0, ang, -1, m->a, m->b);
        return;
    }
    dx = B000755d0_ao - m->b;
    dy = B000755d4_ak - m->a;
    if (abs(dx) > 0x15000) return;
    if (abs(dy) > 0x15000) return;
    k = DAT_0005c658 / 45 + m->dir; /* STANDIN: index built in k */
    who = DAT_0005687e[k & 7];
    srand(FUN_00040700());
    switch (who) {
    case 5: case 7: who = (unsigned)rand() * 2 >> 15; break;
    case 4: case 6: who = ((unsigned)rand() * 2 >> 15) + 1; break;
    }
    first = who;
    if (B00075618_b1.solo != 0xff) {
        while (FUN_0001d4e8(who, def)) {
            who = (who + 3) % 4;
            if (who == first) {
                FUN_00038110(B000758bc_al + 9, 0xff, 0, 1);
                return;
            }
        }
    } else {
        if (B000718f0_hO >= 0x4000 && B00071b38_c0 >= 0x4000 && who < 2) who += 2;
        if (FUN_0001d4e8(who, def)) {
            k = who ^ 1;
            if (FUN_0001d4e8(k, def)) {
                FUN_00038110(B000758bc_al + 9, 0xff, 0, 1);
                return;
            }
            who = k;
        }
    }
    vlad = FUN_00024a60("VLADISLAV") == who;
    if (FUN_0001c9a0(who, def, m)) {
        dmg = FUN_0002c328(def[0x1e], def[0x1f], def[0x20], 0);
        fl = 0;
        if ((*(int *)(def + 0x3a) & 0x20) && (M000718e0_iO[who].f132 & 0x4000)) fl = 1;
        if (!vlad) {
            if (*(int *)(def + 0x3a) & 2) {
                if (M000718e0_iO[who].f132 & 0x4000) fl = 1;
                else if (!FUN_0001cee4(who)) FUN_0001d1e0(who);
            }
            if (*(int *)(def + 0x3a) & 4) {
                if (m->type == 8) {
                    if (m->st == 1) {
                        if (M000718e0_iO[who].f132 & 0x4000) fl = 1;
                        else if (!FUN_0001cee4(who)) {
                            FUN_0002202c(who, -1);
                            M000718e0_iO[who].f1ee = FUN_00029cc4() + FUN_0002c328(2, 4, 0, 0) * 0x2a30;
                        }
                    }
                } else if (M000718e0_iO[who].f132 & 0x4000) fl = 1;
                else if (!FUN_0001cee4(who)) {
                    FUN_0002202c(who, -1);
                    M000718e0_iO[who].f1ee = FUN_00029cc4() + FUN_0002c328(2, 4, 0, 0) * 0x2a30;
                }
            }
            if ((*(int *)(def + 0x39) & 0x20) && (m->type != 0x11 || M000718e0_iO[who].race != 5)
                && M000718e0_iO[who].inv[14] != 0x86 && M000718e0_iO[who].inv[15] != 0x86
                && !FUN_0001f2d4(who, 0x45) && !FUN_0001cee4(who)) {
                M000718e0_iO[who].fl |= 0x1000;
                h = who / 2;
                if (DAT_0005d681[h] && who == DAT_0005d8a8[h]) {
                    DAT_0005cf5a[h * 2] = 1;
                    DAT_0005d681[h] = 0;
                    DAT_0005cf5a[h * 2 + 1] = 1;
                }
            }
            if ((*(int *)(def + 0x39) & 1) && !FUN_0001cee4(who)) M000718e0_iO[who].fl |= 0x800;
            if ((*(int *)(def + 0x3a) & 0x10) && M000718e0_iO[who].cls[0] != 1 && !FUN_0001cee4(who)) M000718e0_iO[who].fl |= 0x400;
        }
        if (!vlad || M000718e0_iO[who].hp - dmg > 10) FUN_0001cd44(who, dmg);
        if (fl) {
            FUN_0001e284((struct M *)m, def, ctx, FUN_0002c328(2, 6, 0, 0), 0);
            M000718e0_iO[who].t[14] = 0;
            M000718e0_iO[who].f132 &= ~0x4000;
        }
        DAT_0005cf5a[who] = 1;
        FUN_00038110(*(unsigned short *)(def + 0x3f) + B000758c0_kK, 0xff, 0, 1);
        FUN_0001ccf4();
        return;
    }
    sprintf(DAT_0005759c, DAT_000567e0, m->type * 0x45 + B00072230_c4);
    FUN_0002c21c(DAT_0005759c);
    FUN_00038110(B000758bc_al + 9, 0xff, 0, 1);
}

#undef M000718e0_iO
#undef DAT_0005d681
#undef M

/* ---- from src/CODE2/f1dacc.c */
/* FUN_0001dacc @ 0001dacc: entity id of the farthest visible monster on the given side (0 left, 1 right) of the view, or -1 */
struct SP { unsigned short x, z, a, id, hidden, key; char pad[10]; };
extern char B00077148_eJ[];
#define B00077152_el (*(unsigned short *)((char *)&B00077148_eJ + 10)) /* STANDIN: a name of its own in the original image, 10 bytes into B00077148_eJ */
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
extern struct MON B00064d80_ay[];
#define B00064d8b_a7 (*(int *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
extern int DAT_0005c050; extern unsigned short DAT_0005f038[]; extern char B00077148_eJ[];   
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
int FUN_0001dacc(int side)
{
    int j, k, off; char *rec;
    for (j = DAT_0005f038[DAT_0005c050 ^ 1] - 1; j >= 0; j--) {
        for (k = 0, off = 0; k < DAT_0005f038[DAT_0005c050 ^ 1]; off += 0x16, k++) {
            if (*(unsigned short *)((char *)&B00077152_el + (DAT_0005c050 ^ 1) * 0x2260 + off) == j) break;
        }
        rec = B00077148_eJ + (DAT_0005c050 ^ 1) * 0x2260 + k * 0x16;
        if (*(short *)(rec + 8)) continue;
        if (ENT_FL(*(unsigned short *)(rec + 6)) & 2) continue;
        if (side == 0 && *(unsigned short *)rec > 0x80) continue;
        if (side == 1 && *(unsigned short *)rec <= 0x80) continue;
        if ((*(unsigned short *)(rec + 2) - 0x7d00) >> 3 < 0x3b) continue;
        if (ENT_FL(*(unsigned short *)(rec + 6)) & 0x10) return *(unsigned short *)(rec + 6);
    }
    return -1;
}

#undef ENT_FL
/* ---- from src/CODE2/f1db94.c */
extern int FUN_0001dacc(int side); /* module prototype */
/* FUN_0001db94 @ 0001db94: select mode bit 0 of flags through FUN_0001dacc, falling back to the other mode; returns the last result (the result variable keeps eax busy, so the bit goes to edx) */

int FUN_0001db94(unsigned flags)
{
    int r;
    if (!(flags & 1)) {
        r = FUN_0001dacc(0); if (r == -1) r = FUN_0001dacc(1);
    } else if ((flags & 1) == 1) {
        r = FUN_0001dacc(flags & 1); if (r == -1) r = FUN_0001dacc(0);
    }
    return r;
}

/* ---- from src/CODE2/f1dbd4.c */
/* FUN_0001dbd4 @ 0001dbd4: training cost of the highest class level */
#include "chars.h"
extern unsigned char DAT_00056827, DAT_00056828;
#define CB(i, o) (*(signed char *)(CHAR_REC(i) + (o)))
#define CW(i, o) (*(short *)(CHAR_REC(i) + (o)))
int FUN_0001dbd4(int i)
{
    int n, k, best, bi;
    n = 1;
    if (CB(i, 0x16) != -1) n = 2;
    if (CB(i, 0x17) != -1) n++;
    best = 0;
    for (k = 0; k < n; k++) {
        if (CW(i, 0x20 + k * 2) > best) { best = CW(i, 0x20 + k * 2); bi = k; }
    }
    return 0x14 - best / *((unsigned char *)&DAT_00056828 + CB(i, 0x15 + bi) * 2) * *((unsigned char *)&DAT_00056827 + CB(i, 0x15 + bi) * 2);
}

#undef CB
#undef CW
/* ---- from src/CODE2/f1dc7c.c */
#define M000718f5_h2 ((signed char *)&B000718f5_h2)
#define M000718fc_i0 ((short *)&B000718fc_i0)
/* FUN_0001dc7c @ 0001dc7c: character c gains the hit points of a new level l in class slot k (hit die, constitution bonus, fixed gain at high levels, split for multiclass) */
extern int FUN_0002c328(int, int, int, int);
#pragma aux FUN_0002c328 modify [ebx ecx edx];
#define B000718f6_h5 ((signed char *)((char *)&B000718e0_iO + 22)) /* STANDIN: view, B000718e0_iO + 0x16 */
#define B000718f7_h4 ((signed char *)((char *)&B000718e0_iO + 23)) /* STANDIN: view, B000718e0_iO + 0x17 */
extern signed char DAT_00056821[], DAT_000567fa[];
 
void FUN_0001dc7c(int c, int k, int l)
{
    int r, h, b, s;
    r = FUN_0002c328(1, DAT_00056821[M000718f5_h2[c * 0x248 + k]], 0, 0);
    h = r;
    b = DAT_000567fa[M000718f5_h2[c * 0x248 + k] / 3 * 0x13 + B00071917_a6[c * 0x248]];
    if (r < 1) h = 1;
    switch ((unsigned char)M000718f5_h2[c * 0x248 + k]) {
    case 0: case 1: case 2: if (l < 10) s = h + b; else s = b + 3; break;
    case 4: if (l < 11) s = h + b; else s = b + 1; break;
    case 3: if (l < 10) s = h + b; else s = b + 2; break;
    case 5: if (l < 11) s = h + b; else s = b + 2; break;
    }
    if (s < 1) s = 1;
    if (B000718f6_h5[c * 0x248] != -1) {
        if (B000718f7_h4[c * 0x248] != -1) s /= 3;
        else s /= 2;
    }
    *(short *)((char *)B000718fe_ar + c * 0x248) += s;
    *(short *)((char *)M000718fc_i0 + c * 0x248) += s;
}

#undef M000718f5_h2
#undef M000718fc_i0
/* ---- from src/CODE2/wip/f1dda4.c */
/* NEAR MISS (round 23, in module 0x1c704 -oa, 31 worklist lines) a. first difference: nm = name is stored before the c-loop guard (cmp nc,0) here, after it (in the preheader) in the original; decision: the copy is a statement inside the loop that loop-invariant motion hoists to the preheader, not a statement ahead of the loop. c. nm = name moved into the loop body (hoisted to the preheader like the original): 31 -> 29 lines (2 real); left: the preheader order (the copy after the share division here, before it there) and the n/per slots. Earlier: 612/612, 18 lines (-oa): the per-class share reuses n (merge sweep); left: the nm = name copy is stored before the who*0x248 setup here, after it in the original */
extern int FUN_0001dbd4(int i); /* module prototype */
extern void FUN_0001dc7c(int c, int k, int l); /* module prototype */
#define M000718e0_iO ((char *)&B000718e0_iO)
#define B000718f0_hO ((char *)&B000718f0_hO)
#define M000718f5_h2 ((char *)&B000718f5_h2)
#define M000718f6_h5 ((char *)B000718f6_h5)
#define M000718f7_h4 ((char *)B000718f7_h4)
#define M00071900_bm ((char *)&B00071900_bm)
#define M00071906_aG ((char *)B00071906_aG)
#define M000719ea_cm ((unsigned char *)&B000719ea_cm)
/* FUN_0001dda4 @ 0001dda4: share xp among the active party members and their classes; announce and apply level gains */
int sprintf(char *, const char *, ...);
extern int FUN_000150dc(int, int);  extern void FUN_00013ea4(int, int), FUN_00013de4(int, int), FUN_0002c21c(char *);
extern char DAT_0005759c[], *PTR_s__s_gains_a__000567e4; extern unsigned short DAT_00057d9c[][20];
 
#define U16(a, o) (*(unsigned short *)((a) + (o)))
#define S16(a, o) (*(short *)((a) + (o)))
#define U32(a, o) (*(unsigned *)((a) + (o)))
#define S8(a, o) (*(signed char *)((a) + (o)))
/* Round 42: matched. The member name passed to sprintf is the expression B000718e0_iO + who * 0x248 (recipe 126: the stepped `name` and its copy `nm` were the compiler's - reduced induction of the who loop, hoisted invariant of the class loop), then declaration order `nc, best, k, share, per, c, n, who` (a pair swap c / best, tools found after declclimb stopped at 17). */
void FUN_0001dda4(int xp)
{
    int nc; int best; int k; int share; int per; int c; int n; int who;
    n = 0;
    for (k = 0; k < 4; k++) if (!(U16(B000718f0_hO, k * 0x248) & 0xf240)) n++;
    share = ((n >> 1) + xp) / n;
    if (!share) share = 1;
    best = 0;
    for (who = 0; who < 4; who++) {
        if (U16(B000718f0_hO, who * 0x248) & 0xf240) continue;
        nc = 1;
        if (S8(M000718f6_h5, who * 0x248) != -1) nc = 2;
        if (S8(M000718f7_h4, who * 0x248) != -1) nc++;
        for (c = 0; c < nc; c++) { int lvl;
            per = ((nc >> 1) + share) / nc;
            n = per;
            if (!n) n = 1;
            U32(M00071906_aG, who * 0x248 + c * 4) += n;
            for (lvl = 0; lvl < 20; lvl++)
                if (DAT_00057d9c[S8(M000718f5_h2, who * 0x248 + c)][lvl] > U32(M00071906_aG, who * 0x248 + c * 4) / 1000) break;
            if (S16(M00071900_bm, who * 0x248 + c * 2) != lvl) {
                S16(M00071900_bm, who * 0x248 + c * 2) = lvl;
                if (FUN_000150dc(0, who) >= 0) {
                    if (S8(M000718f5_h2, who * 0x248) == 1) FUN_00013ea4(who, lvl);
                    else FUN_00013de4(who, lvl);
                }
                sprintf(DAT_0005759c, PTR_s__s_gains_a__000567e4, M000718e0_iO + who * 0x248);
                FUN_0002c21c(DAT_0005759c);
                FUN_0001dc7c(who, c, lvl);
            }
            if (S16(M00071900_bm, who * 0x248 + c * 2) > S16(M00071900_bm, best * 2 + who * 0x248)) best = c;
        }
        M000719ea_cm[who * 0x248] = FUN_0001dbd4(who);
    }
}

#undef M000718e0_iO
#undef B000718f0_hO
#undef M000718f5_h2
#undef M000718f6_h5
#undef M000718f7_h4
#undef M00071900_bm
#undef M00071906_aG
#undef M000719ea_cm
#undef U16
#undef S16
#undef U32
#undef S8
/* ---- from src/CODE2/f1e028.c */
/* FUN_0001e028 @ 0001e028: monster m breaks the wall decoration of the cell it faces (play sound 0xb0, clear the decoration bits) */
#include "world.h"
struct O { short al, ah, bl, bh; int dir; short s; unsigned short type; short pad; short timer; unsigned short lo : 3, face : 3, mid : 3, busy : 1, side : 1, owner : 3, st : 2; };
extern void FUN_0002c124(int);   extern unsigned short B000698e0_b7[];
void FUN_0001e028(struct O *m)
{
    int f, c, d, r;
    r = m->ah;
    c = m->bh;
    f = m->face;
    d = 8 - f;
    d = (d + 4) % 8;
    FUN_0002c124(0xb0);
    switch (d) {
    case 0: r++; break;
    case 1: r++; c--; break;
    case 2: c--; break;
    case 3: c--; r--; break;
    case 4: r--; break;
    case 5: r--; c++; break;
    case 6: c++; break;
    case 7: r++; c++; break;
    }
    *(unsigned char *)&B000698e0_b7[B00075618_b1.w * r + c] &= 0xc0;
}

/* ---- from src/CODE2/f1e0bc.c */
/* FUN_0001e0bc @ 0001e0bc: count map objects of type 0x18 that are not flagged with 2 */
 
#include "world.h"

#define MO_FLAGS(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
#define MO_TYPE(i)  (*(unsigned short *)((char *)&B00064d8b_a7 + (i) * 0x16 + 3))
int FUN_0001e0bc(void)
{
    int i = 0, n = 0;
    for (; i < B00075618_b1.nent; i++)
        if (!(MO_FLAGS(i) & 2) && MO_TYPE(i) == 0x18) n++;
    return n != 1;
}

#undef MO_FLAGS
#undef MO_TYPE
/* ---- from src/CODE2/f1e0f8.c (round 61 blind rewrite) */
/* FUN_0001e0f8 @ 0001e0f8: place monster i on a random free cell (not seen, no wall, 15 cells or more from the party, no live monster there); 0 after three failed tries */
#include "world.h"
#include "dice.h"
#pragma intrinsic(abs)
union FX { int v; struct { unsigned short f; short i; } s; };
struct CELL { unsigned short wall : 6, seen : 1, door : 1, rest : 8; };
struct AI { unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; };
struct MON { union FX y, x; struct AI ai; unsigned short cell, type; short timer, hp; unsigned short b0 : 1, b1 : 2, b3 : 3, b6 : 3, rest : 7; };
extern struct MON B00064d80_ay[];
#define MAPC ((struct CELL *)B000698e0_b7)
extern int B000755d0_ao, B000755d4_ak;

extern unsigned FUN_00040700(void);
extern unsigned short FUN_000390d0(unsigned short);

int FUN_0001e0f8(int i)
{
    int k, c, y, x, tries;

    FUN_000390d0(FUN_00040700());
    for (tries = 0; tries < 3; tries++) {
        x = ((unsigned)(rand() * (B00075618_b1.w - 2)) >> 15) + 1;
        y = ((unsigned)(rand() * (B00075618_b1.h - 2)) >> 15) + 1;
        c = x + B00075618_b1.w * y;
        if (MAPC[c].seen) continue;
        if (MAPC[c].wall) continue;
        if (abs(x - ((short *)&B000755d0_ao)[1]) < 15) continue;
        if (abs(y - ((short *)&B000755d4_ak)[1]) < 15) continue;
        for (k = 0; k < B00075618_b1.nent; k++)
            if (!B00064d80_ay[k].ai.dead && B00064d80_ay[k].cell == c) break;
        if (k >= B00075618_b1.nent) break;
    }
    if (tries != 3) {
        B00064d80_ay[i].x.s.i = x;
        B00064d80_ay[i].y.s.f = 0x8000;
        B00064d80_ay[i].x.s.f = 0x8000;
        B00064d80_ay[i].y.s.i = y;
        B00064d80_ay[i].cell = c;
        B00064d80_ay[i].hp = FUN_0002c328(((unsigned char *)B00072230_c4)[B00064d80_ay[i].type * 0x45 + 0x1d], 6, 0, 0);
        B00064d80_ay[i].b1 = 0;
        B00064d80_ay[i].b6 = 0;
        B00064d80_ay[i].ai = *(struct AI *)(B00072230_c4 + B00064d80_ay[i].type * 0x45 + 0x35);
        B00064d80_ay[i].timer = 0;
        return 1;
    }
    return 0;
}

#undef MAPC

/* ---- from src/CODE2/wip/f1e284.c */
/* NEAR MISS (round 22): MATCHES IN MODULE 0x1c704 (module set -oa); alone 72 lines (the m/k register swap of the old note below; something of the module context, a callee's declaration or expansion, decides it). First difference in module was the kind pointer: the original loads B00072230_c4 into eax and adds the product into it (one byte shorter, `mov eax,[mem]`): `p = B00072230_c4; p += m->type * 0x45;` (recipe 30: the compound add evaluates the term first and adds into p); `p = G + t * 0x45` in either operand order adds into the product. 3 real compiles. */
extern void FUN_0001dda4(int xp); /* module prototype */
extern void FUN_0001e028(struct O *m); /* module prototype */
extern int FUN_0001e0bc(void); /* module prototype */
extern int FUN_0001e0f8(int i); /* module prototype */
#include "world.h"
struct M { int a, b; short w8; unsigned short lo : 9, done : 1, m10 : 2, ai : 2, hi : 2; short wc; unsigned short type; short w10; short hp; unsigned short b0 : 1, fl : 2, mid : 11, st : 2; };
extern int FUN_0003acdc(int), FUN_0002c1dc(int);

extern void FUN_0002c124(int), FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00026524(int), FUN_0003195c(int, int, int, int, int, int, int), FUN_000102a8(int), FUN_00038dcc(int), FUN_00038ef0(void), FUN_00038e58(int, int, int), FUN_00038110(int, int, int, int);
extern int DAT_0005c6c8, DAT_0005bf44, B000758bc_al, B000758c0_kK;
extern unsigned char DAT_0005bf38;
extern char *B00072230_c4;

void FUN_0001e284(struct M *m, unsigned char *def, int ctx, int dmg, int mode)
{
    int k;
    char *p;
    if (!mode) {
        if (def[0x1c]) m->fl = 3;
        m->w10 = 2;
    } else {
        if (def[0x1c]) m->fl = 3;
        m->w10 = 1;
    }
    if (m->type != 0xf) {
        if (m->type == 8) {
            if (m->st != 3 && m->hp > 10) {
                m->hp -= dmg;
                if (m->hp <= 0) m->hp = 10;
            }
        } else m->hp -= dmg;
    }
    if (FUN_0003acdc(m->type)) m->ai = 1;
    if (m->hp > 0) goto alive;
    if (m->type == 0x18) {
        if (!FUN_0002c1dc(0x3b) && DAT_0005c6c8 == 0x19 && !FUN_0001e0bc()) {
            m->hp = FUN_0002c328(1, 3, 0, 0);
            FUN_0002c124(0x3b);
            DAT_0005bf38 = 0;
            FUN_0002f1c8();
            FUN_0002ea78();
            DAT_0005bf38 = 1;
            FUN_00026524(1);
            return;
        }
    } else if (m->type == 0x21) FUN_0001e028(m);
    else if (m->type == 0x12) FUN_0002c124(0x20);
    else if (m->type == 9) {
        FUN_0003195c(0x6e, 0x88, 0, m->b, m->a, 1, 0);
        FUN_0003195c(0x78, 0x87, 0, m->b, m->a, 1, 0);
        FUN_0003195c(0x82, 0xe9, 0, m->b, m->a, 1, 0);
        FUN_0003195c(0x8c, 0x74, 0, m->b, m->a, 1, 0);
        DAT_0005bf44 = 1;
    } else if (m->type == 0x50) FUN_0002c124(0x43);
    else if (m->type == 8) {
        FUN_0002c124(0x51);
        FUN_0003195c(0x80, 0x74, 0, m->b, m->a, 1, 0);
        FUN_000102a8(0x1f);
        FUN_000102a8(0x20);
        FUN_000102a8(0x21);
        FUN_00038dcc(0x9c4);
        FUN_00038ef0();
        FUN_00038e58(B00075618_b1.b4, 1, 0x9c4);
    }
    p = B00072230_c4; p += m->type * 0x45;
    if (*(short *)(p + 0x43)) FUN_00038110(*(unsigned short *)(p + 0x43) + B000758bc_al, 0xff, 0, 1);
    else FUN_00038110(B000758bc_al, 0xff, 0, 1);
    for (k = 0; k < 3; k++)
        if (m->type == B00075618_b1.aa[k] && FUN_0001e0f8(ctx)) break;
    if (k == 3) m->done = 1;
    FUN_0001dda4(*(unsigned short *)(def + 0x23));
    return;
alive:
    FUN_00038110(*(unsigned short *)(def + 0x41) + B000758c0_kK, 0xff, 0, 1);
}

/* ---- from src/CODE2/f1e578.c */
/* FUN_0001e578 @ 0001e578 (character flag words are ints tested with masks) */
#define B00071a3a_di (*(int *)((char *)&B000718e0_iO + 346)) /* STANDIN: view, B000718e0_iO + 0x15a */
 extern unsigned char DAT_0005cf5a[];
#define CH_FLAGS(k) (*(int *)((char *)&B00071a12_dx + (k) * 0x248))
void FUN_0001e578(int i)
{
    int k;
    for (k = 0; k < 4; k++) {
        if (CH_FLAGS(k) & 0x20) { DAT_0005cf5a[k] = 1; CH_FLAGS(k) &= ~0x20; }
    }
    if (CH_FLAGS(i) & 0x200) {
        *(int *)((char *)&B00071a3a_di + i * 0x248) = 0;
        CH_FLAGS(i) &= ~0x200;
        DAT_0005cf5a[i] = 1;
    }
}

#undef CH_FLAGS
/* ---- from src/CODE2/wip/f1e5f0.c */
/* Round 49 (2 compiles, 2 traces + replays, one climb + pair-swap pass): the item-address pairs are named: at each of the five sites the product (wpn * 0x41) and the table-base load are two small temps of equal savings (site 1: t25 / t26, savings 4); the original order (product first at the kind test and the second charge test, base first at the dice call) is reachable from this form only by an inserted node (replay: insert savings 0..1 at pre-sort 58 for sites 1 + 2 together; no single edit for all three wrong sites). `bonus += item.add;` as its own statement before the dice call (one node fewer) puts sites 1 and 4 right but moves the dice-call address before `push n` and flips wpn / e (EDI / EBP): 8 -> 52 lines, the climb cannot repair it (wpn is a parameter); not kept. */
/* Round 43 (region work from the original listing, 79 -> 8 instruction lines, 1170/1170): (1) the strength byte and the damage bonus are two variables (str / bonus): one name split into two webs and left the byte in a slot; (2) the dice call takes `bonus + item.add` as a plain argument - an assignment in the argument doubled bonus's savings, so it was allocated ahead of the item temps and took edx; with 4 it comes after them and takes ebx like the original (xor ebx,ebx / push ebx in every case); (3) FUN_0001c910's second argument is m ([esp+4] in the original), not r - a source error behind a cast macro of the prototype, removed; (4) the timer stores are *(int *)((char *)B00071a7e_dD + hand * 4 + who * 0x248) (hand first); (5) declaration order re-climbed (climb 35 -> 11, pair swap -> 8). Left (tietrace class S, no forced group changes it): the item address wpn * 0x41 + B000755d8_aw at three sites takes the other of two forms each time (original `mov edx,[base]; add eax,ebp` at the kind test and the second charge test, `lea edx,[eax+ebp]; mov eax,[base]` at the dice call; here the reverse), and the bonus sum is add edx,ebx / push edx for add ebx,edx / push ebx. Spellings of the item access (index first, char pointer sum), `add + bonus`, sprintf's operand order: no change. Not kept: x merged into n (1169), the test as ?: without x (1173), `!`(1179 / 1162). */
/* NEAR MISS (round 23, in module 0x1c704 -oa, 102 worklist lines: a. first difference: a value kept in ebx in the original (compared with 0x4b, 0x5a, 0x63) is read from [esp+4] here, then lea/add pairs of the item address with ebp/edi swapped (recipe 42); allocation, no compile spent) 1160/1170 under the module flags -3s -ox -oe -ot (module 0x1c6e0, plain; flags.csv now has them), SHAPE 35, 148 byte lines (was 1161/1170, SHAPE 43, 157 lines; under -oimert -s 1169/1170, but there the two fixes below flip the register/slot ties: SHAPE 14 -> 25). Structural round 2026-11-10, from the original: (1) the sound number is B000758d4_jG + snd (global loaded first) - fixed; (2) the two per-hand stores index the character record in bytes, [who*0x248 + hand*4 + base] (imul 0x248, scale 4), not (who*0x92 + hand)*4 - fixed. Left (allocation): t and r swap frame slots ([esp+0x10]/[esp+8]; declaring t first fixes the slots but rotates the registers: 173 lines), the register rotation ebx/ebp/esi of who/wpn/e, one lea/add for the item address (recipe 42). */
extern int FUN_0001c80c(int i, char *obj, char *tgt, int item, int flag); /* module prototype */
extern int FUN_0001c910(int d, char *obj, int item); /* module prototype */
extern int FUN_0001db94(unsigned flags); /* module prototype */
extern void FUN_0001e284(struct M *m, unsigned char *def, int ctx, int dmg, int mode); /* module prototype */
extern void FUN_0001e578(int i); /* module prototype */
#define ENT T27_ENT
/* earlier note: SHAPE/38/175 (classify): the weapon cases are written in the original layout order 0x81, 0x82, 0x83, 0x7e, 0x85, 0x80, 0x84, 0x86, 0x7f (read off the jump table), which fixed the call order; left: register assignment (ebp/edi, ebx/edx) and 10 bytes */
/* FUN_0001e5f0 @ 0001e5f0: party member who attacks with the weapon in hand (item wpn, -1 bare-handed) the target tgt (-1: pick one): roll to hit, roll damage by weapon, apply it, set the hand's recovery time; returns the hit result */
#include <stdio.h>
#include "world.h"
#define M00064d80_ay ((struct ENT *)B00064d80_ay)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define M00071913_a2 ((unsigned char *)&B00071913_a2)
#define M0007191f_dW ((unsigned char *)&B0007191f_dW)
#define M000719f3_iO ((int *)&B000719f3_iO)
#define M00071a12_dx ((int *)&B00071a12_dx)
struct IT { unsigned char b[0x31]; signed char sub; unsigned char p[3]; unsigned short kind : 2, speed : 4, rest : 10; unsigned char ac, nd, ds, add, y[6]; };
struct ENT { char a[0xe]; unsigned short kind; short x, hp; char z[2]; };
  extern char *B00072230_c4, DAT_0005759c[], *DAT_000567e8;
extern unsigned char DAT_000567ec[]; extern signed char DAT_0005684b[];
#define B00071a7e_dD ((int *)((char *)&B000718e0_iO + 414)) /* STANDIN: view, B000718e0_iO + 0x19e */
#define B00071a8a_eK ((int *)((char *)&B000718e0_iO + 426)) /* STANDIN: view, B000718e0_iO + 0x1aa */
extern int B000758d4_jG, B000758bc_al;
extern int FUN_00033eac(int, int), FUN_00032e40(int, int), FUN_00029cc4(void);
extern void FUN_00038110(int, int, int, int), FUN_0002c21c(char *), FUN_00034b48(int, int, int, int);
/* Round 54 (4 compiles + trace): a block pointer `it` at the dice call (41) or function-wide (65), `.add + bonus` (8), braces on the solo test (8). The trace shows the -oa memory nodes at the end of the pre-sort list (75-79), so the 0..1-savings insert at 58 of round 49 is not a memory node. */
int FUN_0001e5f0(int who, int hand, unsigned wpn, int tgt)
{
    int r; int bonus; int q; int x; int n; int str; int t; int snd; struct ENT *e; int cls; int dmg; char *m; int delay; int tt; /* STANDIN: declaration order (rough-sort ids) */
    { int cq; cq = hand; hand = cq; } /* STANDIN: copy out and back, +savings on hand */
    if (tgt == -1) t = FUN_0001db94(who);
    else t = tgt;
    FUN_0001e578(who);
    { int cq; cq = t; t = cq; } /* STANDIN: copy out and back, +savings on t */
    if (B00075618_b1.solo == 0xff && t != -1 && (who & 2) && (wpn == -1 || ((struct IT *)B000755d8_aw)[wpn].kind != 2)) t = -1;
    r = 0;
    if (t != -1) {
        e = &M00064d80_ay[t];
        snd = -1;
        m = B00072230_c4 + e->kind * 0x45;
        r = FUN_0001c80c(who, e, m, wpn, 1);
        if (r) {
            cls = M00071913_a2[who * 0x248];
            str = M0007191f_dW[who * 0x248];
            if (0x12 == cls && (FUN_00033eac(who, 1) || FUN_00033eac(who, 5) || FUN_00033eac(who, 0) || FUN_00033eac(who, 2))) x = 0;
            else x = 1;
            if (x) n = DAT_0005684b[cls];
            else if (0x4b >= str) n = 3;
            else if (str <= 0x5a) n = 4;
            else if (str <= 0x63) n = 5;
            else n = 6;
            { int cq; cq = n; n = cq; } /* STANDIN: copy out and back, +savings on n */
            bonus = 0;
            if (wpn == -1) dmg = FUN_0002c328(1, 2, 0, 0);
            else if (wpn >= 0x7e && wpn <= 0x86) {
                switch (wpn) {
                case 0x81: dmg = FUN_0002c328(1, 8, 0, 0); break;
                case 0x82: dmg = FUN_0002c328(2, 8, 1, 0); snd = 9; break;
                case 0x83: dmg = FUN_0002c328(3, 8, 3, 0); snd = 9; break;
                case 0x7e: dmg = FUN_0002c328(1, 4, 0, 0); break;
                case 0x85: dmg = FUN_0002c328(1, 4, 4, 2); break;
                case 0x80: snd = 0xc; dmg = FUN_0002c328(2, 6, 0, 0); break;
                case 0x84:
                    dmg = FUN_0002c328(1, 4, 0, 0);
                    snd = 0x24;
                    if (e->hp > dmg) e->hp = dmg;
                    dmg = 0;
                    break;
                case 0x86: dmg = FUN_0002c328(1, 10, 0, 0); break;
                case 0x7f: dmg = FUN_0002c328(FUN_00032e40(4, who) / 2 + 1, 6, 0, 0); break;
                }
            } else dmg = FUN_0002c328(((struct IT *)B000755d8_aw)[wpn].nd, ((struct IT *)B000755d8_aw)[wpn].ds, bonus + ((struct IT *)B000755d8_aw)[wpn].add, n);
            if (snd != -1) {
                q = B000758d4_jG; /* STANDIN: sound base through a named local (rough-sort entry moved) */
                FUN_00038110(q + snd, 0xff, 0, 0);
            }
            if (wpn == 0x4a) {
                if (e->kind == 0x17 || e->kind == 0x1f) {
                    if (r == 0x14) {
                        if (DAT_000567ec[((struct IT *)B000755d8_aw)[wpn].sub]) {
                            tt = e->hp; /* STANDIN: copy through a named temp (+1 in-block node) */
                            dmg = tt;
                            DAT_000567ec[((struct IT *)B000755d8_aw)[wpn].sub]--;
                        }
                    } else dmg = FUN_0002c328(2, 8, 6, 0);
                } else if (0x14 == r && DAT_000567ec[((struct IT *)B000755d8_aw)[wpn].sub]) {
                    DAT_000567ec[((struct IT *)B000755d8_aw)[wpn].sub]--;
                    dmg *= 3;
                }
            } else dmg = FUN_0001c910(dmg, m, wpn);
            FUN_0001e284(e, m, t, dmg, 0);
            if (0x7f == wpn) M000719f3_iO[who * 0x92] = dmg;
            goto timing;
        }
        sprintf(DAT_0005759c, DAT_000567e8, M000718e0_iO + who * 0x248, e->kind * 0x45 + B00072230_c4);
        FUN_0002c21c(DAT_0005759c);
    }
    FUN_00038110(B000758bc_al + 9, 0xff, 1, 1);
timing:
    if (wpn == -1 || (0x7e <= wpn && wpn <= 0x86)) delay = 0x12;
    else delay = ((struct IT *)B000755d8_aw)[wpn].speed * 9;
    if (0x1000010 & M00071a12_dx[who * 0x92]) delay /= 2;
    if (r) {
        *(int *)((char *)B00071a7e_dD + hand * 4 + who * 0x248) = FUN_00029cc4() + delay / 2;
        *(int *)((char *)B00071a8a_eK + hand * 4 + who * 0x248) = dmg;
    }
    FUN_00034b48(who, hand, 0, delay);
    return r;
}

#undef M00064d80_ay
#undef M000718e0_iO
#undef M00071913_a2
#undef M0007191f_dW
#undef M000719f3_iO
#undef M00071a12_dx
#undef ENT

/* ---- module data _DATA 000567dc-00056cd8 (docs/data/dataown.CODE2.csv: inferred (ref; some shared)), generated by tools/data2c.py */
char *PTR_s__s_loses_a_level__000567dc = "%s loses a level.";
char *DAT_000567e0 = "%s swings and misses.";
char *PTR_s__s_gains_a__000567e4 = "%s gains a level.";
char *DAT_000567e8 = "%s swings at %s and misses.";
unsigned char DAT_000567ec[14] = { 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc };
signed char DAT_000567fa[39] = {
    0xc, -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 5, -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 2, 2, 2
};
signed char DAT_00056821[6] = { 10, 10, 10, 8, 4, 6 };
unsigned char DAT_00056827 = 1;
unsigned char DAT_00056828 = 1;
unsigned char DAT_00056829[9] = { 1, 1, 1, 1, 2, 3, 1, 3, 1 };   /* no name in the sources */
signed char DAT_00056832[25] = { 2, -5, -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 4, 4, 5, 6 };
signed char DAT_0005684b[51] = {
    7, -4, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 2, 7, 8, 9, 10, 0xb, 0xc, 0xe, -3, -2, -2, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 6, 6,
    6, 7, 7
};
unsigned char DAT_0005687e[10] = { 5, 0, 5, 0, 5, 1, 5, 1 };
int DAT_00056888 = 0x10;
unsigned char DAT_0005688c[548] = { 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0x10, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0x10, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
int DAT_00056ab0 = 0x13;
unsigned char DAT_00056ab4[548] = { 0x11, 0, 0, 0, 0x11, 0, 0, 0, 0x10, 0, 0, 0, 0x10, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0x13, 0, 0, 0, 0x11, 0, 0, 0, 0x11, 0, 0, 0, 0x10, 0, 0, 0, 0x10, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0x13, 0, 0, 0, 0x11, 0, 0, 0, 0x11, 0, 0, 0, 0x10, 0, 0, 0, 0x10, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0xf, 0, 0, 0, 0xf, 0, 0, 0, 0xf, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xe, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xc, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 0xa, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 8, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0xf, 0, 0, 0, 0xf, 0, 0, 0, 0xf, 0, 0, 0, 0xf, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xd, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 0xb, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
