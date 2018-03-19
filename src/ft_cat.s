; ft_cat(int fd)
; rdi, rsi, rdx
;
; syscall ssize_t read(int fd, void *buf, size_t count)
; syscall ssize_t write(int fd, const void *buf, size_t count);
; We use a buffer of 4096 bytes.

section .data
    STDOUT equ 1
    SYS_READ equ 0
    SYS_WRITE equ 1

    BUFFER_SIZE equ 4096

section .text
    global _ft_cat

_ft_cat:
    mov rdx, BUFFER_SIZE    ; Buffer size
    sub rsp, BUFFER_SIZE    ; Allocate the buffer
    mov rsi, rsp            ; Save the buffer pointer

    cmp rdi, 0
    jl quit

ft_cat_loop:
    mov rax, SYS_READ
    syscall

    cmp rax, 0
    jle quit

    push rdi

    mov rdi, 1
    mov rdx, rax
    mov rax, SYS_WRITE
    syscall

    pop rdi
    mov rdx, BUFFER_SIZE

    cmp rax, 0
    jl quit
    jmp ft_cat_loop

quit:
    add rsp, BUFFER_SIZE  ; Free the buffer
    ret
