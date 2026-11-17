/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
int B00065a2c_ay;
unsigned char B00065a28_bn[4];
unsigned char B00065a24_aj[4];
unsigned char B00065a20_bf[4];
unsigned char B00065a1c_ai[4];
unsigned char B00065a18_cn[4];
unsigned char B00065618_e1[1024];
struct O B00064d80_ay[100];
char B00064580_eK[2048];
/* BSS end */
/* Module: FUN_000186c4, FUN_0001871c, FUN_0001893c, FUN_00018a80, FUN_00018c88, FUN_00018cf4, FUN_00019070,
   FUN_00019368, FUN_00019418, FUN_000194e0, FUN_000195c0, FUN_000196e0, FUN_00019790, FUN_00019b4c,
   FUN_00019d90, FUN_0001a254, FUN_0001a5bc, FUN_0001a60c, FUN_0001a668, FUN_0001a794, FUN_0001a8a0,
   FUN_0001aa30, FUN_0001abc4, FUN_0001ac2c, FUN_0001ad24, FUN_0001ae30, FUN_0001aed8, FUN_0001b02c,
   FUN_0001b410, FUN_0001b518, FUN_0001b6f4, FUN_0001b950
   Module file (tools/modfile.py, round 23): not a verified module; the build splices the functions that match here.
   */
/* ---- from src/CODE2/f186c4.c */
/* FUN_000186c4 @ 000186c4 */
extern unsigned char B000718e0_iO;
#define B0007193c_aB (*(short *)((char *)&B000718e0_iO + 92)) /* STANDIN: view, B000718e0_iO + 0x5c */
#define B0007193e_bP (*(short *)((char *)&B000718e0_iO + 94)) /* STANDIN: view, B000718e0_iO + 0x5e */
extern short DAT_000567ca[];
extern void FUN_00034a9c(int, int);
void FUN_000186c4(int i, int k)
{
    if (*(short *)((char *)&B0007193c_aB + i * 0x248) == DAT_000567ca[k]) FUN_00034a9c(i, 0);
    if (*(short *)((char *)&B0007193e_bP + i * 0x248) == DAT_000567ca[k]) FUN_00034a9c(i, 1);
}

/* ---- from src/CODE2/f1871c.c */
/* the module declaration (seen through a cast view below) */ extern unsigned char B000718e0_iO;
/* FUN_0001871c @ 0001871c: spell effect e of member who wears off: toggle its bit, post "<name>'s <effect> wears off.", clear its duration and undo the effect */
#include <string.h>
#include <stdio.h>
#define M000718e0_iO ((struct CHR *)&B000718e0_iO)
#pragma pack(1)
struct CHR { char name[0x35]; unsigned char b35; char p36[0xed]; int f123; unsigned char f127; char p128[0xa]; int fx; int dur[0x22]; int f1be; char p1c2[0x28]; int f1ea; char p1ee[4]; int f1f2; char rest[0x52]; };
#pragma pack()
 extern char DAT_0005759c[], *DAT_0005669c, *DAT_000566a0; extern unsigned char DAT_0005cf5a; /* STANDIN: DAT_0005cf5a (the four portrait-redraw flags) is declared as a scalar byte and indexed as (&DAT_0005cf5a)[k]: under -oa a function that stores it only as a scalar (FUN_0001a5bc, FUN_0001a60c, ...) gets its zero-savings memory node, one that takes its address gets none - as with the old per-file array / scalar declarations */
extern int DAT_0005f91c, DAT_0005fd08; extern short DAT_0005f03c, DAT_0005f03e, DAT_00056dae;
extern void FUN_0002c368(char *, int), FUN_0002c21c(char *), FUN_00041f38(int), FUN_0002202c(int, int);
void FUN_0001871c(int who, unsigned e)
{
    M000718e0_iO[who].fx ^= 1 << e;
    sprintf(DAT_0005759c, DAT_0005669c, M000718e0_iO[who].name);
    FUN_0002c368(DAT_0005759c + strlen(DAT_0005759c), e + 0x24c);
    strcat(DAT_0005759c, DAT_000566a0);
    FUN_0002c21c(DAT_0005759c);
    (&DAT_0005cf5a)[who] = 1;
    M000718e0_iO[who].dur[e] = 0;
    switch (e) {
    case 1:
    case 10:
        FUN_00041f38(DAT_0005f91c);
        break;
    case 6:
        M000718e0_iO[who].f1f2--;
        break;
    case 11:
        M000718e0_iO[who].f1ea = 0;
        break;
    case 12:
        FUN_0002202c(who, -M000718e0_iO[who].f123);
        break;
    case 13:
        M000718e0_iO[who].b35 -= M000718e0_iO[who].f127;
        break;
    case 17:
        DAT_0005fd08--;
        break;
    case 18:
        DAT_0005f03c--;
        break;
    case 20:
        (&DAT_0005cf5a)[0] = 1;
        (&DAT_0005cf5a)[1] = 1;
        (&DAT_0005cf5a)[2] = 1;
        (&DAT_0005cf5a)[3] = 1;
        DAT_00056dae--;
        break;
    case 21:
        (&DAT_0005cf5a)[0] = 1;
        (&DAT_0005cf5a)[1] = 1;
        (&DAT_0005cf5a)[2] = 1;
        (&DAT_0005cf5a)[3] = 1;
        M000718e0_iO[0].fx &= ~0x200000;
        M000718e0_iO[1].fx &= ~0x200000;
        M000718e0_iO[2].fx &= ~0x200000;
        M000718e0_iO[3].fx &= ~0x200000;
        break;
    case 23:
        FUN_0002202c(who, -M000718e0_iO[who].f1be);
        break;
    case 25:
        DAT_0005f03e--;
        break;
    }
}

#undef M000718e0_iO
#pragma pack()
/* ---- from src/CODE2/f1893c.c */
extern void FUN_000186c4(int i, int k); /* module prototype */
extern void FUN_0001871c(int who, unsigned e); /* module prototype */
/* FUN_0001893c @ 0001893c: expire the party's timed effects (spell durations, hunger, condition timers) (one char base for the character record keeps the stores in source order) */
#include "dice.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
extern int FUN_00029cc4(void), FUN_00022098(int); extern void FUN_0002202c(int, int);
#define B00071912_a3 (*(unsigned char *)((char *)&B000718e0_iO + 50)) /* STANDIN: view, B000718e0_iO + 0x32 */
#define B00071aa2_ht (*(int *)((char *)&B000718e0_iO + 450)) /* STANDIN: view, B000718e0_iO + 0x1c2 */
#define B00071a12_dx (*(int *)((char *)&B000718e0_iO + 306)) /* STANDIN: view, B000718e0_iO + 0x132 */
 extern int DAT_00071aa6, DAT_00071ace, DAT_00071a16; 
#define CH(sym, k) (*(int *)((char *)&sym + (k) * 0x248))
#define CHJ(sym, k, j) (*(int *)((char *)&sym + (k) * 0x248 + (j) * 4))
void FUN_0001893c(void)
{
    int now, k, j, r;
    now = FUN_00029cc4();
    for (k = 0; k < 4; k++) {
        if (*(unsigned short *)(M000718e0_iO + k * 0x248 + 0x10) >= 0x4000) continue;
        if ((*(int *)(M000718e0_iO + (k) * 0x248 + 0x1c2))) {
            for (j = 0; j < 9; j++) {
                if ((*(int *)(M000718e0_iO + (k) * 0x248 + (j) * 4 + 0x1c6)) && (*(int *)(M000718e0_iO + (k) * 0x248 + (j) * 4 + 0x1c6)) <= now) {
                    (*(int *)(M000718e0_iO + (k) * 0x248 + 0x1c2)) ^= 1 << j;
                    (&DAT_0005cf5a)[k] = 1;
                    (*(int *)(M000718e0_iO + (k) * 0x248 + (j) * 4 + 0x1c6)) = 0;
                    FUN_000186c4(k, j);
                }
            }
        }
        if ((*(int *)(M000718e0_iO + (k) * 0x248 + 0x1ee)) && (*(int *)(M000718e0_iO + (k) * 0x248 + 0x1ee)) <= now) {
            FUN_0002202c(k, 1);
            (*(int *)(M000718e0_iO + (k) * 0x248 + 0x1ee)) = 0;
            if (FUN_00022098(k) != *(unsigned char *)(M000718e0_iO + k * 0x248 + 0x32)) {
                r = FUN_0002c328(2, 4, 0, 0) * 0x2a30;
                (*(int *)(M000718e0_iO + (k) * 0x248 + 0x1ee)) = FUN_00029cc4() + r;
            }
        }
        if ((*(int *)(M000718e0_iO + (k) * 0x248 + 0x132))) {
            for (j = 0; j < 0x1a; j++) {
                if ((*(int *)(M000718e0_iO + (k) * 0x248 + (j) * 4 + 0x136)) > 0 && (*(int *)(M000718e0_iO + (k) * 0x248 + (j) * 4 + 0x136)) <= now) FUN_0001871c(k, j);
            }
        }
    }
}

#undef M000718e0_iO
#undef CH
#undef CHJ
/* ---- from src/CODE2/f18a80.c */
#define CHR T3_CHR
/* MATCH (round 27): alone and in module 0x186c4. The sound bank pointer B000758d4_jG is read as an int there (as in four other files), so the sum is an int add cast to char * at the call: the pointer-typed add made the 10.0a/2002 allocator keep EDX off its load (ECX given first, then the cell sum and the face took ECX too); the caster clear stores f14a before f15a */
/* Round 18 (module 0x186c4): 9 -> 4 lines: the caster clear stores the record fields first and the redraw flag DAT_0005cf5a[who] last (as the listing does). Left: the sound-call register tie below; levers tried: m declared first, m in the inner block (no change). */
/* [2026-11-09: declaration order from an automatic sweep, 143 diff lines with -3s -ox -oe -oa -ot -w0] */
/* NEAR MISS (module 0x186a0.. is -oa, as FUN_0001871c), 1 register: under -3s -ox -oe -oa -ot everything matches except the sound call, where the original loads t into edx and B000758d4_jG into eax (mov eax,[mem], 1 byte shorter), here the other way round. Operand orders, || grouping, declaration order tried */
/* FUN_00018a80 @ 00018a80: launch projectile type t from (x, y) in direction dir, cast by member who (0..3, or a creature): fill the next missile slot, play its sound when audible, step it out of the caster's square, and for a party caster clear the cast state */
#include <stdlib.h>
#include "world.h"
#define M000718e0_iO ((struct CHR *)&B000718e0_iO)
union FX { int v; struct { unsigned short f; short i; } s; };
struct MS { int a, b, dir; unsigned short cell, type; short timer, w12; unsigned short b0 : 1, st : 2, face : 3, f6 : 4, b10 : 1, own : 3, b14 : 2; };
struct CELL { unsigned short lo : 6, seen : 1, rest : 9; };
struct CHR { char p0[0x132]; unsigned short st; char p134[0x16]; int f14a; char p14e[0xc]; int f15a; char rest[0xea]; };
extern struct MS B000748ec_bk[]; extern struct CELL B000698e0_b7[]; 
extern int DAT_0005c038, B000755d0_ao, B000755d4_ak, B000758d4_jG; extern unsigned char DAT_0005bf38, DAT_0005cf5a; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
extern void FUN_0001e578(int), FUN_00038110(char *, int, int, int), FUN_00032e90(struct MS *, int), FUN_00029ccc(int), FUN_0002f1c8(void), FUN_0002ea04(void), FUN_0002ea78(void), FUN_00029cf4(void);
extern int FUN_0003c9dc(unsigned, unsigned);
void FUN_00018a80(int t, int dir, int who, union FX x, union FX y)
{
    int snd[9] = { 27, 54, 43, 13, 29, 58, 56, 56, 27 }; struct MS *m;
    FUN_0001e578(who);
    if (DAT_0005c038 < 0x96) {
        m = &B000748ec_bk[DAT_0005c038];
        m->a = x.v;
        m->b = y.v;
        m->dir = dir;
        m->cell = x.s.i * B00075618_b1.w + y.s.i;
        m->type = t;
        m->timer = 0;
        m->f6 = 0;
        m->own = who;
        if (t == 8) m->w12 = ((unsigned)rand() * 10 >> 15) + 0x14;
        DAT_0005c038++;
        m->st = 0;
        if ((who >= 0 && who < 4) || B000698e0_b7[m->cell].seen || (abs(m->a - B000755d4_ak) < 10 && abs(m->b - B000755d0_ao) < 10))
            FUN_00038110((char *)(B000758d4_jG + snd[t]), 0xff, 0, 1);
        dir += 0x16;
        if (dir >= 0x168) dir -= 0x168;
        if (dir < 0) dir += 0x168;
        m->face = 8 - dir / 0x2d;
        if (t != 8) {
            while (FUN_0003c9dc(m->a, m->b)) {
                FUN_00032e90(m, 0);
                if (m->st) break;
            }
        }
        if (m->st) {
            FUN_00029ccc(0);
            dir = DAT_0005bf38;
            DAT_0005bf38 = 0;
            FUN_0002f1c8();
            FUN_0002ea04();
            FUN_0002ea78();
            DAT_0005bf38 = dir;
            FUN_00029cf4();
        }
        if (who >= 0 && who < 4) {
            M000718e0_iO[who].f14a = 0; M000718e0_iO[who].f15a = 0; M000718e0_iO[who].st &= 0xfddf; (&DAT_0005cf5a)[who] = 1;
        }
    }
}

#undef CHR
#undef M000718e0_iO
/* ---- from src/CODE2/f18c88.c */
#define B000748ec_bk ((struct SP *)B000748ec_bk)
/* FUN_00018c88 @ 00018c88: unload spell slot i */
void *memmove(void *, const void *, unsigned);
extern void FUN_0003f580(const char *);
extern char *PTR_s_error_unloading_spell__000566a4; extern int DAT_0005c038;
struct SP { char b[0x16]; }; 
void FUN_00018c88(int i)
{
    if (i >= DAT_0005c038) FUN_0003f580(PTR_s_error_unloading_spell__000566a4);
    memmove(&B000748ec_bk[i], &B000748ec_bk[i + 1], (DAT_0005c038 - 1 - i) * 0x16);
    DAT_0005c038--;
}

#undef B000748ec_bk
/* ---- from src/CODE2/wip/f18cf4.c */
/* Round 46: 35 -> 9 instruction lines in module 0x186c4 (886/889 to the last ret: 2 bytes short). The class block `if (4 == cls[k]) mult = lvl[k]` read six per-field symbols (B000718f5_h2/6/7, B00071900_bm/2/4); as members of the one record `B000718e0_iO[c]` (include/records.h struct PC) the block and everything the round-45 note listed as slot differences is equal. The item (struct ITEM *it) and monster-type (struct MTYPE *t, .rad / .imm / .f3a) records are code-neutral here. Left, the tail only: after the roll the original moves the result (`mov edx,eax`), keeps d in edx and uses eax for p->type and the type index; ours keeps d in eax and uses edx. Tried: the tail value in hit / mult / c / xlo / type / yhi (19 / 50 / 39 / 27 / 9 / 9), a (short) cast on the hp read (9), declaration climb 42 + pair swaps 91 (all 9). */
/* Round 49 (1 compile, read): the 9 lines are the damage variable d of the dice branch: EDX in the original (`mov edx,eax` after FUN_0002c328, `movsx edx` for the hp override, `push edx`), EAX here, with p->type then in EDX; the monster-table reads are [edi + 0x14d8e] (offset register + table symbol) in the original. Not traced further this round. */
/* NEAR MISS (round 45, module 0x186c4 -oa, 35 instruction lines, 888/889): structure equal to the original (docs/data/r44/sd.py: 5 lines). Left: (1) in the last else branch the original copies the roll to edx at once (`mov edx,eax`) and tests p->type in eax; ours keeps the damage in eax and the type temp in edx; (2) frame slots: original [esp+4] mult, +8 r, +0xc ylo, +0x10 the stepped &B00064d80_ay[i], +0x14 dice, +0x18 t; ours +4 the stepped address, +8 t, +0xc mult, +0x10 r, +0x14 ylo, +0x18 dice. Tried (14 compiles + a 42-order declaration climb, no gain): own variable for the tail damage at function scope (45 lines) and block scope (35), own variable for the radius (77, changes structure), operand swap of the 0x58 test, the two declaration orders read off the frame (44). protoscan: callees clean (dice.h in force). */
/* NEAR MISS (round 23, module 0x186c4 -oa, 91 worklist lines) a. first difference: frame 0x20 vs 0x1c and the record address: ours steps a pointer o (edi), the original multiplies i*0x16 at each use (imul ebx,ebp,0x16); decision: the stepped pointer o is not in the source - the calls take &B00064d80_ay[i]. c. done (1 real): 91 -> 45 lines, size -25 -> -1; left: one extra register copy (mov edx,eax) and registers. 865/889 under -3s -oaimert -oe -s (module 0x186c4 is -oa; without -ol: the original multiplies i*0x16 at every use and keeps i in ebp, no strength reduction; under -ox -oe -oa -ot SHAPE 93/152 lines), SHAPE 27, 130 byte lines (was 903/889, SHAPE 74, 162 under -oimert). Structural round 2026-11-10, from the original: (1) the monster-type flag tests are test byte ptr [t + 0x32], k: the flags are an int (*(int *)(t + 0x32) & k, as in the matched FUN_0001b410; a uchar & k compiles to and/movzx/test) - fixed; (2) d = t[0x16] is read after the type test - fixed. Left: (a) cases 2 and 3 (both & 9) are two code blocks in the original (with eax/edx swapped), ours merges them into one (the 24 bytes); the operand order in case 3 does not separate them; (b) ((unsigned char *)B000755d8_aw) + type * 0x41 is shl/add there, imul here (cost choice under register pressure; &((unsigned char *)B000755d8_aw)[...] same); (c) frame slots of mult/r and register choice in the dice block. */
/* earlier note: 903/889, 461 lines (first draft, new candidate): flow from the listing (dice of the projectile type, thrower class multiplier, bounding box test with unsigned compares, per-type immunity switch 0..6, thrown item path); left: the original indexes B00064d80_ay by i (ebp, imul i*0x16 each time) and keeps a separate walking pointer at [esp+0x10]; frame 7 slots (type*0x45 temp, mult, r, ylo, o, dice, t); here the loop is strength-reduced */
/* [2026-11-09: declaration order from an automatic sweep, 440 diff lines with -3s -oimelr -oe -s -w0] */
/* FUN_00018cf4 @ 00018cf4: projectile p hits the monsters it overlaps: weapon damage (f != 0, rolled from the projectile's dice, multiplied for the thrower's class) or the item's damage; 0 when something was hit */
#include "world.h"
struct PRJ { int a, b; short c8, ca; unsigned short s, type; short timer, w12; unsigned short lo : 11, owner : 3, st : 2; };
struct O { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; unsigned short s, type; short timer, hp; unsigned short w14; };
extern struct O B00064d80_ay[100];  extern unsigned char *B00072230_c4, DAT_000566c8[];
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)

extern int FUN_0002c328(int, int, int, int), FUN_00033f50(int); extern void FUN_0001e284(void *, unsigned char *, int, int, int);
#pragma aux FUN_0002c328 modify [ebx ecx edx];
/* Round 54 (10 compiles + trace + forced order): the tail is a tie t149 (the FUN_0002c328 result) / t115 (the p->type reload), both 802; forced t115 first the function matches (build/var/r54/ff.sh). tw.py: insert 803..1887 at 14 / 28 or <= 802 at 93 / 95 (between the named nodes type and dice). Tried: damage into its own variable (block: 9, function: 17), the radius in its own variable rd at eight declaration places (9-32). */
int FUN_00018cf4(struct PRJ *p, int f)
{
    int hit; int d; int xlo; struct MTYPE *t; int yhi; struct ITEM *it; int xhi; int type; int mult; int r; unsigned char *dice; int ylo; int i; int c;
    r = 1;
    if (f) {
        dice = DAT_000566c8 + p->type * 4;
        c = p->owner;
        if (c == 4) mult = 3;
        else {
            if (4 == M000718e0_iO[c].cls[0]) mult = M000718e0_iO[c].lvl[0];
            if (4 == M000718e0_iO[c].cls[1]) mult = M000718e0_iO[c].lvl[1];
            if (M000718e0_iO[c].cls[2] == 4) mult = M000718e0_iO[c].lvl[2];
        }
    }
    for (i = 0; i < B00075618_b1.nent; i += 1) {
        if (B00064d80_ay[i].dead) continue;
        yhi = B00064d80_ay[i].b;
        xhi = B00064d80_ay[i].a;
        ylo = yhi;
        xlo = xhi;
        type = B00064d80_ay[i].type;
        t = &((struct MTYPE *)B00072230_c4)[type];
        if (type >= 0x22 && 0x50 != type) continue;
        d = t->rad;
        ylo -= d; yhi = yhi + d; xlo -= d; xhi = xhi + d;
        if ((unsigned)p->b < (unsigned)ylo || (unsigned)yhi < (unsigned)p->b || (unsigned)xlo > (unsigned)p->a || (unsigned)xhi < (unsigned)p->a) continue;
        if (f) {
            hit = 1;
            switch (p->type) {
            case 0: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 0x21) hit = 0; break;
            case 1: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 3) hit = 0; break;
            case 2: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 9) hit = 0; break;
            case 3: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 9) hit = 0; break;
            case 4: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 0x21) hit = 0; break;
            case 5: case 6: if (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 1) hit = 0; break;
            }
            if (hit) {
                d = FUN_0002c328(dice[0], dice[1], dice[2], 0);
                if (dice[3]) d *= mult;
                FUN_0001e284(&B00064d80_ay[i], (unsigned char *)t, i, d, 0);
            }
            r = 0;
        } else {
            it = &ITEMS[p->type];
            r = 0;
            if (p->type == 0x5a) {
                d = FUN_0002c328(it->nd, it->ds, it->add, 0);
                FUN_0001e284(&B00064d80_ay[i], (unsigned char *)t, i, d, 1);
                if (!(((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].imm & 3)) FUN_0001e284(&B00064d80_ay[i], (unsigned char *)t, i, 0x14, 0);
                p->st = 1;
            } else if (FUN_00033f50(p->type) && it->nd) {
                d = FUN_0002c328(it->nd, it->ds, it->add, it->ac);
                { int cq; cq = d; d = cq; } /* STANDIN: copy out and back, +savings on the roll web d so the p->type reload wins the 802 tie (EAX/EDX as in the original) */
                if (p->type == 0x58 && (((struct MTYPE *)B00072230_c4)[B00064d80_ay[i].type].f3a & 0x20)) {
                    p->st = 1;
                    d = B00064d80_ay[i].hp;
                }
                FUN_0001e284(&B00064d80_ay[i], (unsigned char *)t, i, d, 1);
            }
        }
    }
    return r;
}

#undef M000718e0_iO

/* ---- from src/CODE2/wip/f19070.c */
/* NEAR MISS (round 40: unchanged, 146 masked lines. Re-read: frame y0 [0], x0 [4], mult [8], flag [0xc], i [0x10]; x1 ebp, y1 ebx; the owner's class reads go through edx. The int flag word *(int *)(B000718e0_iO + i * 0x248 + 0x132) & 0x80000 (the module's own view of the status word, recipe 43) gives the original's test byte ptr [ebp+0x134],8 but moves the slots (mult [0], i [4], x0 [8], y0 [0xc], flag [0x10]; 232 masked lines) - still not kept, apply with the slot fix. Declaration orders (6) and the orders of the four bound initialisers (6) do not move x0/y0/mult; tietrace on the int-flag form: class C, x1 (t10) ties with y1, t21, t24, t27 at savings 692 and takes edx after t21/t24 (the owner offsets) took ebp; no forced order of that group gives the original (best 230).) */
#define CHR T6_CHR
#define MS T6_MS
/* Structural round 2026-11-10 (module 0x186c4, -oa; same result under flags.csv): with registers and slots masked the only real difference is the fire-ward test, test byte ptr [ch + 0x134], 8 in the original: an int flag word (recipe 43), *(int *)(B000718e0_iO + i * 0x248 + 0x132) & 0x80000. That form gives the original instruction (SHAPE 16 -> 13) but moves the bound variables to other frame slots (100 -> 108 byte lines, size +4 -> -5), so by the acceptance rule it is not kept; apply it together with the slot fix. The rest is the allocation of x0/y0/x1/y1/mult described below. */
/* NEAR MISS (733/730): logic and order right; left: register/stack allocation of the bounds (original: y0/x0 spilled to [esp]/[esp+4], mult [esp+8], x1/y1 in ebp/ebx; here x1/y1 in edx/esi and the slots permuted) and the class/level reads (original keeps the owner in eax and rereads through edx) */
/* Round 52: the resistance flag is bit 0x80000 of the int at +0x132 (the flag word FUN_0001d550 tests with 0x4000): the original tests it as `test byte ptr [ebp + 0x71a14], 8` (an int & K narrowed, recipe 43), the char read gave mov al / and al,8 / movzx / test: 764 -> 756/730 (+2 filler), structural lines 35 -> 33. The rest of the gap is frame-slot encoding: y0 [esp] / mult [esp+8] in the original, mult [esp] here (declaration climb: no order moves it, recipe 170: weighted references), i a memory counter at [esp+0x10] in both. */
/* FUN_00019070 @ 00019070: missile m reaches the party square: spell missiles (kind != 0) roll their dice (scaled by the caster level for level-based spells, weaker against fire resistance), thrown objects roll the item damage; Vladislav is never hit */
#include "world.h"
struct MS { unsigned a, b; int dir; unsigned short cell, type; short timer, w12; unsigned short b0 : 1, st : 2, face : 3, fr : 3, hit : 1, b10 : 1, own : 3, b14 : 2; };
struct DICE { unsigned char n, s, a, mul; };
struct CHR { char p0[0x10]; unsigned short st; char p12[3]; signed char cls[3]; char p18[8]; short lvl[3]; char p26[0x16]; short mem[0x7c]; };
  

#include "dice.h"
#define DAT_000566c8 ((struct DICE *)DAT_000566c8)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define B000755d0_ao ((unsigned )B000755d0_ao)
#define B000755d4_ak ((unsigned )B000755d4_ak)
extern int FUN_00024a60(char *), FUN_0001f2d4(int, int), FUN_0001cf2c(int, int); extern void FUN_0001cd44(int, int);
#define CH(i) ((struct CHR *)(M000718e0_iO + (i) * 0x248))
#undef DAT_000566c8
#undef M000718e0_iO
#define B00071a14_ff (*(int *)((char *)&B000718e0_iO + 308)) /* STANDIN: view, B000718e0_iO + 0x134 */
extern unsigned short B000718f0_hO[]; 
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
void FUN_00019070(struct MS *p, int f)
{
    unsigned char *dice; int off; int c, mult, k, d, w;
    unsigned xlo, xhi, yhi, ylo;
    xlo = xhi = B000755d0_ao;
    ylo = yhi = B000755d4_ak;
    if (f) {
        c = p->type;
        dice = DAT_000566c8 + c * 4;
        c = p->own;
        if (c == 4) mult = 3;
        else if (c == 7) mult = 5;
        else {
            if (M000718e0_iO[c].cls[0] == 4) mult = M000718e0_iO[c].lvl[0];
            if (M000718e0_iO[c].cls[1] == 4) mult = M000718e0_iO[c].lvl[1];
            if (M000718e0_iO[c].cls[2] == 4) mult = M000718e0_iO[c].lvl[2];
        }
    } else if (p->type == 0x59 || p->type == 0x57) {
        p->hit = 0;
        return;
    }
    xlo -= 0x8fa0;
    ylo -= 0x8fa0;
    xhi += 0x8fa0;
    yhi += 0x8fa0;
    if (p->b < xlo || xhi < p->b || p->a < ylo || yhi < p->a) return;
    for (k = 0, off = 0; k < 4; k++, off += 0x248) {
        if (*(unsigned short *)((char *)&B000718f0_hO + off) & 0xf240) continue;
        if (FUN_00024a60("VLADISLAV") == k) continue;
        if (f) {
            w = 0;
            d = FUN_0002c328(dice[0], dice[1], dice[2], 0);
            if (dice[3]) d = mult * d;
            if (p->type == 0) {
                if (FUN_0001f2d4(k, 0x44) || (*(int *)((char *)&B00071a14_ff + off) & 8)) {
                    d = mult * FUN_0002c328(dice[0], dice[1] - 2, dice[2], 0);
                    w = 2;
                } else w = 0;
            } else if (p->type == 1) {
                if (*(short *)((char *)&B0007193c_aB + off) == 0x67 || *(short *)((char *)&B0007193e_bP + off) == 0x67) {
                    d = mult * FUN_0002c328(dice[0], dice[1] - 2, dice[2], 0);
                    w = 2;
                } else w = 0;
            }
            if (FUN_0001cf2c(k, w)) d /= 2;
            if (d) FUN_0001cd44(k, d);
        } else {
            if (ITEMS[p->type].nd) d = FUN_0002c328(ITEMS[p->type].nd, ITEMS[p->type].ds, ITEMS[p->type].add, 0);
            else d = FUN_0002c328(1, 2, 0, 0);
            FUN_0001cd44(k, d);
            p->hit = 0;
        }
    }
}


#undef CHR
#undef DAT_000566c8
#undef M000718e0_iO
#undef B000755d0_ao
#undef B000755d4_ak
#undef MS
#undef CH
/* ---- from src/CODE2/wip/f19368.c */
/* Round 63 (lane AH): MATCH in the module compile. The c19368 form of round 62 (struct MS of the module, party y via the int view, party x as the short scalar) plus one reused difference local d for the two abs() arguments (lane AF catalogue): one conflict node fewer, which puts the savings-6 group and the dx operands the original way. */
int abs(int);
#pragma intrinsic(abs)
extern short B000755d2_ai;
void FUN_00019368(struct MS *m)
{
    int dy, dx, snd, d;

    d = ((short *)&m->a)[1] - ((short *)&B000755d4_ak)[1]; /* STANDIN: one reused difference local d for both abs() arguments: one conflict node fewer (21 -> 20), decides the savings-6 / dx operand ties */
    dy = abs(d);
    d = ((short *)&m->b)[1] - B000755d2_ai; /* STANDIN: second use of the reused difference local d (see above) */
    dx = abs(d);
    snd = -1;
    switch (m->type) {
    case 0: snd = 0x1c; break;
    case 1: snd = 0x37; break;
    case 4: snd = 0x1e; break;
    case 6: snd = 0x39; break;
    }
    if (m->own >= 4 && !B000698e0_b7[m->cell].seen && (dy >= 10 || dx >= 10)) return;
    if (snd != -1) FUN_00038110((char *)(B000758d4_jG + snd), 0xff, 1, 1);
}


/* ---- from src/CODE2/f19418.c */
/* FUN_00019418 @ 00019418: ask for a casting direction with the mouse */
extern void FUN_0002c21c(char *), FUN_0002c258(void), FUN_0002a9f8(void), FUN_0002c2cc(void), FUN_00032d70(void); extern int FUN_0002a1f4(void);
extern unsigned char DAT_0005c02f; extern char *PTR_s_where_do_you_wish_to_cast_000566a8; extern short DAT_00059e31, DAT_00059e33; extern int DAT_0005c658;
int FUN_00019418(int mode)
{
    int x, y, r;
    if (DAT_0005c02f == 0) {
        FUN_0002c21c(PTR_s_where_do_you_wish_to_cast_000566a8);
        FUN_0002c258();
        FUN_0002a9f8();
        do {
            while (FUN_0002a1f4()) ;
            while (!FUN_0002a1f4()) ;
            x = DAT_00059e31;
            y = DAT_00059e33;
        } while (x < 4 || x >= 0x104 || y < 0x20 || y >= 0x120);
        if (mode) {
            r = DAT_0005c658 - (y - 0xa0) / 3;
            if (r < 0) r += 360;
            if (r >= 360) r -= 360;
        } else r = y - 0x20;
        FUN_0002c2cc();
        FUN_00032d70();
    } else if (mode) r = DAT_0005c658;
    else r = 0x80;
    return r;
}

/* ---- from src/CODE2/f194e0.c */
/* Round 42: the scan loop indexes the button table by k (`+ k * 0x16`, recipe 127) instead of stepping an offset variable: the stepped register is the compiler's reduced induction, and the x / y parameter tie (round 28: class A at 958) falls the original way. Matches in module 0x186c4 (-oa). */
/* Round 37 (real 10.0a, module m186c4 -oa, 7 compiles): catalogue rewrites: b = BTN(page, off) reusing the loop's off (r109: n 34, 62 lines), a named page pg = DAT_0005c050 ^ 1 (n 29, 88), nested if / continue for the button test, swapped x compares: 15 lines, n 35. */
/* NEAR MISS (round 22): 12 lines in module 0x186c4 (-oa), x/y parameter registers swapped (original x edi, y ebp). Tried: the module's struct O for the entity kind (kept, same code). 1 real compile. */
/* Round 28 (real trace): class A. x (t1) and y (t3) tie at 958; forcing x first gives 0 lines (x EDI, y EBP). tiewhat: y's node created later (pre-sort 28 -> 0..14) or one node more at several positions. Real compiles: all declaration orders of n,k,off,b and a named p = DAT_0005c050 ^ 1 (outside and inside the loop): no change (15) or worse. */
/* FUN_000194e0 near miss (221/221): only the registers of the two parameters are swapped (original x=EDI, y=EBP); declaration orders of the locals do not change it; 2026-11-09: all 32 comparison spellings in both x/y orders (y-first gives 6 lines), continue-style tests, param copies tried */
/* FUN_000194e0 @ 000194e0: find the topmost visible button of the current page under (x, y) */
extern int FUN_0003acdc(int), FUN_00031bf0(void *, int);
extern unsigned short B00077148_eJ;
#define B00077152_el (*(unsigned short *)((char *)&B00077148_eJ + 10)) /* STANDIN: a name of its own in the original image, 10 bytes into B00077148_eJ */
extern int DAT_0005c050; extern unsigned short DAT_0005f038[], B00077148_eJ;
/* struct O: defined above */
extern struct O B00064d80_ay[100];
#define BTN(page, off) ((char *)&B00077148_eJ + (page) * 0x2260 + (off))
int FUN_000194e0(int x, int y)
{
    int n, k; char *b;
    for (n = DAT_0005f038[DAT_0005c050 ^ 1] - 1; n >= 0; n--) {
        for (k = 0; k < DAT_0005f038[DAT_0005c050 ^ 1]; k++) {
            if (*(unsigned short *)((char *)&B00077152_el + (DAT_0005c050 ^ 1) * 0x2260 + k * 0x16) == n) break;
        }
        b = BTN(DAT_0005c050 ^ 1, k * 0x16);
        if (*(unsigned short *)(b + 8) == 0 && FUN_0003acdc(B00064d80_ay[*(unsigned short *)(b + 6)].type) && FUN_00031bf0(b, 0)
            && x >= *(unsigned short *)(b + 0xe) && x < *(unsigned short *)(b + 0x10) && y >= *(unsigned short *)(b + 0x12) && y < *(unsigned short *)(b + 0x14))
            return *(unsigned short *)(b + 6);
    }
    return -1;
}

#undef BTN
/* ---- from src/CODE2/f195c0.c */
extern int FUN_000194e0(int x, int y); /* module prototype */
#define MS T10_MS
/* Round 36 (FUN_000194e0 in module 0x186c4, real 10.0a, 8 compiles + replay): x / y tie at 958 (two compares each, as in the original); no single removal flips it; inserts at many places, or the cross-block temp t5 moved behind b; local declaration orders (120) do not. A return variable r (8 forms) changes the code (77-78 lines). */
/* FUN_000195c0 @ 000195c0: let the player pick a visible creature with the mouse; -1 when none or cancelled (the mouse is struct MS at DAT_00059e31, recipe 27: under the module's -oa separate shorts joined the conflict list and swapped x/y) */
extern void FUN_0002c21c(char *), FUN_0002c258(void), FUN_0002a9f8(void), FUN_0002c2cc(void), FUN_00032d70(void);
extern int FUN_0002a1f4(void), FUN_00040b40(void);
#define B00077150_dR (*(short *)((char *)&B00077148_eJ + 8)) /* STANDIN: a name of its own in the original image, 8 bytes into B00077148_eJ */
extern int DAT_0005c050; extern unsigned short DAT_0005f038[];  struct MS { short x, y, b; };
extern char *PTR_s_no_visible_creatures_upo_000566ac, *PTR_s_upon_which_creature_is_t_000566b0;
int FUN_000195c0(void)
{
    int k, off, r, done, x, y;
    for (k = 0, off = 0; k <= DAT_0005f038[DAT_0005c050 ^ 1]; off += 0x16, k++) {
        if (*(short *)((char *)&B00077150_dR + (DAT_0005c050 ^ 1) * 0x2260 + off) == 0) break;
    }
    if (k == DAT_0005f038[DAT_0005c050 ^ 1]) {
        FUN_0002c21c(PTR_s_no_visible_creatures_upo_000566ac);
        FUN_0002c258();
        return -1;
    }
    FUN_0002c21c(PTR_s_upon_which_creature_is_t_000566b0);
    r = -1;
    done = 0;
    FUN_0002c258();
    FUN_0002a9f8();
    do {
        while (FUN_0002a1f4()) {
            if (FUN_00040b40() == 0x1b) { done = 1; break; }
        }
        if (done) break;
        while (!FUN_0002a1f4()) {
            if (FUN_00040b40() == 0x1b) { done = 1; break; }
        }
        if (done) break;
        if ((*(struct MS *)&DAT_00059e31).b & 2) break;
        x = (*(struct MS *)&DAT_00059e31).x;
        y = (*(struct MS *)&DAT_00059e31).y;
        if (x >= 4 && x < 0x104 && y >= 0x20 && y < 0x120) {
            r = FUN_000194e0(x, y - 0x20);
            if (r != -1) break;
        }
    } while (r == -1);
    FUN_0002c2cc();
    FUN_00032d70();
    return r;
}

#undef MS
/* ---- from src/CODE2/f196e0.c */
/* FUN_000196e0 @ 000196e0: give one of two items to party member i */
#include "chars.h"
extern void FUN_0003195c(int, int, int, int, int, int, int);
extern int B000755d0_ao, B000755d4_ak;
#define SLOT(i,k) (*(short *)(CHAR_REC(i) + 0x40 + (k) * 2))
int FUN_000196e0(int a, int b, int c, int d, int flag, int i)
{
    int k, r;
    for (k = 0; k < 12; k++) {
        if (SLOT(i, k) == -1) {
            if (flag) { r = 0; SLOT(i, k) = a; }
            else { r = 1; SLOT(i, k) = b; }
            break;
        }
    }
    if (k == 12) {
        if (flag) { FUN_0003195c(0x80, a, c, B000755d0_ao, B000755d4_ak, 1, 0); r = 0; }
        else { FUN_0003195c(0x80, b, d, B000755d0_ao, B000755d4_ak, 1, 0); r = 1; }
    }
    return r;
}

#undef SLOT
/* ---- from src/CODE2/wip/f19790.c (round 66 lane BE) */
/* MATCH round 66 lane BE (module m186c4.c context, -3s -ox -oe -oa -ot -w0): 956/954 (the +2 is the alignment pad).
   Lane AU's pass-2 draft plus the frame-slot fix: the slot order of the memory locals h2 / ok2 / ret / c1 / c2 is the order of
   the last RoughSortTemps output (TempAllocBefore keeps 4-byte input order).  One copy out and back on ok2 raises its rough
   savings 9 -> 11 (= h2, h1; real 22 = h1 / h2: no register change); the tie is then decided by the temp ids, i.e. the
   declaration order: `int c1, c2, ok2, w, ok1, ret, y, y2` gives ok2, h2, ret, c1, c2 (searched with a replay of both rough
   sorts and of the pass-1 conflict sort over all 10! declaration orders, build/var/r66be/sim19*.py; 7 of 7 predicted orders
   MATCH in the real 10.0a).  Two copies (13) win ok2 a register (90 lines). */
/* FUN_00019790 @ 00019790: party member i readies item `it` (a two-handed weapon 0x80, a shield 0xa5, else one hand): drop what the hands hold, set the hand slots, redraw both hand boxes and start the item's timer */
extern unsigned char FUN_0001f218(int, int);
extern void FUN_0001f238(int, int, int), FUN_0002ea90(int, int, int);
extern struct OPENC DAT_00056fa0[];
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
int FUN_00019790(int it, int i, int snd, int bit, int k, int a, int b)
{
    unsigned h1, h2; int c1, c2, ok2, w, ok1, ret, y, y2; /* STANDIN: y / y2 name the two redraw x values (tail allocation order); ok2 declared after c2 and ahead of w / ok1 (ids: the h2 / ok2 rough-sort tie at 11 goes to ok2, h1 stays first in the pass-1 tie at 22) */

    h1 = M000718e0_iO[i].inv[14];
    h2 = M000718e0_iO[i].inv[15];
    c1 = FUN_0001f218(i, 0xe);
    c2 = FUN_0001f218(i, 0xf);
    if (bit != -1 && (M000718e0_iO[i].f1c2 & bit)) return 0;
    ret = 1;
    ok2 = 1;
    ok1 = 1;
    w = 0;
    if (h1 >= 0x7e && h1 <= 0x86) ok1 = 0;
    { int c; c = ok1; ok1 = c; } /* STANDIN: copy out and back: +4 savings for ok1 (ties w, sorted ahead), no code */
    if (h2 >= 0x7e && h2 <= 0x86) ok2 = 0;
    { int c; c = ok2; ok2 = c; } /* STANDIN: copy out and back: ok2 rough savings 9 -> 11 (ties h2 in the last RoughSortTemps; real 18 -> 22 ties h1 / h2, no code change) */
    if (!ok1 && !ok2) return 0;
    if (it == 0xa5) {
        if (!ok1 || h1 == -1) ok1 = 0; /* STANDIN: the test split around the block (the two ok1 = 0 blocks merge after allocation) */
        else {
            struct ITEM *p, *c; unsigned o; /* STANDIN: block locals for the class test */
            o = h1 * sizeof(struct ITEM); /* STANDIN: offset named so the pointer load starts after it */
            p = ITEMS; c = p; p = c; /* STANDIN: copy out and back: pointer load savings 8 -> 12, allocated before the sum (EAX) */
            if (((struct ITEM *)((char *)p + o))->cls != 0xd || h1 == it) ok1 = 0; /* STANDIN: ITEMS[h1].cls through p / o */
        }
        if (!ok2 || h2 == -1 || ITEMS[h2].cls != 0xd || h2 == it) ok2 = 0;
    } else if (it == 0x80) {
        if (!ok1 || !ok2) return 0;
        if (ok1 && h1 != -1) FUN_000196e0(h1, h2, c1, c2, 1, i);
        if (ok2 && h2 != -1) FUN_000196e0(h1, h2, c1, c2, 0, i);
        w = 1;
    } else if (h1 == -1) w = 0;
    else if (h2 == -1) w = 1;
    else w = FUN_000196e0(h1, h2, c1, c2, ok1, i);
    if (w == 1) {
        DAT_00056fa0[i].kind = -1;
        DAT_00056fa0[i].type = -1;
        DAT_00056fa0[i].st = -1;
        DAT_00056fa0[i].item = -1;
    }
    if (it == 0x80) {
        M000718e0_iO[i].inv[14] = it;
        M000718e0_iO[i].inv[15] = it;
        FUN_0001f238(i, 0xe, 0);
        FUN_0001f238(i, 0xf, 0);
    } else if (it == 0xa5) {
        if (!ok1 && !ok2) ret = 0;
        else {
            if (ok1) {
                M000718e0_iO[i].inv[14] = it;
                FUN_0001f238(i, 0xe, 0);
            }
            if (ok2) {
                M000718e0_iO[i].inv[15] = it;
                FUN_0001f238(i, 0xf, 0);
            }
        }
    } else {
        M000718e0_iO[i].inv[14 + w] = it;
        FUN_0001f238(i, w + 0xe, 0);
        ret = 1;
    }
    FUN_0002ea90(i, w, -1);
    FUN_0002ea90(i, w ^ 1, -1);
    if (snd >= 0) {
        FUN_00038110((char *)(B000758d4_jG + snd), 0xff, 0, 1);
        FUN_00038168();
    }
    y = w * 33 + 4 + i % 2 * 0x35 + i / 2 * 0xd3;
    FUN_0002a8c8(DAT_0005c050, 0x114, y, 0x20, 0x10);
    y2 = (w ^ 1) * 33 + 4 + i % 2 * 0x35 + i / 2 * 0xd3;
    FUN_0002a8c8(DAT_0005c050, 0x114, y2, 0x20, 0x10);
    if (bit != -1) {
        M000718e0_iO[i].f1c2 |= bit;
        (&M000718e0_iO[i].f1c6)[k] = a * b + FUN_00029cc4();
    }
    return ret;
}

#undef M000718e0_iO
/* ---- from src/CODE2/f19b4c.c */
#define FX T13_FX
/* FUN_00019b4c @ 00019b4c: play spell effect fx over the portrait of party member who, or over every standing member when all is set */
struct FX { int img, x, y; unsigned char n, fr[20]; };
extern void FUN_0003e608(void), FUN_0002f494(int), FUN_0003975c(int, int, int, int, int), FUN_0002a8c8(int, int, int, int, int), FUN_00038168(void), FUN_0003e614(unsigned, int);
extern struct FX DAT_000566ec[]; extern unsigned char DAT_0005cf5a; extern unsigned short B000718f0_hO[]; extern int B000758dc_cl, DAT_0005c050; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
void FUN_00019b4c(int who, int fx, int all)
{
    struct FX *e; unsigned char *f, *g, *h; int y, k, j, p;
    e = &DAT_000566ec[fx];
    f = e->fr;
    if (!all) {
        y = who % 2 * 0x35 + who / 2 * 0xd3;
        for (k = 0; k < e->n; k++) {
            FUN_0003e608();
            (&DAT_0005cf5a)[who] = 1;
            FUN_0002f494(0);
            FUN_0003975c(*f, e->x, y + e->y, B000758dc_cl + e->img, 0);
            if (fx == 5) FUN_0003975c(*f, e->x, y + 0x21 + e->y, B000758dc_cl + e->img, 0);
            FUN_0002a8c8(DAT_0005c050, 0x113, y, 0x7d, 0x35);
            FUN_00038168();
            f++;
            FUN_0003e614(3, 0);
        }
    } else {
        for (j = 0, g = f; j < e->n; g++, j++) {
            FUN_0003e608();
            h = g;
            for (p = 0; p < 4; p++) {
                if (B000718f0_hO[p * 0x124] < 0x4000) {
                    y = p % 2 * 0x35 + p / 2 * 0xd3;
                    (&DAT_0005cf5a)[p] = 1;
                    FUN_0002f494(0);
                    FUN_0003975c(*h, e->x, y + e->y, B000758dc_cl + e->img, 0);
                    if (fx == 5) FUN_0003975c(*h, e->x, y + 0x21 + e->y, B000758dc_cl + e->img, 0);
                }
            }
            FUN_0002a8c8(DAT_0005c050, 0x113, 0, 0x7d, 0x140);
            FUN_00038168();
            FUN_0003e614(3, 0);
        }
    }
    (&DAT_0005cf5a)[who] = 1;
    FUN_0002f494(0);
    FUN_0002a8c8(DAT_0005c050, 0x113, y, 0x7d, 0x35);
}

#undef FX
/* ---- from src/CODE2/wip/f19d90.c */
/* NEAR MISS Round 34: MATCH in module 0x186c4 (DOSBox modmerge 20 -> 21/32) with the volatile on hp removed (68 -> 0 lines: the workaround kept hp out of the conflict list). Earlier: (round 31): the static say stand-in written out (module 0x186c4 has no function with its body; a mid-file static leaves a copy): 15 -> 68 masked lines in module (the first "cannot be resurrected" block: name in eax, orig esi), module 19 -> 20/32 (FUN_00019b4c no longer holds the copy); volatile hp still a stand-in. Round 22: read only (three spots). */
#define PC T14_PC
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
int sprintf(char *, const char *, ...);
extern int FUN_0002c328(int, int, int, int), FUN_00032e40(int, int);
extern void FUN_0002c21c(char *);
struct PC { char name[0x10]; unsigned short flags; char p12[2]; unsigned char race; char p15[7]; short hp, maxhp, lv[3]; char p26[0x10]; unsigned char b36, b37; char p38[0xfa]; unsigned int st132; char rest[0x248 - 0x136]; };

extern char DAT_0005759c[];
extern char *PTR_s__s_is_still_alive__000566c4, *PTR_s__s_cannot_be_resurrected__000566b8, *PTR_s__s_is_resurrected__000566b4, *PTR_s_you_cannot_resurrect_an_elf__000566bc;
extern unsigned char DAT_0005cf5a; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
#define FL1(p) (((unsigned char *)&M000718e0_iO[p].flags)[1])
#pragma aux FUN_0002c328 modify [ebx ecx edx];
int FUN_00019d90(int spell, int m, int c)
{
    int r = 1;
    int hp;
    switch (spell) {
    case -1:
        FL1(m) &= 0xf3;
        M000718e0_iO[m].hp += FUN_0002c328(r, 4, 0, 8);
        if (M000718e0_iO[m].hp > M000718e0_iO[m].maxhp) M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    case 0x7b:
        if (!(M000718e0_iO[m].flags & 0x4000)) {
            sprintf(DAT_0005759c, PTR_s__s_is_still_alive__000566c4, M000718e0_iO[m].name);
            r = 0;
            FUN_0002c21c(DAT_0005759c);
            break;
        }
        if (M000718e0_iO[m].flags & 0x8000) break;
        if (M000718e0_iO[m].race != 5) {
            if (M000718e0_iO[m].lv[0] == 0 || M000718e0_iO[m].lv[1] == 0 || M000718e0_iO[m].lv[2] == 0) {
                sprintf(DAT_0005759c, PTR_s__s_cannot_be_resurrected__000566b8, M000718e0_iO[m].name);
                FUN_0002c21c(DAT_0005759c);
                r = 0;
            } else if (M000718e0_iO[m].b37 && M000718e0_iO[m].b37 - M000718e0_iO[m].b36 < 5) {
                M000718e0_iO[m].hp = 1;
                FL1(m) &= 0xbf;
                (&DAT_0005cf5a)[m] = 1;
                M000718e0_iO[m].b37--;
                sprintf(DAT_0005759c, PTR_s__s_is_resurrected__000566b4, M000718e0_iO[m].name);
                r = 1;
                FUN_0002c21c(DAT_0005759c);
            } else {
                sprintf(DAT_0005759c, PTR_s__s_cannot_be_resurrected__000566b8, M000718e0_iO[m].name);
                r = 0;
                FUN_0002c21c(DAT_0005759c);
            }
        } else {
            FUN_0002c21c(PTR_s_you_cannot_resurrect_an_elf__000566bc);
            r = 0;
        }
        break;
    case 0x51:
        hp = FUN_0002c328(r, 8, 0, 0);
        if (M000718e0_iO[c].st132 & 0x8000) {
            M000718e0_iO[c].st132 &= 0xffff7fff;
            hp = 8;
        }
        M000718e0_iO[m].hp += hp;
        if (M000718e0_iO[m].hp > M000718e0_iO[m].maxhp) M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    case 0x6e:
        hp = FUN_0002c328(2, 8, 0, r);
        if (M000718e0_iO[c].st132 & 0x8000) {
            hp = 0x10;
            M000718e0_iO[c].st132 &= 0xffff7fff;
        }
        M000718e0_iO[m].hp += hp;
        if (M000718e0_iO[m].hp > M000718e0_iO[m].maxhp) M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    case 0x78:
        hp = FUN_0002c328(3, 8, 0, 3);
        if (M000718e0_iO[c].st132 & 0x8000) {
            hp = 0x1b;
            M000718e0_iO[c].st132 &= 0xffff7fff;
        }
        M000718e0_iO[m].hp += hp;
        if (M000718e0_iO[m].hp > M000718e0_iO[m].maxhp) M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    case 0x82:
        M000718e0_iO[m].flags &= 0x1c0;
        (&DAT_0005cf5a)[m] = 1;
        M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    case 0x71:
        if (M000718e0_iO[m].flags & 0x800) FL1(m) &= 0xf7;
        break;
    case 0x64:
        if (M000718e0_iO[m].flags & 0x400) FL1(m) &= 0xfb;
        break;
    case 0x68:
        if (M000718e0_iO[m].flags & 0x1000) FL1(m) &= 0xef;
        break;
    case 0x57:
        hp = FUN_00032e40(r, c) * 2;
        M000718e0_iO[m].hp += hp;
        if (M000718e0_iO[m].hp > M000718e0_iO[m].maxhp) M000718e0_iO[m].hp = M000718e0_iO[m].maxhp;
        break;
    }
    return r;
}

#undef M000718e0_iO
#undef PC
#undef FL1
/* ---- from src/CODE2/f1a254.c (round 62 second blind rewrite) */
extern void FUN_00019b4c(int who, int fx, int all); /*-*/
extern int FUN_00019d90(int spell, int m, int c); /*-*/
#define MS T15_MS
/*-*/
/*-*/
/*-*/
/*-*/
/*-*/
extern void FUN_0002f494(int), FUN_0002c21c(char *), FUN_0002c258(void), FUN_0002c2cc(void), FUN_00032d70(void);
#include "dice.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
#define FUN_00038110 ((void (*)(int, int, int, int))FUN_00038110)
extern int FUN_0002a1f4(void), FUN_00029cc4(void), FUN_00032e40(int, int);
extern unsigned char DAT_0005cf5a, DAT_0005d681, DAT_0005d682; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
extern char *PTR_s_cast_spell_on_which_character_000566c0;
struct MS { short x, y, b; };

extern char DAT_0005d684[];
extern int B000758d4_jG;
#define DAT_0005d684 ((short (*)[4])DAT_0005d684)
/*-*/
int FUN_0001a254(int eff, int spell, int a, int dur, int snd, int lvl, int flag, int mul)
{
    int k, i, my, s1, done, s2, r, mx;

    (&DAT_0005cf5a)[0] = 1;
    (&DAT_0005cf5a)[1] = 1;
    (&DAT_0005cf5a)[2] = 1;
    (&DAT_0005cf5a)[3] = 1;
    s1 = DAT_0005d681;
    DAT_0005d681 = 0;
    s2 = DAT_0005d682;
    DAT_0005d682 = 0;
    FUN_0002f494(1);
    FUN_0002c21c(PTR_s_cast_spell_on_which_character_000566c0);
    FUN_0002c258();
    done = 0;
    r = 1;
    while (!done) {
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        if ((*(struct MS *)&DAT_00059e31).b & 2) {
            r = 0;
            done = 1;
        } else {
            mx = (*(struct MS *)&DAT_00059e31).x;
            my = (*(struct MS *)&DAT_00059e31).y;
            for (k = 4; k <= 16; k += 4) {
                if (mx >= DAT_0005d684[k][0] && mx <= DAT_0005d684[k][2] && my >= DAT_0005d684[k][1] && my <= DAT_0005d684[k][3]) {
                    i = k / 4 - 1;
                    if (spell == 0x7b) {
                        if (M000718e0_iO[i].fl & 0x8000) break;
                    } else if (spell == 0x68) {
                        if (!(M000718e0_iO[i].fl & 0x1000)) break;
                    } else if (spell == 0x71) {
                        if (!(M000718e0_iO[i].fl & 0x800)) break;
                    } else if (spell == 0x5d) {
                        if (!(M000718e0_iO[i].fl & 0x800)) break;
                    } else if (spell == 0x64) {
                        if (!(M000718e0_iO[i].fl & 0x400)) break;
                    } else if (M000718e0_iO[i].fl >= 0x4000) break;
                    if (snd >= 0) FUN_00038110(B000758d4_jG + snd, 0xff, 0, 1);
                    if (a >= 0) {
                        FUN_00019b4c(i, a, 0);
                        if (!flag) {
                            M000718e0_iO[i].f132 |= eff;
                            if (dur) M000718e0_iO[i].t[spell] = FUN_00029cc4() + dur * mul;
                            if (eff == 0x40) M000718e0_iO[i].f1f2 += FUN_0002c328(1, 4, 0, FUN_00032e40(4, lvl) / 2);
                            if (eff == 0x800) M000718e0_iO[i].f1ea += FUN_0002c328(1, 8, 0, 0);
                        } else r = FUN_00019d90(spell, i, lvl);
                    } else r = FUN_00019d90(spell, i, lvl);
                    if (spell == 0) {
                        M000718e0_iO[i].t[0] = 0;
                        M000718e0_iO[i].r10b[3] = FUN_00032e40(4, i) + 8;
                    }
                    done = 1;
                    break;
                }
            }
        }
    }
    FUN_0002c2cc();
    DAT_0005d681 = s1;
    DAT_0005d682 = s2;
    (&DAT_0005cf5a)[0] = 1;
    (&DAT_0005cf5a)[1] = 1;
    (&DAT_0005cf5a)[2] = 1;
    (&DAT_0005cf5a)[3] = 1;
    if (DAT_0005d681) DAT_0005d681 = 2;
    if (DAT_0005d682) DAT_0005d682 = 2;
    FUN_0002f494(1);
    FUN_00032d70();
    return r;
}

#undef M000718e0_iO
#undef FUN_00038110
#undef MS
#undef DAT_0005d684
/* ---- from src/CODE2/f1a5bc.c */
/* FUN_0001a5bc @ 0001a5bc: mark the four portraits and remember/clear the two side panels, then redraw */
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh; extern void FUN_0002f494(int);
void FUN_0001a5bc(void)
{
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    B00062ba0_hT = DAT_0005d681;
    DAT_0005d681 = 0;
    B00062ba4_hh = DAT_0005d682;
    DAT_0005d682 = 0;
    FUN_0002f494(1);
}

/* ---- from src/CODE2/f1a60c.c */
/* FUN_0001a60c @ 0001a60c: restore the two side panels saved by FUN_0001a5bc and redraw */
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh; extern void FUN_0002f494(int);
void FUN_0001a60c(void)
{
    DAT_0005d681 = B00062ba0_hT;
    DAT_0005d682 = B00062ba4_hh;
    if (DAT_0005d681) DAT_0005d681 = 2;
    if (DAT_0005d682) DAT_0005d682 = 2;
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    FUN_0002f494(1);
}

/* ---- from src/CODE2/f1a668.c */
extern void FUN_00019b4c(int who, int fx, int all); /* module prototype */
/* FUN_0001a668 @ 0001a668: camp overnight: fade, run the night, restore the party flags and set the wake-up timers */
extern void FUN_00038110(char *, int, int, int), FUN_0002f494(int); extern int FUN_00032e40(int, int), FUN_00029cc4(void);
#define B00071a6a_fy (*(int *)((char *)&B000718e0_iO + 394)) /* STANDIN: view, B000718e0_iO + 0x18a */
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh;
void FUN_0001a668(int i)
{
    int k, off, t;
    FUN_00038110(((char *)B000758d4_jG) + 0x3e, 0xff, 0, 1);
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    B00062ba0_hT = DAT_0005d681;
    DAT_0005d681 = 0;
    B00062ba4_hh = DAT_0005d682;
    DAT_0005d682 = 0;
    FUN_0002f494(1);
    FUN_00019b4c(i, 2, 1);
    DAT_0005d681 = B00062ba0_hT;
    DAT_0005d682 = B00062ba4_hh;
    if (DAT_0005d681) DAT_0005d681 = 2;
    if (DAT_0005d682) DAT_0005d682 = 2;
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    FUN_0002f494(1);
    for (k = 0, off = 0; k < 4; k++, off += 0x248) {
        if (!(*(unsigned short *)((char *)&(*(unsigned short *)&B000718f0_hO) + off) & 0x8000)) {
            (&DAT_0005cf5a)[k] = 1;
            *(int *)((char *)&B00071a14_ff + off) |= 0x20;
            t = FUN_00032e40(3, i) * 0x438;
            *(int *)((char *)&B00071a6a_fy + off) = FUN_00029cc4() + t;
        }
    }
}

/* ---- from src/CODE2/f1a794.c */
extern void FUN_00019b4c(int who, int fx, int all); /* module prototype */
/* FUN_0001a794 @ 0001a794: rest/camp: run the two-phase screen fade with the party status flags set */
#include "chars.h"
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
extern void FUN_0002f494(int);
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh;
void FUN_0001a794(int i)
{
    int k, off;
    FUN_00038110(((char *)B000758d4_jG) + 0x30, 0xff, 0, 1);
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    B00062ba0_hT = DAT_0005d681;
    DAT_0005d681 = 0;
    B00062ba4_hh = DAT_0005d682;
    DAT_0005d682 = 0;
    FUN_0002f494(1);
    FUN_00019b4c(i, 2, 1);
    DAT_0005d681 = B00062ba0_hT;
    DAT_0005d682 = B00062ba4_hh;
    if (DAT_0005d681) DAT_0005d681 = 2;
    if (DAT_0005d682) DAT_0005d682 = 2;
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    FUN_0002f494(1);
    for (k = 0, off = 0; k < 4; k++, off += 0x248) {
        if (!(*(unsigned short *)((char *)&(*(unsigned short *)&B000718f0_hO) + off) & 0x8000)) {
            (&DAT_0005cf5a)[k] = 1;
            *(int *)((char *)&B00071a12_dx + i * 0x248) |= 0x20;
        }
    }
}

#undef FUN_00038110
/* ---- from src/CODE2/f1a8a0.c */
extern void FUN_00019b4c(int who, int fx, int all); /* module prototype */
#define FUN_0002202c ((int (*)(int, int))FUN_0002202c)
/* FUN_0001a8a0 @ 0001a8a0: party member i prays/meditates: fade, run the time, set the next prayer time and memorise spells; 0 when already done (n = q; n++ keeps n in the register of the quotient as in the original under the module's -oa; n = q + 1 put it in a new one) */
extern void FUN_00038110(char *, int, int, int), FUN_0002f494(int); extern int FUN_00032e40(int, int), FUN_00029cc4(void);
#define B00071a13_eo (*(int *)((char *)&B000718e0_iO + 307)) /* STANDIN: view, B000718e0_iO + 0x133 */
#define B00071a46_dE (*(int *)((char *)&B000718e0_iO + 358)) /* STANDIN: view, B000718e0_iO + 0x166 */
#define B00071a03_do (*(int *)((char *)&B000718e0_iO + 291)) /* STANDIN: view, B000718e0_iO + 0x123 */
#define B000718f4_h3 (*(unsigned char *)((char *)&B000718e0_iO + 20)) /* STANDIN: view, B000718e0_iO + 0x14 */
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh;
#define CH(sym, i) (*(int *)((char *)&sym + (i) * 0x248))
#define CH8(sym, i) (*((unsigned char *)&sym + (i) * 0x248))
int FUN_0001a8a0(int i)
{
    int t, n, r;
    if (CH(B00071a13_eo, i) & 0x10) {
        r = 0;
    } else {
        FUN_00038110(((char *)B000758d4_jG) + 0x1a, 0xff, 0, 1);
        DAT_0005cf5a = 1;
        DAT_0005cf5b = 1;
        DAT_0005cf5c = 1;
        DAT_0005cf5d = 1;
        B00062ba0_hT = DAT_0005d681;
        DAT_0005d681 = 0;
        B00062ba4_hh = DAT_0005d682;
        DAT_0005d682 = 0;
        FUN_0002f494(1);
        FUN_00019b4c(i, 2, 0);
        DAT_0005d681 = B00062ba0_hT;
        DAT_0005d682 = B00062ba4_hh;
        if (DAT_0005d681) DAT_0005d681 = 2;
        if (DAT_0005d682) DAT_0005d682 = 2;
        DAT_0005cf5a = 1;
        DAT_0005cf5b = 1;
        DAT_0005cf5c = 1;
        DAT_0005cf5d = 1;
        FUN_0002f494(1);
        CH(B00071a13_eo, i) |= 0x10;
        t = FUN_00032e40(3, i) * 0x438;
        CH(B00071a46_dE, i) = FUN_00029cc4() + t;
        n = FUN_00032e40(3, i) / 3;
        n++;
        if (CH8(B000718f4_h3, i) == 2) {
            if (CH8(B00071912_a3, i) + n > 0x11) n = 0x11 - CH8(B00071912_a3, i);
        } else {
            if (CH8(B00071912_a3, i) + n > 0x12) n = 0x12 - CH8(B00071912_a3, i);
        }
        CH(B00071a03_do, i) = FUN_0002202c(i, n);
        r = 1;
    }
    return r;
}

#undef FUN_0002202c
#undef CH
#undef CH8
/* ---- from src/CODE2/f1aa30.c */
extern void FUN_00019b4c(int who, int fx, int all); /* module prototype */
/* FUN_0001aa30 @ 0001aa30: party member i studies the spell book: fade, run the time, set the next study time and learn spells; 0 when already done */
extern void FUN_00038110(char *, int, int, int), FUN_0002f494(int); extern int FUN_00032e40(int, int), FUN_00029cc4(void);
#define B00071a4a_dy (*(int *)((char *)&B000718e0_iO + 362)) /* STANDIN: view, B000718e0_iO + 0x16a */
#define B00071a07_dk (*(int *)((char *)&B000718e0_iO + 295)) /* STANDIN: view, B000718e0_iO + 0x127 */
#define B00071915_a0 (*(unsigned char *)((char *)&B000718e0_iO + 53)) /* STANDIN: view, B000718e0_iO + 0x35 */
extern unsigned char DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern int B00062ba0_hT, B00062ba4_hh;
#define CH(sym, i) (*(int *)((char *)&sym + (i) * 0x248))
#define CH8(sym, i) (*((unsigned char *)&sym + (i) * 0x248))
int FUN_0001aa30(int i)
{
    int t, n, r;
    if (CH(B00071a13_eo, i) & 0x20) {
        r = 0;
    } else {
        FUN_00038110(((char *)B000758d4_jG) + 0x19, 0xff, 0, 1);
        DAT_0005cf5a = 1;
        DAT_0005cf5b = 1;
        DAT_0005cf5c = 1;
        DAT_0005cf5d = 1;
        B00062ba0_hT = DAT_0005d681;
        DAT_0005d681 = 0;
        B00062ba4_hh = DAT_0005d682;
        DAT_0005d682 = 0;
        FUN_0002f494(1);
        FUN_00019b4c(i, 2, 0);
        DAT_0005d681 = B00062ba0_hT;
        DAT_0005d682 = B00062ba4_hh;
        if (DAT_0005d681) DAT_0005d681 = 2;
        if (DAT_0005d682) DAT_0005d682 = 2;
        DAT_0005cf5a = 1;
        DAT_0005cf5b = 1;
        DAT_0005cf5c = 1;
        DAT_0005cf5d = 1;
        FUN_0002f494(1);
        CH(B00071a13_eo, i) |= 0x20;
        t = FUN_00032e40(3, i) * 0x438;
        CH(B00071a4a_dy, i) = FUN_00029cc4() + t;
        n = FUN_00032e40(3, i) / 3 + 1;
        if (CH8(B000718f4_h3, i) == 2 || CH8(B000718f4_h3, i) == 5) {
            if (CH8(B00071915_a0, i) + n > 0x13) n = 0x13 - CH8(B00071915_a0, i);
        } else {
            if (CH8(B00071915_a0, i) + n > 0x12) n = 0x12 - CH8(B00071915_a0, i);
        }
        CH(B00071a07_dk, i) = n;
        CH8(B00071915_a0, i) += n;
        r = 1;
    }
    return r;
}

#undef CH
#undef CH8
/* ---- from src/CODE2/f1abc4.c */
/* FUN_0001abc4 @ 0001abc4 */
#include "world.h"
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
 extern unsigned char *FUN_0002e8c8(int, int);
extern int B00065a2c_ay;
void FUN_0001abc4(int i)
{
    int pos = *(int *)((char *)&B00065a2c_ay + i * 0x1c);
    int x, y;
    unsigned char *p;
    x = pos % B00075618_b1.w;
    y = pos % B00075618_b1.h;
    FUN_00038110(((char *)B000758d4_jG) + 0x49, 0xff, 0, 1);
    p = FUN_0002e8c8(x, y);
    if (p && p[0] == 1) *(int *)(p + 1) |= 0x40;
}

#undef FUN_00038110
/* ---- from src/CODE2/f1ac2c.c */
/* FUN_0001ac2c @ 0001ac2c: use the object in front of entity i (door toggle / lever); compiled with its module's
   -oa, where the natural declaration order x, y gives the original registers (without -oa it needed y before x) */
#include "world.h"
#define FUN_0002e8c8 ((struct OBJ *(*)(int, int))FUN_0002e8c8)
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
struct OBJ { unsigned char kind; unsigned char f0 : 2, open : 1, f3 : 3, b6 : 1, b7 : 1; signed char c2; unsigned char p3, p4, p5, c6; };
extern void FUN_000102a8(int), FUN_0002c77c(int, int);  extern int FUN_00030c0c(int, int, struct OBJ *), FUN_00030cf4(int), FUN_0002c924(void);
extern int B00065a2c_ay;
void FUN_0001ac2c(int i)
{
    int pos = *(int *)((char *)&B00065a2c_ay + i * 0x1c);
    int x, y, saved; struct OBJ *p;
    x = pos % B00075618_b1.w;
    y = pos % B00075618_b1.h;
    FUN_00038110(((char *)B000758d4_jG) + 0x32, 0xff, 0, 1);
    p = FUN_0002e8c8(x, y);
    if (p) {
        if (p->kind == 1) {
            if (*(int *)((char *)p + 1) & 0x40) *(int *)((char *)p + 1) &= ~0x40;
            else if (p->c6) {
                saved = p->open;
                p->open = 1;
                FUN_00030c0c(x, y, p);
                p->open = saved;
            }
        } else if (p->kind == 4) {
            if (FUN_00030cf4(p->c6)) {
                FUN_000102a8(p->c2);
                *(int *)((char *)p + 1) &= ~4;
                return;
            }
            FUN_0002c77c(FUN_0002c924(), 0x320);
        }
    }
}

#undef FUN_0002e8c8
#undef FUN_00038110
/* ---- from src/CODE2/f1ad24.c */
extern void FUN_000186c4(int i, int k); /* module prototype */
extern void FUN_0001871c(int who, unsigned e); /* module prototype */
extern void FUN_0001893c(void); /* module prototype */
/* FUN_0001ad24 @ 0001ad24: end the timed effects of party member who (-1: all four): first the 26 condition bits, then the 9 spell-effect slots */

 extern unsigned char DAT_0005cf5a; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
#define CH(k, a) (*(int *)((char *)&a + (k) * 0x248))
void FUN_0001ad24(int who)
{
    int lo, hi, k, j;
    if (who == -1) { lo = 0; hi = 4; }
    else { lo = who; hi = who + 1; }
    for (k = lo; k < hi; k++) {
        if (!(*(unsigned short *)((char *)&(*(unsigned short *)&B000718f0_hO) + k * 0x248) & 0x8000))
            for (j = 0; j < 0x1a; j++) if (CH(k, B00071a12_dx) & (1 << j)) FUN_0001871c(k, j);
    }
    for (k = lo; k < hi; k++) {
        if (!(*(unsigned short *)((char *)&(*(unsigned short *)&B000718f0_hO) + k * 0x248) & 0x8000))
            for (j = 0; j < 9; j++) {
                if (CH(k, B00071aa2_ht) & (1 << j)) {
                    CH(k, B00071aa2_ht) ^= 1 << j;
                    (&DAT_0005cf5a)[k] = 1;
                    *(int *)((char *)&B00071aa2_ht + k * 0x248 + 4 + j * 4) = 0;
                    FUN_000186c4(k, j);
                }
            }
    }
    FUN_0001893c();
}

#undef CH
/* ---- from src/CODE2/f1ae30.c */
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
/* FUN_0001ae30 @ 0001ae30: fly a missile along the view direction until it hits something (the step is an int d[2] array: d[0] = dy, d[1] = dx) */
extern void FUN_0003df2c(int *, int *, int, int), FUN_0002f1c8(void), FUN_0002ea78(void); extern short FUN_0003d5d0(int, int, int);
extern int B000755d0_ao, B000755d4_ak, DAT_0005c658;
void FUN_0001ae30(void)
{
    int x, y, d[2];
    x = B000755d0_ao;
    y = B000755d4_ak;
    FUN_00038110((*(char **)&B000758d4_jG) + 0x48, 0xff, 0, 1);
    while (1) {
        FUN_0003df2c(&d[1], &d[0], 0x5000, DAT_0005c658);
        B000755d0_ao += d[1];
        B000755d4_ak += d[0];
        if (FUN_0003d5d0(B000755d4_ak, B000755d0_ao, -2) == 0) break;
        FUN_0002f1c8();
        FUN_0002ea78();
    }
    B000755d0_ao = x;
    B000755d4_ak = y;
    FUN_0002f1c8();
    FUN_0002ea78();
}

#undef FUN_00038110
/* ---- from src/CODE2/f1aed8.c (round 62 second blind rewrite) */
#include "world.h"
#define M00064d80_ay ((struct ENT *)B00064d80_ay)
struct ENT { int y, x; unsigned lo : 24, fb0 : 1, dead : 1, fb2 : 2, st : 2, fb6 : 2;
    unsigned short cell, type; short timer, hp; unsigned short w14; };
struct MT { char name[0x16]; unsigned short rad; char p18[0x16]; unsigned f2e : 31, nokill : 1; int imm; char p36[0xf]; };
extern short B000755d2_ai, B000755d6_ae;  extern unsigned char *B00072230_c4;
void FUN_0001aed8(int who)
{
    int i, j, k, x, y, x0, y0, n, cell;

    n = FUN_0002c328(4, 20, 0, 0);
    x0 = B000755d2_ai - 1;
    y0 = B000755d6_ae - 1;
    FUN_00038110((char *)(B000758d4_jG + 0x12), 0xff, 0, 1);
    for (j = 0; j < 2; j++) {
        if (y0 + j >= 0 && y0 + j < B00075618_b1.h) {
            y = y0 + j;
            for (k = 0; k < 2; k++) {
                x = x0 + k;
                if (x >= 0 && x < B00075618_b1.w) {
                    cell = B00075618_b1.w * y + x;
                    for (i = 0; i < B00075618_b1.nent; i++) {
                        if (!M00064d80_ay[i].dead && FUN_0003acdc(M00064d80_ay[i].type) && M00064d80_ay[i].type != 8 && M00064d80_ay[i].cell == cell) {
                            if (n <= 0) return;
                            if (!((struct MT *)(B00072230_c4 + M00064d80_ay[i].type * 0x45))->nokill) {
                                n--;
                                FUN_0001e284(&M00064d80_ay[i], B00072230_c4 + M00064d80_ay[i].type * 0x45, i, M00064d80_ay[i].hp + 1, 0);
                            }
                        }
                    }
                }
            }
        }
    }
}

#undef M00064d80_ay
/* ---- from src/CODE2/wip/f1b02c.c (round 66 lane BG) */
/* MATCH round 66 lane BG (module m186c4.c context, -3s -ox -oe -oa -ot -w0): 996/994 (the +2 is the alignment pad).
   (a) do-loop zero EBP -> EDI: the a-loop as `for (a = a0; ; a++) { if (a > a1) break; ... }` (no guard twist from
   the for condition) puts the do-loop after the a-loop in the interval block order, so the a-loop zero's
   `MOV 0 => EBP` is no longer inside the do-loop zero's range (CountRegMoves): EDI wins; the rest of the code is unchanged.
   (b) frame slots: y must stay a scalar (a record member is memory at ExpandOps: the mem-mem ops get early needs_one EAX/AX
   temps, GivenRegisters then flips the mark-loop ties, and the stores use EAX where the original has EBX).  So the ray step
   is two address-taken scalars dx / dy (4-byte, like y / hit), and the TempAllocBefore ShellSort perturbation
   decides the order: replayed offline (rough sorts + slot sort, build/var/r66bg/dsim*.py, 6/6 lever predictions exact),
   searched over declaration orders and copy-out-and-back levers (+2 depth 0, +40 a-loop, +800 r-loop rough savings):
   r +800 (one copy in the r-loop), save +1640 (two in the r-loop, one in the a-loop) and the declaration order below
   give bits, x, r, a, save, dx, dy, y, hit as in the original.  No register changes. */
/* FUN_0001b02c @ 0001b02c: a fan of rays from the party; every cell a ray reaches gets an effect record of the given kind, entities standing there are hit */
struct SPX { union FX a, b; int dir; unsigned short cell, type; short timer, w12; unsigned short b0 : 1, st : 2, face : 3, fr : 3, rest : 7; };
struct EFL { int a, b; int fl; unsigned short s, type; short timer, hp; unsigned short w14; };
struct MCELL { unsigned short lo : 6, seen : 1, door : 1, rest : 8; };
#define B000748ec_bk ((struct SPX *)B000748ec_bk)
#define M00064d80_ay ((struct EFL *)B00064d80_ay)
#define M000698e0_b7 ((struct MCELL *)B000698e0_b7)
extern int B000758bc_al;
extern short FUN_0002e930(int);
void FUN_0001b02c(int a0, int a1, int range, int dmg, int mask, int mark, int kind, int snd, int px, int py)
{
    union FX x; int r; int a; int cell; int save; int dx; int done; int i; int dy; int k; unsigned char *t; int rr; int ang; /* STANDIN: ray step as two scalars dx = d[1], dy = d[0]; declaration order searched (frame slot order) */

    save = DAT_0005c02f;
    DAT_0005c02f = 0;
    for (a = a0; ; a++) { if (a > a1) break; { /* STANDIN: exit test as a break (block order: do-loop zero in EDI) */
        int hit; union FX y; /* STANDIN: block-scoped (late ids: slot order) */
        rr = rand(); /* STANDIN: rr built in two statements: the hoisted (rr & 7) << 6 is computed in rr's register */
        rr = (unsigned)rr * 3 >> 15;
        ang = DAT_0005c658 + a;
        while (ang < 0) ang += 360;
        while (ang >= 360) ang -= 360;
        FUN_0003df2c(&dx, &dy, 0xa000, ang);
        y.v = py;
        x.v = px;
        while (FUN_0003c9dc(y.v, x.v)) {
            y.v += dy;
            x.v += dx;
        }
        if (y.s.i > B00075618_b1.h || x.s.i > B00075618_b1.w) {
            DAT_0005c02f = save;
            return;
        }
        hit = 0;
        { int c; c = save; save = c; } /* STANDIN: copy out and back (frame slot order) */
        for (r = 0; r <= range; r++) {
            { int c; c = save; save = c; } /* STANDIN: copy out and back (frame slot order) */
            { int c; c = save; save = c; } /* STANDIN: copy out and back (frame slot order) */
            { int c; c = r; r = c; } /* STANDIN: copy out and back (frame slot order) */
            y.v += dy;
            x.v += dx;
            if (y.s.i >= B00075618_b1.h || x.s.i >= B00075618_b1.w) continue;
            cell = y.s.i * B00075618_b1.w + x.s.i;
            if (M000698e0_b7[cell].door) {
                if (FUN_0002e930(cell)) hit = 1;
            } else if (M000698e0_b7[cell].lo) hit = 1;
            if (hit) break;
            if (mark) {
                for (i = 0; i < DAT_0005c038; i++)
                    if (B000748ec_bk[i].cell == cell) break;
            } else i = DAT_0005c038;
            if (i == DAT_0005c038) {
                B000748ec_bk[i].b.v = x.v;
                B000748ec_bk[i].a.v = y.v;
                if (mark) {
                    B000748ec_bk[i].b.s.f = 0x8000;
                    B000748ec_bk[i].a.s.f = 0x8000;
                }
                B000748ec_bk[i].cell = cell;
                B000748ec_bk[i].type = kind;
                B000748ec_bk[i].fr = rr;
                if (kind == 8) B000748ec_bk[i].fr = (unsigned)rand() * 3 >> 15;
                DAT_0005c038++;
                for (k = 0; k <= B00075618_b1.nent; k++) {
                    if (!(M00064d80_ay[k].fl & 0x2000000) && M00064d80_ay[k].s == cell && (M00064d80_ay[k].fl & 0x10000000) && M00064d80_ay[k].hp != 0) {
                        if (kind == 0xb) {
                            if (M00064d80_ay[k].type == 8 && M00064d80_ay[k].hp <= 10) {
                                M00064d80_ay[k].hp -= 2;
                                FUN_0001e284(&M00064d80_ay[k], B00072230_c4 + M00064d80_ay[k].type * 0x45, k, 0, 0);
                            }
                        } else {
                            t = B00072230_c4 + M00064d80_ay[k].type * 0x45;
                            if (!(*(int *)(t + 0x31) & mask)) FUN_0001e284(&M00064d80_ay[k], t, k, dmg, 0);
                        }
                    }
                }
            }
        }
    }} /* STANDIN: closes the break-form a-loop */
    if (kind == 8 || kind == 0) FUN_00038110((char *)(B000758bc_al + 0x19), 0xff, 0, 1);
    else FUN_00038110((char *)(B000758d4_jG + snd), 0xff, 0, 1);
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038168();
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_0002f1c8();
    FUN_0002ea78();
    done = 0;
    do {
        for (i = 0; i < DAT_0005c038; i++) {
            if (B000748ec_bk[i].type == kind) {
                FUN_00018c88(i);
                break;
            }
        }
        if (i == DAT_0005c038) done = 1;
    } while (!done);
    DAT_0005c02f = save;
}

#undef B000748ec_bk
#undef M00064d80_ay
#undef M000698e0_b7

/* ---- from src/CODE2/f1b410.c */
extern void FUN_00018c88(int i); /* module prototype */
/* FUN_0001b410 @ 0001b410: a monster dies: record the corpse, spawn loot, play the death animation */
#include "dice.h"
#define B00072230_c4 ((char *)B00072230_c4)
#define FUN_0001e284 ((void (*)(void *, int, int, int, int))FUN_0001e284)
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
extern void FUN_0002f1c8(void), FUN_0002ea78(void), FUN_00038168(void);
#define B00064d8c_bX (*(unsigned short *)((char *)&B00064d80_ay + 12)) /* STANDIN: view, B00064d80_ay + 0xc */
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
#define B00064d84_aE (*(int *)((char *)&B00064d80_ay + 4)) /* STANDIN: view, B00064d80_ay + 0x4 */
extern int DAT_0005c038; 
#define CORPSE(o) ((char *)&B000748ec_bk + DAT_0005c038 * 0x16 + (o))
void FUN_0001b410(int i)
{
    int r, v; char *mon;
    v = *(int *)((char *)&B00064d84_aE + i * 0x16);
    *(short *)CORPSE(0xe) = 10;
    *(int *)CORPSE(4) = v;
    *(int *)CORPSE(0) = *(int *)((char *)&(*(int *)&B00064d80_ay) + i * 0x16);
    *(unsigned short *)CORPSE(0xc) = *(unsigned short *)((char *)&B00064d8c_bX + i * 0x16);
    DAT_0005c038++;
    r = FUN_0002c328(6, 8, 0, 0);
    mon = B00072230_c4 + *(unsigned short *)((char *)&B00064d8e_a6 + i * 0x16) * 0x45;
    if (!(*(int *)(mon + 0x32) & 0x21)) FUN_0001e284((char *)&(*(int *)&B00064d80_ay) + i * 0x16, (int)mon, i, r, 0);
    FUN_00038110(((char *)B000758d4_jG) + 0x20, 0xff, 0, 1);
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038168();
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038110(((char *)B000758d4_jG) + 0x21, 0xff, 0, 1);
    FUN_00038168();
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038168();
    FUN_0002f1c8();
    FUN_0002ea78();
    FUN_00038168();
    FUN_00018c88(DAT_0005c038 - 1);
}

#undef B00072230_c4
#undef FUN_0001e284
#undef FUN_00038110
#undef CORPSE
/* ---- from src/CODE2/wip/f1b518.c */
/* NEAR MISS (round 23, module 0x186c4 -oa, 17 worklist lines) a. first differences: roll/lv/k frame slots rotated, then the two party distances: the original computes both differences (eax = y - e[0], ebp = x - e[4]) before the first abs test; decision: the source keeps both differences in variables ahead of the two tests (ours computes each inside its test). b. read from the listing: dy, dx assigned, then if (abs(dy) >= K) continue; if (abs(dx) >= K) continue. c. both differences in variables first: 17 -> 12 lines (STRUCT -> REG; 3 real; size +3 from the register encodings, was -1 with the other shape). Left: dx in ebx (orig ebp, which later holds hd: dx as hd gives the same), and the roll/lv/k slot rotation (declaration order roll, lv, k: no change). Earlier: 58 instr (3 bytes): plain indexed loop gives the right frame; the three spilled scalars land in rotated slots (orig roll 0x1c, lv 0x18, k 0x14; declaration order has no effect with the cnt[5] array) and the monster record pointer is ebx instead of edx */
/* Round 28 (real trace): class D. Slots k -4, roll -8, lv -12, cnt -32; forcing roll,lv,k gives 3 lines (from 12), so slots plus another difference. The slot input order is not the declaration order: 1008 declaration placements of roll/lv/k (cnt first or last) all 12 lines (k keeps -4 with the lowest id). */
/* FUN_0001b518 @ 0001b518: party member i turns undead (evil: command); every visible undead within 10 cells is checked against the turning table */
#include <stdlib.h>
#include "dice.h"
#include "world.h"
#define M00064d80_ay ((char *)B00064d80_ay)
#define M000718e0_iO ((char *)&B000718e0_iO)
#define B00072230_c4 ((char *)B00072230_c4)
#define FUN_0001e284 ((void (*)(char *, char *, int, int, int))FUN_0001e284)
void *memset(void *, int, unsigned);
extern int FUN_00032e40(int, int); 
  extern int B000755d4_ak, B000755d0_ao; extern signed char DAT_000567b2[];
#define EI(k, o) (*(int *)(M00064d80_ay + (k) + (o)))
#define EU(k, o) (*(unsigned short *)(M00064d80_ay + (k) + (o)))
/* Round 54 (8 compiles + trace): slots k / roll / lv rotated (here k, roll, lv top-down; original roll, lv, k) and dy in EBX (original EBP); sw.py: only an inserted size-1/2 temp at input 12 .. 59 (or t85 moved). Byte views of the int flag tests change the code (test dword stays in 10.0a: 17-23), byte |= 0x10 (13), k += 1 / k = 0 before the for / nent > k (13). */
#undef M00064d80_ay
#undef M000718e0_iO
#undef B00072230_c4
#undef FUN_0001e284
#pragma pack(1)
struct E61 { int a, b; int fl; unsigned short s, type; short timer, hp; unsigned short w14; };
struct MT61 { char name[0x16]; unsigned short rad; char p18[5]; unsigned char hd; char p1e[0x13]; int f31; char p35[5]; int f3a; char p3e[7]; };
struct PC61 { char p0[0x132]; int st; char rest[0x248 - 0x136]; };
#pragma pack()
#define M00064d80_ay ((struct E61 *)B00064d80_ay)
#define B00072230_c4 ((struct MT61 *)B00072230_c4)
#define M000718e0_iO ((struct PC61 *)&B000718e0_iO)
#define FUN_0001e284 ((void (*)(struct E61 *, struct MT61 *, int, int, int))FUN_0001e284)
void FUN_0001b518(int i, int evil)
{
    int left[5];
    int k, lvl, roll, n, t, r, dy, dx;
    if (M000718e0_iO[i].st & 0x200) return;
    memset(left, 0, sizeof(left));
    roll = FUN_0002c328(1, 0x14, 0, 0);
    if (evil) lvl = FUN_00032e40(i, 1) - 2;
    else lvl = FUN_00032e40(i, 3);
    n = FUN_0002c328(2, 6, 0, 0);
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (!B000698e0_b7[M00064d80_ay[k].s].seen) continue;
        if (!(B00072230_c4[M00064d80_ay[k].type].f3a & 0x20)) continue;
        dx = B000755d0_ao - M00064d80_ay[k].b;
        dy = B000755d4_ak - M00064d80_ay[k].a;
        if (abs(dy) >= 0xa0000 || abs(dx) >= 0xa0000) continue;
        t = B00072230_c4[M00064d80_ay[k].type].hd;
        r = 12 - t + lvl;
        if (n || (t < 6 && left[t - 1])) {
            if (DAT_000567b2[r] < 0) {
                n--;
                FUN_0001e284(&M00064d80_ay[k], &B00072230_c4[M00064d80_ay[k].type], k, M00064d80_ay[k].hp, 0);
                if (DAT_000567b2[r] == -2) left[t - 1] = FUN_0002c328(2, 4, 0, 0);
            } else {
                if (B00072230_c4[M00064d80_ay[k].type].f31 & 4) roll -= 4;
                if (DAT_000567b2[r] <= roll) {
                    n--;
                    M00064d80_ay[k].fl |= 0x10;
                }
            }
        }
    }
}


#undef M00064d80_ay
#undef M000698e0_b7
#undef M000718e0_iO
#undef B00072230_c4
#undef FUN_0001e284
#undef EI
#undef EU
/* ---- from src/CODE2/f1b6f4.c */
/* FUN_0001b6f4 @ 0001b6f4: mark every visible entity whose kind has flag 0x20.
   Round 61 (blind rewrite): the entity record's +8..+0xb is one int flag word (the original writes +8 as a dword in FUN_0001e0f8 and
   FUN_000281b4 too); the word-sized OR constant is the conflict node the byte form (f9 |= 2) lacked. */
struct MF { int a, b; int fl; unsigned short s, type; short timer, hp; unsigned short w14; };
#define M00064d80_ay ((struct MF *)B00064d80_ay)
void FUN_0001b6f4(void)
{
    int i;
    for (i = 0; i < B00075618_b1.nent; i++)
        if (!(M00064d80_ay[i].fl & 0x2000000) && (((struct MTYPE *)B00072230_c4)[M00064d80_ay[i].type].f3a & 0x20))
            M00064d80_ay[i].fl |= 0x200;
}
#undef M00064d80_ay

/* ---- from src/CODE2/wip/f1b950.c */
/* Round 64 lane AM: MATCH in module context (realcc). */
/* NEAR MISS (round 23, module 0x186c4 -oa, 27 worklist lines) a. first difference: case 4, f13a = FUN_00029cc4() + FUN_00032e40(4, who) * 0x2a30: the multiply temp is edi in ours (orig edx, product into edi only at the end); the same at the next (x+0xa)*7 product; decision: registers of the expanded multiply whose result lives across the call (allocation), not structural; no compile spent. Earlier: 3466/3463 under -3s -ox -oe -ot (module 0x1b950 is this function alone; -ol puts who/r in the original ebx/esi, -oimert swapped them in every case: flags.csv now has the plain module set of the 0x1c6e0 neighbour), SHAPE 110, 271 byte lines (was 3472/3463, 484 lines). Structural round 2026-11-10: (1) case 0x4 adds 0x34 to B000758d4_jG (global first, like every other case) - fixed; (2) case 0x5c had the t == -1 test reversed, so it got its own cmp eax,eax failure stub; in the original it jumps to the stub shared with 0x1a/0x19/0x29 - fixed (same form as the others). Left (allocation): case 0x1 temp in ebx there, edi here; case 0x1a spills the FUN_00032e40 result to the frame slot there, keeps it in ebx here; case 0x4 multiply by 0x2a30 uses edi as the scratch there (4 bytes longer); MASK's imul writes eax there, edx here (MASK written as kind * 0x45 + base and as a struct KT array: no change). */
extern void FUN_00018a80(int t, int dir, int who, union FX x, union FX y); /* module prototype */
extern int FUN_00019418(int mode); /* module prototype */
extern int FUN_000195c0(void); /* module prototype */
extern int FUN_00019790(int it, int i, int snd, int bit, int k, int a, int b); /* module prototype */
extern void FUN_00019b4c(int who, int fx, int all); /* module prototype */
extern int FUN_0001a254(int eff, int spell, int a, int dur, int snd, int lvl, int flag, int mul); /* module prototype */
extern void FUN_0001a668(int i); /* module prototype */
extern void FUN_0001a794(int i); /* module prototype */
extern int FUN_0001a8a0(int i); /* module prototype */
extern int FUN_0001aa30(int i); /* module prototype */
extern void FUN_0001abc4(int i); /* module prototype */
extern void FUN_0001ac2c(int i); /* module prototype */
extern void FUN_0001ad24(int who); /* module prototype */
extern void FUN_0001ae30(void); /* module prototype */
extern void FUN_0001aed8(int who); /* module prototype */
extern void FUN_0001b02c(int a0, int a1, int range, int dmg, int mask, int mark, int kind, int snd, int px, int py); /* module prototype */
extern void FUN_0001b410(int i); /* module prototype */
extern void FUN_0001b518(int i, int evil); /* module prototype */
/* earlier note (under -oimert): 3466/3463, normalised sdiff 25: spell effect switch. Failure path of the target-picking cases needs the odd else { if (t == -1) r = -1; else r = 0; } (reproduces the original cmp eax,eax stub). Left: (1) the original keeps who live in ebx to the end of the function (returning r + who reproduces cases 0x1 and 0x1a exactly, i.e. some use of who after the switch is missing); (2) case 0x4 multiply-by-0x2a30 register choice (+4 bytes). */
/* Round 52 (7 compiles): the +14 is the three FUN_00032e40(..) * 0x2a30 sites: the multiply-by-constant expansion copies the call result into EDI here (mov edi,eax ... lea eax,[eax*4]; sub eax,edi; mov edi,eax) where the original copies it into EDX and builds the product in EDI (lea edi,[eax*4]; sub edi,eax); constant first, the product held in t, either site alone: code identical. Allocation of the expansion temps, not reached. */
extern int B000755d0_ao, B000755d4_ak, DAT_0005c658, B000758d4_jG, DAT_0005f91c, DAT_0005fd08, B00062ba0_hT, B00062ba4_hh;
extern unsigned char DAT_0005bf38, DAT_0005cf5a, DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682; extern short DAT_0005f03c, DAT_00056dae; /* STANDIN: scalar declaration of DAT_0005cf5a, see the first one (module head) */
extern void FUN_00029ccc(int), FUN_00029cf4(void), FUN_0001e578(int);
extern void FUN_00041f38(int), FUN_0002f494(int), FUN_0001f238(int, int, int);
extern void FUN_0002c77c(int, int);
#include "dice.h"
#define B00072230_c4 ((char *)B00072230_c4)
#define FUN_00018a80 ((void (*)(int, int, int, int, int))FUN_00018a80)
#define FUN_00038110 ((void (*)(int, int, int, int))FUN_00038110)
extern int FUN_00032e40(int, int), FUN_00029cc4(void);
#undef M00064d80_ay
#undef M000718e0_iO
#undef B00072230_c4
#undef MASK
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
#define M00064d80_ay ((struct MF *)B00064d80_ay)
#define MTF(t, o) (*(int *)(B00072230_c4 + M00064d80_ay[t].type * 0x45 + (o)))
#define PF ((unsigned char *)DAT_0005d684 - 0x72a) /* STANDIN: the portrait flags DAT_0005cf5a[] addressed through the neighbouring array DAT_0005d684, so that this function takes no address of DAT_0005cf5a: the scalar store of the inlined FUN_0001a60c keeps its -oa memory node (pass-1 list as with the old alias) */
/* FUN_0001b950 @ 0001b950: cast spell sp for character who */
int FUN_0001b950(unsigned sp, int who)
{
    int r, d, t, k;
    r = 1;
    FUN_00029ccc(0);
    DAT_0005bf38 = 0;
    switch (sp) {
    case 1:
        FUN_0001e578(who);
        FUN_0001b02c(-0x3c, 0x3c, 7, 2 * (d = FUN_00032e40(4, who)) + FUN_0002c328(1, 3, 0, 0), 0x2100, 1, 8, 7, B000755d0_ao, B000755d4_ak); /* STANDIN: level named in the argument (adds a conflict node in case 1: the 0x2a30 / 0x45 / 0x248 temp ties) */
        break;
    case 10:
        d = FUN_00019418(1);
        FUN_0001e578(who);
        FUN_0001b02c(d - DAT_0005c658, d - DAT_0005c658, 0x14, FUN_0002c328(3, 6, 0, 0), 0x2100, 0, 8, 0, B000755d0_ao, B000755d4_ak);
        break;
    case 0x7a:
        t = FUN_000195c0();
        if (t != -1) FUN_0001b410(t);
        else r = 0;
        break;
    case 0x35:
        d = FUN_00019418(1);
        FUN_0001e578(who);
        FUN_0001b02c(d - DAT_0005c658, d - DAT_0005c658, 0x14, FUN_0002c328(3, 6, 0, 0), 0x900, 0, 9, 0x3d, B000755d0_ao, B000755d4_ak);
        break;
    case 0x1f:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_0001e578(who);
            FUN_0001b02c(-0xb4, 0xb4, 7, FUN_0002c328(3, 0xa, 0, 0), 0x900, 1, 9, 0x2c, M00064d80_ay[t].b, M00064d80_ay[t].a);
        } else r = 0;
        break;
    case 0:
        r = FUN_0001a254(1, 0, 0, 0, 3, who, 0, 0x438);
        break;
    case 4:
        M000718e0_iO[who].f132 |= 2;
        t = FUN_00032e40(4, who);
        t *= 0x2a30;
        d = t; /* STANDIN: the product copied to a local for the sum (sum in a fresh register, lea edx,[eax+edi]) */
        M000718e0_iO[who].t[1] = FUN_00029cc4() + d;
        PF[who] = 1; /* STANDIN: PF view */
        FUN_00038110(B000758d4_jG + 0x34, 0xff, 0, 1);
        FUN_00041f38(DAT_0005f91c);
        break;
    case 0x55:
        M000718e0_iO[who].f132 |= 0x400;
        t = FUN_00032e40(3, who) + 10;
        t *= 0x2a30;
        M000718e0_iO[who].t[10] = t + FUN_00029cc4();
        PF[who] = 1; /* STANDIN: PF view */
        FUN_00038110(B000758d4_jG + 0x35, 0xff, 0, 1);
        FUN_00041f38(DAT_0005f91c);
        break;
    case 3:
        M000718e0_iO[who].f132 |= 0x40000;
        M000718e0_iO[who].t[18] = FUN_00029cc4() + 0x438;
        DAT_0005f03c++;
        PF[who] = 1; /* STANDIN: PF view */
        FUN_00038110(B000758d4_jG + 0x14, 0xff, 0, 1);
        break;
    case 0x70:
        M000718e0_iO[who].f132 |= 0x8000;
        PF[who] = 1; /* STANDIN: PF view */
        FUN_00038110(B000758d4_jG + 0x22, 0xff, 0, 1);
        break;
    case 6:
        r = FUN_0001a254(4, 2, 0, FUN_00032e40(4, who) * 5, 0x42, who, 0, 0x438);
        break;
    case 0xb:
        r = FUN_0001a254(8, 3, 1, FUN_00032e40(4, who) + 3, 6, who, 0, 0x438);
        break;
    case 0x17:
        r = FUN_0001a254(0x10, 4, 1, FUN_00032e40(4, who) + 3, 0x25, who, 0, 0x438);
        break;
    case 0x37:
        r = FUN_0001a254(0x80, 7, 0, FUN_00032e40(4, who) * 10, 0x18, who, 0, 0x2a30);
        break;
    case 0x20:
        r = FUN_0001a254(0x40, 6, 0, 0, 0x45, who, 0, 0x438);
        break;
    case 0x50:
        r = FUN_0001a254(0x100, 8, 2, 6, 5, who, 0, 0x438);
        break;
    case 0x54:
        r = FUN_0001a254(0x200, 9, 1, 6, 0x30, who, 0, 0x438);
        break;
    case 0x1b:
        FUN_0001a794(who);
        break;
    case 0x5d:
        r = FUN_0001a254(0x10000, 0x10, 4, FUN_00032e40(3, who), 0x44, who, 0, 0x438);
        break;
    case 0x5a:
        r = FUN_0001a254(0x800, 0xb, 3, FUN_00032e40(3, who) + 1, 2, who, 0, 0x438);
        break;
    case 0xc:
        FUN_00038110(B000758d4_jG + 0x2d, 0xff, 0, 1);
        PF[0] = 1; /* STANDIN: PF view */
        PF[1] = 1; /* STANDIN: PF view */
        PF[2] = 1; /* STANDIN: PF view */
        PF[3] = 1; /* STANDIN: PF view */
        B00062ba0_hT = DAT_0005d681;
        B00062ba4_hh = DAT_0005d682;
        DAT_0005d681 = DAT_0005d682 = 0;
        FUN_0002f494(1);
        FUN_00019b4c(who, 5, 0);
        FUN_0001a60c();
        for (k = 0; k < 0x15; k++) FUN_0001f238(who, k, 1);
        PF[who] = 1; /* STANDIN: PF view */
        r = 1;
        break;
    case 0x51:
        r = FUN_0001a254(-1, 0x51, 3, -1, 0x10, who, 1, 0);
        break;
    case 0x6e:
        r = FUN_0001a254(-1, 0x6e, 3, -1, 0x11, who, 1, 0);
        break;
    case 0x78:
        r = FUN_0001a254(-1, 0x78, 3, -1, 0xe, who, 1, 0);
        break;
    case 0x64:
        r = FUN_0001a254(-1, 0x64, 4, -1, 0xf, who, 1, 0);
        break;
    case 0x71:
        r = FUN_0001a254(-1, 0x71, 4, -1, 0x3c, who, 1, 0);
        break;
    case 0x68:
        r = FUN_0001a254(-1, 0x68, 4, -1, 0x41, who, 1, 0);
        break;
    case 0x82:
        r = FUN_0001a254(-1, 0x82, 3, -1, 0x26, who, 1, 0);
        break;
    case 2:
        r = FUN_00019790(0x7e, who, 0xa, 1, 0, FUN_00032e40(4, who) + 3, 0x438);
        break;
    case 0x1d:
        r = FUN_00019790(0x7f, who, 0x47, 2, 1, 1, 0x2a30);
        break;
    case 0x32:
        r = FUN_00019790(0x80, who, 0xb, 4, 2, FUN_00032e40(4, who), 0x438);
        break;
    case 0x52:
        r = FUN_00019790(0x81, who, -1, -1, -1, -1, -1);
        break;
    case 0x6f:
        r = FUN_00019790(0x82, who, 8, -1, -1, -1, -1);
        break;
    case 0x79:
        r = FUN_00019790(0x83, who, 8, -1, -1, -1, -1);
        break;
    case 0x83:
        r = FUN_00019790(0x84, who, 0x23, -1, -1, -1, -1);
        break;
    case 0x5b:
        r = FUN_00019790(0x85, who, 0x1f, 0x80, 7, FUN_00032e40(3, who) / 2 + 4, 0x438);
        break;
    case 0x34:
        r = FUN_00019790(0x86, who, 0x33, 0x100, 8, FUN_00032e40(4, who), 0x438);
        break;
    case 0x18:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_00038110(B000758d4_jG + 0x43, 0xff, 0, 1);
            if (!(MTF(t, 0x32) & 1)) M00064d80_ay[t].fl |= 0x80;
        } else {
            if (t == -1) r = -1; else r = 0; /* STANDIN: a second test of t on the shared t == -1 path - the dead cmp eax,eax / jne the original keeps there */
        }
        break;
    case 0x1a:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_00038110(B000758d4_jG + 0x2a, 0xff, 0, 1);
            if (!(MTF(t, 0x31) & 0x102)) {
                M00064d80_ay[t].fl |= 8;
                M00064d80_ay[t].timer = (FUN_00032e40(4, who) + FUN_0002c328(1, 4, 0, 0)) * 0x438;
            }
        } else {
            if (t == -1) r = -1; else r = 0; /* STANDIN: a second test of t on the shared t == -1 path - the dead cmp eax,eax / jne the original keeps there */
        }
        break;
    case 0x19:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_00038110(B000758d4_jG + 0x27, 0xff, 0, 1);
            if (!(MTF(t, 0x31) & 0x108)) {
                M00064d80_ay[t].fl |= 8;
                M00064d80_ay[t].timer = FUN_00032e40(4, who) * 0x870;
            }
        } else {
            if (t == -1) r = -1; else r = 0; /* STANDIN: a second test of t on the shared t == -1 path - the dead cmp eax,eax / jne the original keeps there */
        }
        break;
    case 0x5c:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_00038110(B000758d4_jG + 0x28, 0xff, 0, 1);
            if (!(MTF(t, 0x31) & 0x108)) {
                M00064d80_ay[t].fl |= 8;
                M00064d80_ay[t].timer = FUN_00032e40(3, who) * 0x870;
            }
        } else {
            if (t == -1) r = -1; else r = 0; /* STANDIN: a second test of t on the shared t == -1 path - the dead cmp eax,eax / jne the original keeps there */
        }
        break;
    case 0x29:
        t = FUN_000195c0();
        if (t != -1) {
            FUN_00038110(B000758d4_jG + 0x29, 0xff, 0, 1);
            if (!(MTF(t, 0x31) & 0x110)) {
                M00064d80_ay[t].fl |= 8;
                M00064d80_ay[t].timer = FUN_00032e40(4, who) * 0x438;
            }
        } else {
            if (t == -1) r = -1; else r = 0; /* STANDIN: a second test of t on the shared t == -1 path - the dead cmp eax,eax / jne the original keeps there */
        }
        break;
    case 0x67:
        FUN_0001a668(who);
        PF[who] = 1; /* STANDIN: PF view */
        break;
    case 0x1c:
        d = FUN_00019418(1);
        FUN_00018a80(1, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0x15:
        d = FUN_00019418(1);
        FUN_00018a80(0, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0xf:
        d = FUN_00019418(1);
        FUN_00018a80(2, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0x28:
        d = FUN_00019418(1);
        FUN_00018a80(3, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0x16:
        d = FUN_00019418(1);
        FUN_00018a80(4, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0x56:
        r = FUN_00019790(0xa5, who, 0x38, -1, -1, -1, -1);
        break;
    case 5:
        d = FUN_00019418(1);
        FUN_00018a80(6, d, who, B000755d4_ak, B000755d0_ao);
        break;
    case 0x66:
        FUN_00038110(B000758d4_jG + 0x3b, 0xff, 0, 1);
        r = FUN_0001a254(0x4000, 0xe, 2, 0, 0x42, who, 0, 0);
        break;
    case 0x7b:
        FUN_00038110(B000758d4_jG + 0x3f, 0xff, 0, 1);
        r = FUN_0001a254(0x7b, 0x7b, 1, 0, 0x42, who, 1, 0);
        break;
    case 0xe:
        FUN_0001abc4(FUN_00019418(0));
        break;
    case 0xd:
        FUN_0001ac2c(FUN_00019418(0));
        break;
    case 0x14:
        FUN_00038110(B000758d4_jG + 0x16, 0xff, 0, 1);
        FUN_0001ad24(-1);
        break;
    case 0x65:
        t = B000758d4_jG; /* STANDIN: sound number built in a local */
        t += 0x17; /* STANDIN: (with the line above) lifts the sum temp's savings; flips the case-0x18 type*0x45 / base tie */
        FUN_00038110(t, 0xff, 0, 1);
        FUN_0001ad24(-1);
        break;
    case 0x57:
        r = FUN_0001a254(-1, 0x57, 3, -1, 0x10, who, 1, 0);
        break;
    case 0x36:
        if (!(M000718e0_iO[who].f132 & 0x20000)) DAT_0005fd08++;
        FUN_00038110(B000758d4_jG + 0x46, 0xff, 0, 1);
        M000718e0_iO[who].f132 |= 0x20000;
        t = FUN_00032e40(3, who) * 0x438;
        M000718e0_iO[who].t[17] = FUN_00029cc4() + t;
        PF[who] = 1; /* STANDIN: PF view */
        break;
    case 0x21:
        FUN_0001ae30();
        break;
    case 0x33:
        FUN_0001aed8(who);
        break;
    case 0x1e:
        FUN_00038110(B000758d4_jG + 0x15, 0xff, 0, 1);
        FUN_0002c77c(who, 0x31d);
        break;
    case 0x53:
        if (!(M000718e0_iO[who].f132 & 0x100000)) DAT_00056dae++;
        FUN_00038110(B000758d4_jG + 0x13, 0xff, 0, 1);
        M000718e0_iO[who].f132 |= 0x100000;
        M000718e0_iO[who].t[20] = FUN_00029cc4() + 0x2a30;
        PF[0] = 1; /* STANDIN: PF view */
        PF[1] = 1; /* STANDIN: PF view */
        PF[2] = 1; /* STANDIN: PF view */
        PF[3] = 1; /* STANDIN: PF view */
        break;
    case 0x58:
        if (M000718e0_iO[who].cls[0] == 1) FUN_0001b518(who, 1);
        else FUN_0001b518(who, 0);
        r = -2;
        break;
    case 0x5e:
        r = FUN_0001a8a0(who);
        break;
    case 0x5f:
        r = FUN_0001aa30(who);
        break;
    }
    FUN_00029cf4();
    DAT_0005bf38 = 1;
    return r;
}

#undef PF
#undef MTF
#undef M00064d80_ay
#undef M00064d80_ay
#undef M000718e0_iO
#undef B00072230_c4
#undef FUN_00018a80
#undef FUN_00038110
#undef MTF

/* ---- module data _DATA 0005669c-000567dc (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
char *DAT_0005669c = "%s's ";
char *DAT_000566a0 = " wears off.";
char *PTR_s_error_unloading_spell__000566a4 = "error unloading spell.";
char *PTR_s_where_do_you_wish_to_cast_000566a8 = "where do you wish to cast the spell?";
char *PTR_s_no_visible_creatures_upo_000566ac = "no visible creatures upon which to cast this spell.";
char *PTR_s_upon_which_creature_is_t_000566b0 = "upon which creature is the spell to be cast? (esc aborts)";
char *PTR_s__s_is_resurrected__000566b4 = "%s is resurrected.";
char *PTR_s__s_cannot_be_resurrected__000566b8 = "%s cannot be resurrected.";
char *PTR_s_you_cannot_resurrect_an_elf__000566bc = "you cannot resurrect an elf.";
char *PTR_s_cast_spell_on_which_character_000566c0 = "cast spell on which character?";
char *PTR_s__s_is_still_alive__000566c4 = "%s is still alive.";
unsigned char DAT_000566c8[36] = { 1, 6, 0, 1, 1, 6, 0, 1, 2, 4, 0, 0, 1, 4, 1, 1, 4, 6, 0, 0, 1, 4, 0, 1, 1, 4, 0, 1, 1, 4, 0, 1, 1, 2 };
struct T13_FX DAT_000566ec[6] = {
    0x42, 0x138, 4, 0xf, 0, 1, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 1, 5, 0, 0, 0, 0, 0,
    0x43, 0x138, 4, 0x11, 0, 1, 2, 3, 2, 4, 2, 3, 2, 4, 2, 3, 2, 4, 2, 1, 0, 0, 0, 0,
    0x44, 0x138, 4, 0x11, 0, 1, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 1, 0, 0, 0, 0,
    0x45, 0x138, 4, 0x11, 0, 1, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 1, 0, 0, 0, 0,
    0x46, 0x138, 4, 0x11, 0, 1, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 1, 0, 0, 0, 0,
    0x47, 0x114, 4, 8, 0, 1, 2, 3, 4, 5, 6, 7
};
signed char DAT_000567b2[24] = {
    0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x14, 0x13, 0x10, 0xd, 10, 7, 4, 0,
    0, -1, -1, -2, -2, -2, -2, -2
};
short DAT_000567ca[9] = { 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86 };
/* ---- end of module data _DATA */
