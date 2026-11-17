typedef void (__far *PARA_BSS)(); /* STANDIN: the _BSS of this object file is paragraph-aligned in the original (unnamed bytes ahead of it up to the 16-byte boundary); a typedef of a far pointer type raises the alignment, as a far pointer or double variable of any function would (docs/BSS.md) */
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
void *B00062bb0_hD[17];
/* BSS end */
/* Module: FUN_0001ea90, FUN_0001eabc, FUN_0001ead8, FUN_0001eb3c, FUN_0001ec1c */
/* ---- from build/var/mod/parts/p1ea90.c */
/* FUN_0001ea90 @ 0001ea90 */
extern void *FUN_0004104c(int); void *memset(void *, int, unsigned);
extern void *B00062bb0_hD[17];
void FUN_0001ea90(void)
{
    int i;
    for (i = 0; i < 17; i++) {
        B00062bb0_hD[i] = FUN_0004104c(0x50);
        memset(B00062bb0_hD[i], 0, 0x50);
    }
}

/* ---- from build/var/mod/parts/p1eabc.c */
/* FUN_0001eabc @ 0001eabc: free the 17 buffers */
extern void FUN_000410b0(void *); extern void *B00062bb0_hD[17];
void FUN_0001eabc(void) { int k; for (k = 0; k < 17; k++) FUN_000410b0(B00062bb0_hD[k]); }

/* ---- from build/var/mod/parts/p1ead8.c */
/* FUN_0001ead8 @ 0001ead8: scroll the message lines up and load a new last line */
char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern void FUN_0002c368(void *, int);
extern char *B00062bb0_hD[17];
void FUN_0001ead8(int n)
{
    int k;
    n %= 0xc0;
    for (k = 0; k < 16; k++) strcpy(B00062bb0_hD[k], B00062bb0_hD[k + 1]);
    FUN_0002c368(B00062bb0_hD[16], n + 0x371);
}

/* ---- from build/var/mod/parts/p1eb3c.c */
/* FUN_0001eb3c: y is computed from k in each iteration (with the start value set before the loop), which keeps y + 12 from becoming a separate induction variable */
/* FUN_0001eb3c @ 0001eb3c: scroll and redraw the seventeen message lines */
extern void FUN_0001ead8(int), FUN_0004060c(int, int, char *, int), FUN_00039cec(int, int, int, int, int); extern int FUN_00040288(char *, int);
extern char *B00062bb0_hD[17]; extern unsigned char DAT_00056cd8[];
void FUN_0001eb3c(int n, int flag)
{
    int k, line, y, w, xl, yb;
    if (n % 16 == 0) FUN_0001ead8(n / 16 + 16);
    if (flag) {
        y = 0x52 - n % 16;
        line = n / 16;
        for (k = 0; k < 17; k++) {
            w = FUN_00040288(B00062bb0_hD[k], 5) / 2;
            xl = 0xa0 - w;
            y = 0x52 - n % 16 + k * 16;
            FUN_0004060c(y, xl, B00062bb0_hD[k], 5);
            if (DAT_00056cd8[line % 0xc0]) { yb = y + 12; FUN_00039cec(yb, xl, yb, w + 0xa0, 0x1b); }
            line++;
        }
    }
}

/* ---- from build/var/mod/parts/p1ec1c.c */
/* FUN_0001ec1c @ 0001ec1c: the end-game credits scroll: fade the COLORS palette in, scroll the text until a click or key, then clean up */
#include "snd.h"
extern void FUN_000391b0(unsigned char), FUN_0003975c(int, int, int, int, int), FUN_00039b40(int, int, int, int, int), FUN_0003a020(int), FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00042404(char *, int, char, char, char, int), FUN_00039234(unsigned char *), FUN_000422ec(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_0001ea90(void), FUN_0003e608(void), FUN_0001eb3c(int, int), FUN_0003a078(int, int, int, int, int, int, int), FUN_0003e614(unsigned, int), FUN_00042220(unsigned char *, int, int, unsigned char, unsigned char, unsigned char), FUN_00030294(void), FUN_000305b4(int);
extern int FUN_0002a1f4(void), FUN_00040b40(void);
extern int DAT_0005c050, B000758dc_cl, B000758d0_jK; extern unsigned char DAT_0005c054[]; extern void *B00062bb0_hD[17];
void FUN_0001ec1c(void)
{
    int t, k;
    FUN_000391b0(DAT_0005c050);
    FUN_0003975c(0, 0, 0, B000758dc_cl + 0x65, 0);
    FUN_0003975c(0, 0xc8, 0, B000758dc_cl + 0x66, 0);
    FUN_00039b40(0xec, 0x53, 0xa0, 0x78, 0);
    FUN_0003a020(DAT_0005c050 ^ 1);
    DAT_0005c050 ^= 1;
    FUN_000425b0(DAT_0005c054, 0, 0xd, "COLORS", 0x100);
    FUN_00042404(DAT_0005c054, 0x90, 0, 0, 0, 0x6f);
    FUN_00039234(DAT_0005c054);
    FUN_000425b0(DAT_0005c054, 0, 0xd, "COLORS", 0x100);
    FUN_000391b0(DAT_0005c050);
    FUN_0003975c(0, 0, 0, B000758dc_cl + 0x65, 0);
    FUN_0003975c(0, 0xc8, 0, B000758dc_cl + 0x66, 0);
    FUN_0003a020(DAT_0005c050 ^ 1);
    DAT_0005c050 ^= 1;
    FUN_00037f24(B000758d0_jK + 0x11);
    FUN_000422ec(DAT_0005c054, 0x90, 0xff, 0, 0, 0);
    t = 0xaf0;
    FUN_0001ea90();
    while (!FUN_0002a1f4() && !FUN_00040b40()) {
        FUN_0003e608();
        FUN_000391b0(DAT_0005c050);
        FUN_0003975c(0, 0, 0, B000758dc_cl + 0x65, 0);
        FUN_0003975c(0, 0xc8, 0, B000758dc_cl + 0x66, 0);
        FUN_0001eb3c(t, 1);
        t++;
        FUN_0003a078(DAT_0005c050 ^ 1, 0x52, 0, 0x52, 0, 0xec, 0x140);
        t %= 0xc00;
        FUN_0001eb3c(t, 0);
        t++;
        t %= 0xc00;
        FUN_0003e614(1, 0);
    }
    for (k = 0; k < 0x11; k++) FUN_000410b0(B00062bb0_hD[k]);
    FUN_00038dcc(0x9c4);
    FUN_00042220(DAT_0005c054, 0, 0xff, 0, 0, 0);
    FUN_00038ef0();
    FUN_00038ce8();
    FUN_00030294();
    FUN_000305b4(0);
}

/* ---- module data _DATA 00056cd8-00056d98 (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
unsigned char DAT_00056cd8[192] = {
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
    0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 1, 0, 0, 0, 0, 1
};
/* ---- end of module data _DATA */
