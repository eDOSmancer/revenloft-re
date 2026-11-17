/* Party / character records: 4 records of 0x248 bytes at DAT_000718e0 (loaded from CHARS, 0x920 bytes).
   Field accessors are written as byte offsets from the record base until the struct is recovered. */
#define CHAR_REC(i)        ((char *)&DAT_000718e0 + (i) * 0x248)
extern unsigned char DAT_000718e0;
#define CH_CLASS_S(i)      (*((signed char *)&DAT_000718f5 + (i) * 0x248))   /* +0x15 */
#define CH_TYPE(i)         (*((unsigned char *)&DAT_00071913 + (i) * 0x248)) /* +0x33 */
#define CH_LEVEL(i)        (*((unsigned char *)&DAT_0007191f + (i) * 0x248)) /* +0x3f */
#define CH_LVLIDX(i)       (*(short *)((char *)&DAT_00071900 + (i) * 0x248))  /* +0x20 */
extern signed char DAT_000718f5; extern unsigned char DAT_00071913, DAT_0007191f; extern short DAT_00071900;
