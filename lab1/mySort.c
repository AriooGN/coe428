void mySort(int d[], unsigned int n) {
    int tempStorage, j;

    for (int i = 1; i < n; i++) {
        tempStorage = d[i];
        j = i - 1;

        while (j >= 0 && d[j] > tempStorage) {
            d[j + 1] = d[j];
            j = j - 1;
        }

        d[j + 1] = tempStorage;
    }

}
