; size_t ft_strlen(const char *s)
; rdi
; using REP

section .text
    global ft_strlen

ft_strlen:
    mov rax, 0
    cmp rdi, 0
    je quit

    mov rcx, -1 ; Count register from repne
    repne scasb ; scan string until al (\0)
    mov rax, -2
    sub rax, rcx
    

quit:
    ret