/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例1:
    输入: numRows = 5
    输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2：
    输入: numRows = 1
    输出: [[1]]


1 <= numRows <= 30
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
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return { {1} };
        }
        else if (numRows == 2) {
            return { {1}, {1, 1} };
        }
        vector<vector<int>> result(numRows, vector<int>());
        result[0] = { 1 };
        result[1] = { 1, 1 };
        for (int i = 2; i < numRows; i++)
        {
            result[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间3ms, 击败35.55% c++用户
* 消耗内存7.91M, 击败5.77% c++用户
*/
