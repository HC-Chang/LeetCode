/*
 * @lc app=leetcode id=933 lang=c
 *
 * [933] Number of Recent Calls
 */

// @lc code=start

typedef struct
{
    int *arr;
    int left;
    int right;
} RecentCounter;

RecentCounter *recentCounterCreate()
{
    RecentCounter *obj = malloc(sizeof(RecentCounter));
    obj->arr = calloc(10000, sizeof(int));
    obj->left = 0;
    obj->right = 0;
    return obj;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    obj->arr[obj->right++] = t;
    while (obj->left <= obj->right && t - 3000 > obj->arr[obj->left])
        obj->left++;
    return obj->right - obj->left;
}

void recentCounterFree(RecentCounter *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
// @lc code=end
