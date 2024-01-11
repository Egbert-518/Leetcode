/*
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例1
    输入：n = 3
    输出：[[1,2,3],[8,9,4],[7,6,5]]
    解释: 1-2-3
             |
         8-9 4
         |   |
         7-6-5

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /*不能乱, 要坚持统一性原则, 不能一行画n个, 一行画n-2个, 必须统一, 对每一行每一列, 都画n - (2 * i - 1)个, 其中i为第几层*/
        int cur_paint = 1;
        vector<int> row(n, 0);
        vector<vector<int>> results(n, row);

        for (int layer = 0; layer < n / 2; layer++)    // 只可能画layer / 2层, 对于偶数层刚好画完, 奇数层差中间一个点
        {
            for (int kk = layer; kk < n - 1 - layer; kk++)   // 这样共画了n - 1 - layer - layer = n - (2 * layer + 1)个, 符合
            {
                results[layer][kk] = cur_paint++;
            }
            // 画4遍会不会浪费时间?
            for (int kk = layer; kk < n - 1 - layer; kk++)
            {
                results[kk][n - 1 - layer] = cur_paint++;
            }
            for (int kk = layer; kk < n - 1 - layer; kk++)
            {
                results[n - 1 - layer][n - 1 - kk] = cur_paint++;
            }
            for (int kk = layer; kk < n - 1 - layer; kk++)
            {
                results[n - 1 - kk][layer] = cur_paint++;
            }
        }

        if (cur_paint == n * n) {
            // 说明中心点没画
            results[n / 2][n / 2] = cur_paint;
        }
        return results;
    }
};

int main()
{   
    Solution solution;
    vector<vector<int>> result = solution.generateMatrix(5);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
} 

/*
* 执行时间0ms, 击败100.00%c++用户
* 内存消耗6.71M, 击败89.54%c++用户
*/