/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。


示例1:
    输入: s = "cbaebabacd", p = "abc"
    输出: [0,6]
    解释:
    起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
    起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

示例2:
    输入: s = "abab", p = "ab"
    输出: [0,1,2]
    解释:
    起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
    起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
    起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。


1 <= s.length, p.length <= 3 * 10^4
s 和 p 仅包含小写字母
*/


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
 

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return {};    // 字符串长度小于, 返回空
        }

        int dst[26] = {0};   // 只包含小写字母
        int src[26] = {0};   
        
        int end_idx = 0;
        for (; end_idx < p.length(); end_idx++)
        {
            dst[p[end_idx] - 'a']++;
            src[s[end_idx] - 'a']++;
        }

        std::vector<int> result;
        if (checkSame(src, dst)) {
            result.push_back(end_idx - p.length());
        }

        for (; end_idx < s.length(); end_idx++)
        {
            src[s[end_idx] - 'a']++;
            src[s[end_idx - p.length()] - 'a']--;
            if (checkSame(src, dst)) {
                result.push_back(end_idx - p.length() + 1);
            }
        }
        return result;
    }

    bool checkSame(int* src, int* dst) {
        for (int i = 0; i < 26; i++)
        {
            if (*(src + i) != *(dst + i)) {
                return false;
            }
        }
        return true;
    }
};


int main()
{   
    Solution solution;
    std::vector<int> result = solution.findAnagrams("abab", "ab");
    for(int item : result) 
    {
        std::cout << item << std::endl;
    }
    return 0;
} 

/*
* 执行时间8ms, 击败78.22%c++用户
* 内存消耗9.68M, 击败76.30%c++用户
*/