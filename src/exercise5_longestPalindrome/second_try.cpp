/*
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

示例1:
    输入：s = "babad"
    输出："bab"
    解释："aba" 同样是符合题意的答案。

示例 2：
    输入：s = "cbbd"
    输出："bb"

1 <= s.length <= 1000
s 仅由数字和英文字母组成
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
    string longestPalindrome(string s) {
        /*最简单的方法是对于每个位置向外两边扩, 遇到不同的停下, 记录最长的位置, 这是o(n^2)*/
        /*dp[i][j]为下标i到下标j是否为回文串, 虽然利用了动态规划思想, 但还是o(n^2)*/
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int max_len = 1, left_idx = 0, right_idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true;
        }
        for (int i = s.length() - 1; i >= 0; i--)    // i需要从尾部开始往前填充
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (j == i + 1) {
                    // 前后两个的
                    if (s[j] == s[i]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    if (s[j] == s[i] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    left_idx = i;
                    right_idx = j;
                }
            }
        }
        return s.substr(left_idx, max_len);
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*
* 运行时间325ms, 击败28.35% c++用户
* 消耗内存24.80M, 击败45.73% c++用户
*/
