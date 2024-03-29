﻿/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。

*/

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> map_ = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};


class Solution {
public:
    int romanToInt(string s) {
        int curMax = 0, result = 0;
        while (!s.empty()){
            int temp = map_.find(s.back())->second;
            curMax = max(curMax, temp);
            if (temp < curMax) {
                result -= temp;
            }
            else {
                result += temp;
            }
            s.pop_back();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    cout << result << endl;
    return 0;
}
/*
* 执行用时：8 ms, 在所有 C++ 提交中击败了83.19%的用户
* 内存消耗：6.1MB, 在所有 C++ 提交中击败了67.28%的用户
* 通过测试用例：3999 / 3999
*/
