	section .text
	global memoire
memoire:
	rdtsc
	push rax
traiter3:	
				;au moins len(*A) multiple de 32
	vmovups ymm1,[rdi]
	vmovups ymm2,[rdi+32]	;car 32/4=8 elements ont ete lus.
	vmovups ymm3,[rdi+64]
	vmovups ymm4,[rdi+96]	;on ajoute 4*8elements (octets) a chaque fois
				;ce qui fera 32 octets en gros.//


	vmovups ymm5,[rdi+128]
	vmovups ymm6,[rdi+160]	
	vmovups ymm7,[rdi+188]	
	vmovups ymm8,[rdi+220]	
	add rdi,252
	sub rsi,64
	cmp rsi,0
	jnz traiter3
fin:	
	pop r10
	rdtsc
	sub rax,r10
	ret
