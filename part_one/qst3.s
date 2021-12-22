	section .text
	global memoire
memoire:
	rdtsc
	push rax
traiter3:	
				;au moins len(*A) multiple de 32
	vmovups ymm1,[rdi]
	vmovups ymm2,[rdi+32]	;car 32/4=8 elements ont ete lus.
	vmovups ymm2,[rdi+64]
	vmovups ymm2,[rdi+96]	;on ajoute 4*8elements (octets) a chaque fois
				;ce qui fera 32 octets en gros.//
	
	add rdi,128
	sub rsi,32
	cmp rsi,0
	jnz traiter3
fin:	
	pop r10
	rdtsc
	sub rax,r10
	ret
