/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        int buffer = 20000;
        int hash[n + buffer];
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < n; i++)
            ++hash[hand[i] % (n + buffer)];

        for (int i = 0; i < n + buffer; i++)
        {
            if (hash[i] != 0)
            {
                for (int j = 0; j < groupSize; j++)
                {
                    if (--hash[(i % (n + buffer)) + j] < 0)
                        return false;
                }
                i--;
            }
        }
        return true;
    }
};
// @lc code=end

// Note: hash table