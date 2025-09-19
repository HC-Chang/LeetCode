/*
 * @lc app=leetcode id=3484 lang=cpp
 *
 * [3484] Design Spreadsheet
 */

// @lc code=start
class Spreadsheet
{
public:
    unordered_map<string, int> hash;
    bool check_cell(string cell)
    {
        if (cell[0] < 'A' || cell[0] > 'Z')
            return false;
        if (stoi(cell.erase(0, 1)) < 0)
            return false;
        return true;
    }

    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        if (check_cell(cell))
            hash[cell] = value;
    }

    void resetCell(string cell)
    {
        if (check_cell(cell))
            hash[cell] = 0;
    }

    int getValue(string formula)
    {
        int n = formula.size();
        int idx = formula.find('+');
        int val = 0;
        string tmp = formula.substr(1, idx - 1);
        if (isdigit(formula[1]))
            val += stoi(tmp);
        else
            val += hash[tmp];
        tmp = formula.substr(idx + 1, n - idx - 1);
        if (isdigit(formula[idx + 1]))
            val += stoi(tmp);
        else
            val += hash[tmp];
        return val;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
// @lc code=end

// Note: hash table + design
