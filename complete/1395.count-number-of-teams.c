/*
 * @lc app=leetcode id=1395 lang=c
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
// Solution : DP

int numTeams(int *rating, int ratingSize)
{
    int n = ratingSize;
    int teams = 0;

    int leftSmaller;
    int rightLarger;
    int leftLarger;
    int rightSmaller;

    for (int mid = 0; mid < n; mid++)
    {
        leftSmaller = 0;
        rightLarger = 0;

        for (int left = mid - 1; left >= 0; left--)
        {
            if (rating[left] < rating[mid])
                leftSmaller++;
        }

        for (int right = mid + 1; right < n; right++)
        {
            if (rating[right] > rating[mid])
                rightLarger++;
        }

        teams += leftSmaller * rightLarger;

        leftLarger = mid - leftSmaller;
        rightSmaller = n - mid - 1 - rightLarger;

        teams += leftLarger * rightSmaller;
    }

    return teams;
}
// @lc code=end

// Note: DP / binary indexed tree

// Official Solution