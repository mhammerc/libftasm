; int ft_isalnum(int c)
; rdi, rsi

section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 0
	jg quit
	call _ft_isdigit

quit:
	ret
