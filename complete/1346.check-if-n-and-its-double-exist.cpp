/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        int n = arr.size();
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

// Note: hash table + sorting / two pointers