/*
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。

示例 1：
    输入：tokens = ["2","1","+","3","*"]
    输出：9
    解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

1 <= S.length <= 20000
S 仅由小写英文字母组成。
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*遇到数字入栈, 遇到算数表达式取出栈的两个元素运算后压栈*/
        std::stack<int> results;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+") {
                int first = results.top();
                results.pop();
                int second = results.top();
                results.pop();

                results.push(second + first);
            }
            else if (tokens[i] == "-") {
                int first = results.top();
                results.pop();
                int second = results.top();
                results.pop();

                results.push(second - first);
            }
            else if (tokens[i] == "*") {
                int first = results.top();
                results.pop();
                int second = results.top();
                results.pop();

                results.push(second * first);
            }
            else if (tokens[i] == "/") {
                int first = results.top();
                results.pop();
                int second = results.top();
                results.pop();

                results.push(second / first);
            }
            else {
                // 数字, 压栈
                results.push(atoi(tokens[i].c_str()));
            }
        }

        return results.top();
    }
};


int main()
{
    Solution solution;
    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    int result = solution.evalRPN(tokens);
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间12ms, 击败63.70% c++用户
* 消耗内存12.08M, 击败47.15% c++用户
*/

/*
逆波兰表达式：
逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
*/