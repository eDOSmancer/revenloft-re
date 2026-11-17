/* Module: FUN_0003f960, FUN_0003f96c, FUN_0003f9b0, FUN_0003f9e4, FUN_0003fa30, FUN_0003fb04, FUN_0003fb68,
   FUN_0003fc48, FUN_0003fd0c, FUN_0003fd3c, FUN_0003fd9c, FUN_00040040, FUN_00040050, FUN_00040070,
   FUN_0004012c, FUN_000401a8, FUN_0004024c, FUN_00040268, FUN_00040288, FUN_000402cc, FUN_00040318,
   FUN_00040338, FUN_00040354, FUN_000403c8, FUN_00040458, FUN_000404f4, FUN_00040508, FUN_0004058c,
   FUN_00040594, FUN_0004059c, FUN_000405a8, FUN_0004060c, FUN_00040630 */
/* ---- from build/var/mod/parts/p3f960.c */
/* FUN_0003f960 @ 0003f960: setter */
extern int DAT_0005f568;
void FUN_0003f960(int v) { DAT_0005f568 = v; }

/* ---- from build/var/mod/parts/p3f96c.c */
/* Buffered byte reader over the level file: FUN_0003f96c, FUN_0003f9b0, FUN_0003f9e4, and FUN_0003fd3c which expands FUN_0003f9e4 (one -oa module; FUN_0003f9b0 is expanded inline into FUN_0003f9e4, which leaves its test duplicated). */
extern long FUN_0004131c(long, int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4; extern unsigned char DAT_0005f0d4[];
void FUN_0003f96c(void)
{
    long pos = FUN_0004131c(0, 1, DAT_0005f568);
    DAT_0005f4d8 = FUN_000412ec(DAT_0005f0d4, 0x400 - (pos & 0x3ff), DAT_0005f568);
    DAT_0005f4d4 = DAT_0005f0d4;
}

extern long FUN_0004131c(long, int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4; extern unsigned char DAT_0005f0d4[];

void FUN_0003f9b0(void)
{
    if (DAT_0005f4d8 == 0) {
        DAT_0005f4d8 = FUN_000412ec(DAT_0005f0d4, 0x400, DAT_0005f568);
        DAT_0005f4d4 = DAT_0005f0d4;
    }
}

extern long FUN_0004131c(long, int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4; extern unsigned char DAT_0005f0d4[];

unsigned short FUN_0003f9e4(void)
{
    if (DAT_0005f4d8 == 0) FUN_0003f9b0();
    DAT_0005f4d8--;
    return *DAT_0005f4d4++;
}

/* ---- from build/var/mod/parts/p3fa30.c */
/* FUN_0003fa30 @ 0003fa30: append one byte to the current picture row buffer */
extern void FUN_0003f868(void), FUN_0003a20c(int, int, unsigned char *, int, int);
extern unsigned char DAT_0007b6c3, DAT_0007b6c2, *DAT_0007b694, *DAT_0007b698, *DAT_0007b6a4; extern int DAT_0007b68c, DAT_0007b6b4, DAT_0007b688, DAT_0007b6bc;
void FUN_0003fa30(int c)
{
    int n = DAT_0007b68c + 1; unsigned char *p;
    if (DAT_0007b6c3) {
        if (DAT_0007b6c2) return;
        p = DAT_0007b694 + DAT_0007b68c;
        DAT_0007b68c = n;
        *p = c;
        if (n >= DAT_0007b6b4) {
            FUN_0003f868();
            FUN_0003a20c(DAT_0007b688, DAT_0007b6b4, DAT_0007b694, DAT_0007b6bc, DAT_0007b6a4[5]);
            DAT_0007b68c = 0;
            DAT_0007b688++;
        }
        if (DAT_0007b688 < *(short *)DAT_0007b6a4) return;
    } else {
        if (DAT_0007b6c2) return;
        p = DAT_0007b698 + DAT_0007b68c;
        DAT_0007b68c = n;
        *p = c;
        if (n < DAT_0007b6b4) return;
        FUN_0003f868();
        DAT_0007b68c = 0;
    }
    DAT_0007b6c2 = 1;
}

/* ---- from build/var/mod/parts/p3fb04.c */
/* FUN_0003fb04 @ 0003fb04 */
extern void FUN_00047700(void);
extern unsigned char DAT_0007b6c3, DAT_0007b6c2, *DAT_0007b694, *DAT_0007b698, *DAT_0007b6a4; extern int DAT_0007b68c, DAT_0007b6b4, DAT_0007b688, DAT_0007b6bc;
void FUN_0003fb04(int a, int b, int c, int d, unsigned char e)
{
    DAT_0007b6c3 = e; DAT_0007b6c2 = 0;
    DAT_0007b6a4 = (unsigned char *)b; DAT_0007b68c = 0;
    DAT_0007b688 = 0; DAT_0007b6b4 = d;
    DAT_0007b6bc = a;
    if (e) DAT_0007b694 = (unsigned char *)c; else DAT_0007b698 = (unsigned char *)c;
    FUN_00047700();
}

/* ---- from build/var/mod/parts/p3fb68.c */
/* FUN_0003fb68 @ 0003fb68: read n bytes into dst from the open file DAT_0005f568 through the 1 KB buffer DAT_0005f0d4 */
#include <string.h>
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4, DAT_0005f0d4[];
extern int FUN_000412ec(void *, unsigned, int);
void FUN_0003fb68(int n, char *dst)
{
    int k;
    if (!DAT_0005f4d8) {
        DAT_0005f4d8 = FUN_000412ec(DAT_0005f0d4, 0x400, DAT_0005f568);
        DAT_0005f4d4 = DAT_0005f0d4;
    }
    if (n <= DAT_0005f4d8) {
        memcpy(dst, DAT_0005f4d4, n);
        DAT_0005f4d4 += n;
        DAT_0005f4d8 -= n;
        return;
    }
    k = DAT_0005f4d8;
    memcpy(dst, DAT_0005f4d4, k);
    n -= k;
    DAT_0005f4d8 = FUN_000412ec(DAT_0005f0d4, 0x400, DAT_0005f568);
    memcpy(dst + k, DAT_0005f0d4, n);
    DAT_0005f4d4 = DAT_0005f0d4 + n;
    DAT_0005f4d8 -= n;
}

/* ---- from build/var/mod/parts/p3fc48.c */
extern unsigned short FUN_0003f9e4(void); /* module prototype */
extern void FUN_0003fb68(int n, char *dst); /* module prototype */
/* FUN_0003fc48 matches in module 0x3e340 (round 15): c is an unsigned char, so the second read is narrowed to dl, which is stored
   into DAT_0005f4e4[0] after the pushes and pushed as movzx eax,dl (an unsigned short c was re-read from the stream). Earlier: both
   stream reads are FUN_0003f9e4() expanded (recipe 26/38), the count decrement follows the if, the literal-run count is -c + 1,
   the first byte is stored before the memset. */
/* FUN_0003fc48 @ 0003fc48: next byte of the run-length encoded picture stream */
void *memset(void *, int, unsigned);
 
extern unsigned char DAT_0005f4dc, DAT_0005f4e4[], *DAT_0005f4e0;
unsigned char FUN_0003fc48(void)
{
    unsigned char c;
    if (0 == DAT_0005f4dc) {
        DAT_0005f4e0 = DAT_0005f4e4;
        c = FUN_0003f9e4();
        if (!((signed char)c < 0)) {
            DAT_0005f4dc = 1 + c;
            FUN_0003fb68(DAT_0005f4dc, DAT_0005f4e4);
        } else {
            DAT_0005f4dc = -c + 1;
            c = FUN_0003f9e4();
            DAT_0005f4e4[0] = c;
            memset(DAT_0005f4e4 + 1, c, DAT_0005f4dc - 1);
        }
    }
    DAT_0005f4dc--;
    return *DAT_0005f4e0++;
}

/* ---- from build/var/mod/parts/p3fd0c.c */
extern unsigned char FUN_0003fc48(void); /* module prototype */
/* FUN_0003fd0c @ 0003fd0c: decode w * h * 8 bytes of the packed stream into dst */

void FUN_0003fd0c(unsigned char *dst, int w, int h)
{
    int k, n = w * h * 8;
    for (k = 0; k < n; k++) *dst++ = FUN_0003fc48();
}

/* ---- from build/var/mod/parts/p3fd3c.c */
extern long FUN_0004131c(long, int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4; extern unsigned char DAT_0005f0d4[];

/* FUN_0003fd3c @ 0003fd3c: copy w * h * 8 raw bytes from the buffered input stream into dst.
   The loop body is FUN_0003f9e4() expanded one level, so its nested FUN_0003f9b0 call stays a call (recipe 26);
   written out with the test inline, the module's visible FUN_0003f9b0 was expanded too (kept here for that). */
void FUN_0003fd3c(unsigned char *dst, int w, int h)
{
    int k, n = w * h * 8; unsigned short c;
    for (k = 0; k < n; k++, dst++) {
        c = FUN_0003f9e4();
        *dst = c;
    }
}

/* ---- from build/var/mod/parts/p3fd9c.c */
extern void FUN_0003fb04(int a, int b, int c, int d, unsigned char e); /* module prototype */
extern unsigned char FUN_0003fc48(void); /* module prototype */
#define FUN_0003a20c ((void (*)(int, int, unsigned char *, void *, int))FUN_0003a20c)
/* MATCH (2026-11-11, round 17, in module 0x3f960 -ox -oe -oa -ot): case 3 is the expanded call FUN_0003fb04(r, h, buf, len, mode) with an int mode = 1. The parameter e is unsigned char, so the expansion assigns e = (unsigned char)mode, a conversion of a variable: copy propagation (cg cse.c PropMoves) does not carry the constant through it, so e stays a value in al (mov eax,1 ... mov [c3],al ... test al,al) and the if (e) of the body is not folded. With the literal 1 the front end folds (unsigned char)1, the parameter assignment is a constant move, PropMoves puts 1 into the store and the test and ConstFold removes the branch (real 10.0a micro-tests build/var/c3: literal folded, int variable kept). The store order c2, 8c, 88, a4, b4, c3, bc needs FUN_0003fb04's statements in CODE.1's order (DAT_0007b688 = 0 before DAT_0007b6b4 = d, as in the verified twin FUN_0001746c); both orders compile FUN_0003fb04 alone the same. Earlier: was NEAR MISS 652/676 with -oa (module m3f96c: FUN_0003f96c is inlined), 74 lines (new candidate): FUN_0003a20c is (i, len, buf, r, f), separate case counters k/i, "p = buf; m = w * h * 8;" loops; everything but case 3 matches. Left: case 3 (the inlined LZW set-up, cf. FUN_0003fb04) keeps the mode 1 in al and tests it at run time, store order c2, 8c, 88, a4, b4, c3, bc; here the test is folded (a local, the inlined FUN_0003fb04 and both store orders all fold it) CODE.1 evidence: its twin FUN_0001767c calls the set-up FUN_0001746c(r, h, buf, len, 1), whose matched source tests the global (if (DAT_000389cf)), so this case is the inlined FUN_0003fb04 with e = 1; inlining it here (with either test) still folds the constant. Also from CODE.1: cases 0/1 there call the row helpers (FUN_0001762c raw, FUN_000175f0 packed = CODE.2 FUN_0003fd3c / FUN_0003fd0c), so here they are those helpers inlined; FUN_0003fd3c is then "*dst++ = FUN_0003f9e4()" (CODE.1 FUN_0001762c calls the reader), but in a module test our compiler does not inline FUN_0003f9e4 into it (original does, without FUN_0003f9b0). 2026-11-10 (module round): case 3 written as the call FUN_0003fb04((int)r, (int)h, (int)buf, len, 1) is expanded and folds the constant too (35 lines either way); the original keeps e = 1 in eax, stores it as the last of the globals but bc and tests al, so the expanded parameter was not a known constant to its optimiser. Q1-Q4 do not apply (no register question: a missed or extra constant propagation). Not explained. */
/* Buffered byte reader over the level file: FUN_0003f96c, FUN_0003f9b0, FUN_0003f9e4 (one -oa module; FUN_0003f9b0 is expanded inline into FUN_0003f9e4, which leaves its test duplicated). */
extern long FUN_0004131c(long, int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int DAT_0005f4d8, DAT_0005f568; extern unsigned char *DAT_0005f4d4; extern unsigned char DAT_0005f0d4[];




extern void FUN_0003f580(const char *), FUN_0003f868(void), FUN_00047700(void), FUN_00047810(void *), FUN_000410b0(void *);

extern int FUN_0003a1e8(int, int, int, int, int); extern void *FUN_0004104c(int); 

#pragma pack(1)
struct SH { short n, w; unsigned char h, f, comp, fr; };
struct SR { short size, n, w; unsigned char h, f; };
#pragma pack()
/* FUN_0003fd9c @ 0003fd9c: load the sprites of resource res from file fd (raw, RLE or LZW), return the sprite set */
struct SR *FUN_0003fd9c(char *res, int fd)
{
    struct SH *h; struct SR *r; int i; struct SR *rr; int len; unsigned char *buf; int k; int sz, j, m; unsigned char *p; int mode;
    h = *(struct SH **)(res + 5);
    DAT_0005f568 = fd;
    if (h->n == 0) FUN_0003f580("Sprite file has no sprites in it");
    sz = FUN_0003a1e8(h->n, h->w, h->h, 8, h->f);
    r = FUN_0004104c(sz + 8);
    r->size = sz / h->n;
    r->w = h->w;
    r->h = h->h;
    r->n = h->n;
    r->f = (h->f != 0xff) << 7;
    len = h->w * h->h * 8;
    buf = FUN_0004104c(len);
    if (!buf) FUN_0003f580("Sprites in file too large to load");
    FUN_0003f96c();
    switch (h->comp) {
    case 0:
        for (i = 0; i < h->n; i++) {
            FUN_0003f868();
            p = buf;
            m = h->w * h->h * 8;
            for (j = 0; j < m; j++) *p++ = FUN_0003f9e4();
            FUN_0003a20c(i, len, buf, r, h->f);
        }
        break;
    case 1:
        for (k = 0; k < h->n; k++) {
            FUN_0003f868();
            p = buf;
            m = h->w * h->h * 8;
            for (j = 0; j < m; j++) *p++ = FUN_0003fc48();
            FUN_0003a20c(k, len, buf, r, h->f);
        }
        break;
    case 2:
        FUN_0003f580("Can't read LZW, not active");
        break;
    case 3:
        mode = 1;
        FUN_0003fb04((int)r, (int)h, (int)buf, len, mode);
        break;
    default:
        FUN_0003f580("Unknown compression in sprite file");
        break;
    }
    FUN_000410b0(buf);
    if (h->fr) FUN_00047810(r);
    return r;
}

#undef FUN_0003a20c
#pragma pack()
/* ---- from build/var/mod/parts/p40040.c */
extern struct SR *FUN_0003fd9c(char *res, int fd); /* module prototype */
/* Module: FUN_00040040, FUN_00040050, FUN_00040070, FUN_0004012c, FUN_000401a8, FUN_0004024c, FUN_00040268,
   FUN_00040288, FUN_000402cc, FUN_00040318, FUN_00040338, FUN_00040354, FUN_000403c8, FUN_00040458,
   FUN_000404f4, FUN_00040508, FUN_0004058c, FUN_00040594, FUN_0004059c, FUN_000405a8, FUN_0004060c,
   FUN_00040630 */
/* ---- from build/var/mod/parts/p40040.c */
/* FUN_00040040 @ 00040040: free wrapper */
extern void FUN_000410b0(void *);
void FUN_00040040(void *p) { FUN_000410b0(p); }

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p40050.c */
/* FUN_00040050 @ 00040050: byte size of image img (w * h + 8 header bytes, + 1 when flagged) */
unsigned short FUN_00040050(unsigned short *img)
{
    unsigned short n = img[0] * img[1] + 8;
    if (((unsigned char *)img)[7] & 0x80) n++;
    return n;
}

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p40070.c */
/* FUN_00040070 @ 00040070: grab a w x h sprite from the screen at (x, y) into a new buffer (header: size, 1, width, height/8, key flag, then the packed pixels, the key colour first when key != 0xff) */
struct SPR { unsigned short size, one, w; unsigned char hb, flags; unsigned char data[1]; };
extern void FUN_000392bc(void *, int, int, int, int); extern int FUN_0003a1e8(int, int, int, int, int); extern struct SPR *FUN_0004104c(int);
struct SPR *FUN_00040070(int x, int y, int w, int h, int key)
{
    int hb, sz;
    struct SPR *p, *q;
    if ((y & 3) || (h & 7)) FUN_0003f580("Invalid params passed into GrabSprite");
    hb = h / 8;
    sz = FUN_0003a1e8(1, w, hb, 8, key);
    p = FUN_0004104c((unsigned short)sz + 8);
    p->size = sz;
    p->one = 1;
    p->w = w;
    p->hb = hb;
    p->flags = (key != 0xff) << 7;
    q = p;
    FUN_000392bc(q->data + (key != 0xff), x, y, w, h);
    if (key != 0xff) q->data[0] = key;
    return q;
}

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p4012c.c */
#define FUN_000392bc ((void (*)(unsigned char *, int, int, int, int))FUN_000392bc)
struct S { unsigned short n, one, w; unsigned char h, key; };

struct S *FUN_0004012c(struct S *h, int n, int pg, int x, int y, int w, int key)
{
    struct S *r = h;
    r->n = n;
    r->w = y;
    r->h = w / 8;
    r->one = 1;
    r->key = (key != 0xff) << 7;
    FUN_000392bc((unsigned char *)(r + 1) + (key != 0xff), pg, x, y, w);
    if (key != 0xff) *(unsigned char *)(r + 1) = key;
    return r;
}

extern void FUN_000410b0(void *);


#undef FUN_000392bc
/* ---- from build/var/mod/parts/p401a8.c */
/* MATCH (2026-11-11, tie round 4, in module 0x40040 -oa): s is stepped in the for increment after i (`i++, s++`, `*s`) instead of indexed by i. With s[i] the loop optimiser strength-reduces both addresses into new temporaries, created in reverse order of their adds in the body (the assignment evaluates its right side first, so s+i before out+i: the out induction got the lower temp id and sorted first in the 162-savings tie, taking EAX by the move from the call result). With s a named basic induction variable only out+i is reduced, s keeps its own node and the increments come in the order i, s, which also gives the original schedule (inc ecx; inc esi; mov dl,[eax]; inc eax). Earlier notes: NEAR MISS SHAPE 5, 9 byte lines, 159/161 (2026-11-10, in module 0x40040 -oa): with the source pointer as a local (s = r->data after the allocation, s[i] in the loop) r is in edi, tr in ebx, i in esi as in the original (was SHAPE 7, 21 lines with r->data[i]: r->data was reloaded in every iteration, which took edi from r). Left: the two strength-reduced pointers of the loop: the original copies the allocation into ecx for out[i+4] (mov ecx,eax; 2 bytes) and loads s into eax, ours keeps out's induction in eax and s in ecx. Q1 no clobber in the loop. Q2 no: both live over the loop only. Q3 the cause: two induction values of equal use counts (load+inc, store+inc), an allocation tie (recipe 28). Q4 no. Tried: *s++ with s set before or in the for (48 lines), (out + 4)[i], out[4 + i], s in the for initialiser, declaration order s/out, int *out with ((char *)out)[i + 4] and ((char *)(out + 1))[i], while loop, without -oa (same). Earlier: declaration orders, r->data[i]. Tie round 3 (2026-11-11, instrument gate IDENTICAL in module 0x40040): the two induction pointers tie at savings 162 (out+i t34 first takes EAX by the move from the call result, s+i t37 then ECX); tiemodel on the trace: any one more surviving node (positions 0..18), or s+i listed after out+i, flips them. 4,860 instrument variants (loop forms, d = out + 4, a kept call result, tr/alloc expression forms, char/unsigned char types, memcpy forms, struct assignment, declaration orders): none adds a node or changes the code; no 10.0a compile. */
/* FUN_000401a8 @ 000401a8: unpack resource r into a new buffer (4-byte unpacked length, then the data): copy the packed bytes after the header, point a copy of r at the 8-byte trailer and decode */
#include <string.h>
#define FUN_0003f580 ((void (*)(char *))FUN_0003f580)
#define FUN_0004104c ((char *(*)(int))FUN_0004104c)
#pragma pack(1)
struct RES { unsigned char k[3]; short len; char *data; };
#pragma pack()
extern int FUN_0003f84c(void); extern void FUN_0003f83c(void), FUN_0003f844(void); 
int *FUN_000401a8(struct RES *r, int mode)
{
    char *out; char *s; char flag; int i; short *tr; struct RES t;
    if (FUN_0003f84c()) {
        FUN_0003f83c();
        flag = 1;
    }
    tr = (short *)(r->len + r->data - 8);
    out = FUN_0004104c(*tr + 4);
    s = r->data; for (i = 0; i < *tr; i++, s++) out[i + 4] = *s;
    memcpy(&t, r, sizeof(t));
    t.len = 8;
    t.data = (char *)tr;
    *(int *)out = FUN_0003fd9c(&t, mode);
    if (flag) FUN_0003f844();
    return (int *)out;
}

extern void FUN_000410b0(void *);


#undef FUN_0004104c
#pragma pack()
/* ---- from build/var/mod/parts/p4024c.c */
/* FUN_0004024c @ 0004024c */
extern void FUN_000410b0(void *);
void FUN_0004024c(void **p) { void *q = *p; FUN_000410b0(q); FUN_000410b0(p); }

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p40268.c */
/* FUN_00040268 @ 00040268: add k to every character of s (string obfuscation); returns s */
char *FUN_00040268(char *s, char k)
{
    char *r = s;
    if (s) while (*s) { *s += k; s++; }
    return r;
}

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p40288.c */
/* Font/text module (compiled with -oa, see flags.csv): FUN_00040288 .. FUN_0004060c in original order.
   FUN_00040288 (string width) is expanded inline into FUN_00040508 and FUN_000405a8 by -oe.
   FUN_000405a8 calls FUN_0004060c, which -oe also expands inline. */
extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;
int FUN_00040288(signed char *s, int font)
{
    int w;
    DAT_0007b67c = FUN_0003f29c(font, 0);
    w = 0;
    if (s) while (*s) { w += DAT_0007b67c[*s + 4]; s++; }
    return w;
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

int FUN_000402cc(signed char *s, int font, int n)
{
    int w;
    DAT_0007b67c = FUN_0003f29c(font, 0);
    w = 0;
    if (s) while (*s && n) { w += DAT_0007b67c[*s++ + 4]; n--; }
    return w;
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

int FUN_00040318(int c, int font)
{
    DAT_0007b67c = FUN_0003f29c(font, 0);
    return DAT_0007b67c[(signed char)c + 4];
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

int FUN_00040338(int font)   /* font height; not in Ghidra's function list */
{
    DAT_0007b67c = FUN_0003f29c(font, 0);
    return *(unsigned short *)(*(char **)DAT_0007b67c + 4);
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_00040354(int c, int font)
{
    DAT_0007b67c = FUN_0003f29c(font, 0);
    if (DAT_0005f56c) FUN_000393ec((signed char)c, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c, DAT_0005f56c);
    else FUN_0003939c((signed char)c, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c);
    DAT_0007b680 += DAT_0007b67c[(signed char)c + 4];
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_000403c8(signed char *s, int font)
{
    DAT_0007b67c = FUN_0003f29c(font, 0);
    if (s) while (*s) {
        if (DAT_0005f56c) FUN_000393ec(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c, DAT_0005f56c);
        else FUN_0003939c(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c);
        DAT_0007b680 += DAT_0007b67c[*s + 4];
        s++;
    }
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_00040458(signed char *s, int font, int n)   /* draw at most n characters; not in Ghidra's function list */
{
    DAT_0007b67c = FUN_0003f29c(font, 0);
    if (s) while (*s && n) {
        if (DAT_0005f56c) FUN_000393ec(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c, DAT_0005f56c);
        else FUN_0003939c(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c);
        DAT_0007b680 += DAT_0007b67c[*s + 4];
        s++;
        n--;
    }
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_000404f4(int a, int b) { DAT_0007b684 = a; DAT_0007b680 = b; }

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_00040508(int a, int b, int c, signed char *s, int font)
{
    int w;
    if (s) {
        DAT_0007b67c = FUN_0003f29c(font, 0);
        DAT_0007b684 = a;
        w = FUN_00040288(s, font);
        DAT_0007b680 = b + ((c - w) >> 1);
        FUN_000403c8(s, font);
    }
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

int FUN_0004058c(void) { return DAT_0007b684; }

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

int FUN_00040594(void) { return DAT_0007b680; }

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_0004059c(int a) { DAT_0005f56c = a; }

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_000405a8(int a, int b, signed char *s, int font)
{
    int w;
    if (s) { w = FUN_00040288(s, font); FUN_0004060c(a, b - w, s, font); }
}

extern void FUN_000410b0(void *);


extern unsigned char *FUN_0003f29c(int, int);
extern void FUN_0003939c(int, int, int, int); extern void FUN_000393ec(int, int, int, int, int);
extern unsigned char *DAT_0007b67c; extern int DAT_0007b680, DAT_0007b684, DAT_0005f56c;

void FUN_0004060c(int a, int b, signed char *s, int font)
{
    DAT_0007b684 = a; DAT_0007b680 = b;
    FUN_000403c8(s, font);
}

extern void FUN_000410b0(void *);


/* ---- from build/var/mod/parts/p40630.c */
/* FUN_00040630 @ 00040630: draw string s at (x, y) in font f, stopping when the next glyph would not fit in width w */
extern unsigned char *FUN_0003f29c(int, int); extern void FUN_000393ec(int, int, int, int, int), FUN_0003939c(int, int, int, int);
extern int DAT_0007b684, DAT_0007b680, DAT_0005f56c; extern unsigned char *DAT_0007b67c;
void FUN_00040630(int y, int x, unsigned char *s, int f, int w)
{
    DAT_0007b684 = y;
    DAT_0007b680 = x;
    DAT_0007b67c = FUN_0003f29c(f, 0);
    if (s == 0) return;
    w -= DAT_0007b67c[*s + 4];
    while (*s && w > 0) {
        if (DAT_0005f56c) FUN_000393ec(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c, DAT_0005f56c);
        else FUN_0003939c(*s, DAT_0007b684, DAT_0007b680, *(int *)DAT_0007b67c);
        DAT_0007b680 += DAT_0007b67c[*s + 4];
        w -= DAT_0007b67c[s[1] + 4];
        s++;
    }
}

#undef FUN_0003f580
#undef FUN_000392bc
#undef FUN_0004104c
#pragma pack()

/* ---- module data _DATA 0005f0d4-0005f570 (docs/data/dataown.CODE2.csv: certain), generated by tools/data2c.py */
unsigned char DAT_0005f0d4[1024] = { 0 };
unsigned char *DAT_0005f4d4 = 0;
int DAT_0005f4d8 = 0;
unsigned char DAT_0005f4dc = 0;
unsigned char DAT_0005f4dd[3] = { 0x69, 0x7a, 0x65 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
unsigned char *DAT_0005f4e0 = 0;
unsigned char DAT_0005f4e4[132] = { 0 };
int DAT_0005f568 = 0;
int DAT_0005f56c = 0;
/* ---- end of module data _DATA */
