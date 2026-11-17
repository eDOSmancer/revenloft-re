#include "farproc.h"
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
unsigned char B00075921_aX[6095];
char B00075900_a9[33];
/* BSS end */
/* Module: FUN_00032e40, FUN_00032e90, FUN_00032f40, FUN_00033024, FUN_000331c0, FUN_000333a8, FUN_00033438,
   FUN_000337e4, FUN_0003388c, FUN_00033b38, FUN_00033d84 */
/* ---- from build/var/mod/parts/p32e40.c */
/* FUN_00032e40 @ 00032e40: level of a character in a given class (three class slots) */
#include "chars.h"
 
int FUN_00032e40(int cls, int i)
{
    if (CH_CLASS_S(i) == cls) return CH_LVLIDX(i);
    if (B000718e0_iO[i].cls[1] == cls) return B000718e0_iO[i].lvl[1];
    if (B000718e0_iO[i].cls[2] == cls) return B000718e0_iO[i].lvl[2];
    return 1;
}

/* ---- from build/var/mod/parts/p32e90.c */
/* FUN_00032e90 @ 00032e90: move a projectile one step */
#include "world.h"
struct PRJ { int a, b, dir; short s; short pad; int pad2; unsigned short f0 : 1, mode : 2, rest : 13; };
extern void FUN_0003df2c(int *, int *, int, int), FUN_00019070(struct PRJ *, int), FUN_00019368(struct PRJ *); extern short FUN_0003d5d0(int, int, int); extern int FUN_00018cf4(struct PRJ *, int);

void FUN_00032e90(struct PRJ *p, int flag)
{
    int db, da; short t;
    FUN_0003df2c(&da, &db, 0xc000, p->dir);
    p->a += db;
    t = ((short *)p)[1] * B00075618_b1.w;
    p->b += da;
    p->s = t + ((short *)p)[3];
    if (FUN_0003d5d0(p->a, p->b, 0x190) == 0) {
        if (flag) FUN_00019070(p, 1);
        p->mode = FUN_00018cf4(p, 1) == 0;
        if (flag) p->mode = 1;
        FUN_00019368(p);
    }
}

/* ---- from build/var/mod/parts/p32f40.c */
/* FUN_00032f40 @ 00032f40: draw the class icon of party member i on the status bar in palette row c (the x position goes through a local) */
#include "chars.h"
extern void FUN_000398f0(int, int, int, int, int, void *);
#define B000718f0_hO (B000718e0_iO[0].fl)
 extern unsigned char DAT_0005cf70[]; extern int B000758dc_cl, DAT_0005c034;
#define CB(i) (B000718e0_iO[i].sp)
void FUN_00032f40(int i, int c)
{
    int r = -1, x;
    if (!(*(unsigned short *)((char *)&B000718f0_hO + i * 0x248) & 0x8000)) {
        if (CB(i) == 1) r = 1;
        if (CB(i) == 2) r = 0;
        if (CB(i) == 3) r = 2;
        if (CB(i) == 4) r = 3;
        if (r != -1) {
            x = (i % 2) * 53 + (i / 2) * 211;
            FUN_000398f0(r, 0x113, x + 0x15, B000758dc_cl + 0x1f + DAT_0005c034, 0, DAT_0005cf70 + (c << 8));
        }
    }
}

#undef CB
/* ---- from build/var/mod/parts/p33024.c */
extern void FUN_00032f40(int i, int c); /* module prototype */
/* FUN_00033024 @ 00033024: draw the spell list panel of side s (0 top, 1 bottom): caster portrait, class icon, six visible entries from the scroll position */
extern void FUN_0003e510(int, int, int, int), FUN_0003975c(int, int, int, int, int), FUN_0004059c(unsigned char *), FUN_0004060c(int, int, char *, int), FUN_0002a8c8(int, int, int, int, int);
extern int FUN_0002f3fc(int);
extern int DAT_0005d8a8[], DAT_0005d8b0[], DAT_0005d8b8[], B000758dc_cl, DAT_0005c034, DAT_0005c050;
#define B00071a0f_bd ((unsigned char *)((char *)&B000718e0_iO + 303)) /* STANDIN: view, B000718e0_iO + 0x12f */
#define B00071a10_dz ((unsigned char *)((char *)&B000718e0_iO + 304)) /* STANDIN: view, B000718e0_iO + 0x130 */
extern unsigned char DAT_0005cf70[], DAT_0005d270[], B00075921_aX[6095], DAT_0005d681[]; extern char B00075900_a9[33];
void FUN_00033024(int s, int flip)
{
    int a, b, who, c, top, k;
    if (!s) {
        a = 0x136;
        b = 2;
    } else {
        a = 0x136;
        b = 0xd5;
    }
    who = DAT_0005d8a8[s];
    c = B00071a0f_bd[who * 0x248];
    top = B00071a10_dz[who * 0x248];
    FUN_00032f40(who, 4);
    who ^= 1;
    FUN_00032f40(who, FUN_0002f3fc(who));
    FUN_0003e510(a, b, B000758dc_cl + 0x15 + DAT_0005c034, 0);
    FUN_0003975c(c, a + 3, c * 16 + (b + 8), B000758dc_cl + 0x1a + DAT_0005c034, 0);
    a += 0x11;
    for (k = 0; k < 6; k++) {
        if (top + k == DAT_0005d8b0[s]) break;
        if (DAT_0005d8b8[s]) FUN_0004059c(DAT_0005cf70);
        else if (!B00075921_aX[(top + k) * 0x22 + s * 0xbf4]) FUN_0004059c(DAT_0005d270);
        FUN_0004060c(a, b + 10, B00075900_a9 + s * 0xbf4 + (top + k) * 0x22, 1);
        a += 0xb;
        FUN_0004059c(0);
    }
    if (flip) FUN_0002a8c8(DAT_0005c050, 0x113, b, 0x78, 0x70);
    DAT_0005d681[s] = 1;
}

/* ---- from build/var/mod/parts/p331c0.c */
#define B00075900_a9 ((struct SP (*)[90])B00075900_a9)
/* FUN_000331c0: build side m/2's spell list from member m's memorised spells of level lvl (mage then priest, one entry per memorised copy) */
extern int FUN_0001eee0(int), FUN_0001f2b4(int);
extern void FUN_0002c368(char *, int);
extern int DAT_0005d8b0[];
#define B000718f4_h3 ((unsigned char *)((char *)&B000718e0_iO + 20)) /* STANDIN: view, B000718e0_iO + 0x14 */

struct MEM { unsigned char lo : 4, hi : 4; };
#define B0007194a_al ((struct MEM *)((char *)&B000718e0_iO + 106)) /* STANDIN: view, B000718e0_iO + 0x6a */
#define B0007199a_mo ((struct MEM *)((char *)&B000718e0_iO + 186)) /* STANDIN: view, B000718e0_iO + 0xba */

#define B00071940_lM ((short *)((char *)&B000718e0_iO + 96)) /* STANDIN: view, B000718e0_iO + 0x60 */

struct SP { char name[0x1e]; unsigned char lvl, k, who, prs; };

void FUN_000331c0(int m, int lvl)
{
    int k, tt, n, sh, ok, s; /* STANDIN: declaration order (k, n first; tt / sh placed): RoughSortTemps chain and frame-slot order */
    s = m / 2;
    DAT_0005d8b0[s] = 0;
    ok = 1;
    if (FUN_0001eee0(m)) {
        tt = B000718f4_h3[m * 0x248]; /* STANDIN: race byte through the named temp tt (a no-conflict rough-sort entry) */
        if (tt != 5 || !FUN_0001f2b4(sh = *(short *)((char *)B00071940_lM + m * 0x248))) ok = 0; /* STANDIN: argument through the named temp sh (a second rough-sort entry: id inductions / pushed-id copies get the original slots) */
    }
    for (k = 0; k < 10; k++) {
        if (ok && (n = B0007194a_al[m * 0x248 + lvl * 10 + k].lo) != 0xf) {
            for (n = B0007194a_al[m * 0x248 + lvl * 10 + k].hi; n; n--) {
                FUN_0002c368(B00075900_a9[s][DAT_0005d8b0[s]].name, lvl * 10 + 0x42 + k);
                B00075900_a9[s][DAT_0005d8b0[s]].prs = 0;
                B00075900_a9[s][DAT_0005d8b0[s]].lvl = lvl;
                B00075900_a9[s][DAT_0005d8b0[s]].k = k;
                B00075900_a9[s][DAT_0005d8b0[s]].who = m;
                DAT_0005d8b0[s]++;
            }
        }
        if ((n = B0007199a_mo[m * 0x248 + lvl * 10 + k].lo) != 0xf) {
            for (n = B0007199a_mo[m * 0x248 + lvl * 10 + k].hi; n; n--) {
                FUN_0002c368(B00075900_a9[s][DAT_0005d8b0[s]].name, lvl * 10 + 0x92 + k);
                B00075900_a9[s][DAT_0005d8b0[s]].prs = 1;
                B00075900_a9[s][DAT_0005d8b0[s]].lvl = lvl;
                B00075900_a9[s][DAT_0005d8b0[s]].k = k;
                B00075900_a9[s][DAT_0005d8b0[s]].who = m;
                DAT_0005d8b0[s]++;
            }
        }
    }
}

#undef B00075900_a9
/* ---- from build/var/mod/parts/p333a8.c */
extern void FUN_000331c0(int m, int lvl); /* module prototype */
/* FUN_000333a8 @ 000333a8 */
#include "chars.h"

extern unsigned char DAT_0005d681[], DAT_0005cf5a[], DAT_0005cf5b[]; extern int DAT_0005d8a8[], DAT_0005d8b8[];
void FUN_000333a8(int i)
{
    int h = i / 2;
    if (*(unsigned short *)(CHAR_REC(i) + 0x10) < 0x4000 && *(unsigned char *)(CHAR_REC(i) + 0x131)) {
        if (DAT_0005d681[h] && i == DAT_0005d8a8[h]) {
            DAT_0005cf5a[h * 2] = 1;
            DAT_0005d681[h] = 0;
            DAT_0005cf5b[h * 2] = 1;
            return;
        }
        DAT_0005d8a8[h] = i;
        DAT_0005d8b8[h] = 0;
        FUN_000331c0(i, *(unsigned char *)(CHAR_REC(i) + 0x12f));
        DAT_0005d681[h] = 2;
    }
}

/* ---- from build/var/mod/parts/p33438.c */
extern void FUN_000331c0(int m, int lvl); /* module prototype */
/* MATCH round 65 lane AV (-3s -ox -oe -oa -ot -w0, real 10.0a): 939/939. All remaining differences were pass-1 sort ties, moved with
   the copy-out-and-back lever (`c = v; v = c;` adds one use + one def = savings +4, the moves vanish after allocation) on named
   values: b (x2), the index sums / idx of the four spell arms, the new y value in the x arm. Note: y must stay in memory - its
   ECX candidate is only "too greedy" while the x-arm division result is allocated ahead of it. */
#include <string.h>
#include <stdio.h>
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
#define B00075900_a9 ((struct SPL (*)[90])B00075900_a9)


extern int DAT_0005d8a8[], DAT_0005d8b0[], DAT_0005d8b8[];
extern unsigned char DAT_0005d681[];
extern char DAT_0005759c[], *DAT_0005d89c, *DAT_0005d8a0, *DAT_0005d8a4;
extern int FUN_0001b950(int, int), FUN_00029cc4(void);
extern void FUN_0002c368(char *, int), FUN_0002c21c(char *);

void FUN_00033438(int s, int x, int y)
{
    int sp, top, b, n, r; /* STANDIN: declaration order (one of 5 of 120 that give the size: y stays in memory) */
    struct SPL *e;
    if (!s) b = 2;
    else b = 0xd5;
    { int c; c = b; b = c; c = b; b = c; } /* STANDIN: b copied out and back twice: savings 10 -> 18, b sorts ahead of the s*4 temp (EDI) and stays ahead when other ties move */
    if (M000718e0_iO[DAT_0005d8a8[s]].fl >= 0x4000) return;
    if (DAT_0005d8b8[s]) return;
    top = M000718e0_iO[DAT_0005d8a8[s]].f130;
    if (b <= y && b + 6 >= y) {
        if (x <= 0x15f) {
            if (top > 0) {
                DAT_0005d681[s] = 2;
                M000718e0_iO[DAT_0005d8a8[s]].f130 -= 6;
            }
        } else if (top + 6 < DAT_0005d8b0[s]) {
            DAT_0005d681[s] = 2;
            M000718e0_iO[DAT_0005d8a8[s]].f130 += 6;
        }
        return;
    }
    if (x >= 0x136 && x <= 0x146) {
        { int c, t; t = (y - (b + 10)) / 16; c = t; t = c; y = t; } /* STANDIN: new y through t, copied out and back: the division result sorts ahead of the record offset (eax; push eax) and y stays in memory */
        M000718e0_iO[DAT_0005d8a8[s]].f130 = 0;
        M000718e0_iO[DAT_0005d8a8[s]].f12f = y;
        FUN_000331c0(DAT_0005d8a8[s], y);
        DAT_0005d681[s] = 2;
        return;
    }
    n = (x - 0x147) / 11;
    n += top;
    if (n >= DAT_0005d8b0[s]) return;
    e = (struct SPL *)(n * 0x22); /* STANDIN: n * 0x22 formed first in e's register (original: mov edi,eax; shl edi,4; ...); = &B00075900_a9[s][n] */
    e = (struct SPL *)((char *)e + (int)B00075900_a9[s]); /* STANDIN: row base added second (add eax,base; add edi,eax) */
    sp = e->lvl * 10; sp += e->idx; sp += e->kind * 0x50; /* STANDIN: three statements: lvl * 10 formed in sp's register (esi) */
    r = FUN_0001b950(sp, DAT_0005d8a8[s]);
    if (r == 1) {
        if (e->kind == 0) { int o, i, c; o = e->who * 0x248 + e->lvl * 10; i = e->idx; c = i; i = c; (&M000718e0_iO[0].mage[0][0])[o + i].hi--; } /* STANDIN: = mage[lvl][idx]; index sum named, idx copied out and back (r==1 mage tie) */
        else { int o, i, c; o = e->who * 0x248 + e->lvl * 10; c = o; o = c; c = o; o = c; c = o; o = c; i = e->idx; c = i; i = c; c = i; i = c; (&M000718e0_iO[0].priest[0][0])[o + i].hi--; } /* STANDIN: = priest[lvl][idx]; sum copied out and back 3x, idx 2x: raises this arm so the second s*4 (lea edx,[ebx*4] at 0x33556) sorts ahead of the 12*s row-base copy, sum eax / idx edx */
        FUN_000331c0(e->who, e->lvl);
        sprintf(DAT_0005759c, DAT_0005d89c, M000718e0_iO[e->who].name);
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), sp + 0x42);
        FUN_0002c21c(DAT_0005759c);
    } else if (r == 0) {
        FUN_0002c21c(DAT_0005d8a0);
        if (e->kind == 0) { int o, c; o = e->who * 0x248 + e->lvl * 10; c = o; o = c; (&M000718e0_iO[0].mage[0][0])[o + e->idx].hi--; } /* STANDIN: = mage[lvl][idx]; index sum named, copied out and back (savings +4: r==0 mage sum in eax) */
        else { int o, i, c; o = e->who * 0x248 + e->lvl * 10; i = e->idx; c = i; i = c; (&M000718e0_iO[0].priest[0][0])[o + i].hi--; } /* STANDIN: = priest[lvl][idx]; same spelling (tail tie) */
        FUN_000331c0(e->who, e->lvl);
    } else if (r == -2) {
        FUN_000331c0(e->who, e->lvl);
        sprintf(DAT_0005759c, DAT_0005d89c, M000718e0_iO[e->who].name);
        FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), sp + 0x42);
        FUN_0002c21c(DAT_0005759c);
    } else {
        FUN_0002c21c(DAT_0005d8a4);
    }
    DAT_0005d8b8[s] = FUN_00029cc4() + 0x40;
    DAT_0005d681[s] = 2;
}

#undef M000718e0_iO
#undef B00075900_a9
/* ---- from build/var/mod/parts/p337e4.c */
/* FUN_000337e4 @ 000337e4: put an item into the first free pack slot (or a hand) of party member i */
#include "chars.h"
extern void FUN_0001f238(int, int, int), FUN_0003195c(int, int, int, int, int, int, int);
extern int B000755d0_ao, B000755d4_ak;
#define SLOT(i,k) (*(short *)(CHAR_REC(i) + 0x40 + (k) * 2))
#define EQUIP(i,k) (*(short *)(CHAR_REC(i) + 0x5c + (k) * 2))
void FUN_000337e4(int item, int b, int i)
{
    int k, slot = -1;
    if (EQUIP(i, 0) == -1) slot = 0xe;
    else if (EQUIP(i, 1) == -1) slot = 0xf;
    else {
        for (k = 0; k < 12; k++) if (SLOT(i, k) == -1) { slot = k; break; }
    }
    if (slot != -1) {
        SLOT(i, slot) = item;
        FUN_0001f238(i, slot, b);
    } else FUN_0003195c(0x80, item, b, B000755d0_ao, B000755d4_ak, 1, 0);
}

#undef SLOT
#undef EQUIP
/* ---- from build/var/mod/parts/p3388c.c */
extern void FUN_000337e4(int item, int b, int i); /* module prototype */
/* MATCH (round 27): alone and in module 0x32e40. The original reloads p->type before the 0x5a compare: the two compares convert p->type to different types (0x5aU unsigned, 0x58 int), so the cg CSE does not share the CONVERT (the 0x59/0x57 pair, both int, shares it). Earlier: 2 lines in module 0x32e40 (was 4): p->timer * B00071913_a2[...] in this operand order gives the original load order of the multiply. Left: the reload of p->type between the 0x58 and 0x5a compares (ours CSEs it; the 0x59/0x57 test later shares the load in both). Tried this round: (type == 0x58 && hit || type == 0x5a && hit) && st == 1 (3 lines, +7 bytes), the fully written-out disjunction (7 lines). Earlier: NEAR MISS 677/681, 8 lines under the module flags -3s -ox -oe -oa -ot (2026-11-10): returns int, as the callers' code needs (FUN_00033b38 compares the result with cmp eax,1, no cwde; with the short definition the module's one prototype made it sign-extend), and the st branch ends in an else instead of an inner return (the int version with the inner return added a mov edx,esi copy). Left: the original reloads p->type (movzx eax,[ebx+0xe]) between the 0x58 and 0x5a compares; here the load is shared (everything after is the 4-byte shift). Q1: no call between the two compares. Q2: the original's first load does not reach the second compare. Q3/Q4: n/a (no register differs). Tried 2026-11-10 (5): int return (16 lines, extra copy), int + else (8), short r (17), type as a 16-bit bitfield (37). Earlier: goto, split ifs, a volatile second read, a repeated condition, ((short *)p)[7] for the second compare (6 lines, movsx, other schedule), unsigned-short spellings, a copy q = p, two && groups (+19), a ?: form (+39). */
#include "world.h"
#define M00071913_a2 ((unsigned char *)&B00071913_a2)
#define FUN_00018cf4 ((int (*)(struct O *, int))FUN_00018cf4)
#define FUN_00019070 ((void (*)(struct O *, int))FUN_00019070)
struct O { int a, b, dir; short s; unsigned short type; short pad; short timer; unsigned short lo : 3, face : 3, mid : 3, busy : 1, side : 1, owner : 3, st : 2; };
extern void FUN_0003df2c(int *, int *, int, int), FUN_0001e578(int), FUN_00018a80(int, int, int, int, int);
extern short FUN_0003d5d0(int, int, int);


struct T { unsigned short wall : 6, rest : 10; };
extern struct T B000698e0_b7[];
extern unsigned char DAT_0005cf5a[];
int FUN_0003388c(struct O *p, int flag)
{
    int db, da, r, hit, d;
    short t;
    r = 0;
    if (p->timer) {
        FUN_0003df2c(&da, &db, 0xc000, p->dir);
        p->a += db;
        t = ((short *)p)[1] * B00075618_b1.w;
        p->b += da;
        p->s = t + ((short *)p)[3];
        if (FUN_0003d5d0(p->a, p->b, 0x190) == 0) {
            hit = 0;
            if (flag && p->type != 0x59 && p->type != 0x57) FUN_00019070(p, r);
            if (p->busy) {
                hit = FUN_00018cf4(p, 0) == 0;
                if (hit) {
                    FUN_0001e578(p->owner);
                    p->busy = 0;
                }
            }
            if (B000698e0_b7[(unsigned short)p->s].wall) {
                p->a -= db;
                t = ((short *)p)[1] * B00075618_b1.w;
                p->b -= da;
                p->busy = 0;
                p->s = t + ((short *)p)[3];
            }
            if ((flag || hit) && p->type == 0x41) {
                r = 1;
                p->busy = 0;
                FUN_00018a80(8, 0, -1, p->a, p->b);
            }
            if ((p->type == 0x58 || p->type == 0x5aU) && hit && p->st == 1) { /* TODO types: an unsigned constant (another CONVERT than 0x58's) keeps the original's reload of p->type */
                r = 1;
                p->st = 0;
            }
        }
        p->timer--;
    } else p->busy = 0;
    if ((p->type == 0x59 || p->type == 0x57) && !p->busy) {
        if (p->st) {
            d = (p->dir + 0xb4) % 0x168;
            p->dir = d;
            p->st = 0;
            d += 0x16;
            if (d >= 0x168) d -= 0x168;
            p->face = 8 - d / 0x2d;
            p->timer = 0x1e - ((unsigned char *)B000755d8_aw)[p->type * 0x41 + 0x30] / 10 * 10;
            p->timer /= 2;
            if (p->timer < 0) p->timer = 0;
            p->timer = (p->timer * M00071913_a2[p->owner * 0x248] + 9) / 0x12;
            p->busy = 1;
        } else {
            FUN_000337e4(p->type, p->side, p->owner);
            r = 1;
            DAT_0005cf5a[p->owner] = 1;
        }
    }
    return r;
}

#undef M00071913_a2
#undef FUN_00018cf4
#undef FUN_00019070
/* ---- from build/var/mod/parts/p33b38.c */
extern int FUN_0003388c(struct O *p, int flag); /* module prototype */
/* FUN_00033b38 @ 00033b38: throw item it from (x, y) (16.16) in direction ang by party member who (-1: none): add a flying object and step it until it stops */
 
#include "world.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
#define M00071913_a2 ((unsigned char *)&B00071913_a2)
void *memmove(void *, const void *, unsigned);
extern int FUN_0003c9dc(unsigned, unsigned); extern void FUN_00038110(int, int, int, int);
extern struct FO B00067618_e7[];
#define B0006762e_es ((char *)((char *)&B00067618_e7 + 22)) /* STANDIN: view, B00067618_e7 + 0x16 */
    extern int B000758bc_al;
struct FB { unsigned short lo : 3, d3 : 3, mid : 3, fly : 1, flag : 1, own : 3, top : 2; };
struct FO { int x, y, dir; short cell, item, z, pw; struct FB fb; };
extern struct FO B00067618_e7[];
void FUN_00033b38(int it, int flag, int ang, int who, int x, int y)
{
    struct FO *e;
    if (B00075618_b1.n4 == 300) {
        memmove(B00067618_e7, B0006762e_es, 0x19b2);
        B00075618_b1.n4 = 299;
    }
    e = (struct FO *)(B00075618_b1.n4 * 0x16 + (int)B00067618_e7);
    e->x = x;
    e->y = y;
    e->cell = (short)(((short *)&x)[1] * B00075618_b1.w) + ((short *)&y)[1];
    e->z = 0;
    e->dir = ang;
    e->fb.mid = 0;
    e->fb.flag = flag;
    e->item = it;
    e->fb.own = who;
    if (it == 0x59 || it == 0x57) e->fb.top = 1;
    else e->fb.top = 0;
    e->pw = 0x1e - *(unsigned char *)(((char *)B000755d8_aw) + it * 0x41 + 0x30) / 10 * 10;
    e->pw /= 2;
    if (e->pw < 0) e->pw = 0;
    if (who != -1) e->pw = (e->pw * M00071913_a2[who * 0x248] + 9) / 0x12;
    if (*(unsigned char *)(((char *)B000755d8_aw) + it * 0x41 + 0x2f) == 0xf || *(unsigned char *)(((char *)B000755d8_aw) + it * 0x41 + 0x2f) == 0xd) e->pw = 0x7fff;
    B00075618_b1.n4++;
    ang += 0x16;
    e->fb.fly = 1;
    if (ang >= 0x168) ang -= 0x168;
    e->fb.d3 = 8 - ang / 0x2d;
    if ((it >= 0x24 && it <= 0x25) || (it >= 0xf4 && it <= 0xf7) || it == 0x2a || (it >= 0x100 && it <= 0x101) || it == 0x65 || it == 0x69 || *(unsigned char *)(((char *)B000755d8_aw) + it * 0x41 + 0x2f) == 0xf)
        e->fb.d3 = (e->fb.d3 + 4) & 7;
    do {
        if (!FUN_0003c9dc(e->x, e->y)) break;
        if (FUN_0003388c(e, 0) == 1) {
            B00075618_b1.n4--;
            break;
        }
    } while (e->fb.fly);
    FUN_00038110(B000758bc_al + 1, 0xff, 1, 3);
}

#undef M000718e0_iO
#undef M00071913_a2
/* ---- from build/var/mod/parts/p33d84.c */
extern void FUN_00033b38(int it, int flag, int ang, int who, int x, int y); /* module prototype */
/* FUN_00033d84 @ 00033d84 */

extern int DAT_0005c658, B000755d0_ao, B000755d4_ak;
void FUN_00033d84(int a, int b, int dir, int d4)
{
    int d = DAT_0005c658 - (dir - 0x80) / 3;
    if (d < 0) d += 360;
    if (d >= 360) d -= 360;
    FUN_00033b38(a, b, d, d4, B000755d4_ak, B000755d0_ao);
}

/* ---- module data _DATA 0005d89c-0005d8c0 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
char *DAT_0005d89c = "%s CASTS ";
char *DAT_0005d8a0 = "THE INCANTATION FAILS";
char *DAT_0005d8a4 = "THE SPELL IS ABORTED";
int DAT_0005d8a8[1] = { 0 };
int DAT_0005d8ac = 0;   /* type from another module's declaration */
int DAT_0005d8b0[2] = { 0 };
int DAT_0005d8b8[1] = { 0 };
unsigned DAT_0005d8bc = 0;   /* type from another module's declaration */
/* ---- end of module data _DATA */
