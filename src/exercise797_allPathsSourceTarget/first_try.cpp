/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

示例1:
    输入：graph = [[1,2],[3],[3],[]]
    输出：[[0,1,3],[0,2,3]]
    解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

示例 2：
    输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
    输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]


n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i（即不存在自环）
graph[i] 中的所有元素 互不相同
保证输入为 有向无环图（DAG）
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /*graph[i]是第i个节点可以通向的路径, 用深度优先算法*/
        path.clear();
        result.clear();
        path.emplace_back(0);   // 先把起点放进去
        dfs(graph, 0);
        return result;
    }

    void dfs(vector<vector<int>>& graph, int node) {
        if (node == graph.size() - 1) {
            // 终止条件, 如果当前node等于目标位置(size() - 1, 因为从0开始)
            result.emplace_back(path);
            return;
        }

        for (int i = 0; i < graph[node].size(); i++)
        {
            // 当前node可以到达的位置
            path.emplace_back(graph[node][i]);   // 不存在自环
            dfs(graph, graph[node][i]);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> result;
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间11ms, 击败69.34% c++用户
* 消耗内存13.02M, 击败36.24% c++用户
*/
