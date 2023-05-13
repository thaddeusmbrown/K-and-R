#include <stdio.h>

/* better_bitcount:  count 1 bits in x
    this version takes advantage of the fact that x &= (x-1) deletes the rightmost 1-bit in x.
    
    This is true because, for example:
        x = 216 is 11011000
    x - 1 = 215 is 11010100
    
    x &= (x - 1) means x = x & (x - 1) 
    
    This results in 11010000 = 208 
    
    We can take advantage of this by using a while loop that iteratively removes 1-bits until x = 0 */
int better_bitcount(unsigned x);

int main(int argc, char *argv[]) {
  int x = 216;
  
  printf("For input of %u, output is %u\n", x, better_bitcount(x));
}

int better_bitcount(unsigned x) {
  int count = 0;

  while (x) {
    x &= x - 1;
    ++count;
  }
  return count;
}
