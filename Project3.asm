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

.macro printInt(%str, %int)
	la $a0, %str
	li $v0, 4
	syscall
	addi $a0, %int
	li $v0,1
	syscall
	li $a0, "\n"
	li $v0,11
	syscall
.end_macro

.macro loadDouble(%int,%double)
mtc1 %int, %double
cvt.d.w %double, %double
.end_macro

.macro midpoint(%from, %to,%n, %result)
	addi $sp, $sp, -40
	sdc1 $f20, 0($sp)
	sdc1 %$f24, 8($sp)
	sdc1 %$f26, 16($sp)
	sdc1 %$f28, 24($sp)
        sdc1 %$f30, 32($sp)
.end_macro


main:       
	printStr("Welcome to Project 4, numerical integration \n")
        printStr("Please Enter the start of the interval \n")
#        getInt($t0)
        printStr("Please Enter the end of the interval\n")
#        getInt($t1)
        printStr("Please Enter the number of iterations you wish to have\n")
 #       getInt($t2)
        printInt("********** Calculating f(x) from ", $t0, " to")
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


