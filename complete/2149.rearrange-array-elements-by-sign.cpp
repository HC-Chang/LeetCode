/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int p_idx = 0;
        int n_idx = 1;
        int *idx;
        int n = nums.size();

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                idx = &p_idx;
            else
                idx = &n_idx;

            ans[*idx] = nums[i];
            *idx += 2;
        }

        return ans;
    }
};
// @lc code=end

// Note: two pointer

// Solution 1: queue
// class Solution
// {
// public:
//     vector<int> rearrangeArray(vector<int> &nums)
//     {
//         queue<int> p;
//         queue<int> n;
//         for (auto i : nums)
//         {
//             if (i > 0)
//                 p.push(i);
//             else
//                 n.push(i);
//         }
//         int cnt = p.size();
//         for (int i = 0; i < cnt; i++)
//         {
//             nums[i * 2] = p.front();
//             nums[i * 2 + 1] = n.front();
//             p.pop();
//             n.pop();
//         }
//         return nums;
//     }
// };