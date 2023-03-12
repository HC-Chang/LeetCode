/*
 * @lc app=leetcode id=6315 lang=c
 *
 * [6315] Count the Number of Vowel Strings in Range
 */

// Difficulty: Easy

// You are given a 0-indexed array of string words and two integers left and right.
// A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
// Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

// Constraints:
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 10
// words[i] consists of only lowercase English letters.
// 0 <= left <= right < words.length

// @lc code=start
int vowelStrings(char **words, int wordsSize, int left, int right)
{
    int count = 0;
    int v_count;
    for (int i = left; i <= right; i++)
    {
        v_count = 0;
        switch (words[i][0])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            v_count++;
            break;
        }
        switch (words[i][strlen(words[i]) - 1])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            v_count++;
            break;
        }
        if (v_count == 2)
            count++;
    }
    return count;
}

// @lc code=end