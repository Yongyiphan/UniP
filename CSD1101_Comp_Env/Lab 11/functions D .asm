; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 11
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: HAN WEI DYLAN, dylan.h@digipen.edu
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

    mov rax, rdi ; mov p1 to rax
    sub rax, rdx ; p1 - p3, save in rax
    imul rax     ; square val at rax
    mov r10, rax ; saving the square in another reg

    mov rax, rsi ; mov p2 to rax
    sub rax, rcx ; p2 - p4, save in rax
    imul rax     ; sq val at rax

    add rax, r10 ; adding the two sq together (total distance between the centers of the two circles)
    mov r11, rax ; saving square into another reg

    mov rax, r8  ; mov p5 to rax
    add rax, r9  ; add the two radii together, store in rax
    imul rax     ; sq radii
    mov r12, rax ; save sq into another reg   

    cmp r11, r12  ; compare distance and total radii. 
                 ; If dist <  radii, zf = 0 and cf = 1
                 ; If dist >  radii, zf = 0 and cf = 0
                 ; If dist == radii, zf = 1 and cf = 0

    jle less ; jump if <=
    
    ; otherwise (>)
    mov rax, 0
    jmp exit

less: ; collide
    mov rax, 1

exit:
    ret    ; return rax;


f2:
; TODO: - Calculare (p1+0)*(p2+0) + (p1+1)*(p2+1) + (p1+2)*(p2+2) + .... +
;           (p1+p3)*(p2+p3)
;       - Tip: Accumulate the result in reverse order by decrementing 
;           p3 or (p1+p3) and (p2+p3)

    inc rdx      ; ++rdx to ensure that the loop can perform if rcx == 0 scenario
    mov rcx, rdx ; mov p3 to counter register. 
    mov r12, 0   ; setting r12 (total sum) to 0
    
f2loop:
    push rcx     ; save the count before setting to correct value for the calculations
    dec rcx      ; --rcx

    mov r10, rdi ; mov original p1 to r10
    mov r11, rsi ; mov original p2 to r11

    ; adding current count to p1 and p2
    add r10, rcx 
    add r11, rcx

    ; mul r10 and r11, store in rax
    mov rax, r10
    imul r11
    
    ; add rax to total sum
    add r12, rax 

    pop rcx      ; pop original counter
    loop f2loop  ; will auto --rcx. If 0, break

    mov rax, r12 ; mov result to rax 
    ret          ; return rax