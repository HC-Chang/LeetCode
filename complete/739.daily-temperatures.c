/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 */

// @lc code=start

typedef struct
{
    int size;
    int cur;
    int *arr;
} STACK;

STACK *init_stack(int size)
{
    STACK *obj = malloc(sizeof(STACK));
    obj->size = size;
    obj->cur = -1;
    obj->arr = malloc(sizeof(int) * size);
    return obj;
}

bool is_empty_stack(STACK *obj)
{
    return (obj->cur == -1 ? true : false);
}

void push_stack(STACK *obj, int idx)
{
    obj->cur += 1;
    obj->arr[obj->cur] = idx;
}

void pop_stack(STACK *obj)
{
    if (is_empty_stack(obj))
    {
        printf("WARNING: empty stack!\n");
        return;
    }

    obj->cur -= 1;
    return obj->arr[obj->cur + 1];
}

int top_stack(STACK *obj)
{
    if (is_empty_stack(obj))
    {
        return -1;
    }
    return obj->arr[obj->cur];
}

void free_stack(STACK *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    if (temperaturesSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int *ret = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    STACK *obj = init_stack(temperaturesSize);

    for (int i = 0; i < temperaturesSize; i++)
    {
        if (is_empty_stack(obj) || temperatures[i] <= temperatures[top_stack(obj)])
            push_stack(obj, i);

        else
        {
            int targetIdx = top_stack(obj);
            pop_stack(obj);
            ret[targetIdx] = i - targetIdx;
            i--;
        }
    }

    free_stack(obj);
    return ret;
}

// @lc code=end

// Note: stack

// Time Limit Exceeded

// int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
//     *returnSize = temperaturesSize;
//     int *dp = calloc(*returnSize, sizeof(int));
//     for(int i = temperaturesSize-1; i>0; i--)
//     {
//         for(int j=i; j>=0; j--)
//         {
//             if(temperatures[i] > temperatures[j])
//                 dp[j] = i-j;
//         }
//     }
//     return dp;
// }
