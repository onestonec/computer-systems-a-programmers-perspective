/*long sum_col(long n, long A[NR(n)][NC(n)], long j) {
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++)
        result += A[i][j];
    return result;
} */

# long sum_col(long n, long A[NR(n)][NC(n)], long j)
# n in %rdi, A in %rsi, j in %rdx
sum_col:
  leaq	  1(,%rdi,4), %r8           ; %r8 = 4 * %rdi + 1
  leaq    (%rdi,%rdi,2), %rax       ; %rax = 3 * %rdi
  movq    %rax, %rdi                ; %rdi = %rax
  testq   %rax, %rax                ; if %rax <= 0, go to L4 and return 0 essentially
  jle     .L4
  salq    $3, %r8                   ; %r8 = %r8 << 3
  leaq    (%rsi,%rdx,8), %rcx       ; %rcx = 8 * %rdx + %rsi
  movl    $0, %eax                  ; %eax = 0 => implying result = 0
  movl    $0, %edx                  ; %edx = 0 => implying that is i (?)
.L3:                            
  addq    (%rcx), %rax              ; %rax = %rax + (%rcx) => result += A[i][j]
  addq    $1, %rdx                  ; %rdx = %rdx + 1 => incrementing
  addq    %r8, %rcx                 ; %rcx = %rcx + %r8
  cmpq    %rdi, %rdx                ; %rdx - n
  jne     .L3
  rep; ret
.L4:
  movl    $0, %eax
  ret

//#define NR(v) (3 * (v))
//#define NC(v) (4 * (v) + 1)