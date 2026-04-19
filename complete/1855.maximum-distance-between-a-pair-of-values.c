/*
 * @lc app=leetcode id=1855 lang=c
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
int maxDistance(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1[nums1Size - 1] > nums2[0])
        return 0;

    int dis = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = i + dis + 1; j < nums2Size; j++)
        {
            if (nums2[j] - nums1[i] >= 0)
                dis = j - i;
            else
                break;
        }
    }
    return dis;
}
// @lc code=end

// Note: two pointers, binary search