/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例1:
    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
         注意，你可以重复使用字典中的单词。

示例 3：
    输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    输出: false


1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s 和 wordDict[i] 仅由小写英文字母组成
wordDict 中的所有字符串 互不相同
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*dp[i]表示长度为i的子序列能否被表示, dp[0]=true, 这是一个排列题, 所以先遍历背包容量, 再遍历物体*/
        /*dp[i]为true的条件是, 从j=1到i遍历背包, 若dp[j]为true且从j开始长度为i-j的序列能在字典中被找到, 则dp[i]为true*/
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (!dp[j]) {    // 如果dp[j]是false, 那不用判断子序列了, 加快点速度
                    continue;
                }
                else {
                    string sub_str = s.substr(j, i - j);
                    for (string word : wordDict)
                    {
                        if (sub_str == word) {
                            dp[i] = true;
                            break;
                        }
                    }
                    if (dp[i]) {
                        break;   // 有一种方法能够拆分, 直接break掉j层循环
                    }
                }
            }
        }

        return dp[s.length()];
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间30ms, 击败5.25% c++用户
* 消耗内存15.35M, 击败21.15% c++用户
*/
