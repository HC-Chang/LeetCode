/*
 * @lc app=leetcode id=3304 lang=c
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
// Gemini Solution
char kthCharacter(int k)
{
    // The number of transformations applied to the base character 'a' is
    // equal to the number of set bits (1s) in the binary representation
    // of (k - 1). This is because each '1' in the binary representation of
    // the 0-based index (k-1) corresponds to a step where the character
    // falls into the transformed half of the string.
    //
    // For example, k=13 -> k-1=12. Binary of 12 is 1100. It has two set bits.
    // The result is 'a' + 2 = 'c'.
    return 'a' + __builtin_popcount(k - 1);
}
// @lc code=end

// Note: bit manipulation + simulation + recursion

// Official Solution

char kthCharacter(int k)
{
    int ans = 0;
    int t;
    while (k != 1)
    {
        t = 31 - __builtin_clz(k);
        if ((1 << t) == k)
        {
            t--;
        }
        k = k - (1 << t);
        ans++;
    }
    return 'a' + ans;
}