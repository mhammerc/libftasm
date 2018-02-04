; void ft_bzero(void *s, size_t n)
; rdi, rsi, rdx, rcx, r8, r9
; TODO using rep

section .text
	global ft_bzero

ft_bzero:
	cmp rdi, 0
	je quit				; If s == 0 then quit

loop_begin:
	cmp rsi, 0
	je quit				; rsi is our counter. If it reach 0, we're done.
	dec rsi

	mov byte [rdi], 0	; Set the current byte to 0
	inc rdi
	jmp loop_begin

quit:
	ret
