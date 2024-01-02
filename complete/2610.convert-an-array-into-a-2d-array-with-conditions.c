/*
 * @lc app=leetcode id=2610 lang=c
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Solution 2:
int sort(void *a ,void *b){return *(int*)a - *(int *)b;}
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), sort);
    int **ans = malloc(numsSize*sizeof(int*));
    for(int i =0;i<numsSize; i++)
        ans[i] = calloc(numsSize,sizeof(int));
    
    int cnt = 1;
    *returnSize = 0;
    returnColumnSizes[0] = calloc(numsSize, sizeof(int)) ;
    for(int i = 1 ; i<numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            cnt++;
            if(cnt > *returnSize)
                *returnSize = cnt;
        }
        else
        {
            for(int j = 0; j<cnt; j++)
                ans[j][returnColumnSizes[0][j]++] = nums[i-1];
            cnt = 1;
        }
    }
    if(cnt > *returnSize)
        *returnSize = cnt;
    for(int j = 0; j<cnt; j++)
        ans[j][returnColumnSizes[0][j]++] = nums[numsSize-1];

    return ans;
}
// @lc code=end

// Note: hash table

// Solution 1:
// int **findMatrix(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
// {
//     int hash[201] = {0};
//     *returnSize = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (++hash[nums[i]] > *returnSize)
//             *returnSize = hash[nums[i]];
//     }

//     returnColumnSizes[0] = calloc(*returnSize, sizeof(int));
//     int **ans = malloc(*returnSize * sizeof(int *));
//     for (int i = 0; i < *returnSize; i++)
//         ans[i] = calloc(200, sizeof(int));
//     for (int i = 1; i < 201; i++)
//     {
//         if (hash[i] > 0)
//         {
//             for (int j = 0; j < hash[i]; j++)
//                 ans[j][returnColumnSizes[0][j]++] = i;
//         }
//     }

//     return ans;
// }