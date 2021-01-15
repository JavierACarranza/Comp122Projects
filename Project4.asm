#Project done by Javier Carranza and Herbert Alvarenga
.macro printStr(%str)
	.data
mystring: .asciiz %str
	.text
	li $v0,4
	la $a0, mystring
	syscall
	li $a0, '\n'
	li $v0, 11
	syscall
.end_macro

.macro printInt(%str1, %int,%str2)
	.data
mystring: .asciiz %str1
	.text
	li $v0, 4
	la $a0,mystring
	syscall
	li $v0,1	
	move $a0,%int
	syscall
	.data
mystring2: .asciiz %str2
	.text
	li $v0, 4
	la $a0,mystring2
	syscall
	li $a0,'\n'
	li $v0,11
	syscall
.end_macro

.macro getInt(%intReg)
li $v0,5
syscall
add %intReg, $0,$v0
.end_macro

.macro loadDouble(%int,%double)
mtc1 %int, %double
cvt.d.w %double, %double
.end_macro


.macro midpoint(%from, %to,%n, %result)
	addi $sp, $sp, -40
	sdc1 $f20, 0($sp)
	sdc1 $f24, 8($sp)
	sdc1 $f26, 16($sp)
	sdc1 $f28, 24($sp)
        sdc1 $f30, 32($sp)
        sub.d $f24, %to, %from
        div.d $f24, $f24, %n
        addi $sp,$sp,-4
        sw $s0,0($sp)
        li $s0,0
        loadDouble($s0,$f26)
        loadDouble($s0,$f28)
        mov.d $f28,%from
        sub.d $f30, %to, $f24
loop:
	c.lt.d $f30,$f28
	bc1t out
	li $s0,2
	loadDouble($s0,$f20)
	div.d $f20, $f24, $f20
	add.d $f20, $f28, $f20
	fx($f20,$f20)
	add.d $f26, $f20,$f26
	add.d $f28, $f28,$f24
	j loop
out:
	mul.d %result, $f26,$f24
	lw $s0,0($sp)
	addi $sp,$sp,4
	ldc1 $f20,0($sp)
	ldc1 $f24,0($sp)
	ldc1 $f26,0($sp)
	ldc1 $f28,0($sp)
	ldc1 $f30,0($sp)
	addi $sp,$sp,40
.end_macro

.macro fx(%din,%dout)
addi $sp, $sp,-4
sw $s0,0($sp)
addi $sp,$sp,-16
sdc1 $f24,0($sp)
sdc1 $f26,8($sp)
li $s0,4
loadDouble($s0,$f26)
mul.d $f24, %din,%din
add.d $f24, $f24,$f26
mul.d %dout,$f24,%din
ldc1 $f24,0($sp)
ldc1 $f26,8($sp)
addi $sp, $sp, 16
lw $s0, 0($sp)
addi $sp,$sp,4
.end_macro

main:       
	printStr("Welcome to Project 4, numerical integration \n")
        printStr("Please Enter the start of the interval \n")
        getInt($t0)
        printStr("Please Enter the end of the interval\n")
        getInt($t1)
        printStr("Please Enter the number of iterations you wish to have\n")
        getInt($t2)
        printInt("********** Calculating f(x) from ", $t0," to" )
        printInt(" ",$t1, " using the midpoint formula \n")

        #initialize
        addi $sp, $sp, -16
        andi $sp, $sp, 0xFFFFFFF8
        li $t3, 0
        li $t1, 10
        li $t0, 0
        li $t2, 20
        loadDouble($t0, $f4)
        loadDouble ($t1, $f6)
        loadDouble ($t2, $f8)
        loadDouble ($t3, $f12)

        midpoint($f4,$f6,$f8,$f12)

done:
