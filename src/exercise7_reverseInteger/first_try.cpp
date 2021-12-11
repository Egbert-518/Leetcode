/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。

-2^31 <= x <= 2^31 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

// 不允许存储64位整数应该是指不能用long long
class Solution {
public:
    int reverse(int x) {
        if (x == INT32_MIN)
            return 0;
        int sgn = (x >= 0 ? 1 : -1);
        vector<short int> reverseNum;   // 改为short int似乎没有节省内存量

        x = x * sgn;
        while (x)
        {
            int res = x % 10;
            reverseNum.emplace_back(res);
            x = int(x / 10);
        }
        double result = 0;
        int bit = reverseNum.size();
        for (int i = 0; i < bit; i++)
        {
            result += reverseNum[i] * pow(10, bit - i - 1);
        }
        result = result * sgn;
        if (result > INT32_MAX || result < INT32_MIN)
            return 0;
        return result;
    }
};

int main()
{
    Solution solution;
    int x = INT32_MIN;
    int result = solution.reverse(x);
    cout << result << endl;
    return 0;
}
/*
* 执行用时：616 ms, 在所有 C++ 提交中击败了21.13%的用户
* 内存消耗：378.1 MB, 在所有 C++ 提交中击败了10.02%的用户
* 通过测试用例：180 / 180
*/
