/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        int cnt;
        int sum;
        int ii;
        int jj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cnt = 0;
                sum = 0;
                ii = i - 1;
                jj = j - 1;
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (ii + x >= 0 && jj + y >= 0 && ii + x < m && jj + y < n)
                        {
                            sum += img[ii + x][jj + y];
                            cnt++;
                        }
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};
// @lc code=end
