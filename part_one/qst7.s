	section .text
	global memoire
memoire:
				;on a un sous-tableau a parcourir avec sa longueur
	rdtsc
	push rax
traiter:
	vmovups ymm1,[rdi]
	vmovups ymm2,[rdi+32]
	vmovups ymm3,[rdi+64]
	vmovups ymm4,[rdi+96]
	add rdi,128
	sub rsi,32
	cmp rsi,4
	jge traiter
fin:
	pop r10
	rdtsc
	sub rax,r10
	ret
	
