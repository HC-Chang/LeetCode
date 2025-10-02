/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = 0;
        int empty = 0;
        while(numBottles > 0)
        {
            drunk += numBottles;
            empty += numBottles;
            numBottles = 0;
            while(empty - numExchange >=0) 
            {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return drunk;
    }
};
// @lc code=end

// Note: math + simulation