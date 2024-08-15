/*
 * @lc app=leetcode id=860 lang=c
 *
 * [860] Lemonade Change
 */

// @lc code=start
bool lemonadeChange(int *bills, int billsSize)
{
    int cnt5 = 0;
    int cnt10 = 0;
    for (int i = 0; i < billsSize; i++)
    {
        switch (bills[i])
        {
        case 5:
            cnt5++;
            break;
        case 10:
            if (--cnt5 < 0)
                return false;
            cnt10++;
            break;
        case 20:
            if (cnt5 > 0 && cnt10 > 0)
            {
                --cnt5;
                --cnt10;
            }
            else if (cnt5 >= 3)
                cnt5 -= 3;
            else
                return false;
            break;
        }
    }
    return true;
}
// @lc code=end

// Note: greedy