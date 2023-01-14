/*
 * @lc app=leetcode id=496 lang=c
 *
 * [496] Next Greater Element I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    *returnSize = nums1Size;
    int map[10000] = {0};
    int *monotonic_stack = malloc(nums2Size * sizeof(int));
    int index_monotonic_stack = 0;

    for (int i = nums2Size - 1; i >= 0; i--)
    {
        while (index_monotonic_stack != 0 && monotonic_stack[index_monotonic_stack - 1] <= nums2[i])
            index_monotonic_stack--;
        
        map[nums2[i]] = index_monotonic_stack == 0 ? -1 : monotonic_stack[index_monotonic_stack - 1];
        monotonic_stack[index_monotonic_stack++] = nums2[i];
    }

    free(monotonic_stack);
    for (int i = 0; i < nums1Size; i++)
    {
        nums1[i] = map[nums1[i]];
    }

    return nums1;
}
// @lc code=end

// 單調堆疊 + Hash Table