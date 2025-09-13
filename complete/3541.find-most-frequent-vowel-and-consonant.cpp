/*
 * @lc app=leetcode id=3541 lang=cpp
 *
 * [3541] Find Most Frequent Vowel and Consonant
 */

// @lc code=start
class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> hash;
        int max_v = 0;
        int max_c = 0;
        for (auto c : s)
        {
            ++hash[c];
            switch (c)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                if (hash[c] > max_v)
                    max_v = hash[c];
                break;
            default:
                if (hash[c] > max_c)
                    max_c = hash[c];
                break;
            }
        }

        return max_v + max_c;
    }
};
// @lc code=end

// Note: hash table + counting
