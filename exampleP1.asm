
  .text
  .globl main

main:
  addi $t0, $zero, 5    #this is a comment that needs to be ignored
  #this is another comment that needs to be ignored
  sub $t0, $zero, $s5 #IGNORE HERE
  addi $s0, $zero, 0
  addi $t5, $0, 8
  addi $t6, $0, 2
  addi $t3, $0, 3
  addi $t4, $0, 4

  sub $t0, $t0, $13
  sll $t1, $t2, 4
  srl $t1, $t2, 8
  slt $t0, $t1, $t2
  lw $t4, 4($t3) #expected decimal number is  2372665348
  sw $t6, 8($t3) #expected decimal number is 2909667336
  

  jal loop

  addi $t2, $zero, 0

  jalr $ra, $s2

  j endProgram

loop:
  add $s0, $s0, $t0
  addi $t0, $t0, -1
  addi $t0, $t0, 5
  mult $t5, $t6 
  mflo $t3 
  div $t5, $t6 
  mflo $t4 
  bne $t0, $zero, loop
  jr $ra

endProgram:
  addi $v0, $0, 10 #End Program
  syscall
