/* Module: FUN_0001f750, FUN_0001f7b8, FUN_0001f8c4 */
/* ---- from build/var/mod/parts/p1f750.c */
/* The sound library loader module: FUN_0001f750 (read from file or memory image), FUN_0001f7b8 (LX image size); the
   4-byte initialiser of the signature buffer sits between them in _TEXT, as in the original */
void *memcpy(void *, const void *, unsigned); int read(int, void *, unsigned); long lseek(int, long, int); long tell(int);
int FUN_0001f750(int fd, int off, int flags, void * dst, int n) { if (flags & 1) { memcpy(dst, (char *)fd + off, n); return off + n; } lseek(fd, off, 0); read(fd, dst, n); return tell(fd); }

/* ---- from build/var/mod/parts/p1f7b8.c */
int open(const char *, int, ...); int close(int); int strcmp(const char *, const char *);
struct LXO { unsigned vsize, base, flags, pgidx, pgcnt, res; };
struct LXH { char pad[0x40]; unsigned objtab, objcnt; char rest[0xac - 0x48]; };
/* the sound library's C modules declare their entry points (this one included) as clobbering ebx,
   so the function neither saves nor uses it */
#pragma aux FUN_0001f7b8 modify [eax ebx ecx edx];
#pragma aux FUN_0001f750 modify [eax ebx ecx edx];
int FUN_0001f7b8(char *name, int flags)
{
    unsigned k; char sig[4] = "  "; struct LXO ent; struct LXH hdr; int hoff; int fd; int off; int total;
    total = 0;
    if (flags & 1) fd = (int)name;
    else {
        fd = open(name, 0x200);
        if (fd == -1) return 0;
    }
    FUN_0001f750(fd, 0x3c, flags, &hoff, 4);
    FUN_0001f750(fd, hoff, flags, sig, 2);
    if (strcmp(sig, "LX")) { close(fd); return 0; }
    FUN_0001f750(fd, hoff, flags, &hdr, 0xac);
    off = hoff + hdr.objtab;
    for (k = 0; k < hdr.objcnt; k++) {
        off = FUN_0001f750(fd, off, flags, &ent, 0x18);
        total += ent.vsize;
    }
    if (!(flags & 1)) close(fd);
    return total + 0xf;
}

/* ---- from build/var/mod/parts/p1f8c4.c */
#define LXH T2_LXH
#define LXO T2_LXO
/* FUN_0001f8c4 @ 0001f8c4: load the LX executable name (or the image at name when flags & 1) into dst
   (allocated when flags & 4): copy each object's pages, then apply the internal fixups. One read cursor (off)
   serves every read; the object counter i is reused for the fixup-page offset and for the fixup address.
   Same module as f1f750.c (its in-code signature initialiser still comes from the original until both share a file). */
int open(const char *, int, ...); int close(int); int strcmp(const char *, const char *); void *memset(void *, int, unsigned);
extern int FUN_0001f750(int, int, int, void *, int); extern int FUN_0001f7b8(char *, int); extern void *FUN_000171c8(int);
#pragma aux FUN_0001f750 modify [eax ebx ecx edx];
#pragma aux FUN_0001f7b8 modify [eax ebx ecx edx];
#pragma aux FUN_0001f8c4 modify [eax ebx ecx edx];
struct LXO { unsigned vsize, base, flags, pgidx, pgcnt, res; };
struct LXP { unsigned off; unsigned short size, flags; };
struct LXH { char p0[0x14]; unsigned npages; char p1[0x10]; unsigned pgsize, pgshift; char p2[0x10];
             unsigned objtab, objcnt, pgtab; char p3[0x1c]; unsigned fixpg, fixrec; char p4[0x10]; unsigned data; char rest[0xac - 0x84]; };
void *FUN_0001f8c4(char *name, int flags, char *dst)
{
    unsigned pgnext; struct LXH hdr; unsigned char fobj; unsigned char ftype; unsigned short ftoff; char *cur; unsigned char fflags; unsigned p; unsigned j; unsigned len; int npg; unsigned save; char sig[4] = "  "; unsigned fp0; unsigned fp1; unsigned short fsrc; int hoff; struct LXP pg; struct LXO ent; char *objbase[10]; unsigned objnext; char *pageaddr[100]; int fd; unsigned i; int size; unsigned off; unsigned t;
    npg = 0;
    if (flags & 1) fd = (int)name;
    else {
        fd = open(name, 0x200);
        if (fd == -1) return 0;
    }
    size = FUN_0001f7b8(name, flags);
    if (flags & 4) {
        dst = FUN_000171c8(size);
        if (!dst) {
            if (!(flags & 1)) close(fd);
            return 0;
        }
    }
    memset(dst, 0, size);
    cur = dst;
    FUN_0001f750(fd, 0x3c, flags, &hoff, 4);
    FUN_0001f750(fd, hoff, flags, sig, 2);
    if (strcmp(sig, "LX")) {
        if (!(flags & 1)) close(fd);
        return 0;
    }
    FUN_0001f750(fd, hoff, flags, &hdr, 0xac);
    off = hoff + hdr.objtab;
    for (i = 0; i < hdr.objcnt; i++) {
        off = FUN_0001f750(fd, off, flags, &ent, 0x18);
        objnext = off;
        off = hoff + hdr.pgtab;
        for (j = 0; j < ent.pgcnt; j++) {
            off = FUN_0001f750(fd, off, flags, &pg, 8);
            if (j == 0) {
                if ((ent.flags & 2) && (ent.flags & 1) && ((unsigned)cur & 0xf)) cur += 0x10 - ((unsigned)cur & 0xf);
                objbase[i + 1] = cur;
            }
            pageaddr[npg] = cur;
            pgnext = off;
            npg++;
            if (ent.vsize - (cur - objbase[i + 1]) < pg.size) len = ent.vsize - (cur - objbase[i + 1]);
            else len = pg.size;
            off = (pg.off << hdr.pgshift) + hdr.data;
            FUN_0001f750(fd, off, flags, cur, len);
            cur += len;
            off = pgnext;
        }
        off = objnext;
    }
    i = hoff + hdr.fixpg;
    i = FUN_0001f750(fd, i, flags, &fp0, 4);
    for (p = 0; p < hdr.npages; p++) {
        i = FUN_0001f750(fd, i, flags, &fp1, 4);
        if (fp0 != fp1) {
            save = i;
            off = fp0 + hoff + hdr.fixrec;
            do {
                off = FUN_0001f750(fd, off, flags, &ftype, 1);
                t = FUN_0001f750(fd, off, flags, &fflags, 1);
                if (!(ftype & 7)) { if (!(flags & 1)) close(fd); return 0; }
                if ((fflags & 4) && !(fflags & 0x20)) { if (!(flags & 1)) close(fd); return 0; }
                if (ftype & 0x20) { if (!(flags & 1)) close(fd); return 0; }
                off = FUN_0001f750(fd, t, flags, &fsrc, 2);
                off = FUN_0001f750(fd, off, flags, &fobj, 1);
                off = FUN_0001f750(fd, off, flags, &ftoff, 2);
                if (fsrc <= hdr.pgsize) {
                    i = (unsigned)(fsrc + pageaddr[p]);
                    *(char **)i = objbase[fobj] + ftoff;
                }
            } while (off < fp1 + hoff + hdr.fixrec);
            i = save;
        }
        fp0 = fp1;
    }
    if (!(flags & 1)) close(fd);
    return dst;
}

#undef LXH
#undef LXO
