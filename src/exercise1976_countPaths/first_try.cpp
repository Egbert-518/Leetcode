/*
你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。

给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。

请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 109 + 7 取余 后返回。

示例1:
    输入：n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    输出：4
    解释：从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
    四条花费 7 分钟的路径分别为：
    - 0 ➝ 6
    - 0 ➝ 4 ➝ 6
    - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
    - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

示例 2：
    输入：n = 2, roads = [[1,0,10]]
    输出：1
    解释：只有一条从路口 0 到路口 1 的路，花费 10 分钟。


1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 10^9
ui != vi
任意两个路口之间至多有一条路。
从任意路口出发，你能够到达其他任意路口。
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
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> reachable_list(n, vector<int>());
        for (int i = 0; i < roads.size(); i++)
        {
            reachable_list[roads[i][0]].emplace_back(i);     // 将以该值为起点的路径放入到列表中
            reachable_list[roads[i][1]].emplace_back(i);     // 双向通行
        }
        vector<bool> is_reach(n, false);
        is_reach[0] = true;
        backtracking(roads, reachable_list, is_reach, n, 0, 0);
        return count;
    }

    void backtracking(vector<vector<int>>& roads, vector<vector<int>>& reachable_list, vector<bool>& is_reach, int n, int cur_node, int cur_time) {
        if (cur_node == n - 1) {
            // 到达终点
            if (cur_time < cur_min_time) {
                cur_min_time = cur_time;
                count = 1;
            }
            else if (cur_time == cur_min_time) {
                count++;
            }
            // 到达终点, 但时间大于不考虑
            return;
        }

        if (cur_time > cur_min_time) {
            // 剪枝, 如果未到终点但时间已经超过了当前最短时间, 没必要搜索
            return;
        }

        // 开始处理节点
        for (int i = 0; i < reachable_list[cur_node].size(); i++)   // 当前节点联通的路径
        {
            int next_node;
            if (cur_node == roads[reachable_list[cur_node][i]][1]) {
                next_node = roads[reachable_list[cur_node][i]][0];
            }
            else {
                next_node = roads[reachable_list[cur_node][i]][1];
            }

            if (!is_reach[next_node]) {    // 没走过的才走
                is_reach[next_node] = true;
                backtracking(roads, reachable_list, is_reach, n, next_node, cur_time + roads[reachable_list[cur_node][i]][2]);
                is_reach[next_node] = false;
            }
        }
    }

private:
    int cur_min_time = INT32_MAX;
    int count = 1;
};


int main()
{
    Solution solution;
    vector<vector<int>> roads = { {0,6,7} ,{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2} };
    solution.countPaths(7, roads);
    return 0;
}

/*
* 超过时间限制
*/
