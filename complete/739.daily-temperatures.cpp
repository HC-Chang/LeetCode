/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            if (s.empty() || temperatures[i] <= temperatures[s.top()])
                s.push(i);

            else
            {
                int targetIdx = s.top();
                s.pop();
                ret[targetIdx] = i - targetIdx;
                i--;
            }
        }
        return ret;
    }
};
// @lc code=end

// Note: stack