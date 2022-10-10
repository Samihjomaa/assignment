#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Requires: Array of Strings
//
//Effects: prints string values on new lines
//
//@params: an array of integers
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of strings of different sizes
//

void printoutarray(char **pointertoarray, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s \n", pointertoarray[i]);
    }
}

//Requires: Array of Strings
//
//Effects: Sorts the array of strings alpha-numerically
//
//@params: an array of strings
//@returns: void
//
//Testing Strategy
//
//Testing Partitions:
//*array of strings of different sizes
//

void bubbleSort(char *array[], int size_of_array){
    char temp[30];

    for(int i=0; i<size_of_array; i++){
        for(int j=0; j<size_of_array-1-i; j++){
            if(strcmp(array[j], array[j+1]) > 0){
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
}


//Requires: 2 Arrays of alpha-numerically sorted Strings
//
//Effects: Concatenates the two arrays
//
//@params: 2 string arrays and their sizes
//@returns: pointer to the new string array
//
//Testing Strategy
//
//Testing Partitions:
//*array of strings of different sizes
//

char** concatenateArr(char *arr1[], int size1, char *arr2[], int size2){

    char ** strArray = malloc((size1+size2) * sizeof(char*));

    for (int i =0 ; i < (size1+size2); ++i)
        strArray[i] = malloc(30 * sizeof(char));

    for(int i = 0; i < size1; i++){
        strcpy( strArray[i], arr1[i]);
    }

    for(int i = size1; i < (size1 + size2); i++){
        strcpy( strArray[i], arr2[i-size1]);
    }

    return strArray;
}


int main() {

    char *str[2] = {"ab", "ac"};

    char *str2[3] = {"za", "zb", "zzzc"};

    bubbleSort(str, 2);
    bubbleSort(str2, 3);

    char** arrayy = concatenateArr(str, 2, str2, 3);

    printoutarray(arrayy, 5);

    return 0;
}


















