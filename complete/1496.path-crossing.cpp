/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        bool rec_pos[10001] = {false};
        int x = 0;
        int y = 0;
        rec_pos[x * 50 + y + 5000] = true;
        for (char &c : path)
        {
            switch (c)
            {
            case 'N':
                y += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'E':
                x += 1;
                break;
            case 'W':
                x -= 1;
                break;
            }
            if (rec_pos[x * 50 + y + 5000] == true)
                return true;
            else
                rec_pos[x * 50 + y + 5000] = true;
        }
        return false;
    }
};
// @lc code=end

// Note: hash table