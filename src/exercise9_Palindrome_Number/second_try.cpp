/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
-2^31 <= x <= 2^31 - 1
进阶：你能不将整数转为字符串来解决这个问题吗？
*/

#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int count = 0;
        int x_ = x;
        while (x)
        {
            x /= 10;
            count++;
        }
        for (int i = 0; i < count / 2; i++)
        {
            int front = bitNum(x_, i);
            int back = bitNum(x_, count - i - 1);
            if (front != back)
                return false;
        }
        return true;
    }
    int bitNum(int x, int count) {
        while (count--)
        {
            x /= 10;
        }
        return (x % 10);
    }
};

/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了96.45%的用户
* 内存消耗：5.7MB, 在所有 C++ 提交中击败了89.03%的用户
* 通过测试用例：11510 / 11510
*/
