/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

([]) 为true

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


char pair_bracket(char ch) {
    if (ch == ')')
        return '(';
    if (ch == ']')
        return '[';
    if (ch == '}')
        return '{';
    return ' ';
}

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            // 如果不是偶数个, 直接返回false
            return false;
        }
        
        // 构建栈
        std::vector<char> stack;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                // 如果是左括号, 入栈
                stack.emplace_back(ch);
            }
            else {
                // 如果是右括号, 从栈中取出最后一个括号, 比较是否相同
                if (stack.empty())
                    return false;  // 如果没取之前, 就是空, 那肯定不行

                char stack_char = stack.back();
                if (pair_bracket(ch) == stack_char) {
                    // 相同, 则出栈
                    stack.pop_back();
                }
                else {
                    // 不同, 直接返回
                    return false;
                }
            }
        }
        // 遍历完毕, 如果栈为空, 则说明Ok
        if (stack.empty())
            return true;
        return false;

    }
};

int main() {
    Solution solution;
    std::string str = ")}";
    if (solution.isValid(str)) {
        std::cout << "is valid" << std::endl;
    }
    else {
        std::cout << "not valid" << std::endl;
    }
    return 0;
}


/*
* 执行用时：4 ms, 在所有 C++ 提交中击败了35.98%的用户
* 内存消耗：6.06MB, 在所有 C++ 提交中击败了41.87%的用户
*/
