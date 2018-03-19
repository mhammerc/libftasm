; int ft_isprint(int c)
; rdi, rsi

section .text
	global _ft_isprint
	extern _ft_isspace
	extern _ft_isalnum
	extern _ft_ispunct

_ft_isprint:			; Char is printable if:
	call _ft_isspace	; (ft_isspace(c) || ft_isalnum(c) || ft_ispunct(c))
	cmp rax, 0
	jg quit

	call _ft_isalnum
	cmp rax, 0
	jg quit

	call _ft_ispunct

quit:
	ret
