/* Module: FUN_00028d90, FUN_000291c0, FUN_000292cc, FUN_00029378, FUN_0002942c, FUN_00029464, FUN_000297b8,
   FUN_00029888 */
/* ---- from build/var/mod/parts/p28d90.c */
/* Round 18: module 0x28d90 is -j (recipe 60): in module context under -ox -oe -oa -ot -j 7 lines (the round-17 tie), 21 without -j. */
/* NEAR MISS 1070/1070, 7 lines (module 0x28d90, flags -3s -ox -oe -ot -j -w0). Causes found 2026-11-10: (1) the module is compiled with -j: _IsTable is plain char and the original reads it with movsx; (2) the test is written isspace | isalnum | ispunct (left operand of the first | is isspace; that also gives the panel sprite its frame slot, the old "spill"); (3) redraw = 1 comes before buf[0] = ..., so the q*16 index cannot take ebx. Left: in the ctype test the original evaluates the isalnum term first into ebp and puts isspace in edi (`or edi, ebp`); ours loads isspace first (cl -> edi) and isalnum into ecx. Q1: ecx is free in ours; in the original isalnum is live across the `mov cl` of isspace, so it cannot be ecx - the evaluation order differs. Q2/Q3: all 12 term orders/groupings tried, plus a temporary for the first |, a char copy of key, `!= 0`: none moves isalnum ahead while keeping isspace as the left operand. Declaration order: 400 random orders, no effect  Round 17 (module flags -ox -oe -oa -ot -j): 10.0a's CTYPE.H (tools/watcom/w10a/H, same as 9.5) expands each test to _IsTable[(unsigned char)((key)+1)] & mask; the code generator evaluates the operand with more tree nodes first (cg tree.c TNBinary: left first when left->kids >= rite->kids), and the three terms have equal node counts (isspace's & 2 is demoted to char by ResultType and converted back for the |, isalnum's & 0xe0 converts first), so the left operand is always evaluated first and no spelling of the macros puts isalnum first with isspace as the left operand (instrument micro-tests build/var/ct: casts, key + 0, (char), regrouping, isalpha | isdigit). isalnum(key) | isspace(key) | ispunct(key) gives the original evaluation order and instruction shape (movsx/and 0xe0 first), but 47 lines (10.0a): isalnum's value t108 and isspace's t109 tie at 15362 savings and t108 is allocated first, taking EDI (original: t109 EDI, then isalnum EBP, which also keeps spr out of EBP and in its frame slot); tools/ow1lib.py whatif --first t109 t108 on that source: almost any one-node change of the conflict list flips the pair; 451 declaration orders (instrument, tools/ow1search.py build/var/g28.py): one code. Kept the 7-line form. */
/* FUN_00028d90 @ 00028d90: the manual word check (once per game): draw the stone panel, then up to three times ask for a word from the manual ("On page %d, under the heading "%s", enter the %s word:"), first letter given; three failures end the game */
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int rand(void);
struct QZ { int page; char *head, *nth, *ans; };
struct GS { char p0[0x72]; unsigned char asked; };
extern struct QZ DAT_000582cc[]; extern struct GS *DAT_0005f050; extern int DAT_0005c050; extern unsigned char DAT_0005c054[];
extern int DAT_000758dc; extern char DAT_0005759c[];
extern unsigned short FUN_000390d0(unsigned short); extern int FUN_000411e0(void), FUN_00040aec(void); int strcmp(const char *, const char *); extern void *FUN_00040070(int, int, int, int, int);
extern void FUN_0002aacc(void), FUN_00030294(void), FUN_0002a288(void), FUN_000391b0(unsigned char), FUN_000391c8(unsigned char), FUN_00039b40(int, int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_000425b0(unsigned char *, int, int, char *, int), FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_00042220(unsigned char *, int, int, unsigned char, unsigned char, unsigned char);
extern void FUN_0003a380(int, int, int, void *), FUN_00040508(int, int, int, char *, int), FUN_00040354(int, int), FUN_0002a8c8(int, int, int, int, int), FUN_000305b4(int);
void FUN_00028d90(void)
{
    char buf[30]; int tries, q; void *spr; int x, y, loaded, redraw, key;
    if (DAT_0005f050->asked == 1) return;
    DAT_0005f050->asked = 1;
    FUN_000390d0(FUN_000411e0());
    FUN_0002aacc();
    FUN_00030294();
    FUN_0002a288();
    FUN_000391b0(DAT_0005c050);
    FUN_000391c8(DAT_0005c050 ^ 1);
    FUN_00039b40(0, 0, 0x190, 0x140, 0);
    for (x = 0xa0; x < 0xf0; x += 0x10)
        for (y = 0; y < 0x140; y += 8) FUN_0003975c((unsigned)rand() * 4 >> 15, x, y, DAT_000758dc + 0x35, 0);
    for (y = 0; y < 0x140; y += 8) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 9, 0xa0, y, DAT_000758dc + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 5, 0xe0, y, DAT_000758dc + 0x35, 0);
    }
    for (x = 0xb0; x < 0xe0; x += 0x10) {
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xc, x, 0, DAT_000758dc + 0x35, 0);
        FUN_0003975c(((unsigned)rand() * 2 >> 15) + 0xe, x, 0x138, DAT_000758dc + 0x35, 0);
    }
    FUN_0003975c(8, 0xa0, 0, DAT_000758dc + 0x35, 0);
    FUN_0003975c(0xb, 0xa0, 0x138, DAT_000758dc + 0x35, 0);
    FUN_0003975c(4, 0xe0, 0, DAT_000758dc + 0x35, 0);
    FUN_0003975c(7, 0xe0, 0x138, DAT_000758dc + 0x35, 0);
    spr = FUN_00040070(0xa0, 0, 0x50, 0x140, 0xff);
    loaded = 0;
    tries = 0;
    do {
        q = (unsigned)rand() * 0x33 >> 15;
        memset(buf, 0, sizeof(buf));
        sprintf(DAT_0005759c, "On page %d, under the heading \"%s\", enter the %s word:", DAT_000582cc[q].page, DAT_000582cc[q].head, DAT_000582cc[q].nth);
        redraw = 1;
        buf[0] = *DAT_000582cc[q].ans;
        do {
            if (redraw) {
                if (!loaded) {
                    FUN_000425b0(DAT_0005c054, 0, 0, "COLORS", 0x100);
                    FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
                    loaded = 1;
                }
                FUN_000391b0(DAT_0005c050);
                FUN_0003a380(0, 0xa0, 0, spr);
                FUN_00040508(0xaa, 0, 0x140, DAT_0005759c, 1);
                FUN_00040508(0xbe, 0, 0x140, buf, 1);
                FUN_00040354(0x7c, 1);
                FUN_0002a8c8(DAT_0005c050, 0xa0, 0, 0x50, 0x140);
                redraw = 0;
            }
            key = FUN_00040aec();
            if (key != 0xd) {
                if (key == 8) {
                    if (strlen(buf) > 0) {
                        redraw = 1;
                        buf[strlen(buf) - 1] = 0;
                    }
                } else if (strlen(buf) < 0x1d) {
                    if (isspace(key) | (unsigned)isalnum(key) | ispunct(key)) { /* TODO types: the cast gives isalnum one node more, so it is evaluated first (round 27) */
                        redraw = 1;
                        buf[strlen(buf)] = key;
                    }
                }
            }
        } while (key != 0xd);
        if (!strcmp(buf, DAT_000582cc[q].ans)) break;
        tries++;
    } while (tries < 3);
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    if (tries == 3) FUN_000305b4(-1);
}

/* ---- from build/var/mod/parts/p291c0.c */
/* matches with -oa only; module 0x28d90 is compiled without -oa (and with -j). Without -oa the sums DAT_00058210[j].x + tx are formed in place (add ecx, [mem]) and ty in the quotient register; the original loads DAT_00058210[j].x into a fresh register. Tried 2026-11-10 without -oa: operands swapped, +=, read-first locals, an output pointer, separate sum temporaries, a struct copy, pointers to the inputs (9 variants) */
/* FUN_000291c0 @ 000291c0: animate the four title logos sliding into place */
int abs(int);
#pragma intrinsic(abs)
struct PT { int x, y; };
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_000397d0(int, int, int, int), FUN_000391c8(unsigned char);
extern struct PT DAT_00058210[4], DAT_00058230[4], DAT_00058250[4], DAT_00058270[4]; extern int DAT_0005c050, DAT_000758dc;
void FUN_000291c0(void)
{
    int k, j, dx, dy, tx, ty;
    for (k = 1; k < 15; k++) {
        FUN_000391b0(DAT_0005c050);
        for (j = 0; j < 4; j++) {
            dx = abs(DAT_00058210[j].x - DAT_00058230[j].x);
            dy = abs(DAT_00058210[j].y - DAT_00058230[j].y);
            tx = DAT_00058250[j].x * ((dx * k + 7) / 14);
            ty = DAT_00058250[j].y * ((dy * k + 7) / 14);
            DAT_00058270[j].x = DAT_00058210[j].x + tx;
            DAT_00058270[j].y = DAT_00058210[j].y + ty;
        }
        FUN_0003e510(0, 0, DAT_000758dc + 0x52, 0);
        for (j = 0; j < 4; j++) FUN_000397d0(DAT_00058270[j].x, DAT_00058270[j].y, DAT_000758dc + 0x53 + j, 0);
        FUN_000391c8(DAT_0005c050);
        DAT_0005c050 ^= 1;
    }
}

/* ---- from build/var/mod/parts/p292cc.c */
/* FUN_000292cc @ 000292cc: draw the title screen */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0004060c(int, int, char *, int), FUN_0002ea78(void), FUN_0002a9f8(void);
extern int DAT_0005c050, DAT_000758dc; extern char s_Ver_1_2a_000582c0[];
void FUN_000292cc(void)
{
    FUN_000391b0(DAT_0005c050);
    FUN_0003e510(0, 0, DAT_000758dc + 0x52, 0);
    FUN_0003e510(7, 0x55, DAT_000758dc + 0x53, 0);
    FUN_0003e510(0x4f, 0, DAT_000758dc + 0x54, 0);
    FUN_0003e510(0xc8, 0, DAT_000758dc + 0x55, 0);
    FUN_0003e510(0x155, 0x8f, DAT_000758dc + 0x56, 0);
    FUN_0004060c(0, 0, s_Ver_1_2a_000582c0, 1);
    FUN_0002ea78();
    FUN_0002a9f8();
}

/* ---- from build/var/mod/parts/p29378.c */
#define DAT_0005759c ((unsigned char *)DAT_0005759c)
/* FUN_00029378 @ 00029378: build the identity palette map with the translucency entries and install it */
extern void FUN_0003aa9c(int, unsigned char *, void *);
#pragma aux FUN_0003aa9c modify [eax ebx ecx edx esi edi];
extern unsigned char DAT_0005880d[];
void FUN_00029378(void)
{
    int k;
    for (k = 0; k < 256; k++) DAT_0005759c[k] = k;
    DAT_0005759c[0x08] = 0xeb;
    DAT_0005759c[0x1b] = 0xff;
    DAT_0005759c[0x16] = 0xf9;
    DAT_0005759c[0x09] = 0xec;
    DAT_0005759c[0x1a] = 0xfe;
    DAT_0005759c[0x0b] = 0xef;
    DAT_0005759c[0x12] = 0xf5;
    DAT_0005759c[0x10] = 0xf3;
    DAT_0005759c[0x0c] = 0xef;
    DAT_0005759c[0x0d] = 0xf0;
    DAT_0005759c[0x0a] = 0xed;
    DAT_0005759c[0x5c] = 0xac;
    DAT_0005759c[0x58] = 0x53;
    DAT_0005759c[0x55] = 0x44;
    DAT_0005759c[0x53] = 10;
    DAT_0005759c[0x56] = 0x45;
    DAT_0005759c[0x57] = 0x45;
    DAT_0005759c[0x54] = 0x42;
    DAT_0005759c[0x59] = 0x53;
    FUN_0003aa9c(0, DAT_0005759c, DAT_0005880d);
}

#undef DAT_0005759c
/* ---- from build/var/mod/parts/p2942c.c */
#define DAT_0005880d ((char *)DAT_0005880d)
/* FUN_0002942c @ 0002942c: load the 0x1614-byte table from resource DAT_000758dc + 0x2f */
void *memmove(void *, const void *, unsigned); extern void *FUN_0003f29c(int, int); extern int DAT_000758dc; 
void FUN_0002942c(void)
{
    void *p = FUN_0003f29c(DAT_000758dc + 0x2f, 0);
    memmove(DAT_0005880d, p, 0x1614);
}

#undef DAT_0005880d
/* ---- from build/var/mod/parts/p29464.c */
extern void FUN_000292cc(void); /* module prototype */
extern void FUN_00029378(void); /* module prototype */
/* FUN_00029464 @ 00029464: title menu: highlight the entry under the mouse; on click run it (new game, load, intro, quit) until a game is started */
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
struct ME { int x, y, lim; };
extern struct ME DAT_00058290[4];
extern void FUN_0002a0b0(void), FUN_0002a288(void), FUN_00030294(void), FUN_0002aacc(void), FUN_000305b4(int), FUN_00038ce8(void), FUN_0002ea78(void);
extern int FUN_0002a1f4(void), FUN_00023ef8(int), FUN_00017b94(void); extern void *FUN_0003f29c(int, int);
extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_00042220(unsigned char *, int, int, unsigned char, unsigned char, unsigned char);
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_00039234(unsigned char *);
extern unsigned char DAT_0005c054[], DAT_0005880d[], DAT_00059e39, DAT_0005c02c, DAT_0005c02b, DAT_00064090, DAT_00064094;
extern int DAT_0005c050, DAT_000758dc; extern short DAT_00059e31, DAT_00059e33; 
void FUN_00029464(void)
{
    int sel, ly, lx, done, n, k; void *p;
    FUN_0002a0b0();
    FUN_00029378();
    sel = -1;
    done = 0;
    DAT_00059e39 = (unsigned char)DAT_0005c050 ^ 1;
    ly = -1;
    lx = -1;
    FUN_0002a288();
    FUN_000292cc();
    do {
        if (FUN_0002a1f4()) {
            switch (sel) {
            case 0:
                FUN_00023ef8(0);
                memset(DAT_0005c054, 0, 0x300);
                FUN_00039234(DAT_0005c054);
                FUN_00030294();
                FUN_000425b0(DAT_0005c054, 0, 0xc, "COLORS", 0x100);
                FUN_000292cc();
                sel = -1;
                FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
                break;
            case 1:
                FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
                p = FUN_0003f29c(DAT_000758dc + 0x2f, 0);
                memmove(DAT_0005880d, p, 0x1614);
                FUN_0002aacc();
                FUN_00030294();
                FUN_0002a288();
                FUN_000425b0(DAT_0005c054, 0, 0, "COLORS", 0x100);
                FUN_00039234(DAT_0005c054);
                done = FUN_00017b94() == 0;
                if (done) {
                    DAT_0005c02c = DAT_00064090;
                    DAT_0005c02b = DAT_00064094;
                    p = FUN_0003f29c(DAT_000758dc + 0x2f, 0);
                memmove(DAT_0005880d, p, 0x1614);
                    continue;
                }
                FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
                FUN_000425b0(DAT_0005c054, 0, 0xc, "COLORS", 0x100);
                FUN_00029378();
                FUN_000292cc();
                FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
                break;
            case 2:
                FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
                p = FUN_0003f29c(DAT_000758dc + 0x2f, 0);
                memmove(DAT_0005880d, p, 0x1614);
                FUN_000305b4(10);
                break;
            case 3:
                FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
                FUN_00038ce8();
                FUN_000305b4(0);
                break;
            }
        }
        if (DAT_00059e31 == lx && DAT_00059e33 == ly) continue;
        n = -1;
        lx = DAT_00059e31;
        ly = DAT_00059e33;
        for (k = 0; k < 4; k++) {
            if (lx <= DAT_00058290[k].lim) { n = k; break; }
        }
        if (n == sel) continue;
        FUN_000391b0(DAT_0005c050);
        FUN_0003e510(0xc8, 0, DAT_000758dc + 0x55, 0);
        if (n != -1) FUN_0003e510(DAT_00058290[n].x, DAT_00058290[n].y, DAT_000758dc + 0x57 + n, 0);
        FUN_0002ea78();
        sel = n;
    } while (done != 1);
    if (sel != 1) {
        FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
        p = FUN_0003f29c(DAT_000758dc + 0x2f, 0);
                memmove(DAT_0005880d, p, 0x1614);
    }
}

/* ---- from build/var/mod/parts/p297b8.c */
#define FUN_0003a380 ((void (*)(int, int, int, unsigned char *))FUN_0003a380)
/* FUN_000297b8 @ 000297b8: play the 82-frame title animation; 1 when Esc skipped it */
extern void FUN_000391b0(unsigned char), FUN_000391c8(unsigned char), FUN_0003e608(void), FUN_0003e614(unsigned, int), FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_0003a020(int);
extern unsigned FUN_00040700(void); extern int FUN_00040b40(void); extern unsigned char *FUN_0003f29c(int, int);
extern int DAT_0005c050, DAT_000758dc; extern unsigned char DAT_0005c054[];
int FUN_000297b8(void)
{
    int k, esc; unsigned t; unsigned char *img;
    FUN_000391b0(DAT_0005c050);
    FUN_000391c8(DAT_0005c050 ^ 1);
    esc = 0;
    for (k = 0; k < 0x52; k++) {
        FUN_0003e608();
        t = FUN_00040700() + 0x12;
        img = FUN_0003f29c(DAT_000758dc + 0x7e + k, 0);
        if (k == 0) {
            FUN_0003a380(0, 0, 0, img);
            FUN_0003e614(0x12, 0);
            FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
        } else {
            img[8] = 0xff;
            FUN_0003a380(0, 0, 0, img);
        }
        FUN_0003a020(DAT_0005c050 ^ 1);
        while (t > FUN_00040700()) {
            if (FUN_00040b40() == 0x1b) {
                esc = 1;
                break;
            }
        }
        if (esc) break;
    }
    return esc;
}

#undef FUN_0003a380
/* ---- from build/var/mod/parts/p29888.c */
extern void FUN_000291c0(void); /* module prototype */
extern void FUN_00029464(void); /* module prototype */
#define DAT_0005f050 ((unsigned char *)DAT_0005f050)
#define FUN_000391b0 ((void (*)(int))FUN_000391b0)
#define FUN_000391c8 ((void (*)(int))FUN_000391c8)
/* FUN_00029888 @ 00029888: play the intro (logo, title cards with timed waits, ESC skips) unless the config disables it, then restore the palette and start the main menu */
void *memset(void *, int, unsigned);
extern void FUN_0003f844(void), FUN_00039234(unsigned char *), FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00030294(void), FUN_00038ce8(void), FUN_00038e58(int, int, int), FUN_0003e614(unsigned, int), FUN_0003e510(int, int, int, int), FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_00042220(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_0003ecb4(int, int);
extern int FUN_00023ef8(int), FUN_00040b40(void);
extern unsigned FUN_00040700(void);
extern unsigned char DAT_0005c02c, DAT_0005c02b, DAT_0005c054[];
extern int DAT_000758dc;


void FUN_00029888(void)
{
    int skip;
    unsigned t;
    FUN_0003f844();
    *(int *)&DAT_00064090 = DAT_0005c02c;
    *(int *)&DAT_00064094 = DAT_0005c02b;
    DAT_0005c02c = 1;
    DAT_0005c02b = 1;
    if (!DAT_0005f050[0x72]) {
        memset(DAT_0005c054, 0, 0x300);
        FUN_00039234(DAT_0005c054);
        FUN_000425b0(DAT_0005c054, 0, 0, "COLORS", 0x100);
        FUN_000391b0(((unsigned char)DAT_0005c050) ^ 1);
        FUN_000391c8(((unsigned char)DAT_0005c050) ^ 1);
        FUN_00030294();
        skip = FUN_00023ef8(0);
        if (!skip) {
            FUN_000391b0(((unsigned char)DAT_0005c050));
            FUN_000391c8(((unsigned char)DAT_0005c050) ^ 1);
            memset(DAT_0005c054, 0, 0x300);
            FUN_00039234(DAT_0005c054);
            FUN_00030294();
            FUN_00038ce8();
            FUN_00038e58(0x19, 1, 0x9c4);
            skip = FUN_00023ef8(0xc);
            FUN_000391b0(((unsigned char)DAT_0005c050) ^ 1);
            FUN_000391c8(((unsigned char)DAT_0005c050) ^ 1);
        }
        if (!skip) {
            FUN_00038e58(0x2c, 1, 0x9c4);
            FUN_0003e614(0x78, 0);
            FUN_00030294();
            FUN_000425b0(DAT_0005c054, 0, 0xe, "COLORS.", 0x100);
            t = FUN_00040700() + 0x78;
            FUN_0003e510(0x8f, 0x28, DAT_000758dc + 0x4f, 0);
            FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            FUN_0003ecb4(DAT_000758dc + 0x50, 0);
            while (t > FUN_00040700())
                if (FUN_00040b40() == 0x1b) {
                    skip = 1;
                    break;
                }
        }
        if (!skip) {
            FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
            FUN_00030294();
            t = FUN_00040700() + 0x6a;
            FUN_0003e510(0x8a, 0x24, DAT_000758dc + 0x50, 0);
            FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            FUN_0003ecb4(DAT_000758dc + 0x51, 0);
            while (t > FUN_00040700())
                if (FUN_00040b40() == 0x1b) {
                    skip = 1;
                    break;
                }
        }
        if (!skip) {
            FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
            FUN_00030294();
            t = FUN_00040700() + 0x79;
            FUN_000425b0(DAT_0005c054, 0, 9, "COLORS", 0x100);
            FUN_0003e510(0, 0, DAT_000758dc + 0x51, 0);
            FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            FUN_0003ecb4(DAT_000758dc + 0x52, 0);
            while (t > FUN_00040700())
                if (FUN_00040b40() == 0x1b) {
                    skip = 1;
                    break;
                }
        }
        FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
        FUN_00030294();
        FUN_000425b0(DAT_0005c054, 0, 0xc, "COLORS", 0x100);
        if (!skip) {
            t = FUN_00040700() + 0x37;
            FUN_000425b0(DAT_0005c054, 0, 0xc, "COLORS", 0x100);
            FUN_0003e510(0, 0, DAT_000758dc + 0x52, 0);
            FUN_000422ec(DAT_0005c054, 0, 0xff, 0, 0, 0);
            while (t > FUN_00040700())
                if (FUN_00040b40() == 0x1b) {
                    skip = 1;
                    break;
                }
        }
        if (!skip) FUN_000291c0();
        else FUN_00038ce8();
    }
    FUN_000425b0(DAT_0005c054, 0, 0xc, "COLORS", 0x100);
    FUN_00039234(DAT_0005c054);
    FUN_00029464();
}

#undef DAT_0005f050
#undef FUN_000391b0
#undef FUN_000391c8

/* ---- module data _DATA 00058210-000585fc (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
struct PT DAT_00058210[4] = { -0x46, 0x55, 0x4f, -0xf0, 0x190, 0, 0x155, 0x140 };
struct PT DAT_00058230[4] = { 7, 0x55, 0x4f, 0, 0xc8, 0, 0x155, 0x8f };
struct PT DAT_00058250[4] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct PT DAT_00058270[4] = { -0x46, 0x55, 0x4f, -0xf0, 0x190, 0, 0x155, 0x140 };
struct ME DAT_00058290[4] = { 0x10e, 0x21, 0x11d, 0x11f, 0x2f, 0x12c, 0x12e, 0x27, 0x13d, 0x13f, 0x40, 0x18f };
char s_Ver_1_2a_000582c0[12] = { 0x56, 0x65, 0x72, 0x20, 0x31, 0x2e, 0x32, 0x61, 0, -1, -1, -1 };
struct QZ DAT_000582cc[51] = {
    4, "BASIC TRAINING", "FIRST", "WANDERING",
    4, "BASIC TRAINING", "TWELFTH", "WOLF",
    7, "APPRENTICE INSTRUCTIONS", "EIGHTH", "ENCOUNTER",
    10, "MOVEMENT", "THIRTEENTH", "SIMPLE",
    0xc, "STEP MOVEMENT", "FOURTH", "POSSIBLE",
    0xc, "NPC ENCOUNTERS", "FOURTH", "FIREBALLS",
    0xd, "NPC DIALOG", "SEVENTH", "CONVERSE",
    0x13, "SAVE", "FOURTEENTH", "ADVENTURE",
    0x14, "INVENTORY SCREEN", "NINTH", "OVER",
    0x17, "AUTOMAPPING", "NINTH", "LABYRINTHS",
    0x19, "COMBAT MECHANICS", "FIRST", "UNDERSTANDING",
    0x1a, "DAMAGE", "FOURTH", "HIT",
    0x1a, "COMBAT STRATEGIES", "FOURTH", "THROWN",
    0x1a, "MOVING AND FIGHTING", "FIFTH", "COMPASS",
    0x1b, "HINTS", "FIRST", "HERE",
    0x1e, "GENERATING CHARACTERS", "SIXTH", "PROVIDES",
    0x1e, "GENERATING CHARACTERS", "EIGHTH", "UNIQUE",
    0x21, "CHARACTER BASICS", "THIRD", "INHABIT",
    0x22, "DWARVES", "SEVENTH", "GAME",
    0x23, "ELVES", "NINTH", "CAREFREE",
    0x23, "GNOMES", "SEVENTH", "PRACTICAL",
    0x25, "CLASSES", "THIRD", "LEARN",
    0x26, "MAGES", "THIRD", "POWERFUL",
    0x27, "PALADINS", "FOURTH", "AURA",
    0x28, "ALIGNMENTS", "THIRD", "SIX",
    0x29, "ABILITY SCORES", "SEVENTH", "NATURAL",
    0x2c, "RACIAL ADVANTAGES", "THIRD", "WONDERING",
    0x2d, "SPELLS", "FOURTH", "PERILOUS",
    0x43, "STRATEGIES FOR USING SPELLS", "THIRD", "HOSTILE",
    0x46, "BAT, SKELETAL", "THIRD", "ANIMATED",
    0x46, "BRIGANDS", "EIGHTH", "COMMON",
    0x46, "BROKEN ONES", "FIFTH", "TRAGIC",
    0x48, "GARGOYLE", "THIRD", "FEROCIOUS",
    0x49, "GHOUL/GHAST", "FIRST", "ONCE",
    0x4a, "GOLEM, BONE", "FIFTH", "ARTIFICIAL",
    0x4c, "HELL HOUND", "THIRD", "MONSTROUS",
    0x4c, "LIVING WALL", "FOURTH", "APPEAR",
    0x4d, "LYCANTHROPE, WEREBAT", "THIRD", "THEMSELVES",
    0x4e, "LYCANTHROPE, WEREWOLF", "ELEVENTH", "TRANSFORM",
    0x4f, "INQUISITOR", "THIRTEENTH", "TORTURING",
    0x4f, "PYRE ELEMENTAL", "EIGHTH", "INTELLIGENT",
    0x50, "REVENANT", "SIXTH", "SPIRITS",
    0x50, "SHADOW FIEND", "TENTH", "MISTAKEN",
    0x51, "SPECTRE", "THIRD", "POWERFUL",
    0x51, "STRAHD SKELETON", "SECOND", "MAGICALLY",
    0x52, "STRAHD ZOMBIE", "FOURTH", "SKELETONS",
    0x52, "TREANT, EVIL", "SIXTH", "KNOWN",
    0x53, "VAMPIRE, FEMALE", "SIXTH", "CREATURES",
    0x53, "WIGHT", "FOURTH", "WORD",
    0x54, "WORG", "FOURTH", "CARNIVORES",
    0x54, "ZOMBIE LORD", "NINTH", "HANGS"
};
/* ---- end of module data _DATA */
