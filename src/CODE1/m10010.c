/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
#include "records.h"
int B0003713c_eu;
unsigned char B00037138_eu[4];
int B00037134_eu;
void *B00037130_eu;
int B0003712c_eu;
void *B00037128_eu;
int B00037124_eu;
int B00037120_eu;
int B0003711c_eu;
int B00037118_eu;
struct PC B000367f8_eu[4];   /* the four character records (file CHARS); the layout is that of CODE.2 (include/records.h) */
unsigned char B000364f8_eu[768];
unsigned char B000363f8_eu[256];
unsigned char B00035ff8_eu[1024];
unsigned char B00035af8_eu[1280];
unsigned char B00035a00_eu[248];
char B000359f8_eu[8];
char B000355f8_eu[1024];
/* BSS end */
#define B00036808_eu (*(unsigned char (*)[1])((char *)&B000367f8_eu + 16)) /* STANDIN: view, B000367f8_eu + 0x10 */

extern unsigned char B000363f8_eu[256];
extern unsigned char B00035a00_eu[248];
/* Module: FUN_00010010, FUN_0001004c, FUN_000100ec, FUN_0001035c, FUN_0001043c, FUN_000104b0, FUN_0001064c,
   FUN_000107e4, FUN_000110a4, FUN_00011464, FUN_000115b0, FUN_00011a04, FUN_00011bd4, FUN_00011cd0,
   FUN_00011dd8, FUN_00011e64, FUN_00011ee4, FUN_00011f24, FUN_00012198, FUN_000124d4, FUN_0001266c,
   FUN_000128e4, FUN_00012994, FUN_00012a64, FUN_00012dfc, FUN_00013020, FUN_00013138, FUN_00013208,
   FUN_000132f4, FUN_0001334c, FUN_00013404, FUN_000137c0, FUN_00013884, FUN_000138a4, FUN_00013c58,
   FUN_000140fc, FUN_000144e4, FUN_00014520, FUN_000145fc, FUN_00014978, FUN_00014a0c, FUN_00014b00,
   FUN_00014b18, FUN_00014c80, FUN_00014cb0, FUN_00014d54, FUN_00014dc4, FUN_00014ef0, FUN_00015014,
   main */
/* ---- module data _DATA 000304b8-000304c4, ahead of the code: 9.5b writes the literals of data initialisers into CONST where
   they are defined, and these three messages are the first CONST bytes (0x30004); the rest of _DATA is at the end of the file */
char *DAT_000304b8 = "\"CLICK ON ATTRIBUTE CARD TO ACCEPT\"";
char *PTR_s_Error_opening_INIT_000304bc = "Error opening INIT";
char *DAT_000304c0 = "Error opening T";
/* names inside DAT_0003087c (tools/dataview.py): views of the object the module defines */
#define DAT_00030874 ((struct XY *)((char *)DAT_0003087c + -0x8))
#define DAT_000308a0 (*(int *)((char *)DAT_0003087c + 0x24))
#define DAT_000308e4 (*(int *)((char *)DAT_0003087c + 0x68))
/* names inside DAT_000308f4 (tools/dataview.py): views of the object the module defines */
#define DAT_000308f8 ((struct VP *)((char *)DAT_000308f4 + 0x4))
#define DAT_00030904 (*(int *)((char *)DAT_000308f4 + 0x10))
#define DAT_00030908 (*(int *)((char *)DAT_000308f4 + 0x14))
#define DAT_0003090c (*(int *)((char *)DAT_000308f4 + 0x18))
#define DAT_00030910 (*(int *)((char *)DAT_000308f4 + 0x1c))
#define DAT_00030924 (*(int *)((char *)DAT_000308f4 + 0x30))
#define DAT_00030928 (*(int *)((char *)DAT_000308f4 + 0x34))
#define DAT_0003092c (*(int *)((char *)DAT_000308f4 + 0x38))
#define DAT_00030930 (*(int *)((char *)DAT_000308f4 + 0x3c))
#define DAT_00030934 (*(int *)((char *)DAT_000308f4 + 0x40))
#define DAT_00030938 (*(int *)((char *)DAT_000308f4 + 0x44))
#define DAT_00030940 (*(int *)((char *)DAT_000308f4 + 0x4c))
#define DAT_00030948 (*(int *)((char *)DAT_000308f4 + 0x54))
extern volatile int DAT_000304d0; /* STANDIN: volatile module-wide for FUN_00011cd0's inc dword ptr; the other increments are written prefix (a volatile postfix reloads the value), the decrements go through a plain view at DAT_000304cc + 4 (a volatile decrement is add -1, not dec) */
/* ---- from build/var/mod/parts/p10010.c */
/* FUN_00010010: roll n dice of d sides, each plus b, then add bonus; at least 1 */
unsigned rand(void);
int FUN_00010010(int n, int d, int b, int bonus) { int t, k; t = 0; for (k = 0; k < n; k++) { t += (rand() * d >> 15) + 1; t += b; } t += bonus; if (t < 1) t = 1; return t; }

/* ---- from build/var/mod/parts/p1004c.c */
/* FUN_0001004c */
extern void FUN_0001633c(int, int, int), FUN_00016304(void *, int, int); extern int DAT_000304c8;
void FUN_0001004c(char *buf, int k) { int off; unsigned short len; FUN_0001633c(k * 4 + 4, 0, DAT_000304c8); FUN_00016304((void *)&off, 4, DAT_000304c8); FUN_0001633c(off, 0, DAT_000304c8); FUN_00016304((void *)&len, 2, DAT_000304c8); FUN_00016304(buf, len, DAT_000304c8); buf[len] = 0; while (len) { buf[len - 1] ^= 0xdc; len--; } }

/* ---- from build/var/mod/parts/p100ec.c */
unsigned strlen(const char *);
char *strcpy(char *, const char *);
extern void FUN_00016eb0(int, int, int, int, int, unsigned char *), FUN_00016c60(int, int, int, int, int), FUN_00017d80(int, int, int, char *, int), FUN_00017240(void *);
extern char *FUN_000171c8(int);
void FUN_000100ec(int x, int y, int w, int col, char *s, int mode, unsigned char *tbl)
{
    char *buf, *p, *b2, *q;
    int n, cx;
    if (mode == 0) {
        FUN_00016eb0(0, x, y, 0x1a, 7, tbl);
        buf = FUN_000171c8(strlen(s) + 1);
        strcpy(buf, s);
        for (p = buf, n = 0; *p; n++) {
            while (*p != ' ' && *p) p++;
            if (*p == ' ') *p++ = 0;
        }
        cx = x + w / 2 - n * 5;
        for (q = buf; n; n--) {
            FUN_00017d80(cx, y, col, q, 0);
            while (*q) q++;
            q++;
            cx += 10;
        }
        FUN_00017240(buf);
    } else if (mode == 1) {
        FUN_00016c60(0, x, y, 0x1a, 7);
        FUN_00017d80(x + 8, y, col, s, 0);
    } else if (mode == 2) {
        FUN_00016c60(0, x, y, 0x1a, 7);
        FUN_00017d80(x + w - 0x11, y, col, s, 0);
    } else if (mode == 3) {
        FUN_00016c60(0, x, y, 0x17, 7);
        FUN_00017d80(w / 2 + x - 5, y, col, s, 0);
    } else if (mode == 4 || mode == 5) {
        if (mode != 5) FUN_00016c60(0, x, y, 0x1a, 7);
        b2 = FUN_000171c8(strlen(s) + 1);
        p = b2;
        strcpy(p, s);
        for (q = p; *q; ) {
            while (*q != ' ' && *q) q++;
            if (*q == ' ') *q++ = 0;
        }
        p = b2;
        FUN_00017d80(x + 8, y, col, p, 0);
        while (*p) p++;
        p++;
        FUN_00017d80(x + w - 0x10, y, col, p, 0);
        FUN_00017240(b2);
    }
}

/* ---- from build/var/mod/parts/p1035c.c */
/* FUN_0001035c */
struct P { int x, y; }; extern struct P DAT_0003087c[]; 
int FUN_0001035c(int x, int y) { int r, k, n; r = -1; if (DAT_000304d0 == 6) { k = 6; n = 9; } else { k = 0; n = 6; } for (; k < n; k++) if (x >= DAT_0003087c[k].x && DAT_0003087c[k].x + 0x7a > x && y >= DAT_0003087c[k].y && DAT_0003087c[k].y + 0x30 > y) r = k + 1; if (x >= 0x114 && x < 0x18e && y >= 0x10c && y < 0x13c) r = 0; if ((DAT_000304d0 == 3 || DAT_000304d0 == 5) && x >= DAT_000308e4 && DAT_000308e4 + 0x7a > x && y >= DAT_000308a0 && DAT_000308a0 + 0x30 > y) r = 0xff; return r; }

/* ---- from build/var/mod/parts/p1043c.c */
extern int FUN_0001035c(int x, int y); /* module prototype */
extern int FUN_000153b4(void), FUN_0001831c(void); extern int DAT_000304d4; extern short B000373e6_eu, B000373e8_eu, B000373ea_eu;
int FUN_0001043c(void) { int r, v, x, y; while (FUN_000153b4()); for (;;) { if (!FUN_000153b4()) { if (DAT_000304d0 != 6) continue; if (FUN_0001831c() == 0x14e) return 7; if (FUN_0001831c() == 0x14a) return 9; continue; } x = B000373e6_eu; y = B000373e8_eu; v = B000373ea_eu; DAT_000304d4 = v; if ((r = FUN_0001035c(x, y)) >= 0) return r; } }

/* ---- from build/var/mod/parts/p104b0.c */
extern void FUN_000138a4(int y, int x); /* module prototype */
/* Round 32: matches under -ol (the module set; flags.csv now -ol) with the step-5 record index as k (k = DAT_000304cc; DAT_000304c4[k], k * 0x248): k is then a variable with uses in several steps and its step-1/step-4 instances stay in its home ebx; without -ol 410/409. */
/* FUN_000104b0: draws a panel of the current record (DAT_000304cc) up to step; k doubles as the record offset in steps 1 and 4 (that is what puts it in ebx). Round 25: the round-24 "state carried between functions" reading is withdrawn: the record offset goes to eax only under -ol (alone, after a 60-statement synthetic function, and in module 0x10010 alike: 4 lines); without -ol it matches alone, after a predecessor and in the module. So module 0x10010 has a flag conflict here (-ol for FUN_000100ec, FUN_000110a4, FUN_000115b0, FUN_00012198 ...), not a context effect; tried under -ol: a separate offset variable, c in the loop block, k = R as its own statement, int c, k (8 real compiles). Round 27 (re-derived, 0 compiles): the original recomputes R inside the step-3 loop (imul eax per iteration, k in ebx), so the loop has no invariant hoisted even under -ol; the only -ol effect here is on the dead step-1/step-4 instances of k (k = R, never read before k = 2 / the end): without -ol 9.5b keeps them in k's home ebx, with -ol they become their own temporaries and take eax. A source for -ol needs those instances live: the most likely untested form is k read after the step-1/step-4 calls (e.g. the step-2 and step-5 record reads written through k, B0003680c_eu[k], which the original's fresh imul in step 2 argues against) - not tested for lack of budget */
#define R (DAT_000304cc * 0x248)
extern int DAT_000304cc, B0003713c_eu;
#define B0003680b_eu (*(unsigned char (*)[])((char *)&B000367f8_eu + 19)) /* STANDIN: view, B000367f8_eu + 0x13 */
#define B0003680c_eu (*(unsigned char (*)[])((char *)&B000367f8_eu + 20)) /* STANDIN: view, B000367f8_eu + 0x14 */
#define B00036812_eu ((unsigned char *)((char *)&B000367f8_eu + 26)) /* STANDIN: view, B000367f8_eu + 0x1a */
extern unsigned char DAT_000304c4[], B00035ff8_eu[];
#define B0003680d_eu ((signed char *)((char *)&B000367f8_eu + 21)) /* STANDIN: view, B000367f8_eu + 0x15 */
#define B0003680a_eu (*(signed char (*)[])((char *)&B000367f8_eu + 18)) /* STANDIN: view, B000367f8_eu + 0x12 */

extern void FUN_00016eb0(int, int, int, int, int, unsigned char *), FUN_00016c60(int, int, int, int, int), FUN_00017d80(int, int, int, char *, int);
void FUN_000104b0(int step)
{
    int k, c;
    if (step >= 1) FUN_00016eb0(0, 0x114, 3, B0003680b_eu[k = R] + 0xc, 7, B00035ff8_eu);
    if (step >= 2) FUN_00016eb0(0, 0x114, 0x38, B0003680c_eu[R], 7, B00035ff8_eu);
    if (step >= 3)
        for (k = 2; k >= 0; k--) {
            c = B0003680d_eu[k + R];
            if (c != -1) FUN_00016eb0(0, 0x114 - k * 0x14, 0x6d - k, c + 6, 7, B00035ff8_eu);
        }
    if (step >= 4) FUN_00016eb0(0, 0x114, 0xa2, B00036812_eu[k = R] + 0xe, 7, B00035ff8_eu);
    if (step >= 5) {
        FUN_00016c60(0, 0x114, 0xd7, 0x14, 7);
        FUN_00016c60(0, 0x129, 0xd7, B0003680b_eu[R] * 0x17 + B0003713c_eu + B0003680a_eu[R], 1);
        k = DAT_000304cc; if (DAT_000304c4[k]) FUN_00017d80(0x116, 0xd7, 0x30, B000367f8_eu[k].name, 0);
    }
    if (step >= 6) FUN_000138a4(0x114, 0x10c);
}

#undef R
/* ---- from build/var/mod/parts/p1064c.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
extern void FUN_000100ec(int x, int y, int w, int col, char *s, int mode, unsigned char *tbl); /* module prototype */
/* struct P: defined above */
struct B { int state, spr; };
extern struct P DAT_0003087c[];
extern struct B DAT_000308f4[];
extern int B0003713c_eu, DAT_00030954[], DAT_00030958;
extern unsigned char B00035af8_eu[], B00035ff8_eu[];
extern char B000355f8_eu[];
extern void FUN_000167c8(int, int, int, int), FUN_00016c60(int, int, int, int, int), FUN_00016eb0(int, int, int, int, int, unsigned char *);
void FUN_0001064c(void)
{
    int k;
    for (k = 0; k < 9; k++) {
        if (DAT_000308f4[k].spr == -1) continue;
        if (DAT_000304d0 == 0 && DAT_000308f4[k].spr == 1) FUN_000167c8(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_00030954[k]);
        else if (k == 7 && DAT_000308f4[k].spr != 0x14) FUN_000167c8(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_00030958);
        else if (DAT_000308f4[k].spr >= B0003713c_eu && B0003713c_eu + 0x2e > DAT_000308f4[k].spr) {
            FUN_00016c60(0, DAT_0003087c[k].x, DAT_0003087c[k].y, 0x14, 7);
            FUN_00016eb0(0, DAT_0003087c[k].x + 0x15, DAT_0003087c[k].y, DAT_000308f4[k].spr, 1, B00035af8_eu);
        } else FUN_00016eb0(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_000308f4[k].spr, 7, B00035ff8_eu);
    }
    if (DAT_00030940 != -1) {
        FUN_0001004c(B000355f8_eu, DAT_00030940);
        FUN_000100ec(0x114, 0x10c, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
    }
    if (DAT_00030948 != -1) {
        FUN_0001004c(B000355f8_eu, DAT_00030948);
        FUN_000100ec(0x114, 0xd7, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
    }
}

/* ---- from build/var/mod/parts/p107e4.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
extern void FUN_000100ec(int x, int y, int w, int col, char *s, int mode, unsigned char *tbl); /* module prototype */
extern void FUN_0001064c(void); /* module prototype */
#define DAT_0003087c ((struct EMB *)DAT_0003087c)
#define DAT_000308f4 ((struct VP *)DAT_000308f4)
#define DAT_00030954 ((void **)DAT_00030954)
#define DAT_00030958 (*(void **)&DAT_00030958)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
void *memset(void *, int, unsigned);
extern void FUN_00018e3c(int, int), FUN_00016588(int), FUN_000186c4(int, int, int, int), FUN_00016c60(int, int, int, int, int), FUN_00016eb0(int, int, int, int, int, unsigned char *);
extern void FUN_00019c44(int, int, int, int, int, void *, int, int), FUN_0001a05c(int, int, int, int, int), FUN_000155dc(int, int, int, int, int), FUN_000153e4(int);
extern void *FUN_0001954c(int, int);
#define B000363f8_eu (*(unsigned char *)((char *)&B000363f8_eu)) /* STANDIN: the first bytes of the object */
#define B00037138_eu (*(unsigned char *)((char *)&B00037138_eu)) /* STANDIN: the first bytes of the object */
extern unsigned char B00035af8_eu[], B00035ff8_eu[];
extern int B0003713c_eu;

extern char B000355f8_eu[];
struct EMB { int x, y; };

struct VP { int v, pad; };

#define PG (*(int *)&B00037138_eu)
#define CUR(k) DAT_000308f8[k].v
#define OLD(k) DAT_000308f4[k].v
#define INR(v) ((v) >= B0003713c_eu && B0003713c_eu + 0x2e > (v))
void FUN_000107e4(int lo, int hi)
{
    int k1, k2; unsigned char ph[9]; int k3, step, y18;
    memset((void *)ph, 0, 9);
    FUN_00018e3c(0x14, 7);
    for (k1 = lo; k1 < hi; k1++) {
        if (CUR(k1) < 0) continue;
        if (!DAT_000304d0 && CUR(k1) == 1) continue;
        if (k1 == 7 && CUR(k1) != 0x14) continue;
        if (INR(CUR(k1))) FUN_00018e3c(CUR(k1), 1);
        else FUN_00018e3c(CUR(k1), 7);
    }
    for (step = 0; ph[hi - 1] != 11; step++) {
        FUN_00016588(B00037138_eu);
        if (!DAT_000304d0 && step < 2) FUN_000186c4(0xc8, 0, 0x19, 7);
        for (k2 = lo; k2 - lo <= step && k2 < hi; k2++) ph[k2]++;
        for (k3 = lo; k3 < hi; k3++) {
            int p, x, y;
            p = ph[k3];
            x = DAT_0003087c[k3].x;
            y = DAT_0003087c[k3].y;
            if (CUR(k3) != OLD(k3)) {
            if (CUR(k3) == -1) continue;
            if (p == 0) {
                if (!DAT_000304d0 && OLD(k3) == 1) FUN_000167c8(0, x, y, DAT_00030954[k3]);
                else if (INR(OLD(k3))) {
                    FUN_00016c60(0, x, y, 0x14, 7);
                    FUN_00016eb0(0, x + 0x15, y, OLD(k3), 1, B00035af8_eu);
                } else if (k3 == 7 && OLD(k3) != 0x15) FUN_000167c8(0, x, y, DAT_00030954[0]);
                else FUN_00016c60(0, x, y, OLD(k3), 7);
            } else if (p > 0 && p < 6) {
                FUN_00016c60(0, x, y, k3 + 0x1e, 7);
                if (!DAT_000304d0 && OLD(k3) == 1) FUN_00019c44(0, 6 - p, 10, 1, 1, DAT_00030954[k3], x, y + 0x18 - ((6 - p) * 48 + 3) / 6 / 2);
                else if (INR(OLD(k3))) {
                    k1 = 6 - p;
                    y = y + 0x18 - (k1 * 48 + 3) / 6 / 2;
                    FUN_00019c44(0, k1, 10, 1, 1, FUN_0001954c(0x14, 7), x, y);
                    FUN_00019c44(1, k1, 10, 1, 1, FUN_0001954c(OLD(k3), 1), x + 0x15, y);
                } else if (k3 == 7 && OLD(k3) != 0x15) FUN_00019c44(0, 6 - p, 10, 1, 1, DAT_00030954[0], x, y + 0x18 - ((6 - p) * 48 + 3) / 6 / 2);
                else {
                    k1 = 6 - p;
                    FUN_00019c44(0, k1, 10, 1, 1, FUN_0001954c(OLD(k3), 7), x, y + 0x18 - (k1 * 48 + 3) / 6 / 2);
                }
            } else {
                y18 = y + 0x18;
                if (p == 6) {
                    FUN_00016c60(0, x, y, k3 + 0x1e, 7);
                    FUN_0001a05c(x, y18, x + 0x79, y18, B000363f8_eu);
                } else if (p > 6 && p < 12) {
                    p = 12 - p;
                    FUN_00016c60(0, x, y, k3 + 0x1e, 7);
                    if (!DAT_000304d0 && CUR(k3) == 1) FUN_00019c44(0, 6 - p, 6, 1, 1, DAT_00030954[k3], x, y18 - ((6 - p) * 48 + 3) / 6 / 2);
                    else if (k3 == 7 && CUR(k3) != 0x14) FUN_00019c44(0, 6 - p, 6, 1, 1, DAT_00030958, x, y + 0x18 - ((6 - p) * 48 + 3) / 6 / 2);
                    else if (INR(CUR(k3))) {
                        k1 = 6 - p;
                        FUN_00019c44(0, k1, 6, 1, 1, FUN_0001954c(0x14, 7), x, y + 0x18 - (k1 * 48 + 3) / 6 / 2);
                        FUN_00019c44(1, k1, 6, 1, 1, FUN_0001954c(CUR(k3), 1), x + 0x15, y + 0x18 - (k1 * 48 + 3) / 6 / 2);
                    } else {
                        k1 = 6 - p;
                        FUN_00019c44(0, k1, 6, 1, 1, FUN_0001954c(CUR(k3), 7), x, y + 0x18 - (k1 * 48 + 3) / 6 / 2);
                    }
                } else if (p >= 12) {
                    if (!DAT_000304d0 && CUR(k3) == 1) FUN_000167c8(0, x, y, DAT_00030954[k3]);
                    else if (k3 == 7 && CUR(k3) != 0x14) FUN_000167c8(0, x, y, DAT_00030958);
                    else if (INR(CUR(k3))) {
                        FUN_00016c60(0, x, y, 0x14, 7);
                        x += 0x15;
                        FUN_00016eb0(0, x, y, CUR(k3), 1, B00035af8_eu);
                    } else FUN_00016c60(0, x, y, CUR(k3), 7);
                }
            }
            } else {
                if (CUR(k3) == -1) continue;
                if (k3 == 7 && CUR(k3) != 0x14) FUN_000167c8(0, x, y, DAT_00030958);
                else if (INR(OLD(k3))) {
                    FUN_00016c60(0, x, y, 0x14, 7);
                    FUN_00016eb0(0, x + 0x15, y, CUR(k3), 1, B00035af8_eu);
                } else FUN_00016eb0(0, x, y, CUR(k3), 7, B00035ff8_eu);
            }
        }
        if (step < 2) {
            if (DAT_00030940 != -1) {
                FUN_0001004c(B000355f8_eu, DAT_00030940);
                FUN_000100ec(0x114, 0x10c, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
            }
            if (DAT_00030948 != -1) {
                FUN_0001004c(B000355f8_eu, DAT_00030948);
                FUN_000100ec(0x114, 0xd7, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
            }
            FUN_000155dc(PG, 0xec, 0, 0xa4, 0x140);
        } else {
            FUN_000153e4(PG);
            B00037138_eu ^= 1;
        }
    }
    FUN_00016588(B00037138_eu);
    FUN_0001064c();
    FUN_000153e4(PG);
    B00037138_eu ^= 1;
}

#undef DAT_0003087c
#undef DAT_000308f4
#undef DAT_00030954
#undef DAT_00030958
#undef FUN_000167c8
#undef PG
#undef CUR
#undef OLD
#undef INR
/* ---- from build/var/mod/parts/p110a4.c */
extern void FUN_000104b0(int step); /* module prototype */
#define DAT_0003087c ((struct EMB *)DAT_0003087c)
extern void *FUN_000171c8(int), *FUN_0001954c(int, int);
extern void FUN_00016588(int), FUN_000186c4(int, int, int, int), FUN_00016c60(int, int, int, int, int), FUN_00017d80(int, int, int, char *, int), FUN_000153e4(int);
extern void FUN_00016744(void *, int, int, int, int), FUN_000166c0(void *, int, int, int, int), FUN_00016d54(int, int, int, void *), FUN_0001a5c8(int, void *), FUN_00017240(void *);
extern unsigned char DAT_00030964[], DAT_00030970[];

extern char B00037140_eu[];
/* struct EMB: defined above */

/* struct VP: defined above */

struct SPR { char pad[4]; unsigned short w; unsigned char h; };
#define PG (*(int *)&B00037138_eu)
void FUN_000110a4(int arg)
{
    int tx; int j; int s; int sw[2]; int px0; int sh[2]; int sx[2]; int px; int sy[2]; int ty; struct SPR *spr; int e; int py0; int py; int k; void *buf[2]; int i;
    buf[0] = FUN_000171c8(0x3540);
    buf[1] = FUN_000171c8(0x3540);
    for (i = 0; i < 2; i++) {
        FUN_00016588(B00037138_eu);
        if (!DAT_000304d0) FUN_000186c4(0, 0, 0x18, 7);
        FUN_000186c4(0xc8, 0, 0x19, 7);
        FUN_00016c60(0, 5, 0, 0x2a, 7);
        FUN_00017d80(5, 0, 0x140, B00037140_eu, 1);
        for (e = 0; e < 9; e++) FUN_00016c60(0, DAT_0003087c[e].x, DAT_0003087c[e].y, e + 0x1e, 7);
        if (arg) FUN_000104b0(arg);
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    FUN_0001954c(0x15, 7);
    FUN_0001954c(0x27, 7);
    FUN_0001954c(0x28, 7);
    FUN_0001954c(0x29, 7);
    for (k = 0; k < 9; k++) {
        if (DAT_000308f8[k].v == -1) continue;
        py = 0xa0;
        py0 = 0xa0;
        px = -0x38;
        px0 = -0x38;
        ty = DAT_0003087c[k].y + 0x18;
        tx = DAT_0003087c[k].x + 0x3d;
        for (s = 0, j = 0; j < 12; j++) {
            FUN_00016588(B00037138_eu);
            if (j >= 2) FUN_00016744(buf[PG], sx[PG], sy[PG], sw[PG], sh[PG]);
            spr = FUN_0001954c(DAT_00030964[s], 7);
            if (DAT_00030970[s]) FUN_0001a5c8(0, spr);
            sx[PG] = px - spr->w / 2;
            sy[PG] = py - spr->h * 2;
            sw[PG] = spr->w;
            sh[PG] = spr->h * 8;
            FUN_000166c0(buf[PG], sx[PG], sy[PG], sw[PG], sh[PG]);
            FUN_00016d54(0, sx[PG], sy[PG], spr);
            if (DAT_00030970[s]) FUN_0001a5c8(0, spr);
            s = (s + 1) % 12;
            py = py0 + ((ty - py0) * (j + 1) + 6) / 12;
            px = px0 + ((tx - px0) * (j + 1) + 6) / 12;
            FUN_000153e4(PG);
            B00037138_eu ^= 1;
        }
        FUN_00016588(B00037138_eu);
        FUN_00016744(buf[PG], sx[PG], sy[PG], sw[PG], sh[PG]);
        FUN_00016c60(0, DAT_0003087c[k].x, DAT_0003087c[k].y, 0x15, 7);
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
        FUN_00016588(B00037138_eu);
        FUN_00016744(buf[PG], sx[PG], sy[PG], sw[PG], sh[PG]);
        FUN_00016c60(0, DAT_0003087c[k].x, DAT_0003087c[k].y, 0x15, 7);
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    FUN_00017240(buf[0]);
    FUN_00017240(buf[1]);
}

#undef DAT_0003087c
#undef PG
/* ---- from build/var/mod/parts/p11464.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_000110a4(int arg); /* module prototype */
/* FUN_00011464: set up a menu screen: eleven button slots (sprite, state), the status message, draw the screen and highlight the buttons */
char *strcpy(char *, const char *);
/* struct B: defined above */
extern struct B DAT_000308f4[];
extern char B00037140_eu[], *DAT_000304b8;
extern int B0003713c_eu;

extern void *FUN_0001954c(int, int);
void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg)
{
    int i, k;
    for (i = 0; i < 11; i++) DAT_000308f4[i].state = 0x15;
    DAT_000308f4[0].spr = b0; DAT_000308f4[1].spr = b1; DAT_000308f4[2].spr = b2; DAT_000308f4[3].spr = b3;
    DAT_000308f4[4].spr = b4; DAT_000308f4[5].spr = b5; DAT_000308f4[6].spr = b6; DAT_000308f4[7].spr = b7;
    DAT_000308f4[8].spr = b8; DAT_000308f4[9].spr = b9; DAT_000308f4[10].spr = b10;
    if (msg == -1) B00037140_eu[0] = 0;
    else if (msg == 0x2b) strcpy(B00037140_eu, DAT_000304b8);
    else FUN_0001004c(B00037140_eu, msg);
    FUN_000110a4(scr);
    for (k = 0; k < 9; k++)
        if (DAT_000308f4[k].spr != -1 && DAT_000308f4[k].spr > 10) {
            if (DAT_000308f4[k].spr >= B0003713c_eu && B0003713c_eu + 0x2e > DAT_000308f4[k].spr) FUN_0001954c(DAT_000308f4[k].spr, 1);
            else FUN_0001954c(DAT_000308f4[k].spr, 7);
        }
    if (DAT_000304d0 < 2) FUN_000107e4(2, 4);
    else if (DAT_000304d0 != 6) FUN_000107e4(0, 6);
    else FUN_000107e4(6, 9);
}

/* ---- from build/var/mod/parts/p115b0.c */
extern void FUN_000104b0(int step); /* module prototype */
#define DAT_0003087c ((struct EMB *)DAT_0003087c)
#define DAT_00030954 ((void **)DAT_00030954)
#define DAT_00030958 (*(void **)&DAT_00030958)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
extern void *FUN_000171c8(int), *FUN_0001954c(int, int);
extern void FUN_000156dc(void), FUN_00016588(int), FUN_00016824(int, int, int, void *, void *), FUN_00016eb0(int, int, int, int, int, unsigned char *), FUN_000153e4(int), FUN_00015454(int);
extern void FUN_00016c60(int, int, int, int, int), FUN_000166c0(void *, int, int, int, int), FUN_00016744(void *, int, int, int, int), FUN_00017240(void *), FUN_000186c4(int, int, int, int);
extern unsigned char B00035ff8_eu[], B00035af8_eu[];
extern int B0003713c_eu;

/* struct EMB: defined above */

/* struct VP: defined above */

#define PG (*(int *)&B00037138_eu)
void FUN_000115b0(int sel, int tx, int ty, int arg)
{
    int y0; int px[2]; int x0; void *buf[2]; int f, k, x, y; int py[2];
    FUN_000156dc();
    for (f = 0; f < 5; f++) {
        FUN_00016588(B00037138_eu);
        for (k = 0; k < 9; k++) {
            if (k == sel || DAT_000308f8[k].v == -1) continue;
            if (!DAT_000304d0) FUN_00016824(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_00030954[k], B00035ff8_eu + f * 256);
            else if (k == 7) FUN_00016824(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_00030958, B00035ff8_eu + f * 256);
            else if (DAT_000308f8[k].v >= B0003713c_eu && B0003713c_eu + 0x2e > DAT_000308f8[k].v) {
                FUN_00016eb0(0, DAT_0003087c[k].x, DAT_0003087c[k].y, 0x14, 7, B00035ff8_eu + f * 256);
                FUN_00016824(0, DAT_0003087c[k].x + 0x15, DAT_0003087c[k].y, FUN_0001954c(DAT_000308f8[k].v, 1), B00035af8_eu + f * 256);
            } else FUN_00016eb0(0, DAT_0003087c[k].x, DAT_0003087c[k].y, DAT_000308f8[k].v, 7, B00035ff8_eu + f * 256);
        }
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    for (f = 4; f >= 0; f--) {
        FUN_00016588(B00037138_eu);
        for (k = 0; k < 9; k++) {
            if (k == sel || DAT_000308f8[k].v == -1) continue;
            FUN_00016eb0(0, DAT_0003087c[k].x, DAT_0003087c[k].y, k + 0x1e, 7, B00035ff8_eu + f * 256);
        }
        if (f == 0) FUN_00015454(PG);
        else FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    if (sel == -1) return;
    buf[0] = FUN_000171c8(0x1e80);
    buf[1] = FUN_000171c8(0x1e80);
    FUN_00016588(B00037138_eu);
    FUN_00016c60(0, DAT_0003087c[sel].x, DAT_0003087c[sel].y, sel + 0x1e, 7);
    x0 = x = DAT_0003087c[sel].x;
    y0 = y = DAT_0003087c[sel].y;
    FUN_000166c0(buf[0], x, y, 0x7a, 0x30);
    FUN_000166c0(buf[1], x, y, 0x7a, 0x30);
    px[0] = px[1] = x;
    py[0] = py[1] = y;
    for (f = 0; f <= 8; f++) {
        FUN_00016588(B00037138_eu);
        FUN_00016744(buf[PG], px[PG], py[PG], 0x7a, 0x30);
        px[PG] = x;
        py[PG] = y;
        FUN_000166c0(buf[PG], x, y, 0x7a, 0x30);
        if (DAT_000308f8[sel].v >= B0003713c_eu && B0003713c_eu + 0x2e > DAT_000308f8[sel].v) {
            FUN_000167c8(0, px[PG], py[PG], FUN_0001954c(0x14, 7));
            FUN_000167c8(0, px[PG] + 0x15, py[PG], FUN_0001954c(DAT_000308f8[sel].v, 1));
        } else FUN_000167c8(0, px[PG], py[PG], FUN_0001954c(DAT_000308f8[sel].v, 7));
        x = x0 + ((tx - x0) * (f + 1) + 4) / 8;
        y = y0 + ((ty - y0) * (f + 1) + 4) / 8;
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    FUN_00017240(buf[0]);
    FUN_00017240(buf[1]);
    FUN_00016588(B00037138_eu);
    FUN_000186c4(0xc8, 0, 0x19, 7);
    FUN_000104b0(arg);
    FUN_00015454(PG);
    B00037138_eu ^= 1;
}

#undef DAT_0003087c
#undef DAT_00030954
#undef DAT_00030958
#undef FUN_000167c8
#undef PG
/* ---- from build/var/mod/parts/p11a04.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
extern void FUN_000100ec(int x, int y, int w, int col, char *s, int mode, unsigned char *tbl); /* module prototype */
#define DAT_000304c4 (*(unsigned char *)&DAT_000304c4)
#define M000367f8_eu ((char *)B000367f8_eu)
#define M0003680a_eu (*(signed char *)&B0003680a_eu)
#define M0003680b_eu (*(unsigned char *)&B0003680b_eu)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
/* FUN_00011a04: rebuild the two portrait cards (empty slot text or the character's face and name) as grabbed sprites, saving and restoring the screen under them */
extern void FUN_00017830(void *), FUN_00016588(int), FUN_00016c60(int, int, int, int, int), FUN_00017d80(int, int, int, char *, int);
extern void *FUN_00017868(int, int, int, int, int);
extern void *DAT_0003095c, *DAT_00030960;
#define B00036a53_eu (*(unsigned char *)((char *)&B000367f8_eu + 603)) /* STANDIN: view, B000367f8_eu + 0x25b */
extern unsigned char DAT_000304c5, B00035ff8_eu[];
#define B00036a52_eu (*(signed char *)((char *)&B000367f8_eu + 602)) /* STANDIN: view, B000367f8_eu + 0x25a */

#define B00036a40_eu ((char *)((char *)&B000367f8_eu + 584)) /* STANDIN: view, B000367f8_eu + 0x248 */
extern char B000355f8_eu[];
extern int B0003713c_eu;
void FUN_00011a04(void)
{
    void *save;
    if (DAT_0003095c) {
        FUN_00017830(DAT_0003095c);
        DAT_0003095c = 0;
    }
    if (DAT_00030960) {
        FUN_00017830(DAT_00030960);
        DAT_00030960 = 0;
    }
    FUN_00016588(B00037138_eu);
    save = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    if (!DAT_000304c4) {
        FUN_0001004c(B000355f8_eu, 0);
        FUN_000100ec(0, 0, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
    } else {
        FUN_00016c60(0, 0, 0, 0x14, 7);
        FUN_00016c60(0, 0x15, 0, M0003680a_eu + B0003713c_eu + M0003680b_eu * 0x17, 1);
        FUN_00017d80(2, 0, 0x30, M000367f8_eu, 0);
    }
    DAT_0003095c = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    if (!DAT_000304c5) {
        FUN_0001004c(B000355f8_eu, 0);
        FUN_000100ec(0, 0, 0x7a, 0x30, B000355f8_eu, 0, B00035ff8_eu);
    } else {
        FUN_00016c60(0, 0, 0, 0x14, 7);
        FUN_00016c60(0, 0x15, 0, B00036a52_eu + B0003713c_eu + B00036a53_eu * 0x17, 1);
        FUN_00017d80(2, 0, 0x30, B00036a40_eu, 0);
    }
    DAT_00030960 = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    FUN_000167c8(0, 0, 0, save);
    FUN_00017830(save);
}

#undef DAT_000304c4
#undef M000367f8_eu
#undef M0003680a_eu
#undef M0003680b_eu
#undef FUN_000167c8
/* ---- from build/var/mod/parts/p11bd4.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_000104b0(int step); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_00011a04(void); /* module prototype */
/* FUN_00011bd4: the "start the adventure?" screen: show the party sheet, wait for yes (4: finish creation) or no (3), then restore the cursor shapes */
extern void FUN_00016588(int), FUN_0001550c(int, int, int, int, int); 
#define M00036808_eu ((short *)((char *)&B00036808_eu)) /* STANDIN: the first bytes of the object */
extern int DAT_000304cc; extern unsigned char DAT_000304c4[]; 
void FUN_00011bd4(void) { int done, r; DAT_00030904 = DAT_00030908; DAT_0003090c = DAT_00030910; DAT_00030908 = 0x2f; DAT_00030910 = 0x30; FUN_000107e4(0, 6); FUN_00016588(B00037138_eu); FUN_000104b0(6); FUN_0001550c(*(int *)&B00037138_eu, 0xc8, 0, 0xc8, 0x140); B00037138_eu ^= 1; done = 0; do { r = FUN_0001043c(); switch (r) { case 4: *(short *)((char *)M00036808_eu + DAT_000304cc * 0x248) = 0x8000; DAT_000304c4[DAT_000304cc] = 0; DAT_00030940 = 2; case 3: done = 1; } } while (!done); DAT_00030904 = DAT_00030908; DAT_0003090c = DAT_00030910; DAT_00030908 = 1; DAT_00030910 = 1; FUN_00011a04(); FUN_000107e4(0, 6); }

/* ---- from build/var/mod/parts/p11cd0.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_00011a04(void); /* module prototype */
extern void FUN_00011bd4(void); /* module prototype */
/* FUN_00011cd0: character creation menu: pick member slot 1 or 2 (start the adventure when it is already made, else start making it), or leave */
extern void FUN_00017830(void *); 
#define B0003685a_eu (*(unsigned char (*)[])((char *)&B000367f8_eu + 98)) /* STANDIN: view, B000367f8_eu + 0x62 */

#define B00036903_eu ((int *)((char *)&B0003685a_eu + 169)) /* STANDIN: view, B0003685a_eu + 0xa9 */
#define B00036907_eu ((int *)((char *)&B0003685a_eu + 173)) /* STANDIN: view, B0003685a_eu + 0xad */
extern int DAT_000304cc; extern unsigned char DAT_000304c4[], DAT_000304c5;  extern void *DAT_0003095c, *DAT_00030960;
void FUN_00011cd0(void) { int done, k; unsigned r; FUN_00011a04(); if (DAT_000304c4[0] && DAT_000304c5) FUN_00011464(0, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, -1, -1); else FUN_00011464(0, -1, -1, 1, 1, -1, -1, -1, -1, -1, 2, -1, -1); done = 0; do { r = FUN_0001043c(); if (r > 0) { if (r >= 3 && r <= 4) { k = r - 3; DAT_000304cc = k; if (DAT_000304c4[k]) FUN_00011bd4(); else { FUN_000115b0(-1, -1, -1, -1); ++DAT_000304d0; DAT_000304cc = k; k *= 0x248; *(int *)((char *)B00036903_eu + k) = 0; *(int *)((char *)B00036907_eu + k) = 0; done = 1; } } } else { DAT_000304cc = -1; done = 1; } } while (!done); if (DAT_0003095c) { FUN_00017830(DAT_0003095c); DAT_0003095c = 0; } if (DAT_00030960) { FUN_00017830(DAT_00030960); DAT_00030960 = 0; } }

/* ---- from build/var/mod/parts/p11dd8.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
#define FUN_000166c0 ((void (*)(unsigned char *, int, int, int, int))FUN_000166c0)
struct SR { short size, n, w; unsigned char hb, flag; unsigned char data[1]; };
extern int DAT_000304cc; 
extern void FUN_000165c0(int, int, int, int), FUN_000165e8(int, int, int, int);

/* FUN_00011dd8 @ 00011dd8: alignment choice screen (buttons 3 and 4) for the current character, or step back */
void FUN_00011dd8(void) { unsigned k; int done; FUN_00011464(0, -1, -1, 0xc, 0xd, -1, -1, -1, -1, -1, 8, -1, 0x26); done = 0; do { k = FUN_0001043c(); if (k > 0) { if (k >= 3 && k <= 4) { B0003680b_eu[DAT_000304cc * 0x248] = k - 3; ++DAT_000304d0; FUN_000115b0(k - 1, 0x114, 3, 1); done = 1; } } else { (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */ FUN_000115b0(-1, -1, -1, -1); done = 1; } } while (!done); }

#undef FUN_000166c0
/* ---- from build/var/mod/parts/p11e64.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
#define FUN_00016824 ((void (*)(int, int, int, int, int))FUN_00016824)
struct CHR { char b[0x248]; };
extern unsigned char *B00038988_eu; extern int DAT_00032908, B0003898c_eu, B00038990_eu, DAT_000304cc; 
extern unsigned char *FUN_0001954c(int, int); extern void FUN_000167c8(int, int, int, int);
 
/* FUN_00011e64 @ 00011e64: class choice screen for the current character: store the pick (or step back) */
void FUN_00011e64(void) { int k, done; FUN_00011464(1, 0, 1, 2, 3, 4, 5, -1, -1, -1, 9, -1, 0x27); done = 0; do { k = FUN_0001043c(); if (k) { B0003680c_eu[DAT_000304cc * 0x248] = k - 1; ++DAT_000304d0; FUN_000115b0(k - 1, 0x114, 0x38, 2); done = 1; } else { (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */ FUN_000115b0(-1, -1, -1, -1); done = 1; } } while (!done); }

#undef FUN_00016824
/* ---- from build/var/mod/parts/p11ee4.c */
/* FUN_00011ee4 */
void FUN_00011ee4(char *a, char *b) { char t = *a; *a = *b; *b = t; }

/* ---- from build/var/mod/parts/p11f24.c */
extern void FUN_00011ee4(char *a, char *b); /* module prototype */
#define M000367f8_eu ((struct CH *)B000367f8_eu)
/* FUN_00011f24 @ 00011f24: put the classes of the current character into the canonical multi-class order */
extern int DAT_000304cc; struct CH { char pad[0x15]; signed char cls[3]; char rest[0x248 - 0x18]; };


void FUN_00011f24(void)
{
    signed char k;
    if (M000367f8_eu[DAT_000304cc].cls[1] == -1) k = M000367f8_eu[DAT_000304cc].cls[0];
    else if (M000367f8_eu[DAT_000304cc].cls[2] == -1) {
        if (M000367f8_eu[DAT_000304cc].cls[0] == 0) {
            if (M000367f8_eu[DAT_000304cc].cls[1] == 5) k = 6;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 3) k = 7;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 4) k = 8;
        }
        if (M000367f8_eu[DAT_000304cc].cls[0] == 5) {
            if (M000367f8_eu[DAT_000304cc].cls[1] == 0) k = 6;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 3) k = 9;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 4) k = 12;
        }
        if (M000367f8_eu[DAT_000304cc].cls[0] == 2) k = 10;
        if (M000367f8_eu[DAT_000304cc].cls[0] == 3) {
            if (M000367f8_eu[DAT_000304cc].cls[1] == 0) k = 7;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 5) k = 9;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 4) k = 11;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 2) k = 10;
        }
        if (M000367f8_eu[DAT_000304cc].cls[0] == 4) {
            if (M000367f8_eu[DAT_000304cc].cls[1] == 0) k = 8;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 3) k = 11;
            if (M000367f8_eu[DAT_000304cc].cls[1] == 5) k = 12;
        }
    } else {
        if (M000367f8_eu[DAT_000304cc].cls[0] == 5 || M000367f8_eu[DAT_000304cc].cls[1] == 5 || M000367f8_eu[DAT_000304cc].cls[2] == 5) k = 13;
        else k = 14;
    }
    switch (k) {
    case 6: case 7: case 8:
        if (M000367f8_eu[DAT_000304cc].cls[0] != 0) FUN_00011ee4(&M000367f8_eu[DAT_000304cc].cls[0], &M000367f8_eu[DAT_000304cc].cls[1]);
        break;
    case 9: case 10: case 11:
        if (M000367f8_eu[DAT_000304cc].cls[0] != 3) FUN_00011ee4(&M000367f8_eu[DAT_000304cc].cls[0], &M000367f8_eu[DAT_000304cc].cls[1]);
        break;
    case 12:
        if (M000367f8_eu[DAT_000304cc].cls[0] != 4) FUN_00011ee4(&M000367f8_eu[DAT_000304cc].cls[0], &M000367f8_eu[DAT_000304cc].cls[1]);
        break;
    case 13:
        M000367f8_eu[DAT_000304cc].cls[0] = 0; M000367f8_eu[DAT_000304cc].cls[1] = 4; M000367f8_eu[DAT_000304cc].cls[2] = 5;
        break;
    case 14:
        M000367f8_eu[DAT_000304cc].cls[0] = 0; M000367f8_eu[DAT_000304cc].cls[1] = 4; M000367f8_eu[DAT_000304cc].cls[2] = 3;
        break;
    }
}

#undef M000367f8_eu
/* ---- from build/var/mod/parts/p12198.c */
void *memset(void *, int, unsigned);
extern int DAT_000304cc;

#define B0003680e_eu ((signed char *)((char *)&B000367f8_eu + 22)) /* STANDIN: view, B000367f8_eu + 0x16 */
extern signed char DAT_000306d8[], DAT_000306fc[];
#define R B0003680c_eu[DAT_000304cc * 0x248]
#define C0 B0003680d_eu[DAT_000304cc * 0x248]
#define C1 B0003680e_eu[DAT_000304cc * 0x248]
int FUN_00012198(int *f, int mode)
{
    int k, ok;
    if (mode == 0) {
        for (k = 0; k < 6; k++) f[k] = DAT_000306d8[R * 6 + k];
        ok = 0;
        for (k = 0; k < 6; k++)
            if (f[k]) ok = 1;
    } else if (mode == 1) {
        for (k = 0; k < 6; k++) f[k] = DAT_000306fc[R * 36 + C0 * 6 + k];
        ok = 0;
        for (k = 0; k < 6; k++)
            if (f[k]) ok = 1;
        return ok;
    } else if (mode == 2) {
        memset(f, 0, 0x18);
        ok = 0;
        if (R == 5) {
            if (C0 == 0) {
                if (C1 == 4) f[5] = 1;
                if (C1 == 5) f[4] = 1;
            }
            if (C0 == 4) {
                if (C1 == 0) f[5] = 1;
                if (C1 == 5) f[0] = 1;
            }
            if (C0 == 5) {
                if (C1 == 4) f[0] = 1;
                if (C1 == 0) f[4] = 1;
            }
        } else if (R == 1) {
            if (C0 == 0) {
                if (C1 == 4) {
                    f[5] = 1;
                    f[3] = 1;
                }
                if (C1 == 5) f[4] = 1;
                if (C1 == 3) f[4] = 1;
            }
            if (C0 == 4) {
                if (C1 == 0) {
                    f[5] = 1;
                    f[3] = 1;
                }
                if (C1 == 5) f[0] = 1;
                if (C1 == 3) f[0] = 1;
            }
            if (C0 == 5) {
                if (C1 == 4) f[0] = 1;
                if (C1 == 0) {
                    f[4] = 1;
                    f[3] = 1;
                }
            }
            if (C0 == 3) {
                if (C1 == 4) f[0] = 1;
                if (C1 == 0) f[4] = 1;
            }
        }
        for (k = 0; k < 6; k++)
            if (f[k]) ok = 1;
    }
    return ok;
}

#undef R
#undef C0
#undef C1
/* ---- from build/var/mod/parts/p124d4.c */
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
/* FUN_000124d4: slide a button card to (tx, ty) in nine steps, double-buffering the background under it */
/* struct P: defined above */
/* struct B: defined above */
extern struct P DAT_0003087c[];
extern struct B DAT_000308f4[];

#define PG (*(int *)&B00037138_eu)
extern void FUN_000156dc(void), FUN_00016588(int), FUN_00016c60(int, int, int, int, int), FUN_000166c0(void *, int, int, int, int), FUN_00016744(void *, int, int, int, int), FUN_000153e4(int), FUN_00017240(void *);
extern void *FUN_000171c8(int), *FUN_0001954c(int, int);
void FUN_000124d4(int btn, int tx, int ty)
{
    void *buf[2];
    int px[2];
    int py[2];
    int dx, dy;
    int x, y, k;
    FUN_000156dc();
    buf[0] = FUN_000171c8(0x1e80);
    buf[1] = FUN_000171c8(0x1e80);
    FUN_00016588(B00037138_eu);
    FUN_00016c60(0, DAT_0003087c[btn].x, DAT_0003087c[btn].y, btn + 0x1e, 7);
    x = DAT_0003087c[btn].x;
    y = DAT_0003087c[btn].y;
    FUN_000166c0(buf[0], x, y, 0x7a, 0x30);
    FUN_000166c0(buf[1], x, y, 0x7a, 0x30);
    px[0] = px[1] = x;
    py[0] = py[1] = y;
    dx = (tx - x) / 8;
    dy = (ty - y) / 8;
    for (k = 0; k <= 8; k++) {
        FUN_00016588(B00037138_eu);
        FUN_00016744(buf[PG], px[PG], py[PG], 0x7a, 0x30);
        px[PG] = x;
        py[PG] = y;
        FUN_000166c0(buf[PG], x, y, 0x7a, 0x30);
        FUN_000167c8(0, px[PG], py[PG], FUN_0001954c(DAT_000308f4[btn].spr, 7));
        y += dy;
        x += dx;
        FUN_000153e4(PG);
        B00037138_eu ^= 1;
    }
    FUN_00017240(buf[0]);
    FUN_00017240(buf[1]);
}

#undef FUN_000167c8
#undef PG
/* ---- from build/var/mod/parts/p1266c.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_000104b0(int step); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_00011f24(void); /* module prototype */
extern int FUN_00012198(int *f, int mode); /* module prototype */
extern void FUN_000124d4(int btn, int tx, int ty); /* module prototype */
#define DAT_000308f4 ((struct BT *)DAT_000308f4)
#define M0003680d_eu ((unsigned char *)B0003680d_eu)
struct BT { int a, b; };
extern int DAT_000304cc;  
extern int FUN_000153b4(void);
extern void FUN_00016588(int), FUN_000186c4(int, int, int, int);
/* FUN_0001266c @ 0001266c: class choice screen for up to three classes (multi-class): each slot offers the classes still allowed; Esc steps back a slot or leaves, Done (0xff) accepts what has been picked */
void FUN_0001266c(void)
{
    int b[6]; int k, shown; int i; int j; int res; int slot; int state; int m;
    k = 0;
    res = 0;
    shown = res;
    for (i = 0; i < 3; i++) M0003680d_eu[DAT_000304cc * 0x248 + i] = 0xff;
    state = 0;
    for (slot = 0; slot < 3 && res != -1 && !state; slot++) {
        if (!FUN_00012198(b, slot)) break;
        for (m = 0; m < 6; m++) {
            if (b[m]) b[m] = m + 6;
            else b[m] = 0x15;
        }
        if (shown) {
            if (slot) FUN_000124d4(k - 1, 0x114, 0x6d);
            for (j = 0; j < 6; j++) {
                if (b[j] != 0x15) {
                    if (!slot) {
                        DAT_000308f4[j].a = DAT_000308f4[j].b;
                        DAT_000308f4[j].b = b[j];
                    } else {
                        DAT_000308f4[j].b = b[j];
                        DAT_000308f4[j].a = b[j];
                    }
                } else {
                    DAT_000308f4[j].a = DAT_000308f4[j].b;
                    DAT_000308f4[j].b = 0x15;
                }
            }
            FUN_00016588(B00037138_eu);
            FUN_000186c4(0xc8, 0, 0x19, 7);
            FUN_000104b0(3);
            DAT_00030940 = 0xb;
            DAT_00030948 = 3;
            FUN_000107e4(0, 6);
        } else {
            FUN_00011464(3, b[0], b[1], b[2], b[3], b[4], b[5], -1, -1, -1, 0xa, -1, 0x28);
            shown = 1;
        }
        while (FUN_000153b4()) ;
        state = 0;
        do {
            k = FUN_0001043c();
            if (k && k != 0xff) {
                if (b[k - 1] != 0x15) {
                    M0003680d_eu[DAT_000304cc * 0x248 + slot] = k - 1;
                    res = 1;
                    state = res;
                }
            } else if (k == 0xff && slot) {
                res = 1;
                state = 2;
            } else if (k == 0) {
                if (slot) {
                    for (i = 0; i < 3; i++) M0003680d_eu[DAT_000304cc * 0x248 + i] = 0xff;
                    slot = -1;
                } else res = -1;
                state = 1;
            }
        } while (!state);
        state--;
    }
    if (k && k != 0xff) FUN_000115b0(k - 1, 0x114, 0x6d, 3);
    else FUN_000115b0(-1, -1, -1, -1);
    DAT_000304d0 += res;
    if (res == 1) FUN_00011f24();
}

#undef DAT_000308f4
#undef M0003680d_eu
/* ---- from build/var/mod/parts/p128e4.c */
#define M0003680d_eu ((unsigned char *)B0003680d_eu)
#define M0003680e_eu ((unsigned char *)B0003680e_eu)
/* FUN_000128e4 */
#define B0003680f_eu ((unsigned char *)((char *)&B000367f8_eu + 23)) /* STANDIN: view, B000367f8_eu + 0x17 */
void *memset(void *, int, unsigned); extern int DAT_000304cc; 
void FUN_000128e4(int *f) { int k; for (k = 0; k < 6; k++) f[k] = 1; if (M0003680d_eu[DAT_000304cc * 0x248] == 1) { memset(f, 0, 0x18); f[0] = 1; return; } if (M0003680d_eu[DAT_000304cc * 0x248] == 5 || M0003680e_eu[DAT_000304cc * 0x248] == 5 || B0003680f_eu[DAT_000304cc * 0x248] == 5) f[0] = 0; if (M0003680d_eu[DAT_000304cc * 0x248] == 2 || M0003680e_eu[DAT_000304cc * 0x248] == 2) { f[1] = 0; f[3] = 0; f[5] = 0; } }

#undef M0003680d_eu
#undef M0003680e_eu
/* ---- from build/var/mod/parts/p12994.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_000128e4(int *f); /* module prototype */
extern int DAT_000304cc; 
 
/* FUN_00012994 @ 00012994: race choice screen: the six race buttons (greyed, 0x15, where the class rules them out); store the pick or step back */
void FUN_00012994(void)
{
    int b[6]; int i, k, done;
    FUN_000128e4(b);
    for (i = 0; i < 6; i++) {
        if (b[i]) b[i] = i + 0xe;
        else b[i] = 0x15;
    }
    FUN_00011464(3, b[0], b[1], b[2], b[3], b[4], b[5], -1, -1, -1, 0xc, -1, 0x29);
    done = 0;
    do {
        k = FUN_0001043c();
        if (k) {
            if (b[k - 1] != 0x15) {
                B00036812_eu[DAT_000304cc * 0x248] = k - 1;
                ++DAT_000304d0;
                FUN_000115b0(k - 1, 0x114, 0xa2, 4);
                done = 1;
            }
        } else {
            (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */
            FUN_000115b0(-1, -1, -1, -1);
            done = 1;
        }
    } while (!done);
}

/* ---- from build/var/mod/parts/p12a64.c */
extern int FUN_0001035c(int x, int y); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
#define DAT_000308f4 ((struct BT *)DAT_000308f4)
#define M00037138_eu (*(int *)&B00037138_eu)
#define FUN_00016588 ((void (*)(unsigned char))FUN_00016588)
/* FUN_00012a64 @ 00012a64: portrait selection for the current character: six portraits per page (three pages), the other character's portrait and slot 17 are not offered; 0xff turns the page, Esc goes back */
/* struct BT: defined above */ struct XY { int x, y; };
extern int DAT_000304cc, B0003713c_eu; extern short B000373e6_eu, B000373e8_eu;
extern unsigned char DAT_000304c4[], B00035af8_eu[];   
extern void FUN_00016c60(int, int, int, int, int);
extern void FUN_00016eb0(int, int, int, int, int, unsigned char *), FUN_000155dc(int, int, int, int, int);
extern int FUN_000153b4(void);
void FUN_00012a64(void)
{
    int page; int x; int y; int hit; int g; int prev; int state; char ok[6]; int first; int k;
    first = 1;
    page = 0;
    state = 0;
    g = B0003680b_eu[DAT_000304cc * 0x248];
    while (!state) {
        FUN_00016588(M00037138_eu);
        if (!first) for (k = 0; k < 6; k++) DAT_000308f4[k].a = DAT_000308f4[k].b;
        for (k = 0; k < 6; k++) {
            if (B0003680b_eu[(DAT_000304cc ^ 1) * 0x248] == g && DAT_000304c4[DAT_000304cc ^ 1] && B0003680a_eu[(DAT_000304cc ^ 1) * 0x248] == page + k) {
                DAT_000308f4[k].b = 0x15;
                ok[k] = 0;
            } else if (page + k == 0x11) {
                DAT_000308f4[k].b = 0x15;
                ok[k] = 0;
            } else {
                DAT_000308f4[k].b = g * 0x17 + B0003713c_eu + k + page;
                ok[k] = 1;
            }
        }
        if (first) {
            FUN_00011464(4, DAT_000308f4[0].b, DAT_000308f4[1].b, DAT_000308f4[2].b, DAT_000308f4[3].b, DAT_000308f4[4].b, DAT_000308f4[5].b, -1, -1, -1, 0xd, 4, 0x2a);
            first = 0;
        } else FUN_000107e4(0, 6);
        while (FUN_000153b4()) ;
        state = 0;
        for (;;) {
            prev = -1;
            while (!FUN_000153b4()) {
                x = B000373e6_eu; y = B000373e8_eu; hit = FUN_0001035c(x, y);
                if (prev == hit) continue;
                FUN_00016588(M00037138_eu);
                if (prev > 0 && prev != 0xff && ok[prev - 1]) {
                    FUN_00016c60(0, DAT_00030874[prev].x, DAT_00030874[prev].y, 0x14, 7);
                    FUN_00016eb0(0, DAT_00030874[prev].x + 0x15, DAT_00030874[prev].y, g * 0x17 + B0003713c_eu + prev - 1 + page, 1, B00035af8_eu);
                    FUN_000155dc(M00037138_eu, DAT_00030874[prev].x + 0x15, DAT_00030874[prev].y, 0x50, 0x30);
                }
                if (hit > 0 && hit != 0xff && ok[hit - 1]) {
                    FUN_00016c60(0, DAT_00030874[hit].x, DAT_00030874[hit].y, 0x14, 7);
                    FUN_00016c60(0, DAT_00030874[hit].x + 0x15, DAT_00030874[hit].y, g * 0x17 + B0003713c_eu + hit - 1 + page, 1);
                    FUN_000155dc(M00037138_eu, DAT_00030874[hit].x + 0x15, DAT_00030874[hit].y, 0x50, 0x30);
                }
                prev = hit;
            }
            x = B000373e6_eu; y = B000373e8_eu; hit = FUN_0001035c(x, y);
            if (hit < 0) continue;
            if (hit != 0 && hit != 0xff) {
                if (ok[hit - 1]) {
                    B0003680a_eu[DAT_000304cc * 0x248] = page + (hit - 1);
                    FUN_000115b0(hit - 1, 0x114, 0xd7, 5);
                    state = 2;
                    ++DAT_000304d0;
                }
            } else if (hit == 0xff) {
                page = (page + 6) % 0x12;
                state = 1;
            } else if (hit == 0) {
                (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */
                FUN_000115b0(-1, -1, -1, -1);
                state = 2;
            }
            if (state) break;
        }
        state--;
    }
}

#undef DAT_000308f4
#undef M00037138_eu
#undef FUN_00016588
/* ---- from build/var/mod/parts/p12dfc.c */
#define M000367f8_eu ((char *)B000367f8_eu)
/* FUN_00012dfc: type the name of the current character at column x (max characters, 0x30 pixels), with a blinking underscore cursor */
void *memset(void *, int, unsigned);
extern unsigned FUN_00017f50(void); extern void FUN_00017d68(int, int), FUN_00016588(int), FUN_00019eb0(int, int, int, int, int), FUN_0001550c(int, int, int, int, int), FUN_000153e4(int), FUN_00017d80(int, int, int, char *, int);
extern int FUN_00017de8(void), FUN_0001831c(void), FUN_000182c0(void), FUN_00017ab4(char *, int), FUN_00017b50(int, int);
extern int DAT_000304cc;  
void FUN_00012dfc(int x, int max) { int blink; int key, n; unsigned t; int w; blink = 1; FUN_00017f50(); key = 0; n = 0; memset(M000367f8_eu + DAT_000304cc * 0x248, 0, 0x10); M000367f8_eu[DAT_000304cc * 0x248] = 0; FUN_00017d68(x, 0xa0);
    while (key != 0xd) {
        FUN_00016588(B00037138_eu);
        key = FUN_00017de8();
        FUN_00019eb0(x, key, 10, 1, 0);
        t = FUN_00017f50() + 9;
        FUN_0001550c(*(int *)&B00037138_eu, x, 0x88, 10, 0x30);
    top:
        B00037138_eu ^= 1;
    poll:
        if (FUN_0001831c()) goto got;
        if (t >= FUN_00017f50()) goto poll;
        t = FUN_00017f50() + 9;
        *(char *)&blink ^= 1;
        FUN_00016588(B00037138_eu);
        if (blink) FUN_00019eb0(x, key, 10, 1, 0); else FUN_00019eb0(x, key, 10, 1, 0x5f);
        FUN_000153e4(*(int *)&B00037138_eu);
        goto top;
    got:
        FUN_00016588(B00037138_eu);
        blink = 0;
        FUN_00019eb0(x, key, 10, 1, 0x5f);
        key = FUN_000182c0();
        if (key == 8) {
            if (n) {
                FUN_00019eb0(x, 0x88, 10, 0x30, 0x5f);
                M000367f8_eu[--n + DAT_000304cc * 0x248] = 0;
            }
        } else if ((key >= 'A' && key <= 'Z' || key == ' ' || key >= '0' && key <= '9') && n < max) {
            w = FUN_00017ab4(M000367f8_eu + DAT_000304cc * 0x248, 0);
            if (FUN_00017b50((signed char)key, 0) + w < 0x30) { M000367f8_eu[n + DAT_000304cc * 0x248] = key; n++; }
        }
        FUN_00019eb0(x, 0x88, 10, 0x30, 0x5f);
        FUN_00017d80(x, 0x88, 0x30, M000367f8_eu + DAT_000304cc * 0x248, 0);
    }
}

#undef M000367f8_eu
/* ---- from build/var/mod/parts/p13020.c */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_00012dfc(int x, int max); /* module prototype */
#define DAT_00030958 (*(void **)&DAT_00030958)
#define M000367f8_eu ((char *)B000367f8_eu)
/* FUN_00013020 */
extern void FUN_00016588(int), FUN_00016c60(int, int, int, int, int), FUN_000153e4(int), FUN_00017830(void *), FUN_00017d80(int, int, int, char *, int); extern void *FUN_00017868(int, int, int, int, int);   extern int DAT_000304cc; 
void FUN_00013020(void) { FUN_00011464(6, -1, -1, -1, -1, -1, -1, -1, 0x14, -1, -1, -1, 0x2e); FUN_00016588(B00037138_eu); FUN_00016c60(0, 0x5b, 0x88, 0x14, 7); FUN_000153e4(*(int *)&B00037138_eu); B00037138_eu ^= 1; FUN_00012dfc(0x93, 0xf); if (DAT_00030958) FUN_00017830(DAT_00030958); FUN_00016588(B00037138_eu); FUN_00016c60(0, 0x5b, 0x88, 0x14, 7); FUN_00017d80(0x93, 0x88, 0x30, M000367f8_eu + DAT_000304cc * 0x248, 0); DAT_00030958 = FUN_00017868(0x5b, 0x88, 0x7a, 0x30, 0xff); DAT_0003092c = 0; DAT_00030930 = 1; FUN_000115b0(-1, -1, -1, -1); }

#undef DAT_00030958
#undef M000367f8_eu
/* ---- from build/var/mod/parts/p13138.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_00013020(void); /* module prototype */
/* FUN_00013138: run the "keep this character" dialog until it is answered: 3 = keep (back to the roll screen), 4 = done */
 
#define B00036809_eu ((unsigned char *)((char *)&B000367f8_eu + 17)) /* STANDIN: view, B000367f8_eu + 0x11 */
extern int DAT_000304cc; extern unsigned char DAT_000304c4[]; 
void FUN_00013138(void) { int done, s, r; ++DAT_000304d0; FUN_00011464(6, -1, -1, 0x2f, 0x30, -1, -1, -1, -1, -1, -1, -1, 0x2d); done = 0; (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */ do { s = DAT_000304d0; DAT_000304d0 = 0; r = FUN_0001043c(); DAT_000304d0 = s; switch (r) { case 3: FUN_000115b0(-1, -1, -1, -1); FUN_00013020(); DAT_000304c4[DAT_000304cc] = 1; *(short *)((char *)M00036808_eu + DAT_000304cc * 0x248) = 0; done = 1; break; case 4: FUN_000115b0(-1, -1, -1, -1); DAT_000304c4[DAT_000304cc] = 0; B00036809_eu[DAT_000304cc * 0x248] |= 0x80; done = 1; break; } } while (!done); }

/* ---- from build/var/mod/parts/p13208.c */
#define M0003680f_eu ((signed char *)B0003680f_eu)
/* FUN_00013208: share the starting experience between the classes of the current character and set each class level from the level table */
#define B0003681c_eu (*(char (*)[])((char *)&B000367f8_eu + 36)) /* STANDIN: view, B000367f8_eu + 0x24 */

#define B0003681e_eu ((unsigned *)((char *)&B0003681c_eu + 2)) /* STANDIN: view, B0003681c_eu + 0x2 */
#define B00036818_eu ((unsigned short *)((char *)&B000367f8_eu + 32)) /* STANDIN: view, B000367f8_eu + 0x20 */
extern int DAT_000304cc;   extern unsigned short DAT_0003057c[];
#define P (DAT_000304cc * 0x248)
void FUN_00013208(void) { int n, k, lv; n = 1; if (B0003680e_eu[P] != -1) n = 2; if (M0003680f_eu[P] != -1) n++; for (k = 0; k < n; k++) { *(unsigned *)((char *)B0003681e_eu + P + k * 4) = 35004 / n; for (lv = 0; lv < 20; lv++) if (*(unsigned *)((char *)B0003681e_eu + P + k * 4) / 1000 < *(unsigned short *)((char *)DAT_0003057c + B0003680d_eu[P + k] * 40 + lv * 2)) break; *(unsigned short *)((char *)B00036818_eu + k * 2 + P) = lv; } }

#undef M0003680f_eu
#undef P
/* ---- from build/var/mod/parts/p132f4.c */
extern int FUN_00010010(int n, int d, int b, int bonus); /* module prototype */
/* FUN_000132f4 */
#define B00036810_eu ((char *)((char *)&B000367f8_eu + 24)) /* STANDIN: view, B000367f8_eu + 0x18 */
 extern int DAT_000304cc; extern unsigned char DAT_0003082e[], DAT_0003082f[], DAT_00030830[]; 
void FUN_000132f4(void) { int i = DAT_000304cc * 0x248, c = B0003680c_eu[i] * 3; *(unsigned short *)(B00036810_eu + i) = DAT_0003082e[c]; *(unsigned short *)(B00036810_eu + i) += FUN_00010010(DAT_0003082f[c], DAT_00030830[c], 0, 0); }

/* ---- from build/var/mod/parts/p1334c.c */
extern int FUN_00010010(int n, int d, int b, int bonus); /* module prototype */
#define M0003680d_eu ((unsigned char *)B0003680d_eu)
#define M0003680e_eu ((unsigned char *)B0003680e_eu)
/* FUN_0001334c: roll the six ability scores (3d6) of the current character and the exceptional strength percentile */
#define B0003682a_eu (*(unsigned char (*)[])((char *)&B000367f8_eu + 50)) /* STANDIN: view, B000367f8_eu + 0x32 */
#define B00036836_eu (*(unsigned char (*)[])((char *)&B000367f8_eu + 62)) /* STANDIN: view, B000367f8_eu + 0x3e */
void *memset(void *, int, unsigned);  extern int DAT_000304cc; void FUN_0001334c(void) { int k; memset(&B000367f8_eu[DAT_000304cc].f32, 0, 14); for (k = 0; k < 6; k++) B0003682a_eu[DAT_000304cc * 0x248 + k * 2] = FUN_00010010(3, 6, 0, 0) + 3; if (B0003682a_eu[DAT_000304cc * 0x248] >= 0x12 && B0003680c_eu[DAT_000304cc * 0x248] != 2 && (M0003680d_eu[DAT_000304cc * 0x248] == 1 || M0003680d_eu[DAT_000304cc * 0x248] == 2 || M0003680d_eu[DAT_000304cc * 0x248] == 0 || M0003680e_eu[DAT_000304cc * 0x248] == 0 || B0003680f_eu[DAT_000304cc * 0x248] == 0)) B00036836_eu[DAT_000304cc * 0x248] = FUN_00010010(1, 100, 0, 0); }

#undef M0003680d_eu
#undef M0003680e_eu
/* ---- from build/var/mod/parts/p13404.c */
#define DAT_000304d4 ((int (*)[19])&DAT_000304d4)
#define M0003680f_eu ((signed char *)B0003680f_eu)
#define M00036818_eu ((short *)B00036818_eu)
/* FUN_00013404: apply racial limits and class minimums to the abilities, then hit points */
/* r63aj: byte-exact with three STANDIN named temps (s1, s2, l5a) and a searched declaration order; see STANDIN comments */
extern int DAT_000304cc, B0003711c_eu, B00037118_eu;
#define B0003682e_eu ((unsigned char *)((char *)&B000367f8_eu + 54)) /* STANDIN: view, B000367f8_eu + 0x36 */
#define B00036813_eu ((unsigned char *)((char *)&B000367f8_eu + 27)) /* STANDIN: view, B000367f8_eu + 0x1b */

extern unsigned char DAT_0003066c[], DAT_0003066d[], DAT_000307d4[];
extern signed char DAT_000306b4[], DAT_00030853[];
#define B00036816_eu ((short *)((char *)&B000367f8_eu + 30)) /* STANDIN: view, B000367f8_eu + 0x1e */

void FUN_00013404(void)
{
    short ts1;            /* STANDIN: s1 temp; declared first so its rough-sort entry (k=0 conf=0) gets the highest function id */
    int k, n, con, mx, race;
    unsigned char tl5a;   /* STANDIN: l5a temp; its rough-sort entry sits between race and j in id order */
    int j;
    short ts2;            /* STANDIN: s2 temp; its rough-sort entry sits between j and cls in id order */
    int cls;
    race = B0003680c_eu[DAT_000304cc * 0x248];
    for (k = 0; k < 6; k++) {
        if (B0003682a_eu[DAT_000304cc * 0x248 + k * 2] < DAT_0003066c[race * 12 + k * 2] + DAT_000306b4[race * 6 + k])
            B0003682a_eu[DAT_000304cc * 0x248 + k * 2] = DAT_0003066c[race * 12 + k * 2] + DAT_000306b4[race * 6 + k];
        if (B0003682a_eu[DAT_000304cc * 0x248 + k * 2] > DAT_0003066d[race * 12 + k * 2] + DAT_000306b4[race * 6 + k])
            B0003682a_eu[DAT_000304cc * 0x248 + k * 2] = DAT_0003066d[race * 12 + k * 2] + DAT_000306b4[race * 6 + k];
    }
    if (B0003682a_eu[DAT_000304cc * 0x248] == 18 && B00036836_eu[DAT_000304cc * 0x248] == 0)
        B00036836_eu[DAT_000304cc * 0x248]++;
    if (B0003682a_eu[DAT_000304cc * 0x248] < 18 || !(B0003680d_eu[DAT_000304cc * 0x248] == 1 || B0003680d_eu[DAT_000304cc * 0x248] == 2
        || B0003680e_eu[DAT_000304cc * 0x248] == 2 || M0003680f_eu[DAT_000304cc * 0x248] == 2 || B0003680d_eu[DAT_000304cc * 0x248] == 0
        || B0003680e_eu[DAT_000304cc * 0x248] == 0 || M0003680f_eu[DAT_000304cc * 0x248] == 0))
        B00036836_eu[DAT_000304cc * 0x248] = 0;
    for (k = 0; k < 6; k++)
        for (j = 0; j < 3; j++)
            if (B0003680d_eu[DAT_000304cc * 0x248 + j] != -1 && B0003682a_eu[DAT_000304cc * 0x248 + k * 2] < DAT_000307d4[k * 15 + B0003680d_eu[DAT_000304cc * 0x248 + j]])
                { tl5a = DAT_000307d4[k * 15 + B0003680d_eu[DAT_000304cc * 0x248 + j]]; B0003682a_eu[DAT_000304cc * 0x248 + k * 2] = tl5a; } /* STANDIN: byte copy through a named temp: the late split temp of this store (pre-sort pos 5) becomes an in-block node at the head of the j-loop group (pos 24) */
    n = 1;
    if (B0003680e_eu[DAT_000304cc * 0x248] != -1) n = 2;
    if (M0003680f_eu[DAT_000304cc * 0x248] != -1) n++;
    B0003711c_eu = 0;
    B00037118_eu = 99;
    for (k = 0; k < n; k++) {
        int c, d, sum;
        c = B0003680d_eu[DAT_000304cc * 0x248 + k];
        sum = 0;
        for (j = 0; j < *(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2); j++) {
            d = DAT_00030853[c];
            if (d < 1) d = 1;
            sum += d;
        }
        B0003711c_eu += sum;
        if (*(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2) < B00037118_eu)
            B00037118_eu = *(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2);
    }
    mx = 0;
    for (k = 0; k < n; k++)
        if (*(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2) > mx)
            mx = *(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2);
    cls = B0003680d_eu[DAT_000304cc * 0x248];
    if (B0003680e_eu[DAT_000304cc * 0x248] == 2) cls = 2;
    B0003711c_eu /= n;
    con = B0003682e_eu[DAT_000304cc * 0x248];
    race = cls / 3;
    race = DAT_000304d4[race][con];
    if (race < 0) race = 0;
    B0003711c_eu += race * mx;
    B00037118_eu += race * mx;
    B00036813_eu[DAT_000304cc * 0x248] = 10;
    if (B0003711c_eu < B00037118_eu) B0003711c_eu = B00037118_eu;
    if (*(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) < B00037118_eu)
        { ts1 = B00037118_eu; *(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) = ts1; } /* STANDIN: 16-bit copy through a named temp: late temp (pre-sort pos 2) becomes an in-block tail node (pos 10) */
    if (*(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) > B0003711c_eu)
        { ts2 = B0003711c_eu; *(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) = ts2; } /* STANDIN: 16-bit copy through a named temp: late temp (pre-sort pos 1) becomes an in-block tail node (pos 9) */
    if (*(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) == 0)
        *(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) = 1;
    if (B00036836_eu[DAT_000304cc * 0x248] > 100) B00036836_eu[DAT_000304cc * 0x248] = 100;
}

#undef DAT_000304d4
#undef M0003680f_eu
#undef M00036818_eu
/* ---- from build/var/mod/parts/p137c0.c */
extern int FUN_00010010(int n, int d, int b, int bonus); /* module prototype */
#define DAT_000304d4 ((int (*)[19])&DAT_000304d4)
#define M0003680f_eu ((signed char *)B0003680f_eu)
#define M00036818_eu ((short *)B00036818_eu)

extern int DAT_000304cc;
extern signed char DAT_00030853[];


void FUN_000137c0(void)
{
    int n, sum, cls;
    int k;
    n = 1;
    if (B0003680e_eu[DAT_000304cc * 0x248] != -1) n = 2;
    if (M0003680f_eu[DAT_000304cc * 0x248] != -1) n++;
    sum = 0;
    for (k = 0; k < n; k++) {
        cls = B0003680d_eu[DAT_000304cc * 0x248 + k];
        sum += FUN_00010010(*(short *)((char *)M00036818_eu + DAT_000304cc * 0x248 + k * 2), DAT_00030853[cls], 0, 0);
    }
    sum /= n;
    sum += DAT_000304d4[cls / 3][B0003682e_eu[DAT_000304cc * 0x248]];
    *(short *)((char *)B00036816_eu + DAT_000304cc * 0x248) = sum;
}

#undef DAT_000304d4
#undef M0003680f_eu
#undef M00036818_eu
/* ---- from build/var/mod/parts/p13884.c */
extern void FUN_00013208(void); /* module prototype */
extern void FUN_000132f4(void); /* module prototype */
extern void FUN_0001334c(void); /* module prototype */
extern void FUN_00013404(void); /* module prototype */
extern void FUN_000137c0(void); /* module prototype */
/* FUN_00013884 */

void FUN_00013884(void) { FUN_00013208(); FUN_000132f4(); FUN_0001334c(); FUN_000137c0(); FUN_00013404(); }

/* ---- from build/var/mod/parts/p138a4.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
#define M0003680f_eu ((signed char *)B0003680f_eu)
#define M00036813_eu ((signed char *)B00036813_eu)
#define M00036816_eu ((char *)B00036816_eu)
#define M00036818_eu ((char *)B00036818_eu)
extern void FUN_00016c60(int, int, int, int, int), FUN_00017df4(void *), FUN_00017e44(int, int, char *, int), FUN_00017e04(int, int, char *, int);
extern char *FUN_000188d8(int);
int sprintf(char *, const char *, ...);
char *strcpy(char *, const char *), *strcat(char *, const char *);
extern int DAT_000304cc, B00037124_eu;
extern char B000355f8_eu[], B000359f8_eu[];
#define B00035a00_eu (*(unsigned char *)((char *)&B00035a00_eu)) /* STANDIN: the first bytes of the object */

#define B0003682c_eu ((unsigned char *)((char *)&B000367f8_eu + 52)) /* STANDIN: view, B000367f8_eu + 0x34 */

extern signed char DAT_0003083f[];
#define B0003681a_eu ((char *)((char *)&B000367f8_eu + 34)) /* STANDIN: view, B000367f8_eu + 0x22 */

#define W(a) (*(short *)(a + P))

#define P (DAT_000304cc * 0x248)
void FUN_000138a4(int y, int x)
{
    int k, p, q;
    FUN_00016c60(0, y, x, 0x14, 7);
    y += 4;
    for (k = 0; k < 6; k++, y += 10) {
        if (k == B00037124_eu) {
            B00035a00_eu = 0x5a;
            FUN_00017df4(B000359f8_eu);
        }
        FUN_0001004c(B000355f8_eu, k + 0x2f);
        FUN_00017e44(y, x + 1, B000355f8_eu, 0);
        p = DAT_000304cc * 0x248;
        q = k * 2 + p;
        /* round 76: three branches, the plain form first and last - the compiler merges the two equal calls into the
           original's two blocks, and "%02d" is created ahead of "%02d/%02d" as CONST has them (0x3004c, 0x30054) */
        if (k) sprintf(B000355f8_eu, "%02d", B0003682a_eu[q]);
        else if (B00036836_eu[p]) sprintf(B000355f8_eu, "%02d/%02d", B0003682a_eu[q], B00036836_eu[p] % 100);
        else sprintf(B000355f8_eu, "%02d", B0003682a_eu[q]);
        FUN_00017e04(y, x + 0x2f, B000355f8_eu, 0);
        if (k == B00037124_eu) {
            B00035a00_eu = 8;
            FUN_00017df4(0);
        }
    }
    y += 10;
    FUN_0001004c(B000355f8_eu, k + 0x2f);
    FUN_00017e44(y, x + 1, B000355f8_eu, 0);
    FUN_00017e04(y, x + 0x2f, FUN_000188d8(W(B00036810_eu)), 0);
    y += 10;
    FUN_0001004c(B000355f8_eu, ++k + 0x2f);
    FUN_00017e44(y, x + 1, B000355f8_eu, 0);
    FUN_00017e04(y, x + 0x2f, FUN_000188d8(M00036813_eu[P] + DAT_0003083f[B0003682c_eu[P]]), 0);
    y += 10;
    FUN_0001004c(B000355f8_eu, ++k + 0x2f);
    k++;
    if (B0003680e_eu[P] != -1) FUN_0001004c(B000355f8_eu, k + 0x2f);
    FUN_00017e44(y, x + 1, B000355f8_eu, 0);
    strcpy(B000355f8_eu, FUN_000188d8(W(M00036818_eu)));
    if (B0003680e_eu[P] != -1) {
        strcat(B000355f8_eu, "/");
        strcat(B000355f8_eu, FUN_000188d8(W(B0003681a_eu)));
    }
    if (M0003680f_eu[P] != -1) {
        strcat(B000355f8_eu, "/");
        strcat(B000355f8_eu, FUN_000188d8(W(B0003681c_eu)));
    }
    FUN_00017e04(y, x + 0x2f, B000355f8_eu, 0);
    y += 10;
    k++;
    if (B00037124_eu == 10) {
        B00035a00_eu = 0x5a;
        FUN_00017df4(B000359f8_eu);
    }
    FUN_0001004c(B000355f8_eu, k + 0x2f);
    FUN_00017e44(y, x + 1, B000355f8_eu, 0);
    FUN_00017e04(y, x + 0x2f, FUN_000188d8(W(M00036816_eu)), 0);
    if (B00037124_eu == 10) {
        B00035a00_eu = 8;
        FUN_00017df4(0);
    }
}

#undef M0003680f_eu
#undef M00036813_eu
#undef M00036816_eu
#undef M00036818_eu
#undef W
#undef P
/* ---- from build/var/mod/parts/p13c58.c */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_00013404(void); /* module prototype */
extern void FUN_000138a4(int y, int x); /* module prototype */
#define DAT_00030954 (*(void **)&DAT_00030954)
#define DAT_00030958 (*(void **)&DAT_00030958)
#define M0003680d_eu ((unsigned char *)B0003680d_eu)
#define M00036816_eu ((char *)B00036816_eu)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
extern void FUN_000156dc(void), FUN_00016588(int), FUN_000155dc(int, int, int, int, int), FUN_00019eb0(int, int, int, int, int), FUN_00017830(void *);
extern int FUN_000153b4(void);
extern void *FUN_00017868(int, int, int, int, int);
extern int B00037124_eu, DAT_000304cc, DAT_000304d4;

extern short B000373e6_eu;


#define PG (*(int *)&B00037138_eu)
#define P (DAT_000304cc * 0x248)
#define ST B0003682a_eu[P + B00037124_eu * 2]
#define EX B00036836_eu[P]
#define C0 M0003680d_eu[P]
#define HP (*(short *)(M00036816_eu + P))
void FUN_00013c58(void)
{
    int done, key, v;
    void *b;
    DAT_00030924 = DAT_00030928;
    DAT_0003092c = DAT_00030930;
    DAT_00030934 = DAT_00030938;
    DAT_00030928 = 0x2c;
    DAT_00030938 = 0x2d;
    DAT_00030940 = 3;
    FUN_000107e4(6, 9);
    FUN_000156dc();
    B00037124_eu = -1;
    done = 0;
    do {
        key = FUN_0001043c();
        if (!key) {
            done = 1;
        } else if (key == 7) {
            if (B00037124_eu != -1) {
                if (B00037124_eu < 6) {
                    if (B00037124_eu == 0) {
                        if (DAT_000304d4 & 1) {
                            if (ST == 18) {
                                if (C0 == 1 || C0 == 2 || C0 == 0) EX++;
                            } else ST++;
                        } else {
                            ST = 20;
                            EX = 100;
                        }
                    } else if (DAT_000304d4 & 1) ST++;
                    else ST = 20;
                } else if (B00037124_eu == 10) {
                    if (DAT_000304d4 & 1) HP++;
                    else HP = 1000;
                }
                FUN_00013404();
                FUN_00016588(B00037138_eu);
                FUN_000138a4(0x5b, 0x88);
                FUN_000155dc(PG, 0x5b, 0x88, 0x7a, 0x30);
                while (FUN_000153b4());
            }
        } else if (key == 8) {
            v = (B000373e6_eu - 0x60) / 10;
            if (v >= 0 && v < 6 || v == 10) B00037124_eu = v;
            else B00037124_eu = -1;
            FUN_00016588(B00037138_eu);
            FUN_000138a4(0x5b, 0x88);
            FUN_000155dc(PG, 0x5b, 0x88, 0x7a, 0x30);
            while (FUN_000153b4());
        } else if (key == 9) {
            if (B00037124_eu != -1) {
                if (B00037124_eu < 6) {
                    if (B00037124_eu == 0) {
                        if (DAT_000304d4 & 1) {
                            if (ST == 18) {
                                if (EX != 1) EX--;
                                else ST--;
                            } else ST--;
                        } else {
                            ST = 0;
                            EX = 0;
                        }
                    } else if (DAT_000304d4 & 1) ST--;
                    else ST = 0;
                } else if (B00037124_eu == 10) {
                    if (DAT_000304d4 & 1) HP--;
                    else HP = 0;
                }
                FUN_00013404();
                FUN_00016588(B00037138_eu);
                FUN_000138a4(0x5b, 0x88);
                FUN_000155dc(PG, 0x5b, 0x88, 0x7a, 0x30);
                while (FUN_000153b4());
            }
        }
    } while (!done);
    B00037124_eu = -1;
    FUN_00016588(B00037138_eu);
    b = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    FUN_00019eb0(0, 0, 0x7a, 0x30, 0xfe);
    FUN_000138a4(0, 0);
    if (DAT_00030954) {
        FUN_00017830(DAT_00030954);
        DAT_00030954 = 0;
    }
    if (DAT_00030958) {
        FUN_00017830(DAT_00030958);
        DAT_00030958 = 0;
    }
    DAT_00030958 = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    DAT_00030954 = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    FUN_000167c8(0, 0, 0, b);
    FUN_00017830(b);
    DAT_00030924 = DAT_00030928;
    DAT_0003092c = DAT_00030930;
    DAT_00030934 = DAT_00030938;
    DAT_00030928 = 0x16;
    DAT_00030938 = 0x2e;
    DAT_00030940 = 0xe;
    FUN_000107e4(6, 9);
}

#undef DAT_00030954
#undef DAT_00030958
#undef M0003680d_eu
#undef M00036816_eu
#undef FUN_000167c8
#undef PG
#undef P
#undef ST
#undef EX
#undef C0
#undef HP
/* ---- from build/var/mod/parts/p140fc.c */
extern void FUN_0001004c(char *buf, int k); /* module prototype */
extern int FUN_0001043c(void); /* module prototype */
extern void FUN_000107e4(int lo, int hi); /* module prototype */
extern void FUN_00011464(int scr, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9, int b10, int msg); /* module prototype */
extern void FUN_000115b0(int sel, int tx, int ty, int arg); /* module prototype */
extern void FUN_00013138(void); /* module prototype */
extern void FUN_00013884(void); /* module prototype */
extern void FUN_000138a4(int y, int x); /* module prototype */
extern void FUN_00013c58(void); /* module prototype */
#define DAT_00030954 (*(void **)&DAT_00030954)
#define DAT_00030958 (*(void **)&DAT_00030958)
#define M00037138_eu (*(int *)&B00037138_eu)
#define FUN_00016588 ((void (*)(unsigned char))FUN_00016588)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
/* FUN_000140fc @ 000140fc: character review screen: Esc leaves (back), 7 rerolls the portrait and stats, 8 accepts, 9 renames */
extern int B00037124_eu; extern char *DAT_000304b8;
 extern char B00037140_eu[];
extern unsigned FUN_00017f50(void); void srand(unsigned); extern void FUN_00019eb0(int, int, int, int, int);
extern void FUN_00017830(void *), FUN_00016c60(int, int, int, int, int);
extern void FUN_000153e4(int), FUN_00017d80(int, int, int, char *, int);
extern void FUN_00015780(void), FUN_0001a3e8(int, int, int, int, int, int, int), FUN_000157dc(void);
 extern void *FUN_00017868(int, int, int, int, int);
void FUN_000140fc(void)
{
    int r; void *spr; int k;
    srand(FUN_00017f50());
    FUN_00013884();
    B00037124_eu = -1;
    FUN_00016588(M00037138_eu);
    spr = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    FUN_00019eb0(0, 0, 0x7a, 0x30, 0xfe);
    FUN_000138a4(0, 0);
    DAT_00030958 = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
    FUN_000167c8(0, 0, 0, spr);
    FUN_00017830(spr);
    FUN_00011464(5, -1, -1, -1, -1, -1, -1, 0x16, 2, 0x2e, 0xe, -1, 0x2b);
    do {
        FUN_00016588(M00037138_eu);
        FUN_000167c8(0, 0x5b, 0x88, DAT_00030958);
        FUN_00016c60(0, 0x5b, 0xbd, 0x2e, 7);
        FUN_000153e4(M00037138_eu);
        M00037138_eu ^= 1;
        FUN_00016588(M00037138_eu);
        FUN_000167c8(0, 0x5b, 0x88, DAT_00030958);
        FUN_00016c60(0, 0x5b, 0xbd, 0x2e, 7);
        FUN_000153e4(M00037138_eu);
        M00037138_eu ^= 1;
        r = 0;
        do {
            k = FUN_0001043c();
            if (k == 0) {
                r = 2;
                FUN_000115b0(-1, -1, -1, -1);
                (*(int *)((char *)&DAT_000304cc + 4))--; /* STANDIN: plain view of DAT_000304d0 through its neighbour: dec dword ptr */
            } else if (k == 7) {
                if (DAT_00030954) FUN_00017830(DAT_00030954);
                DAT_00030954 = DAT_00030958;
                FUN_00013884();
                FUN_00016588(M00037138_eu);
                spr = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
                FUN_00019eb0(0, 0, 0x7a, 0x30, 0xfe);
                FUN_000138a4(0, 0);
                DAT_00030958 = FUN_00017868(0, 0, 0x7a, 0x30, 0xff);
                FUN_000167c8(0, 0, 0, spr);
                FUN_00017830(spr);
                DAT_00030924 = DAT_00030928;
                DAT_00030934 = DAT_00030938;
                DAT_0003092c = DAT_00030930;
                DAT_00030930 ^= 1;
                FUN_000107e4(7, 8);
                r = 1;
            } else if (k == 8) {
                FUN_000115b0(-1, -1, -1, -1);
                FUN_00013138();
                r = 2;
                ++DAT_000304d0;
            } else if (k == 9) {
                FUN_0001004c(B00037140_eu, 0x2c);
                FUN_00016588(M00037138_eu);
                FUN_00016c60(0, 5, 0, 0x2a, 7);
                FUN_00017d80(5, 0, 0x140, B00037140_eu, 1);
                FUN_00015780();
                FUN_0001a3e8(M00037138_eu ^ 1, 5, 0, 5, 0, 0x14, 0x140);
                FUN_000157dc();
                FUN_00013c58();
                strcpy(B00037140_eu, DAT_000304b8);
                FUN_00016588(M00037138_eu);
                FUN_00016c60(0, 5, 0, 0x2a, 7);
                FUN_00017d80(5, 0, 0x140, B00037140_eu, 1);
                FUN_00015780();
                FUN_0001a3e8(M00037138_eu ^ 1, 5, 0, 5, 0, 0x14, 0x140);
                FUN_000157dc();
                r = 1;
            }
        } while (!r);
    } while (!--r);
    if (DAT_00030954) {
        FUN_00017830(DAT_00030954);
        DAT_00030954 = 0;
    }
    if (DAT_00030958) {
        FUN_00017830(DAT_00030958);
        DAT_00030958 = 0;
    }
}

#undef DAT_00030954
#undef DAT_00030958
#undef M00037138_eu
#undef FUN_00016588
#undef FUN_000167c8
/* ---- from build/var/mod/parts/p144e4.c */
/* FUN_000144e4: normalise a (heading, step) pair: 24 wraps to 20/-2, -4 to 0/2 */
void FUN_000144e4(int *a, int *b) { int s, t; s = *a; t = *b; s += t; if (s == 0x18) { s = 0x14; t = -2; } if (s == -4) { s = 0; t = 2; } *a = s; *b = t; }

/* ---- from build/var/mod/parts/p14520.c */
extern void FUN_000144e4(int *a, int *b); /* module prototype */
#define M00037138_eu (*(int *)&B00037138_eu)
#define FUN_00016588 ((void (*)(unsigned char))FUN_00016588)
#define FUN_000167c8 ((void (*)(int, int, int, void *))FUN_000167c8)
/* One module (-3s -ot -d1+): FUN_00014520 draws the hit-point bar, FUN_000145fc the title animation; the
   initialiser image of FUN_000145fc's frame table sits between them in _TEXT, as in the original */
extern void *FUN_0001954c(int, int); extern void FUN_0001a5c8(int, void *), FUN_00016c98(int, int, int, int, int), FUN_00016c60(int, int, int, int, int);
void FUN_00014520(int a, int b) { int v = a; if (a == 0x16) { FUN_0001a5c8(0, FUN_0001954c(0x3d, 7)); FUN_00016c98(0, 0xe5, a - b, 0x3d, 7); FUN_0001a5c8(0, FUN_0001954c(0x3d, 7)); } else if (a == -2) { FUN_00016c98(0, 0xe5, a - b, 0x3d, 7); } else { if (b > 0) FUN_0001a5c8(0, FUN_0001954c(0x3c, 7)); FUN_00016c98(0, 0xe5, v, 0x3c, 7); if (b > 0) FUN_0001a5c8(0, FUN_0001954c(0x3c, 7)); } FUN_00016c60(0, 0xe5, 0, 0x3b, 7); }

extern void *FUN_0001954c(int, int); extern void FUN_0001a5c8(int, void *), FUN_00016c98(int, int, int, int, int), FUN_00016c60(int, int, int, int, int);

/* FUN_000145fc @ 000145fc: title animation: the logo frames and the two banner passes with their sounds, then the remaining title sprites */
 extern unsigned char B000364f8_eu[]; extern void *B00037130_eu; extern int B0003712c_eu;
extern void FUN_000186c4(int, int, int, int), FUN_00014520(int, int), FUN_00016c60(int, int, int, int, int), FUN_0001a390(int), FUN_000165a4(unsigned char);
extern void FUN_000187c4(void), FUN_000187d8(int, int), FUN_0001bc1c(int, int, int), FUN_0001bfe0(unsigned char *, int, int, int, int, int);
extern void FUN_0001c4e0(int), FUN_00017830(void *), FUN_000191d8(int, int); extern void *FUN_00017868(int, int, int, int, int);
void FUN_000145fc(void)
{
    unsigned char fr[10] = { 0x36, 0x37, 0x38, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a };
    int a, b; int k, j; void *spr;
    a = 0;
    b = 2;
    FUN_00016588(M00037138_eu);
    FUN_000186c4(0, 0, 0x1b, 7);
    FUN_000186c4(0xc8, 0, 0x1c, 7);
    B00037130_eu = FUN_00017868(0xe5, 0, 0xaa, 0x50, 0xff);
    FUN_00014520(0, 2);
    FUN_00016c60(0, 0x15f, 0x74, 0x31, 7);
    FUN_0001a390(M00037138_eu ^ 1);
    FUN_000165a4(M00037138_eu);
    M00037138_eu ^= 1;
    for (j = 0x31; j <= 0x3d; j++) FUN_0001954c(j, 7);
    FUN_00016588(M00037138_eu);
    FUN_000167c8(0, 0xe5, 0, B00037130_eu);
    spr = FUN_00017868(0x96, 0x8c, 0xe2, 0x68, 0xff);
    for (k = 0; k < 2; k++) {
        for (j = 0; j < 10; j++) {
            FUN_000187c4();
            FUN_00016588(M00037138_eu);
            FUN_000167c8(0, 0x96, 0x8c, spr);
            FUN_00016c60(0, 0x96, 0x8c, fr[k * 5 + j / 2], 7);
            FUN_000167c8(0, 0xe5, 0, B00037130_eu);
            FUN_00014520(a, b);
            FUN_000165a4(M00037138_eu);
            M00037138_eu ^= 1;
            FUN_000187d8(2, 0);
            if (k == 0 && j == 0) {
                FUN_0001bc1c(0x18, 1, 0x9c4);
                FUN_0001bfe0(B000364f8_eu, 0, 0xff, 0, 0, 0);
            }
            if (j == 1) FUN_0001c4e0(B0003712c_eu + 0xd);
            FUN_000144e4((int *)&a, (int *)&b);
        }
        for (j = 0; j < 0x19; j++) {
            FUN_000187c4();
            FUN_00016588(M00037138_eu);
            FUN_000167c8(0, 0x96, 0x8c, spr);
            if (k == 0) FUN_00016c60(0, 0x15f, 0x95, 0x32, 7);
            else FUN_00016c60(0, 0x15f, 0xb2, 0x33, 7);
            FUN_000167c8(0, 0xe5, 0, B00037130_eu);
            FUN_00014520(a, b);
            FUN_000165a4(M00037138_eu);
            M00037138_eu ^= 1;
            FUN_000187d8(2, 0);
            FUN_000144e4((int *)&a, (int *)&b);
            if (k == 0 && j == 0xf) FUN_0001c4e0(B0003712c_eu + 0xc);
        }
        FUN_00017830(spr);
        spr = FUN_00017868(0x96, 0x8c, 0xd8, 0x68, 0xff);
    }
    FUN_000191d8(0x32, 7);
    FUN_000191d8(0x33, 7);
    for (j = 0x34; j <= 0x3a; j++) FUN_000191d8(j, 7);
    FUN_00017830(spr);
    FUN_00017830(B00037130_eu);
}

#undef M00037138_eu
#undef FUN_00016588
#undef FUN_000167c8
/* ---- from build/var/mod/parts/p14978.c */
extern void FUN_000145fc(void); /* module prototype */
#define DAT_000304c4 (*(unsigned char *)&DAT_000304c4)
/* FUN_00014978 */
extern void FUN_0001c254(unsigned char *, int, int, char *, int), FUN_000157dc(void); extern int FUN_000153b4(void); extern void (*PTR_FUN_0003085c[])(void); extern int DAT_000304cc; extern unsigned char B000364f8_eu[], B000373ee_eu, DAT_000304c5; 
int FUN_00014978(void) { DAT_000304d0 = 0; FUN_0001c254(B000364f8_eu, 0, 8, "COLORS", 0x100); FUN_000145fc(); B000373ee_eu = B00037138_eu ^ 1; FUN_000157dc(); top: if (DAT_000304d0 == 7) goto reset; (*PTR_FUN_0003085c[DAT_000304d0])(); while (FUN_000153b4()); if (DAT_000304cc != -1) goto top; if (DAT_000304c4 && DAT_000304c5) return 10; return 0; reset: DAT_000304d0 = 0; goto top; }

#undef DAT_000304c4
/* ---- from build/var/mod/parts/p14a0c.c */
#define B00035ff8_eu ((unsigned char (*)[0x100])B00035ff8_eu)
extern void FUN_00015a34(unsigned char *); extern unsigned char FUN_00015b64(unsigned char, unsigned char, unsigned char, int); extern unsigned char B000364f8_eu[];
void FUN_00014a0c(void) { int lv, g, r, k, b, dr, dg, db; FUN_00015a34(B000364f8_eu); for (lv = 0; lv < 5; lv++) for (k = 0; k < 0x100; k++) { r = B000364f8_eu[k * 3]; dr = 0x3f - r; g = B000364f8_eu[k * 3 + 1]; dg = 0x3f - g; b = B000364f8_eu[k * 3 + 2]; db = 0x3f - b; dr = (dr * lv + 2) / 4; dg = (dg * lv + 2) / 4; db = (db * lv + 2) / 4; dr += r; dg += g; db += b; B00035ff8_eu[lv][k] = FUN_00015b64(dr, dg, db, 0xf); } }

#undef B00035ff8_eu
/* ---- from build/var/mod/parts/p14b00.c */
#define B000359f8_eu ((unsigned char *)B000359f8_eu)
/* FUN_00014b00 */

void FUN_00014b00(void) { int k; for (k = 0; k < 0x100; k++) B000359f8_eu[k] = k; }

#undef B000359f8_eu
/* ---- from build/var/mod/parts/p14b18.c */
/* FUN_00014b18: build the five grey-level remap tables (luminance of each palette colour, then four steps towards white) and install them */
extern void FUN_0001cbd4(unsigned char *); extern unsigned char B000364f8_eu[], B00035af8_eu[];
void FUN_00014b18(void) { int c, k; unsigned short r, g, b, t; for (c = 0; c < 0x100; c++) { r = B000364f8_eu[c * 3]; g = B000364f8_eu[c * 3 + 1]; b = B000364f8_eu[c * 3 + 2]; r = r * 300 / 1000; g = g * 590 / 1000; b = b * 110 / 1000; t = g + r + b; for (k = 0; k < 0x1c; k++) if (B000364f8_eu[k * 3] > t) break; k--; B00035af8_eu[c] = k; } for (k = 1; k < 5; k++) for (c = 0; c < 0x100; c++) { r = B000364f8_eu[B00035af8_eu[c] * 3]; t = 0x3f - r; t = (t * k + 2) / 4; r += t; for (t = 0; t < 0x1c; t++) if (B000364f8_eu[t * 3] > r) break; t--; B00035af8_eu[k * 0x100 + c] = t; } FUN_0001cbd4(B00035af8_eu); }

/* ---- from build/var/mod/parts/p14c80.c */
/* FUN_00014c80: read the 16-bit entry k of the open table file f */
extern void FUN_0001633c(int, int, int); extern void FUN_00016304(void *, int, int);
int FUN_00014c80(int k, int f) { FUN_0001633c(k * 2, 0, f); FUN_00016304((void *)&f, 2, f); return f; }

/* ---- from build/var/mod/parts/p14cb0.c */
extern int FUN_00014c80(int k, int f); /* module prototype */
/* FUN_00014cb0 */
extern int FUN_000162a8(char *); extern void FUN_00019814(char *), FUN_000162f0(int), FUN_0001b74c(int), FUN_0001c650(int); extern char *PTR_s_Error_opening_INIT_000304bc, *DAT_000304c0; extern int B00037134_eu, B0003713c_eu, B0003712c_eu, DAT_000304c8;
void FUN_00014cb0(void) { int fd = FUN_000162a8("INIT"); if (fd == -1) FUN_00019814(PTR_s_Error_opening_INIT_000304bc); B00037134_eu = FUN_00014c80(0, fd); B0003713c_eu = FUN_00014c80(2, fd); B0003712c_eu = FUN_00014c80(0xb, fd); FUN_000162f0(fd); fd = FUN_000162a8("T"); if (fd == -1) FUN_00019814(DAT_000304c0); FUN_0001b74c(5); FUN_0001c650(6); DAT_000304c8 = fd; }

/* ---- from build/var/mod/parts/p14d54.c */
#define FUN_00016304 ((int (*)(void *, int, int))FUN_00016304)
/* FUN_00014d54 */
extern int FUN_000162a8(char *); extern void *FUN_000171c8(int); extern void FUN_000162f0(int);  extern int B00037120_eu; extern void *B00037128_eu;
void FUN_00014d54(void) { int fd = FUN_000162a8("OBJECTS.DAT"); FUN_00016304(&B00037120_eu, 4, fd); if (B00037120_eu) { B00037128_eu = FUN_000171c8(B00037120_eu * 0x41); FUN_00016304(B00037128_eu, B00037120_eu * 0x41, fd); FUN_000162f0(fd); } }

#undef FUN_00016304
/* ---- from build/var/mod/parts/p14dc4.c */
extern void FUN_00014a0c(void); /* module prototype */
extern void FUN_00014b00(void); /* module prototype */
extern void FUN_00014b18(void); /* module prototype */
extern void FUN_00014cb0(void); /* module prototype */
extern void FUN_00014d54(void); /* module prototype */
#define M00036903_eu ((char *)B00036903_eu)
#define FUN_000165a4 ((void (*)(int))FUN_000165a4)
void *memset(void *, int, unsigned); extern void FUN_000195bc(void *, int), FUN_00019724(char *, int, int), FUN_000164dc(int), FUN_0001c254(unsigned char *, int, int, char *, int), FUN_00016618(unsigned char *), FUN_00019ac4(void), FUN_00016588(int), FUN_000152ac(void);  extern unsigned char B000364f8_eu[]; 
void FUN_00014dc4(void) { int p, k; FUN_000195bc("RES", 0xb); FUN_00019724("Ravenloft", 1, 0x3c); FUN_00014d54(); FUN_00014cb0(); FUN_000164dc(3); FUN_0001c254(B000364f8_eu, 0, 8, "COLORS", 0x100); FUN_00016618(B000364f8_eu); FUN_00019ac4(); FUN_00014b18(); FUN_00014b00(); FUN_00014a0c(); memset(B000364f8_eu, 0, 0x300); FUN_00016618(B000364f8_eu); FUN_0001c254(B000364f8_eu, 0, 8, "COLORS", 0x100); *(int *)&B00037138_eu = 1; FUN_00016588(B00037138_eu); FUN_000165a4(B00037138_eu ^ 1); FUN_000152ac(); memset(B000367f8_eu, -1, sizeof B000367f8_eu); for (p = 0; p < 4; p++) { B00036809_eu[p * 0x248] |= 0x80; for (k = 0; k < 4; k++) ((int *)(M00036903_eu + p * 0x248))[k] = 0; } }

#undef M00036903_eu
#undef FUN_000165a4
/* ---- from build/var/mod/parts/p14ef0.c */
#define M0003680d_eu ((unsigned char *)B0003680d_eu)
#define M0003680e_eu ((unsigned char *)B0003680e_eu)
#define B00036814_eu ((short *)((char *)&B000367f8_eu + 28)) /* STANDIN: view, B000367f8_eu + 0x1c */
#define B0003682b_eu ((unsigned char *)((char *)&B000367f8_eu + 51)) /* STANDIN: view, B000367f8_eu + 0x33 */
#define B00036929_eu ((unsigned char *)((char *)&B000367f8_eu + 305)) /* STANDIN: view, B000367f8_eu + 0x131 */
void *memset(void *, int, unsigned); extern void FUN_000163a4(char *), FUN_000162f0(int), FUN_00016320(void *, int, int); extern int FUN_000162d8(char *), FUN_000162c0(char *);  
void FUN_00014ef0(void) { int k, p, fd; for (p = 0; p < 2; p++) { memset(B000367f8_eu[p].r10b, 0, (char *)&B000367f8_eu[p + 1] - (char *)B000367f8_eu[p].r10b); B00036813_eu[p * 0x248] = 10; *(short *)((char *)B00036814_eu + p * 0x248) = *(short *)((char *)B00036816_eu + p * 0x248); for (k = 0; k < 7; k++) B0003682b_eu[p * 0x248 + k * 2] = B0003682a_eu[p * 0x248 + k * 2]; B00036929_eu[p * 0x248] = 0; if (M0003680d_eu[p * 0x248] == 3 || M0003680e_eu[p * 0x248] == 3 || B0003680f_eu[p * 0x248] == 3) B00036929_eu[p * 0x248] |= 1; if (M0003680d_eu[p * 0x248] == 4 || M0003680e_eu[p * 0x248] == 4 || B0003680f_eu[p * 0x248] == 4) B00036929_eu[p * 0x248] |= 2; } FUN_000163a4("CHARS"); FUN_000162f0(FUN_000162d8("CHARS")); fd = FUN_000162c0("CHARS"); FUN_00016320(B000367f8_eu, sizeof B000367f8_eu, fd); FUN_000162f0(fd); }

#undef M0003680d_eu
#undef M0003680e_eu
/* ---- from build/var/mod/parts/p15014.c */
extern void FUN_00014ef0(void); /* module prototype */
#define DAT_000304c4 (*(unsigned char *)&DAT_000304c4)
/* FUN_00015014 @ 00015014: leave character creation with code c (0xb: quit without saving; 0xa: save the party), then exit */
extern void FUN_0001bb80(int), FUN_0001bcb4(void), FUN_000162f0(int), FUN_0001538c(void), FUN_00019778(void), FUN_000164dc(int), FUN_00015f4c(void);
void exit(int);
#pragma aux exit aborts;
extern int DAT_000304c8; extern unsigned char DAT_000304c5;
void FUN_00015014(int c)
{
    FUN_0001bb80(0x9c4);
    FUN_0001bcb4();
    if (c != 0xb) {
        FUN_000162f0(DAT_000304c8);
        FUN_0001538c();
        FUN_00019778();
    } else c = 0xa;
    if (c != 0xa) FUN_000164dc(0xff);
    else if (DAT_000304c4 && DAT_000304c5) {
        FUN_00015f4c();
        FUN_00014ef0();
    }
    exit(c);
}

#undef DAT_000304c4
/* ---- from build/var/mod/parts/p1508c.c */
extern int FUN_00014978(void); /* module prototype */
extern void FUN_00014dc4(void); /* module prototype */
extern void FUN_00015014(int c); /* module prototype */
#include <i86.h>
struct RF { int fh, n, count; void *tab; };
extern int DAT_00032b04; extern struct RF *DAT_00032b08;
extern void FUN_0001df13(int), FUN_000187d8(int, int), FUN_0001df73(void), FUN_000161d0(char *), exit(int);
#pragma aux exit aborts;
extern int FUN_0001da1c(int, union REGS *, union REGS *);
/* main @ 0001508c: needs exactly one argument (started by the launcher), else print the message and exit(1) */
void main(int argc, char **argv) { if (argc != 2) { FUN_000161d0("Bad command or file name\n"); exit(1); } FUN_00014dc4(); FUN_00015014(FUN_00014978()); }

/* ---- module data _DATA 000304b8-0003097c (docs/data/dataown.CODE1.csv: inferred), generated by tools/data2c.py */



unsigned char DAT_000304c4[1] = { 0 };
unsigned char DAT_000304c5 = 0;
unsigned char DAT_000304c6[2] = { 0x65, 0x66 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_000304c8 = -1;
int DAT_000304cc = -1;
volatile int DAT_000304d0 = 0;
int DAT_000304d4 = 0;
unsigned char DAT_000304d8[164] = { 0xfd, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 3, 1, 3, 1, 2 };   /* no name in the sources */
unsigned short DAT_0003057c[120] = {
    0, 2, 4, 8, 0x10, 0x20, 0x40, 0x7d, 0xfa, 0x1f4, 0x2ee, 0x3e8, 0x4e2, 0x5dc, 0x6d6, 0x7d0,
    0x8ca, 0x9c4, 0xabe, 0xbb8, 0, 2, 4, 9, 0x12, 0x24, 0x4b, 0x96, 0x12c, 0x258, 0x384, 0x4b0,
    0x5dc, 0x708, 0x834, 0x960, 0xa8c, 0xbb8, 0xce4, 0xe10, 0, 2, 4, 9, 0x12, 0x24, 0x4b, 0x96,
    0x12c, 0x258, 0x384, 0x4b0, 0x5dc, 0x708, 0x834, 0x960, 0xa8c, 0xbb8, 0xce4, 0xe10, 0, 1, 3, 6,
    0xd, 0x1b, 0x37, 0x6e, 0xe1, 0x1c2, 0x2a3, 0x384, 0x465, 0x546, 0x627, 0x708, 0x7e9, 0x807, 0x9ab, 0xa8c,
    0, 2, 5, 10, 0x14, 0x28, 0x3c, 0x5a, 0x87, 0xfa, 0x177, 0x2ee, 0x465, 0x5dc, 0x753, 0x8ca,
    0xa41, 0xbb8, 0xd2f, 0xea6, 0, 1, 2, 5, 10, 0x14, 0x28, 0x46, 0x6e, 0xa0, 0xdc, 0x1b8,
    0x294, 0x370, 0x44c, 0x528, 0x604, 0x6e0, 0x7bc, 0x898
};
unsigned char DAT_0003066c[1] = { 3 };
unsigned char DAT_0003066d[71] = {
    0x12, 3, 0x12, 3, 0x12, 3, 0x12, 3, 0x12, 3, 0x12, 3, 0x12, 6, 0x12, 6,
    0x12, 4, 0x12, 3, 0x12, 3, 0x12, 7, 0x12, 7, 0x12, 10, 0x12, 6, 0x12, 3,
    0x11, 3, 0x12, 6, 0x12, 3, 0x12, 8, 0x12, 6, 0x12, 3, 0x12, 3, 0x12, 8,
    0x12, 3, 0x11, 0xb, 0x12, 3, 0x12, 3, 0x12, 3, 0x11, 3, 0x12, 6, 0x12, 7,
    0x12, 8, 0x12, 3, 0x12, 8, 0x12
};
signed char DAT_000306b4[36] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0,
    0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 1, 0, 0, -1, 0, 1,
    -1
};
signed char DAT_000306d8[36] = {
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
    1, 1, 1, 1
};
signed char DAT_000306fc[216] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 1
};
unsigned char DAT_000307d4[90] = {
    9, 0xc, 0xd, 0, 0, 0, 9, 9, 9, 0, 0xd, 0, 0, 9, 9, 0,
    0, 0xd, 0, 0, 9, 9, 0, 0, 9, 0xd, 0, 9, 9, 0, 0, 9,
    0xe, 0, 0, 0, 0, 0, 0, 0, 0xe, 0, 0, 0, 0, 0, 0, 0,
    0, 9, 0, 0, 0, 9, 0, 0, 9, 9, 9, 9, 0, 0xd, 0xe, 9,
    0, 0, 0, 9, 0, 9, 0xe, 9, 0, 0, 9, 0, 0x11
};
unsigned char DAT_0003082e[1] = { 0xf };
unsigned char DAT_0003082f[1] = { 1 };
unsigned char DAT_00030830[15] = { 4, 0xf, 1, 6, 0x14, 3, 4, 0x3c, 3, 0xc, 0x28, 5, 6, 0x64, 5 };
signed char DAT_0003083f[20] = { 6, 5, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -4 };
signed char DAT_00030853[9] = { 10, 10, 10, 8, 4, 6 };
void (*PTR_FUN_0003085c[8])(void) = { FUN_00011cd0, FUN_00011dd8, FUN_00011e64, FUN_0001266c, FUN_00012994, FUN_00012a64, FUN_000140fc };
struct P DAT_0003087c[15] = {
    0xd, 3,
    0x43, 0x38,
    0x5b, 0x6d,
    0x5b, 0xa2,
    0x43, 0xd7,
    0xd, 0x10c,
    0x5b, 0x53,
    0x5b, 0x88,
    0x5b, 0xbd,
    0x114, 3,
    0x114, 0x38,
    0x114, 0x6d,
    0x114, 0xa2,
    0x114, 0xd7,
    0x114, 0x10c
};
struct B DAT_000308f4[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int DAT_00030954[1] = { 0 };
int DAT_00030958 = 0;
void *DAT_0003095c = 0;
void *DAT_00030960 = 0;
unsigned char DAT_00030964[12] = { 0x15, 0x27, 0x28, 0x29, 0x28, 0x27, 0x15, 0x27, 0x28, 0x29, 0x28, 0x27 };
unsigned char DAT_00030970[12] = { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1 };
/* ---- end of module data _DATA */
