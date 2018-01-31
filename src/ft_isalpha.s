; int ft_isalpha(int c)
; rdi, rsi

section .text
	global ft_isalpha

return_false:
	mov rax, 0
	ret

return_true:
	mov rax, rdi
	ret

ft_isalpha:
	cmp rdi, 65
	jl return_false
	cmp rdi, 90
	jle return_true
	cmp rdi, 97
	jl return_false
	cmp rdi, 122
	ja return_false
	jmp return_true
