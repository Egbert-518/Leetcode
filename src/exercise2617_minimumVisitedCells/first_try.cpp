/*
给你一个下标从 0 开始的 m x n 整数矩阵 grid 。你一开始的位置在 左上角 格子 (0, 0) 。

当你在格子 (i, j) 的时候，你可以移动到以下格子之一：
    满足 j < k <= grid[i][j] + j 的格子 (i, k) （向右移动），或者
    满足 i < k <= grid[i][j] + i 的格子 (k, j) （向下移动）。
请你返回到达 右下角 格子 (m - 1, n - 1) 需要经过的最少移动格子数，如果无法到达右下角格子，请你返回 -1 。


示例 1：
    输入：grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
    输出：4
    解释：上图展示了到达右下角格子经过的 4 个格子。

示例 2：
    输入：grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
    输出：3
    解释：上图展示了到达右下角格子经过的 3 个格子。

示例 3：
    输入：grid = [[2,1,0],[1,0,0]]
    输出：-1
    解释：无法到达右下角格子。

m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
0 <= grid[i][j] < m * n
grid[m - 1][n - 1] == 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 200000));

        // 先初始化最后一行
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1) {
                dp[m - 1][i] = 0;    // 就是终点位置
            }
            else {
                for (int j = i + 1; j <= i + grid[m - 1][i] && j < n; j++)    // 从这个点的右边开始寻找, 寻找长度为这个点能够移动的最大长度或者寻找到头
                {
                    dp[m - 1][i] = min(dp[m - 1][i], 1 + dp[m - 1][j]);    // 当前最小, 或者是移动到j位置再跳到终点中的最小值
                }
            }
        }
        // 再初始化最后一列
        for (int i = m - 1; i >= 0; i--)
        {
            if (i == m - 1) {
                dp[i][n - 1] = 0;   // 终点
            }
            else {
                for (int j = i + 1; j <= i + grid[i][n - 1] && j < m; j++)   // 从这个点的下面开始寻找, 寻找长度为这个点能够移动的最大长度或者寻找到头
                {
                    dp[i][n - 1] = min(dp[i][n - 1], 1 + dp[j][n - 1]);
                }
            }
        }

        // 初始化完毕, 从后遍历为各个点分配最小值
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                for (int k = i + 1; k <= i + grid[i][j] && k < m; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j]);
                }
                for (int k = j + 1; k <= j + grid[i][j] && k < n; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k]);
                }
            }
        }

        if (dp[0][0] >= 200000) {
            return -1;
        }
        return 1 + dp[0][0];    // dp[i][j]表示要跳几次, 答案要求是经过几个格子, 所以加一
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> grid = { {3, 4, 2, 1},{4, 2, 3, 1},{2, 1, 0, 0},{2, 4, 0, 0} };
    solution.minimumVisitedCells(grid);
    return 0;
}

/*
* 困难题, 超过时间限制1052/1069, 至少证明思路是对的
*/
