/*
 * @lc app=leetcode id=373 lang=c
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes)
{
    if (nums1Size == 0 || nums2Size == 0 || k <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int left = nums1[0] + nums2[0];
    int right = nums1[nums1Size - 1] + nums2[nums2Size - 1];
    int pairSum = right;
    int mid;
    long long cnt;
    int start;
    int end;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        cnt = 0;
        start = 0;
        end = nums2Size - 1;
        while (start < nums1Size && end >= 0)
        {
            if (nums1[start] + nums2[end] > mid)
                end--;
            else
            {
                cnt += end + 1;
                start++;
            }
        }
        if (cnt < k)
            left = mid + 1;
        else
        {
            pairSum = mid;
            right = mid - 1;
        }
    }

    int **ans = (int **)malloc(sizeof(int *) * k);
    *returnColumnSizes = (int *)malloc(sizeof(int) * k);
    int currSize = 0;
    int pos = nums2Size - 1;
    for (int i = 0; i < nums1Size; i++)
    {
        while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum)
            pos--;

        for (int j = 0; j <= pos && k > 0; j++, k--)
        {
            ans[currSize] = (int *)malloc(sizeof(int) * 2);
            ans[currSize][0] = nums1[i];
            ans[currSize][1] = nums2[j];
            (*returnColumnSizes)[currSize] = 2;
            currSize++;
        }
    }

    pos = nums2Size - 1;
    int start1, start2;
    int count;
    for (int i = 0; i < nums1Size && k > 0; i++)
    {
        start1 = i;
        while (i < nums1Size - 1 && nums1[i] == nums1[i + 1])
            i++;

        while (pos >= 0 && nums1[i] + nums2[pos] > pairSum)
            pos--;

        start2 = pos;
        while (pos > 0 && nums2[pos] == nums2[pos - 1])
            pos--;

        if (nums1[i] + nums2[pos] != pairSum)
            continue;

        count = (int)fmin(k, (long)(i - start1 + 1) * (start2 - pos + 1));
        for (int j = 0; j < count && k > 0; j++, k--)
        {
            ans[currSize] = (int *)malloc(sizeof(int) * 2);
            ans[currSize][0] = nums1[i];
            ans[currSize][1] = nums2[pos];
            (*returnColumnSizes)[currSize] = 2;
            currSize++;
        }
    }
    *returnSize = currSize;
    return ans;
}
// @lc code=end

// Official Solution
