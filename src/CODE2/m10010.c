#include "farproc.h"
/* Module: FUN_00010010, FUN_00010074, FUN_000100b8, FUN_000101fc, FUN_000102a8 */

/* ---- from build/var/mod/parts/p10010.c */
/* FUN_00010010 @ 00010010: mark the door at (x, y) */
 
#include "world.h"
#define B00072246_dJ (*(unsigned short *)((char *)&B00072238_dL + 14)) /* STANDIN: view, B00072238_dL + 0xe */
#define B0007224c_ez (*(unsigned short *)((char *)&B00072238_dL + 20)) /* STANDIN: view, B00072238_dL + 0x14 */
extern unsigned char B00072238_dL[];
#define B0007223a_et (*(short *)((char *)&B00072238_dL + 2)) /* STANDIN: view, B00072238_dL + 0x2 */
#define B0007223e_dx (*(short *)((char *)&B00072238_dL + 6)) /* STANDIN: view, B00072238_dL + 0x6 */
 
#define DR_KIND(i) (*(unsigned short *)((char *)&B00072246_dJ + (i) * 0x16))
#define DR_X(i)    (*(short *)((char *)&B0007223e_dx + (i) * 0x16))
#define DR_Y(i)    (*(short *)((char *)&B0007223a_et + (i) * 0x16))
#define DR_ST(i)   (*(unsigned short *)((char *)&B0007224c_ez + (i) * 0x16))
void FUN_00010010(int x, int y)
{
    int i;
    for (i = 0; i < B00075618_b1.ndoor; i++) {
        if (DR_KIND(i) == 0x54 && DR_X(i) == x && DR_Y(i) == y) {
            DR_ST(i) &= 0xfe3f;
            DR_ST(i) |= 0x40;
            return;
        }
    }
}

#undef DR_KIND
#undef DR_X
#undef DR_Y
#undef DR_ST
/* ---- from build/var/mod/parts/p10074.c */
/* FUN_00010074 @ 00010074 */
#include "world.h"
struct R22 { unsigned char flags; char pad[2]; unsigned short type; char pad2[17]; };
extern unsigned char B00064d80_ay[];
#define B00064d8b_a7 ((struct R22 *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
 
extern void FUN_00026524(int); extern void FUN_0002c124(int); extern void FUN_0002f1c8(void);
void FUN_00010074(void)
{
    int i;
    FUN_00026524(0x1c);
    FUN_0002c124(0x3a);
    for (i = 0; i < B00075618_b1.nent; i++)
        if (B00064d8b_a7[i].type == 8) B00064d8b_a7[i].flags &= ~2;
    FUN_0002f1c8();
}

/* ---- from build/var/mod/parts/p100b8.c */
#include "chars.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
/* FUN_000100b8: matched 2026-11-10 in module 0x10010. The else-branch loops count k only (the compiler makes the 0x248 offset itself; with an explicit off it strength-reduces name into a fourth induction register), and the flag is set before the possession byte. */
/* FUN_000100b8 @ 000100b8: Strahd's possession: pick the first ordinary party member (not Irmgarde, Vladislav or Tatian) and mark them possessed */
int strcmp(const char *, const char *);
extern int FUN_0002c1dc(int); extern void FUN_00026524(int), FUN_0002c124(int), FUN_0002c160(int);
#define B000718f0_hO (B000718e0_iO[0].fl)
 extern unsigned char DAT_0005cf5a; 
void FUN_000100b8(void)
{
    int k, off; char *name;
    if (FUN_0002c1dc(0x3d) == 1) return;
    if (FUN_0002c1dc(0x20)) {
        FUN_00026524(9);
        FUN_0002c124(0x3d);
        FUN_0002c160(0x3c);
        k = 0;
        off = 0;
        while (1) {
            (&DAT_0005cf5a)[k] = 1;
            *(unsigned short *)((char *)&B000718f0_hO + off) &= 0xfebf;
            off += 0x248;
            k++;
            if (k >= 4) break;
        }
    } else {
        if (FUN_0002c1dc(0x3c)) return;
        for (k = 0; k < 4; k++) {
            if (!(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0xe000) && !(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0x80)) break;
        }
        if (k == 4) {
            for (k = 0; k < 4; k++) {
                if (!(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0xe000)) {
                    name = M000718e0_iO + k * 0x248;
                    if (strcmp(name, "IRMGARDE") && strcmp(name, "VLADISLAV") && strcmp(name, "TATIAN")) break;
                }
            }
        }
        FUN_00026524(9);
        *(unsigned short *)((char *)&B000718f0_hO + k * 0x248) |= 0x100;
        (&DAT_0005cf5a)[k] = 1;
        FUN_0002c124(0x3c);
    }
}

#undef M000718e0_iO
/* ---- from build/var/mod/parts/p101fc.c */
/* FUN_000101fc @ 000101fc */
#include "chars.h"
#include "world.h"
extern int FUN_0002c1dc(int), FUN_00024a60(char *); extern void FUN_0002c124(int);
extern struct CELL B000698e0_b7[];
#define B0006994c_hI (*(unsigned short *)((char *)&B000698e0_b7 + 108)) /* STANDIN: view, B000698e0_b7 + 0x6c */
 extern int DAT_0005bf44;  
int FUN_000101fc(void)
{
    int k, r;
    if (FUN_0002c1dc(0x46) == 0) {
        k = FUN_00024a60("IRMGARDE");
        if (k == -1) { DAT_0005bf44 = 0x4a; return 0; }
        if ((*(unsigned short *)(CHAR_REC(k) + 0x10) & 0x5000) == 0) {
            r = B00075618_b1.w * 0x12;
            ((unsigned short *)&B0006994c_hI)[r] &= 0xffc0;
            FUN_0002c124(0x46);
            DAT_0005bf44 = 0x33;
            return 1;
        }
    }
    return 0;
}

/* ---- from build/var/mod/parts/p102a8.c */
extern void FUN_00010010(int x, int y); /* module prototype */
extern void FUN_00010074(void); /* module prototype */
extern void FUN_000100b8(void); /* module prototype */
extern int FUN_000101fc(void); /* module prototype */
/* FUN_000102a8 (module 0x10010, -3s -ox -oe -oa -ot -w0): MATCH with stand-ins (round 63 lane AG); see the STANDIN comments */
/* FUN_000102a8 @ 000102a8: run trigger script n: open/close/toggle doors, set wall decorations, spawn monsters, sounds, music, pictures, end the game */
#include "world.h"
struct OBJ { unsigned char kind; unsigned char f0 : 2, open : 1, f3 : 3, b6 : 1, b7 : 1; signed char c2; unsigned char p3, p4, p5, c6; };
union POS { int v; struct { unsigned short f; short i; } s; };
struct CELL { unsigned short deco : 6, rest : 10; };
extern unsigned char *DAT_0005cf44, DAT_0005759c[]; extern struct CELL B000698e0_b7[]; extern short DAT_00058600; extern unsigned char DAT_00058602;
extern int DAT_0005c050, DAT_0005bf44;
extern struct OBJ *FUN_0002e8c8(int, int); extern int FUN_00030c0c(int, int, struct OBJ *), FUN_00023ef8(int), FUN_0002a1f4(void);
extern void FUN_00018a80(int, int, int, int, int), FUN_00038110(int, int, int, int), FUN_00038dcc(int), FUN_00038ef0(void), FUN_00038c54(int, int);
extern void FUN_0002c124(int), FUN_0002c160(int), FUN_0002c1a0(int), FUN_000391b0(unsigned char), FUN_0002aacc(void), FUN_0003a020(int), FUN_0002a288(void), FUN_0002c40c(int, int, int, int, int), FUN_0002c368(unsigned char *, int);
extern int FUN_00023fd4(int, int, int, int, int, unsigned char *, int); extern void FUN_0002a510(int); extern void FUN_0002a5b0(int, short, unsigned char);
void FUN_000102a8(int n)
{
    unsigned char *s, *p; union POS Y, X; int t; volatile int stop; /* STANDIN: volatile keeps stop a memory variable with its frame slot below t (non-volatile: it is enregistered and the t webs take EBX in case 0); a volatile store keeps its place among the memory accesses, see the block below */ int k, m; struct OBJ *o;
    if (n == -1) return;
    { /* STANDIN: s = DAT_0005cf44 + n * 0x1a split so that both memory reads (n, DAT_0005cf44) come before the volatile stop = 0 and the add after it, as in the original */
        int nn = n * 0x1a; /* STANDIN: copy-propagated; orders the read of n before stop = 0 */
        unsigned char *b = DAT_0005cf44; /* STANDIN: copy-propagated; orders the read of DAT_0005cf44 before stop = 0 */
        stop = 0;
        s = b + nn; /* STANDIN: the add after stop = 0 */
    }
    for (k = 0, p = s; k < s[0]; p += 5, k++) {
        o = FUN_0002e8c8(p[3], p[2]);
        switch (p[1]) {
        case 0:
            if (o) {
                if (o->kind == 1) {
                    if (!o->c6) break;
                    t = o->open;
                    o->open = 1;
                    FUN_00030c0c(p[3], p[2], o);
                    o->open = t;
                } else o->open = 1;
            } else FUN_00010010(p[3], p[2]);
            break;
        case 1:
            if (!o) break;
            if (o->kind == 1) {
                if (o->c6) break;
                t = o->open;
                o->open = 1;
                FUN_00030c0c(p[3], p[2], o);
                o->open = t;
            } else o->open = 0;
            break;
        case 2:
            if (!o) break;
            if (o->kind == 1) {
                t = o->open;
                o->open = 1;
                FUN_00030c0c(p[3], p[2], o);
                o->open = t;
            } else if (o->kind == 6) o->open ^= 1;
            else o->f0 ^= 1;
            break;
        case 4:
            t = p[2] * B00075618_b1.w + p[3]; /* product first: sum in edx, stored, then copied to eax (original order) */
            B000698e0_b7[t].deco = p[4];
            break;
        case 3:
            m = p[4];
            X.s.i = p[3];
            Y.s.i = p[2];
            X.s.f = 0x8000;
            Y.s.f = 0x8000;
            FUN_00018a80(m, (8 - p[5]) % 8 * 0x2d, 4, Y.v, X.v);
            break;
        case 11:
            if (p[4] == 11) FUN_00010074();
            else if (p[4] == 12) FUN_000100b8();
            else if (p[4] == 13) { if (FUN_000101fc() && o) o->open = 0; }
            else { FUN_00023ef8(p[4]); stop = 1; }
            break;
        case 5: FUN_00038110(*(int *)(p + 4), 0xff, 0, 0); break;
        case 6: FUN_00038dcc(0x9c4); FUN_00038ef0(); FUN_00038c54(*(int *)(p + 4), 1); break;
        case 8: FUN_0002c124(p[4]); break;
        case 9: FUN_0002c160(p[4]); break;
        case 10: FUN_0002c1a0(p[4]); break;
        case 7:
            FUN_000391b0(DAT_0005c050 ^ 1);
            FUN_0002aacc();
            FUN_0003a020(DAT_0005c050);
            FUN_0002a288();
            FUN_000391b0(DAT_0005c050);
            FUN_0002c40c(DAT_0005c050, 0x10, 0x30, 0xc8, 0xc8);
            FUN_0002c368(DAT_0005759c, p[4]);
            FUN_00023fd4(0, 0x10, 0x30, 10, 0xc8, DAT_0005759c, 1);
            FUN_0002a510(DAT_0005c050);
            DAT_0005c050 ^= 1;
            while (FUN_0002a1f4()) ;
            while (!FUN_0002a1f4()) ;
            while (FUN_0002a1f4()) ;
            FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
            DAT_0005c050 ^= 1;
            break;
        case 12: DAT_0005bf44 = p[4]; break;
        }
        if (stop) break;
    }
}

