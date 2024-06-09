/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        vector <int> map(k);
        map[0] = 1;

        int r = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            r = ((r + nums[i]) % k + k) % k;
            count += map[r];
            map[r]++;
        }
    
        return count;
    }
};
// @lc code=end

// Note: hash table + prefix sum