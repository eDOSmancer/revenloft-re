/* Module: FUN_0001e0d0, FUN_0001e174 */
/* ---- from build/var/mod/parts/p1e0d0.c */
/* Module: FUN_0001e0d0, FUN_0001e174 */
/* ---- from build/var/mod/parts/p1e0d0.c */
/* FUN_0001e0d0 */
struct H { short a[11]; int size; char c1, c2; };
extern struct H *FUN_000171c8(int); extern int FUN_00016304(void *, int, int);
struct H *FUN_0001e0d0(char *hdr, int fd) { struct H *s, *p; s = *(struct H **)(hdr + 5); p = FUN_000171c8(0x1b + s->size); p->a[0] = s->a[0]; p->a[1] = s->a[1]; p->a[2] = s->a[2]; p->a[3] = s->a[3]; p->a[4] = s->a[4]; p->a[5] = s->a[5]; p->a[6] = s->a[6]; p->a[7] = s->a[7]; p->a[8] = s->a[8]; p->a[9] = s->a[9]; p->a[10] = s->a[10]; p->size = s->size; p->c1 = s->c1; p->c2 = s->c2; FUN_00016304(p + 1, p->size - 1, fd); return p; }

/* ---- from build/var/mod/parts/p1e174.c */
/* ---- from build/var/mod/parts/p1e174.c */
/* FUN_0001e174 */
extern void FUN_00017240(int);
void FUN_0001e174(int a) { FUN_00017240(a); }

