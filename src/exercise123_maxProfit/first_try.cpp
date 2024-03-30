/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例1:
    输入：prices = [3,3,5,0,0,3,1,4]
    输出：6
    解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
         随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2：
    输入：prices = [1,2,3,4,5]
    输出：4
    解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
         因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3：
    输入：prices = [7,6,4,3,1]
    输出：0
    解释：在这个情况下, 没有交易完成, 所以最大利润为 0。

示例 4：
    输入：prices = [1]
    输出：0

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int dp[5] = { 0, -prices[0], 0, -prices[0], 0 };
        // 0: 啥都没做状态, 1: 第一次买入状态, 2: 第一次卖出状态, 3: 第二次买入状态, 4: 第二次卖出状态
        for (int i = 1; i < prices.size(); i++)
        {
            dp[4] = max(dp[4], dp[3] + prices[i]);    // 理应倒着来, 全用上一天的更新, 否则dp[1]先更新会影响dp[2]的值, 但从结果来看似乎不会
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[0] = dp[0];
        }

        return dp[4];
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间92ms, 击败89.77% c++用户
* 消耗内存75.72M, 击败83.09% c++用户
*/
