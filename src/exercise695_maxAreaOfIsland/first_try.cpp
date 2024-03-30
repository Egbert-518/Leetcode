/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

示例1:
    输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                  [0,0,0,0,0,0,0,1,1,1,0,0,0],
                  [0,1,1,0,1,0,0,0,0,0,0,0,0],
                  [0,1,0,0,1,1,0,0,1,0,1,0,0],
                  [0,1,0,0,1,1,0,0,1,1,1,0,0],
                  [0,0,0,0,0,0,0,0,0,0,1,0,0],
                  [0,0,0,0,0,0,0,1,1,1,0,0,0],
                  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
    输出：6
    解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。

示例 2：
    输入：grid = [[0,0,0,0,0,0,0,0]]
    输出：0


m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*从一个位置1开始广度优先扩张, 直到不能扩张时结束, 再从下一个位置1且visitied为false的开始扩张, 如此往复, 直到位置1的选取到grid末端*/
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int max_area = 0;
        int x = 0, y = 0;
        while (x < grid.size() && y < grid[0].size())
        {
            if (grid[x][y] == 1 && !visited[x][y]) {
                int cur_area = bfs(grid, visited, x, y);
                if (cur_area > max_area) {
                    max_area = cur_area;
                }
            }
            else {
                if (y == grid[0].size() - 1) {
                    y = 0;
                    x = x + 1;
                }
                else {
                    y = y + 1;
                }
            }
        }

        return max_area;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<std::pair<int, int>> que;
        que.push({ x, y });
        visited[x][y] = true;
        int area = 1;

        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first, cur_y = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int next_x = cur_x + direction[i][0];
                int next_y = cur_y + direction[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited[next_x][next_y] || grid[next_x][next_y] == 0) {
                    continue;
                }
                que.push({ next_x, next_y });
                visited[next_x][next_y] = true;
                area++;
            }
        }

        return area;
    }

private:
    int direction[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间26ms, 击败14.19% c++用户
* 消耗内存31.20M, 击败7.18% c++用户
*/
