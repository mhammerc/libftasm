; int ft_isspace(int c)
; rdi

section .text
	global _ft_isspace

_ft_isspace:
	mov rax, 0
	cmp rdi, ' '
	jne quit
	mov rax, rdi

quit:
	ret
