/*
 * @lc app=leetcode id=2683 lang=c
 *
 * [2683] Neighboring Bitwise XOR
 */

// @lc code=start
bool doesValidArrayExist(int *derived, int derivedSize)
{
    int ans = 0;
    for (int i = 0; i < derivedSize; i++)
        ans ^= derived[i];

    return ans % 2 == 0;
}
// @lc code=end

// Note: bit manipulation