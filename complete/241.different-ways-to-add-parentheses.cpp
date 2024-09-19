/*
 * @lc app=leetcode id=241 lang=c
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string input)
    {
        if (memo.count(input))
            return memo[input];
        vector<int> ans;
        for (int i = 0; i < input.size(); ++i)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j)
                {
                    for (int k = 0; k < right.size(); ++k)
                    {
                        if (input[i] == '+')
                            ans.push_back(left[j] + right[k]);
                        else if (input[i] == '-')
                            ans.push_back(left[j] - right[k]);
                        else
                            ans.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(input));
        memo[input] = ans;
        return ans;
    }
};
// @lc code=end

// Note: recursion + memorize