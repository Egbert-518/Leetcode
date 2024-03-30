/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。


示例 1：
    输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2：
    输入: strs = [""]
    输出: [[""]]

示例 3：
    输入: strs = ["a"]
    输出: [["a"]]

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母

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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, std::vector<string>> map;

        for (string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }

        std::vector<std::vector<string>> results;
        for (auto iter = map.begin(); iter != map.end(); iter++)
        {
            std::vector<string> result;
            for (string str : iter->second)
            {
                result.emplace_back(str);
            }
            results.emplace_back(result);
        }

        return results;
    }
};

int main()
{
    // Solution solution;

    return 0;
}

/*
* 运行时间33ms, 击败31.36% c++用户
* 消耗内存24.45M, 击败15.26% c++用户
*/
