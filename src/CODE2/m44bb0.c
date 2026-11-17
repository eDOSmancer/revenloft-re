#include "farproc.h"
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
struct SD B0007b870_hl[32];
struct SD B0007b7f0_dN[32];
unsigned char B0007b7d0_ko[32];
unsigned char B0007b7b0_bn[32];
/* BSS end */
/* Module: FUN_00044bb0, FUN_00044de8 */
/* ---- from build/var/mod/parts/p44bb0.c */
/* FUN_00044bb0 @ 00044bb0: draw a wall decoration polygon for the four corner rows ys and distances ds (in 1/8 steps): front face, or the mirrored face when the decoration faces the other way */
#include "world.h"
struct PT { int x, y; };
struct WD { unsigned char f0; unsigned char b0 : 5, back : 1, b6 : 2; unsigned char f2[7]; unsigned char pic; };
extern int DAT_0005c738, B00065618_e1[], B000758f8_h3, DAT_0005fdb8, DAT_0005fdb4; extern char *DAT_0005fdc0;
extern unsigned char DAT_0005c026, DAT_0005c027;
extern char *FUN_0003f29c(int, int); extern void FUN_00043e6c(struct PT *);
void FUN_00044bb0(int *ys, int *ds, struct WD *w)
{
    struct PT p1[4], p2[4]; int i, h, c;
    for (i = 0; i < 4; i++) {
        ds[i] >>= 3;
        if (ds[i] > DAT_0005c738) ds[i] = DAT_0005c738;
        if (ds[i]) {
            h = B00065618_e1[ds[i]];
            c = h / 8 + 0x80;
            p1[i].y = ys[i];
            if (i & 1) p2[i ^ 2].y = ys[i];
            else p2[i].y = ys[i];
            p1[i].x = c + h / 2;
            if (i & 1) p2[i ^ 2].x = c - h / 2;
            else p2[i].x = c - h / 2;
        } else return;
    }
    if (!w->back) {
        if (DAT_0005c026) {
            DAT_0005fdc0 = FUN_0003f29c(w->pic + B000758f8_h3, 4);
            DAT_0005fdc0 += 2;
            DAT_0005fdb8 = 0x84;
            DAT_0005fdb4 = 0x103;
            FUN_00043e6c(p1);
        }
    } else if (DAT_0005c027) {
        DAT_0005fdc0 = FUN_0003f29c(w->pic + B000758f8_h3, 4);
        DAT_0005fdc0 += 2;
        DAT_0005fdb8 = 4;
        DAT_0005fdb4 = 0x83;
        FUN_00043e6c(p2);
    }
}

/* ---- from build/var/mod/parts/p44de8.c */
/* FUN_00044de8 @ 00044de8: draw the wall decorations around the party (30x30 squares): project the square corners row by row (two corner rows cached in B0007b7f0_dN/B0007b870_hl) and draw each decorated wall marker */
union FX { int v; struct { unsigned short f; short i; } s; };
struct SD { short y; unsigned short d; };
struct MK { unsigned char kind; unsigned char b0 : 3, b3 : 1, deco : 1, b5 : 3; };
extern struct SD B0007b7f0_dN[32], B0007b870_hl[32]; extern unsigned char B0007b7b0_bn[32], B0007b7d0_ko[32];
extern int B000755d0_ao, B000755d4_ak; 
extern void *memset(void *, int, unsigned), *memmove(void *, const void *, unsigned);
extern struct MK *FUN_0002e8c8(int, int); extern void FUN_00045798(int, int, short *, unsigned short *), FUN_00044bb0(int *, int *, void *);
void FUN_00044de8(void)
{
    int ys[4], ds[4], x0, y0, r, c, k, y1; union FX px, py; int x1; struct MK *p; char open;
    memset(B0007b7f0_dN, 0, 0x80);
    memset(B0007b870_hl, 0, 0x80);
    memset(B0007b7b0_bn, 0, 0x20);
    memset(B0007b7d0_ko, 0, 0x20);
    px.s.f = py.s.f = 0;
    x0 = ((short *)&B000755d0_ao)[1] - 0xf;
    x1 = ((short *)&B000755d0_ao)[1] + 0xf;
    y0 = ((short *)&B000755d4_ak)[1] - 0xf;
    y1 = ((short *)&B000755d4_ak)[1] + 0xf;
    if (x0 < 0) x0 = 0;
    if (x1 > B00075618_b1.w) x1 = B00075618_b1.w;
    if (y0 < 0) y0 = 0;
    if (y1 > B00075618_b1.h) y1 = B00075618_b1.h;
    for (r = x0; r < x1; r++) {
        open = 0;
        for (c = y0, k = 0; c < y1; c++, k++) {
            p = FUN_0002e8c8(r, c);
            if (p) {
                if (p->deco) {
                    if (p->kind == 3) {
                        if (!p->b3) continue;
                    }
                    if (!open) {
                        open = 1;
                        if (!B0007b7b0_bn[k]) {
                            px.s.i = c;
                            py.s.i = r;
                            FUN_00045798(px.v, py.v, &B0007b7f0_dN[k].y, &B0007b7f0_dN[k].d);
                            B0007b7f0_dN[k].y += 0x20;
                            B0007b7b0_bn[k] = 1;
                        }
                        px.s.i = c;
                        py.s.i = r + 1;
                        FUN_00045798(px.v, py.v, &B0007b870_hl[k].y, &B0007b870_hl[k].d);
                        B0007b870_hl[k].y += 0x20;
                        B0007b7d0_ko[k] = 1;
                    }
                    if (!B0007b7b0_bn[k + 1]) {
                        px.s.i = c + 1;
                        py.s.i = r;
                        FUN_00045798(px.v, py.v, &B0007b7f0_dN[k + 1].y, &B0007b7f0_dN[k + 1].d);
                        B0007b7f0_dN[k + 1].y += 0x20;
                        B0007b7b0_bn[k + 1] = 1;
                    }
                    px.s.i = c + 1;
                    py.s.i = r + 1;
                    FUN_00045798(px.v, py.v, &B0007b870_hl[k + 1].y, &B0007b870_hl[k + 1].d);
                    B0007b870_hl[k + 1].y += 0x20;
                    B0007b7d0_ko[k + 1] = 1;
                    if (B0007b7f0_dN[k].d && B0007b7f0_dN[k + 1].d && B0007b870_hl[k].d && B0007b870_hl[k + 1].d) {
                        ys[0] = B0007b7f0_dN[k].y;
                        ds[0] = B0007b7f0_dN[k].d;
                        ys[1] = B0007b7f0_dN[k + 1].y;
                        ds[1] = B0007b7f0_dN[k + 1].d;
                        ys[2] = B0007b870_hl[k + 1].y;
                        ds[2] = B0007b870_hl[k + 1].d;
                        ys[3] = B0007b870_hl[k].y;
                        ds[3] = B0007b870_hl[k].d;
                        FUN_00044bb0(ys, ds, p);
                    }
                } else open = 0;
            } else open = 0;
        }
        memmove(B0007b7f0_dN, B0007b870_hl, 0x80);
        memset(B0007b870_hl, 0, 0x80);
        memmove(B0007b7b0_bn, B0007b7d0_ko, 0x20);
        memset(B0007b7d0_ko, 0, 0x20);
    }
}

