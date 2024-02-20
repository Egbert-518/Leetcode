/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。

题目数据保证结果符合 32 位带符号整数。

示例1:
    输入：amount = 5, coins = [1, 2, 5]
    输出：4
    解释：有四种方式可以凑成总金额：
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1

示例 2：
    输入：amount = 3, coins = [2]
    输出：0
    解释：只用面额 2 的硬币不能凑成总金额 3 。

1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*完全背包问题, 每个物品可以取无限次, 背包容量为amount, 物品价值为钱币价值, 看能否装到amount价值*/
        /*对于该问题dp[j]表示容量为j的背包可以有dp[j]种方法被填充, 则dp[j]=求和(dp[j-coin])*/
        if (amount == 0) {
            return 1;
        }

        vector<int> dp(amount + 1, 0);

        for (int coin : coins)
        {
            for (int j = coin; j <= amount; j++)
            {
                if (j == coin) {
                    dp[j]++;     // 因为dp[0] = 0, 所以对于每个币种, 该位置的数量需要+1
                }
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};


int main()
{
    Solution solution;
    vector<int> coins = { 1, 2, 5 };
    solution.change(5, coins);
    return 0;
}

/*
* 运行时间3ms, 击败92.32% c++用户
* 消耗内存8.21M, 击败35.02% c++用户
*/
