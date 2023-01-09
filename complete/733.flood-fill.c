/*
 * @lc app=leetcode id=733 lang=c
 *
 * [733] Flood Fill
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void DFS(int **image, int imageSize, int *imageColSize, int sr, int sc, int color, int *old_color)
{
    if (sr >= imageSize || sr < 0 || sc >= imageColSize[sr] || sc < 0 || color == 0 || image[sr][sc] != old_color || color == old_color)
        return;

    image[sr][sc] = color;

    if (sr + 1 < imageSize)
        DFS(image, imageSize, imageColSize, sr + 1, sc, color, old_color);
    if (sr - 1 >= 0)
        DFS(image, imageSize, imageColSize, sr - 1, sc, color, old_color);
    if (sc + 1 < imageColSize[sr])
        DFS(image, imageSize, imageColSize, sr, sc + 1, color, old_color);
    if (sc - 1 >= 0)
        DFS(image, imageSize, imageColSize, sr, sc - 1, color, old_color);
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int color, int *returnSize, int **returnColumnSizes)
{
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    DFS(image, imageSize, imageColSize, sr, sc, color, image[sr][sc]);
    return image;
}
// @lc code=end
