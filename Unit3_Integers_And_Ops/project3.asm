;Javier Rodriguez Project 03: From C to Assembly 

%include "asm_io.inc"

section .data
prompt db "Enter your favorite number: ", 0

section .text
    global asm_main

asm_main:
    enter 0, 0  ; Setup routine
    pusha

    mov eax, prompt
    call print_string

    popa
    mov eax, 0  ; Return back to C
    leave
    ret
