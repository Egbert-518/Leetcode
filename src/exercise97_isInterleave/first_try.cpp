/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空子字符串：
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...

注意：a + b 意味着字符串 a 和 b 连接。

示例1:
    输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    输出：true

示例 2：
    输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    输出：false

示例 3：
    输入：s1 = "", s2 = "", s3 = ""
    输出：true

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1、s2、和 s3 都由小写英文字母组成

进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
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
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), p = s3.size();
        if (m + n != p) {
            return false;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));    // dp[i][j]表示s1中前i个与s2中j个是否能与s3中前i+j个形成交错字符串
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i > 0) {
                    if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                }
                if (j > 0) {
                    if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[m][n];
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间2ms, 击败75.42% c++用户
* 消耗内存8.04M, 击败32.57% c++用户
*/
