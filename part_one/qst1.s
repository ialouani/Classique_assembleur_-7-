	section .text
	global memoire
memoire:
	rdtsc
	push rax	      ;sauve le nombre de cycles jusqu'à maintenant
				;rsi>=8(n>=8)
traiter2:	
	vmovups ymm1,[rdi]	;copiage des 256/32=8 elements vers ymm1
	add rdi,32		;vu que j'ai lu 8 elements je doit ajouter 8*4
				;=32 elements (floats).
	sub rsi,8
	cmp rsi,0
	jne traiter2
fin:
	pop r8
	rdtsc
	sub rax,r8		;temps de cycles=rax_ancien(r8)-rax_nouveau(rax
				;apres appel a rdtsc).
	ret
				;remplir 128 bits par exemple ou moins que 256 bits par ecarts multiple
				;8<256 bits est possible;la lecture se fait et les bits du poids ~fort n'importe peu(demarrage calcul avec precedent depuis ceux
	;du poids trop faible().
	
