/*
 * @lc app=leetcode id=149 lang=c
 *
 * [149] Max Points on a Line
 */

// @lc code=start
int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    if (pointsSize < 3)
        return pointsSize;

    int max_count = 0;
    int count;
    int dx1, dy1, dx2, dy2;

    for (int i = 0; i < pointsSize; i++)
    {

        for (int j = i + 1; j < pointsSize; j++)
        {
            count = 2;

            dx1 = points[j][0] - points[i][0];
            dy1 = points[j][1] - points[i][1];

            for (int k = 0; k < pointsSize; k++)
            {
                if (k != i && k != j)
                {
                    dx2 = points[k][0] - points[i][0];
                    dy2 = points[k][1] - points[i][1];

                    if (dx2 * dy1 == dy2 * dx1)
                        count++;
                }
            }

            if (count > max_count)
                max_count = count;
        }
    }

    return max_count;
}
// @lc code=end
