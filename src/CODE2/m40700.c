/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
unsigned char B0007b6c4_dQ[12];
/* BSS end */
/* Module: FUN_00040700, LAB_00040708, FUN_00040738, FUN_00040748, FUN_000407f0, FUN_000408bc, FUN_000408f4,
   LAB_000408f8, FUN_00040abc, FUN_00040ac8, FUN_00040ad8, FUN_00040aec, FUN_00040b1c, FUN_00040b2c,
   FUN_00040b40, LAB_00040b54, FUN_00040bb4, FUN_00040c38, FUN_00040c94 */
/* ---- from build/var/mod/parts/p40700.c */
/* FUN_00040700 @ 00040700: getter */
extern volatile int DAT_0005f58c;
int FUN_00040700(void) { return DAT_0005f58c; }

/* ---- from build/var/mod/parts/p40708.c */
/* LAB_00040708 @ 00040708: timer interrupt (IRQ0) handler: count the tick, run the per-tick routine and chain to the old handler */
extern volatile int DAT_0005f58c;
extern void (__interrupt __far *DAT_0005f582)();
extern void FUN_00029c80(void);
void __interrupt __far LAB_00040708(void)
{
    DAT_0005f58c++;
    FUN_00029c80();
    (*DAT_0005f582)();
}

/* ---- from build/var/mod/parts/p40738.c */
/* FUN_00040738 @ 00040738: set DAT_0005f58c with interrupts disabled (_enable emits sti; cld) */
#include <i86.h>
extern volatile int DAT_0005f58c;
void FUN_00040738(int v) { _disable(); DAT_0005f58c = v; _enable(); }

/* ---- from build/var/mod/parts/p40748.c */
/* FUN_00040748, FUN_000407f0: remove / add a key in the pressed-key list (the key count and the current key are volatile: the keyboard interrupt updates them); FUN_000407f0 also turns cursor keys into a move direction */
void *memmove(void *, const void *, unsigned);
extern volatile unsigned char DAT_0005f588;
extern volatile unsigned char DAT_0005f572; extern unsigned char DAT_0005f571, B0007b6c4_dQ[12], B0007b6c3_dR[];
void FUN_00040748(int key)
{
    int k;
    for (k = 0; k < DAT_0005f588; k++) {
        if (B0007b6c4_dQ[k] == key) {
            memmove(&B0007b6c4_dQ[k], &B0007b6c4_dQ[k + 1], DAT_0005f588 - k - 1);
            DAT_0005f588--;
            break;
        }
    }
    if (DAT_0005f588 == 0) DAT_0005f572 = 0;
    else DAT_0005f572 = B0007b6c3_dR[DAT_0005f588];
    DAT_0005f571 = DAT_0005f572;
}

extern volatile unsigned char DAT_0005f588;
extern volatile unsigned char DAT_0005f572; extern unsigned char DAT_0005f571, B0007b6c4_dQ[12], B0007b6c3_dR[];

extern short B000758fc_kL, B000758fe_j6;
/* FUN_000407f0 @ 000407f0: add a key to the pressed-key list and turn cursor keys into a move direction (fc) and sense (fe) */
void FUN_000407f0(int key)
{
    int k;
    for (k = 0; k < DAT_0005f588; k++) {
        if (B0007b6c4_dQ[k] == key) {
            FUN_00040748(key);
            break;
        }
    }
    B0007b6c4_dQ[DAT_0005f588] = key;
    DAT_0005f588++;
    switch (key) {
    case 0x48: B000758fc_kL = 3; B000758fe_j6 = -1; break;
    case 0x47: B000758fc_kL = 1; B000758fe_j6 = -1; break;
    case 0x49: B000758fc_kL = 1; B000758fe_j6 = 1; break;
    case 0x4b: B000758fc_kL = 2; B000758fe_j6 = -1; break;
    case 0x4d: B000758fc_kL = 2; B000758fe_j6 = 1; break;
    case 0x50: B000758fc_kL = 0; B000758fe_j6 = 1; break;
    }
    DAT_0005f572 = key;
    DAT_0005f571 = DAT_0005f572;
}

/* ---- from build/var/mod/parts/p408bc.c */
#define DAT_0005f588 (*(unsigned char *)&DAT_0005f588)
/* FUN_000408bc @ 000408bc, FUN_000408f4 @ 000408f4 (round 15: the original's `pop ebx; nop; ret` is FUN_000408bc's exit
   falling through the 4-byte procedure alignment into the empty function FUN_000408f4, whose `ret` it shares: 10.0a's
   peephole drops a jump to an identical return sequence that follows; FUN_000408f4 is referenced nowhere in the program) */
extern unsigned char B0007b6c4_dQ[];
int FUN_000408bc(int v)
{
    int i;
    for (i = 0; i < DAT_0005f588; i++) if (B0007b6c4_dQ[i] == v) return 1;
    return 0;
}

extern unsigned char B0007b6c4_dQ[12];


void FUN_000408f4(void)
{
}

#undef DAT_0005f588
/* ---- from build/var/mod/parts/p408f8.c */
extern void FUN_00040748(int key); /* module prototype */
extern void FUN_000407f0(int key); /* module prototype */
/* LAB_000408f8 @ 000408f8: keyboard interrupt (IRQ1) handler: read the scan code, acknowledge it on port 0x61, track shift/ctrl/alt state, keypad keys, the last key, and the Alt+Q / F9 / P / Space hot keys */
#include <conio.h>
#include <i86.h>
extern volatile unsigned char DAT_0005f570; extern volatile unsigned char DAT_0005f572; extern unsigned char DAT_0005f571, DAT_0005f573, DAT_0005f0b1; extern volatile unsigned char DAT_0005f574;
extern volatile short B0006457c_bO;

void __interrupt __far LAB_000408f8(void)
{
    int k;
    k = inp(0x60);
    DAT_0005f570 = inp(0x61);
    if (DAT_0005f570 == 0x80) {
        DAT_0005f570 = inp(0x61);
        DAT_0005f570 |= 0x80;
    }
    outp(0x61, DAT_0005f570 | 0x80);
    outp(0x61, DAT_0005f570);
    _disable();
    if (k > 0x80) {
        k &= 0x7f;
        if (k == 0x2a) DAT_0005f573 &= ~1;
        else if (k == 0x36) DAT_0005f573 &= ~2;
        else if (k == 0x38) DAT_0005f573 &= ~4;
        else if (k == 0x1d) DAT_0005f573 &= ~8;
        else if (k >= 0x47 && k <= 0x51) FUN_00040748(k);
        else DAT_0005f572 = DAT_0005f571;
    } else {
        if (k == 0x2a) DAT_0005f573 |= 1;
        else if (k == 0x36) DAT_0005f573 |= 2;
        else if (k == 0x38) DAT_0005f573 |= 4;
        else if (k == 0x1d) DAT_0005f573 |= 8;
        else {
            if (k >= 0x47 && k <= 0x51) {
                FUN_000407f0(k);
                DAT_0005f571 = k;
            }
            DAT_0005f572 = k;
        }
    }
    if (DAT_0005f572 == 0x10 && (DAT_0005f573 & 4)) {
        DAT_0005f0b1 |= 1;
        DAT_0005f572 = 0;
    } else if (DAT_0005f572 == 0x43) {
        DAT_0005f572 = 0;
        outp(0x20, 0x20);
        _enable();
        return;
    } else if (DAT_0005f572 == 0x19) {
        B0006457c_bO = 1;
        outp(0x20, 0x20);
        _enable();
        return;
    } else if (DAT_0005f572 == 0x39) DAT_0005f574 = 1;
    outp(0x20, 0x20);
    _enable();
}

/* ---- from build/var/mod/parts/p40abc.c */
/* FUN_00040abc @ 00040abc: test bits of the shift-state byte */
extern unsigned char DAT_0005f573;
int FUN_00040abc(int m) { return DAT_0005f573 & m; }

/* ---- from build/var/mod/parts/p40ac8.c */
/* FUN_00040ac8 @ 00040ac8: read and clear the pending mouse click */
extern volatile unsigned char DAT_0005f574;
int FUN_00040ac8(void) { int r = DAT_0005f574; DAT_0005f574 = 0; return r; }

/* ---- from build/var/mod/parts/p40ad8.c */
#define DAT_0005f572 (*(unsigned char *)&DAT_0005f572)
/* FUN_00040ad8 @ 00040ad8: poll input and report whether a key is waiting */
extern void FUN_0003f868(void); 
int FUN_00040ad8(void) { FUN_0003f868(); return DAT_0005f572 != 0; }

#undef DAT_0005f572
/* ---- from build/var/mod/parts/p40aec.c */
#define DAT_0005f572 (*(unsigned char *)&DAT_0005f572)
/* FUN_00040aec @ 00040aec: wait for a key and return its code from the table that follows the key byte (one base symbol, so the load stays before the clear) */
extern void FUN_0003f868(void);
 
int FUN_00040aec(void)
{
    int v;
    while (DAT_0005f572 == 0) FUN_0003f868();
    v = ((int *)((char *)&DAT_0005f572 + 0x1e))[DAT_0005f572];
    DAT_0005f572 = 0;
    return v;
}

#undef DAT_0005f572
/* ---- from build/var/mod/parts/p40b1c.c */
#define DAT_0005f588 (*(unsigned char *)&DAT_0005f588)
/* FUN_00040b1c @ 00040b1c: clear the keyboard buffer */
extern unsigned char DAT_0005f571;
void FUN_00040b1c(void) { DAT_0005f588 = 0; DAT_0005f571 = 0; }

#undef DAT_0005f588
/* ---- from build/var/mod/parts/p40b2c.c */
#define DAT_0005f572 (*(unsigned char *)&DAT_0005f572)
/* FUN_00040b2c @ 00040b2c: copy the last key into the key byte and clear the click */
extern unsigned char DAT_0005f571; extern volatile unsigned char DAT_0005f574;
void FUN_00040b2c(void) { DAT_0005f572 = DAT_0005f571; DAT_0005f574 = 0; }

#undef DAT_0005f572
/* ---- from build/var/mod/parts/p40b40.c */
#define DAT_0005f572 (*(unsigned char *)&DAT_0005f572)
/* FUN_00040b40 @ 00040b40 */
extern void FUN_0003f868(void);

extern int DAT_0005f590[];
int FUN_00040b40(void) { FUN_0003f868(); return DAT_0005f590[DAT_0005f572]; }

#undef DAT_0005f572
/* ---- from build/var/mod/parts/p40b54.c */
/* LAB_00040b54 @ 00040b54: divide error handler: shut down, put the keyboard and timer vectors back and chain to the old handler */
#include <dos.h>
extern void (__interrupt __far *DAT_0005f576)(), (__interrupt __far *DAT_0005f582)(), (__interrupt __far *DAT_0005f57c)();
extern void FUN_000390f4(int), FUN_00043b44(void);
void __interrupt __far LAB_00040b54(void)
{
    FUN_000390f4(0xff);
    FUN_00043b44();
    _dos_setvect(9, DAT_0005f576);
    _dos_setvect(8, DAT_0005f582);
    (*DAT_0005f57c)();
}

/* ---- from build/var/mod/parts/p40bb4.c */
extern void __interrupt __far LAB_00040708(void); /* module prototype */
extern void __interrupt __far LAB_000408f8(void); /* module prototype */
extern void __interrupt __far LAB_00040b54(void); /* module prototype */
/* FUN_00040bb4 @ 00040bb4: install the keyboard, timer and divide interrupt handlers (old vectors saved) */
#include <dos.h>
extern unsigned char DAT_0005f575;
extern void (__interrupt __far *DAT_0005f576)(), (__interrupt __far *DAT_0005f582)(), (__interrupt __far *DAT_0005f57c)();
/* extern void __interrupt __far; (declared above) */
/* extern void __interrupt __far; (declared above) */
/* extern void __interrupt __far; (declared above) */
void FUN_00040bb4(void)
{
    if (!DAT_0005f575) {
        DAT_0005f576 = _dos_getvect(9);
        _dos_setvect(9, LAB_000408f8);
        DAT_0005f582 = _dos_getvect(8);
        _dos_setvect(8, LAB_00040708);
        DAT_0005f57c = _dos_getvect(0);
        _dos_setvect(0, LAB_00040b54);
        DAT_0005f575 = 1;
    }
}

/* ---- from build/var/mod/parts/p40c38.c */
/* FUN_00040c38 @ 00040c38: restore the keyboard, timer and divide interrupt vectors */
#include <dos.h>
extern unsigned char DAT_0005f575;
extern void (__interrupt __far *DAT_0005f576)(), (__interrupt __far *DAT_0005f582)(), (__interrupt __far *DAT_0005f57c)();
void FUN_00040c38(void)
{
    if (DAT_0005f575) {
        _dos_setvect(9, DAT_0005f576);
        _dos_setvect(8, DAT_0005f582);
        _dos_setvect(0, DAT_0005f57c);
        DAT_0005f575 = 0;
    }
}

/* ---- from build/var/mod/parts/p40c94.c */
#include <dos.h>
#include <direct.h>
#include <ctype.h>
extern unsigned char DAT_0005f575; extern char B0007b6fb_iP[];
/* FUN_00040c94 @ 00040c94 */
int FUN_00040c94(void) { return DAT_0005f575; }

/* ---- module data _DATA 0005f570-0005f6f4 (docs/data/dataown.CODE2.csv: inferred), generated by tools/data2c.py */
volatile unsigned char DAT_0005f570 = 0;
unsigned char DAT_0005f571 = 0;
volatile unsigned char DAT_0005f572 = 0;
unsigned char DAT_0005f573 = 0;
volatile unsigned char DAT_0005f574 = 0;
unsigned char DAT_0005f575 = 0;
void (__interrupt __far *DAT_0005f576)() = 0;
void (__interrupt __far *DAT_0005f57c)() = 0;
void (__interrupt __far *DAT_0005f582)() = 0;
volatile unsigned char DAT_0005f588 = 0;
unsigned char DAT_0005f589[3] = { 0xa, 0x74, 0x79 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
volatile int DAT_0005f58c = 0;
int DAT_0005f590[89] = {
    0, 0x1b, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 8, 9,
    0x51, 0x57, 0x45, 0x52, 0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0xd, 0x11d, 0x41, 0x53,
    0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3b, 0x27, 0x60, 0x12a, 0x5c, 0x5a, 0x58, 0x43, 0x56,
    0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x136, 0x2a, 0x138, 0x20, 0x13a, 0x13b, 0x13c, 0x13d, 0x13e, 0x13f,
    0x140, 0x141, 0x142, 0x143, 0x144, 0x145, 0x146, 0x147, 0x148, 0x149, 0x14a, 0x14b, 0x14c, 0x14d, 0x14e, 0x14f,
    0x150, 0x151, 0x152, 0x153, 0, 0x154, 0, 0x157, 0x158
};
/* ---- end of module data _DATA */
