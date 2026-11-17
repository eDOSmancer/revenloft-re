/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
short B0007b7ae_hb;
short B0007b7ac_kp;
short B0007b7aa_kn;   /* no code references it */
short B0007b7a8_b6;
short B0007b7a6_c4;
short B0007b7a4_c2;
short B0007b7a2_c0;
struct RMI B0007b770_gl;
/* BSS end */
/* Module: FUN_00043aa0, FUN_00043af4, FUN_00043b44, FUN_00043c90, FUN_00043cb0, FUN_00043d18, FUN_00043d38, FUN_00043d58, FUN_00043d78 */
/* ---- from build/var/mod/parts/p43aa0.c */
/* FUN_00043aa0 @ 00043aa0: issue real-mode int 33h through DPMI 0300h with the call structure at rmregs */
extern int FUN_00040de8(int);
#include <i86.h>
#include <string.h>
#include <stdlib.h>
void FUN_00043aa0(void *rmregs)
{
    union REGS r; struct SREGS s;
    memset(&s, 0, sizeof s);
    r.x.eax = 0x300;
    r.x.ebx = 0x33;
    r.x.ecx = 0;
    { void __far *fp = rmregs; r.x.edi = FP_OFF(fp); s.es = FP_SEG(fp); }   /* the far pointer object is what makes this file's _BSS paragraph-aligned (docs/BSS.md) */
    int386x(0x31, &r, &r, &s);
}

/* ---- from build/var/mod/parts/p43af4.c */
/* FUN_00043af4 @ 00043af4: real-mode INT 15h AX=53C1h (APM) through the DPMI call block; true when AX comes back 1 */
void *memset(void *, int, unsigned); extern void FUN_00043aa0(void *); extern unsigned DAT_0005fd14;
struct RMI { int edi, esi, ebp, res, ebx, edx, ecx, eax; short flags, es, ds, fs, gs, ip, cs, sp, ss; };
extern struct RMI B0007b770_gl;
int FUN_00043af4(void)
{
    memset(&B0007b770_gl, 0, 0x32);
    B0007b770_gl.eax = 0x53c1;
    B0007b770_gl.edx = 0;
    B0007b770_gl.es = DAT_0005fd14 >> 16;
    FUN_00043aa0(&B0007b770_gl);
    return B0007b770_gl.eax == 1;
}

/* ---- from build/var/mod/parts/p43b44.c */
/* FUN_00043b44 .. FUN_00043cb0: mouse driver reset and status (int 33h), twins of CODE.1 FUN_0001cf98 and
   FUN_0001d0b4. The moves between the driver's registers and the locals are byte-coded in the pragmas (32-bit
   displacement forms); "modify [esp]" gives the ebp frame; the locals the inline code writes are volatile. */
extern short B0007b7a2_c0, B0007b7a4_c2, B0007b7a6_c4, B0007b7a8_b6, B0007b7ac_kp, B0007b7ae_hb;
extern unsigned char *DAT_0005fd10; extern unsigned short DAT_0005fd18;
extern int DAT_0005ee78, DAT_0005ee40;
extern struct CFG { char pad[8]; short f8; char pad2[0xa]; short f14; } *DAT_0005f050;
extern void *FUN_00040d80(int, int *, unsigned short *); extern void FUN_000411e8(char *);
extern int FUN_00043af4(void), FUN_0003e340(void);
extern void FUN_00037ecc(void), FUN_000385d4(void), FUN_000462be(int), FUN_00040c38(void);
void ms_reset(void);
#pragma aux ms_reset = "mov eax, 0" "int 33h" 0x89 0x85 0xfc 0xff 0xff 0xff 0x89 0x9d 0xf8 0xff 0xff 0xff modify [eax ebx esp];

/* FUN_00043b44: reset the mouse driver; without a mouse print the message and quit */
short *FUN_00043b44(void)
{
    volatile int ax, bx;
    ax = bx = 0;
    ms_reset();
    B0007b7a2_c0 = ax;
    B0007b7a4_c2 = bx;
    B0007b7a6_c4 = 0;
    if (B0007b7a2_c0) {
        if ((DAT_0005fd10 = FUN_00040d80(0x40, (int *)&DAT_0005fd14, &DAT_0005fd18)) != 0) {
            if (FUN_00043af4()) B0007b7a6_c4 = *DAT_0005fd10;
            if (!B0007b7a6_c4) FUN_00040de8(DAT_0005fd18);
        }
    } else {
        struct CFG *cfg;
        FUN_000411e8("No Mouse Installed.  Ravenloft requires a mouse to run.\r\n");
        cfg = DAT_0005f050;
        ax = DAT_0005ee78 | DAT_0005ee40;
        if (cfg->f8 != 0x71) {
            if (cfg->f14) FUN_00037ecc();
            FUN_000385d4();
            if (ax) FUN_000462be(0);
        }
        FUN_00040c38();
        exit(1);
    }
    return &B0007b7a2_c0;
}

/* ---- from build/var/mod/parts/p43c90.c */
extern int FUN_0003e340(void); extern short B0007b7a8_b6, B0007b7ac_kp, B0007b7ae_hb;
void mouse_setpos(int x, int y);
#pragma aux mouse_setpos = 0xb8 0x04 0x00 0x00 0x00 0x31 0xdb 0x01 0xc9 0xcd 0x33 parm [edx] [ecx] modify [eax ebx];
/* FUN_00043c90 @ 00043c90: put the mouse cursor at (x, y) (when a mouse is present) */
void FUN_00043c90(int x, int y) { if (FUN_0003e340()) mouse_setpos(x, y); }

/* ---- from build/var/mod/parts/p43cb0.c */
/* FUN_00043cb0 @ 00043cb0: read buttons and position into B0007b7a8_b6 (buttons), B0007b7ac_kp (x / 2),
   B0007b7ae_hb (y); see f43b44.c for the pragma conventions. The short casts are what keep it from being
   expanded inline into FUN_00043d58/FUN_00043d78 (21 expression nodes, over the -oe threshold of 20) */
extern short B0007b7a8_b6, B0007b7ac_kp, B0007b7ae_hb; extern int FUN_0003e340(void);
void ms_status(void);
#pragma aux ms_status = "mov eax, 3" "int 33h" 0x66 0x89 0x9d 0xf4 0xff 0xff 0xff 0x66 0x89 0x95 0xf8 0xff 0xff 0xff 0x66 0x89 0x8d 0xfc 0xff 0xff 0xff modify [eax ebx ecx edx esp];
short *FUN_00043cb0(void)
{
    volatile int cx, dy, bx;
    bx = dy = cx = 0;
    if (FUN_0003e340()) {
        ms_status();
        B0007b7a8_b6 = (short)bx;
        B0007b7ae_hb = (short)dy;
        B0007b7ac_kp = (short)((short)cx >> 1);
    }
    return &B0007b7a8_b6;
}

/* ---- from build/var/mod/parts/p43d18.c */
/* Module: FUN_00043d18, FUN_00043d38, FUN_00043d58, FUN_00043d78 */
/* ---- from build/var/mod/parts/p43d18.c */
extern int FUN_0003e340(void);
void mouse_xrange(int lo, int hi);
#pragma aux mouse_xrange = 0xb8 0x07 0x00 0x00 0x00 0x31 0xdb 0xcd 0x33 parm [ecx] [edx] modify [eax ebx];
void mouse_yrange(int lo, int hi);
#pragma aux mouse_yrange = 0xb8 0x08 0x00 0x00 0x00 0x31 0xdb 0xcd 0x33 parm [ecx] [edx] modify [eax ebx];
/* FUN_00043d18 @ 00043d18: limit the mouse x range to lo..hi (when a mouse is present) */
void FUN_00043d18(int lo, int hi) { if (FUN_0003e340()) mouse_xrange(lo, hi); }

/* ---- from build/var/mod/parts/p43d38.c */
/* ---- from build/var/mod/parts/p43d38.c */
/* FUN_00043d38 @ 00043d38: limit the mouse y range */
void FUN_00043d38(int lo, int hi) { if (FUN_0003e340()) mouse_yrange(lo, hi); }

/* ---- from build/var/mod/parts/p43d58.c */
/* ---- from build/var/mod/parts/p43d58.c */
/* FUN_00043d58 @ 00043d58: wait until the mouse buttons are released */
extern int FUN_0003e340(void); extern short *FUN_00043cb0(void); extern void FUN_0003e758(void);
void FUN_00043d58(void)
{
    short *p;
    if (FUN_0003e340()) {
        do {
            p = FUN_00043cb0();
            FUN_0003e758();
        } while (*p);
    }
}

/* ---- from build/var/mod/parts/p43d78.c */
/* ---- from build/var/mod/parts/p43d78.c */
/* FUN_00043d78 @ 00043d78: wait for a mouse click or a key (just a key without a mouse) */
extern int FUN_0003e340(void), FUN_00040ad8(void), FUN_00040aec(void); extern short *FUN_00043cb0(void); extern void FUN_0003e758(void), FUN_00040b1c(void), FUN_00040b2c(void);
void FUN_00043d78(void)
{
    short *p;
    if (FUN_0003e340()) {
        do {
            p = FUN_00043cb0();
            FUN_0003e758();
        } while (*p);
        while (!FUN_00040ad8() && !*FUN_00043cb0()) FUN_0003e758();
        if (FUN_00040ad8()) {
            FUN_00040b1c();
            FUN_00040b2c();
        } else {
            do FUN_0003e758(); while (*FUN_00043cb0());
        }
    } else FUN_00040aec();
}

/* ---- module data _DATA 0005fd10-0005fd20 (docs/data/dataown.CODE2.csv: certain), generated by tools/data2c.py */
unsigned char *DAT_0005fd10 = 0;
unsigned DAT_0005fd14 = 0;
unsigned short DAT_0005fd18 = 0;
unsigned char DAT_0005fd1a[6] = { 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
