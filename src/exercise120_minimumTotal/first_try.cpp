/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例1:
    输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    输出：11
    解释：如下面简图所示：
       2
      3 4
     6 5 7
    4 1 8 3
    自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

示例 2：
    输入：triangle = [[-10]]
    输出：-10


1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4
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
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        int min_cost = INT32_MAX;
        for (int i = 0; i < triangle.back().size(); i++)
        {
            if (triangle.back()[i] < min_cost) {
                min_cost = triangle.back()[i];
            }
        }
        return min_cost;
    }
};

int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间4ms, 击败75.92% c++用户
* 消耗内存10.71M, 击败52.68% c++用户
*/
