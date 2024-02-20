/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

示例1:
    输入：n = 3
    输出：5

示例 2：
    输入：n = 1
    输出：1

1 <= n <= 19
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
    int numTrees(int n) {
        /*dp[i]表示i个节点的二叉搜索树数量, 其等于将第i个节点放在根节点, 然后把i - 1个节点放在左边的情况数量, 加上把i - 1节点放在根节点, 然后把i - 2个节点放在左边情况乘以1个节点放在右边情况的数量, 再加上...*/
        /*所以dp[i] = dp[i-1]*dp[0] + dp[i-2]*dp[1]+...+dp[0]*dp[i-1] */
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution solution;
    int result = solution.numTrees(4);
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间3ms, 击败26.67% c++用户
* 消耗内存7.08M, 击败9.20% c++用户
*/
