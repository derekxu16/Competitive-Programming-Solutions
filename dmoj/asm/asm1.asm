; libc

global main
extern printf, scanf, exit

section .bss
    n resb 4
    a resb 4

section .data
    scan_int: db "%d", 0
    print_ints: db "%d %d", 10, 0

section .text
main:
    ; Initialize min in r8.
    mov r8, 2000
    ; Initialize max in r9.
    mov r9, -2000

    ; Read n into rcx.
    mov rdi, scan_int
    mov rsi, n
    push rcx
    push r8
    push r9
    call scanf
    pop r9
    pop r8
    pop rcx
    movsx rcx, dword [n]

L1:
    ; Read an integer into r10. 
    mov rdi, scan_int
    mov rsi, a
    push rcx
    push r8
    push r9
    call scanf
    pop r9
    pop r8
    pop rcx
    movsx r10, dword [a]

    ; Update min and max.
    cmp r10, r8
    jge SKIP_MIN
    mov r8, r10
SKIP_MIN:
    cmp r10, r9
    jle SKIP_MAX
    mov r9, r10
SKIP_MAX:
    ; Loop n times.
    dec rcx
    jnz L1

    ; Print the min and max.
    mov rdi, print_ints
    mov rsi, r8
    mov rdx, r9
    push rcx
    call printf
    pop rcx
    mov rdi, 0
    call exit
    ret
