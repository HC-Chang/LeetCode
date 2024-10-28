/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = (int)sqrt(nums[n - 1]);

        int cnt = 0;
        int tmp = 0;
        unordered_map<int, int> hash;
        for (auto nn : nums)
            hash[nn] = 1;
        long long val;
        for (int i = 0; i < n; i++)
        {
            tmp = 0;
            val = (long long)nums[i] * (long long)nums[i];
            while (val <= nums[n - 1])
            {
                if (hash.find(val) != hash.end())
                {
                    if (tmp == 0)
                        tmp = 2;
                    else
                        tmp++;
                    hash.erase(val);
                }
                else
                    break;
                val *= val;
            }
            if (tmp > cnt)
                cnt = tmp;
        }
        return cnt == 0 ? -1 : cnt;
    }
};
// @lc code=end

// Note: hash table + sorting + DP