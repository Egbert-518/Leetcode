/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例1:
    输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

示例 2：
    输入：board = [["X"]]
    输出：[["X"]]


m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
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
    void solve(vector<vector<char>>& board) {
        /*从一个位置1开始广度优先扩张, 直到不能扩张时结束, 再从下一个位置1且visitied为false的开始扩张, 如此往复, 直到位置1的选取到grid末端*/
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int x = 0, y = 0;
        while (x < board.size() && y < board[0].size())
        {
            if (board[x][y] == 'O' && !visited[x][y]) {
                bfs(board, visited, x, y);
            }
            else {
                if (y == board[0].size() - 1) {
                    y = 0;
                    x = x + 1;
                }
                else {
                    y = y + 1;
                }
            }
        }
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        vector<std::pair<int, int>> vec;   // 用来存储此次遍历的下标
        queue<std::pair<int, int>> que;
        que.push({ x, y });
        vec.push_back({ x, y });
        visited[x][y] = true;
        int min_left = y, min_top = x, max_right = y, max_bottom = x;

        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first, cur_y = cur.second;
            for (int i = 0; i < 4; i++)
            {
                int next_x = cur_x + direction[i][0];
                int next_y = cur_y + direction[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || visited[next_x][next_y] || grid[next_x][next_y] == 'X') {
                    continue;
                }
                que.push({ next_x, next_y });
                vec.push_back({ next_x, next_y });
                visited[next_x][next_y] = true;
                if (next_y < min_left) {
                    min_left = next_y;
                }
                if (next_y > max_right) {
                    max_right = next_y;
                }
                if (next_x < min_top) {
                    min_top = next_x;
                }
                if (next_x > max_bottom) {
                    max_bottom = next_x;
                }
            }
        }

        if (min_left == 0 || min_top == 0 || max_right == grid[0].size() - 1 || max_bottom == grid.size() - 1) {
            // 如果能到达边界, 则这一部分均可以到达
            return;
        }
        else {
            for (std::pair<int, int> ele : vec)
            {
                grid[ele.first][ele.second] = 'X';
            }
            return;
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
* 运行时间18ms, 击败16.48% c++用户
* 消耗内存15.59M, 击败10.21% c++用户
*/
