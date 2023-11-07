/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<double> time(n);

        for (int i = 0; i < n; i++)
            time[i] = (double)dist[i] / speed[i];

        sort(std::begin(time), std::end(time));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if ((double)i < time[i])
                count++;
            else
                break;
        }
        return count == n ? n : count;
    }
};
// @lc code=end
