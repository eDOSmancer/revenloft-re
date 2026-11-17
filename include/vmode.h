/* CODE.1 0x323d4..0x32409: the video state record of module m164b0 (defined there).  One packed object: its fields
   lie at odd addresses (0x323d7, 0x323ed, 0x32401), which only a member of a byte-packed struct can have, and
   FUN_00019ca0 (assembler) fills it from &mode.  Field names follow their DAT_ addresses; each module maps the names
   it uses with #define DAT_000323xx (VID_000323d4.field); the object is named VID_000323d4 (same length as a DAT_ name: the import buffer of the object writer, recipe 17). */
#pragma pack(1)
struct VMODE {
    unsigned char mode, f5, f6;             /* 0x323d4 */
    short w, h, fdb, fdd, fdf;              /* 0x323d7: screen width, height, ... */
    unsigned char fe1[4];
    unsigned char fe5, fe6;                 /* 0x323e5: current page, display page */
    unsigned char fe7[4];
    short feb;
    int l, r, t, b;                         /* 0x323ed: clip rectangle (FUN_00016bc0, FUN_00016c44) */
    unsigned char ffd[3];
    unsigned char f400;
    short cx, cy, cw, ch;                   /* 0x32401: cursor rectangle (m150c0 struct CRECT) */
};
#pragma pack()
extern struct VMODE VID_000323d4;
