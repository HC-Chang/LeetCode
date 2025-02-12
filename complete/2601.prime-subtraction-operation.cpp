/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start
class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++)
        {
            if (sieve[i] == 1)
            {
                for (int j = i * i; j <= maxElement; j += i)
                    sieve[j] = 0;
            }
        }

        int currValue = 1;
        int i = 0;
        while (i < nums.size())
        {
            int difference = nums[i] - currValue;
            if (difference < 0)
                return false;

            if (sieve[difference] == 1 or difference == 0)
                i++;
            currValue++;
        }
        return true;
    }
};
// @lc code=end

// Note: binary search + greedy

// Official Solution