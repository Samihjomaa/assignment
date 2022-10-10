#include <stdio.h>
#include <math.h>


//Requires: Positive non-zero integer
//
//Effects: Returns the position of the most significant bit that is set to 1 of integer a
//
//@params: an integer
//@returns: unsigned integer
//
//Testing Strategy
//
//Testing Partitions:
//
//*(0) to cover (0)
//*(1) to cover (1)
//*(8392) to cover (small positive integer)
//*(-7) to cover (small negative integer)
//*One large negative integer(-13855533)
//*One Large positive integers (23333424)
//

unsigned int msb(int a){
    return (log2(a));
}


//Requires: Positive non-zero integer
//
//Effects: Returns the position of the Least significant bit that is set to 1 of integer n
//
//@params: an integer
//@returns: unsigned integer
//
//Testing Strategy
//
//Testing Partitions:
//
//*(0) to cover (0)
//*(1) to cover (1)
//*(8392) to cover (small positive integer)
//*(-7) to cover (small negative integer)
//*One large negative integer(-13855533)
//*One Large positive integers (23333424)
//
unsigned int lsb(int n){
    return log2(n & -n);
}




int main() {

    int inp;

     int result;

     do {
         printf("Enter a number:\n");
         scanf("%d", &inp);
     }while(inp > 0);

    result = msb(inp) - lsb(inp);

    printf("%u\n", result);

    return 0;
}