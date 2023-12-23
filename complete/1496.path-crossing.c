/*
 * @lc app=leetcode id=1496 lang=c
 *
 * [1496] Path Crossing
 */

// @lc code=start
bool isPathCrossing(char *path)
{
    bool rec_pos[10001] = {false};
    int x = 0;
    int y = 0;
    rec_pos[x * 50 + y + 5000] = true;
    while (*path)
    {
        switch (*path)
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
        path++;
    }
    return false;
}
// @lc code=end

// Note: hash table