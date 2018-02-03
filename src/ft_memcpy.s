; void *ft_memcpy(void *dest, const void *src, size_t n);
; rdi, rsi, rdx
; Note: int c is just a byte (char c)
; using REP

section .text
    global ft_memcpy

ft_memcpy:
    mov rbx, rdi

    cmp rdi, 0
    je quit

    mov rcx, rdx    ; Count register
    mov al, sil     ; move c into al
    rep movsb       ; copy al into rdi until rcx == 0

quit:
    mov rax, rbx    ; Return the original rdi
    ret