/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        if (k == 0)
            return vector<int>(n, 0);

        vector<int> tmp = code;
        int flag = k > 0 ? 1 : 0;
        k = abs(k);
        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                tmp[j] += code[(j + i) % n];
        }

        for (int i = 0; i < n; i++)
        {
            if (flag)
                code[i] = tmp[(i + 1) % n];
            else
                code[i] = tmp[(i - k + n) % n];
        }

        return code;
    }
};

// @lc code=end

// Note: sliding window