/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。

示例1:
    输入：cost = [10, 15, 20]
    输出：15
    解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。

示例 2：
    输入：cost = [1,100,1,1,1,100,1,1,100,1]
    输出：6
    解释：你将从下标为 0 的台阶开始。
    - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
    - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
    - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
    总花费为 6 。


2 <= cost.length <= 1000
0 <= cost[i] <= 999
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
    int minCostClimbingStairs(vector<int>& cost) {
        /*dp[i]表示到第i级的最小花费, dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])*/
        /*dp[0] = 0, dp[1] = 0*/
        if (cost.size() == 1) {
            return cost[0];
        }
        else {
            vector<int> dp(cost.size() + 1, 0);    // 顶峰也算一个位置
            dp[0] = 0;
            dp[1] = 0;
            for (int i = 2; i < dp.size(); i++)
            {
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            }
            return dp.back();
        }
    }
};


int main()
{
    Solution solution;
    vector<int> cost = { 10, 15, 20 };
    int min_cost = solution.minCostClimbingStairs(cost);
    std::cout << min_cost << std::endl;
    return 0;
}

/*
* 运行时间7ms, 击败43.59% c++用户
* 消耗内存16.08M, 击败5.08% c++用户
*/
