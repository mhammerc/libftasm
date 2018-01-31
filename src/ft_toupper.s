; int ft_toupper(int c)
; rdi

section .text
    global ft_toupper

ft_toupper:
    mov rax, rdi

    ; We want to test if rdi is between 'a' and 'z'.
    ; if (rdi >= 'a' && rdi <= 'z')
    ; We can simplify it with:
    ; if ((unsigned)(rdi - 'a') <= ('z' - 'a'))

    sub rdi, 'a'
    mov rsi, 'z'
    sub rsi, 'a'
    cmp rdi, rsi
    jnbe quit
    sub rax, 32

quit:
    ret