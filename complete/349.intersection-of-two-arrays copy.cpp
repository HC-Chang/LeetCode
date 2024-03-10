/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hash;
        for (auto i : nums1)
            ++hash[i];

        vector<int> ans;
        for (auto i : nums2)
        {
            if (hash.find(i) != hash.end())
            {
                ans.push_back(i);
                hash.erase(i);
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table