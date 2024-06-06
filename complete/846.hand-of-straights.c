/*
 * @lc app=leetcode id=846 lang=c
 *
 * [846] Hand of Straights
 */

// @lc code=start
bool isNStraightHand(int *hand, int handSize, int groupSize)
{
    if (handSize % groupSize != 0)
        return false;
    int buffer = 20000;
    int hash[handSize + buffer];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < handSize; i++)
        ++hash[hand[i] % (handSize + buffer)];

    for (int i = 0; i < handSize + buffer; i++)
    {
        if (hash[i] != 0)
        {
            for (int j = 0; j < groupSize; j++)
            {
                if (--hash[(i % (handSize + buffer)) + j] < 0)
                    return false;
            }
            i--;
        }
    }
    return true;
}
// @lc code=end

// Note: hash table