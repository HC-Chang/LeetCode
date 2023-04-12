/*
 * @lc app=leetcode id=43 lang=c
 *
 * [43] Multiply Strings
 */

// @lc code=start
char *multiply(char *num1, char *num2)
{
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int *products = calloc(l1 + l2, sizeof(int));

    int p1, p2, sum;
    for (int i = l1 - 1; i >= 0; i--)
    {
        for (int j = l2 - 1; j >= 0; j--)
        {
            p1 = i + j;
            p2 = p1 + 1;
            sum = (num1[i] - '0') * (num2[j] - '0') + products[p2];
            products[p1] += sum / 10;
            products[p2] = sum % 10;
        }
    }

    char *r = calloc(l1 + l2 + 1, sizeof(char));
    int r_index = 0;
    int i = 0;
    while (products[i] == 0 && i < l1 + l2 - 1)
        i++;
    for (i; i < l1 + l2; i++)
        r[r_index++] = products[i] + '0';

    free(products);
    if (strlen(r) == 0)
        r = "0";
    return r;
}
// @lc code=end
