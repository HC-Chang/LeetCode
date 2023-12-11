/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int cnt = 1;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                cnt++;
                if (cnt > n / 4)
                    return arr[i];
            }
            else
                cnt = 1;
        }
        return arr[n - 1];
    }
};
// @lc code=end
