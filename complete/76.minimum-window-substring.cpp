/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int s_len = s.size();
        int t_len = t.size();
        int left = 0;
        int right = 0;
        int s_valid_count = 0;
        int t_valid_count = 0;

        int start = 0;
        int r_len = INT_MAX;
        unordered_map<char, int> hash_s;
        unordered_map<char, int> hash_t;
        for (int i = 0; i < t_len; i++)
        {
            if (++hash_t[t[i]] == 1)
                t_valid_count++;
        }

        char c;
        char d;
        while (right < s_len)
        {
            c = s[right];
            right++;
            if (hash_t[c])
            {
                hash_s[c]++;
                if (hash_s[c] == hash_t[c])
                    s_valid_count++;
            }
            while (s_valid_count == t_valid_count)
            {
                if (right - left < r_len)
                {
                    start = left;
                    r_len = right - left;
                }
                d = s[left];
                left++;
                if (hash_t[d])
                {
                    if (hash_s[d] == hash_t[d])
                        s_valid_count--;

                    --hash_s[d];
                }
            }
        }

        if (r_len == INT_MAX)
            return "";

        string r;
        r = s.substr(start, r_len);
        return r;
    }
};
// @lc code=end

// Note: hash table + sliding window