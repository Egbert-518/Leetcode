/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例1:
    输入：s = "abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"

示例 2：
    输入：s = "aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

1 <= s.length <= 1000
s 由小写英文字母组成
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
    int countSubstrings(string s) {
        /*和最长回文字串一样, 只是计数的地方不一样*/
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true;
            count++;
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*
* 运行时间38ms, 击败14.74% c++用户
* 消耗内存10.00M, 击败21.88% c++用户
*/
