; int ft_isprint(int c)
; rdi, rsi

section .text
	global ft_isprint
	extern ft_isspace
	extern ft_isalnum
	extern ft_ispunct

ft_isprint:			; Char is printable if:
	call ft_isspace	; (ft_isspace(c) || ft_isalnum(c) || ft_ispunct(c))
	cmp rax, 0
	jg quit

	call ft_isalnum
	cmp rax, 0
	jg quit

	call ft_ispunct

quit:
	ret
