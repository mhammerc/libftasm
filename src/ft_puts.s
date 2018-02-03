; void ft_puts(const char *s)
; edi       edx, eax
; dil, sil
; rdi, rsi, rdx
; write(int fd, void *buf, size_t len)

section .text
    global ft_puts
    extern strlen   ; TODO: must use ft_strlen

ft_puts:
    push rbp

    cmp rdi, 0
    je end

    ; First, get string length with strlen
    mov rax, 0
    call strlen wrt ..plt

    mov rsi, rdi    ; 2nd arg: the string (from first arg)
    mov rdx, rax    ; 3rd arg: string length (from strlen return value)

    mov rax, 1      ; syscall write(int fd, void *buf, size_t len)
    mov rdi, 1      ; stdout
    syscall

end:
    pop rbp
    ret