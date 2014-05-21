void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;

    // Could really be set to any value, choosing middle value to reduce execution if already sorted
    int pivot = arr[(left + right) / 2];

    /* Partition - group all ints greater than pivot and all less than pivot into seperate partitions */
    while (i <= j)
    {
        // Find first int from left which is LESS than pivot value
        while (arr[i] < pivot)
              i++;

        // Find first int from right which is GREATER than pivot value
        while (arr[j] > pivot)
              j--;

        // Swap ints if the index from the left is lte than the index from the right
        if (i <= j)
        {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
    };

    /* Recursion - perform quicksort on created partitions */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
