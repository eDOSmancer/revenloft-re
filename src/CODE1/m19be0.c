/* Module: FUN_00019be0, FUN_00019c44 */
/* ---- from build/var/mod/parts/p19be0.c */
/* Module: FUN_00019be0, FUN_00019c44 */
/* ---- from build/var/mod/parts/p19be0.c */
struct CB { char b[0x18]; };
extern struct CB DAT_0003240c[]; extern int DAT_0003246c;
extern void FUN_0001da18(void), FUN_0001da1a(void), FUN_000186a4(int, int, int), FUN_0001c7a0(int, int, int, int, int), FUN_0001c8c4(int, int, int, int, int);
extern int FUN_00016a04(int, int, int, int, int, struct CB *);
/* FUN_00019be0 @ 00019be0: draw a line; a vertical one directly, else the clipped (k != 0) or plain line routine */
void FUN_00019be0(int k, int a, int b, int d, int e, int f) { if (a == b) { FUN_000186a4(e, f, d); return; } if (k) FUN_0001c7a0(a, b, d, e, f); else FUN_0001c8c4(a, b, d, e, f); }

/* ---- from build/var/mod/parts/p19c44.c */
/* ---- from build/var/mod/parts/p19c44.c */
/* FUN_00019c44 */
extern void FUN_0001cacc(int, int, int, int, int, int, int), FUN_0001c9d4(int, int, int, int, int, int, int);
void FUN_00019c44(int f, int a, int b, int c, int d, int e, int g, int h) { if (f) FUN_0001cacc(a, b, c, d, e, g, h); else FUN_0001c9d4(a, b, c, d, e, g, h); }

