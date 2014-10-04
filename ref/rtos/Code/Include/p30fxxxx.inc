;;
;; generic include file for dsPIC
;;
.ifdef __30F1010
.include "p30f1010.inc"
.equ VALID_ID,1
.endif
.ifdef __30F2010
.include "p30f2010.inc"
.equ VALID_ID,1
.endif
.ifdef __30F2011
.include "p30f2011.inc"
.equ VALID_ID,1
.endif
.ifdef __30F2012
.include "p30f2012.inc"
.equ VALID_ID,1
.endif
.ifdef __30F2020
.include "p30f2020.inc"
.equ VALID_ID,1
.endif
.ifdef __30F2023
.include "p30f2023.inc"
.equ VALID_ID,1
.endif
.ifdef __30F3010
.include "p30f3010.inc"
.equ VALID_ID,1
.endif
.ifdef __30F3011
.include "p30f3011.inc"
.equ VALID_ID,1
.endif
.ifdef __30F3012
.include "p30f3012.inc"
.equ VALID_ID,1
.endif
.ifdef __30F3013
.include "p30f3013.inc"
.equ VALID_ID,1
.endif
.ifdef __30F3014
.include "p30f3014.inc"
.equ VALID_ID,1
.endif
.ifdef __30F4011
.include "p30f4011.inc"
.equ VALID_ID,1
.endif
.ifdef __30F4012
.include "p30f4012.inc"
.equ VALID_ID,1
.endif
.ifdef __30F4013
.include "p30f4013.inc"
.equ VALID_ID,1
.endif
.ifdef __30F5011
.include "p30f5011.inc"
.equ VALID_ID,1
.endif
.ifdef __30F5013
.include "p30f5013.inc"
.equ VALID_ID,1
.endif
.ifdef __30F5015
.include "p30f5015.inc"
.equ VALID_ID,1
.endif
.ifdef __30F5016
.include "p30f5016.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6010
.include "p30f6010.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6010A
.include "p30f6010A.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6011
.include "p30f6011.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6011A
.include "p30f6011A.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6012
.include "p30f6012.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6012A
.include "p30f6012A.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6013
.include "p30f6013.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6013A
.include "p30f6013A.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6014
.include "p30f6014.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6014A
.include "p30f6014A.inc"
.equ VALID_ID,1
.endif
.ifdef __30F6015
.include "p30f6015.inc"
.equ VALID_ID,1
.endif
.ifndef VALID_ID
.error "processor ID not specified in generic include file"
.endif
