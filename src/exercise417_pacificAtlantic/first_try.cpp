/*
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。

示例1:
    输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

示例 2：
    输入: heights = [[2,1],[1,2]]
    输出: [[0,0],[0,1],[1,0],[1,1]]


m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*基本思想是, 对每个节点进行bfs, 判断能否进入到太平洋和大西洋, 但这样会非常耗时, 时间复杂度是o(m^2*n^2)*/
        /*逆向思维, 将临近太平洋的节点逆向搜索, 对能够到达的节点做标记, 同理对大西洋也如此, 当所有标记完成后, 对某个节点若均有太平洋和大西洋的标记, 则是所求点*/
        vector<vector<bool>> pacific_visited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic_visited(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); i++)
        {
            bfs(heights, pacific_visited, i, 0);
        }
        for (int j = 0; j < heights[0].size(); j++)
        {
            bfs(heights, pacific_visited, 0, j);
        }
        for (int i = 0; i < heights.size(); i++)
        {
            bfs(heights, atlantic_visited, i, heights[0].size() - 1);
        }
        for (int j = 0; j < heights[0].size(); j++)
        {
            bfs(heights, atlantic_visited, heights.size() - 1, j);
        }

        vector<vector<int>> results;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (pacific_visited[i][j] && atlantic_visited[i][j]) {
                    results.push_back({ i, j });
                }
            }
        }
        return results;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) {
            return;
        }
        queue<std::pair<int, int>> que;
        que.push({ x, y });
        visited[x][y] = true;

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
                if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size() || visited[next_x][next_y] || heights[next_x][next_y] < heights[cur_x][cur_y]) {
                    continue;    // 逆向的时候, 需要扩展节点的高度大于等于当前节点的高度
                }
                que.push({ next_x, next_y });
                visited[next_x][next_y] = true;
            }
        }

        return;
    }

private:
    int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
};


int main()
{
    Solution solution;
    vector<vector<int>> heights = { {1, 2, 3}, {8, 9, 4}, {7, 6, 5} };
    solution.pacificAtlantic(heights);
    return 0;
}

/*
* 运行时间30ms, 击败84.16% c++用户
* 消耗内存26.80M, 击败11.49% c++用户
*/
