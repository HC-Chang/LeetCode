/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    typedef struct
    {
        int val;
        int bit_count;
    } DATA;

    int count_bits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        int n = arr.size();
        vector<DATA> d(n);
        for (int i = 0; i < n; i++)
        {
            d[i].val = arr[i];
            d[i].bit_count = count_bits(arr[i]);
        }
        std::sort(d.begin(), d.end(), [](DATA a, DATA b){
            if (a.bit_count == b.bit_count)
                return a.val < b.val;
            return a.bit_count < b.bit_count; });
        for (int i = 0; i < n; i++)
            arr[i] = d[i].val;
        return arr;
    }
};
// @lc code=end
