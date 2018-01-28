; void ft_strcat(char *dest, char *src)
; rdi, rsi

section .text
	global ft_strcat

quit:
	pop rdi
	mov rax, rdi
	ret

ft_strcat:
	push rdi
	cmp rdi, 0		; Check if dest and src are NULL.
	je quit			; If so, quit.
	cmp rsi, 0
	je quit

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

