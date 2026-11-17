/* Module 0x26810 (FUN_00026810 .. FUN_00026d04), module-context file, -3s -ox -oe -oa -ot -w0, functions in address order
   (round 71 lane BT; FUN_00026934 after FUN_000268c8).
   FUN_00026d04 matches with STANDIN copy chains at reads 0 (2 temps) and 13 (2 temps; round 76, with the file-name strings as literals: before, with the strings extern, 5 and 15). They leave no code; they move the
   instruction ids and the instruction-chunk reuse that decide where BlkTooBig cuts the long block of inlined FUN_00026a58
   calls for the scheduler. The cut also depends on never-written ins->id fields of recycled chunks (ALLOCATOR.md, stale
   instruction id), whose values differ between DOSBox-X (the build route) and the Unicorn emulator for this file: this form
   matches under DOSBox (tools/match.py); the emulated 10.0a (tools/realcc.py) reports FUN_00026d04 DIFF. */
/* FUN_00026810 @ 00026810: load NPCS.DAT */
extern int FUN_000412a0(const char *); extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int); extern void *FUN_0004104c(int);
 extern int DAT_000758f4; extern void *DAT_00072230;
void FUN_00026810(void)
{
    int h = FUN_000412a0("NPCS.DAT");
    FUN_000412ec(&DAT_000758f4, 4, h);
    if (DAT_000758f4) {
        DAT_00072230 = FUN_0004104c(DAT_000758f4 * 0x45);
        FUN_000412ec(DAT_00072230, DAT_000758f4 * 0x45, h);
        FUN_000412dc(h);
    }
}

/* FUN_0002686c, FUN_00026934: load a counted table of 7-byte records */
#include "world.h"
extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int);
extern int DAT_000758e0, DAT_000758f0; extern void *DAT_00072234;
void FUN_0002686c(int fd)
{
    FUN_000412ec(&DAT_000758e0, 2, fd);
    if (DAT_000758e0) {
        DAT_000755dc = FUN_0004104c(DAT_000758e0 * 7);
        FUN_000412ec(DAT_000755dc, DAT_000758e0 * 7, fd);
    }
}

/* FUN_000268c8 @ 000268c8: load OBJECTS.DAT (monster table, 0x41-byte records) */
#include "world.h"
extern int FUN_000412a0(char *); extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int); extern void FUN_000412dc(int);
 extern int DAT_000758e8;
void FUN_000268c8(void)
{
    int h = FUN_000412a0("OBJECTS.DAT");
    FUN_000412ec(&DAT_000758e8, 4, h);
    if (DAT_000758e8) {
        DAT_000755d8 = (struct IT *)FUN_0004104c(DAT_000758e8 * 0x41);
        FUN_000412ec(DAT_000755d8, DAT_000758e8 * 0x41, h);
        FUN_000412dc(h);
    }
}

void FUN_00026934(int fd)
{
    FUN_000412ec(&DAT_000758f0, 2, fd);
    if (DAT_000758f0) {
        DAT_00072234 = FUN_0004104c(DAT_000758f0 * 7);
        FUN_000412ec(DAT_00072234, DAT_000758f0 * 7, fd);
    }
}

/* FUN_00026990 @ 00026990: load the counted list of 8-byte record tables */
extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int);
extern unsigned short DAT_0007b750[]; extern void **DAT_0007b764;
void FUN_00026990(int h)
{
    short n; int k, cnt;
    FUN_000412ec(&n, 2, h);
    if (n) {
        DAT_0007b764 = FUN_0004104c(n * 4);
        for (k = 0; k < n; k++) {
            DAT_0007b750[k] = 0;
            cnt = 0;
            FUN_000412ec(&DAT_0007b750[k], 2, h);
            FUN_000412ec(&cnt, 2, h);
            DAT_0007b764[k] = FUN_0004104c(cnt * 8);
            FUN_000412ec(DAT_0007b764[k], cnt * 8, h);
        }
    }
}

/* FUN_00026a58 @ 00026a58: read the 16-bit entry k of the open table file f */
extern void FUN_0004131c(int, int, int);
int FUN_00026a58(int k, int f)
{
    int r;
    FUN_0004131c(k * 2, 0, f);
    FUN_000412ec(&f, 2, f);
    r = f;
    return r;
}

/* FUN_00026a88: matched 2026-11-10 (the two nibbles are cleared by two statements, not one chained assignment: with the chain the loaded slot was allocated before the table index) */
#include "chars.h"
struct NB { unsigned char lo : 4, hi : 4; };

extern signed char DAT_0005817c[][4]; extern unsigned char DAT_0007194a;
void FUN_00026a88(int i)
{
    int r, j;
    for (r = 0; r < 5; r++)
        for (j = 0; j < 4; j++)
            if (DAT_0005817c[r][j] != -1) { ((struct NB *)&DAT_0007194a)[i * 0x248 + r * 10 + DAT_0005817c[r][j]].lo = 0; ((struct NB *)&DAT_0007194a)[i * 0x248 + r * 10 + DAT_0005817c[r][j]].hi = 0; }
}

/* FUN_00026adc @ 00026adc: initialise a new party: members 2 and 3 absent, clear the tables, give each present member class equipment and spells */
void *memset(void *, int, unsigned);
extern int FUN_0001dbd4(int); extern void FUN_00013ea4(int, int), FUN_00026a88(int), FUN_00013de4(int, int);
extern char DAT_000719eb[], DAT_00071b28[], DAT_00071c33[], DAT_00071d70[]; extern unsigned short DAT_000718f0, DAT_00071b38, DAT_00071d80, DAT_00071fc8;
#define DAT_000718e0 ((char *)&DAT_000718e0)
#define C8(k, o) (*(signed char *)(DAT_000718e0 + (k) * 0x248 + (o)))
#define CB(k, o) (*(unsigned char *)(DAT_000718e0 + (k) * 0x248 + (o)))
#define CS(k, o) (*(short *)(DAT_000718e0 + (k) * 0x248 + (o)))
#define CI(k, o) (*(int *)(DAT_000718e0 + (k) * 0x248 + (o)))
void FUN_00026adc(void)
{
    int k;
    DAT_000718f0 = 0;
    DAT_00071b38 = 0;
    DAT_00071d80 = 0x8000;
    DAT_00071fc8 = 0x8000;
    memset(DAT_000719eb, 0, DAT_00071b28 - DAT_000719eb);
    memset(DAT_00071c33, 0, DAT_00071d70 - DAT_00071c33);
    for (k = 0; k < 4; k++) {
        memset(DAT_000718e0 + k * 0x248 + 0x6a, 0xff, 0x50);
        memset(DAT_000718e0 + k * 0x248 + 0xba, 0xff, 0x50);
        CI(k, 0x113) = 0;
        CI(k, 0x117) = 0;
        CI(k, 0x19e) = 0;
        CI(k, 0x1a2) = 0;
        CI(k, 0x1a6) = 0;
        CI(k, 0x12b) = 0;
        if (*(unsigned short *)(DAT_000718e0 + k * 0x248 + 0x10) & 0x8000) continue;
        CB(k, 0x1b) = 10;
        CB(k, 0x10a) = FUN_0001dbd4(k);
        CB(k, 0x131) = 0;
        if (C8(k, 0x15) == 1) {
            CB(k, 0x131) |= 4;
            FUN_00013ea4(k, CS(k, 0x20));
        }
        if (C8(k, 0x15) == 4 || C8(k, 0x16) == 4 || C8(k, 0x17) == 4) {
            CS(k, 0x40) = 0xa6;
            CB(k, 0x131) |= 2;
            FUN_00026a88(k);
        }
        if (C8(k, 0x15) == 3) {
            CB(k, 0x131) |= 1;
            FUN_00013de4(k, CS(k, 0x20));
        }
        if (C8(k, 0x16) == 3) {
            CB(k, 0x131) |= 1;
            FUN_00013de4(k, CS(k, 0x22));
        }
        if (C8(k, 0x17) == 3) {
            CB(k, 0x131) |= 1;
            FUN_00013de4(k, CS(k, 0x24));
        }
    }
}

/* FUN_00026cd0 @ 00026cd0 */
extern int FUN_000412a0(const char *); extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int); extern void FUN_00026adc(void);

void FUN_00026cd0(void)
{
    int h = FUN_000412a0("CHARS");
    FUN_000412ec(DAT_000718e0, 0x920, h);
    FUN_000412dc(h);
    FUN_00026adc();
}


extern int FUN_000412a0(const char *); extern void FUN_000412dc(int);
extern void FUN_00026810(void), FUN_000268c8(void), FUN_0002686c(int), FUN_00026934(int), FUN_00026990(int);
extern void FUN_000380dc(int), FUN_000388e4(int), FUN_000388f0(int);
extern int DAT_000758dc, DAT_000758d8, DAT_000758e4, DAT_000758f8, DAT_000758d0, DAT_000758c0, DAT_000758bc;
extern int DAT_000758d4, DAT_000758c8, DAT_000758ec, DAT_000758cc, DAT_00075614;
extern short DAT_00077100[], DAT_00057fcc;

void FUN_00026d04(void)
{
    int f, m;
    FUN_00026810();
    FUN_000268c8();
    f = FUN_000412a0("INIT");
    { /* STANDIN: copy chain (2 block-local temps, propagated away; they advance the instruction-id counter that places the BlkTooBig block cuts) */
        int t0 = FUN_00026a58(0, f); /* STANDIN */
        int t1 = t0; /* STANDIN */
        DAT_000758dc = t1; /* STANDIN */
    }
    DAT_000758d8 = FUN_00026a58(1, f);
    DAT_000758e4 = FUN_00026a58(2, f);
    DAT_00077100[0] = FUN_00026a58(3, f);
    DAT_00077100[1] = FUN_00026a58(4, f);
    DAT_00077100[2] = FUN_00026a58(5, f);
    DAT_00077100[3] = FUN_00026a58(6, f);
    DAT_000758f8 = FUN_00026a58(7, f);
    m = FUN_00026a58(8, f);
    DAT_000758d0 = FUN_00026a58(9, f);
    DAT_000758c0 = FUN_00026a58(10, f);
    DAT_000758bc = FUN_00026a58(11, f);
    DAT_000758d4 = FUN_00026a58(12, f);
    { /* STANDIN: copy chain (2 block-local temps, propagated away; they advance the instruction-id counter that places the BlkTooBig block cuts) */
        int t0 = FUN_00026a58(13, f); /* STANDIN */
        int t1 = t0; /* STANDIN */
        DAT_000758c8 = t1; /* STANDIN */
    }
    DAT_000758ec = FUN_00026a58(14, f);
    DAT_000758cc = FUN_00026a58(15, f);
    DAT_00075614 = FUN_00026a58(16, f);
    DAT_00057fcc = FUN_00026a58(17, f);
    FUN_0002686c(f);
    FUN_00026934(f);
    FUN_00026990(f);
    FUN_000412dc(f);
    FUN_000380dc(6);
    FUN_000388e4(5);
    FUN_000388f0(m);
}

/* ---- module data _DATA 0005817c-00058190 (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
signed char DAT_0005817c[5][4] = { 0, 5, 6, 4, 0, 1, 2, -1, 2, 7, 4, -1, 0, 3, -1, -1, 1, -1, -1, -1 };
/* ---- end of module data _DATA */
