/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
    输入：s = "()"
    输出：true

示例 2：
    输入：s = "()[]{}"
    输出：true

示例 3：
    输入：s = "(]"
    输出：false

1 <= s.length <= 10^4
s 仅由括号 '()[]{}' 组成
*/

#include <iostream>
#include <deque>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        /*左括号入栈, 右括号出栈*/
        stack<char> stack_bracket;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack_bracket.push(s[i]);
            }
            else {
                if (stack_bracket.empty()) {
                    return false;   // 没有可匹配的左括号了
                }
                char bracket = stack_bracket.top();
                stack_bracket.pop();
                if (bracket_pair(s[i]) != bracket) {
                    return false;
                }
            }
        }
        if (stack_bracket.empty()) {
            return true;
        }
        else {
            return false;
        }
    }

    char bracket_pair(char ch) {
        if (ch == ')') {
            return '(';
        }
        else if (ch == '}') {
            return '{';
        }
        else if (ch == ']') {
            return '[';
        }
        // 正常只会返回上面三种括号
        return ' ';
    }
};


int main()
{
    string s = "()";
    return 0;
}

/*
* 运行时间4ms, 击败34.79% c++用户
* 消耗内存6.59M, 击败39.33% c++用户
*/
