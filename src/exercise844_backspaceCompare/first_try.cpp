/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例1:
    输入：s = "ab#c", t = "ad#c"
    输出：true
    解释：s 和 t 都会变成 "ac"。

示例 2：
    输入：s = "ab##", t = "c#d#"
    输出：true
    解释：s 和 t 都会变成 ""。

示例 3：
    输入：s = "a#c", t = "b"
    输出：false
    解释：s 会变成 "c"，但 t 仍然是 "b"。

1 <= s.length, t.length <= 200
s 和 t 只含有小写字母以及字符 '#'

你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st_s;
        stack<char> st_t;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '#') {
                st_s.push(s[i]);
            }
            if (!st_s.empty() && s[i] == '#') {
                st_s.pop();
            }
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '#') {
                st_t.push(t[i]);
            }
            if (!st_t.empty() && t[i] == '#') {
                st_t.pop();
            }
        }

        while (!st_s.empty() && !st_t.empty())
        {
            if (st_s.top() != st_t.top()) {
                return false;
            }
            st_s.pop();
            st_t.pop();
        }

        if (st_s.empty() && st_t.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间4ms, 击败33.48% c++用户
* 消耗内存7.62M, 击败5.08% c++用户
*/
