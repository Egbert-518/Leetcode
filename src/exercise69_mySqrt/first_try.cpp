/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例1:
    输入：x = 4
    输出：2

示例 2：
    输入：x = 8
    输出：2
    解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。


0 <= x <= 2^31 - 1
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
    int mySqrt(int x) {
        int left = 0, right = x - 1;   // 用二分法确定
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                if ((mid + 1) * (mid + 1) > x) {
                    return mid;
                }
                else if ((mid + 1) * (mid + 1) == x) {
                    return mid + 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                right = mid - 1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    int result = solution.mySqrt(0);
    return 0;
}

/*
* 运行时间3ms, 击败48.57% c++用户
* 消耗内存7.42M, 击败5.26% c++用户
*/
