/*
 * @lc app=leetcode id=881 lang=c
 *
 * [881] Boats to Save People
 */

// @lc code=start
int sort(void *a, void *b) { return *(int *)a - *(int *)b; }
int numRescueBoats(int *people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), sort);
    int left = 0;
    int right = peopleSize - 1;
    int boat_count = 0;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            left++;
            right--;
        }
        else
            right--;
        boat_count++;
    }
    return boat_count;
}

// @lc code=end

// Note: sorting + two pointers