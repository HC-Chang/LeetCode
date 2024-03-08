/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> hash(101);
        for (auto i : nums)
            ++hash[i];
        sort(hash.begin(), hash.end(), greater<int>());
        int max_cnt = hash[0];
        int i = 1;
        while (hash[0] == hash[i])
            max_cnt += hash[i++];
        return max_cnt;
    }
};
// @lc code=end

// Note: hash table + counting