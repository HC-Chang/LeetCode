/*
 * @lc app=leetcode id=278 lang=c
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    if (n == 1 && isBadVersion(n))
        return 1;
    int left = 0;
    int right = n;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (isBadVersion(middle))
        {
            if (!isBadVersion(middle - 1))
                return middle;
            else
                right = middle - 1;
        }
        else
            left = middle + 1;
    }

    return 0;
}
// @lc code=end
