/* Module: FUN_00044bb0, FUN_00044de8 */
/* ---- from build/var/mod/parts/p44bb0.c */
/* FUN_00044bb0 @ 00044bb0: draw a wall decoration polygon for the four corner rows ys and distances ds (in 1/8 steps): front face, or the mirrored face when the decoration faces the other way */
#include "world.h"
struct PT { int x, y; };
struct WD { unsigned char f0; unsigned char b0 : 5, back : 1, b6 : 2; unsigned char f2[7]; unsigned char pic; };
extern int DAT_0005c738, DAT_00065618[], DAT_000758f8, DAT_0005fdb8, DAT_0005fdb4; extern char *DAT_0005fdc0;
extern unsigned char DAT_0005c026, DAT_0005c027;
extern char *FUN_0003f29c(int, int); extern void FUN_00043e6c(struct PT *);
void FUN_00044bb0(int *ys, int *ds, struct WD *w)
{
    struct PT p1[4], p2[4]; int i, h, c;
    for (i = 0; i < 4; i++) {
        ds[i] >>= 3;
        if (ds[i] > DAT_0005c738) ds[i] = DAT_0005c738;
        if (ds[i]) {
            h = DAT_00065618[ds[i]];
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
            DAT_0005fdc0 = FUN_0003f29c(w->pic + DAT_000758f8, 4);
            DAT_0005fdc0 += 2;
            DAT_0005fdb8 = 0x84;
            DAT_0005fdb4 = 0x103;
            FUN_00043e6c(p1);
        }
    } else if (DAT_0005c027) {
        DAT_0005fdc0 = FUN_0003f29c(w->pic + DAT_000758f8, 4);
        DAT_0005fdc0 += 2;
        DAT_0005fdb8 = 4;
        DAT_0005fdb4 = 0x83;
        FUN_00043e6c(p2);
    }
}

/* ---- from build/var/mod/parts/p44de8.c */
/* FUN_00044de8 @ 00044de8: draw the wall decorations around the party (30x30 squares): project the square corners row by row (two corner rows cached in DAT_0007b7f0/DAT_0007b870) and draw each decorated wall marker */
union FX { int v; struct { unsigned short f; short i; } s; };
struct SD { short y; unsigned short d; };
struct MK { unsigned char kind; unsigned char b0 : 3, b3 : 1, deco : 1, b5 : 3; };
extern struct SD DAT_0007b7f0[], DAT_0007b870[]; extern unsigned char DAT_0007b7b0[], DAT_0007b7d0[];
extern int DAT_000755d0, DAT_000755d4; 
extern void *memset(void *, int, unsigned), *memmove(void *, const void *, unsigned);
extern struct MK *FUN_0002e8c8(int, int); extern void FUN_00045798(int, int, short *, unsigned short *), FUN_00044bb0(int *, int *, void *);
void FUN_00044de8(void)
{
    int ys[4], ds[4], x0, y0, r, c, k, y1; union FX px, py; int x1; struct MK *p; char open;
    memset(DAT_0007b7f0, 0, 0x80);
    memset(DAT_0007b870, 0, 0x80);
    memset(DAT_0007b7b0, 0, 0x20);
    memset(DAT_0007b7d0, 0, 0x20);
    px.s.f = py.s.f = 0;
    x0 = ((short *)&DAT_000755d0)[1] - 0xf;
    x1 = ((short *)&DAT_000755d0)[1] + 0xf;
    y0 = ((short *)&DAT_000755d4)[1] - 0xf;
    y1 = ((short *)&DAT_000755d4)[1] + 0xf;
    if (x0 < 0) x0 = 0;
    if (x1 > DAT_00075618.w) x1 = DAT_00075618.w;
    if (y0 < 0) y0 = 0;
    if (y1 > DAT_00075618.h) y1 = DAT_00075618.h;
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
                        if (!DAT_0007b7b0[k]) {
                            px.s.i = c;
                            py.s.i = r;
                            FUN_00045798(px.v, py.v, &DAT_0007b7f0[k].y, &DAT_0007b7f0[k].d);
                            DAT_0007b7f0[k].y += 0x20;
                            DAT_0007b7b0[k] = 1;
                        }
                        px.s.i = c;
                        py.s.i = r + 1;
                        FUN_00045798(px.v, py.v, &DAT_0007b870[k].y, &DAT_0007b870[k].d);
                        DAT_0007b870[k].y += 0x20;
                        DAT_0007b7d0[k] = 1;
                    }
                    if (!DAT_0007b7b0[k + 1]) {
                        px.s.i = c + 1;
                        py.s.i = r;
                        FUN_00045798(px.v, py.v, &DAT_0007b7f0[k + 1].y, &DAT_0007b7f0[k + 1].d);
                        DAT_0007b7f0[k + 1].y += 0x20;
                        DAT_0007b7b0[k + 1] = 1;
                    }
                    px.s.i = c + 1;
                    py.s.i = r + 1;
                    FUN_00045798(px.v, py.v, &DAT_0007b870[k + 1].y, &DAT_0007b870[k + 1].d);
                    DAT_0007b870[k + 1].y += 0x20;
                    DAT_0007b7d0[k + 1] = 1;
                    if (DAT_0007b7f0[k].d && DAT_0007b7f0[k + 1].d && DAT_0007b870[k].d && DAT_0007b870[k + 1].d) {
                        ys[0] = DAT_0007b7f0[k].y;
                        ds[0] = DAT_0007b7f0[k].d;
                        ys[1] = DAT_0007b7f0[k + 1].y;
                        ds[1] = DAT_0007b7f0[k + 1].d;
                        ys[2] = DAT_0007b870[k + 1].y;
                        ds[2] = DAT_0007b870[k + 1].d;
                        ys[3] = DAT_0007b870[k].y;
                        ds[3] = DAT_0007b870[k].d;
                        FUN_00044bb0(ys, ds, p);
                    }
                } else open = 0;
            } else open = 0;
        }
        memmove(DAT_0007b7f0, DAT_0007b870, 0x80);
        memset(DAT_0007b870, 0, 0x80);
        memmove(DAT_0007b7b0, DAT_0007b7d0, 0x20);
        memset(DAT_0007b7d0, 0, 0x20);
    }
}

