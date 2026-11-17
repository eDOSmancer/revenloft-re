typedef void (__far *PARA_BSS)(); /* STANDIN: the _BSS of this object file is paragraph-aligned in the original (unnamed bytes ahead of it up to the 16-byte boundary); a typedef of a far pointer type raises the alignment, as a far pointer or double variable of any function would (docs/BSS.md) */
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
char B00062b70_ah[48];
struct LSP *B00062b58_ap[6];
void *B00062b30_k9[10];
unsigned char B00062a30_mJ[256];
char B00062990_ll[160];
char B000628f0_jm[160];
char B00062850_hl[160];
char B000627b0_dn[160];
char B00062760_fl[80];
/* BSS end */
/* Module: FUN_00013a78, FUN_00013c04, FUN_00013de4, FUN_00013ea4, FUN_00013f78, FUN_00014040, FUN_00014100,
   FUN_00014228, FUN_000143f4, FUN_000144d0, FUN_0001461c, FUN_000150dc, FUN_0001518c, FUN_00015578,
   FUN_00015698, FUN_00015984, FUN_00015a14, FUN_00015aa4, FUN_00015bdc, FUN_00015c84, FUN_00015d34,
   FUN_00015dd0, FUN_00015e38, FUN_00015eec, FUN_00016008, FUN_000162ac, FUN_00016354, FUN_00016444,
   FUN_00016548, FUN_000166e8, FUN_00016c68, FUN_00017070, FUN_0001719c, FUN_000171b8, FUN_00017378,
   FUN_000173a0, FUN_000175cc, FUN_000177a0, FUN_00017874, FUN_00017938, FUN_000179e0, FUN_00017b94,
   FUN_00017d44, FUN_0001803c, FUN_000180ac
   Module file (tools/modfile.py, round 23): not a verified module; the build splices the functions that match here.
   (no function of this module is layout-only any more) */
/* ---- from src/CODE2/wip/f13a78.c */
extern void FUN_00015bdc(int mode, int i, int row, unsigned char *tbl); /* module prototype */
/* Round 18: MATCH in module 0x13a78, written like its matched priest twin FUN_00013c04: `row--;` as a statement and the declarations hi, k, lo, lev (the frame slots follow), and the low-nibble clamp as `lo + e.lo > cap`. Earlier: NEAR MISS 395/395, slots only: every instruction matches (nibble bitfield, record index inline in every access); only the frame slots of the compiler temporaries differ (orig lev*4 0x14, i*0x248 0xc, its +10 copy 0x1c, lo 0x10, hi 4; here 0x20, 0x1c, 0x14, 8, 0xc). Declaration orders (24), init orders, row pointers/offsets and byte arithmetic tried */
/* FUN_00013a78 @ 00013a78: after a level change, clamp the memorised (low nibble) and prepared (high nibble) spell counts of member i to the slots of the new table row */
struct NB { unsigned char lo : 4, hi : 4; };

#include "chars.h"
#define B0007194a_al ((struct NB *)((char *)&B000718e0_iO + 106)) /* STANDIN: view, B000718e0_iO + 0x6a */
extern unsigned char DAT_00056210[], DAT_00056208[]; extern int DAT_00056440[]; 
void FUN_00013a78(int i, int row)
{
    int hi; int k; int lo; int lev;
    row--;
    FUN_00015bdc(1, i, row, DAT_00056210);
    for (lev = 0; lev < 8; lev++) {
        lo = 0;
        hi = 0;
        for (k = 0; k < DAT_00056440[lev]; k++) {
            if (B0007194a_al[i * 0x248 + lev * 10 + k].lo == 0xf) continue;
            if (lo + B0007194a_al[i * 0x248 + lev * 10 + k].lo > DAT_00056208[lev]) B0007194a_al[i * 0x248 + lev * 10 + k].lo = DAT_00056208[lev] - lo;
            lo += B0007194a_al[i * 0x248 + lev * 10 + k].lo;
            if (B0007194a_al[i * 0x248 + lev * 10 + k].hi > B0007194a_al[i * 0x248 + lev * 10 + k].lo) B0007194a_al[i * 0x248 + lev * 10 + k].hi = B0007194a_al[i * 0x248 + lev * 10 + k].lo;
            if (hi + B0007194a_al[i * 0x248 + lev * 10 + k].hi > DAT_00056208[lev]) B0007194a_al[i * 0x248 + lev * 10 + k].hi = DAT_00056208[lev] - hi;
            hi += B0007194a_al[i * 0x248 + lev * 10 + k].hi;
        }
    }
}

/* ---- from src/CODE2/wip/f13c04.c */
extern void FUN_00015bdc(int mode, int i, int row, unsigned char *tbl); /* module prototype */
#define B000718f5_h2 (*(signed char *)((char *)&B000718e0_iO + 21)) /* STANDIN: view, B000718e0_iO + 0x15 */
/* the module declaration (seen through a cast view below) */ 
#define M000718f5_h2 ((signed char *)&B000718f5_h2)
/* Round 18: MATCH in module 0x13a78: the low-nibble clamp is written like the high one, `lo + e.lo > cap` (the sum is the left operand, so it is evaluated into ebp first and compared against the cap: cmp cap, sum; jae). Earlier: NEAR MISS 477/479: the prelude matches (if/else of two FUN_00015bdc calls, nibble bitfields for the two entries, the else-copy merged by the compiler); the clamp loop has the same temp-slot difference as wip/f13a78 (twin function, also tried together in one file) */
/* [2026-11-09: declaration order from an automatic sweep, 113 diff lines with -3s -oimelr -oe -s -w0] */
/* FUN_00013c04 @ 00013c04: priest twin of FUN_00013a78: rebuild the slot row, reset the first two spell entries for clerics, then clamp the memorised (low) and prepared (high) nibbles */
/* struct NB: defined above */

#define B0007199a_mo ((struct NB *)((char *)&B000718e0_iO + 186)) /* STANDIN: view, B000718e0_iO + 0xba */
extern unsigned char DAT_00056350[], DAT_000562b0[], DAT_00056208[]; extern int DAT_00056440[]; 
void FUN_00013c04(int i, int row)
{
    int hi; int k; int lo; int lev;
    row--;
    if (M000718f5_h2[i * 0x248] == 1) FUN_00015bdc(0, i, row, DAT_00056350);
    else FUN_00015bdc(0, i, row, DAT_000562b0);
    if (M000718f5_h2[i * 0x248] == 1) {
        B0007199a_mo[i * 0x248 + 7].lo = 1;
        B0007199a_mo[i * 0x248 + 7].hi = 1;
        if (row < 3) {
            B0007199a_mo[i * 0x248 + 8].lo = 0xf;
            B0007199a_mo[i * 0x248 + 8].hi = 0xf;
        } else {
                B0007199a_mo[i * 0x248 + 8].lo = 1;
            B0007199a_mo[i * 0x248 + 8].hi = 1;
        }
    } else {
        B0007199a_mo[i * 0x248 + 8].lo = 1;
        B0007199a_mo[i * 0x248 + 8].hi = 1;
    }
    for (lev = 0; lev < 8; lev++) {
        lo = 0;
        hi = 0;
        for (k = 0; k < DAT_00056440[lev]; k++) {
            if (B0007199a_mo[i * 0x248 + lev * 10 + k].lo == 0xf) continue;
            if (lo + B0007199a_mo[i * 0x248 + lev * 10 + k].lo > DAT_00056208[lev]) B0007199a_mo[i * 0x248 + lev * 10 + k].lo = DAT_00056208[lev] - lo;
            lo += B0007199a_mo[i * 0x248 + lev * 10 + k].lo;
            if (B0007199a_mo[i * 0x248 + lev * 10 + k].hi > B0007199a_mo[i * 0x248 + lev * 10 + k].lo) B0007199a_mo[i * 0x248 + lev * 10 + k].hi = B0007199a_mo[i * 0x248 + lev * 10 + k].lo;
            if (hi + B0007199a_mo[i * 0x248 + lev * 10 + k].hi > DAT_00056208[lev]) B0007199a_mo[i * 0x248 + lev * 10 + k].hi = DAT_00056208[lev] - hi;
            hi += B0007199a_mo[i * 0x248 + lev * 10 + k].hi;
        }
    }
}

#undef M000718f5_h2
/* ---- from src/CODE2/f13de4.c */
#define NB T2_NB
#define M000718e0_iO ((struct CH *)&B000718e0_iO)
/* FUN_00013de4 @ 00013de4: reset the priest spell book of party member i for class level lvl */
#pragma pack(1)
struct NB { unsigned char lo : 4, hi : 4; };
struct CH { char p0[0x6a]; struct NB mage[8][10]; struct NB priest[8][10]; char p10a[0x248 - 0x10a]; };
#pragma pack()
 extern unsigned char DAT_000562b0[]; extern int DAT_00056420[8];
void FUN_00013de4(int i, int lvl)
{
    int k, j;
    lvl--;
    M000718e0_iO[i].priest[0][8].lo = 1;
    M000718e0_iO[i].priest[0][8].hi = 1;
    for (k = 0; k < 8; k++) {
        if (DAT_000562b0[lvl * 8 + k]) {
            for (j = 0; j < DAT_00056420[k]; j++) {
                if (M000718e0_iO[i].priest[k][j].lo == 0xf) {
                    M000718e0_iO[i].priest[k][j].lo = 0;
                    M000718e0_iO[i].priest[k][j].hi = 0;
                }
            }
        } else {
            for (j = 0; j < DAT_00056420[k]; j++) {
                if (M000718e0_iO[i].priest[k][j].lo != 0xf) {
                    M000718e0_iO[i].priest[k][j].lo = 0xf;
                    M000718e0_iO[i].priest[k][j].hi = 0xf;
                }
            }
        }
    }
}

#undef M000718e0_iO
#undef NB
#pragma pack()
/* ---- from src/CODE2/f13ea4.c */
#define M0007199a_mo ((struct N *)B0007199a_mo)
/* FUN_00013ea4 @ 00013ea4: reset the memorised-spell nibbles of party member who for caster class n */
struct N { unsigned char lo : 4, hi : 4; };
 extern unsigned char DAT_00056350[]; extern int DAT_00056420[];
void FUN_00013ea4(int who, int n)
{
    int i, j;
    n--;
    M0007199a_mo[who * 0x248 + 7].lo = 1;
    M0007199a_mo[who * 0x248 + 7].hi = 1;
    if (n >= 3) {
        M0007199a_mo[who * 0x248 + 8].lo = 1;
        M0007199a_mo[who * 0x248 + 8].hi = 1;
    }
    for (i = 0; i < 8; i++) {
        if (DAT_00056350[n * 8 + i]) {
            for (j = 0; j < DAT_00056420[i]; j++)
                if (M0007199a_mo[who * 0x248 + i * 10 + j].lo == 0xf) {
                    M0007199a_mo[who * 0x248 + i * 10 + j].lo = 0;
                    M0007199a_mo[who * 0x248 + i * 10 + j].hi = 0;
                }
        } else {
            for (j = 0; j < DAT_00056420[i]; j++)
                if (M0007199a_mo[who * 0x248 + i * 10 + j].lo != 0xf) {
                    M0007199a_mo[who * 0x248 + i * 10 + j].lo = 0xf;
                    M0007199a_mo[who * 0x248 + i * 10 + j].hi = 0xf;
                }
        }
    }
}

#undef M0007199a_mo
/* ---- from src/CODE2/f13f78.c */
/* FUN_00013f78 @ 00013f78: show a two-line message box and wait for a click or key */
extern void FUN_000391b0(unsigned char), FUN_0002c40c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int), FUN_0002a510(int), FUN_0002a5b0(int, short, unsigned char);
extern int FUN_0002a1f4(void), FUN_00040b40(void); extern int DAT_0005c050; extern short DAT_00058600; extern unsigned char DAT_00058602;
void FUN_00013f78(char *a, char *b)
{
    FUN_000391b0(DAT_0005c050);
    FUN_0002c40c(DAT_0005c050, 0x50, 0x50, 0xf0, 0xa0);
    FUN_00040508(0xc4, 0x50, 0xa0, a, 1);
    FUN_00040508(0xce, 0x50, 0xa0, b, 1);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    while (FUN_0002a1f4());
    while (!FUN_0002a1f4() && !FUN_00040b40());
    while (FUN_0002a1f4() || FUN_00040b40());
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
}

/* ---- from src/CODE2/f14040.c (round 61 blind rewrite) */
/* FUN_00014040 @ 00014040: is the party position enclosed (rays in all 360 directions) */
#include "world.h"
union FX { int v; struct { unsigned short f; short i; } s; };
struct CELL { unsigned short wall : 6, seen : 1, door : 1, rest : 8; };
#define MAPC ((struct CELL *)&B000698e0_b7)
extern int B000755d0_ao, B000755d4_ak;
extern unsigned short B000698e0_b7;
extern void FUN_0003df2c(int *, int *, int, int);
extern unsigned short FUN_0002e930(int);
extern int FUN_0003c8e4(unsigned y, unsigned x, int skip);

int FUN_00014040(void)
{
    int a, c, step;
    union FX x, y;
    int dx, dy;

    step = 0x5000;
    for (a = 0; a < 360; a++) {
        x.v = B000755d0_ao;
        y.v = B000755d4_ak;
        FUN_0003df2c(&dx, &dy, step, a);
        for (;;) {
            x.v += dx;
            y.v += dy;
            c = y.s.i * B00075618_b1.w + x.s.i;
            if (MAPC[c].wall) {
                if (!MAPC[c].door) break;
                if (FUN_0002e930(c) == 0x8000) break;
            }
            if (FUN_0003c8e4(y.v, x.v, -1)) return 0;
        }
    }
    return 1;
}

/* ---- from src/CODE2/wip/f14100.c */
extern int FUN_00014040(void); /* module prototype */
/* Round 18: MATCH in module 0x13a78: the party cell is the high word of the int positions B000755d0_ao/B000755d4_ak (recipe 36), and the x distance is abs(ENT_X(k) - x) (the earlier -(x - ENT_X) was a stand-in for the node-count order the high-word read gives). Earlier note: NEAR MISS 293/293, 2 instr: plain abs(ENT_Y - G) for the first distance gives the original load order (G in edx, entity in eax, sub eax,edx); the second distance should load G into eax and compute entity - G in edx then copy (sub edx,eax; mov eax,edx). 36 form combinations and split conditions tried; -(G - E) is the closest */
/* FUN_00014100 @ 00014100: may the party rest here? 1 when a monster is near or the spot forbids it */
#include "world.h"
int abs(int);
#pragma intrinsic(abs)
extern int FUN_0003acdc(int);
#define B000698e1_b6 (*(unsigned short *)((char *)&B000698e0_b7 + 1)) /* STANDIN: view, B000698e0_b7 + 0x1 */
#define B00064d8b_a7 (*(int *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
#define B00064d8c_bX (*(unsigned short *)((char *)&B00064d80_ay + 12)) /* STANDIN: view, B00064d80_ay + 0xc */
extern struct ENT B00064d80_ay[];
#define B00064d82_aG (*(short *)((char *)&B00064d80_ay + 2)) /* STANDIN: view, B00064d80_ay + 0x2 */
#define B00064d86_aC (*(short *)((char *)&B00064d80_ay + 6)) /* STANDIN: view, B00064d80_ay + 0x6 */
extern int DAT_00056688, DAT_0005c6c8; extern int B000755d0_ao, B000755d4_ak;  extern unsigned short B000698e0_b7; 
#define ENT(sym, i) (*(&sym + 0) , 0)
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_CELL(i) (*(unsigned short *)((char *)&B00064d8c_bX + (i) * 0x16))
#define ENT_Y(i) (*(short *)((char *)&B00064d82_aG + (i) * 0x16))
#define ENT_X(i) (*(short *)((char *)&B00064d86_aC + (i) * 0x16))
int FUN_00014100(void)
{
    int k;
    DAT_00056688 = 0;
    if (DAT_0005c6c8 == 0x1d && ((short *)&B000755d0_ao)[1] > 0x41) return 1;
    if (DAT_0005c6c8 == 0xb && ((short *)&B000755d0_ao)[1] >= 4 && ((short *)&B000755d0_ao)[1] <= 7 && ((short *)&B000755d4_ak)[1] >= 7 && ((short *)&B000755d4_ak)[1] <= 0xb) return 0;
    if (FUN_00014040()) {
        DAT_00056688 = 1;
        return 0;
    }
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (ENT_FL(k) & 2) continue;
        if (!FUN_0003acdc(ENT_ID(k))) continue;
        if (*(int *)((char *)&B000698e0_b7 + ENT_CELL(k) * 2) & 0x40) return 1;
        if (abs(ENT_Y(k) - ((short *)&B000755d4_ak)[1]) < 0xf && abs(ENT_X(k) - ((short *)&B000755d0_ao)[1]) < 0xf && (*(int *)((char *)&B000698e1_b6 + ENT_CELL(k) * 2) & 4)) return 1;
    }
    return 0;
}

#undef ENT
#undef ENT_FL
#undef ENT_ID
#undef ENT_CELL
#undef ENT_Y
#undef ENT_X
/* ---- from src/CODE2/f14228.c (round 61 blind rewrite) */
/* FUN_00014228 @ 00014228: round 61 lane N blind rewrite */
struct ENT { union FX y, x; unsigned lo : 24, fb0 : 1, dead : 1, fb2 : 2, st : 2, fb6 : 2;
    unsigned short cell, type; short timer, hp; unsigned short w14; };
extern struct ENT B00064d80_ay[];
extern unsigned short B000698e0_b7;
extern int B000755d0_ao, B000755d4_ak;
extern short FUN_0003d5d0(int, int, int);

int FUN_00014228(void)
{
    int k, i, type, found, oy, ox;

    for (k = 0; k < 3; k++) {
        type = B00075618_b1.aa[k];
        for (i = 0; i < B00075618_b1.nent; i++) {
            if (B00064d80_ay[i].dead) continue;
            if (MAPC[B00064d80_ay[i].cell].seen) continue;
            if (B00064d80_ay[i].type != type) continue;
            found = 0;
            if (abs(B00064d80_ay[i].x.s.i - ((short *)&B000755d0_ao)[1]) > 10 &&
                abs(B00064d80_ay[i].y.s.i - ((short *)&B000755d4_ak)[1]) > 10) {
                oy = B00064d80_ay[i].y.v;
                ox = B00064d80_ay[i].x.v;
                B00064d80_ay[i].x.v = B000755d0_ao;
                B00064d80_ay[i].y.v = B000755d4_ak;
                B00064d80_ay[i].y.s.i++;
                if (!FUN_0003d5d0(B00064d80_ay[i].y.v, B00064d80_ay[i].x.v, i)) {
                    B00064d80_ay[i].y.v = B000755d4_ak;
                    B00064d80_ay[i].y.s.i--;
                    if (!FUN_0003d5d0(B00064d80_ay[i].y.v, B00064d80_ay[i].x.v, i)) {
                        B00064d80_ay[i].x.v = B000755d4_ak;
                        B00064d80_ay[i].x.s.i--;
                        if (!FUN_0003d5d0(B00064d80_ay[i].y.v, B00064d80_ay[i].x.v, i)) {
                            B00064d80_ay[i].x.v = B000755d4_ak;
                            B00064d80_ay[i].x.s.i++;
                            if (!FUN_0003d5d0(B00064d80_ay[i].y.v, B00064d80_ay[i].x.v, i)) {
                                B00064d80_ay[i].x.v = ox;
                                B00064d80_ay[i].y.v = oy;
                            } else found = 1;
                        } else found = 1;
                    } else found = 1;
                } else found = 1;
            }
            if (found) {
                B00064d80_ay[i].st = 1;
                return 1;
            }
        }
    }
    return 0;
}

/* ---- from src/CODE2/f143f4.c */
extern int FUN_000150dc(int mode, int i); /* module prototype */
#define NB T8_NB
#define M000718e0_iO ((struct CH *)&B000718e0_iO)
/* FUN_000143f4 @ 000143f4: count the spells still to be memorised (priest -> *pm, mage -> *pp) */
#pragma pack(1)
struct NB { unsigned char lo : 4, hi : 4; };
/* struct CH: defined above */
#pragma pack()


void FUN_000143f4(int i, int *pm, int *pp)
{
    int m, p, lvl, j; struct CH *c;
    m = FUN_000150dc(0, i);
    p = FUN_000150dc(1, i);
    c = &M000718e0_iO[i];
    for (lvl = 0; lvl < 8; lvl++) {
        for (j = 0; j < 10; j++) {
            if (p != 0 && c->mage[lvl][j].lo != 0xf && c->mage[lvl][j].lo != c->mage[lvl][j].hi && c->mage[lvl][j].hi < c->mage[lvl][j].lo) *pp -= c->mage[lvl][j].lo - c->mage[lvl][j].hi;
            if (m != 0 && c->priest[lvl][j].lo != 0xf && c->priest[lvl][j].lo != c->priest[lvl][j].hi && c->priest[lvl][j].hi < c->priest[lvl][j].lo) (*pm)--;
        }
    }
}

#undef M000718e0_iO
#undef NB
#pragma pack()
/* ---- from src/CODE2/f144d0.c */
#define M0007199a_mo ((struct SLOT *)B0007199a_mo)
/* FUN_000144d0 @ 000144d0: memorise spells from a slot: each resting priest/mage learns while charges remain */
struct SLOT { unsigned char lo : 4, hi : 4; };
extern void FUN_00019d90(int, int, int), FUN_0002f494(int);
#define B000718f0_hO (B000718e0_iO[0].fl)
   extern unsigned char DAT_0005cf5a;
int FUN_000144d0(int a, int b, int c, int d, int *e, int *f, int g)
{
    int r, k, idx, t;
    t = a * 0x248;
    idx = c + (b * 10 + t);
    if (M0007199a_mo[idx].lo == 0xf) return 0;
    {
        if (!M0007199a_mo[idx].hi) return 0;
        r = 0;
        for (k = 0; k < 4; k++) {
            if (!(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0xc000) && B000718e0_iO[k].hp != B000718e0_iO[k].maxhp) {
                while (M0007199a_mo[idx].hi && B000718e0_iO[k].hp < B000718e0_iO[k].maxhp) {
                    FUN_00019d90(d, k, a);
                    (&DAT_0005cf5a)[k] = 1;
                    FUN_0002f494(1);
                    M0007199a_mo[idx].hi--;
                    if (d != 0x57 && *e == 0) {
                        r = 1;
                        *e = g + 0xf0;
                    }
                }
                if (B000718e0_iO[k].hp == B000718e0_iO[k].maxhp) (*f)--;
            }
        }
    }
    return r;
}

#undef M0007199a_mo
/* ---- r62ab f1461c */
/* FUN_0001461c: MATCH (round 72 lane FD, build/var/r72fd; flags -3s -ox -oe -oa -ot -j -w0, 2749 bytes, nothing forced).
   The instruction stream was the original's since round 66 (lane BB; pass-1 register ties right since `--hurt` in the
   hp == 1 branch); what stayed open through rounds 66-71 was the frame-slot handout: 31 slots handed out in the order of
   AssignOtherLocals' SortList(Names[N_TEMP], TempAllocBefore), an unstable shell sort on SIZE over the 429-entry temp list
   (gaps 214/108/54/28/14/8/4/3/1), so every small entry anywhere in the list can throw a 4-byte temp forward by one gap.
   Target handout: t113 t104 t95 t56 (loop-1 nibble spill bytes), t420 priest-learn row end, t427 mage lvl*10 IV, t424 priest
   k*4 IV, t416 priest spell IV (0x92), t283 priest name, t421 priest &DAT[k] IV, t430 mage bound n*10, t413 priest row ptr,
   t336 mage name, t431 mage &DAT[k] IV, lvl hurt mg pr, t388 loop-1 k*4 IV, t any heal done toldp toldd, t434 mage k*4 IV,
   t385 loop-1 &DAT[k] IV, t384 loop-1 row ptr, t330 mage k*4 copy, tm, mt.
   What decides it (lane FA's list model, build/var/r71fa cmod.py, verified against the real 10.0a):
   - head of the list (254 entries): declaration order of the memory scalars (relabelled onto the handout ranks, lane BL) and
     the code-neutral spellings marked STANDIN below (lanes BB / BO);
   - tail (175 CONST_TEMPs): sorted four times by RoughSortTemps (savings, ties scrambled by the shell sort).  Its input
     order is the creation order of the function's constant names: ConstToTemp walks Names[N_CONSTANT], so in every loop the
     constant temps take their ids in reverse first-appearance order of the constants.  The dead stores `o = C;` at function
     entry create the names in a chosen order (no code, no list entry, n stays 429).
   Last step (lane FD): with FA's prologue 3 of 31 positions were wrong (t416 ahead of t427 / t424: both jumped +8 at the
   gap-8 pass).  The exhaustive single-move neighbourhood of that creation order (2625 relocations / transpositions through
   the exact model, round-1 global-bit set unchanged) has exactly one solution: 0x5a0 and 0x78 exchanged.
   Pitfall: a prologue constant must be spelled with the signedness of its natural use (`o = -65536;` creates a second name
   next to the unsigned 0xffff0000 of the mask test and moves nothing).
   History of the search (levers that are inert or change code, models, 1536 lever combinations): docs/MODULES.md rounds
   62-71; lane notes build/var/r66bb, r67bl, r68bo, r71bv, r71fa, r72fd/NOTES.md. */
#include <stdio.h>
#include <string.h>
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
#define DAT_0005cf5a ((unsigned char *)&DAT_0005cf5a)
int rand(void);
extern int FUN_00014100(void), FUN_00033eac(int, int), FUN_00017d44(char *msg), FUN_00014228(void), FUN_00040b40(void), FUN_00040aec(void);
extern void FUN_0002c21c(char *), FUN_0002c258(void), FUN_00041f94(void), FUN_0001893c(void), FUN_0001cd44(int, int);
extern void FUN_0002e74c(int t), FUN_000331c0(int, int), FUN_0002c368(char *, int);
extern char DAT_0005759c[], *DAT_000560ac, *DAT_000560d0, *DAT_000560d4, *DAT_000560d8, *DAT_00056098, *DAT_0005609c, *DAT_000560a0;
extern int DAT_0005a7e4, DAT_0005cf4c, DAT_0005d8a8, DAT_0005d8ac;
extern unsigned char DAT_0005d681, DAT_0005d682;
void FUN_0001461c(void)
{
    int s;
    int toldp;
    int lvl;
    int hurt;
    int mg;
    int pr;
    int tm[4];
    int t;
    int toldd;
    int any;
    int k;
    int heal;
    int j;
    int n;
    int mt[4];
    int done;
    struct PC *c; /* STANDIN: declaration order s toldp lvl hurt mg pr tm t toldd any k heal j n mt done c (frame-slot sort input: the memory scalars relabelled onto the handout ranks, code unchanged) */
    int o; /* STANDIN: dead stores below create the function's constant names in this order (ConstToTemp walks Names[N_CONSTANT]; the per-loop CONST_TEMP ids, the rough-sort tie order of the constant temps and through it the frame-slot shell sort follow it); no code */
    o = 0x1e0; o = 0x800; o = 0xa; o = -1; o = 0x42; o = 0; o = 0x6e; o = 0x50; o = 0x920; o = 0x438; o = 0x248; o = 0x1000; o = 0xff; o = 0x92; o = 0x5a0; o = 0x8000; o = 0xc000; o = 0xf; o = 0x78; o = -241; o = 0xef; o = 0x64; o = 0x11; o = 0x1b; o = 2; o = -256; /* STANDIN: constant-name creation order (see o) */
    done = 0;
    if (FUN_00014100()) {
        strcpy(DAT_0005759c, DAT_000560ac);
        FUN_0002c21c(DAT_0005759c);
        FUN_0002c258();
        return;
    }
    pr = mg = hurt = 0;
    memset(tm, 0, sizeof(tm));
    for (k = 0; k < 4; k++) {
        if (M000718e0_iO[k].fl & 0x1000) {
            DAT_0005cf5a[k] = 1;
            ((unsigned char *)&M000718e0_iO[k].fl)[1] &= 0xef; /* STANDIN: byte view (constant temp EF of size 1 instead of FFFFEFFF of size 2) */
        }
    }
    toldp = toldd = 0; /* STANDIN: toldd's store first ([esp+0x30] before [esp+0x34]) */
    for (k = 0; k < 4; k -= -1) { /* STANDIN: SUB -1 instead of k++ (constant temp -1 in loop 1 and its chain) */
        c = &M000718e0_iO[k];
        if (!(c->fl & 0xc000) && c->hp != c->maxhp) hurt++;
        if (c->hp == c->maxhp && (c->fl & 0xc00)) hurt++;
        if (!(c->fl & 0xc000)) {
            for (lvl = 0; lvl < 8; lvl++) {
                for (j = 0; j < 10; j++) {
                    if (c->sp & 2) {
                        if (c->mage[lvl][j].lo != 0xf && c->mage[lvl][j].lo != c->mage[lvl][j].hi) {
                            if (c->mage[lvl][j].hi > c->mage[lvl][j].lo) c->mage[lvl][j].hi = c->mage[lvl][j].lo;
                            else mg += c->mage[lvl][j].lo - c->mage[lvl][j].hi;
                        }
                    }
                    if (c->sp & 5) {
                        if (c->priest[lvl][j].lo != 0xf && c->priest[lvl][j].lo != c->priest[lvl][j].hi) {
                            if (c->priest[lvl][j].hi > c->priest[lvl][j].lo) c->priest[lvl][j].hi = c->priest[lvl][j].lo;
                            else tm[k] = 720;
                        }
                    }
                }
            }
        }
        if (tm[k]) pr++;
    }
    DAT_0005cf5a[0] = 1;
    DAT_0005cf5a[1] = 1;
    DAT_0005cf5a[2] = 1;
    DAT_0005cf5a[3] = 1;
    any = pr | mg;
    t = 0;
    mt[0] = 0;
    mt[1] = 0;
    mt[2] = 0;
    mt[3] = 0;
    if (hurt) {
        for (k = 0; k < 4; k++) {
            if (!(M000718e0_iO[k].fl & 0xc000)) {
                if (FUN_000150dc(0, k) >= 0) {
                    if ((M000718e0_iO[k].priest[0][1].lo != 0xf && M000718e0_iO[k].priest[0][1].lo)
                        || (M000718e0_iO[k].priest[3][0].lo != 0xf && M000718e0_iO[k].priest[0][1].lo)
                        || (M000718e0_iO[k].priest[4][0].lo != 0xf && M000718e0_iO[k].priest[0][1].lo)
                        || (M000718e0_iO[k].priest[5][0].lo != 0xf && M000718e0_iO[k].priest[0][1].lo)) {
                        heal = FUN_00017d44(DAT_000560d0);
                        break;
                    }
                } else if (FUN_00033eac(k, 1)) {
                    heal = FUN_00017d44(DAT_000560d0);
                    break;
                }
            }
        }
    }
    do {
        if (!hurt && !mg && !pr) break;
        for (j = 0; j < 10; j++) {
            t++;
            DAT_0005a7e4 += 0x438;
            DAT_0005cf4c += 0x445;
            FUN_00041f94();
            if (!(DAT_0005cf4c & 0xffff0000)) {
                for (k = 0; k < 4; k++) {
                    if (!(M000718e0_iO[k].fl & 0xc000)) {
                        if (M000718e0_iO[k].cls[0] == 1) {
                            M000718e0_iO[k].priest[0][7].lo = 1;
                            M000718e0_iO[k].priest[0][7].hi = 1;
                        }
                        if (FUN_000150dc(0, k) >= 0) {
                            M000718e0_iO[k].priest[0][8].lo = 1;
                            M000718e0_iO[k].priest[0][8].hi = 1;
                        }
                    }
                }
            }
        }
        if (t >= 0x1e0) done = 1;
        FUN_0001893c();
        if (B00075618_b1.solo != 0xff && (int)((unsigned)(rand() * 100) / 0x8000) > 0x5f && FUN_00014228()) { /* STANDIN: divide instead of >> 15 (constant 0x8000 in the do loop) */
            FUN_0002e74c(DAT_0005a7e4);
            return;
        }
        for (k = 0; k < 4; k++) {
            if (M000718e0_iO[k].fl < 0x4000) {
                if (M000718e0_iO[k].fl & 0x800) {
                    if (M000718e0_iO[k].hp == 1) {
                        --hurt; /* STANDIN: pre-decrement: changes the constant temps (-1); gives the pass-1 ties t269<t288 / t286<t413 unforced */
                        FUN_000143f4(k, &pr, &mg);
                    }
                    FUN_0001cd44(k, 1);
                    DAT_0005cf5a[k] = 1;
                    if (toldp == 0) {
                        toldp = 1;
                        if (!FUN_00017d44(DAT_000560d4)) {
                            FUN_0002e74c(DAT_0005a7e4);
                            return;
                        }
                    }
                }
                if (M000718e0_iO[k].fl & 0x400) {
                    if (M000718e0_iO[k].hp <= 3) {
                        hurt--;
                        FUN_000143f4(k, &pr, &mg);
                    }
                    FUN_0001cd44(k, 3);
                    DAT_0005cf5a[k] = 1;
                    if (toldd == 0) {
                        toldd = 1;
                        if (!FUN_00017d44(DAT_000560d8)) {
                            FUN_0002e74c(DAT_0005a7e4);
                            return;
                        }
                    }
                }
            }
        }
        if (heal) {
            for (k = 0; k < 4; k++) {
                if (!(M000718e0_iO[k].fl & 0xc000)) {
                    if (FUN_000150dc(0, k) >= 0) {
                        pr += FUN_000144d0(k, 0, 1, 0x51, &tm[k], &hurt, t);
                        pr += FUN_000144d0(k, 3, 0, 0x6e, &tm[k], &hurt, t);
                        pr += FUN_000144d0(k, 4, 0, 0x78, &tm[k], &hurt, t);
                    }
                    if (FUN_00033eac(k, 1)) FUN_000144d0(k, 0, 7, 0x57, 0, &hurt, t);
                }
            }
        }
        if (t % 60 == 0) {
            for (k = 0; k < 4; k++) {
                if (!(M000718e0_iO[k].fl & 0x8000) && M000718e0_iO[k].cls[0] == 1) {
                    M000718e0_iO[k].priest[0][7].lo = 1;
                    M000718e0_iO[k].priest[0][7].hi = 1;
                }
            }
        }
        if (hurt && t % 1440 == 0) {
            for (k = 0; k < 4; k++) {
                c = &M000718e0_iO[k];
                if (!(c->fl & 0xc000) && c->hp != c->maxhp) {
                    c->hp += 3;
                    if (c->hp >= c->maxhp) {
                        c->hp = c->maxhp;
                        hurt--;
                    }
                    DAT_0005cf5a[k] = 1;
                }
            }
        }
        FUN_0002f494(1);
        if (done) {
            if (pr) {
                for (k = 0; k < 4; k++) {
                    c = &M000718e0_iO[k];
                    if (!(c->fl & 0xc000) && (c->sp & 5) && tm[k] && t > tm[k]) {
                        pr--;
                        tm[k] = 0;
                        for (lvl = 0; lvl < 8; lvl++) {
                            for (j = 0; j < 10; j++) {
                                if (c->priest[lvl][j].lo != 0xf && c->priest[lvl][j].hi != c->priest[lvl][j].lo) {
                                    c->priest[lvl][j].hi = c->priest[lvl][j].lo;
                                    sprintf(DAT_0005759c, DAT_00056098, M000718e0_iO[k].name); /* STANDIN: name through its own hoisted slot ([esp+0x70]), tm/mt slots and ESI/EBP of the priest-learn loop */
                                    FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), lvl * 10 + 0x92 + j);
                                    FUN_0002c21c(DAT_0005759c);
                                    FUN_0002c258();
                                }
                            }
                        }
                    }
                }
            }
            if (mg) {
                for (k = 0; k < 4; k++) {
                    c = &M000718e0_iO[k];
                    if (!(c->fl & 0xc000) && (c->sp & 2)) {
                        n = (t - mt[k]) / 10;
                        for (lvl = 0; lvl < n && lvl < 8; lvl++) {
                            for (j = 0; j < 10; j++) {
                                if (c->mage[lvl][j].lo != 0xf && c->mage[lvl][j].hi != c->mage[lvl][j].lo) {
                                    c->mage[lvl][j].hi++;
                                    s = lvl * 10 + 0x42 + j; /* STANDIN: named spell number: add 0x42 in place in ESI before the call, mt[k] store before the call, loop-1 mage nibble dl/dh */
                                    mt[k] = t;
                                    sprintf(DAT_0005759c, DAT_00056098, M000718e0_iO[k].name);
                                    FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), s);
                                    FUN_0002c21c(DAT_0005759c);
                                    FUN_0002c258();
                                    mg--;
                                    break;
                                }
                            }
                            if (j != 10) break;
                        }
                    }
                }
            }
        }
    } while (FUN_00040b40() != 0x1b);
    if (FUN_00040b40()) FUN_00040aec();
    if (any) {
        if (DAT_0005d681) {
            DAT_0005d681 = 2;
            FUN_000331c0(DAT_0005d8a8, (unsigned char)M000718e0_iO[DAT_0005d8a8].f12f);
        }
        if (DAT_0005d682) {
            DAT_0005d682 = 2;
            FUN_000331c0(DAT_0005d8ac, (unsigned char)M000718e0_iO[DAT_0005d8ac].f12f);
        }
    }
    if (t / 60) sprintf(DAT_0005759c, DAT_0005609c, t / 60, t % 60);
    else sprintf(DAT_0005759c, DAT_000560a0, t % 60);
    FUN_0002c21c(DAT_0005759c);
    FUN_0002c258();
    FUN_0002e74c(DAT_0005a7e4);
}

#undef M000718e0_iO
#undef DAT_0005cf5a

/* ---- from src/CODE2/f150dc.c */
/* FUN_000150dc @ 000150dc: which class slot of party member i can cast (mode 0: priest, 1: mage) */
#include "chars.h"

#define CB(i, o) (*(signed char *)(CHAR_REC(i) + (o)))
#define CW(i, o) (*(short *)(CHAR_REC(i) + (o)))
int FUN_000150dc(int mode, int i)
{
    if ((*(unsigned short *)(CHAR_REC(i) + 0x10) & 0xf240) == 0) {
        if (mode == 0) {
            if (CB(i, 0x15) == 3) return 0;
            if (CB(i, 0x16) == 3) return 1;
            if (CB(i, 0x17) == 3) return 2;
            if (CB(i, 0x15) == 1 && CW(i, 0x20) >= 9) return 0;
        } else {
            if (CB(i, 0x15) == 4) return 0;
            if (CB(i, 0x16) == 4) return 1;
            if (CB(i, 0x17) == 4) return 2;
        }
    }
    return -1;
}

#undef CB
#undef CW
/* ---- FUN_0001518c (round 71 lane FB): the cell x is x + j * 0xc (an induction of j, as FUN_00015698 writes it), declarations at function level in the order m, x, n, j, lev, k, ty; stand-ins marked below. Frame slots follow the unstable ShellSort of the slot-sort input (docs: lane report r71fb) */
/* FUN_0001518c @ 0001518c: draw the six-level spell list of member ch (portrait buttons of the party at the left, sel highlighted; per level the free points and every known spell with its count) and fade in palette pal */
struct LBOX { int x, y; };
struct LSP { signed char id, cnt; };
extern int sprintf(char *, const char *, ...);
extern void *memset(void *, int, unsigned);
extern void FUN_0004059c(unsigned char *), FUN_00042220(unsigned char *, int, int, int, int, int), FUN_000422ec(unsigned char *, int, int, int, int, int);
extern void FUN_000425b0(unsigned char *, int, char *, char *, int), FUN_00042468(unsigned char *, int, int, int, int, unsigned char *);
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003975c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int);
extern void FUN_0004060c(int, int, char *, int), FUN_00040630(int, int, char *, int, int), FUN_0002c368(char *, int), FUN_0003aa9c(int, unsigned char *, unsigned char *);
extern void FUN_0002a5b0(int, short, unsigned char); extern char *FUN_0003e6f0(int);
#pragma aux FUN_0003aa9c modify [eax ebx ecx edx esi edi];
extern struct LSP *B00062b58_ap[6];
extern struct LBOX DAT_000563f0[];
extern int DAT_00056420[1][8], DAT_0005c050; extern char *B000758dc_cl; /* STANDIN: one char * declaration module-wide (FUN_00016354 needs a pointer-typed -oa node; an int node changes its code); the int uses cast it */
extern unsigned char DAT_0005c054[], B00062a30_mJ[256], DAT_0005880d[], DAT_00058602;
extern char DAT_0005759c[], *DAT_000560a4, *DAT_000560a8, *DAT_000560e0; extern short DAT_00058600;
void FUN_0001518c(int ch, int sel, int y, int pal, struct NB *sk, unsigned char *mx, int nm)
{
    unsigned char c[3] = { 0, 0, 0 };
    int m;
    int h0; /* STANDIN: helper that exists only in the first RoughSortTemps input (savings 860, id between m and x): permutes the equal-savings ties there (n / j*2, ty + 2 / + 0x19 / + 0x20, the 61 group) and with them the slot-sort input; its stores are deleted by AxeDeadCode: no pass-1 node, no slot, no code */
    int x;
    int n;
    int j;
    int lev;
    int k;
    int ty;

    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 256; k++) B00062a30_mJ[k] = k;
    B00062a30_mJ[0x1b] = 0xf1;
    B00062a30_mJ[0] = 0xf0;
    FUN_0004059c(B00062a30_mJ);
    FUN_0003e510(0, 0, y, 0);
    FUN_0003e510(0xc8, 0, y + 1, 0);
    for (k = 0; k < 5; k++) {
        if (k == 4 || FUN_000150dc(ch, k) >= 0) {
            FUN_0003975c(k == sel, 0, k * 0x42 + 5, (int)B000758dc_cl + 0x4a + ch, 0);
            if (k == 4) FUN_00040508((k != sel) + 1, k * 0x42 + 6, 0x30, DAT_000560e0, 1);
            else FUN_00040508((k != sel) + 1, k * 0x42 + 6, 0x30, CHAR_REC(k), 1);
        }
    }
    for (lev = 0; lev < 6; lev++) {
        memset(B00062b58_ap[lev], -1, 0x14);
        m = lev * 10;
        x = DAT_000563f0[lev].x;
        ty = DAT_000563f0[lev].y;
        h0 = x; h0 = lev; /* STANDIN: two depth-1 stores of the helper (+20 each for h0, x, lev in the first rough sort only) */
        sprintf(DAT_0005759c, DAT_000560a4, lev + 1);
        FUN_00040508(x + 2, ty, 0x64, DAT_0005759c, 1);
        sprintf(DAT_0005759c, DAT_000560a8, *(unsigned char *)((int)mx + lev)); /* STANDIN: int-class sum for mx[lev]: IncAndInit keeps the initialisation temp of the mx + lev accumulator as a 4-byte entry ahead of the SetOnCondition byte temps (12 entries between m and the first of them, list length 131) */
        FUN_00040508(x + 0xe, ty, 0x64, DAT_0005759c, 1);
        x += 0x2d;
        for (n = j = 0; n < DAT_00056420[ch][lev]; n++) {
            h0 = lev; h0 = ty; /* STANDIN: two depth-2 stores of the helper (+400 each for h0, lev, ty in the first rough sort only) */
            if (sk[m + n].lo == 0xf) continue;
            FUN_0004060c(x + j * 0xc, ty + 2, "[-] [+]", 1);
            FUN_0004060c(x + j * 0xc, ty + 0x19, FUN_0003e6f0(sk[m + n].lo), 1);
            FUN_0002c368(DAT_0005759c, nm + lev * 10 + n);
            FUN_00040630(x + j * 0xc, ty + 0x20, DAT_0005759c, 1, 0x44);
            B00062b58_ap[lev][j].id = n;
            B00062b58_ap[lev][j].cnt = sk[m + n].lo;
            j++;
        }
        x = h0; ty = n; ty = lev; /* STANDIN: dead stores (x and ty are reloaded at the loop top): the read keeps h0 through InsDead, +20 each for x, ty, n, lev in the first rough sort only; deleted by AxeDeadCode */
    }
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    FUN_000425b0(DAT_0005c054, 0, (char *)pal, "COLORS.", 0x100);
    FUN_00042468(DAT_0005c054, 0, 0xec, 6, 3, c);
    for (k = 0; k < 256; k++) B00062a30_mJ[k] = k;
    B00062a30_mJ[8] = 0xf0;
    B00062a30_mJ[0x1b] = 0xf1;
    B00062a30_mJ[0x16] = 0xf2;
    B00062a30_mJ[0x1a] = 0xf3;
    B00062a30_mJ[0x12] = 0xf4;
    B00062a30_mJ[9] = 0xf5;
    B00062a30_mJ[0x10] = 0xf6;
    B00062a30_mJ[0xb] = 0xf7;
    B00062a30_mJ[0xa] = 0xf8;
    B00062a30_mJ[0x5c] = 0xf9;
    B00062a30_mJ[0x58] = 0xfa;
    B00062a30_mJ[0x55] = 0xfb;
    B00062a30_mJ[0x53] = 0xfc;
    B00062a30_mJ[0x57] = 0xfd;
    B00062a30_mJ[0x54] = 0xfe;
    B00062a30_mJ[0x56] = 0xff;
    B00062a30_mJ[0x59] = 0xed;
    B00062a30_mJ[0xd] = 0xee;
    B00062a30_mJ[0xc] = 0xef;
    FUN_0003aa9c(0, B00062a30_mJ, DAT_0005880d);
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
    FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
}
/* ---- from src/CODE2/f15578.c */
#define FUN_0004059c ((void (*)(int))FUN_0004059c)
#define FUN_00042220 ((void (*)(unsigned char *, int, int, int, int, int))FUN_00042220)
/* FUN_00015578 @ 00015578: reset the palette and install the identity colour map with the UI colours (FUN_0003aa9c declared with the parameter types of the module's other declaration: with a different prototype the merge aliased it and the #pragma aux, whose name is not macro-expanded, no longer applied to this call) */
void *memset(void *, int, unsigned);
extern void FUN_0003aa9c(int, unsigned char *, unsigned char *);
extern unsigned char DAT_0005c054[], B00062a30_mJ[256], DAT_0005880d[];
void FUN_00015578(void)
{
    int k;
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    memset(DAT_0005c054, 0, 0x300);
    for (k = 0; k < 256; k++) B00062a30_mJ[k] = k;
    B00062a30_mJ[0xf0] = 8;
    B00062a30_mJ[0xf1] = 0x1b;
    B00062a30_mJ[0xf2] = 0x16;
    B00062a30_mJ[0xf3] = 0x1a;
    B00062a30_mJ[0xf4] = 0x12;
    B00062a30_mJ[0xf5] = 9;
    B00062a30_mJ[0xf6] = 0x10;
    B00062a30_mJ[0xf7] = 0xb;
    B00062a30_mJ[0xf8] = 10;
    B00062a30_mJ[0xf9] = 0x5c;
    B00062a30_mJ[0xfa] = 0x58;
    B00062a30_mJ[0xfb] = 0x55;
    B00062a30_mJ[0xfc] = 0x53;
    B00062a30_mJ[0xfd] = 0x57;
    B00062a30_mJ[0xfe] = 0x54;
    B00062a30_mJ[0xff] = 0x56;
    B00062a30_mJ[0xed] = 0x59;
    B00062a30_mJ[0xee] = 0xd;
    B00062a30_mJ[0xef] = 0xc;
    FUN_0003aa9c(0, B00062a30_mJ, DAT_0005880d);
    for (k = 0; k < 256; k++) B00062a30_mJ[k] = k;
    FUN_0004059c(0);
}

#undef FUN_0004059c
#undef FUN_00042220
/* ---- r62ab f15698 */
/* FUN_00015698 @ 00015698: click on a spell row of the six-level list of member who: raise / lower the memorised count of the spell under (x, y) within the level's points, redraw its cell and store the count in base */
struct LBOX2 { int x, y; };
struct LSP2 { signed char id, cnt; };
#define DAT_000563f0 ((struct LBOX2 *)DAT_000563f0)
#define B00062b58_ap ((struct LSP2 **)B00062b58_ap)
#define DAT_00056420 ((int (*)[8])DAT_00056420)
extern void FUN_000396c0(int, int, int, int), FUN_0003e438(int, int, int, int, int); extern int FUN_0003f29c(int, int);
void FUN_00015698(int who, int x, int y, int font, struct NB *base, unsigned char *pts, int names)
{
    int j; int row; int n; int m; int lev; int d;

    for (lev = 0; lev < 6; lev++) {
        m = lev * 10;
        if (x <= DAT_000563f0[lev].x + 0x2d || x >= DAT_000563f0[lev].x + 0xa5) continue;
        d = 0;
        if (y >= DAT_000563f0[lev].y + 2 && y <= DAT_000563f0[lev].y + 9) d = -1;
        if (y >= DAT_000563f0[lev].y + 0xd && y <= DAT_000563f0[lev].y + 0x15) d = 1;
        if (d == 0) continue;
        row = x - (DAT_000563f0[lev].x + 0x2d);
        row /= 12;
        if (B00062b58_ap[lev][row].id == -1) continue;
        n = 0;
        for (j = 0; j < DAT_00056420[who][lev]; j++)
            if (B00062b58_ap[lev][j].id != -1) n += B00062b58_ap[lev][j].cnt;
        if (n + d > pts[lev]) continue;
        if (d == -1 && B00062b58_ap[lev][row].cnt == 0) return;
        B00062b58_ap[lev][row].cnt += d;
        x = DAT_000563f0[lev].x + 0x2d + row * 12;
        y = DAT_000563f0[lev].y;
        FUN_000391b0(DAT_0005c050);
        FUN_000396c0(x, y + 1, x + 0xc, y + 0x62);
        if (lev < 3) FUN_0003e438(x, 0, x, 0xc, FUN_0003f29c(font, 0));
        else FUN_0003e438(x, 0, x - 0xc8, 0xc, FUN_0003f29c(font + 1, 0));
        FUN_000396c0(0, 0, 0x18f, 0x13f);
        FUN_0004060c(x, y + 2, "[-] [+]", 1);
        FUN_0004060c(x, y + 0x19, FUN_0003e6f0(B00062b58_ap[lev][row].cnt), 1);
        FUN_0002c368(DAT_0005759c, names + m + B00062b58_ap[lev][row].id);
        FUN_00040630(x, y + 0x20, DAT_0005759c, 1, 0x44);
        base[m + B00062b58_ap[lev][row].id].lo = B00062b58_ap[lev][row].cnt;
        FUN_0002a8c8(DAT_0005c050, x, y, 0xc, 0x64);
        return;
    }
}


#undef DAT_000563f0
#undef B00062b58_ap
#undef DAT_00056420

/* ---- from src/CODE2/f15984.c */
#define FUN_000425b0 ((void (*)(void *, int, int, char *, int))FUN_000425b0)
/* FUN_00015984 @ 00015984 */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0002a510(int), FUN_00039234(void *);
extern unsigned char DAT_00056460, DAT_0005c054[]; extern int DAT_0005c050;
void FUN_00015984(int a, int b)
{
    if (DAT_00056460 == 0) {
        DAT_00056460 = 1;
        FUN_000425b0(DAT_0005c054, 0, b, "COLORS", 0x100);
        FUN_000391b0(DAT_0005c050);
        FUN_0003e510(0, 0, a, 0);
        FUN_0003e510(0xc8, 0, a + 1, 0);
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        FUN_00039234(DAT_0005c054);
    }
}

#undef FUN_000425b0
/* ---- from src/CODE2/f15a14.c */
#define FUN_0002a5b0 ((void (*)(int, int, int))FUN_0002a5b0)
#define FUN_00039234 ((void (*)(unsigned char *))FUN_00039234)
#define FUN_00042468 ((void (*)(unsigned char *, int, int, int, int, unsigned char *))FUN_00042468)
#define FUN_000425b0 ((void (*)(unsigned char *, int, int, char *, int))FUN_000425b0)
/* FUN_00015a14 @ 00015a14: on the first call after a level load, load the level palette (COLORS block of file f), darken entries 0..235 by 6/8 and show it, then redraw the status panel and flip pages */
extern unsigned char DAT_00056460, DAT_0005c054[], DAT_00058602; extern short DAT_00058600; extern int DAT_0005c050;

void FUN_00015a14(int f)
{
    unsigned char c[3] = { 0, 0, 0 };
    if (DAT_00056460) {
        DAT_00056460 = 0;
        FUN_000425b0(DAT_0005c054, 0, f, "COLORS", 0x100);
        FUN_00042468(DAT_0005c054, 0, 0xec, 6, 3, c);
        FUN_00039234(DAT_0005c054);
        FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
        DAT_0005c050 ^= 1;
    }
}

#undef FUN_0002a5b0
#undef FUN_00039234
#undef FUN_00042468
#undef FUN_000425b0
/* ---- from src/CODE2/f15aa4.c */
extern int FUN_000150dc(int mode, int i); /* module prototype */
extern void FUN_0001518c(int ch, int sel, int y, int pal, struct NB *sk, unsigned char *mx, int nm); /* module prototype */
extern void FUN_00015578(void); /* module prototype */
extern void FUN_00015698(int who, int x, int y, int font, struct NB *base, unsigned char *pts, int names); /* module prototype */
extern void FUN_00015984(int a, int b); /* module prototype */
extern void FUN_00015a14(int f); /* module prototype */
#define B00062b58_ap ((void **)B00062b58_ap)
#define FUN_0001518c ((void (*)(int, int, int, int, int, int, int))FUN_0001518c)
#define FUN_00015698 ((void (*)(int, int, int, int, int, int, int))FUN_00015698)
/* FUN_00015aa4 @ 00015aa4: run the six-entry list menu of member m until a valid entry is clicked; returns the entry (4 = cancel) */
extern void *FUN_0004104c(int); extern void FUN_000410b0(void *);
extern int FUN_0002a1f4(void);
 extern short DAT_00059e31, DAT_00059e33;
int FUN_00015aa4(int m, int cur, int a, int b, int c, int d, int e)
{
    int k, sel, y, r, x;
    for (k = 0; k < 6; k++) B00062b58_ap[k] = FUN_0004104c(0x14);
    FUN_0001518c(m, cur, a, b, c, d, e);
    for (;;) {
        if (!FUN_0002a1f4()) {
            if (DAT_00059e33 == 0x13f || DAT_00059e31 == 0x18f) FUN_00015984(a, b);
            else FUN_00015a14(b);
            continue;
        }
        FUN_00015a14(b);
        if (DAT_00059e31 < 0xf) {
            y = DAT_00059e33 - 5;
            sel = y / 0x42;
            r = y % 0x42;
            if (r >= 0 && r < 0x30 && sel != cur) {
                if (sel == 4) break;
                if (FUN_000150dc(m, sel) >= 0) break;
            }
        }
        x = DAT_00059e31;
        FUN_00015698(m, x, DAT_00059e33, a, c, d, e);
        while (FUN_0002a1f4()) ;
    }
    FUN_00015578();
    for (k = 0; k < 6; k++) FUN_000410b0(B00062b58_ap[k]);
    return sel;
}

#undef B00062b58_ap
#undef FUN_0001518c
#undef FUN_00015698
/* ---- from src/CODE2/f15bdc.c */
/* FUN_00015bdc @ 00015bdc: build the spell-slot table for a character */
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
extern unsigned char DAT_00056208[8], DAT_000562b0[], DAT_00056160[], DAT_0005613f[];
void FUN_00015bdc(int mode, int i, int row, unsigned char *tbl)
{
    int k;
    memset(DAT_00056208, 0, 8);
    memmove(DAT_00056208, tbl + row * 8, 8);
    if (mode == 0) {
        if (B000718e0_iO[i].cls[0] != 1) {
            for (k = 0; k < 8; k++) {
                if (DAT_000562b0[row * 8 + k]) DAT_00056208[k] += DAT_00056160[B000718e0_iO[i].ab[8] * 8 + k];
            }
        }
    } else if (DAT_0005613f[B000718e0_iO[i].ab[6]] != 0) {
        for (k = DAT_0005613f[B000718e0_iO[i].ab[6]]; k < 8; k++) DAT_00056208[k] = 0;
    }
}

/* ---- from src/CODE2/wip/f15c84.c */
extern int FUN_000150dc(int mode, int i); /* module prototype */
extern void FUN_0001518c(int ch, int sel, int y, int pal, struct NB *sk, unsigned char *mx, int nm); /* module prototype */
extern void FUN_00015578(void); /* module prototype */
extern void FUN_00015698(int who, int x, int y, int font, struct NB *base, unsigned char *pts, int names); /* module prototype */
extern void FUN_00015984(int a, int b); /* module prototype */
extern void FUN_00015a14(int f); /* module prototype */
/* Round 18: FUN_00015d34 (13 lines): the original keeps r in esi (live across a call) and ok in edi, whose 1 is reused for the constant 1 arguments; ok = 1 at the loop top: 12 lines. */
/* NEAR MISS module 00015aa4..00015dcf (-oa): FUN_00015aa4 and FUN_00015bdc MATCH here; FUN_00015d34 exits through FUN_00015c84's epilogue. Left in both spell screens: the original evaluates FUN_00015bdc's row argument (with the FUN_000150dc call inline in the index, which fixes the first-loop r register) before the table ternary, and pushes the two table addresses inside the branches; here the ternary is evaluated first into eax. Tried: row as a statement, if/else with two calls, - ok for - 1. Promote the whole file (dropping f15aa4.c/f15bdc.c) once both match. 2026-11-08: FUN_00015c84 as an if/else of two FUN_00015bdc calls (row expression in both) gives the right size (26 lines left: the original calls FUN_000150dc and loads the row before the class test, here after) */
#include "chars.h"
#define B00062b58_ap ((void **)B00062b58_ap)
/* FUN_00015aa4 @ 00015aa4: run the six-entry list menu of member m until a valid entry is clicked; returns the entry (4 = cancel) */
extern void *FUN_0004104c(int); extern void FUN_000410b0(void *);
extern int FUN_0002a1f4(void);
 extern short DAT_00059e31, DAT_00059e33;

/* FUN_00015bdc @ 00015bdc: build the spell-slot table for a character */
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
extern unsigned char DAT_00056208[8], DAT_000562b0[], DAT_00056160[], DAT_0005613f[];

/* FUN_00015c84 near miss (180/176): the first loop result r is kept in ESI in the original (callee-saved) but in EDX here; declaration order and loop phrasing do not change it; otherwise identical */
/* FUN_00015c84 @ 00015c84: priest spell memorisation screen for every priest in the party */
extern unsigned char DAT_00056350[], DAT_000562b0[], DAT_00056208[]; extern char *B000758dc_cl;
#define CB(i, o) (*(signed char *)(CHAR_REC(i) + (o)))
#define CW(i, o) (*(short *)(CHAR_REC(i) + (o)))
int FUN_00015c84(void)
{
    int k, r, ok = 0;
    for (k = 0; 4 > k; k = k + 1) { r = FUN_000150dc(0, k); if (r >= 0) break; }
    if (0 <= r) {
        while (k != 4) {
            ok = 1;
            r = *(short *)(CHAR_REC(k) + 0x20 + FUN_000150dc(0, k) * 2) - 1;
            if (CB(k, 0x15) == 1) FUN_00015bdc(0, k, r, DAT_00056350);
            else FUN_00015bdc(0, k, r, DAT_000562b0);
            k = FUN_00015aa4(0, k, (int)B000758dc_cl + 0x30, 0xa, (int)(CHAR_REC(k) + 0xba), (int)DAT_00056208, 0x92);
        }
    }
    return ok;
}

extern void *FUN_0004104c(int); extern void FUN_000410b0(void *);
extern int FUN_0002a1f4(void);
 extern short DAT_00059e31, DAT_00059e33;

extern int FUN_0001f2d4(int, int); extern unsigned char DAT_00056210[], DAT_0005620a;
/* Round 38: MATCH (with FUN_00015c84): the level-index read written CHAR_REC(k) + 0x20 + call * 2 (not CHAR_REC(k) + (0x20 + call * 2)): the base side then has as many tree nodes as the call side and the code generator evaluates k * 0x248 first (into ESI, before the call), as the original; FUN_00015c84 the same with ok = 1 first, which also gives both functions the shared epilogue. Round 32: ok = 1 first in the loop body: the code generator then takes the 1 of FUN_000150dc(1, k) and of the - 1 from ok's register (push edi / sub eax,edi as in the original), 48 -> 36 masked lines in module. Left: the original computes k * 0x248 before the FUN_000150dc call and keeps it in ESI (r's register); here it is computed after the call in EDX. In the twin FUN_00015c84 that product is a CSE shared with the class byte test; 7 index forms of the CW read (array, struct, operand orders): 36-48 */
/* FUN_00015d34 @ 00015d34: mage spell memorisation screen for every mage in the party */
int FUN_00015d34(void)
{
    int k, r, ok = 0;
    for (k = 0; k < 4; k += 1) { r = FUN_000150dc(1, k); if (0 <= r) break; }
    if (r >= 0) {
        while (4 != k) {
            ok = 1;
            r = *(short *)(CHAR_REC(k) + 0x20 + FUN_000150dc(1, k) * 2) - 1;
            FUN_00015bdc(1, k, r, DAT_00056210);
            if (FUN_0001f2d4(k, 0x48)) DAT_0005620a <<= 1;
            k = FUN_00015aa4(1, k, (int)B000758dc_cl + 0x32, 0xb, (int)(CHAR_REC(k) + 0x6a), (int)DAT_00056208, 0x42);
        }
    }
    return ok;
}

#undef B00062b58_ap
#undef CB
#undef CW
/* ---- from src/CODE2/f15dd0.c */
/* FUN_00015dd0 @ 00015dd0: save GAME.OPT */
extern void FUN_00041380(char *); extern int FUN_000412c8(char *); extern void FUN_000412dc(int); extern int FUN_000412b4(char *);
extern void FUN_0003f5f4(char *, int); extern void FUN_00041304(void *, unsigned, int);
extern char *PTR_s_GAME_OPT_00056138, *PTR_s_cannot_save_game_options_000560dc; extern unsigned char DAT_0005c025;
void FUN_00015dd0(void)
{
    int h;
    FUN_00041380(PTR_s_GAME_OPT_00056138);
    FUN_000412dc(FUN_000412c8(PTR_s_GAME_OPT_00056138));
    h = FUN_000412b4(PTR_s_GAME_OPT_00056138);
    if (h == -1) { FUN_0003f5f4(PTR_s_cannot_save_game_options_000560dc, 0x36); return; }
    FUN_00041304(&DAT_0005c025, 0xe, h);
    FUN_000412dc(h);
}

/* ---- from src/CODE2/f15e38.c */
#define FUN_000425b0 ((void (*)(void *, int, int, char *, int))FUN_000425b0)
/* FUN_00015e38 @ 00015e38: load GAME.OPT */
extern int FUN_000412a0(char *), FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int), FUN_00039234(void *), FUN_00038098(unsigned char), FUN_000390a8(int);
extern char *PTR_s_GAME_OPT_00056138; extern unsigned char DAT_0005c025, DAT_0005c02b, DAT_0005c02c, DAT_0005c02e, DAT_0005c054[]; extern int DAT_0005c034; extern char *DAT_0005f050;
void FUN_00015e38(void)
{
    int h = FUN_000412a0(PTR_s_GAME_OPT_00056138);
    if (h != -1) {
        FUN_000412ec(&DAT_0005c025, 0xe, h);
        FUN_000412dc(h);
        DAT_0005f050[0x6c] = DAT_0005c02e;
        FUN_000425b0(DAT_0005c054, 0, DAT_0005c034, "COLORS", 0x100);
        FUN_00039234(DAT_0005c054);
        FUN_00038098(DAT_0005c02b);
        FUN_000390a8(DAT_0005c02c);
    }
}

#undef FUN_000425b0
/* ---- from src/CODE2/f15eec.c */
/* FUN_00015eec @ 00015eec: draw the ten option rows: label k at y = 23 + 30k and the current setting (sliders for 0, 5 and 8, check boxes for the rest) */
extern void FUN_000391b0(unsigned char), FUN_0004060c(int, int, char *, int), FUN_0003975c(int, int, int, int, int);
extern int DAT_0005c050; extern unsigned char DAT_0005c025, DAT_0005c026, DAT_0005c027, DAT_0005c028, DAT_0005c029, DAT_0005c02a, DAT_0005c02b, DAT_0005c02c, DAT_0005c02e, DAT_0005c02f;
extern char *DAT_00056110[]; extern char *B000758dc_cl;
void FUN_00015eec(void)
{
    int k, ly, y;
    FUN_000391b0(DAT_0005c050);
    k = 0; ly = 0x17; y = 0xf;
    do {
        FUN_0004060c(ly, 0xf, DAT_00056110[k], 1);
        switch (k) {
        case 0: FUN_0003975c(0, y, DAT_0005c025 * 10 + 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 1: FUN_0003975c(DAT_0005c026 + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 2: FUN_0003975c(DAT_0005c027 + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 3: FUN_0003975c(DAT_0005c028 + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 4: FUN_0003975c(DAT_0005c029 + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 5: FUN_0003975c(0, y, DAT_0005c02a + 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 6: FUN_0003975c(DAT_0005c02b + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 7: FUN_0003975c(DAT_0005c02c + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 8: FUN_0003975c(0, y, DAT_0005c02e * 10 + 0x78, (int)B000758dc_cl + 0x40, 0); break;
        case 9: FUN_0003975c(DAT_0005c02f + 2, y, 0x78, (int)B000758dc_cl + 0x40, 0); break;
        }
        ly += 30; k++; y += 30;
    } while (k < 10);
}

/* ---- from src/CODE2/f16008.c */
extern void FUN_00015eec(void); /* module prototype */
/* FUN_00016008 @ 00016008: draw the title/character-creation background: random star field, coloured frame lines, the three boxes, then load the ten portraits */
#include "world.h"
#define FUN_00039234 ((void (*)(unsigned char *))FUN_00039234)
#define FUN_0003975c ((void (*)(int, int, int, char *, int))FUN_0003975c)
#define FUN_000425b0 ((void (*)(unsigned char *, int, int, char *, int))FUN_000425b0)
int rand(void);
extern void FUN_000391b0(unsigned char), FUN_0003e374(int, int, int, int, unsigned char), FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int), FUN_0002a510(int), FUN_0002a9f8(void);
extern void *FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050; extern char *B000758dc_cl; extern char *DAT_000560e4, *DAT_000560e8; extern void *B00062b30_k9[10];
void FUN_00016008(void)
{
    int x, y, k;
    FUN_000391b0(DAT_0005c050);
    for (y = 0; y < 400; y += 0x10)
        for (x = 0; x < 0x140; x += 8)
            FUN_0003975c((unsigned)rand() * 4 >> 15, y, x, B000758dc_cl + 0x35, 0);
    for (x = 8; x < 0x138; x += 8) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 9, 0, x, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 5, 0x180, x, B000758dc_cl + 0x35, 0);
    }
    for (y = 0x10; y < 0x180; y += 0x10) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xc, y, 0, B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xe, y, 0x138, B000758dc_cl + 0x35, 0);
    }
    FUN_0003975c(8, 0, 0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(0xb, 0, 0x138, B000758dc_cl + 0x35, 0);
    FUN_0003975c(4, 0x180, 0, B000758dc_cl + 0x35, 0);
    FUN_0003975c(7, 0x180, 0x138, B000758dc_cl + 0x35, 0);
    FUN_0003e374(0xf, 0x78, 0x18, 0x89, 0x3d);
    FUN_0003e374(0xa5, 0x78, 0x18, 0xaf, 0x3d);
    FUN_0003e374(0xff, 0x78, 0x18, 0xbb, 0x3d);
    FUN_0004060c(0x17, 0x7c, DAT_000560e4, 1);
    FUN_0004060c(0xad, 0x7c, DAT_000560e4, 1);
    FUN_0004060c(0x107, 0x7c, DAT_000560e4, 1);
    FUN_000405a8(0x17, 0xfc, DAT_000560e8, 1);
    FUN_000405a8(0xad, 0x122, DAT_000560e8, 1);
    FUN_000405a8(0x107, 0x12d, DAT_000560e8, 1);
    for (k = 0, x = 0xf; k < 10; k++, x += 0x1e)
        B00062b30_k9[k] = FUN_00040070(x, 0x78, 0x19, 0xc8, 0xff);
    FUN_00015eec();
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    FUN_0002a9f8();
}

extern void FUN_000391b0(unsigned char), FUN_0003e374(int, int, int, int, unsigned char), FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int), FUN_0002a510(int), FUN_0002a9f8(void);
extern void *FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050; extern char *B000758dc_cl; extern char *DAT_000560e4, *DAT_000560e8; extern void *B00062b30_k9[10];

extern int FUN_0002a1f4(void); extern void FUN_0003a380(int, int, int, void *), FUN_0002a8c8(int, int, int, int, int);
extern short DAT_00059e33; extern unsigned char DAT_0005c025;
/* FUN_000162ac: drag the level slider while the button is held */
void FUN_000162ac(void)
{
    int v;
    while (FUN_0002a1f4()) {
        v = (DAT_00059e33 - 0x90) / 10;
        if (v < 0) v = 0;
        if (v > 9) v = 9;
        if (v == DAT_0005c025) continue;
        DAT_0005c025 = v;
        v *= 10;
        FUN_000391b0(DAT_0005c050);
        FUN_0003a380(0, 0xf, 0x78, B00062b30_k9[0]);
        FUN_0003975c(1, 0xf, v + 0x78, B000758dc_cl + 0x40, 0);
        FUN_0002a8c8(DAT_0005c050, 0xf, 0x78, 0x19, 0xc8);
    }
}

extern void FUN_000391b0(unsigned char), FUN_0003e374(int, int, int, int, unsigned char), FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int), FUN_0002a510(int), FUN_0002a9f8(void);
extern void *FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050; extern char *B000758dc_cl; extern char *DAT_000560e4, *DAT_000560e8; extern void *B00062b30_k9[10];


extern unsigned char DAT_0005c02e, DAT_0005c054[]; extern int DAT_0005c034; extern char *DAT_0005f050;
/* FUN_00016354: drag the brightness slider while the button is held, reloading the palette */
void FUN_00016354(void)
{
    int v;
    while (FUN_0002a1f4()) {
        v = (DAT_00059e33 - 0x90) / 10;
        if (v < 0) v = 0;
        if (v > 14) v = 14;
        if (v == DAT_0005c02e) continue;
        DAT_0005c02e = v;
        FUN_000391b0(DAT_0005c050);
        FUN_0003a380(0, 0xff, 0x78, B00062b30_k9[8]);
        FUN_0003975c(1, 0xff, v * 10 + 0x78, B000758dc_cl + 0x40, 0);
        FUN_0002a8c8(DAT_0005c050, 0xff, 0x78, 0x19, 0xc8);
        DAT_0005f050[0x6c] = DAT_0005c02e;
        FUN_000425b0(DAT_0005c054, 0, DAT_0005c034, "COLORS", 0x100);
        FUN_00039234(DAT_0005c054);
    }
}

#undef FUN_00039234
#undef FUN_0003975c
#undef FUN_000425b0
/* ---- from src/CODE2/f16444.c */
/* ROUND 22: matches alone under the module set (-oa -j, flags.csv) and in module 0x13a78: `(0x80 - v) * DAT_0005c02a` (the product into the register of 0x80 - v, as in the original); round 21 had lost it in module with the operands the other way. */
/* FUN_00016444 @ 00016444: drag the brightness slider (the final gamma value reuses the loop variable) */
#include "world.h"
#define FUN_0003a380 ((void (*)(int, int, int, int))FUN_0003a380)
extern int FUN_0002a1f4(void); extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0002a8c8(int, int, int, int, int);
extern short DAT_00059e33; extern unsigned char DAT_0005c02a, DAT_0005c02d; extern int DAT_0005c050; extern char *B000758dc_cl;
void FUN_00016444(void)
{
    int v;
    { int d; d = DAT_0005c034; } /* STANDIN: dead read of a scalar this function does not use - one zero-savings -oa memory node in the pass-1 conflict list; the handle below is element 5 of the 10-entry table (no node), not a variable of its own */
    while (FUN_0002a1f4()) {
        v = DAT_00059e33 - 0x90;
        if (v < 0) v = 0;
        if (v > 0x80) v = 0x80;
        if (v != DAT_0005c02a) {
            DAT_0005c02a = v;
            FUN_000391b0(DAT_0005c050);
            FUN_0003a380(0, 0xa5, 0x78, B00062b30_k9[5]);
            FUN_0003975c(1, 0xa5, v + 0x78, (int)B000758dc_cl + 0x40, 0);
            FUN_0002a8c8(DAT_0005c050, 0xa5, 0x78, 0x19, 0xc8);
        }
    }
    v = B00075618_b1.b2;
    v = 0x80 - ((0x80 - v) * DAT_0005c02a + 0x40) / 128;
    DAT_0005c02d = v;
}

#undef FUN_0003a380
/* ---- from src/CODE2/f16548.c */
extern void FUN_00015eec(void); /* module prototype */
extern void FUN_00016008(void); /* module prototype */
extern void FUN_000162ac(void); /* module prototype */
extern void FUN_00016354(void); /* module prototype */
extern void FUN_00016444(void); /* module prototype */
/* FUN_00016548 @ 00016548: options screen loop: wait for a click, toggle or drag the option under the mouse, redraw; right button leaves */
#include "world.h"
extern int FUN_0002a1f4(void);
extern void FUN_00030994(void), FUN_0002a510(int), FUN_0002a9f8(void);
extern void FUN_00038098(unsigned char), FUN_000390a8(int), FUN_00038e58(int, int, int), FUN_00040040(void *);
extern short DAT_00059e31, DAT_00059e33, DAT_00059e35;
extern unsigned char DAT_0005c026, DAT_0005c027, DAT_0005c028, DAT_0005c029, DAT_0005c02b, DAT_0005c02c;
extern int DAT_0005c050; extern void *B00062b30_k9[10];
void FUN_00016548(void)
{
    int x, y, i;
    FUN_00016008();
    for (;;) {
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        if (DAT_00059e35 & 2) break;
        x = DAT_00059e33;
        y = DAT_00059e31;
        if (x < 0x78) continue;
        y -= 0xf;
        if (y % 30 >= 25) continue;
        y /= 30;
        switch (y) {
        case 0: FUN_000162ac(); break;
        case 1: if (x < 0xa8) DAT_0005c026 ^= 1; break;
        case 2: if (x < 0xa8) DAT_0005c027 ^= 1; break;
        case 3: if (x < 0xa8) DAT_0005c028 ^= 1; break;
        case 4: if (x < 0xa8) DAT_0005c029 ^= 1; break;
        case 5: FUN_00016444(); break;
        case 6: if (x < 0xa8) { DAT_0005c02b ^= 1; FUN_00038098(DAT_0005c02b); } break;
        case 7:
            if (x < 0xa8) {
                DAT_0005c02c ^= 1;
                FUN_000390a8(DAT_0005c02c);
                if (DAT_0005c02c) FUN_00038e58(B00075618_b1.b4, 1, 0x9c4);
            }
            break;
        case 8: FUN_00016354(); break;
        case 9: if (x < 0xa8) FUN_00030994(); break;
        }
        FUN_00015eec();
        FUN_0002a510(DAT_0005c050);
        FUN_0002a9f8();
        DAT_0005c050 ^= 1;
    }
    for (i = 0; i < 9; i++) FUN_00040040(B00062b30_k9[i]);
}

/* ---- from src/CODE2/f166e8.c */
/* FUN_000166e8 @ 000166e8: save the game into SAVE.DAT of the save directory under slot name slot (-1: TEMP); 1 on a write error */
#include <string.h>
#define DAT_0005d8a8 ((int *)&DAT_0005d8a8)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define FUN_00041304 ((int (*)(void *, int, int))FUN_00041304)
#pragma pack(1)
struct G { unsigned char n, cols, maxw, y0, kind; short *slots; unsigned char mask; };
#pragma pack()
extern char DAT_0005c020[], B00062990_ll[160], B00072200_ew[], DAT_00056461[], B000748ec_bk[], DAT_0005a808[];
extern int DAT_0005c6c8, B000755d0_ao, B000755d4_ak, DAT_0005c658, DAT_0005fd08, DAT_0005cf4c, DAT_0005c038, DAT_0005a7e4, DAT_0005f920, DAT_0005f91c;
extern short DAT_0005f03c, DAT_0005f03e, DAT_00056dae, DAT_00058600; extern unsigned char DAT_00058602, DAT_000567ec[], DAT_00056fa0[]; extern struct G DAT_00057330[];
extern int FUN_000412c8(char *), FUN_000412b4(char *); extern void FUN_00041380(char *), FUN_000412dc(int); extern unsigned FUN_00040700(void);
int FUN_000166e8(int slot)
{
    int fh; int t;
    strcpy(B00062990_ll, DAT_0005c020);
    strcat(B00062990_ll, "\\");
    strcat(B00062990_ll, "SAVE.DAT");
    FUN_00041380(B00062990_ll);
    FUN_000412dc(FUN_000412c8(B00062990_ll));
    fh = FUN_000412b4(B00062990_ll);
    if (fh == -1) return 1;
    if (slot == -1) strcpy(B00062990_ll, "TEMP");
    else strcpy(B00062990_ll, DAT_00056461 + slot * 0x32);
    if (FUN_00041304(B00062990_ll, 0x32, fh) != 0x32) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(B00072200_ew, 0x20, fh) != 0x20) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005c6c8, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&B000755d0_ao, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&B000755d4_ak, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005c658, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005f03c, 2, fh) != 2) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005f03e, 2, fh) != 2) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005fd08, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_00056dae, 2, fh) != 2) {
        FUN_000412dc(fh);
        return 1;
    }
    t = FUN_00040700();
    if (FUN_00041304(&t, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005cf4c, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_00058600, 2, fh) != 2) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_00058602, 1, fh) != 1) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(M000718e0_iO, 0x920, fh) != 0x920) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005c038, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(B000748ec_bk, DAT_0005c038 * 0x16, fh) != DAT_0005c038 * 0x16) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(DAT_0005d8a8, 8, fh) != 8) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005a7e4, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    for (t = 0; t < 0x3e; t++) {
        if (FUN_00041304(DAT_00057330[t].slots, DAT_00057330[t].n * 2, fh) != DAT_00057330[t].n * 2) {
            FUN_000412dc(fh);
            return 1;
        }
        if (FUN_00041304(&DAT_00057330[t].mask, 1, fh) != 1) {
            FUN_000412dc(fh);
            return 1;
        }
    }
    if (FUN_00041304(&DAT_0005f920, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(&DAT_0005f91c, 4, fh) != 4) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(DAT_000567ec, 0xf, fh) != 0xf) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(DAT_0005a808, 0x16d0, fh) != 0x16d0) {
        FUN_000412dc(fh);
        return 1;
    }
    if (FUN_00041304(DAT_00056fa0, 0x10, fh) != 0x10) {
        FUN_000412dc(fh);
        return 1;
    }
    FUN_000412dc(fh);
    return 0;
}

#undef DAT_0005d8a8
#undef M000718e0_iO
#undef FUN_00041304
#pragma pack()
/* ---- from src/CODE2/f16c68.c */
/* FUN_00016c68 @ 00016c68 */
extern unsigned char *FUN_0002e8c8(int, int);
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */
 extern int DAT_0005cf6c;
void FUN_00016c68(void)
{
    unsigned char *p = FUN_0002e8c8(B000755d2_ai, B000755d6_ae);
    DAT_0005cf6c = 0;
    if (p && p[0] == 6 && (*(int *)(p + 1) & 4) && p[6]) DAT_0005cf6c = 1;
}

/* ---- FUN_00017938 (round 50) */
/* Round 50: defined here, after FUN_00016c68, because the original's code for it lies here (0x16cad..0x17070): FUN_00017874 ends in a call of it (call + ret -> jmp) and StraightenCode pushes the head (entry up to the fh == -1 return) down behind that jump at 0x17938 (recipe 172; srcpos.csv). The body is spliced as FUN_00016c68's extent. Matches since round 54 (FUN_000175cc matched; its 4 extra bytes had moved the head's jne into the body). Written like its twin FUN_000166e8 (the save); the frame (pos, sv, sw, no, lv, t, held, h2 at 0..0x1c) is the reverse declaration order. */
/* FUN_00017938 @ 00017938: load the game from SAVE.DAT of the save directory (after the slot name); 1 if it cannot be opened */
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
extern unsigned char DAT_0005d681, DAT_0005d682, DAT_0005c02f, DAT_0005cf5a, DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d;
extern char B00062990_ll[160], DAT_0005c020[], B00072200_ew[], B000748ec_bk[], DAT_0005a808[];
extern unsigned char DAT_000567ec[], DAT_00056fa0[]; extern int DAT_0005d8a8;
extern int B000755d0_ao, B000755d4_ak, DAT_0005fd08, DAT_0005cf4c, DAT_00056f90, DAT_00056f94, DAT_00056f98, DAT_00056f9c, DAT_0005c6c8, DAT_0005bf44, DAT_0005c038;
extern short DAT_0005f03c, DAT_0005f03e, DAT_00056dae;
extern int FUN_000412a0(char *); extern long FUN_0004131c(long, int, int);
extern void FUN_0002c0c0(int), FUN_00040738(int), FUN_0002a344(short, unsigned char), FUN_0002e74c(int), FUN_00041edc(int), FUN_00041f38(int), FUN_000281b4(int);
void *memmove(void *, const void *, unsigned);
int FUN_00017938(void)
{
    int t; int lv; int no; int sw; int sv; int pos; short held; unsigned char h2;
    int fh; int r; int i; void *p;
    DAT_0005d681 = 0;
    DAT_0005d682 = 0;
    strcpy(B00062990_ll, DAT_0005c020);
    strcat(B00062990_ll, "\\");
    strcat(B00062990_ll, "SAVE.DAT");
    fh = FUN_000412a0(B00062990_ll);
    if (fh == -1) return 1;
    FUN_0004131c(0x32, 0, fh);
    FUN_000412ec(B00072200_ew, 0x20, fh);
    FUN_000412ec(&lv, 4, fh);
    FUN_000412ec(&B000755d0_ao, 4, fh);
    FUN_000412ec(&B000755d4_ak, 4, fh);
    FUN_000412ec(&pos, 4, fh);
    FUN_0002c0c0(pos);
    if (DAT_0005c02f) {
        *(unsigned short *)&B000755d0_ao = 0x8000;
        *(unsigned short *)&B000755d4_ak = 0x8000;
    }
    FUN_000412ec(&DAT_0005f03c, 2, fh);
    FUN_000412ec(&DAT_0005f03e, 2, fh);
    FUN_000412ec(&DAT_0005fd08, 4, fh);
    FUN_000412ec(&DAT_00056dae, 2, fh);
    FUN_000412ec(&t, 4, fh);
    FUN_00040738(t);
    FUN_000412ec(&DAT_0005cf4c, 4, fh);
    FUN_000412ec(&held, 2, fh);
    FUN_000412ec(&h2, 1, fh);
    FUN_0002a344(held, h2);
    FUN_000412ec(M000718e0_iO, 0x920, fh);
    FUN_000412ec(&no, 4, fh);
    FUN_000412ec(B000748ec_bk, no * 0x16, fh);
    for (i = 0; i < 4; i++) {
        if (M000718e0_iO[i].fl & 0x8000) continue;
        if (M000718e0_iO[i].cls[0] == 1) M000718e0_iO[i].sp |= 4;
        if (M000718e0_iO[i].cls[0] == 4 || M000718e0_iO[i].cls[1] == 4 || M000718e0_iO[i].cls[2] == 4) M000718e0_iO[i].sp |= 2;
        if (M000718e0_iO[i].cls[0] == 3 || M000718e0_iO[i].cls[1] == 3 || M000718e0_iO[i].cls[2] == 3) M000718e0_iO[i].sp |= 1;
    }
    FUN_000412ec(&DAT_0005d8a8, 8, fh);
    FUN_000412ec(&t, 4, fh);
    FUN_0002e74c(t);
    for (t = 0; t < 0x3e; t++) {
        FUN_000412ec(DAT_00057330[t].slots, DAT_00057330[t].n * 2, fh);
        FUN_000412ec(&DAT_00057330[t].mask, 1, fh);
    }
    FUN_000412ec(&sw, 4, fh);
    FUN_000412ec(&sv, 4, fh);
    if ((r = FUN_000412ec(B00062990_ll, 0xf, fh)) == 0xf) memmove(DAT_000567ec, B00062990_ll, r);
    p = FUN_0004104c(0x248);
    for (t = 0; t < 10; t++) {
        if ((r = FUN_000412ec(p, 0x248, fh)) == 0x248) memmove(DAT_0005a808 + r * t, p, r);
    }
    if ((r = FUN_000412ec(p, 0x10, fh)) == 0x10) memmove(DAT_00056fa0, p, r);
    FUN_000410b0(p);
    FUN_000412dc(fh);
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    FUN_00041edc(sw);
    FUN_00041f38(sv);
    DAT_00056f90 = 0;
    DAT_00056f94 = 0;
    DAT_00056f98 = 0;
    DAT_00056f9c = 0;
    DAT_0005c6c8 = -1;
    FUN_000281b4(lv);
    DAT_0005bf44 = 9999;
    DAT_0005c038 = no;
    FUN_00016c68();
    return 0;
}
#undef M000718e0_iO


/* ---- from src/CODE2/wip/f17070.c */
#define B00062b30_k9 ((int *)B00062b30_k9)
#define FUN_00040070 ((int (*)(int, int, int, int, int))FUN_00040070)
#define FUN_000412ec ((void (*)(char *, int, int))FUN_000412ec)
/* FUN_00017070 matches in module 0x13a78 (round 15): the button coordinates, x = k * 2, y = k * 0x25 + 0x15, y2 = k * 0x25 + 0x1d
   and the table slot B00062b30_k9[k], are written from the counter, not kept as variables: the loop optimiser makes them
   induction variables and puts their initial stores after the name pointer's (the original order k, ebp, x, y, off, y2);
   `int n, k, fd` gives their frame slots. Earlier note: do-while with k = 0 first put the counter store first. */
/* FUN_00017070 @ 00017070: list the ten save-game slots: read each slot name (or EMPTY) and draw the buttons */
char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern int FUN_000412a0(char *); extern void FUN_000412dc(int), FUN_0003975c(int, int, int, int, int), FUN_0004060c(int, int, char *, int);
extern char DAT_00056461[], DAT_0005668c[], *PTR_s_EMPTY_000560ec; 
void FUN_00017070(int a)
{
    int n, k, fd;
    k = 0;
    do {
        n = k + 1;
        DAT_0005668c[4] = n / 10 + '0';
        DAT_0005668c[5] = n % 10 + '0';
        fd = FUN_000412a0(DAT_0005668c);
        if (fd == -1) {
            strcpy(DAT_00056461 + (k + 1) * 0x32, PTR_s_EMPTY_000560ec);
        } else {
            FUN_000412ec(DAT_00056461 + (k + 1) * 0x32, 0x32, fd);
            FUN_000412dc(fd);
        }
        B00062b30_k9[k] = FUN_00040070(k * 0x25 + 0x1d, 0x64, 0xf, 0xd8, 0xff);
        FUN_0003975c(k * 2, k * 0x25 + 0x15, 0x14, a, 0);
        FUN_0004060c(k * 0x25 + 0x1d, 0x64, DAT_00056461 + (k + 1) * 0x32, 1);
        k++;
    } while (k < 10);
}

#undef B00062b30_k9
#undef FUN_00040070
#undef FUN_000412ec
/* ---- from src/CODE2/f1719c.c */
#define B00062b30_k9 ((int *)B00062b30_k9)
#define FUN_00040040 ((void (*)(int))FUN_00040040)
/* FUN_0001719c @ 0001719c: free the ten sprite handles */
 
void FUN_0001719c(void) { int k; for (k = 0; k < 10; k++) FUN_00040040(B00062b30_k9[k]); }

#undef B00062b30_k9
#undef FUN_00040040
/* ---- from src/CODE2/f171b8.c */
extern void FUN_00015eec(void); /* module prototype */
extern void FUN_00017070(int a); /* module prototype */
#define FUN_00040070 ((void *(*)(int, int, int, int, int))FUN_00040070)
/* FUN_000171b8 @ 000171b8: redraw the character-creation background (star field and frame) and the panel of party member m */
int rand(void);
extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0003e374(int, int, int, int, unsigned char), FUN_0004060c(int, int, char *, int), FUN_000405a8(int, int, char *, int), FUN_0002a510(int), FUN_0002a9f8(void);

extern int DAT_0005c050; extern char *DAT_000560e4, *DAT_000560e8; extern void *B00062b30_k9[10]; extern char *B000758dc_cl;

void FUN_000171b8(int m)
{
    int x, y;
    FUN_000391b0(DAT_0005c050);
    for (y = 0; y < 400; y += 0x10)
        for (x = 0; x < 0x140; x += 8)
            FUN_0003975c((unsigned)rand() * 4 >> 15, y, x, (int)B000758dc_cl + 0x35, 0);
    for (x = 8; x < 0x138; x += 8) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 9, 0, x, (int)B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 5, 0x180, x, (int)B000758dc_cl + 0x35, 0);
    }
    for (y = 0x10; y < 0x180; y += 0x10) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xc, y, 0, (int)B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xe, y, 0x138, (int)B000758dc_cl + 0x35, 0);
    }
    FUN_0003975c(8, 0, 0, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(0xb, 0, 0x138, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(4, 0x180, 0, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(7, 0x180, 0x138, (int)B000758dc_cl + 0x35, 0);
    FUN_00017070(m);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    FUN_0002a9f8();
    FUN_000391b0(DAT_0005c050);
}

#undef FUN_00040070
/* ---- from src/CODE2/f17378.c */
/* FUN_00017378 @ 00017378: delete all files of the current directory through an FCB ("???????????", DOS 13h) */
#include <string.h>
extern char B00062b70_ah[48];
void fcb_delete(char *fcb);
#pragma aux fcb_delete = 0xb4 0x13 0xcd 0x21 parm [edx] modify [eax];
void FUN_00017378(void)
{
    B00062b70_ah[0] = 0;
    strncpy(B00062b70_ah + 1, "???????????", 11);
    fcb_delete(B00062b70_ah);
}

/* ---- from src/CODE2/f173a0.c */
/* FUN_000173a0 @ 000173a0: copy every file of directory src into directory dst (save-game slots); 1 on a read/write error, 0 when done or the directory is empty */
#include <string.h>
#include <dos.h>
#define FUN_000412ec ((void (*)(void *, int, int))FUN_000412ec)
#define FUN_00041304 ((int (*)(void *, int, int))FUN_00041304)
extern char B000628f0_jm[160], B00062850_hl[160], B000627b0_dn[160];
extern int FUN_0004127c(char *), FUN_000412a0(char *), FUN_000412c8(char *), FUN_000412b4(char *);
extern void *FUN_0004104c(int); extern void FUN_000412dc(int), FUN_00041380(char *), FUN_000410b0(void *);
int FUN_000173a0(char *src, char *dst)
{
    struct find_t ff; int size, fh; void *buf;
    strcpy(B000628f0_jm, src);
    strcat(B000628f0_jm, "\\*.*");
    if (_dos_findfirst(B000628f0_jm, 0, &ff)) return 0;
    do {
        strcpy(B00062850_hl, src);
        strcat(B00062850_hl, "\\");
        strcat(B00062850_hl, ff.name);
        size = FUN_0004127c(B00062850_hl);
        fh = FUN_000412a0(B00062850_hl);
        if (fh == -1) return 1;
        buf = FUN_0004104c(size);
        FUN_000412ec(buf, size, fh);
        FUN_000412dc(fh);
        strcpy(B000627b0_dn, dst);
        strcat(B000627b0_dn, "\\");
        strcat(B000627b0_dn, ff.name);
        FUN_00041380(B000627b0_dn);
        FUN_000412dc(FUN_000412c8(B000627b0_dn));
        fh = FUN_000412b4(B000627b0_dn);
        if (fh == -1) {
            FUN_000410b0(buf);
            return 1;
        }
        if (FUN_00041304(buf, size, fh) != size) {
            FUN_000410b0(buf);
            FUN_000412dc(fh);
            return 1;
        }
        FUN_000412dc(fh);
        FUN_000410b0(buf);
    } while (!_dos_findnext(&ff));
    return 0;
}

#undef FUN_000412ec
#undef FUN_00041304
/* ---- from src/CODE2/wip/f175cc.c */
/* Round 54: MATCH in module context: the loop as `key = 0; while (key != 0xd) { ... }` (the do-while had the same code but one temp fewer in the slot sort input, which put key and the hoisted row*4 in each other's slots; sw.py: any single insert at 0-9 / 39-49). */
/* Round 50 (real 10.0a, 16 compiles + slot trace): the only difference is the frame slots of key (t9) and the hoisted row*4 (t17): sw.py on the trace gives the original order after removing any one of 15 later temps of the slot input (t40 .. t62, among them the loop constants 1 / 0x64 / 0xd / 2 and OFFSET B00062760_fl) or inserting one at input 0..9 / 39..49 (a parity question). Code-neutral rewrites tried, all unchanged (7 lines): first = 1; redraw = 1 / redraw = first = 1 / y in two statements / 0x1d + row*0x25 / != 0 / continue for the Enter test / '\r' / block-scope key / first != 0 / an unused n / a block around the loop / (char)key / strlen into n at either site / the length test as two ifs / the call inside the condition / first set before strcpy / no int* or prototype cast views. This function's 4 extra bytes ([esp+4] for key) are also what keeps FUN_00017938's head off: its jne into the body crosses this function. */
/* Round 18: module 0x13a78 is -j (recipe 60): with -ox -oe -oa -ot -j in module context 12 -> 6 lines (key and the row*4 temp slots remain). */
/* Formerly NEAR MISS (flags -3s -ox -oe -ot -j -w0: the ctype tests read _IsTable with movsx, so plain char is signed in this module), 219 lines from one cause: key and the hoisted row*4 temp swap stack slots ([esp] / [esp+4]; 2 bytes longer). Declaration orders, an explicit offset variable or pointer, assignment forms tried */
/* FUN_000175cc @ 000175cc: edit the text line of row row (save-game name): Esc returns 0, Enter copies the edited text back and returns 1; backspace deletes, printable keys append while the text fits (49 chars, 210 pixels); the first key replaces the old text */
#include <string.h>
#include <ctype.h>
#define B00062b30_k9 ((int *)B00062b30_k9)
#define FUN_0003a380 ((void (*)(int, int, int, int))FUN_0003a380)
#define FUN_00040aec ((int (*)(void))FUN_00040aec)
extern char B00062760_fl[80]; extern int DAT_0005c050;
extern void FUN_000391b0(unsigned char), FUN_0004060c(int, int, char *, int), FUN_00040354(int, int), FUN_0002a8c8(int, int, int, int, int);
extern int FUN_00040288(char *, int);
int FUN_000175cc(char *text, int row)
{
    int key, y, first, redraw;
    FUN_000391b0(DAT_0005c050);
    strcpy(B00062760_fl, text);
    y = row * 0x25 + 0x1d;
    first = 1;
    redraw = first;
    key = 0;
    while (key != 0xd) {
        if (redraw) {
            FUN_0003a380(0, y, 0x64, B00062b30_k9[row]);
            FUN_0004060c(y, 0x64, B00062760_fl, 1);
            FUN_00040354(0x7c, 1);
            FUN_0002a8c8(DAT_0005c050, y, 0x64, 0xa, 0xd8);
            redraw = 0;
        }
        key = FUN_00040aec();
        if (key == 0x1b) return 0;
        if (key != 0xd) {
            if (key == 8) {
                if (strlen(B00062760_fl) > 0) {
                    redraw = 1;
                    B00062760_fl[strlen(B00062760_fl) - 1] = 0;
                }
            } else if (strlen(B00062760_fl) < 0x31 && FUN_00040288(B00062760_fl, 1) < 0xd2) {
                if (first) memset(B00062760_fl, 0, 0x50);
                if (isalnum(key) || isspace(key) || ispunct(key)) {
                    redraw = 1;
                    B00062760_fl[strlen(B00062760_fl)] = key;
                }
            }
            first = 0;
        }
    }
    strcpy(text, B00062760_fl);
    return 1;
}

#undef B00062b30_k9
#undef FUN_0003a380
#undef FUN_00040aec
/* ---- from src/CODE2/f177a0.c */
extern int FUN_000166e8(int slot); /* module prototype */
extern void FUN_00017378(void); /* module prototype */
extern int FUN_000173a0(char *src, char *dst); /* module prototype */
extern void FUN_0001803c(int a); /* module prototype */
#define FUN_0001803c ((void (*)(char *))FUN_0001803c)
/* FUN_000177a0 @ 000177a0: quick save into SAVE00\SAVE.DAT */
int mkdir(const char *); int chdir(const char *);
extern void FUN_000271fc(int), FUN_0002c21c(char *), FUN_0003f580(char *); 
extern unsigned char DAT_0005a79d; extern int DAT_0005c6c8; extern char DAT_0005668c[], DAT_0005c020[];
extern char *PTR_s_Game_not_quick_saved_000560b8, *PTR_s_Could_not_quick_save_000560b4, *DAT_000560b0;
void FUN_000177a0(void)
{
    DAT_0005a79d = 0;
    FUN_000271fc(DAT_0005c6c8);
    DAT_0005a79d = 1;
    if (FUN_000166e8(0) == 0) {
        DAT_0005668c[4] = '0';
        DAT_0005668c[5] = '0';
        DAT_0005668c[6] = 0;
        mkdir(DAT_0005668c);
        if (chdir(DAT_0005668c)) { FUN_0002c21c(PTR_s_Could_not_quick_save_000560b4); return; }
        FUN_00017378();
        if (chdir("..")) FUN_0003f580(DAT_000560b0);
        if (FUN_000173a0(DAT_0005c020, DAT_0005668c) == 1) { FUN_0002c21c(PTR_s_Could_not_quick_save_000560b4); return; }
        DAT_0005668c[6] = '\\';
    } else FUN_0001803c(PTR_s_Game_not_quick_saved_000560b8);
}

#undef FUN_0001803c
/* ---- from src/CODE2/m17874.c */
extern void FUN_00017378(void); /* module prototype */
extern int FUN_000173a0(char *src, char *dst); /* module prototype */
/* FUN_00017874 @ 00017874: prepare the save directory SAVE00: chdir into it (or report), back to the game directory, then copy the current game into it and continue with FUN_00017938 (tail call, falls through). FUN_00017938 is defined after FUN_00016c68 (round 50) */
#include <direct.h>
#include <string.h>
extern unsigned char DAT_0005d681, DAT_0005d682; extern int FUN_000412a0(char *); extern char B00062990_ll[160], DAT_0005668c[], DAT_0005c020[], *DAT_000560bc, *DAT_000560b0, *DAT_000560c0;
extern void FUN_0002c21c(char *), FUN_0003f580(char *); extern int FUN_00017938(void);
void FUN_00017874(void)
{
    DAT_0005668c[4] = '0';
    DAT_0005668c[5] = '0';
    DAT_0005668c[6] = 0;
    if (chdir(DAT_0005668c)) {
        FUN_0002c21c(DAT_000560bc);
        return;
    }
    if (chdir("..")) FUN_0003f580(DAT_000560b0);
    if (chdir(DAT_0005c020)) {
        FUN_0002c21c(DAT_000560bc);
        return;
    }
    FUN_00017378();
    if (chdir("..")) FUN_0003f580(DAT_000560b0);
    if (FUN_000173a0(DAT_0005668c, DAT_0005c020) == 1) FUN_0003f580(DAT_000560c0);
    DAT_0005668c[6] = '\\';
    FUN_00017938();
}



/* ---- from src/CODE2/f179e0.c */
extern int FUN_000166e8(int slot); /* module prototype */
extern void FUN_000171b8(int m); /* module prototype */
extern void FUN_00017378(void); /* module prototype */
extern int FUN_000173a0(char *src, char *dst); /* module prototype */
extern int FUN_000175cc(char *text, int row); /* module prototype */
#define B00062b30_k9 ((int *)B00062b30_k9)
#define FUN_00040040 ((void (*)(int))FUN_00040040)
/* FUN_000179e0 @ 000179e0: the save-game screen: pick a slot, confirm, create the directory and write the game; 2 = right-click cancel */
int mkdir(const char *); int chdir(const char *);
extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0002a8c8(int, int, int, int, int), FUN_0003f580(char *);
extern int FUN_0002a1f4(void);
extern int DAT_0005c050; extern short DAT_00059e31, DAT_00059e33, DAT_00059e35; extern char DAT_00056461[], DAT_0005668c[], DAT_0005c020[], *DAT_000560b0; extern char *B000758dc_cl;
int FUN_000179e0(void)
{
    int x, y, cx, r, n, k;
    r = 0;
    FUN_000171b8((int)B000758dc_cl + 0x41);
    while (1) {
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        x = DAT_00059e31;
        y = DAT_00059e33;
        if (DAT_00059e35 & 2) return 2;
        if (x < 0x15 || x >= 0x17b || y < 0x14 || y >= 0x5c) continue;
        x -= 0x15;
        if (x % 0x25 > 0x19) continue;
        x /= 0x25;
        FUN_000391b0(DAT_0005c050);
        cx = x * 0x25 + 0x15;
        FUN_0003975c(x * 2 + 1, cx, 0x14, (int)B000758dc_cl + 0x41, 0);
        FUN_0002a8c8(DAT_0005c050, cx, 0x14, 0x19, 0x48);
        if (FUN_000175cc(DAT_00056461 + (x + 1) * 0x32, x)) {
            n = x + 1;
            if (FUN_000166e8(n) == 0) {
                DAT_0005668c[4] = n / 10 + '0';
                DAT_0005668c[5] = n % 10 + '0';
                DAT_0005668c[6] = 0;
                mkdir(DAT_0005668c);
                if (chdir(DAT_0005668c) == 0) {
                    FUN_00017378();
                    if (chdir("..")) FUN_0003f580(DAT_000560b0);
                    r = FUN_000173a0(DAT_0005c020, DAT_0005668c);
                    DAT_0005668c[6] = '\\';
                } else {
                    r = 1;
                }
            } else {
                r = 1;
            }
        }
        break;
    }
    for (k = 0; k < 10; k++) FUN_00040040(B00062b30_k9[k]);
    return r;
}

#undef B00062b30_k9
#undef FUN_00040040
/* ---- from src/CODE2/f17b94.c */
extern void FUN_000171b8(int m); /* module prototype */
extern void FUN_00017378(void); /* module prototype */
extern int FUN_000173a0(char *src, char *dst); /* module prototype */
extern int FUN_00017938(void); /* module prototype */
#define B00062b30_k9 ((int *)B00062b30_k9)
#define FUN_00040040 ((void (*)(int))FUN_00040040)
/* FUN_00017b94 @ 00017b94: the load-game screen: pick a slot and restore it; 1 when the slot is missing, 2 = right-click cancel */
int chdir(const char *);
extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_0002a8c8(int, int, int, int, int), FUN_0003f580(char *);
extern int FUN_0002a1f4(void);
extern int DAT_0005c050; extern short DAT_00059e31, DAT_00059e33, DAT_00059e35; extern char DAT_0005668c[], DAT_0005c020[], *DAT_000560b0, *DAT_000560c0; extern char *B000758dc_cl;
int FUN_00017b94(void)
{
    int x, y, cx, r, n, k;
    FUN_000171b8((int)B000758dc_cl + 0x64);
    while (1) {
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        x = DAT_00059e31;
        y = DAT_00059e33;
        if (DAT_00059e35 & 2) return 2;
        if (x < 0x15 || x >= 0x17b || y < 0x14 || y >= 0x5c) continue;
        x -= 0x15;
        if (x % 0x25 > 0x19) continue;
        x /= 0x25;
        FUN_000391b0(DAT_0005c050);
        cx = x * 0x25 + 0x15;
        FUN_0003975c(x * 2 + 1, cx, 0x14, (int)B000758dc_cl + 0x64, 0);
        n = x + 1;
        FUN_0002a8c8(DAT_0005c050, cx, 0x14, 0x19, 0x48);
        DAT_0005668c[4] = n / 10 + '0';
        DAT_0005668c[5] = n % 10 + '0';
        DAT_0005668c[6] = 0;
        if (chdir(DAT_0005c020) != 0) break;
        FUN_00017378();
        if (chdir("..")) FUN_0003f580(DAT_000560b0);
        r = FUN_000173a0(DAT_0005668c, DAT_0005c020);
        DAT_0005668c[6] = '\\';
        if (r != 1) {
            r = FUN_00017938();
            for (k = 0; k < 10; k++) FUN_00040040(B00062b30_k9[k]);
            return r;
        }
        FUN_0003f580(DAT_000560c0);
    }
    r = 1;
    for (k = 0; k < 10; k++) FUN_00040040(B00062b30_k9[k]);
    return r;
}

#undef B00062b30_k9
#undef FUN_00040040
/* ---- from src/CODE2/f17d44.c */
#define FUN_000391b0 ((void (*)(int))FUN_000391b0)
/* FUN_00017d44 @ 00017d44: yes/no dialog: draw a stone frame from random tiles, the message and the two buttons, then wait for a click on YES (0) or NO (1) */
int rand(void);
extern void FUN_0003975c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int), FUN_0002a510(int), FUN_0002a9f8(void);
extern int FUN_0002a1f4(void);
 extern char *B000758dc_cl;
extern short DAT_00059e31, DAT_00059e33;
int FUN_00017d44(char *msg)
{
    int x, y;
    FUN_000391b0(*(unsigned char *)&DAT_0005c050); /* STANDIN: byte views of the int page flag; the address taken keeps this function without a DAT_0005c050 -oa node */
    for (x = 0xa0; x < 0xf0; x += 0x10)
        for (y = 0x20; y < 0x120; y += 8)
            FUN_0003975c((unsigned)rand() * 4 >> 15, x, y, (int)B000758dc_cl + 0x35, 0);
    for (y = 0x20; y < 0x118; y += 8) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 9, 0xa0, y, (int)B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 5, 0xe0, y, (int)B000758dc_cl + 0x35, 0);
    }
    for (x = 0xb0; x < 0xe0; x += 0x10) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xc, x, 0x20, (int)B000758dc_cl + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xe, x, 0x118, (int)B000758dc_cl + 0x35, 0);
    }
    FUN_0003975c(8, 0xa0, 0x20, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(0xb, 0xa0, 0x118, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(4, 0xe0, 0x20, (int)B000758dc_cl + 0x35, 0);
    FUN_0003975c(7, 0xe0, 0x118, (int)B000758dc_cl + 0x35, 0);
    FUN_00040508(0xaa, 0x20, 0x100, msg, 1);
    FUN_0003975c(0, 0xc8, 0x60, (int)B000758dc_cl + 0x63, 0);
    FUN_0003975c(2, 0xc8, 0xb0, (int)B000758dc_cl + 0x63, 0);
    FUN_0002a510(DAT_0005c050);
    *(unsigned char *)&DAT_0005c050 ^= 1;
    FUN_0002a9f8();
    FUN_000391b0(*(unsigned char *)&DAT_0005c050);
    for (;;) {
        while (FUN_0002a1f4());
        while (!FUN_0002a1f4());
        if (DAT_00059e31 < 0xc8 || DAT_00059e31 > 0xe0) continue;
        if (DAT_00059e33 >= 0x60 && DAT_00059e33 < 0x90) {
            FUN_0003975c(1, 0xc8, 0x60, (int)B000758dc_cl + 0x63, 0);
            FUN_0002a510(DAT_0005c050);
            *(unsigned char *)&DAT_0005c050 ^= 1;
            FUN_000391b0(*(unsigned char *)&DAT_0005c050);
            return 0;
        }
        if (DAT_00059e33 >= 0xb0 && DAT_00059e33 < 0xe0) {
            FUN_0003975c(3, 0xc8, 0xb0, (int)B000758dc_cl + 0x63, 0);
            FUN_0002a510(DAT_0005c050);
            *(unsigned char *)&DAT_0005c050 ^= 1;
            FUN_000391b0(*(unsigned char *)&DAT_0005c050);
            return 1;
        }
    }
}

#undef FUN_000391b0
/* ---- from src/CODE2/f1803c.c */
/* FUN_0001803c @ 0001803c */
extern void FUN_0002a9f8(void); extern void FUN_0002c40c(int, int, int, int, int);
extern void FUN_00023fd4(int, int, int, int, int, int, int); extern void FUN_0002a510(int);
extern int DAT_0005c050;
void FUN_0001803c(int a)
{
    FUN_0002a9f8();
    FUN_0002c40c(DAT_0005c050, 0xf, 0x40, 0x32, 0xc0);
    FUN_00023fd4(0, 0x14, 0x46, 0x12, 0xb4, a, 1);
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
}

/* ---- from src/CODE2/wip/f180ac.c */
/* Round 64 lane AM: MATCH in module context (realcc): the row height 0x28 as the local w (divisor, argument, product), cur and old one variable in the click block, img declared last. */
/* FUN_000180ac @ 000180ac: the game menu at the left edge: eight entries, hover highlight, click runs the entry (spells, save, load, options, quit ...) until the mouse leaves the menu */
extern void FUN_00029ccc(int), FUN_00029cf4(void), FUN_0002f8fc(void), FUN_00032d70(void), FUN_0003939c(int, int, int, void *);
extern void FUN_0003975c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int), FUN_0002a8c8(int, int, int, int, int);
extern void FUN_000422ec(unsigned char *, int, int, int, int, int);
extern void FUN_00013634(int), FUN_000271fc(int), FUN_000305b4(int);
extern int FUN_0002a1f4(void);
extern short DAT_00059e31, DAT_00059e33, DAT_0005a6c2, B0006457c_bO; extern unsigned char DAT_0005a79d, DAT_0005d680, DAT_0005cf58;
extern char *DAT_000560f0[], *DAT_000560c4, *DAT_000560c8, *DAT_000560cc;  extern char *B000758dc_cl;
void FUN_000180ac(void)
{
    int k; int cur; int old; int pb; int redraw; int px; int save; int o; int w; void *img; /* STANDIN: img declared last (frame slot order img, redraw, save) */

    if (DAT_00059e31 >= 0x40) {
        DAT_0005a6c2 = 0;
        return;
    }
    DAT_0005a79d = 1;
    FUN_00029ccc(0);
    FUN_0002a9f8();
    save = DAT_0005d680;
    DAT_0005d680 = 3;
    FUN_000391b0(DAT_0005c050);
    redraw = 1;
    img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
    while (DAT_00059e31 < 0x40) {
        if (redraw) {
            FUN_000391b0(DAT_0005c050);
            old = DAT_00059e33 / 0x28;
            for (k = 0; k < 8; k++) {
                FUN_0003975c(old == k, 0, k * 0x28, (int)B000758dc_cl + 0x49, 0);
                FUN_00040508(0x1b, k * 0x28, 0x28, DAT_000560f0[k], 1);
            }
            redraw = 0;
            FUN_0002a8c8(DAT_0005c050, 0, 0, 0x40, 0x140);
        }
        while (!FUN_0002a1f4() && DAT_00059e31 < 0x40) {
            cur = DAT_00059e33 / 0x28;
            if (cur == old) continue;
            o = old;
            old = cur;
            FUN_000391b0(DAT_0005c050);
            FUN_0003975c(0, 0, o * 0x28, (int)B000758dc_cl + 0x49, 0);
            FUN_00040508(0x1b, o * 0x28, 0x28, DAT_000560f0[o], 1);
            FUN_0003975c(1, 0, cur * 0x28, (int)B000758dc_cl + 0x49, 0);
            FUN_00040508(0x1b, cur * 0x28, 0x28, DAT_000560f0[cur], 1);
            FUN_0002a8c8(DAT_0005c050, 0, o * 0x28, 0x40, 0x28);
            FUN_0002a8c8(DAT_0005c050, 0, cur * 0x28, 0x40, 0x28);
        }
        if (!FUN_0002a1f4()) continue;
        w = 0x28; /* STANDIN: the row height as a named local, reused as the divisor, an argument and the product */
        o = old;
        old = DAT_00059e33 / w;
        FUN_000391b0(DAT_0005c050);
        FUN_0003975c(0, 0, o * 0x28, (int)B000758dc_cl + 0x49, 0);
        FUN_00040508(0x1b, o * 0x28, w, DAT_000560f0[o], 1);
        w *= old;
        FUN_0003975c(2, 0, w, (int)B000758dc_cl + 0x49, 0);
        FUN_00040508(0x1b, w, 0x28, DAT_000560f0[old], 1);
        FUN_0002a8c8(DAT_0005c050, 0, o * 0x28, 0x40, 0x28);
        FUN_0002a8c8(DAT_0005c050, 0, w, 0x40, 0x28);
        switch (DAT_00059e33 / 0x28) {
        case 0:
            FUN_0001461c();
            while (FUN_0002a1f4()) ;
            break;
        case 1:
            DAT_00056460 = 0;
            px = DAT_00058600;
            pb = DAT_00058602;
            FUN_0002a344(-1, 0);
            if (FUN_00015c84()) {
                DAT_0005cf58 = 0;
                FUN_0002f8fc();
                FUN_000391b0(DAT_0005c050);
                FUN_00040040(img);
                img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
                FUN_000425b0(DAT_0005c054, 0, (char *)DAT_0005c034, "COLORS", 0x100);
                redraw = 1;
                FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            }
            FUN_0002a344(px, pb);
            break;
        case 2:
            DAT_00056460 = 0;
            px = DAT_00058600;
            pb = DAT_00058602;
            FUN_0002a344(-1, 0);
            if (FUN_00015d34()) {
                DAT_0005cf58 = 0;
                FUN_0002f8fc();
                FUN_000391b0(DAT_0005c050);
                FUN_00040040(img);
                img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
                FUN_000425b0(DAT_0005c054, 0, (char *)DAT_0005c034, "COLORS", 0x100);
                redraw = 1;
                FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            }
            FUN_0002a344(px, pb);
            break;
        case 3:
            redraw = 1;
            FUN_00013634(0);
            break;
        case 4:
            if (FUN_00017b94() == 1) FUN_0001803c((int)DAT_000560c4);
            FUN_0002f8fc();
            FUN_000391b0(DAT_0005c050);
            FUN_00040040(img);
            img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
            redraw = 1;
            break;
        case 5:
            DAT_0005a79d = 0;
            FUN_000271fc(DAT_0005c6c8);
            DAT_0005a79d = 1;
            if (FUN_000179e0() == 1) FUN_0001803c((int)DAT_000560c8);
            FUN_0002f8fc();
            FUN_000391b0(DAT_0005c050);
            FUN_00040040(img);
            img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
            redraw = 1;
            break;
        case 6:
            if (FUN_00017d44(DAT_000560cc)) {
                FUN_000305b4(-1);
                break;
            }
            FUN_0002f8fc();
            FUN_000391b0(DAT_0005c050);
            FUN_00040040(img);
            img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
            redraw = 1;
            break;
        case 7:
            FUN_00016548();
            FUN_00015dd0();
            FUN_0002f8fc();
            FUN_000391b0(DAT_0005c050);
            FUN_00040040(img);
            img = FUN_00040070(0, 0, 0x40, 0x140, 0xff);
            redraw = 1;
            break;
        }
    }
    FUN_000391b0(DAT_0005c050);
    FUN_0003939c(0, 0, 0, img);
    FUN_00040040(img);
    FUN_0002a8c8(DAT_0005c050, 0, 0, 0x40, 0x140);
    FUN_00032d70();
    DAT_0005a79d = 0;
    DAT_0005a6c2 = 0;
    DAT_0005d680 = save;
    FUN_00029cf4();
    B0006457c_bO = 0;
}

/* ---- module data _DATA 00056098-0005669c (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
char *DAT_00056098 = "%s LEARNED ";
char *DAT_0005609c = "RESTED %d HOURS %d MINUTES";
char *DAT_000560a0 = "RESTED %d MINUTES";
char *DAT_000560a4 = "LEVEL %d";
char *DAT_000560a8 = "(%d MAX)";
char *DAT_000560ac = "You cannot rest here...too many monsters about";
char *DAT_000560b0 = "Problem with dos directory functions.";
char *PTR_s_Could_not_quick_save_000560b4 = "Could not quick save";
char *PTR_s_Game_not_quick_saved_000560b8 = "Game not quick saved ... check to make sure you have enough disk space.";
char *DAT_000560bc = "Could not quick restore";
char *DAT_000560c0 = "Could not restore...not enough disk space.";
char *DAT_000560c4 = "Could not restore game.";
char *DAT_000560c8 = "Game not saved ... check to make sure you have enough disk space.";
char *DAT_000560cc = "do you wish to quit?";
char *DAT_000560d0 = "Do you want spell casters to heal the party?";
char *DAT_000560d4 = "party members are poisoned...continue resting?";
char *DAT_000560d8 = "party members are diseased...continue resting?";
char *PTR_s_cannot_save_game_options_000560dc = "cannot save game options";
char *DAT_000560e0 = "done";
char *DAT_000560e4 = "MIN";
char *DAT_000560e8 = "MAX";
char *PTR_s_EMPTY_000560ec = "EMPTY";
char *DAT_000560f0[8] = { "rest", "pray", "memorize", "automap", "load", "save", "quit", "options" };
char *DAT_00056110[10] = {
    "Double Click Speed", "Floors", "Ceiling", "Sky", "Sprite Dithering", "Distancing", "Sound", "Music", "Palette Intensity", "Step Movement"
};
char *PTR_s_GAME_OPT_00056138 = "GAME.OPT";
unsigned char DAT_0005613c[3] = { 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_0005613f[20] = { 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9 };
unsigned char DAT_00056153[13] = { 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7 };   /* only other modules name it: bytes */
unsigned char DAT_00056160[168] = {
    9, 9, 0xb, 0xb, 0xe, 0x12, 0x12, 0x12, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0,
    2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0,
    2, 2, 1, 1, 0, 0, 0, 0, 3, 2, 1, 2, 0, 0, 0, 0,
    3, 3, 1, 3
};
unsigned char DAT_00056208[2] = { 0 };
unsigned char DAT_0005620a = 0;
unsigned char DAT_0005620b[5] = { 0, 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_00056210[160] = {
    1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
    2, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0,
    4, 2, 1, 0, 0, 0, 0, 0, 4, 2, 2, 0, 0, 0, 0, 0,
    4, 3, 2, 1, 0, 0, 0, 0, 4, 3, 3, 2, 0, 0, 0, 0,
    4, 3, 3, 2, 1, 0, 0, 0, 4, 4, 3, 2, 2, 0, 0, 0,
    4, 4, 4, 3, 3, 0, 0, 0, 4, 4, 4, 4, 4, 1, 0, 0,
    5, 5, 5, 4, 4, 2, 0, 0, 5, 5, 5, 4, 4, 2, 1, 0,
    5, 5, 5, 5, 5, 2, 1, 0, 5, 5, 5, 5, 5, 3, 2, 1,
    5, 5, 5, 5, 5, 3, 3, 2, 5, 5, 5, 5, 5, 3, 3, 2,
    5, 5, 5, 5, 5, 3, 3, 3, 5, 5, 5, 5, 5, 4, 3, 3
};
unsigned char DAT_000562b0[160] = {
    1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
    2, 1, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0,
    3, 3, 1, 0, 0, 0, 0, 0, 3, 3, 2, 0, 0, 0, 0, 0,
    3, 3, 2, 1, 0, 0, 0, 0, 3, 3, 3, 2, 0, 0, 0, 0,
    4, 4, 3, 2, 1, 0, 0, 0, 4, 4, 3, 3, 2, 0, 0, 0,
    5, 4, 4, 3, 2, 1, 0, 0, 6, 5, 5, 3, 2, 2, 0, 0,
    6, 6, 6, 4, 2, 2, 0, 0, 6, 6, 6, 5, 3, 2, 1, 0,
    6, 6, 6, 6, 4, 2, 1, 0, 7, 7, 7, 6, 4, 3, 1, 0,
    7, 7, 7, 7, 5, 3, 2, 0, 8, 8, 8, 8, 6, 4, 2, 0,
    9, 9, 8, 8, 6, 4, 2, 0, 9, 9, 9, 8, 7, 5, 2
};
unsigned char DAT_00056350[160] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
    2, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0,
    2, 2, 1, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 0, 0,
    3, 2, 1, 1, 0, 0, 0, 0, 3, 3, 2, 1, 0, 0, 0, 0,
    3, 3, 3, 1, 0, 0, 0, 0, 3, 3, 3, 2, 0, 0, 0, 0,
    3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3
};
struct LBOX DAT_000563f0[6] = { 0xf, 8, 0xf, 0x6e, 0xf, 0xd4, 0xe1, 8, 0xe1, 0x6e, 0xe1, 0xd4 };
int DAT_00056420[1][8] = { 7, 6, 5, 4, 4, 2 };
int DAT_00056440[8] = { 7, 6, 10, 4, 2, 6 };
unsigned char DAT_00056460 = 0;
char DAT_00056461[551] = "QUICKSAVE";
int DAT_00056688 = 0;
char DAT_0005668c[16] = "SAVE??\\SAVE.DAT";
/* ---- end of module data _DATA */
