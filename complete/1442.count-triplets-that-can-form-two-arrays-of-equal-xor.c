/*
 * @lc app=leetcode id=1442 lang=c
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 */

// @lc code=start
// Solution 2:

int countTriplets(int *arr, int arrSize)
{
    int dp[arrSize + 1];
    dp[0] = 0;
    for (int i = 1; i <= arrSize; i++)
        dp[i] = arr[i - 1] ^ dp[i - 1];

    int cnt = 0;
    for (int i = 0; i <= arrSize; i++)
    {
        for (int j = i + 1; j <= arrSize; j++)
        {
            if (dp[i] == dp[j])
                cnt += j - i - 1;
        }
    }
    return cnt;
}
// @lc code=end

// Note: prefix sum

// Solution 1:

// int countTriplets(int* arr, int arrSize) {
//     int dp[arrSize][arrSize];
//     for(int i = 0;i<arrSize; i++)
//     {
//         dp[i][i] = arr[i];
//         for(int j = i+1;j<arrSize; j++)
//             dp[i][j] = dp[i][j-1] ^ arr[j];
//     }

//     int cnt = 0;
//     for(int i =0 ; i<arrSize; i++)
//     {
//         for(int j = i+1; j<arrSize; j++)
//         {
//             for(int k = j; k<arrSize; k++)
//             {
//                 if( dp[i][j-1] == dp[j][k])
//                     cnt++;
//             }
//         }
//     }
//     return cnt;
// }