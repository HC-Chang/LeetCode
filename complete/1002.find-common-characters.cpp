/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int arr[26] = {0};
        int n;
        n = words[0].size();
        for (int i = 0; i < n; i++)
            ++arr[words[0][i] - 'a'];

        int tmp[26];
        for (int i = 1; i < words.size(); i++)
        {
            n = words[i].size();
            memset(tmp, 0, sizeof(tmp));
            for (int j = 0; j < n; j++)
                ++tmp[words[i][j] - 'a'];
            for (int j = 0; j < 26; j++)
                arr[j] = min(arr[j], tmp[j]);
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < arr[i]; j++)
                ans.push_back(string(1, 'a' + i));
        }
        return ans;
    }
};
// @lc code=end

// Note: hash table