
/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */

// @lc code=start
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        vector<int>::iterator it = std::find(nums.begin(), nums.end(), target);
        if (it == nums.end())
            return ans;
        int idx = distance(nums.begin(), it);
        int n = nums.size();
        while (idx < n && nums[idx] == target)
            ans.push_back(idx++);

        return ans;
    }
};
// @lc code=end

// Note: sort