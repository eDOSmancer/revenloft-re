typedef void (__far *PARA_BSS)(); /* STANDIN: the _BSS of this object file is paragraph-aligned in the original (unnamed bytes ahead of it up to the 16-byte boundary); a typedef of a far pointer type raises the alignment, as a far pointer or double variable of any function would (docs/BSS.md) */
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
int B00062c10_h8;
/* BSS end */
/* Module: FUN_000231dc, FUN_00023248, FUN_00023268, FUN_00023284, FUN_0002329c, FUN_000232b4, FUN_000232dc,
   FUN_0002330c, FUN_000233cc, FUN_00023488, FUN_000235c4, FUN_00023834, FUN_000239ac, FUN_00023ad8,
   FUN_00023c88, FUN_00023ef8 */
/* ---- from build/var/mod/parts/p231dc.c */
/* FUN_000231dc @ 000231dc: remove the 0x3c door at (13, 31) from the door list.
   The door count is the third short of a block of list counts at 0x758a2 (entities, ?, doors; f271fc saves it
   with &DAT_000758a6). Declared as a plain global, -oa makes it
   a register candidate (OW cg conflict.c: N_MEMORY names get conflicts under RELAX_ALIAS) and it is cached in si
   for the whole function, which the original does not do; as a struct member it stays in memory (observed,
   2026-11-10). Matches with and without -oa. */
#include "world.h"
void *memmove(void *, const void *, unsigned);

 extern short B0007223a_et, B0007223e_dx; extern unsigned short B00072246_dJ; extern unsigned char B00072238_dL[];
#define DR_KIND(i) (*(unsigned short *)((char *)&B00072246_dJ + (i) * 0x16))
#define DR_X(i)    (*(short *)((char *)&B0007223e_dx + (i) * 0x16))
#define DR_Y(i)    (*(short *)((char *)&B0007223a_et + (i) * 0x16))
void FUN_000231dc(void)
{
    int i;
    for (i = 0; i < B00075618_b1.ndoor; i++) {
        if (DR_Y(i) == 0x1f && DR_X(i) == 0xd && DR_KIND(i) == 0x3c) {
            memmove(B00072238_dL + i * 0x16, B00072238_dL + (i + 1) * 0x16, (B00075618_b1.ndoor - i - 1) * 0x16);
            B00075618_b1.ndoor--;
            return;
        }
    }
}

#undef DR_KIND
#undef DR_X
#undef DR_Y
/* ---- from build/var/mod/parts/p23248.c */
/* FUN_00023248..FUN_000235c4: the cut-scene stream readers and the script step/command functions of module 0x231dc, in one
   file as in the module (recipe 26): FUN_000233cc and FUN_00023488 expand the readers FUN_00023284/FUN_0002329c, and
   FUN_000235c4 expands FUN_000232dc and FUN_00023488. */
/* DAT_00057f98: the picture sequence is running; DAT_00057f9c: frames left in it. As two members of one structure they are
   not -oa register candidates; as two plain globals FUN_00023488's conflict list has two more memory nodes and the
   allocation tie (ShellSort of equal savings) puts the long read's address into the stream pointer's register (found with
   the 2002 instrument tools/ow1cc.sh, tie round 2026-11-11; confirmed with 10.0a). */
struct CSEQ { int on, left; };
extern struct CSEQ DAT_00057f98;
/* FUN_00023248 @ 00023248: current read position in the resource file */
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;
int FUN_00023248(void) { return FUN_0004131c(0, 1, DAT_00057f7c) - 0x1f400 + DAT_00057f88; }

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_00023268 @ 00023268 */
extern unsigned char *DAT_00057f84;
extern int DAT_00057f88;
unsigned char FUN_00023268(void) { int i = DAT_00057f88++; return DAT_00057f84[i]; }

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_00023284, FUN_0002329c: read a 16-bit / 32-bit value from the resource stream */
extern int DAT_00057f88;
unsigned short FUN_00023284(void) { unsigned short *p = (unsigned short *)(DAT_00057f84 + DAT_00057f88); DAT_00057f88 += 2; return *p; }

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


extern int DAT_00057f88;

int FUN_0002329c(void) { int *p = (int *)(DAT_00057f84 + DAT_00057f88); DAT_00057f88 += 4; return *p; }

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_000232b4 @ 000232b4: copy n bytes from the resource stream */
/* FUN_000232dc @ 000232dc: take the 768-byte palette from the resource stream. It calls FUN_000232b4, which is expanded here; where
   FUN_000232dc itself is expanded (FUN_000235c4, case 0) the nested call stays a call: 10.0a expands one level only */
void *memmove(void *, const void *, unsigned);
extern unsigned char *DAT_00057f84, DAT_0005c355[], DAT_00057f8c; extern int DAT_00057f88;
void FUN_000232b4(void *dst, int n) { memmove(dst, DAT_00057f84 + DAT_00057f88, n); DAT_00057f88 += n; }

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


extern unsigned char *DAT_00057f84, DAT_0005c355[], DAT_00057f8c; extern int DAT_00057f88;

void FUN_000232dc(void)
{
    FUN_000232b4(DAT_0005c355, 0x300);
    DAT_00057f8c = 1;
}

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_0002330c @ 0002330c: decode the 400 run-length coded 320-pixel rows of the resource stream to the screen */
void *memmove(void *, const void *, unsigned); extern void FUN_00037a90(unsigned char *, int, int, int, int);
extern unsigned char *DAT_00057f84, DAT_0005759c[]; extern int DAT_00057f88, DAT_0005c050;
void FUN_0002330c(void)
{
    int row, x, n; unsigned char c, *dst, v;
    for (row = 0; row < 400; row++) {
        dst = DAT_0005759c;
        x = 0;
        do {
            c = DAT_00057f84[DAT_00057f88++];
            if (c < 0x80) {
                n = c + 1;
                x += n;
                memmove(dst, DAT_00057f84 + DAT_00057f88, n);
                dst += n;
                DAT_00057f88 += n;
            } else if (c > 0x80) {
                n = 0x101 - c;
                x += n;
                v = DAT_00057f84[DAT_00057f88++];
                while (n) {
                    *dst++ = v;
                    n--;
                }
            }
        } while (x < 0x140);
        FUN_00037a90(DAT_0005759c, row, 0, 0x50, DAT_0005c050);
    }
}

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_000233cc @ 000233cc: draw a run-length encoded picture from the script data (-oa: the script read offset DAT_00057f88 is cached in ebp; words come through an inlined reader) */
extern void FUN_000391b0(unsigned char), FUN_00039aa4(int, int, int); 
extern int DAT_00057f88;
void FUN_000233cc(int c)
{
    int n, m, cnt, x, y;
    FUN_000391b0(c);
    n = FUN_00023284();
    x = 0;
    for (; n != 0; n--) {
        x += FUN_00023284();
        m = FUN_00023284();
        y = 0;
        for (; m != 0; m--) {
            y += FUN_00023284();
            cnt = FUN_00023284();
            while (cnt--) FUN_00039aa4(y++, x, FUN_00023268());
        }
    }
}

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_00023488 @ 00023488: step the scripted picture sequence (one frame per call) */
 extern int FUN_0004131c(int, int, int);
extern int DAT_00057f88, DAT_00057fa0, DAT_00057fac, DAT_00057fb0, DAT_00057f7c, DAT_00057f94, DAT_0005c050;
void FUN_00023488(void)
{
    if (DAT_00057f98.on) {
        if (--DAT_00057f98.left == 0) {
            FUN_0004131c(DAT_00057fb0, 0, DAT_00057f7c);
            DAT_00057f88 = 0x1f400;
            DAT_00057f98.on = 0;
            DAT_00057f94 = 0;
            return;
        }
        DAT_00057f88 += 6;
        FUN_000233cc(DAT_0005c050);
        FUN_0004131c(DAT_00057fa0, 0, DAT_00057f7c);
        DAT_00057f88 = 0x1f400;
    } else {
        DAT_00057f98.left = FUN_00023284();
        DAT_00057fa0 = FUN_0002329c() + DAT_00057fac;
        FUN_000233cc(DAT_0005c050);
        DAT_00057fb0 = FUN_00023248();
        FUN_0004131c(DAT_00057fa0, 0, DAT_00057f7c);
        DAT_00057f88 = 0x1f400;
        DAT_00057f98.on = 1;
    }
}

extern struct CSEQ DAT_00057f98;
extern int FUN_0004131c(int, int, int); extern int DAT_00057f7c, DAT_00057f88;


/* FUN_000235c4 @ 000235c4: read and run one command of the cut-scene script: palette, clear, fades, sounds, music, text */
void *memset(void *, int, unsigned);
extern void FUN_000412ec(void *, unsigned, int), FUN_00039b40(int, int, int, int, int), FUN_00039234(unsigned char *);
extern void FUN_00037bd8(int), FUN_00037aec(int), FUN_00037b84(int), FUN_00038dcc(int), FUN_00038ef0(void), FUN_00039008(int), FUN_00038f58(int), FUN_00038e58(int, int, int);
extern void FUN_00038110(int, int, int, int), FUN_000246b8(int), FUN_0002c368(void *, int);
extern int DAT_00057f7c, DAT_00057f88, DAT_00057f78, DAT_00057fa4, DAT_00057fa8, DAT_0005c050, B000758d0_jK;
extern unsigned char DAT_00057f80, DAT_00057f8c, DAT_0005c355[], DAT_0005759c[];
void FUN_000235c4(void)
{
    int len; unsigned short type; short b, a, x; short *q;
    FUN_000412ec(&type, 2, DAT_00057f7c);
    FUN_000412ec(&len, 4, DAT_00057f7c);
    FUN_000412ec(DAT_00057f84, len, DAT_00057f7c);
    DAT_00057f88 = 0;
    switch (type) {
    case 0: FUN_000232dc(); break;
    case 1: FUN_00039b40(0, 0, 0x190, 0x140, 0); memset(DAT_0005c355, 0, 0x300); FUN_00039234(DAT_0005c355); break;
    case 2: FUN_00037bd8(DAT_0005c050); break;
    case 3: DAT_00057f80 = 1; FUN_00037aec(DAT_0005c050); break;
    case 4: FUN_00023488(); break;
    case 8: DAT_00057f80 = 1; FUN_00037b84(DAT_0005c050); break;
    case 5:
        q = (short *)DAT_00057f84;
        x = *q++;
        DAT_00057f88 = 4;
        b = *q;
        a = x;
        if (x == 0x15 && DAT_00057f78 == 0xb) a = 0x30;
        FUN_00038dcc(0x9c4);
        FUN_00038ef0();
        FUN_00039008(100);
        FUN_00038f58(100);
        FUN_00038e58(a, b + 1, 0x9c4);
        break;
    case 6:
        a = ((short *)DAT_00057f84)[0];
        DAT_00057f88 = 2;
        if (a == 3 || a == 0xf || a == 0x88) break;
        FUN_00038110(a + B000758d0_jK, 0xff, 0, 1);
        break;
    case 9:
        a = ((short *)DAT_00057f84)[0];
        DAT_00057f88 = 2;
        FUN_000246b8(a);
        break;
    case 7:
        q = (short *)DAT_00057f84;
        a = *q++;
        x = *q;
        DAT_00057f88 = 4;
        DAT_00057fa8 = (unsigned short)x;
        if (!a) {
            FUN_00039b40(0x140, 0, 0x50, 0x140, 0);
            DAT_00057fa4 = 0;
        } else {
            FUN_0002c368(DAT_0005759c, a + 0x324);
            DAT_00057fa4 = 1;
        }
        break;
    }
}

/* ---- from build/var/mod/parts/p23834.c */
extern void FUN_000235c4(void); /* module prototype */
#define DAT_0005759c ((char *)DAT_0005759c)
/* FUN_00023834 @ 00023834: play the frames of the current cut scene from the script file; 1 when aborted with Esc (the frame source is an if/else of two calls: a ?: argument would force an ebp frame) */
extern void FUN_000412ec(void *, unsigned, int), FUN_000391b0(unsigned char), FUN_000391c8(unsigned char), FUN_0003e608(void), FUN_00040700(void), FUN_0003f868(void);
extern void FUN_00039b40(int, int, int, int, int), FUN_0003a020(int), FUN_00038168(void), FUN_00039234(unsigned char *), FUN_0003e614(unsigned, int);
extern int FUN_00023fd4(int, int, int, int, int, char *, int), FUN_00040b40(void);
extern int DAT_00057f7c, DAT_00057f90, DAT_00057fa4, DAT_00057fa8, DAT_0005c050, B00062c10_h8, DAT_00057f94; extern unsigned char DAT_00057f80, DAT_00057f8c, DAT_0005c355[]; 
int FUN_00023834(void)
{
    unsigned short nfr, n, k, j; int r;
    r = 0;
    DAT_00057f90 = 0;
    FUN_000412ec(&nfr, 2, DAT_00057f7c);
    FUN_000412ec(&DAT_00057f90, 2, DAT_00057f7c);
    FUN_000391b0(DAT_0005c050);
    FUN_000391c8(DAT_0005c050 ^ 1);
    for (k = 0; k < nfr; k++) {
        FUN_0003e608();
        FUN_00040700();
        DAT_00057f80 = 0;
        FUN_000412ec(&n, 2, DAT_00057f7c);
        for (j = 0; j < n; j++) {
            FUN_000235c4();
            FUN_0003f868();
        }
        if (DAT_00057fa4) {
            FUN_00039b40(0x140, 0, 0x50, 0x140, 0);
            FUN_00023fd4(1, 0x140, 0, 0x10, 0x140, DAT_0005759c, DAT_00057fa8);
        }
        FUN_0003a020(DAT_0005c050 ^ 1);
        FUN_00038168();
        if (DAT_00057f8c) {
            FUN_00039234(DAT_0005c355);
            DAT_00057f8c = 0;
        }
        if (DAT_00057f80) FUN_0003e614(B00062c10_h8, 0); else FUN_0003e614(DAT_00057f90, 0);
        FUN_0003f868();
        if (FUN_00040b40() == 0x1b) {
            r = 1;
            break;
        }
        DAT_00057f94 = 1;
    }
    return r;
}

#undef DAT_0005759c
/* ---- from build/var/mod/parts/p239ac.c */
/* FUN_000239ac @ 000239ac: open cutscene file n (path\CINEnn.ANM); if it is missing restore the palette and abort with "<path>...Cannot Find"; returns the handle, rewound */
#include <string.h>
#define DAT_0005759c ((char *)DAT_0005759c)
extern char DAT_0005f061[], *DAT_00057f74; extern unsigned char DAT_0005c054[];
extern int FUN_000412a0(char *); extern void FUN_000425b0(unsigned char *, int, int, char *, int), FUN_00039234(unsigned char *), FUN_0003f580(char *), FUN_0004131c(int, int, int);
int FUN_000239ac(int n)
{
    char name[11] = "CINE00.ANM"; int fh;
    name[4] = n / 10 + '0';
    name[5] = n % 10 + '0';
    strcpy(DAT_0005759c, DAT_0005f061);
    strcat(DAT_0005759c, "\\");
    strcat(DAT_0005759c, name);
    fh = FUN_000412a0(DAT_0005759c);
    if (fh == -1) {
        FUN_000425b0(DAT_0005c054, 0, 0, "COLORS", 0x100);
        FUN_00039234(DAT_0005c054);
        strcat(DAT_0005759c, DAT_00057f74);
        FUN_0003f580(DAT_0005759c);
    }
    FUN_0004131c(0, 0, fh);
    return fh;
}

#undef DAT_0005759c
/* ---- from build/var/mod/parts/p23ad8.c */
extern int FUN_000239ac(int n); /* module prototype */
#define FUN_0004131c ((int (*)(int, int, int))FUN_0004131c)
/* FUN_00023ad8 @ 00023ad8: set up scene *mode: save the audio state (except mode 12), adjust the mode to the party, open its data stream */
extern void FUN_00029ccc(int), FUN_00038dcc(int), FUN_0002aacc(void); extern int FUN_00039048(void), FUN_00039050(void), FUN_00039098(void), FUN_000390a0(void); extern void *FUN_0004104c(int);
extern unsigned char B000718e0_iO[];
#define B000718f0_hO ((char *)((char *)&B000718e0_iO + 16)) /* STANDIN: view, B000718e0_iO + 0x10 */
 extern int B00062c10_h8, DAT_00057f78, DAT_00057f88, DAT_00057f94, DAT_00057fa4, DAT_00057fa0, DAT_00057fb0, DAT_00057f7c, DAT_00057fac;
extern unsigned char DAT_00057f8c;
/* struct CSEQ: defined above */   /* DAT_00057f98, DAT_00057f9c: see f23248.c */
extern struct CSEQ DAT_00057f98;
void FUN_00023ad8(int *pmode, int *a, int *b, int *c, int *d)
{
    int v4, v2, v1, v3, mode, n, k, fd;
    mode = *pmode;
    FUN_00029ccc(0);
    if (mode != 0xc) {
        v1 = FUN_00039048();
        v2 = FUN_00039050();
        v3 = FUN_00039098();
        v4 = FUN_000390a0();
        FUN_00038dcc(0x9c4);
        B00062c10_h8 = 6;
    } else {
        B00062c10_h8 = 2;
    }
    FUN_0002aacc();
    if (mode == 2) {
        n = 0;
        for (k = 0; k < 4; k++) if (!(*(unsigned short *)(B000718f0_hO + k * 0x248) & 0x8000)) n++;
        mode += n - 1;
    }
    if (mode == 10) {
        n = 0;
        for (k = 0; k < 4; k++)
            if (*(unsigned short *)(B000718f0_hO + k * 0x248) < 0x4000 && !(*(unsigned short *)(B000718f0_hO + k * 0x248) & 0x80)) n++;
        if (!n) mode = 0xb;
    }
    DAT_00057f78 = mode;
    fd = FUN_000239ac(mode);
    DAT_00057f88 = 0x1f400;
    DAT_00057f8c = 0;
    DAT_00057f94 = 1;
    DAT_00057f98.on = 0;
    DAT_00057fa4 = 0;
    DAT_00057f98.left = 0;
    DAT_00057fa0 = 0;
    DAT_00057fb0 = 0;
    DAT_00057f7c = fd;
    DAT_00057fac = FUN_0004131c(0, 1, fd);
    DAT_00057f84 = FUN_0004104c(0x1f400);
    *pmode = mode;
    *a = v2;
    *b = v1;
    *c = v3;
    *d = v4;
}

#undef FUN_0004131c
/* ---- from build/var/mod/parts/p23c88.c */
extern void FUN_000231dc(void); /* module prototype */
#define DAT_00057f84 ((void *)DAT_00057f84)
/* FUN_00023c88 @ 00023c88: end the cut scene: close its file, restore the game screen, place the party where the scene leads, restart the music s (vol v, pan p, fade f) */
void *memset(void *, int, unsigned);
extern void FUN_000410b0(void *), FUN_000412dc(int), FUN_0001ec1c(void), FUN_00037ff0(void), FUN_00038dcc(int), FUN_00030294(void), FUN_00039234(unsigned char *), FUN_0002a288(void);
extern void FUN_0002c124(int), FUN_00038ef0(void), FUN_00038ce8(void), FUN_000281b4(int), FUN_00025050(int), FUN_000425b0(unsigned char *, int, int, char *, int);
extern void FUN_00039008(int), FUN_00038f58(int), FUN_00038e58(int, int, int), FUN_0002f8fc(void), FUN_00029cf4(void);
extern int FUN_00039050(void);
 extern int DAT_00057f7c, DAT_0005c658, DAT_0005c034;
extern short B000755d0_ao;
#define B000755d2_ai (*(short *)((char *)&B000755d0_ao + 2)) /* STANDIN: view, B000755d0_ao + 0x2 */
extern short B000755d4_ak;
#define B000755d6_ae (*(short *)((char *)&B000755d4_ak + 2)) /* STANDIN: view, B000755d4_ak + 0x2 */
extern short B000755d0_ao, B000755d4_ak;
extern unsigned char DAT_0005c054[];
void FUN_00023c88(int sc, int s, int v, int f, int p)
{
    FUN_000410b0(DAT_00057f84);
    FUN_000412dc(DAT_00057f7c);
    if (sc == 10 || sc == 11) FUN_0001ec1c();
    FUN_00037ff0();
    FUN_00038dcc(0x9c4);
    FUN_00030294();
    memset(DAT_0005c054, 0, 0x300);
    FUN_00039234(DAT_0005c054);
    FUN_0002a288();
    switch (sc) {
    case 1: FUN_0002c124(0x2b); break;
    case 2: case 3: case 4: case 5:
        B000755d2_ai = 0x16; B000755d6_ae = 0xd; B000755d4_ak = 0x8000; B000755d0_ao = 0x8000; DAT_0005c658 = 0;
        FUN_00038ef0(); FUN_00038ce8(); s = -2; FUN_000281b4(0xc);
        break;
    case 6:
        B000755d2_ai = 0x17; B000755d6_ae = 0x17; B000755d4_ak = 0x8000; B000755d0_ao = 0x8000; DAT_0005c658 = 0x10e;
        FUN_00038ef0(); FUN_00038ce8(); s = -2; FUN_000281b4(0xc);
        break;
    case 7:
        B000755d2_ai = 2; B000755d6_ae = 0x41; B000755d4_ak = 0x8000; B000755d0_ao = 0x8000; DAT_0005c658 = 0x10e;
        FUN_00038ef0(); FUN_00038ce8(); FUN_000281b4(0xb); FUN_0002c124(0x25); FUN_00025050(0x6e); s = -2; FUN_000231dc();
        break;
    case 9:
        B000755d2_ai = 0x15; B000755d6_ae = 0x2b; DAT_0005c658 = 0xb4;
        break;
    }
    if (sc != 0 && sc != 12) {
        FUN_000425b0(DAT_0005c054, 0, DAT_0005c034, "COLORS", 0x100);
        FUN_00039234(DAT_0005c054);
        if (s != -2) {
            if (FUN_00039050() != -1) { FUN_00038dcc(0x9c4); FUN_00038ef0(); }
            if (s != -1) {
                FUN_00038ce8();
                FUN_00039008(f);
                FUN_00038f58(p);
                FUN_00038e58(s, v, 0x9c4);
            }
        }
        FUN_0002f8fc();
        FUN_00029cf4();
    } else {
        if (FUN_00039050() != -1) { FUN_00038dcc(0x9c4); FUN_00038ef0(); }
        FUN_00029cf4();
    }
}

#undef DAT_00057f84
/* ---- from build/var/mod/parts/p23ef8.c */
extern int FUN_00023834(void); /* module prototype */
extern void FUN_00023ad8(int *pmode, int *a, int *b, int *c, int *d); /* module prototype */
extern void FUN_00023c88(int sc, int s, int v, int f, int p); /* module prototype */
/* FUN_00023ef8 @ 00023ef8 */
extern int FUN_0002c1dc(int);   
int FUN_00023ef8(int a)
{
    int l0, l1, l2, l3, r;
    if (a == 7) { if (FUN_0002c1dc(0x25) == 1) return 0; }
    FUN_00023ad8(&a, &l0, &l1, &l2, &l3);
    r = FUN_00023834();
    FUN_00023c88(a, l0, l1, l2, l3);
    return r;
}

/* ---- module data _DATA 00057f74-00057fb4 (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
char *DAT_00057f74 = "...Cannot Find";
int DAT_00057f78 = 0;
int DAT_00057f7c = 0;
unsigned char DAT_00057f80 = 0;
unsigned char DAT_00057f81[3] = { 0x79, 0x70, 0x65 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned char *DAT_00057f84 = 0;
int DAT_00057f88 = 0x1f400;
unsigned char DAT_00057f8c = 0;
unsigned char DAT_00057f8d[3] = { 0x2c, 0x20, 0x69 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00057f90 = 0;
int DAT_00057f94 = 1;
struct CSEQ DAT_00057f98 = { 0 };
int DAT_00057fa0 = 0;
int DAT_00057fa4 = 0;
int DAT_00057fa8 = 0;
int DAT_00057fac = 0;
int DAT_00057fb0 = 0;
/* ---- end of module data _DATA */
