/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start

class Solution
{
public:
    const long long int mod = 1e9 + 7;
    int ways(vector<string> &pizza, int k)
    {
        int row = pizza.size(), col = pizza[0].length();

        vector<vector<int>> num(row, vector<int>(col, 0));
        if (pizza[0][0] == 'A')
            num[0][0] = 1;
        for (int i = 1; i < row; i++)
            num[i][0] = num[i - 1][0] + (pizza[i][0] == 'A');
        for (int i = 1; i < col; i++)
            num[0][i] = num[0][i - 1] + (pizza[0][i] == 'A');
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1] + (pizza[i][j] == 'A');

        vector<vector<vector<long long int>>> dp(row, vector<vector<long long int>>(col, vector<long long int>(k + 1, 0)));
        dp[0][0][1] = 1;

        for (int x = 2; x <= k; x++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (dp[i][j][x - 1] == 0)
                        continue;
                    for (int z = i + 1; z < row; z++)
                    {
                        if (hasA(num, i, j, z - 1, col - 1) && hasA(num, z, j, row - 1, col - 1))
                        {
                            dp[z][j][x] += dp[i][j][x - 1];
                            dp[z][j][x] %= mod;
                        }
                    }
                    for (int z = j + 1; z < col; z++)
                    {
                        if (hasA(num, i, j, row - 1, z - 1) && hasA(num, i, z, row - 1, col - 1))
                        {
                            dp[i][z][x] += dp[i][j][x - 1];
                            dp[i][z][x] %= mod;
                        }
                    }
                }
            }
        }

        long long int ans = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans += dp[i][j][k];
            }
            ans %= mod;
        }
        return ans;
    }

    bool hasA(vector<vector<int>> &num, int sr, int sc, int er, int ec)
    {
        int num1 = 0, num2 = 0, num3 = 0, res;
        if (sr != 0 && sc != 0)
            num1 = num[sr - 1][sc - 1];
        if (sr != 0)
            num2 = num[sr - 1][ec];
        if (sc != 0)
            num3 = num[er][sc - 1];
        return num[er][ec] - num2 - num3 + num1 > 0;
    }
};

// @lc code=end
