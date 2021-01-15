#Project done by Javier Carranza and Herbert Alvarenga
.data 
prompt: .asciiz "Put a value for n : \n "
result: .asciiz "The result is : \n "
.text
.globl main
.macro PrintDouble(%str, %double)
	la $a0, %str
	li $v0, 4
	syscall 
	mov.d $f14, %double
	li $v0, 3 
	syscall 
	li $a0, '\n' 
	li $v0, 11
	syscall 
.end_macro 

main:
	li $v0, 4
	la $a0, prompt
	syscall 
	li $v0, 5
	syscall 
	move $a0, $v0 
	jal recusiveFunction
	PrintDouble(result, $f12)
done:
	li $v0, 10
	syscall 
	
recusiveFunction :
	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	li $t0, 2 
	bge $a0, $t0, recusivecall
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	li $t1, 1  
	mtc1 $t1, $f12 
	cvt.d.w $f12, $f12 
	jr $ra 
recusivecall:
	addi $a0, $a0, -1 
	jal recusiveFunction  
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	addi $sp, $sp, 8
	li $t1,4 
	mtc1 $t1, $f4 
	cvt.d.w $f4, $f4
	li $t2, 1    
	mtc1 $t2, $f14
	cvt.d.w $f14, $f14 
	mtc1 $a0, $f6 
	cvt.d.w $f6, $f6
	mul.d $f8, $f6, $f6 
	mul.d $f10, $f8, $f6 
	mul.d $f14, $f14, $f10 
	div.d $f4, $f4, $f6 
	add.d $f4, $f4, $f14
	mul.d $f12, $f12, $f4 
	jr $ra

	

