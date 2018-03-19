; void ft_lstadd(t_list **alst, t_list *new)
; rdi, rsi

%include "include/libfts.s"

section .text
    global _ft_lstadd

_ft_lstadd:
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit

    mov r8, [rdi]
    mov qword [rsi + t_list.next], r8       ; new->next = *alst
    mov qword [rdi], rsi                    ; *alst = new

quit:
    mov rax, 0
    ret
