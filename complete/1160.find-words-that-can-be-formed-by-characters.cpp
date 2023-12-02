/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int char_freq[26] = {0};
        for (int i = 0; i < chars.size(); i++)
            ++char_freq[chars[i] - 'a'];
        int count = 0;
        int tmp_freq[26];
        for (int i = 0; i < words.size(); i++)
        {
            memset(tmp_freq, 0, sizeof(tmp_freq));
            for (int j = 0; j < words[i].size(); j++)
                ++tmp_freq[words[i][j] - 'a'];
            for (int j = 0; j < 26; j++)
            {
                if (tmp_freq[j] > char_freq[j])
                    break;
                if (j == 25)
                    count += words[i].size();
            }
        }
        return count;
    }
};
// @lc code=end

// Note: hash table