/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        string num_str = to_string(num);
        int n = num_str.size();
        int max_idx = -1, swap_idx1 = -1, swap_idx2 = -1;

        for (int i = n - 1; i >= 0; --i)
        {
            if (max_idx == -1 || num_str[i] > num_str[max_idx])
                max_idx = i;
            else if (num_str[i] < num_str[max_idx])
            {
                swap_idx1 = i;
                swap_idx2 = max_idx;
            }
        }

        if (swap_idx1 != -1 && swap_idx2 != -1)
            swap(num_str[swap_idx1], num_str[swap_idx2]);

        return stoi(num_str);
    }
};
// @lc code=end

// Note: math + greedy

// Official Solution