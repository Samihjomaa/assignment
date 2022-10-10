#include <stdio.h>

//Requires: Non-negative integers x and y
//
//Effects: Returns the Hamming distance between the bit representations of x and y
//
//@params: two ints x and y
//@returns: integer
//
//Testing Strategy
//
//Testing Partitions:
//
//*(0, 0) to cover (0, 0)
//*(0, 1) to cover (0, 1)
//*(0, 8392) to cover (0, small positive integer)
//*(0, -7) to cover (0, small negative integer)
//*One small negative integer(-100)
//*One large negative integer(-13855533)
//*Two small positive integers (2, 5)
//*Two Large positive integers (13855533, 23333424)
//*One 0 and one large positive int (0, 13855533)
//*(0,-13855533) to cover (0, large negative integer)
//


int hammingDistance(int x, int y){

    int n = x ^ y;
    int bitsDiff = 0;

    while (n > 0) {
        bitsDiff += n & 1;
        n >>= 1;
    }

    return bitsDiff;
}

int main() {

    int a, b;

    do{
        printf("Enter two integers:\n");
        scanf("%d", &a);

        if(a < 0){
            break;
        }

        scanf("%d", &b);

        if(b < 0){
            break;
        }

        printf("%d\n", hammingDistance(a, b));
    } while (1);

    return 0;
}
