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
        // 样例中-101不是回文数, 所以负数似乎都不可能是回文?
        if (x < 0)
            return false;

        deque<int> queue;
        while (x)
        {
            queue.push_back(x % 10);
            x = x / 10;
        }
        while (queue.size() > 1)
        {
            int front = queue.front();
            int back = queue.back();
            if (front == back)
            {
                queue.pop_front();
                queue.pop_back();
            }
            else
                return false;
        }
        return true;
    }
};

/*
* 执行用时：24 ms, 在所有 C++ 提交中击败了12.15%的用户
* 内存消耗：15.1MB, 在所有 C++ 提交中击败了5.04%的用户
* 通过测试用例：11510 / 11510
*/
