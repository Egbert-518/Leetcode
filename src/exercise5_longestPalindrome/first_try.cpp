/*
给你一个字符串 s，找到 s 中最长的回文子串。

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
        {
            return s;
        }

        if (n == 2)
        {
            return s[0] == s[1] ? s : s.substr(0, 1);
        }

        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> isSub(n, vector<int>(n));        // isSub[i][j]表示s[i:j]是否为回文
        for (int i = 0; i < n; i++)
        {
            isSub[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)   // len表示子串长度从小刷到大
        {
            for (int i = 0; i < n; i++)     // i为左边界
            {
                int j = i + len - 1;        // j为右边界
                if (j >= n) 
                    break;
                if (s[i] != s[j])
                    isSub[i][j] = 0;
                else
                {
                    if (j - i + 1<= 2)
                        isSub[i][j] = 1;
                    else
                        isSub[i][j] = isSub[i + 1][j - 1];
                }
                if (isSub[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};


int main()
{
    Solution solution;
    string s = "abcda";
    string substr = solution.longestPalindrome(s);
    cout << substr << endl;
    return 0;
}

/*
* 执行用时：616 ms, 在所有 C++ 提交中击败了21.13%的用户
* 内存消耗：378.1 MB, 在所有 C++ 提交中击败了10.02%的用户
* 通过测试用例：180 / 180
*/
