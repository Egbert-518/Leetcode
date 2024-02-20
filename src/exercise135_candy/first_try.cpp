/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

示例 1：
    输入：ratings = [1,0,2]
    输出：5
    解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

示例 2:
    输入：ratings = [1,2,2]
    输出：4
    解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
         第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。


n == ratings.length
1 <= n <= 2 * 10^4
0 <= ratings[i] <= 2 * 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        /*分别考虑两边, 先考虑从左到右, 再考虑从右到左*/
        vector<int> candyVec(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int i = 0; i < candyVec.size(); i++)
        {
            sum = sum + candyVec[i];
        }
        return sum;
    }
};

int main()
{

    return 0;
}

/*
* 运行时间19ms, 击败48.59％ c++用户
* 消耗内存19.64M, 击败14.34% c++用户
*/
