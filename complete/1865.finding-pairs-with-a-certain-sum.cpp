/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
class FindSumPairs
{
public:
    vector<int> n1;
    vector<int> n2;
    unordered_map<int, int> hash_sum;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        n1 = nums1;
        n2 = nums2;
        for (auto v2 : nums2)
            ++hash_sum[v2];
    }

    void add(int index, int val)
    {
        --hash_sum[n2[index]];
        n2[index] += val;
        ++hash_sum[n2[index]];
    }

    int count(int tot)
    {
        int ans = 0;
        for (int num : n1)
        {
            int rest = tot - num;
            if (hash_sum.count(rest))
            {
                ans += hash_sum[rest];
            }
        }
        return ans;
    }
};
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end

// Note: hash table + design

// Offcial solution