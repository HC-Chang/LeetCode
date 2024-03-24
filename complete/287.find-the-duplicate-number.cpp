/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// Solution 2: two pointers

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

// Note: hash table / two pointers

// Solution 1: hash table

// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         int hash[nums.size()];
//         memset(hash, 0, sizeof(hash));
//         for (auto i : nums)
//         {
//             if (hash[i]++ > 0)
//                 return i;
//         }
//         return nums[0];
//     }
// };