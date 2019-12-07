.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0,4
  la $a0,_Prompt
  syscall
  li $v0,5
  syscall
  jr $ra
write:
  li $v0,1
  syscall
  li $v0,4
  la $a0,_ret
  syscall
  move $v0,$0
  jr $ra

main:
  addi $sp, $sp, -20
label4:
  li $t3, 3
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  lw $t2, 16($sp)
  blt $t1,$t2,label3
  j label2
label3:
  j label4
label2:
  li $t3, 3
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  move $t3, $t1
  sw $t3, 16($sp)
  li $t3, 0
  sw $t3, 16($sp)
  lw $v0,16($sp)
  jr $ra
label1:
