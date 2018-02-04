; char *ft_strdup(const char *s)
; rdi, rsi, rdx
; using REP
;
; (1) size_t ft_strlen(const char *s)
; (2) void   *malloc(size_t size)
; (3) void   *ft_memcpy(char *dest, const char *src, size_t n)

section .text
    global ft_strdup
    extern ft_strlen
    extern ft_memcpy
    extern malloc

ft_strdup:
    mov rax, 0
    cmp rdi, 0          ; if rdi (s) is null then quit
    je quit

    push rdi

    call ft_strlen      ; (1) arg1: (s), already in rdi
    mov rdi, rax        ; (2) arg1: new string size
    add rdi, 1
    push rdi

    call malloc wrt ..plt ; allocate new memory (same size as s)
    cmp rax, 0
    je quit
    mov rdx, rdi        ; (3) arg3: size of the copy
    mov rdi, rax        ; (3) arg1: newly allocated string
    
    pop rdx
    pop rsi
    call ft_memcpy      ; copy every bytes from old string to new

quit:
    ret