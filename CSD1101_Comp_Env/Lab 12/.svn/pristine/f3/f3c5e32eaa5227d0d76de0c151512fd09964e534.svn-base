; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 12
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Your name, email
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
;      p1, p2, p3, p4, p5, p6
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

    ret    ; return rax

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

    ret    ; return rax