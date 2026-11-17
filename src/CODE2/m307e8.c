/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
int B00075614_lm;
int B00075610_a9;
int B0007560c_hn;
int B00075608_c1;
int B00075604_mM;
int B00075600_b9;
int B000755fc_ax;
int B000755f8_bg;
/* BSS end */
/* Module: FUN_000307e8, FUN_00030850, FUN_00030994, FUN_00030a24, FUN_00030b40, FUN_00030c0c, FUN_00030cf4,
   FUN_00030d7c, FUN_00030e08, FUN_000310b0, FUN_000311d8, FUN_000314b8, FUN_00031704, FUN_00031880,
   FUN_0003195c, FUN_00031adc, FUN_00031b44, FUN_00031bf0, FUN_00031db4, FUN_00031f1c, FUN_00031f70,
   FUN_000323f4, FUN_00032894, FUN_000329cc, FUN_00032ce0, FUN_00032d70, FUN_00032d8c */
/* names inside DAT_0005cf4c (tools/dataview.py): views of the object its module defines */
#define DAT_0005cf4e (*(short *)((char *)&DAT_0005cf4c + 0x2))
/* names inside DAT_00057330 (tools/dataview.py): views of the object its module defines */
#define DAT_00057334 ((unsigned char *)((char *)DAT_00057330 + 0x4))
/* names inside PTR_s_NOT_ENOUGH_SPACE_IN_INVENTORY_0005d678 (tools/dataview.py): views of the object its module defines */
#define DAT_0005d67c (*(char * *)((char *)&PTR_s_NOT_ENOUGH_SPACE_IN_INVENTORY_0005d678 + 0x4))
/* ---- from build/var/mod/parts/p307e8.c */
/* FUN_000307e8 and FUN_00031880 in one file (round 62 lane Z): FUN_00031880's auto initialiser cell[8] is module 0x307e8's lead data at 0x307e0 (ahead of the first function of the object); replaces src/CODE2/f307e8.c and src/CODE2/f31880.c, supersedes asmfb/w307d1.asm */
/* FUN_000307e8 @ 000307e8: facing angle of a map entity (3-bit direction field) */
extern void FUN_0003df2c(int, int, int, int);
struct ENT { unsigned short f0 : 3, dir : 3, rest : 10; };
extern char B00064d80_ay[];
#define B00064d94_aU (*(struct ENT *)((char *)&B00064d80_ay + 20)) /* STANDIN: view, B00064d80_ay + 0x14 */

#define ENT(i) ((struct ENT *)((char *)&B00064d94_aU + (i) * 0x16))
void FUN_000307e8(int i, int turn, int c, int d)
{
    int t = 0;
    int ang = ((8 - ENT(i)->dir + 4 + turn) & 7) * 45;
    if (ang >= 360) ang -= 360;
    FUN_0003df2c(d, c, t, ang);
}

#undef ENT
/* ---- from build/var/mod/parts/p30850.c */
extern void FUN_000307e8(int i, int turn, int c, int d); /* module prototype */
/* FUN_00030850 @ 00030850: monster wander pass: centre every active wanderer in its cell (keeping its facing), then try a random step for each */
#include "world.h"
#define FUN_000307e8 ((void (*)(int, unsigned, int *, int *))FUN_000307e8)

extern int FUN_0003acdc(int); extern short FUN_0003d5d0(int, int, int); extern void FUN_0001e0f8(int);
 extern char B00064d80_ay[];
#define EF(k) (*(int *)(B00064d80_ay + (k) * 0x16 + 0xb))
#define EID(k) (*(unsigned short *)(B00064d80_ay + (k) * 0x16 + 0xe))
#define EX(k) (*(int *)(B00064d80_ay + (k) * 0x16))
#define EY(k) (*(int *)(B00064d80_ay + (k) * 0x16 + 4))
struct DIR { unsigned short lo : 3, dir : 3, hi : 10; };
#define ED(k) (*(struct DIR *)(B00064d80_ay + (k) * 0x16 + 0x14))
void FUN_00030850(void)
{
    int k, x, y;
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (EF(k) & 2) continue;
        if (!FUN_0003acdc(EID(k))) continue;
        *(short *)(B00064d80_ay + k * 0x16) = 0x8000;
        *(short *)(B00064d80_ay + k * 0x16 + 4) = 0x8000;
        ED(k).dir &= 6;
    }
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (EF(k) & 2) continue;
        if (!FUN_0003acdc(EID(k))) continue;
        x = EX(k);
        y = EY(k);
        if (FUN_0003d5d0(x, y, k) == 0) {
            FUN_000307e8(k, (unsigned)(rand() * 8) >> 15, &x, &y);
            x += EX(k);
            y += EY(k);
            if (FUN_0003d5d0(x, y, k) == 0) { FUN_0001e0f8(k); continue; }
        }
        EX(k) = x;
        EY(k) = y;
    }
}

#undef FUN_000307e8
#undef EF
#undef EID
#undef EX
#undef EY
#undef ED
/* ---- from build/var/mod/parts/p30994.c */
extern void FUN_00030850(void); /* module prototype */
/* FUN_00030994 @ 00030994: toggle stepping mode */
extern void FUN_0002c21c(char *);
extern unsigned char DAT_0005c02f; extern int DAT_0005c658; extern short B000755d0_ao, B000755d4_ak; extern char *PTR_s_Stepping_Mode_On_0005d670, *PTR_s_Stepping_Mode_Off_0005d674;
void FUN_00030994(void)
{
    DAT_0005c02f ^= 1;
    if (DAT_0005c02f) {
        DAT_0005c658 = (((DAT_0005c658 / 45 + 1) % 8) / 2) * 90;
        B000755d0_ao = 0x8000;
        B000755d4_ak = 0x8000;
        FUN_00030850();
    }
    if (DAT_0005c02f) FUN_0002c21c(PTR_s_Stepping_Mode_On_0005d670);
    else FUN_0002c21c(PTR_s_Stepping_Mode_Off_0005d674);
}

/* ---- from build/var/mod/parts/p30a24.c */
/* MATCH (round 36, real 10.0a trace + DOSBox match.py alone and modmerge 0x307e8 19 -> 20/27): the cell sum assigned to type first and type reused for the t0 lookup, as the sibling FUN_000310b0 writes `id = o->x + W * o->y; id = t0[cell[id] & 0x3f];` (type's web then starts at the sum, which takes ECX); that left a pure pass-1 tie (abs temps t10/t11, t14/t15 and the setg index t27/dist at 46/48 savings) that a replay showed flips with one conflict node fewer; `snd += B000758bc_al;` before the first call (recipe 105, same add edi,[DAT]) is that node. */
/* Round 31 (real 10.0a, module m307e8 -oa, 48 compiles): a named cell variable placed before, between or after the two abs lines x both abs operand orders x four sum orders: best 3 lines (unchanged); the product still receives the sum. */
/* Round 29 (real 10.0a, module m307e8 -oa, 35 compiles): 3 lines; the sum takes the product's register (add edx,ebx) where the original adds the product into e[5]'s (movzx ecx,e[5]; add ecx,edx). Tried: 16 operand orders / pointer forms of the cell index, casts on e[5], on the product and on the index, (e[5] & 0xff), *(e + 5), the cell in a named variable (type, k, v, dist, vol, snd; 64-80 lines). The split oracle (docs/data/splitoracle.CODE2.csv) changes nothing. */
/* NEAR MISS (round 22): 6 lines in module 0x307e8 (was 10). First difference was the cell product: the original loads the map width first and multiplies into its register (`imul edx, ebx` with W in edx), i.e. `B00075618_b1.w * e[4]` (left operand W; with the LEV member the operand order of round 19 no longer gives it). Left (also tried c = e[5]; c += W * e[4]: 177 lines; the party y as the cast view ((short *)&B000755d4_ak)[1] as in FUN_0001083c/FUN_00019368: 8, with e[4] * W 12): the sum e[5] + product goes to the product's register (edx) here, to e[5]'s (ecx) in the original - a register choice of the sum temp; `W * e[4] + e[5]` is worse (8), the scalar short W (as in module 0x2af90) is worse (10). 3 real compiles. Round 27 (gate STRUCTURE, so no trace; 12 real in module): original block - edx=party x, eax=e[4]-x abs -> [esp]; same for y -> [esp+4] (eax stays live to the compare); edx=W, ebx=e[4], imul edx,ebx; ecx=e[5], add ecx,edx (sum in e[5]'s register, which then carries the t0 index and type). Tested: (unsigned)e[5], parenthesised product, the cell as a bit-field view .lo, *(B000698e0_b7 + ...): no change (6); the cell in a named variable (type, dist, k, v, vol, snd reused): the sum goes to ecx as in the original, but the abs operands and the d[] index swap registers (177, +4 bytes). Most likely untested cause: the abs() parts written differently so that the named cell variable keeps them (e.g. differences in variables before abs), or a cell helper the original expanded (-oe parameter copies). */
/* [2026-11-09: declaration order from an automatic sweep, 6 diff lines] */
/* NEAR MISS 284/284 with -oa, 4 instr: with "e[5] + e[4] * W" the product matches; left: e[5] is loaded into ebx (orig ecx, then add ecx,edx) and the d[] index byte goes through ebp (orig eax). Index local, casts, d[0] < d[1] do not change it */
/* FUN_00030a24 @ 00030a24: play entity e's ambient sound, its volume falling off with the distance to the party */
#include <stdlib.h>
#include "world.h"
extern void FUN_00038110(int, int, int, int), FUN_00038164(int, int, unsigned char);
extern short B000755d6_ae, B000755d2_ai, DAT_0005d7a0[]; extern unsigned short B000698e0_b7[]; extern int B000758bc_al;
void FUN_00030a24(unsigned char *e)
{
    int dist; int v; int d[2]; int type; int k; int vol; int snd;
    d[0] = abs(e[4] - B000755d6_ae);
    d[1] = abs(e[5] - B000755d2_ai);
    type = e[5] + B00075618_b1.w * e[4];
    type = B00075618_b1.t0[B000698e0_b7[type] & 0x3f];
    dist = d[d[1] > d[0]];
    v = 0x40 - dist * 8;
    vol = ((unsigned short)v * 0xff + 0x20) / 0x40;
    if (v > 0) {
        snd = 0xe;
        for (k = 0; k < 0x22; k++) if (DAT_0005d7a0[k * 2] == type) break;
        if (k != 0x22) snd = DAT_0005d7a0[k * 2 + 1];
        if ((e[6] == 0 || e[6] == 8) && e[7]) {
            snd += B000758bc_al;
            FUN_00038110(snd, vol, 0, dist);
        } else FUN_00038164(B000758bc_al + snd, 0, vol);
    }
}

/* ---- from build/var/mod/parts/p30b40.c */
/* FUN_00030b40 @ 00030b40: advance the animation counters of all map objects (-oa module; the object scans are goto loops, which stay top-tested) */
#include "world.h"
extern unsigned char DAT_0005cf50;  extern unsigned char *DAT_0005cd3c[];
void FUN_00030b40(void)
{
    int x2, x1, off;
    if (DAT_0005cf50) {
        for (x1 = 0; x1 < B00075618_b1.w; x1++) {
            if (DAT_0005cd3c[x1]) {
                off = 0;
            l1: if (DAT_0005cd3c[x1][off] != 0) {
                    unsigned char *p = DAT_0005cd3c[x1] + off;
                    if (p[7]) {
                        p[6] += p[7];
                        if (p[6] == 0 || p[6] == 8) { DAT_0005cf50--; p[7] = 0; }
                    }
                    off += 10;
                    goto l1;
                }
            }
        }
        if (DAT_0005cf50 == 0) {
            for (x2 = 0; x2 < B00075618_b1.w; x2++) {
                if (DAT_0005cd3c[x2]) {
                    off = 0;
                l2: if (DAT_0005cd3c[x2][off] != 0) {
                        unsigned char *p = DAT_0005cd3c[x2] + off;
                        if (p[6] != 8) p[6] = 0;
                        off += 10;
                        goto l2;
                    }
                }
            }
        }
    }
}

/* ---- from build/var/mod/parts/p30c0c.c */
extern void FUN_00030a24(unsigned char *e); /* module prototype */
/* FUN_00030c0c @ 00030c0c: start the open/close animation of a door object if the way is clear (2-bit mode bitfield compared as a byte; -oa) */
union FIX { int v; struct { short lo, hi; } h; };
extern int FUN_0003c800(unsigned, unsigned, int), FUN_0003c8e4(unsigned, unsigned, int), FUN_0003c9dc(unsigned, unsigned); 
extern unsigned char DAT_0005cf50;
struct DB { unsigned char mode:2, rest:6; };
int FUN_00030c0c(int x, int y, unsigned char *obj)
{
    union FIX b, a;
    if ((*(int *)(obj + 1) & 4) && !(*(int *)(obj + 1) & 0x40) && obj[7] == 0) {
        a.h.hi = y; a.h.lo = 0x8000;
        b.h.hi = x; b.h.lo = 0x8000;
        if (FUN_0003c800(a.v, b.v, -1) == 0) {
            if (FUN_0003c8e4(a.v, b.v, -1) == 0) {
                if (FUN_0003c9dc(a.v, b.v) == 0) {
                    if (((struct DB *)(obj + 1))->mode == 1) {
                        if (obj[6] == 0) obj[7] = 1;
                        else { obj[7] = 0xff; obj[6] = 8; }
                        DAT_0005cf50++;
                        FUN_00030a24(obj);
                        return 1;
                    }
                    if (((struct DB *)(obj + 1))->mode == 2) {
                        DAT_0005cf50++;
                        obj[7] = 0xff;
                        FUN_00030a24(obj);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/* ---- from build/var/mod/parts/p30cf4.c */
/* FUN_00030cf4 @ 00030cf4: is monster type k one of the undead kinds */
int FUN_00030cf4(int k)
{
    if (k == 0x6a) return 1;
    if (k == 0x90) return 1;
    if (k == 0x91) return 1;
    if (k == 0x95) return 1;
    if (k == 0x97) return 1;
    if (k == 0x9a) return 1;
    if (k == 0x9c) return 1;
    if (k == 0xa1) return 1;
    if (k == 0xa2) return 1;
    if (k == 0xa3) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p30d7c.c */
/* FUN_00030d7c @ 00030d7c: find the first party member holding a level-5 class */
extern unsigned short B000718f0_hO;
#define CB(off, o) (*(signed char *)((char *)&B000718f0_hO + (off) + (o)))
#define CW(off, o) (*(short *)((char *)&B000718f0_hO + (off) + (o)))
void FUN_00030d7c(int *w, int *lvl)
{
    int k; int *who = w; int off; int *l = lvl;
    for (k = 0, off = 0; off < 0x920; off += 0x248, k++) {
        if ((*(unsigned short *)((char *)&B000718f0_hO + off) & 0xf240) == 0) {
            if (CB(off, 5) == 5) { *who = k; *l = CW(off, 0x10); return; }
            if (CB(off, 6) == 5) { *who = k; *l = CW(off, 0x12); return; }
            if (CB(off, 7) == 5) { *who = k; *l = CW(off, 0x14); return; }
        }
    }
    *who = -1;
    *l = -1;
}

#undef CB
#undef CW
/* ---- from build/var/mod/parts/p30e08.c */
extern int FUN_00030cf4(int k); /* module prototype */
extern void FUN_00030d7c(int *w, int *lvl); /* module prototype */
/* MATCH (round 47, module 0x307e8 -oa): (1) the thieves-tools branch is one if / else-if nest that falls to a single `return 1;` (no return after each DAT_0005bf44 store, no goto r3f): the compiler duplicates the short return tail itself, and `mov eax,1` then comes from the join block, so it stays behind the `add esp,8` of the FUN_0002a344 call as in the original (written in each arm it was scheduled ahead of it); (2) declaration order `k, pick, r, skill` re-climbed for that form (all 24 orders: x in edi, y in its slot); (3) `== 0x32U` reloads the held item for the != -1 test (recipe 82, TODO types). Earlier notes: rounds 23 / 41. */
/* FUN_00030e08 @ 00030e08: click (x, y) on locked object obj of entity e: inside its lock area, pick the lock (thieves' tools, item 0x32) or try the held key; 1 when handled */
#include "dice.h"
 extern int FUN_0001f390(short, short); extern void FUN_0002a344(short, unsigned char), FUN_00038110(int, int, int, int), FUN_000102a8(int);
extern short DAT_00058600, DAT_0005d828[]; extern int DAT_0005bf44, B000758bc_al;
int FUN_00030e08(int x, int y, int obj, unsigned char *e)
{
    int k, pick, r, skill;
    if (!(*(int *)e & 0x400)) goto fail;
    if (obj == 0x15b) {
        if (x < 0x12 || x > 0x33 || y < 0x15) goto fail;
        if (y <= 0x29) goto use;
        goto fail;
    } else if (obj == 0x182) {
        if (x < 0x26 || x > 0x42 || y < 0x17) goto fail;
        if (y <= 0x29) goto use;
        return 0;
    } else if (obj == 0x18b) {
        if (x < 0x1c || x > 0x35 || y < 0x19) goto fail;
        if (y <= 0x29) goto use;
        return 0;
    } else {
        for (k = 0; DAT_0005d828[k] != -1; k++) {
            if (DAT_0005d828[k] == obj) {
                if (x < 0x1d || x > 0x35 || y < 0x1d) goto fail;
                if (y > 0x28) return 0;
                break;
            }
        }
        if (DAT_0005d828[k] == -1) goto fail;
    }
use:
    if (DAT_00058600 == 0x32U) { /* TODO types: the unsigned constant (another CONVERT than the != -1 test's) keeps the original's reload of the held item, recipe 82 */
        if (FUN_00030cf4(e[6])) {
            FUN_00030d7c(&pick, &skill);
            if (pick != -1) {
                r = FUN_0002c328(1, 0x14, 0, 0);
                skill += 3;
                if (r != 0x14 && r >= skill) {
                    FUN_00038110(B000758bc_al + 6, 0xff, 1, 2);
                    FUN_000102a8((signed char)e[2]);
                    e[1] &= 0xfb;
                } else if (FUN_0002c328(1, 0x14, 0, 0) <= 2) {
                    FUN_0002a344(-1, 0);
                    DAT_0005bf44 = 0x41;
                } else DAT_0005bf44 = 0x40;
            } else if (FUN_0002c328(1, 0x14, 0, 0) <= 2) {
                FUN_0002a344(-1, 0);
                DAT_0005bf44 = 0x41;
            } else DAT_0005bf44 = 0x40;
        } else DAT_0005bf44 = 0x3f;
        return 1;
    }
    if (DAT_00058600 != -1) {
        if (FUN_0001f390(DAT_00058600, e[6])) {
            FUN_00038110(B000758bc_al + 6, 0xff, 1, 2);
            FUN_000102a8((signed char)e[2]);
            e[1] &= 0xfb;
        } else {
            DAT_0005bf44 = 0x3e;
        }
    }
    return 1;
fail:
    return 0;
}

/* ---- from build/var/mod/parts/p310b0.c */
/* FUN_000310b0 @ 000310b0: use a key/lever object on the door in front: toggles its state and plays the sound */
#include "world.h"
struct OBJ { unsigned char b0; unsigned char dir : 2, flag4 : 1, rest : 5; signed char snd; unsigned char b3, y, x; };
extern void FUN_00038110(int, int, int, int), FUN_000102a8(int);
extern unsigned short DAT_0005d734; extern unsigned char DAT_0005d737, DAT_0005d739, DAT_0005d736, DAT_0005d738; extern short DAT_0005d858, DAT_0005d85a; extern unsigned short B000698e0_b7[]; extern int B000758bc_al;
int FUN_000310b0(int a, int b, unsigned c, struct OBJ *o)
{
    int k; int off; int j; int v; int id; int idx; unsigned t;
    if (!o->flag4) goto fail;
    for (k = 0, off = 0; (t = *(unsigned short *)((char *)&DAT_0005d734 + off)) != 0xffffffff; off += 6, k++) {
        if (c == t || c == t + 1) {
            idx = k * 6;
            if (a < (&DAT_0005d737)[idx]) goto fail;
            if ((&DAT_0005d739)[idx] < a) goto fail;
            if (b < (&DAT_0005d736)[idx]) goto fail;
            if ((&DAT_0005d738)[idx] >= b) break;
            goto fail;
        }
    }
    if (*(unsigned short *)((char *)&DAT_0005d734 + k * 6) == 0xffffffff) goto fail;
    id = o->x + B00075618_b1.w * o->y;
    id = B00075618_b1.t0[B000698e0_b7[id] & 0x3f];
    v = 3;
    for (j = 0, off = 0; off < 0x44; j++, off += 4) {
        if (*(short *)((char *)&DAT_0005d858 + off) == id) break;
    }
    if (j != 0x11) v = *(short *)((char *)&DAT_0005d85a + j * 4);
    o->dir ^= 1;
    FUN_00038110(v + B000758bc_al, 0xff, 1, 2);
    FUN_000102a8(o->snd);
    return 1;
fail:
    return 0;
}

/* ---- from build/var/mod/parts/p311d8.c */
/* FUN_000311d8 @ 000311d8: drop the held item on party member m: into an open bag, into a quiver/holder in either hand, else into the first free pack slot (or complain); a plain click opens the sheet */
/* r69bp: module 0x307e8 -oa set (-3s -ox -oe -oa -ot -w0). Under -oa every scalar global is a zero-savings memory node
   in the pass-1 list; the four this function reads (the item-table pointer, the held item id / flags, the message pointer)
   are read as record members, so the list is the one of the plain compile, which gives the original registers. */
#include "world.h"
struct IP { unsigned char *p; };
#define ITEMP (((struct IP *)((char *)&B00075618_b1 - 0x40))->p) /* STANDIN: the item-table pointer B000755d8_aw read through the level record B00075618_b1 (0x75618 - 0x40 = 0x755d8, same address and bytes): a record access is no -oa memory node, and the module keeps world.h's one declaration of B000755d8_aw */
#include "records.h"
#define B000718f0_hO ((char *)&B000718f0_hO)
#define FUN_0002a344 ((void (*)(int, unsigned char))FUN_0002a344)
extern struct CURSOR DAT_000585fc; /* STANDIN: held item DAT_00058600 / DAT_00058602 as CURSOR members .id / .f - removes two -oa memory nodes */
#pragma pack(1)
struct BAG { unsigned char n, b1, b2, b3, kind; short *slots; char pad; };
#pragma pack()
extern void FUN_00033438(int, int, int), FUN_0001f290(int, int, int), FUN_0002c21c(char *), FUN_00023118(void);
extern unsigned char DAT_0005d681[];
extern struct BAG DAT_00057330[];
struct FL { unsigned short x : 15, busy : 1; };
extern unsigned char B000718e0_iO[];
#define B00071946_l7 ((char *)((char *)&B000718e0_iO + 102)) /* STANDIN: view, B000718e0_iO + 0x66 */
#define B0007193c_aB ((char *)((char *)&B000718e0_iO + 92)) /* STANDIN: view, B000718e0_iO + 0x5c */
#define B0007193e_bP ((char *)((char *)&B000718e0_iO + 94)) /* STANDIN: view, B000718e0_iO + 0x5e */
#define B00071920_bM ((char *)((char *)&B000718e0_iO + 64)) /* STANDIN: view, B000718e0_iO + 0x40 */

struct MSGQ { char *s; int q; }; extern struct MSGQ PTR_s_NOT_ENOUGH_SPACE_IN_INVENTORY_0005d678; /* STANDIN: message pointer as a record member - removes its -oa memory node */
#define RS(f) (*(short *)((f) + m * 0x248))
#define ITEM(i, o) ITEMP[(i) * 0x41 + (o)]
void FUN_000311d8(int m, int a, int b, int flags)
{
    int e, k, v, it, ok, slot;
    struct BAG *pk;
    if (DAT_0005d681[m / 2]) {
        FUN_00033438(m / 2, a, b);
        return;
    }
    if (flags & 8) {
        it = DAT_000585fc.id;
        if (it == -1) return;
        ok = 1;
        if (ITEM(it, 0x2f) == 0xf) {
            e = RS(B00071946_l7);
            if (e != -1) {
                pk = &DAT_00057330[(signed char)ITEM(e, 0x31)];
                for (k = 0; k < pk->n; k++) {
                    v = pk->slots[k];
                    if (v == -1) {
                        pk->slots[k] = DAT_000585fc.id;
                        FUN_0001f290((signed char)ITEM(RS(B00071946_l7), 0x31), k, DAT_000585fc.f);
                        FUN_0002a344(v, 0);
                        ok = 0;
                        break;
                    }
                }
            }
        } else if (ITEM(it, 0x2f) == 0xd) {
            slot = -1;
            e = RS(B0007193c_aB);
            if (e != -1) {
                if (ITEM(e, 0x2f) == 1 && DAT_00057330[(signed char)ITEM(e, 0x31)].kind == 3) slot = 0;
                else e = -1;
            }
            if (e == -1) {
                e = RS(B0007193e_bP);
                if (e != -1) {
                    if (ITEM(e, 0x2f) == 1 && DAT_00057330[(signed char)ITEM(e, 0x31)].kind == 3) slot = 1;
                    else e = -1;
                }
            }
            if (e != -1) {
                pk = &DAT_00057330[(signed char)ITEM(*(short *)(B0007193c_aB + slot * 2 + m * 0x248), 0x31)];
                for (k = 0; k < pk->n; k++) {
                    v = pk->slots[k];
                    if (v == -1) {
                        pk->slots[k] = DAT_000585fc.id;
                        FUN_0001f290((signed char)ITEM(*(short *)(B0007193c_aB + slot * 2 + m * 0x248), 0x31), k, DAT_000585fc.f);
                        FUN_0002a344(v, 0);
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            for (k = 0; k < 12; k++)
                if (*(short *)(B00071920_bM + m * 0x248 + k * 2) == -1) {
                    *(short *)(B00071920_bM + m * 0x248 + k * 2) = DAT_000585fc.id;
                    FUN_0002a344(-1, 0);
                    break;
                }
            if (k == 12) FUN_0002c21c(PTR_s_NOT_ENOUGH_SPACE_IN_INVENTORY_0005d678.s);
        }
    } else if (flags & 1) {
        if (!(*(unsigned short *)(B000718f0_hO + m * 0x248) & 0x8000)) FUN_00023118();
    }
}

#undef B000718f0_hO
#undef FUN_0002a344
#undef ITEMP
#undef RS
#undef ITEM
#pragma pack()
/* ---- from build/var/mod/parts/p314b8.c */
/* FUN_000314b8: click on hand slot s of party member m: put the held item into the hand (shield / weapon icons redrawn, the ammunition readout of the second hand updated), or use the item in the hand */
/* r69bp: module 0x307e8 -oa set (-3s -ox -oe -oa -ot -w0): the held item and the item-table pointer read as record members
   (no -oa memory nodes), so the pass-1 list is the plain one, where the tt stand-in already gives the original registers. */
extern void FUN_000391b0(unsigned char), FUN_0001f238(int, int, int), FUN_0002ea90(int, int, int);
extern void FUN_0002a8c8(int, int, int, int, int), FUN_00036018(int, int, int);
extern unsigned char FUN_0001f218(int, int);
extern int FUN_00034478(int, int);
#define B00071a7e_dD ((char *)((char *)&B000718e0_iO + 414)) /* STANDIN: view, B000718e0_iO + 0x19e */

#include "records.h"
extern struct CURSOR DAT_000585fc; /* STANDIN: held item DAT_00058600 / DAT_00058602 as CURSOR members .id / .f - removes two -oa memory nodes */
extern int DAT_0005c050;
#include "world.h"
#define B000718f0_hO ((char *)&B000718f0_hO)
#define FUN_0002a344 ((void (*)(short, int))FUN_0002a344)
/* struct IP: defined above */
#define ITEMP (((struct IP *)((char *)&B00075618_b1 - 0x40))->p) /* STANDIN: the item-table pointer B000755d8_aw read through the level record B00075618_b1 (0x75618 - 0x40 = 0x755d8, same address and bytes): a record access is no -oa memory node, and the module keeps world.h's one declaration of B000755d8_aw */
extern signed char DAT_00056fa0[];

#define FL(m) (*(unsigned short *)(B000718f0_hO + (m) * 0x248))
#define HAND(m, s) (*(short *)(B0007193c_aB + (m) * 0x248 + (s) * 2))
#define ITEM(i, o) ITEMP[(i) * 0x41 + (o)]
void FUN_000314b8(int m, int s, int flags)
{
    int x, cls, id; unsigned it; int n, f, k;
    int tt; /* STANDIN: named temp for x (declared last: lowest local id) */
    if (FL(m) & 0x8000) return;
    if (flags & 8) {
        tt = m % 2 * 0x35 + 4 + m / 2 * 0xd3; /* STANDIN: x copied through tt: extra node, the (signed char)ITEM(n, 0x31) * 10 temp sorts ahead of the idiv EDX temp and takes ECX */
        x = tt;
        it = HAND(m, s);
        if (it >= 0x7e && it <= 0x86) return;
        n = DAT_000585fc.id;
        f = DAT_000585fc.f;
        cls = ITEM(n, 0x2f);
        if (cls == 3 || cls == 4 || cls == 8 || cls == 6 || cls == 7 || cls == 5) return;
        FUN_000391b0(DAT_0005c050);
        k = s + 0xe;
        FUN_0002a344(it, FUN_0001f218(m, k));
        HAND(m, s) = n;
        FUN_0001f238(m, k, f);
        *(int *)(B00071a7e_dD + m * 0x248 + s * 4) = 0;
        FUN_0002ea90(m, s, -1);
        FUN_0002ea90(m, s ^ 1, -1);
        FUN_0002a8c8(DAT_0005c050, 0x113, x, 0x7d, 0x35);
        FUN_0002a8c8(DAT_0005c050, 0x113, x + 0x21, 0x7d, 0x35);
        if (s == 1) {
            if (DAT_00056fa0[m * 4] != -1) {
                DAT_00056fa0[m * 4] = -1;
                DAT_00056fa0[m * 4 + 1] = -1;
                DAT_00056fa0[m * 4 + 2] = -1;
                DAT_00056fa0[m * 4 + 3] = -1;
            }
            if (ITEM(n, 0x2f) == 1) {
                id = (signed char)ITEM(n, 0x31);
                DAT_00056fa0[m * 4] = DAT_00057334[id * 10];
                DAT_00056fa0[m * 4 + 1] = ITEM(n, 0x31);
                DAT_00056fa0[m * 4 + 2] = 3;
                DAT_00056fa0[m * 4 + 3] = n;
            }
        }
    } else if (flags & 1) {
        if (!(FL(m) & 0xf240) && FUN_00034478(m, s)) FUN_00036018(m, s, -1);
    }
}

#undef B000718f0_hO
#undef FUN_0002a344
#undef ITEMP
#undef FL
#undef HAND
#undef ITEM
/* ---- from build/var/mod/parts/p31704.c */
/* FUN_00031704 @ 00031704: remove map object i from the object list and refresh the cursor state for the spot under the mouse (the count DAT_000758a4 is struct LCNT's n4, recipe 27: under the module's -oa the plain short shared a register with the held-item tests) */
 
#include "world.h"
struct OBJ2 { char pad[0xe]; short f; char pad2[4]; unsigned short b0 : 10, b10 : 1, rest : 5; };
void *memmove(void *, const void *, unsigned);
extern void FUN_0002a344(short, unsigned char); extern int FUN_0001f4b0(short), FUN_0001f2b4(int), FUN_0002c1dc(int);
extern struct OBJ2 B00067618_e7[]; extern short DAT_00058600; extern int DAT_0005bf44;
void FUN_00031704(int i)
{
    FUN_0002a344(B00067618_e7[i].f, B00067618_e7[i].b10);
    memmove(&B00067618_e7[i], &B00067618_e7[i + 1], (B00075618_b1.n4 - 1 - i) * 0x16);
    B00075618_b1.n4--;
    if (DAT_00058600 >= 0x61 && DAT_00058600 <= 0x64 && FUN_0001f4b0(0x35)) DAT_0005bf44 = 0xf;
    if (DAT_00058600 == 0x49) DAT_0005bf44 = 0x25;
    if (DAT_00058600 == 0x9e) DAT_0005bf44 = 0x36;
    if (DAT_00058600 == 0x5f) DAT_0005bf44 = 0x37;
    if (DAT_00058600 == 0x8b) DAT_0005bf44 = 0x38;
    if (FUN_0001f2b4(DAT_00058600) && DAT_00058600 != 0x5f) DAT_0005bf44 = 0x39;
    if (DAT_00058600 >= 0xa7 && DAT_00058600 <= 0xc9) DAT_0005bf44 = 0x3a;
    if (DAT_00058600 == 0x77) DAT_0005bf44 = 0x3c;
    if (DAT_00058600 == 0x75) DAT_0005bf44 = 0x29;
    if (DAT_00058600 == 0x74 && FUN_0002c1dc(0x51)) DAT_0005bf44 = 0x2f;
}

/* ---- from build/var/mod/parts/p31880.c */
#define OBJ T13_OBJ
extern void FUN_0003df2c(int, int, int, int);


/* FUN_00031880: in area 16, once all four marker objects (type 0x89) stand on their four cells, solve the puzzle */
#include "world.h"
#define M00067618_e7 ((struct OBJ *)B00067618_e7)
void *memset(void *, int, unsigned);
extern int FUN_0002c1dc(int);
extern void FUN_0002c124(int), FUN_00023ef8(int), FUN_00025050(int);
extern int DAT_0005c6c8;
struct OBJ { unsigned short yf; short y; unsigned short xf; short x; unsigned char p8[6]; unsigned short type; unsigned char p10[6]; };

void FUN_00031880(void)
{
    unsigned char cell[8] = { 13, 19, 11, 21, 13, 23, 15, 21 };
    int found[4];
    int i, k;
    if (DAT_0005c6c8 != 16) return;
    if (FUN_0002c1dc(0x44)) return;
    memset(found, 0, sizeof(found));
    for (i = 0; i < B00075618_b1.n4; i++) {
        if (M00067618_e7[i].type == 0x89) {
            for (k = 0; k < 4; k++) {
                if (M00067618_e7[i].x == cell[k * 2] && M00067618_e7[i].y == cell[k * 2 + 1]) {
                    found[k] = 1;
                    break;
                }
            }
        }
    }
    if (found[0] && found[1] && found[2] && found[3]) {
        FUN_0002c124(0x44);
        FUN_00023ef8(8);
        FUN_00025050(0x73);
    }
}

#undef M00067618_e7
#undef OBJ
/* ---- from build/var/mod/parts/p3195c.c */
extern void FUN_00031880(void); /* module prototype */
/* FUN_0003195c @ 0003195c: drop object type t at position (px, py) (thrown along the view from screen column sx when thrown), append it to the floor-object list (oldest dropped when full) */
/* In module 0x307e8 (-ox -oe -oa -ot, 2026-11-10): matches only without -oa. Under -oa the two cell products
   B00075618_b1.w * y take the other operand order (first: y loaded into eax, width into edx; second: the product in
   eax instead of ebx, x added into ebx). Q1 no clobber; Q2 equal; Q3 operand order of a commutative multiply, which
   under -oa depends on the conflict list (the width is a plain global); Q4 -. Tried (with the count as LCNT.n4):
   swapping the first product's operands (fixes the first site), x + W * y, x + y * W, y * W + x at the second
   site (the product stays in eax); 6 experiments. Blocked. */
#include "world.h"
#define M00067618_e7 ((char *)B00067618_e7)
#define FUN_0003df2c ((void (*)(int *, int *, int, int))FUN_0003df2c)
void *memmove(void *, const void *, unsigned);
extern void FUN_0002a344(short, unsigned char); extern short FUN_0003d5d0(int, int, int);
extern int DAT_0005c658; extern unsigned char DAT_0005c02f; 

struct FB { unsigned short lo : 3, z : 6, keep : 1, flag : 1, hi : 5; };
/* Round 18: inside module 0x307e8 (-oa) this file matches with the two cell sums written `((short *)pos)[3] * B00075618_b1.w +
   ((short *)pos)[1]` (first) and `((short *)pos)[1] + ((short *)pos)[3] * B00075618_b1.w` (second); alone (default flags) only the orders
   below match. Apply the swap when the module is promoted.
   Round 29 (real 10.0a, all 16 operand-order combinations of the two sites in build/var/mod/m307e8.c, then DOSBox
   match.py on that text): in the current module text (world.h declarations) the in-module form is
   first `cell = ((short *)pos)[3] * B00075618_b1.w + ((short *)pos)[1];`, second
   `cell = B00075618_b1.w * ((short *)pos)[3] + ((short *)pos)[1];` (the two forms below exchanged): MATCH under
   -ox -oe -oa -ot (also `x + y * W` first); the round-18 forms give 3 lines now. Alone under plain -ox this form fails,
   so the file keeps the alone form until module 0x307e8 is turned into a module file or promoted. */
void FUN_0003195c(int sx, int t, int flag, int px, int py, int thrown, int redraw)
{
    int a, pos[2], cell, n, o;
    if (thrown) {
        a = DAT_0005c658 - (sx - 0xa0) / 3;
        if (a < 0) a += 0x168;
        if (a >= 0x168) a -= 0x168;
        FUN_0003df2c(&pos[0], &pos[1], 0x18000, a);
        pos[1] += py;
        pos[0] += px;
    } else {
        pos[1] = py;
        pos[0] = px;
    }
    if (DAT_0005c02f) {
        *(short *)&pos[1] = 0x8000;
        *(short *)&pos[0] = 0x8000;
    }
    cell = ((short *)pos)[3] * B00075618_b1.w + ((short *)pos)[1];
    if (FUN_0003d5d0(pos[1], pos[0], 0x190) == 0) {
        pos[1] = py;
        pos[0] = px;
        cell = ((short *)pos)[3] * B00075618_b1.w + ((short *)pos)[1];
    }
    n = B00075618_b1.n4;
    if (n == 300) {
        memmove(M00067618_e7, M00067618_e7 + 0x16, 0x19b2);
        n = 299;
    }
    o = n * 0x16;
    *(short *)(M00067618_e7 + o + 0xe) = t;
    *(int *)(M00067618_e7 + o) = pos[1];
    *(int *)(M00067618_e7 + o + 4) = pos[0];
    *(short *)(M00067618_e7 + o + 0xc) = cell;
    ((struct FB *)(M00067618_e7 + o + 0x14))->z = 0;
    ((struct FB *)(M00067618_e7 + o + 0x14))->flag = flag;
    B00075618_b1.n4++;
    if (redraw) FUN_0002a344(-1, 0);
    if (t == 0x89) FUN_00031880();
}

#undef M00067618_e7
#undef FUN_0003df2c
/* ---- from build/var/mod/parts/p31adc.c */
/* FUN_00031adc @ 00031adc */
struct R22 { unsigned char flags; char pad[2]; unsigned short type; char pad2[17]; };
#define B00064d8b_a7 (*(struct R22 (*)[])((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */

extern int FUN_0003ad18(int); extern void FUN_00026524(int);
int FUN_00031adc(int i, int c)
{
    if (c == 0 && FUN_0003ad18(B00064d8b_a7[i].type)) {
        if (B00064d8b_a7[i].type == 0x52) FUN_00026524(0x25);
        else FUN_00026524(B00064d8b_a7[i].type - 0x22);
        return 1;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p31b44.c */
/* FUN_00031b44 @ 00031b44: on first sight (t == 0) of a talking monster e, say its greeting line; 1 when one was said */
extern int FUN_0003ade0(int); extern void FUN_0002cd48(int, int, int, int, int, int, int, int, int);
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */

int FUN_00031b44(int e, int t)
{
    int r = 0;
    if (t == 0 && FUN_0003ade0(*(unsigned short *)((char *)&B00064d8e_a6 + e * 0x16))) {
        switch (*(unsigned short *)((char *)&B00064d8e_a6 + e * 0x16)) {
        case 0x48: r = 1; FUN_0002cd48(-1, 0x21, 0x34, -1, -1, -1, -1, -1, -1); break;
        case 0x49: r = 1; FUN_0002cd48(-1, 0x21, 0x33, -1, -1, -1, -1, -1, -1); break;
        case 0x4a: r = 1; FUN_0002cd48(-1, 0x21, 0x31, -1, -1, -1, -1, -1, -1); break;
        case 0x4d: r = 1; FUN_0002cd48(-1, 0x21, 0x32, -1, -1, -1, -1, -1, -1); break;
        case 0x4f: r = 1; FUN_0002cd48(-1, 0x21, 0x35, -1, -1, -1, -1, -1, -1); break;
        }
    }
    return r;
}

/* ---- from build/var/mod/parts/p31bf0.c */
/* FUN_00031bf0: scale sprite e (image img, depth from dist) and set its screen box; returns 1 when drawn (lv >= min) */
struct SP { unsigned short x, dist, img; short idx, kind, fa, f0c, f0e, f10, f12, f14; };
extern short *FUN_0003f29c(int, int);
int FUN_00031bf0(struct SP *e, int min)
{
    int oy, cx, q, tt, img, sc, ht, lv, w, base, r, ox, x; /* STANDIN: declaration order (tt placed for the rough / slot sort) */
    short *h;
    lv = (e->dist - 32000) >> 3;
    img = e->img;
    x = e->x;
    if (lv >= min) {
        r = 1;
        h = FUN_0003f29c(img, 3) + 1;
        cx = h[0] / 2;
        tt = h[2] - h[1]; /* STANDIN: w copied through the named temp tt: an in-block node of the h block (EDX for the cx product) */
        w = tt;
        ox = h[1];
        oy = h[3];
        ht = h[4] - h[3];
        q = lv / 4;
        lv -= lv / 8;
        sc = lv * 4;
        if (sc == 0) sc = 4;
        oy = ((unsigned short)oy * sc + 0x40) / 0x80;
        ox = ((unsigned short)ox * sc + 0x40) / 0x80;
        ht = ((unsigned short)ht * sc + 0x40) / 0x80;
        w = ((unsigned short)w * sc + 0x40) / 0x80;
        cx = ((unsigned short)cx * sc + 0x40) / 0x80;
        ox = x - (cx - ox);
        base = q + 4 + (0x100 - lv * 4) / 2;
        oy += lv * 4 / 8 + base;
        if (ht + oy > 0x104) ht = 0x104 - oy;
        e->f12 = ox;
        e->f10 = ht + oy;
        e->f0e = oy;
        e->f14 = ox + w;
    } else r = 0;
    return r;
}

/* ---- from build/var/mod/parts/p31db4.c */
extern void FUN_00032d70(void); /* module prototype */
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)
/* (FUN_00032d70, expanded in line here, is defined in this module) */
/* The copy of FUN_00032d70 after the function is the module's own definition (src/CODE2/f32ce0.c): the original expands it in line here (-oe), which needs both in one compile; it goes away when module 0x307e8 becomes one module file. */
/* FUN_00031db4 @ 00031db4: show picture id centred on screen (picture 4 gets its caption), wait for a click or key */
 extern void FUN_000391b0(unsigned char), FUN_0003e4f4(int, int, unsigned char *), FUN_0002c368(unsigned char *, int);
extern int FUN_00023fd4(int, int, int, int, int, unsigned char *, int); extern void FUN_0002ea04(void), FUN_0002a510(int), FUN_0002a5b0(int, int, int);
extern int FUN_0002a1f4(void), FUN_00040b40(void); 
extern unsigned char DAT_0005d680, DAT_0005759c[], DAT_00058602, DAT_0005cf4a; extern int DAT_0005c050; extern short DAT_00058600, DAT_0005a6ba;
void FUN_00031db4(int id)
{
    unsigned char *img; int old, h, w, x, y;
    old = DAT_0005d680;
    DAT_0005d680 = 2;
    img = FUN_0003f29c(id, 9);
    h = img[6] * 8;
    w = *(unsigned short *)(img + 2) * *(unsigned short *)(img + 4);
    x = 0x84 - w / 2;
    y = 0xa0 - h / 2;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    FUN_000391b0(DAT_0005c050);
    FUN_0003e4f4(x, y, img);
    if (id == 4) {
        FUN_0002c368(DAT_0005759c, 0x36f);
        FUN_00023fd4(0, 0x20, 0x40, 0x12, 0xc0, DAT_0005759c, 2);
    }
    if (w == 0x100 && h == 0x100) FUN_0002ea04();
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    while (FUN_0002a1f4()) ;
    while (!FUN_0002a1f4() && !FUN_00040b40()) ;
    while (FUN_0002a1f4() || FUN_00040b40()) ;
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    FUN_00032d70();
    DAT_0005c050 ^= 1;
    DAT_0005d680 = old;
}

#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p31f1c.c */
extern void FUN_00031db4(int id); /* module prototype */
/* FUN_00031f1c @ 00031f1c */
 extern void FUN_0002c124(int);
void FUN_00031f1c(int k)
{
    if (k == 0x52) FUN_00031db4(1);
    if (k == 0x71) FUN_00031db4(2);
    if (k == 0x6e) { FUN_00031db4(8); FUN_0002c124(0x53); }
    if (k == 0x91) FUN_00031db4(9);
}

/* ---- from build/var/mod/parts/p31f70.c */
#define FUN_00038110 ((void (*)(char *, int, int, int))FUN_00038110)
/* FUN_00031f70: end-game walk: turn the party to face the exit and step to row 0x17 / column 7, turn again, play the closing animation and scroll the final text */
extern void FUN_00029ccc(int), FUN_0002f1c8(void), FUN_0002ea78(void), FUN_0002cd48(int, int, int, int, int, int, int, int, int), FUN_00041f94(void);
extern void FUN_000380e8(void), FUN_0003e608(void), FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0002ea04(void), FUN_00038168(void), FUN_0003e614(unsigned, int), FUN_000281b4(int), FUN_0001f540(int), FUN_00029cf4(void);
extern int DAT_0005c658;
extern int DAT_0005bf30;
extern short B000755d2_ai, B000755d6_ae;

extern unsigned DAT_0005cf4c;


extern char *B000758d0_jK, *B000758dc_cl;
void FUN_00031f70(void)
{
    int i;
    FUN_00029ccc(0);
    FUN_0002f1c8();
    FUN_0002ea78();
    DAT_0005bf30 = 1;
    if (B000755d2_ai > 0x17) {
        for (;;) {
            if (DAT_0005c658 == 0x5a) break;
            if (DAT_0005c658 >= 0x55 && DAT_0005c658 <= 0x5f) DAT_0005c658 = 0x5a;
            else {
                if (DAT_0005c658 > 0x5a && DAT_0005c658 < 0x10e) {
                    if (DAT_0005c658 < 0x5a) DAT_0005c658 = 0x5f;
                    else DAT_0005c658 -= 10;
                } else {
                    if (DAT_0005c658 > 0x50) DAT_0005c658 = 0x5a;
                    else DAT_0005c658 += 10;
                    if (DAT_0005c658 >= 0x168) DAT_0005c658 -= 0x168;
                }
            }
            FUN_0002f1c8();
            FUN_0002ea78();
        }
        B000755d0_ao = 0x8000;
        while (B000755d2_ai != 0x17) {
            B000755d2_ai--;
            FUN_0002f1c8();
            FUN_0002ea78();
        }
    } else {
        for (;;) {
            if (DAT_0005c658 == 0x10e) break;
            if (DAT_0005c658 >= 0x109 && DAT_0005c658 <= 0x113) DAT_0005c658 = 0x10e;
            else {
                if (DAT_0005c658 > 0x10e || DAT_0005c658 < 0x5a) {
                    if (DAT_0005c658 < 0x10e) DAT_0005c658 = 0x113;
                    else DAT_0005c658 -= 10;
                    if (DAT_0005c658 < 0) DAT_0005c658 += 0x168;
                } else {
                    if (DAT_0005c658 > 0x109) DAT_0005c658 = 0x113;
                    else DAT_0005c658 += 10;
                }
            }
            FUN_0002f1c8();
            FUN_0002ea78();
        }
        B000755d0_ao = 0x8000;
        while (B000755d2_ai != 0x17) {
            B000755d2_ai++;
            FUN_0002f1c8();
            FUN_0002ea78();
        }
    }
    if (B000755d6_ae > 7) {
        for (;;) {
            if (DAT_0005c658 == 0xb4) break;
            if (DAT_0005c658 >= 0xaf && DAT_0005c658 <= 0xb9) DAT_0005c658 = 0xb4;
            else if (DAT_0005c658 > 0xb4) {
                if (DAT_0005c658 < 0xb4) DAT_0005c658 = 0xb9;
                else DAT_0005c658 -= 10;
            } else if (DAT_0005c658 > 0xaa) DAT_0005c658 = 0xb4;
            else {
                DAT_0005c658 += 10;
            }
            FUN_0002f1c8();
            FUN_0002ea78();
        }
        B000755d4_ak = 0x8000;
        while (B000755d6_ae != 7) {
            B000755d6_ae--;
            FUN_0002f1c8();
            FUN_0002ea78();
        }
    } else {
        for (;;) {
            if (DAT_0005c658 == 0) break;
            if (DAT_0005c658 >= 5 && DAT_0005c658 <= 0x163) {
                if (DAT_0005c658 > 0) {
                    if (DAT_0005c658 < 10) goto snap0;
                    DAT_0005c658 -= 10;
                } else {
                    if (DAT_0005c658 > 0x159) DAT_0005c658 = 0;
                    else DAT_0005c658 += 10;
                    if (DAT_0005c658 >= 0x168) goto snap0;
                }
            } else {
            snap0:
                DAT_0005c658 = 0;
            }
            FUN_0002f1c8();
            FUN_0002ea78();
        }
        B000755d4_ak = 0x8000;
        while (B000755d6_ae != 7) {
            B000755d6_ae++;
            FUN_0002f1c8();
            FUN_0002ea78();
        }
    }
    for (;;) {
        if (DAT_0005c658 == 0xd5) break;
        if (DAT_0005c658 < 0xd2 || DAT_0005c658 > 0xdc) {
            if (DAT_0005c658 >= 0xb4 && DAT_0005c658 < 0xd5) {
                DAT_0005c658 += 10;
                if (DAT_0005c658 < 0xd2) goto next;
            } else {
                DAT_0005c658 -= 10;
                if (DAT_0005c658 < 0) DAT_0005c658 += 0x168;
                if (DAT_0005c658 > 0xdc) goto next;
            }
        }
        DAT_0005c658 = 0xd5;
    next:
        FUN_0002f1c8();
        FUN_0002ea78();
    }
    FUN_0002cd48(2, 0x21, 7, -1, -1, -1, -1, -1, -1);
    while (DAT_0005cf4c >> 16 != 2) {
        DAT_0005cf4e++;
        FUN_00041f94();
        FUN_0002f1c8();
        FUN_0002ea78();
    }
    for (i = 0; i < 0x16; i++) {
        if (!FUN_000380e8) FUN_00038110(B000758d0_jK + 5, 0xff, 0, 1);
        FUN_0003e608();
        FUN_000391b0(((unsigned char)DAT_0005c050));
        FUN_0003e510(4, 0x20, (int)(B000758dc_cl + 0x67 + i), 0);
        FUN_0002ea04();
        FUN_0002ea78();
        FUN_00038168();
        FUN_0003e614(9, 0);
        if (i == 0x14) {
            B000755d2_ai = 9;
            B000755d6_ae = 0x3a;
            DAT_0005c658 = 0xb4;
            B000755d4_ak = 0x8000;
            B000755d0_ao = 0x8000;
            FUN_000281b4(0x17);
        }
    }
    FUN_0001f540(0x87);
    FUN_0001f540(0x88);
    FUN_0001f540(0x74);
    FUN_00029cf4();
    DAT_0005bf30 = 0;
}

#undef FUN_00038110
/* ---- from build/var/mod/parts/p323f4.c */
extern void FUN_00031704(int i); /* module prototype */
extern int FUN_00031adc(int i, int c); /* module prototype */
extern int FUN_00031b44(int e, int t); /* module prototype */
extern int FUN_00031bf0(struct SP *e, int min); /* module prototype */
extern void FUN_00031f1c(int k); /* module prototype */
extern void FUN_00031f70(void); /* module prototype */
/* FUN_000323f4 @ 000323f4: handle a click at (x, y) on the topmost matching button of the current page: pick up a floor item (with the four-piece set check), use or talk to a map entity, or open a door; 1 when handled */
#include <string.h>
#include "world.h"
#define DAT_0005759c ((char *)DAT_0005759c)
extern unsigned short B00077148_eJ;
#define B00077152_el (*(unsigned short *)((char *)&B00077148_eJ + 10)) /* STANDIN: a name of its own in the original image, 10 bytes into B00077148_eJ */
extern int DAT_0005c050, DAT_0005bf44; extern unsigned short DAT_0005f038[], B00077148_eJ, B00067626_hm, B00072246_dJ;
extern unsigned char DAT_00058602, DAT_0005cf68; 
extern int FUN_0003ac80(int), FUN_0001f4b0(short), FUN_0002c1dc(int), FUN_0003ad18(int), FUN_0003ade0(int), FUN_0003acdc(int);
extern int FUN_00034478(int, int), FUN_000343e0(int, int);
extern void FUN_0002c21c(char *), FUN_00036018(int, int, int), FUN_0001c704(void);
extern char *FUN_0003e6f0(int);
#define BW(b, o) (*(unsigned short *)((b) + (o)))
int FUN_000323f4(int x, int y, int fl)
{
    int n, k, off, id, type; unsigned item; char *b;
    for (n = DAT_0005f038[DAT_0005c050 ^ 1] - 1; n >= 0; n--) {
        for (k = 0, off = 0; k < DAT_0005f038[DAT_0005c050 ^ 1]; off += 0x16, k++) {
            if (*(unsigned short *)((char *)&B00077152_el + (DAT_0005c050 ^ 1) * 0x2260 + off) == n) break;
        }
        b = (char *)&B00077148_eJ + (DAT_0005c050 ^ 1) * 0x2260 + k * 0x16;
        if (BW(b, 8) == 3) continue;
        if (BW(b, 8) == 1 && !FUN_0003ac80(*(unsigned short *)((char *)&B00072246_dJ + BW(b, 6) * 0x16))) continue;
        if (!FUN_00031bf0(b, 0x1e)) continue;
        id = BW(b, 6);
        type = BW(b, 8);
        if (BW(b, 0xe) > x || BW(b, 0x10) < x || BW(b, 0x12) > y || BW(b, 0x14) < y) continue;
        if (type == 2 && (fl & 1)) {
            item = *(unsigned short *)((char *)&B00067626_hm + id * 0x16);
            FUN_00031704(id);
            strcpy(DAT_0005759c, DAT_0005d67c);
            strcat(DAT_0005759c, ((char *)B000755d8_aw) + item * 0x41);
            if (DAT_00058602 && ((char *)B000755d8_aw)[item * 0x41 + 0x37]) {
                strcat(DAT_0005759c, " +");
                strcat(DAT_0005759c, FUN_0003e6f0((unsigned char)((char *)B000755d8_aw)[item * 0x41 + 0x37]));
            }
            FUN_0002c21c(DAT_0005759c);
            if ((item == 0x87 && FUN_0001f4b0(0x88) && FUN_0001f4b0(0x74) && FUN_0001f4b0(0xe9))
             || (item == 0x88 && FUN_0001f4b0(0x87) && FUN_0001f4b0(0x74) && FUN_0001f4b0(0xe9))
             || (item == 0x74 && FUN_0001f4b0(0x87) && FUN_0001f4b0(0x88) && FUN_0001f4b0(0xe9))
             || (item == 0xe9 && FUN_0001f4b0(0x87) && FUN_0001f4b0(0x88) && FUN_0001f4b0(0x74))) FUN_00031f70();
            if (!FUN_0002c1dc(0x8f) && item >= 0x61 && item <= 0x62 && FUN_0001f4b0(0x35)) DAT_0005bf44 = 0xf;
            return 1;
        }
        if (BW(b, 8) == 0) {
            k = *(unsigned short *)((char *)&B00064d8e_a6 + BW(b, 6) * 0x16);
            if (FUN_0003ad18(k) && (fl & 1)) return FUN_00031adc(id, type);
            if (FUN_0003ade0(k) && (fl & 1)) return FUN_00031b44(id, type);
            if (!FUN_0003acdc(k)) continue;
            if (*(int *)((char *)&(*(int *)&B00064d8b_a7) + BW(b, 6) * 0x16) & 2) continue;
            if (((BW(b, 2) - 0x7d00) >> 3) < 0x39) continue;
            if ((fl & 1) && FUN_00034478(DAT_0005cf68 / 2, DAT_0005cf68 % 2) && FUN_000343e0(DAT_0005cf68 / 2, DAT_0005cf68 % 2))
                FUN_00036018(DAT_0005cf68 / 2, DAT_0005cf68 % 2, BW(b, 6));
            FUN_0001c704();
            return 1;
        }
        if (BW(b, 8) == 1) {
            FUN_00031f1c(*(unsigned short *)((char *)&B00072246_dJ + BW(b, 6) * 0x16));
            return 1;
        }
    }
    return 0;
}

#undef DAT_0005759c
#undef BW
/* ---- from build/var/mod/parts/p32894.c */
/* FUN_00032894 @ 00032894: hit-test row y of a perspective strip of width r against window win; report the window geometry and the column index; round 21: the map width is the level header member (the old `const short` fit stood in for the module -oa) */
#include "world.h"
struct W { int a, w, h, c, d, e, f; };
extern struct W B00065a18_cn[];
void FUN_00032894(int r, int y, int win, int *ph, int *pd, int *res, int *pcol, int *prow)
{
    struct W *w; int k, s, base;
    w = (struct W *)(win * 0x1c + (int)B00065a18_cn);
    *ph = w->h;
    *pd = w->d >> 6;
    *pcol = w->e % B00075618_b1.w;
    *prow = w->e / B00075618_b1.w;
    s = r * 4;
    base = 0x84 - s / 2;
    base += s / 8;
    for (k = 0; k < 0x80; k++) {
        if (y < (s * k + 0x40) / 128 + base) {
            *res = k;
            return;
        }
    }
}

/* ---- from build/var/mod/parts/p329cc.c */
extern void FUN_00030994(void); /* module prototype */
extern int FUN_00030c0c(int x, int y, unsigned char *obj); /* module prototype */
extern int FUN_00030e08(int x, int y, int obj, unsigned char *e); /* module prototype */
extern int FUN_000310b0(int a, int b, unsigned c, struct OBJ *o); /* module prototype */
extern void FUN_000311d8(int m, int a, int b, int flags); /* module prototype */
extern void FUN_000314b8(int m, int s, int flags); /* module prototype */
extern void FUN_0003195c(int sx, int t, int flag, int px, int py, int thrown, int redraw); /* module prototype */
extern void FUN_00031db4(int id); /* module prototype */
extern int FUN_000323f4(int x, int y, int fl); /* module prototype */
extern void FUN_00032894(int r, int y, int win, int *ph, int *pd, int *res, int *pcol, int *prow); /* module prototype */
/* r69bp: declarations brought in line with module 0x307e8 (DAT_0005d681 an array as in FUN_000311d8, the party cells short
   as in FUN_000307e8 with an int view for the 32-bit pushes), so the merged module needs no ALT alias for them; code unchanged.
   Its 820/788 failure in the merged module was not this function: FUN_00032ce0's file defined `static int next()`, which a
   one-file module emits out of line (32 bytes) right after FUN_000329cc - fixed in final/f32ce0.c (macro). */
struct BOX { short x0, y0, x1, y1; };
/* struct W: defined above */
extern struct BOX DAT_0005d684[];
extern struct W B00065a18_cn[];
extern short DAT_00058600; extern unsigned char DAT_00058602, DAT_0005d681[], DAT_0005d682;
extern short B000755d0_ao, B000755d4_ak; extern int DAT_0005c738;
extern void FUN_0001c704(void);

extern void FUN_00043808(int, int, int, int *, int *, int *, int *, int *);
extern unsigned char *FUN_0002e8c8(int, int);

extern void FUN_00033d84(int, int, int, int), FUN_0002a344(short, unsigned char), FUN_0002ac0c(void), FUN_0002ac38(int, int);
extern void FUN_000333a8(int), FUN_00033438(int, int, int);
void FUN_000329cc(int x, int y, int fl)
{
    int i, v, a, c, b, miss, ok, col, row;
    unsigned char *p;
    ok = 1;
    miss = 0;
    for (i = 0; DAT_0005d684[i].x0 != -1; i++)
        if (x >= DAT_0005d684[i].x0 && x <= DAT_0005d684[i].x1 && y >= DAT_0005d684[i].y0 && y <= DAT_0005d684[i].y1) break;
    switch (i) {
    case 0:
        if (fl & 2) FUN_0001c704();
        else if (DAT_00058600 != -1 && x > 0xbc)
            FUN_0003195c(y, DAT_00058600, DAT_00058602, *(int *)&B000755d0_ao, *(int *)&B000755d4_ak, 1, 1);
        else {
            y -= 0x20;
            if (!FUN_000323f4(x, y, fl)) {
                v = B00065a18_cn[y].a / 8;
                if (v >= 0x2d) {
                    if (v >= DAT_0005c738) FUN_00032894(v, x, y, &a, &b, &c, &col, &row);
                    else FUN_00043808(v, x, y, &a, &b, &c, &col, &row);
                    p = FUN_0002e8c8(col, row);
                    if (p != 0 && b >= 0) {
                        switch (*p) {
                        case 1: if (FUN_00030c0c(col, row, p)) ok = 0; break;
                        case 2: if (FUN_000310b0(c, b, a, p)) ok = 0; break;
                        case 4: if (FUN_00030e08(c, b, a, p)) ok = 0; break;
                        case 10: FUN_00031db4(p[9]); break;
                        default: miss = 1; break;
                        }
                    } else miss = 1;
                } else miss = 1;
            } else ok = 0;
        }
        if (miss && DAT_00058600 != -1) {
            FUN_00033d84(DAT_00058600, DAT_00058602, y, -1);
            FUN_0002a344(-1, 0);
            ok = 0;
        }
        if (ok) {
            FUN_0002ac0c();
            FUN_0002ac38(x, y);
        }
        break;
    case 1: case 5: case 9: case 13: FUN_000314b8((i - 1) / 4, 0, fl); break;
    case 2: case 6: case 10: case 14: FUN_000333a8((i - 2) / 4); break;
    case 3: case 7: case 11: case 15: FUN_000314b8((i - 3) / 4, 1, fl); break;
    case 4: case 8: case 12: case 16: FUN_000311d8((i - 4) / 4, x, y, fl); break;
    case 17: if (DAT_0005d681[0]) FUN_00033438(0, x, y); break;
    case 18: if (DAT_0005d682) FUN_00033438(1, x, y); break;
    case 19: FUN_00030994(); break;
    case 20: FUN_0002ac38(x, y); break;
    }
}

/* ---- from build/var/mod/parts/p32ce0.c */
extern void FUN_000329cc(int x, int y, int fl); /* module prototype */
/* FUN_00032ce0, FUN_00032d70, FUN_00032d8c: the 20-entry sound-event ring (queue, flush, process); one -oa module, the ring index through an inlined next() */
struct EV { short a, b, c; };
struct EQ { unsigned char tail, head; struct EV q[20]; };
extern unsigned char DAT_0005d680; extern struct EQ DAT_0005a63a;
#define next(h) (((h) + 1) % 20) /* r69bp: a macro, not a static function: in the one-file module 0x307e8 the static was emitted out of line (32 bytes after FUN_000329cc, which then failed 820/788); 10.0a C has no __inline */
void FUN_00032ce0(int a, int b, int c)
{
    if (DAT_0005d680 == 0 || DAT_0005d680 == 1 || DAT_0005d680 == 4) {
        if (next(DAT_0005a63a.head) != DAT_0005a63a.tail) {
            DAT_0005a63a.q[DAT_0005a63a.head].a = a;
            DAT_0005a63a.q[DAT_0005a63a.head].b = b;
            DAT_0005a63a.q[DAT_0005a63a.head].c = c;
            DAT_0005a63a.head = next(DAT_0005a63a.head);
        }
    }
}

extern unsigned char DAT_0005d680; extern struct EQ DAT_0005a63a;

/* FUN_00032d70 @ 00032d70 */
extern unsigned char DAT_0005cf4a;
extern short DAT_0005a6ba;
void FUN_00032d70(void) { DAT_0005cf4a = 0; DAT_0005a6ba = 0; DAT_0005a63a.tail = DAT_0005a63a.head; }

extern unsigned char DAT_0005d680; extern struct EQ DAT_0005a63a;

/* FUN_00032d8c @ 00032d8c: process the queued sound events */
extern void FUN_0003f868(void), FUN_00022e70(int, int, int), FUN_00012db0(int, int, int);
extern short DAT_00059e21, DAT_00059e23, DAT_00059e25, DAT_00059e27;
void FUN_00032d8c(void)
{
    int z, x, y, k, again; /* STANDIN: declaration order (x before y: the x / y load tie at the ring read, ESI for x as in the original) */
    do {
        FUN_0003f868();
        again = 0;
        if (DAT_0005a63a.tail != DAT_0005a63a.head) {
            k = DAT_0005a63a.tail;
            x = DAT_0005a63a.q[k].a;
            y = DAT_0005a63a.q[k].b;
            z = DAT_0005a63a.q[k].c;
            DAT_0005a63a.tail = next(k);
            DAT_00059e21 = -1;
            DAT_00059e23 = -1;
            DAT_00059e25 = -1;
            DAT_00059e27 = -1;
            again = 1;
            switch (DAT_0005d680) {
            case 0: FUN_000329cc(x, y, z); break;
            case 1: FUN_00022e70(x, y, z); break;
            case 4: FUN_00012db0(x, y, z); break;
            }
        }
    } while (again);
}

#undef next

/* ---- module data _DATA 0005d670-0005d89c (docs/data/dataown.CODE2.csv: inferred (ref; some shared)), generated by tools/data2c.py */
char *PTR_s_Stepping_Mode_On_0005d670 = "Stepping Mode On";
char *PTR_s_Stepping_Mode_Off_0005d674 = "Stepping Mode Off";
struct MSGQ PTR_s_NOT_ENOUGH_SPACE_IN_INVENTORY_0005d678 = { "NOT ENOUGH SPACE IN INVENTORY.", "You pick up " };
unsigned char DAT_0005d680 = 0;
unsigned char DAT_0005d681[1] = { 0 };
unsigned char DAT_0005d682 = 0;
unsigned char DAT_0005d683[1] = { 0x6e };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
struct BOX DAT_0005d684[22] = {
    4, 0x20, 0x103, 0x11f,
    0x114, 4, 0x133, 0x13,
    0x114, 0x15, 0x133, 0x23,
    0x114, 0x25, 0x133, 0x34,
    0x138, 4, 0x187, 0x33,
    0x114, 0x39, 0x133, 0x48,
    0x114, 0x4a, 0x133, 0x58,
    0x114, 0x5a, 0x133, 0x69,
    0x138, 0x39, 0x187, 0x68,
    0x114, 0xd7, 0x133, 0xe6,
    0x114, 0xe8, 0x133, 0xf6,
    0x114, 0xf8, 0x133, 0x107,
    0x138, 0xd7, 0x187, 0x106,
    0x114, 0x10c, 0x133, 0x11b,
    0x114, 0x11d, 0x133, 0x12b,
    0x114, 0x12d, 0x133, 0x13c,
    0x138, 0x10c, 0x187, 0x13b,
    0x138, 0x34, 0x187, 0x38,
    0x138, 0x107, 0x187, 0x10b,
    0x113, 0x8c, 0x121, 0xb3,
    0x124, 0x7e, 0x187, 0xc3,
    -1, -1, -1, -1
};
unsigned short DAT_0005d734 = 0x64;
unsigned char DAT_0005d736 = 0x1c;
unsigned char DAT_0005d737 = 0x1a;
unsigned char DAT_0005d738 = 0x27;
unsigned char DAT_0005d739 = 0x25;
unsigned char DAT_0005d73a[102] = { 0xd1, 0, 0x10, 0x2d, 0x1a, 0x45, 0xd7, 0, 0, 0x54, 8, 0x68, 0x42, 1, 0x1c, 0x1a, 0x27, 0x25, 0x49, 1, 0x1c, 0x1a, 0x27, 0x25, 0x4d, 1, 0x1c, 0x1b, 0x25, 0x26, 0x53, 1, 0x1c, 0x1a, 0x27, 0x25, 0x55, 1, 4, 0x28, 0x10, 0x3c, 0x57, 1, 0x1c, 0x14, 0x26, 0x51, 0x69, 1, 0x1c, 0x4b, 0x26, 0x5f, 0x6b, 1, 0x1c, 0x1a, 0x27, 0x25, 0x7e, 1, 5, 0x40, 0xf, 0x58, 0x80, 1, 0x1c, 0x1a, 0x27, 0x25, 0x89, 1, 0x1c, 0x1a, 0x27, 0x3a, 0x8e, 1, 0, 0x4e, 0xa, 0x67, 0xbd, 1, 0x1d, 0x1d, 0x27, 0x45, 0x40, 2, 0x10, 0x46, 0x1c, 0x55, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };   /* no name in the sources */
short DAT_0005d7a0[68] = {
    0x195, 0xe, 0x20, 0xf, 0x9c, 0xf, 0x119, 0x10, 0x130, 0x10, 0x2e, 0x11, 0x3c, 0x11, 0xb5, 0x11,
    0xb7, 0x11, 0xeb, 0x11, 0xf0, 0x11, 0x1cc, 0x11, 0x122, 0x11, 0x193, 0x11, 0x1c2, 0x11, 0x1c4, 0x11,
    0x1c6, 0x11, 0x1c8, 0x11, 0x1ca, 0x11, 0x134, 0x12, 0x167, 0x12, 0x1a2, 0x12, 0x24, 0x13, 0x83, 0x13,
    0x87, 0x13, 0xcf, 0x13, 0x109, 0x13, 0x10b, 0x13, 0x13f, 0x13, 0x191, 0x13, 0xb9, 0x15, 0xbb, 0x15,
    0xd5, 0x15, 0xfd, 0x15
};
short DAT_0005d828[24] = {
    0x14b, 0x14c, 0x152, 0x160, 0x161, 0x162, 0x163, 0x176, 0x177, 0x17a, 0x17b, 0x17c, 0x17d, 0x18c, 0x1a1, 0x1d6,
    0x1d7, 0x1d8, 0x1d9, 0x1da, 0x1db, 0x1dc, 0x1dd, -1
};
short DAT_0005d858 = 0x64;
short DAT_0005d85a = 3;
unsigned char DAT_0005d85c[64] = { 0xd7, 0, 3, 0, 0x42, 1, 3, 0, 0x49, 1, 3, 0, 0x4d, 1, 3, 0, 0x53, 1, 3, 0, 0x55, 1, 3, 0, 0x6b, 1, 3, 0, 0x80, 1, 3, 0, 0x8e, 1, 3, 0, 0xd1, 0, 4, 0, 0x69, 1, 4, 0, 0x40, 2, 4, 0, 0x57, 1, 5, 0, 0x7e, 1, 5, 0, 0x89, 1, 5, 0, 0xbd, 1, 5, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
