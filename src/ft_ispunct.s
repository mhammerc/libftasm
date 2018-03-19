; int ft_ispunct(int c)
; edi, ebx, ecx

; ft_ispunct is:
;  return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
;  || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
;
; thus we can refactor it:
;
;  return (((unsigned)(c - 33) <= (47 - 33)) || ((unsigned)(c - 58) <= (64 - 58))
;  || ((unsigned)c - 91) <= (96 - 91) || ((unsigned)(c - 123) <= (126 - 123)))
;
;  Only four comparaisons.

section .text
	global _ft_ispunct

_ft_ispunct:
	mov rax, rdi

	mov ebx, edi
	sub ebx, 33
	mov ecx, 47
	sub ecx, 33
	cmp ebx, ecx
	jbe quit

	mov ebx, edi
	sub ebx, 58
	mov ecx, 64
	sub ecx, 58
	cmp ebx, ecx
	jbe quit

	mov ebx, edi
	sub ebx, 91
	mov ecx, 96
	sub ecx, 91
	cmp ebx, ecx
	jbe quit

	mov ebx, edi
	sub ebx, 123
	mov ecx, 126
	sub ecx, 123
	cmp ebx, ecx
	jbe quit

	mov rax, 0

quit:
	ret
