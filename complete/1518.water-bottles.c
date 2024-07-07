/*
 * @lc app=leetcode id=1518 lang=c
 *
 * [1518] Water Bottles
 */

// @lc code=start
// Solution 2: math

int numWaterBottles(int numBottles, int numExchange)
{
    return ((numBottles * numExchange) - 1) / (numExchange - 1);
}
// @lc code=end

// Note: math + simulation

// Solution 1: simulation
int numWaterBottles(int numBottles, int numExchange)
{
    int cnt = numBottles;
    while (numBottles >= numExchange)
    {
        cnt += numBottles / numExchange;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }

    return cnt;
}