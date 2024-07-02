/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int hash[1001] = {0};
        int n = nums1.size();
        for (int i = 0; i < n; i++)
            ++hash[nums1[i]];

        vector<int> ans;
        n = nums2.size();
        for (int i = 0; i < n; i++)
        {
            if (hash[nums2[i]]-- > 0)
                ans.push_back(nums2[i]);
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table