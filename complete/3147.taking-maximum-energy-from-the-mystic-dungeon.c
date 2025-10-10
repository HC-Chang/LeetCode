/*
 * @lc app=leetcode id=3147 lang=c
 *
 * [3147] Taking Maximum Energy From the Mystic Dungeon
 */

// @lc code=start
int maximumEnergy(int *energy, int energySize, int k)
{
    for (int i = 0; i < energySize - k; i++)
        energy[i + k] = fmax(energy[i + k] + energy[i], energy[i + k]);
    for (int i = energySize - k; i < energySize; i++)
        energy[energySize - 1] = fmax(energy[energySize - 1], energy[i]);
    return energy[energySize - 1];
}
// @lc code=end

// Note: prefix sum + greedy