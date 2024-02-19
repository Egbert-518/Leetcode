/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

示例 1：
    输入：m = 3, n = 2
    输出：3
    解释：
    从左上角开始，总共有 3 条路径可以到达右下角。
    1. 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右
    3. 向下 -> 向右 -> 向下

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10^9
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        /*考虑递归?f(m, n) = f(m - 1, n) + f(m, n - 1), 且f(m, 1) = 1, f(1, n) = 1, 即到边界只有一条路可走*/
        /*递归速度太慢, 新想法如下, 从右下角记录每个点到达的情况种数, 一直到左上角*/
        /*         10 4 1
                   6 3 1
                   3 2 1
        1 1 1 1 ...1 1 0
        */
        if (m == 1 || n == 1)
            return 1;

        vector<int> col(n, 1);
        vector<vector<int>> matrix(m, col);    // 这样这个矩阵就全是1, 但没关系, 右下角虽然是0但不会被用到, 其他值会被更新
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                matrix[j][i] = matrix[j + 1][i] + matrix[j][i + 1];
            }
        }

        return matrix[0][0];
    }
};


int main() 
{
    Solution solution;
    int unique_path = solution.uniquePaths(7, 3);
    std::cout << unique_path << std::endl;
    return 0;
}

/*
* 运行时间4ms, 击败29.56％ c++用户
* 消耗内存6.7M, 击败40.35% c++用户
*/
