/*
 * @lc app=leetcode id=2014 lang=cpp
 *
 * [2014] Longest Subsequence Repeated k Times
 */

// @lc code=start
class Solution
{
public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        string possible_chars = "";
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 25; i >= 0; --i)
        {
            if (freq[i] >= k)
                possible_chars += (char)('a' + i);
        }

        string result = "";
        queue<string> q;
        q.push("");

        while (!q.empty())
        {
            string current = q.front();
            q.pop();

            for (char c : possible_chars)
            {
                string next = current + c;
                if (isSubsequence(s, next, k))
                {
                    if (next.length() > result.length() || (next.length() == result.length() && next > result))
                        result = next;

                    q.push(next);
                }
            }
        }
        return result;
    }

private:
    bool isSubsequence(const string &s, const string &sub, int k)
    {
        int j = 0;
        int repetitions = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == sub[j])
            {
                j++;
                if (j == sub.length())
                {
                    repetitions++;
                    if (repetitions == k)
                        return true;
                    j = 0;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// Gemini Solution