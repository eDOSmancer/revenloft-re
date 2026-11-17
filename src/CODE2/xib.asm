; xib.asm - STANDIN: an empty paragraph-aligned XIB segment.
; In the original the initialiser table (XIB/XI/XIE, class DATA, from the C library start-up) begins on a paragraph
; boundary, 12 bytes after the end of _DATA.  Every XIB segment of the Watcom library objects is word-aligned, so some
; object of the original link aligned it; which one cannot be told from the image.  This file does it.
.386p
DGROUP group XIB
XIB segment para public use32 'DATA'
XIB ends
end
