/*
 * @lc app=leetcode id=2409 lang=c
 *
 * [2409] Count Days Spent Together
 */

// @lc code=start
int countDaysTogether(char *arriveAlice, char *leaveAlice, char *arriveBob, char *leaveBob)
{
    int month_day[] = {0, 31, 59, 90, 120, 151, 181,
                       212, 243, 273, 304, 334, 365};
    int arrive1 = month_day[(arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0') - 1] +
                  (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
    int arrive2 = month_day[(arriveBob[0] - '0') * 10 + (arriveBob[1] - '0') - 1] +
                  (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
    int leave1 = month_day[(leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0') - 1] +
                 (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
    int leave2 = month_day[(leaveBob[0] - '0') * 10 + (leaveBob[1] - '0') - 1] +
                 (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

    if (leave1 < arrive2 || arrive1 > leave2)
        return 0;
    return fmin(leave1, leave2) - fmax(arrive1, arrive2) + 1;
}
// @lc code=end

// Note: math