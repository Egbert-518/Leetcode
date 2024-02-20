/*
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例1:
    输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
    输出：8
    解释：能够达到的最大利润:
    在此处买入 prices[0] = 1
    在此处卖出 prices[3] = 8
    在此处买入 prices[4] = 4
    在此处卖出 prices[5] = 9
    总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

示例 2：
    输入：prices = [1,3,7,5,10,3], fee = 3
    输出：6


1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4
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
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);   // 不用跟上一次买入作比较, 肯定不可能高于不操作
            dp[i][1] = max(max(dp[i - 1][1], dp[i - 1][0] - prices[i]), dp[i - 1][2] - prices[i]);    // 这里需要与卖出的状态作比较, 因为没有冻结期, 所以上一状态卖出后可以立即买入
            dp[i][2] = dp[i - 1][1] + prices[i] - fee;
        }

        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间147ms, 击败53.47% c++用户
* 消耗内存90.96M, 击败17.47% c++用户
*/
