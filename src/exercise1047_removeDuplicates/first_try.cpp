/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例 1：
    输入："abbaca"
    输出："ca"
    解释：
    例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

1 <= S.length <= 20000
S 仅由小写英文字母组成。
*/

#include <iostream>
#include <deque>
#include <stack>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        /*考虑堆栈, 遍历s, 当栈非空时, 判断s[i]与栈的top是否相同, 相同则pop, 且不入栈, 否则入栈; 当栈为空时直接入栈*/
        deque<char> stack_str;

        for (int i = 0; i < s.length(); i++)
        {
            if (stack_str.empty()) {
                stack_str.push_back(s[i]);
            }
            else {
                char top = stack_str.back();
                if (top == s[i]) {
                    stack_str.pop_back();
                }
                else {
                    stack_str.push_back(s[i]);
                }
            }
        }
        string out_str = "";
        // 使用双端队列就不需要考虑从栈底拿数据了
        while (!stack_str.empty())
        {
            out_str += stack_str.front();
            stack_str.pop_front();
        }
        return out_str;
    }
};


int main()
{
    string s = "()";
    return 0;
}

/*
* 运行时间32ms, 击败31.54% c++用户
* 消耗内存11.83M, 击败17.51% c++用户
*/
