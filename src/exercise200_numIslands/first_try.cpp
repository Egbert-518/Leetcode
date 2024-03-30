/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例1:
    输入：grid = [
      ["1","1","1","1","0"],
      ["1","1","0","1","0"],
      ["1","1","0","0","0"],
      ["0","0","0","0","0"]
    ]
    输出：1

示例 2：
    输入：grid = [
      ["1","1","0","0","0"],
      ["1","1","0","0","0"],
      ["0","0","1","0","0"],
      ["0","0","0","1","1"]
    ]
    输出：3


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
    int numIslands(vector<vector<char>>& grid) {
        /*从一个位置1开始广度优先扩张, 直到不能扩张时结束, 再从下一个位置1且visitied为false的开始扩张, 如此往复, 直到位置1的选取到grid末端*/
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num_islands = 0;
        int x = 0, y = 0;
        while (x < grid.size() && y < grid[0].size())
        {
            if (grid[x][y] == '1' && !visited[x][y]) {
                bfs(grid, visited, x, y);
                num_islands++;
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

        return num_islands;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<std::pair<int, int>> que;
        que.push({ x, y });
        visited[x][y] = true;

        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first, cur_y = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int next_x = cur_x + direction[i][0];
                int next_y = cur_y + direction[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited[next_x][next_y] || grid[next_x][next_y] == '0') {
                    continue;
                }
                que.push({ next_x, next_y });
                visited[next_x][next_y] = true;
            }
        }
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
* 运行时间46ms, 击败10.91% c++用户
* 消耗内存22.52M, 击败6.87% c++用户
*/
