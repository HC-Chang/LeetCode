/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Solution 2: merge sort

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

void merge_sort(int *dst, int *src, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    merge_sort(dst, src, left, middle);
    merge_sort(dst, src, middle + 1, right);
    merge(dst, src, left, middle, middle + 1, right);
}

int *sortArray(int *nums, int numsSize, int *returnSize)
{
    int *r = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    memcpy(r, nums, sizeof(int) * numsSize);
    merge_sort(r, nums, 0, numsSize - 1);

    return r;
}
// @lc code=end

// Note: merge sort

// Solution 1: qsort

// int sort(const void *a, const void *b){return *(int *)a - *(int*)b;}
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     *returnSize = numsSize;
//     if(numsSize == 1)
//         return nums;
//     qsort(nums, numsSize, sizeof(int), sort);
//     return nums;
// }
