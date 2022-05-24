; nasm -f elf sqrt.asm -o sqrt.o
; gcc sqrt.o -o sqrt

default rel
extern printf
extern scanf

section .data
    format_output:   	db "%f", 0xa, 0
    format_input:	db "%lf", 0
	
section .bss
	res:	resq 1
	x:      resq 1

section .text
    global main
main:
    sub    rsp, 8
	
	mov 	rsi, x
        mov 	rdi, format_input
        mov 	rax, 1
	call scanf	wrt ..plt
	
	fld qword [x]  

	fsqrt

	fstp qword [res]
	
	movq 	xmm0, qword [res]
    mov 	rdi, format_output
    mov 	rax, 1
    call   printf  wrt ..plt

    add    rsp, 8
    xor    eax, eax
    ret
