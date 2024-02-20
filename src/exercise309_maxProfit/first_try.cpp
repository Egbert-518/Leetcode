/*
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例1:
    输入: prices = [1,2,3,0,2]
    输出: 3
    解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

示例 2：
    输入: prices = [1]
    输出: 0


1 <= prices.length <= 5000
0 <= prices[i] <= 1000
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
    int maxProfit(vector<int>& prices) {
        /*dp[i][j]表示第i天处于j状态能获得的最大利润, 状态0: 不操作, 1: 买入, 2: 卖出, 3: 冻结*/
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][3], max(dp[i - 1][2], max(dp[i - 1][0], dp[i - 1][1])));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }

        return max(dp[prices.size() - 1][3], max(dp[prices.size() - 1][2], max(dp[prices.size() - 1][0], dp[prices.size() - 1][1])));
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间2ms, 击败74.54% c++用户
* 消耗内存13.72M, 击败18.11% c++用户
*/
