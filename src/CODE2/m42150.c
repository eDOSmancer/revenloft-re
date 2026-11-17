/* Module: FUN_00042150, FUN_00042220, FUN_000422ec, FUN_000423bc, FUN_00042404, FUN_00042468, FUN_000424cc,
   FUN_000424f8, FUN_00042588, FUN_000425b0 */
/* ---- from build/var/mod/parts/p42150.c */
/* FUN_00042150 @ 00042150: brighten the 256-colour palette by the light level of the current area (0..63), keeping each colour's hue */
extern char *DAT_0005f050;
void FUN_00042150(unsigned char *pal)
{
    int lvl, k, j, max, s, half; unsigned char *p;
    lvl = *(unsigned char *)(DAT_0005f050 + 0x6c);
    if (lvl > 0x3f) lvl = 0x3f;
    if (lvl < 0) lvl = 0;
    if (lvl == 0) return;
    for (k = 0; k <= 0xff; k++) {
        p = pal + k * 3;
        max = 0;
        for (j = 0; j < 3; j++) if (p[j] > max) max = p[j];
        s = 0x3f - max;
        s = (lvl * s + 0x1f) / 0x3f + max;
        half = max >> 1;
        for (j = 0; j < 3; j++) if (s && p[j]) p[j] = (p[j] * s + half) / max;
    }
}

/* ---- from build/var/mod/parts/p42220.c */
extern void FUN_00042468(unsigned char *pal, int first, int n, int mul, int sh, unsigned char *target); /* module prototype */
/* FUN_00042220: matched 2026-11-10 (s = 7 before the length/offset temporaries: the counter is live there in the original, so ebx is taken and the temporaries get ebp) */
#include <string.h>
extern unsigned char DAT_0005f9d0[];
extern void FUN_00039234(unsigned char *), FUN_0003f83c(void), FUN_0003f844(void);
/* FUN_00042220 @ 00042220: fade palette entries from..to of pal towards the colour (r, g, b) in eight steps */
void FUN_00042220(unsigned char *pal, int from, int to, unsigned char r, unsigned char g, unsigned char b)
{
    int n3; int s; unsigned char *src; unsigned char c[3]; unsigned char *dst;
    c[0] = r;
    c[1] = (int)g;
    c[2] = b;
    to = to - from + 1;
    memcpy(DAT_0005f9d0, pal, 0x300);
    s = 7;
    n3 =3 *  to;
    dst = DAT_0005f9d0 + from * 3;
    src = pal + from * 3;
    for (;0 <=  s; s--) {
        FUN_00042468(DAT_0005f9d0, from, to, s, 3, c);
        FUN_00039234(DAT_0005f9d0);
        memcpy(dst, src, n3);
    }
    FUN_0003f83c();
}

/* ---- from build/var/mod/parts/p422ec.c */
extern void FUN_00042468(unsigned char *pal, int first, int n, int mul, int sh, unsigned char *target); /* module prototype */
/* FUN_000422ec: matched 2026-11-10 (k = 1 before the length/offset temporaries, as in FUN_00042220) */
/* FUN_000422ec @ 000422ec: flash palette entries first..last towards colour (r, g, b) in 8 steps, restoring them after each step */
#include <string.h>
extern unsigned char DAT_0005f9d0[0x300];
extern void FUN_00039234(unsigned char *), FUN_0003f844(void);
void FUN_000422ec(unsigned char *pal, int first, int n, unsigned char r, unsigned char g, unsigned char b)
{
    unsigned char col[3]; int k; unsigned char *src; int len; unsigned char *dst;
    col[0] = r;
    col[1] = (int)g;
    col[2] = (int)b;
    n = n - first + 1;
    memcpy((int)DAT_0005f9d0, pal, 0x300);
    k = 1;
    len = n * 3;
    dst = DAT_0005f9d0 + first * 3;
    src = pal + first * 3;
    for (;k <= 8; k =k + 1) {
        FUN_00042468(DAT_0005f9d0, first, n, k, 3, col);
        FUN_00039234(DAT_0005f9d0);
        memcpy(dst, src, len);
    }
    FUN_0003f844();
}

/* ---- from build/var/mod/parts/p423bc.c */
/* FUN_000423bc @ 000423bc: copy n palette entries (3 bytes each) from src[si] to dst[di] */
#include <string.h>
void FUN_000423bc(char *dst, int di, char *src, int si, int n)
{
    memcpy(dst + di * 3, src + si * 3, n * 3);
}



/* FUN_00042404 @ 00042404: set n palette entries from pal[start] on to the colour (r, g, b) */
void FUN_00042404(char *pal, int start, char r, char g, char b, int n)
{
    char c[3]; int i;
    c[0] = r;
    c[1] = g;
    c[2] = b;
    pal += start * 3;
    for (i = 0; i < n; i++) {
        memcpy(pal, c, 3);
        pal += 3;
    }
}

/* ---- from build/var/mod/parts/p42468.c */
/* Matched 2026-11-11 (tie round, found with the 2002 instrument tools/ow1cc.sh, confirmed with 10.0a): pal itself is the pointer and mul is used directly, no local copies. */
void FUN_00042468(unsigned char *pal, int first, int n, int mul, int sh, unsigned char *target)
{
    int k, j;
    pal += first * 3;
    for (k = 0; k < n; k++)
        for (j = 0; j < 3; j++, pal++) *pal = target[j] + (((*pal - target[j]) * mul) >> sh);
}

/* ---- from build/var/mod/parts/p424cc.c */
extern void FUN_00042404(char *pal, int start, char r, char g, char b, int n); /* module prototype */
#include <string.h>
extern unsigned char DAT_0005f9d0[];
extern void FUN_00039234(unsigned char *), FUN_0003f83c(void);
/* FUN_000424cc @ 000424cc: black out the whole working palette and show it */
void FUN_000424cc(void)
{
    FUN_00042404(DAT_0005f9d0, 0, 0, 0, 0, 0x100);
    FUN_00039234(DAT_0005f9d0);
    FUN_0003f83c();
}

/* ---- from build/var/mod/parts/p424f8.c */
#include <string.h>
/* FUN_000424f8 @ 000424f8: rotate the n palette entries starting at pal[a + b] down by one (colour cycling) */
void FUN_000424f8(unsigned char *pal, int a, int b, int n)
{
    unsigned char t[3]; unsigned char *p;
    if (n > 1) {
        p = pal + a * 3 + b * 3;
        n = n * 3 - 3;
        memcpy(t, p, 3);
        memcpy(p, p + 3, n);
        memcpy(p + n, t, 3);
    }
}

/* ---- from build/var/mod/parts/p42588.c */
/* FUN_00042588 @ 00042588 */
extern int FUN_000412a0(const char *); extern void FUN_0003f580(const char *);

int FUN_00042588(const char *name)
{
    int h = FUN_000412a0(name);
    if (h == -1) FUN_0003f580("Unable to open palette file");
    return h;
}

/* ---- from build/var/mod/parts/p425b0.c */
extern void FUN_00042150(unsigned char *pal); /* module prototype */
extern int FUN_00042588(const char *name); /* module prototype */
#define FUN_00042588 ((int (*)(int))FUN_00042588)
/* FUN_000425b0 @ 000425b0: read n palette entries at index idx from a palette file into buf+off */
 extern void FUN_0004131c(int, int, int); extern int FUN_000412ec(void *, unsigned, int);  extern void FUN_000412dc(int);
void FUN_000425b0(char *buf, int off, int idx, int name, int n)
{
    int h = FUN_00042588(name);
    FUN_0004131c(idx * 768 + 1, 1, h);
    FUN_000412ec(buf + off * 3, n * 3, h);
    FUN_00042150(buf);
    FUN_000412dc(h);
}

#undef FUN_00042588

/* ---- module data _DATA 0005f9d0-0005fcd0 (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
unsigned char DAT_0005f9d0[768] = { 0 };
/* ---- end of module data _DATA */
