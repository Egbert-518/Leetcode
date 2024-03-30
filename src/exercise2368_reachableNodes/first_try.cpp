﻿/*
现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。

给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。

在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。

注意，节点 0 不 会标记为受限节点。

示例1:
    输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
    输出：4
    解释：上图所示正是这棵树。
    在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。

示例 2：
    输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
    输出：3
    解释：上图所示正是这棵树。
    在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。


2 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵有效的树
1 <= restricted.length < n
1 <= restricted[i] < n
restricted 中的所有值 互不相同
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        /*0所在的节点最大能蔓延的节点数量, 考虑广度优先搜索*/
        vector<bool> visited(n, false);
        for (int i = 0; i < restricted.size(); i++)
        {
            visited[restricted[i]] = true;    // 限制点相当于已经被visited, 不能向外扩展
        }

        vector<vector<int>> reachable_list(n, vector<int>());
        for (vector<int> edge : edges)
        {
            reachable_list[edge.front()].emplace_back(edge.back());
            reachable_list[edge.back()].emplace_back(edge.front());   // 双向图
        }

        queue<int> que;
        que.push(0);
        visited[0] = true;
        int count = 1;

        while (!que.empty())
        {
            int cur_node = que.front();
            que.pop();
            for (int i = 0; i < reachable_list[cur_node].size(); i++)
            {
                // cur_node可以到达的节点
                if (visited[reachable_list[cur_node][i]]) {
                    continue;
                }
                else {
                    count++;
                    visited[reachable_list[cur_node][i]] = true;
                    que.push(reachable_list[cur_node][i]);
                }
            }
        }

        return count;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间440ms, 击败68.78% c++用户
* 消耗内存161.26M, 击败67.13% c++用户
*/
