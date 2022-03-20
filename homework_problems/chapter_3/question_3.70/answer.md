A. See table below
| Field | Offset |
| --- | --- |
| e1.p | 0 |
| e1.y | 8 |
| e2.x | 0 |
| e2.next | 8 |

The reason is that **With a union, all members share the same memory (i.e. laying on top of each other)**
			
** Versus with a struct, they do not share memory, so a different space in memory is allocated to each member of the struct.** 

B. 16 bytes (either e1 and e2 is 16)

C. The compiler genreates the following assembly code for the body of proc:

``` asm
void proc (union ele *up)
up in %rdi
proc:
	movq	8(%rdi),	%rax    ;offset from %rdi => either pointing to up->e1.y or up->e2.next 
	movq	(%rax),		%rdx    ;dereference from %rax => impying it is *(up->e2.next)
	movq	(%rdx),		%rdx    ;Further dereference without offset => implying it is *(*(up->e2.next)->e1.p)
	subq	8(%rax),	%rdx    ;*(*(up->e2.next)->e1.p) - *(up->e2.next).e1.y //offset 8 from whatever *(up->e2.next) is pointing at to get a long number  for subtraction => has to be e1.y
	movq	%rdx,		(%rdi)  ; up->e2.x = *(*(up->e2.next)->e1.p) - *(up->e2.next).e1.y //up->e2.x because %rdi is still referencing e2
	ret
```

``` C
//Void proc function:
void proc (union ele *up) {
	up->____ = *(____) - ____;
}
```

On the basis of this information, fill in the missing expressions in the code for proc.
Hint: Some union references can have ambiguous interpretations. These ambiguities get resolved as you see where the references lead. There is only one answer that does not perform any casting and does not violate any type constraints. 

Reference:
``` C
union ele {
	struct {
		long *p;
		long y;
	} e1;
	struct {
		long x;
		union ele *next;
	} e2;
};
```
