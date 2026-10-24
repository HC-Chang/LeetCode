/*
 * @lc app=leetcode id=2409 lang=cpp
 *
 * [2409] Count Days Spent Together
 */

// @lc code=start
class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob)
    {
        vector<int> month_day = {0, 31, 59, 90, 120, 151, 181,
                                 212, 243, 273, 304, 334, 365};
        int arrive1 = month_day[stoi(arriveAlice.substr(0, 2)) - 1] +
                      stoi(arriveAlice.substr(3, 2));
        int arrive2 = month_day[stoi(arriveBob.substr(0, 2)) - 1] +
                      stoi(arriveBob.substr(3, 2));
        int leave1 = month_day[stoi(leaveAlice.substr(0, 2)) - 1] +
                     stoi(leaveAlice.substr(3, 2));
        int leave2 = month_day[stoi(leaveBob.substr(0, 2)) - 1] +
                     stoi(leaveBob.substr(3, 2));

        if (leave1 < arrive2 || arrive1 > leave2)
            return 0;
        return min(leave1, leave2) - max(arrive1, arrive2) + 1;
    }
};
// @lc code=end

// Note: math