/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string a, const string b)
             { return a.size() < b.size(); });
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// Note: KMP