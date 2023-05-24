/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// Difficulty:Medium

// @lc code=start
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<long long, long long>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums2[i], nums1[i]});

        sort(arr.rbegin(), arr.rend());

        priority_queue<long long, vector<long long>, greater<>> pq;
        long long min = INT_MAX;
        long long sum = 0;
        long long r = 0;
        for (int i = 0; i < n; i++)
        {
            min = arr[i].first;
            sum += arr[i].second;
            pq.push(arr[i].second);
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                r = max(r, sum * min);
        }
        return r;
    }
};
// @lc code=end