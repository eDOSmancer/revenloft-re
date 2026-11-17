/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
unsigned char F000770f0_bn[12];
char *B000770f0_a0;
/* BSS end */
/* Module: FUN_00038210, FUN_000382bc, FUN_000385d4, FUN_00038670, FUN_000386c4, FUN_0003871c, FUN_0003873c,
   FUN_0003878c, FUN_0003885c, FUN_00038884, FUN_000388e4, FUN_000388f0, FUN_000388fc, FUN_000389e4,
   FUN_00038ae0, FUN_00038c54, FUN_00038ce8, FUN_00038dcc, FUN_00038e30, FUN_00038e58, FUN_00038ef0,
   FUN_00038f58, FUN_00039008, FUN_00039048, FUN_00039050, FUN_00039058, FUN_00039098, FUN_000390a0,
   FUN_000390a8 */
/* ---- from build/var/mod/parts/p38210.c */
/* FUN_00038210 @ 00038210: load the digital sample file SAMPLE.AD into memory (DAT_0005ee8c) and mark sound as loaded */
#include <string.h>
#include <stdio.h>
extern int FUN_0004127c(char *), FUN_000412a0(char *); extern void *FUN_0004104c(int);
extern void FUN_0003f580(char *), FUN_000412dc(int); extern int FUN_000412ec(void *, unsigned, int);
extern void *DAT_0005ee8c; extern unsigned char DAT_0005ee88;
void FUN_00038210(void)
{
    char msg[256]; char name[32]; int size; int fh;
    strcpy(name, "SAMPLE.AD");
    size = FUN_0004127c(name);
    DAT_0005ee8c = FUN_0004104c(size);
    fh = FUN_000412a0(name);
    if (fh == -1) {
        sprintf(msg, "Timber file \"%s\" not found\n", name);
        FUN_0003f580(msg);
    }
    FUN_000412ec(DAT_0005ee8c, size, fh);
    FUN_000412dc(fh);
    DAT_0005ee88 = 1;
}

/* ---- from build/var/mod/parts/p382bc.c */
extern void FUN_00038210(void); /* module prototype */
/* FUN_000382bc @ 000382bc: load the digital sound driver and allocate its buffers. The sound library entry points are cdecl (ebx not preserved). The second cleanup loop indexes with `i`, which is never assigned (bug in the game; the original reads whatever is in esi) */
extern int FUN_00040de8(int);
struct DRVINFO { int a, type; };
struct SNDCFG { char pad[0x32]; short mode; };
extern void *FUN_00040d80(int, int *, unsigned short *), *FUN_0004104c(int), *FUN_00045a0c(void *, int, int);
extern int FUN_000412a0(char *), FUN_0004127c(char *), FUN_000465df(void *), FUN_000466bb(int, int, int, int, int), FUN_0004685d(int), FUN_0004687b(int);
extern struct DRVINFO *FUN_0004669c(int);
extern int FUN_000412ec(void *, unsigned, int); extern void FUN_000412dc(int), FUN_000410b0(void *), FUN_00046254(void), FUN_000462be(int), FUN_000466c5(int, int, int, int, int), FUN_00046885(int, void *, int);
extern int DAT_0005ee78, DAT_0005ee94, DAT_0005ee40, DAT_0005ee84, DAT_0005eef8, DAT_0005eebc[], DAT_0005ee80, DAT_0005eef0;
extern unsigned short DAT_0005ee98, DAT_0005eedc[], DAT_0005eef4;
extern void *DAT_0005ee90, *DAT_0005ee9c[], *DAT_0005eeec;
extern char *DAT_0005f050, *B000770f0_a0;
#pragma aux (cdecl) FUN_00045a0c;
#pragma aux (cdecl) FUN_00046254;
#pragma aux (cdecl) FUN_000462be;
#pragma aux (cdecl) FUN_000465df;
#pragma aux (cdecl) FUN_0004669c;
#pragma aux (cdecl) FUN_000466bb;
#pragma aux (cdecl) FUN_000466c5;
#pragma aux (cdecl) FUN_0004685d;
#pragma aux (cdecl) FUN_0004687b;
#pragma aux (cdecl) FUN_00046885;
void FUN_000382bc(char *name, int a, int b, int c, int d)
{
    int fd; int k; int j; int i; void *buf; void *h;
    if (DAT_0005ee78) return;
    if ((DAT_0005ee90 = FUN_00040d80(0xc800, &DAT_0005ee94, &DAT_0005ee98)) == 0) return;
    fd = FUN_000412a0(name);
    if (fd == -1) {
        FUN_00040de8(DAT_0005ee98);
        return;
    }
    buf = FUN_0004104c(FUN_0004127c(name));
    if (!buf) {
        FUN_00040de8(DAT_0005ee98);
        return;
    }
    FUN_000412ec(buf, FUN_0004127c(name), fd);
    FUN_000412dc(fd);
    h = FUN_00045a0c(buf, 5, 0);
    if (!h) {
        FUN_00040de8(DAT_0005ee98);
        FUN_000410b0(buf);
        return;
    }
    FUN_000410b0(buf);
    if (!DAT_0005ee40) FUN_00046254();
    DAT_0005ee84 = FUN_000465df(h);
    if (DAT_0005ee84 == -1) {
        if (!DAT_0005ee40) FUN_000462be(0);
        FUN_00040de8(DAT_0005ee98);
        return;
    }
    if (FUN_0004669c(DAT_0005ee84)->type != 3) {
        if (!DAT_0005ee40) FUN_000462be(0);
        FUN_00040de8(DAT_0005ee98);
        return;
    }
    if (!FUN_000466bb(DAT_0005ee84, a, b, c, d)) {
        if (!DAT_0005ee40) FUN_000462be(0);
        FUN_00040de8(DAT_0005ee98);
        return;
    }
    FUN_000466c5(DAT_0005ee84, a, b, c, d);
    DAT_0005eef8 = FUN_0004685d(DAT_0005ee84);
    if (DAT_0005eef8)
        for (k = 0; k < 8; k++)
            if ((DAT_0005ee9c[k] = FUN_00040d80(DAT_0005eef8, &DAT_0005eebc[k], &DAT_0005eedc[k])) == 0) {
                if (!DAT_0005ee40) FUN_000462be(0);
                for (j = 0; j < k; j++) FUN_00040de8(DAT_0005eedc[j]);
                FUN_00040de8(DAT_0005ee98);
                return;
            }
    DAT_0005ee80 = FUN_0004687b(DAT_0005ee84);
    if (DAT_0005ee80) {
        if ((DAT_0005eeec = FUN_00040d80(DAT_0005ee80, &DAT_0005eef0, &DAT_0005eef4)) == 0) {
            if (!DAT_0005ee40) FUN_000462be(0);
            for (j = 0; j < 8; j++) FUN_00040de8(DAT_0005eedc[i]);
            FUN_00040de8(DAT_0005ee98);
            return;
        }
        FUN_00046885(DAT_0005ee84, DAT_0005eeec, DAT_0005ee80);
    }
    B000770f0_a0 = DAT_0005f050;
    if (((struct SNDCFG *)B000770f0_a0)->mode && ((struct SNDCFG *)B000770f0_a0)->mode != 3) FUN_00038210();
    DAT_0005ee78 = 1;
}

/* ---- from build/var/mod/parts/p385d4.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);

void FUN_000385d4(void)
{
    int k;
    if (DAT_0005ee78) {
        FUN_00038ce8();
        FUN_00038884();
        FUN_0004666e(DAT_0005ee84);
        if (DAT_0005ee80) FUN_00040de8(DAT_0005eef4);
        if (DAT_0005eef8) for (k = 0; k < 8; k++) FUN_00040de8(DAT_0005eedc[k]);
        FUN_00040de8(DAT_0005ee98);
        if (DAT_0005ee88) { FUN_000410b0(DAT_0005ee8c); DAT_0005ee88 = 0; }
        DAT_0005ee78 = 0;
    }
}

/* ---- from build/var/mod/parts/p38670.c */
/* FUN_00038670 @ 00038670: look up a (b, a) entry in the resource directory at DAT_0005ee8c */

char *FUN_00038670(unsigned short a, unsigned short b)
{
    signed char *p;
    for (p = ((signed char *)DAT_0005ee8c); p[1] != -1; p += 6)
        if (p[1] == a && p[0] == b) return (char *)((signed char *)DAT_0005ee8c) + *(int *)(p + 2);
    return 0;
}

/* ---- from build/var/mod/parts/p386c4.c */
/* FUN_000386c4: read a length-prefixed block from a file into a fresh buffer (twin of FUN_00038020) */
extern void *FUN_0004104c(int);
extern int DAT_0005ee78;
void *FUN_000386c4(int unused, int fd)
{
    int n; void *p;
    if (DAT_0005ee78) {
        FUN_000412ec(&n, 4, fd);
        p = FUN_0004104c(n + 4);
        *(int *)p = n;
        FUN_000412ec((char *)p + 4, n, fd);
        return p;
    }
    return 0;
}

/* ---- from build/var/mod/parts/p3871c.c */
/* FUN_0003871c: free a block if the digital driver is loaded (twin of FUN_00038078) */
extern void FUN_000410b0(void *);
extern int DAT_0005ee78;
void FUN_0003871c(void *p) { if (DAT_0005ee78 && p) FUN_000410b0(p); }

/* ---- from build/var/mod/parts/p3873c.c */
/* FUN_0003873c @ 0003873c: music volume for the driver (90% on driver type 3) */
extern int DAT_0005ef30;
int FUN_0003873c(void)
{
    B000770f0_a0 = DAT_0005f050;
    if (*(short *)(DAT_0005f050 + 0x32) == 3) return (DAT_0005ef30 * 0x5a + 0x32) / 100;
    return DAT_0005ef30;
}

/* ---- from build/var/mod/parts/p3878c.c */
/* FUN_0003878c @ 0003878c: load sound effect k into the driver and register its sub-samples */
#include "snd.h"
void FUN_0003878c(int k)
{
    unsigned short hi, lo; int v, r;
    if (DAT_0005ee78 && DAT_0005ef1c[k] == 0) {
        DAT_0005eefc[k] = FUN_00046867(DAT_0005ee84, DAT_0005ee90, k, DAT_0005ee9c[k], 0);
        if (DAT_0005eefc[k] != -1) {
            if (DAT_0005ee88) {
                while ((v = (unsigned short)FUN_0004688f(DAT_0005ee84, DAT_0005eefc[k])) != 0xffff) {
                    hi = v / 256;
                    lo = v % 256;
                    r = FUN_00038670(hi, lo);
                    if (r == 0) return;
                    FUN_00046899(DAT_0005ee84, hi, lo, r);
                }
            }
            DAT_0005ef1c[k] = 1;
        }
    }
}

/* ---- from build/var/mod/parts/p3885c.c */
/* FUN_0003885c @ 0003885c: release song k from the music driver */
#include "snd.h"
void FUN_0003885c(int k) { if (DAT_0005ee78) FUN_00046871(DAT_0005ee84, DAT_0005eefc[k]); }

/* ---- from build/var/mod/parts/p38884.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);

void FUN_00038884(void)
{
    int k;
    if (DAT_0005ee78) {
        for (k = 0; k < 8; k++) {
            if (DAT_0005ef1c[k]) {
                int st = FUN_000468df(DAT_0005ee84, DAT_0005eefc[k]);
                if (st == 0 || st == 2) FUN_00046871(DAT_0005ee84, DAT_0005eefc[k]);
                DAT_0005ef1c[k] = 0;
            }
        }
    }
}

/* ---- from build/var/mod/parts/p388e4.c */
/* FUN_000388e4 @ 000388e4: setter */
extern int DAT_0005ee74;
void FUN_000388e4(int v) { DAT_0005ee74 = v; }

/* ---- from build/var/mod/parts/p388f0.c */
/* FUN_000388f0 @ 000388f0: setter */
extern int DAT_0005ee7c;
void FUN_000388f0(int v) { DAT_0005ee7c = v; }

/* ---- from build/var/mod/parts/p388fc.c */
extern void FUN_0003878c(int k); /* module prototype */
extern void FUN_00038ce8(void); /* module prototype */
/* FUN_000388fc @ 000388fc: start song k at the music volume (90% on driver type 3) */
extern int FUN_000468df(int, int); extern void FUN_000468cb(int, int), FUN_000468c1(int, int), FUN_000468fd(int, int, int, int), FUN_00046907(int, int, int, int);
#pragma aux FUN_000468df modify [eax ebx ecx edx];
#pragma aux FUN_000468cb modify [eax ebx ecx edx];
#pragma aux FUN_000468c1 modify [eax ebx ecx edx];
#pragma aux FUN_000468fd modify [eax ebx ecx edx];
#pragma aux FUN_00046907 modify [eax ebx ecx edx];
extern int DAT_0005ee78, DAT_0005ef2c, DAT_0005ef24, DAT_0005ee84, DAT_0005ef34, DAT_0005ef30, DAT_0005eefc[];
extern unsigned char DAT_0005ef38;
void FUN_000388fc(int k)
{
    int vol;
    if (!DAT_0005ee78 || !DAT_0005ef38 || k == DAT_0005ef2c) return;
    FUN_00038ce8();
    FUN_0003878c(k);
    DAT_0005ef2c = k;
    DAT_0005ef24 = DAT_0005eefc[k];
    if (DAT_0005ef24 == -1 || k == -1) return;
    B000770f0_a0 = DAT_0005f050;
    if (*(short *)(DAT_0005f050 + 0x32) == 3) vol = (DAT_0005ef30 * 0x5a + 0x32) / 100;
    else vol = DAT_0005ef30;
    FUN_000468fd(DAT_0005ee84, DAT_0005ef24, vol, 0);
    FUN_00046907(DAT_0005ee84, DAT_0005ef24, DAT_0005ef34, 0);
    FUN_000468c1(DAT_0005ee84, DAT_0005ef24);
}

/* ---- from build/var/mod/parts/p389e4.c */
extern void FUN_0003878c(int k); /* module prototype */
extern void FUN_00038ce8(void); /* module prototype */
/* FUN_000389e4 @ 000389e4: start song k silently and fade it in to the music volume over t */
extern int FUN_000468df(int, int); extern void FUN_000468cb(int, int), FUN_000468c1(int, int), FUN_000468fd(int, int, int, int), FUN_00046907(int, int, int, int);
#pragma aux FUN_000468df modify [eax ebx ecx edx];
#pragma aux FUN_000468cb modify [eax ebx ecx edx];
#pragma aux FUN_000468c1 modify [eax ebx ecx edx];
#pragma aux FUN_000468fd modify [eax ebx ecx edx];
#pragma aux FUN_00046907 modify [eax ebx ecx edx];
extern int DAT_0005ee78, DAT_0005ef2c, DAT_0005ef24, DAT_0005ee84, DAT_0005ef34, DAT_0005ef30, DAT_0005eefc[];
extern unsigned char DAT_0005ef38;
void FUN_000389e4(int k, int t)
{
    int vol;
    if (!DAT_0005ee78 || !DAT_0005ef38 || k == DAT_0005ef2c) return;
    FUN_00038ce8();
    FUN_0003878c(k);
    DAT_0005ef2c = k;
    DAT_0005ef24 = DAT_0005eefc[k];
    if (DAT_0005ef24 == -1 || k == -1) return;
    FUN_00046907(DAT_0005ee84, DAT_0005ef24, DAT_0005ef34, 0);
    FUN_000468c1(DAT_0005ee84, DAT_0005ef24);
    FUN_000468fd(DAT_0005ee84, DAT_0005ef24, 0, 0);
    B000770f0_a0 = DAT_0005f050;
    if (*(short *)(DAT_0005f050 + 0x32) == 3) vol = (DAT_0005ef30 * 0x5a + 0x32) / 100;
    else vol = DAT_0005ef30;
    FUN_000468fd(DAT_0005ee84, DAT_0005ef24, vol, t);
}

/* ---- from build/var/mod/parts/p38ae0.c */
/* FUN_00038ae0 @ 00038ae0: switch to song k: unloaded songs fade in through FUN_000389e4; loaded ones start at the music volume, or from silence fading in over t */
#include "snd.h"
extern void FUN_000468d5(int, int);
#pragma aux FUN_000468d5 modify [eax ebx ecx edx];
extern int DAT_0005ef30;
void FUN_00038ae0(int k, int t)
{
    int vol;
    if (!DAT_0005ee78 || !DAT_0005ef38 || k == DAT_0005ef2c) return;
    FUN_00038ce8();
    DAT_0005ef2c = k;
    DAT_0005ef24 = DAT_0005eefc[k];
    if (DAT_0005ef24 == -1 || k == -1) return;
    if (!DAT_0005ef1c[k]) {
        FUN_000389e4(k, t);
        return;
    }
    B000770f0_a0 = DAT_0005f050;
    if (*(short *)(DAT_0005f050 + 0x32) == 3) vol = (DAT_0005ef30 * 0x5a + 0x32) / 100;
    else vol = DAT_0005ef30;
    FUN_000468fd(DAT_0005ee84, DAT_0005ef24, vol, 0);
    FUN_000468d5(DAT_0005ee84, DAT_0005ef24);
    if (t) {
        FUN_000468fd(DAT_0005ee84, DAT_0005ef24, 0, 0);
        B000770f0_a0 = DAT_0005f050;
        if (*(short *)(DAT_0005f050 + 0x32) == 3) vol = (DAT_0005ef30 * 0x5a + 0x32) / 100;
        else vol = DAT_0005ef30;
        FUN_000468fd(DAT_0005ee84, DAT_0005ef24, vol, t);
        return;
    }
    FUN_00046907(DAT_0005ee84, DAT_0005ef24, DAT_0005ef34, 0);
}

/* ---- from build/var/mod/parts/p38c54.c */
/* FUN_00038c54, FUN_00038e58 @ 00038c54: switch the music/ambient sequence (module compiled without -ot) */
#include "snd.h"
void FUN_00038c54(int a, int b)
{
    int *p;
    if (DAT_0005ee78 && DAT_0005ef38) {
        FUN_00038ce8();
        FUN_00038884();
        if (DAT_0005ef28 != a) {
            if (*(short *)(DAT_0005f050 + 0x32) == 3 || *(short *)(DAT_0005f050 + 0x32) == 4) p = FUN_0003f29c(a + DAT_0005ee7c, DAT_0005ee74);
            else p = FUN_0003f29c(a, DAT_0005ee74);
            memmove(DAT_0005ee90, p + 1, *p);
            DAT_0005ef28 = a;
        }
        FUN_000388fc(b);
    }
}

/* ---- from build/var/mod/parts/p38ce8.c */
extern void FUN_0003878c(int k); /* module prototype */
/* FUN_00038ce8 @ 00038ce8: stop the current song: halt it, switch to the silent sequence 0 and wait until it has started */
extern int FUN_000468df(int, int); extern void FUN_000468cb(int, int), FUN_000468c1(int, int), FUN_000468fd(int, int, int, int), FUN_00046907(int, int, int, int);
#pragma aux FUN_000468df modify [eax ebx ecx edx];
#pragma aux FUN_000468cb modify [eax ebx ecx edx];
#pragma aux FUN_000468c1 modify [eax ebx ecx edx];
#pragma aux FUN_000468fd modify [eax ebx ecx edx];
#pragma aux FUN_00046907 modify [eax ebx ecx edx];
extern int DAT_0005ee78, DAT_0005ef2c, DAT_0005ef24, DAT_0005ee84, DAT_0005ef34, DAT_0005ef30, DAT_0005eefc[];
void FUN_00038ce8(void)
{
    int st;
    if (!DAT_0005ee78 || DAT_0005ef2c == -1) return;
    st = FUN_000468df(DAT_0005ee84, DAT_0005ef24);
    if (st != 0 && st != 2) FUN_000468cb(DAT_0005ee84, DAT_0005ef24);
    FUN_0003878c(0);
    DAT_0005ef2c = 0;
    DAT_0005ef24 = DAT_0005eefc[0];
    if (DAT_0005ef24 != -1) {
        FUN_000468fd(DAT_0005ee84, DAT_0005ef24, 0, 0);
        FUN_00046907(DAT_0005ee84, DAT_0005ef24, DAT_0005ef34, 0);
        FUN_000468c1(DAT_0005ee84, DAT_0005ef24);
        while (FUN_000468df(DAT_0005ee84, DAT_0005ef24) != 2) ;
    }
    DAT_0005ef2c = -1;
    DAT_0005ef24 = -1;
}

/* ---- from build/var/mod/parts/p38dcc.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);

void FUN_00038dcc(int a)
{
    if (DAT_0005ee78 && DAT_0005ef2c != -1) {
        int st = FUN_000468df(DAT_0005ee84, DAT_0005ef24);
        if (st == 0 || st == 2) { DAT_0005ef24 = -1; DAT_0005ef2c = -1; }
        else FUN_000468fd(DAT_0005ee84, DAT_0005ef24, 0, a);
    }
}

/* ---- from build/var/mod/parts/p38e30.c */
extern void FUN_000389e4(int k, int t); /* module prototype */
extern void FUN_00038ce8(void); /* module prototype */
/* FUN_00038e30 @ 00038e30: stop the current song and fade in song k over t */
extern int DAT_0005ee78; extern unsigned char DAT_0005ef38; 
void FUN_00038e30(int k, int t)
{
    if (DAT_0005ee78 && DAT_0005ef38) {
        FUN_00038ce8();
        FUN_000389e4(k, t);
    }
}

/* ---- from build/var/mod/parts/p38e58.c */
void FUN_00038e58(int a, int b, int c)
{
    int *p;
    if (DAT_0005ee78 && DAT_0005ef38) {
        FUN_00038ce8();
        FUN_00038884();
        if (DAT_0005ef28 != a) {
            if (*(short *)(DAT_0005f050 + 0x32) == 3 || *(short *)(DAT_0005f050 + 0x32) == 4) p = FUN_0003f29c(a + DAT_0005ee7c, DAT_0005ee74);
            else p = FUN_0003f29c(a, DAT_0005ee74);
            memmove(DAT_0005ee90, p + 1, *p);
            DAT_0005ef28 = a;
        }
        FUN_000389e4(b, c);
    }
}

/* ---- from build/var/mod/parts/p38ef0.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);

void FUN_00038ef0(void)
{
    if (DAT_0005ee78 && DAT_0005ef2c != -1) {
        int st = FUN_000468df(DAT_0005ee84, DAT_0005ef24);
        if (st == 0 || st == 2) { DAT_0005ef2c = -1; DAT_0005ef24 = -1; return; }
        while (FUN_000468e9(DAT_0005ee84, DAT_0005ef24)) ;
        FUN_00038ce8();
    }
}

/* ---- from build/var/mod/parts/p38f58.c */
/* FUN_00038f58 @ 00038f58: set the music volume v; tell the driver when music is playing (scaled to 90% on driver type 3) */
#include "snd.h"
extern int DAT_0005ef30, DAT_0005ee78, DAT_0005ef2c, DAT_0005ef24, DAT_0005ee84;
void FUN_00038f58(int v)
{
    int vol;
    if (DAT_0005ef30 == v) return;
    DAT_0005ef30 = v;
    if (DAT_0005ee78 && DAT_0005ef2c != -1 && FUN_000468e9(DAT_0005ee84, DAT_0005ef24) == 0x64) {
        B000770f0_a0 = DAT_0005f050;
        if (*(short *)(DAT_0005f050 + 0x32) == 3) vol = (DAT_0005ef30 * 0x5a + 0x32) / 100;
        else vol = DAT_0005ef30;
        FUN_000468fd(DAT_0005ee84, DAT_0005ef24, vol, 0);
    }
}

/* ---- from build/var/mod/parts/p39008.c */
/* Sound interface wrappers: FUN_00037ecc, FUN_00037ff0, FUN_000380e8, FUN_00038098, FUN_00039008, FUN_00037f24 (music start: the CODE.2 copy of CODE.1 FUN_0001c4e0, FUN_00037ff0 expanded inline) */
#include "snd.h"
#include <string.h>
extern void FUN_000467f9(int, void __far *, int), FUN_000467ef(int, void __far *, int, int), FUN_0004680d(int);
#pragma aux FUN_000467f9 modify [eax ebx ecx edx];
#pragma aux FUN_000467ef modify [eax ebx ecx edx];
#pragma aux FUN_0004680d modify [eax ebx ecx edx];
extern void *DAT_0005ee60; extern int DAT_0005ee64, DAT_0005ee44;
void FUN_00037f24(int);

void FUN_00039008(int v)
{
    if (v != DAT_0005ef34) {
        DAT_0005ef34 = v;
        if (DAT_0005ee78 && DAT_0005ef2c != -1) FUN_00046907(DAT_0005ee84, DAT_0005ef24, v, 0);
    }
}

/* ---- from build/var/mod/parts/p39048.c */
/* FUN_00039048 @ 00039048: getter */
extern int DAT_0005ef2c;
int FUN_00039048(void) { return DAT_0005ef2c; }

/* ---- from build/var/mod/parts/p39050.c */
/* FUN_00039050 @ 00039050: getter */
extern int DAT_0005ef28;
int FUN_00039050(void) { return DAT_0005ef28; }

/* ---- from build/var/mod/parts/p39058.c */
/* FUN_00039058 @ 00039058: 1 while the current song is playing or paused */
#include "snd.h"
int FUN_00039058(void)
{
    int r = 0;
    if (DAT_0005ee78 && DAT_0005ef2c != -1) {
        r = FUN_000468df(DAT_0005ee84, DAT_0005ef24);
        if (r == 0 || r == 2) r = 1;
    }
    return r;
}

/* ---- from build/var/mod/parts/p39098.c */
/* FUN_00039098 @ 00039098: getter */
extern int DAT_0005ef34;
int FUN_00039098(void) { return DAT_0005ef34; }

/* ---- from build/var/mod/parts/p390a0.c */
/* FUN_000390a0 @ 000390a0: getter */
extern int DAT_0005ef30;
int FUN_000390a0(void) { return DAT_0005ef30; }

/* ---- from build/var/mod/parts/p390a8.c */
extern void FUN_00038ce8(void); /* module prototype */
/* FUN_000390a8 @ 000390a8: set the music flag; stop the music when it is switched off while playing */
extern unsigned char DAT_0005ef38; extern int DAT_0005ee78; 
void FUN_000390a8(int on) { DAT_0005ef38 = on; if (DAT_0005ee78 && !(unsigned char)on) FUN_00038ce8(); }

/* ---- module data _DATA 0005ee74-0005ef3c (docs/data/dataown.CODE2.csv: certain (ref; some shared)), generated by tools/data2c.py */
int DAT_0005ee74 = 0;
int DAT_0005ee78 = 0;
int DAT_0005ee7c = 0;
int DAT_0005ee80 = 0;
int DAT_0005ee84 = 0;
unsigned char DAT_0005ee88 = 0;
unsigned char DAT_0005ee89[3] = { 0x65, 0x5f, 0x63 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
void *DAT_0005ee8c = 0;
void *DAT_0005ee90 = 0;
int DAT_0005ee94 = 0;
unsigned short DAT_0005ee98 = 0;
unsigned char DAT_0005ee9a[2] = { 0x65, 0x64 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
void *DAT_0005ee9c[8] = { 0 };
int DAT_0005eebc[8] = { 0 };
unsigned short DAT_0005eedc[8] = { 0 };
void *DAT_0005eeec = 0;
int DAT_0005eef0 = 0;
unsigned short DAT_0005eef4 = 0;
unsigned char DAT_0005eef6[2] = { 0, 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_0005eef8 = 0;
int DAT_0005eefc[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
unsigned char DAT_0005ef1c[8] = { 0 };
int DAT_0005ef24 = -1;
int DAT_0005ef28 = -1;
int DAT_0005ef2c = -1;
int DAT_0005ef30 = 0x64;
int DAT_0005ef34 = 0x64;
unsigned char DAT_0005ef38 = 1;
/* ---- end of module data _DATA */
