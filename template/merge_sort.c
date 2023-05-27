// Merge Sort
// Similar Questions: 912

void merge(int *arr1, int *arr2, int start1, int end1, int start2, int end2)
{
    int index = start1;
    int i = start1;
    int j = start2;
    while (i <= end1 && j <= end2)
    {
        if (arr2[i] < arr2[j])
            arr1[index++] = arr2[i++];

        else if (arr2[i] > arr2[j])
            arr1[index++] = arr2[j++];
        else
        {
            arr1[index] = arr2[i++];
            arr1[index + 1] = arr2[j++];
            index += 2;
        }
    }

    while (i <= end1)
        arr1[index++] = arr2[i++];

    while (j <= end2)
        arr1[index++] = arr2[j++];

    memcpy(&(arr2[start1]), &(arr1[start1]), sizeof(int) * (end2 - start1 + 1));
}

void merge_sort(int *arr1, int *arr2, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    merge_sort(arr1, arr2, left, middle);
    merge_sort(arr1, arr2, middle + 1, right);
    merge(arr1, arr2, left, middle, middle + 1, right);
}