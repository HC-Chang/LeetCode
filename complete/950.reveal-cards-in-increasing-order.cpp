/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        sort(deck.begin(), deck.end());
        vector<int> r(n);
        int tmp;
        for (int i = 0; i < n; i++)
        {
            tmp = q.front();
            q.pop();
            r[tmp] = deck[i];
            q.push(q.front());
            q.pop();
        }
        return r;
    }
};
// @lc code=end

// Note: sorting + queue