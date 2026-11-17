/* Module: FUN_0003e340, FUN_0003e34c, FUN_0003e360, FUN_0003e374, FUN_0003e404, FUN_0003e438, FUN_0003e488,
   FUN_0003e4a4, FUN_0003e4f4, FUN_0003e510, FUN_0003e538, FUN_0003e564, FUN_0003e590, FUN_0003e5d4,
   FUN_0003e608, FUN_0003e614, FUN_0003e6d0, FUN_0003e6f0, FUN_0003e70c, FUN_0003e728, FUN_0003e740,
   FUN_0003e74c, FUN_0003e758, FUN_0003e768, FUN_0003e7f0, FUN_0003e9cc, FUN_0003ea28, FUN_0003ea9c,
   FUN_0003eb28, FUN_0003eb60, FUN_0003ec74, FUN_0003ec84, FUN_0003ecb4, FUN_0003efd0, FUN_0003f0b4,
   FUN_0003f184, FUN_0003f1b4, FUN_0003f1e4, FUN_0003f260, FUN_0003f29c, FUN_0003f2e0, FUN_0003f2ec,
   FUN_0003f468, FUN_0003f4e0, FUN_0003f540, FUN_0003f554, FUN_0003f580, FUN_0003f5f4, FUN_0003f83c,
   FUN_0003f844, FUN_0003f84c, FUN_0003f860, FUN_0003f868 */
/* ---- from build/var/mod/parts/p3e340.c */
/* FUN_0003e340 @ 0003e340: value behind a short pointer */
extern short *DAT_0005f04c;
int FUN_0003e340(void) { return *DAT_0005f04c; }

/* ---- from build/var/mod/parts/p3e34c.c */
/* FUN_0003e34c @ 0003e34c: true when the current font record says mode 1 */
extern short *DAT_0005f04c;
int FUN_0003e34c(void) { return DAT_0005f04c[2] == 1; }

/* ---- from build/var/mod/parts/p3e360.c */
/* FUN_0003e360 @ 0003e360: second word of the current record, 0 when it is empty */
extern short *DAT_0005f04c;
int FUN_0003e360(void) { if (*DAT_0005f04c) return DAT_0005f04c[1]; return 0; }

/* ---- from build/var/mod/parts/p3e374.c */
/* FUN_0003e374 @ 0003e374: draw a w x h frame at (x, y) in colour col */
extern void FUN_000391e0(int, int, int, unsigned char), FUN_00039208(int, int, int, unsigned char);
void FUN_0003e374(int x, int y, int w, int h, unsigned char col)
{
    FUN_000391e0(x, y, h, col);
    if (w > 2) FUN_00039208(x + 1, y, w - 2, col);
    if (w > 1) FUN_000391e0(x + w - 1, y, h, col);
    if (w > 2 && h > 1) FUN_00039208(x + 1, y + h - 1, w - 2, col);
}

/* ---- from build/var/mod/parts/p3e404.c */
/* FUN_0003e404 @ 0003e404 */
extern void FUN_0003aa9c(int, int, char *);
void FUN_0003e404(int a, char *p)
{
    int i;
    for (i = 0; i < *(unsigned short *)(p + 2); i++) FUN_0003aa9c(i, a, p);
}

/* ---- from build/var/mod/parts/p3e438.c */
/* FUN_0003e438 @ 0003e438: draw rows first..last of an image, one strip per row, stepping y by the image row height */
extern void FUN_00039804(int, int, int, unsigned short *);
void FUN_0003e438(int y, int x, int first, int last, unsigned short *img)
{
    int k, step;
    if (last == -1) last = img[1];
    else last += first;
    k = first;
    step = img[2];
    for (; k < last; k++) {
        FUN_00039804(k, y, x, img);
        y += step;
    }
}

/* ---- from build/var/mod/parts/p3e488.c */
extern void FUN_0003e438(int y, int x, int first, int last, unsigned short *img); /* module prototype */
extern void FUN_0003e4a4(int y, int x, int first, int last, unsigned short *img); /* module prototype */
#define FUN_0003e438 ((void (*)(int, int, int, int, int))FUN_0003e438)
/* FUN_0003e488, FUN_0003e4f4 */
 
void FUN_0003e488(int a, int b, int c) { FUN_0003e438(a, b, 0, -1, c); }

#undef FUN_0003e438
/* ---- from build/var/mod/parts/p3e4a4.c */
/* FUN_0003e4a4 @ 0003e4a4: draw rows (masked) first..last of an image, one strip per row, stepping y by the image row height */
extern void FUN_0003939c(int, int, int, unsigned short *);
void FUN_0003e4a4(int y, int x, int first, int last, unsigned short *img)
{
    int k, step;
    if (last == -1) last = img[1];
    else last += first;
    k = first;
    step = img[2];
    for (; k < last; k++) {
        FUN_0003939c(k, y, x, img);
        y += step;
    }
}

/* ---- from build/var/mod/parts/p3e4f4.c */
extern void FUN_0003e438(int y, int x, int first, int last, unsigned short *img); /* module prototype */
extern void FUN_0003e4a4(int y, int x, int first, int last, unsigned short *img); /* module prototype */
#define FUN_0003e4a4 ((void (*)(int, int, int, int, int))FUN_0003e4a4)
 

void FUN_0003e4f4(int a, int b, int c) { FUN_0003e4a4(a, b, 0, -1, c); }

#undef FUN_0003e4a4
/* ---- from build/var/mod/parts/p3e510.c */
extern void FUN_0003e4a4(int y, int x, int first, int last, unsigned short *img); /* module prototype */
extern int *FUN_0003f29c(int a, int b); /* module prototype */
#define FUN_0003e4a4 ((void (*)(int, int, int, int, int))FUN_0003e4a4)
#define FUN_0003f29c ((int (*)(int, int))FUN_0003f29c)
/* FUN_0003e510 @ 0003e510 */
 
void FUN_0003e510(int a, int b, int c, int d) { int r = FUN_0003f29c(c, d); FUN_0003e4a4(a, b, 0, -1, r); }

#undef FUN_0003e4a4
#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p3e538.c */
/* FUN_0003e538 @ 0003e538 */
extern void FUN_0003a258(int, char *);
void FUN_0003e538(char *p)
{
    int i;
    for (i = 0; i < *(unsigned short *)(p + 2); i++) FUN_0003a258(i, p);
}

/* ---- from build/var/mod/parts/p3e564.c */
/* FUN_0003e564 @ 0003e564: draw every row of image img */
extern void FUN_0003a308(int, unsigned short *);
void FUN_0003e564(unsigned short *img) { int k; for (k = 0; k < img[1]; k++) FUN_0003a308(k, img); }

/* ---- from build/var/mod/parts/p3e590.c */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003e590 @ 0003e590: push the page stack (the post-increment index form also compiles like the original under the module's -oa; n = count, count = n + 1 does not) */
 extern void FUN_000391b0(unsigned char);
extern unsigned char DAT_0005f0d0, DAT_0007b644[], DAT_0005ef4d;

void FUN_0003e590(unsigned char page)
{
    if (DAT_0005f0d0 == 10) FUN_0003f580("Page Stack Overflow");
    DAT_0007b644[DAT_0005f0d0++] = DAT_0005ef4d;
    FUN_000391b0(page);
}

/* ---- from build/var/mod/parts/p3e5d4.c */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003e5d4 @ 0003e5d4: pop the page stack */
 extern void FUN_000391b0(unsigned char);
extern unsigned char DAT_0005f0d0, DAT_0007b644[];

void FUN_0003e5d4(void)
{
    if (DAT_0005f0d0 == 0) FUN_0003f580("Page Stack Underflow");
    DAT_0005f0d0--;
    FUN_000391b0(DAT_0007b644[DAT_0005f0d0]);
}

/* ---- from build/var/mod/parts/p3e608.c */
/* FUN_0003e608 @ 0003e608: remember the current timer value */
extern unsigned FUN_00040700(void); extern unsigned DAT_0007b640;
void FUN_0003e608(void) { DAT_0007b640 = FUN_00040700(); }

/* ---- from build/var/mod/parts/p3e614.c */
extern int FUN_0003e340(void); /* module prototype */
extern void FUN_0003f868(void); /* module prototype */
#define FUN_00040700 ((int (*)(void))FUN_00040700)
/* FUN_0003e614 @ 0003e614: wait up to t ticks for input (flags: 1 key, 2 mouse button, 4 return at once); returns the key, 0x1f8 + button, 0x1f0 or 0 */
extern int FUN_00040ad8(void), FUN_00040aec(void); extern short *FUN_00043cb0(void); 
extern unsigned DAT_0007b640;
int FUN_0003e614(unsigned t, int flags)
{
    unsigned end; int k; short *p;
    if (DAT_0007b640) end = DAT_0007b640 + t;
    else end = t + FUN_00040700();
    if (flags & 4) flags &= ~4;
    do {
        FUN_0003f868();
        if ((flags & 1) && FUN_00040ad8()) {
            DAT_0007b640 = 0;
            return FUN_00040aec();
        }
        if ((flags & 2) && FUN_0003e340()) {
            p = FUN_00043cb0();
            if (*p) {
                k = *p;
                while (*FUN_00043cb0()) ;
                DAT_0007b640 = 0;
                return k + 0x1f8;
            }
        }
        if (flags & 4) {
            DAT_0007b640 = 0;
            return 0x1f0;
        }
    } while (FUN_00040700() < end);
    DAT_0007b640 = 0;
    return 0;
}

#undef FUN_00040700
/* ---- from build/var/mod/parts/p3e6d0.c */
extern int FUN_0003e614(unsigned t, int flags); /* module prototype */
/* FUN_0003e6d0 @ 0003e6d0 */
void sound(unsigned); void nosound(void); 
void FUN_0003e6d0(void) { sound(0x416); FUN_0003e614(6, 0); nosound(); }

/* ---- from build/var/mod/parts/p3e6f0.c */
/* FUN_0003e6f0 @ 0003e6f0: a as a decimal string (itoa, the library function at 0x473bf) */
extern char *itoa(int, char *, int);
extern char DAT_0007b64e[];
char *FUN_0003e6f0(int a) { itoa(a, DAT_0007b64e, 10); return DAT_0007b64e; }

/* ---- from build/var/mod/parts/p3e70c.c */
/* FUN_0003e70c @ 0003e70c: a as a decimal string (ltoa, the library function at 0x47483) */
extern char *ltoa(long, char *, int);
extern char DAT_0007b64e[];
char *FUN_0003e70c(int a) { ltoa(a, DAT_0007b64e, 10); return DAT_0007b64e; }

/* ---- from build/var/mod/parts/p3e728.c */
/* FUN_0003e728 @ 0003e728: sign of v (-1, 0, 1) */
int FUN_0003e728(int v)
{
    if (v < 0) return -1;
    if (v > 0) return 1;
    return 0;
}

/* ---- from build/var/mod/parts/p3e740.c */
/* FUN_0003e740 @ 0003e740: install the hook FUN_0003ecb4 calls with (index, group) after loading a resource (round 18: the hook pointer
   is declared as FUN_0003ecb4 calls it, one declaration per symbol in module 0x3e340) */
extern void (*DAT_0005f0cc)(int, int);
void FUN_0003e740(void (*c)(int, int)) { DAT_0005f0cc = c; }

/* ---- from build/var/mod/parts/p3e74c.c */
/* FUN_0003e74c @ 0003e74c: install the idle/redraw hook that FUN_0003e758 and FUN_0003f868 call (round 18: declared as they call it) */
extern void (*DAT_0005f0c8)(void);
void FUN_0003e74c(void (*c)(void)) { DAT_0005f0c8 = c; }

/* ---- from build/var/mod/parts/p3e758.c */
/* FUN_0003e758 @ 0003e758: call the redraw hook if one is installed */
extern void (*DAT_0005f0c8)(void);
void FUN_0003e758(void) { if (DAT_0005f0c8) DAT_0005f0c8(); }

/* ---- from build/var/mod/parts/p3e768.c */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003e768 @ 0003e768: read INFO.DAT */
void *memset(void *, int, unsigned);
extern int FUN_000412a0(char *), FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int);
 extern unsigned char DAT_0005f054[13], DAT_0005f061[];
void FUN_0003e768(void)
{
    int k; short n;
    int h = FUN_000412a0("INFO.DAT");
    if (h == -1) FUN_0003f580("Cannot Find INFO.DAT, rerun INSTALL.EXE");
    FUN_000412ec(DAT_0005f054, 13, h);
    memset(DAT_0005f061, 0, 0x50);
    for (k = 0; k < 13; k++) DAT_0005f054[k] -= 0x30;
    FUN_000412ec(&n, 2, h);
    FUN_000412ec(DAT_0005f061, n, h);
    FUN_000412dc(h);
}

/* ---- from build/var/mod/parts/p3e7f0.c */
extern char *FUN_0003e6f0(int a); /* module prototype */
extern void FUN_0003e768(void); /* module prototype */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003e7f0 @ 0003e7f0: open the n resource files <path\>name<k> (path only for those flagged in DAT_0005f054), read each one's entry count and allocate its 9-byte entry table, all marked not loaded */
#include <string.h>
#define DAT_0005f061 ((char *)DAT_0005f061)
#pragma pack(1)
struct RE { unsigned short lo : 4, ld : 1, b5 : 3, f1 : 8; unsigned char f2; unsigned short f3; int f5; };
#pragma pack()
struct RF { int fh, f4, count; struct RE *tab; };
extern struct RF *DAT_0005f0b8; extern int DAT_0005f0b4; extern unsigned char DAT_0005f054[]; 
 extern void *FUN_0004104c(int);  extern int FUN_000412a0(char *), FUN_000412ec(void *, unsigned, int);
void FUN_0003e7f0(char *name, int n)
{
    char path[80]; int i, k, off; struct RF *f;
    FUN_0003e768();
    DAT_0005f0b8 = FUN_0004104c(n << 4);
    DAT_0005f0b4 = n;
    for (i = 0; i < n; i++) {
        if (DAT_0005f054[i]) {
            strcpy(path, DAT_0005f061);
            strcat(path, "\\");
            strcat(path, name);
        } else strcpy(path, name);
        strcat(path, FUN_0003e6f0(i));
        if ((DAT_0005f0b8[i].fh = FUN_000412a0(path)) == -1) FUN_0003f580("Unable to open resource file");
        FUN_000412ec(&DAT_0005f0b8[i].count, 4, DAT_0005f0b8[i].fh);
        DAT_0005f0b8[i].f4 = 0;
        off = 0;
        DAT_0005f0b8[i].tab = FUN_0004104c(DAT_0005f0b8[i].count * 9);
        for (k = 0; k < (f = &DAT_0005f0b8[i])->count; k++, off += 9) {
            ((struct RE *)((char *)f->tab + off))->lo = -1;
            ((struct RE *)((char *)f->tab + off))->ld = 0;
            ((struct RE *)((char *)f->tab + off))->f2 = 0;
            ((struct RE *)((char *)f->tab + off))->f3 = 0;
            ((struct RE *)((char *)f->tab + off))->f5 = 0;
        }
    }
}

#undef DAT_0005f061
#pragma pack()
/* ---- from build/var/mod/parts/p3e9cc.c */
extern void FUN_0003efd0(int a, int b); /* module prototype */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003e9cc @ 0003e9cc */

extern int DAT_0005f0b4; 
void FUN_0003e9cc(void)
{
    int g, j;
    for (g = 0; g < DAT_0005f0b4; g++) {
        for (j = 0; j < *(int *)(DAT_0005f0b8 + g * 16 + 8); j++) {
            unsigned char *p = *(unsigned char **)(DAT_0005f0b8 + g * 16 + 12) + j * 9;
            if (p[2]) *p &= ~0x10;
            FUN_0003efd0(j, g);
        }
    }
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3ea28.c */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003ea28 @ 0003ea28: set the colour field of every active menu entry */
extern int DAT_0005f0b4; 
void FUN_0003ea28(unsigned c)
{
    int j, g; unsigned char *p;
    c >>= 5;
    for (g = 0; g < DAT_0005f0b4; g++) {
        for (j = 0; j < *(int *)(DAT_0005f0b8 + g * 16 + 8); j++) {
            p = *(unsigned char **)(DAT_0005f0b8 + g * 16 + 12) + j * 9;
            if (p[2]) *(short *)(p + 3) = c;
        }
    }
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3ea9c.c */
extern void FUN_0003e9cc(void); /* module prototype */
/* FUN_0003ea9c @ 0003ea9c: close the resource files and free their entry tables (round 18: the table is FUN_0003e7f0's struct RF,
   one declaration of DAT_0005f0b8 in module 0x3e340) */
#pragma pack(1)
/* struct RE: defined above */
#pragma pack()
/* struct RF: defined above */
extern void FUN_000412dc(int), FUN_000410b0(void *);
extern int DAT_0005f0b4; extern struct RF *DAT_0005f0b8;
void FUN_0003ea9c(void)
{
    int g;
    FUN_0003e9cc();
    for (g = 0; g < DAT_0005f0b4; g++) {
        if (DAT_0005f0b8[g].fh) {
            FUN_000412dc(DAT_0005f0b8[g].fh);
            DAT_0005f0b8[g].fh = 0;
            DAT_0005f0b8[g].count = 0;
        }
        if (DAT_0005f0b8[g].tab) {
            FUN_000410b0(DAT_0005f0b8[g].tab);
            DAT_0005f0b8[g].tab = 0;
        }
    }
    FUN_000410b0(DAT_0005f0b8);
    DAT_0005f0b8 = 0;
}

#pragma pack()
/* ---- from build/var/mod/parts/p3eb28.c */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003eb28 @ 0003eb28: total entry count over all menu groups */
extern int DAT_0005f0b4; 
int FUN_0003eb28(void)
{
    int k, s = 0;
    for (k = 0; k < DAT_0005f0b4; k++) s += *(int *)(DAT_0005f0b8 + k * 16 + 4);
    return s;
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3eb60.c */
extern char *FUN_0003e6f0(int a); /* module prototype */
extern char *FUN_0003e70c(int a); /* module prototype */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003eb60 @ 0003eb60: read the resource at offset pos of file fh into r (5-byte header, then the data in a new buffer); abort with "Attempt to load non-resource file: <file>/<n>" when the magic is not "EH" */
#include <string.h>
#pragma pack(1)
struct RES { unsigned short magic; unsigned char k; short len; char *data; };
#pragma pack()
extern void FUN_00041334(int, int); extern int FUN_000412ec(void *, unsigned, int);
extern char *FUN_0004104c(int);
void FUN_0003eb60(struct RES *r, int pos, int fh, int n)
{
    char buf[80];
    FUN_00041334(pos, fh);
    FUN_000412ec(r, 5, fh);
    if (r->len) {
        r->data = FUN_0004104c(r->len);
        FUN_000412ec(r->data, r->len, fh);
    } else r->data = 0;
    if (r->magic != 0x4845) {
        strcpy(buf, "Attempt to load non-resource file: ");
        strcat(buf, FUN_0003e6f0(pos));
        strcat(buf, "/");
        strcat(buf, FUN_0003e70c(n));
        FUN_0003f580(buf);
    }
}

#pragma pack()
/* ---- from build/var/mod/parts/p3ec74.c */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003ec74 @ 0003ec74: pointer field of a 16-byte font record */

int FUN_0003ec74(int n) { return *(int *)(DAT_0005f0b8 + n * 16); }

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3ec84.c */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003ec84 @ 0003ec84: third field of a 16-byte font record */

int FUN_0003ec84(int n) { return *(int *)(DAT_0005f0b8 + n * 16 + 8); }

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3ecb4.c */
extern char *FUN_0003e6f0(int a); /* module prototype */
extern char *FUN_0003e70c(int a); /* module prototype */
extern void FUN_0003eb60(struct RES *r, int pos, int fh, int n); /* module prototype */
extern void FUN_0003f580(char *msg); /* module prototype */
/* FUN_0003ecb4 @ 0003ecb4 (-oa): types 6 and 7 call the same address under two names (ALT_00047590), so the cases are not merged. Make resource idx of group grp resident: load it through the loader for its type, mark it loaded and stamp its last use */
#include <string.h>
#define DAT_0005f0b8 ((struct GRP *)DAT_0005f0b8)
#define FUN_00040700 ((unsigned (*)(void))FUN_00040700)
#pragma pack(1)
/* struct RES: defined above */
struct REC { unsigned short type : 4, locked : 1; unsigned char loaded; unsigned short used; void *data; };
#pragma pack()
struct GRP { int fh, nloaded, n; struct REC *rec; };
 extern void (*DAT_0005f0cc)(int, int); extern struct RES DAT_0007b670;
extern void FUN_000410b0(void *);
 
extern void *FUN_0003fd9c(struct RES *, int), *FUN_000401a8(struct RES *, int), *FUN_000386c4(struct RES *, int), *FUN_00038020(struct RES *, int), *FUN_000474e0(struct RES *, int), *FUN_00047590(struct RES *, int), *ALT_00047590(struct RES *, int);
/* the second name of the type-7 loader is an object-level alias of FUN_00047590 (one function, two C names, so the
   compiler keeps the two cases apart as in the original); the object references FUN_00047590 for both (round 18) */
#pragma aux ALT_00047590 "FUN_00047590";
void FUN_0003ecb4(int idx, int grp)
{
    char buf[80];
    if (idx < 0 || idx >= DAT_0005f0b8[grp].n) {
        strcpy(buf, "Attempt to load out-of-range: ");
        strcat(buf, FUN_0003e6f0(idx));
        strcat(buf, "/");
        strcat(buf, FUN_0003e70c(grp));
        FUN_0003f580(buf);
    }
    if (!DAT_0005f0b8[grp].rec[idx].loaded) {
        if (DAT_0005f0cc) DAT_0005f0cc(idx, grp);
        FUN_0003eb60(&DAT_0007b670, idx, DAT_0005f0b8[grp].fh, grp);
        switch (DAT_0007b670.k) {
        case 1: DAT_0005f0b8[grp].rec[idx].data = FUN_0003fd9c(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 2: DAT_0005f0b8[grp].rec[idx].data = FUN_000401a8(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 3: DAT_0005f0b8[grp].rec[idx].data = FUN_000386c4(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 4: DAT_0005f0b8[grp].rec[idx].data = FUN_00038020(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 5: DAT_0005f0b8[grp].rec[idx].data = FUN_000474e0(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 6: DAT_0005f0b8[grp].rec[idx].data = FUN_00047590(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        case 7: DAT_0005f0b8[grp].rec[idx].data = ALT_00047590(&DAT_0007b670, DAT_0005f0b8[grp].fh); break;
        default: FUN_0003f580("Unknown resource type");
        }
        DAT_0005f0b8[grp].rec[idx].loaded = 1;
        DAT_0005f0b8[grp].rec[idx].type = DAT_0007b670.k;
        DAT_0005f0b8[grp].rec[idx].locked = 0;
        if (DAT_0007b670.data) FUN_000410b0(DAT_0007b670.data);
        DAT_0005f0b8[grp].nloaded++;
    }
    DAT_0005f0b8[grp].rec[idx].used = FUN_00040700() >> 5;
}

#undef DAT_0005f0b8
#undef FUN_00040700
#pragma pack()
/* ---- from build/var/mod/parts/p3efd0.c */
#define DAT_0005f0b8 ((struct S *)DAT_0005f0b8)
/* Round 18: MATCH in module 0x3e340 with d declared in an inner block after the head test (lever catalogue: inner-block scope reorders the cross-block nodes; the b*16+g / a*9 tie flips to the original). Earlier note: NEAR MISS 226/226 with -oa, 16 lines: case 7 calls the same address as case 6 under another name (ALT_000475f0; in CODE.1 the two cases call different functions, FUN_0001e1f4 and FUN_0001e26c), which keeps the compiler from merging the two tails; left: the entry address takes ebx for g + b * 16 and edx for a * 9 (original edx and ebx: "b * 16 + g" operand order); index spellings, casts, pointer locals and parameter types do not change it tried 2026-11-10: the rest of the function matches; only the two index temporaries swap (orig b*16 in edx, a*9 in ebx which the switch value reuses). Without the switch our compile gives the original registers. Switching on a local k gives ebx right but k as int moves the movzx (as unsigned short/short +2 bytes); .n-- forms, store order, b[DAT] and *(DAT+b) spellings change nothing. 2026-11-10 (module round): Q1 no clobber, Q2 no live-range difference, Q3 an allocation tie (recipe 28): the head computes b*16/a*9 in the form FUN_0003f184/f1b4/f29c have alone, the original in the form of its own tail; in FUN_0003f468 the same two forms flip between blocks with the spelling of the other block. Q4 no. Tried: the head test as two returns, the body under the inverted test (both unchanged, 16 lines). Tie round 3 (2026-11-11, gate IDENTICAL in module 0x3e340): (a) b*16+g (t8) and a (t88) tie at savings 6, t88 first; tiemodel: removing one of DAT_0005f0b8's, a's, the type bit-field's or a head temp's node, or one more zero-savings node at positions 0-7, flips it. 600 instrument variants (parameter types of a, b and d, head test forms, n-- forms, (DAT+b)-> and (t+a)-> spellings): none closer; no 10.0a compile. Tie round 4 (2026-11-11, instrument with the reversed declaration chain, gate IDENTICAL): (a) b*16+g (t9) and a*9 (t89) tie at 6; whatif: move a's parameter node, remove DAT_0005f0b8's -oa node or a block-local temp, or one more node at the list front. Levers of the catalogue tried (ALLOCATOR.md "Lever catalogue"): parameter types of a, b and d with the module prototypes (192, int/unsigned/long one code, char/short change the code), tail forms with e/s pointers and n-- spellings (20); DAT_0005f0b8 cannot be a structure member (FUN_0003f1e4 caches its neighbours DAT_0005f0b4/DAT_0005f0c0 as scalars). No match; no 10.0a compile. */
/* FUN_0003efd0 @ 0003efd0: release entry a of menu group b: free what it holds by type, then clear it and count it out of the group */
#pragma pack(1)
struct E { unsigned short type : 4, off : 1, rest : 11; unsigned char g; unsigned short pr; int data; };
#pragma pack()
struct S { int a, n, c; struct E *t; };

extern void FUN_00040040(int), FUN_0004024c(int), FUN_0003871c(int), FUN_00038078(int), FUN_0004757c(int), FUN_000475f0(int), ALT_000475f0(int);
/* the type-7 free under its second name: an object-level alias of FUN_000475f0 (see f3ecb4.c) */
#pragma aux ALT_000475f0 "FUN_000475f0";
void FUN_0003efd0(int a, int b)
{
    if (DAT_0005f0b8[b].t[a].off || !DAT_0005f0b8[b].t[a].g) return;
    {
    int d;
    d = DAT_0005f0b8[b].t[a].data;
    switch (DAT_0005f0b8[b].t[a].type) {
    case 1: if (DAT_0005f0b8[b].t[a].g == 1) FUN_00040040(d); break;
    case 2: FUN_0004024c(d); break;
    case 3: FUN_0003871c(d); break;
    case 4: FUN_00038078(d); break;
    case 5: FUN_0004757c(d); break;
    case 6: if (DAT_0005f0b8[b].t[a].g == 1) FUN_000475f0(d); break;
    case 7: if (DAT_0005f0b8[b].t[a].g == 1) ALT_000475f0(d); break;
    }
    }
    DAT_0005f0b8[b].t[a].g = 0;
    DAT_0005f0b8[b].t[a].pr = 0;
    DAT_0005f0b8[b].t[a].data = 0;
    DAT_0005f0b8[b].n--;
}

#undef DAT_0005f0b8
#pragma pack()
/* ---- from build/var/mod/parts/p3f0b4.c */
extern void FUN_0003efd0(int a, int b); /* module prototype */
/* Round 18: MATCH in module 0x3e340. The entry table is the resource table of FUN_0003e7f0/FUN_0003ecb4 (struct RF/RE): key is the
   loaded state f2, ld the lock bit (a 1-bit field test, recipe 43), f3 the last-use stamp; with the struct accesses written out (recipe 6)
   best takes ebp as in the original, and `unsigned best` declared first gives the original frame slots (g@0, fg@8). This is not a menu
   hot key: it picks the least recently used loaded entry and releases it through FUN_0003efd0. Earlier note: NEAR MISS 207/207 with -oa, 34 lines: struct-indexed group table (GRP), unsigned best and the return-0-first exit give the size and the inner loop; left: the original keeps best in ebp (also used as the zero for g and off) and lays out g@0, off@4, fg@8 and the two off copies at 0xc/0x10; here best is edi and g sits at 0x10. 720 declaration orders tried 2026-11-10 (module round, in context 43 differing lines): Q1 no clobber; Q2 none (best is loop-carried in both, its zero also stores g); Q3 the cause: best (2 uses per inner iteration) and the e[2] temporary (def + compare) are an equal-savings pair; the original allocates the temporary first (edi) and best gets ebp, ours the reverse (recipe 28). Q4 follows from Q3. Tried: unsigned short best (47), int best with an unsigned compare (43), key == e[2] (68, frame grows), best = 0 as a statement (43). */
/* FUN_0003f0b4 @ 0003f0b4: release the least recently used resource entry whose state is key (unlocked, lowest last-use stamp); -oa module */
#pragma pack(1)
/* struct RE: defined above */
#pragma pack()
/* struct RF: defined above */

extern int DAT_0005f0b4; extern struct RF *DAT_0005f0b8;
int FUN_0003f0b4(int key)
{
    unsigned best = 0; int g, j, found = -1, fg;
    for (g = 0; g < DAT_0005f0b4; g++) {
        if (DAT_0005f0b8[g].f4) {
            for (j = 0; j < DAT_0005f0b8[g].count; j++) {
                if (DAT_0005f0b8[g].tab[j].f2 == key && !DAT_0005f0b8[g].tab[j].ld && (found == -1 || DAT_0005f0b8[g].tab[j].f3 < best)) {
                    best = DAT_0005f0b8[g].tab[j].f3;
                    found = j;
                    fg = g;
                }
            }
        }
    }
    if (found == -1) return 0;
    FUN_0003efd0(found, fg);
    return 1;
}

#pragma pack()
/* ---- from build/var/mod/parts/p3f184.c */
extern void FUN_0003e9cc(void); /* module prototype */
extern void FUN_0003ecb4(int idx, int grp); /* module prototype */
#define E T35_E
#define S T35_S
#define DAT_0005f0b8 ((struct S *)DAT_0005f0b8)
/* FUN_0003f184, FUN_0003f1b4, FUN_0003f260: set/clear the highlight bit of glyph a in font b, highlight the current glyph (one -oa module: -oe inlines FUN_0003f184 into FUN_0003f260) */
struct E { unsigned char f, x, g, r[6]; };
struct S { int a, b, c; struct E *t; };

 extern int DAT_0005f0c0;
void FUN_0003f184(int a, int b)
{
    if (DAT_0005f0b8[b].t[a].g) DAT_0005f0b8[b].t[a].f |= 0x10;
}


 extern int DAT_0005f0c0;

void FUN_0003f1b4(int a, int b)
{
    if (DAT_0005f0b8[b].t[a].g) DAT_0005f0b8[b].t[a].f &= ~0x10;
}

#undef DAT_0005f0b8
#undef E
#undef S
/* ---- from build/var/mod/parts/p3f1e4.c */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003f1e4 @ 0003f1e4: clear the highlight flag of every menu entry except the current one (-oa module:
   the two globals are cached in registers and written back at the end) */
extern int DAT_0005f0b4, DAT_0005f0c0; 
void FUN_0003f1e4(void)
{
    int j, g;
    for (g = 0; g < DAT_0005f0b4; g++) {
        for (j = 0; j < *(int *)(DAT_0005f0b8 + g * 16 + 8); j++) {
            if (j != DAT_0005f0c0) {
                unsigned char *p = *(unsigned char **)(DAT_0005f0b8 + g * 16 + 0xc) + j * 9;
                if (p[2]) *p &= ~0x10;
            }
        }
    }
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3f260.c */
extern void FUN_0003e9cc(void); /* module prototype */
extern void FUN_0003ecb4(int idx, int grp); /* module prototype */
#define DAT_0005f0b8 ((struct S *)DAT_0005f0b8)

 extern int DAT_0005f0c0;

void FUN_0003f260(void)
{
    FUN_0003e9cc();
    FUN_0003ecb4(DAT_0005f0c0, 0);
    FUN_0003f184(DAT_0005f0c0, 0);
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3f29c.c */
extern void FUN_0003ecb4(int idx, int grp); /* module prototype */
#define DAT_0005f0b8 ((char *)DAT_0005f0b8)
/* FUN_0003f29c @ 0003f29c: glyph entry a of font b: its data pointer when the entry is in use, else 0 */
 
int *FUN_0003f29c(int a, int b)
{
    unsigned char *p;
    FUN_0003ecb4(a, b);
    p = *(unsigned char **)(DAT_0005f0b8 + b * 16 + 12) + a * 9;
    if (p[2] == 1) return *(int **)(p + 5);
    return 0;
}

#undef DAT_0005f0b8
/* ---- from build/var/mod/parts/p3f2e0.c */
extern void FUN_0003e7f0(char *name, int n); /* module prototype */
/* FUN_0003f2e0, FUN_0003f2ec: critical-error handler and game start-up (error handler, timer, sound config, mouse, sound driver) */
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define FUN_0003e7f0 ((void (*)(int, int))FUN_0003e7f0)
#define FUN_000412ec ((void (*)(void *, int, int))FUN_000412ec)
extern unsigned DAT_0005f6f8; extern short DAT_0005ef53; extern unsigned char DAT_0005ef3e, DAT_0005ef68, DAT_0005ef3c; extern int DAT_0005f0c0; extern short *DAT_0005f04c; extern int _argc; extern char **_argv;
extern char *DAT_0005f050;
extern unsigned short FUN_000390d0(unsigned short); extern void FUN_00040bb4(void), FUN_000412dc(int), FUN_00037d20(char *, int, int, int, int), FUN_000382bc(char *, int, int, int, int), FUN_00043d18(int, int), FUN_00043d38(int, int);
extern void *FUN_0004104c(int); extern int FUN_000412a0(char *); extern short *FUN_00043b44(void);
#define SW(o) (*(short *)(p + (o)))
/* FUN_0003f2e0 @ 0003f2e0: _harderr handler: remember the error code, ignore the error */
int __far FUN_0003f2e0(unsigned deverr, unsigned errcode, unsigned __far *devhdr)
{
    DAT_0005f6f8 = errcode;
    return 0;
}

extern unsigned DAT_0005f6f8; extern short DAT_0005ef53; extern unsigned char DAT_0005ef3e, DAT_0005ef68, DAT_0005ef3c; extern int DAT_0005f0c0; extern short *DAT_0005f04c; extern int _argc; extern char **_argv;
extern char *DAT_0005f050;
extern unsigned short FUN_000390d0(unsigned short); extern void FUN_00040bb4(void), FUN_000412dc(int), FUN_00037d20(char *, int, int, int, int), FUN_000382bc(char *, int, int, int, int), FUN_00043d18(int, int), FUN_00043d38(int, int);
extern void *FUN_0004104c(int); extern int FUN_000412a0(char *); extern short *FUN_00043b44(void);

/* FUN_0003f2ec @ 0003f2ec */
void FUN_0003f2ec(int a, int b)
{
    char *p; int f;
    DAT_0005ef53 = 0x182;
    DAT_0005ef3e = 0xc;
    DAT_0005ef68 = 1;
    DAT_0005ef3c = 0xff;
    DAT_0005f0c0 = -1;
    _harderr(FUN_0003f2e0);
    FUN_00040bb4();
    FUN_000390d0(0);
    if (_argc != 2) {
        DAT_0005f050 = FUN_0004104c(0x100);
        memset(DAT_0005f050, 0, 0x100);
    } else DAT_0005f050 = (char *)atoi(_argv[1]);
    if (!DAT_0005f050[0x64]) {
        f = FUN_000412a0("sound.cfg");
        FUN_000412ec(DAT_0005f050, 0x3b, f);
        FUN_000412dc(f);
        DAT_0005f050[0x64] = 1;
        DAT_0005f050[0x66] = 1;
    }
    DAT_0005f04c = FUN_00043b44();
    p = DAT_0005f050;
    if (SW(8) != 0x71) {
        if (SW(8) == 0x79) {
            outp(SW(0xa) + 4, 0x83);
            outp(SW(0xa) + 5, 0xb);
        }
        if (SW(0x14)) FUN_00037d20(p + 0x24, SW(0xa), SW(0xc), SW(0xe), SW(0x10));
        FUN_000382bc(p + 0x16, SW(0), SW(2), SW(4), SW(6));
    }
    FUN_00043d18(0, 0x27e);
    FUN_00043d38(0, 0xc7);
    if (a) FUN_0003e7f0(a, b);
}

#undef FUN_0003e7f0
#undef FUN_000412ec
#undef SW
/* ---- from build/var/mod/parts/p3f468.c */
extern void FUN_0003ecb4(int idx, int grp); /* module prototype */
/* FUN_0003f468 @ 0003f468: select menu entry b of the current menu */
#pragma pack(1)
/* struct RE: defined above */
#pragma pack()
/* struct RF: defined above */

extern int DAT_0005f0c0; extern char *DAT_0005f0bc; extern struct RF *DAT_0005f0b8; extern unsigned char DAT_0005f0c4;
void FUN_0003f468(char *a, int b, char c)
{
    if (DAT_0005f0c0 != -1) { if (DAT_0005f0b8->tab[DAT_0005f0c0].f2) DAT_0005f0b8->tab[DAT_0005f0c0].ld = 0; }
    DAT_0005f0c0 = b;
    FUN_0003ecb4(b, 0);
    if (DAT_0005f0b8->tab[DAT_0005f0c0].f2) DAT_0005f0b8->tab[DAT_0005f0c0].ld = 1;
    DAT_0005f0bc = a;
    DAT_0005f0c4 = c;
}

#pragma pack()
/* ---- from build/var/mod/parts/p3f4e0.c */
extern void FUN_0003ea9c(void); /* module prototype */
/* FUN_0003f4e0 @ 0003f4e0: shut down sound, video and input */
#include "snd.h"
extern short *FUN_00043b44(void); extern void FUN_000385d4(void), FUN_00037ecc(void), FUN_00040c38(void);
extern int DAT_0005ee78, DAT_0005ee40; extern struct RF *DAT_0005f0b8; extern char *DAT_0005f050;
void FUN_0003f4e0(void)
{
    int snd; char *p;
    FUN_00043b44();
    p = DAT_0005f050;
    snd = DAT_0005ee78 | DAT_0005ee40;
    if (*(short *)(p + 8) != 0x71) {
        FUN_000385d4();
        if (*(short *)(p + 0x14)) FUN_00037ecc();
        if (snd) FUN_000462be(0);
    }
    if (DAT_0005f0b8) FUN_0003ea9c();
    FUN_00040c38();
}

/* ---- from build/var/mod/parts/p3f540.c */
extern void FUN_0003f4e0(void); /* module prototype */
extern int FUN_0003f5f4(char *msg, int mode); /* module prototype */
/* FUN_0003f540 @ 0003f540, FUN_0003f554 @ 0003f554, FUN_0003f860 @ 0003f860, FUN_0003f868 @ 0003f868: shutdown
   and the quit key.  One file because FUN_0003f868 calls FUN_0003f554(1), which 10.0a expands one level: the
   nested FUN_0003f540 call stays a call (recipe 26), while FUN_0003f554 itself expands FUN_0003f540. */
#include <string.h>
extern void FUN_000476f0(void); void exit(int);
extern void FUN_000390f4(int);
extern void (*DAT_0005f0c8)(void); extern unsigned char DAT_0005f0b1, DAT_0005f0b2; extern char *DAT_0005f0bc;


/* FUN_0003f540: shut the video down and exit */
void FUN_0003f540(int code) { FUN_000476f0(); exit(code); }

extern void FUN_000476f0(void); void exit(int);
extern void FUN_000390f4(int);
extern void (*DAT_0005f0c8)(void); extern unsigned char DAT_0005f0b1, DAT_0005f0b2; extern char *DAT_0005f0bc;



/* FUN_0003f554: shut the display down; with quit set also exit to DOS */
void FUN_0003f554(int quit)
{
    FUN_000390f4(0xff);
    FUN_0003f4e0();
    if (quit) FUN_0003f540(1);
}

/* ---- from build/var/mod/parts/p3f580.c */
extern void FUN_0003f4e0(void); /* module prototype */
extern int FUN_0003f5f4(char *msg, int mode); /* module prototype */
/* FUN_0003f580 @ 0003f580: fatal error: show msg in the game's own box when possible, shut down, print it and exit(1) */
 extern void FUN_000390f4(int), FUN_000411e8(char *), FUN_000476f0(void); void exit(int);
extern int DAT_0005f0c0; extern unsigned char DAT_0005f0b1;
void FUN_0003f580(char *msg)
{
    int k;
    if (DAT_0005f0c0 != -1 && !(DAT_0005f0b1 & 0x80)) {
        k = FUN_0003f5f4(msg, 0);
        FUN_000390f4(0xff);
        FUN_0003f4e0();
        if (k == 0x54) FUN_000411e8(msg);
    } else {
        FUN_000390f4(0xff);
        FUN_0003f4e0();
        FUN_000411e8(msg);
    }
    FUN_000476f0();
    exit(1);
}

/* ---- from build/var/mod/parts/p3f5f4.c */
extern int FUN_0003e614(unsigned t, int flags); /* module prototype */
#define FUN_000391b0 ((void (*)(unsigned char))FUN_000391b0)
/* FUN_0003f5f4 @ 0003f5f4: message box: save the top strip, print msg centred, wait (mode > 1: timed, 1: Y/N, 0: space or T), restore; returns the key (module 0x3e340 is -oa. Frame slots of pg/lim: no register is involved (Q1 no clobber, Q2 equal live ranges, Q4 both stay in memory across the calls); Q3 the slot order follows the order of the conflict list, which -oa extends by the globals; declaration order fitted with tools/modclimb.py under -oa, 14 compiles) */
extern void FUN_000411e8(char *), FUN_000392bc(void *, int, int, int, int), FUN_00039cec(int, int, int, int, int), FUN_000404f4(int, int), FUN_000403c8(char *, int), FUN_0003a104(int), FUN_0003932c(void *, int, int, int, int), FUN_000410b0(void *);
extern int FUN_0004058c(void), FUN_00040594(void), FUN_00040288(char *, int), FUN_00040aec(void); extern void *FUN_0004104c(int);
extern unsigned char DAT_0005ef3c, DAT_0005ef4d, DAT_0005ef4e, DAT_0005ef3e, DAT_0005f0c4; extern int DAT_0005f0c0; extern short DAT_0005ef47;
int FUN_0003f5f4(char *msg, int mode)
{
    int oy; unsigned char pg; int ox; int key, w, k, h; unsigned char lim; void *save;
    if (DAT_0005ef3c != 0xff) {
    lim = 0xff;
    pg = DAT_0005ef4d;
    ox = FUN_0004058c();
    oy = FUN_00040594();
    w = 0x140;
    if (DAT_0005ef3c != 5 && DAT_0005ef4d != DAT_0005ef4e) FUN_000391b0(DAT_0005ef4e);
    else if (DAT_0005ef3c == 5) {
        FUN_000391b0(0);
        w -= 8;
    }
    save = FUN_0004104c(DAT_0005ef3e * 0x140);
    w--;
    FUN_000392bc(save, 0, 0, DAT_0005ef3e, 0x140);
    for (k = 0; k < DAT_0005ef3e; k++) FUN_00039cec(k, 0, k, w, DAT_0005f0c4 - k);
    if (DAT_0005f0c0 != -1 && msg) {
        FUN_000404f4(0, 0xa0 - FUN_00040288(msg, DAT_0005f0c0) / 2);
        FUN_000403c8(msg, DAT_0005f0c0);
    }
    if (DAT_0005ef3c == 5 && DAT_0005ef4e) {
        lim = DAT_0005ef47;
        h = 0xc8 - DAT_0005ef3e;
        if (DAT_0005ef47 > h) FUN_0003a104(h);
    }
    if (mode > 1) FUN_0003e614(mode, 0);
    else if (mode == 1) {
        do key = FUN_00040aec(); while (key != 0x4e && key != 0x59 && key != 0x53);
        if (key == 0x53) key = 0x59;
    } else {
        do key = FUN_00040aec(); while (key != 0x20 && key != 0x54);
    }
    FUN_0003932c(save, 0, 0, DAT_0005ef3e, 0x140);
    FUN_000410b0(save);
    FUN_000391b0(pg);
    FUN_000404f4(ox, oy);
    if (DAT_0005ef3c == 5 && lim != 0xff && DAT_0005ef4e) FUN_0003a104(lim);
    return key;
    }
    FUN_000411e8(msg);
    return 0;
}

#undef FUN_000391b0
/* ---- from build/var/mod/parts/p3f83c.c */
/* FUN_0003f83c @ 0003f83c: set the top bit of the display flags */
extern unsigned char DAT_0005f0b1;
void FUN_0003f83c(void) { DAT_0005f0b1 |= 0x80; }

/* ---- from build/var/mod/parts/p3f844.c */
/* FUN_0003f844 @ 0003f844: clear the top bit of the display flags */
extern unsigned char DAT_0005f0b1;
void FUN_0003f844(void) { DAT_0005f0b1 &= 0x7f; }

/* ---- from build/var/mod/parts/p3f84c.c */
/* FUN_0003f84c @ 0003f84c: true when the top display flag is clear */
extern unsigned char DAT_0005f0b1;
int FUN_0003f84c(void) { return (DAT_0005f0b1 & 0x80) == 0; }

/* ---- from build/var/mod/parts/p3f860.c */
extern void FUN_0003f4e0(void); /* module prototype */
extern int FUN_0003f5f4(char *msg, int mode); /* module prototype */
extern void FUN_000476f0(void); void exit(int);
extern void FUN_000390f4(int);
extern void (*DAT_0005f0c8)(void); extern unsigned char DAT_0005f0b1, DAT_0005f0b2; extern char *DAT_0005f0bc;



/* FUN_0003f868: poll the quit key: run the idle hook, and when the quit request is pending ask "Quit <name> (Y/N) ?";
   on Y shut down and exit */
void FUN_0003f868(void);
void FUN_0003f860(void) { DAT_0005f0b1 |= 1; FUN_0003f868(); }

extern void FUN_000476f0(void); void exit(int);
extern void FUN_000390f4(int);
extern void (*DAT_0005f0c8)(void); extern unsigned char DAT_0005f0b1, DAT_0005f0b2; extern char *DAT_0005f0bc;


void FUN_0003f868(void)
{
    char buf[80];
    if (DAT_0005f0c8) DAT_0005f0c8();
    if (DAT_0005f0b1 && !(DAT_0005f0b1 & 0x80) && !DAT_0005f0b2) {
        DAT_0005f0b2 = 1;
        DAT_0005f0b1 = 0;
        strcpy(buf, "Quit ");
        if (DAT_0005f0bc) strcat(buf, DAT_0005f0bc);
        strcat(buf, " (Y/N) ?");
        if (FUN_0003f5f4(buf, 1) == 'Y') FUN_0003f554(1);
        DAT_0005f0b2 = 0;
        DAT_0005f0b1 = 0;
    }
}

/* ---- module data _DATA 0005f04c-0005f0d4 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
short *DAT_0005f04c = 0;
char *DAT_0005f050 = 0;
unsigned char DAT_0005f054[13] = { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 };
unsigned char DAT_0005f061[80] = { 0 };
unsigned char DAT_0005f0b1 = 0;
unsigned char DAT_0005f0b2 = 0;
unsigned char DAT_0005f0b3[1] = { 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005f0b4 = 0;
struct RF *DAT_0005f0b8 = 0;
char *DAT_0005f0bc = 0;
int DAT_0005f0c0 = -1;
unsigned char DAT_0005f0c4 = 0;
unsigned char DAT_0005f0c5[3] = { 0, 0, 0x5f };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
void (*DAT_0005f0c8)(void) = 0;
void (*DAT_0005f0cc)(int, int) = 0;
unsigned char DAT_0005f0d0 = 0;
/* ---- end of module data _DATA */
