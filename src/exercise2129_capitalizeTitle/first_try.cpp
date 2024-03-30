/*
给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 大写 ：
    如果单词的长度为 1 或者 2 ，所有字母变成小写。
    否则，将单词首字母大写，剩余字母变成小写。
请你返回 大写后 的 title 。

示例 1：
    输入：title = "capiTalIze tHe titLe"
    输出："Capitalize The Title"
    解释：
    由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。

示例 2：
    输入：title = "First leTTeR of EACH Word"
    输出："First Letter of Each Word"
    解释：
    单词 "of" 长度为 2 ，所以它保持完全小写。
    其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。

示例 3：
    输入：title = "i lOve leetcode"
    输出："i Love Leetcode"
    解释：
    单词 "i" 长度为 1 ，所以它保留小写。
    其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。

1 <= title.length <= 100
title 由单个空格隔开的单词组成，且不含有任何前导或后缀空格。
每个单词由大写和小写英文字母组成，且都是 非空 的。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    string capitalizeTitle(string title) {
        int slow = 0, fast = 0;
        for (; fast <= title.size(); fast++)
        {
            if (fast == title.size() || title[fast] == ' ') {
                if (fast - slow <= 2) {
                    // 只有2位
                    for (; slow < fast; slow++)
                    {
                        if (title[slow] >= 'A' && title[slow] <= 'Z') {
                            title[slow] = title[slow] - 'A' + 'a';
                        }
                    }
                }
                else {
                    if (title[slow] >= 'a' && title[slow] <= 'z') {
                        title[slow] = title[slow] - 'a' + 'A';
                    }
                    slow++;
                    for (; slow < fast; slow++)
                    {
                        if (title[slow] >= 'A' && title[slow] <= 'Z') {
                            title[slow] = title[slow] - 'A' + 'a';
                        }
                    }
                }
                slow++;
            }
        }
        return title;
    }
};

int main()
{
    Solution solution;
    string result = solution.capitalizeTitle("First leTTeR of EACH Word");
    std::cout << result << std::endl;
    return 0;
}

/*
* 运行时间4ms, 击败26.49% c++用户
* 消耗内存7.54M, 击败40.17% c++用户
*/
