/*
 * @lc app=leetcode id=3536 lang=c
 *
 * [3536] Maximum Product of Two Digits
 */

// @lc code=start
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int maxProduct(int n)
{
    int first = INT_MIN;
    int second = INT_MIN;
    while (n)
    {
        int val = n % 10;
        if (val > first || first == INT_MIN)
        {
            if (first > second)
                second = first;
            first = val;
        }
        else if (val > second)
            second = val;
        if (second > first)
            swap(&first, &second);
        n /= 10;
    }

    return first * second;
}
// @lc code=end

// Note: math + sorting
