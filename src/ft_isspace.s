; int ft_isspace(int c)
; rdi

section .text
	global ft_isspace

ft_isspace:
	mov rax, 0
	cmp rdi, ' '
	jne quit
	mov rax, rdi

quit:
	ret
