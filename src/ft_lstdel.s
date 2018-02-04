; void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
; rdi, rsi
; using recursion

%include "include/libfts.s"

section .text
    global ft_lstdel
    extern free

ft_lstdel:
    cmp rdi, 0
    je quit
    cmp qword [rdi], 0
    je quit
    cmp rsi, 0
    je quit

    mov r8, rdi                             ; r8 = alst
    mov r9, [r8]                            ; r9 = *alst
    mov r10, rsi                            ; r10 = void (*del)(void *, size_t)

    push r8
    push r9
    push r10

    mov rdi, r9
    add rdi, t_list.next                    ; call the recursion on the next node
    call ft_lstdel

    pop r10
    pop r9
    pop r8
    
    push r8
    push r9

    mov rdi, [r9 + t_list.content]          ; call the 2nd arg: del
    mov rsi, [r9 + t_list.content_size]     ; with the current node as parameter
    call r10                                ; (r10 end of life)

    pop r9
    pop r8

    push r8

                                            ; (r9 end of life)
    mov rdi, r9                             ; and finally free the current node
    call free wrt ..plt                     ; (not its content, del() did it.)

    pop r8
    mov qword [r8], 0                       ; set *alst to zero (because it is freed).

quit:
    mov rax, 0
    ret