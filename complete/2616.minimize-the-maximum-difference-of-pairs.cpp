/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution
{
public:
    int countValidPairs(vector<int> &nums, int n, int threshold)
    {
        int index = 0, count = 0;
        while (index < n - 1)
        {
            if (nums[index + 1] - nums[index] <= threshold)
            {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (countValidPairs(nums, n, mid) >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end