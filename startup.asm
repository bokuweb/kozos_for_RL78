    .list
    .global _start
    .short _start
    .text

_start:
    movw sp,#_stack /* Set stack pointer */
    call !!_main

1:
    bra 1b
