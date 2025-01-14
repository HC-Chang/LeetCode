/*
 * @lc app=leetcode id=2657 lang=cpp
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> ans(n);
        vector<int> arr(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (++arr[A[i]] == 2)
                cnt++;
            if (++arr[B[i]] == 2)
                cnt++;
            ans[i] = cnt;
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table