; void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
; rdi, rsi

%include "include/libfts.s"

section .text
    global ft_lstdelone
    extern free

ft_lstdelone:
    cmp rdi, 0
    je quit
    cmp qword [rdi], 0
    je quit
    cmp rsi, 0
    je quit

    mov r8, rdi                     ; r8 = alst
    mov r9, [rdi]                   ; r9 = *alst
    mov r10, rsi                    ; r10 = del()

    push r8
    push r9

    mov rdi, [r9 + t_list.content]
    mov rsi, [r9 + t_list.content_size]
    call r10                        ; r10 end of life

    pop r9
    pop r8

    push r8

    mov rdi, r9                     ; r9 end of life
    call free wrt ..plt

    pop r8

    mov qword [r8], 0               ; r8 end of life

quit:
    mov rax, 0
    ret