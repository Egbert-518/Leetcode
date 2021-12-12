/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。



0 <= s.length <= 200
s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成
*/

#include <iostream>
#include <vector>
using namespace std;

enum State {
    nbsp,
    sgn,
    num
};

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        State state = State::nbsp;
        int sign = 1;
        double result = 0;

        for (int i = 0; i < n; i++)
        {
            if (state == State::nbsp)
            {
                if (s[i] == ' ')
                    continue;      // 读入前导空格
                else
                {
                    state = sgn;   // 非空格, 状态机进入读符号, 下标-1重新检测当前值
                    i--;
                }
            }
            else if (state == sgn)
            {
                if (s[i] == '-')
                {
                    sign = -1;
                    state = num;
                }
                else if (s[i] == '+')
                {
                    sign = 1;
                    state = num;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    sign = 1;
                    state = num;
                    i--;
                }
                else
                {
                    return 0;
                }
            }
            else if (state == num)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    result = 10 * result + (s[i] - 0x30);
                }
                else
                {
                    break;
                }
            }
        }
        result = result * sign;
        if (result > INT32_MAX)
            return INT32_MAX;
        else if (result < INT32_MIN)
            return INT32_MIN;
        else
            return int(result);
    }
};

int main()
{
    Solution solution;
    string s = "-91283472332";
    int result = solution.myAtoi(s);
    cout << result << endl;
    return 0;
}
/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了70.59%的用户
* 内存消耗：6.8MB, 在所有 C++ 提交中击败了84.15%的用户
* 通过测试用例：1082 / 1082
*/
