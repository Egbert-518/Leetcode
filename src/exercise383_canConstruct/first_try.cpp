/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例1：
    输入：ransomNote = "a", magazine = "b"
    输出：false

1 <= ransomNote.length, magazine.length <= 10^5
ransomNote 和 magazine 由小写英文字母组成
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*构建hash表即可, 或者数组也行, 因为只有小写英文字母*/
        vector<int> count(26, 0);
        for (int i = 0; i < magazine.length(); i++)
        {
            count[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            count[ransomNote[i] - 'a']--;
            if (count[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};


int main() 
{


    return 0;
}

/*
* 运行时间12ms, 击败80.19％ c++用户
* 消耗内存8.83M, 击败84.52% c++用户
*/
