/*
 * @lc app=leetcode id=2043 lang=c
 *
 * [2043] Simple Bank System
 */

// @lc code=start

typedef struct
{
    long long *account;
    int account_size;
} Bank;

Bank *bankCreate(long long *balance, int balanceSize)
{
    Bank *obj = malloc(sizeof(Bank));
    obj->account = balance;
    obj->account_size = balanceSize;

    return obj;
}

bool bankTransfer(Bank *obj, int account1, int account2, long long money)
{
    if (account1 - 1 > obj->account_size || account2 - 1 > obj->account_size || obj->account[account1 - 1] < money)
        return false;
    obj->account[account1 - 1] -= money;
    obj->account[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank *obj, int account, long long money)
{
    if (account - 1 > obj->account_size)
        return false;
    obj->account[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank *obj, int account, long long money)
{
    if (account - 1 > obj->account_size || obj->account[account - 1] < money)
        return false;

    obj->account[account - 1] -= money;
    return true;
}

void bankFree(Bank *obj)
{
    free(obj);
}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);

 * bool param_2 = bankDeposit(obj, account, money);

 * bool param_3 = bankWithdraw(obj, account, money);

 * bankFree(obj);
*/
// @lc code=end

// Note: hash table + design + simulation