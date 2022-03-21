/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

// @lc code=start

int next(int n)
{
    int r = 0;
    while (n != 0)
    {
        int d = n % 10;
        n /= 10;
        r += d * d;
    }

    return r;
}

// 判斷有無環狀鏈結陣列 -> 快慢指標
bool isHappy(int n)
{
    int fast = n;
    int slow = n;

    do
    {
        fast = next(next(fast));
        slow = next(slow);

    } while (slow != fast);

    return (fast == 1);
}
// @lc code=end
