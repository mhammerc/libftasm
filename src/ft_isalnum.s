; int ft_isalnum(int c)
; rdi, rsi

section .text
	global ft_isalnum
	extern ft_isalpha
	extern ft_isdigit

ft_isalnum:
	call ft_isalpha
	cmp rax, 1
	je quit
	call ft_isdigit

quit:
	ret
