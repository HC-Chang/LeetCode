/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */

// @lc code=start
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int far[3] = {0};
        int counts[3] = {0};
        int len;
        for (int i = 0; i < garbage.size(); i++)
        {
            len = garbage[i].size();
            for (int j = 0; j < len; j++)
            {
                switch (garbage[i][j])
                {
                case 'M':
                    far[0] = i;
                    ++counts[0];
                    break;
                case 'G':
                    far[1] = i;
                    ++counts[1];
                    break;
                case 'P':
                    far[2] = i;
                    ++counts[2];
                    break;
                }
            }
        }

        int time = 0;
        for (int i = 0; i < 3; i++)
        {
            if (counts[i] > 0)
            {
                time += counts[i];
                if (far[i] > 0)
                {
                    for (int j = far[i] - 1; j >= 0; j--)
                        time += travel[j];
                }
            }
        }
        return time;
    }
};
// @lc code=end
