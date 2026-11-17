/* Module: FUN_00015880, FUN_000159ac, FUN_00015a34, FUN_00015b64 */
/* ---- from build/var/mod/parts/p15880.c */
/* FUN_00015880: insert colour v as node n into the RGB k-d tree rooted at node 0 (axis cycles r, g, b) */
#pragma pack(1)
struct KD { unsigned char c[3]; short idx; short left, right; };
#pragma pack()
extern struct KD DAT_00037ff0[];
void FUN_00015880(struct KD v, short n) { short prev = 0, cur = DAT_00037ff0[0].right, axis = -1, side = 1; DAT_00037ff0[n].c[1] = v.c[1]; DAT_00037ff0[n].c[0] = v.c[0]; DAT_00037ff0[n].c[2] = v.c[2]; DAT_00037ff0[n].idx = v.idx; DAT_00037ff0[n].left = DAT_00037ff0[n].right = 0x101; while (cur != 0x101) { prev = cur; if (axis == 2) axis = 0; else axis++; side = 0; if (v.c[axis] >= DAT_00037ff0[cur].c[axis]) { cur = DAT_00037ff0[cur].right; side = 1; } else cur = DAT_00037ff0[cur].left; } if (!side) DAT_00037ff0[prev].left = n; else DAT_00037ff0[prev].right = n; }

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
extern short DAT_00037ff3, DAT_00037ff5, DAT_00037ff7, DAT_000388fc, DAT_000388fe, DAT_00038900, DAT_00030982;
 
/* FUN_00015a34 @ 00015a34: feed every palette entry to FUN_00015880, from the start index down to 0 and then up to 255 */
void FUN_00015a34(unsigned char *pal)
{
    volatile struct PE e; int i, j, n;
    n = 1;
    DAT_00037ff3 = -1;
    DAT_00037ff5 = 0x101;
    DAT_00037ff7 = 0x101;
    DAT_000388fc = -1;
    DAT_000388fe = 0x101;
    DAT_00038900 = 0x101;
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
extern struct KD DAT_00037ff0[];
extern short DAT_00030980, DAT_00030982, DAT_00030984, DAT_00037bf0[];

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
    DAT_00037bf0[DAT_00030980++] = -1;
    DAT_00037bf0[DAT_00030980++] = 0;
    while (DAT_00030980 != 0 && best != 0) {
        n = DAT_00037ff0[DAT_00037bf0[--DAT_00030980]].right;
        axis = DAT_00037bf0[--DAT_00030980];
        while (n != 0x101 && best != 0) {
            DAT_00030984++;
            if (axis == 2) axis = 0; else axis++;
            v = DAT_00037ff0[n].c[axis];
            if (v > lim[axis][0]) {
                if (v <= lim[axis][1]) {
                    DAT_00037bf0[DAT_00030980++] = axis;
                    DAT_00037bf0[DAT_00030980++] = n;
                    cr = DAT_00037ff0[n].c[1];
                    cg = DAT_00037ff0[n].c[0];
                    cb = DAT_00037ff0[n].c[2];
                    dist = (cr - r) * (cr - r) + (cg - g) * (cg - g) + (cb - b) * (cb - b);
                    if (dist < best) {
                        best = dist;
                        bestn = n;
                    }
                }
                n = DAT_00037ff0[n].left;
            } else
                n = DAT_00037ff0[n].right;
        }
    }
    return DAT_00037ff0[bestn].idx;
}

#pragma pack()

/* ---- module data: _DATA 00030980-00030986 (docs/data/dataown.CODE1.csv; tools/data2c.py) */
short DAT_00030980 = 0, DAT_00030982 = 0, DAT_00030984 = 0;
