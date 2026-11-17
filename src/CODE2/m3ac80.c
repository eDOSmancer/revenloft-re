/* Debug-info module 0003ac70.. (-3s -d2 -oe -s; the 16 zero bytes at 0003ac70 are the module's const for FUN_0003c294's int r[4] = {0}): FUN_0003ac80 .. FUN_0003c294 in address order (FUN_0003b2f4 and FUN_0003b6d0 matched 2026-11-10: the original adds to e->h with +=, which evaluates the term first and adds into the register of e->h; "e->h = e->h + x" in either operand order adds into the term register); built with -ot ahead of -d2 (lea for index scaling); -oe inlines FUN_0003acdc and FUN_0003ac80 into later functions (only in statement-level ifs) */

#include "world.h"
struct DE { short f0; unsigned short dist; unsigned short h; short idx, kind, fa, f0c, f0e, f10, f12, f14; };
struct MO { int a, b; unsigned char f8, f9, fa, fb; unsigned short cell, type; short timer, w12; unsigned short lo : 6, frame : 3, rest : 7; };
struct CELL { unsigned short lo : 6, seen : 1, rest : 9; };
extern struct DE DAT_00077148[]; extern void *DAT_00072230; extern struct MO DAT_00072238[]; extern struct CELL DAT_000698e0[];
 extern int DAT_0005c050; extern unsigned char DAT_0005c02d;
extern void FUN_00045798(int, int, void *, unsigned short *), FUN_0003b2f4(void *, void *, int, int, int), FUN_0003b088(int, int), FUN_00031bf0(void *, int);
int rand(void);
extern short DAT_00077106;

extern int FUN_000469a7(int); /* abs */
struct O { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, fb2 : 6; unsigned short s, type; short timer, w12; unsigned short w14; };
extern struct O DAT_00064d80[];  extern int DAT_000755d0, DAT_000755d4;

int FUN_0003ac80(int t)
{
    if (t == 0x52) return 1;
    if (t == 0x71) return 1;
    if (t == 0x6e) return 1;
    if (t == 0x91) return 1;
    return 0;
}

int FUN_0003acdc(int t)
{
    if (t < 0x22) return 1;
    if (t == 0x50) return 1;
    return 0;
}

extern int FUN_0002c1dc(int);
int FUN_0003ad18(int t)
{
    if (t == 0x3b) {
        if (FUN_0002c1dc(0x48)) return 0;
        if (FUN_0002c1dc(0x35)) return 1;
    } else if (t == 0x3c) {
        if (FUN_0002c1dc(0x48)) return 0;
        if (FUN_0002c1dc(0x36)) return 1;
    } else if (t == 0x3a) return 0;
    else if (t >= 0x22 && t <= 0x46) return 1;
    else if (t == 0x52) return 1;
    return 0;
}

int FUN_0003ade0(int t)
{
    if (t >= 0x48 && t <= 0x4a) return 1;
    if (t == 0x4d) return 1;
    if (t == 0x4f) return 1;
    return 0;
}

extern unsigned char DAT_0005d680; extern unsigned short DAT_0005f038[];
extern int FUN_0003ad18(int), FUN_0003ade0(int);
struct DE2 { short f0; unsigned short dist; unsigned short h, idx, kind, fa, f0c, f0e, f10, f12, f14; };
struct SO2 { int a, b; unsigned char f8, f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short w14; };
/* FUN_0003ae30 @ 0003ae30: what the cursor at (x, y) in the 3-D view points at: 2 talk/attack target, 1 person, 0 nothing */
int FUN_0003ae30(int x, int y)
{
    int i, t; struct DE2 *e;
    if (DAT_0005d680) return 0;
    e = (struct DE2 *)((char *)DAT_00077148 + (DAT_0005c050 ^ 1) * 0x2260);
    for (i = 0; i < DAT_0005f038[DAT_0005c050 ^ 1]; i++) {
        if (e[i].kind == 0) {
            if (FUN_0003acdc(DAT_00064d80[e[i].idx].type)) {
                if ((int)(e[i].dist - 0x7d00) >> 3 < 0x39) continue;
            }
        }
        if ((e[i].f0e <= x && e[i].f10 >= x) && (e[i].f12 <= y && e[i].f14 >= y)) {
            if (e[i].kind == 0) {
                t = DAT_00064d80[e[i].idx].type;
                if (FUN_0003ad18(t) || FUN_0003ade0(t)) return 2;
                if (FUN_0003acdc(t)) return 1;
            } else if (e[i].kind == 1) {
                t = ((struct SO2 *)DAT_00072238)[e[i].idx].type;
                if (FUN_0003ac80(t)) return 2;
            }
        }
    }
    return 0;
}

struct W { int w[5]; int cell, val; };
extern struct W DAT_00065a18[]; extern short DAT_00077108[], DAT_00077128[];
void FUN_0003b088(int n, int c)
{
    int last, j, i, v;
    last = -1;
    for (i = 0; i < 0x100; i++) {
        if (last != DAT_00065a18[i].cell) {
            last = DAT_00065a18[i].cell;
            v = DAT_00065a18[i].val;
            if (last == c) v += n;
            else {
                if (n > 1) {
                    for (j = 0; j < 8; j++) {
                        if (DAT_00077108[j] + c == last) { v += n - 1; break; }
                    }
                }
                if (n == 3) {
                    for (j = 0; j < 16; j++) {
                        if (DAT_00077128[j] + c == last) { v++; break; }
                    }
                }
            }
        }
        DAT_00065a18[i].val = v;
    }
}

int FUN_0003b188(int t)
{
    if (t >= 0x3c && t <= 0x43) return 1;
    return 0;
}

int FUN_0003b1bc(void)
{
    {
        int i, best, d;
        best = 0xf;
        for (i = 0; i < DAT_00075618.nent; i++) {
            if (DAT_00064d80[i].dead) continue;
            if (DAT_00064d80[i].type == 8) continue;
            if (FUN_0003acdc(DAT_00064d80[i].type)) {
                d = FUN_000469a7(DAT_00064d80[i].b - DAT_000755d0) > FUN_000469a7(DAT_00064d80[i].a - DAT_000755d4) ? FUN_000469a7(DAT_00064d80[i].b - DAT_000755d0) : FUN_000469a7(DAT_00064d80[i].a - DAT_000755d4);
                d += 0x8000;
                d >>= 16;
                if (d < best) best = d;
            }
        }
        return best;
    }
}

struct OB { int a, b; unsigned char f8, f9, fa, fb; unsigned short cell, type; short timer, w12; unsigned short lo1 : 1, st : 2, face : 3, rest : 10; };
struct DE3 { unsigned short f0, dist, h; short idx, kind, fa, f0c, f0e, f10, f12, f14; };
extern short DAT_0007b608[], DAT_0007b61c[], DAT_00077100[]; extern int DAT_0005c6d0, DAT_0005c658;
/* FUN_0003b2f4 @ 0003b2f4: choose the frame of sprite e for object o of draw kind k, type t, with nf direction frames (groups of three scenery pieces share one direction) */
void FUN_0003b2f4(void *o_p, void *e_p, int k, int t, int nf)
{
#define o ((struct OB *)o_p)
#define e ((struct DE3 *)e_p)
    int a, g, s, isg, tmp;
    g = (t - 2) / 3;
    s = (t - 2) % 3;
    if (g >= 0 && g < 10) isg = 1;
    else isg = 0;
    if (k == 1 && (isg && s > 0)) {
        a = DAT_0005c6d0 - DAT_0007b608[g];
        a /= 8;
        a += DAT_0005c658;
        a = a - 0xb4 + ((struct OB *)DAT_00072238)[DAT_0007b61c[g]].face * 0x2d;
    } else {
        a = DAT_0005c6d0 - e->f0;
        a /= 8;
        a += DAT_0005c658;
        a = a - 0xb4 + o->face * 0x2d;
    }
    if (k == 1 && (isg && s == 0)) DAT_0007b608[g] = e->f0;
    if (nf == 0x10) {
        a += 0x16;
        a -= 16 / nf * 0xb;
        while (a >= 0x168) a += -0x168;
        while (a < 0) a += 0x168;
        a = a * 10 / 0xe1 % 16;
        if (k == 1 && FUN_0003b188(t)) {
            if (a < 8) e->h += a % 8;
            else e->h += 7 - a % 8;
        } else e->h += a % 8;
    } else if (nf == 2) {
        a += 0x16;
        while (a >= 0x168) a += -0x168;
        while (a < 0) a += 0x168;
        a = a / 0x2d % 8;
        e->h += a % 2;
    } else {
        a += 0x2c;
        a -= 8 / nf * 0x16;
        while (a >= 0x168) a += -0x168;
        while (a < 0) a += 0x168;
        a = a / 0x2d % 8;
        if (o->st == 1 || o->st == 2) {
            if (k != 0 || o->type != 0x21) {
                tmp = a / (8 / nf) % 5;
                tmp %= 3;
                e->h += tmp;
            }
        } else if (!o->st) e->h += a / (8 / nf);
    }
    e->h += DAT_00077100[k];
}
#undef o
#undef e
#undef o
#undef e

struct OC { int a, b; unsigned char f8, f9, fa; unsigned char fb0 : 1, dead : 1, big : 1, tab : 1, fb4 : 4; unsigned short cell, type; short timer, w12; unsigned short b0 : 1, st : 2, b3 : 3, fr : 3, b9 : 5, top : 2; };
#pragma pack(1)
struct TY { unsigned char p0[0x14]; unsigned short w14; unsigned char p16[2]; unsigned char f18, f19, f1a, f1b, f1c; unsigned char p1d[0xa]; unsigned short w27; unsigned char tab[0x1c]; };
#pragma pack()
/* the module declares DAT_00072230 as void * (cast view, recipe 29) */
#define DAT_00072230 (*(struct TY **)&DAT_00072230)
extern short DAT_00077100[];
int rand(void); void srand(unsigned); extern unsigned FUN_00040700(void);
/* FUN_0003b6d0 @ 0003b6d0: put the visible creatures into draw list slot n onwards (frame from type, state and animation), return the next free slot */
int FUN_0003b6d0(int n)
{
    int z, i; unsigned char *q; struct DE *e; struct OC *o; struct TY *ty;
    z = 0;
    for (i = 0; i < DAT_00075618.nent; i++) {
        if (((struct OC *)DAT_00064d80)[i].dead) continue;
        e = (struct DE *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + n;
        o = (struct OC *)DAT_00064d80 + i;
        ty = DAT_00072230 + o->type;
        if (DAT_000698e0[o->cell].seen) {
            if (o->dead) continue;
            e->h = ty->w14;
            if (o->type == 8) {
                if (o->top == 3) e->h += (o->fr + 0xc);
                else switch (o->st) {
                case 3:
                    e->h += (((unsigned)rand() * 2 >> 15) + 0xa);
                    break;
                case 1:
                case 2:
                    e->h += (o->top * 2 + 4 + (o->st - 1));
                    break;
                case 0:
                    e->h += o->fr;
                    break;
                }
            } else if (o->st == 3) {
                e->h += ty->f19 * ty->f18;
                srand(i);
                e->h += ((unsigned)rand() * 2 >> 15) * (ty->f1a + 1);
                e->h += ty->f1a;
                e->h += DAT_00077100[0];
                srand(FUN_00040700());
            } else if (o->st) {
                e->h += ty->f19 * ty->f18;
                e->h += (ty->f1a + ty->f1c) * (o->st - 1);
            } else if (o->tab) {
                q = ty->tab;
                e->h += q[o->fr] * ty->f18;
            } else if (o->big) {
                if (o->type == 0x51) e->h += (ty->f19 * o->top + o->fr);
                else e->h += ty->f18 * o->fr;
            } else e->h += ty->f18 * o->fr;
            FUN_00045798(o->a, o->b, e, &e->dist);
            e->f0e = 0;
            e->f10 = 0;
            e->f12 = 0;
            e->f14 = 0;
            if (e->dist > DAT_0005c02d) {
                e->f0e = 0;
                e->f10 = 0;
                e->f12 = 0;
                e->f14 = 0;
                e->f0c = ty->w27;
                if (e->dist != 0) {
                    if (n != 400) n++;
                    if (o->st != 3) FUN_0003b2f4(o, e, 0, o->type, ty->f18);
                    if (ty->f1b) FUN_0003b088(ty->f1b, o->cell);
                    e->kind = 0;
                    e->idx = i;
                    e->dist += 0x7d00;
                    FUN_00031bf0(e, 0x28);
                    e->f12 += 0x20;
                    e->f14 += 0x20;
                    e->dist -= 0x7d00;
                }
            }
        }
    }
    return n;
}
#undef DAT_00072230

int FUN_0003bba0(int n)
{
    int i; struct DE *e; struct MO *o;
    for (i = 0; i < DAT_00075618.ndoor; i++) {
        e = (struct DE *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + n;
        o = DAT_00072238 + i;
        if (DAT_000698e0[o->cell].seen) {
            e->h = DAT_000755dc[o->type * 7 + 4] * o->frame;
            e->h += *(unsigned short *)(DAT_000755dc + o->type * 7);
            e->f0c = 0;
            FUN_00045798(o->a, o->b, e, &e->dist);
            e->f0e = 0;
            e->f10 = 0;
            e->f12 = 0;
            e->f14 = 0;
            if (e->dist != 0 && e->dist > DAT_0005c02d) {
                if (FUN_0003ac80(o->type)) {
                    e->dist += 0x7d00;
                    FUN_00031bf0(e, 0x28);
                    e->f12 += 0x20;
                    e->f14 += 0x20;
                    e->dist -= 0x7d00;
                }
                if (n != 400) n++;
                FUN_0003b2f4(o, e, 1, o->type, DAT_000755dc[o->type * 7 + 4]);
                if (DAT_000755dc[o->type * 7 + 6]) FUN_0003b088(DAT_000755dc[o->type * 7 + 6], o->cell);
                e->kind = 1;
                e->idx = i;
            }
        }
    }
    return n;
}

/* FUN_0003bdf4 @ 0003bdf4: add the visible items lying on the floor to the draw list from entry n on; returns the next free entry; debug-info module */
struct DEI { short f0; unsigned short dist; short h, idx, kind, fa, f0c, f0e, f10, f12, f14; };
struct MOI { int a, b; unsigned char f8, f9, fa, fb; unsigned short cell, item; short timer, w12; unsigned short lo : 6, frame : 3, rest : 7; };
extern struct MOI DAT_00067618[];
 
int FUN_0003bdf4(int n)
{
    int i; struct DEI *e; struct MOI *o;
    for (i = 0; i < DAT_00075618.n4; i++) {
        e = (struct DEI *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + n;
        o = DAT_00067618 + i;
        if (DAT_000698e0[o->cell].seen) {
            e->h = ((unsigned char *)DAT_000755d8)[o->item * 0x41 + 0x2a] * o->frame;
            e->h += *(short *)(((unsigned char *)DAT_000755d8) + o->item * 0x41 + 0x28);
            e->f0c = 0;
            FUN_00045798(o->a, o->b, e, &e->dist);
            e->f0e = 0;
            e->f10 = 0;
            e->f12 = 0;
            e->f14 = 0;
            if (e->dist != 0 && e->dist > DAT_0005c02d) {
                if (n != 400) n++;
                FUN_0003b2f4(o, e, 2, o->item, ((unsigned char *)DAT_000755d8)[o->item * 0x41 + 0x2a]);
                if (((unsigned char *)DAT_000755d8)[o->item * 0x41 + 0x2b]) FUN_0003b088(((unsigned char *)DAT_000755d8)[o->item * 0x41 + 0x2b], o->cell);
                e->kind = 2;
                e->idx = i;
                e->dist += 0x7d00;
                FUN_00031bf0(e, 0x28);
                e->f12 += 0x20;
                e->f14 += 0x20;
                e->dist -= 0x7d00;
            }
        }
    }
    return n;
}

/* FUN_0003bfec @ 0003bfec: add the visible projectiles to the draw list from entry n on (flames flicker); returns the next free entry; debug-info module */
extern struct MO DAT_000748ec[];
extern int DAT_0005c038; extern unsigned char *DAT_00072234;
int FUN_0003bfec(int n)
{
    int i; struct DE *e; struct MO *o;
    for (i = 0; i < DAT_0005c038; i++) {
        e = (struct DE *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + n;
        o = DAT_000748ec + i;
        if (DAT_000698e0[o->cell].seen) {
            e->h = DAT_00072234[o->type * 7 + 4] * o->frame;
            e->h += *(unsigned short *)(DAT_00072234 + o->type * 7);
            e->f0c = 0;
            FUN_00045798(o->a, o->b, e, &e->dist);
            if (e->dist != 0 && e->dist > DAT_0005c02d) {
                if (n != 400) n++;
                FUN_0003b2f4(o, e, 3, o->type, DAT_00072234[o->type * 7 + 4]);
                if (o->type == 0 || o->type == 3 || o->type == 4 || o->type == 7) {
                    if (e->h == *(unsigned short *)(DAT_00072234 + o->type * 7) + 4 + DAT_00077106) {
                        if ((int)((unsigned)rand() * 10 >> 15) > 5) e->h = *(unsigned short *)(DAT_00072234 + o->type * 7) + 8 + DAT_00077106 + ((unsigned)rand() * 2 >> 15);
                    }
                }
                if (DAT_00072234[o->type * 7 + 6]) FUN_0003b088(DAT_00072234[o->type * 7 + 6], o->cell);
                e->kind = 3;
                e->idx = i;
            }
        }
    }
    return n;
}

/* FUN_0003c230 @ 0003c230: screen x of a creature label for distance d (only inlined, the copy stays) */
int FUN_0003c230(int d)
{
    int r;
    d /= 2;
    r = 0x84 - d / 2 + d / 8;
    r += d / 2;
    return r;
}

struct DE5 { unsigned short f0, dist, h, idx, kind, fa, f0c, f0e, f10, f12, f14; };
struct O5 { int a, b; unsigned char f80 : 3, glow : 1, f84 : 4; unsigned char f9, fa, fb; unsigned short s, type; short timer, w12; unsigned short w14; };
struct IT5 { unsigned char f0; unsigned char b0 : 1, big : 1, b2 : 6; unsigned char rest[0x14]; };
struct TY5 { unsigned char pad[0x31]; unsigned char nolabel : 1, b1 : 7; unsigned char rest[0x13]; };
extern struct IT5 DAT_0006762c[]; extern char *DAT_000758dc; extern short DAT_0005f03c, DAT_0005f03e;
extern void *memset(void *, int, unsigned);
extern void FUN_000435dc(void), FUN_00039738(int *), FUN_000396c0(int, int, int, int), FUN_00046cec(int, int, int, int, int, int), FUN_0003978c(int, int, int, int, int);
/* FUN_0003c294 @ 0003c294: build and draw the 3-D view list: collect creatures, objects, items and missiles, then draw them farthest first (creature labels in the debug views) */
extern int FUN_0003b6d0(int);
void FUN_0003c294(void)
{
    int r[4] = { 0 };
    int best, k, bi; struct DE5 *e; int j;
    memset((char *)DAT_00077148 + DAT_0005c050 * 0x2260, 0, 0x1130);
    DAT_0005f038[DAT_0005c050] = 0;
    DAT_0005f038[DAT_0005c050] = FUN_0003b6d0(DAT_0005f038[DAT_0005c050]);
    DAT_0005f038[DAT_0005c050] = FUN_0003bba0(DAT_0005f038[DAT_0005c050]);
    DAT_0005f038[DAT_0005c050] = FUN_0003bdf4(DAT_0005f038[DAT_0005c050]);
    DAT_0005f038[DAT_0005c050] = FUN_0003bfec(DAT_0005f038[DAT_0005c050]);
    FUN_000435dc();
    if (DAT_0005f038[DAT_0005c050]) {
        if (DAT_0005f03c || DAT_0005f03e) {
            FUN_00039738(r);
            FUN_000396c0(4, 0x20, 0x103, 0x11f);
        }
        for (k = 0; k < DAT_0005f038[DAT_0005c050]; k++) {
            best = 0x7d00;
            j = 0;
            e = (struct DE5 *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260);
            while (j < DAT_0005f038[DAT_0005c050]) {
                if (e->dist < best) {
                    best = e->dist;
                    bi = j;
                }
                j++;
                e = (struct DE5 *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + j;
            }
            e = (struct DE5 *)((char *)DAT_00077148 + DAT_0005c050 * 0x2260) + bi;
            if (e->kind == 0 && DAT_00064d80[e->idx].type == 8) {
                FUN_00046cec(e->f0, e->h + 0x12, (e->dist * 0x78 + 0x6c) / 0xd8, e->f0c, 0x58, e->dist);
                FUN_00046cec(e->f0, e->h, (e->dist * 0x78 + 0x6c) / 0xd8, e->f0c, 0, e->dist);
            } else {
                if (e->kind == 1) {
                    if (FUN_0003b188(DAT_00072238[e->idx].type)) FUN_00046cec(e->f0, e->h + 8, e->dist, e->f0c, 0x58, e->dist);
                }
                if (e->kind == 2) {
                    if (DAT_0006762c[e->idx].big) FUN_00046cec(e->f0, e->h, e->dist, e->f0c, 0x3c, e->dist);
                    else FUN_00046cec(e->f0, e->h, e->dist, e->f0c, 0, e->dist);
                } else FUN_00046cec(e->f0, e->h, e->dist, e->f0c, 0, e->dist);
            }
            if (e->kind == 0) {
                if (((struct O5 *)DAT_00064d80)[e->idx].glow) FUN_00046cec(e->f0, DAT_00077106 + 0x41, e->dist, e->f0c, 0, e->dist);
            }
            if (DAT_0005f03c || DAT_0005f03e) if (e->kind == 0) if (DAT_00064d80[e->idx].type < 0x22) if (DAT_0005f03e || !((struct TY5 *)DAT_00072230)[DAT_00064d80[e->idx].type].nolabel)
                FUN_0003978c(0, FUN_0003c230(e->dist), e->f0 + 0x18, (int)(DAT_000758dc + 0x48), 0);
            e->fa = k;
            e->dist += 0x7d00;
        }
        if (DAT_0005f03c || DAT_0005f03e) FUN_000396c0(r[0], r[2], r[1], r[3]);
    }
}

/* ---- module data _DATA 0005f038-0005f040 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
unsigned short DAT_0005f038[2] = { 0 };
short DAT_0005f03c = 0;
short DAT_0005f03e = 0;
/* ---- end of module data _DATA */
