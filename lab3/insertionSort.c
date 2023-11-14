#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
    int key, j;
    for (int i = first; i < last + 1; i++) {
        
        myCopy(&array[i], &key);
        key = array[i];
        j = i - 1;
        
        while (j >= 0 &&  myCompare(array[j], key) >= 0) {
            mySwap(&array[j], &array[j + 1]);//array[j + 1] = array[j];
            j = j - 1;
        }
        
    }
}
