/*
 * @lc app=leetcode id=2601 lang=c
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start
bool primeSubOperation(int *nums, int numsSize)
{
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max_val)
            max_val = nums[i];
    }

    int sieve[max_val + 1];
    sieve[1] = 0;
    for (int i = 2; i < max_val + 1; i++)
        sieve[i] = 1;

    for (int i = 2; i <= sqrt(max_val + 1); i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j <= max_val; j += i)
                sieve[j] = 0;
        }
    }

    int currValue = 1;
    int i = 0;
    int difference;
    while (i < numsSize)
    {
        difference = nums[i] - currValue;
        if (difference < 0)
            return false;

        if (sieve[difference] == 1 || difference == 0)
            i++;
        currValue++;
    }
    return true;
}
// @lc code=end

// Note: binary search + greedy

// Official Solution