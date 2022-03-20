store_prod:             # store_prod(rdi, rsi, rdx)
  movq    %rdx, %rax    # rax = rdx
  cqto                  # rdx = rax >> 63
  movq    %rsi, %rcx    # rcx = rsi
  sarq    $63, %rcx     # rcx >>= 63
  imulq   %rax, %rcx    # rcx *= rax
  imulq   %rsi, %rdx    # rdx *= rsi
  addq    %rdx, %rcx    # rcx += rdx
  mulq    %rsi          # rdx:rax = rsi * rax
  addq    %rcx, %rdx    # rdx += rcx
  movq    %rax, (%rdi)  # *(rdi + 0) = rax
  movq    %rdx, 8(%rdi) # *(rdi + 8) = rdx
  ret

# In the above code, rsi is xl, rcx is xh, rax is yl, rdx is yh.
#   x * y                                                   (mod 2^128)
# = (2^64 * xh + xl) * (2^64 * yh + yl)                     (mod 2^128)
# = 2^128 * xh * yh + 2^64 * (xh * yl + xl * yh) + xl * yl  (mod 2^128)
# = 2^64 * (xh * yl + xl * yh) + xl * yl
# = 2^64 * (xh * yl + xl * yh + xl * yl / 2^64) + xl * yl % 2^64
#
# And according to the Equation 2.7 (P94 in English ver or P67 Chinese translate
# ver), the result of low 64 bits can be calculated through unsigned
# multiplication and a modulus, so one mulq is enough to produce both xl * yl /
# 2^64 and xl * yl % 2^64, which will be saved in rdx and rax by mulq.