.section .either.data,"aw"
.word 0
.section .either.bss,"aw",%nobits
.word 0
.section .either.rodata,"a"
.word 0
.section .either.text,"ax",%progbits
_start:
.global main
main:
.word 0
