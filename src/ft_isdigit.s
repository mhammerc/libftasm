; int ft_isdigit(int c)
; rdi, rsi

section .text
	global ft_isdigit

return_false:
	mov rax, 0
	ret

return_true:
	mov rax, rdi
	ret

ft_isdigit:
	cmp rdi, 48
	jl return_false
	cmp rdi, 57
	jle return_true
	jmp return_false
