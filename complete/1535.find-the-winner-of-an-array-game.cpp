/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n =arr.size();
        if (n == 1)
            return arr[0];
        if (k == 1)
            return max(arr[0], arr[1]);

        int win_count = 0;
        int index = 1;
        for (int i = 1; i < n && win_count < k; ++i)
        {
            if (arr[i] > arr[0])
            {
                arr[0] = arr[i];
                win_count = 1;
            }
            else
                ++win_count;
        }

        return arr[0];
    }
};
// @lc code=end
