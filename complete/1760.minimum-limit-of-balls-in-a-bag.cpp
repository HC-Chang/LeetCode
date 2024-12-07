/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution
{
public:
    bool is_pass(int maxBallsInBag, vector<int> &nums, int maxOperations)
    {
        int sum_op = 0;

        for (int num : nums)
        {
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            sum_op += operations;

            if (sum_op > maxOperations)
                return false;
        }
        return true;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1;
        int right = 0;

        for (auto num : nums)
            right = max(right, num);

        while (left < right)
        {
            int middle = (left + right) / 2;

            if (is_pass(middle, nums, maxOperations))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};
// @lc code=end

// Note: binary search