/*
 * @lc app=leetcode id=2410 lang=c
 *
 * [2410] Maximum Matching of Players With Trainers
 */

// @lc code=start
int sort(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int matchPlayersAndTrainers(int *players, int playersSize, int *trainers, int trainersSize)
{
    qsort(players, playersSize, sizeof(int), sort);
    qsort(trainers, trainersSize, sizeof(int), sort);
    
    int r_p = playersSize - 1;
    int r_t = trainersSize - 1;
    int cnt = 0;
    while (r_p >= 0 && r_t >= 0)
    {
        if (players[r_p] <= trainers[r_t])
        {
            cnt++;
            r_t--;
            r_p--;
        }
        else
            r_p--;
    }

    return cnt;
}
// @lc code=end

// Note: greedy + sorting