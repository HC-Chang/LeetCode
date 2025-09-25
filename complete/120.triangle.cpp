/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = n-2; i>=0; i--)
        {
            for(int j = 0; j<= i; j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);    
        }
        return triangle[0][0];
    }
};
// @lc code=end

// Note: DP