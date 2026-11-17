/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
struct KD B00037ff0_eu[257];
short B00037bf0_eu[512];
/* BSS end */
/* Module: FUN_00015880, FUN_000159ac, FUN_00015a34, FUN_00015b64 */
/* ---- from build/var/mod/parts/p15880.c */
/* FUN_00015880: insert colour v as node n into the RGB k-d tree rooted at node 0 (axis cycles r, g, b) */
#pragma pack(1)
struct KD { unsigned char c[3]; short idx; short left, right; };
#pragma pack()
extern struct KD B00037ff0_eu[];
void FUN_00015880(struct KD v, short n) { short prev = 0, cur = B00037ff0_eu[0].right, axis = -1, side = 1; B00037ff0_eu[n].c[1] = v.c[1]; B00037ff0_eu[n].c[0] = v.c[0]; B00037ff0_eu[n].c[2] = v.c[2]; B00037ff0_eu[n].idx = v.idx; B00037ff0_eu[n].left = B00037ff0_eu[n].right = 0x101; while (cur != 0x101) { prev = cur; if (axis == 2) axis = 0; else axis++; side = 0; if (v.c[axis] >= B00037ff0_eu[cur].c[axis]) { cur = B00037ff0_eu[cur].right; side = 1; } else cur = B00037ff0_eu[cur].left; } if (!side) B00037ff0_eu[prev].left = n; else B00037ff0_eu[prev].right = n; }

#pragma pack()
/* ---- from build/var/mod/parts/p159ac.c */
/* FUN_000159ac: index of the palette entry closest to (31,31,31); all 16-bit arithmetic */
short FUN_000159ac(unsigned char *pal) { short best, t, bd, g, r, b, d, k; best = 0; bd = 0x200; for (k = 0; k < 0x300; k += 3) { r = pal[k]; g = pal[k + 1]; b = pal[k + 2]; t = (r - 0x1f) * (r - 0x1f); d = t + (g - 0x1f) * (g - 0x1f) + (b - 0x1f) * (b - 0x1f); if (d < bd) { bd = d; best = k / 3; } } return best; }

/* ---- from build/var/mod/parts/p15a34.c */
extern void FUN_00015880(struct KD v, short n); /* module prototype */
extern short FUN_000159ac(unsigned char *pal); /* module prototype */
#define FUN_00015880 ((void (*)(struct PE, int))FUN_00015880)
#pragma pack(1)
struct PE { unsigned char g, r, b; short idx; short x, y; };
#pragma pack()
#define B00037ff3_eu (*(short *)((char *)&B00037ff0_eu + 3)) /* STANDIN: a name of its own in the original image, 3 bytes into B00037ff0_eu */
#define B00037ff5_eu (*(short *)((char *)&B00037ff0_eu + 5)) /* STANDIN: a name of its own in the original image, 5 bytes into B00037ff0_eu */
#define B00037ff7_eu (*(short *)((char *)&B00037ff0_eu + 7)) /* STANDIN: a name of its own in the original image, 7 bytes into B00037ff0_eu */
extern short B000388fc_eu, B000388fe_eu, B00038900_eu, DAT_00030982;
 
/* FUN_00015a34 @ 00015a34: feed every palette entry to FUN_00015880, from the start index down to 0 and then up to 255 */
void FUN_00015a34(unsigned char *pal)
{
    volatile struct PE e; int i, j, n;
    n = 1;
    B00037ff3_eu = -1;
    B00037ff5_eu = 0x101;
    B00037ff7_eu = 0x101;
    B000388fc_eu = -1;
    B000388fe_eu = 0x101;
    B00038900_eu = 0x101;
    e.x = 0;
    e.y = 0;
    i = ((int (*)(unsigned char *))FUN_000159ac)(pal);   /* TODO types: the original call does not sign-extend the short result */
    j = i + n;
    for (; (short)i > -1; i--) {
        e.r = pal[(short)(i * 3)];
        e.g = pal[(short)(i * 3) + 1];
        e.b = pal[(short)(i * 3) + 2];
        e.idx = i;
        FUN_00015880(*(struct PE *)&e, (short)n);
        n++;
    }
    for (; (short)j < 0x100; j++) {
        e.r = pal[(short)(j * 3)];
        e.g = pal[(short)(j * 3) + 1];
        e.b = pal[(short)(j * 3) + 2];
        e.idx = j;
        FUN_00015880(*(struct PE *)&e, (short)n);
        n++;
    }
    DAT_00030982 = 1;
}

#undef FUN_00015880
#pragma pack()
/* ---- from build/var/mod/parts/p15b64.c */
#pragma pack(1)
/* struct KD: defined above */
#pragma pack()
extern struct KD B00037ff0_eu[];
extern short DAT_00030980, DAT_00030982, DAT_00030984, B00037bf0_eu[];

short FUN_00015b64(unsigned char r, unsigned char g, unsigned char b, short d)
{
    short lim[3][2];
    short best, bestn, n, axis, v, dist, cr, cg, cb;

    best = 0x2e83;
    bestn = 0x101;
    if (DAT_00030982 == 0) return -1;
    DAT_00030980 = 0;
    DAT_00030984 = 0;
    lim[1][0] = r - d;
    lim[1][1] = r + d;
    lim[0][0] = g - d;
    lim[0][1] = g + d;
    lim[2][0] = b - d;
    lim[2][1] = b + d;
    B00037bf0_eu[DAT_00030980++] = -1;
    B00037bf0_eu[DAT_00030980++] = 0;
    while (DAT_00030980 != 0 && best != 0) {
        n = B00037ff0_eu[B00037bf0_eu[--DAT_00030980]].right;
        axis = B00037bf0_eu[--DAT_00030980];
        while (n != 0x101 && best != 0) {
            DAT_00030984++;
            if (axis == 2) axis = 0; else axis++;
            v = B00037ff0_eu[n].c[axis];
            if (v > lim[axis][0]) {
                if (v <= lim[axis][1]) {
                    B00037bf0_eu[DAT_00030980++] = axis;
                    B00037bf0_eu[DAT_00030980++] = n;
                    cr = B00037ff0_eu[n].c[1];
                    cg = B00037ff0_eu[n].c[0];
                    cb = B00037ff0_eu[n].c[2];
                    dist = (cr - r) * (cr - r) + (cg - g) * (cg - g) + (cb - b) * (cb - b);
                    if (dist < best) {
                        best = dist;
                        bestn = n;
                    }
                }
                n = B00037ff0_eu[n].left;
            } else
                n = B00037ff0_eu[n].right;
        }
    }
    return B00037ff0_eu[bestn].idx;
}

#pragma pack()

/* ---- module data: _DATA 00030980-00030986 (docs/data/dataown.CODE1.csv; tools/data2c.py) */
short DAT_00030980 = 0, DAT_00030982 = 0, DAT_00030984 = 0;
