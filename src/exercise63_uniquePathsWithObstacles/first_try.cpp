/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

示例1:
    输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    输出：2
    解释：3x3 网格的正中间有一个障碍物。
    从左上角到右下角一共有 2 条不同的路径：
    1. 向右 -> 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右 -> 向右


*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*基本和上面是一样的, 就是每次更新时乘以这个位置是否有障碍即可, 有障碍乘以(1-tij), 则为0*/
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {   // 特殊情况, 当终点或起点有障碍, 肯定不行
            return 0;
        }

        if (m == 1) {
            for (int k = 0; k < obstacleGrid[0].size(); k++)
            {
                if (obstacleGrid[0][k] == 1)
                    return 0;
            }
            return 1;
        }
        if (n == 1) {
            for (int k = 0; k < obstacleGrid.size(); k++)
            {
                if (obstacleGrid[k][0] == 1)
                    return 0;
            }
            return 1;
        }

        vector<long> col(n, 0);     // 这里不使用long在测试案例中会溢出
        vector<vector<long>> matrix(m, col);    // 这里全部初始化为0了, 因为最后一栏是有可能有遮挡的, 但有一点要注意, 如果最后一栏或最后一列中有一个障碍, 则障碍以左(或以上)均应置零, 而非1

        for (int i = n - 2; i >= 0; i--)
        {
            if (obstacleGrid[m - 1][i] == 1) {
                for (int j = i; j >= 0; j--) {
                    matrix[m - 1][j] = 0;
                }
                break;   // 前面的就不需要再计算了
            }
            else {
                matrix[m - 1][i] = 1;    // 到这里将最后一行初始化完毕
            }
        }
        for (int i = m - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][n - 1] == 1) {
                for (int j = i; j >= 0; j--) {
                    matrix[j][n - 1] = 0;
                }
                break;
            }
            else {
                matrix[i][n - 1] = 1;   // 到这里最后一列初始化完毕
            }
        }

        // 开始从末尾逐级向头开始计算可行路径条数
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                matrix[j][i] = matrix[j + 1][i] * (1 - obstacleGrid[j + 1][i]) + matrix[j][i + 1] * (1 - obstacleGrid[j][i + 1]);
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        return matrix[0][0];
    }
};


int main()
{
    return 0;
} 

/*
* 执行时间8ms, 击败13.61%c++用户
* 内存消耗8.03M, 击败28.13%c++用户
*/