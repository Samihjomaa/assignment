#include <stdio.h>

#define SIZE 10


//Requires: Array of Integers
//
//Effects: Prints two columns of index and value of each index in the array
//
//@params: an array of integers
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes
//

void printArray(int arr[]){

    printf("Index  Value\n");

    for(int i=0; i<SIZE; i++){
        printf("    %d      %d\n", i, arr[i]);
    }
}




//Requires: Array of Integers
//
//Effects: Prints three columns of discrete values in the array along with their frequency and histogram of the frequency
//
//@params: an array of integers
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different frequencies of values
//

void arrayHistogram(const int arr[]){
    printf("Value  Frequency  Histogram\n");
    int count;

    for(int num = 1; num <= 3; num++) {
        count = 0;
        for (int i = 0; i < SIZE; i++) {

            if(num == arr[i])
                count++;
        }

        printf("%d      %d             ", num, count);

        for(int lol = 0; lol < count; lol++){
            printf("*");
        }
        printf("\n");

    }

}


//Requires: Array of Integers
//
//Effects: Swaps two values in the array that are of indices 
//
//@params: an array of integers
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different frequencies of values and indices
//


void swapValues(int arr[], int ind1, int ind2){
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}


//Requires: Array of Integers
//
//Effects: Sorts the array of integers
//
//@params: an array of integers
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different values
//


void bubbleSort(int arr[])
{
    int i, j;
    for (i = 0; i < SIZE - 1; i++)

        for (j = 0; j < SIZE - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapValues(arr, j, j + 1);
}


//Requires: Array of Integers
//
//Effects: Returns the median of the array 
//
//@params: an array of integers
//@returns: float of median
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different values
//

float median(int arr[]){
    bubbleSort(arr);

    return (arr[SIZE/2] + arr[SIZE/2+1])/2.0 ;
}


//Requires: Array of Integers
//
//Effects: Returns the most frequent value in the array
//
//@params: an array of integers
//@returns: int of the most frequent value in the array
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different values
//

int mode(const int arr[]){
    int maxcount = 0;
    int max_freq;
    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxcount) {
            maxcount = count;
            max_freq = arr[i];
        }
    }

    return max_freq;
}


//Requires: Array of Integers
//
//Effects: Returns whether an array is sorted (1) or not (0)
//
//@params: an array of integers
//@returns: an integer (1 or 0)
//
//Testing Strategy
//
//Testing Partitions:
//*array of integers of different sizes and different values
//

int isSorted(int arr[], int size){
    int current;
    int prev = arr[0];

    for(int i = 1; i<size; i++){
        current = arr[i];

        if(prev > current)
            return 0;

        prev = current;
    }

    return 1;
}


int main() {

    int arr[] = {1, 1, 1, 1, 1, 2, 2, 2, 3, 3};

    printArray(arr);

    arrayHistogram(arr);

    swapValues(arr, 3,8);

    printArray(arr);

    bubbleSort(arr);

    printArray(arr);

    printf("%f\n", median(arr));

    printf("%d\n", mode(arr));

    printf("1 for sorted and 0 for non-sorted: %d\n", isSorted(arr, SIZE));

    return 0;
}


















