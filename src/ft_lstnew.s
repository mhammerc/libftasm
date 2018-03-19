; t_list *ft_lstnew(void const *content, size_t content_size)
; 
; typedef struct s_list t_list; See in libfts.h
; void *malloc(size_t size);
; void *ft_memcpy(void *dest, const void *src, size_t n)
;
; rdi, rsi, rdx

%include "include/libfts.s"

section .text
    global _ft_lstnew
    extern _malloc
    extern _free
    extern _ft_memcpy

_ft_lstnew:
    push rdi
    push rsi

    mov rdi, SIZEOF_T_LIST
    call _malloc                                ; Allocate t_list
    cmp rax, 0                                  ; rax = list
    je quit_1

    mov qword [rax + t_list.next], 0               ; list->next = NULL

    pop r9                                      ; r9 = content_size
    pop r8                                      ; r8 = content

    cmp r8, 0
    je content_empty

content_not_empty:
    mov qword [rax + t_list.content_size], r9      ; list->content_size = content_size

    push r8
    push r9
    push rax

    mov rdi, r9
    call _malloc                                ; allocate list->content
    
    mov r10, rax                                ; r10 = newly allocated content
    pop rax
    pop r9
    pop r8

    cmp r10, 0
    je quit_2

    mov qword [rax + t_list.content], r10          ; list->content = r10

    push rax

    mov rdi, r10
    mov rsi, r8
    mov rdx, r9
    call _ft_memcpy

    pop rax
    ret

content_empty:
    mov qword [rax], 0                          ; list->content = NULL
    mov qword [rax + t_list.content_size], 0       ; list->content_size = 0
    ret

quit_1:
    pop rsi
    pop rdi
    mov rax, 0
    ret

quit_2:
    mov rdi, rax
    call _free                                     ; free list
    mov rax, 0
    ret