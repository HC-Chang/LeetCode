/*
 * @lc app=leetcode id=2425 lang=cpp
 *
 * [2425] Bitwise XOR of All Pairings
 */

// @lc code=start
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> hash;
        for (auto n : nums1)
            hash[n] += n2 % 2;
        for (auto n : nums2)
            hash[n] += n1 % 2;
        int ans = 0;
        for (auto h : hash)
        {
            if (h.second % 2 == 1)
                ans ^= h.first;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash + bit manipulation