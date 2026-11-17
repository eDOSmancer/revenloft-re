/* Module: FUN_000390d0, FUN_000390f4, FUN_000391b0, FUN_000391c8, FUN_000391e0, FUN_00039208, FUN_00039234,
   FUN_00039248, FUN_00039264, FUN_00039280, FUN_0003929c, FUN_000392ac, FUN_000392bc, FUN_0003932c,
   FUN_0003939c, FUN_000393c0, FUN_000393ec, FUN_00039414, FUN_00039564, FUN_000396c0, FUN_00039738,
   FUN_0003975c, FUN_0003978c, FUN_000397d0, FUN_00039804, FUN_00039838, FUN_0003986c, FUN_000398b4,
   FUN_000398f0 */
/* STANDIN: fields of a packed record that the sources name on their own (tools/data2c.py --pack): declared as
   their bytes, which the compiler does not align, and read through a cast */
extern unsigned char DAT_0005ef3f[2];
extern unsigned char DAT_0005ef41[2];
extern unsigned char DAT_0005ef43[2];
extern unsigned char DAT_0005ef45[2];
extern unsigned char DAT_0005ef47[2];
extern unsigned char DAT_0005ef55[4];
extern unsigned char DAT_0005ef59[4];
extern unsigned char DAT_0005ef5d[4];
extern unsigned char DAT_0005ef61[4];
extern unsigned char DAT_0005ef69[2];
extern unsigned char DAT_0005ef6b[2];
extern unsigned char DAT_0005ef6d[2];
extern unsigned char DAT_0005ef6f[2];
#define DAT_0005ef3f (*(short *)DAT_0005ef3f)
#define DAT_0005ef41 (*(short *)DAT_0005ef41)
#define DAT_0005ef43 (*(short *)DAT_0005ef43)
#define DAT_0005ef45 (*(short *)DAT_0005ef45)
#define DAT_0005ef47 (*(short *)DAT_0005ef47)
#define VIEW_DAT_0005ef55 (*(int *)DAT_0005ef55)
#define DAT_0005ef55 VIEW_DAT_0005ef55
#define DAT_0005ef59 (*(int *)DAT_0005ef59)
#define DAT_0005ef5d (*(int *)DAT_0005ef5d)
#define DAT_0005ef61 (*(int *)DAT_0005ef61)
#define DAT_0005ef69 (*(short *)DAT_0005ef69)
#define DAT_0005ef6b (*(short *)DAT_0005ef6b)
#define DAT_0005ef6d (*(short *)DAT_0005ef6d)
#define DAT_0005ef6f (*(short *)DAT_0005ef6f)
/* ---- from build/var/mod/parts/p390d0.c */
/* FUN_000390d0 @ 000390d0 */
void srand(unsigned);
unsigned short FUN_000390d0(unsigned short p)
{
    unsigned short s = p;
    if (s == 0) s = *(unsigned short *)0x46c;
    srand(s);
    return s;
}

/* ---- from build/var/mod/parts/p390f4.c */
extern void FUN_000396c0(int x0, int y0, int x1, int y1); /* module prototype */
/* FUN_000390f4 @ 000390f4: set video mode m (0xff restores the text mode) */
extern void FUN_00039a84(void), FUN_0003a104(int), FUN_00039fec(int), FUN_00039ffc(int);
extern unsigned char FUN_00039930(unsigned char, unsigned char *);
extern unsigned char DAT_0005ef3c, DAT_0005ef4d, DAT_0005ef4e; 
void FUN_000390f4(int m)
{
    unsigned char r;
    if (m == 0xff) {
        FUN_00039a84();
        DAT_0005ef3c = 0xff;
        return;
    }
    r = FUN_00039930(m, &DAT_0005ef3c);
    DAT_0005ef43 = 0x100;
    DAT_0005ef45 = (r & 4) != 0;
    if (DAT_0005ef47 < 0xff) FUN_0003a104(0xff);
    DAT_0005ef4e = 0;
    DAT_0005ef4d = 0;
    FUN_00039fec(0);
    DAT_0005ef4d = 0;
    FUN_00039ffc(0);
    DAT_0005ef4e = 0;
    FUN_000396c0(0, 0, DAT_0005ef3f - 1, DAT_0005ef41 - 1);
    DAT_0005ef3c = m & 0x7f;
}

/* ---- from build/var/mod/parts/p391b0.c */
/* FUN_000391b0 @ 000391b0 (24 bytes) */
extern void FUN_00039fec(int);
extern unsigned char DAT_0005ef4d;

void FUN_000391b0(unsigned char c)
{
    FUN_00039fec(c);
    DAT_0005ef4d = c;
}

/* ---- from build/var/mod/parts/p391c8.c */
/* FUN_000391c8 @ 000391c8 */
extern void FUN_00039ffc(int);
extern unsigned char DAT_0005ef4e;
void FUN_000391c8(unsigned char c) { FUN_00039ffc(c); DAT_0005ef4e = c; }

/* ---- from build/var/mod/parts/p391e0.c */
/* FUN_000391e0 @ 000391e0 */
extern void FUN_00039cec(int, int, int, int, int);
void FUN_000391e0(int x, int y, int h, unsigned char c) { FUN_00039cec(x, y, x, y + h - 1, c); }

/* ---- from build/var/mod/parts/p39208.c */
/* FUN_00039208 @ 00039208 */
extern void FUN_00039cec(int, int, int, int, int);
void FUN_00039208(int x, int y, int w, unsigned char c) { if (w) FUN_00039cec(x, y, x + w - 1, y, c); }

/* ---- from build/var/mod/parts/p39234.c */
/* FUN_00039234 @ 00039234 */
extern void FUN_00039ca0(int, int, int);
void FUN_00039234(int a) { FUN_00039ca0(a, 0, 0x300); }

/* ---- from build/var/mod/parts/p39248.c */
/* FUN_00039248, FUN_00039264: palette upload and horizontal scroll wrappers */
extern void FUN_00039ca0(int, int, int), FUN_00039f40(int, int); 
void FUN_00039248(int first, int n, int pal) { FUN_00039ca0(pal, first, n * 2 + n); }

extern void FUN_00039ca0(int, int, int), FUN_00039f40(int, int); 

void FUN_00039264(int x) { FUN_00039f40(DAT_0005ef3f - x, x); }

/* ---- from build/var/mod/parts/p39280.c */
/* FUN_00039280, FUN_0003929c: scroll helpers around FUN_00039f40 / FUN_00039eac */
extern void FUN_00039f40(int, int), FUN_00039eac(int); 
void FUN_00039280(int x) { FUN_00039f40(DAT_0005ef3f - x, x - DAT_0005ef3f); }

extern void FUN_00039f40(int, int), FUN_00039eac(int); 

void FUN_0003929c(int v) { FUN_00039eac(v); }

/* ---- from build/var/mod/parts/p392ac.c */
/* FUN_000392ac @ 000392ac: FUN_00039eac with the negated argument */
extern void FUN_00039eac(int);
void FUN_000392ac(int v) { FUN_00039eac(-v); }

/* ---- from build/var/mod/parts/p392bc.c */
/* FUN_000392bc, FUN_0003932c @ 000392bc: clip a rectangle to the screen, then fill / outline it */
extern void FUN_0003a114(int, int, int, int, int); extern void FUN_0003a178(int, int, int, int, int);

void FUN_000392bc(int c, int x, int y, int w, int h)
{
    if (x < 0) { w += x; x = 0; }
    if (y < 0) { h += y; y = 0; }
    if (x + w > DAT_0005ef3f) w = DAT_0005ef3f - x;
    if (y + h > DAT_0005ef41) h = DAT_0005ef41 - y;
    if (w > 0 && h > 0) FUN_0003a114(c, x, y, w, h);
}

extern void FUN_0003a114(int, int, int, int, int); extern void FUN_0003a178(int, int, int, int, int);


void FUN_0003932c(int c, int x, int y, int w, int h)
{
    if (x < 0) { w += x; x = 0; }
    if (y < 0) { h += y; y = 0; }
    if (x + w > DAT_0005ef3f) w = DAT_0005ef3f - x;
    if (y + h > DAT_0005ef41) h = DAT_0005ef41 - y;
    if (w > 0 && h >= 0) FUN_0003a178(c, x, y, w, h);
}

extern void FUN_0003a114(int, int, int, int, int); extern void FUN_0003a178(int, int, int, int, int);


extern void FUN_0003a380(int, int, int, int), FUN_0003a478(int, int, int, int, unsigned char), FUN_0003a584(int, int, int, int, int), FUN_0003e758(void);
/* FUN_0003939c: draw image img at (x, y) on page pg when there is one */
void FUN_0003939c(int pg, int x, int y, int img)
{
    if (!img) return;
    FUN_0003a380(pg, x, y, img);
    FUN_0003e758();
}

extern void FUN_0003a114(int, int, int, int, int); extern void FUN_0003a178(int, int, int, int, int);


/* FUN_000393c0 (not in the function list): draw image img at (x, y) on page pg in colour c */
void FUN_000393c0(int pg, int x, int y, int img, unsigned char c)
{
    if (!img) return;
    FUN_0003a478(pg, x, y, img, c);
    FUN_0003e758();
}

extern void FUN_0003a114(int, int, int, int, int); extern void FUN_0003a178(int, int, int, int, int);


/* FUN_000393ec: draw image img at (x, y) on page pg with colour remap c */
void FUN_000393ec(int pg, int x, int y, int img, int c)
{
    if (!img) return;
    FUN_0003a584(pg, x, y, img, c);
    FUN_0003e758();
}

/* ---- from build/var/mod/parts/p39414.c */
#define FUN_0003a380 ((void (*)(int, int, int, unsigned char *))FUN_0003a380)
/* FUN_00039414 @ 00039414: clip image img at (x, y) against the clip window, fill clip record c, draw it (2 unclipped, 1 clipped, 0 not visible) */
extern void FUN_0003e758(void), FUN_0003a6b0(int, int, int, int *, unsigned char *);
 
int FUN_00039414(int pg, int x, int y, unsigned char *img, int *c)
{
    int d, w;
    FUN_0003e758();
    if (img == 0) return 0;
    c[2] = *(unsigned short *)(img + 4);
    d = DAT_0005ef55 - x;
    c[0] = 0;
    c[1] = 0;
    if (d > 0) {
        c[2] -= d;
        x = img[6] * 8;
        w = d * x;
        x = DAT_0005ef55;
        c[0] = w;
    }
    d = c[2] + x - 1 - DAT_0005ef59;
    if (d > 0) {
        c[2] -= d;
        c[1] = d * (img[6] * 8);
    }
    c[5] = img[6] * 8;
    d = DAT_0005ef5d - y;
    c[3] = 0;
    c[4] = 0;
    if (d > 0) {
        c[3] = d;
        c[5] -= d;
        y = DAT_0005ef5d;
    }
    d = y + c[5] - 1 - DAT_0005ef61;
    if (d > 0) {
        c[4] = d;
        c[5] -= d;
    }
    DAT_0005ef6b = y;
    DAT_0005ef6d = c[2];
    DAT_0005ef6f = c[5];
    w = *(unsigned short *)(img + 4);
    DAT_0005ef69 = x;
    if (w == c[2] && img[6] * 8 == c[5]) {
        FUN_0003a380(pg, x, y, img);
        return 2;
    }
    if (c[2] > 0 && c[5] > 0) {
        FUN_0003a6b0(pg, x, y, c, img);
        return 1;
    }
    return 0;
}

#undef FUN_0003a380
/* ---- from build/var/mod/parts/p39564.c */
#define FUN_0003a478 ((void (*)(int, int, int, unsigned char *, unsigned char))FUN_0003a478)
/* FUN_00039564 @ 00039564: draw sprite img at (x, y) on page pg clipped to the window: 2 = unclipped, 1 = clipped, 0 = nothing drawn */
struct R { int l, r, w, t, b, h; };
extern void FUN_0003e758(void), FUN_0003a8a0(int, int, int, struct R *, unsigned char *, unsigned char);
 
int FUN_00039564(int pg, int x, int y, unsigned char *img, unsigned char c, struct R *r)
{
    int d, w;
    FUN_0003e758();
    if (img) {
        r->w = *(unsigned short *)(img + 4);
        d = DAT_0005ef55 - x;
        r->l = 0;
        r->r = 0;
        if (d > 0) {
            r->w -= d;
            x = img[6] * 8;
            w = d * x;
            x = DAT_0005ef55;
            r->l = w;
        }
        d = r->w + x - 1 - DAT_0005ef59;
        if (d > 0) {
            r->w -= d;
            r->r = d * (img[6] * 8);
        }
        r->h = img[6] * 8;
        d = DAT_0005ef5d - y;
        r->t = 0;
        r->b = 0;
        if (d > 0) {
            r->t = d;
            r->h -= d;
            y = DAT_0005ef5d;
        }
        d = y + r->h - 1 - DAT_0005ef61;
        if (d > 0) {
            r->b = d;
            r->h -= d;
        }
        DAT_0005ef6b = y;
        DAT_0005ef6d = r->w;
        DAT_0005ef6f = r->h;
        w = *(unsigned short *)(img + 4);
        DAT_0005ef69 = x;
        if (w == r->w && img[6] * 8 == r->h) {
            FUN_0003a478(pg, x, y, img, c);
            return 2;
        }
        if (r->w > 0 && r->h > 0) {
            FUN_0003a8a0(pg, x, y, r, img, c);
            return 1;
        }
    }
    return 0;
}

#undef FUN_0003a478
/* ---- from build/var/mod/parts/p396c0.c */
/* FUN_000396c0 @ 000396c0: set the clipping window (rows rounded to multiples of 4); the parameters are
   adjusted in place before the stores */
 
void FUN_000396c0(int x0, int y0, int x1, int y1)
{
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= DAT_0005ef3f) x1 = DAT_0005ef3f - 1;
    if (y1 >= DAT_0005ef41) y1 = DAT_0005ef41 - 1;
    y0 &= ~3;
    y1 = (y1 / 4) * 4 + 3;
    DAT_0005ef59 = x1;
    DAT_0005ef5d = y0;
    DAT_0005ef61 = y1;
    DAT_0005ef55 = x0;
}

/* ---- from build/var/mod/parts/p39738.c */
#undef DAT_0005ef55
#define DAT_0005ef55 ((unsigned char *)&VIEW_DAT_0005ef55)
#define FUN_0003a380 ((void (*)(int, int, int, unsigned char *))FUN_0003a380)
/* FUN_00039738 @ 00039738 */
void *memcpy(void *, const void *, unsigned);
#pragma intrinsic(memcpy)

void FUN_00039738(void *dst) { memcpy(dst, DAT_0005ef55, 16); }



extern unsigned char *FUN_0003f29c(int, int); extern void FUN_0003e758(void);
/* FUN_0003975c: draw image (id, sub) at (x, y) on page pg when it exists */
void FUN_0003975c(int pg, int x, int y, int id, int sub)
{
    unsigned char *img = FUN_0003f29c(id, sub);
    if (!img) return;
    FUN_0003a380(pg, x, y, img);
    FUN_0003e758();
}

#undef DAT_0005ef55
#define DAT_0005ef55 VIEW_DAT_0005ef55
#undef FUN_0003a380
/* ---- from build/var/mod/parts/p3978c.c */
extern int FUN_00039414(int pg, int x, int y, unsigned char *img, int *c); /* module prototype */
#define FUN_00039414 ((int (*)(int, int, int, int, struct S24 *))FUN_00039414)
#define FUN_0003f29c ((int (*)(int, int))FUN_0003f29c)
/* FUN_0003978c: draw image (id d, sub e) at (b, c) on page a with a clip record from the nesting stack; returns FUN_00039414's
   result like its sibling FUN_000398b4. Matched 2026-11-11 (tie round, found with the 2002 instrument tools/ow1cc.sh): the
   kept result r is one more conflict node, which changes the ShellSort order of the tied temporaries n*24 and p (savings 4
   each), so p takes eax as in the original. */
struct S24 { char b[24]; };
 
extern int DAT_0005efd4; extern struct S24 DAT_0005ef74[];
int FUN_0003978c(int a, int b, int c, int d, int e)
{
    struct S24 *p = &DAT_0005ef74[DAT_0005efd4++];
    int r = FUN_00039414(a, b, c, FUN_0003f29c(d, e), p);
    DAT_0005efd4--;
    return r;
}

#undef FUN_00039414
#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p397d0.c */
#define FUN_0003f29c ((int (*)(int, int))FUN_0003f29c)
/* FUN_000397d0 @ 000397d0 */
 extern void FUN_0003e488(int, int, int);
extern int DAT_0005efd4;
void FUN_000397d0(int a, int b, int c, int d)
{
    int r = FUN_0003f29c(c, d);
    if (r) { DAT_0005efd4++; FUN_0003e488(a, b, r); DAT_0005efd4--; }
}

#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p39804.c */
extern int FUN_00039414(int pg, int x, int y, unsigned char *img, int *c); /* module prototype */
#define FUN_00039414 ((void (*)(int, int, int, int, struct S24 *))FUN_00039414)
#define FUN_0003a478 ((void (*)(int, int, int, unsigned char *, unsigned char))FUN_0003a478)
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)
/* FUN_00039804 @ 00039804 */
/* struct S24: defined above */

extern int DAT_0005efd4; extern struct S24 DAT_0005ef74[];
void FUN_00039804(int a, int b, int c, int d)
{
    FUN_00039414(a, b, c, d, &DAT_0005ef74[DAT_0005efd4++]);
    DAT_0005efd4--;
}


extern int DAT_0005efd4; extern struct S24 DAT_0005ef74[];

 extern void FUN_0003e758(void);
/* FUN_00039838: draw image (id, sub) at (x, y) on page pg in colour c when it exists */
void FUN_00039838(int pg, int x, int y, int id, int sub, unsigned char c)
{
    unsigned char *img = FUN_0003f29c(id, sub);
    if (!img) return;
    FUN_0003a478(pg, x, y, img, c);
    FUN_0003e758();
}

#undef FUN_00039414
#undef FUN_0003a478
#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p3986c.c */
extern int FUN_00039564(int pg, int x, int y, unsigned char *img, unsigned char c, struct R *r); /* module prototype */
#define FUN_00039564 ((void (*)(int, int, int, int, int, struct S24 *))FUN_00039564)
#define FUN_0003f29c ((int (*)(int, int))FUN_0003f29c)
/* FUN_0003986c @ 0003986c */
/* struct S24: defined above */
 
extern int DAT_0005efd4; extern struct S24 DAT_0005ef74[];
void FUN_0003986c(int a, int b, int c, int d, int e, unsigned char g)
{
    FUN_00039564(a, b, c, FUN_0003f29c(d, e), g, &DAT_0005ef74[DAT_0005efd4++]);
    DAT_0005efd4--;
}

#undef FUN_00039564
#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p398b4.c */
extern int FUN_00039564(int pg, int x, int y, unsigned char *img, unsigned char c, struct R *r); /* module prototype */
#define DAT_0005ef74 ((struct R *)DAT_0005ef74)
#define FUN_00039564 ((int (*)(int, int, int, int, unsigned char, struct R *))FUN_00039564)
#define FUN_0003a584 ((void (*)(int, int, int, unsigned char *, int))FUN_0003a584)
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)
/* FUN_000398b4 @ 000398b4: clipped sprite draw with a clip record from the nesting stack */
/* struct R: defined above */
  extern int DAT_0005efd4;
int FUN_000398b4(int pg, int x, int y, int img, unsigned char c)
{
    int r = FUN_00039564(pg, x, y, img, c, &DAT_0005ef74[DAT_0005efd4++]);
    DAT_0005efd4--;
    return r;
}

  extern int DAT_0005efd4;

 extern void FUN_0003e758(void);
/* FUN_000398f0: draw image (id, sub) at (x, y) on page pg with colour remap c when it exists */
void FUN_000398f0(int pg, int x, int y, int id, int sub, int c)
{
    unsigned char *img = FUN_0003f29c(id, sub);
    if (!img) return;
    FUN_0003a584(pg, x, y, img, c);
    FUN_0003e758();
}

#undef DAT_0005ef74
#undef FUN_00039564
#undef FUN_0003a584
#undef FUN_0003f29c

/* ---- module data _DATA 0005ef3c-0005efe0 (docs/data/dataown.CODE2.csv: range given by hand, see docs/MODULES.md Data round), generated by tools/data2c.py */
#undef DAT_0005ef3f
#undef DAT_0005ef41
#undef DAT_0005ef43
#undef DAT_0005ef45
#undef DAT_0005ef47
#undef DAT_0005ef55
#undef DAT_0005ef59
#undef DAT_0005ef5d
#undef DAT_0005ef61
#undef DAT_0005ef69
#undef DAT_0005ef6b
#undef DAT_0005ef6d
#undef DAT_0005ef6f
unsigned char DAT_0005ef3c = 0;
unsigned char DAT_0005ef3d[1] = { 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned char DAT_0005ef3e = 0;   /* type from another module's declaration */
unsigned char DAT_0005ef3f[2] = { 0 };
unsigned char DAT_0005ef41[2] = { 0 };
unsigned char DAT_0005ef43[2] = { 0 };
unsigned char DAT_0005ef45[2] = { 0 };
unsigned char DAT_0005ef47[2] = { 0 };
unsigned char DAT_0005ef49[4] = { 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_0005ef4d = 0;
unsigned char DAT_0005ef4e = 0;
unsigned char DAT_0005ef4f[4] = { 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_0005ef53[2] = { 0 };   /* a field at an unaligned address, named by other modules only: bytes */
unsigned char DAT_0005ef55[4] = { 0 };
unsigned char DAT_0005ef59[4] = { 0 };
unsigned char DAT_0005ef5d[4] = { 0 };
unsigned char DAT_0005ef61[4] = { 0 };
unsigned char DAT_0005ef65[3] = { 0, 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned char DAT_0005ef68 = 0;   /* type from another module's declaration */
unsigned char DAT_0005ef69[2] = { 0 };
unsigned char DAT_0005ef6b[2] = { 0 };
unsigned char DAT_0005ef6d[2] = { 0 };
unsigned char DAT_0005ef6f[2] = { 0 };
unsigned char DAT_0005ef71[3] = { 0x45, 0x20, 0x20 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
struct S24 DAT_0005ef74[4] = { 0 };
int DAT_0005efd4 = 0;
unsigned char DAT_0005efd8[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
