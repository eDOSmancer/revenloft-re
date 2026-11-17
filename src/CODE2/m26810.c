/* Module 0x26810 (FUN_00026810 .. FUN_00026d04), module-context file, -3s -ox -oe -oa -ot -w0, functions in address order
   (round 71 lane BT; FUN_00026934 after FUN_000268c8).
   FUN_00026d04 matches with STANDIN copy chains at reads 0 (2 temps) and 13 (2 temps; round 76, with the file-name strings as literals: before, with the strings extern, 5 and 15). They leave no code; they move the
   instruction ids and the instruction-chunk reuse that decide where BlkTooBig cuts the long block of inlined FUN_00026a58
   calls for the scheduler. The cut also depends on never-written ins->id fields of recycled chunks (ALLOCATOR.md, stale
   instruction id), whose values differ between DOSBox-X (the build route) and the Unicorn emulator for this file: this form
   matches under DOSBox (tools/match.py); the emulated 10.0a (tools/realcc.py) reports FUN_00026d04 DIFF. */
/* FUN_00026810 @ 00026810: load NPCS.DAT */
extern int FUN_000412a0(const char *); extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int); extern void *FUN_0004104c(int);
 extern int B000758f4_hG; extern void *B00072230_c4;
void FUN_00026810(void)
{
    int h = FUN_000412a0("NPCS.DAT");
    FUN_000412ec(&B000758f4_hG, 4, h);
    if (B000758f4_hG) {
        B00072230_c4 = FUN_0004104c(B000758f4_hG * 0x45);
        FUN_000412ec(B00072230_c4, B000758f4_hG * 0x45, h);
        FUN_000412dc(h);
    }
}

/* FUN_0002686c, FUN_00026934: load a counted table of 7-byte records */
#include "world.h"
extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int);
extern int B000758e0_iK, B000758f0_hK; extern void *B00072234_hx;
void FUN_0002686c(int fd)
{
    FUN_000412ec(&B000758e0_iK, 2, fd);
    if (B000758e0_iK) {
        B000755dc_aX = FUN_0004104c(B000758e0_iK * 7);
        FUN_000412ec(B000755dc_aX, B000758e0_iK * 7, fd);
    }
}

/* FUN_000268c8 @ 000268c8: load OBJECTS.DAT (monster table, 0x41-byte records) */
#include "world.h"
extern int FUN_000412a0(char *); extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int); extern void FUN_000412dc(int);
 extern int B000758e8_jC;
void FUN_000268c8(void)
{
    int h = FUN_000412a0("OBJECTS.DAT");
    FUN_000412ec(&B000758e8_jC, 4, h);
    if (B000758e8_jC) {
        B000755d8_aw = (struct IT *)FUN_0004104c(B000758e8_jC * 0x41);
        FUN_000412ec(B000755d8_aw, B000758e8_jC * 0x41, h);
        FUN_000412dc(h);
    }
}

void FUN_00026934(int fd)
{
    FUN_000412ec(&B000758f0_hK, 2, fd);
    if (B000758f0_hK) {
        B00072234_hx = FUN_0004104c(B000758f0_hK * 7);
        FUN_000412ec(B00072234_hx, B000758f0_hK * 7, fd);
    }
}

/* FUN_00026990 @ 00026990: load the counted list of 8-byte record tables */
extern int FUN_000412ec(void *, unsigned, int); extern void *FUN_0004104c(int);
extern unsigned short B0007b750_el[]; extern void **B0007b764_fp;
void FUN_00026990(int h)
{
    short n; int k, cnt;
    FUN_000412ec(&n, 2, h);
    if (n) {
        B0007b764_fp = FUN_0004104c(n * 4);
        for (k = 0; k < n; k++) {
            B0007b750_el[k] = 0;
            cnt = 0;
            FUN_000412ec(&B0007b750_el[k], 2, h);
            FUN_000412ec(&cnt, 2, h);
            B0007b764_fp[k] = FUN_0004104c(cnt * 8);
            FUN_000412ec(B0007b764_fp[k], cnt * 8, h);
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

extern signed char DAT_0005817c[][4]; extern unsigned char B0007194a_al;
void FUN_00026a88(int i)
{
    int r, j;
    for (r = 0; r < 5; r++)
        for (j = 0; j < 4; j++)
            if (DAT_0005817c[r][j] != -1) { ((struct NB *)&B0007194a_al)[i * 0x248 + r * 10 + DAT_0005817c[r][j]].lo = 0; ((struct NB *)&B0007194a_al)[i * 0x248 + r * 10 + DAT_0005817c[r][j]].hi = 0; }
}

/* FUN_00026adc @ 00026adc: initialise a new party: members 2 and 3 absent, clear the tables, give each present member class equipment and spells */
void *memset(void *, int, unsigned);
extern int FUN_0001dbd4(int); extern void FUN_00013ea4(int, int), FUN_00026a88(int), FUN_00013de4(int, int);
extern char B000719eb_cp[], B00071b28_gs[], B00071c33_jl[], B00071d70_aF[]; extern unsigned short B000718f0_hO, B00071b38_c0, B00071d80_d5, B00071fc8_l9;
#define B000718e0_iO ((char *)&B000718e0_iO)
#define C8(k, o) (*(signed char *)(B000718e0_iO + (k) * 0x248 + (o)))
#define CB(k, o) (*(unsigned char *)(B000718e0_iO + (k) * 0x248 + (o)))
#define CS(k, o) (*(short *)(B000718e0_iO + (k) * 0x248 + (o)))
#define CI(k, o) (*(int *)(B000718e0_iO + (k) * 0x248 + (o)))
void FUN_00026adc(void)
{
    int k;
    B000718f0_hO = 0;
    B00071b38_c0 = 0;
    B00071d80_d5 = 0x8000;
    B00071fc8_l9 = 0x8000;
    memset(B000719eb_cp, 0, B00071b28_gs - B000719eb_cp);
    memset(B00071c33_jl, 0, B00071d70_aF - B00071c33_jl);
    for (k = 0; k < 4; k++) {
        memset(B000718e0_iO + k * 0x248 + 0x6a, 0xff, 0x50);
        memset(B000718e0_iO + k * 0x248 + 0xba, 0xff, 0x50);
        CI(k, 0x113) = 0;
        CI(k, 0x117) = 0;
        CI(k, 0x19e) = 0;
        CI(k, 0x1a2) = 0;
        CI(k, 0x1a6) = 0;
        CI(k, 0x12b) = 0;
        if (*(unsigned short *)(B000718e0_iO + k * 0x248 + 0x10) & 0x8000) continue;
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
    FUN_000412ec(B000718e0_iO, 0x920, h);
    FUN_000412dc(h);
    FUN_00026adc();
}


extern int FUN_000412a0(const char *); extern void FUN_000412dc(int);
extern void FUN_00026810(void), FUN_000268c8(void), FUN_0002686c(int), FUN_00026934(int), FUN_00026990(int);
extern void FUN_000380dc(int), FUN_000388e4(int), FUN_000388f0(int);
extern int B000758dc_cl, B000758d8_j3, B000758e4_h7, B000758f8_h3, B000758d0_jK, B000758c0_kK, B000758bc_al;
extern int B000758d4_jG, B000758c8_as, B000758ec_bl, B000758cc_fL, B00075614_lm;
extern short B00077100_ds[], DAT_00057fcc;

void FUN_00026d04(void)
{
    int f, m;
    FUN_00026810();
    FUN_000268c8();
    f = FUN_000412a0("INIT");
    { /* STANDIN: copy chain (2 block-local temps, propagated away; they advance the instruction-id counter that places the BlkTooBig block cuts) */
        int t0 = FUN_00026a58(0, f); /* STANDIN */
        int t1 = t0; /* STANDIN */
        B000758dc_cl = t1; /* STANDIN */
    }
    B000758d8_j3 = FUN_00026a58(1, f);
    B000758e4_h7 = FUN_00026a58(2, f);
    B00077100_ds[0] = FUN_00026a58(3, f);
    B00077100_ds[1] = FUN_00026a58(4, f);
    B00077100_ds[2] = FUN_00026a58(5, f);
    B00077100_ds[3] = FUN_00026a58(6, f);
    B000758f8_h3 = FUN_00026a58(7, f);
    m = FUN_00026a58(8, f);
    B000758d0_jK = FUN_00026a58(9, f);
    B000758c0_kK = FUN_00026a58(10, f);
    B000758bc_al = FUN_00026a58(11, f);
    B000758d4_jG = FUN_00026a58(12, f);
    { /* STANDIN: copy chain (2 block-local temps, propagated away; they advance the instruction-id counter that places the BlkTooBig block cuts) */
        int t0 = FUN_00026a58(13, f); /* STANDIN */
        int t1 = t0; /* STANDIN */
        B000758c8_as = t1; /* STANDIN */
    }
    B000758ec_bl = FUN_00026a58(14, f);
    B000758cc_fL = FUN_00026a58(15, f);
    B00075614_lm = FUN_00026a58(16, f);
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
