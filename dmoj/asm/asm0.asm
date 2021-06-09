; libc

global main
extern printf, scanf, exit

section .bss
    a resb 4

section .data
    scan_int: db "%d", 0
    print_int: db "%d", 10, 0

section .text
main:
    ; Initialize r8 to 0.
    mov r8, 0

    ; Add a to the total.
    mov rdi, scan_int
    mov rsi, a
    push r8
    call scanf
    pop r8
    add r8, [a]

    ; Add b to the total.
    mov rdi, scan_int
    mov rsi, a
    push r8
    call scanf
    pop r8
    add r8, [a]

    ; Add c to the total.
    mov rdi, scan_int
    mov rsi, a
    push r8
    call scanf
    pop r8
    add r8, [a]

    ; Compute the mean.
    mov rax, r8
    mov r9, 3
    div r9

    ; Print the mean.
    mov rdi, print_int
    movsx rsi, al
    push rcx
    call printf
    pop rcx
    mov rdi, 0
    call exit
    ret
