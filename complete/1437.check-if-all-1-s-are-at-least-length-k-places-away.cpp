/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

 // @lc code=start
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int trigger = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cnt++;
            else if (cnt < k && trigger)
                return false;
            else
            {
                cnt = 0;
                trigger = 1;
            }
        }
        return true;
    }
};
// @lc code=end

