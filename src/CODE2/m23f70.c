typedef void (__far *PARA_BSS)(); /* STANDIN: the _BSS of this object file is paragraph-aligned in the original (unnamed bytes ahead of it up to the 16-byte boundary); a typedef of a far pointer type raises the alignment, as a far pointer or double variable of any function would (docs/BSS.md) */
/* BSS: the uninitialised data of this module (tools/bssfit.py, docs/BSS.md). wcc386 emits these objects by size class and, in a class, last declared first; every name lies in one chain of its symbol table, so the declarations run from the highest address down. STANDIN: the names (fitted to the hash) and the F... filler objects (bytes no code names). */
short B00064064_am[22];
int B00064060_aa;
struct TM B00064024_ck[5];
int B00064020_bW;
unsigned char B00063020_bP[4096];
unsigned char B00062c20_jH[1024];
/* BSS end */
/* Module: FUN_00023f70, FUN_00023fd4, FUN_00024118, FUN_000241b8, FUN_00024218, FUN_0002430c, FUN_000246b8,
   FUN_000246dc, FUN_000248f0, FUN_00024a60, FUN_00024adc, FUN_00024be0, FUN_00024c40, FUN_00024ca4,
   FUN_00024e9c, FUN_00024fc0, FUN_00025050, FUN_00025144, FUN_00025168, FUN_0002520c, FUN_00025280,
   FUN_00025320, FUN_0002538c, FUN_000253fc, FUN_00025534, FUN_00025df8, FUN_00025e24, FUN_00025e38,
   FUN_00026400, FUN_00026034, FUN_0002608c, FUN_0002624c, FUN_0002635c, FUN_000263c4, FUN_00026524
   Verified module (2026-11-17; was a module file from tools/modfile.py, round 61). */
/* names inside DAT_00057330 (tools/dataview.py): views of the object its module defines */
extern unsigned char DAT_00057330;
#define PTR_DAT_00057335 (*(short * *)((char *)&DAT_00057330 + 0x5))
/* ---- from src/CODE2/f23f70.c */
/* FUN_00023f70 @ 00023f70: load a script block */
extern int FUN_0003ec74(int); extern void FUN_00041334(int, int); extern int FUN_000412ec(void *, unsigned, int);
extern int B000758cc_fL, DAT_00057fcc, DAT_00057fec; extern unsigned char B00063020_bP[4096];
void FUN_00023f70(int a)
{
    int n, h;
    h = FUN_0003ec74(9);
    n = 0;
    FUN_00041334(B000758cc_fL + a + DAT_00057fcc, h);
    FUN_000412ec(&n, 2, h);
    FUN_000412ec(B00063020_bP, n * 2, h);
    DAT_00057fec = 0;
}

/* ---- from src/CODE2/f23fd4.c */
/* Round 53 (module 0x23f70 -oa, 2 compiles + 1 scheduler trace with operands, wcctrace h_sched_pick now prints opcode/operands): the block 0x2405c.. is pre-scheduled as step-load(41) add x(42, height 4) brk=0(43, height 2) sp=0(44) e-load(45, height 6: eax anti-dependence on the add) ...; ScheduleIns (bottom-up) has add and brk ready after the e-load and takes the higher one (add), so brk fills the load slot. For the original order brk must not be ready before the add: brk's store must DEPEND on the add (height 6), and no tie-break (stall cost 0 both, stallable add 2 > brk 0) gives it otherwise. redefby.c: a store to v+4 (N_TEMP alias of v) and a store to the parameter x (N_TEMP) are dependent only if one is volatile, both DeAlias to one temp, or one is N_INDEXED with no base and the other USE_ADDRESS. So in the original either x had its address taken (and brk was stored through a free index) or x and brk were one aggregate - x is the parameter slot [esp+0x2c], so neither reading is a C form we know; volatile is a device. Most likely untested cause: brk (or the whole sp/brk/cnt record) accessed through a pointer the optimiser folded back to the frame (N_INDEXED kept), with x address-taken by the centring call's prototype. */
/* (FUN_00023fd4 is compiled for its neighbour: the next function's exit jumps into its epilogue) */
/* Round 52 (6 compiles + scheduler trace): `v.brk = v.sp = 0` / `v.sp = v.brk = 0` / `x = step + x` / brk before the add / a comma expression: all unchanged (the store fills the load slot of `add [x],eax`). Reading of inssched.c: two stores to different temps are independent unless one result is N_INDEXED and the other operand has USE_ADDRESS (redefby.c ZapsTemp), so the original had a dependency here that ours lacks (x address-taken, or brk stored through an index form); no natural source for either found. */
/* Round 51 (module 0x23f70 -oa, real 10.0a, ~30 compiles): SIZE EXACT (322), 2 lines left. Regions of the +18: (a) brk's dead reset and frame slot (+30 when split): sp, brk, cnt are one 12-byte local struct (frame [0]/[4]/[8] in member order; a struct temp has aliases, so SplitVars leaves it whole and InsDead keeps the reset; 8-byte structs and the 16-byte one with e are scalarised and fail); (b) the shared `brk = 1` block after the sp path (-2): the inner for(;;) exits are `e--; break;` / `e = p; break;` and `brk = 1;` follows the loop; CloneCode copies that 13-byte block into the near jump of the e = p exit, not into the short jump of the e-- exit; (c) the str copy (+2): the parameter str is the walking pointer itself (no local s); (d) `*e = c; str = e + 1;` (+2: e loaded once, lea). Left: the scheduler fills the load-use slot of `x += step` with `brk = 0` (original: no fill; every source order of the five statements tried: 2-7 lines). FUN_00024118 now matches (build). */
/* NEAR MISS Round 38 (module 0x23f70 -oa, real 10.0a, 3 compiles): the round-31 form (inner for(;;), exits `e--; brk = 1; break;` / `e = p; brk = 1; break;`, x += step before the brk reset) with `volatile int brk` gives 64 lines and 324/322 bytes (draft 66, 340/322; non-volatile 64, 292): what is left is the str copy (mov eax,[str]; mov ebp,eax instead of loading ebp) and the cnt/brk slots exchanged ([4]/[8]). So the original's brk is a memory variable whose dead reset is kept; volatile is a device and is not applied. Open: a natural reason for brk to stay in memory (address taken, aggregate member). */
/* Round 50 (FUN_00024118, 1 module compile, compare report): FUN_00024118's own code equals the original; matchlib fails it on one byte, the je displacement into FUN_00023fd4's `pop esi; pop ebx; ret`. That displacement depends only on FUN_00023fd4's epilogue shape and its end alignment (size mod 4: the filler before 0x24118 is 2 bytes in the original, 322 = 2 mod 4; ours is 340 = 0 mod 4 with 3 filler bytes after the ret), not on its exact size: any FUN_00023fd4 of the same epilogue with size = 2 mod 4 makes FUN_00024118 match in place. */
/* Round 49 (read, OW1 cg insdead.c / splitvar.c, no compile): why brk stays in memory with its dead reset. InsDead keeps every store to a temp that has a useful read anywhere (it works per name, not per web), so the reset survives exactly when brk is NOT split into webs: SplitVars skips a name only when it has aliases (op->t.alias != op), and InitVisitedTemps keeps USE_ADDRESS / VAR_VOLATILE names. The non-volatile draft is split (the reset web has no read and is freed, the test web goes to EAX and the optimiser threads the brk = 1 / test pair: 292 bytes). So the original's brk had its address taken, was volatile, or was accessed through another type (an alias); the listing shows no &brk use, so the open lever is an alias view (a union / cast access of brk) or an address taken in code that generates nothing. FUN_00024118 still waits on this function's size (its je into the epilogue). */
/* NEAR MISS (round 31, FUN_00023fd4 in module 0x23f70 -oa, 9 real compiles): the original's control flow is an inner for(;;) whose two exits store brk = 1 and jump straight to the outer `if (brk)` (no inner brk test; the space path jumps to the body top). That form (exits `e--; brk = 1; break;` / `e = p; brk = 1; break;`) gives the original jumps and 64 lines but 292/322 bytes: our brk splits into a web without the reset `brk = 0` (dead) and lives in EAX, while the original keeps the dead reset and brk in a frame slot (5 slots: sp, brk, cnt, e, lw; s in EBP). Tested: do-while(!brk), else-if chain, continue form, goto into the body (304-348 bytes, 63-115 lines). Most likely untested cause: a read of brk on a path from the reset that leaves no code. Not applied (size further from the original). */
/* Round 18: FUN_00024118 (6 lines): the `]` skip loop runs on a copy in eax in the original (split live range of s). `s++; while (*s++ != ']');` moves s and d to other registers (31 lines); p = s / p = s + 1 / `while (*s++ != '|') *d++ = s[-1]` forms stay at 6-8. Round 27 (FUN_00024118, module 0x23f70 -oa, 2 real): the original computes s+1 once at the loop top (lea eax,[esi+1]) and s then alternates between eax and esi in the inner loops; the final skip copies esi to eax, loops on eax and copies back (p not coalesced with s+1); ours coalesces p with esi. Instrument gate STRUCTURE (no trace). Tested: q in an inner block (same 26), an index k (95). Most likely untested cause: p live beyond s = p in the original (s and p both used afterwards, e.g. the outer loop continued through p). */
/* NEAR MISS (round 23, module 0x23f70 -oa, 38 worklist lines: a. first difference: a counter kept in ebp in the original lives in [esp+0x10] here, and the copies around it; allocation, no compile spent) ~35 instr (register choice): signed chars, `while (!brk)` inner loop and a local copy of the string give the original frame (5 slots, brk in memory). Remaining: the original keeps the string pointer s in ebp and the line end e in a stack slot; here e gets ebp and s is spilled. Declaration order has no effect */
/* FUN_00023fd4 @ 00023fd4: print s word-wrapped to width w in font f, one line per step; mode 1 centres each line; returns the line count */
extern void FUN_00040508(int, int, int, char *, int), FUN_0004060c(int, int, char *, int); extern int FUN_00040318(char, int);
int FUN_00023fd4(int center, int x, int y, int step, int maxw, char *s, int font)
{
    int lines, sp, len, w;
    volatile int brk; /* STANDIN: volatile keeps brk a memory name (no SplitVars web), so its dead reset brk = 0 and its frame slot stay as in the original */
    char *e, *p, c;
    lines = 0; brk = 0; sp = 0;
    if (*s) {
        e = s;
        for (;;) {
            if (brk) {
                c = *e;
                *e = 0;
                if (center == 1) FUN_00040508(x, 0, 0x140, s, font);
                else FUN_0004060c(x, y, s, font);
                lines++;
                if (c == 0) break;
                x += step;
                brk = 0;
                sp = 0;
                *e = c;
                s = e + 1;
                while (*s == ' ') s++;
            }
            len = w = 0;
            p = s;
            for (;;) {
                len += w;
                e = p;
                w = sp;
                while (*p != ' ' && *p != 0 && *p != 1) w += FUN_00040318(*p++, font);
                if (len + w > maxw) {
                    e--;
                    break;
                }
                if (*p == 0 || *p == 1) {
                    e = p;
                    break;
                }
                sp = FUN_00040318(' ', font);
                p++;
            }
            brk = 1;
        }
    }
    return lines;
}

extern void FUN_00040508(int, int, int, char *, int), FUN_0004060c(int, int, char *, int); extern int FUN_00040318(char, int);

/* Round 29 (real 10.0a in module 0x23f70 -oa, 9 variants; DOSBox match.py agrees): the ']' skip written
   `while (*p != ']') p++; s = p + 1;` gives the original's copy (mov eax,esi; loop on eax; mov esi,eax): 9 -> 1 line.
   The one line left is `je` at 0x40 into the preceding function's epilogue (rel8 -5 in the original, -6 here):
   FUN_00023fd4 compiles to 340 bytes instead of 322, so the alignment ahead of this function differs. Blocked by
   predecessor FUN_00023fd4; solve that first, then this one should match without change. */
/* + FUN_00024118 (same module: its exit jumps into this function's epilogue): NEAR MISS 5 instr, the last ']' skip loop runs on a temporary in eax (mov eax,esi; loop; mov esi,eax) in the original, here directly on s. Tried p/c temporaries, do-while, a p for the whole parse */
void *memset(void *, int, unsigned);
extern unsigned short B000718f0_hO;
/* FUN_00024118 @ 00024118: copy s to d, keeping the first alternative of each [b | a] group when several members are alive, the second when one is */
void FUN_00024118(unsigned char *s, unsigned char *d, int n)
{
    int k; int cnt; unsigned char *p;
    memset(d, 0, n);
    cnt = 0;
    for (k = 0;4 > k; k += 1) if (!(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0xc000)) cnt++;
    while (*s) {
        if (*s == '[') {
            s += 1;
            if (cnt == 1) {
                while (*s++ != '|') ;
                while (*s != ']') *d++ = *s++;
                s++;
            } else {
                while (*s != '|') *d++ = *s++;
                p = 1 + s;
                while (*p != ']') p++;
                s = p + 1;
            }
        } else *d++ = *s++;
    }
}

/* ---- from src/CODE2/f241b8.c */
extern void FUN_00024118(unsigned char *s, unsigned char *d, int n); /* module prototype */
/* FUN_000241b8 @ 000241b8 */
struct PX { unsigned short id, pad; };
extern void FUN_0002c368(void *, int); 
extern int DAT_00057fe8, DAT_00057ff4; extern struct PX DAT_00057fd8[4]; extern unsigned char DAT_0005759c[], B00062c20_jH[1024];
void FUN_000241b8(void)
{
    int k; unsigned char *buf;
    DAT_00057fe8 = 0;
    buf = B00062c20_jH;
    for (k = 0; k < 4; k++, buf += 0x100) {
        if (DAT_00057fd8[k].id != 0xffff) {
            DAT_00057fe8++;
            FUN_0002c368(DAT_0005759c, DAT_00057fd8[k].id + DAT_00057ff4);
            FUN_00024118(DAT_0005759c, buf, 0x100);
        }
    }
}

/* ---- from src/CODE2/f24218.c */
extern int FUN_00023fd4(int mode, int x, int y, int step, int w, char *str, int f); /* module prototype */
/* FUN_00024218 @ 00024218: draw the four script picture slots (names and portraits) */
/* struct PX: defined above */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0004059c(int), FUN_0004060c(int, int, char *, int), FUN_00040354(int, int); extern char *FUN_0003e6f0(int);
extern int DAT_0005c050, B000758cc_fL; extern struct PX DAT_00057fd8[4]; extern char DAT_00058000[]; extern unsigned char B00062c20_jH[1024];
void FUN_00024218(int sel, int all)
{
    int k;
    FUN_000391b0(DAT_0005c050);
    if (sel == -1) FUN_0003e510(0x1e, 0xac, B000758cc_fL + 3, 9);
    FUN_0003e510(0xdc, 0, B000758cc_fL + 2, 9);
    for (k = 0; k < 4; k++) {
        if (DAT_00057fd8[k].id != 0xffff) {
            if (k == sel) FUN_0004059c((int)DAT_00058000);
            else FUN_0004059c(0);
            if (k == sel || all) {
                FUN_0004060c(0xdd + k * 0x16, 0x17, FUN_0003e6f0(k + 1), 1);
                FUN_00040354(0x3a, 1);
                FUN_00023fd4(0, 0xdd + k * 0x16, 0x1f, 10, 0x10a, B00062c20_jH + k * 0x100, 1);
            }
        }
    }
    FUN_0004059c(0);
}

/* ---- from src/CODE2/f2430c.c */
/* the module declaration (seen through a cast view below) */ extern unsigned char B000718e0_iO;
#define M00063020_bP ((unsigned short *)B00063020_bP)
#define M000718e0_iO ((unsigned char *)&B000718e0_iO)
/* Round 53 (module 0x23f70 -oa, 2 compiles): the walk as `for (;; DAT_00057fec += 2) { p = &B00063020_bP[DAT_00057fec]; ...}` (one more 2/4 constant in the loop): 173 lines; without p (table at each use): compiler error exit. The constant tie (1 / 4 / 2 at eight uses) stands; one more use of 2 or 4 or one fewer of 1 in the loop decides it (found = 1 is the extra use of 1 here). */
/* FUN_0002430c @ 0002430c: evaluate the current script condition list against the active character; -oa without loop optimisation (-ol would cache the constant 1 in ebp) */
/* Round 49 (2 compiles, 1 trace): the replay on a new trace agrees with round 47 (constants 1 / 4 / 2 tie at 322 for EBP in pass 2; 4 or 2 first needs one INSERTED node: savings 0..283 at pre-sort 0 (for 4) / 1 (for 2), or 323..363 at 4, 6, 9, ...; no removal). The character record as struct PC (c->align, c->race, c->cls[k], c->ab[k]) compiles to the same 4 lines: neutral, not kept. Most likely untested cause unchanged: one more value in the loop in the original (a constant or a cross-block local). */
/* In module 0x23f70 (-ox -oe -oa -ot, round of 2026-11-10): the only difference is -ol: the loop optimiser puts the
   constant of `found = 1` into ebp before the loop (`mov ebp,1` ... `mov ecx,ebp`); the original has `mov ecx,1`.
   Q1 no clobber; Q2 the extra value is the hoisted constant, live over the whole loop; Q3 -; Q4 the original never
   creates that value. Matches under the module flags without -ol (-oaimr -s -oe -ot); the other module functions
   need -ol. Tried: found/tgt assignment order, the loop as while + goto, a local copy of DAT_00057fec (no -oa):
   the constant stays. Blocked. */
extern int DAT_00057fec, DAT_00057ffc;


/* Round 47 (module 0x23f70, -ol in force; 4 lines: push / pop ebp, mov ebp,1, mov ecx,ebp): the difference is NOT the flag but a three-way tie.
   Under -ol the loop's constants are CONST_TEMPs; 1, 4 and 2 have eight uses each (savings 322) and the first of them in the pass-2
   sort takes the free EBP. Ours: 1 first, and `found = 1` becomes `mov ecx,ebp`. The original must have had 4 or 2 first: neither
   has a MOV use (compares and adds keep their immediates), so EBP is never touched and 1 stays an immediate - that is the
   original's code. Replay (build/var/r47/tw.py on the real trace, equals the real sort): only an inserted node gives it (savings
   <= 283 at pre-sort 0, or >= 323 at 4, 6, 9, ...); no removal. Tried (4 compiles): p = &B00063020_bP[DAT_00057fec] at the loop
   top (173 lines), no p (1088 bytes), tgt before found = 1 (same). Most likely untested cause: one more constant in the loop in
   the original source (a ninth use of 2 or 4, or a constant the optimiser later folds away). */
int FUN_0002430c(void)
{
    int found, tgt, one; /* STANDIN: one = the constant 1 through a local (see below) */
    unsigned short *p;
    unsigned char *c;
    one = 1; /* STANDIN: copy-propagated back to an immediate; the loop CONST_TEMP for 1 is then created after those for 2 and 4 (pass-2 pre-sort position 3 instead of 1), so 2 wins the 322-savings tie for EBP; 2 has no MOV use, EBP stays untouched and found = 1 stays mov ecx,1 as in the original */
    c = M000718e0_iO + DAT_00057ffc * 0x248;
    found = 0;
    for (p = &M00063020_bP[DAT_00057fec];; p += 2, DAT_00057fec += 2) {
        if (*p == 0x21) break;
        if (*p == 0 && c[0x1a] == 0) goto hit;
        if (*p == 1 && c[0x1a] == 2) goto hit;
        if (*p == 2 && c[0x1a] == 4) goto hit;
        if (*p == 3 && c[0x1a] == 1) goto hit;
        if (*p == 4 && c[0x1a] == 3) goto hit;
        if (*p == 5 && c[0x1a] == 5) goto hit;
        if (*p == 6 && c[0x3d] > 0x10) goto hit;
        if (*p == 7 && c[0x3d] < 10) goto hit;
        if (*p == 8 && c[0x33] > 0x10) goto hit;
        if (*p == 9 && c[0x33] < 10) goto hit;
        if (*p == 0xa && c[0x39] > 0x10) goto hit;
        if (*p == 0xb && c[0x39] < 10) goto hit;
        if (*p == 0xc && c[0x35] > 0x10) goto hit;
        if (*p == 0xd && c[0x35] < 10) goto hit;
        if (*p == 0xe && c[0x37] > 0x10) goto hit;
        if (*p == 0xf && c[0x37] < 10) goto hit;
        if (*p == 0x10 && c[0x3b] > 0x10) goto hit;
        if (*p == 0x11 && c[0x3b] < 10) goto hit;
        if (*p == 0x12 && c[0x14] == 0) goto hit;
        if (*p == 0x13 && c[0x14] == 5) goto hit;
        if (*p == 0x14 && c[0x14] == 1) goto hit;
        if (*p == 0x15 && c[0x14] == 4) goto hit;
        if (*p == 0x16 && c[0x14] == 3) goto hit;
        if (*p == 0x17 && c[0x14] == 2) goto hit;
        if (*p == 0x12 && c[0x14] == 0) goto hit;
        if (*p == 0x18 && (c[0x14] == 5 || c[0x14] == 4 || c[0x14] == 3 || c[0x14] == 2)) goto hit;
        if (*p == 0x19 && (c[0x15] == 0 || c[0x16] == 0 || c[0x17] == 0)) goto hit;
        if (*p == 0x1a && ((signed char)c[0x15] == 2 || (signed char)c[0x16] == 2 || (signed char)c[0x17] == 2)) goto hit;
        if (*p == 0x1b && ((signed char)c[0x15] == 1 || (signed char)c[0x16] == 1 || (signed char)c[0x17] == 1)) goto hit;
        if (*p == 0x1c && ((signed char)c[0x15] == 4 || (signed char)c[0x16] == 4 || (signed char)c[0x17] == 4)) goto hit;
        if (*p == 0x1d && ((signed char)c[0x15] == 3 || (signed char)c[0x16] == 3 || (signed char)c[0x17] == 3)) goto hit;
        if (*p == 0x1e && ((signed char)c[0x15] == 5 || (signed char)c[0x16] == 5 || (signed char)c[0x17] == 5)) goto hit;
        if (*p == 0x1f && c[0x13] == 0) goto hit;
        if (*p == 0x20 && c[0x13] == 1) goto hit;
        continue;
    hit:
        if (!found) {
            found = one; /* STANDIN: found = 1 written through one (code: mov ecx,1) */
            tgt = p[1];
        }
    }
    if (!found) tgt = p[1];
    DAT_00057fec += 2;
    return tgt;
}

#undef M00063020_bP
#undef M000718e0_iO
/* ---- from src/CODE2/f246b8.c */
/* FUN_000246b8 @ 000246b8 */
extern void FUN_000380dc(int); extern void FUN_00037f24(int);
void FUN_000246b8(int a) { FUN_000380dc(10); FUN_00037f24(a); FUN_000380dc(6); }

/* ---- from src/CODE2/f246dc.c */
extern int FUN_00023fd4(int mode, int x, int y, int step, int w, char *str, int f); /* module prototype */
extern int FUN_0002430c(void); /* module prototype */
extern void FUN_00026034(void); /* module prototype */
/* FUN_000246dc @ 000246dc: show the next dialogue line, play its voice sample (and the reply sample) and wait for a click */
#include "snd.h"
#define FUN_0002c368 ((void (*)(unsigned char *, int))FUN_0002c368)
extern int FUN_0002a1f4(void); extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_0002a8c8(int, int, int, int, int);
#define B0006301e_ak ((unsigned short *)((char *)&B00063020_bP - 2)) /* STANDIN: view, B00063020_bP - 2 (element -1 of the table: the code indexes from 1) */
extern int DAT_00057fec, B000758cc_fL, DAT_00057ff4, DAT_0005c050, B00075614_lm, DAT_00057ff8, DAT_00057fd4;  extern unsigned char DAT_0005759c[], DAT_0005c02b;
void FUN_000246dc(void)
{
    int n, r, snd; unsigned short v, v2;
    n = DAT_00057fec + 1;
    v = B0006301e_ak[n];
    DAT_00057fec = n;
    r = FUN_0002430c();
    FUN_000391b0(DAT_0005c050);
    FUN_0003e510(0x1e, 0xac, B000758cc_fL + 3, 9);
    FUN_0002c368(DAT_0005759c, r + DAT_00057ff4);
    FUN_00023fd4(0, 0x20, 0xaf, 0xc, 0x7b, DAT_0005759c, 1);
    if (v != 0xffff && DAT_0005c02b != 0 && DAT_0005ee40 != 0) {
        snd = B00075614_lm + DAT_00057ff8 + v;
        FUN_000380dc(10);
        FUN_00037f24(snd);
        FUN_000380dc(6);
        FUN_0002a8c8(DAT_0005c050, 8, 0xa0, 0xd2, 0xa0);
        while (FUN_0002a1f4()) FUN_00026034();
        while (!FUN_0002a1f4() && FUN_000380e8()) FUN_00026034();
        FUN_00037ff0();
        if (DAT_00057fd4 == 9) {
            if (v == 2) v2 = 10;
            else v2 = 0xffff;
        } else if (DAT_00057fd4 == 0x17 && v == 0) {
            v2 = 2;
        } else {
            v2 = 0xffff;
        }
        if (v2 != 0xffff) {
            snd = B00075614_lm + DAT_00057ff8 + v2;
            FUN_000380dc(10);
            FUN_00037f24(snd);
            FUN_000380dc(6);
            while (FUN_0002a1f4()) FUN_00026034();
            while (!FUN_0002a1f4() && FUN_000380e8()) FUN_00026034();
            FUN_00037ff0();
        }
    } else {
        FUN_0002a8c8(DAT_0005c050, 8, 0xa0, 0xd2, 0xa0);
        while (FUN_0002a1f4()) FUN_00026034();
        while (!FUN_0002a1f4()) FUN_00026034();
    }
    FUN_0002a8c8(DAT_0005c050, 8, 0xa0, 0xd2, 0xa0);
}

#undef FUN_0002c368
/* ---- from src/CODE2/f248f0.c */
/* FUN_000248f0 @ 000248f0: fill party slot who from the next pregenerated character template, reset the run-time part, set up spells */
void *memmove(void *, const void *, unsigned); void *memset(void *, int, unsigned);
extern int FUN_0001dbd4(int); extern void FUN_00013ea4(int, int), FUN_00013de4(int, int);
extern int DAT_00057fec; 
#include "records.h"
#define M00063020_bP ((unsigned short *)B00063020_bP)
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
extern struct PC DAT_0005a808[];
void FUN_000248f0(int who)
{
    int t = M00063020_bP[DAT_00057fec++];
    memmove(&M000718e0_iO[who], (void *)(t * 0x248 + (int)DAT_0005a808), sizeof(struct PC));
    memset((char *)M000718e0_iO[who].r10b, 0, (char *)&M000718e0_iO[who + 1] - (char *)M000718e0_iO[who].r10b);
    M000718e0_iO[who].cost = FUN_0001dbd4(who);
    M000718e0_iO[who].sp = 0;
    if (M000718e0_iO[who].cls[0] == 1) {
        M000718e0_iO[who].sp |= 4;
        FUN_00013ea4(who, M000718e0_iO[who].lvl[0]);
    }
    if (M000718e0_iO[who].cls[0] == 4 || M000718e0_iO[who].cls[1] == 4 || M000718e0_iO[who].cls[2] == 4) {
        M000718e0_iO[who].inv[0] = 0xa6;
        M000718e0_iO[who].sp |= 2;
    }
    if (M000718e0_iO[who].cls[0] == 3) {
        M000718e0_iO[who].sp |= 1;
        FUN_00013de4(who, M000718e0_iO[who].lvl[0]);
    }
    if (M000718e0_iO[who].cls[1] == 3) {
        M000718e0_iO[who].sp |= 1;
        FUN_00013de4(who, M000718e0_iO[who].lvl[1]);
    }
    if (M000718e0_iO[who].cls[2] == 3) {
        M000718e0_iO[who].sp |= 1;
        FUN_00013de4(who, M000718e0_iO[who].lvl[2]);
    }
    M000718e0_iO[who].fl |= 0x80;
}

#undef M00063020_bP
#undef M000718e0_iO
/* ---- from src/CODE2/f24a60.c */
/* FUN_00024a60: index of the party record named name whose flag word (+0x10) has bit 7 set, -1 if none */
/* Round 47: matches in module 0x23f70 under the module flags (-ox -oe -oa -ot, loop optimisation on) written as the plain index
   loop over the record table: `B000718e0_iO[i].name` / `B000718e0_iO[i].fl` (struct PC, include/records.h). The name address
   becomes the stepped register and the flag read keeps `imul edi,ebx,0x248` in every iteration, as the original. The earlier
   form (a stepped char pointer p beside o = i * 0x248) had the product reduced under -ol and matched only without it; the
   "module needs -ol, this function not" contradiction of recipe 41 is gone for this function. */
#include "records.h"
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
int strcmp(const char *, const char *);

int FUN_00024a60(const char *name)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (strcmp(M000718e0_iO[i].name, name) == 0 && (M000718e0_iO[i].fl & 0x80)) return i;
    }
    return -1;
}

#undef M000718e0_iO
/* ---- from src/CODE2/f24adc.c */
#define M000718e0_iO ((char *)&B000718e0_iO)
/* FUN_00024adc @ 00024adc: when character c is one of the named NPCs, show its portrait/voice and play its greeting */
int strcmp(const char *, const char *);
struct N { char *name; int pic, voice; };
extern struct N PTR_s_GLORIANNA_00058104[10];
 extern int DAT_0005bf2c;
extern void FUN_0002c77c(int, int), FUN_0002c160(int), FUN_0002c124(int);
void FUN_00024adc(int c)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(PTR_s_GLORIANNA_00058104[i].name, M000718e0_iO + c * 0x248) == 0) {
            if (!(*(unsigned short *)(M000718e0_iO + c * 0x248 + 0x10) & 0x4000)) {
                DAT_0005bf2c = PTR_s_GLORIANNA_00058104[i].voice;
                FUN_0002c77c(c, PTR_s_GLORIANNA_00058104[i].pic);
            }
            FUN_0002c160(i + 4);
            if (*(unsigned short *)(M000718e0_iO + c * 0x248 + 0x10) & 0x4000) FUN_0002c124(i + 0xf);
            switch (i) {
            case 0: FUN_0002c124(0x19); return;
            case 1: FUN_0002c124(0x1c); return;
            case 2: FUN_0002c124(0x11); return;
            case 3: FUN_0002c124(0x21); return;
            case 6: FUN_0002c124(0x23); return;
            case 9: FUN_0002c124(0xe); return;
            }
            return;
        }
    }
}

#undef M000718e0_iO
/* ---- from src/CODE2/f24be0.c */
/* FUN_00024be0 @ 00024be0: store a party member back into the NPC template it came from */
#include "chars.h"
#define DAT_0005a808 ((char *)DAT_0005a808)
int strcmp(const char *, const char *); void *memmove(void *, const void *, unsigned); void *memset(void *, int, unsigned);

void FUN_00024be0(int i)
{
    int k; char *p = DAT_0005a808;
    for (k = 0; k < 10; k++, p += 0x248) {
        if (strcmp(p, CHAR_REC(i)) == 0) {
            memmove(p, CHAR_REC(i), 0x248);
            memset(p + 0x40, -1, 0x2a);
            return;
        }
    }
}

#undef DAT_0005a808
/* ---- from src/CODE2/f24c40.c */
/* FUN_00024c40 @ 00024c40 */
#include "chars.h"
extern unsigned char FUN_0001f218(int, int); extern void FUN_0003195c(int, int, int, int, int, int, int);
extern int B000755d0_ao, B000755d4_ak;
#define SLOT(i,k) (*(short *)(CHAR_REC(i) + 0x40 + (k) * 2))
void FUN_00024c40(int i)
{
    int k;
    for (k = 0; k < 21; k++) {
        if (SLOT(i,k) != -1 && SLOT(i,k) != 0xa6)
            FUN_0003195c(0x80, SLOT(i,k), FUN_0001f218(i, k), B000755d0_ao, B000755d4_ak, 1, 0);
    }
}

#undef SLOT
/* ---- from src/CODE2/f24ca4.c */
extern int FUN_00023fd4(int mode, int x, int y, int step, int w, char *str, int f); /* module prototype */
extern int FUN_00024a60(const char *name); /* module prototype */
extern void FUN_00024adc(int c); /* module prototype */
extern void FUN_00024be0(int i); /* module prototype */
extern void FUN_00026400(void); /* module prototype */
/* MATCH (round 47, module 0x23f70 -oa): (1) the eligibility test is two statements with their own store (`if (fl & 0x140) e[k] = 1; else if (!(fl & 0x80) && !(fl & 0x4000)) e[k] = 1;`): same code (the compiler merges the stores), but the constant 1 then has three uses in the loop and ties with the table-address constant at 122 for EDI; (2) the mouse position and buttons are one record (`struct MOUSE DAT_00059e31`, .x / .y / .b; include/records.h): three -oa memory nodes fewer, which lets the constant 1 win that tie (mov edi,1) and puts the two reduced inductions in edx / eax as the original. Either change alone leaves the 11 lines. */
/* Round 41: 17 -> 11 instruction lines in module 0x23f70 (504/501): declaration order `k, x, m, ...` (hill climb, real compiler, 80 variants) gives x in ecx / y in esi as the original. Left: the eligibility loop's two reduced inductions (k * 0x248 in eax, k * 4 in edx; the original edx / eax) and the constant 1 the original caches in edi; struct / table / cast spellings of the flag word and the store (5 variants) compile identically. */
/* NEAR MISS (round 23, module 0x23f70 -oa, 17 worklist lines) a. first difference: in the eligibility loop the record offset k*0x248 is in eax and k*4 in edx (orig edx / eax) and the constant 1 is not cached in edi; decision: the tie of the two reduced inductions (loopopts: newest temp to the first add in instruction order) and ConstToTemp for the constant 1. b. orig: done=0 in ebp doubles as memset 0, k ebx, m esi; loop edx=rec, eax=k*4, edi=1, increments rec first. c. tried (2 real, in module): the store through a stepped int *e (rec still eax, 17), the k == m test first as if/else (23, other code). Left: the induction/const-temp tie. Earlier: 51 instr (2 bytes): top = k * 0x50 + 0xd inside the loop is closest; the original caches the constant 1 in edi for the eligibility stores (edi is already saved for top + 0x20 in the click loop), keeps done in ebp and only who on the stack. Tried: top as a second loop variable (strength-reduced top + 0x20, worse), inline k * 0x50 forms */
/* FUN_00024ca4 @ 00024ca4: ask the player to pick a party member (ineligible members greyed out); copy the member's items for the hand-over and return the member */
void *memset(void *, int, unsigned); void *memmove(void *, const void *, unsigned);
extern int FUN_0002a1f4(void);
extern void FUN_0002a9f8(void), FUN_0002c40c(int, int, int, int, int), FUN_0002a510(int), FUN_00032d70(void);
extern char *PTR_s_You_need_to_00057fb4; extern int DAT_00057fbc[], DAT_00057fd4, DAT_0005c050, B00064060_aa;
#include "records.h"
#define M000718e0_iO ((char *)&B000718e0_iO)
extern struct MOUSE DAT_00059e31; extern short B00064064_am[22];
#define CF(k) (*(unsigned short *)(M000718e0_iO + (k) * 0x248 + 0x10))
int FUN_00024ca4(void)
{
    int k, x, m, y, top, who, done;
    m = FUN_00024a60("IRMGARDE");
    done = 0;
    memset(DAT_00057fbc, 0, 0x10);
    for (k = 0; k < 4; ++k) {
        if (CF(k) & 0x140) DAT_00057fbc[k] = 1;
        else if (!(CF(k) & 0x80) && !(CF(k) & 0x4000)) DAT_00057fbc[k] = 1;
        if (DAT_00057fd4 == 0x1c && k == m) DAT_00057fbc[k] = 1;
    }
    FUN_0002a9f8();
    FUN_0002c40c(DAT_0005c050, 0xf, 0x40, 0x32, 0xc0);
    FUN_00023fd4(0, 0x14, 0x46, 0x12, 0xb4, PTR_s_You_need_to_00057fb4, 1);
    FUN_00026400();
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 ^= 1;
    while (!done) {
        while (FUN_0002a1f4()) ;
        while (!FUN_0002a1f4()) ;
        if (DAT_00059e31.b & 2) continue;
        x = DAT_00059e31.x;
        y = DAT_00059e31.y;
        for (k = 0; k < 4; k = k + 1) {
            top = k * 0x50 + 0xd;
            if (x >= 0x136 &&x < 0x166 && y >= top && y < top + 0x20 && !DAT_00057fbc[k]) {
                done = 1;
                who = k;
                break;
            }
        }
    }
    memmove(B00064064_am, M000718e0_iO + who * 0x248 + 0x40, 0x2a);
    B00064060_aa = *(int *)(M000718e0_iO + who * 0x248 + 0x12b);
    if (CF(who) & 0x80) {
        FUN_00024adc(who);
        FUN_00024be0(who);
    }
    FUN_0002a510(DAT_0005c050);
    DAT_0005c050 = DAT_0005c050 ^ 1;
    FUN_0002a9f8();
    FUN_00032d70();
    memset(DAT_00057fbc, 0, 0x10);
    return who;
}

#undef M000718e0_iO
#undef CF
/* ---- from src/CODE2/f24e9c.c */
/* FUN_00024e9c @ 00024e9c: hand the found items to party member i (into free slots, else dropped at the party position); the extra 9 are always dropped */
extern void FUN_0001f238(int, int, int), FUN_0003195c(int, int, int, int, int, int, int);
#define B00071920_bM (*(char (*)[])((char *)&B000718e0_iO + 64)) /* STANDIN: view, B000718e0_iO + 0x40 */
extern short B00064064_am[22]; extern int B00064060_aa, B000755d0_ao, B000755d4_ak; 
void FUN_00024e9c(int i)
{
    int k, j;
    for (k = 0; k < 0xc; k++) {
        if (B00064064_am[k] == -1 || B00064064_am[k] == 0xa6) continue;
        for (j = 0; j < 0xc; j++) {
            if (*(short *)(B00071920_bM + i * 0x248 + j * 2) == -1) {
                *(short *)(B00071920_bM + i * 0x248 + j * 2) = B00064064_am[k];
                FUN_0001f238(i, j, (B00064060_aa & 1 << k) >> k);
                break;
            }
        }
        if (j == 0xc) FUN_0003195c(0x80, B00064064_am[k], (B00064060_aa & 1 << k) >> k, B000755d0_ao, B000755d4_ak, 1, 0);
    }
    for (k = 0xc; k < 0x15; k++)
        if (B00064064_am[k] != -1) FUN_0003195c(0x80, B00064064_am[k], (B00064060_aa & 1 << k) >> k, B000755d0_ao, B000755d4_ak, 1, 0);
}

/* ---- from src/CODE2/f24fc0.c */
extern void FUN_000248f0(int who); /* module prototype */
extern int FUN_00024ca4(void); /* module prototype */
extern void FUN_00024e9c(int i); /* module prototype */
/* FUN_00024fc0 @ 00024fc0 */
#include "chars.h"
extern void FUN_0001ad24(int); 
extern unsigned short B000718f0_hO; extern unsigned char DAT_0005d681[], DAT_0005cf5a[], DAT_0005cf5b[]; extern int DAT_0005d8a8[];
void FUN_00024fc0(void)
{
    int k, off, who, h;
    for (k = 0, off = 0; off < 0x920; off += 0x248, k++) {
        if (*(unsigned short *)((char *)&B000718f0_hO + off) & 0x8000) { FUN_000248f0(k); break; }
    }
    if (k == 4) {
        who = FUN_00024ca4();
        FUN_0001ad24(who);
        FUN_000248f0(who);
        FUN_00024e9c(who);
        h = who / 2;
        if (DAT_0005d681[h] && who == DAT_0005d8a8[h]) {
            DAT_0005cf5a[h * 2] = 1;
            DAT_0005d681[h] = 0;
            DAT_0005cf5b[h * 2] = 1;
        }
    }
}

/* ---- from src/CODE2/f25050.c */
/* FUN_00025050 @ 00025050: script op: give the party an item (into a free pack slot, or into the hand) */
#include "chars.h"
extern int FUN_0002c1dc(int); extern void FUN_0002c124(int), FUN_0002a344(short, unsigned char), FUN_0001f238(int, int, int), FUN_0003195c(int, int, int, int, int, int, int);
extern short DAT_00058600; extern unsigned short B000718f0_hO; extern int B000755d0_ao, B000755d4_ak;
#define SLOT(off, j) (*(short *)((char *)&B00071920_bM + (off) + (j) * 2))
void FUN_00025050(int item)
{
    int k, j, off;
    if (item == 0x90) item = 0x94;
    if (item == 0x78) {
        if (FUN_0002c1dc(0x58) == 1) return;
        FUN_0002c124(0x58);
    }
    if (item == 0x9b) {
        if (FUN_0002c1dc(0x59) == 1) return;
        FUN_0002c124(0x59);
    }
    if (DAT_00058600 == -1) { FUN_0002a344(item, 0); return; }
    for (k = 0, off = 0; off < 0x920; off += 0x248, k++) {
        if (!(*(unsigned short *)((char *)&B000718f0_hO + off) & 0x8000)) {
            for (j = 0; j < 12; j++) {
                if (SLOT(off, j) == -1) {
                    SLOT(off, j) = item;
                    FUN_0001f238(k, j, 0);
                    return;
                }
            }
        }
    }
    FUN_0003195c(0x80, item, 0, B000755d0_ao, B000755d4_ak, 1, 0);
}

#undef SLOT
/* ---- from src/CODE2/f25144.c */
/* FUN_00025144 @ 00025144: drop object type t at the party position */
extern void FUN_0003195c(int, int, int, int, int, int, int); extern int B000755d0_ao, B000755d4_ak;
void FUN_00025144(int t) { FUN_0003195c(0x80, t, 0, B000755d0_ao, B000755d4_ak, 1, 0); }

/* ---- from src/CODE2/f25168.c */
extern void FUN_000241b8(void); /* module prototype */
#define M00063020_bP ((unsigned short *)B00063020_bP)
/* FUN_00025168 @ 00025168: script op: add a picture to the four slots (-oa: the script index global is cached in a register) */
/* struct PX: defined above */
void *memmove(void *, const void *, unsigned);

extern int DAT_00057fec; extern struct PX DAT_00057fd8[4]; 
void FUN_00025168(int mode)
{
    int k;
    if (mode == 0) {
        for (k = 0; k < 4; k++) {
            if (DAT_00057fd8[k].id == 0xffff) {
                DAT_00057fd8[k].id = M00063020_bP[DAT_00057fec++];
                DAT_00057fd8[k].pad = M00063020_bP[DAT_00057fec++];
                break;
            }
        }
    } else {
        memmove(&DAT_00057fd8[1], &DAT_00057fd8[0], 12);
        DAT_00057fd8[0].id = M00063020_bP[DAT_00057fec++];
        DAT_00057fd8[0].pad = M00063020_bP[DAT_00057fec++];
    }
    FUN_000241b8();
}

#undef M00063020_bP
/* ---- from src/CODE2/f2520c.c */
extern void FUN_000241b8(void); /* module prototype */
/* FUN_0002520c @ 0002520c: drop the current script picture from the four slots */
/* struct PX: defined above */
void *memmove(void *, const void *, unsigned);

extern int DAT_00057fec, DAT_00057fe8; extern struct PX DAT_00057fd8[4]; 
void FUN_0002520c(void)
{
    int k, n; unsigned id;
    n = DAT_00057fec + 1;
    id = B0006301e_ak[n];
    DAT_00057fec = n;
    for (k = 0; k < 4; k++) {
        if (DAT_00057fd8[k].id == id) {
            if (k != 3) memmove(&DAT_00057fd8[k], &DAT_00057fd8[k + 1], (3 - k) * 4);
            DAT_00057fd8[3].id = 0xffff;
            DAT_00057fe8--;
            break;
        }
    }
    FUN_000241b8();
}

/* ---- from src/CODE2/f25280.c */
/* FUN_00025280 @ 00025280: script op: hide the entity named by the next word (or all 0x18s), show the 0x2a ones; the entity count is
   B00075618_b1.nent of struct LCNT (recipe 27: not cached under the module's -oa, reloaded per test as in the original) */
#include "world.h"
#define B00064d8e_a6 (*(unsigned short *)((char *)&B00064d80_ay + 14)) /* STANDIN: view, B00064d80_ay + 0xe */
#define B00064d92_aW (*(unsigned short *)((char *)&B00064d80_ay + 18)) /* STANDIN: view, B00064d80_ay + 0x12 */
extern unsigned char B00064d80_ay[];
#define B00064d8b_a7 (*(int *)((char *)&B00064d80_ay + 11)) /* STANDIN: view, B00064d80_ay + 0xb */
extern int DAT_00057fec;     
#define ENT_FL(i) (*(int *)((char *)&B00064d8b_a7 + (i) * 0x16))
#define ENT_ID(i) (*(unsigned short *)((char *)&B00064d8e_a6 + (i) * 0x16))
#define ENT_W12(i) (*(unsigned short *)((char *)&B00064d92_aW + (i) * 0x16))
void FUN_00025280(void)
{
    int k, n; unsigned short id;
    n = DAT_00057fec + 1;
    id = B0006301e_ak[n];
    DAT_00057fec = n;
    for (k = 0; k < B00075618_b1.nent; k++) {
        if (!(ENT_FL(k) & 2)) {
            if (id == 0xffff) {
                if (ENT_ID(k) == 0x18) ENT_FL(k) |= 2;
            } else if (id == ENT_ID(k)) {
                ENT_W12(k) = 0;
                ENT_FL(k) |= 2;
            }
        }
    }
    if (id == 0x29) {
        for (k = 0; k < B00075618_b1.nent; k++)
            if (!(ENT_FL(k) & 2) && ENT_ID(k) == 0x2a) ENT_FL(k) &= ~2;
    }
}

#undef ENT_FL
#undef ENT_ID
#undef ENT_W12
/* ---- from src/CODE2/f25320.c */
/* FUN_00025320 @ 00025320: draw the four corner pieces of the text box */
extern void FUN_0003975c(int, int, int, int, int); extern int B000758cc_fL;
void FUN_00025320(void)
{
    FUN_0003975c(0, 8, 0xc, B000758cc_fL + 5, 9);
    FUN_0003975c(1, 8, 0x74, B000758cc_fL + 5, 9);
    FUN_0003975c(2, 0xa6, 0xc, B000758cc_fL + 5, 9);
    FUN_0003975c(3, 0xa6, 0x74, B000758cc_fL + 5, 9);
}

/* ---- from src/CODE2/f2538c.c */
/* FUN_0002538c @ 0002538c: count how many times item b is found inside container item a (recursive) */
#include "world.h"
extern int B00064020_bW;   extern unsigned char DAT_00057330;
void FUN_0002538c(short a, short b)
{
    int k, t, off; short *p;
    if (a == b) { B00064020_bW++; return; }
    off = a * 0x41;
    if ((unsigned char)((char *)B000755d8_aw)[off + 0x2f] == 1) {
        t = (signed char)((char *)B000755d8_aw)[off + 0x31];
        p = *(short **)((char *)&PTR_DAT_00057335 + t * 10);
        for (k = 0; k < *((unsigned char *)&DAT_00057330 + t * 10); p++, k++)
            if (*p != -1) FUN_0002538c(*p, b);
    }
}

/* ---- from src/CODE2/f253fc.c */
extern void FUN_0002538c(short a, short b); /* module prototype */
/* FUN_000253fc @ 000253fc: does the party hold all fifteen pieces of item 0x75 (item is an int local: the short-prototype conversion keeps it in edi as movsx edx,di) */
#include "chars.h"
extern int FUN_0001f390(short, short); 
extern int B00064020_bW; extern short DAT_00058600; extern unsigned short B000718f0_hO;
int FUN_000253fc(void)
{
    int k, j; int item;
    item = 0x75;
    B00064020_bW = 0;
    if (DAT_00058600 != -1) {
        if (FUN_0001f390(DAT_00058600, item)) B00064020_bW++;
    }
    for (k = 0; k < 4; k++) {
        if (!(*(unsigned short *)((char *)&B000718f0_hO + k * 0x248) & 0x8000)) {
            for (j = 0; j < 21; j++) {
                if (*(short *)((char *)B00071920_bM + k * 0x248 + j * 2) != -1)
                    FUN_0002538c(*(short *)((char *)B00071920_bM + k * 0x248 + j * 2), item);
            }
        }
    }
    return B00064020_bW == 0xf;
}

/* ---- from src/CODE2/f25534.c */
/* MATCH round 66 lane BD (module m23f70.c context, -3s -ox -oe -oa -ot -j -w0): 2241/2241, from lane AU's 2240/2241, 12 masked lines.
   All register choices here are pass-1 ties (savings 46/48) that the ShellSort permutation decides; the STANDIN lines either
   lift one node above its competitor by a copy out and back or (head, case 3 first fetch) change the node count so the
   permutation comes out as the original's.  Forced orders that match (real 10.0a, build/var/r66bd): on lane AU's draft + the
   case-4 copy-back, FORCE="t29,t28;t210,t209,t35,t34".  Watch-out kept: the head pair t6 (PC load, EAX) / t7 (PC * 2, EDX);
   t7 first gives the 2120-2124-byte form where the cases reuse the head's PC + 1 in EDX. */
/* NEAR MISS (round 23, module 0x23f70 -oa, 56 worklist lines: a. first difference: register of a table index (mov dx,[eax*2] vs [edx*2]) and three scheduling moves; with registers masked the shape is equal apart from those; allocation, no compile spent) 2241/2241 under the module flags -3s -ox -oe -oa -ot (module 0x23f70; flags.csv now has them), SHAPE 150, 225 byte lines (was 2261/2241 under -oa, SHAPE 294; 2235/2241 SHAPE 203 under plain). Structural round 2026-11-10, from the original: (1) DAT_0005c050 is an int (push dword to FUN_0002a510/FUN_0002a8c8, movzx byte only for FUN_000391b0's unsigned char) - fixed; (2) the dispatch is k = PC++; switch (S[k]): the new PC goes to eax and is clobbered by the opcode load, so every case reloads PC (with switch (S[PC++]) and an int DAT_0005c050 PC stays in edx and every case changes) - fixed; (3) the FUN_0001f4b0 test is written positively like case 9 (if (f) PC = S[PC]; else PC++;) and case 29 is if (X != 0x1a) {...} else PC++;, so all PC++ tails cross-jump to case 8's - fixed; (4) case 28 reads its operand into an int (movzx straight from S) - fixed. Left (ties/scheduling): cases 3/4 load PC twice before S[pc1] in the original; case 35 pushes before the PC reload and adds into the S[PC] register (3 sum orders tried: worse or equal); RND product in ebx there, a copy in edx here; one byte longer encoding before 0x47 shifts the near jumps. */
extern void FUN_000241b8(void); /* module prototype */
extern void FUN_000246dc(void); /* module prototype */
extern void FUN_00024fc0(void); /* module prototype */
extern void FUN_00025050(int item); /* module prototype */
extern void FUN_00025168(int mode); /* module prototype */
extern void FUN_0002520c(void); /* module prototype */
extern void FUN_00025280(void); /* module prototype */
extern void FUN_00025320(void); /* module prototype */
extern int FUN_000253fc(void); /* module prototype */
/* Round 50 (trace + 18 forced compiles, build/var/r50/fz.py): the EAX / EDX pairs of equal savings in pass 1 that overlap (17, by instruction range) are not the case fetches: forcing t7 before t6 swaps the DISPATCH (k = PC++ before the switch, 0x25547: right as it is) and the case loads then reuse its PC (149 lines); the other 16 single swaps leave the code as it is (76 unmasked lines), two improve it slightly (t90/t89: 68, t233/t232: 71). So the case fetches are not decided by a pass-1 order of their own pair; next step: name the case-25 temps from the trace (their instruction ids lie after the dispatch's) before any replay. */
/* Round 49 (1 compile): 50 lines in module, 2244/2241; the first differences are the operand fetch `X = S[PC++]` in cases 25 / 23 / 39 / 3 / 4: the original loads PC into EAX and the word into EDX (`mov eax,[PC]; movzx edx,[eax*2+S]; inc eax`), ours the reverse - the same two-temp tie in every case (one statement shape, many copies), so a node-count change flips all of them together. Not traced this round. */
/* earlier note: 2261/2241 (normalised sdiff 101): all 42 opcodes written in the layout order (Watcom emits cases in source order and places the post-switch return 0 right after the first breaking case, as in the original). Left: per-case register choice for the pc load (eax vs edx; cases 25, 40 and 33/34 come out the other way round), the operand/index load order in cases 3 and 4. Per-case spellings (S[PC]; PC++, temporaries) tried */
/* FUN_00025534 @ 00025534: execute one instruction of the event script at B00063020_bP[DAT_00057fec]; 0 = continue, 1/2/3 = stop codes */
#include <stdlib.h>
#define DAT_00057fd8 ((struct XY *)DAT_00057fd8)
#define M00063020_bP ((unsigned short *)B00063020_bP)
#define FUN_0003f29c ((int (*)(int, int))FUN_0003f29c)
struct XY { short x, y; };
struct TM { int a, b, c; };
 extern int DAT_00057fec, DAT_00057ff4, DAT_00057ff0, DAT_00057ff8, DAT_00057fe8, DAT_00057fd0, DAT_00057fd4;
 extern struct TM B00064024_ck[5]; extern unsigned char DAT_00058101, DAT_00058100, DAT_00058102, DAT_00057fb8; extern int DAT_0005c050;
extern int B000755d0_ao, B000755d4_ak, B000758cc_fL, B000758c8_as; extern short DAT_0005a6ba;
extern void FUN_0003195c(int, int, int, int, int, int, int), FUN_0001f540(int);
extern void FUN_0002c124(int), FUN_0002c160(int), FUN_0002c1a0(int), FUN_000391b0(unsigned char);
extern void FUN_0003e510(int, int, int, int), FUN_000396c0(int, int, int, int), FUN_000397d0(int, int, int, int), FUN_0003e538(int), FUN_0002a510(int);
extern void FUN_0002a9f8(void), FUN_0002a8c8(int, int, int, int, int), FUN_0003e608(void), FUN_00037f24(int), FUN_00038ef0(void), FUN_00039008(int); extern int FUN_0003e614(unsigned, int);
extern void FUN_00038f58(int), FUN_00038e58(int, int, int), FUN_00023ef8(int);
extern int FUN_0001f4b0(int), FUN_0002c1dc(int); extern unsigned FUN_00040700(void);
#define S M00063020_bP
#define PC DAT_00057fec
#define RND(n) ((unsigned)((n) * rand()) >> 15)
int FUN_00025534(void)
{
    int n; int t; unsigned short v; int k;
    if (DAT_00058101) return 3;
    t = PC++; switch (S[t]) { /* STANDIN: dispatch through t instead of k: keeps the head's PC load (t6) ahead of PC * 2 (t7) in the tie, PC + 1 in EAX */
    case 27: return 3;
    case 25: { int pc, c; pc = PC; c = pc; pc = c; DAT_00057ff4 = S[pc]; PC = pc + 1; } break; /* STANDIN: PC named per case + copy out and back: PC load allocated first (EAX) */
    case 23: { int pc, c; pc = PC; c = pc; pc = c; DAT_00057ff0 = S[pc]; PC = pc + 1; } break; /* STANDIN: PC named per case + copy out and back: PC load allocated first (EAX) */
    case 39: DAT_00057ff8 = S[PC++]; break;
    case 0:
        DAT_00057fe8 = S[PC++];
        for (k = 0; k < DAT_00057fe8; k++) DAT_00057fd8[k].x = S[PC++];
        break;
    case 1:
        n = S[PC++];
        for (k = 0; k < n; k++) DAT_00057fd8[k].y = S[PC++];
        break;
    case 7: return 1;
    case 2: FUN_000246dc(); break;
    case 3:
        v = S[PC]; PC++; /* STANDIN: fetch and increment apart: one temp fewer, case 1's n / PC loop tie comes out as the original */
        { unsigned short c; c = v; v = c; } /* STANDIN: copy out and back: v (case 3) above the PC1 temp, below the word */
        { int w, c; w = S[PC++]; c = w; w = c; c = w; w = c; DAT_00057fd8[w].y = v; } /* STANDIN: word named + two copies out and back: PC2 / word allocated first (EAX), v DX, PC1 EDX */
        break;
    case 5: FUN_00024fc0(); break;
    case 6: FUN_00025050(S[PC++]); break;
    case 41: FUN_0003195c(0x80, S[PC++], 0, B000755d0_ao, B000755d4_ak, 1, 0); break;
    case 40: { int pc, c, w; pc = PC; c = pc; pc = c; w = S[pc++]; PC = pc; FUN_0001f540(w); } break; /* STANDIN: PC named per case + copy out and back: PC load allocated first (EAX) */
    case 4:
        v = S[PC++];
        { unsigned short c; c = v; v = c; } /* STANDIN: copy out and back: v (case 4) above the PC2 temps: v AX, PC2 EDX */
        DAT_00057fd8[S[PC++]].x = v;
        FUN_000241b8();
        break;
    case 19: FUN_00025168(0); break;
    case 26: FUN_00025168(1); break;
    case 20: FUN_0002520c(); break;
    case 22: FUN_00025280(); break;
    case 14: return 2;
    case 8:
        if (S[PC] == 0xffff) {
            PC++;
            if (FUN_000253fc()) PC = S[PC];
            else PC++;
            break;
        }
        if (FUN_0001f4b0(S[PC++])) PC = S[PC];
        else PC++;
        break;
    case 24: PC = S[PC]; break;
    case 9:
        if (FUN_0002c1dc(S[PC++])) PC = S[PC];
        else PC++;
        break;
    case 13:
        if (!FUN_0002c1dc(S[PC++])) PC = S[PC];
        else PC++;
        break;
    case 33:
        { int m, c; m = 1 << S[PC++]; c = m; m = c; if (DAT_00057fd0 & m) PC = S[PC]; /* STANDIN: mask named + copy out and back: the 1 << n temp takes EAX first, PC EDX */
        else PC++;
        }
        break;
    case 34:
        if (!(DAT_00057fd0 & (1 << S[PC++]))) PC = S[PC];
        else PC++;
        break;
    case 10: FUN_0002c124(S[PC++]); break;
    case 11: FUN_0002c160(S[PC++]); break;
    case 12: FUN_0002c1a0(S[PC++]); break;
    case 30: { int m, c; m = 1 << S[PC++]; c = m; m = c; DAT_00057fd0 |= m; } break; /* STANDIN: mask named + copy out and back: the 1 << n temp takes EAX first, PC EDX */
    case 31: { int pc, c; pc = PC; c = pc; pc = c; DAT_00057fd0 &= ~(1 << S[pc]); PC = pc + 1; } break; /* STANDIN: PC named per case + copy out and back: PC load allocated first (EAX), mask EDX */
    case 32: { int m, c; m = 1 << S[PC++]; c = m; m = c; DAT_00057fd0 ^= m; } break; /* STANDIN: mask named + copy out and back: the 1 << n temp takes EAX first, PC EDX */
    case 15:
        k = S[PC++];
        B00064024_ck[k].a = S[PC++];
        B00064024_ck[k].b = S[PC++];
        B00064024_ck[k].c = FUN_00040700() + B00064024_ck[k].b;
        if (B00064024_ck[k].a == 0xffff) B00064024_ck[k].a = -1;
        break;
    case 16:
        FUN_000391b0(DAT_0005c050);
        FUN_0003e510(S[PC + 1], S[PC + 2], S[PC] + (B000758cc_fL + DAT_00057ff0), 9); /* STANDIN: operand order: the sum lands in the base register */
        PC += 3;
        break;
    case 38:
        DAT_0005a6ba = 1;
        FUN_000396c0(8, 0xc, 0xcf, 0x9b);
        FUN_000391b0(DAT_0005c050);
        FUN_000397d0(S[PC + 1], S[PC + 2], B000758cc_fL + DAT_00057ff0 + S[PC], 9);
        FUN_000396c0(0, 0, 0x18f, 0x13f);
        DAT_0005a6ba = 0;
        PC += 3;
        break;
    case 37:
        FUN_000391b0(DAT_0005c050);
        t = FUN_0003f29c(B000758cc_fL + DAT_00057ff0 + S[PC], 9);
        FUN_0003e538(t);
        FUN_0003e510(S[PC + 1], S[PC + 2], B000758cc_fL + DAT_00057ff0 + S[PC], 9);
        FUN_0003e538(t);
        PC += 3;
        break;
    case 35:
        FUN_000391b0(DAT_0005c050);
        { int r, x, y, p, c; FUN_0003e510(S[PC + 2], S[PC + 3], (r = RND(S[PC + 1]), p = PC, c = p, p = c, x = S[p], y = B000758cc_fL + DAT_00057ff0, c = y, y = c, c = y, y = c, c = y, y = c, x += y, x += r, x), 9); } /* STANDIN: sum built in one comma argument: A + B (y, 3 copies out and back) first in EAX, x = S[PC] + y + r in EDX, PC (p) EAX */
        PC += 4;
        break;
    case 17:
        FUN_000391b0(DAT_0005c050);
        FUN_00025320();
        if (!DAT_00058102) {
            FUN_0002a510(DAT_0005c050);
            DAT_0005c050 ^= 1;
            FUN_0002a9f8();
        } else FUN_0002a8c8(DAT_0005c050, 8, 0xc, 0xc8, 0x90);
        if (DAT_00057fb8) {
            FUN_0003e614(4, 0);
            FUN_0003e608();
        }
        break;
    case 18:
        DAT_00057fb8 = 1;
        k = S[PC++];
        t = PC;
        PC = k;
        while (!FUN_00025534()) ;
        DAT_00057fb8 = 0;
        PC = t;
        break;
    case 21: DAT_00058100 = 1; break;
    case 28:
        n = S[PC++];
        if (n != 3 && n != 0x88) FUN_00037f24(B000758c8_as + n);
        break;
    case 29:
        if (DAT_00057fd4 != 0x1a) {
            FUN_00038ef0();
            FUN_00039008(0x64);
            FUN_00038f58(0x37);
            { int w, c; w = S[PC++]; c = w; w = c; FUN_00038e58(w, 1, 0x9c4); } /* STANDIN: word named + copy out and back: word EAX first, PC EDX */
        } else PC++;
        break;
    case 36:
        { int pc, c, w; pc = PC; c = pc; pc = c; w = S[pc++]; PC = pc; FUN_00023ef8(w); } /* STANDIN: PC named per case + copy out and back: PC load allocated first (EAX) */
        DAT_00058100 = 1;
        return 3;
    }
    return 0;
}

#undef DAT_00057fd8
#undef M00063020_bP
#undef FUN_0003f29c
#undef S
#undef PC
#undef RND
/* ---- from src/CODE2/f25df8.c */
extern int FUN_00025534(void); /* module prototype */
/* FUN_00025df8 @ 00025df8: run FUN_00025534 with the counter set to v until it succeeds, then restore the counter */
extern int DAT_00057fec; 
void FUN_00025df8(int v)
{
    int o = DAT_00057fec;
    DAT_00057fec = v;
    while (!FUN_00025534());
    DAT_00057fec = o;
}

/* ---- from src/CODE2/f25e24.c */
extern int FUN_00025534(void); /* module prototype */
/* FUN_00025e24 @ 00025e24: set the counter and run FUN_00025534 until it reports success */
extern int DAT_00057fec; 
void FUN_00025e24(int v) { DAT_00057fec = v; while (!FUN_00025534()); }

/* ---- from src/CODE2/f25e38.c */
extern int FUN_00023fd4(int mode, int x, int y, int step, int w, char *str, int f); /* module prototype */
extern void FUN_00026400(void); /* module prototype */
/* MATCH (round 47, module 0x23f70 -oa): the held item and its flag (0x58600 / 0x58602) are members of one record (`struct CURSOR DAT_000585fc`, include/records.h; `FUN_0002a5b0(DAT_0005c050, DAT_000585fc.id, DAT_000585fc.f)`). As two scalars they were two -oa memory nodes in the conflict list, which decided both ties of rounds 36-46 (r / shift temp at 86: `lea ecx,[eax+4]`; remainder / product at 202: `imul eax,edx,0x248`); as a record they are none and both fall the original way. Nothing else changed. */
/* NEAR MISS (round 45, module 0x23f70 -oa, 6 lines, 326/326 without filler): the original keeps r in eax (the call's result register) and forms the bound in ecx with `lea ecx,[eax+4]`, and the record offset as `imul eax,edx,0x248`; ours computes r in ecx and adds in place, and multiplies in edx. Tried (5 compiles, all equal): bound as its own variable, r in two statements, unsigned r with either cast. */
/* Round 42: the flag loop indexes (&DAT_00057fbc)[k] (recipe 127) instead of stepping an offset variable: identical code; the offset variable was a leftover device. `for (k = 0, best = 0; ...)` (round 36's zero-store order, which the file did not carry): 9 -> 6 instruction lines (328/326). Left: the two ties of round 36 (r / shr temp, remainder / product); bound variable, unsigned r, declaration orders (7 more compiles): same 6. */
/* Round 37 (real 10.0a, module m23f70 -oa, 10 compiles): on the for (k = 0, best = 0; ...) form (5 lines, ties (1) t8 / r and (2) t10 / t9 left) the replay allows only: a node of savings 0..83 inserted at pre-sort 0 or 5 or after t44 (31), one of 202..405 at 18 (among the -oa memory nodes), or a temp moved to 17 / 30. Tried: r = rand() * 6; r = (unsigned)r >> 15 (r109: n 31, 10-13 lines), best = best % 4, r declared in a block around the first loop, the + 4 folded into r (both forms), the index form (&DAT_00057fbc)[k] for the off loop (same code, n 32), 0x248 * (k % 4): all 5 lines. DAT_0005c050 (int scalar, byte and dword reads) gets no memory node. */
/* Round 36 (real 10.0a, module m23f70 -oa, 54 compiles + replay): three independent pieces. (1) r / shr result t8 tie at 86 (r takes ECX through t14's hint; needs t8 before r), (2) remainder t9 / product t10 tie at 202 (needs t10 first so the product takes EAX), (3) the xor order k before best: `for (k = 0, best = 0; ...)` gives it (with (1)+(2) forced: MATCH; alone 5 lines). Replay on that form: no single removal; insert a node of savings <= 86 after the named block, or one of 0..83 at pre-sort 0/5; r last in the named block (828 of 5040 named orders) - but all 24 declaration orders x 2 forms leave r second (its position follows first definition, not declaration); a named loop bound n (5 forms) is propagated away. Open: a source form that creates r's node later. */
/* Round 31 (real 10.0a, module m23f70 -oa, 13 compiles): loop bound 4 + r, unsigned r, a named bound n (two placements), the + 4 folded into r, r + 4 > k, rand() * 6 / 0x8000, cast placement, best first, 0x248 * (k % 4), k & 3: 8-10 lines; r and r + 4 stay coalesced. */
/* Round 29 (real 10.0a, module m23f70 -oa, 6 compiles): 8 lines; the original keeps rand()*6>>15 in eax and forms the loop bound r + 4 in ecx (lea ecx,[eax+4]); ours computes in ecx and adds in place. r = (..) + 4 with k < r, best = 0 before or after, 4 + r, r += 4: same code or worse (13). */
/* NEAR MISS (round 22): 15 lines in module 0x23f70 (-oa; was 19). Fixed: the second loop initialises k before off (`for (k = 0, off = 0; ...)`, the order of the original's xor eax / xor edx). Left: (1) r is coalesced with the loop bound r + 4 in ecx (original: r in eax from rand, `lea ecx,[eax+4]`); (2) the (k % 4) * 0x248 product is made in place in edx (original into eax, which the 16-bit load then reuses). Instrument gate IDENTICAL: t10 (remainder) / t11 (product) both savings 202 and t11 takes t10's register; r (86) gets its hint to ecx from r + 4 (126). Tried: best = 0 before the rand call, three declaration orders, the party record as B000718e0_iO + i * 0x248 + 0x10, no -oa (18). 9 real compiles. */
/* FUN_00025e38 @ 00025e38: pick a random able party member to speak and open the dialogue panel for them */
int rand(void); void *memset(void *, int, unsigned);
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int), FUN_00040508(int, int, int, char *, int), FUN_00040354(int, int); extern void FUN_0002a5b0(int, short, unsigned char);
#include "records.h"
#define B00062c20_jH ((char (*)[256])B00062c20_jH)
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
 extern int B000758cc_fL, DAT_00057ffc, DAT_0005c050;  extern struct CURSOR DAT_000585fc;
void FUN_00025e38(int a)
{
    int r, k, best;
    r = (unsigned)(rand() * 6) >> 15;
    for (k = 0, best = 0; k < r + 4; k++) {
        if (!(M000718e0_iO[k % 4].fl & 0xd040)) best = k;
    }
    best %= 4;
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 4; k++) {
        if (k != best) DAT_00057fbc[k] = 1;
    }
    FUN_00026400();
    memset(DAT_00057fbc, 0, 0x10);
    FUN_0003e510(0xdc, 0, B000758cc_fL + 2, 9);
    FUN_00040508(0xe7, 0, 0x140, M000718e0_iO[best].name, 1);
    FUN_00040354(0x3a, 1);
    FUN_00023fd4(0, 0xf6, 0x1f, 0xa, 0x10a, B00062c20_jH[a], 1);
    DAT_00057ffc = best;
    FUN_0002a5b0(DAT_0005c050, DAT_000585fc.id, DAT_000585fc.f);
    DAT_0005c050 ^= 1;
    FUN_000391b0(DAT_0005c050);
}

#undef B00062c20_jH
#undef M000718e0_iO
/* ---- from ? */
/* Round 61 (blind rewrite): this body MATCHES in the module compile (realcc on the merged module: FUN_00026400 292/292, FUN_00025e38 with the 0x25f7e chunk, FUN_000263c4, FUN_00026524; module 30 of 35). Alone it cannot match (split layout, see srcpos.csv), so it stays here until module 0x23f70 is whole. What fixed it: y derived from the counter (k*0x50 + 0xd + (k >= 2)) with continue; the bar x written inline as 0x50 - len + 0x136; three separate colour calls instead of a ternary; in loop 2 the marker y as its own statement before the call. The old draft (stepped y, named bar-x local) is in git history. */
/* FUN_00026400: draw the party panel: portrait, name plate and hit-point bar of each character */
#include "records.h"
extern void FUN_000391b0(unsigned char), FUN_000398f0(int, int, int, int, int, unsigned char *), FUN_00039b40(int, int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_0003e510(int, int, int, int);
extern int FUN_0002f3fc(int), FUN_0001ef14(int);
#define M000718e0_iO ((struct PC *)&B000718e0_iO)
extern int DAT_00057fbc[], B000758cc_fL, B000758e4_h7, DAT_0005c050;
extern unsigned char DAT_0005cf70[];
#define DAT_0005cf70 ((char (*)[256])DAT_0005cf70)
void FUN_00026400(void)
{
    int k, y, pic, face, len;
    FUN_000391b0(DAT_0005c050);
    for (k = 0; k < 4; k++) {
        if (M000718e0_iO[k].fl >= 0x8000) continue;
        pic = B000758e4_h7 + M000718e0_iO[k].sex * 0x17 + (signed char)M000718e0_iO[k].f12;
        if (M000718e0_iO[k].fl & 0x100) pic += 0x2e;
        face = FUN_0002f3fc(k);
        if (DAT_00057fbc[k]) face = 0;
        y = k * 0x50 + 0xd + (k >= 2);
        FUN_000398f0(0, 0x136, y, pic, 1, (unsigned char *)DAT_0005cf70[face]);
        if (M000718e0_iO[k].fl & 0x4000) continue;
        FUN_00039b40(0x136, y + 0x30, 0x50, 6, 0);
        len = ((M000718e0_iO[k].maxhp >> 1) + FUN_0001ef14(k) * 0x50) / M000718e0_iO[k].maxhp;
        y += 0x31;
        if (len > 0x50) FUN_00039b40(0x136, y, 0x50, 4, 0x1b);
        else if (len > 0x14) FUN_00039b40(0x50 - len + 0x136, y, len, 4, 0x43);
        else FUN_00039b40(0x50 - len + 0x136, y, len, 4, 0x57);
    }
    FUN_0003975c(0, 0x136, 0x8e, B000758cc_fL + 6, 9);
    for (k = 0; k < 4; k++) {
        if (M000718e0_iO[k].fl & 0x8000) {
            y = k * 0x50 + k / 2 + 0xb;
            FUN_0003e510(0x134, y, B000758cc_fL + 4, 9);
        }
    }
}

#undef M000718e0_iO
#undef DAT_0005cf70
/* ---- from src/CODE2/f26034.c */
extern int FUN_00025534(void); /* module prototype */
#define TM T28_TM
/* FUN_00026034 @ 00026034: run due timed scripts */
struct TM { int script, period, due; };
#define M00064024_ck ((struct TM *)B00064024_ck) /* this function's names for the members of the timer records */
extern unsigned FUN_00040700(void);  extern int DAT_00057fec;
void FUN_00026034(void)
{
    int k, old;
    for (k = 0; k < 5; k++) {
        if (M00064024_ck[k].script != -1) {
            if (FUN_00040700() > (unsigned)M00064024_ck[k].due) {
                old = DAT_00057fec;
                DAT_00057fec = M00064024_ck[k].script;
                while (FUN_00025534() == 0) ;
                DAT_00057fec = old;
                M00064024_ck[k].due = FUN_00040700() + M00064024_ck[k].period;
            }
        }
    }
}

#undef M00064024_ck
#undef TM
/* ---- from src/CODE2/f2608c.c */
extern void FUN_000241b8(void); /* module prototype */
extern void FUN_00024218(int sel, int all); /* module prototype */
extern int FUN_00025534(void); /* module prototype */
extern void FUN_00025e38(int a); /* module prototype */
extern void FUN_00026400(void); /* module prototype */
extern void FUN_00026034(void); /* module prototype */
#define DAT_00057fd8 ((unsigned short (*)[2])DAT_00057fd8)
#define FUN_0002a5b0 ((void (*)(int, int, int))FUN_0002a5b0)
/* FUN_0002608c @ 0002608c: dialogue answer menu: highlight the answer under the cursor, play the clicked answer, repeat until the conversation ends */
extern void FUN_000391b0(unsigned char), FUN_0002a8c8(int, int, int, int, int), FUN_00032d70(void);
extern int FUN_0002a1f4(void);
extern int DAT_0005c050, DAT_00057fe8, DAT_00057fec; extern short DAT_00058600, DAT_00059e33; extern unsigned char DAT_00058602, DAT_00058102, DAT_00058101, DAT_00058100;

void FUN_0002608c(void)
{
    int sel, k, r, y;
    FUN_000241b8();
    sel = -1;
    FUN_00024218(sel, 1);
    FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
    DAT_0005c050 ^= 1;
    FUN_000391b0(DAT_0005c050);
    DAT_00058102 = 1;
    for (;;) {
        while (FUN_0002a1f4()) FUN_00026034();
        while ((r = FUN_0002a1f4()) == 0) {
            FUN_00026034();
            y = DAT_00059e33;
            k = DAT_00059e31.x;
            if ((y < 0x17 && y > 0x129) || k < 0xdd || k >= 0x12a - (4 - DAT_00057fe8) * 0x16) k = -1;
            else {
                k = (k - 0xdd) / 0x16;
                if (k < 0 || k > 3) k = -1;
                if (DAT_00057fd8[k][0] == 0xffff) k = -1;
            }
            if (k != sel) {
                FUN_00024218(k, 1);
                sel = k;
                FUN_0002a8c8(DAT_0005c050, 0xdc, 0, 0x50, 0x140);
            }
        }
        if (r & 2) break;
        if (sel < 0 || sel >= DAT_00057fe8) continue;
        FUN_00025e38(sel);
        DAT_00057fec = DAT_00057fd8[sel][1];
        while (!FUN_00025534()) ;
        if (DAT_00058101 || DAT_00058100) break;
        FUN_00026400();
        FUN_00024218(-1, 1);
        FUN_0002a5b0(DAT_0005c050, DAT_00058600, DAT_00058602);
        DAT_0005c050 ^= 1;
        sel = -1;
        FUN_000391b0(DAT_0005c050);
    }
    FUN_00032d70();
}

#undef DAT_00057fd8
#undef FUN_0002a5b0
/* ---- from src/CODE2/f2624c.c */
/* FUN_0002624c @ 0002624c: remove the first entity of type 0x4e from the list, spawning five sparkle effects at its position;
   the count is the third short of struct LCNT (recipe 27: a struct member is not cached under the module's -oa) */
#include "world.h"
void *memmove(void *, const void *, unsigned);
extern void FUN_0003195c(int, int, int, int, int, int, int);

 extern char B00072238_dL[], B0007223c_dz[]; extern unsigned short B00072246_dJ;
void FUN_0002624c(void)
{
    int k;
    for (k = 0; k < B00075618_b1.ndoor; k++) {
        if (*(unsigned short *)((char *)&B00072246_dJ + k * 0x16) == 0x4e) {
            FUN_0003195c(0x80, 0x52, 0, *(int *)(B0007223c_dz + k * 0x16), *(int *)(B00072238_dL + k * 0x16), 0, 0);
            FUN_0003195c(0x80, 0x5c, 0, *(int *)(B0007223c_dz + k * 0x16), *(int *)(B00072238_dL + k * 0x16), 0, 0);
            FUN_0003195c(0x80, 0x5f, 0, *(int *)(B0007223c_dz + k * 0x16), *(int *)(B00072238_dL + k * 0x16), 0, 0);
            FUN_0003195c(0x80, 0x66, 0, *(int *)(B0007223c_dz + k * 0x16), *(int *)(B00072238_dL + k * 0x16), 0, 0);
            FUN_0003195c(0x80, 0x69, 0, *(int *)(B0007223c_dz + k * 0x16), *(int *)(B00072238_dL + k * 0x16), 0, 0);
            memmove(B00072238_dL + k * 0x16, B00072238_dL + (k + 1) * 0x16, (B00075618_b1.ndoor - k + 1) * 0x16);
            return;
        }
    }
}

/* ---- from src/CODE2/f2635c.c */
extern void FUN_00025320(void); /* module prototype */
extern int FUN_00025534(void); /* module prototype */
extern void FUN_0002608c(void); /* module prototype */
extern void FUN_0002624c(void); /* module prototype */
/* FUN_0002635c @ 0002635c */
  extern int FUN_0002c1dc(int);
extern int DAT_00057fec, DAT_00057fd4;
void FUN_0002635c(void)
{
    int r, saved;
    DAT_00057fec = 0;
    do { r = FUN_00025534(); } while (r != 2 && r != 3);
    if (r != 3) {
        saved = DAT_00057fec;
        FUN_00025320();
        FUN_0002608c();
        DAT_00057fec = saved;
        do { r = FUN_00025534(); } while (r != 3);
    }
    if (DAT_00057fd4 == 0x13) {
        if (FUN_0002c1dc(0x2e) == 1) FUN_0002624c();
    }
}

/* ---- from src/CODE2/wip/f26400.c */
extern void FUN_00026400(void); /* module prototype */
extern void FUN_000391b0(unsigned char), FUN_000398f0(int, int, int, int, int, unsigned char *), FUN_00039b40(int, int, int, int, int);
extern void FUN_0003975c(int, int, int, int, int), FUN_0003e510(int, int, int, int);
extern int FUN_0002f3fc(int), FUN_0001ef14(int);
extern int DAT_00057fbc[], B000758cc_fL, B000758e4_h7, DAT_0005c050;
extern unsigned char DAT_0005cf70[];

#undef DAT_0005cf70
#undef M000718e0_iO

/* FUN_000263c4 @ 000263c4: clear the dialogue screen's frame (two panels) and draw the party panel (FUN_00026400, whose head
   10.0a moves behind this function's tail jump); no caller in the program */
extern void FUN_000391b0(unsigned char), FUN_0003e510(int, int, int, int);
extern int B000758cc_fL, DAT_0005c050;
void FUN_000263c4(void)
{
    FUN_000391b0(DAT_0005c050);
    FUN_0003e510(0, 0, B000758cc_fL, 9);
    FUN_0003e510(0xc8, 0, B000758cc_fL + 1, 9);
    FUN_00026400();
}

/* ---- from src/CODE2/f26524.c */
extern void FUN_00023f70(int a); /* module prototype */
extern int FUN_00024a60(const char *name); /* module prototype */
extern void FUN_00026400(void); /* module prototype */
extern void FUN_0002635c(void); /* module prototype */
/* FUN_00026524 @ 00026524: enter level n: save and fade the music, reset per-level state, load the map, apply the level's quest overrides, and resume the music */
#include "world.h"
#define DAT_00057fd8 ((struct W2 *)DAT_00057fd8)
#define DAT_00058000 ((unsigned char *)DAT_00058000)
#define FUN_000391b0 ((void (*)(int))FUN_000391b0)
struct T { unsigned short wall : 6, rest : 10; };
struct R12 { int a, b, c; };
struct W2 { short a, b; };
extern int FUN_00039050(void), FUN_00039048(void), FUN_000390a0(void), FUN_00039098(void), FUN_0002c1dc(int);
extern void FUN_00038dcc(int), FUN_00029ccc(int), FUN_000396c0(int, int, int, int), FUN_0003e510(int, int, int, int), FUN_000281b4(int), FUN_0002c160(int), FUN_00038ef0(void), FUN_00038f58(int), FUN_00039008(int), FUN_00038e58(int, int, int), FUN_0002f8fc(void), FUN_00032d70(void), FUN_00029cf4(void);
extern unsigned char DAT_0005bf38, DAT_00058100, DAT_00058102, DAT_00058101, DAT_00057fb8, DAT_0005d680, DAT_0005801b;
extern int DAT_00057ff0, DAT_00057ff8, DAT_00057fd0, DAT_00057fd4, B000758cc_fL, DAT_0005c658, DAT_0005bf44;
extern short DAT_0005a6ba, DAT_0005a6be, DAT_0005a6bc, B000755d2_ai, B000755d6_ae;
#define B00064018_co ((struct R12 *)((char *)&B00064024_ck - 12)) /* STANDIN: view, B00064024_ck - 12 (element -1 of the table: the code indexes from 1) */


extern struct T B000698e0_b7[];

void FUN_00026524(int n)
{
    int mus, pos, sv, sd, v3, v4, q, k;
    if (n != 0x1c) {
        mus = FUN_00039050();
        pos = FUN_00039048();
        v3 = FUN_000390a0();
        v4 = FUN_00039098();
        FUN_00038dcc(0x9c4);
    }
    sv = DAT_0005bf38;
    DAT_0005bf38 = 0;
    q = FUN_0002c1dc(0x26);
    FUN_00029ccc(0);
    DAT_00058100 = 0;
    DAT_00057ff0 = 0;
    DAT_00057ff8 = 0;
    DAT_00058102 = 0;
    DAT_00057fd0 = 0;
    DAT_00058101 = 0;
    DAT_00057fb8 = 0;
    DAT_0005a6ba = 1;
    sd = DAT_0005d680;
    DAT_0005d680 = 2;
    FUN_000396c0(0, 0, 0x18f, 0x13f);
    DAT_0005a6ba = 0;
    DAT_0005a6be = 0;
    DAT_0005a6bc = 0;
    for (k = 0; k < 5;) B00064018_co[++k].a = -1;
    for (k = 0; k < 0x100; k++) DAT_00058000[k] = k;
    for (k = 0; k < 4; k++) DAT_00057fd8[k].a = -1;
    DAT_0005801b = 0x45;
    DAT_00057fd4 = n;
    FUN_00023f70(n);
    FUN_000391b0((unsigned char)DAT_0005c050);
    FUN_0003e510(0, 0, B000758cc_fL, 9);
    FUN_0003e510(0xc8, 0, B000758cc_fL + 1, 9);
    FUN_00026400();
    FUN_0002635c();
    if (n == 0x1f && FUN_0002c1dc(0x3f)) B000698e0_b7[B00075618_b1.w * 0x71 + 0x49].wall = 0;
    if (n == 0x14 && !q && FUN_0002c1dc(0x26) == 1) {
        B000755d2_ai = 0x3c;
        B000755d6_ae = 4;
        *(short *)&B000755d4_ak = 0x8000;
        *(short *)&B000755d0_ao = 0x8000;
        DAT_0005c658 = 0xb4;
        mus = -1;
        FUN_000281b4(6);
    }
    if (n == 0x12 && !FUN_0002c1dc(0x2f)) DAT_0005bf44 = 0x16;
    if (n == 0x20 && FUN_0002c1dc(0x4e) == 1) {
        FUN_0002c160(0x4e);
        if (FUN_0002c1dc(0x4f) == 1) DAT_0005bf44 = 0x4b;
    }
    if (n != 0x1c && mus != -1 && pos != -1) {
        FUN_00038dcc(0x9c4);
        FUN_00038ef0();
        FUN_00038f58(v3);
        FUN_00039008(v4);
        FUN_00038e58(mus, pos, 0x9c4);
    }
    if (n == 0x25 && FUN_00024a60("IRMGARDE") != -1) DAT_0005bf44 = 0x69;
    FUN_0002f8fc();
    FUN_00032d70();
    DAT_0005bf38 = sv;
    DAT_0005d680 = sd;
    FUN_00029cf4();
}

#undef DAT_00057fd8
#undef DAT_00058000
#undef FUN_000391b0

/* ---- module data _DATA 00057fb4-0005817c (docs/data/dataown.CODE2.csv: inferred (ref; some shared)), generated by tools/data2c.py */
char *PTR_s_You_need_to_00057fb4 = "You need to drop one of your party members.  Who will it be?";
unsigned char DAT_00057fb8 = 0;
unsigned char DAT_00057fb9[3] = { 0x73, 0x74, 0x28 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
int DAT_00057fbc[4] = { 0 };
int DAT_00057fcc = 0;
int DAT_00057fd0 = 0;
int DAT_00057fd4 = 0;
struct PX DAT_00057fd8[4] = { 0 };
int DAT_00057fe8 = 0;
int DAT_00057fec = 0;
int DAT_00057ff0 = 0;
int DAT_00057ff4 = 0;
int DAT_00057ff8 = 0;
int DAT_00057ffc = 0;
char DAT_00058000[27] = { 0 };
unsigned char DAT_0005801b = 0;
unsigned char DAT_0005801c[228] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };   /* no name in the sources */
unsigned char DAT_00058100 = 0;
unsigned char DAT_00058101 = 0;
unsigned char DAT_00058102 = 0;
unsigned char DAT_00058103[1] = { 0 };   /* bytes before the next name (alignment in the original: compiler buffer contents; STANDIN) */
struct N PTR_s_GLORIANNA_00058104[10] = {
    "GLORIANNA", 0x181, 0x43,
    "VELIKA", 0x231, 0x9e,
    "MISCHA", 0x171, 0x3d,
    "VUKO", 0x18b, 0x48,
    "TATIAN", 0x136, 0x22,
    "IRMGARDE", 0x198, 0x4f,
    "ANSHELM", 0x1a2, 0x54,
    "RYSZARD", 0x23c, 0xa3,
    "VLADISLAV", 0x20f, 0,
    "FHALKEN", 0x148, 0x2b
};
/* ---- end of module data _DATA */
