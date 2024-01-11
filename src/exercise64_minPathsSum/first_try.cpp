/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。说明：每次只能向下或者向右移动一步。说明：每次只能向下或者向右移动一步。

示例1:
    输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
    输出：7
    解释：因为路径 1→3→1→1→1 的总和最小。

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*思路如下: 从终点反向计算, 更新每个位置从终点到此的最短和, 因为只能向下和向右走, 所以从最下行自右到左更新即可*/
        int m = grid.size();
        int n = grid[0].size();

        for (int i = m - 1; i >= 0; i--)
        {
            if (i == m - 1) {
                // 如果是最底下一行, 不需要做min判断
                for (int j = n - 2; j >= 0; j--)   // 注意这里是n - 2开始, 因为最下面一栏无需更新终点值
                {
                    grid[i][j] += grid[i][j + 1];
                }
            }
            else {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (j == n - 1) {
                        grid[i][j] += grid[i + 1][j];
                        continue;
                    }
                    grid[i][j] += std::min(grid[i + 1][j], grid[i][j + 1]);
                }
            }
        }

        return grid[0][0];
    }
};


int main()
{   
    vector<int> row1 = {1, 2, 3};
    vector<int> row2 = {4, 5, 6};
    vector<int> row3 = {4, 2, 1};
    vector<vector<int>> grid = {row1, row2};
    Solution solution;

    int min_path_sum = solution.minPathSum(grid);
    std::cout << min_path_sum << std::endl;

    return 0;
} 

/*
* 执行时间8ms, 击败82.27%c++用户
* 内存消耗9.75M, 击败87.35%c++用户
*/