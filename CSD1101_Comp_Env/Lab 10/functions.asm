; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 10
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Edgar yong, y.yiphanedgar@digipen.edu
; .
; Compile: nasm -f elf64 functions.asm -o functions.o
; Link: gcc main.o functions.o -o main.o -lm
; .
; Copyright: 2021, Digipen Institute of Technology, Singapore
; .
; Note: All functions use at most 6 parameters
;      p1,  p2,  p3,  p4,  p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
; ------------------------------------------------------------------

    section .text

    global f1
    global f2
    global f3
    global f4
    global f5

f1:
; TODO: Return 5th integer parameter.
    mov rax, r8
    ret

f2:
; TODO: Return the result of addition of the first 3 integer parameters.
    mov rax, rdi
    add rax, rsi
    add rax, rdx
    ret

f3:
; TODO: Return the result of calculation p1 * p2 + p3 / p4 + 1,
;       where operator / calculates an integer result.
; Tip: Be aware that parameter p4 in rdx is used in both * and /.
;      p1,  p2,  p3,  p4,  p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
    mov rax, rdx     ; r15 = p3 / p4
    mov rdx, 0       ; zero out rdi
    idiv rcx
    mov r15, rax     ; div rax with p4 (rcx)

    mov rax, rdi     ; rax = p1 * p2
    imul rsi
    
    add rax, r15      ; rax += r15
 
    add rax, 1    ; rax++

    ret

f4:
; TODO: Return the result of calculation 
;       p1 * 100000 + p2 * 10000 + p3 * 1000 + p4 * 100 + p5 * 10 + p6 * 1.
; Tip: Use push/pop to save rdx temporarily in stack to do multiplications.

    push rdx
    mov rax, rdi
    mov r10, 100000 ; r11 = p1 * 100000
    imul r10
    mov r11, rax

    mov rax, rsi
    mov r10, 10000
    imul r10
    mov r12, rax    ; r12 = p2 * 10000

    pop rdx
    mov rax, rdx
    mov r10, 1000
    imul r10
    mov r13, rax   ; r13 = p3 * 1000

    mov rax, rcx
    mov r10, 100
    imul r10
    mov r14, rax; r14 = p4 * 100

    mov rax, r8
    mov r10, 10
    imul r10
    mov r15, rax; r15 = p5 * 10

    mov rax, r9
    add rax, r11
    add rax, r12
    add rax, r13
    add rax, r14
    add rax, r15; rax = p6 + r11 + r12 + r13 + r14 + r15

    ret
; Note: All functions use at most 6 parameters
;      p1,  p2,  p3,  p4,  p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
f5:
; TODO: Return the result of calculation 
;       p1 / 100000 - p2 / 10000 - p3 / 1000 - p4 / 100 - p5 / 10.
    push rdx
    mov rax, rdi     
    mov rdx, 0      
    mov r10, 100000 
    idiv r10
    mov r11, rax ; r11 = p1 / 100000

    mov rax, rsi; r12 = p2 / 10000
    mov rdx, 0
    mov r10, 10000
    idiv r10
    mov r12, rax
    ; r13 = p3 / 1000
    pop rdx
    mov rax, rdx
    mov rdx, 0
    mov r10, 1000
    idiv r10
    mov r13, rax

    ; r14 = p4 / 100
    mov rax, rcx
    mov rdx, 0
    mov r10, 100
    idiv r10
    mov r14, rax

    ; r15 = p5 / 10
    mov rax, r8;
    mov rdx, 0
    mov r10, 10
    idiv r10
    mov r15, rax

    mov rax, r11
    sub rax, r12
    sub rax, r13
    sub rax, r14
    sub rax, r15; rax = r11 - r12 - r13 - r14 - r15

    ret