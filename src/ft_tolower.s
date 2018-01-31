; int ft_tolower(int c)
; rdi

section .text
    global ft_tolower

ft_tolower:
    mov rax, rdi

    ; We want to test if rdi is between 'A' and 'Z'.
    ; if (rdi >= 'A' && rdi <= 'Z')
    ; We can simplify it with:
    ; if ((unsigned)(rdi - 'A') <= ('Z' - 'A'))

    sub rdi, 'A'
    mov rsi, 'Z'
    sub rsi, 'A'
    cmp rdi, rsi
    jnbe quit
    add rax, 32

quit:
    ret