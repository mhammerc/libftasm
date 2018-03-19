; void ft_strcat(char *dest, char *src)
; rdi, rsi
; TODO: using rep

section .text
	global _ft_strcat

_ft_strcat:
	cmp rdi, 0		; Check if dest and src are NULL.
	je quit_error			; If so, quit.
	cmp rsi, 0
	je quit_error
	push rdi

going_to_dest_end_loop:	; A loop to reach the end of dest
	cmp byte [rdi], 0
	je writing_src_in_dest
	inc rdi
	jmp going_to_dest_end_loop


writing_src_in_dest:	; A loop to write src in current pos of dest
	mov al, [rsi]
	mov [rdi], al		; *dest = *src
	inc rdi
	inc rsi
	cmp byte [rsi], 0		; If we reach the end of src (\0) then quit
	je quit
	jmp writing_src_in_dest

quit:
	pop rdi
	mov rax, rdi
	ret

quit_error:
	mov rax, 0
	ret