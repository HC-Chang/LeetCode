/*
 * @lc app=leetcode id=42 lang=c
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

// Soluiton 2:

int trap(int *height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int pre_max = 0, post_max = 0;
    int r = 0;
    while (left <= right)
    {
        if (pre_max < height[left])
            pre_max = height[left];
        if (post_max < height[right])
            post_max = height[right];
        if (pre_max < post_max)
            r += pre_max - height[left++];
        else
            r += post_max - height[right--];
    }

    return r;
}
// @lc code=end

// Solution 1:

// int trap(int *height, int heightSize)
// {
//     int *pre_max = malloc(heightSize * sizeof(int));
//     int *post_max = malloc(heightSize * sizeof(int));
//     pre_max[0] = height[0];
//     post_max[heightSize - 1] = height[heightSize - 1];
//     for (int i = 1; i < heightSize; i++)
//     {
//         pre_max[i] = fmax(pre_max[i - 1], height[i]);
//         post_max[heightSize - 1 - i] = fmax(post_max[heightSize - i], height[heightSize - 1 - i]);
//     }

//     int r = 0;
//     for (int i = 0; i < heightSize; i++)
//         r += fmin(pre_max[i], post_max[i]) - height[i];

//     free(pre_max);
//     free(post_max);
//     return r;
// }