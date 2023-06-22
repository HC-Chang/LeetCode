/*
 * @lc app=leetcode id=999 lang=c
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
int numRookCaptures(char **board, int boardSize, int *boardColSize)
{
    int count = 0;
    int i, j, k;
    int trigger = 0;
    for (i = 0; i < boardSize; i++)
    {
        for (j = 0; j < boardColSize[i]; j++)
        {
            if (board[i][j] == 'R')
            {
                trigger = 1;
                break;
            }
        }
        if (trigger)
            break;
    }

    for (k = i + 1; k < boardSize; k++)
    {
        if (board[k][j] == 'B')
            break;
        if (board[k][j] == 'p')
        {
            count++;
            break;
        }
    }

    for (k = j + 1; k < boardSize; k++)
    {
        if (board[i][k] == 'B')
            break;
        if (board[i][k] == 'p')
        {
            count++;
            break;
        }
    }

    for (k = i - 1; k >= 0; k--)
    {
        if (board[k][j] == 'B')
            break;
        if (board[k][j] == 'p')
        {
            count++;
            break;
        }
    }

    for (k = j - 1; k >= 0; k--)
    {
        if (board[i][k] == 'B')
            break;
        if (board[i][k] == 'p')
        {
            count++;
            break;
        }
    }

    return count;
}
// @lc code=end
