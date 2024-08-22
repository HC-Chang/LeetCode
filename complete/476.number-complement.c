/*
 * @lc app=leetcode id=476 lang=c
 *
 * [476] Number Complement
 */

// @lc code=start
int findComplement(int num)
{
    char arr[32] = {0};
    int idx = 0;
    while (num)
    {
        arr[idx++] = !(num & 1);
        num >>= 1;
    }

    unsigned int ans = 0;
    long long offset = 1;
    for (int i = 0; i < idx; i++)
    {
        ans += arr[i] * offset;
        offset *= 2;
    }
    return ans;
}

// @lc code=end

// Note: bit manipulation