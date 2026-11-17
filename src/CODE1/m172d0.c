/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
volatile unsigned char B000389cf_eu;
unsigned char B000389ce_eu;
short B000389cc_eu;   /* no code references it */
char *B000389c8_eu;
char *B000389c4_eu;
int B000389c0_eu;   /* no code references it */
int B000389bc_eu;   /* no code references it */
int B000389b8_eu;
int B000389b4_eu;
int B000389a8_eu[3];   /* no code references it */
int B000389a4_eu;
int B000389a0_eu;   /* no code references it */
int B0003899c_eu;
int B00038998_eu;   /* no code references it */
unsigned char *B00038994_eu;
int B00038990_eu;
int B0003898c_eu;
unsigned char *B00038988_eu;
/* BSS end */
/* Module: FUN_000172d0, FUN_000172e0, FUN_00017328, FUN_00017360, FUN_0001738c, FUN_0001746c, FUN_000174d0, FUN_0001756c, FUN_000175f0, FUN_0001762c, FUN_0001767c, FUN_00017830, FUN_00017844, FUN_00017868, FUN_00017944, FUN_000179c8, FUN_00017a64, FUN_00017a84, FUN_00017ab4, FUN_00017afc, FUN_00017b50, FUN_00017b74, FUN_00017b94, FUN_00017c0c, FUN_00017cb0, FUN_00017d68, FUN_00017d80, FUN_00017ddc, FUN_00017de8, FUN_00017df4, FUN_00017e04, FUN_00017e44, FUN_00017e6c */
#include "vmode.h"
#define DAT_000323d7 (VID_000323d4.w)
/* ---- from build/var/mod/parts/p172d0.c */
/* FUN_000172d0 */
extern int DAT_00032904;
void FUN_000172d0(int v) { DAT_00032904 = v; }

/* ---- from build/var/mod/parts/p172e0.c */
/* FUN_000172e0: refill the read buffer up to the next 1 KB file boundary */
extern int FUN_0001633c(int, int, int), FUN_00016304(void *, int, int); extern int DAT_00032904, DAT_00032874; extern unsigned char DAT_00032470[], *DAT_00032870;
void FUN_000172e0(void) { int n = 0x400 - (FUN_0001633c(0, 1, DAT_00032904) & 0x3ff); DAT_00032874 = FUN_00016304(DAT_00032470, n, DAT_00032904); DAT_00032870 = DAT_00032470; }

/* ---- from build/var/mod/parts/p17328.c */
/* FUN_00017328 */
extern int FUN_00016304(void *, int, int); extern int DAT_00032874, DAT_00032904; extern unsigned char DAT_00032470[], *DAT_00032870;
void FUN_00017328(void) { if (!DAT_00032874) { DAT_00032874 = FUN_00016304(DAT_00032470, 0x400, DAT_00032904); DAT_00032870 = DAT_00032470; } }

/* ---- from build/var/mod/parts/p17360.c */
/* FUN_00017360 */
extern void FUN_00017328(void); extern int DAT_00032874; extern unsigned char *DAT_00032870;
unsigned short FUN_00017360(void) { unsigned char *p; unsigned short c; if (!DAT_00032874) FUN_00017328(); p = DAT_00032870; DAT_00032874--; c = *p; DAT_00032870 = p + 1; return c; }

/* ---- from build/var/mod/parts/p1738c.c */
/* FUN_0001738c */
extern void FUN_00019ae8(void), FUN_0001a57c(int, int, unsigned char *, void *, int); extern volatile unsigned char B000389cf_eu; extern unsigned char B000389ce_eu; extern char *B000389c8_eu, *B000389c4_eu; extern int B000389b8_eu, B000389a4_eu, B000389b4_eu, B0003899c_eu; extern unsigned char *B00038994_eu;
void FUN_0001738c(char c) { if (B000389cf_eu) { if (!B000389ce_eu) { B000389c8_eu[B000389b8_eu] = c; B000389b8_eu++; if (B000389b8_eu >= B000389a4_eu) { FUN_00019ae8(); FUN_0001a57c(B000389b4_eu, B000389a4_eu, (unsigned char *)B000389c8_eu, (void *)B0003899c_eu, B00038994_eu[5]); B000389b8_eu = 0; B000389b4_eu++; } if (*(short *)B00038994_eu <= B000389b4_eu) B000389ce_eu = 1; } } else if (!B000389ce_eu) { B000389c4_eu[B000389b8_eu] = c; B000389b8_eu++; if (B000389b8_eu >= B000389a4_eu) { FUN_00019ae8(); B000389b8_eu = 0; B000389ce_eu = 1; } } }

/* ---- from build/var/mod/parts/p1746c.c */
/* FUN_0001746c */
extern void FUN_0001db80(void);
void FUN_0001746c(int a, int b, int c, int d, unsigned char e) { B000389cf_eu = e; B000389ce_eu = 0; B00038994_eu = (unsigned char *)b; B000389b8_eu = 0; B000389b4_eu = 0; B000389a4_eu = d; B0003899c_eu = a; if (B000389cf_eu) B000389c8_eu = (char *)c; else B000389c4_eu = (char *)c; FUN_0001db80(); }

/* ---- from build/var/mod/parts/p174d0.c */
/* FUN_000174d0 */
void *memcpy(void *, const void *, unsigned); extern void FUN_00017328(void); extern int FUN_00016304(void *, int, int); extern int DAT_00032874, DAT_00032904; extern unsigned char *DAT_00032870, DAT_00032470[];
void FUN_000174d0(int n, unsigned char *dst) { int m; FUN_00017328(); if (DAT_00032874 >= n) { memcpy(dst, DAT_00032870, n); DAT_00032870 += n; } else { m = DAT_00032874; memcpy(dst, DAT_00032870, m); n -= m; DAT_00032874 = FUN_00016304(DAT_00032470, 0x400, DAT_00032904); memcpy(m + dst, DAT_00032470, n); DAT_00032870 = DAT_00032470 + n; } DAT_00032874 -= n; }

/* ---- from build/var/mod/parts/p1756c.c */
/* FUN_0001756c: next byte of the run-length coded stream */
void *memset(void *, int, unsigned); extern unsigned short FUN_00017360(void); extern void FUN_000174d0(int, unsigned char *); extern unsigned char DAT_00032878, DAT_00032880[], DAT_00032881[], *DAT_0003287c;
unsigned char FUN_0001756c(void) { signed char c; unsigned char v, *p; if (!DAT_00032878) { DAT_0003287c = DAT_00032880; c = FUN_00017360(); if (c >= 0) { DAT_00032878 = c + 1; FUN_000174d0(DAT_00032878, DAT_00032880); } else { DAT_00032878 = -c + 1; v = FUN_00017360(); DAT_00032880[0] = v; memset(DAT_00032881, v, DAT_00032878 - 1); } } p = DAT_0003287c; DAT_00032878--; v = *p; DAT_0003287c = p + 1; return v; }

/* ---- from build/var/mod/parts/p175f0.c */
/* FUN_000175f0 */
extern unsigned char FUN_0001756c(void);
void FUN_000175f0(unsigned char *dst, int w, int h) { int k, n = w * h * 8; for (k = 0; k < n; k++, dst++) *dst = FUN_0001756c(); }

/* ---- from build/var/mod/parts/p1762c.c */
/* FUN_0001762c */
extern unsigned short FUN_00017360(void);
void FUN_0001762c(unsigned char *dst, int w, int h) { int k, n = w * h * 8; for (k = 0; k < n; k++, dst++) *dst = FUN_00017360(); }

/* ---- from build/var/mod/parts/p1767c.c */
/* FUN_0001767c @ 0001767c: load the sprite set of resource res from file fd: allocate the sprite block and a frame buffer, then read each frame raw (comp 0), RLE (1) or LZW (3) and pack it (CODE.1 copy of CODE.2 FUN_0003fd9c) */
#pragma pack(1)
struct SH { short n, w; unsigned char h, f, comp, fr; };
struct SR { short size, n, w; unsigned char h, f; };
#pragma pack()
extern int DAT_00032904;
extern void FUN_00019814(char *), FUN_000172e0(void), FUN_00019ae8(void), FUN_0001762c(unsigned char *, int, int), FUN_000175f0(unsigned char *, int, int);
extern void FUN_00017240(void *), FUN_0001dc90(struct SR *);
extern int FUN_0001a558(int, int, int, int, int); extern void *FUN_000171c8(int);
struct SR *FUN_0001767c(char *res, int fd)
{
    int sz; unsigned char *buf; struct SH *h; struct SR *r; int i; int k; int len;
    DAT_00032904 = fd;
    h = *(struct SH **)(res + 5);
    if (h->n == 0) FUN_00019814("Sprite file has no sprites in it");
    sz = FUN_0001a558(h->n, h->w, h->h, 8, h->f);
    r = FUN_000171c8(sz + 8);
    r->size = sz / h->n;
    r->w = h->w;
    r->h = h->h;
    r->n = h->n;
    r->f = (h->f != 0xff) << 7;
    len = h->w * h->h * 8;
    buf = FUN_000171c8(len);
    if (!buf) FUN_00019814("Sprites in file too large to load");
    FUN_000172e0();
    switch (h->comp) {
    case 0:
        for (i = 0; i < h->n; i++) {
            FUN_00019ae8();
            FUN_0001762c(buf, h->w, h->h);
            FUN_0001a57c(i, len, buf, r, h->f);
        }
        break;
    case 1:
        for (k = 0; k < h->n; k++) {
            FUN_00019ae8();
            FUN_000175f0(buf, h->w, h->h);
            FUN_0001a57c(k, len, buf, r, h->f);
        }
        break;
    case 2:
        FUN_00019814("Can't read LZW, not active");
        break;
    case 3:
        FUN_0001746c((int)r, (int)h, (int)buf, len, 1);
        break;
    default:
        FUN_00019814("Unknown compression in sprite file");
        break;
    }
    FUN_00017240(buf);
    if (h->fr) FUN_0001dc90(r);
    return r;
}

#pragma pack()
/* ---- from build/var/mod/parts/p17830.c */
/* FUN_00017830 */
void FUN_00017830(int a) { FUN_00017240((void *)a); }

/* ---- from build/var/mod/parts/p17844.c */
#define SH T12_SH
/* FUN_00017844 @ 00017844: byte size of a sprite: w * h + 8 header bytes, one more when the flag bit 7 of byte 7 is set */
struct SH { short w, h; char pad[3]; unsigned char f; };
short FUN_00017844(struct SH *p) { short n = p->w * p->h + 8; if (p->f & 0x80) n++; return n; }

#undef SH
/* ---- from build/var/mod/parts/p17868.c */
struct S { unsigned short n, one, w; unsigned char h, key; };
extern void FUN_00019814(char *), FUN_000166c0(unsigned char *, int, int, int, int); extern void *FUN_000171c8(int);
struct S *FUN_00017868(int pg, int x, int y, int w, int key) { unsigned short n; struct S *h; if ((x & 3) || (w & 7)) FUN_00019814("Invalid params passed into GrabSprite"); n = FUN_0001a558(1, y, w / 8, 8, key); h = FUN_000171c8(n + 8); h->n = n; h->w = y; h->h = w / 8; h->one = 1; h->key = (key != 0xff) << 7; FUN_000166c0((unsigned char *)(h + 1) + (key != 0xff), pg, x, y, w); if (key != 0xff) *(unsigned char *)(h + 1) = key; return h; }

/* ---- from build/var/mod/parts/p17944.c */
#define SR T14_SR
struct SR { short size, n, w; unsigned char hb, flag; unsigned char data[1]; };
#include "records.h"
extern struct PC B000367f8_eu[4];
extern int DAT_000304cc, DAT_000304d0; 
extern void FUN_00011464(int, int, int, int, int, int, int, int, int, int, int, int, int), FUN_000115b0(int, int, int, int), FUN_000166c0(unsigned char *, int, int, int, int), FUN_000165c0(int, int, int, int), FUN_000165e8(int, int, int, int);
extern unsigned FUN_0001043c(void);
/* FUN_00017944 @ 00017944: fill in the sprite header at s (size, one frame, width, height/8, key flag) and grab the w x h image at (b, c) into it */
struct SR *FUN_00017944(struct SR *s0, int a, int b, int c, int w, int h, int key) { struct SR *s = s0; s->size = a; s->w = w; s->hb = h / 8; s->n = 1; s->flag = (key != 0xff) << 7; FUN_000166c0(s->data + (key != 0xff), b, c, w, h); if (key != 0xff) s->data[0] = key; return s; }

#undef SR
/* ---- from build/var/mod/parts/p179c8.c */
/* FUN_000179c8: duplicate a resource: copy its data block into a fresh buffer and register a copy of the 9-byte header (the interrupt-off flag is only set on one path, as in the original) */
void *memcpy(void *, const void *, unsigned);
extern int FUN_00019ad4(void); extern void FUN_00019ab4(void), FUN_00019ac4(void);
unsigned char *FUN_000179c8(char *hdr, int b)
{
    char loc[12]; volatile char flag; short *t; unsigned char *p; char *s; int k;
    if (FUN_00019ad4()) {
        flag = 1;
        FUN_00019ab4();
    }
    t = (short *)(*(char **)(hdr + 5) + *(short *)(hdr + 3) - 8);
    p = FUN_000171c8(*t + 4);
    for (k = 0, s = *(char **)(hdr + 5); k < *t; k++, s++) p[k + 4] = *s;
    memcpy(loc, hdr, 9);
    *(short *)(loc + 3) = 8;
    *(short **)(loc + 5) = t;
    *(int *)p = FUN_0001767c(loc, b);
    if (flag) FUN_00019ac4();
    return p;
}

/* ---- from build/var/mod/parts/p17a64.c */
/* FUN_00017a64: release a handle block: free its first handle, then the block */
void FUN_00017a64(int *p) { int *q = p; FUN_00017830(*q); FUN_00017240(p); }

/* ---- from build/var/mod/parts/p17a84.c */
#include <i86.h>
struct RF { int fh, n, count; void *tab; };
extern int DAT_00032b04; extern struct RF *DAT_00032b08;
extern void FUN_0001df13(int), FUN_000187d8(int, int), FUN_0001df73(void), FUN_000161d0(int), FUN_0001cbf0(int), FUN_00014dc4(void), FUN_00015014(int);
#pragma aux FUN_0001cbf0 aborts;
extern int FUN_00014978(void), FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_00017a84 @ 00017a84: add k to every character of s (simple text cipher); returns s */
char *FUN_00017a84(char *s, char k) { char *r; r = s; if (s) while (*s) { *s += k; s++; } return r; }

/* ---- from build/var/mod/parts/p17ab4.c */
/* FUN_00017ab4 @ 00017ab4: pixel width of string s in font font (module compiled with -os) */
extern unsigned char *FUN_0001954c(int, int); extern unsigned char *B00038988_eu;
int FUN_00017ab4(signed char *s, int font) { int w; B00038988_eu = FUN_0001954c(font, 0); w = 0; if (s) while (*s) { w += (B00038988_eu + 4)[*s]; s++; } return w; }

/* ---- from build/var/mod/parts/p17afc.c */
#define RF T19_RF
#pragma pack(1)
struct RE { unsigned char lo, f1, f2; unsigned short f3; int f5; };
#pragma pack()
struct RF { int fh, n, count; struct RE *tab; };
extern int DAT_0003246c, DAT_00032b04;
extern unsigned char *FUN_0001954c(int, int); extern void FUN_0001da18(void), FUN_0001da1a(void), FUN_0001862c(int, int, unsigned char *);
/* FUN_00017afc @ 00017afc: pixel width of the first n characters of s in font font */
int FUN_00017afc(signed char *s, int font, int n) { int w; B00038988_eu = FUN_0001954c(font, 0); w = 0; if (s) while (*s && n) { w += (B00038988_eu + 4)[*s]; s++; n--; } return w; }

#undef RF
#pragma pack()
/* ---- from build/var/mod/parts/p17b50.c */
/* FUN_00017b50 */
extern unsigned char *FUN_0001954c(int, int);
int FUN_00017b50(signed char c, int id) { unsigned char *p = FUN_0001954c(id, 0); B00038988_eu = p; return p[c + 4]; }

/* ---- from build/var/mod/parts/p17b74.c */
#define SR T21_SR
extern short *DAT_00032a9c;
extern void FUN_000185d4(int, int, int, int, int), FUN_0001864c(int, int, int, int, int), FUN_0001a010(int, int, int), FUN_0001a2b0(int, int);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_00017b74 @ 00017b74: select font n and return its height */
int FUN_00017b74(int n) { B00038988_eu = FUN_0001954c(n, 0); return (*(unsigned short **)B00038988_eu)[2]; }

#undef SR
/* ---- from build/var/mod/parts/p17b94.c */
struct CHR { char b[0x248]; };
extern int DAT_00032908, B0003898c_eu, B00038990_eu, DAT_000304cc, DAT_000304d0; 
extern unsigned char *FUN_0001954c(int, int); extern void FUN_00016824(int, int, int, int, int), FUN_000167c8(int, int, int, int);
extern void FUN_00011464(int, int, int, int, int, int, int, int, int, int, int, int, int), FUN_000115b0(int, int, int, int);
/* FUN_00017b94 @ 00017b94: draw character c in font font at the text cursor and advance it (CODE.1 copy of CODE.2 FUN_00040354) */
void FUN_00017b94(int c, int font) { B00038988_eu = FUN_0001954c(font, 0); if (DAT_00032908) FUN_00016824((signed char)c, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu, DAT_00032908); else FUN_000167c8((signed char)c, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu); B0003898c_eu += *(B00038988_eu + 4 + (signed char)c); }

/* ---- from build/var/mod/parts/p17c0c.c */
/* FUN_00017c0c */
extern unsigned char *FUN_0001954c(int, int); extern void FUN_00016824(int, int, int, int, int), FUN_000167c8(int, int, int, int); extern int DAT_00032908, B0003898c_eu, B00038990_eu;
void FUN_00017c0c(signed char *s, int font) { B00038988_eu = FUN_0001954c(font, 0); if (s) while (*s) { if (DAT_00032908) FUN_00016824(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu, DAT_00032908); else FUN_000167c8(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu); B0003898c_eu += (B00038988_eu + 4)[*s]; s++; } }

/* ---- from build/var/mod/parts/p17cb0.c */
extern int DAT_00032908, B0003898c_eu, B00038990_eu;
extern unsigned char *FUN_0001954c(int, int); extern void FUN_00016824(int, int, int, int, int), FUN_000167c8(int, int, int, int);
/* FUN_00017cb0 @ 00017cb0: draw at most n characters of s in font font at the text cursor (CODE.1 copy of CODE.2 FUN_00040458) */
void FUN_00017cb0(signed char *s, int font, int n)
{
    B00038988_eu = FUN_0001954c(font, 0);
    if (s) while (*s && n) {
        if (DAT_00032908) FUN_00016824(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu, DAT_00032908);
        else FUN_000167c8(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu);
        B0003898c_eu += *(B00038988_eu + 4 + *s);
        s++;
        n--;
    }
}

/* ---- from build/var/mod/parts/p17d68.c */
/* FUN_00017d68 */
extern int B00038990_eu, B0003898c_eu;
void FUN_00017d68(int a, int b) { B00038990_eu = a; B0003898c_eu = b; }

/* ---- from build/var/mod/parts/p17d80.c */
/* FUN_00017d80 */
extern unsigned char *FUN_0001954c(int, int); extern int FUN_00017ab4(char *, int); extern void FUN_00017c0c(char *, int); extern int B00038990_eu, B0003898c_eu;
void FUN_00017d80(int x, int y, int w, char *s, int font) { if (s) { B00038988_eu = FUN_0001954c(font, 0); B00038990_eu = x; B0003898c_eu = y + ((w - FUN_00017ab4(s, font)) >> 1); FUN_00017c0c(s, font); } }

/* ---- from build/var/mod/parts/p17ddc.c */
/* FUN_00017ddc */
extern int B00038990_eu;
int FUN_00017ddc(void) { return B00038990_eu; }

/* ---- from build/var/mod/parts/p17de8.c */
/* FUN_00017de8 */
extern int B0003898c_eu;
int FUN_00017de8(void) { return B0003898c_eu; }

/* ---- from build/var/mod/parts/p17df4.c */
/* FUN_00017df4 */
extern int DAT_00032908;
void FUN_00017df4(int v) { DAT_00032908 = v; }

/* ---- from build/var/mod/parts/p17e04.c */
/* FUN_00017e04 */
 
void FUN_00017e04(int a, int b, int c, int d) { if (c) { FUN_00017d68(a, b - FUN_00017ab4(c, d)); FUN_00017c0c(c, d); } }

/* ---- from build/var/mod/parts/p17e44.c */
/* FUN_00017e44 */

void FUN_00017e44(int a, int b, int c, int d) { FUN_00017d68(a, b); FUN_00017c0c(c, d); }

/* ---- from build/var/mod/parts/p17e6c.c */
extern int DAT_00032908, B0003898c_eu, B00038990_eu;
extern unsigned char *FUN_0001954c(int, int); extern void FUN_00017d68(int, int), FUN_00016824(int, int, int, int, int), FUN_000167c8(int, int, int, int);
/* FUN_00017e6c @ 00017e6c: draw s in font font from (x, y) while it fits in w pixels */
void FUN_00017e6c(int x, int y, unsigned char *s, int font, int w)
{
    FUN_00017d68(x, y);
    B00038988_eu = FUN_0001954c(font, 0);
    if (s) {
        w -= B00038988_eu[*s + 4];
        while (*s && w > 0) {
            if (DAT_00032908) FUN_00016824(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu, DAT_00032908);
            else FUN_000167c8(*s, B00038990_eu, B0003898c_eu, *(int *)B00038988_eu);
            B0003898c_eu += (B00038988_eu + 4)[*s];
            s++;
            w -= B00038988_eu[*s + 4];
        }
    }
}

/* ---- module data _DATA 00032470-00032918 (docs/data/dataown.CODE1.csv: inferred), generated by tools/data2c.py */
unsigned char DAT_00032470[1024] = { 0 };
unsigned char *DAT_00032870 = 0;
int DAT_00032874 = 0;
unsigned char DAT_00032878 = 0;
unsigned char DAT_00032879[3] = { 0x6f, 0x75, 0x72 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned char *DAT_0003287c = 0;
unsigned char DAT_00032880[1] = { 0 };
unsigned char DAT_00032881[131] = { 0 };
int DAT_00032904 = 0;
int DAT_00032908 = 0;
unsigned char DAT_0003290c[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
