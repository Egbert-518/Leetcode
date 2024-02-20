/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例1:
    输入：n = 12
    输出：3
    解释：12 = 4 + 4 + 4

示例 2：
    输入：n = 13
    输出：2
    解释：13 = 4 + 9

1 <= n <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        /*每个正整数一定可以用多个1相加表示, 所以一定存在表示, dp[j]表示数值j能够被表示的最少个完全平方数*/
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;    // 初始化, 至少需要i个1就可以表示
        }

        // 可选数值应该从1到根号n向下取整
        for (int i = 1; i <= sqrt(n); i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }
};


int main()
{
    Solution solution;
    int result = solution.numSquares(13);
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间46ms, 击败82.69% c++用户
* 消耗内存10.40M, 击败12.41% c++用户
*/
