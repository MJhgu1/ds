.data
matrixA:   .float 1.5, -1.2, 2.3, -2.8, 0.7, 3.9, 1.3, 1.3, 1.4, 1.0, 0.5, -1.2, 1.2, -2.1, 1.8
vectorX:   .float 3.2, -1.5, 1.1 # 3 dimension
vectorB:   .float 0.3, -0.5, 1.3, -2.1, 0.1 # 5 dimension
shapeA:    .word 5, 3 # matrix size is 5 x 3
str1: .asciiz "\nshape\n"  #
str2: .asciiz "\nmatrix elements at (0,0) and (0,1)\n"
str3: .asciiz "\nMax matrix is\n" #
space: .asciiz " "
nextLine: .asciiz "\n"
Zero: .float 0.0
.text
main:
    la $a0, matrixA
    la $a1, vectorX
    la $a2, vectorB

    li $t1, 32
    li $s0, 0 # i = 0; initialize 1st for loop
    L1:
    li $s1,0 #j=0; restart2ndforloop
    L2:
    li $s2,0 #k=0; restart3rdforloop

    sll $t2,$s0,5 #$t2=i*32(sizeofrowofx)
    addu $t2, $t2, $s1 # $t2 = i * size(row) + j
    sll $t2, $t2, 2 # $t2 = byte offset of [i][j]
    addu $t2, $a0, $t2 # $t2 = byte address of x[i][j]
    l.d $f4, 0($t2) # $f4 = 8 bytes of x[i][j]

    L3:
    sll $t0,$s2,5 #$t0=k*32(sizeofrowofz)
    addu $t0, $t0, $s1 # $t0 = k * size(row) + j
    sll $t0, $t0, 2 # $t0 = byte offset of [k][j]
    addu $t0, $a2, $t0 # $t0 = byte address of z[k][j]
    l.d $f16, 0($t0) # $f16 = 8 bytes of z[k][j]

    sll $t0,$s0,5
    addu $t0, $t0, $s2
    sll $t0, $t0, 2
    addu $t0, $a1, $t0
    l.d $f18, 0($t0)

    mul.d $f16, $f18, $f16 # $f16 = y[i][k] * z[k][j]
    add.d $f4, $f4, $f16

    addiu $s2, $s2, 1 # k = k + 1
    bne $s2,$t1,L3 #if(k!=32)gotoL3
    s.d $f4, 0($t2)

    li $v0, 2
    add.s $f12, $f4, $f31
    syscall

    addiu $s1, $s1, 1 # j = j + 1
    bne $s1,$t1,L2

    addiu $s0, $s0, 1 # i = i + 1
    bne $s0,$t1,L1
