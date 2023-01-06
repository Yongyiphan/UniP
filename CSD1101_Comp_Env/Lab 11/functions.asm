; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 11
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Edgar yong, y.yiphanedgar@digipen.edu
;
; Compile: nasm -f elf64 -g -F dwarf functions.asm -o functions.o
; Link: gcc main.o functions.o -o main.o -lm
; Run: ./main 0
; Debug: gdb main
;  (gdb) b f1
;  (gdb) run
;  ...
;  0
;  ...
;  (gdb) ...
;
; Copyright: 2021, Digipen Institute of Technology, Singapore
;
; Note: All functions use at most 6 parameters
;      p1, p2, p3, p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
; ------------------------------------------------------------------

    section .text

    global f1
    global f2

f1:
; TODO: - Given two circles with central points at (p1,p2), (p3,p4),
;       and radii p5, p6. All values in p1, ..., p6 are integers.
;       - Create code that determins intersection
;       or non-intersection of the circles.
;       - You code must return 1 when intersecting or 0 otherwise
;       based on the result of calculation.
;       - Tip 1: use the method without square root calculations:
;       if (p1-p3)^2+(p2-p4)^2 <= (p5+p6)^2 then return 1
;       - Tip 2: do not use pow() function to calculate x^2, use 
;       x*x instead.
;       - Note that a point is a circle with radius 0.
; Note: All functions use at most 6 parameters
;      p1,   p2,  p3,  p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
    mov rax, rdi ;mov p1 to rax
    sub rax, rdx ;sub (p1 - p3)
    imul rax    ;(p1- p3) ^2 
    mov r10, rax ;store it at r10

    mov rax, rsi ;mov p2 to rax
    sub rax, rcx ;sub (p2-p4)
    imul rax    ;(p2-p4)^2
    add rax, r10     ;(p2-p4)^2 + (p1+p3)^2
    mov r11, rax ;store it at r11

    mov rax, r8 ;mov p5 to rax
    add rax, r9 ;add p6
    imul rax   ;(p5+p6)^2
    mov r12, rax    ;store it at r12

    cmp r11, r12
    jle less

    mov rax, 0
    jmp else

less:
    mov rax, 1
else:
    ret




f2:
; TODO: - Calculate 
;           (p1+0)*(p2+0) + (p1+1)*(p2+1) + (p1+2)*(p2+2) + .... +

;           (p1+p3)*(p2+p3)
;       - Tip: Accumulate the result in reverse order by decrementing 
;           p3 for (p1+p3) and (p2+p3)

; Note: All functions use at most 6 parameters
;      p1,   p2,  p3,  p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
    
    mov rcx, rdx ;mov rdx to rcx
    mov r14, 0 ;blank reg for total sum

f2loop:
    ;p1 = rdi
    ;p2 = rsi
    ;p3 = rdx
    mov rax, rdi
    add rax, rcx
    mov r10, rax

    mov rax, rsi
    add rax, rcx
    imul r10
    add r14, rax

    dec rcx
    cmp rcx, 0
    jge f2loop

    
exit:
    mov rax, r14
    ret




    