/*
 * @lc app=leetcode id=962 lang=c
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
// Solution 2:
int maxWidthRamp(int *nums, int numsSize)
{
    int max_len = 0;

    int mono_stack[numsSize];
    int mono_stack_len = 0;

    mono_stack[mono_stack_len] = 0;
    mono_stack_len += 1;

    for (int i = 1; i < numsSize; i += 1)
    {
        if (nums[i] < nums[mono_stack[mono_stack_len - 1]])
        {
            mono_stack[mono_stack_len] = i;
            mono_stack_len += 1;
        }
    }

    int cur_len;
    for (int i = numsSize - 1; i >= 0; i -= 1)
    {
        if (0 == mono_stack_len)
            break;

        while (mono_stack_len >= 1 &&
               nums[i] >= nums[mono_stack[mono_stack_len - 1]])
        {
            cur_len = i - mono_stack[mono_stack_len - 1];
            if (cur_len > max_len)
                max_len = cur_len;

            mono_stack_len -= 1;
        }
    }

    return max_len;
}
// @lc code=end

// Note: stack / monotonic stack

// Solution 1:

// typedef struct
// {
//     int idx;
//     int val;
// } DATA;

// int sort(const void *a, const void *b)
// {
//     DATA *x = (DATA *)a;
//     DATA *y = (DATA *)b;
//     if (x->val == y->val)
//         return x->idx - y->idx;
//     return x->val - y->val;
// }
// int maxWidthRamp(int *nums, int numsSize)
// {
//     DATA d[numsSize];

//     for (int i = 0; i < numsSize; i++)
//     {
//         d[i].idx = i;
//         d[i].val = nums[i];
//     }

//     qsort(&d, numsSize, sizeof(DATA), sort);

//     int min_index = numsSize;
//     int max_width = 0;

//     for (int i = 0; i < numsSize; i++)
//     {
//         max_width = fmax(max_width, d[i].idx - min_index);
//         min_index = fmin(min_index, d[i].idx);
//     }

//     return max_width;
// }