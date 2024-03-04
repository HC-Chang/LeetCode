/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return power > tokens[0];

        sort(tokens.begin(), tokens.end());
        if (tokens[0] > power)
            return 0;

        int l = 0;
        int r = n - 1;
        int score = 0;
        while (l < r)
        {
            while (power >= tokens[l] && l < n)
            {
                power -= tokens[l++];
                score++;
            }

            if (score <= 0 || r - l <= 1)
                break;
            score--;
            power += tokens[r--];
            if (tokens[l] > power)
                break;
        }

        return score;
    }
};
// @lc code=end

// Note: sorting + two pointers