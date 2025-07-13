/*
 * @lc app=leetcode id=2410 lang=cpp
 *
 * [2410] Maximum Matching of Players With Trainers
 */

// @lc code=start
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int r_p = players.size() - 1;
        int r_t = trainers.size() - 1;
        int cnt = 0;
        while (r_p >= 0 && r_t >= 0)
        {
            if (players[r_p] <= trainers[r_t])
            {
                cnt++;
                r_t--;
                r_p--;
            }
            else
                r_p--;
        }

        return cnt;
    }
};
// @lc code=end

// Note: greedy + sorting