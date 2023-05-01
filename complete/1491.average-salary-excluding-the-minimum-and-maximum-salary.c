/*
 * @lc app=leetcode id=1491 lang=c
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
double average(int *salary, int salarySize)
{
    double avg = salary[0];
    int min_val = salary[0];
    int max_val = salary[0];
    for (int i = 1; i < salarySize; i++)
    {
        if (salary[i] < min_val)
            min_val = salary[i];
        else if (salary[i] > max_val)
            max_val = salary[i];
        avg += salary[i];
    }
    return (avg - min_val - max_val) / (salarySize - 2);
}
// @lc code=end
