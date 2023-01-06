; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 12
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Edgar Yong, y.yiphanedgar@digipen.edu
;
; Compile: nasm -f elf64 -g -F dwarf functions.asm -o functions.o
; Link: gcc main.o functions.o -o main.o -lm
; Run: ./main 0
; Debug: gdb main
;  (gdb) b len
;  (gdb) run
;  0
;  ...
;  To see a string in memory by address in rdi use gdb's command:
;  (gdb) p/d (char[20]) *$rdi
;   ...
;
; Copyright: 2021, Digipen Institute of Technology, Singapore
;
; Note: All functions use at most 6 parameters
;      p1,  p2,  p3,  p4,  p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
; Note 2: Use instruction cmp byte [rdi+rcx], 0 to campare
;         a byte by adddress rdi*rci with 0
; ------------------------------------------------------------------
    section .text

    global len
    global countn
    global counta
    global counts

len:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the length of the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
    mov r10, rdi ;store first parameter
    xor rax, rax ;reset rax

notNullTer:
    cmp byte[r10 + rax], 0
    jz zeroReached
    inc rax
    jmp notNullTer;
zeroReached:
    ret    ; return rax;



countn:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of digits in 
;         the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hints:- Digit '0' has ASCII code 48, '1' - 49, ... '9' - 57.
;       - You can use your function len.

;loop thru char until ascii > 47 and ascii < 58
    call len
    mov r15, rax ;store len
    mov r11, 0   ;char index = 0;
    mov r12, 0   ;digit counter = 0;
    cmp r15, 0
    je END
    xor rax, rax ;rax to 0

nxtDig:
    ;if (48 <= x && x <=57)    
    cmp byte[rdi + r11], 48
    jl goNxtDig
    cmp byte[rdi + r11], 57
    jg goNxtDig
    inc r12
    jmp goNxtDig

goNxtDig:
    ;for(r11 < r15; r11++)
    inc r11
    cmp r11, r15
    jl nxtDig
    jmp END

END:
    mov rax, r12
    ret    ; return rax;



counta:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of alphabet letters in 
;         the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hints:- Letters have ASCII codes 65-90 and 97-122.
;       - You can use your function len.


;loop thru char until ascii > 47 and ascii < 58
    call len
    mov r15, rax ;store len
    mov r11, 0   ;char index = 0;
    mov r12, 0   ;digit counter = 0;
    cmp r15, 0
    je ENDChar
    xor rax, rax ;rax to 0
    jmp nxtChar

incC:
    inc r12
    jmp goNxtChar

nxtChar:
    ;let x = current char
    ;if x < 65 skip, if x < 90 - inc if x < 97 skip, x < 122 inc
    cmp byte[rdi + r11], 65
    jl goNxtChar
    cmp byte[rdi + r11], 90
    jle incC
    cmp byte[rdi + r11], 97
    jl goNxtChar
    cmp byte[rdi + r11], 122
    jle incC
    jmp goNxtChar

goNxtChar:
    ;for(r11 < r15; r11++)
    inc r11
    cmp r11, r15
    jl nxtChar
    ;jmp ENDChar

ENDChar:
    mov rax, r12
    ret    ; return rax;


counts:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of special characters in 
;         the string.
;       - Special character is a character which is neither a digit
;         not a letter.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hint: - You can use your functions len, countn, and counta.
    call len
    mov r9, rax
    call countn
    sub r9, rax
    call counta
    sub r9, rax

;   sub r9, r13
;   sub r9, r14

    mov rax, r9
    ret    ; return rax