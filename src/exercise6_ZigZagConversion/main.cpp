/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        int everyZ = 2 * numRows - 2;
        int quotient = s.length() / everyZ;
        int res = s.length() % everyZ;
        string result;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < quotient; j++)
            {
                if (i == 0 || i == int(everyZ / 2))
                    result = result + s[everyZ * j + i];
                else
                {
                    result = result + s[everyZ * j + i];
                    result = result + s[everyZ * (j + 1) - i];
                }
            }
            if (int(res / (i + 1)) > 0)
            {
                if (i == 0 || i == int(everyZ / 2))
                    result = result + s[quotient * everyZ + i];
                else
                {
                    result = result + s[quotient * everyZ + i];
                    if (res - 1 >= everyZ - 1 - (i - 1))
                    {
                        result = result + s[(quotient + 1) * everyZ - i];
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "ABC";
    int numRows = 3;
    Solution solution;
    string result = solution.convert(s, numRows);
    cout << result << endl;
}

/*
* 执行用时：48 ms, 在所有 C++ 提交中击败了10.56%的用户
* 内存消耗：93 MB, 在所有 C++ 提交中击败了5.02%的用户
* 通过测试用例：1157 / 1157
*/


/*
0     6
1   5 7
2 4   8
3     9
*/