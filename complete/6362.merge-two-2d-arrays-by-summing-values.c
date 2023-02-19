/*
 * @lc app=leetcode id=6362 lang=c
 *
 * [6362] Merge Two 2D Arrays by Summing Values
 */

// Difficulty:Easy

// You are given two 2D integer arrays nums1 and nums2.

// nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// Each array contains unique ids and is sorted in ascending order by id.

// Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

// Only ids that appear in at least one of the two arrays should be included in the resulting array.
// Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays then its value in that array is considered to be 0.
// Return the resulting array. The returned array must be sorted in ascending order by id.

// Constraints:
// 1 <= nums1.length, nums2.length <= 200
// nums1[i].length == nums2[j].length == 2
// 1 <= idi, vali <= 1000
// Both arrays contain unique ids.
// Both arrays are in strictly ascending order by id.

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void push_arr(int *num, int *arr, int *arr_index)
{
    if (arr[num[0]] == 0)
        ++*arr_index;
    arr[num[0]] += num[1];
}

int **mergeArrays(int **nums1, int nums1Size, int *nums1ColSize, int **nums2, int nums2Size, int *nums2ColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int *arr = calloc(1001, sizeof(int));

    for (int i = 0; i < nums1Size; i++)
        push_arr(nums1[i], arr, returnSize);
    for (int i = 0; i < nums2Size; i++)
        push_arr(nums2[i], arr, returnSize);

    int **r = calloc(*returnSize, sizeof(int *));
    returnColumnSizes[0] = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++)
    {
        r[i] = calloc(2, sizeof(int));
        returnColumnSizes[0][i] = 2;
    }
    int index = 0;
    for (int i = 0; i < 1001 && index < *returnSize; i++)
    {
        if (arr[i] != 0)
        {
            r[index][0] = i;
            r[index++][1] = arr[i];
        }
    }

    free(arr);
    return r;
}
// @lc code=end