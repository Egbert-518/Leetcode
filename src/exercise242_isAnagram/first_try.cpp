/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例1:
    输入: s = "anagram", t = "nagaram"
    输出: true

1 <= s.length, t.length <= 5 * 10^4
s 和 t 仅包含小写字母
*/

#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        /*思路是, 先将s创建一个unordered_map<char, int>, 记录每个字符的出现字数, 随后遍历t中的字符, 在map中进行查找, 若没查到, 直接返回false, 若查到, 对应数值减1, 最后确定是否每个value==0*/
        std::unordered_map<char, int> map;

        for (int i = 0; i < s.length(); i++)
        {
            if (map.find(s[i]) != map.end()) {
                map[s[i]] += 1;  // 查找到, 则计数+1 
            }
            else {
                map[s[i]] = 1;   // 没查找到, 新建一个, 数量为1
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (map.find(t[i]) != map.end()) {
                map[t[i]] -= 1;   // 找到了, 计数-1
            }
            else {
                return false;     // 没找到, 一定会有不匹配的, 直接返回false
            }
        }

        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second != 0) {
                return false;    // 若计数不为0, 说明该字符数量不匹配, 返回false
            }
        }

        return true;
    }
};

int main() 
{
    Solution solution;
    string s = "anagram", t = "nagaram";

    if (solution.isAnagram(s, t)) {
        std::cout << "is anagram" << std::endl;
    }
    else {
        std::cout << "is not anagram" << std::endl;
    }

    return 0;
}

/*
* 运行时间4ms, 击败97.84％ c++用户
* 消耗内存7.73M, 击败12.28% c++用户
*/


// 由于本题只需要针对小写字母, 不一定要用unordered_map, 直接用一个长度为26的整形数组计数即可