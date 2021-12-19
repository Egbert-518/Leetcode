/*
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
给你一个整数，将其转为罗马数字。

1 <= num <= 3999
*/

#include <iostream>
#include <map>
using namespace std;

struct myMap {
    int first;
    string second;
};

myMap map_[] = { 
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

class Solution {
public:
    string intToRoman(int num) {
        
        string s = "";
        while (num)
        {
            s = s + addS(num);
        }
        return s;
    }

    string addS(int &num) {    // 如果有小于当前数值的, 把他减去, 并把对应的字符加上, 二分查找应该没必要,o(n)和o(logn), 查找范围比较短, 不值
        for (auto it : map_)
        {
            if (it.first <= num)
            {
                num -= it.first;
                return it.second;
            }
        }
        return "";
    }
};

/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了85.10%的用户
* 内存消耗：5.9MB, 在所有 C++ 提交中击败了48.17%的用户
* 通过测试用例：3999 / 3999
*/
