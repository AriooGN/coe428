void merge(int array[], unsigned int first, unsigned int m, unsigned int last) {
    
    int i, j, k;
    int lLength = m - first + 1;
    int rLength = last - m;

    int l[lLength], r[rLength];

    for (i = 0; i < lLength; i++) {
        myCopy(&array[i + first], &l[i]);
    }
    for (j = 0; j < rLength; j++) {
        myCopy(&array[m + j + 1], &r[j]);
    }

    i = 0;
    j = 0;
    k = first;
    
    while (i < lLength && j < rLength) {
        if (myCompare(l[i], r[j]) <= 0) {
            myCopy(&l[i], &array[k]);
            i++;
        }
        else {
            myCopy(&r[j], &array[k]);
            j++;
        }
        k++;
    }

    while (i < lLength) {
        myCopy(&l[i], &array[k]);
        i++;
        k++;
    }
    while (j < rLength) {
        myCopy(&r[j], &array[k]);
        j++;
        k++;
    }
}


void mergeSort(int array[], unsigned int first, unsigned int last) {
    if (first < last) {
        int m = first + (last - first) / 2;
        mergeSort(array, first, m);
        mergeSort(array, m + 1, last);
        merge(array, first, m, last);
    }
}

void mySort(int array[], unsigned int first, unsigned int last) {
    mergeSort(array, first, last);
}

