/*
 * @lc app=leetcode id=1061 lang=c
 *
 * [1061] Lexicographically Smallest Equivalent String
 */
// @lc code=start
int find(int x, int *representative)
{
    if (representative[x] == x)
        return x;

    return representative[x] = find(representative[x], representative);
}

void performUnion(int x, int y, int *representative)
{
    x = find(x, representative);
    y = find(y, representative);

    if (x == y)
        return;

    if (x < y)
        representative[y] = x;
    else
        representative[x] = y;
}

char *smallestEquivalentString(char *s1, char *s2, char *baseStr)
{
    int representative[26];
    for (int i = 0; i < 26; i++)
        representative[i] = i;

    for (int i = 0; i < strlen(s1); i++)
        performUnion(s1[i] - 'a', s2[i] - 'a', representative);

    char *ans = malloc(1001 * sizeof(char));
    int idx = 0;
    for (int i = 0; i < strlen(baseStr); i++)
    {
        ans[idx++] = (char)(find(baseStr[i] - 'a', representative) + 'a');
    }
    ans[idx] = '\0';
    return ans;
}
// @lc code=end

// Union Find