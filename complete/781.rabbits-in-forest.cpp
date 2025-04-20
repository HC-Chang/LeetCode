/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int n = answers.size();
        if (n == 0)
            return 0;

        int ans = 0;
        int max = 0;
        int j;
        int start;
        sort(answers.begin(), answers.end());
        for (int i = 0; i < n; i++)
        {
            ans += answers[i] + 1;
            max = answers[i] + 1;
            j = answers[i];
            start = i;
            while (i < n && j == answers[i] && i - start < max)
                i++;
            i--;
        }
        return ans;
    }
};
// @lc code=end

// Note: greedy