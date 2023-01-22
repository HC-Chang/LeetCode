/*
 * @lc app=leetcode id=2540 lang=c
 *
 * [2540] Minimum Common Value
 */

// Difficulty:Easy

// @lc code=start

int sort(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    qsort(nums1, nums1Size, sizeof(int), sort);
    qsort(nums2, nums2Size, sizeof(int), sort);
    if (nums1[nums1Size - 1] < nums2[0])
        return -1;

    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] < nums2[j])
            {
                if (i + 1 < nums1Size)
                {
                    i++;
                    j = -1;
                }
            }
        }
    }

    return -1;
}
// @lc code=end