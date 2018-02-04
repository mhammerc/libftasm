; void ft_puts(const char *s)
; rdi, rsi, rdx
; write(int fd, void *buf, size_t len)

section .data
    STDOUT equ 1
    SYS_WRITE equ 1
    NEW_LINE db 0xa ; \n

section .text
    global ft_puts
    extern ft_strlen

ft_puts:
    cmp rdi, 0
    je quit

    push rdi

    ; First, get string length with ft_strlen
    call ft_strlen

    ; Print the string
    mov rdi, STDOUT         ; 1st arg: stdout
    pop rsi                 ; 2nd arg: the string
    mov rdx, rax            ; 3rd arg: string length (from strlen return value)

    mov rax, SYS_WRITE      ; syscall write(int fd, void *buf, size_t len)
    syscall

    ; Print a \n
    mov rax, SYS_WRITE      ; syscall write
    mov rdi, STDOUT         ; 1st arg
    mov rsi, NEW_LINE       ; 2nd arg
    mov rdx, 1              ; 3rt arg
    syscall

quit:
    ret