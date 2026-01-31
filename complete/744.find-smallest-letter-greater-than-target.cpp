/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (target >= letters[letters.size() - 1])
            return letters[0];
        priority_queue<char, vector<char>, greater<char>> pq;
        for (const auto &l : letters)
        {
            if (l > target)
                pq.push(l);
        }

        return pq.top();
    }
};
// @lc code=end

// Note: binary search