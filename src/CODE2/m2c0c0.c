/* Module: FUN_0002c0c0, FUN_0002c124, FUN_0002c160, FUN_0002c1a0, FUN_0002c1dc, FUN_0002c21c, FUN_0002c258,
   FUN_0002c2c4, FUN_0002c2cc, FUN_0002c328, FUN_0002c368, FUN_0002c40c, FUN_0002c77c, FUN_0002c924,
   FUN_0002ca2c, FUN_0002cd48, FUN_0002ce68, FUN_0002e4a0, FUN_0002e534, FUN_0002e594, FUN_0002e74c,
   FUN_0002e75c, FUN_0002e8c8, FUN_0002e930, FUN_0002e9a0, FUN_0002ea04, FUN_0002ea78, FUN_0002ea90,
   FUN_0002edac, FUN_0002ef7c, FUN_0002f120, FUN_0002f1c8, FUN_0002f3fc, FUN_0002f494, FUN_0002f7b0,
   FUN_0002f7f8, FUN_0002f80c, FUN_0002f820, FUN_0002f86c, FUN_0002f8e0, FUN_0002f8fc, FUN_0002fb80,
   FUN_0002fc14, FUN_00030294, FUN_000302f0, FUN_00030440, FUN_000305b4, main */
/* ---- from build/var/mod/parts/p2c0c0.c */
/* FUN_0002c0c0 @ 0002c0c0 */
extern unsigned char DAT_0005c02f; extern int DAT_0005c658;
void FUN_0002c0c0(int a)
{
    if (DAT_0005c02f) DAT_0005c658 = (((a / 45 + 1) % 8) / 2) * 90;
    else DAT_0005c658 = a;
}

/* ---- from build/var/mod/parts/p2c124.c */
/* (FUN_0002c124 and FUN_0002c1dc are defined in this module) */
/* MATCH (round 66 lane BA): FUN_0002ce68, 5688/5688, flags -3s -ox -oe -oa -ot -w0
   (python3 tools/realcc.py match CODE.2 <file> "-3s -ox -oe -oa -ot -w0": FUN_0002c124, FUN_0002c1dc, FUN_0002ce68 MATCH).
   Key: the flag test / set are the module's own functions FUN_0002c1dc / FUN_0002c124, defined earlier in the module
   and expanded in line under -oe (<= 20 nodes).  An expanded call gives the same instructions as the macro but two more
   savings-4 conflicts (the argument copy and the f piece) at the head of its case, and a named result `r = call;`
   adds one more (a copy after the sar result that decides shape A when it is allocated first).  These change the
   ShellSort order of the savings-4 tie group, which decides each test's shape.  Calls in the second operand of && / ||
   and in comma expressions are not expanded (cases 56, 84 keep real calls, as in the original).
   Per site (layout order: shape, source form):  0x92 A macro | 0x84 A call+r | 0x4b(c10) B macro | 0x4c B macro |
   0x30 B call | 0x49 B macro | 0x4b(c28) A call+r | 0x4d C macro | 0xac B macro | 0x3e A call+r | 0x4e B macro |
   0xaf B call+r | 0x2b B macro | 0x38 B call | 0x4a A macro | 0xbd B call | 9 C macro | 0x50 B call | 0x17 B call |
   0xd1 B call | 0x28 B macro.  Sets: SETF(0x55) macro, FUN_0002c124 for 0xca and 0xcf.  Case 20 as nested ifs (the
   0x30 test is expanded only outside the comma/&& form); case 96 names the
   rand() result in place (one more savings-4 conflict in the tail).  Found with build/var/r66ba/s3.c (splice simulator
   over per-case conflict segments, ShellSort + K/tA/tS/R model, verified against the real compiler).
   The macro/call choice per site and the named r exist only for the bytes (marked STANDIN). */
#include <stdlib.h>
extern int DAT_00072200[];
extern unsigned DAT_0005bf44;
extern void FUN_0003d9fc(void);
extern int FUN_0001f4b0(int), FUN_00024a60(char *);
void FUN_0002c124(int i) { DAT_00072200[i / 32] |= 1 << (i % 32); }

/* ---- from build/var/mod/parts/p2c160.c */
/* FUN_0002c160, FUN_0002c1dc: bit clear / test in DAT_00072200 */
extern int DAT_00072200[];
void FUN_0002c160(int i) { DAT_00072200[i / 32] &= ~(1 << (i % 32)); }

/* ---- from build/var/mod/parts/p2c1a0.c */
#define DAT_00072200 ((unsigned *)DAT_00072200)
/* FUN_0002c124, FUN_0002c1a0: bit set / toggle in DAT_00072200 */


void FUN_0002c1a0(int i) { DAT_00072200[i / 32] ^= 1 << (i % 32); }

#undef DAT_00072200
/* ---- from build/var/mod/parts/p2c1dc.c */
extern int DAT_00072200[];
extern unsigned DAT_0005bf44;
extern void FUN_0003d9fc(void);
extern int FUN_0001f4b0(int), FUN_00024a60(char *);

int FUN_0002c1dc(int i) { return (DAT_00072200[i / 32] & (1 << (i % 32))) >> (i % 32); }

/* ---- from build/var/mod/parts/p2c21c.c */
/* FUN_0002c21c @ 0002c21c */
char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern int FUN_00040700(void);
extern int DAT_0005cf54; extern unsigned char DAT_0005cf59; extern char DAT_00064580[];
void FUN_0002c21c(const char *s)
{
    DAT_0005cf54 = FUN_00040700() + 0x5a;
    strcpy(DAT_00064580, s);
    DAT_0005cf59 = 1;
}

/* ---- from build/var/mod/parts/p2c258.c */
/* FUN_0002c258 @ 0002c258 */
extern void FUN_000391b0(unsigned char); extern void FUN_0003939c(int, int, int, int); extern void FUN_0004060c(int, int, void *, int); extern void FUN_0002a8c8(int, int, int, int, int);
extern unsigned char DAT_0005cf59; extern int DAT_0005c050, DAT_0007222c; extern char DAT_00064580[];
void FUN_0002c258(void)
{
    if (DAT_0005cf59) {
        FUN_000391b0(DAT_0005c050);
        FUN_0003939c(0, 0x106, 0x20, DAT_0007222c);
        FUN_0004060c(0x107, 0x22, DAT_00064580, 1);
        FUN_0002a8c8(DAT_0005c050, 0x106, 0x20, 0xc, 0x100);
        DAT_0005cf59 = 0;
    }
}

/* ---- from build/var/mod/parts/p2c2c4.c */
extern void FUN_0002c258(void); /* module prototype */
#define FUN_00040700 ((unsigned (*)(void))FUN_00040700)
/* FUN_0002c2cc @ 0002c2cc */
 extern void FUN_000391b0(unsigned char); extern void FUN_0003939c(int, int, int, int); extern void FUN_0002a8c8(int, int, int, int, int);
extern int DAT_0005cf54; extern int DAT_0005c050, DAT_0007222c;

void FUN_0002c2cc(void);
void FUN_0002c2c4(void) { FUN_0002c258(); FUN_0002c2cc(); }

 extern void FUN_000391b0(unsigned char); extern void FUN_0003939c(int, int, int, int); extern void FUN_0002a8c8(int, int, int, int, int);
extern int DAT_0005cf54; extern int DAT_0005c050, DAT_0007222c;


void FUN_0002c2cc(void)
{
    if (FUN_00040700() > DAT_0005cf54) {
        FUN_000391b0(DAT_0005c050);
        FUN_0003939c(0, 0x106, 0x20, DAT_0007222c);
        DAT_0005cf54 = -1;
        FUN_0002a8c8(DAT_0005c050, 0x106, 0x20, 0xc, 0x100);
    }
}

#undef FUN_00040700
/* ---- from build/var/mod/parts/p2c328.c */
/* FUN_0002c328 @ 0002c328: roll n dice of d sides, each plus b, then add bonus; at least 1 */
int rand(void);
#pragma aux FUN_0002c328 modify [ebx ecx edx];
int FUN_0002c328(int n, int d, int b, int bonus)
{
    int t, k;
    t = 0;
    for (k = 0; k < n; k++) {
        t += ((unsigned)rand() * d >> 15) + 1;
        t += b;
    }
    t += bonus;
    if (t < 1) t = 1;
    return t;
}

/* ---- from build/var/mod/parts/p2c368.c */
/* FUN_0002c368 @ 0002c368: read string n of the open string file into buf (stored XOR 0xdc) */
extern void FUN_0004131c(int, int, int), FUN_000412ec(void *, unsigned, int); extern int DAT_00072224;
void FUN_0002c368(unsigned char *buf, int n)
{
    int off; unsigned short len;
    FUN_0004131c(n * 4 + 4, 0, DAT_00072224);
    FUN_000412ec(&off, 4, DAT_00072224);
    FUN_0004131c(off, 0, DAT_00072224);
    FUN_000412ec(&len, 2, DAT_00072224);
    FUN_000412ec(buf, len, DAT_00072224);
    buf[len] = 0;
    if (len) do buf[len - 1] ^= 0xdc; while (--len);
}

/* ---- from build/var/mod/parts/p2c40c.c */
/* Round 41: MATCH in module 0x2c0c0 (-3s -ox -oe -oa -ot). The top/bottom loop counts from 0 like the right-edge loop (i < (w - 0x40) / 2, x + i and x + w - 0x10 - i): the loop optimiser builds both inductions and the replaced bound, which gives the original preheader (x + w recomputed, one load of x for the bound and the start, bound in a frame slot). Round 15 had this shape but an early ebx/esi tie moved in the module text of that time; in the current module text it does not. Earlier notes (rounds 15-39) described the pointer-form loop. */
int rand(void);
extern void FUN_0003ecb4(int, int), FUN_0003e590(int), FUN_0003978c(int, int, int, int, int), FUN_0003e5d4(void);
extern int DAT_000758dc;
void FUN_0002c40c(int win, int x, int y, int w, int h)
{
    int i, j, k, e;
    if (w < 0x40) w = 0x40;
    if (h < 0x50) h = 0x50;
    w = w + 0x1f & ~0x1f;
    h = h + 0xf & ~0xf;
    FUN_0003ecb4(DAT_000758dc + 0x29, 0);
    FUN_0003ecb4(DAT_000758dc + 0x2a, 0);
    FUN_0003ecb4(DAT_000758dc + 0x2b, 0);
    FUN_0003e590(win);
    FUN_0003978c(8, x - 0x10, y - 8, DAT_000758dc + 0x29, 0);
    FUN_0003978c(4, x + w, y - 8, DAT_000758dc + 0x29, 0);
    FUN_0003978c(7, x + w, y + h, DAT_000758dc + 0x29, 0);
    FUN_0003978c(0xb, x - 0x10, y + h, DAT_000758dc + 0x29, 0);
    FUN_0003978c(0, x + (w - 0x40) / 2, y - 0x20, DAT_000758dc + 0x2a, 0);
    FUN_0003978c(1, x + (w - 0x40) / 2, y + h, DAT_000758dc + 0x2a, 0);
    FUN_0003978c(0, x + w, (h - 0x50) / 2 + y, DAT_000758dc + 0x2b, 0);
    for (j = 0; j < h; j += 8) FUN_0003978c(((unsigned)rand() * 2 >> 15) + 9, x - 0x10, y + j, DAT_000758dc + 0x29, 0);
    for (j = 0; j < (h - 0x50) / 2; j += 8) {
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 5, x + w, y + j, DAT_000758dc + 0x29, 0);
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 5, x + w, y + h - 8 - j, DAT_000758dc + 0x29, 0);
    }
    for (i = 0; i < (w - 0x40) / 2; i += 0x10) {
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 0xc, x + i, y - 8, DAT_000758dc + 0x29, 0);
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 0xc, x + w - 0x10 - i, y - 8, DAT_000758dc + 0x29, 0);
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 0xe, x + i, y + h, DAT_000758dc + 0x29, 0);
        FUN_0003978c(((unsigned)rand() * 2 >> 15) + 0xe, x + w - 0x10 - i, y + h, DAT_000758dc + 0x29, 0);
    }
    for (i = 0; i < w; i += 0x10)
        for (j = 0; j < h; j += 8) FUN_0003978c((unsigned)rand() * 4 >> 15, x + i, y + j, DAT_000758dc + 0x29, 0);
    FUN_0003e5d4();
}

/* ---- from build/var/mod/parts/p2c77c.c */
extern void FUN_0002c368(unsigned char *buf, int n); /* module prototype */
extern void FUN_0002c40c(int win, int x, int y, int w, int h); /* module prototype */
/* the module declaration (seen through a cast view below) */ extern unsigned char DAT_000718e0;
#define DAT_000718e0 ((char *)&DAT_000718e0)
/* FUN_0002c77c @ 0002c77c: party member i says string s: bubble sized to the text, portrait, text, wait for a click */
void *memset(void *, int, unsigned);
extern void *FUN_0004104c(int); extern void FUN_0002a9f8(void), FUN_000391b0(unsigned char), FUN_00024118(unsigned char *, char *, int);
extern int FUN_00023fd4(int, int, int, int, int, char *, int); extern void FUN_0003975c(int, int, int, int, int), FUN_000246b8(int), FUN_0002a510(int), FUN_0003e614(unsigned, int), FUN_00032d70(void), FUN_00037ff0(void), FUN_000410b0(void *);
extern int FUN_0002a1f4(void);
extern int DAT_0005c050, DAT_000758e4, DAT_0005bf2c, DAT_00075614; extern unsigned char DAT_0005759c[];  extern short DAT_0005a6be, DAT_0005a6bc;
void FUN_0002c77c(int i, int s)
{
    char *buf; int n, pic;
    buf = FUN_0004104c(0x800);
    memset(buf, 0, 0x800);
    FUN_0002a9f8();
    FUN_000391b0(DAT_0005c050);
    FUN_0002c368(DAT_0005759c, s);
    FUN_00024118(DAT_0005759c, buf, 0x800);
    n = FUN_00023fd4(1, 0x7e, 0x55, 0xc, 0x96, buf, 1);
    n++;
    pic = *(unsigned char *)(DAT_000718e0 + i * 0x248 + 0x13) * 0x17 + DAT_000758e4 + *(signed char *)(DAT_000718e0 + i * 0x248 + 0x12);
    if (*(unsigned short *)(DAT_000718e0 + i * 0x248 + 0x10) & 0x100) pic += 0x2e;
    FUN_0002c40c(DAT_0005c050, 0x20, 0x50, n * 0xc + 0x5e, 0xa0);
    FUN_0003975c(0, 0x24, 0x86, pic, 1);
    FUN_00023fd4(1, 0x7e, 0x55, 0xc, 0x96, buf, 1);
    if (DAT_0005bf2c) FUN_000246b8(DAT_00075614 + DAT_0005bf2c);
    FUN_0002a510(DAT_0005c050);
    DAT_0005a6be = 0;
    DAT_0005a6bc = 0;
    DAT_0005c050 ^= 1;
    FUN_0003e614(9, 0);
    while (FUN_0002a1f4()) ;
    while (!FUN_0002a1f4()) ;
    while (FUN_0002a1f4()) ;
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    FUN_0002a9f8();
    FUN_00032d70();
    if (DAT_0005bf2c) {
        FUN_00037ff0();
        DAT_0005bf2c = 0;
    }
    FUN_000410b0(buf);
}

#undef DAT_000718e0
/* ---- from build/var/mod/parts/p2c924.c */
/* FUN_0002c924 @ 0002c924: pick a random living, able party member */
#include "chars.h"
int rand(void);
extern unsigned short DAT_000718f0;
#define CH10(k) (*(unsigned short *)((char *)&DAT_000718f0 + (k) * 0x248))
int FUN_0002c924(void)
{
    int k, start;
    start = ((unsigned)rand() << 2) >> 15;
    k = start;
    do {
        if (!(CH10(k) & 0x80) && !(CH10(k) & 0xf240)) break;
        k = (k + 1) % 4;
    } while (k != start);
    while (CH10(k) & 0xf240) k = (k + 1) % 4;
    return k;
}

#undef CH10
/* ---- from build/var/mod/parts/p2ca2c.c */
/* MATCH (round 47): the record pointer is `p = &DAT_000718e0[i]` at the loop top of an index loop (recipes 127 / 144), struct PC from include/records.h. The stepped pointer in the for clauses put `mov eax, OFFSET` ahead of the hoisted load of n; as a strength-reduction temp its initialiser follows it, as in the original. Earlier notes (rounds 40-41: `for (...; i < 4 && r == -1; ...)`, q = p for the cases) still hold. */
/* FUN_0002ca2c @ 0002ca2c: first able party member that meets condition n (alignment, high/low ability, race, gender, class), -1 if none */
#include "records.h"
#define DAT_000718e0 ((struct PC *)&DAT_000718e0)

int FUN_0002ca2c(int n)
{
    int r, i; struct PC *p, *q;
    r = -1;
    for (i = 0; i < 4 && r == -1; i++) {
        p = &DAT_000718e0[i];
        q = p;
        if (p->fl & 0xf240) continue;
        switch (n) {
        case 34: if (q->fl & 0x80) r = i; break;
        case 0: if (q->align == 0) r = i; break;
        case 1: if (q->align == 2) r = i; break;
        case 2: if (q->align == 4) r = i; break;
        case 3: if (q->align == 1) r = i; break;
        case 4: if (q->align == 3) r = i; break;
        case 5: if (q->align == 5) r = i; break;
        case 6: if (q->ab[10] > 16) r = i; break;
        case 7: if (q->ab[10] < 10) r = i; break;
        case 8: if (q->ab[0] > 16) r = i; break;
        case 9: if (q->ab[0] < 10) r = i; break;
        case 10: if (q->ab[6] > 16) r = i; break;
        case 11: if (q->ab[6] < 10) r = i; break;
        case 12: if (q->ab[2] > 16) r = i; break;
        case 13: if (q->ab[2] < 10) r = i; break;
        case 14: if (q->ab[4] > 16) r = i; break;
        case 15: if (q->ab[4] < 10) r = i; break;
        case 16: if (q->ab[8] > 16) r = i; break;
        case 17: if (q->ab[8] < 10) r = i; break;
        case 18: if (q->race == 0) r = i; break;
        case 19: if (q->race == 5) r = i; break;
        case 20: if (q->race == 1) r = i; break;
        case 21: if (q->race == 4) r = i; break;
        case 22: if (q->race == 3) r = i; break;
        case 23: if (q->race == 2) r = i; break;
        case 24: if (q->race != 0 && q->race != 1) r = i; break;
        case 31: if (q->sex == 0) r = i; break;
        case 32: if (q->sex == 1) r = i; break;
        case 27: if (q->cls[0] == 1) r = i; break;
        case 25: if (q->cls[0] == 0 || q->cls[1] == 0 || q->cls[2] == 0) r = i; break;
        case 26: if (q->cls[0] == 2 || q->cls[1] == 2 || q->cls[2] == 2) r = i; break;
        case 30: if (q->cls[0] == 5 || q->cls[1] == 5 || q->cls[2] == 5) r = i; break;
        case 29: if (q->cls[0] == 3 || q->cls[1] == 3 || q->cls[2] == 3) r = i; break;
        case 28: if (q->cls[0] == 4 || q->cls[1] == 4 || q->cls[2] == 4) r = i; break;
        }
    }
    return r;
}

#undef DAT_000718e0
/* ---- from build/var/mod/parts/p2cd48.c */
extern int FUN_0002c1dc(int i); /* module prototype */
extern void FUN_0002c77c(int i, int s); /* module prototype */
extern int FUN_0002c924(void); /* module prototype */
extern int FUN_0002ca2c(int n); /* module prototype */
/* FUN_0002cd48 @ 0002cd48: unless flag f (+0x80) is already set, say the first of up to four lines whose condition t holds (t == 0x21: always, by the party leader), then set the flag (FUN_0002c924 takes no arguments: the pushed s is the second argument of FUN_0002c77c) */
 
extern int DAT_00072200[];
void FUN_0002cd48(int f, int t1, int s1, int t2, int s2, int t3, int s3, int t4, int s4)
{
    int r, s;
    if (f != -1) f += 0x80;
    if (f == -1 || !FUN_0002c1dc(f)) {
        s = s1 + 0x292;
        if (t1 == 0x21) FUN_0002c77c(FUN_0002c924(), s);
        else if ((r = FUN_0002ca2c(t1)) != -1) FUN_0002c77c(r, s);
        else {
            s = s2 + 0x292;
            if (t2 == 0x21) FUN_0002c77c(FUN_0002c924(), s);
            else if ((r = FUN_0002ca2c(t2)) != -1) FUN_0002c77c(r, s);
            else {
                s = s3 + 0x292;
                if (t3 == 0x21) FUN_0002c77c(FUN_0002c924(), s);
                else if ((r = FUN_0002ca2c(t3)) != -1) FUN_0002c77c(r, s);
                else {
                    s = s4 + 0x292;
                    if (t4 == 0x21) FUN_0002c77c(FUN_0002c924(), s);
                    else if ((r = FUN_0002ca2c(t4)) != -1) FUN_0002c77c(r, s);
                }
            }
        }
    }
    if (f != -1) DAT_00072200[f / 32] |= 1 << f % 32;
}

/* ---- from build/var/mod/parts/p2ce68.c */
extern void FUN_0002c77c(int i, int s); /* module prototype */
extern int FUN_0002ca2c(int n); /* module prototype */
extern void FUN_0002cd48(int f, int t1, int s1, int t2, int s2, int t3, int s3, int t4, int s4); /* module prototype */
extern int DAT_00072200[];
extern unsigned DAT_0005bf44;
extern void FUN_0003d9fc(void);
extern int FUN_0001f4b0(int), FUN_00024a60(char *);




#define FLAG(n) ((DAT_00072200[(n) / 32] & 1 << (n) % 32) >> (n) % 32)
#define SETF(n) (DAT_00072200[(n) / 32] |= 1 << (n) % 32)
#define RND(n) ((unsigned)(rand() * (n)) >> 15)
void FUN_0002ce68(void)
{
    int f;
    int r; /* STANDIN: named test results (allocation order) */
    switch (DAT_0005bf44) {
    case 9999:
        FUN_0002cd48(0, 26, 0, 19, 1, 33, 2, -1, -1);
        break;
    case 1:
        FUN_0002cd48(1, 29, 3, 0, 4, 28, 5, 33, 6);
        break;
    case 4:
        f = 0x84;
        r = FUN_0002c1dc(f); /* STANDIN: named test result (allocation order) */
        if (!r) {
            FUN_0002cd48(4, 33, 8, -1, -1, -1, -1, -1, -1);
            FUN_0002cd48(-1, 33, 9, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 5:
        FUN_0002cd48(5, 30, 10, 33, 11, -1, -1, -1, -1);
        break;
    case 7:
        FUN_0002cd48(-1, 8, 15, 25, 16, 33, 17, -1, -1);
        break;
    case 8:
        FUN_0002cd48(8, 26, 18, 19, 19, -1, -1, -1, -1);
        break;
    case 9:
        FUN_0002cd48(9, 33, 20, -1, -1, -1, -1, -1, -1);
        break;
    case 10:
        f = 0x4b;
        if (FLAG(f)) FUN_0002cd48(10, 26, 21, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        SETF(0x8a);
        break;
    case 12:
        FUN_0002cd48(12, 27, 26, 0, 26, -1, -1, -1, -1);
        break;
    case 13:
        FUN_0002cd48(13, 29, 27, -1, -1, -1, -1, -1, -1);
        break;
    case 14:
        FUN_0002cd48(14, 29, 28, 27, 28, 33, 29, -1, -1);
        break;
    case 15:
        FUN_0002cd48(15, 10, 30, -1, -1, -1, -1, -1, -1);
        break;
    case 16:
        FUN_0002cd48(16, 27, 31, 0, 31, 26, 33, 33, 32);
        FUN_0002cd48(17, 28, 34, 19, 35, 21, 36, -1, -1);
        break;
    case 17:
    case 18:
        f = 0x92;
        if (!FLAG(f)) { /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
            FUN_0002cd48(18, 33, 37, -1, -1, -1, -1, -1, -1);
            if (DAT_0005bf44 != 0x12) FUN_0002cd48(-1, 33, 38, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 19:
        FUN_0002cd48(19, 21, 39, 33, 40, -1, -1, -1, -1);
        break;
    case 20:
        f = 0x55; SETF(f);
        f = 0x4c;
        if (FLAG(f) == 1) { /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
            f = 0x30;
            if (!FUN_0002c1dc(f)) FUN_0002cd48(20, 33, 41, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 21:
        f = 0x49;
        if (FLAG(f)) FUN_0002cd48(-1, 33, 43, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        else FUN_0002cd48(-1, 33, 42, -1, -1, -1, -1, -1, -1);
        break;
    case 22:
        FUN_0002cd48(-1, 33, 44, -1, -1, -1, -1, -1, -1);
        break;
    case 23:
        FUN_0002cd48(23, 33, 45, -1, -1, -1, -1, -1, -1);
        break;
    case 24:
        FUN_0002cd48(24, 33, 46, -1, -1, -1, -1, -1, -1);
        break;
    case 25:
        FUN_0002cd48(-1, 33, 47, -1, -1, -1, -1, -1, -1);
        break;
    case 26:
        FUN_0002cd48(-1, 33, 48, -1, -1, -1, -1, -1, -1);
        break;
    case 28:
        f = 0x4b;
        r = FUN_0002c1dc(f); /* STANDIN: named test result (allocation order) */
        if (r) FUN_0002cd48(28, 33, 54, -1, -1, -1, -1, -1, -1);
        SETF(0x9c);
        break;
    case 29:
        FUN_0002cd48(29, 33, 55, -1, -1, -1, -1, -1, -1);
        break;
    case 32:
        FUN_0003d9fc();
        break;
    case 36:
        FUN_0002cd48(36, 25, 63, -1, -1, -1, -1, -1, -1);
        break;
    case 37:
        FUN_0002cd48(37, 29, 64, -1, -1, -1, -1, -1, -1);
        break;
    case 38:
        FUN_0002cd48(38, 33, 65, -1, -1, -1, -1, -1, -1);
        break;
    case 39:
        FUN_0002cd48(39, 33, 66, -1, -1, -1, -1, -1, -1);
        break;
    case 41:
        f = 0x4d;
        if (FLAG(f) == 1) FUN_0002cd48(41, 33, 68, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        else FUN_0002cd48(41, 33, 69, -1, -1, -1, -1, -1, -1);
        break;
    case 42:
        FUN_0002cd48(42, 33, 70, -1, -1, -1, -1, -1, -1);
        break;
    case 43:
        FUN_0002cd48(43, 34, 71, -1, -1, -1, -1, -1, -1);
        break;
    case 44:
        f = 0xac;
        if (!FLAG(f) && (FUN_0002ca2c(0x1b) != -1 || FUN_0002ca2c(0) != -1)) { /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
            FUN_0002cd48(44, 27, 72, 0, 72, -1, -1, -1, -1);
            FUN_0002cd48(-1, 33, 73, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 45:
        FUN_0002cd48(45, 33, 74, -1, -1, -1, -1, -1, -1);
        FUN_0002cd48(-1, 33, 75, -1, -1, -1, -1, -1, -1);
        break;
    case 46:
        f = 0x3e;
        r = FUN_0002c1dc(f); /* STANDIN: named test result (allocation order) */
        if (!r) {
            f = 0x4e;
            if (FLAG(f) == 1) FUN_0002cd48(-1, 33, 76, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
            else FUN_0002cd48(-1, 33, 141, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 47:
        f = 0xaf;
        r = FUN_0002c1dc(f); /* STANDIN: named test result (allocation order) */
        if (!r) {
            FUN_0002cd48(47, 33, 78, -1, -1, -1, -1, -1, -1);
            if (FUN_0001f4b0(0x74) && FUN_0001f4b0(0x5c) && FUN_0001f4b0(0x76) && FUN_0001f4b0(0x8b) && FUN_0001f4b0(0x77)) FUN_0002cd48(-1, 33, 79, -1, -1, -1, -1, -1, -1);
            else FUN_0002cd48(-1, 33, 80, -1, -1, -1, -1, -1, -1);
        }
        break;
    case 48:
        FUN_0002cd48(48, 33, 81, -1, -1, -1, -1, -1, -1);
        break;
    case 49:
        FUN_0002cd48(49, 33, 82, -1, -1, -1, -1, -1, -1);
        break;
    case 50:
        FUN_0002cd48(50, 21, 83, -1, -1, -1, -1, -1, -1);
        break;
    case 51:
        FUN_0002c77c(FUN_00024a60("IRMGARDE"), 0x2e6);
        break;
    case 52:
        FUN_0002cd48(52, 10, 85, -1, -1, -1, -1, -1, -1);
        break;
    case 53:
        FUN_0002cd48(-1, 33, 86, -1, -1, -1, -1, -1, -1);
        break;
    case 54:
        FUN_0002cd48(54, 27, 87, 25, 87, 26, 87, -1, -1);
        break;
    case 55:
        FUN_0002cd48(55, 19, 88, -1, -1, -1, -1, -1, -1);
        break;
    case 56:
        f = 0x2b;
        if (FLAG(f) == 1 && !FUN_0002c1dc(0x4a)) FUN_0002cd48(56, 33, 89, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        else if (FUN_0002c1dc(0x4a) == 1) FUN_0002cd48(56, 33, 90, -1, -1, -1, -1, -1, -1);
        SETF(0xb8);
        break;
    case 57:
        FUN_0002cd48(57, 19, 91, -1, -1, -1, -1, -1, -1);
        break;
    case 58:
        FUN_0002cd48(58, 33, 92, -1, -1, -1, -1, -1, -1);
        break;
    case 59:
        f = 0x38;
        if (FUN_0002c1dc(f)) FUN_0002cd48(59, 33, 93, -1, -1, -1, -1, -1, -1);
        break;
    case 60:
        f = 0x4a;
        if (FLAG(f) == 1) FUN_0002cd48(60, 33, 95, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        else FUN_0002cd48(60, 30, 94, -1, -1, -1, -1, -1, -1);
        break;
    case 61:
        f = 0xbd;
        if (FUN_0002c1dc(f)) break;
        FUN_0002cd48(61, 33, 96, -1, -1, -1, -1, -1, -1);
    case 104:
        FUN_0002cd48(-1, 33, 137, -1, -1, -1, -1, -1, -1);
        break;
    case 62:
        FUN_0002cd48(-1, 33, 97, -1, -1, -1, -1, -1, -1);
        break;
    case 63:
        FUN_0002cd48(-1, 30, 98, 33, 98, -1, -1, -1, -1);
        break;
    case 64:
        FUN_0002cd48(-1, 30, 99, 33, 99, -1, -1, -1, -1);
        break;
    case 65:
        FUN_0002cd48(-1, 30, 100, 33, 100, -1, -1, -1, -1);
        break;
    case 66:
        FUN_0002cd48(66, 33, 101, -1, -1, -1, -1, -1, -1);
        break;
    case 67:
        FUN_0002cd48(67, 33, 102, -1, -1, -1, -1, -1, -1);
        break;
    case 68:
        FUN_0002cd48(68, 33, 103, -1, -1, -1, -1, -1, -1);
        break;
    case 69:
        FUN_0002cd48(69, 33, 103, -1, -1, -1, -1, -1, -1);
        break;
    case 70:
        FUN_0002cd48(70, 33, 103, -1, -1, -1, -1, -1, -1);
        break;
    case 71:
        FUN_0002cd48(71, 33, 103, -1, -1, -1, -1, -1, -1);
        break;
    case 72:
        FUN_0002cd48(72, 33, 103, -1, -1, -1, -1, -1, -1);
        break;
    case 73:
        FUN_0002cd48(-1, 33, 104, -1, -1, -1, -1, -1, -1);
        break;
    case 74:
        f = 0x9;
        if (FLAG(f) == 1) { /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
            f = 0xca; FUN_0002c124(f); /* STANDIN: expanded call instead of SETF (allocation order) */
            break;
        }
        f = 0x50;
        if (FUN_0002c1dc(f) == 1) FUN_0002cd48(74, 33, 107, -1, -1, -1, -1, -1, -1);
        else FUN_0002cd48(74, 33, 106, -1, -1, -1, -1, -1, -1);
        break;
    case 75:
        FUN_0002cd48(75, 33, 108, -1, -1, -1, -1, -1, -1);
        break;
    case 76:
        FUN_0002cd48(76, 27, 109, 19, 110, 33, RND(2) + 0x6f, -1, -1);
        break;
    case 77:
        f = 0x17;
        if (FUN_0002c1dc(f) == 1) FUN_0002cd48(77, 27, 113, 0, 113, 33, 114, -1, -1);
        break;
    case 78:
        FUN_0002cd48(78, 33, 115, -1, -1, -1, -1, -1, -1);
        break;
    case 79:
        if (FUN_0001f4b0(0x72)) {
            f = 0xcf; FUN_0002c124(f); /* STANDIN: expanded call instead of SETF (allocation order) */
            break;
        }
        FUN_0002cd48(79, 33, 116, -1, -1, -1, -1, -1, -1);
        break;
    case 80:
        if (FUN_0001f4b0(0x72)) FUN_0002cd48(80, 33, 117, -1, -1, -1, -1, -1, -1);
        break;
    case 81:
        f = 0xd1;
        if (!FUN_0002c1dc(f)) FUN_0002cd48(-1, 33, 118, -1, -1, -1, -1, -1, -1);
        break;
    case 84:
        f = 0x28;
        if (!FLAG(f) || !FUN_0002c1dc(0x28)) FUN_0002cd48(84, 33, 124, -1, -1, -1, -1, -1, -1); /* STANDIN: macro, not the expanded FUN_0002c1dc call (allocation order) */
        break;
    case 85:
        FUN_0002cd48(85, 33, 125, -1, -1, -1, -1, -1, -1);
        break;
    case 86:
        FUN_0002cd48(86, 33, 126, -1, -1, -1, -1, -1, -1);
        break;
    case 87:
        FUN_0002cd48(87, 33, 127, -1, -1, -1, -1, -1, -1);
        break;
    case 88:
        FUN_0002cd48(88, 33, 128, -1, -1, -1, -1, -1, -1);
        break;
    case 89:
        FUN_0002cd48(89, 33, 129, -1, -1, -1, -1, -1, -1);
        break;
    case 90:
        FUN_0002cd48(90, 33, 130, -1, -1, -1, -1, -1, -1);
        break;
    case 91:
        FUN_0002cd48(91, 33, 131, -1, -1, -1, -1, -1, -1);
        break;
    case 92:
        FUN_0002cd48(92, 33, 132, -1, -1, -1, -1, -1, -1);
        break;
    case 93:
        FUN_0002cd48(93, 33, 133, -1, -1, -1, -1, -1, -1);
        break;
    case 95:
        FUN_0002cd48(-1, 33, 135, -1, -1, -1, -1, -1, -1);
        break;
    case 96:
        FUN_0002cd48(96, 19, 110, 33, ((unsigned)((r = rand()) * 2) >> 15) + 0x6f, -1, -1, -1, -1); /* STANDIN: named rand() result (one more tie conflict) */
        break;
    case 97:
        FUN_0002cd48(97, 33, RND(2) + 0x6f, -1, -1, -1, -1, -1, -1);
        break;
    case 98:
        FUN_0002cd48(98, 33, RND(2) + 0x6f, -1, -1, -1, -1, -1, -1);
        break;
    case 99:
        break;
    case 100:
        FUN_0002cd48(100, 33, 22, -1, -1, -1, -1, -1, -1);
        break;
    case 101:
        FUN_0002cd48(101, 33, 23, -1, -1, -1, -1, -1, -1);
        break;
    case 102:
        FUN_0002cd48(102, 33, 24, -1, -1, -1, -1, -1, -1);
        break;
    case 103:
        FUN_0002cd48(103, 33, 25, -1, -1, -1, -1, -1, -1);
        break;
    case 105:
        FUN_0002cd48(-1, 33, 143, -1, -1, -1, -1, -1, -1);
        break;
    case 106:
        FUN_0002cd48(-1, 33, 144, -1, -1, -1, -1, -1, -1);
        break;
    case 107:
        FUN_0002cd48(107, 33, 145, -1, -1, -1, -1, -1, -1);
        break;
    }
    DAT_0005bf44 = 0;
}

#undef FLAG
#undef SETF
#undef RND
/* ---- from build/var/mod/parts/p2e4a0.c */
/* FUN_0002e4a0 @ 0002e4a0: expire the five per-character timers (the record offset is written as one
   parenthesised expression so it folds into the displacement) */
/* FUN_0002e4a0 @ 0002e4a0: expire the five per-character timers */
#include "chars.h"
extern unsigned FUN_00029cc4(void);
extern unsigned short DAT_000718f0; extern unsigned DAT_000719eb, DAT_00071a7e; extern unsigned char DAT_0005cf5a[];
void FUN_0002e4a0(void)
{
    unsigned t = FUN_00029cc4();
    int k, j;
    for (k = 0; k < 4; k++) {
        if (!(*(unsigned short *)((char *)&DAT_000718f0 + k * 0x248) & 0x8000)) {
            for (j = 0; j < 2; j++) {
                if (*(unsigned *)((char *)&DAT_000719eb + (k * 0x248 + j * 4)) != 0 && *(unsigned *)((char *)&DAT_000719eb + (k * 0x248 + j * 4)) <= t) { DAT_0005cf5a[k] = 1; *(unsigned *)((char *)&DAT_000719eb + (k * 0x248 + j * 4)) = 0; }
            }
            for (j = 0; j < 3; j++) {
                if (*(unsigned *)((char *)&DAT_00071a7e + (k * 0x248 + j * 4)) != 0 && *(unsigned *)((char *)&DAT_00071a7e + (k * 0x248 + j * 4)) <= t) { DAT_0005cf5a[k] = 1; *(unsigned *)((char *)&DAT_00071a7e + (k * 0x248 + j * 4)) = 0; }
            }
        }
    }
}

/* ---- from build/var/mod/parts/p2e534.c */
/* FUN_0002e534 @ 0002e534 */
extern unsigned FUN_00029cc4(void);
extern unsigned DAT_0005d8b8, DAT_0005d8bc; extern unsigned char DAT_0005d681, DAT_0005d682;
void FUN_0002e534(void)
{
    unsigned t = FUN_00029cc4();
    if (DAT_0005d8b8 && t >= DAT_0005d8b8) { DAT_0005d8b8 = 0; if (DAT_0005d681) DAT_0005d681 = 2; }
    if (DAT_0005d8bc && t >= DAT_0005d8bc) { DAT_0005d8bc = 0; if (DAT_0005d682) DAT_0005d682 = 2; }
}

/* ---- from build/var/mod/parts/p2e594.c */
/* FUN_0002e594 @ 0002e594: poison and disease tick for the living party members: damage them and post "<name> FEELS THE EFFECT OF POISON/DISEASE." (poison only every fourth tick for members with slow poison) */
#include <string.h>
#define DAT_0005759c ((char *)DAT_0005759c)
#define DAT_000718e0 ((struct CHR *)&DAT_000718e0)
#define FUN_00040700 ((int (*)(void))FUN_00040700)
struct CHR { char name[0x10]; unsigned short st; char p12[0x122]; unsigned char slow : 1, b1 : 7; char rest[0x113]; };
 extern char DAT_00064580[], *DAT_0005bed8, *DAT_0005bedc; extern int DAT_0005cf54; extern unsigned char DAT_0005cf59;
extern void FUN_0001cd44(int, int); 
void FUN_0002e594(int t)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (DAT_000718e0[i].st & 0xc000) continue;
        if (DAT_000718e0[i].st & 0x800) {
            if (DAT_000718e0[i].slow && t % 4) return;
            FUN_0001cd44(i, 1);
            strcpy(DAT_0005759c, DAT_000718e0[i].name);
            strcat(DAT_0005759c, DAT_0005bed8);
            DAT_0005cf54 = FUN_00040700() + 0x5a;
            strcpy(DAT_00064580, DAT_0005759c);
            DAT_0005cf59 = 1;
        }
        if (DAT_000718e0[i].st & 0x400) {
            FUN_0001cd44(i, 3);
            strcpy(DAT_0005759c, DAT_000718e0[i].name);
            strcat(DAT_0005759c, DAT_0005bedc);
            DAT_0005cf54 = FUN_00040700() + 0x5a;
            strcpy(DAT_00064580, DAT_0005759c);
            DAT_0005cf59 = 1;
        }
    }
}

#undef DAT_0005759c
#undef DAT_000718e0
#undef FUN_00040700
/* ---- from build/var/mod/parts/p2e74c.c */
/* FUN_0002e74c @ 0002e74c: set the game clock and its last-update mark */
extern int DAT_0005a7e4, DAT_0005bf50;
void FUN_0002e74c(int t) { DAT_0005a7e4 = t; DAT_0005bf50 = t; }

/* ---- from build/var/mod/parts/p2e75c.c */
extern void FUN_0002e594(int t); /* module prototype */
/* FUN_0002e75c @ 0002e75c: advance the game clock: every 0x438 ticks an hour passes (healing, hunger), every 0x21c ticks the torch flickers */
struct ST { unsigned char f : 8; };
extern void FUN_00041f94(void); extern int FUN_0001f2d4(int, int);
extern int DAT_0005bf58, DAT_0005bf50, DAT_0005bf54, DAT_0005a7e4; extern unsigned DAT_0005cf4c; extern unsigned short DAT_000718f0; extern signed char DAT_000718f5; extern unsigned char DAT_000718f4, DAT_0005cf5a[]; extern short DAT_000718fc, DAT_000718fe; extern struct ST DAT_000719a1;
#define CH16(o) (*(unsigned short *)((char *)&DAT_000718f0 + (o)))
#define HP(o) (*(short *)((char *)&DAT_000718fc + (o)))
#define MAXHP(o) (*(short *)((char *)&DAT_000718fe + (o)))
void FUN_0002e75c(void)
{
    int d, k, off;
    if (DAT_0005bf58 == -1) {
        DAT_0005bf58 = 0;
        DAT_0005bf50 = DAT_0005a7e4;
        DAT_0005bf54 = DAT_0005a7e4;
    }
    if (DAT_0005a7e4 - DAT_0005bf50 >= 0x438) {
        d = DAT_0005a7e4 - DAT_0005bf50;
        DAT_0005bf50 = DAT_0005a7e4;
        while (d >= 0x438) {
            DAT_0005cf4c += 0x10000;
            FUN_00041f94();
            d -= 0x438;
            if ((DAT_0005cf4c & 0xffff0000) == 0) {
                for (k = 0, off = 0; k < 4; k++, off += 0x248) {
                    if (CH16(off) < 0x4000) {
                        if (*((signed char *)&DAT_000718f5 + off) == 1) ((struct ST *)((char *)&DAT_000719a1 + off))->f = 0x11;
                        if (HP(off) < MAXHP(off)) {
                            DAT_0005cf5a[k] = 1;
                            HP(off)++;
                        }
                    }
                }
            }
            for (k = 0, off = 0; k < 4; k++, off += 0x248) {
                if ((CH16(off) < 0x4000 || *((unsigned char *)&DAT_000718f4 + off) != 5) && FUN_0001f2d4(k, 0x47) && HP(off) < MAXHP(off)) {
                    DAT_0005cf5a[k] = 1;
                    HP(off)++;
                }
            }
        }
    }
    if (DAT_0005a7e4 - DAT_0005bf54 > 0x21c) {
        DAT_0005bf54 = DAT_0005a7e4;
        FUN_0002e594(DAT_0005bf58);
        DAT_0005bf58 = (DAT_0005bf58 + 1) % 4;
    }
}

#undef CH16
#undef HP
#undef MAXHP
/* ---- from build/var/mod/parts/p2e8c8.c */
/* FUN_0002e8c8 @ 0002e8c8: find the object entry of map cell (x, y) in the two per-column lists */
#include "world.h"
 extern unsigned char *DAT_0005cb3c[], *DAT_0005cd3c[];
unsigned char *FUN_0002e8c8(int x, int y)
{
    unsigned char *e, *q;
    if (x >= DAT_00075618.w || y >= DAT_00075618.h) return 0;
    e = DAT_0005cb3c[x];
    if (e) {
        while (1) {
            if (*e == 0 && !(*(int *)(e + 1) & 0x10)) break;
            if (e[4] == y) return e;
            e += 10;
        }
    }
    q = DAT_0005cd3c[x];
    if (q) {
        for (e = q; *e; e += 10) if (e[4] == y) return e;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p2e930.c */
/* FUN_0002e930 @ 0002e930: wall-decoration word of cell pos (0x8000 = none; 0 outside the map): early returns, the column list in q, the cursor p a copy of it */
#include "world.h"
 extern unsigned char *DAT_0005cd3c[];
unsigned short FUN_0002e930(int pos)
{
    int w = DAT_00075618.w;
    int y = pos / w, x = pos % w;
    unsigned char *p, *q;
    if (x >= w) return 0;
    if (y >= DAT_00075618.h) return 0;
    q = DAT_0005cd3c[x];
    if (q) {
        p = q;
        if (*q) do {
            if (p[4] == y) return p[6] << 12;
            p += 10;
        } while (*p);
    }
    return 0x8000;
}

/* ---- from build/var/mod/parts/p2e9a0.c */
/* FUN_0002e9a0 @ 0002e9a0: object list lookup for a map cell (while(1)/break keeps the loop top-tested) */
#include "world.h"
 extern unsigned char *DAT_0005cb3c[];
unsigned short FUN_0002e9a0(int pos)
{
    int w = DAT_00075618.w;
    int y = pos / w, x = pos % w;
    unsigned char *p;
    if (x < w && y < DAT_00075618.h && (p = DAT_0005cb3c[x]) != 0) {
        while (1) {
            if (!(p[0] || (*(int *)(p + 1) & 0x10))) break;
            if (p[4] == y) return p[1] & 3;
            p += 10;
        }
    }
    return 0;
}

/* ---- from build/var/mod/parts/p2ea04.c */
/* FUN_0002ea04 @ 0002ea04 */
extern void FUN_0003939c(int, int, int, int); extern int FUN_0003f29c(int, int);
extern int DAT_0005bf48, DAT_0005bf4c, DAT_0005bf5c[12], DAT_0005bf8c[12], DAT_0005c034; extern int DAT_000758dc;
void FUN_0002ea04(void)
{
    int k;
    FUN_0003939c(0, 0, 0x20, DAT_0005bf48);
    FUN_0003939c(0, 0x104, 0x20, DAT_0005bf4c);
    for (k = 0; k < 12; k++)
        FUN_0003939c(k, DAT_0005bf5c[k], DAT_0005bf8c[k], FUN_0003f29c(DAT_000758dc + 3 + DAT_0005c034 * 3, 0));
}

/* ---- from build/var/mod/parts/p2ea78.c */
/* FUN_0002ea78 @ 0002ea78 */
extern void FUN_0002a510(int); extern int DAT_0005c050;
void FUN_0002ea78(void) { FUN_0002a510(DAT_0005c050); DAT_0005c050 ^= 1; }

/* ---- from build/var/mod/parts/p2ea90.c */
/* FUN_0002ea90 @ 0002ea90: draw the hand button h of party member i (item picture or the bare-hand glyph) in palette state st (-1: derive it) */
#include "world.h"
#define DAT_000718e0 ((char *)&DAT_000718e0)
#define FUN_00029cc4 ((int (*)(void))FUN_00029cc4)
#define FUN_0003f29c ((unsigned char *(*)(int, int))FUN_0003f29c)
extern void FUN_00039b40(int, int, int, int, int), FUN_0003a258(int, unsigned char *), FUN_000398f0(int, int, int, int, int, unsigned char *), FUN_0003e374(int, int, int, int, unsigned char), FUN_0003975c(int, int, int, int, int), FUN_00040508(int, int, int, char *, int);
extern int FUN_00034478(int, int);  extern char *FUN_0003e6f0(int);
 extern short DAT_00056dae; extern int DAT_000758dc, DAT_0005cf60[]; extern unsigned char DAT_0005cf70[], DAT_0005cf68;
#define CH(i, o) (DAT_000718e0 + (i) * 0x248 + (o))
void FUN_0002ea90(int i, int h, int st)
{
    int y, it, off;
    y = h * 0x21 + 4 + i % 2 * 0x35 + i / 2 * 0xd3;
    FUN_00039b40(0x114, y, 0x20, 0x10, 0);
    if (st == -1) {
        st = 2;
        if (*(int *)CH(i, 0x10b + h * 4) || (*(unsigned short *)CH(i, 0x10) & 0xf240)) st = 0;
        else if (*(unsigned short *)CH(i, 0x10) & 0x2000) st = 1;
    }
    if (DAT_00056dae && *(short *)CH(i, 0x5c + h * 2) != -1) {
        if (((char *)DAT_000755d8)[*(short *)CH(i, 0x5c + h * 2) * 0x41 + 0x37]) st = 5;
        if (*(short *)(((char *)DAT_000755d8) + *(short *)CH(i, 0x5c + h * 2) * 0x41 + 0x32)) st = 5;
    }
    if (!FUN_00034478(i, h)) st = 0;
    it = *(short *)CH(i, 0x5c + h * 2);
    if (it != -1) {
        if (h == 0 && (unsigned)it >= 0x7e && (unsigned)it < 0x86) FUN_0003a258(h, FUN_0003f29c(*(short *)(((char *)DAT_000755d8) + it * 0x41 + 0x2d), 1));
        off = it * 0x41;
        FUN_000398f0(0, 0x114, y, *(short *)(((char *)DAT_000755d8) + off + 0x2d), 1, DAT_0005cf70 + st * 0x100);
        if (h == 0 && (unsigned)it >= 0x7e && (unsigned)it < 0x86) FUN_0003a258(h, FUN_0003f29c(*(short *)(((char *)DAT_000755d8) + off + 0x2d), 1));
    } else {
        off = (DAT_0005cf60[*(unsigned char *)CH(i, 0x13)] & 1 << *(signed char *)CH(i, 0x12)) != 0;
        if (h == 1) FUN_0003a258(off, FUN_0003f29c(DAT_000758dc + 0x2d, 0));
        FUN_000398f0(off, 0x114, y, DAT_000758dc + 0x2d, 0, DAT_0005cf70 + st * 0x100);
        if (h == 1) FUN_0003a258(off, FUN_0003f29c(DAT_000758dc + 0x2d, 0));
    }
    if (DAT_0005cf68 / 2 == i && DAT_0005cf68 % 2 == h) FUN_0003e374(0x114, y, 0x20, 0x10, 0x43);
    if (*(int *)CH(i, 0x19e + h * 4)) {
        if (FUN_00029cc4() > *(int *)CH(i, 0x19e + h * 4)) *(int *)CH(i, 0x19e + h * 4) = 0;
        else {
            FUN_0003975c(0, 0x114, y, DAT_000758dc + 0x5c, 0);
            FUN_00040508(0x120, y, 0x10, FUN_0003e6f0(*(int *)CH(i, 0x1aa + h * 4)), 0);
        }
    }
}

#undef DAT_000718e0
#undef FUN_00029cc4
#undef FUN_0003f29c
#undef CH
/* ---- from build/var/mod/parts/p2edac.c */
/* FUN_0002edac: swap the level's wall textures through the replacement table, then step the animated ones */
#include "world.h"
struct REPL { unsigned short from, to; };
extern struct REPL DAT_0005bfbc[10];
void FUN_0002edac(void)
{
    int i, j, done0, done2, t;
    for (i = 0; i < 63; i++) {
        done0 = done2 = 0;
        for (j = 0; j < 10; j++) {
            if (DAT_00075618.t0[i] == DAT_0005bfbc[j].from && !done0) {
                DAT_00075618.t0[i] = DAT_0005bfbc[j].to;
                done0 = 1;
            }
            if (DAT_00075618.t2[i] == DAT_0005bfbc[j].from && !done2) {
                DAT_00075618.t2[i] = DAT_0005bfbc[j].to;
                done2 = 1;
            }
        }
        if (DAT_00075618.t0[i] >= 0x242 && DAT_00075618.t0[i] <= 0x244) {
            t = DAT_00075618.t0[i] + 1;
            if (t > 0x244) t = 0x242;
            DAT_00075618.t0[i] = t;
            DAT_00075618.t1[i] = t + 6;
        }
        if (DAT_00075618.t2[i] >= 0x242 && DAT_00075618.t2[i] <= 0x244) {
            t = DAT_00075618.t2[i] + 1;
            if (t > 0x244) t = 0x242;
            DAT_00075618.t2[i] = t;
            DAT_00075618.t3[i] = t + 6;
        }
        if (DAT_00075618.t0[i] >= 0x245 && DAT_00075618.t0[i] <= 0x247) {
            t = DAT_00075618.t0[i] + 1;
            if (t > 0x247) t = 0x245;
            DAT_00075618.t0[i] = t;
            DAT_00075618.t1[i] = t + 6;
        }
        if (DAT_00075618.t2[i] >= 0x245 && DAT_00075618.t2[i] <= 0x247) {
            t = DAT_00075618.t2[i] + 1;
            if (t > 0x247) t = 0x245;
            DAT_00075618.t2[i] = t;
            DAT_00075618.t3[i] = t + 6;
        }
    }
}

/* ---- from build/var/mod/parts/p2ef7c.c */
/* FUN_0002ef7c @ 0002ef7c: start the music of the current area (night variants between 21:00 and 4:00) */
int rand(void);
extern void FUN_00038110(int, int, int, int);
extern unsigned DAT_0005cf4c; extern unsigned DAT_0005c6c8;
void FUN_0002ef7c(void)
{
    int h, night, m;
    h = DAT_0005cf4c >> 16;
    if (h >= 21 || h <= 4) night = 1; else night = 0;
    m = -1;
    switch (DAT_0005c6c8) {
    case 22: m = 0; break;
    case 9: case 23: case 24: case 25: case 26: case 31:
        if (night) m = (unsigned)rand() * 3 / 0x8000 + 4; else m = (unsigned)rand() * 3 / 0x8000 + 1; break;
    case 11:
        if (night) m = (unsigned)rand() * 4 / 0x8000 + 11; else m = (unsigned)rand() * 4 / 0x8000 + 7; break;
    case 1: m = 15; break;
    case 2: m = (unsigned)rand() * 2 / 0x8000 + 16; break;
    case 0: m = (unsigned)rand() * 2 / 0x8000 + 18; break;
    case 8:
        if (night) m = (unsigned)rand() * 2 / 0x8000 + 22; else m = (unsigned)rand() * 2 / 0x8000 + 20; break;
    case 3: m = (unsigned)rand() * 2 / 0x8000 + 24; break;
    case 4: m = (unsigned)rand() * 2 / 0x8000 + 26; break;
    case 12: case 13: case 14: m = (unsigned)rand() * 3 / 0x8000 + 28; break;
    case 28: case 29: m = (unsigned)rand() * 3 / 0x8000 + 32; break;
    case 6: m = (unsigned)rand() * 4 / 0x8000 + 34; break;
    case 5: m = (unsigned)rand() * 4 / 0x8000 + 38; break;
    case 16: case 17: m = (unsigned)rand() * 4 / 0x8000 + 42; break;
    }
    if (m != -1) FUN_00038110(m, 0xff, 1, 6);
}

/* ---- from build/var/mod/parts/p2f120.c */
extern void FUN_0002ef7c(void); /* module prototype */
/* FUN_0002f120 @ 0002f120: ambient sound/music for the current area */
int rand(void);
extern int FUN_0003b1bc(void), FUN_00039048(void); extern void FUN_00038ae0(int, int), FUN_000388fc(int), FUN_00038f58(int), FUN_00039008(int);
void FUN_0002f120(void)
{
    int n = FUN_0003b1bc();
    if (n > 1) {
        if (FUN_00039048() != 1) {
            if (FUN_00039048() == 2) FUN_00038ae0(1, 0x9c4);
            else FUN_000388fc(1);
        }
        n--;
        FUN_00038f58(100 - n);
        FUN_00039008(107 - n / 2);
    } else {
        if (FUN_00039048() != 2) {
            FUN_000388fc(2);
            FUN_00038f58(100);
            FUN_00039008(100);
        }
    }
    if ((int)((unsigned)(rand() * 1000) >> 15) > 0x3e6) FUN_0002ef7c();
}

/* ---- from build/var/mod/parts/p2f1c8.c */
extern void FUN_0002ea04(void); /* module prototype */
extern void FUN_0002edac(void); /* module prototype */
/* FUN_0002f1c8 @ 0002f1c8: draw one frame of the 3D view: walls, position, ambient sound, light, the left/right overlays and the HUD; round 21: with the level header struct (world.h) the locals are declared c, b (the solo flag read into c takes edx as in the original) */
#include "world.h"
#define FUN_0003f29c ((void *(*)(int, int))FUN_0003f29c)
extern void FUN_000391b0(unsigned char), FUN_000434c4(void), FUN_00044998(void), FUN_00039b40(int, int, int, int, int), FUN_000414b0(int), FUN_00043e28(int), FUN_00044a74(void), FUN_00043de0(int);
extern void FUN_00044de8(void), FUN_0002bdac(void), FUN_0003c294(void), FUN_000374a4(void), FUN_0003f868(void); 
extern int DAT_0005c050, DAT_0005fdbc, DAT_0005c044, DAT_0005c048, DAT_0005bff0, DAT_0005c658, DAT_00072220, DAT_00065618[], DAT_0005ff50, DAT_0005f920, DAT_000758f8, DAT_0005ff4c, DAT_0005ff44, DAT_0005ff48;
  extern unsigned short DAT_000755d4, DAT_000755d0; extern unsigned char DAT_0005c026, DAT_0005c027, DAT_0005c028, DAT_0005bfe4[];  extern void *DAT_0005c040;
void FUN_0002f1c8(void)
{
    int c, b;
    FUN_000391b0(DAT_0005c050);
    DAT_0005fdbc = (DAT_0005c050 << 15) + 0xa0000;
    FUN_0002edac();
    FUN_000434c4();
    DAT_0005c044 = DAT_000755d4 / 256;
    DAT_0005c048 = DAT_000755d0 / 256;
    if ((DAT_0005c026 || DAT_0005c027) && DAT_0005bff0 != DAT_0005c658) {
        DAT_0005bff0 = DAT_0005c658;
        FUN_00044998();
    }
    if (DAT_00072220 != 0x800) {
        b = DAT_00065618[DAT_00072220 / 8];
        DAT_0005ff50 = 0x80 - b / 2 + b / 8;
    } else {
        DAT_0005ff50 = 0x80;
        b = 0;
    }
    c = DAT_00075618.solo;
    if (c != 0xff) {
        if (DAT_00075618.b0 == 0x2c) FUN_00039b40(4, 0x20, 0x80, 0x100, DAT_0005bfe4[DAT_0005f920]);
        else if (DAT_0005c028) FUN_000414b0(c);
        else FUN_00043e28(DAT_00075618.b0);
    } else if (DAT_0005c027) {
        if (DAT_0005ff50 > 0) {
            DAT_0005c040 = FUN_0003f29c(DAT_00075618.s5 + DAT_000758f8, 4);
            DAT_0005ff4c = 1;
            DAT_0005ff44 = 0x50;
            DAT_0005ff48 = 0x148;
            FUN_00044a74();
        }
    } else {
        FUN_00043e28(DAT_00075618.b0);
    }
    if (DAT_0005c026) {
        DAT_0005ff50 = 0x100 - (b + DAT_0005ff50);
        if (DAT_0005ff50 > 0) {
            DAT_0005c040 = FUN_0003f29c(DAT_00075618.s7 + DAT_000758f8, 4);
            DAT_0005ff4c = -1;
            DAT_0005ff44 = -0x50;
            DAT_0005ff48 = 0x50f8;
            FUN_00044a74();
        }
    } else {
        FUN_00043de0(DAT_00075618.b1);
    }
    FUN_00044de8();
    FUN_0002bdac();
    FUN_0003c294();
    FUN_0002ea04();
    FUN_000374a4();
    FUN_0003f868();
}

#undef FUN_0003f29c
/* ---- from build/var/mod/parts/p2f3fc.c */
/* FUN_0002f3fc @ 0002f3fc: status icon of party member i */
#include "chars.h"
extern unsigned short DAT_000718f0;
#define CH10(i) (*(unsigned short *)((char *)&DAT_000718f0 + (i) * 0x248))
int FUN_0002f3fc(int i)
{
    int r = 2;
    if (CH10(i) & 0x4000) r = 0;
    else if (CH10(i) & 0x1000) r = 4;
    else if (CH10(i) & 0x40) r = 1;
    else if (CH10(i) & 0x800) r = 3;
    else if (CH10(i) & 0x400) r = 5;
    return r;
}

#undef CH10
/* ---- from build/var/mod/parts/p2f494.c */
extern void FUN_0002ea90(int i, int h, int st); /* module prototype */
extern int FUN_0002f3fc(int i); /* module prototype */
#define DAT_0005d681 ((unsigned char *)&DAT_0005d681)
#define DAT_000718e0 ((unsigned char *)&DAT_000718e0)
#define FUN_0003f29c ((int *(*)(int, int))FUN_0003f29c)
/* FUN_0002f494 @ 0002f494: redraw the dirty party portraits: dead marker or face, health bar, status overlays and hands, then flip each slot */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003e4a4(int, int, int, int, int *), FUN_0003975c(int, int, int, int, int), FUN_000398f0(int, int, int, int, int, unsigned char *), FUN_00039b40(int, int, int, int, int), FUN_0003e374(int, int, int, int, unsigned char), FUN_00040508(int, int, int, char *, int), FUN_00032f40(int, int), FUN_0002a8c8(int, int, int, int, int), FUN_00033024(int, int);

extern int FUN_0001ef14(int);
extern char *FUN_0003e6f0(int);
extern int DAT_0005c050; extern unsigned char DAT_0005cf5a[], DAT_0005d682, DAT_0005cf70[];
extern int DAT_000758dc, DAT_0005c034, DAT_000758e4, DAT_0005d8a8[];

#define RW(o) (*(unsigned short *)(DAT_000718e0 + (o) + k * 0x248))
#define RS(o) (*(short *)(DAT_000718e0 + (o) + k * 0x248))
#define RI(o) (*(int *)(DAT_000718e0 + (o) + k * 0x248))
#define RB(o) (DAT_000718e0[(o) + k * 0x248])
void FUN_0002f494(int flip)
{
    int k, y, vis, p, r, face, pct, yy, x;
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 4; k++) {
        if (!DAT_0005cf5a[k]) continue;
        y = k % 2 * 0x35;
        DAT_0005cf5a[k] = 0;
        y += k / 2 * 0xd3;
        vis = 1;
        if (k < 2 && DAT_0005d681[0]) vis = 0;
        if (k >= 2 && DAT_0005d682) vis = 0;
        if (RW(0x10) & 0x8000) {
            p = DAT_000758dc + 0x10 + DAT_0005c034;
            if (vis) FUN_0003e510(0x113, y + 2, p, 0);
            else FUN_0003e4a4(0x113, y + 2, 0, 0x23, FUN_0003f29c(p, vis));
        } else {
            if (vis) {
                r = FUN_0002f3fc(k);
                face = (signed char)RB(0x12) + (RB(0x13) * 0x17 + DAT_000758e4);
                if (RW(0x10) & 0x100) face += 0x2e;
                FUN_0003975c(0, 0x136, y + 1, DAT_000758dc + 0x24 + DAT_0005c034, 0);
                FUN_000398f0(0, 0x138, y + 4, face, 1, DAT_0005cf70 + r * 0x100);
                if (RW(0x10) < 0x4000) {
                    pct = (FUN_0001ef14(k) * 0x50 + (RS(0x1e) >> 1)) / RS(0x1e);
                    yy = y + 0x30;
                    if (pct > 0x50) FUN_00039b40(0x138, yy, 0x50, 4, 0x1b);
                    else {
                        x = 0x50 - pct + 0x138;
                        if (pct > 0x14) FUN_00039b40(x, yy, pct, 4, 0x43);
                        else FUN_00039b40(x, yy, pct, 4, 0x57);
                    }
                }
                if (RI(0x132)) FUN_0003e374(0x138, y + 4, 0x50, 0x30, 0x43);
                if (RW(0x10) & 0x1e00) FUN_0003e374(0x139, y + 5, 0x4e, 0x2e, 0x53);
                if (RI(0x1a6)) {
                    FUN_0003975c(0, 0x138, y + 4, DAT_000758dc + 0x5b, 0);
                    FUN_00040508(0x15c, y + 4, 0x30, FUN_0003e6f0(RI(0x1b2)), 0);
                }
            }
            if (DAT_0005d681[k / 2] && DAT_0005d8a8[k / 2] == k) FUN_00032f40(k, 4);
            else FUN_00032f40(k, FUN_0002f3fc(k));
            FUN_0002ea90(k, 0, -1);
            FUN_0002ea90(k, 1, -1);
        }
        if (flip) FUN_0002a8c8(DAT_0005c050, 0x113, y, 0x7d, 0x35);
    }
    if (DAT_0005d681[0] == 2) FUN_00033024(0, flip);
    if (DAT_0005d682 == 2) FUN_00033024(1, flip);
}

#undef DAT_0005d681
#undef DAT_000718e0
#undef FUN_0003f29c
#undef RW
#undef RS
#undef RI
#undef RB
/* ---- from build/var/mod/parts/p2f7b0.c */
/* FUN_0002f7b0 @ 0002f7b0: clamp the value of axis i to plus or minus its limit */
extern short DAT_0005c000[], DAT_00064570;
void FUN_0002f7b0(int i)
{
    if (DAT_0005c000[i] > (&DAT_00064570)[i]) DAT_0005c000[i] = (&DAT_00064570)[i];
    else if (DAT_0005c000[i] < -(&DAT_00064570)[i]) DAT_0005c000[i] = -(&DAT_00064570)[i];
}

/* ---- from build/var/mod/parts/p2f7f8.c */
/* FUN_0002f7f8 @ 0002f7f8: store into a short table */
extern short DAT_00064570;
void FUN_0002f7f8(int i, int v) { (&DAT_00064570)[i] = v; }

/* ---- from build/var/mod/parts/p2f80c.c */
#define DAT_0005c000 ((char *)DAT_0005c000)
/* FUN_0002f80c @ 0002f80c: clear the 12-byte block at DAT_0005c000 */
void *memset(void *, int, unsigned); 
void FUN_0002f80c(void) { memset(DAT_0005c000, 0, 0xc); }

#undef DAT_0005c000
/* ---- from build/var/mod/parts/p2f820.c */
extern void FUN_0002ea04(void); /* module prototype */
extern void FUN_0002f120(void); /* module prototype */
extern void FUN_0002f1c8(void); /* module prototype */
extern void FUN_0002f494(int flip); /* module prototype */
#define FUN_00029cc4 ((int (*)(void))FUN_00029cc4)
/* Module 0002f820..0002fb80: FUN_0002f820, FUN_0002f86c (switch; its jump table sits between the two), FUN_0002f8e0 (early return jumps to FUN_0002f86c's ret; the tail call to FUN_0002f8fc falls through), FUN_0002f8fc. The palette-colour calls of FUN_0002f8fc go through the helper macros Q1/Q2: their argument p is the stack temporary the original stores and reloads */
/* FUN_0002f8fc @ 0002f8fc: redraw the whole main screen: frame, compass, view, panels, palette and the cursor; then flip pages */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003efd0(int, int), FUN_00040040(int);
extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00039234(unsigned char *), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void), FUN_0003f868(void), FUN_00040b2c(void);
extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050, DAT_000758dc, DAT_0005c034, DAT_0005bf48, DAT_0005bf4c, DAT_0007222c, DAT_0005d8e4, DAT_0005d8e0, DAT_0005bf30, DAT_000758ec;
extern unsigned char DAT_0005cf58, DAT_0005cf5a[], DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682, DAT_0005c054[], DAT_00058602, DAT_0005d680;
extern short DAT_00058600;
extern short DAT_00064570, DAT_00064572, DAT_00064574, DAT_00064576, DAT_00064578, DAT_0006457a;
/* Q1/Q2 were static helpers that the compiler expanded in line; 10.0a emits every referenced static out of line, so they are macros */
#define Q1(a, p) FUN_0003e510((a), 0, (p) + DAT_0005c034 * 3, 0) /* STANDIN: p ahead of the product: p is evaluated first and spilled to the one stack slot, as the expanded parameter was */
#define Q2(p) FUN_0003efd0((p) + DAT_0005c034 * 3, 0) /* STANDIN: p ahead of the product (as Q1) */
void FUN_0002f820(void)
{
    DAT_00064570 = 0xa0; DAT_00064572 = 0x50; DAT_00064574 = 0xa0;
    DAT_00064576 = 0xa0; DAT_00064578 = 0x50; DAT_0006457a = 0x50;
}

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003efd0(int, int), FUN_00040040(int);
extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00039234(unsigned char *), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void), FUN_0003f868(void), FUN_00040b2c(void);
extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050, DAT_000758dc, DAT_0005c034, DAT_0005bf48, DAT_0005bf4c, DAT_0007222c, DAT_0005d8e4, DAT_0005d8e0, DAT_0005bf30, DAT_000758ec;
extern unsigned char DAT_0005cf58, DAT_0005cf5a[], DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682, DAT_0005c054[], DAT_00058602, DAT_0005d680;
extern short DAT_00058600;
extern short DAT_00064570, DAT_00064572, DAT_00064574, DAT_00064576, DAT_00064578, DAT_0006457a;

 extern void FUN_000102a8(int);
extern int DAT_0005c018, DAT_0005c01c;
void FUN_0002f8fc(void);
void FUN_0002f86c(void)
{
    if (FUN_00029cc4() > DAT_0005c01c + 0xb4) {
        switch (DAT_0005c018) {
        case 4:
            FUN_000102a8(0x2d);
            DAT_0005c018 = -1;
        case 3:
            FUN_000102a8(0x2e);
        case 2:
            FUN_000102a8(0x2f);
        case 1:
            FUN_000102a8(0x30);
        case 0:
            FUN_000102a8(0x31);
        }
        DAT_0005c018++;
        DAT_0005c01c = FUN_00029cc4();
    }
}

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003efd0(int, int), FUN_00040040(int);
extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00039234(unsigned char *), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void), FUN_0003f868(void), FUN_00040b2c(void);
extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050, DAT_000758dc, DAT_0005c034, DAT_0005bf48, DAT_0005bf4c, DAT_0007222c, DAT_0005d8e4, DAT_0005d8e0, DAT_0005bf30, DAT_000758ec;
extern unsigned char DAT_0005cf58, DAT_0005cf5a[], DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682, DAT_0005c054[], DAT_00058602, DAT_0005d680;
extern short DAT_00058600;
extern short DAT_00064570, DAT_00064572, DAT_00064574, DAT_00064576, DAT_00064578, DAT_0006457a;

void FUN_0002f8e0(int m)
{
    DAT_0005cf58 = 1;
    if (DAT_0005c034 == m) return;
    DAT_0005c034 = m;
    FUN_0002f8fc();
}

extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0003efd0(int, int), FUN_00040040(int);
extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00039234(unsigned char *), FUN_0002a5b0(int, short, unsigned char), FUN_00032d70(void), FUN_0003f868(void), FUN_00040b2c(void);
extern int FUN_00040070(int, int, int, int, int);
extern int DAT_0005c050, DAT_000758dc, DAT_0005c034, DAT_0005bf48, DAT_0005bf4c, DAT_0007222c, DAT_0005d8e4, DAT_0005d8e0, DAT_0005bf30, DAT_000758ec;
extern unsigned char DAT_0005cf58, DAT_0005cf5a[], DAT_0005cf5b, DAT_0005cf5c, DAT_0005cf5d, DAT_0005d681, DAT_0005d682, DAT_0005c054[], DAT_00058602, DAT_0005d680;
extern short DAT_00058600;
extern short DAT_00064570, DAT_00064572, DAT_00064574, DAT_00064576, DAT_00064578, DAT_0006457a;

void FUN_0002f8fc(void)
{
    FUN_000391b0(DAT_0005c050);
    Q1(0, DAT_000758dc + 1);
    Q1(0xc8, DAT_000758dc + 2);
    Q2(DAT_000758dc + 1);
    Q2(DAT_000758dc + 2);
    if (DAT_0005cf58) {
        if (DAT_0005bf48) {
            FUN_00040040(DAT_0005bf48);
            FUN_00040040(DAT_0005bf4c);
            FUN_00040040(DAT_0007222c);
        }
        DAT_0005bf48 = FUN_00040070(0, 0x20, 4, 0x100, 0xff);
        DAT_0005bf4c = FUN_00040070(0x104, 0x20, 4, 0x100, 0xff);
        DAT_0007222c = FUN_00040070(0x106, 0x20, 0xb, 0x100, 0xff);
    }
    DAT_0005cf5a[0] = 1;
    DAT_0005cf5b = 1;
    DAT_0005cf5c = 1;
    DAT_0005cf5d = 1;
    if (DAT_0005d681) DAT_0005d681 = 2;
    if (DAT_0005d682) DAT_0005d682 = 2;
    FUN_0002f494(0);
    DAT_0005d8e4 = -1;
    DAT_0005d8e0 = -1;
    FUN_0002f1c8();
    FUN_0002f120();
    if (DAT_0005cf58) {
        FUN_000425b0(DAT_0005c054, 0, DAT_0005c034, "COLORS", 0x100);
        FUN_00039234(DAT_0005c054);
    }
    if (DAT_0005bf30 == 1) {
        FUN_0003e510(4, 0x20, DAT_000758dc + 0x7b, 0);
        FUN_0002ea04();
    }
    if (DAT_0005bf30 == 2) {
        FUN_0003e510(4, 0x20, DAT_000758ec + 0x14, 9);
        FUN_0002ea04();
    }
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
    FUN_00032d70();
    DAT_0005d680 = 0;
    FUN_0003f868();
    FUN_00040b2c();
    DAT_0005cf58 = 0;
}

#undef FUN_00029cc4
#undef Q1
#undef Q2
/* ---- from build/var/mod/parts/p2fb80.c */
extern void FUN_0002c258(void); /* module prototype */
extern void FUN_0002c2cc(void); /* module prototype */
/* FUN_0002fb80 @ 0002fb80: pause the game until P is pressed again (the message pointer is read before the timer call) */
/* FUN_0002fb80 @ 0002fb80: pause the game until P is pressed again */
char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern void FUN_00029ccc(int), FUN_00040aec(void), FUN_00029cf4(void); extern int FUN_00040700(void), FUN_00040b40(void);
extern unsigned char DAT_0005bf38, DAT_0005cf59; extern int DAT_0005cf54; extern char DAT_00064580[], *PTR_s_Game_is_paused_0005bee0; extern short DAT_0006457c;
void FUN_0002fb80(void)
{
    char *s;
    DAT_0005bf38 = 0;
    FUN_00029ccc(0);
    s = PTR_s_Game_is_paused_0005bee0;
    DAT_0005cf54 = FUN_00040700() + 0x5a;
    strcpy(DAT_00064580, s);
    DAT_0005cf59 = 1;
    FUN_0002c258();
    while (FUN_00040b40() == 0x50) ;
    while (FUN_00040b40() != 0x50) ;
    FUN_00040aec();
    DAT_0005cf54 = FUN_00040700() - 1;
    FUN_0002c2cc();
    FUN_00029cf4();
    DAT_0005bf38 = 1;
    DAT_0006457c = 0;
}

/* ---- from build/var/mod/parts/p2fc14.c */
extern void FUN_0002c258(void); /* module prototype */
extern void FUN_0002c2cc(void); /* module prototype */
extern void FUN_0002ce68(void); /* module prototype */
extern void FUN_0002e4a0(void); /* module prototype */
extern void FUN_0002e534(void); /* module prototype */
extern void FUN_0002e75c(void); /* module prototype */
extern void FUN_0002f120(void); /* module prototype */
extern void FUN_0002f1c8(void); /* module prototype */
extern void FUN_0002f494(int flip); /* module prototype */
extern void FUN_0002f7b0(int i); /* module prototype */
extern void FUN_0002f86c(void); /* module prototype */
extern void FUN_0002fb80(void); /* module prototype */
#define DAT_0005759c ((char *)DAT_0005759c)
#define FUN_0003e614 ((int (*)(unsigned, int))FUN_0003e614)
int abs(int);
#pragma intrinsic(abs)
char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
void *memset(void *, int, unsigned); int sprintf(char *, const char *, ...);
extern int FUN_000408bc(int), FUN_00040b40(void), FUN_00040abc(int), FUN_00040700(void), FUN_00040ac8(void);
extern void FUN_0002ae30(void), FUN_00017874(void), FUN_000177a0(void);
extern void FUN_0003e608(void), FUN_0001893c(void), FUN_0003e120(void), FUN_00030b40(void);
extern void FUN_0002a510(int), FUN_00038168(void), FUN_000180ac(void);
extern void FUN_00032d8c(void), FUN_0002a220(void);



extern short DAT_000758fc, DAT_000758fe, DAT_00064570, DAT_00064572, DAT_00064574, DAT_00064576, DAT_00064578, DAT_0006457a, DAT_0006457c, DAT_0005a6c2;
extern short DAT_0005c000[], DAT_0005bff4[], DAT_0005c00c[];
extern int DAT_0005c6e8, DAT_0005c6ec, DAT_0005c6f0, DAT_0005cf54, DAT_0005c050, DAT_0005cf6c, DAT_0005c658; extern unsigned DAT_0005bf44;
extern unsigned DAT_0005cf4c; extern char *PTR_DAT_0005bee4; extern char DAT_00064580[];
extern unsigned char DAT_0005cf59, DAT_0005c02f, DAT_0005cf4a;
void FUN_0002fc14(void)
{
    int i;

    DAT_000758fc = -1;
    FUN_0002ae30();
    DAT_00064570 = 0xa0;
    DAT_00064572 = 0x50;
    DAT_00064574 = 0xa0;
    DAT_00064576 = 0xa0;
    DAT_00064578 = 0x50;
    DAT_0006457a = 0x50;
    DAT_0006457c = 0;
    FUN_00040700();
    for (;;) {
        DAT_0005c6e8 = 0;
        DAT_0005c6ec = 0;
        DAT_0005c6f0 = 0;
        FUN_0002ae30();
        switch ((unsigned short)FUN_00040b40()) {
        case 0x53:
            FUN_000177a0();
            break;
        case 0x149:
            if (FUN_000408bc(0x48)) { DAT_000758fc = 4; DAT_000758fe = 1; }
            else if (FUN_000408bc(0x50)) { DAT_000758fc = 5; DAT_000758fe = 1; }
            else { DAT_000758fc = 1; DAT_000758fe = 1; }
            break;
        case 0x147:
            if (FUN_000408bc(0x48)) { DAT_000758fc = 4; DAT_000758fe = -1; }
            else if (FUN_000408bc(0x50)) { DAT_000758fc = 5; DAT_000758fe = -1; }
            else { DAT_000758fc = 1; DAT_000758fe = -1; }
            break;
        case 0x148:
            if (FUN_000408bc(0x47)) { DAT_000758fc = 4; DAT_000758fe = -1; }
            else if (FUN_000408bc(0x49)) { DAT_000758fc = 4; DAT_000758fe = 1; }
            else { DAT_000758fc = 0; DAT_000758fe = -1; }
            break;
        case 0x150:
            if (FUN_000408bc(0x47)) { DAT_000758fc = 5; DAT_000758fe = -1; }
            else if (FUN_000408bc(0x49)) { DAT_000758fc = 5; DAT_000758fe = 1; }
            else { DAT_000758fc = 0; DAT_000758fe = 1; }
            break;
        case 0x14d:
        case 0x151:
            DAT_000758fc = 2; DAT_000758fe = 1;
            break;
        case 0x14b:
        case 0x14f:
            DAT_000758fc = 2; DAT_000758fe = -1;
            break;
        case 0x14c:
            memset(DAT_0005c000, 0, 12);
            DAT_000758fc = -1;
            break;
        case 0x52:
            if (FUN_00040abc(3)) FUN_00017874();
            break;
        case 0x54:
            sprintf(DAT_0005759c, PTR_DAT_0005bee4, DAT_0005cf4c >> 16, ((DAT_0005cf4c >> 16) + 1) % 24);
            DAT_0005cf54 = FUN_00040700() + 0x5a;
            strcpy(DAT_00064580, DAT_0005759c);
            DAT_0005cf59 = 1;
            FUN_0002c258();
            break;
        }
        if (DAT_0006457c) FUN_0002fb80();
        i = 0;
        if (DAT_000758fc > -1) {
            if (DAT_000758fc == 4 && DAT_0005c000[4] == 0) DAT_0005c000[4] = abs(DAT_0005c000[0]) * DAT_000758fe;
            if (DAT_000758fc == 5 && DAT_0005c000[5] == 0) DAT_0005c000[5] = abs(DAT_0005c000[5]) * DAT_000758fe;
            DAT_0005c000[DAT_000758fc] += DAT_000758fe * DAT_0005bff4[DAT_000758fc];
            FUN_0002f7b0(DAT_000758fc);
            if (DAT_000758fc == 4) {
                DAT_0005c000[0] = abs(DAT_0005c000[4]);
                DAT_0005c000[0] = -DAT_0005c000[0];
                DAT_0005c000[1] = DAT_0005c000[4];
                FUN_0002f7b0(0);
                i = 2;
                FUN_0002f7b0(1);
            }
            if (DAT_000758fc == 5) {
                DAT_0005c000[0] = abs(DAT_0005c000[5]);
                DAT_0005c000[1] = DAT_0005c000[5];
                FUN_0002f7b0(0);
                i = 2;
                FUN_0002f7b0(1);
            }
        }
        for (; i < 5; i++) {
            if (i != DAT_000758fc || DAT_000758fe * DAT_0005c000[i] < 0) {
                if (DAT_0005c000[i] > 0) {
                    DAT_0005c000[i] -= DAT_0005c00c[i];
                    if (DAT_0005c000[i] < 0) DAT_0005c000[i] = 0;
                } else if (DAT_0005c000[i] < 0) {
                    DAT_0005c000[i] += DAT_0005c00c[i];
                    if (DAT_0005c000[i] > 0) DAT_0005c000[i] = 0;
                }
            }
        }
        if (DAT_0005c6e8 || DAT_0005c6ec || DAT_0005c6f0) {
            DAT_0005c6ec = (short)((unsigned)(DAT_0005c6ec * 10) >> 3);
            DAT_0005c6e8 = (short)((unsigned)(DAT_0005c6e8 * 20) >> 3);
        } else {
            DAT_0005c6f0 = DAT_0005c000[2];
            DAT_0005c6ec = (short)((unsigned)(DAT_0005c000[1] * 20) >> 3);
            DAT_0005c6e8 = (short)((unsigned)((DAT_0005c000[3] + DAT_0005c000[0]) * 20) >> 3);
        }
        DAT_000758fc = -1;
        FUN_0003e608();
        FUN_0002e4a0();
        FUN_0001893c();
        FUN_0002e534();
        FUN_0003e120();
        FUN_00030b40();
        FUN_0002f1c8();
        FUN_0002a510(DAT_0005c050);
        DAT_0005c050 ^= 1;
        FUN_0002f494(1);
        FUN_00038168();
        FUN_0002f120();
        FUN_0003e614(2, 0);
        if (DAT_0005bf44) FUN_0002ce68();
        if (DAT_0005a6c2) FUN_000180ac();
        FUN_00032d8c();
        FUN_0002c258();
        FUN_0002c2cc();
        FUN_0002e75c();
        if (DAT_0005cf6c) {
            if (DAT_0005c02f) DAT_0005c658 = (DAT_0005c658 + 0x5a) % 360;
            else DAT_0005c658 = (DAT_0005c658 + 0xf) % 360;
        }
        FUN_0002f86c();
        if (DAT_0005cf4a || FUN_00040ac8()) {
            FUN_0002a220();
            DAT_0005cf4a = 0;
        }
    }
}

#undef DAT_0005759c
#undef FUN_0003e614
/* ---- from build/var/mod/parts/p30294.c */
/* FUN_00030294 @ 00030294 */
extern void FUN_0003e590(int); extern void FUN_000391b0(unsigned char); extern void FUN_00039b40(int, int, int, int, int); extern void FUN_0003e5d4(void);
extern short DAT_0005ef3f;
void FUN_00030294(void)
{
    FUN_0003e590(0);
    FUN_000391b0(0);
    FUN_00039b40(0, 0, DAT_0005ef3f, 0x140, 0);
    FUN_000391b0(1);
    FUN_00039b40(0, 0, DAT_0005ef3f, 0x140, 0);
    FUN_0003e5d4();
}

/* ---- from build/var/mod/parts/p302f0.c */
/* FUN_000302f0 @ 000302f0: check the free disk space at start-up and warn or exit */
struct DF { unsigned short total, avail, spc, bps; };
extern unsigned _dos_getdiskfree(unsigned, struct DF *); extern void exit(int), FUN_000411e8(char *), FUN_00040aec(void);
extern char *PTR_0005bee8, *PTR_0005beec, *PTR_0005bef0, *PTR_0005bef4, *PTR_0005bef8, *PTR_0005befc, *PTR_0005bf00, *PTR_0005bf04, *PTR_0005bf08, *PTR_0005bf0c, *PTR_0005bf10, *PTR_0005bf14, *PTR_0005bf18, *PTR_0005bf1c, *PTR_0005bf20, *PTR_0005bf24, *PTR_0005bf28;
void FUN_000302f0(void)
{
    struct DF d; unsigned free;
    if (_dos_getdiskfree(0, &d) == 0) {
        free = d.bps;
        free *= d.spc;
        free *= d.avail;
        if (free < 0x200000) {
            FUN_000411e8(PTR_0005bee8);
            FUN_000411e8(PTR_0005beec);
            FUN_000411e8(PTR_0005bef0);
            exit(1);
        }
        if (free < 0x306000) {
            FUN_000411e8(PTR_0005bef4);
            FUN_000411e8(PTR_0005bef8);
            FUN_000411e8(PTR_0005befc);
            FUN_000411e8(PTR_0005bf00);
            FUN_000411e8(PTR_0005bf04);
            FUN_000411e8(PTR_0005bf08);
            FUN_000411e8(PTR_0005bf0c);
            FUN_00040aec();
        }
    } else {
        FUN_000411e8(PTR_0005bf10);
        FUN_000411e8(PTR_0005bf14);
        FUN_000411e8(PTR_0005bf18);
        FUN_000411e8(PTR_0005bf1c);
        FUN_000411e8(PTR_0005bf20);
        FUN_000411e8(PTR_0005bf24);
        FUN_000411e8(PTR_0005bf28);
        FUN_00040aec();
    }
}

/* ---- from build/var/mod/parts/p30440.c */
extern void FUN_00030294(void); /* module prototype */
extern void FUN_000302f0(void); /* module prototype */
#define FUN_0003ecb4 ((void (*)(char *, int))FUN_0003ecb4)
/* FUN_00030440 @ 00030440: start the game: title, palette, music, load or create the party, set up the view; resume a saved game (arg) when one exists */
void *memset(void *, int, unsigned);
extern void FUN_0003f2ec(char *, int), FUN_0003f468(char *, int, char), FUN_000390f4(int), FUN_00039234(unsigned char *), FUN_00015e38(void), FUN_00038f58(int);
extern int FUN_00041218(char *, unsigned short), FUN_000412a0(char *); extern void FUN_00026d04(void), FUN_00013838(void), FUN_00029888(void), FUN_00026cd0(void), FUN_000425b0(unsigned char *, int, int, char *, int);
extern void FUN_0003f844(void), FUN_000391b0(unsigned char), FUN_000391c8(unsigned char), FUN_0003f184(char *, int), FUN_0002a0b0(void), FUN_0002a288(void), FUN_000281b4(int);
extern char *DAT_0005f050; extern int DAT_000758dc;
extern unsigned char DAT_0005c054[], DAT_00059e39; extern int DAT_0005c034, DAT_0005c050, DAT_00072224, DAT_0005a7e8; extern unsigned DAT_0005cf4c;
void FUN_00030440(int arg)
{
    int r;
    FUN_0003f2ec("RES", 0xb);
    if (!DAT_0005f050[0x72]) FUN_000302f0();
    FUN_0003f468("Ravenloft", 1, 0x3c);
    FUN_000390f4(3);
    memset(DAT_0005c054, 0, 0x300);
    FUN_00039234(DAT_0005c054);
    FUN_00030294();
    FUN_00015e38();
    FUN_00038f58(0x5a);
    r = FUN_00041218("CHARS", 0);
    DAT_00072224 = FUN_000412a0("t");
    FUN_00026d04();
    FUN_00013838();
    if (!r) FUN_00029888();
    else {
        FUN_00026cd0();
        FUN_00030294();
    }
    FUN_000425b0(DAT_0005c054, 0, DAT_0005c034, "COLORS", 0x100);
    FUN_00039234(DAT_0005c054);
    FUN_0003f844();
    FUN_000391b0(DAT_0005c050);
    FUN_000391c8(DAT_0005c050 ^ 1);
    FUN_0003ecb4((char *)DAT_000758dc + 0x2c, 0);
    FUN_0003f184((char *)DAT_000758dc + 0x2c, 0);
    DAT_0005cf4c = 0xe0000;
    if (r) {
        FUN_0002a0b0();
        DAT_00059e39 = DAT_0005c050 ^ 1;
        FUN_0002a288();
        FUN_000281b4(arg);
    }
    DAT_0005a7e8 = 1;
}

#undef FUN_0003ecb4
/* ---- from build/var/mod/parts/p305b4.c */
extern void FUN_0002fc14(void); /* module prototype */
extern void FUN_00030440(int arg); /* module prototype */
/* FUN_000305b4 @ 000305b4: shut down and exit; main @ 00030608 (round 61 blind rewrite: the party position cells are records { unsigned short f; short i; } - the two records take four zero-savings memory nodes out of the level / n / x / y tie). main ends in FUN_000305b4(-1), expanded in line, so both live in this file. */
char *getenv(const char *); int atoi(const char *); void exit(int);
extern void FUN_0002a1d0(void); extern void FUN_000410b0(void *); extern void FUN_00013810(void); extern void FUN_0003f4e0(void); extern void FUN_000390f4(int);

extern void *DAT_0005c65c, *DAT_0005c660;
extern int DAT_000755e0, DAT_000755e4, DAT_000755e8, DAT_000755ec, DAT_000755f0, DAT_000755f4, DAT_000755f8, DAT_000755fc;
extern int DAT_00075600, DAT_00075604, DAT_00075608, DAT_0007560c, DAT_00075610, DAT_000748e4, DAT_000748e8;
extern int DAT_00072200[];
#include "world.h"
struct POS { unsigned short f; short i; };
/* STANDIN: the party cells 0x755d0 / 0x755d4 read as records through the level record (DAT_00075618 - 0x48 / - 0x44): the module declares them as unsigned short scalars (FUN_0002f1c8 needs their -oa memory nodes), main needs no node for them */
#define PX (*(struct POS *)((char *)&DAT_00075618 - 0x48))
#define PY (*(struct POS *)((char *)&DAT_00075618 - 0x44))
extern int DAT_0005c658; extern unsigned DAT_0005bf44;
void FUN_000305b4(int code)
{
    FUN_0002a1d0();
    FUN_000410b0(DAT_0005c65c);
    FUN_000410b0(DAT_0005c660);
    FUN_00013810();
    FUN_0003f4e0();
    if (code != 10 && code != 12) FUN_000390f4(0xff);
    exit(code);
}

extern void FUN_0002a1d0(void); extern void FUN_000410b0(void *); extern void FUN_00013810(void); extern void FUN_0003f4e0(void); extern void FUN_000390f4(int);

extern void *DAT_0005c65c, *DAT_0005c660;
extern int DAT_000755e0, DAT_000755e4, DAT_000755e8, DAT_000755ec, DAT_000755f0, DAT_000755f4, DAT_000755f8, DAT_000755fc;
extern int DAT_00075600, DAT_00075604, DAT_00075608, DAT_0007560c, DAT_00075610, DAT_000748e4, DAT_000748e8;
extern int DAT_00072200[];
extern int DAT_0005c658; extern unsigned DAT_0005bf44;

void main(void)
{
    int level, x, y, n;
    level = 0x16;
    x = 4;
    y = 4;
    n = 0x10e;
    if (getenv("ALSIU")) {
        level = atoi(getenv("ALSIU"));
        x = atoi(getenv("KHSSDKJ"));
        y = atoi(getenv("CANLW"));
        n = atoi(getenv("SEPVON"));
    }
    DAT_000755e0 = 0;
    DAT_0007560c = 0;
    DAT_000755f8 = 0;
    DAT_000755fc = 0;
    DAT_000755f4 = 0;
    DAT_000755ec = 0;
    DAT_000755e4 = 0;
    DAT_00075600 = 0;
    DAT_00075608 = 0;
    DAT_000755e8 = 0;
    DAT_000755f0 = 0;
    DAT_00075604 = 0;
    DAT_00075610 = 0;
    DAT_000748e8 = 0;
    DAT_000748e4 = 0;
    DAT_00072200[0] = 0;
    DAT_00072200[1] = 0;
    DAT_00072200[2] = 0;
    DAT_00072200[3] = 0;
    PX.f = 0x8000;
    PY.f = 0x8000;
    PX.i = x;
    PY.i = y;
    DAT_0005c658 = n;
    FUN_00030440(level);
    DAT_0005bf44 = 0x270f;
    FUN_0002fc14();
    FUN_000305b4(-1);
}

#undef PX
#undef PY

/* ---- module data _DATA 0005bed8-0005d670 (docs/data/dataown.CODE2.csv: inferred (ref; some shared)), generated by tools/data2c.py */
char *DAT_0005bed8 = " FEELS THE EFFECT OF POISON.";
char *DAT_0005bedc = " FEELS THE EFFECT OF DISEASE.";
char *PTR_s_Game_is_paused_0005bee0 = "Game is paused...Press 'P' to continue";
char *PTR_DAT_0005bee4 = "It is currently between %d:00 and %d:00 R.S.T.";
char *PTR_0005bee8 = "\x0a\x0dRavenloft requires at LEAST 512K disk space to run properly\x0a\x0d";
char *PTR_0005beec = "and approximately another 1.5M for save games.\x0a\x0d";
char *PTR_0005bef0 = "Please make sure that you have 2M free on your hard drive.\x0a\x0d";
char *PTR_0005bef4 = "\x0a\x0dYou have between 2 and 3 Meg. on your hard drive.  Ravenloft\x0a\x0d";
char *PTR_0005bef8 = "requires approximately 2M on your hard drive to run properly\x0a\x0d";
char *PTR_0005befc = "and for a couple save games.  If you are running a hard drive\x0a\x0d";
char *PTR_0005bf00 = "compression utility, you may want to free some more space since\x0a\x0d";
char *PTR_0005bf04 = "these programs may not report the true amount of hard drive\x0a\x0d";
char *PTR_0005bf08 = "space available.\x0a\x0d\x0a\x0d";
char *PTR_0005bf0c = "Press any key to continue.";
char *PTR_0005bf10 = "\x0a\x0dRavenloft cannot get the amount of free space on your hard drive.\x0a\x0d";
char *PTR_0005bf14 = "It requires approximately 2M on your hard drive to run properly\x0a\x0d";
char *PTR_0005bf18 = "and for a couple save games.  If you are running a hard drive\x0a\x0d";
char *PTR_0005bf1c = "compression utility, you may want to free some more space since\x0a\x0d";
char *PTR_0005bf20 = "these programs may not report the true amount of hard drive\x0a\x0d";
char *PTR_0005bf24 = "space available.\x0a\x0d\x0a\x0d";
char *PTR_0005bf28 = "Press any key to continue.";
int DAT_0005bf2c = 0;
int DAT_0005bf30 = 0;
unsigned char DAT_0005bf34[4] = { 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_0005bf38 = 1;
unsigned char DAT_0005bf39[11] = { 0x3b, 0xd, 0xa, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
unsigned DAT_0005bf44 = 0;
int DAT_0005bf48 = 0;
int DAT_0005bf4c = 0;
int DAT_0005bf50 = 0;
int DAT_0005bf54 = 0;
int DAT_0005bf58 = -1;
int DAT_0005bf5c[12] = { 4, 0x3e, 0x5d, 0xb6, 0xc7, 0x100, 4, 0x37, 0x5d, 0xb5, 0xc7, 0xff };
int DAT_0005bf8c[12] = { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x100, 0x11b, 0x11d, 0x11d, 0x11e, 0x113 };
struct REPL DAT_0005bfbc[10] = {
    0x15c, 0x15d,
    0x15d, 0x15e,
    0x15e, 0x15c,
    0xaa, 0xab,
    0xab, 0xaa,
    0x11b, 0x11c,
    0x11c, 0x11d,
    0x11d, 0x11b,
    0x101, 0x102,
    0x102, 0x101
};
unsigned char DAT_0005bfe4[12] = { 0x2b, 0x2b, 0x2a, 0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x24, 0x24 };
int DAT_0005bff0 = -1;
short DAT_0005bff4[6] = { 10, 0xf, 10, 0x14, 10, 10 };
short DAT_0005c000[6] = { 0 };
short DAT_0005c00c[6] = { 0x19, 0x50, 0x14, 0x14, 0x19, 0x19 };
int DAT_0005c018 = 0;
int DAT_0005c01c = 0;
unsigned char DAT_0005c020[5] = { 0x57, 0x4f, 0x52, 0x4b };   /* only other modules name it: bytes */
unsigned char DAT_0005c025 = 9;   /* type from another module's declaration */
unsigned char DAT_0005c026 = 1;
unsigned char DAT_0005c027 = 1;
unsigned char DAT_0005c028 = 1;
unsigned char DAT_0005c029 = 1;   /* type from another module's declaration */
unsigned char DAT_0005c02a = 0x80;   /* type from another module's declaration */
unsigned char DAT_0005c02b = 1;   /* type from another module's declaration */
unsigned char DAT_0005c02c = 1;   /* type from another module's declaration */
unsigned char DAT_0005c02d = 0;   /* type from another module's declaration */
unsigned char DAT_0005c02e = 0;   /* type from another module's declaration */
unsigned char DAT_0005c02f = 0;
unsigned char DAT_0005c030[4] = { 0, 0, 0, 0x6e };   /* no name in the sources */
int DAT_0005c034 = 0;
int DAT_0005c038 = 0;   /* type from another module's declaration */
unsigned char DAT_0005c03c[4] = { 1, 0x74, 0x20, 0x70 };   /* no name in the sources */
void *DAT_0005c040 = 0;
int DAT_0005c044 = 0;
int DAT_0005c048 = 0;
int DAT_0005c04c = 0;   /* type from another module's declaration */
int DAT_0005c050 = 1;
unsigned char DAT_0005c054[769] = { 0xff };
unsigned char DAT_0005c355[771] = { 0xff };   /* only other modules name it: bytes */
int DAT_0005c658 = 0;
void *DAT_0005c65c = 0;
void *DAT_0005c660 = 0;
unsigned char DAT_0005c664[100] = {
    0, 0, 0, 0, 0, 1, 3, 7, 0xf, 0xf, 0xf, 0xf, 0xf, 2, 6, 0xe,
    0xe, 0xe, 0xe, 0xe, 0xe, 4, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 8, 8, 8,
    8, 8, 8, 8, 8, 0, 0, 0, 0, 1, 3, 7, 0xf, 0, 0, 0,
    1, 3, 7, 0xf, 0xf, 0, 0, 1, 3, 7, 0xf, 0xf, 0xf, 0, 1, 3,
    7, 0xf, 0xf, 0xf, 0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0,
    0, 0, 1, 3
};   /* only other modules name it: bytes */
unsigned DAT_0005c6c8 = 0xffffffff;
int DAT_0005c6cc = 0;   /* type from another module's declaration */
int DAT_0005c6d0 = 0;   /* type from another module's declaration */
int DAT_0005c6d4 = 0;   /* type from another module's declaration */
int DAT_0005c6d8 = 0;   /* type from another module's declaration */
int DAT_0005c6dc = 0;   /* type from another module's declaration */
int DAT_0005c6e0 = 0;   /* type from another module's declaration */
int DAT_0005c6e4 = 0;   /* type from another module's declaration */
int DAT_0005c6e8 = 0;
int DAT_0005c6ec = 0;
int DAT_0005c6f0 = 0;
unsigned char DAT_0005c6f4[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
int DAT_0005c730 = 0;   /* type from another module's declaration */
int DAT_0005c734 = 0;   /* type from another module's declaration */
int DAT_0005c738 = 0;   /* type from another module's declaration */
unsigned char DAT_0005c73c[1024] = { 0 };   /* only other modules name it: bytes */
unsigned char *DAT_0005cb3c[128] = { 0 };
unsigned char *DAT_0005cd3c[130] = { 0 };
unsigned char DAT_0005cf44[4] = { 0 };   /* only other modules name it: bytes */
short DAT_0005cf48 = 1;   /* type from another module's declaration */
unsigned char DAT_0005cf4a = 0;
unsigned char DAT_0005cf4b[1] = { 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned DAT_0005cf4c = 0;
unsigned char DAT_0005cf50 = 0;   /* type from another module's declaration */
unsigned char DAT_0005cf51[3] = { 0, 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005cf54 = -1;
unsigned char DAT_0005cf58 = 1;
unsigned char DAT_0005cf59 = 0;
unsigned char DAT_0005cf5a[1] = { 0 };
unsigned char DAT_0005cf5b = 0;
unsigned char DAT_0005cf5c = 0;
unsigned char DAT_0005cf5d = 0;
unsigned char DAT_0005cf5e[2] = { 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005cf60[2] = { 0x88000, 0x80100 };
unsigned char DAT_0005cf68 = 0;
unsigned char DAT_0005cf69[3] = { 0, 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005cf6c = 0;
unsigned char DAT_0005cf70[768] = {
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x1c, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x31, 0x31, 0x31, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    0xd2, 0xd4, 0xd5, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 0x48, 0x48, 0x48, 0x48, 0x48, 0x49, 0x49, 0x49,
    0x49, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
    0x60, 0x60, 0x60, 0x60, 0x60, 0x61, 0x61, 0x61, 0x61, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x78, 0x78, 0x78, 0x78, 0x78, 0x79, 0x79, 0x79,
    0x79, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x91, 0x91, 0x91, 0x91, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
    0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa8, 0xa8, 0xa8, 0xa8, 0xa8, 0xa9, 0xa9, 0xa9,
    0xa9, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xe2, 0xe2, 0xe2, 0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
    0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
    0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 0xb,
    0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x1c, 0x1c, 0x1d, 0x1d,
    0x1e, 0x1e, 0x1f, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
    0x30, 0x30, 0x31, 0x31, 0x32, 0x32, 0x33, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
    0xbc, 0xbd, 0xd9, 0xda, 0xdb, 0xdd, 0xde, 0xdf, 0x48, 0x48, 0x49, 0x49, 0x4a, 0x4a, 0x4b, 0x4b,
    0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b,
    0x60, 0x60, 0x61, 0x61, 0x62, 0x62, 0x63, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
    0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x78, 0x78, 0x79, 0x79, 0x7a, 0x7a, 0x7b, 0x7b,
    0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b,
    0x90, 0x90, 0x91, 0x91, 0x92, 0x92, 0x93, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b,
    0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa3, 0xa8, 0xa8, 0xa9, 0xa9, 0xaa, 0xaa, 0xab, 0xab,
    0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb,
    0xbc, 0xbd, 0xbe, 0xc3, 0xc3, 0xc4, 0xc4, 0xc5, 0xc5, 0xc6, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb,
    0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb,
    0xdc, 0xdd, 0xe2, 0xe2, 0xe3, 0xe3, 0xe4, 0xe4, 0xe5, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
    0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
unsigned char DAT_0005d270[256] = {
    0, 0x92, 0x92, 0x92, 0x93, 0x93, 0x93, 0x95, 0x95, 0x97, 0x98, 0x99, 0x99, 0x9a, 0x9b, 0x9c,
    0x9d, 0x9e, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa4, 0xa5, 0xa6, 0x92, 0x92, 0x92, 0x93,
    0x95, 0x95, 0x97, 0x97, 0x98, 0x99, 0x99, 0x9a, 0x9b, 0x9c, 0x9e, 0x9f, 0xa1, 0xa3, 0xa4, 0xa5,
    0x92, 0x92, 0x92, 0x93, 0x95, 0x95, 0x96, 0x97, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e,
    0x9f, 0x9f, 0xa1, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0x92, 0x92, 0x92, 0x93, 0x94, 0x94, 0x95, 0x96,
    0x96, 0x97, 0x98, 0x98, 0x99, 0x99, 0x9a, 0x9b, 0x9b, 0x9c, 0x9d, 0x9e, 0xa0, 0xa1, 0xa3, 0xa4,
    0x92, 0x92, 0x92, 0x93, 0x95, 0x96, 0x97, 0x97, 0x98, 0x98, 0x99, 0x99, 0x9a, 0x9a, 0x9b, 0x9c,
    0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa3, 0xa4, 0xa4, 0x92, 0x92, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
    0x97, 0x98, 0x99, 0x99, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0xa1, 0xa4, 0xa5,
    0x92, 0x92, 0x93, 0x94, 0x96, 0x97, 0x97, 0x98, 0x99, 0x99, 0x99, 0x99, 0x9a, 0x9b, 0x9b, 0x9c,
    0x9e, 0x9e, 0xa0, 0xa1, 0xa2, 0xa4, 0xa4, 0xa5, 0x92, 0x92, 0x92, 0x93, 0x94, 0x96, 0x97, 0x97,
    0x96, 0x97, 0x97, 0x97, 0x98, 0x99, 0x99, 0x9a, 0x9b, 0x9c, 0x9e, 0x9e, 0x9f, 0xa0, 0xa2, 0xa3,
    0xa4, 0xa4, 0xa6, 0x92, 0x92, 0x92, 0x92, 0x94, 0x94, 0x95, 0x96, 0x97, 0x97, 0x98, 0x98, 0x99,
    0x99, 0x9a, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa2, 0xa3, 0xa4, 0xa4,
    0xa5, 0xa6, 0x92, 0x92, 0x92, 0x94, 0x96, 0x97, 0x97, 0x98, 0x99, 0x99, 0x9a, 0x9a, 0x9b, 0x9c,
    0x9e, 0x9f, 0xa0, 0xa2, 0xa3, 0xa4, 0x96, 0x97, 0x97, 0x98, 0x98, 0x99, 0x99, 0x99, 0x99, 0xa6
};   /* only other modules name it: bytes */
unsigned char DAT_0005d370[256] = {
    0, 2, 2, 2, 3, 3, 3, 6, 6, 8, 9, 10, 0xb, 0xc, 0xd, 0xe,
    0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 2, 2, 2, 3,
    6, 6, 8, 8, 9, 10, 0xb, 0xc, 0xd, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x19,
    2, 2, 2, 3, 6, 6, 7, 8, 8, 9, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10,
    0x12, 0x12, 0x14, 0x14, 0x15, 0x16, 0x18, 0x19, 2, 2, 2, 3, 5, 5, 6, 7,
    7, 8, 9, 9, 10, 0xb, 0xc, 0xd, 0xd, 0xe, 0xf, 0x11, 0x13, 0x14, 0x16, 0x18,
    2, 2, 2, 3, 6, 7, 8, 8, 9, 9, 10, 0xb, 0xc, 0xc, 0xd, 0xe,
    0xf, 0x11, 0x12, 0x13, 0x14, 0x16, 0x17, 0x18, 2, 2, 2, 3, 5, 6, 7, 8,
    8, 9, 10, 0xb, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x10, 0x11, 0x12, 0x14, 0x17, 0x19,
    2, 2, 3, 5, 7, 8, 8, 9, 10, 10, 0xb, 0xb, 0xc, 0xd, 0xd, 0xe,
    0x10, 0x11, 0x13, 0x14, 0x15, 0x17, 0x18, 0x19, 2, 2, 2, 3, 5, 7, 8, 8,
    7, 8, 8, 8, 9, 10, 0xb, 0xc, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13, 0x15, 0x16,
    0x17, 0x18, 0x1a, 2, 2, 2, 2, 5, 5, 6, 7, 8, 8, 9, 9, 10,
    0xb, 0xc, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1a, 2, 2, 2, 5, 7, 8, 8, 9, 10, 10, 0xc, 0xc, 0xd, 0xe,
    0x10, 0x12, 0x13, 0x15, 0x16, 0x18, 7, 8, 8, 9, 9, 10, 0xb, 0xb, 0xb, 0x1a
};   /* only other modules name it: bytes */
unsigned char DAT_0005d470[512] = {
    0x60, 0x60, 0x61, 0x62, 0x62, 0x63, 0x63, 0x65, 0x66, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6b, 0x6c,
    0x6d, 0x6e, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x74, 0x75, 0x76, 0x60, 0x60, 0x62, 0x63,
    0x64, 0x65, 0x65, 0x66, 0x67, 0x68, 0x69, 0x69, 0x6b, 0x6c, 0x6e, 0x6f, 0x71, 0x72, 0x74, 0x75,
    0x60, 0x61, 0x63, 0x63, 0x63, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d,
    0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x60, 0x60, 0x62, 0x62, 0x62, 0x63, 0x63, 0x63,
    0x63, 0x64, 0x65, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6a, 0x6b, 0x6c, 0x6d, 0x6f, 0x71, 0x72, 0x74,
    0x60, 0x60, 0x62, 0x63, 0x63, 0x63, 0x65, 0x66, 0x66, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6a, 0x6b,
    0x6c, 0x6e, 0x6f, 0x70, 0x72, 0x73, 0x73, 0x74, 0x60, 0x61, 0x62, 0x63, 0x63, 0x65, 0x65, 0x65,
    0x67, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6a, 0x6b, 0x6c, 0x6d, 0x6d, 0x6e, 0x6f, 0x71, 0x73, 0x75,
    0x60, 0x61, 0x63, 0x64, 0x66, 0x67, 0x67, 0x68, 0x68, 0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6b, 0x6c,
    0x6d, 0x6e, 0x6f, 0x71, 0x72, 0x73, 0x74, 0x75, 0x60, 0x60, 0x61, 0x62, 0x63, 0x63, 0x63, 0x65,
    0x63, 0x64, 0x65, 0x65, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6c, 0x6c, 0x6e, 0x6e, 0x70, 0x71, 0x72,
    0x73, 0x74, 0x75, 0x60, 0x62, 0x63, 0x63, 0x63, 0x63, 0x64, 0x65, 0x65, 0x66, 0x67, 0x68, 0x69,
    0x69, 0x69, 0x6a, 0x6b, 0x6c, 0x6c, 0x6d, 0x6e, 0x6f, 0x6f, 0x71, 0x71, 0x72, 0x73, 0x74, 0x74,
    0x75, 0x76, 0x60, 0x61, 0x63, 0x63, 0x63, 0x65, 0x66, 0x67, 0x67, 0x68, 0x69, 0x69, 0x6a, 0x6c,
    0x6d, 0x6e, 0x6f, 0x72, 0x73, 0x74, 0x71, 0x73, 0x74, 0x74, 0x65, 0x67, 0x69, 0x6a, 0x69, 0x72,
    0x78, 0x78, 0x78, 0x78, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x80, 0x81, 0x82, 0x83, 0x84,
    0x84, 0x86, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8c, 0x8d, 0x8d, 0x78, 0x78, 0x78, 0x78,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x7a, 0x7d, 0x7f, 0x80, 0x81, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8d,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7b, 0x7d, 0x7e, 0x7f,
    0x81, 0x82, 0x84, 0x86, 0x87, 0x89, 0x8b, 0x8c, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7a, 0x7b, 0x7d, 0x80, 0x83, 0x86, 0x87, 0x8a,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7a, 0x7b, 0x7c, 0x7d,
    0x80, 0x81, 0x84, 0x86, 0x86, 0x88, 0x8a, 0x8b, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78,
    0x78, 0x7a, 0x7c, 0x7d, 0x7f, 0x7f, 0x80, 0x80, 0x81, 0x82, 0x83, 0x83, 0x84, 0x87, 0x89, 0x8c,
    0x78, 0x78, 0x78, 0x78, 0x7a, 0x7b, 0x7c, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x80, 0x81, 0x82, 0x82,
    0x84, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8c, 0x8c, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78,
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7b, 0x7b, 0x7d, 0x80, 0x81, 0x81, 0x83, 0x85, 0x86, 0x88,
    0x89, 0x8b, 0x8c, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7b, 0x7b,
    0x7b, 0x7e, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x83, 0x83, 0x84, 0x86, 0x86, 0x87, 0x89, 0x8a, 0x8c,
    0x8c, 0x8d, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7b, 0x7b, 0x7c, 0x80,
    0x81, 0x83, 0x86, 0x86, 0x89, 0x8a, 0x80, 0x84, 0x89, 0x8b, 0x78, 0x78, 0x7a, 0x7b, 0x80, 0x8a
};   /* only other modules name it: bytes */
/* ---- end of module data _DATA */
