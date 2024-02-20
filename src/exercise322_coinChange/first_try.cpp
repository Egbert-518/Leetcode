/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

示例1:
    输入：coins = [1, 2, 5], amount = 11
    输出：3
    解释：11 = 5 + 5 + 1

示例 2：
    输入：coins = [2], amount = 3
    输出：-1

示例 3：
    输入：coins = [1], amount = 0
    输出：0

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
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
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());   // 默认从小到大

        vector<int> dp(amount + 1, 1000000);   /*dp[j]表示容量为j的背包被填满所需要的最少硬币数量*/
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (j == coins[i]) {
                    dp[j] = 1;
                }
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }

            for (int j = 0; j <= amount; j++)
            {
                std::cout << dp[j] << " ";
            }
            std::cout << std::endl;
        }
        if (dp[amount] == 1000000) {
            return -1;
        }
        return dp[amount];
    }
};


int main()
{
    Solution solution;
    vector<int> coins = { 1, 2, 5 };
    solution.coinChange(coins, 11);
    return 0;
}

/*
* 运行时间21ms, 击败90.98% c++用户
* 消耗内存15.75M, 击败22.49% c++用户
*/
