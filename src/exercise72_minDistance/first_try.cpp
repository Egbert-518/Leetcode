/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符

示例1:
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')

示例2:
    输入：word1 = "intention", word2 = "execution"
    输出：5
    解释：
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')


0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/


#include <iostream>
#include <vector>
using namespace std;
 

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*dp[i][j]表示word1中前i - 1个元素与word2中前j - 1个元素至少需要多少次才能相同*/
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 0; i <= word1.length(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.length(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];     // 若这个字符相同, 则不需要操作
                }
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;    // 否则, 可以从word1中增加一个, 或者word2中增加一个, 或者变动一个, word1增加等价于word2删除
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};


int main()
{   

    return 0;
} 

/*
* 执行时间7ms, 击败85.33%c++用户
* 内存消耗11.82M, 击败5.74%c++用户
*/