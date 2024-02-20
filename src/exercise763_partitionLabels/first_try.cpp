/*
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。

示例 1：
    输入：s = "ababcbacadefegdehijhklij"
    输出：[9,7,8]
    解释：
    划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
    每个字母最多出现在一个片段中。
    像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。

示例 2:
    输入：s = "eccbbbbdec"
    输出：[10]


1 <= s.length <= 500
s 仅由小写英文字母组成
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
    vector<int> partitionLabels(string s) {
        vector<std::pair<string, unordered_set<char>>> stack;
        for (int i = 0; i < s.length(); i++)
        {
            int pos = -1;
            for (int j = 0; j < stack.size(); j++)
            {
                if (stack[j].second.find(s[i]) != stack[j].second.end()) {
                    // 如果在曾经的集合中有
                    pos = j;
                    break;
                }
            }

            if (pos != -1) {
                // 将pos之后的元素合并, 需要将string相加, set相加
                string str = stack[pos].first;
                unordered_set<char> set = stack[pos].second;
                for (int k = pos + 1; k < stack.size(); k++)
                {
                    str = str + stack[k].first;
                    for (auto value : stack[k].second)
                    {
                        set.insert(value);
                    }
                }
                // 再加上本元素
                str = str + s[i];
                set.insert(s[i]);
                // 擦除pos到末尾的元素
                stack.erase(stack.begin() + pos, stack.end());
                // 加入新合并的元素
                std::pair<string, unordered_set<char>> pair(str, set);
                stack.emplace_back(pair);
            }
            else {
                // 如果以往的元素中都没有, 则新建
                unordered_set<char> set;
                set.insert(s[i]);
                string str;
                str = str + s[i];
                std::pair<string, unordered_set<char>> pair(str, set);
                stack.emplace_back(pair);
            }
        }

        vector<int> result;
        for (int i = 0; i < stack.size(); i++)
        {
            result.push_back(stack[i].first.length());
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = solution.partitionLabels(s);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}

/*
* 运行时间119ms, 击败6.77％ c++用户
* 消耗内存58.20M, 击败5.02% c++用户
*/
