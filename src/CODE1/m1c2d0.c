/* Module: FUN_0001c2d0, FUN_0001c4a0, FUN_0001c4e0, FUN_0001c57c, FUN_0001c5b0, FUN_0001c608, FUN_0001c62c, FUN_0001c650, FUN_0001c660, FUN_0001c690, FUN_0001c6f0, FUN_0001c6f8 */
/* ---- from build/var/mod/parts/p1c2d0.c */
/* FUN_0001c2d0: load and start the sound driver (CODE.1 menu version): DOS buffer, read the driver, install, check the type, init; each failure frees what was allocated */
struct DRVINFO { int a, type; };
extern void *FUN_00016f10(int, int *, unsigned short *), *FUN_000171c8(int), *FUN_0001f8c4(void *, int, int);
extern int FUN_000162a8(char *), FUN_0001627c(char *), FUN_00016304(void *, int, int), FUN_0001ea0b(void *), FUN_0001eae7(int, int, int, int, int);
extern struct DRVINFO *FUN_0001eac8(int);
extern void FUN_00016f74(int), FUN_000162f0(int), FUN_00017240(void *), FUN_0001e680(void), FUN_0001e6ea(int), FUN_0001eaf1(int, int, int, int, int);
extern int DAT_00032f48, DAT_00032f6c, DAT_00032f74;
extern unsigned short DAT_00032f70;
extern void *DAT_00032f68;
#pragma aux FUN_0001f8c4 modify [eax ebx ecx edx];
#pragma aux FUN_0001e680 modify [eax ebx ecx edx];
#pragma aux FUN_0001ea0b modify [eax ebx ecx edx];
#pragma aux FUN_0001e6ea modify [eax ebx ecx edx];
#pragma aux FUN_0001eac8 modify [eax ebx ecx edx];
#pragma aux FUN_0001eae7 modify [eax ebx ecx edx];
#pragma aux FUN_0001eaf1 modify [eax ebx ecx edx];
void FUN_0001c2d0(char *name, int a, int b, int c, int d)
{
    int fd;
    void *buf, *h;
    if (!DAT_00032f48 && (DAT_00032f68 = FUN_00016f10(0x612b0, &DAT_00032f6c, &DAT_00032f70)) != 0) {
        fd = FUN_000162a8(name);
        if (fd == -1) FUN_00016f74(DAT_00032f70);
        else {
            buf = FUN_000171c8(FUN_0001627c(name));
            if (!buf) {
                FUN_00016f74(DAT_00032f70);
                return;
            }
            FUN_00016304(buf, FUN_0001627c(name), fd);
            FUN_000162f0(fd);
            h = FUN_0001f8c4(buf, 5, 0);
            if (!h) {
                FUN_00016f74(DAT_00032f70);
                FUN_00017240(buf);
                return;
            }
            FUN_00017240(buf);
            FUN_0001e680();
            DAT_00032f74 = FUN_0001ea0b(h);
            if (DAT_00032f74 == -1) {
                FUN_00016f74(DAT_00032f70);
                FUN_0001e6ea(0);
                return;
            }
            if (FUN_0001eac8(DAT_00032f74)->type != 2) {
                FUN_0001e6ea(0);
                FUN_00016f74(DAT_00032f70);
                return;
            }
            if (!FUN_0001eae7(DAT_00032f74, a, b, c, d)) {
                FUN_0001e6ea(0);
                FUN_00016f74(DAT_00032f70);
                return;
            }
            FUN_0001eaf1(DAT_00032f74, a, b, c, d);
            DAT_00032f48 = 1;
        }
    }
}

/* ---- from build/var/mod/parts/p1c4a0.c */
/* FUN_0001c4a0 */
extern void FUN_0001c57c(void), FUN_0001ea9a(int), FUN_00016f74(int);
#pragma aux FUN_0001ea9a modify [eax ebx ecx edx];
extern int DAT_00032f48, DAT_00032f74; extern unsigned short DAT_00032f70;
void FUN_0001c4a0(void) { if (DAT_00032f48) { FUN_0001c57c(); FUN_0001ea9a(DAT_00032f74); FUN_00016f74(DAT_00032f70); DAT_00032f48 = 0; } }

/* ---- from build/var/mod/parts/p1c4e0.c */
/* FUN_0001c4e0 @ 0001c4e0: start music sequence a: copy its data into the sequence buffer, hand it to the driver as a far pointer and start it */
void *memcpy(void *, const void *, unsigned);
extern int *FUN_0001954c(int, int); extern void FUN_0001c57c(void);
extern void FUN_0001ec25(int, void __far *, int), FUN_0001ec1b(int, void __far *, int, int), FUN_0001ec39(int);
#pragma aux FUN_0001ec25 modify [eax ebx ecx edx];
#pragma aux FUN_0001ec1b modify [eax ebx ecx edx];
#pragma aux FUN_0001ec39 modify [eax ebx ecx edx];
extern int DAT_00032f48, DAT_00032f4c, DAT_00032f74, DAT_00032f6c; extern char DAT_00032f78; extern void *DAT_00032f68;
void FUN_0001c4e0(int a)
{
    int *d; int *p; int n;
    if (DAT_00032f48 && DAT_00032f78) {
        p = FUN_0001954c(a, DAT_00032f4c);
        n = *p; d = p + 1;
        FUN_0001c57c();
        memcpy(DAT_00032f68, d, n);
        FUN_0001ec25(DAT_00032f74, DAT_00032f68, -1);
        FUN_0001ec1b(DAT_00032f74, DAT_00032f68, DAT_00032f6c, -1);
        FUN_0001ec39(DAT_00032f74);
    }
}

/* ---- from build/var/mod/parts/p1c57c.c */
/* FUN_0001c57c */
extern int FUN_0001ec2f(int); extern void FUN_0001ec43(int);
#pragma aux FUN_0001ec2f modify [eax ebx ecx edx];
#pragma aux FUN_0001ec43 modify [eax ebx ecx edx];
extern int DAT_00032f48, DAT_00032f74;
void FUN_0001c57c(void) { if (DAT_00032f48 && FUN_0001ec2f(DAT_00032f74) == 2) FUN_0001ec43(DAT_00032f74); }

/* ---- from build/var/mod/parts/p1c5b0.c */
/* FUN_0001c5b0 */
extern int FUN_00016304(void *, int, int); extern int *FUN_000171c8(int); extern int DAT_00032f48;
int *FUN_0001c5b0(int a, int f) { volatile int n; int *p; if (DAT_00032f48) { FUN_00016304((void *)&n, 4, f); p = FUN_000171c8(n + 4); *p = n; FUN_00016304(p + 1, n, f); return p; } return 0; }

/* ---- from build/var/mod/parts/p1c608.c */
/* FUN_0001c608 */
extern int DAT_00032f48;
void FUN_0001c608(int p) { if (DAT_00032f48 && p) FUN_00017240((void *)p); }

/* ---- from build/var/mod/parts/p1c62c.c */
/* sound effect module gap functions: enable flag, playing query, two-slot priority queue, flush */
#pragma aux FUN_0001ec2f modify [eax ebx ecx edx];
extern int FUN_0001ec2f(int);
extern int DAT_00032f48, DAT_00032f74; extern unsigned char DAT_00032f78;
struct SFX { int h, b, pri; }; extern struct SFX DAT_00032f50[];
extern void FUN_0001c57c(void), FUN_0001c4e0(int);
void FUN_0001c62c(unsigned char on)
{
    DAT_00032f78 = on;
    if (DAT_00032f48 && !DAT_00032f78) FUN_0001c57c();
}

/* ---- from build/var/mod/parts/p1c650.c */
/* FUN_0001c650 */
extern int DAT_00032f4c;
void FUN_0001c650(int v) { DAT_00032f4c = v; }

/* ---- from build/var/mod/parts/p1c660.c */
int FUN_0001c660(void)
{
    if (DAT_00032f48) return FUN_0001ec2f(DAT_00032f74) == 2;
    return 0;
}

/* ---- from build/var/mod/parts/p1c690.c */
void FUN_0001c690(int h, int b, int slot, int pri)
{
    int ok;
    if (DAT_00032f48) {
        ok = 1;
        if (DAT_00032f50[slot].h != -1 && DAT_00032f50[slot].pri < pri) ok = 0;
        if (ok) {
            DAT_00032f50[slot].h = h;
            DAT_00032f50[slot].b = b;
            DAT_00032f50[slot].pri = pri;
        }
    }
}

/* ---- from build/var/mod/parts/p1c6f0.c */
void FUN_0001c6f0(void)
{
}

/* ---- from build/var/mod/parts/p1c6f8.c */
void FUN_0001c6f8(void)
{
    if (DAT_00032f48) {
        if (DAT_00032f50[0].h != -1 && DAT_00032f50[1].h != -1) {
            if (DAT_00032f50[0].pri < DAT_00032f50[1].pri) FUN_0001c4e0(DAT_00032f50[0].h);
            else FUN_0001c4e0(DAT_00032f50[1].h);
            DAT_00032f50[1].h = -1;
            DAT_00032f50[0].h = -1;
        } else if (DAT_00032f50[0].h != -1) {
            FUN_0001c4e0(DAT_00032f50[0].h);
            DAT_00032f50[0].h = -1;
        } else if (DAT_00032f50[1].h != -1) {
            FUN_0001c4e0(DAT_00032f50[1].h);
            DAT_00032f50[1].h = -1;
        }
    }
}

/* ---- module data _DATA 00032f48-00032f88 (docs/data/dataown.CODE1.csv: inferred (ref; shared by m184d0 m1b060 m1c2d0 m1cef0)), generated by tools/data2c.py */
int DAT_00032f48 = 0;
int DAT_00032f4c = 0;
struct SFX DAT_00032f50[2] = { -1, -1, -1, -1, -1, -1 };
void *DAT_00032f68 = 0;
int DAT_00032f6c = 0;
unsigned short DAT_00032f70 = 0;
unsigned char DAT_00032f72[2] = { 0x20, 0x75 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00032f74 = 0;
char DAT_00032f78 = 1;
unsigned char DAT_00032f79[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
/* ---- end of module data _DATA */
