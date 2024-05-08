int SortInt(int *intArray, int len) {
    int temp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len -1; j++) {
            if (intArray[i] > intArray[j]) {
                temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
}