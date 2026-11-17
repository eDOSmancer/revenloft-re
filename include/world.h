/* Shared declarations of the game state (round 21, docs/MODULES.md "Shared declarations"): one declaration per global,
   as the original's headers had them.  Under -oa only a named scalar global is a register candidate, so whether a
   global is a member of a structure decides code; every entry below carries its evidence in MODULES.md. */
#ifndef _WORLD_H
#define _WORLD_H

/* the level header: one record of 0x2a4 bytes at 0x75618, written to and read from the level files as a block
   (FUN_000271fc: write(B00075618_b1, 0x2a4)); map size, four per-level tables, the list counts (entities, 4-byte objects,
   doors) and the solo flag are its members.  Under -oa no member is a register candidate. */
struct LEV {
    unsigned char f0;
    short w, h;                     /* +0x01 map width (0x75619), +0x03 height (0x7561b) */
    short s5, s7;                   /* +0x05, +0x07 */
    unsigned char p9;
    short t0[64], t1[64], t2[64], t3[64];   /* +0x0a 0x75622, +0x8a 0x756a2, +0x10a 0x75722, +0x18a 0x757a2 */
    unsigned char u[0x80];          /* +0x20a 0x75822 */
    short nent, n4, ndoor;          /* +0x28a 0x758a2 entities, 0x758a4 objects, 0x758a6 doors */
    unsigned char solo, p291;       /* +0x290 0x758a8 */
    short aa[3];                    /* +0x292 0x758aa */
    unsigned char b0, b1;           /* +0x298 0x758b0, 0x758b1 */
    short b2;                       /* +0x29a 0x758b2 */
    unsigned char b4, p29d[0x2a4 - 0x29d];  /* +0x29c 0x758b4 */
};
extern struct LEV B00075618_b1;

/* party position (0x755d0 x, 0x755d4 y, 16.16 fixed point): no shared declaration.  The original reads the same bytes as
   three independent scalars: the int (FUN_00025534 changes shape when it is a member or a cast view), the cell short at
   +2 (FUN_00030a24, FUN_0002b27c: a cast or member raises the node count and swaps the operand order) and the fraction
   ushort at +0 (FUN_0002f1c8 loses its match as a cast view).  Listed as a contradiction in MODULES.md "Shared
   declarations"; each file keeps its own declaration. */

/* the loaded tables: item records (0x41 bytes each) and object types (7 bytes each).  Both pointers are scalars: under
   -oa FUN_00022180 and FUN_0002ea90 keep the item pointer in a register (as a structure member they reload it at every use
   and grow by 27 and 3 bytes).  struct IT is completed where its fields are used: the files still define different layouts,
   so they read the table through a cast to their own view. */
struct IT;
extern struct IT *B000755d8_aw;
extern unsigned char *B000755dc_aX;

/* automap size (rows, columns), copied from the map size: plain scalars (FUN_00011558 and FUN_000126e8 match only so) */
extern short B00062754_gp, B00062756_ff;
/* automap scroll origin (row, column): plain scalars. FUN_000134b0's original caches both with the store-back and reloads the
   row dead after a call (memmap SB / SD, round 59); FUN_000106c0 writes the row through because it loses the candidate tie
   there (round 60: it reads the party cells as the high halves of the 16.16 positions) */
extern int B00062740_gK, B00062744_fp;

/* saved live automap 0x56050 (block) / 0x56054 (its size): one record (round 27). fit: FUN_00012ae8 under the module's -oa
   matches only with two zero-savings global nodes fewer (the W*H product register tie, tiemodel: 4 memory nodes give W's
   register, 2 give H's); FUN_00013634 unchanged. Only these two functions use them. */
struct SAVM { void *p; int n; };
extern struct SAVM DAT_00056050;

#endif
