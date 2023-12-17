/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
class FoodRatings
{
public:
    unordered_map<string, pair<int, string>> hash_food;
    unordered_map<string, set<pair<int, string>>> hash_cuisine;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            hash_food[foods[i]] = make_pair(ratings[i], cuisines[i]);
            hash_cuisine[cuisines[i]].emplace(-ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating)
    {
        int rating = hash_food[food].first;
        string cuisine = hash_food[food].second;

        hash_food[food].first = newRating;
        hash_cuisine[cuisine].erase({-rating, food});
        hash_cuisine[cuisine].emplace(-newRating, food);
    }

    string highestRated(string cuisine)
    {
        return hash_cuisine[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

// Note: hash table