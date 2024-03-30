/*
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

返回执行此操作后，grid 中最大的岛屿面积是多少？

岛屿 由一组上、下、左、右四个方向相连的 1 形成。

示例1:
    输入: grid = [[1, 0], [0, 1]]
    输出: 3
    解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。

示例 2：
    输入: grid = [[1, 1], [1, 0]]
    输出: 4
    解释: 将一格0变成1，岛屿的面积扩大为 4。

示例 3：
    输入: grid = [[1, 1], [1, 1]]
    输出: 4
    解释: 没有0可以让我们变成1，面积依然为 4。

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] 为 0 或 1
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
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> umap;
        int mark = 2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) {
                    int count = bfs(grid, i, j, mark);
                    umap[mark] = count;
                    mark++;
                }
            }
        }

        int max_area = 0;
        bool has_zero = false;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 0) {
                    has_zero = true;
                    int cur_area = 1;   // 插入位置一定有面积1
                    unordered_set<int> visited_grid;  // 记录当前周围已经访问过的岛屿
                    for (int k = 0; k < 4; k++)
                    {
                        int next_x = i + dir[k][0];
                        int next_y = j + dir[k][1];
                        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited_grid.count(grid[next_x][next_y])) {
                            continue;
                        }
                        cur_area += umap[grid[next_x][next_y]];    // 即使grid[next_x][next_y]为0, 对于不存在的元素umap进行访问, 会有默认值0
                        visited_grid.insert(grid[next_x][next_y]);
                    }
                    if (cur_area > max_area) {
                        max_area = cur_area;
                    }
                }
            }
        }

        if (has_zero) {
            return max_area;
        }
        else {
            // 一开始就没有0
            return (grid.size() * grid[0].size());
        }
    }

    int bfs(vector<vector<int>>& grid, int x, int y, int mark) {
        queue<std::pair<int, int>> que;
        que.push({ x, y });
        grid[x][y] = mark;

        int count = 1;   // 已经放入了起点
        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || grid[next_x][next_y] != 1) {    // 只能向1扩展, 被标记的相当于已经visited
                    continue;
                }
                que.push({ next_x, next_y });
                grid[next_x][next_y] = mark;
                count++;
            }
        }

        return count;
    }

private:
    int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
};


int main()
{
    Solution solution;
    vector<vector<int>> grid = { {1, 1}, {1, 0} };
    solution.largestIsland(grid);
    return 0;
}

/*
* 运行时间839ms, 击败16.24% c++用户
* 消耗内存348.50M, 击败5.03% c++用户
*/
