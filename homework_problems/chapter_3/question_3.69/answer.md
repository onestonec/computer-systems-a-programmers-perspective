A. According to

``` asm
lea (%rdi,%rdi,4),%rax
lea (%rsi,%rax,8),%rax
mov 0x8(%rax),%rdx
```

The expression `&bp->a[i]` is equal to `bp + i * 5 * 8 + 8`. It means the width of `a_struct` is 40. So CNT is the difference of offset of `&b_struct.last` and `&b_struct.a` divide 40, which is 7 exactly.

B.
The `ap->idx` should be saved at `%rdx` after `mov 0x8(%rax),%rdx`. so `0x10(%rax,%rdx,8)` is the address of `ap->x[ap->idx]`, and the offset of `a_struct.x` is 8. So

``` C
typedef struct {
    long idx;
    long x[4];
} a_struct
```