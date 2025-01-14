/*
 * @lc app=leetcode id=2657 lang=c
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findThePrefixCommonArray(int *A, int ASize, int *B, int BSize, int *returnSize)
{
    *returnSize = ASize;
    int *ans = malloc(ASize * sizeof(int));
    int arr[ASize + 1];
    memset(arr, 0, sizeof(arr));
    int cnt = 0;
    for (int i = 0; i < ASize; i++)
    {
        if (++arr[A[i]] == 2)
            cnt++;
        if (++arr[B[i]] == 2)
            cnt++;
        ans[i] = cnt;
    }
    return ans;
}
// @lc code=end

// Note: hash table