/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int a = (x & y);
  int b = (~x & ~y);
  return ((~a) & (~b));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return ~(1 << 31);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  //For odd test, use (0xAAAAAAAA) => because they will have to return (0xAAAAAAAA)
  //For even test, use (0x55555555) => because they will have to return (0x55555555)
  int mask = 0xAAAAAAAA;
  int test_result = (x & (mask));
  return !(test_result ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int first_digit_check = !((x >> 4) ^ 0x3); //check if the first digit is 3 
  int second_digit_check = (!( ((x << 28) >> 28) ^ 0x0) || !( ((x << 28) >> 28) ^ 0x1) || !( ((x << 28) >> 28) ^ 0x2) || !( ((x << 28) >> 28) ^ 0x3) || !( ((x << 28) >> 28) ^ 0x4) || !( ((x << 28) >> 28) ^ 0x5) || !( ((x << 28) >> 28) ^ 0x6) || !( ((x << 28) >> 28) ^ 0x7) || !( ((x << 28) >> 28) ^ 0x8) || !( ((x << 28) >> 28) ^ 0x9));
  return first_digit_check & second_digit_check;

/* Alternative solution 
  int lowerBound = 0x30;
  int upperBound = 0x3a;
  
  //Dissection by part

  printf("%d\n", ~lowerBound + 1); //First negate it + 1 to get back into the actual negate(lowerbound)
  printf("%d\n", !((x + (~lowerBound + 1)) >> 31)); //If it is smaller than lower bound, x + (~lowerBound + 1) 
                                                      will be a negative number meaning the MSB will be 1 => !1 = 0
  printf("%d\n", (x + (~upperBound + 1)) >> 31 );   //Similarly, if it is greater than the upper bound, x + (~upperBound + 1) 
                                                      will be a positive number meaning the MSB will be 0
  
  return !((x + (~lowerBound + 1)) >> 31) & (x + (~upperBound + 1)) >> 31; 
*/
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

  int a = !!x;    //Confirm whether x is 0 (false) or any other number (true)
  int b = ~a + 1; //Set or clear bits 
                  /*If we started with 0, then flipping the bits gives all ones. 
                  When we add one, all those turn back to zeros (and the carry gets set, but we ignore it).
                  If we started with 1, flipping the bits gives 111...10. Adding 1 turns that last 0 to a 1, so all the bits are now 1's */
  return (b & y) | (~b & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  return (((x + (~y + 1)) >> 31) || !(x^y));
  
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  x = (x | (~x + 1)) >> 31; // (~x + 1): similar to negate; (x | (~x + 1)) set all bits to 1 (unless it is orginally 0); In C, right shift is arithmetic
  printf("%X\n",x);
  return ~x & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */

//Need more attention: DID NOT FIGURE THIS OUT ON MY OWN
int howManyBits(int x) {
  int n = 0;
    printf("%X\n", x);
    printf("(x >> 31): %X\n", (x >> 31));
    x = x ^ (x >> 31);
    printf("x ^ (x >> 31): %X\n", x);
    printf("x >> (n + 16): %X\n", x >> (n + 16));
    printf("(!!(x >> (n + 16))): %X\n", (!!(x >> (n + 16))));
    printf("((!!(x >> (n + 16))) << 4): %X\n", ((!!(x >> (n + 16))) << 4));
    
    n = n + ((!!(x >> (n + 16))) << 4);
    
    printf("x >> (n + 8): %X\n", x >> (n + 8));
    printf("((!!(x >> (n + 8))) << 3): %X\n", ((!!(x >> (n + 8))) << 3));
    n = n + ((!!(x >> (n + 8))) << 3);
   
    printf("x >> (n + 4): %X\n", x >> (n + 4));
    printf("((!!(x >> (n + 4))) << 2): %X\n", ((!!(x >> (n + 4))) << 2));
    n = n + ((!!(x >> (n + 4))) << 2);
    
    printf("x >> (n + 2): %X\n", x >> (n + 2));
    printf("((!!(x >> (n + 2))) << 1): %X\n", ((!!(x >> (n + 2))) << 1));
    n = n + ((!!(x >> (n + 2))) << 1);
    
    printf("x >> (n + 1): %X\n", x >> (n + 1));
    printf("((!!(x >> (n + 1)))): %X\n", ((!!(x >> (n + 1)))));
    n = n + ((!!(x >> (n + 1))));
    
    printf("n + (x >> n): %X\n", n + (x >> n));
    n = n + (x >> n);
    return n + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
//Need more attention: DID NOT FIGURE THIS OUT ON MY OWN
unsigned floatScale2(unsigned uf) {

  //These are specific numbers chosen to extract the '1's in the sign / exp / frac fields
  unsigned sign = uf & 0x80000000;
  unsigned exp = uf & 0x07f80000;
  unsigned frac = uf & 0x007FFFFF;

  //zero or denorm (small fraction)
  if (exp == 0){
    return sign | uf << 1;
  }

  //special case: infinity / NaN
  if (exp == 0x07f80000){  //exp field is all '1's => special case
    return uf;
  }

  //norm
  exp += 0x00800000; //align the '1' bit with the last bit of the exp field to add 1 (like left shift 1, which is multiply by 2)
   // large number becomes inf
  if (exp == 0x07f80000){
    frac = 0;
  }

  return sign | exp | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
//TBD
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = uf & 0x07f80000;
  unsigned frac = uf & 0x007FFFFF;

  if(exp == 0){
    return sign | frac;
  }

  //infinity ; 2147483648 => if it is changed to sign, it overflows
  if ((exp == 0x07f80000)|| ((exp == 0x4F000000) && (frac == 0x00000000))){
    return 0x80000000u;
  }

  return sign | exp | frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  unsigned sign = 0x00000000;
  unsigned exp = 0x3F800000;
  unsigned frac = 0x00000000;
  
  //infinity
  if ( x > 128){
    return 0x7F800000;
  }

  //zero
  if (x < -149){
    return 0;
  }

  //denorm
  if (x < -126)
  {
    exp = 0x00000000;
    frac = 0x007FFFFF;
    x = -x - 127;
    printf("%d\n",x);
    frac = frac >> x;
    printf("%X\n",frac);

  } else {
    exp = (((exp >> 23) + x) << 23);
  }

  return sign | exp | frac;

}
