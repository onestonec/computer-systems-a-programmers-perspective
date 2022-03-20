# long loop(long x, int n)
# x in %rdi, n in %esi
loop:
  movl %esi, %ecx   ;%ecx = %esi => implying %ecx = n
  movl $1, %edx     ;$edx = 1 => implying %edx is mask
  movl $0, %eax     ;%eax = 0 => implying result = 0
  jmp .L2
.L3:
  movq %rdi, %r8    ;%r8 = %rdi
  andq %rdx, %r8    ;%r8 = %r8 & %rdx => implying %r8 = (x & mask)
  orq %r8, %rax     ;%rax = %rax | %r8 => implying result != (x & mask)
  salq %cl, %rdx    ;
.L2:
  testq %rdx, %rdx  ;
  jne .L3
  rep
  ret