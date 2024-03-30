/*
有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

示例1:
    输入:
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 1
    输出: 200
    解释: 从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200

示例 2：
    输入:
    n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
    src = 0, dst = 2, k = 0
    输出: 500
    解释: 从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500


1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
航班没有重复，且不存在自环
0 <= src, dst, k < n
src != dst
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> reachable_list(n, vector<int>());
        for (int i = 0; i < flights.size(); i++)
        {
            reachable_list[flights[i][0]].push_back(i);     // 存下标, 有向图, 不用存逆向机票
        }
        backtracking(flights, reachable_list, src, dst, k, 0);
        if (min_cost == INT32_MAX) {
            return -1;
        }
        else {
            return min_cost;
        }
    }

    void backtracking(vector<vector<int>>& flights, vector<vector<int>>& reachable_list, int cur_node, int dst, int k, int cur_cost) {
        if (cur_node == dst) {
            if (cur_cost < min_cost) {
                min_cost = cur_cost;
            }
            return;
        }
        if (k < 0 || cur_cost > min_cost) {
            return;   // 中转次数用完了, 或者当前花费已经超过了当前最少花费, 直接返回
        }

        for (int i = 0; i < reachable_list[cur_node].size(); i++)
        {
            // 当前节点可以去的节点
            backtracking(flights, reachable_list, flights[reachable_list[cur_node][i]][1], dst, k - 1, cur_cost + flights[reachable_list[cur_node][i]][2]);
        }
    }

private:
    int min_cost = INT32_MAX;
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 超过时间限制
*/
