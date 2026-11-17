/* Module: FUN_000184d0, FUN_000184e0, FUN_000184f8, FUN_00018514, FUN_000185a8, FUN_000185d4, FUN_0001862c, FUN_0001864c, FUN_000186a4, FUN_000186c4, FUN_000186f0, FUN_00018718, FUN_00018740, FUN_00018788, FUN_000187c4, FUN_000187d8, FUN_000188b0, FUN_000188d8, FUN_000188f8, FUN_00018918, FUN_00018940, FUN_00018950, FUN_00018960, FUN_00018978, FUN_00018a04, FUN_00018b94, FUN_00018be4, FUN_00018c40, FUN_00018cd4, FUN_00018d0c, FUN_00018df0, FUN_00018e08, FUN_00018e3c, FUN_000191d8, FUN_00019378, FUN_00019440, FUN_00019488, FUN_000194d0, FUN_00019520, FUN_0001954c, FUN_000195a8, FUN_000195bc, FUN_00019724, FUN_00019778, FUN_000197d4, FUN_000197e8, FUN_00019814, FUN_00019874, FUN_00019ab4, FUN_00019ac4, FUN_00019ad4, FUN_00019ae8, FUN_00019bc4 */
#include "vmode.h"
#define DAT_000323d4 (VID_000323d4.mode)   /* the object itself is the record */
#define DAT_000323d6 (VID_000323d4.f6)
#define DAT_000323d7 (VID_000323d4.w)
#define DAT_000323df (VID_000323d4.fdf)
#define DAT_000323e5 (VID_000323d4.fe5)
#define DAT_000323e6 (VID_000323d4.fe6)
#define DAT_000323eb (VID_000323d4.feb)
#define DAT_00032400 (VID_000323d4.f400)
#include <i86.h>
#include <stdlib.h>
/* ---- from build/var/mod/parts/p184d0.c */
/* FUN_000184d0 */
extern short *DAT_00032a9c;
int FUN_000184d0(void) { return *DAT_00032a9c; }

/* ---- from build/var/mod/parts/p184e0.c */
/* FUN_000184e0 */
extern short *DAT_00032a9c;
int FUN_000184e0(void) { return DAT_00032a9c[2] == 1; }

/* ---- from build/var/mod/parts/p184f8.c */
extern short *DAT_00032a9c; extern unsigned short **B00038988_eu; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a010(int, int, int), FUN_0001a2b0(int, int);
extern int FUN_0001d2ad(char *);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_000184f8 @ 000184f8 */
int FUN_000184f8(void) { if (*DAT_00032a9c) return DAT_00032a9c[1]; return 0; }

/* ---- from build/var/mod/parts/p18514.c */
#define SR T3_SR
struct SR { short size, n, w; unsigned char hb, flag; unsigned char data[1]; };
extern int DAT_000304cc, DAT_000304d0; extern unsigned char B0003680b_eu[];
extern void FUN_00011464(int, int, int, int, int, int, int, int, int, int, int, int, int), FUN_000115b0(int, int, int, int), FUN_000166c0(void *, int, int, int, int), FUN_000165c0(int, int, int, int), FUN_000165e8(int, int, int, int);
extern unsigned FUN_0001043c(void);
/* FUN_00018514 @ 00018514: outline of a w x h box at (x, y) in colour col */
void FUN_00018514(int x, int y, int w, int h, unsigned char col) { FUN_000165c0(x, y, h, col); if (w > 2) FUN_000165e8(x + 1, y, w - 2, col); if (w > 1) FUN_000165c0(x + w - 1, y, h, col); if (w > 2 && h > 1) FUN_000165e8(x + 1, y + h - 1, w - 2, col); }

#undef SR
/* ---- from build/var/mod/parts/p185a8.c */
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000185a8 @ 000185a8 */
void FUN_000185a8(int a, struct SB *r) { int i; for (i = 0; i < r->n; i++) FUN_0001ae0c(i, a, r); }

/* ---- from build/var/mod/parts/p185d4.c */
/* FUN_000185d4 @ 000185d4: draw frames first .. first+n-1 of strip img side by side from (x, y); n = -1 draws them all */
extern void FUN_00016d54(int, int, int, unsigned short *);
void FUN_000185d4(int x, int y, int first, int n, unsigned short *img)
{
    int k, w;
    if (n == -1) n = img[1];
    else n += first;
    k = first;
    w = img[2];
    for (; k < n; k++, x += w) FUN_00016d54(k, x, y, img);
}

/* ---- from build/var/mod/parts/p1862c.c */
#define SR T6_SR
extern short *DAT_00032a9c; extern unsigned short **B00038988_eu; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a010(int, int, int), FUN_0001a2b0(int, int);
extern int FUN_0001d2ad(char *);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_0001862c @ 0001862c */
void FUN_0001862c(int a, int b, int c) { FUN_000185d4(a, b, 0, -1, c); }

#undef SR
/* ---- from build/var/mod/parts/p1864c.c */
/* FUN_0001864c */
extern void FUN_000167c8(int, int, int, int);
void FUN_0001864c(int x, int y, int from, int to, unsigned short *img) { int k, w; if (to == -1) to = img[1]; else to += from; for (k = from, w = img[2]; k < to; k++, x += w) FUN_000167c8(k, x, y, (int)img); }

/* ---- from build/var/mod/parts/p186a4.c */
#define SR T8_SR
extern short *DAT_00032a9c; extern unsigned short **B00038988_eu; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a010(int, int, int), FUN_0001a2b0(int, int);
extern int FUN_0001d2ad(char *);
struct SR { short size, n, w; unsigned char h, f; };
/* FUN_000186a4 @ 000186a4 */
void FUN_000186a4(int a, int b, int c) { FUN_0001864c(a, b, 0, -1, c); }

#undef SR
/* ---- from build/var/mod/parts/p186c4.c */
/* FUN_000186c4 */
 
void FUN_000186c4(int a, int b, int c, int d) { FUN_0001864c(a, b, 0, -1, FUN_0001954c(c, d)); }

/* ---- from build/var/mod/parts/p186f0.c */
#define SB T10_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000186f0 @ 000186f0 */
void FUN_000186f0(struct SB *r) { int i; for (i = 0; i < r->n; i++) FUN_0001a5c8(i, r); }

#undef SB
/* ---- from build/var/mod/parts/p18718.c */
#define SB T11_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_00018718 @ 00018718 */
void FUN_00018718(struct SB *r) { int i; for (i = 0; i < r->n; i++) FUN_0001a678(i, r); }

#undef SB
/* ---- from build/var/mod/parts/p18740.c */
/* FUN_00018740 */
extern void FUN_00019814(char *), FUN_00016588(int); extern unsigned char DAT_00032b20, B000389ec_eu[];
void FUN_00018740(unsigned char c) { if (DAT_00032b20 == 10) FUN_00019814("Page Stack Overflow"); B000389ec_eu[DAT_00032b20++] = DAT_000323e5; FUN_00016588(c); }

/* ---- from build/var/mod/parts/p18788.c */
/* FUN_00018788 */
extern void FUN_00019814(char *), FUN_00016588(int); extern unsigned char DAT_00032b20, B000389ec_eu[];
void FUN_00018788(void) { if (!DAT_00032b20) FUN_00019814("Page Stack Underflow"); DAT_00032b20--; FUN_00016588(B000389ec_eu[DAT_00032b20]); }

/* ---- from build/var/mod/parts/p187c4.c */
/* FUN_000187c4 */
extern unsigned FUN_00017f50(void); extern int B000389e8_eu;
void FUN_000187c4(void) { B000389e8_eu = FUN_00017f50(); }

/* ---- from build/var/mod/parts/p187d8.c */
/* FUN_000187d8: wait up to t ticks (from the pending deadline base B000389e8_eu, else now) for a mouse click (f & 1), a key (f & 2) or nothing (f & 4); returns the event code */
extern void FUN_00019ae8(void); extern int FUN_000182a4(void), FUN_000182c0(void), FUN_000184d0(void); extern short *FUN_0001d0b4(void);

int FUN_000187d8(int t, int f) { unsigned end; short *p; int k; if (((unsigned)B000389e8_eu)) end = ((unsigned)B000389e8_eu) + t; else end = t + FUN_00017f50(); if (f & 4) f &= ~4; do { FUN_00019ae8(); if ((f & 1) && FUN_000182a4()) { (*(unsigned *)&B000389e8_eu) = 0; return FUN_000182c0(); } if ((f & 2) && FUN_000184d0() && *(p = FUN_0001d0b4())) { k = *p; while (*FUN_0001d0b4()) ; (*(unsigned *)&B000389e8_eu) = 0; return k + 0x1f8; } if (f & 4) { (*(unsigned *)&B000389e8_eu) = 0; return 0x1f0; } } while (FUN_00017f50() < end); (*(unsigned *)&B000389e8_eu) = 0; return 0; }

/* ---- from build/var/mod/parts/p188b0.c */
#include <i86.h>
struct RF { int fh, n, count; void *tab; };
extern int DAT_00032b04; extern struct RF *DAT_00032b08;
extern void FUN_000187d8(int, int), FUN_000161d0(char *), FUN_00014dc4(void), FUN_00015014(int);
extern int FUN_00014978(void), FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_000188b0 @ 000188b0 */
void FUN_000188b0(void) { sound(0x416); FUN_000187d8(6, 0); nosound(); }

/* ---- from build/var/mod/parts/p188d8.c */
/* FUN_000188d8 */
extern char B000389f6_eu[];
char *FUN_000188d8(int v) { itoa(v, B000389f6_eu, 10); return B000389f6_eu; }

/* ---- from build/var/mod/parts/p188f8.c */
/* FUN_000188f8 */
extern char B000389f6_eu[];
char *FUN_000188f8(int v) { ltoa(v, B000389f6_eu, 10); return B000389f6_eu; }

/* ---- from build/var/mod/parts/p18918.c */
#define SB T19_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_00032930, DAT_00032919, DAT_0003291a, DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_00018918 @ 00018918: sign of v */
int FUN_00018918(int v) { if (v < 0) return -1; if (v > 0) return 1; return 0; }

#undef SB
/* ---- from build/var/mod/parts/p18940.c */
extern unsigned char B00038919_eu, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00018940 @ 00018940 */
void FUN_00018940(int v) { DAT_00032b1c = v; }

/* ---- from build/var/mod/parts/p18950.c */
extern unsigned char B00038919_eu, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00018950 @ 00018950 */
void FUN_00018950(int v) { DAT_00032b18 = v; }

/* ---- from build/var/mod/parts/p18960.c */
/* FUN_00018960 @ 00018960 */

void FUN_00018960(void) { if (((void (*)(void))DAT_00032b18)) (*((void (*)(void))DAT_00032b18))(); }

/* ---- from build/var/mod/parts/p18978.c */
/* FUN_00018978 */
void *memset(void *, int, unsigned); extern int FUN_000162a8(char *), FUN_00016304(void *, unsigned, int); extern void FUN_00019814(char *), FUN_000162f0(int); extern unsigned char DAT_00032aa4[], DAT_00032ab1[];
void FUN_00018978(void) { int fd, k; volatile short n; fd = FUN_000162a8("INFO.DAT"); if (fd == -1) FUN_00019814("Cannot Find INFO.DAT, rerun INSTALL.EXE"); FUN_00016304(DAT_00032aa4, 0xd, fd); memset(DAT_00032ab1, 0, 0x50); for (k = 0; k < 0xd; k++) DAT_00032aa4[k] -= 0x30; FUN_00016304((void *)&n, 2, fd); FUN_00016304(DAT_00032ab1, n, fd); FUN_000162f0(fd); }

/* ---- from build/var/mod/parts/p18a04.c */
/* 2026-11-10: as the matched CODE.2 twin FUN_0003e7f0: the first entry byte is a 16-bit bitfield unit (lo:4, used:1, hi:3, b1:8) and lo = -1 gives the and 0xf0 / or 0xf pair */
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
#pragma pack(1)
struct E { unsigned short lo:4, used:1, hi:3, b1:8; unsigned char b2; short w3; int i5; };
#pragma pack()
struct G { int fd; int x4; int count; struct E *tab; };
extern void FUN_00018978(void), FUN_00019814(char *);
extern void *FUN_000171c8(int);
extern int FUN_000162a8(char *), FUN_00016304(void *, unsigned, int);
extern char *FUN_000188d8(int);

extern int DAT_00032b04;
extern unsigned char DAT_00032aa4[];
extern char DAT_00032ab1[];
void FUN_00018a04(char *base, int n)
{
    char path[0x50];
    int k, j;
    FUN_00018978();
    DAT_00032b08 = FUN_000171c8(n << 4);
    DAT_00032b04 = n;
    for (k = 0; k < n; k++) {
        if (DAT_00032aa4[k]) {
            strcpy(path, DAT_00032ab1);
            strcat(path, "\\");
            strcat(path, base);
        } else strcpy(path, base);
        strcat(path, FUN_000188d8(k));
        if ((((struct G *)DAT_00032b08)[k].fd = FUN_000162a8(path)) == -1) FUN_00019814("Unable to open resource file");
        FUN_00016304(&((struct G *)DAT_00032b08)[k].count, 4, ((struct G *)DAT_00032b08)[k].fd);
        ((struct G *)DAT_00032b08)[k].x4 = 0;
        ((struct G *)DAT_00032b08)[k].tab = FUN_000171c8(((struct G *)DAT_00032b08)[k].count * 9);
        for (j = 0; j < ((struct G *)DAT_00032b08)[k].count; j++) {
            ((struct G *)DAT_00032b08)[k].tab[j].lo = -1;
            ((struct G *)DAT_00032b08)[k].tab[j].used = 0;
            ((struct G *)DAT_00032b08)[k].tab[j].b2 = 0;
            ((struct G *)DAT_00032b08)[k].tab[j].w3 = 0;
            ((struct G *)DAT_00032b08)[k].tab[j].i5 = 0;
        }
    }
}

#pragma pack()
/* ---- from build/var/mod/parts/p18b94.c */
/* [2026-11-08: -os gives the right registers but a bottom-tested outer loop; -ot (or -os -ot) gives the right loop (guard test + duplicated epilogue) with g/j in esi/ebx swapped. Guarded do-while under -os is 6 bytes short; declaration/block scope/index forms under -os -ot do not swap them] */
/* [closest 2026-11-06: -os, 17 instr] */
/* NEAR MISS (-ot, registers): the original keeps the group index in ebx and the entry index in esi; here the other way round. Declaration order and block scope do not change it */
/* FUN_00018b94 */
extern void FUN_00019488(int, int), FUN_000191d8(int, int); extern int DAT_00032b04;
void FUN_00018b94(void) { int j, g; for (g = 0; g < DAT_00032b04; g++) for (j = 0; j < *(int *)(((char *)DAT_00032b08) + g * 16 + 8); j++) { FUN_00019488(j, g); FUN_000191d8(j, g); } }

/* ---- from build/var/mod/parts/p18be4.c */
#define RF T26_RF
#pragma pack(1)
struct RE { unsigned char lo, f1, f2; unsigned short f3; int f5; };
#pragma pack()
struct RF { int fh, n, count; struct RE *tab; };
extern int DAT_0003246c, DAT_00032b04;
extern void FUN_0001da18(void), FUN_0001da1a(void);
/* FUN_00018be4 @ 00018be4: stamp every loaded resource entry with time t / 32 */
void FUN_00018be4(unsigned t) { int i, k; t >>= 5; for (i = 0; i < DAT_00032b04; i++) for (k = 0; k < ((struct RF *)DAT_00032b08)[i].count; k++) if (((struct RF *)DAT_00032b08)[i].tab[k].f2) ((struct RF *)DAT_00032b08)[i].tab[k].f3 = t; }

#undef RF
#pragma pack()
/* ---- from build/var/mod/parts/p18c40.c */
/* FUN_00018c40 */
extern void FUN_00018b94(void), FUN_000162f0(int), FUN_00017240(void *); extern int DAT_00032b04;
void FUN_00018c40(void) { int k; FUN_00018b94(); for (k = 0; k < DAT_00032b04; k++) { if (*(int *)(((char *)DAT_00032b08) + k * 16)) { FUN_000162f0(*(int *)(((char *)DAT_00032b08) + k * 16)); *(int *)(((char *)DAT_00032b08) + k * 16) = 0; *(int *)(((char *)DAT_00032b08) + k * 16 + 8) = 0; } if (*(int *)(((char *)DAT_00032b08) + k * 16 + 12)) { FUN_00017240(*(void **)(((char *)DAT_00032b08) + k * 16 + 12)); *(int *)(((char *)DAT_00032b08) + k * 16 + 12) = 0; } } FUN_00017240(((char *)DAT_00032b08)); DAT_00032b08 = 0; }

/* ---- from build/var/mod/parts/p18cd4.c */
#define RF T28_RF
#include <i86.h>
struct RF { int fh, n, count; void *tab; };
extern int DAT_00032b04;
extern void FUN_000187d8(int, int), FUN_000161d0(char *), FUN_00014dc4(void), FUN_00015014(int);
extern int FUN_00014978(void), FUN_0001da1c(int, union REGS *, union REGS *);
/* FUN_00018cd4 @ 00018cd4: total entry count of all resource files */
int FUN_00018cd4(void) { int i, s; for (i = 0, s = 0; i < DAT_00032b04; i++) s += ((struct RF *)DAT_00032b08)[i].n; return s; }

#undef RF
/* ---- from build/var/mod/parts/p18d0c.c */
/* FUN_00018d0c @ 00018d0c: read the resource at offset pos of file fh into r (5-byte header, then the data in a new buffer); abort with "Attempt to load non-resource file: <file>/<n>" when the magic is not "EH" (CODE.1 copy of CODE.2 FUN_0003eb60; the raw-offset read of the data pointer is pushed straight from memory) */
#include <string.h>
#pragma pack(1)
struct RES { unsigned short magic; unsigned char k; short len; char *data; };
#pragma pack()
extern void FUN_00016358(int, int), FUN_00019814(char *); extern int FUN_00016304(void *, unsigned, int);
extern char *FUN_000171c8(int), *FUN_000188d8(int), *FUN_000188f8(int);
void FUN_00018d0c(struct RES *r, int pos, int fh, int n)
{
    char buf[80];
    FUN_00016358(pos, fh);
    FUN_00016304((char *)r, 5, fh);
    if (r->len) {
        r->data = FUN_000171c8(r->len);
        FUN_00016304(*(char **)((char *)r + 5), r->len, fh);
    } else r->data = 0;
    if (r->magic != 0x4845) {
        strcpy(buf, "Attempt to load non-resource file: ");
        strcat(buf, FUN_000188d8(pos));
        strcat(buf, "/");
        strcat(buf, FUN_000188f8(n));
        FUN_00019814(buf);
    }
}

#pragma pack()
/* ---- from build/var/mod/parts/p18df0.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[]; 
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_00018df0 @ 00018df0 */
int FUN_00018df0(int k) { return *(int *)(((char *)DAT_00032b08) + k * 16); }

/* ---- from build/var/mod/parts/p18e08.c */
/* FUN_00018e08: number of entries in menu group g */
struct GRP { int r0, on, n; unsigned char *e; };

int FUN_00018e08(int g) { return ((struct GRP *)((char *)DAT_00032b08))[g].n; }

/* ---- from build/var/mod/parts/p18e3c.c */
#define GRP T32_GRP
#define RES T32_RES
/* FUN_00018e3c @ 00018e3c: make resource idx of group grp resident (CODE.2 FUN_0003ecb4) */
#include <string.h>
#pragma pack(1)
struct RES { unsigned short magic; unsigned char k; short len; char *data; };
struct REC { unsigned short type : 4, locked : 1; unsigned char loaded; unsigned short used; void *data; };
#pragma pack()
struct GRP { int fh, nloaded, n; struct REC *rec; };

extern void FUN_00018d0c(struct RES *, int, int, int), FUN_00019814(char *), FUN_00017240(void *);
extern char *FUN_000188d8(int), *FUN_000188f8(int);
extern void *FUN_0001767c(struct RES *, int), *FUN_000179c8(struct RES *, int), *FUN_0001b51c(struct RES *, int), *FUN_0001c5b0(struct RES *, int), *FUN_0001e0d0(struct RES *, int), *FUN_0001e190(struct RES *, int), *FUN_0001e208(struct RES *, int);
void FUN_00018e3c(int idx, int grp)
{
    char buf[80]; struct RES h;
    if (idx < 0 || idx >= ((struct GRP *)DAT_00032b08)[grp].n) {
        strcpy(buf, "Attempt to load out-of-range: ");
        strcat(buf, FUN_000188d8(idx));
        strcat(buf, "/");
        strcat(buf, FUN_000188f8(grp));
        FUN_00019814(buf);
    }
    if (!((struct GRP *)DAT_00032b08)[grp].rec[idx].loaded) {
        if (((void (*)(int, int))DAT_00032b1c)) ((void (*)(int, int))DAT_00032b1c)(idx, grp);
        FUN_00018d0c(&h, idx, ((struct GRP *)DAT_00032b08)[grp].fh, grp);
        switch (h.k) {
        case 1: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001767c(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 2: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_000179c8(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 3: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001b51c(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 4: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001c5b0(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 5: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001e0d0(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 6: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001e190(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        case 7: ((struct GRP *)DAT_00032b08)[grp].rec[idx].data = FUN_0001e208(&h, ((struct GRP *)DAT_00032b08)[grp].fh); break;
        default: FUN_00019814("Unknown resource type");
        }
        ((struct GRP *)DAT_00032b08)[grp].rec[idx].loaded = 1;
        ((struct GRP *)DAT_00032b08)[grp].rec[idx].type = h.k;
        ((struct GRP *)DAT_00032b08)[grp].rec[idx].locked = 0;
        if (h.data) FUN_00017240(h.data);
        ((struct GRP *)DAT_00032b08)[grp].nloaded++;
    }
    ((struct GRP *)DAT_00032b08)[grp].rec[idx].used = FUN_00017f50() >> 5;
}

#undef GRP
#undef RES
#pragma pack()
/* ---- from build/var/mod/parts/p191d8.c */
#define E T33_E
/* FUN_000191d8 @ 0003efd0: release entry a of menu group b: free what it holds by type, then clear it and count it out of the group */
#pragma pack(1)
struct E { unsigned short type : 4, off : 1, rest : 11; unsigned char g; unsigned short pr; int data; };
#pragma pack()
struct S { int a, n, c; struct E *t; };

extern void FUN_00017830(int), FUN_00017a64(int), FUN_0001b574(int), FUN_0001c608(int), FUN_0001e174(int), FUN_0001e1f4(int), FUN_0001e26c(int);
void FUN_000191d8(int a, int b)
{
    int d;
    if (((struct S *)DAT_00032b08)[b].t[a].off || !((struct S *)DAT_00032b08)[b].t[a].g) return;
    d = ((struct S *)DAT_00032b08)[b].t[a].data;
    switch (((struct S *)DAT_00032b08)[b].t[a].type) {
    case 1: if (((struct S *)DAT_00032b08)[b].t[a].g == 1) FUN_00017830(d); break;
    case 2: FUN_00017a64(d); break;
    case 3: FUN_0001b574(d); break;
    case 4: FUN_0001c608(d); break;
    case 5: FUN_0001e174(d); break;
    case 6: if (((struct S *)DAT_00032b08)[b].t[a].g == 1) FUN_0001e1f4(d); break;
    case 7: if (((struct S *)DAT_00032b08)[b].t[a].g == 1) FUN_0001e26c(d); break;
    }
    ((struct S *)DAT_00032b08)[b].t[a].g = 0;
    ((struct S *)DAT_00032b08)[b].t[a].pr = 0;
    ((struct S *)DAT_00032b08)[b].t[a].data = 0;
    ((struct S *)DAT_00032b08)[b].n--;
}

#undef E
#pragma pack()
/* ---- from build/var/mod/parts/p19378.c */
#define E T34_E
#define G T34_G
/* FUN_00019378: select the menu entry with hot key `key` (lowest priority value wins); same routine as CODE.2 FUN_0003f0b4 */
extern void FUN_000191d8(int, int);
#pragma pack(1)
struct E { unsigned short lo:4, used:1, hi:3, b1:8; unsigned char b2; unsigned short w3; int i5; };
#pragma pack()
struct G { int fd; int on; int count; struct E *tab; };
extern int DAT_00032b04;
int FUN_00019378(int key)
{
    unsigned best = 0; int fg, found = -1, j, g;
    for (g = 0; g < DAT_00032b04; g++) {
        if (((struct G *)DAT_00032b08)[g].on) {
            for (j = 0; j < ((struct G *)DAT_00032b08)[g].count; j++) {
                if (((struct G *)DAT_00032b08)[g].tab[j].b2 == key && !((struct G *)DAT_00032b08)[g].tab[j].used && (found == -1 || ((struct G *)DAT_00032b08)[g].tab[j].w3 < best)) {
                    best = ((struct G *)DAT_00032b08)[g].tab[j].w3;
                    found = j;
                    fg = g;
                }
            }
        }
    }
    if (found == -1) return 0;
    FUN_000191d8(found, fg);
    return 1;
}

#undef E
#undef G
#pragma pack()
/* ---- from build/var/mod/parts/p19440.c */
/* FUN_00019440 */

void FUN_00019440(int a, int b) { if ((*(unsigned char **)(((char *)DAT_00032b08) + b * 16 + 12))[a * 9 + 2]) (*(unsigned char **)(((char *)DAT_00032b08) + b * 16 + 12))[a * 9] |= 0x10; }

/* ---- from build/var/mod/parts/p19488.c */
/* FUN_00019488 */

void FUN_00019488(int a, int b) { if ((*(unsigned char **)(((char *)DAT_00032b08) + b * 16 + 12))[a * 9 + 2]) (*(unsigned char **)(((char *)DAT_00032b08) + b * 16 + 12))[a * 9] &= ~0x10; }

/* ---- from build/var/mod/parts/p194d0.c */
/* FUN_000194d0 */
extern void FUN_00019488(int, int); extern int DAT_00032b04, DAT_00032b10;
void FUN_000194d0(void) { int g, j; for (g = 0; g < DAT_00032b04; g++) for (j = 0; j < *(int *)(((char *)DAT_00032b08) + g * 16 + 8); j++) if (j != DAT_00032b10) FUN_00019488(j, g); }

/* ---- from build/var/mod/parts/p19520.c */
/* FUN_00019520 */
extern void FUN_00018b94(void), FUN_00018e3c(int, int), FUN_00019440(int, int); extern int DAT_00032b10;
void FUN_00019520(void) { FUN_00018b94(); FUN_00018e3c(DAT_00032b10, 0); FUN_00019440(DAT_00032b10, 0); }

/* ---- from build/var/mod/parts/p1954c.c */
/* FUN_0001954c */
extern void FUN_00018e3c(int, int);
int FUN_0001954c(int a, int b) { FUN_00018e3c(a, b); if ((*(unsigned char **)(((char *)DAT_00032b08) + b * 16 + 12))[a * 9 + 2] == 1) return *(int *)(*(char **)(((char *)DAT_00032b08) + b * 16 + 12) + a * 9 + 5); return 0; }

/* ---- from build/var/mod/parts/p195a8.c */
/* FUN_000195a8: critical-error (INT 24h) handler, records the error code and fails the call; FUN_000195bc: low-level startup (video defaults, handler, sound config from SOUND.CFG or the parent's block, mouse range) */
#include <dos.h>
void *memset(void *, int, unsigned);
int atoi(const char *);


extern int DAT_00032b10, DAT_000323d0;
extern int _argc; extern char **_argv;
extern unsigned char *DAT_00032aa0;
extern void FUN_00018398(void), FUN_000164b0(int), FUN_000162f0(int), FUN_0001c2d0(void *, int, int, int, int), FUN_0001b0f8(void *, int, int, int, int), FUN_0001d10c(int, int), FUN_0001d130(int, int);
extern void *FUN_000171c8(int);
extern int FUN_000162a8(char *), FUN_00016304(void *, unsigned, int), FUN_0001cf98(void);
int __far FUN_000195a8(unsigned deverr, unsigned errcode, unsigned __far *devhdr)
{
    DAT_000323d0 = errcode;
    return 0;
}

/* ---- from build/var/mod/parts/p195bc.c */
void FUN_000195bc(int a, int b)
{
    int fd;
    short *p;
    DAT_000323eb = 0x182;
    DAT_000323d6 = 0xc;
    DAT_00032400 = 1;
    DAT_000323d4 = 0xff;
    DAT_00032b10 = -1;
    _harderr(FUN_000195a8);
    FUN_00018398();
    FUN_000164b0(0);
    if (_argc != 2) {
        DAT_00032aa0 = FUN_000171c8(0x100);
        memset(DAT_00032aa0, 0, 0x100);
    } else DAT_00032aa0 = (unsigned char *)atoi(_argv[1]);
    if (!DAT_00032aa0[0x64]) {
        fd = FUN_000162a8("sound.cfg");
        FUN_00016304(DAT_00032aa0, 0x3b, fd);
        FUN_000162f0(fd);
        DAT_00032aa0[0x64] = 1;
        DAT_00032aa0[0x66] = 1;
    }
    DAT_00032a9c = FUN_0001cf98();
    p = (short *)DAT_00032aa0;
    if (p[4] != 0x71) {
        if (p[10]) FUN_0001c2d0(p + 0x12, p[5], p[6], p[7], p[8]);
        FUN_0001b0f8((char *)p + 0x16, p[0], p[1], p[2], p[3]);
    }
    FUN_0001d10c(0, 0x27e);
    FUN_0001d130(0, 0xc7);
    if (a) FUN_00018a04(a, b);
}

/* ---- from build/var/mod/parts/p19724.c */
/* FUN_00019724 */
extern void FUN_00019488(int, int), FUN_00018e3c(int, int), FUN_00019440(int, int); extern int DAT_00032b10, DAT_00032b0c; extern unsigned char DAT_00032b14;
void FUN_00019724(int a, int b, unsigned char c) { if (DAT_00032b10 != -1) FUN_00019488(DAT_00032b10, 0); DAT_00032b10 = b; FUN_00018e3c(DAT_00032b10, 0); FUN_00019440(DAT_00032b10, 0); DAT_00032b0c = a; DAT_00032b14 = c; }

/* ---- from build/var/mod/parts/p19778.c */
/* FUN_00019778 @ 00019778: shut down sound and music on exit (module compiled for a 486/Pentium target, -5s) */
extern void FUN_0001cf98(void), FUN_0001b430(void), FUN_0001c4a0(void), FUN_0001e6ea(int), FUN_00018c40(void), FUN_00018424(void); extern char *DAT_00032aa0; extern int DAT_00032b84, DAT_00032f48;
void FUN_00019778(void) { char *p; int f; FUN_0001cf98(); p = DAT_00032aa0; f = DAT_00032b84 | DAT_00032f48; if (*(short *)(p + 8) != 0x71) { FUN_0001b430(); if (*(short *)(p + 0x14)) FUN_0001c4a0(); if (f) FUN_0001e6ea(0); } if (((int)DAT_00032b08)) FUN_00018c40(); FUN_00018424(); }

/* ---- from build/var/mod/parts/p197d4.c */
/* FUN_000197d4 @ 000197d4: shut down and exit with code c */
extern void FUN_0001ede0(void);
void FUN_000197d4(int c)
{
    FUN_0001ede0();
    exit(c);
}

/* ---- from build/var/mod/parts/p197e8.c */
/* FUN_000197e8 */
extern void FUN_000164dc(int), FUN_00019778(void), FUN_000197d4(int);
void FUN_000197e8(int quit) { FUN_000164dc(0xff); FUN_00019778(); if (quit) FUN_000197d4(1); }

/* ---- from build/var/mod/parts/p19814.c */
/* FUN_00019814 */
extern int FUN_00019874(char *, int); extern void FUN_000161d0(char *); extern int DAT_00032b10; extern unsigned char DAT_00032b01;
void FUN_00019814(char *msg) { int r; if (DAT_00032b10 != -1 && !(DAT_00032b01 & 0x80)) { r = FUN_00019874(msg, 0); FUN_000197e8(0); if (r != 0x54) goto out; } else FUN_000197e8(0); FUN_000161d0(msg); out: FUN_000197d4(1); }

/* ---- from build/var/mod/parts/p19874.c */
extern int FUN_00017ddc(void), FUN_00017de8(void), FUN_00017ab4(char *, int), FUN_000182c0(void);
extern void FUN_00016588(int), FUN_000166c0(void *, int, int, int, int), FUN_0001a05c(int, int, int, int, int), FUN_00017d68(int, int), FUN_00017c0c(char *, int), FUN_0001a474(int), FUN_00016744(void *, int, int, int, int), FUN_00017240(void *), FUN_000161d0(char *);
extern void *FUN_000171c8(int);
extern unsigned char DAT_00032b14;
extern int DAT_00032b10;

int FUN_00019874(char *msg, int mode)
{
    unsigned char sv; int cy; int k; void *buf; int cx; int w; unsigned char pg; int key;
    if (DAT_000323d4 != 0xff) {
        sv = 0xff;
        w = 0x140;
        pg = DAT_000323e5;
        cx = FUN_00017ddc();
        cy = FUN_00017de8();
        if (DAT_000323d4 != 5 && DAT_000323e5 != DAT_000323e6) FUN_00016588(DAT_000323e6);
        else if (DAT_000323d4 == 5) {
            FUN_00016588(0);
            w -= 8;
        }
        buf = FUN_000171c8(DAT_000323d6 * 0x140);
        FUN_000166c0(buf, 0, 0, DAT_000323d6, 0x140);
        for (k = 0; k < DAT_000323d6; k++) FUN_0001a05c(k, 0, k, w - 1, DAT_00032b14 - k);
        if (DAT_00032b10 != -1 && msg) {
            FUN_00017d68(0, 0xa0 - FUN_00017ab4(msg, DAT_00032b10) / 2);
            FUN_00017c0c(msg, DAT_00032b10);
        }
        if (DAT_000323d4 == 5 && DAT_000323e6) {
            sv = *(unsigned char *)&DAT_000323df;
            if (DAT_000323df > 0xc8 - DAT_000323d6) FUN_0001a474(0xc8 - DAT_000323d6);
        }
        if (mode > 1) FUN_000187d8(mode, 0);
        else if (mode == 1) {
            do key = FUN_000182c0(); while (key != 'N' && key != 'Y' && key != 'S');
            if (key == 'S') key = 'Y';
        } else {
            do key = FUN_000182c0(); while (key != ' ' && key != 'T');
        }
        FUN_00016744(buf, 0, 0, DAT_000323d6, 0x140);
        FUN_00017240(buf);
        FUN_00016588(pg);
        FUN_00017d68(cx, cy);
        if (DAT_000323d4 == 5 && sv != 0xff && DAT_000323e6) FUN_0001a474(sv);
        return key;
    }
    FUN_000161d0(msg);
    return 0;
}

/* ---- from build/var/mod/parts/p19ab4.c */
/* FUN_00019ab4 */
extern unsigned char DAT_00032b01;
void FUN_00019ab4(void) { DAT_00032b01 |= 0x80; }

/* ---- from build/var/mod/parts/p19ac4.c */
/* FUN_00019ac4 */
extern unsigned char DAT_00032b01;
void FUN_00019ac4(void) { DAT_00032b01 &= 0x7f; }

/* ---- from build/var/mod/parts/p19ad4.c */
/* FUN_00019ad4 @ 00019ad4 */
extern unsigned char DAT_00032b01;
int FUN_00019ad4(void) { return (DAT_00032b01 & 0x80) == 0; }

/* ---- from build/var/mod/parts/p19ae8.c */
/* FUN_00019ae8 @ 00019ae8: poll the keyboard hooks: Ctrl-Break-style request 2 runs FUN_00015014(10); the quit request asks "Quit <name> (Y/N) ?" and exits on Y (CODE.1 copy of CODE.2 FUN_0003f868) */
#include <string.h>
extern unsigned char DAT_00032b01, DAT_00032b02;
extern void FUN_00018960(void), FUN_00015014(int), FUN_000197e8(int); extern int FUN_00019874(char *, int);
void FUN_00019ae8(void)
{
    char buf[80];
    FUN_00018960();
    if ((DAT_00032b01 & 2) && !(DAT_00032b01 & 0x80) && !DAT_00032b02) {
        DAT_00032b02 = 1;
        DAT_00032b01 = 0;
        FUN_00015014(10);
    }
    if (DAT_00032b01 && !(DAT_00032b01 & 0x80) && !DAT_00032b02) {
        DAT_00032b02 = 1;
        DAT_00032b01 = 0;
        strcpy(buf, "Quit ");
        if (((char *)DAT_00032b0c)) strcat(buf, ((char *)DAT_00032b0c));
        strcat(buf, " (Y/N) ?");
        if (FUN_00019874(buf, 1) == 'Y') FUN_000197e8(1);
        DAT_00032b02 = 0;
        DAT_00032b01 = 0;
    }
}

/* ---- from build/var/mod/parts/p19bc4.c */
extern unsigned char B00038919_eu, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00019bc4 @ 00019bc4: request the quit prompt and poll the keyboard hooks */
void FUN_00019bc4(void) { DAT_00032b01 |= 1; FUN_00019ae8(); }

/* ---- module data _DATA 00032a9c-00032b28 (docs/data/dataown.CODE1.csv: certain (ref; some shared)), generated by tools/data2c.py */
short *DAT_00032a9c = 0;
unsigned char *DAT_00032aa0 = 0;
unsigned char DAT_00032aa4[13] = { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 };
unsigned char DAT_00032ab1[80] = { 0 };
unsigned char DAT_00032b01 = 0;
unsigned char DAT_00032b02 = 0;
unsigned char DAT_00032b03[1] = { 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00032b04 = 0;
struct RF *DAT_00032b08 = 0;
int DAT_00032b0c = 0;
int DAT_00032b10 = -1;
unsigned char DAT_00032b14 = 0;
unsigned char DAT_00032b15[3] = { 0, 0, 0x66 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00032b18 = 0;
int DAT_00032b1c = 0;
unsigned char DAT_00032b20 = 0;
unsigned char DAT_00032b21[7] = { 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
