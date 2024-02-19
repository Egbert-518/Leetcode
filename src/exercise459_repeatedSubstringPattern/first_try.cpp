/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

示例 1：
    输入: s = "abab"
    输出: true
    解释: 可由子串 "ab" 重复两次构成。

示例 2：
    输入: s = "aba"
    输出: false

示例 1：
    输入: s = "abcabcabcabc"
    输出: true
    解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

1 <= s.length <= 10^4
s 由小写英文字母组成
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.length(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        /*代码随想录中提供了一种不使用KMP方法的简单做法, 就是将s前后拼接为t = s + s, 去掉t的首尾字符, 在剩余的t中若能找到s, 则是可重复子串*/
        /*而利用KMP的思想, 在由重复字串组成的字符串中, 找到最长公共前后缀t, 字串设为x, 则s = n * x, t = m * x, 必有m == n - 1*/

        int* next = new int[s.length()];
        getNext(next, s);

        if (next[s.length() - 1] != -1 && (s.length() % (s.length() - (next[s.length() - 1] + 1))) == 0) {
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
    string s = "abaababaab";
    if (solution.repeatedSubstringPattern(s)) {
        std::cout << "can repeat\n";
    }
    else {
        std::cout << "can not repeat\n";
    }
    return 0;
}

/*
* 运行时间16ms, 击败87.58% c++用户
* 消耗内存12.64M, 击败27.12% c++用户
*/
