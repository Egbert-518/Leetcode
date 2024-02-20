/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。

示例1:
    输入: n = 2
    输出: 1
    解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2：
    输入: n = 10
    输出: 36
    解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。


2 <= n <= 58
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
    int integerBreak(int n) {
        /*利用一些数学的知识, 首先对于个数k来说, 一定是平均能够使得乘积最大, 且一旦递减就不会超过当前值*/
        int k = 2;
        int max_result = INT32_MIN;
        while (true)
        {
            int res = n % k;
            int result = 1;
            for (int i = 0; i < k; i++)
            {
                if (i < res) {
                    result = result * (n / k + 1);
                }
                else {
                    result = result * (n / k);
                }
            }
            if (result > max_result) {
                max_result = result;
                k++;
            }
            else {
                break;
            }
        }
        return max_result;
    }
};


int main()
{
    Solution solution;
    int max_result = solution.integerBreak(10);
    std::cout << max_result << std::endl;
    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存7.00M, 击败23.44% c++用户
*/
