/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (38.82%)
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        
        int len = nums.Length;
        int [] r = new int [2];

        for(int i =0 ;i<len;i++)
        {
            for (int j = i+1;j<len;j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    r[0] = i;
                    r[1] = j;
                    break;
                }
            }
        }

        return r;
    }
}
