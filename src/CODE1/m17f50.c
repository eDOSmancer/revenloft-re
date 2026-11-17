/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
volatile unsigned char B000389d0_eu[24];
/* BSS end */
/* Module: FUN_00017f50, LAB_00017f5c, FUN_00017f8c, FUN_00017fa8, FUN_0001802c, FUN_0001808c, FUN_000180bc, FUN_00018270, FUN_00018278, FUN_0001828c, FUN_000182a4, FUN_000182c0, FUN_000182ec, FUN_00018304, FUN_0001831c, LAB_00018338, FUN_00018398, FUN_00018424, FUN_00018484 */
#include "vmode.h"
#define DAT_000323d7 (VID_000323d4.w)
/* ---- from build/var/mod/parts/p17f50.c */
/* FUN_00017f50 */
extern volatile int DAT_00032934;
unsigned FUN_00017f50(void) { return DAT_00032934; }

/* ---- from build/var/mod/parts/p17f5c.c */
/* LAB_00017f5c @ 00017f5c: timer interrupt (IRQ0) handler: count the tick, run the per-tick routine and chain to the old handler */

extern void (__interrupt __far *DAT_0003292a)();
extern void FUN_0001dde0(void);
void __interrupt __far LAB_00017f5c(void)
{
    DAT_00032934++;
    FUN_0001dde0();
    (*DAT_0003292a)();
}

/* ---- from build/var/mod/parts/p17f8c.c */
/* FUN_00017f8c: set the timer tick counter with interrupts off */
extern void _disable(void), _enable(void);
void FUN_00017f8c(int v) { _disable(); DAT_00032934 = v; _enable(); }

/* ---- from build/var/mod/parts/p17fa8.c */
/* FUN_00017fa8 */
void *memmove(void *, const void *, unsigned); extern volatile unsigned char DAT_00032930, DAT_0003291a, DAT_00032919, B000389d0_eu[], B000389cf_eu[];
void FUN_00017fa8(int k) { int i; for (i = 0; i < DAT_00032930; i++) if (B000389d0_eu[i] == k) { memmove((void *)&B000389d0_eu[i], (void *)&B000389d0_eu[i + 1], DAT_00032930 - i - 1); DAT_00032930--; break; } if (!DAT_00032930) DAT_0003291a = 0; else DAT_0003291a = B000389cf_eu[DAT_00032930]; DAT_00032919 = DAT_0003291a; }

/* ---- from build/var/mod/parts/p1802c.c */
/* FUN_0001802c */
extern void FUN_00017fa8(int); extern volatile unsigned char DAT_00032930, DAT_0003291a, DAT_00032919, B000389d0_eu[];
void FUN_0001802c(int k) { int i; for (i = 0; i < DAT_00032930; i++) if (B000389d0_eu[i] == k) { FUN_00017fa8(k); break; } B000389d0_eu[DAT_00032930] = k; DAT_00032930++; DAT_0003291a = k; DAT_00032919 = DAT_0003291a; }

/* ---- from build/var/mod/parts/p1808c.c */

/* FUN_0001808c @ 0001808c: 1 when key code c is in the queued key list */
int FUN_0001808c(int c) { int i; for (i = 0; i < DAT_00032930; i++) if (B000389d0_eu[i] == c) return 1; return 0; }

/* ---- from build/var/mod/parts/p180bc.c */
#include <conio.h>
extern volatile unsigned char DAT_00032918; extern unsigned char DAT_0003291b, DAT_0003291c, DAT_00032b01;
extern void _disable(void), _enable(void), FUN_00017fa8(int), FUN_0001802c(int);
/* FUN_000180bc @ 000180bc: keyboard interrupt handler: read the scan code, acknowledge the keyboard, track the shift/alt/ctrl state and the cursor keys, set the quit (Alt-Q), Esc and space flags */
void __interrupt __far FUN_000180bc(void)
{
    int k;
    k = inp(0x60);
    DAT_00032918 = inp(0x61);
    if (DAT_00032918 == 0x80) {
        DAT_00032918 = inp(0x61);
        DAT_00032918 |= 0x80;
    }
    outp(0x61, DAT_00032918 | 0x80);
    outp(0x61, DAT_00032918);
    _disable();
    if (k > 0x80) {
        k &= 0x7f;
        if (k == 0x2a) DAT_0003291b &= ~1;
        else if (k == 0x36) DAT_0003291b &= ~2;
        else if (k == 0x38) DAT_0003291b &= ~4;
        else if (k == 0x1d) DAT_0003291b &= ~8;
        else if (k >= 0x47 && k <= 0x51) FUN_00017fa8(k);
        else DAT_0003291a = DAT_00032919;
    } else {
        if (k == 0x2a) DAT_0003291b |= 1;
        else if (k == 0x36) DAT_0003291b |= 2;
        else if (k == 0x38) DAT_0003291b |= 4;
        else if (k == 0x1d) DAT_0003291b |= 8;
        else {
            if (k >= 0x47 && k <= 0x51) {
                FUN_0001802c(k);
                DAT_00032919 = k;
            }
            DAT_0003291a = k;
        }
    }
    if (DAT_0003291a == 0x10 && (DAT_0003291b & 4)) {
        DAT_00032b01 |= 1;
        DAT_0003291a = 0;
    } else if (DAT_0003291a == 0x43) DAT_0003291a = 0;
    else if (DAT_0003291a == 1) DAT_00032b01 |= 2;
    else if (DAT_0003291a == 0x39) DAT_0003291c = 1;
    outp(0x20, 0x20);
    _enable();
}

/* ---- from build/var/mod/parts/p18270.c */
/* FUN_00018270 @ 00018270: empty */
void FUN_00018270(void)
{
}

/* ---- from build/var/mod/parts/p18278.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_00018278 @ 00018278 */
int FUN_00018278(int m) { return DAT_0003291b & m; }

/* ---- from build/var/mod/parts/p1828c.c */
extern unsigned char DAT_0003291b, DAT_0003291c; extern char B0003892f_eu[];  extern char *DAT_00032b08;
extern int FUN_0001daa6(void), FUN_000163d8(void), FUN_0001d23a(int, int); extern int FUN_000163b8(int); extern void FUN_0001d9ca(int), FUN_0001a21c(int), FUN_0001d906(char *, int), FUN_0001d8d0(int *), FUN_0001d8e8(int, int *), FUN_0001a2b0(int, int);
/* FUN_0001828c @ 0001828c: fetch and clear the pending key flag */
int FUN_0001828c(void) { int v; v = DAT_0003291c; DAT_0003291c = 0; return v; }

/* ---- from build/var/mod/parts/p182a4.c */
/* FUN_000182a4 */
extern void FUN_00019ae8(void);
int FUN_000182a4(void) { FUN_00019ae8(); return DAT_0003291a != 0; }

/* ---- from build/var/mod/parts/p182c0.c */
/* FUN_000182c0 */
extern void FUN_00019ae8(void); extern int DAT_00032938[];
int FUN_000182c0(void) { int r; while (!DAT_0003291a) FUN_00019ae8(); r = DAT_00032938[DAT_0003291a]; DAT_0003291a = 0; return r; }

/* ---- from build/var/mod/parts/p182ec.c */
struct SB { short size; unsigned short n; };
extern unsigned char DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_000182ec @ 000182ec */
void FUN_000182ec(void) { DAT_00032930 = 0; DAT_00032919 = 0; }

/* ---- from build/var/mod/parts/p18304.c */
#define SB T13_SB
struct SB { short size; unsigned short n; };
extern unsigned char DAT_0003291c; extern char B00038904_eu[], DAT_00038922[];
extern void FUN_0001a5c8(int, struct SB *), FUN_0001a678(int, struct SB *), FUN_0001ae0c(int, int, struct SB *), FUN_0001a05c(int, int, int, int, int), FUN_0001a7e8(int, int, int, int, int), FUN_00018960(void);
extern int FUN_0001d280(int, int, char *);
/* FUN_00018304 @ 00018304 */
void FUN_00018304(void) { DAT_0003291a = DAT_00032919; DAT_0003291c = 0; }

#undef SB
/* ---- from build/var/mod/parts/p1831c.c */
/* FUN_0001831c */
extern void FUN_00019ae8(void); extern int DAT_00032938[];
int FUN_0001831c(void) { FUN_00019ae8(); return DAT_00032938[DAT_0003291a]; }

/* ---- from build/var/mod/parts/p18338.c */
/* LAB_00018338 @ 00018338: divide error handler: shut down, put the keyboard and timer vectors back and chain to the old handler */
#include <dos.h>
extern void (__interrupt __far *DAT_0003291e)(), (__interrupt __far *DAT_0003292a)(), (__interrupt __far *DAT_00032924)();
extern void FUN_000164dc(int), FUN_0001cf98(void);
void __interrupt __far LAB_00018338(void)
{
    FUN_000164dc(0xff);
    FUN_0001cf98();
    _dos_setvect(9, DAT_0003291e);
    _dos_setvect(8, DAT_0003292a);
    (*DAT_00032924)();
}

/* ---- from build/var/mod/parts/p18398.c */
/* FUN_00018398 */
#include <dos.h>
extern unsigned char DAT_0003291d; extern void (__interrupt __far *DAT_0003291e)();
extern void (__interrupt __far *DAT_0003292a)();
extern void (__interrupt __far *DAT_00032924)();
extern void __interrupt __far FUN_000180bc();
extern void __interrupt __far LAB_00017f5c();
extern void __interrupt __far LAB_00018338();
void FUN_00018398(void) { if (!DAT_0003291d) { DAT_0003291e = _dos_getvect(9); _dos_setvect(9, FUN_000180bc); DAT_0003292a = _dos_getvect(8); _dos_setvect(8, LAB_00017f5c); DAT_00032924 = _dos_getvect(0); _dos_setvect(0, LAB_00018338); DAT_0003291d = 1; } }

/* ---- from build/var/mod/parts/p18424.c */
/* FUN_00018424 */
#include <dos.h>
extern unsigned char DAT_0003291d; extern void (__interrupt __far *DAT_0003291e)();
extern void (__interrupt __far *DAT_0003292a)();
extern void (__interrupt __far *DAT_00032924)();
void FUN_00018424(void) { if (DAT_0003291d) { _dos_setvect(9, DAT_0003291e); _dos_setvect(8, DAT_0003292a); _dos_setvect(0, DAT_00032924); DAT_0003291d = 0; } }

/* ---- from build/var/mod/parts/p18484.c */
extern unsigned char B00038919_eu, DAT_0003291d, DAT_00032b01; extern int DAT_00032b1c, DAT_00032b18;
extern void FUN_0001a21c(int), FUN_00019ae8(void), FUN_0001da6c(int);
/* FUN_00018484 @ 00018484 */
int FUN_00018484(void) { return DAT_0003291d; }

/* ---- module data _DATA 00032918-00032a9c (docs/data/dataown.CODE1.csv: inferred), generated by tools/data2c.py */
volatile unsigned char DAT_00032918 = 0;
volatile unsigned char DAT_00032919 = 0;
volatile unsigned char DAT_0003291a = 0;
unsigned char DAT_0003291b = 0;
unsigned char DAT_0003291c = 0;
unsigned char DAT_0003291d = 0;
void (__interrupt __far *DAT_0003291e)() = 0;
void (__interrupt __far *DAT_00032924)() = 0;
void (__interrupt __far *DAT_0003292a)() = 0;
volatile unsigned char DAT_00032930 = 0;
unsigned char DAT_00032931[3] = { 0x55, 0x49, 0x20 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
volatile int DAT_00032934 = 0;
int DAT_00032938[89] = {
    0, 0x1b, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 8, 9,
    0x51, 0x57, 0x45, 0x52, 0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0xd, 0x11d, 0x41, 0x53,
    0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3b, 0x27, 0x60, 0x12a, 0x5c, 0x5a, 0x58, 0x43, 0x56,
    0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x136, 0x2a, 0x138, 0x20, 0x13a, 0x13b, 0x13c, 0x13d, 0x13e, 0x13f,
    0x140, 0x141, 0x142, 0x143, 0x144, 0x145, 0x146, 0x147, 0x148, 0x149, 0x14a, 0x14b, 0x14c, 0x14d, 0x14e, 0x14f,
    0x150, 0x151, 0x152, 0x153, 0, 0x154, 0, 0x157, 0x158
};
/* ---- end of module data _DATA */
