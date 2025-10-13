/*
 * @lc app=leetcode id=2273 lang=cpp
 *
 * [2273] Find Resultant Array After Removing Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        int n = words.size();
        string last;
        string tmp;

        for (int i = 0; i < n; i++)
        {
            tmp = words[i];
            sort(tmp.begin(), tmp.end());
            if (last == tmp)
            {
                words.erase(words.begin() + i);
                i--;
                n--;
            }
            last = tmp;
        }

        return words;
    }
};
// @lc code=end

// Note: hash table + sorting