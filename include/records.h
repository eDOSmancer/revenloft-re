/* Record layouts of the game tables (round 46, docs/MODULES.md "Shared declarations" / record inventory).  One struct per
   record family, so that every field of a record is a member of ONE symbol (recipe 150: under -or the scheduler orders
   accesses through different symbols independently, under -oa they do not alias).  Field names are neutral (f_xx by
   offset) where the meaning is not known; the evidence per field is in the inventory table of MODULES.md.
   The structures are packed (ints at odd offsets: 0x10b, 0x113, ...). */
/* The tags (PC, SPM, SPL, ITEM, CONT, ...) are not used by any file's own structures: tools/mergemod.py renames a tag
   that two PARTS define differently but cannot do that for a header's. */
#ifndef _RECORDS_H
#define _RECORDS_H

/* one memorised-spell cell: low nibble memorised, high nibble left (f13a78, f331c0, f33438, f21630) */
struct SPM { unsigned char lo : 4, hi : 4; };

/* character record: 4 of 0x248 bytes at 0x718e0 (file CHARS, 0x920 bytes), templates of the same layout at 0x5a808 */
struct PC {
    char name[0x10];                    /* +0x00 */
    unsigned short fl;                  /* +0x10 state bits (0x4000 dead, 0x8000 gone, 0x80 ...) */
    unsigned char f12, sex, race;       /* +0x12 +0x13 +0x14 */
    signed char cls[3];                 /* +0x15 */
    unsigned char f18, f19, align;      /* +0x18 */
    signed char f1b;                    /* +0x1b */
    short hp, maxhp;                    /* +0x1c +0x1e */
    short lvl[3];                       /* +0x20 */
    int xp[3];                          /* +0x26 */
    unsigned char f32;                  /* +0x32 */
    unsigned char ab[12];               /* +0x33 str, 34, dex, 36, con, 38, int, 3a, wis, 3c, cha, 3e */
    unsigned char f3f;                  /* +0x3f */
    short inv[21];                      /* +0x40 .. +0x69 (14, 15 = +0x5c, +0x5e: the hands) */
    struct SPM mage[8][10];             /* +0x6a */
    struct SPM priest[8][10];           /* +0xba */
    unsigned char cost;                 /* +0x10a */
    int r10b[9];                        /* +0x10b the run-time part starts here (FUN_000248f0 clears +0x10b .. end) */
    signed char f12f;                   /* +0x12f spell level shown */
    unsigned char f130, sp;             /* +0x130 first spell shown, +0x131 caster bits */
    int f132;                           /* +0x132 effect bits */
    int t[26];                          /* +0x136 effect timers */
    int t19e[3], t1aa[3];               /* +0x19e ready time per hand, +0x1aa last damage per hand (FUN_0001e5f0) */
    int t1b6[2];                        /* +0x1b6 */
    int f1be, f1c2, f1c6;               /* +0x1be */
    char p1ca[0x20];
    int f1ea, f1ee, f1f2;               /* +0x1ea */
    char p1f6[0x52];
};
/* each file declares `extern struct PC DAT_000718e0[];` itself: tools/mergemod.py turns a file-level declaration that
   differs from an earlier part's into a cast view of the one symbol, which it cannot do for a header's */

/* spell panel line: 2 panels of 90 lines of 0x22 bytes at 0x75900 (0xbf4 per panel); FUN_000331c0 fills, FUN_00033438 reads */
struct SPL { char name[0x1e]; signed char lvl, idx, who, kind; };

/* item record: 0x41 bytes each in the block DAT_000755d8 points to (the pointer itself is a scalar, world.h) */
struct ITEM {
    char name[0x28];                    /* +0x00 */
    short f28;                          /* +0x28 */
    unsigned char f2a, f2b, f2c;        /* +0x2a */
    short f2d;                          /* +0x2d */
    unsigned char cls, wt;              /* +0x2f class (1 container, 0xc..0xf ...), +0x30 weight */
    signed char sub;                    /* +0x31 container type / charges */
    unsigned char p0, p1;               /* +0x32 */
    signed char acb;                    /* +0x34 */
    unsigned short kind : 2, speed : 4, rest : 10;      /* +0x35 */
    unsigned char ac, nd, ds, add, y[6];                /* +0x37 */
};
#define ITEMS ((struct ITEM *)DAT_000755d8)      /* world.h leaves struct IT incomplete: unconverted files define their own */

/* monster type: 0x45 bytes each in the block DAT_00072230 points to (the pointer is a scalar; files declare it char * / unsigned char * / void *) */
struct MTYPE { char name[0x16]; unsigned short rad; char p18[0x1a]; int imm; char p36[4]; int f3a; char p3e[7]; };

/* container type: 10 bytes each at 0x57330 */
struct CONT { unsigned char n, cols, maxw, y0, kind; short *slots; unsigned char mask; };

/* open container of a character: 4 records of 4 bytes at 0x56fa0 (FUN_000314b8 fills, FUN_00020a70 / FUN_00020bbc / FUN_00021c3c read) */
struct OPENC { signed char kind, type, st, item; };

/* monster / entity: DAT_00075618.nent records of 0x16 bytes at 0x64d80 (position 16.16, cell, type, timer, hit points) */
struct MONR {
    int a, b;                           /* +0x00 x, +0x04 y */
    unsigned char f8, f9, fa;           /* +0x08 */
    unsigned char fb0 : 1, dead : 1, fb2 : 6;   /* +0x0b */
    unsigned short s, type;             /* +0x0c cell, +0x0e type (index of struct MTYPE) */
    short timer, hp;                    /* +0x10, +0x12 */
    unsigned short w14;                 /* +0x14 */
};

/* sorted draw list: 2 lists (one per page) of 400 entries of 0x16 bytes at 0x77148 (0x2260 per list) */
struct DRAWE { unsigned short id; char p2[4]; unsigned short mon; short f8; unsigned short ord; char pc[10]; };

/* cursor record at 0x585fc: cursor enabled, sprite shown, held item and its identified flag (the image buffer at 0x58603
   follows and stays its own array symbol). Round 47: with on / spr / id / f as members of ONE symbol FUN_0002a5b0 and
   FUN_0002a724 match (as scalars they are four -oa memory nodes that order the allocator's ties); FUN_00025e38 needs at
   least id + f in it. */
struct CURSOR { short on, spr, id; unsigned char f; };

/* mouse record at 0x59e31: position, buttons, pointer shown, the page it is drawn on (the saved background at 0x59e3a
   stays its own array symbol). Round 47: FUN_00024ca4 (x, y, b), FUN_0002a5b0 / FUN_0002a724 (x, y, on, pg).
   struct MS in f1a254 / f195c0 is the first three members. */
struct MOUSE { short x, y, b, on; unsigned char pg; };

/* last clipped draw rectangle at 0x5ef69 (FUN_00039414 writes x, y and the clipped width / height; the mouse callback
   FUN_00029d18 saves and restores it around the cursor redraw). Round 49: as one symbol the module 0x29c80 object
   reproduces the original's record cuts (as four scalars their 14-byte import entries fill the import buffer at 0x29fcd,
   where the original has no cut); code-neutral there and in m390d0 (which keeps the scalars). */
struct CLIPR { short x, y, w, h; };

#endif
