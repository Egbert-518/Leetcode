/*
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

示例 1：
    输入: n = 10
    输出: 9

示例 2:
    输入: n = 1234
    输出: 1234

示例 3:
    输入: n = 332
    输出: 299

0 <= n <= 10^9
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
    int monotoneIncreasingDigits(int n) {
        /*从前往后看, 找到当前位比下一位小时, 看当前位与前一位是否相等, 若相等, 再往前找直到找到不相等或首位, 对该位-1, 后续全给9; 若不相等, 则该位直接-1, 后面全给9*/
        vector<int> results;   // 用来储存每一位的结果

        while (n > 0)
        {
            int result = n % 10;   // 个位
            n = n / 10;
            results.emplace_back(result);    // 从后往前存储
        }

        for (int i = results.size() - 1; i >= 1; i--)
        {
            if (results[i] > results[i - 1]) {
                // 当前位比下一位要大
                int j = i;
                for (; j < results.size() - 1; j++)
                {
                    if (results[j] == results[j + 1]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }

                // j位置数值-1, 后面全变9
                results[j] = results[j] - 1;
                for (int k = j - 1; k >= 0; k--)
                {
                    results[k] = 9;
                }
                break;  // 跳出最外层循环
            }
        }

        // 开始求和
        int base = 1, sum = 0;     // leetcode中需要用long存储
        for (int i = 0; i < results.size(); i++)
        {
            sum += results[i] * base;
            base *= 10;
        }

        return sum;
    }
};

int main()
{
    Solution solution;
    int result = solution.monotoneIncreasingDigits(1000000000);
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存7.30M, 击败5.20% c++用户
*/
