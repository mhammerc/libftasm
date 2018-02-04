; void ft_lstaddback(t_list **alst, t_list *new)
; rdi, rsi

%include "include/libfts.s"

section .text
    global ft_lstaddback

ft_lstaddback:
    cmp rdi, 0
    je quit
    cmp rsi, 0
    je quit

    mov r8, [rdi]       ; r8 = *alst
    cmp r8, 0
    je no_alst

    cmp qword [r8 + t_list.next], 0
    je after_loop

loop_list_end:
    mov r8, [r8 + t_list.next]
    cmp qword [r8 + t_list.next], 0
    jne loop_list_end

after_loop:
    mov qword [r8 + t_list.next], rsi
    jmp quit

no_alst:
    mov [rdi], rsi

quit:
    mov rax, 0
    ret
