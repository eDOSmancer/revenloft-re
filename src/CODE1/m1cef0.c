/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
short B00038a66_eu;
short B00038a64_eu;
unsigned char F00038a60_eu[2];
short B00038a60_eu;
short B00038a5e_eu;
short B00038a5c_eu;
short B00038a5a_eu;
struct RMI B00038a28_eu;
/* BSS end */
/* Module: FUN_0001cef0, FUN_0001cf44, FUN_0001cf98, FUN_0001d08c, FUN_0001d0b4, FUN_0001d10c, FUN_0001d130, FUN_0001d154, FUN_0001d17c */
#include <stdlib.h>
/* ---- from build/var/mod/parts/p1cef0.c */
/* FUN_0001cef0 @ 0001cef0 (twin of CODE.2 FUN_0001cef0): issue real-mode int 33h through DPMI 0300h with the call structure at rmregs */
#include <i86.h>
#include <string.h>
void FUN_0001cef0(void *rmregs)
{
    union REGS r; struct SREGS s;
    memset(&s, 0, sizeof s);
    r.x.eax = 0x300;
    r.x.ebx = 0x33;
    r.x.ecx = 0;
    r.x.edi = (unsigned)rmregs;
    s.es = FP_SEG((void __far *)rmregs);
    int386x(0x31, &r, &r, &s);
}

/* ---- from build/var/mod/parts/p1cf44.c */
/* FUN_0001cf44 */
void *memset(void *, int, unsigned); extern void FUN_0001cef0(void *);
unsigned char *DAT_000330a4 = 0; unsigned DAT_000330a8 = 0; unsigned short DAT_000330ac = 0;
struct RMI { int edi, esi, ebp, res, ebx, edx, ecx, eax; short flags, es, ds, fs, gs, ip, cs, sp, ss; };
extern struct RMI B00038a28_eu;
int FUN_0001cf44(void) { memset(&B00038a28_eu, 0, 0x32); B00038a28_eu.eax = 0x53c1; B00038a28_eu.es = DAT_000330a8 >> 16; B00038a28_eu.edx = 0; FUN_0001cef0(&B00038a28_eu); return B00038a28_eu.eax == 1; }

/* ---- from build/var/mod/parts/p1cf98.c */
/* FUN_0001cf98 .. FUN_0001d17c @ 0001cf98: mouse driver interface (int 33h). Each call is inline machine code
   (#pragma aux); the moves between the driver's registers and the C parameters/locals are coded as bytes,
   because the original has the 32-bit displacement forms, which the pragma assembler does not produce. */
extern short B00038a5a_eu, B00038a5c_eu, B00038a5e_eu, B00038a60_eu, B00038a64_eu, B00038a66_eu;
extern int DAT_00032b84, DAT_00032f48;
extern struct SNDCFG { char pad[8]; short f8; char pad2[0xa]; short f14; } *DAT_00032aa0;
extern void *FUN_00016f10(int, int *, unsigned short *); extern void FUN_00016f74(int), FUN_000161d0(char *);
extern int FUN_0001cf44(void); extern void FUN_0001c4a0(void), FUN_0001b430(void), FUN_0001e6ea(int), FUN_00018424(void);
extern int FUN_000184d0(void); extern void FUN_00018960(void), FUN_000182ec(void), FUN_00018304(void), FUN_000182c0(void); extern int FUN_000182a4(void);
void ms_reset(void);
#pragma aux ms_reset = "mov eax, 0" "int 33h" 0x89 0x85 0xf8 0xff 0xff 0xff 0x89 0x9d 0xf4 0xff 0xff 0xff modify [eax ebx];
void ms_setpos(void);
#pragma aux ms_setpos = 0x8b 0x95 0x08 0x00 0x00 0x00 0x8b 0x8d 0x0c 0x00 0x00 0x00 "shl ecx, 1" "mov eax, 4" "int 33h" modify [eax ecx edx];
void ms_status(void);
#pragma aux ms_status = "mov eax, 3" "int 33h" 0x66 0x89 0x9d 0xf0 0xff 0xff 0xff 0x66 0x89 0x95 0xf8 0xff 0xff 0xff 0x66 0x89 0x8d 0xf4 0xff 0xff 0xff modify [eax ebx ecx edx];
void ms_xrange(void);
#pragma aux ms_xrange = 0x8b 0x8d 0x08 0x00 0x00 0x00 0x8b 0x95 0x0c 0x00 0x00 0x00 "mov eax, 7" "int 33h" modify [eax ecx edx];
void ms_yrange(void);
#pragma aux ms_yrange = 0x8b 0x8d 0x08 0x00 0x00 0x00 0x8b 0x95 0x0c 0x00 0x00 0x00 "mov eax, 8" "int 33h" modify [eax ecx edx];

/* FUN_0001cf98: reset the mouse driver; without a mouse print the message and quit */
short *FUN_0001cf98(void)
{
    volatile int ax, bx; struct SNDCFG *cfg;
    ms_reset();
    B00038a5a_eu = ax;
    B00038a5c_eu = bx;
    B00038a5e_eu = 0;
    if (B00038a5a_eu) {
        if ((DAT_000330a4 = FUN_00016f10(0x40, (int *)&DAT_000330a8, &DAT_000330ac)) != 0) {
            if (FUN_0001cf44()) B00038a5e_eu = *DAT_000330a4;
            if (!B00038a5e_eu) FUN_00016f74(DAT_000330ac);
        }
    } else {
        FUN_000161d0("No Mouse Installed.  Ravenloft requires a mouse to run.\r\n");
        cfg = DAT_00032aa0;
        ax = DAT_00032b84 | DAT_00032f48;
        if (cfg->f8 != 0x71) {
            if (cfg->f14) FUN_0001c4a0();
            FUN_0001b430();
            if (ax) FUN_0001e6ea(0);
        }
        FUN_00018424();
        exit(1);
    }
    return &B00038a5a_eu;
}

/* ---- from build/var/mod/parts/p1d08c.c */
/* FUN_0001d08c: move the mouse pointer to (x, y); y is in half lines for the driver */
void FUN_0001d08c(int x, int y)
{
    if (FUN_000184d0()) ms_setpos();
}

/* ---- from build/var/mod/parts/p1d0b4.c */
/* FUN_0001d0b4: read buttons and position into B00038a60_eu (buttons), B00038a64_eu (x / 2), B00038a66_eu (y) */
short *FUN_0001d0b4(void)
{
    volatile int dy, cx, bx;
    if (FUN_000184d0()) {
        ms_status();
        B00038a60_eu = bx;
        B00038a66_eu = dy;
        B00038a64_eu = (short)cx >> 1;
    }
    return &B00038a60_eu;
}

/* ---- from build/var/mod/parts/p1d10c.c */
/* FUN_0001d10c / FUN_0001d130: horizontal and vertical range of the pointer */
void FUN_0001d10c(int lo, int hi)
{
    if (FUN_000184d0()) ms_xrange();
}

/* ---- from build/var/mod/parts/p1d130.c */
void FUN_0001d130(int lo, int hi)
{
    if (FUN_000184d0()) ms_yrange();
}

/* ---- from build/var/mod/parts/p1d154.c */
/* FUN_0001d154: wait until all mouse buttons are released */
void FUN_0001d154(void)
{
    short *m;
    if (FUN_000184d0()) do { m = FUN_0001d0b4(); FUN_00018960(); } while (*m);
}

/* ---- from build/var/mod/parts/p1d17c.c */
/* FUN_0001d17c: wait for a click or a key (released buttons first); without a mouse wait for a key */
void FUN_0001d17c(void)
{
    short *m;
    if (FUN_000184d0()) {
        do { m = FUN_0001d0b4(); FUN_00018960(); } while (*m);
        while (!FUN_000182a4() && !*FUN_0001d0b4()) FUN_00018960();
        if (FUN_000182a4()) { FUN_000182ec(); FUN_00018304(); }
        else do FUN_00018960(); while (*FUN_0001d0b4());
    } else FUN_000182c0();
}

