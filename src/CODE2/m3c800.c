/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
unsigned char F0007b638_ml[4];
int B0007b638_d2;
int B0007b634_e6;
int B0007b630_hz;
/* BSS end */
/* Module: FUN_0003c800, FUN_0003c8e4, FUN_0003c9dc, FUN_0003ca5c, FUN_0003cad4, FUN_0003cc88, FUN_0003ceb8,
   FUN_0003d004, FUN_0003d234, FUN_0003d2f4, FUN_0003d3c4, FUN_0003d3d8, FUN_0003d5d0, FUN_0003d9fc,
   FUN_0003da7c, FUN_0003dbac, FUN_0003df2c, FUN_0003e0e4, FUN_0003e120 */
/* One object, compiled as the original module (-3s -ot -d2 -oe -s). Every external has one declaration; where a
   function below sees a symbol with another type, it reads it through a cast view of that one symbol
   (#define X (*(T *)&X), ((T *)X) for arrays, a cast function pointer for calls) instead of a second extern
   name: an extra EXTDEF name fills the object writer's name buffer and moves the LEDATA record cuts
   (recipe 17). TODO types (plan step 2): give each symbol its one real type. */
/* ---- from build/var/mod/parts/p3c800.c */
/* FUN_0003c800 @ 0003c800: is (y, x) within reach of a living monster other than skip; unoptimised module */
#include "world.h"
struct O { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; unsigned short s, type; short timer, w12; unsigned short w14; };
extern struct O B00064d80_ay[];  extern unsigned char *B00072230_c4;
int FUN_0003c800(unsigned y, unsigned x, int skip)
{
    {
        int i; int r; unsigned y0; unsigned y1; unsigned x0; unsigned x1;
        for (i = 0; i < B00075618_b1.nent; i++) {
            if (i == skip) continue;
            if (B00064d80_ay[i].dead) continue;
            y1 = B00064d80_ay[i].b;
            y0 = y1;
            x1 = B00064d80_ay[i].a;
            x0 = x1;
            r = *(unsigned short *)(B00072230_c4 + B00064d80_ay[i].type * 0x45 + 0x16) + 1000;
            y0 -= r;
            y1 += r;
            x0 -= r;
            x1 += r;
            if ((x >= y0 && x <= y1) && (y >= x0 && y <= x1)) return 1;
        }
        return 0;
    }
}

/* ---- from build/var/mod/parts/p3c8e4.c */
#define O T1_O
/* FUN_0003c8e4 @ 0003c8e4: is (y, x) inside a living person monster other than skip; unoptimised module */
struct O { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; unsigned short s, type; short timer, w12; unsigned short w14; };
#define M00064d80_ay ((struct O *)B00064d80_ay)
extern int FUN_0003acdc(int);
int FUN_0003c8e4(unsigned y, unsigned x, int skip)
{
    {
        int i; int r; unsigned y0; unsigned y1; unsigned x0; unsigned x1;
        for (i = 0; i < B00075618_b1.nent; i++) {
            if (i == skip) continue;
            if (!FUN_0003acdc(M00064d80_ay[i].type)) continue;
            if (M00064d80_ay[i].dead) continue;
            y1 = M00064d80_ay[i].b;
            y0 = y1;
            x1 = M00064d80_ay[i].a;
            x0 = x1;
            r = *(unsigned short *)(B00072230_c4 + M00064d80_ay[i].type * 0x45 + 0x16);
            y0 -= r;
            y1 += r;
            x0 -= r;
            x1 += r;
            if ((x >= y0 && x <= y1) && (y >= x0 && y <= x1)) return 1;
        }
        return 0;
    }
}

#undef M00064d80_ay
#undef O
/* ---- from build/var/mod/parts/p3c9dc.c */
/* FUN_0003c9dc @ 0003c9dc: is the point (y, x) within 0x8fa0 of the party on both axes; debug-info module (-3s -d2 -oe -s: -d2 keeps "add [mem],-c" that -od turns into sub; locals in an inner block; first-declared gets the lowest slot) */
extern unsigned B000755d0_ao, B000755d4_ak;
int FUN_0003c9dc(unsigned y, unsigned x)
{
    {
        unsigned x0, x1, y0, y1;
        x1 = B000755d0_ao;
        x0 = x1;
        y1 = B000755d4_ak;
        y0 = y1;
        x0 += -0x8fa0;
        x1 += 0x8fa0;
        y0 += -0x8fa0;
        y1 += 0x8fa0;
        if ((x >= x0 && x <= x1) && (y >= y0 && y <= y1)) return 1;
        return 0;
    }
}

/* ---- from build/var/mod/parts/p3ca5c.c */
/* FUN_0003ca5c @ 0003ca5c: is there a scenery object of type 0xad at map cell (y, x); unoptimised module */
struct SO { short xf, x, yf, y; unsigned char f8, f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short w14; };
extern struct SO B00072238_dL[]; 
int FUN_0003ca5c(int y, int x)
{
    {
        int i;
        for (i = 0; i < B00075618_b1.ndoor; i++) {
            if (B00072238_dL[i].type == 0xad) {
                if (B00072238_dL[i].y == y && B00072238_dL[i].x == x) return 1;
            }
        }
        return 0;
    }
}

/* ---- from build/var/mod/parts/p3cad4.c */
/* FUN_0003cad4 @ 0003cad4: the end: the party is put at the gate and Vladislav, Irmgarde and Tatiana leave; debug-info module */
extern int FUN_00024a60(char *), FUN_0002c1dc(int);
extern void FUN_000281b4(int), FUN_00024c40(int), FUN_0002c160(int), FUN_0002c124(int), FUN_0001ccf4(void);
extern int DAT_0005c658, DAT_0005bf44; extern unsigned short B000718f0_hO[]; extern unsigned char DAT_0005cf5a[];
#define B000755d0_ao (*(int *)&B000755d0_ao)
#define B000755d4_ak (*(int *)&B000755d4_ak)
#define CH16(i) (*(unsigned short *)((char *)B000718f0_hO + (i) * 0x248))
void FUN_0003cad4(void)
{
    int vl, ta, ir, i;
    ((short *)&B000755d0_ao)[1] = 0x26;
    ((short *)&B000755d0_ao)[0] = 0x8000;
    ((short *)&B000755d4_ak)[1] = 0x37;
    ((short *)&B000755d4_ak)[0] = 0x8000;
    DAT_0005c658 = 0x5a;
    FUN_000281b4(0x18);
    DAT_0005bf44 = 0x12;
    vl = FUN_00024a60("VLADISLAV");
    ir = FUN_00024a60("IRMGARDE");
    ta = FUN_00024a60("TATIAN");
    for (i = 0; i < 4; i++) {
        if (i == vl) {
            FUN_00024c40(i);
            FUN_0002c160(0xc);
            FUN_0002c124(0x17);
            CH16(i) = 0x8000;
            DAT_0005cf5a[i] = 1;
            if (FUN_0002c1dc(0x47)) {
                FUN_0002c160(8);
                FUN_0002c124(0x13);
            }
        }
        if (i == ir) {
            if (CH16(i) < 0x4000) {
                FUN_00024c40(i);
                FUN_0002c160(9);
                FUN_0002c124(0x14);
                CH16(i) = 0x8000;
                DAT_0005cf5a[i] = 1;
            }
        }
        if (i == ta) {
            DAT_0005bf44 = 0x11;
            FUN_00024c40(i);
            FUN_0002c160(8);
            FUN_0002c124(0x13);
            CH16(i) = 0x8000;
            DAT_0005cf5a[i] = 1;
        }
    }
    FUN_0001ccf4();
}

#undef B000755d0_ao
#undef B000755d4_ak
#undef CH16
/* ---- from build/var/mod/parts/p3cc88.c */
extern void FUN_0003cad4(void); /* module prototype */
#define O T5_O
#define SO T5_SO
/* FUN_0003cc88 @ 0003cc88: does a solid scenery object block (y, x) for mover who (-1: the party, who may pass the two gates and the exit); 2 when the party was moved; debug-info module */
struct SO { int a, b; unsigned char f8, f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short lo : 6, st : 3, rest : 7; };
struct MT { unsigned char pad[0x39]; unsigned char lo : 7, ghost : 1; unsigned char rest[0x45 - 0x3a]; };
struct O { int a, b; unsigned char f8, f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short w14; };

extern unsigned char *B000755dc_aX; extern int DAT_0005c6c8;
#define B00072238_dL ((struct SO *)B00072238_dL)
#define M00064d80_ay ((struct O *)B00064d80_ay)
#define B00072230_c4 (*(struct MT **)&B00072230_c4)
#define B000755d0_ao (*(int *)&B000755d0_ao)
#define B000755d4_ak (*(int *)&B000755d4_ak)
extern void FUN_0002c0c0(int), FUN_000281b4(int);
int FUN_0003cc88(unsigned y, unsigned x, int who)
{
    int i; unsigned a, b, c, d; unsigned char *t;
    for (i = 0; i < B00075618_b1.ndoor; i++) {
        b = B00072238_dL[i].b;
        a = b;
        d = B00072238_dL[i].a;
        c = d;
        if (*(unsigned short *)(B000755dc_aX + B00072238_dL[i].type * 7 + 2) <= 1) continue;
        t = B000755dc_aX + B00072238_dL[i].type * 7;
        a -= *(unsigned short *)(t + 2);
        b += *(unsigned short *)(t + 2);
        c -= *(unsigned short *)(t + 2);
        d += *(unsigned short *)(t + 2);
        if ((x >= a && x <= b) && (y >= c && y <= d)) {
            if (who == -1) {
                if (B00072238_dL[i].type == 0x54) {
                    if (B00072238_dL[i].st == 1) {
                        if (DAT_0005c6c8 == 0x17) {
                            ((short *)&B000755d0_ao)[1] = 3;
                            ((short *)&B000755d0_ao)[0] = 0x8000;
                            ((short *)&B000755d4_ak)[1] = 0xa;
                            ((short *)&B000755d4_ak)[0] = 0x8000;
                            FUN_0002c0c0(0xb4);
                            FUN_000281b4(0x13);
                            return 2;
                        } else if (DAT_0005c6c8 == 0xa) {
                            ((short *)&B000755d0_ao)[1] = 6;
                            ((short *)&B000755d0_ao)[0] = 0x8000;
                            ((short *)&B000755d4_ak)[1] = 0x3e;
                            ((short *)&B000755d4_ak)[0] = 0x8000;
                            FUN_0002c0c0(0xb4);
                            FUN_000281b4(6);
                            return 2;
                        }
                    }
                } else if (B00072238_dL[i].type == 0x7a) {
                    FUN_0003cad4();
                    return 2;
                } else return 1;
            } else {
                if (who >= 0 && who < 400) {
                    if (B00072230_c4[M00064d80_ay[who].type].ghost) return 0;
                }
                return 1;
            }
        }
    }
    return 0;
}

#undef M00064d80_ay
#undef B00072230_c4
#undef B00072238_dL
#undef B000755d0_ao
#undef B000755d4_ak
#undef O
#undef SO
/* ---- from build/var/mod/parts/p3ceb8.c */
/* FUN_0003ceb8 @ 0003ceb8: play the 0x47 frames of the closing flight (Esc skips), then put the party at the castle gate; unoptimised module */
extern int DAT_0005bf30, B0007b630_hz, B0007b634_e6, DAT_0005c050, B000758ec_bl, DAT_0005c658;
extern void FUN_0003e608(void), FUN_000391b0(unsigned char), FUN_0002f1c8(void), FUN_0003e510(int, int, int, int), FUN_0003efd0(int, int);
extern void FUN_0002ea04(void), FUN_0002ea78(void), FUN_0003e614(unsigned, int), FUN_000281b4(int); extern int FUN_00040b40(void);
#define B000755d0_ao (*(int *)&B000755d0_ao)
#define B000755d4_ak (*(int *)&B000755d4_ak)
#define XF (((short *)&B000755d0_ao)[0])
#define XI (((short *)&B000755d0_ao)[1])
#define YF (((short *)&B000755d4_ak)[0])
#define YI (((short *)&B000755d4_ak)[1])
void FUN_0003ceb8(void)
{
    int i;
    DAT_0005bf30 = 2;
    B000755d0_ao = B0007b634_e6;
    B000755d4_ak = B0007b630_hz;
    for (i = 0; i < 0x47; i++) {
        FUN_0003e608();
        FUN_000391b0(DAT_0005c050);
        if (i < 0xb || i > 0x44) FUN_0002f1c8();
        FUN_0003e510(4, 0x20, B000758ec_bl + i, 9);
        FUN_0003efd0(B000758ec_bl + i, 9);
        FUN_0002ea04();
        FUN_0002ea78();
        FUN_0003e614(6, 0);
        if (FUN_00040b40() == 0x1b) break;
        if (i == 0xe) {
            XI = 0xd;
            YI = 0x23;
            DAT_0005c658 = 0xb4;
            XF = YF = 0x8000;
            FUN_000281b4(0x11);
        }
    }
    DAT_0005bf30 = 0;
    if (i <= 0xe) {
        XI = 0xd;
        YI = 0x23;
        DAT_0005c658 = 0xb4;
        XF = YF = 0x8000;
        FUN_000281b4(0x11);
    }
}

#undef B000755d0_ao
#undef B000755d4_ak
#undef XF
#undef XI
#undef YF
#undef YI
/* ---- from build/var/mod/parts/p3d004.c */
extern void FUN_0003ceb8(void); /* module prototype */
/* FUN_0003d004 @ 0003d004: use of item slot k: the mirror (items 0x242..0x247) ends the game in the castle areas or brings the party out of the crypt, else it hurts everybody and turns the party round; 1 when used; debug-info module */
extern int FUN_0002c1dc(int), FUN_0002c328(int, int, int, int);
#pragma aux FUN_0002c328 modify [eax ebx ecx edx];
extern void FUN_000281b4(int), FUN_0002f1c8(void), FUN_0002ea78(void), FUN_0001cd44(int, int), FUN_0003e510(int, int, int, int), FUN_0002ea04(void);
 extern int DAT_0005c6c8, B0007b630_hz, B0007b634_e6, DAT_0005c658, B000758ec_bl, DAT_0005bf44;
extern unsigned short B000718f0_hO[];
#define B000755d0_ao (*(int *)&B000755d0_ao)
#define B000755d4_ak (*(int *)&B000755d4_ak)
int FUN_0003d004(int k)
{
    int sy, sx, i;
    if (FUN_0002c1dc(0x3e)) {
        if (B00075618_b1.t0[k] >= 0x242 && B00075618_b1.t0[k] <= 0x247) {
            if (DAT_0005c6c8 == 8 || DAT_0005c6c8 == 0x12 || DAT_0005c6c8 == 0x17 || DAT_0005c6c8 == 0x18 || DAT_0005c6c8 == 0x19 || DAT_0005c6c8 == 0x1a || DAT_0005c6c8 == 0x1f) {
                FUN_0003ceb8();
                return 1;
            }
            if (DAT_0005c6c8 == 0x10 || DAT_0005c6c8 == 0x11) {
                ((short *)&B000755d0_ao)[1] = 0x21;
                ((short *)&B000755d0_ao)[0] = 0x8000;
                ((short *)&B000755d4_ak)[1] = 2;
                ((short *)&B000755d4_ak)[0] = 0x8000;
                DAT_0005c658 = 0;
                FUN_000281b4(0x1f);
                return 1;
            }
        }
    } else {
        if (B00075618_b1.t0[k] >= 0x242 && B00075618_b1.t0[k] <= 0x247) {
            sy = B000755d0_ao;
            sx = B000755d4_ak;
            B000755d0_ao = B0007b634_e6;
            B000755d4_ak = B0007b630_hz;
            FUN_0002f1c8();
            FUN_0002ea78();
            for (i = 0; i < 4; i++) {
                if (*(unsigned short *)((char *)B000718f0_hO + i * 0x248) >= 0x4000) continue;
                FUN_0001cd44(i, FUN_0002c328(1, 2, 0, 0));
            }
            FUN_0002f1c8();
            FUN_0003e510(4, 0x20, B000758ec_bl, 9);
            FUN_0002ea04();
            FUN_0002ea78();
            DAT_0005c658 += 0xb4;
            DAT_0005c658 %= 0x168;
            FUN_0002f1c8();
            FUN_0003e510(4, 0x20, B000758ec_bl, 9);
            FUN_0002ea04();
            FUN_0002ea78();
            DAT_0005bf44 = 0x2e;
            return 1;
        }
    }
    return 0;
}

#undef B000755d0_ao
#undef B000755d4_ak
/* ---- from build/var/mod/parts/p3d234.c */
/* FUN_0003d234 @ 0003d234: Vladislav leaves the party for good; unoptimised module */
void *memset(void *, int, unsigned);
extern int FUN_00024a60(char *); extern void FUN_0002c77c(int, int), FUN_00024c40(int), FUN_00024be0(int), FUN_0002c160(int), FUN_0001ccf4(void);
extern char B000718e0_iO[]; extern unsigned char DAT_0005cf5a[];
void FUN_0003d234(void)
{
    int k;
    k = FUN_00024a60("VLADISLAV");
    if (k != -1) {
        FUN_0002c77c(k, 0x2fb);
        FUN_00024c40(k);
        memset(B000718e0_iO + k * 0x248 + 0x40, 0, 0x2a);
        FUN_00024be0(k);
        FUN_0002c160(0xc);
        memset(B000718e0_iO + k * 0x248, 0xff, 0x248);
        *(unsigned short *)(B000718e0_iO + k * 0x248 + 0x10) = 0x8000;
        DAT_0005cf5a[k] = 1;
    }
    FUN_0001ccf4();
}

/* ---- from build/var/mod/parts/p3d2f4.c */
/* FUN_0003d2f4 @ 0003d2f4: Irmgarde leaves the party for good unless she is gone already; unoptimised module */
void *memset(void *, int, unsigned);
extern int FUN_00024a60(char *); extern void FUN_00024c40(int), FUN_00024be0(int), FUN_0002c160(int), FUN_0001ccf4(void);
extern char B000718e0_iO[]; extern unsigned char DAT_0005cf5a[]; extern int DAT_0005bf44;
void FUN_0003d2f4(void)
{
    int k;
    k = FUN_00024a60("IRMGARDE");
    if (k != -1) {
        if (*(unsigned short *)(B000718e0_iO + k * 0x248 + 0x10) < 0x4000) {
            DAT_0005bf44 = 0x49;
            FUN_00024c40(k);
            memset(B000718e0_iO + k * 0x248 + 0x40, 0, 0x2a);
            FUN_00024be0(k);
            FUN_0002c160(9);
            memset(B000718e0_iO + k * 0x248, 0xff, 0x248);
            *(unsigned short *)(B000718e0_iO + k * 0x248 + 0x10) = 0x8000;
            DAT_0005cf5a[k] = 1;
        }
    }
    FUN_0001ccf4();
}

/* ---- from build/var/mod/parts/p3d3c4.c */
/* FUN_0003d3c4 @ 0003d3c4: empty stub (debug-info module) */
void FUN_0003d3c4(void)
{
}

/* ---- from build/var/mod/parts/p3d3d8.c */
extern int FUN_0003ca5c(int y, int x); /* module prototype */
extern void FUN_0003d234(void); /* module prototype */
extern void FUN_0003d2f4(void); /* module prototype */
#define O T11_O
/* FUN_0003d3d8 @ 0003d3d8: teleport the party to map cell (cy, cx) of level lev, turning by dirs * 45 degrees; monsters standing there are pushed away; debug-info module */
struct O { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; unsigned short s, type; short timer, w12; unsigned short w14; };
#define M00064d80_ay ((struct O *)B00064d80_ay)

extern unsigned B000755d0_ao, B000755d4_ak; extern int DAT_0005c658, DAT_0005c6c8;
extern int FUN_0001e0f8(int);
extern void FUN_0002c0c0(int), FUN_000281b4(int), FUN_00038110(int, int, int, int);
void FUN_0003d3d8(int y, int x, int cy, int cx, int dirs, int lev)
{
    int found, old, i, r; unsigned a, b, c, d;
    found = FUN_0003ca5c(y, x);
    ((short *)&B000755d0_ao)[1] = cy;
    ((short *)&B000755d0_ao)[0] = 0x8000;
    ((short *)&B000755d4_ak)[1] = cx;
    ((short *)&B000755d4_ak)[0] = 0x8000;
    DAT_0005c658 += dirs * 0x2d;
    while (DAT_0005c658 >= 0x168) DAT_0005c658 -= 0x168;
    FUN_0002c0c0(DAT_0005c658);
    old = DAT_0005c6c8;
    FUN_000281b4(lev);
    for (i = 0; i < B00075618_b1.nent; i++) {
        if (M00064d80_ay[i].dead) continue;
        b = M00064d80_ay[i].b;
        a = b;
        d = M00064d80_ay[i].a;
        c = d;
        r = *(unsigned short *)(B00072230_c4 + M00064d80_ay[i].type * 0x45 + 0x16);
        a -= r * 2;
        b += r * 2;
        c -= r * 2;
        d += r * 2;
        if ((B000755d0_ao >= a && B000755d0_ao <= b) && (B000755d4_ak >= c && B000755d4_ak <= d)) {
            for (y = 0; y < 3; y++) {
                if (M00064d80_ay[i].type == B00075618_b1.aa[y]) {
                    if (FUN_0001e0f8(i)) break;
                }
            }
        }
    }
    if (old == DAT_0005c6c8) found = 1;
    if (old == 5 && DAT_0005c6c8 != 5) FUN_0003d234();
    if (DAT_0005c6c8 == 0xb && old != 0xb) FUN_0003d2f4();
    if (DAT_0005c6c8 == 0xa && old == 0xa) ;
    if (found) FUN_00038110(7, 0xff, 1, 1);
}

#undef M00064d80_ay
#undef O
/* ---- from build/var/mod/parts/p3d5d0.c */
extern int FUN_0003c800(unsigned y, unsigned x, int skip); /* module prototype */
extern int FUN_0003c9dc(unsigned y, unsigned x); /* module prototype */
extern int FUN_0003cc88(unsigned y, unsigned x, int who); /* module prototype */
extern int FUN_0003d004(int k); /* module prototype */
extern void FUN_0003d3d8(int y, int x, int cy, int cx, int dirs, int lev); /* module prototype */
#define O T12_O
/* FUN_0003d5d0 @ 0003d5d0: can mover who (-1 party, -2 probe, 0..0x18f a creature, 0x190 missile) stand at (x, y)?  Scans the squares under its bounding box for walls, doors and markers, then tests objects and creatures; 1 free, 0 blocked, -1 hit; debug-info module */
struct CELL { unsigned short lo : 6, seen : 1, door : 1, m8 : 3, mark : 1, pass : 1, rest : 3; };
struct MK { unsigned char kind; unsigned char b0 : 2, on : 1, b3 : 3, lock : 1, b7 : 1; signed char a2, a3; unsigned char a4, a5, a6, a7, a8, a9; };
struct O { int a, b; unsigned char f8, f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short w14; };
struct TY { unsigned char pad[0x39]; unsigned char b0 : 6, open : 1, ghost : 1; unsigned char rest[0xb]; };
extern struct CELL B000698e0_b7[];
#define M00064d80_ay ((struct O *)B00064d80_ay)
#define B00072230_c4 (*(struct TY **)&B00072230_c4)
 extern int DAT_0005f048;
extern struct MK *FUN_0002e8c8(int, int);
extern unsigned short FUN_0002e930(int);
extern void FUN_00030c0c(int, int, struct MK *);

short FUN_0003d5d0(int x, int y, int who)
{
    int x0, y0, x1, y1, blocked, n, last, cell, i, j, r, door, sv, t; struct MK *p;
    t = x; t += -0x5800; x0 = ((short *)&t)[1];
    t = y; t += -0x5800; y0 = ((short *)&t)[1];
    t = x; t += 0x5800; x1 = ((short *)&t)[1];
    t = y; t += 0x5800; y1 = ((short *)&t)[1];
    last = -1;
    blocked = 0;
    n = 0;
    for (i = y0; i <= y1; i++) {
        for (j = x0; j <= x1; j++) {
            if (DAT_0005f048) continue;
            cell = B00075618_b1.w * j + i;
            if (j < 0 || j >= B00075618_b1.h) continue;
            if (i < 0 || i >= B00075618_b1.w) continue;
            if (last != cell) {
                last = cell;
                p = FUN_0002e8c8(i, j);
            }
            if (B000698e0_b7[cell].door) {
                door = FUN_0002e930(cell);
                if (door) {
                    if (p && p->kind != 8) {
                        if (door == 0x8000) {
                            if (p->on && !p->lock && (who >= 0 && who < 0x190) && B00072230_c4[M00064d80_ay[who].type].open) {
                                if (!p->a7) {
                                    sv = p->on;
                                    p->on = 1;
                                    FUN_00030c0c(i, j, p);
                                    p->on = sv;
                                } else blocked = 1;
                            } else {
                                if (who != -2) blocked = 1;
                            }
                        } else {
                            if (who >= 0 && who < 0x190) {
                                if (!B00072230_c4[M00064d80_ay[who].type].ghost) blocked = 1;
                            } else blocked = 1;
                        }
                    }
                }
            }
            if (B000698e0_b7[cell].lo) {
                if (!B000698e0_b7[cell].mark) {
                    if (!B000698e0_b7[cell].pass) {
                        if (who == -1 && FUN_0003d004(B000698e0_b7[cell].lo)) return 1;
                        blocked = 1;
                    } else {
                        if (p) {
                            if (who == -2) blocked = 1;
                            else switch (p->kind) {
                            case 8:
                                if (who == 0x190) blocked = 1;
                                else if (who == -1) {
                                    FUN_0003d3d8(i, j, p->a7, p->a8, p->a9, p->a6);
                                    DAT_0005f048 = 1;
                                    return 1;
                                }
                                break;
                            case 1:
                                break;
                            default:
                                blocked = 1;
                            }
                        }
                    }
                } else {
                    if (who != -1) blocked = 1;
                }
            }
        }
    }
    if (who != -2) {
        if (FUN_0003c800(x, y, who)) return 0;
        if (who != 0x190) {
            r = FUN_0003cc88(x, y, who);
            if (r == 2) return -1;
            if (r == 1) return 0;
        }
        if (who >= 0 && FUN_0003c9dc(x, y)) return 0;
    }
    return !blocked;
}

#undef M00064d80_ay
#undef B00072230_c4
#undef O
/* ---- from build/var/mod/parts/p3d9fc.c */
/* FUN_0003d9fc @ 0003d9fc: the first able elf in the party may get a vision (1 in 2) */
#define B000718f4_h3 ((unsigned char *)((char *)&B000718e0_iO + 20)) /* STANDIN: view, B000718e0_iO + 0x14 */
extern unsigned short B000718f0_hO[]; 
extern int FUN_0002c328(int, int, int, int); extern void FUN_0002c77c(int, int);
void FUN_0003d9fc(void)
{
    {
        int i;
        for (i = 0; i < 4; i++) {
            if (*(unsigned short *)((char *)B000718f0_hO + i * 0x248) & 0xf240) continue;
            if (B000718f4_h3[i * 0x248] == 5) {
                if (FUN_0002c328(1, 2, 0, 0) == 1) {
                    FUN_0002c77c(i, 0x2cd);
                    break;
                }
            }
        }
    }
}

/* ---- from build/var/mod/parts/p3da7c.c */
#define CELL T14_CELL
/* FUN_0003da7c @ 0003da7c: next to map cell c a hidden door may be spotted by the first able elf (1 in 6) or dwarf (4 in 6); unoptimised module */
struct CELL { unsigned short lo : 10, b10 : 1, b11 : 1, rest : 4; };
#define M000698e0_b7 ((struct CELL *)B000698e0_b7)
extern short B00077108_dk[];
extern unsigned short B000718f0_hO[]; 
extern int FUN_0002c328(int, int, int, int); extern void FUN_0002c77c(int, int);
void FUN_0003da7c(int c)
{
    int i; int j;
    for (i = 0; i < 8; i++) {
        if (M000698e0_b7[B00077108_dk[i] + c].b11) {
            if (!M000698e0_b7[B00077108_dk[i] + (c + B00077108_dk[i])].b10) {
                for (j = 0; j < 4; j++) {
                    if (*(unsigned short *)((char *)B000718f0_hO + j * 0x248) & 0xf240) continue;
                    if (B000718f4_h3[j * 0x248] == 5) {
                        if (FUN_0002c328(1, 6, 0, 0) == 1) {
                            FUN_0002c77c(j, 0x2cc);
                            break;
                        }
                    } else if (B000718f4_h3[j * 0x248] == 4) {
                        if (FUN_0002c328(1, 6, 0, 0) <= 4) {
                            FUN_0002c77c(j, 0x2cc);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}

#undef CELL
#undef M000698e0_b7
/* ---- from build/var/mod/parts/p3dbac.c */
extern void FUN_0003d3d8(int y, int x, int cy, int cx, int dirs, int lev); /* module prototype */
extern short FUN_0003d5d0(int x, int y, int who); /* module prototype */
extern void FUN_0003da7c(int c); /* module prototype */
#define CELL T15_CELL
#define MK T15_MK
/* FUN_0003dbac @ 0003dbac: move the party by (dx, dy), sliding along walls; on entering a new square handle its markers (wall plate light, teleport/trap/turn objects); debug-info module */
struct CELL { unsigned short lo : 6, mid : 5, mark : 1, rest : 4; };
#define M000698e0_b7 ((struct CELL *)B000698e0_b7)
#define FUN_00038110 ((void (*)(void *, int, int, int))FUN_00038110)
extern void FUN_000102a8(int);
struct MK { unsigned char kind; unsigned char b0 : 2, on : 1, b3 : 5; signed char a2, a3; unsigned char a4, a5, a6, a7, a8, a9; };
#define FUN_0002e8c8 ((struct MK *(*)(int, int))FUN_0002e8c8)
#define B000755d0_ao (*(int *)&B000755d0_ao)
#define B000755d4_ak (*(int *)&B000755d4_ak)
extern int B0007b630_hz, B0007b634_e6, DAT_0005f040, DAT_0005f044, DAT_0005f048, B0007b638_d2, DAT_0005cf6c, DAT_0005c658;
 extern char *B000758bc_al;
void FUN_0003dbac(int dx, int dy)
{
    int a, b, cell; struct MK *p;
    B0007b630_hz = B000755d4_ak;
    B0007b634_e6 = B000755d0_ao;
    a = B000755d4_ak;
    b = B000755d0_ao;
    B000755d4_ak = a + dx;
    B000755d0_ao = b + dy;
    DAT_0005f048 = 0;
    if (!FUN_0003d5d0(B000755d4_ak, B000755d0_ao, -1)) if (!DAT_0005f048) {
        B000755d4_ak = a + dx;
        B000755d0_ao = b;
        if (!FUN_0003d5d0(B000755d4_ak, B000755d0_ao, -1)) if (!DAT_0005f048) {
            B000755d4_ak = a;
            B000755d0_ao = b + dy;
            if (!FUN_0003d5d0(B000755d4_ak, B000755d0_ao, -1)) if (!DAT_0005f048) {
                B000755d4_ak = a;
                B000755d0_ao = b;
            }
        }
    }
    if (((short *)&B000755d4_ak)[1] != DAT_0005f044 || ((short *)&B000755d0_ao)[1] != DAT_0005f040) {
        cell = B00075618_b1.w * DAT_0005f044 + DAT_0005f040;
        FUN_0003da7c(cell);
        if (M000698e0_b7[cell].mark) {
            M000698e0_b7[cell].lo = B0007b638_d2;
            FUN_00038110(B000758bc_al + 10, 0xff, 1, 4);
        }
        if (DAT_0005f044 != -1 && !DAT_0005f048) {
            p = FUN_0002e8c8(DAT_0005f040, DAT_0005f044);
            if (p) {
                switch (p->kind) {
                case 3:
                    if (p->on) FUN_000102a8(p->a3);
                    break;
                case 6:
                    if (p->on) {
                        if (p->a6) DAT_0005cf6c = 0;
                    }
                    break;
                }
            }
        }
        DAT_0005f040 = ((short *)&B000755d0_ao)[1];
        DAT_0005f044 = ((short *)&B000755d4_ak)[1];
        cell = B00075618_b1.w * DAT_0005f044 + DAT_0005f040;
        if (M000698e0_b7[cell].mark) {
            FUN_00038110(B000758bc_al + 10, 0xff, 1, 4);
            B0007b638_d2 = M000698e0_b7[cell].lo;
            M000698e0_b7[cell].lo = 0;
        }
        p = FUN_0002e8c8(((short *)&B000755d0_ao)[1], ((short *)&B000755d4_ak)[1]);
        if (p) {
            switch (p->kind) {
            case 3:
                if (p->on) FUN_000102a8(p->a2);
                break;
            case 8:
                FUN_0003d3d8(((short *)&B000755d0_ao)[1], ((short *)&B000755d4_ak)[1], p->a7, p->a8, p->a9, p->a6);
                break;
            case 6:
                if (p->on) {
                    if (!p->a6) DAT_0005c658 = (DAT_0005c658 + 0xb4) % 0x168;
                    else DAT_0005cf6c = 1;
                }
                break;
            }
        }
    }
    DAT_0005f048 = 0;
}

#undef CELL
#undef M000698e0_b7
#undef B000755d0_ao
#undef B000755d4_ak
#undef FUN_0002e8c8
#undef FUN_00038110
#undef MK
/* ---- from build/var/mod/parts/p3df2c.c */
/* FUN_0003df2c @ 0003df2c: step vector (px, py) for distance dist in direction ang (16.16); one of eight fixed unit steps when DAT_0005c02f is set; debug-info module, built with -ot before -d2 (lea for index scaling) */
union FX { int v; struct { unsigned short f; short i; } s; };
extern unsigned char DAT_0005c02f; extern int *DAT_0005c664, *DAT_0005c65c;
extern int FUN_00045680(int, int);
void FUN_0003df2c(int *py, int *px, union FX dist, int ang)
{
    int s;
    if (ang >= 0x168) ang -= 0x168;
    if (ang < 0) ang += 0x168;
    if (!DAT_0005c02f) {
        if (dist.s.i >= 0) {
            if (dist.s.i == 0 && dist.s.f >= (unsigned short)0xb000) {
                dist.s.i = 0;
                dist.s.f = 0xafff;
            }
        }
        s = DAT_0005c664[ang];
        *px = FUN_00045680(dist.v, s);
        s = DAT_0005c65c[ang];
        *py = -FUN_00045680(dist.v, s);
    } else {
        switch (ang / 45) {
        case 0: *px = 0x10000; *py = 0; break;
        case 1: *px = 0x10000; *py = -0x10000; break;
        case 2: *px = 0; *py = -0x10000; break;
        case 3: *px = -0x10000; *py = -0x10000; break;
        case 4: *px = -0x10000; *py = 0; break;
        case 5: *px = -0x10000; *py = 0x10000; break;
        case 6: *px = 0; *py = 0x10000; break;
        case 7: *px = 0x10000; *py = 0x10000; break;
        }
    }
}

/* ---- from build/var/mod/parts/p3e0e4.c */
extern void FUN_0003dbac(int dx, int dy); /* module prototype */
#define FX T17_FX
/* FUN_0003e0e4, FUN_0003e120 (debug-info module, -3s -d2 -oe -s: FUN_0003e0e4 is inlined twice into FUN_0003e120; FUN_0003e0e4 was missed by the Ghidra export, it sits where Ghidra ended FUN_0003df2c) */
union FX { int v; struct { short f, i; } s; };

extern int FUN_000469a7(int); /* abs */
extern int DAT_0005c6e4, DAT_0005c6ec, DAT_0005c658, DAT_0005c6f0, DAT_0005c6e8; extern unsigned char DAT_0005c02f;
/* FUN_0003e0e4 @ 0003e0e4: move the party by dist in direction ang */
void FUN_0003e0e4(int ang, int dist)
{
    int px, py;
    ((void (*)(int *, int *, int, int))FUN_0003df2c)(&py, &px, dist, ang);
    FUN_0003dbac(px, py);
}


extern int FUN_000469a7(int); 
extern int DAT_0005c6e4, DAT_0005c6ec, DAT_0005c658, DAT_0005c6f0, DAT_0005c6e8; extern unsigned char DAT_0005c02f;

/* FUN_0003e120 @ 0003e120: per-frame movement: turn by the accumulated turn speed, then walk forward/back or sidestep */
void FUN_0003e120(void)
{
    int d; union FX k, m; int a, t, back;
    DAT_0005c6e4 += DAT_0005c6ec;
    t = DAT_0005c6e4 / 20;
    DAT_0005c6e4 -= t * 20;
    if (!DAT_0005c02f) {
        DAT_0005c658 -= t;
        if (DAT_0005c658 >= 0x168) DAT_0005c658 -= 0x168;
        if (DAT_0005c658 < 0) DAT_0005c658 += 0x168;
    } else {
        if (t < 0) t = -0x5a;
        else if (t > 0) t = 0x5a;
        DAT_0005c658 -= t;
        if (DAT_0005c658 >= 0x168) DAT_0005c658 -= 0x168;
        if (DAT_0005c658 < 0) DAT_0005c658 += 0x168;
    }
    a = DAT_0005c658;
    if (DAT_0005c6f0) {
        DAT_0005c6e8 = FUN_000469a7(DAT_0005c6f0);
        if (DAT_0005c6f0 < 0) a += -0x5a;
        else a += 0x5a;
        if (a >= 0x168) a += -0x168;
        if (a < 0) a += 0x168;
    }
    if (DAT_0005c6e8 < 0) {
        k.s.i = 0; k.s.f = 0x96;
        m.s.i = 0; m.s.f = DAT_0005c6e8; m.s.f = -m.s.f; m.v = m.s.f;
        d = k.v * m.v;
        FUN_0003e0e4(a, d);
    } else if (DAT_0005c6e8 > 0) {
        back = a;
        back += 0xb4;
        if (back >= 0x168) back += -0x168;
        k.s.i = 0; k.s.f = 0x64;
        m.v = DAT_0005c6e8;
        d = k.v * m.v;
        FUN_0003e0e4(back, d);
    }
}

#undef FUN_0003df2c
#undef FX

/* ---- module data _DATA 0005f040-0005f04c (docs/data/dataown.CODE2.csv: certain), generated by tools/data2c.py */
int DAT_0005f040 = -1;
int DAT_0005f044 = -1;
int DAT_0005f048 = 0;
/* ---- end of module data _DATA */
