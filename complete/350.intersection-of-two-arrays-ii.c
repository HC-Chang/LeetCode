/*
 * @lc app=leetcode id=350 lang=c
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
// Solution 2:

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int hash[1001] = {0};
    for (int i = 0; i < nums1Size; i++)
        ++hash[nums1[i]];
    *returnSize = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        if (hash[nums2[i]]-- > 0)
            nums1[(*returnSize)++] = nums2[i];
    }
    return nums1;
}
// @lc code=end

// Note: hash table

// Solution 1:

// int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
// {
//     *returnSize = nums1Size;
//     int *arr = malloc(*returnSize * sizeof(int));
//     int index = 0;
//     int map1[1001] = {0};
//     int map2[1001] = {0};
//     for (int i = 0; i < nums1Size; i++)
//         ++map1[nums1[i]];
//     for (int i = 0; i < nums2Size; i++)
//         ++map2[nums2[i]];
//     int min;
//     for (int i = 0; i < 1001; i++)
//     {
//         if (map1[i] == 0 || map2[i] == 0)
//             continue;
//         min = map1[i] < map2[i] ? map1[i] : map2[i];
//         for(int j=0; j<min; j++)
//             arr[index++] = i;
//     }
//     *returnSize = index;
//     arr = realloc(arr, *returnSize*sizeof(int));
//     return arr;
// }