; int ft_isascii(int c)
; rdi, rsi

section .text
	global _ft_isascii

_ft_isascii:
	mov rax, 0
	cmp rdi, 0
	jl quit
	cmp rdi, 127
	jg quit
	mov rax, 1

quit:
	ret
