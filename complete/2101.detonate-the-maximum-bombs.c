/*
 * @lc app=leetcode id=2101 lang=c
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
int TwoPointBomb(int x0, int y0, int x1, int y1, int r)
{
    long r2 = (long)(x1 - x0) * (x1 - x0) + (long)(y1 - y0) * (y1 - y0);
    long rr = (long)r * r;
    return r2 <= rr ? 1 : 0;
}

int maximumDetonation(int **bombs, int bombsSize, int *bombsColSize)
{
    int *queue[101] = {0};
    int temp = 0;
    int visited[101];
    int *ele;
    int head, tail;
    int max_count = 0;
    int len;
    int *cur;
    int x0, y0, x1, y1, r;
    for (int i = 0; i < bombsSize; ++i)
    {
        temp = 0;
        memset(visited, 0, sizeof(visited));
        ele = bombs[i];
        head = 0, tail = 0;
        queue[tail] = ele;
        tail++;
        visited[i] = 1;
        while (head != tail)
        {
            len = tail - head;
            temp += len;
            for (int j = 0; j < len; ++j)
            {
                cur = queue[head];
                head++;
                x0 = cur[0];
                y0 = cur[1];
                r = cur[2];
                for (int k = 0; k < bombsSize; ++k)
                {
                    if (visited[k] == 0)
                    {
                        x1 = bombs[k][0];
                        y1 = bombs[k][1];
                        if (TwoPointBomb(x0, y0, x1, y1, r) == 1)
                        {
                            visited[k] = 1;
                            queue[tail] = bombs[k];
                            tail++;
                        }
                    }
                }
            }
        }

        if (max_count == bombsSize)
            return max_count;
        max_count = temp > max_count ? temp : max_count;
    }
    return max_count;
}
// @lc code=end
