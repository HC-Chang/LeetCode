/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        vector<char> arr;
        int idx = 0;
        while (num)
        {
            arr.push_back(!(num & 1));
            num >>= 1;
        }

        unsigned int ans = 0;
        long long offset = 1;
        for (auto a : arr)
        {
            ans += a * offset;
            offset *= 2;
        }
        return ans;
    }
};
// @lc code=end

// Note: bit manipulation