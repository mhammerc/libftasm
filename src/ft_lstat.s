; t_list *ft_lstat(t_list *list, size_t index)
; rdi, rsi

%include "include/libfts.s"

section .text
    global ft_lstat

ft_lstat:
    mov rax, 0

    cmp rdi, 0                              ; list == null -> quit
    je quit

    mov rcx, rsi                            ; rcx = index
    mov rax, rdi                            ; rax = list

    cmp rcx, 0                              ; index == null -> quit
    je quit

loop_1:
    mov qword rax, [rax + t_list.next]
    loop loop_1

quit:
    ret
