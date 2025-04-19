/*
 * @lc app=leetcode id=229 lang=c
 *
 * [229] Majority Element II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 2:
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int n1 = 0;
    int n2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == n1)
            cnt1++;
        else if(nums[i] == n2)
            cnt2++;
        else if(cnt1 == 0)
        {
            n1 = nums[i];
            cnt1++;
        }
        else if(cnt2 == 0 )
        {
            n2 = nums[i];
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i =0; i<numsSize; i++)
    {
        if(nums[i] == n1)
            cnt1++;
        else if(nums[i] == n2)
            cnt2++; 
    }

    *returnSize = 0;
    if(cnt1 > numsSize/3)
        nums[(*returnSize)++] = n1;
    if(cnt2 > numsSize/3)
        nums[(*returnSize)++] = n2;
    return nums;
}
// @lc code=end

// Solution 1:
// int sort(const void *a, const void *b){return *(int*)a - *(int*)b;}
// int* majorityElement(int* nums, int numsSize, int* returnSize){
//     *returnSize = 0;
//     qsort(nums, numsSize, sizeof(int), sort);
//     int cnt=1;
//     int n = numsSize/3;
//     for(int i = 1; i<numsSize; i++)
//     {
//         if(nums[i] == nums[i-1])
//             cnt++;
//         else
//         {
//             if(cnt > n)
//                 nums[(*returnSize)++] = nums[i-1];
//             cnt = 1;
//         }
//     }
//     if(cnt > n)
//         nums[(*returnSize)++] = nums[numsSize-1];
//     return nums;
// }