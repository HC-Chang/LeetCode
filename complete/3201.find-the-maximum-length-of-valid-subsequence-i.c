/*
 * @lc app=leetcode id=3201 lang=c
 *
 * [3201] Find the Maximum Length of Valid Subsequence I
 */

// @lc code=start
int maximumLength(int *nums, int numsSize)
{
    int max_cnt = 0;
    int patterns[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 4; i++)
    {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] % 2 == patterns[i][cnt % 2])
                cnt++;
        }
        max_cnt = fmax(max_cnt, cnt);
    }
    return max_cnt;
}
// @lc code=end

// Note: DP + greedy

// Official Solution