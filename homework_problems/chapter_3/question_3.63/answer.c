//     The jump table resides in a different area of memory. We can see from
// the indirect jump on line 5 that the jump table begins at address 0x4006f8.
// Using the GDB debugger, we can examine the six 8-byte words of memory
// comprising the jump table with the command x/6gx 0x4006f8. GDB prints the
// following:
//
// (gdb) x/6gx 0x4006f8
// 0x4006f8:    0x00000000004005a1    0x00000000004005c3
// 0x400708:    0x00000000004005a1    0x00000000004005aa
// 0x400718:    0x00000000004005b2    0x00000000004005bf
//
//     Fill in the body of the switch statement with C code that will have the
// same behaviour as the machine code.

// long switch_prob(long x, long n)
//x in %rdi, n in %rsi

//   400590:  48 83 ee 3c             sub    $0x3c,%rsi ; %rsi -= 60 => implying the first case number is 60
//   400594:  48 83 fe 05             cmp    $0x5,%rsi ; if %rsi > 5, jump to 0x4005c3 => implying the case numbers are from 60 - 65
//   400598:  77 29                	  ja     4005c3 <switch_prob+0x33>
//   40059a:  ff 24 f5 f8 06 40 00    jmpq   *0x4006f8(,%rsi,8) ;jump to the case denoted by (%rsi) * (8n) byte
//   4005a1:  48 80 04 fd 00 00 00    lea    0x0(,%rdi,8),%rax ; result = 8*x => this is likely (case 0, case 2)
//   4005a8:  00
//   4005a9:  c3                      retq
//   4005aa:  48 89 f8                mov    %rdi,%rax ; result = x => likely case 3
//   4005ad:  48 c1 f8 03             sar    $0x3,%rax ; result = result >> 3;
//   4005b1:  c3                      retq             ; return => end of case 3
//   4005b2:  48 89 f8                mov    %rdi,%rax ; result = x => likely case 4
//   4005b5:  48 89 e0 04             shl    $0x4,%rax ; result = result << 4
//   4005b9:  48 29 f8                sub    %rdi,%rax ; result = result - x; 
//   4005bc:  48 89 c7                mov    %rax,%rdi ; x = result => fall through
//   4005bf:  48 0f af ff             imul   %rdi,%rdi ; x = x*x => case 5
//   4005c3:  48 8d 47 4b             lea    0x4b(%rdi),%rax  ;%rax = 75 + x => default
//   4005c7:  c3                      ret

long switch_prob(long x, long n){
    long result = x;
    switch(n){
        case 60:
            result = 8*x;
            break;
        case 62:
            result = 8*x;
            break;
        case 63:
            result = x;
            result = >> 3;
            break;
        case 64:
            result = x;
            result = result << 4;
            result = result - x;
        case 65;
            x = x*x;
        default:
            result = 75 + x;
            break;
    }
    return result;
}