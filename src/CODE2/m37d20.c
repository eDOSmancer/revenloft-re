#include "farproc.h"
/* Module: FUN_00037d20, FUN_00037ecc, FUN_00037f24, FUN_00037ff0, FUN_00038020, FUN_00038078, FUN_00038098,
   FUN_000380dc, FUN_000380e8, FUN_00038110, FUN_00038164, FUN_00038168 */
/* ---- from build/var/mod/parts/p37d20.c */
/* the sound library entry points and FUN_00045a0c are cdecl (ebx not preserved); that decides the register layout */
/* FUN_00037d20 @ 00037d20: load the digital sound driver file and initialise the sound card; sets DAT_0005ee40 on success */
#include "snd.h"
extern int FUN_00040d80(void *, void *, void *), FUN_000412a0(char *), FUN_0004127c(char *), FUN_00045a0c(void *, int, int), FUN_000465df(int), FUN_000466bb(int, int, int, int, int); extern void *FUN_0004104c(int);
extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int), FUN_00046254(void), FUN_000462be(int), FUN_000466c5(int, int, int, int, int); extern int *FUN_0004669c(int);
#pragma aux FUN_00045a0c modify [eax ebx ecx edx];
#pragma aux FUN_00046254 modify [eax ebx ecx edx];
#pragma aux FUN_000465df modify [eax ebx ecx edx];
#pragma aux FUN_0004669c modify [eax ebx ecx edx];
#pragma aux FUN_000466bb modify [eax ebx ecx edx];
#pragma aux FUN_000466c5 modify [eax ebx ecx edx];
#pragma aux FUN_000462be modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64; extern char DAT_00061e68[];
void FUN_00037d20(char *name, int a, int b, int c, int d)
{
    int fd, r; void *buf;
    if (DAT_0005ee40 == 0) {
        DAT_0005ee60 = FUN_00040d80(0x61e68, &DAT_0005ee64, &DAT_0005ee68);
        if (DAT_0005ee60 != 0) {
            fd = FUN_000412a0(name);
            if (fd == -1) {
                FUN_00040de8(DAT_0005ee68);
                return;
            }
            buf = FUN_0004104c(FUN_0004127c(name));
            if (buf == 0) {
                FUN_00040de8(DAT_0005ee68);
                return;
            }
            FUN_000412ec(buf, FUN_0004127c(name), fd);
            FUN_000412dc(fd);
            r = FUN_00045a0c(buf, 5, 0);
            if (r == 0) {
                FUN_00040de8(DAT_0005ee68);
                FUN_000410b0(buf);
                return;
            }
            FUN_000410b0(buf);
            FUN_00046254();
            DAT_0005ee6c = FUN_000465df(r);
            if (DAT_0005ee6c == -1) {
                FUN_00040de8(DAT_0005ee68);
                FUN_000462be(0);
                return;
            }
            if (FUN_0004669c(DAT_0005ee6c)[1] != 2) {
                FUN_000462be(0);
                FUN_00040de8(DAT_0005ee68);
                return;
            }
            if (FUN_000466bb(DAT_0005ee6c, a, b, c, d) == 0) {
                FUN_000462be(0);
                FUN_00040de8(DAT_0005ee68);
                return;
            }
            FUN_000466c5(DAT_0005ee6c, a, b, c, d);
            DAT_0005ee40 = 1;
        }
    }
}

/* ---- from build/var/mod/parts/p37ecc.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);
void FUN_00037ecc(void)
{
    if (DAT_0005ee40) {
        FUN_00037ff0();
        FUN_0004666e(DAT_0005ee6c);
        FUN_00040de8(DAT_0005ee68);
        DAT_0005ee40 = 0;
    }
}

extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
extern int DAT_0005ee64, DAT_0005ee44;


void FUN_00037f24(int a)
{
    int *p; unsigned n; int *d;
    if (DAT_0005ee40 && DAT_0005ee70) {
        p = FUN_0003f29c(a, DAT_0005ee44);
        n = *p; d = p + 1;
        FUN_00037ff0();
        memcpy(DAT_0005ee60, d, n);
        FUN_000467f9(DAT_0005ee6c, DAT_0005ee60, -1);
        FUN_000467ef(DAT_0005ee6c, DAT_0005ee60, DAT_0005ee64, -1);
        FUN_0004680d(DAT_0005ee6c);
    }
}


/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);
void FUN_00037ff0(void)
{
    if (DAT_0005ee40) {
        if (FUN_00046803(DAT_0005ee6c) == 2) FUN_00046817(DAT_0005ee6c);
    }
}

/* ---- from build/var/mod/parts/p38020.c */
/* FUN_00038020, FUN_000386c4: read a length-prefixed block from a file into a fresh buffer */
extern void *FUN_0004104c(int);
extern int DAT_0005ee40, DAT_0005ee78;
void *FUN_00038020(int unused, int fd)
{
    int n; void *p;
    if (DAT_0005ee40) {
        FUN_000412ec(&n, 4, fd);
        p = FUN_0004104c(n + 4);
        *(int *)p = n;
        FUN_000412ec((char *)p + 4, n, fd);
        return p;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p38078.c */
/* FUN_00038078, FUN_0003871c */
extern void FUN_000410b0(void *);
extern int DAT_0005ee40, DAT_0005ee78;
void FUN_00038078(void *p) { if (DAT_0005ee40 && p) FUN_000410b0(p); }

/* ---- from build/var/mod/parts/p38098.c */
extern void FUN_00037f24(int a); /* module prototype */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern int DAT_0005ee64, DAT_0005ee44;


void FUN_00038098(unsigned char on)
{
    DAT_0005ee70 = on;
    if (DAT_0005ee40 && on == 0) {
        if (DAT_0005ee40) {
            if (FUN_00046803(DAT_0005ee6c) == 2) FUN_00046817(DAT_0005ee6c);
        }
    }
}

/* ---- from build/var/mod/parts/p380dc.c */
/* FUN_000380dc @ 000380dc: setter */
extern int DAT_0005ee44;
void FUN_000380dc(int v) { DAT_0005ee44 = v; }

/* ---- from build/var/mod/parts/p380e8.c */
extern void FUN_00037f24(int a); /* module prototype */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern int DAT_0005ee64, DAT_0005ee44;


int FUN_000380e8(void)
{
    if (DAT_0005ee40) return FUN_00046803(DAT_0005ee6c) == 2;
    return 0;
}

/* ---- from build/var/mod/parts/p38110.c */
/* FUN_00038110, FUN_00038164 @ 00038110: queue sound id on channel ch unless a higher-priority one is pending; then the empty stub it falls into */
struct SND { int id, vol, prio; };
extern int DAT_0005ee40;
void FUN_00038110(int id, int vol, int ch, int prio)
{
    int ok;
    if (!DAT_0005ee40) return;
    ok = 1;
    if (((struct SND *)&DAT_0005ee48)[ch].id != -1 && ((struct SND *)&DAT_0005ee48)[ch].prio < prio) ok = 0;
    if (ok) {
        ((struct SND *)&DAT_0005ee48)[ch].id = id;
        ((struct SND *)&DAT_0005ee48)[ch].vol = vol;
        ((struct SND *)&DAT_0005ee48)[ch].prio = prio;
    }
}

extern int DAT_0005ee40;

void FUN_00038164(int a, int b, unsigned char c) {}

/* ---- from build/var/mod/parts/p38168.c */
extern void FUN_00037f24(int a); /* module prototype */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern int DAT_0005ee64, DAT_0005ee44;


void FUN_00038168(void)
{
    if (DAT_0005ee40) {
        if (DAT_0005ee48 != -1 && DAT_0005ee54 != -1) {
            if (DAT_0005ee50 < DAT_0005ee5c) FUN_00037f24(DAT_0005ee48);
            else FUN_00037f24(DAT_0005ee54);
            DAT_0005ee54 = -1;
            DAT_0005ee48 = -1;
            return;
        }
        if (DAT_0005ee48 != -1) { FUN_00037f24(DAT_0005ee48); DAT_0005ee48 = -1; return; }
        if (DAT_0005ee54 != -1) { FUN_00037f24(DAT_0005ee54); DAT_0005ee54 = -1; }
    }
}

/* ---- module data _DATA 0005ee40-0005ee74 (docs/data/dataown.CODE2.csv: certain (ref; shared by m23f70 m37d20 m38210 m3e340 m43aa0)), generated by tools/data2c.py */
int DAT_0005ee40 = 0;
int DAT_0005ee44 = 0;
int DAT_0005ee48 = -1;
unsigned char DAT_0005ee4c[4] = { 0xff, 0xff, 0xff, 0xff };   /* no name in the sources */
int DAT_0005ee50 = -1;
int DAT_0005ee54 = -1;
unsigned char DAT_0005ee58[4] = { 0xff, 0xff, 0xff, 0xff };   /* no name in the sources */
int DAT_0005ee5c = -1;
void *DAT_0005ee60 = 0;
int DAT_0005ee64 = 0;
unsigned short DAT_0005ee68 = 0;
unsigned char DAT_0005ee6a[2] = { 0x68, 0x79 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005ee6c = 0;
unsigned char DAT_0005ee70 = 1;
/* ---- end of module data _DATA */
