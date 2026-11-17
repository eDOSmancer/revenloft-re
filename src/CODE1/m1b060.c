/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
unsigned char F00038a18_eu[12];
struct SNDCFG *B00038a18_eu;
/* BSS end */
/* Module: FUN_0001b060, FUN_0001b0f8, FUN_0001b430, FUN_0001b4d4, FUN_0001b51c, FUN_0001b574, FUN_0001b598,
   FUN_0001b5e4, FUN_0001b6c0, FUN_0001b6ec, FUN_0001b74c, FUN_0001b75c, FUN_0001b76c, FUN_0001b824,
   FUN_0001b8f4, FUN_0001ba04, FUN_0001ba98, FUN_0001bb80, FUN_0001bbec, FUN_0001bc1c, FUN_0001bcb4,
   FUN_0001bd20, FUN_0001bd84, FUN_0001bdcc, FUN_0001bdd8, FUN_0001bde4, FUN_0001be28, FUN_0001be34,
   FUN_0001be40 */
/* ---- from build/var/mod/parts/p1b060.c */
/* FUN_0001b060 @ 0001b060: load the digital sample file SAMPLE.AD into memory (DAT_00032b98) and mark sound as loaded (CODE.1 copy of CODE.2 FUN_00038210) */
#include <string.h>
#include <stdio.h>
extern int FUN_0001627c(char *), FUN_000162a8(char *); extern void *FUN_000171c8(int);
extern void FUN_00019814(char *), FUN_00016304(void *, int, int), FUN_000162f0(int);
extern void *DAT_00032b98; extern unsigned char DAT_00032b94;
void FUN_0001b060(void)
{
    char msg[256]; char name[32]; int size; int fh;
    strcpy(name, "SAMPLE.AD");
    size = FUN_0001627c(name);
    DAT_00032b98 = FUN_000171c8(size);
    fh = FUN_000162a8(name);
    if (fh == -1) {
        sprintf(msg, "Timber file \"%s\" not found\n", name);
        FUN_00019814(msg);
    }
    FUN_00016304(DAT_00032b98, size, fh);
    FUN_000162f0(fh);
    DAT_00032b94 = 1;
}

/* ---- from build/var/mod/parts/p1b0f8.c */
extern void FUN_0001b060(void); /* module prototype */
#define FUN_00016304 ((int (*)(void *, int, int))FUN_00016304)
/* FUN_0001b0f8 @ 0001b0f8: load the digital sound driver and allocate its buffers (twin of CODE.2 FUN_000382bc). Round 24: first difference was buf/h in edi/ebx (original esi/edi); cause: FUN_0001e680 (the AIL start-up entry, CODE.2 FUN_00046254) is cdecl too and clobbers ebx, so h cannot take ebx; with the twin's statement order and its never-assigned index i the function matches. */
struct DRVINFO { int a, type; };
struct SNDCFG { char pad[0x32]; short mode; };
extern void *FUN_00016f10(int, int *, unsigned short *), *FUN_000171c8(int), *FUN_0001f8c4(void *, int, int);
extern int FUN_000162a8(char *), FUN_0001627c(char *), FUN_0001ea0b(void *), FUN_0001eae7(int, int, int, int, int), FUN_0001ec89(int), FUN_0001eca7(int);
extern struct DRVINFO *FUN_0001eac8(int);
extern void FUN_00016f74(int), FUN_000162f0(int), FUN_00017240(void *), FUN_0001e680(void), FUN_0001e6ea(int), FUN_0001eaf1(int, int, int, int, int), FUN_0001ecb1(int, void *, int);
#pragma aux FUN_0001f8c4 modify [eax ebx ecx edx];
#pragma aux FUN_0001e680 modify [eax ebx ecx edx];
#pragma aux FUN_0001ea0b modify [eax ebx ecx edx];
#pragma aux FUN_0001e6ea modify [eax ebx ecx edx];
#pragma aux FUN_0001eac8 modify [eax ebx ecx edx];
#pragma aux FUN_0001eae7 modify [eax ebx ecx edx];
#pragma aux FUN_0001eaf1 modify [eax ebx ecx edx];
#pragma aux FUN_0001ec89 modify [eax ebx ecx edx];
#pragma aux FUN_0001eca7 modify [eax ebx ecx edx];
#pragma aux FUN_0001ecb1 modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032ba0, DAT_00032b90, DAT_00032f48, DAT_00032c04, DAT_00032bc8[], DAT_00032b8c, DAT_00032bfc;
extern unsigned short DAT_00032ba4, DAT_00032be8[], DAT_00032c00;
extern void *DAT_00032b9c, *DAT_00032ba8[], *DAT_00032bf8;
extern struct SNDCFG *DAT_00032aa0, *B00038a18_eu;
void FUN_0001b0f8(char *name, int a, int b, int c, int d)
{
    int fd; int k; int j; int i; void *buf; void *h;
    if (DAT_00032b84) return;
    if ((DAT_00032b9c = FUN_00016f10(0xc800, &DAT_00032ba0, &DAT_00032ba4)) == 0) return;
    fd = FUN_000162a8(name);
    if (fd == -1) {
        FUN_00016f74(DAT_00032ba4);
        return;
    }
    buf = FUN_000171c8(FUN_0001627c(name));
    if (!buf) {
        FUN_00016f74(DAT_00032ba4);
        return;
    }
    FUN_00016304(buf, FUN_0001627c(name), fd);
    FUN_000162f0(fd);
    h = FUN_0001f8c4(buf, 5, 0);
    if (!h) {
        FUN_00016f74(DAT_00032ba4);
        FUN_00017240(buf);
        return;
    }
    FUN_00017240(buf);
    if (!DAT_00032f48) FUN_0001e680();
    DAT_00032b90 = FUN_0001ea0b(h);
    if (DAT_00032b90 == -1) {
        if (!DAT_00032f48) FUN_0001e6ea(0);
        FUN_00016f74(DAT_00032ba4);
        return;
    }
    if (FUN_0001eac8(DAT_00032b90)->type != 3) {
        if (!DAT_00032f48) FUN_0001e6ea(0);
        FUN_00016f74(DAT_00032ba4);
        return;
    }
    if (!FUN_0001eae7(DAT_00032b90, a, b, c, d)) {
        if (!DAT_00032f48) FUN_0001e6ea(0);
        FUN_00016f74(DAT_00032ba4);
        return;
    }
    FUN_0001eaf1(DAT_00032b90, a, b, c, d);
    DAT_00032c04 = FUN_0001ec89(DAT_00032b90);
    if (DAT_00032c04)
        for (k = 0; k < 8; k++)
            if ((DAT_00032ba8[k] = FUN_00016f10(DAT_00032c04, &DAT_00032bc8[k], &DAT_00032be8[k])) == 0) {
                if (!DAT_00032f48) FUN_0001e6ea(0);
                for (j = 0; j < k; j++) FUN_00016f74(DAT_00032be8[j]);
                FUN_00016f74(DAT_00032ba4);
                return;
            }
    DAT_00032b8c = FUN_0001eca7(DAT_00032b90);
    if (DAT_00032b8c) {
        if ((DAT_00032bf8 = FUN_00016f10(DAT_00032b8c, &DAT_00032bfc, &DAT_00032c00)) == 0) {
            if (!DAT_00032f48) FUN_0001e6ea(0);
            for (j = 0; j < 8; j++) FUN_00016f74(DAT_00032be8[i]);
            FUN_00016f74(DAT_00032ba4);
            return;
        }
        FUN_0001ecb1(DAT_00032b90, DAT_00032bf8, DAT_00032b8c);
    }
    B00038a18_eu = DAT_00032aa0;
    if (DAT_00032aa0->mode && DAT_00032aa0->mode != 3) FUN_0001b060();
    DAT_00032b84 = 1;
}

#undef FUN_00016304
/* ---- from build/var/mod/parts/p1b430.c */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
/* FUN_0001b430 */
extern void FUN_0001ea9a(int), FUN_00016f74(int), FUN_00017240(void *);
#pragma aux FUN_0001ea9a modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032b90, DAT_00032b8c, DAT_00032c04; extern unsigned short DAT_00032c00, DAT_00032be8[], DAT_00032ba4; extern unsigned char DAT_00032b94; extern void *DAT_00032b98;
void FUN_0001b430(void) { int k; if (DAT_00032b84) { FUN_0001ba98(); FUN_0001b6ec(); FUN_0001ea9a(DAT_00032b90); if (DAT_00032b8c) FUN_00016f74(DAT_00032c00); if (DAT_00032c04) for (k = 0; k < 8; k++) FUN_00016f74(DAT_00032be8[k]); FUN_00016f74(DAT_00032ba4); if (DAT_00032b94) { FUN_00017240(DAT_00032b98); DAT_00032b94 = 0; } DAT_00032b84 = 0; } }

/* ---- from build/var/mod/parts/p1b4d4.c */
#define DAT_00032b98 (*(signed char **)&DAT_00032b98)
/* FUN_0001b4d4 @ 0001b4d4: find entry (a, b) in the sound bank directory and return its data pointer (module compiled with -os) */

char *FUN_0001b4d4(unsigned short a, unsigned short b) { int k; signed char *e, *t = DAT_00032b98; for (k = 0; (e = t + k * 6)[1] != -1; k++) if (e[1] == a && e[0] == b) return *(int *)(e + 2) + (char *)DAT_00032b98; return 0; }

#undef DAT_00032b98
/* ---- from build/var/mod/parts/p1b51c.c */
#define FUN_00016304 ((int (*)(void *, int, int))FUN_00016304)
/* FUN_0001b51c */
 extern int *FUN_000171c8(int); extern int DAT_00032b84;
int *FUN_0001b51c(int a, int f) { volatile int n; int *p; if (DAT_00032b84) { FUN_00016304((void *)&n, 4, f); p = FUN_000171c8(n + 4); *p = n; FUN_00016304(p + 1, n, f); return p; } return 0; }

#undef FUN_00016304
/* ---- from build/var/mod/parts/p1b574.c */
#define FUN_00017240 ((void (*)(int))FUN_00017240)
/* FUN_0001b574 */
 extern int DAT_00032b84;
void FUN_0001b574(int p) { if (DAT_00032b84 && p) FUN_00017240(p); }

#undef FUN_00017240
/* ---- from build/var/mod/parts/p1b598.c */
#define DAT_00032aa0 (*(char **)&DAT_00032aa0)
#define B00038a18_eu (*(char **)&B00038a18_eu)
/* FUN_0001b598 @ 0001b598: current music volume, scaled to 90% in the quiet mode (module compiled for a 486/Pentium target, -5s) */
extern int DAT_00032c3c; 
int FUN_0001b598(void) { int vol; B00038a18_eu = DAT_00032aa0; if (*(short *)(DAT_00032aa0 + 0x32) == 3) vol = (DAT_00032c3c * 0x5a + 0x32) / 100; else vol = DAT_00032c3c; return vol; }

#undef DAT_00032aa0
#undef B00038a18_eu
/* ---- from build/var/mod/parts/p1b5e4.c */
extern char *FUN_0001b4d4(unsigned short a, unsigned short b); /* module prototype */
#define DAT_00032b9c (*(int *)&DAT_00032b9c)
#define DAT_00032ba8 ((int *)DAT_00032ba8)
extern int FUN_0001ec93(int, int, int, int, int); extern unsigned short FUN_0001ecbb(int, int); extern void FUN_0001ecc5(int, int, int, int); extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[]; extern unsigned char DAT_00032c28[], DAT_00032b94;
void FUN_0001b5e4(int k) { unsigned short r; int p, t; unsigned short a, b; if (DAT_00032b84 && !DAT_00032c28[k]) { if ((DAT_00032c08[k] = FUN_0001ec93(DAT_00032b90, DAT_00032b9c, k, DAT_00032ba8[k], 0)) != -1) { if (DAT_00032b94) while ((r = FUN_0001ecbb(DAT_00032b90, DAT_00032c08[k])) != 0xffff) { t = r; a = t / 256; b = t % 256; p = FUN_0001b4d4(a, b); if (!p) return; FUN_0001ecc5(DAT_00032b90, a, b, p); } DAT_00032c28[k] = 1; } } }

#undef DAT_00032b9c
#undef DAT_00032ba8
/* ---- from build/var/mod/parts/p1b6c0.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
/* sound module helpers (gap functions, not in the Ghidra export): music sequence start/resume/fade, bank load, volume and tempo, status queries */
#pragma aux FUN_0001ec9d modify [eax ebx ecx edx];
#pragma aux FUN_0001ed29 modify [eax ebx ecx edx];
#pragma aux FUN_0001ed33 modify [eax ebx ecx edx];
#pragma aux FUN_0001eced modify [eax ebx ecx edx];
#pragma aux FUN_0001ed01 modify [eax ebx ecx edx];
#pragma aux FUN_0001ed15 modify [eax ebx ecx edx];
#pragma aux FUN_0001ed0b modify [eax ebx ecx edx];
extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
/* struct SNDCFG: defined above */
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);
void *memmove(void *, const void *, unsigned);
void FUN_0001b6c0(int k)
{
    if (DAT_00032b84) FUN_0001ec9d(DAT_00032b90, DAT_00032c08[k]);
}

/* ---- from build/var/mod/parts/p1b6ec.c */
/* FUN_0001b6ec */
extern int FUN_0001ed0b(int, int); extern void FUN_0001ec9d(int, int);
#pragma aux FUN_0001ed0b modify [eax ebx ecx edx];
#pragma aux FUN_0001ec9d modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[]; extern unsigned char DAT_00032c28[];
void FUN_0001b6ec(void) { int k, r; if (DAT_00032b84) { for (k = 0; k < 8; k++) if (DAT_00032c28[k]) { r = FUN_0001ed0b(DAT_00032b90, DAT_00032c08[k]); if (r == 0 || r == 2) FUN_0001ec9d(DAT_00032b90, DAT_00032c08[k]); DAT_00032c28[k] = 0; } } }

/* ---- from build/var/mod/parts/p1b74c.c */
/* FUN_0001b74c */
extern int DAT_00032b80;
void FUN_0001b74c(int v) { DAT_00032b80 = v; }

/* ---- from build/var/mod/parts/p1b75c.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001b75c(int v)
{
    DAT_00032b88 = v;
}

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001b76c(int k)
{
    if (DAT_00032b84 && DAT_00032c44 && k != DAT_00032c38) {
        FUN_0001ba98();
        FUN_0001b5e4(k);
        DAT_00032c30 = DAT_00032c08[k];
        DAT_00032c38 = k;
        if (DAT_00032c30 != -1 && DAT_00032c38 != -1) {
            FUN_0001ed29(DAT_00032b90, DAT_00032c30, FUN_0001b598(), 0);
            FUN_0001ed33(DAT_00032b90, DAT_00032c30, DAT_00032c40, 0);
            FUN_0001eced(DAT_00032b90, DAT_00032c30);
        }
    }
}

/* ---- from build/var/mod/parts/p1b824.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
/* FUN_0001b824 */
extern void FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed29(int, int, int, int); 
#pragma aux FUN_0001ed33 modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032c38, DAT_00032c30, DAT_00032c08[], DAT_00032c40, DAT_00032b90; extern unsigned char DAT_00032c44;
void FUN_0001b824(int song, int vol) { if (DAT_00032b84 && DAT_00032c44 && song != DAT_00032c38) { FUN_0001ba98(); FUN_0001b5e4(song); DAT_00032c30 = DAT_00032c08[song]; DAT_00032c38 = song; if (DAT_00032c30 != -1 && DAT_00032c38 != -1) { FUN_0001ed33(DAT_00032b90, DAT_00032c30, DAT_00032c40, 0); FUN_0001eced(DAT_00032b90, DAT_00032c30); FUN_0001ed29(DAT_00032b90, DAT_00032c30, 0, 0); FUN_0001ed29(DAT_00032b90, DAT_00032c30, FUN_0001b598(), vol); } } }

/* ---- from build/var/mod/parts/p1b8f4.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001b8f4(int k, int fade)
{
    if (DAT_00032b84 && DAT_00032c44 && k != DAT_00032c38) {
        FUN_0001ba98();
        DAT_00032c30 = DAT_00032c08[k];
        DAT_00032c38 = k;
        if (DAT_00032c30 != -1 && DAT_00032c38 != -1) {
            if (!DAT_00032c28[k]) {
                FUN_0001b824(k, fade);
                return;
            }
            FUN_0001ed29(DAT_00032b90, DAT_00032c30, FUN_0001b598(), 0);
            FUN_0001ed01(DAT_00032b90, DAT_00032c30);
            if (fade) {
                FUN_0001ed29(DAT_00032b90, DAT_00032c30, 0, 0);
                FUN_0001ed29(DAT_00032b90, DAT_00032c30, FUN_0001b598(), fade);
            } else FUN_0001ed33(DAT_00032b90, DAT_00032c30, DAT_00032c40, 0);
        }
    }
}

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001ba04(int bank, int k)
{
    int *p;
    if (DAT_00032b84 && DAT_00032c44) {
        FUN_0001ba98();
        FUN_0001b6ec();
        if (DAT_00032c34 != bank) {
            if (DAT_00032aa0->mode == 3 || DAT_00032aa0->mode == 4) p = FUN_0001954c(bank + DAT_00032b88, DAT_00032b80);
            else p = FUN_0001954c(bank, DAT_00032b80);
            memmove(DAT_00032b9c, p + 1, *p);
            DAT_00032c34 = bank;
        }
        FUN_0001b76c(k);
    }
}

/* ---- from build/var/mod/parts/p1ba98.c */
extern void FUN_0001b5e4(int k); /* module prototype */
/* FUN_0001ba98 */
extern int FUN_0001ed0b(int, int); extern void FUN_0001ecf7(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int);
#pragma aux FUN_0001ed33 modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032c38, DAT_00032c30, DAT_00032b90, DAT_00032c08[], DAT_00032c40;
void FUN_0001ba98(void) { int r; if (DAT_00032b84 && DAT_00032c38 != -1) { r = FUN_0001ed0b(DAT_00032b90, DAT_00032c30); if (r != 0 && r != 2) FUN_0001ecf7(DAT_00032b90, DAT_00032c30); FUN_0001b5e4(0); DAT_00032c30 = DAT_00032c08[0]; DAT_00032c38 = 0; if (DAT_00032c30 != -1) { FUN_0001ed29(DAT_00032b90, DAT_00032c30, 0, 0); FUN_0001ed33(DAT_00032b90, DAT_00032c30, DAT_00032c40, 0); FUN_0001eced(DAT_00032b90, DAT_00032c30); while (FUN_0001ed0b(DAT_00032b90, DAT_00032c30) != 2); } DAT_00032c38 = -1; DAT_00032c30 = -1; } }

/* ---- from build/var/mod/parts/p1bb80.c */
extern void FUN_0001ba98(void); /* module prototype */
/* FUN_0001bb80 */
extern int FUN_0001ed0b(int, int), FUN_0001ed15(int, int); extern void FUN_0001ed29(int, int, int, int);
#pragma aux FUN_0001ed0b modify [eax ebx ecx edx];
#pragma aux FUN_0001ed15 modify [eax ebx ecx edx];
#pragma aux FUN_0001ed29 modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032c38, DAT_00032c30, DAT_00032b90;
void FUN_0001bb80(int v) { int r; if (DAT_00032b84 && DAT_00032c38 != -1) { r = FUN_0001ed0b(DAT_00032b90, DAT_00032c30); if (r == 0 || r == 2) { DAT_00032c30 = -1; DAT_00032c38 = -1; } else FUN_0001ed29(DAT_00032b90, DAT_00032c30, 0, v); } }

/* ---- from build/var/mod/parts/p1bbec.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001bbec(int k, int fade)
{
    if (DAT_00032b84 && DAT_00032c44) {
        FUN_0001ba98();
        FUN_0001b824(k, fade);
    }
}

/* ---- from build/var/mod/parts/p1bc1c.c */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
#define DAT_00032aa0 (*(char **)&DAT_00032aa0)
/* FUN_0001bc1c */
void *memmove(void *, const void *, unsigned);  extern int *FUN_0001954c(int, int); extern int DAT_00032b84, DAT_00032c34, DAT_00032b88, DAT_00032b80; extern unsigned char DAT_00032c44;  extern void *DAT_00032b9c;
void FUN_0001bc1c(int song, int a, int b) { int *p; if (DAT_00032b84 && DAT_00032c44) { FUN_0001ba98(); FUN_0001b6ec(); if (DAT_00032c34 != song) { if (*(short *)(DAT_00032aa0 + 0x32) == 3 || *(short *)(DAT_00032aa0 + 0x32) == 4) p = FUN_0001954c(song + DAT_00032b88, DAT_00032b80); else p = FUN_0001954c(song, DAT_00032b80); memmove(DAT_00032b9c, p + 1, *p); DAT_00032c34 = song; } FUN_0001b824(a, b); } }

#undef DAT_00032aa0
/* ---- from build/var/mod/parts/p1bcb4.c */
extern void FUN_0001ba98(void); /* module prototype */
/* FUN_0001bcb4 */
extern int FUN_0001ed0b(int, int), FUN_0001ed15(int, int); extern void FUN_0001ed29(int, int, int, int);
#pragma aux FUN_0001ed0b modify [eax ebx ecx edx];
#pragma aux FUN_0001ed15 modify [eax ebx ecx edx];
#pragma aux FUN_0001ed29 modify [eax ebx ecx edx];
extern int DAT_00032b84, DAT_00032c38, DAT_00032c30, DAT_00032b90;
void FUN_0001bcb4(void) { int r; if (DAT_00032b84 && DAT_00032c38 != -1) { r = FUN_0001ed0b(DAT_00032b90, DAT_00032c30); if (r == 0 || r == 2) { DAT_00032c38 = -1; DAT_00032c30 = -1; } else { while (FUN_0001ed15(DAT_00032b90, DAT_00032c30)); FUN_0001ba98(); } } }

/* ---- from build/var/mod/parts/p1bd20.c */
extern int FUN_0001b598(void); /* module prototype */
extern void FUN_0001b5e4(int k); /* module prototype */
extern void FUN_0001b6ec(void); /* module prototype */
extern void FUN_0001b824(int song, int vol); /* module prototype */
extern void FUN_0001ba98(void); /* module prototype */
extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001bd20(int t)
{
    if (DAT_00032c3c != t) {
        DAT_00032c3c = t;
        if (DAT_00032b84 && DAT_00032c38 != -1 && FUN_0001ed15(DAT_00032b90, DAT_00032c30) == 100) FUN_0001ed29(DAT_00032b90, DAT_00032c30, FUN_0001b598(), 0);
    }
}

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001bd84(int v)
{
    if (DAT_00032c40 != v) {
        DAT_00032c40 = v;
        if (DAT_00032b84 && DAT_00032c38 != -1) FUN_0001ed33(DAT_00032b90, DAT_00032c30, v, 0);
    }
}

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

int FUN_0001bdcc(void) { return DAT_00032c38; }

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

int FUN_0001bdd8(void) { return DAT_00032c34; }

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

int FUN_0001bde4(void)
{
    int r, s;
    r = 0;
    if (DAT_00032b84 && DAT_00032c38 != -1) {
        s = r = FUN_0001ed0b(DAT_00032b90, DAT_00032c30);
        if (s == 0 || s == 2) r = 1;
    }
    return r;
}

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

int FUN_0001be28(void) { return DAT_00032c40; }

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

int FUN_0001be34(void) { return DAT_00032c3c; }

extern void FUN_0001ec9d(int, int), FUN_0001ed29(int, int, int, int), FUN_0001ed33(int, int, int, int), FUN_0001eced(int, int), FUN_0001ed01(int, int);
extern int FUN_0001ed15(int, int), FUN_0001ed0b(int, int);
extern int DAT_00032b84, DAT_00032b90, DAT_00032c08[], DAT_00032c30, DAT_00032c34, DAT_00032c38, DAT_00032c3c, DAT_00032c40, DAT_00032b88, DAT_00032b80;
extern unsigned char DAT_00032c44, DAT_00032c28[];
extern void *DAT_00032b9c;
extern struct SNDCFG *DAT_00032aa0;


extern int *FUN_0001954c(int, int);

void FUN_0001be40(unsigned char on)
{
    DAT_00032c44 = on;
    if (DAT_00032b84 && !DAT_00032c44) FUN_0001ba98();
}

/* ---- module data _DATA 00032b80-00032c48 (docs/data/dataown.CODE1.csv: certain (ref; some shared)), generated by tools/data2c.py */
int DAT_00032b80 = 0;
int DAT_00032b84 = 0;
int DAT_00032b88 = 0;
int DAT_00032b8c = 0;
int DAT_00032b90 = 0;
unsigned char DAT_00032b94 = 0;
unsigned char DAT_00032b95[3] = { 0x75, 0x66, 0x66 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
void *DAT_00032b98 = 0;
void *DAT_00032b9c = 0;
int DAT_00032ba0 = 0;
unsigned short DAT_00032ba4 = 0;
unsigned char DAT_00032ba6[2] = { 0x76, 0x65 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
void *DAT_00032ba8[8] = { 0 };
int DAT_00032bc8[8] = { 0 };
unsigned short DAT_00032be8[8] = { 0 };
void *DAT_00032bf8 = 0;
int DAT_00032bfc = 0;
unsigned short DAT_00032c00 = 0;
unsigned char DAT_00032c02[2] = { 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00032c04 = 0;
int DAT_00032c08[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
unsigned char DAT_00032c28[8] = { 0 };
int DAT_00032c30 = -1;
int DAT_00032c34 = -1;
int DAT_00032c38 = -1;
int DAT_00032c3c = 0x64;
int DAT_00032c40 = 0x64;
unsigned char DAT_00032c44 = 1;
/* ---- end of module data _DATA */
