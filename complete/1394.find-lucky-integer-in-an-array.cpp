/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int n = arr.size();
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == arr[i])
                cnt++;
            else
            {
                if (arr[i - 1] == cnt)
                    return cnt;
                cnt = 1;
            }
        }
        if (arr[n - 1] == cnt)
            return cnt;
        return -1;
    }
};
// @lc code=end

// Note: hash table + counting
