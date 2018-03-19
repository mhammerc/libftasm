; void *ft_memset(void *s, int c, size_t n);
; rdi, rsi, rdx
; Note: int c is just a byte (char c)
; using REP

section .text
    global _ft_memset

_ft_memset:
    mov rbx, rdi

    cmp rdi, 0
    je quit

    mov rcx, rdx    ; Count register
    mov al, sil     ; move c into al
    rep stosb       ; copy al into rdi until rcx == 0

quit:
    mov rax, rbx    ; Return the original rdi
    ret