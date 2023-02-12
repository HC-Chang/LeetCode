/*
 * @lc app=leetcode id=6354 lang=c
 *
 * [6354] Find the Array Concatenation Value
 */

// Difficulty:Easy

// You are given a 0-indexed integer array nums.
// The concatenation of two numbers is the number formed by concatenating their numerals.

// For example, the concatenation of 15, 49 is 1549.
// The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:

// If there exists more than one number in nums, pick the first element and last element in nums respectively and add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
// If one element exists, add its value to the concatenation value of nums, then delete it.
// Return the concatenation value of the nums.

// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104

// @lc code=start

long long  concat_val(int a, int b)
{
    int offset = 0;
    int tmp = b;
    while(tmp)
    {
        offset++;
        tmp /= 10; 
    }
    
    long long r = (long long)a;
    for(int i =0; i< offset; i++)
        r *= 10;
    r += b;
    return r;
}

long long findTheArrayConcVal(int* nums, int numsSize){
    long long r = 0;
    
    for(int i= 0; i< numsSize/2; i++)    
        r += concat_val(nums[i], nums[numsSize-1-i]);
    if(numsSize%2 == 1)
        r += nums[numsSize/2];
    
    return r;    
}

// @lc code=end