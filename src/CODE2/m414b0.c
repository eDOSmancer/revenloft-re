/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
struct SKY **B0007b764_fp;
short B0007b750_el[10];
/* BSS end */
/* Module: FUN_000414b0, FUN_000418b4, FUN_00041a14, FUN_00041c58, FUN_00041e74, FUN_00041edc, FUN_00041f38, FUN_00041f94 */
/* ---- from build/var/mod/parts/p414b0.c */
/* FUN_000414b0 @ 000414b0: draw the outdoor sky for sky set n: the cloud band (random tiles, darker at night) then the sky pictures (sun, moon, mountains) placed by the view angle, wrapping round 360 degrees */
#include "world.h"
struct SKY { short id, ang, w, y; };
extern short B0007b750_el[10]; extern struct SKY **B0007b764_fp; extern int DAT_0005c658; extern unsigned char DAT_0005f918;
extern void FUN_000396c0(int, int, int, int), FUN_00039838(int, int, int, int, int, unsigned char), FUN_0003986c(int, int, int, int, int, unsigned char);
extern void srand(unsigned); extern unsigned rand(void); extern int FUN_00040700(void);
void FUN_000414b0(int n)
{
    int i, y, x; struct SKY *sky; int a, base, sh, pic;
    base = B0007b750_el[n];
    sky = B0007b764_fp[n];
    FUN_000396c0(4, 0x20, 0x83, 0x11f);
    srand(DAT_0005c658);
    if (DAT_0005f918 <= 8) {
        for (i = 0; i < 0x20; i++) FUN_00039838(0, 4, i * 8 + 0x20, (rand() * 7 >> 15) + base, 8, DAT_0005f918);
    } else if (DAT_0005f918 == 9) {
        for (i = 0; i < 0x20; i++) FUN_00039838(0, 4, i * 8 + 0x20, base + 8 + (rand() * 7 >> 15), 8, 8);
    } else if (DAT_0005f918 == 10) {
        for (i = 0; i < 0x20; i++) FUN_00039838(0, 4, i * 8 + 0x20, base + 0x10 + (rand() * 7 >> 15), 8, 8);
    }
    srand(FUN_00040700());
    for (i = 0; ; i++) {
        if (i > 0 && !sky[i].id) break;
        sh = DAT_0005f918;
        if (sh > 8) sh = 8;
        if (i == 0) {
            sh /= 2;
            if (sky[i].id != 0x18) sh = 0;
        }
        pic = sky[i].id;
        if (pic >= 8) pic += base;
        y = sky[i].y;
        a = sky[i].ang - DAT_0005c658;
        a = (a * 128 + 0x12) / 0x24;
        x = 0xa0 - a;
        x -= sky[i].w / 2;
        if (x < 0x120 && sky[i].w + x >= 0x20) FUN_0003986c(0, y, x, pic, 8, sh);
        else {
            a = sky[i].ang - DAT_0005c658 + 0x168;
            a = (a * 128 + 0x12) / 0x24;
            x = 0xa0 - a;
            x -= sky[i].w / 2;
            if (x < 0x120 && sky[i].w + x >= 0x20) FUN_0003986c(0, y, x, pic, 8, sh);
            else {
                a = sky[i].ang - DAT_0005c658 - 0x168;
                a = (a * 128 + 0x12) / 0x24;
                x = 0xa0 - a;
                x -= sky[i].w / 2;
                FUN_0003986c(0, y, x, pic, 8, sh);
            }
        }
    }
    FUN_000396c0(0, 0, 0x18f, 0x13f);
}

/* ---- from build/var/mod/parts/p418b4.c */
/* FUN_000418b4 @ 000418b4: build the shading table for the indoor light level lvl: per distance step the dithered shade pair, full darkness (8) beyond the view distance, and the floor/ceiling fade bytes for the near half */
extern int DAT_0005c730, DAT_0005c738; extern unsigned char DAT_0005f918; extern short *B000758c4_j7; extern unsigned short DAT_0005fcfa;
extern signed char DAT_0005fe14[], DAT_0005fe94[];
void FUN_000418b4(int lvl)
{
    int i, n, v, l9; signed char c1, c2;
    n = DAT_0005c738;
    l9 = lvl + 9;
    DAT_0005f918 = lvl;
    for (i = 0; i < DAT_0005c730 + 1; i++) {
        if (i < n) {
            c1 = (i * l9 + (DAT_0005c738 >> 1)) / DAT_0005c738;
            if (c1 < 0) c1 = 0;
            c2 = c1;
            if (c1 > 9) c1 = 9;
            if (c2 > 9) c2 = 9;
            if (i / (n / (l9 * 2)) & 1) c2--;
            if (c1 <= 2) c2 = c1;
            if (c1 == 8 && c2 == 9) c2 = 8;
        } else {
            c2 = 8;
            c1 = c2;
        }
        v = c2;
        v <<= 8;
        v += c1;
        B000758c4_j7[i] = v;
        if (i < 0x80) {
            if (c1 > 8) c1 = 8;
            DAT_0005fe14[0x7f - i] = c1;
            DAT_0005fe94[i] = c1;
        }
    }
    DAT_0005fcfa = 0x808;
}

/* ---- from build/var/mod/parts/p41a14.c */
/* FUN_00041a14 @ 00041a14: build the distance shading table for light level lvl and darkness dark (0..8): per distance step the two shade indices (dithered pair), the floor and ceiling fade bytes */
extern int DAT_0005c730, DAT_0005c738; extern unsigned char DAT_0005f918; extern short DAT_0005f954[];
extern short *B000758c4_j7; extern unsigned short DAT_0005fcfa; extern signed char DAT_0005fe4e[], DAT_0005fe14[];
void FUN_00041a14(int lvl, int dark)
{
    int i, n1, v, l1, t, d1, sub, a, b; signed char c1, c2;
    if (dark > 8) dark = 8;
    l1 = lvl + 1;
    n1 = DAT_0005c730 + 1;
    d1 = dark + 1;
    t = dark * (DAT_0005c738 / (10 - d1));
    a = DAT_0005c738 - t;
    b = DAT_0005c730 - a;
    DAT_0005f918 = lvl;
    for (i = 0; i < DAT_0005c730 + 1; i++) {
        c1 = ((n1 - i + 1) * l1 + (DAT_0005c730 + 1 >> 1)) / (DAT_0005c730 + 1);
        if (c1 < 0) c1 = 0;
        c1 = (c1 * 5 + (DAT_0005f954[lvl] >> 1)) / DAT_0005f954[lvl];
        c2 = c1;
        if (c1 > 9) c1 = 9;
        if (c2 > 9) c2 = 9;
        if (dark && i) {
            if (i > a) sub = ((i - a) * 8 + (b >> 1)) / b;
            else sub = 0;
            c1 -= sub;
            c2 -= sub;
            if (c1 < 0) c1 = 0;
            if (c2 < 0) c2 = 0;
        }
        if (i / (n1 / (l1 * 2)) & 1) c2--;
        if (c1 <= 2) c2 = c1;
        if (c1 == 8 && c2 == 9) c2 = 8;
        v = c2;
        v <<= 8;
        v += c1;
        B000758c4_j7[i] = v;
        if (c1 > 8) c1 = 8;
        if (i >= 0x46 && i < 0xc6) DAT_0005fe4e[i] = c1;
        if (i >= 0x32 && i < 0xb2) DAT_0005fe14[0x7f - (i - 0x32)] = c1;
    }
    DAT_0005fcfa = v;
}

/* ---- from build/var/mod/parts/p41c58.c */
/* FUN_00041c58 @ 00041c58: build the fog shading table for fog density p: clear near band, solid fog far band, a linear ramp between (dithered pairs), and the matching floor/ceiling fade bytes */
extern int DAT_0005c730; extern unsigned char DAT_0005f918; extern short *B000758c4_j7; extern unsigned short DAT_0005fcfa;
extern signed char DAT_0005fe14[], DAT_0005fe94[];
void FUN_00041c58(int p)
{
    int a, b, i, n1, v, a1, s, t, u; signed char c1, c2;
    a = 3;
    b = 4;
    a1 = a + 1;
    n1 = DAT_0005c730 + 1;
    s = b * 0x1e + p * 5;
    t = s * 3 - p * 5;
    u = DAT_0005c730 + 1 - s - t;
    DAT_0005f918 = a;
    for (i = 0; i < DAT_0005c730 + 1; i++) {
        if (i < s) c1 = 0;
        else if (DAT_0005c730 + 1 - t <= i) c1 = 9;
        else c1 = ((i - s) * 8 + 8 + (u >> 1)) / u;
        if (c1 < 0) c1 = 0;
        c2 = c1;
        if (c1 > 9) c1 = 9;
        if (c2 > 9) c2 = 9;
        if (i / (n1 / (a1 * 2)) & 1) c2--;
        if (c1 <= 2) c2 = c1;
        if (c1 == 8 && c2 == 9) c2 = 8;
        v = c2;
        v <<= 8;
        v |= c1;
        B000758c4_j7[i] = v;
    }
    DAT_0005fcfa = v;
    s = a * 5;
    t = s * 3;
    u = 0x81 - s - t;
    for (i = 0; i < 0x80; i++) {
        if (i < s) c1 = 0;
        else if (0x81 - t <= i) c1 = 8;
        else c1 = ((i - s + 1) * 7 + (u >> 1)) / u;
        if (c1 > 8) c1 = 8;
        DAT_0005fe94[i] = c1;
        DAT_0005fe14[0x7f - i] = c1;
    }
}

/* ---- from build/var/mod/parts/p41e74.c */
/* FUN_00041e74 @ 00041e74: 8 if a living party member carries a light (status bits 0x402), else 0; debug-info module */
extern unsigned char B000718e0_iO[];
#define B00071a12_dx ((unsigned short *)((char *)&B000718e0_iO + 306)) /* STANDIN: view, B000718e0_iO + 0x132 */
#define B000718f0_hO ((unsigned short *)((char *)&B000718e0_iO + 16)) /* STANDIN: view, B000718e0_iO + 0x10 */

int FUN_00041e74(void)
{
    int i, r;
    r = 0;
    for (i = 0; i < 4; i++) {
        if (*(unsigned short *)((char *)B000718f0_hO + i * 0x248) >= 0x4000) continue;
        if (*(unsigned *)((char *)B00071a12_dx + i * 0x248) & 0x402) r = 8;
    }
    return r;
}

/* ---- from build/var/mod/parts/p41edc.c */
/* FUN_00041edc, FUN_00041f38: music volume / sound volume setters (this module looks unoptimised) */
extern int FUN_00041e74(void); extern void FUN_00041a14(int, int);
extern int DAT_0005f91c, DAT_0005f920;
void FUN_00041edc(int v)
{
    DAT_0005f920 = v;
    if (DAT_0005f920 > 10) DAT_0005f920 = 10;
    if (DAT_0005f920 < 0) DAT_0005f920 = 0;
    FUN_00041a14(DAT_0005f920, FUN_00041e74() + DAT_0005f91c);
}

/* ---- from build/var/mod/parts/p41f38.c */
void FUN_00041f38(int v)
{
    DAT_0005f91c = v;
    if (DAT_0005f91c > 8) DAT_0005f91c = 8;
    if (DAT_0005f91c < 0) DAT_0005f91c = 0;
    FUN_00041a14(DAT_0005f920, FUN_00041e74() + DAT_0005f91c);
}

/* ---- from build/var/mod/parts/p41f94.c */
/* FUN_00041f94 @ 00041f94: hourly update of the outdoor sky: wrap the game clock's hour, and on a new hour set the sky picture (night, or a random cloud set by day), its palette and the ambient light; debug-info module */
extern unsigned DAT_0005cf4c; extern int DAT_0005f9cc, DAT_0005f910, DAT_0005f914, DAT_0005f920, DAT_0005f91c;

extern short DAT_0005f924[]; extern unsigned short DAT_0005f99a[], DAT_0005f96a[];
extern int FUN_00040700(void), FUN_00041e74(void); extern void srand(unsigned), FUN_00041a14(int, int);
void FUN_00041f94(void)
{
    unsigned short *p; unsigned short h;
    h = DAT_0005cf4c >> 16;
    if (h == 0xffff) h = 0x17;
    h = h % 0x18;
    DAT_0005cf4c = ((unsigned)h << 16) + (DAT_0005cf4c & 0xffff);
    if (h != DAT_0005f9cc) {
        if (B00075618_b1.solo != 0xff) {
            p = ((unsigned short **)B0007b764_fp)[B00075618_b1.solo];
            if (DAT_0005f924[h] < 10) {
                p[0] = 0x18;
                DAT_0005f910 = -1;
            } else if (DAT_0005f910 == -1) {
                srand(FUN_00040700());
                DAT_0005f910 = DAT_0005f914;
                p[0] = DAT_0005f910;
                DAT_0005f914 = (DAT_0005f914 + 1) % 8;
            }
            p[1] = DAT_0005f99a[h];
            p[3] = DAT_0005f96a[h];
            DAT_0005f920 = DAT_0005f924[h];
            FUN_00041a14(DAT_0005f920, FUN_00041e74() + DAT_0005f91c);
        }
        DAT_0005f9cc = h;
    }
}

/* ---- module data _DATA 0005f910-0005f9d0 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
int DAT_0005f910 = -1;
int DAT_0005f914 = 0;
unsigned char DAT_0005f918 = 0;
unsigned char DAT_0005f919[3] = { 0x73, 0x74, 0x28 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005f91c = 0;
int DAT_0005f920 = 0;
short DAT_0005f924[24] = { 10, 10, 10, 10, 10, 10, 10, 9, 8, 7, 5, 4, 2, 1, 0, 1, 2, 4, 5, 7, 8, 9, 10, 10 };
short DAT_0005f954[11] = { 9, 9, 8, 7, 7, 6, 6, 6, 5, 5, 5 };
unsigned short DAT_0005f96a[24] = {
    0x19, 0xffea, 0xffba, 0xffea, 0x19, 0x49, 0x78, 0x78, 0x5d, 0x42, 0x27, 0xc, 0xfff1, 0xffd6, 0xffba, 0xffd6,
    0xfff1, 0xc, 0x27, 0x42, 0x5d, 0x78, 0x78, 0x49
};
unsigned short DAT_0005f99a[25] = {
    0x2d, 0x2d, 0x2d, 0xe1, 0xe1, 0xe1, 0xe1, 0, 0, 0, 0, 0, 0, 0, 0, 0xb4,
    0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0x2d, 0x2d
};
int DAT_0005f9cc = -1;
/* ---- end of module data _DATA */
