/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> f_arr(n);

        int force = 0;
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else
                force = max(force - 1, 0);
            f_arr[i] += force;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else
                force = max(force - 1, 0);
            f_arr[i] -= force;
        }
        for (int i = 0; i < n; i++)
        {
            if (f_arr[i] > 0)
                dominoes[i] = 'R';
            else if (f_arr[i] < 0)
                dominoes[i] = 'L';
            else
                dominoes[i] = '.';
        }

        return dominoes;
    }
};
// @lc code=end

// Note: DP