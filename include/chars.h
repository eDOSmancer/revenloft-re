/* Party / character records: 4 records of 0x248 bytes at B000718e0_iO (loaded from CHARS, 0x920 bytes).
   Field accessors are written as byte offsets from the record base until the struct is recovered. */
#define CHAR_REC(i)        ((char *)&B000718e0_iO + (i) * 0x248)
extern unsigned char B000718e0_iO;
#define CH_CLASS_S(i)      (*((signed char *)&B000718f5_h2 + (i) * 0x248))   /* +0x15 */
#define CH_TYPE(i)         (*((unsigned char *)&B00071913_a2 + (i) * 0x248)) /* +0x33 */
#define CH_LEVEL(i)        (*((unsigned char *)&B0007191f_dW + (i) * 0x248)) /* +0x3f */
#define CH_LVLIDX(i)       (*(short *)((char *)&B00071900_bm + (i) * 0x248))  /* +0x20 */
#define B00071900_bm (*(short *)((char *)&B000718e0_iO + 32)) /* STANDIN: view, B000718e0_iO + 0x20 */
#define B00071913_a2 (*(unsigned char *)((char *)&B000718e0_iO + 51)) /* STANDIN: view, B000718e0_iO + 0x33 */
#define B0007191f_dW (*(unsigned char *)((char *)&B000718e0_iO + 63)) /* STANDIN: view, B000718e0_iO + 0x3f */
#define B000718f5_h2 (*(signed char *)((char *)&B000718e0_iO + 21)) /* STANDIN: view, B000718e0_iO + 0x15 */
  
