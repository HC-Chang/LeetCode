/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

int max(int a, int b) { return a > b ? a : b; };
int min(int a, int b) { return a < b ? a : b; };

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int k = (nums1Size + nums2Size + 1) / 2;

    int left = 0;
    int right = nums1Size;
    int m1;
    int m2;
    
    while (left < right)
    {
        m1 = left + (right - left) / 2;
        m2 = k - m1;
        if (nums1[m1] < nums2[m2 - 1])
            left = m1 + 1;
        else
            right = m1;
    }

    m1 = left;
    m2 = k - left;

    int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                 m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((nums1Size + nums2Size) % 2 == 1)
        return c1;

    int c2 = min(m1 >= nums1Size ? INT_MAX : nums1[m1],
                 m2 >= nums2Size ? INT_MAX : nums2[m2]);

    return (c1 + c2) * 0.5;
}
// @lc code=end

// Binary Search

// 維持 n1 <= n2
// k 為兩陣列中的中位數的 index
// m1 + m2 找出前 k 個元素
// c 中位數
// A[m1-1], A[m1], B[m2-1], B[m2] 找出中位數 c
// c1: k-1
// c2: k
// return:
//      奇數: c1
//      偶數: (c1+c2) / 2