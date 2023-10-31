/*
 * @lc app=leetcode id=2433 lang=c
 *
 * [2433] Find The Original Array of Prefix Xor
 */
// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findArray(int *pref, int prefSize, int *returnSize)
{
    *returnSize = prefSize;
    int *r = malloc(prefSize * sizeof(int));
    r[0] = pref[0];
    for (int i = 1; i < prefSize; i++)
        r[i] = pref[i - 1] ^ pref[i];
    return r;
}
// @lc code=end

// Note: bit manipulation