/*
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

示例1:
    输入: word1 = "sea", word2 = "eat"
    输出: 2
    解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

示例2:
    输入：word1 = "leetcode", word2 = "etco"
    输出：4

1 <= word1.length, word2.length <= 500
word1 和 word2 只包含小写英文字母
*/


#include <iostream>
#include <vector>
using namespace std;
 

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*想法是求出word1与word2的最长公共自序列长度l, 则答案为word1.length() + word2.length() - 2l*/
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return word1.length() + word2.length() - 2 * dp[word1.length()][word2.length()];
    }
};


int main()
{   

    return 0;
} 

/*
* 执行时间11ms, 击败90.79%c++用户
* 内存消耗15.16M, 击败10.38%c++用户
*/