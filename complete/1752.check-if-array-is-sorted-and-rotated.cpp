/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start

// Solution 2: O(n) time, O(1) space

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        bool flag = false;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (flag || (i + 1 < n && nums[i - 1] < nums[i + 1]))
                    return false;
                else if (nums[0] < nums[n - 1])
                    return false;
                else
                    flag = true;
            }
        }

        return true;
    }
};
// @lc code=end

// Solution 1: O(nlogn) time, O(n) space

// class Solution
// {
// public:
//     bool check(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<pair<int, int>> p;
//         for (int i = 0; i < n; i++)
//             p.push_back({nums[i], i});
//         sort(p.begin(), p.end());

//         int start = p[0].second;
//         while (n > 0 && nums[(start - 1 + n) % n] == nums[(start) % n])
//         {
//             start = (start - 1 + n) % n;
//             n--;
//         }

//         for (int i = 0; i < n - 1; i++)
//         {
//             if (nums[(start + 1 + i) % n] - nums[(start + i) % n] < 0)
//                 return false;
//         }

//         return true;
//     }
// };
