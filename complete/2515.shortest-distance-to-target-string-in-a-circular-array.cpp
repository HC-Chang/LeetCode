/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        if (words[startIndex] == target)
            return 0;
        int n = words.size();
        int dis = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                int diff = abs(startIndex - i);
                dis = min(dis, min(diff, n - diff));
            }
        }

        if (dis == INT_MAX)
            return -1;
        return dis;
    }
};
// @lc code=end
