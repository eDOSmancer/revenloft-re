/* Module: FUN_000270ac, FUN_000271d0, FUN_000271fc, FUN_00027838, FUN_00027a68, FUN_000281b4 */
/* names inside DAT_0005819c (tools/dataview.py): views of the object the module defines */
#define DAT_000581a4 (*(char *)((char *)DAT_0005819c + 0x8))
#define DAT_000581a5 (*(char *)((char *)DAT_0005819c + 0x9))
#define DAT_000581a6 (*(char *)((char *)DAT_0005819c + 0xa))
/* ---- from build/var/mod/parts/p270ac.c */
/* FUN_000270ac @ 000270ac: fill the neighbour-offset tables for the current map width */
#include "world.h"
extern short B00077108_dk[8], B00077128_fk[16];
void FUN_000270ac(void)
{
    int w, w2;
    w = B00075618_b1.w;
    w2 = w * 2;
    B00077108_dk[0] = -1;
    B00077108_dk[1] = 1;
    B00077108_dk[2] = -w;
    B00077108_dk[3] = w;
    B00077108_dk[4] = w - 1;
    B00077108_dk[5] = w + 1;
    B00077108_dk[6] = -1 - w;
    B00077108_dk[7] = 1 - w;
    B00077128_fk[0] = -2;
    B00077128_fk[1] = 2;
    B00077128_fk[2] = -w2;
    B00077128_fk[3] = w2;
    B00077128_fk[4] = w2 - 2;
    B00077128_fk[5] = w2 + 2;
    B00077128_fk[6] = -2 - w2;
    B00077128_fk[7] = 2 - w2;
    B00077128_fk[8] = -1 - w2;
    B00077128_fk[9] = 1 - w2;
    B00077128_fk[10] = w2 - 1;
    B00077128_fk[11] = w2 + 1;
    B00077128_fk[12] = w - 2;
    B00077128_fk[13] = w + 2;
    B00077128_fk[14] = -2 - w;
    B00077128_fk[15] = 2 - w;
}

/* ---- from build/var/mod/parts/p271d0.c */
/* FUN_000271d0 (write len bytes or report the error) and FUN_000271fc: save the current level state to work\levNNN.dat: header, map rows, the two per-column object lists, monsters, items, doors, event table, map size, automap and the variable block, then the section offset table at offset 1 */
#include "world.h"
extern void FUN_00041380(char *), FUN_000412dc(int), FUN_0003f580(char *), FUN_00011558(void);
extern int FUN_000412c8(char *), FUN_000412b4(char *), FUN_0004131c(int, int, int), FUN_00041304(void *, unsigned, int), FUN_00011c28(void);
extern unsigned char DAT_0005a79d, DAT_0005cf50, DAT_00051760[], DAT_00055760[];
extern char DAT_0005819c[], *DAT_00058190, *DAT_00058194;


extern unsigned short B000698e0_b7[];
extern unsigned char *DAT_0005cb3c[], *DAT_0005cd3c[];
extern char B00064d80_ay[], B00072238_dL[2], B00067618_e7[], *DAT_0005cf44;
void FUN_000271d0(void *p, int len, int fd)
{
    if (FUN_00041304(p, len, fd) != len) FUN_0003f580(DAT_00058190);
}

extern void FUN_00041380(char *), FUN_000412dc(int), FUN_0003f580(char *), FUN_00011558(void);
extern int FUN_000412c8(char *), FUN_000412b4(char *), FUN_0004131c(int, int, int), FUN_00041304(void *, unsigned, int), FUN_00011c28(void);
extern unsigned char DAT_0005a79d, DAT_0005cf50, DAT_00051760[], DAT_00055760[];
extern char DAT_0005819c[], *DAT_00058190, *DAT_00058194;
extern unsigned short B000698e0_b7[];
extern unsigned char *DAT_0005cb3c[], *DAT_0005cd3c[];
extern char B00064d80_ay[], B00072238_dL[2], B00067618_e7[], *DAT_0005cf44;

void FUN_000271fc(int lvl)
{
    int fd, c, n, o0, o1, o2, o3, o4, o5, o6;
    if (lvl == -1 || DAT_0005a79d) return;
    DAT_000581a4 = lvl / 100 + '0';
    DAT_000581a6 = lvl % 10 + '0';
    DAT_000581a5 = (lvl - lvl / 100 * 100) / 10 + '0';
    FUN_00041380(DAT_0005819c);
    FUN_000412dc(FUN_000412c8(DAT_0005819c));
    fd = FUN_000412b4(DAT_0005819c);
    if (fd == -1) FUN_0003f580(DAT_00058194);
    o0 = 0x1d;
    FUN_0004131c(0x1d, 0, fd);
    FUN_000271d0(((char *)&B00075618_b1), 0x2a4, fd);
    o1 = o0 + 0x2a4;
    for (n = 0; n < B00075618_b1.h; n++) {
        FUN_000271d0(&B000698e0_b7[B00075618_b1.w * n], B00075618_b1.w * sizeof(short), fd);
        o1 += B00075618_b1.w * 2;
    }
    o2 = o1;
    for (c = 0; c < B00075618_b1.w; c++) {
        if (DAT_0005cb3c[c]) {
            n = 0;
            while (DAT_0005cb3c[c][n * 10] || *(int *)&DAT_0005cb3c[c][n * 10 + 1] & 0x10) n++;
            FUN_000271d0(&n, 2, fd);
            o2 += 2;
            if (n) {
                FUN_000271d0(DAT_0005cb3c[c], n * 10, fd);
                o2 += n * 10;
            }
        } else {
            n = 0;
            FUN_000271d0(&n, 2, fd);
            o2 += 2;
        }
    }
    FUN_000271d0(&DAT_0005cf50, 1, fd);
    o2++;
    for (c = 0; c < B00075618_b1.w; c++) {
        if (DAT_0005cd3c[c]) {
            n = 0;
            while (DAT_0005cd3c[c][n * 10]) n++;
            FUN_000271d0(&n, 2, fd);
            o2 += 2;
            if (n) {
                FUN_000271d0(DAT_0005cd3c[c], n * 10, fd);
                o2 += n * 10;
            }
        } else {
            n = 0;
            FUN_000271d0(&n, 2, fd);
            o2 += 2;
        }
    }
    FUN_000271d0(B00064d80_ay, B00075618_b1.nent * 0x16, fd);
    o3 = o2 + B00075618_b1.nent * 0x16;
    FUN_000271d0(&B00075618_b1.ndoor, 2, fd);
    FUN_000271d0(B00072238_dL, B00075618_b1.ndoor * 0x16, fd);
    o4 = o3 + B00075618_b1.ndoor * 0x16 + 2;
    FUN_000271d0(B00067618_e7, B00075618_b1.n4 * 0x16, fd);
    o5 = o4 + B00075618_b1.n4 * 0x16;
    FUN_000271d0(DAT_0005cf44, 0x514, fd);
    o6 = o5 + 0x514;
    FUN_000271d0(&B00075618_b1.w, 2, fd);
    FUN_000271d0(&B00075618_b1.h, 2, fd);
    FUN_00011558();
    FUN_000271d0(DAT_00051760, B00075618_b1.w * B00075618_b1.h, fd);
    n = FUN_00011c28();
    FUN_000271d0(&n, 4, fd);
    FUN_000271d0(DAT_00055760, n, fd);
    FUN_0004131c(1, 0, fd);
    FUN_000271d0(&o0, 4, fd);
    FUN_000271d0(&o1, 4, fd);
    FUN_000271d0(&o2, 4, fd);
    FUN_000271d0(&o3, 4, fd);
    FUN_000271d0(&o4, 4, fd);
    FUN_000271d0(&o5, 4, fd);
    FUN_000271d0(&o6, 4, fd);
    FUN_000412dc(fd);
}

/* ---- from build/var/mod/parts/p27838.c */
/* FUN_00027838 @ 00027838: per-day check: a party member who slept badly may fall ill unless the area is safe (branch 1: "{ r = 0; goto roll; }" keeps the original je continue; jmp roll, a bare goto would be folded into the test) */
/* FUN_00027838 @ 00027838: per-day check: a party member who slept badly may fall ill unless the area is safe */
int rand(void);
extern int FUN_0002c1dc(int); extern void FUN_0002c77c(int, int);
extern unsigned char B000718e0_iO[];
#define B000718f0_hO (*(unsigned short *)((char *)&B000718e0_iO + 16)) /* STANDIN: view, B000718e0_iO + 0x10 */
 extern int DAT_0005c6c8, DAT_0005bf2c;
#define CH16(o) (*(unsigned short *)((char *)&B000718f0_hO + (o)))
void FUN_00027838(void)
{
    int k, off, r;
    for (k = 0, off = 0; k < 4; k++, off += 0x248) {
        if (!(CH16(off) & 0x8000) && (CH16(off) & 0x100)) {
            CH16(off) &= 0xffbf;
            if (FUN_0002c1dc(0x37)) {
                if (DAT_0005c6c8 != 0x15 && DAT_0005c6c8 != 0x14 && DAT_0005c6c8 != 10 && DAT_0005c6c8 != 0xb && DAT_0005c6c8 != 6 && DAT_0005c6c8 != 7 && DAT_0005c6c8 != 0x12 && DAT_0005c6c8 != 8 && DAT_0005c6c8 != 0xf) { r = 0; goto roll; }
            } else {
                if (DAT_0005c6c8 != 0x15 && DAT_0005c6c8 != 0x14 && DAT_0005c6c8 != 10 && DAT_0005c6c8 != 0xb && DAT_0005c6c8 != 0xc && DAT_0005c6c8 != 0x18 && DAT_0005c6c8 != 5 && DAT_0005c6c8 != 0x12 && DAT_0005c6c8 != 8 && DAT_0005c6c8 != 0xf) goto roll;
            }
            continue;
        roll:
            r = (unsigned)(rand() * 4) >> 15;
            DAT_0005bf2c = r + 0x32;
            FUN_0002c77c(k, r + 0x15f);
            CH16(off) |= 0x40;
        }
    }
}

#undef CH16
/* ---- from build/var/mod/parts/p27a68.c */
extern void FUN_00027838(void); /* module prototype */
/* FUN_00027a68 @ 00027a68: daily update, then decide for every monster whether it is hidden today (time of day, area, quest flags) */
#include "world.h"
#define M00064d80_ay ((struct O *)B00064d80_ay)
struct O { int a; int d4; int d8; unsigned short s, type; short timer, w12; unsigned short st; };
  extern unsigned DAT_0005cf4c; extern int DAT_0005c6c8; extern unsigned char *B00072230_c4;
 extern int FUN_0003acdc(int), FUN_0002c1dc(int), FUN_0002c328(int, int, int, int);
#pragma aux FUN_0002c328 modify [ebx ecx edx];
void FUN_00027a68(void)
{
    int i, hide, h;
    FUN_00027838();
    for (i = 0; i < B00075618_b1.nent; i++) {
        hide = 0;
        ((unsigned char *)&M00064d80_ay[i])[0xb] &= ~2;
        if (FUN_0003acdc(M00064d80_ay[i].type) && M00064d80_ay[i].w12 <= 0) hide = 1;
        h = DAT_0005cf4c >> 16;
        switch (M00064d80_ay[i].type) {
        case 0: if ((DAT_0005c6c8 == 0x12 || DAT_0005c6c8 == 0x1f) && h > 4 && h < 0x15) hide = 1; break;
        case 6: if ((DAT_0005c6c8 == 0x19 || DAT_0005c6c8 == 0x1a) && h > 4 && h < 0x15) hide = 1; break;
        case 0x11: if (DAT_0005c6c8 == 0x12 && h > 4 && h < 0x15) hide = 1; break;
        case 0x15: case 0x50: if (DAT_0005c6c8 == 0x18 && h > 4 && h < 0x15) hide = 1; break;
        case 0x18: case 0x1a: if (DAT_0005c6c8 == 0xb && h > 4 && h < 0x15) hide = 1; break;
        case 8: if (!FUN_0002c1dc(0x3a)) hide = 1; break;
        case 0xf: if (FUN_0002c1dc(0x28) && FUN_0002c1dc(0x29)) hide = 1; break;
        default:
            switch ((int)M00064d80_ay[i].type) {
            case 0x22: if (FUN_0002c1dc(0x1d) == 1) hide = 1; break;
            case 0x24: if (FUN_0002c1dc(0x1e) == 1) hide = 1; break;
            case 0x26: if (FUN_0002c1dc(0x8) == 1 || FUN_0002c1dc(0x13) == 1) hide = 1; break;
            case 0x27: if (FUN_0002c1dc(0xe) == 1 || FUN_0002c1dc(0xd) == 1 || FUN_0002c1dc(0x18) == 1) hide = 1; break;
            case 0x28: if (!FUN_0002c1dc(0xe) || FUN_0002c1dc(0xd) == 1 || FUN_0002c1dc(0x18) == 1) hide = 1; break;
            case 0x29: if (FUN_0002c1dc(0x2c) == 1) hide = 1; break;
            case 0x2c: if (FUN_0002c1dc(0x6) == 1 || FUN_0002c1dc(0x11) == 1 || !FUN_0002c1dc(0x30)) hide = 1; break;
            case 0x2d: if (FUN_0002c1dc(0x4) == 1 || FUN_0002c1dc(0xf) == 1 || FUN_0002c1dc(0x19) == 1) hide = 1; break;
            case 0x2e: if (FUN_0002c1dc(0x7) == 1 || FUN_0002c1dc(0x12) == 1 || FUN_0002c1dc(0x1b) == 1) hide = 1; break;
            case 0x2f: if (FUN_0002c1dc(0x7) == 1 || FUN_0002c1dc(0x12) == 1 || !FUN_0002c1dc(0x1b)) hide = 1; break;
            case 0x30: if (FUN_0002c1dc(0x9) == 1 || FUN_0002c1dc(0x45) == 1 || FUN_0002c1dc(0x14) == 1) hide = 1; break;
            case 0x31: if (FUN_0002c1dc(0xa) == 1 || FUN_0002c1dc(0x15) == 1 || FUN_0002c1dc(0x23) == 1) hide = 1; break;
            case 0x33: if (FUN_0002c1dc(0x2d) == 1) hide = 1; break;
            case 0x34: if (FUN_0002c1dc(0x2f) == 1) hide = 1; break;
            case 0x35: if (FUN_0002c1dc(0x2e) == 1) hide = 1; break;
            case 0x36: if (FUN_0002c1dc(0x2f) == 1 || !FUN_0002c1dc(0x39)) hide = 1; break;
            case 0x37: if (FUN_0002c1dc(0x27) == 1) hide = 1; break;
            case 0x39: if (FUN_0002c1dc(0x2c) == 1) hide = 1; break;
            case 0x2a: case 0x3a: if (!FUN_0002c1dc(0x2c)) hide = 1; break;
            case 0x3d: if (FUN_0002c1dc(0xc) == 1 || FUN_0002c1dc(0x17) == 1) hide = 1; break;
            case 0x3f: if (FUN_0002c1dc(0x5) == 1 || FUN_0002c1dc(0x10) == 1 || FUN_0002c1dc(0x1c) == 1) hide = 1; break;
            case 0x40: if (FUN_0002c1dc(0xb) == 1 || FUN_0002c1dc(0x16) == 1) hide = 1; break;
            case 0x42: if (!FUN_0002c1dc(0x1e)) hide = 1; break;
            case 0x43: if (FUN_0002c1dc(0x4) == 1 || FUN_0002c1dc(0xf) == 1 || !FUN_0002c1dc(0x19)) hide = 1; break;
            case 0x44: if (FUN_0002c1dc(0xa) == 1 || FUN_0002c1dc(0x15) == 1 || !FUN_0002c1dc(0x23)) hide = 1; break;
            case 0x45: if (FUN_0002c1dc(0x5) == 1 || FUN_0002c1dc(0x10) == 1 || !FUN_0002c1dc(0x1c)) hide = 1; break;
            case 0x46: if (!FUN_0002c1dc(0x1d)) hide = 1; break;
            case 0x47: if (FUN_0002c1dc(0x2f) == 1 || !FUN_0002c1dc(0x39)) hide = 1; break;
            case 0x4e:
                if (FUN_0002c1dc(0x25)) {
                    M00064d80_ay[i].type = 1;
                    M00064d80_ay[i].d8 = 0x10000000;
                    M00064d80_ay[i].w12 = FUN_0002c328(B00072230_c4[M00064d80_ay[i].type * 0x45 + 0x1d], 8, 0, 0);
                }
                break;
            case 0x52: if (FUN_0002c1dc(0x14) == 1 || FUN_0002c1dc(0x9) == 1) hide = 1; break;
            }
            break;
        }
        if (hide) ((unsigned char *)&M00064d80_ay[i])[0xb] |= 2;
    }
}

#undef M00064d80_ay
/* ---- from build/var/mod/parts/p281b4.c */
extern void FUN_000270ac(void); /* module prototype */
extern void FUN_000271fc(int lvl); /* module prototype */
extern void FUN_00027a68(void); /* module prototype */
/* Round 42 (module 0x270ac, real 10.0a, about 900 compiles incl. climbs): matched in module context. (1) `rec` declared in the `if (from == 1)` block (49 -> 12 instruction lines: the frame slots); (2) the count loop indexes the temporary list (`(tmp + j * 10)[5]`, recipe 125: the stepped pointer is the compiler's, initialised after the zero-trip test); (3) `for (j = 0, o = 0; ...)` in both copy loops (j's zero store is scheduled ahead of the memset call); (4) `(0x80 - b2) * DAT_0005c02a` operand order (recipe 89); (5) the b4 compare value held in j, not t (one conflict node fewer: flips the p / j tie at savings 6522, tietrace class A); (6) declaration order from tools/declclimb.py. A hand-rotated count loop (`j = 0; if (j < cnt) { p = tmp; do ... }`) with t also matches; not kept (unnatural). */
/* NEAR MISS 3034/3032 under the module flags -ox -oe -ot (module 0x270ac; no -oa: the original reloads B00075618_b1.w, which is the non-oa behaviour). 2026-11-10 step 1: SHAPE 129/211 -> 24/84 by (1) the row size written `B00075618_b1.w * sizeof(short)` (unsigned multiply; gives the reload of B00075618_b1.w exactly) and (2) aggregates declared name, rec, it. Left: Q3 (allocation/slot order): the original frame has saved@0x38, tmp@0x34, old@0x30, fh@0x2c, k@0x28 = declaration order; ours old@0x38, saved@0x34, fh@0x30, tmp@0x2c = order of first use, so the slot sort input differs (c/temps.c AssignOtherLocals). Then the register rotation p/j/o in the two item-list loops (edi/ebx/ebp), likely the same allocation-order cause. In-context declaration climb (tools/modclimb.py, 87 compiles): 396 -> 389, no further. Q1 (clobbers): none (cdeclscan clean). Q2: no live-range difference found */
/* FUN_000281b4 @ 000281b4: enter level lvl: save the old one, open work\levNNN.dat (or levels.dat), read the map, the chest/item lists, entities, objects and floor items, then the triggers and the level text */
#include <string.h>
#include "world.h"
#define DAT_0005cf44 (*(unsigned char **)&DAT_0005cf44)
#define M00064d80_ay ((struct ENT *)B00064d80_ay)
#define M00067618_e7 ((struct ENT *)B00067618_e7)
#define M000698e0_b7 ((short *)B000698e0_b7)
#define B00072230_c4 (*(char **)&B00072230_c4)
#define M00072238_dL ((struct ENT *)B00072238_dL)
#pragma pack(1)
struct REC { short kind, a, b, c, d; unsigned char dir; };
#pragma pack()
struct ENT { short d, c, b, a; int f8; short cell, kind, w10, hp; unsigned short a1 : 1, b2 : 2, dir : 3, c3 : 3, d5 : 5, mode : 2; };
extern int DAT_0005c6c8, DAT_0005bf44, DAT_0005f9cc, DAT_0005c038, DAT_0005c034, DAT_0005c018, DAT_0005c01c; extern char DAT_0005819c[], *DAT_00058198;
extern unsigned char DAT_0005bf38, DAT_0005c02f, DAT_0005c02a, DAT_0005c02d, DAT_000581ac[], DAT_000581ad[], DAT_000581ae[];
extern unsigned char DAT_0005cf50, DAT_0005cf5a, DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_00051760[], DAT_00055760[];
extern short B0007b61c_dd[];
extern unsigned char *DAT_0005cb3c[], *DAT_0005cd3c[];  
extern void FUN_0002c124(int), FUN_00029ccc(int), FUN_0004131c(int, int, int), FUN_000412ec(void *, unsigned, int), FUN_0003f580(char *), FUN_00038dcc(int);
extern void FUN_000410b0(void *), FUN_00030850(void), FUN_000412dc(int), FUN_00041edc(int), FUN_00041f38(int), FUN_00041f94(void);
extern void FUN_00029cf4(void), FUN_00038ef0(void), FUN_00038e58(int, int, int), FUN_0002f8e0(int), FUN_000100b8(void), FUN_0002c160(int), FUN_00010010(int, int), FUN_0001ccf4(void);
extern int FUN_000412a0(char *), FUN_00039050(void), FUN_00039048(void), FUN_0002c328(int, int, int, int), FUN_0002c1dc(int), FUN_000253fc(void); extern void *FUN_0004104c(int);
void FUN_000281b4(int lvl)
{
    int t; short n; unsigned char *tmp; int saved; int old; int fh; int k; int off; char name[11] = "levels.dat"; unsigned char it[10]; int j; int from; unsigned char *p; int cnt; int o;
    if (lvl == 0x1a) FUN_0002c124(0x1d);
    if (lvl == 0xb) FUN_0002c124(0x1e);
    old = DAT_0005c6c8;
    if (old == lvl) return;
    FUN_000271fc(old);
    FUN_00029ccc(0);
    saved = DAT_0005bf38;
    DAT_0005819c[8] = lvl / 100 + '0';
    DAT_0005819c[10] = lvl % 10 + '0';
    DAT_0005819c[9] = (lvl - lvl / 100 * 100) / 10 + '0';
    DAT_0005bf38 = 0;
    fh = FUN_000412a0(DAT_0005819c);
    if (fh != -1) {
        from = 0;
        FUN_0004131c(0x1d, 0, fh);
    } else {
        fh = FUN_000412a0(name);
        if (fh == -1) FUN_0003f580(DAT_00058198);
        FUN_0004131c(lvl * 4 + 4, 0, fh);
        FUN_000412ec(&off, 4, fh);
        from = 1;
        FUN_0004131c(off + 0x1d, 0, fh);
    }
    DAT_0005c6c8 = lvl;
    FUN_000412ec(((unsigned char *)&B00075618_b1), 0x2a4, fh);
    j = B00075618_b1.b4;
    if (FUN_00039050() != j || FUN_00039048() != 1) FUN_00038dcc(0x9c4);
    FUN_000270ac();
    memset(M000698e0_b7, 0, 0x8000);
    for (k = 0; k < B00075618_b1.h; k++) FUN_000412ec(M000698e0_b7 + B00075618_b1.w * k, B00075618_b1.w * sizeof(short), fh);
    for (k = 0; k < 0x80; k++) {
        if (DAT_0005cb3c[k]) {
            FUN_000410b0(DAT_0005cb3c[k]);
            DAT_0005cb3c[k] = 0;
        }
    }
    memset(DAT_0005cb3c, 0, B00075618_b1.w * 4);
    for (k = 0; k < 0x80; k++) {
        if (DAT_0005cd3c[k]) {
            FUN_000410b0(DAT_0005cd3c[k]);
            DAT_0005cd3c[k] = 0;
        }
    }
    memset(DAT_0005cd3c, 0, B00075618_b1.w * 4);
    if (DAT_0005cf44) {
        FUN_000410b0(DAT_0005cf44);
        DAT_0005cf44 = 0;
    }
    cnt = 0;
    if (from == 1) { struct REC rec;
        tmp = FUN_0004104c(0x2bc);
        for (k = cnt; k < B00075618_b1.w; k++) {
            FUN_000412ec(&n, 2, fh);
            if (n) {
                DAT_0005cb3c[k] = FUN_0004104c((n + 1) * 10);
                memset(DAT_0005cb3c[k], 0, (n + 1) * 10);
                p = tmp + cnt * 10;
                for (j = 0, o = 0; j < n; j++) {
                    FUN_000412ec(it, 10, fh);
                    if (it[0] == 1) {
                        cnt++;
                        memmove(p, it, 10);
                        p += 10;
                    } else {
                        memmove(DAT_0005cb3c[k] + o, it, 10);
                        o += 10;
                    }
                }
            }
        }
        for (k = 0; k < B00075618_b1.w; k++) {
            n = 0;
            for (j = 0; j < cnt; j++) if ((tmp + j * 10)[5] == k) n++;
            if (n) {
                DAT_0005cd3c[k] = FUN_0004104c((n + 1) * 10);
                memset(DAT_0005cd3c[k], 0, (n + 1) * 10);
                for (j = 0, o = 0, p = tmp; j < n; p += 10) {
                    if (p[5] == k) {
                        j++;
                        memmove(DAT_0005cd3c[p[5]] + o, p, 10);
                        o += 10;
                    }
                }
            }
        }
        FUN_000410b0(tmp);
        for (k = 0; B00075618_b1.nent > k; k++) {
            FUN_000412ec(&rec, 0xb, fh);
            M00064d80_ay[k].a = rec.a;
            M00064d80_ay[k].b = rec.b;
            M00064d80_ay[k].c = rec.c;
            M00064d80_ay[k].d = rec.d;
            M00064d80_ay[k].kind = rec.kind;
            M00064d80_ay[k].f8 = *(int *)(B00072230_c4 + rec.kind * 0x45 + 0x35);
            M00064d80_ay[k].dir = rec.dir;
            M00064d80_ay[k].w10 = 0;
            M00064d80_ay[k].b2 = 0;
            M00064d80_ay[k].c3 = 0;
            M00064d80_ay[k].mode = 0;
            M00064d80_ay[k].cell = M00064d80_ay[k].c * B00075618_b1.w + M00064d80_ay[k].a;
            if (M00064d80_ay[k].f8 & 0x30000000) M00064d80_ay[k].hp = FUN_0002c328((unsigned char)B00072230_c4[(unsigned short)M00064d80_ay[k].kind * 0x45 + 0x1d], 8, 0, 0);
            else M00064d80_ay[k].hp = 0;
            if ((unsigned short)M00064d80_ay[k].kind == 8) M00064d80_ay[k].hp = 0x37;
        }
        for (k = 0; k < B00075618_b1.ndoor; k++) {
            FUN_000412ec(&rec, 0xb, fh);
            M00072238_dL[k].a = rec.a;
            M00072238_dL[k].b = rec.b;
            M00072238_dL[k].c = rec.c;
            M00072238_dL[k].d = rec.d;
            M00072238_dL[k].kind = rec.kind;
            M00072238_dL[k].w10 = 0;
            M00072238_dL[k].dir = rec.dir;
            M00072238_dL[k].c3 = 0;
            t = (rec.kind - 2) / 3;
            if (t >= 0 && t < 10) B0007b61c_dd[t] = k;
            M00072238_dL[k].cell = M00072238_dL[k].c * B00075618_b1.w + M00072238_dL[k].a;
        }
        for (k = 0; k < B00075618_b1.n4; k++) {
            FUN_000412ec(&rec, 0xb, fh);
            if (rec.kind == 0x54) rec.kind = 0x58;
            M00067618_e7[k].a = rec.a;
            M00067618_e7[k].b = rec.b;
            M00067618_e7[k].c = rec.c;
            M00067618_e7[k].d = rec.d;
            M00067618_e7[k].kind = rec.kind;
            M00067618_e7[k].w10 = 0;
            M00067618_e7[k].dir = 0;
            M00067618_e7[k].c3 = 0;
            M00067618_e7[k].cell = M00067618_e7[k].c * B00075618_b1.w + M00067618_e7[k].a;
        }
    } else {
        for (k = cnt; k < B00075618_b1.w; k++) {
            FUN_000412ec(&n, 2, fh);
            if (n) {
                DAT_0005cb3c[k] = FUN_0004104c((n + 1) * 10);
                memset(DAT_0005cb3c[k], 0, (n + 1) * 10);
                FUN_000412ec(DAT_0005cb3c[k], n * 10, fh);
            }
        }
        FUN_000412ec(&DAT_0005cf50, 1, fh);
        for (k = 0; k < B00075618_b1.w; k++) {
            FUN_000412ec(&n, 2, fh);
            if (n) {
                DAT_0005cd3c[k] = FUN_0004104c((n + 1) * 10);
                memset(DAT_0005cd3c[k], 0, (n + 1) * 10);
                FUN_000412ec(DAT_0005cd3c[k], n * 10, fh);
            }
        }
        FUN_000412ec(M00064d80_ay, B00075618_b1.nent * 0x16, fh);
        FUN_000412ec(&k, 2, fh);
        FUN_000412ec(M00072238_dL, B00075618_b1.ndoor * 0x16, fh);
        FUN_000412ec(M00067618_e7, B00075618_b1.n4 * 0x16, fh);
    }
    FUN_00027a68();
    if (DAT_0005c02f) FUN_00030850();
    DAT_0005cf44 = FUN_0004104c(0x514);
    FUN_000412ec(DAT_0005cf44, 0x514, fh);
    FUN_0004131c(4, 1, fh);
    FUN_000412ec(DAT_00051760, B00075618_b1.w * B00075618_b1.h, fh);
    FUN_000412ec(&k, 4, fh);
    memset(DAT_00055760, 0, 0x800);
    if (k < 0x7ff) FUN_000412ec(DAT_00055760, k, fh);
    FUN_000412dc(fh);
    if (B00075618_b1.solo == 0xff) {
        FUN_00041edc(DAT_000581ad[lvl * 3]);
        FUN_00041f38(DAT_000581ae[lvl * 3]);
    }
    DAT_0005f9cc = -1;
    FUN_00041f94();
    FUN_00029cf4();
    DAT_0005c038 = 0;
    if (!B00075618_b1.b2) B00075618_b1.b2 = 1;
    DAT_0005c02d = 0x80 - ((0x80 - B00075618_b1.b2) * DAT_0005c02a + 0x40) / 0x80;
    j = B00075618_b1.b4;
    if (FUN_00039050() != j || FUN_00039048() != 1) {
        FUN_00038ef0();
        FUN_00038e58(B00075618_b1.b4, 1, 0x9c4);
    }
    if (!DAT_000581ac[lvl * 3] && !DAT_0005c034) DAT_0005c034 = -1;
    FUN_0002f8e0(DAT_000581ac[lvl * 3]);
    if (lvl == 0x17) DAT_0005bf44 = 4;
    if (lvl == 0x15) DAT_0005bf44 = 0xc;
    if (lvl == 0xb) DAT_0005bf44 = 0x3d;
    DAT_0005bf38 = saved;
    if (lvl == 8 && FUN_0002c1dc(0x20)) {
        FUN_000100b8();
        FUN_0002c160(0x20);
    }
    if (6 == old) {
        if (lvl == 0xa) {
            FUN_0002c124(0xc2);
            FUN_00010010(0x31, 0x5e);
        }
        if (FUN_000253fc()) FUN_0002c124(0xd1);
        else DAT_0005bf44 = 0x51;
    }
    if (lvl == 0xc) DAT_0005bf44 = 0xe;
    DAT_0005cf5a = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    DAT_0005c018 = 0;
    DAT_0005c01c = 0;
    FUN_0001ccf4();
}

#undef DAT_0005cf44
#undef M00064d80_ay
#undef M00067618_e7
#undef M000698e0_b7
#undef B00072230_c4
#undef M00072238_dL
#pragma pack()

/* ---- module data _DATA 00058190-00058210 (docs/data/dataown.CODE2.csv: inferred (ref; some shared)), generated by tools/data2c.py */
char *DAT_00058190 = "No Space Available For Temporary Work Area";
char *DAT_00058194 = "Error trying to open level temp file.";
char *DAT_00058198 = "Cannot find file levels.dat";
char DAT_0005819c[16] = "work\\lev???.dat";   /* the level number is written into 0x581a4..0x581a6 */
unsigned char DAT_000581ac[1] = { 4 };
unsigned char DAT_000581ad[1] = { 10 };
unsigned char DAT_000581ae[98] = {
    3, 4, 10, 3, 4, 10, 3, 2, 10, 3, 2, 10, 3, 3, 10, 3,
    3, 10, 3, 2, 10, 3, 4, 0, 0, 2, 10, 3, 3, 10, 3, 3,
    0, 0, 2, 10, 3, 2, 10, 3, 2, 10, 3, 4, 10, 3, 4, 0,
    0, 4, 0, 0, 3, 0, 0, 4, 10, 3, 3, 10, 3, 3, 10, 3,
    4, 0, 0, 3, 0, 0, 3, 0, 0, 4, 0, 0, 4, 0, 0, 3,
    10, 3, 2, 10, 3, 0, 10, 3, 3, 10, 3, 4, 0, 0, 4, 10,
    3
};
/* ---- end of module data _DATA */
