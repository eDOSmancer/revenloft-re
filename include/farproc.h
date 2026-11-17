/* A far function pointer type.  STANDIN (inferred): no code of the game uses this name.  The _BSS segment of every C module of
   CODE.2 except m3f960 and m40700 starts on a paragraph boundary wherever the image can show it (docs/BSS.md,
   "Paragraph alignment"), which WCC386 does for a file that declares a far pointer or double object or typedef; a
   declaration every module sees - a typedef of the kind DOS programs keep for their interrupt handlers - explains
   the pattern, and its absence in the two files explains theirs.  The name and the exact type are not known. */
#ifndef _FARPROC_H
#define _FARPROC_H
typedef void (__far *FARPROC)();
#endif
