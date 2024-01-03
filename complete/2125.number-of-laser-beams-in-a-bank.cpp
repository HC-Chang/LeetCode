/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        vector<int> size(n);
        for (int i = 0; i < n; i++)
        {
            for (auto c : bank[i])
            {
                if (c == '1')
                    size[i]++;
            }
        }
        int cnt = 0;
        int j;
        for (int i = 0; i < n; i++)
        {
            while (i < n - 1 && size[i] == 0)
                i++;
            j = i + 1;
            while (j < n - 1 && size[j] == 0)
                j++;
            if (i >= n || j >= n)
                break;
            cnt += size[i] * size[j];
            i = j - 1;
        }

        return cnt;
    }
};
// @lc code=end
