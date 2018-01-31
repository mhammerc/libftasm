; void ft_puts(const char *s)
; edi       edx, eax
; dil, sil
; rdi, rsi, rdx

section .text
    global ft_puts
    extern strlen   ; TODO: must use ft_strlen

ft_puts:
    push rbp
    mov rbp, rsp

    ;push rdi
    ;mov rbx, rdi
    ; First, get string length with strlen
    mov rax, 0
    call strlen
    ;pop rdi
    ;mov rdx, rax    ; String length is in rdx

    ;mov rsi, rbx
    ;mov rax, 1      ; syscall write(int fd, char *buf, size_t len)
    ;mov rdi, 1      ; stdout
    ;syscall

    mov rsp, rbp
    pop rbp
    ret