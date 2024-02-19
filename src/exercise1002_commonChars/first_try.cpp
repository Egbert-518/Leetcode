/*
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。


示例1:
    输入：words = ["bella","label","roller"]
    输出：["e","l","l"]

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 由小写英文字母组成
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*思路是, 首先将words[0]中的字符出现次数存储在一个长度为26的int数组中, 然后遍历后面每个元素的字符串, 对这个计数数组进行加减, 对于减到<=0的位置, 保留原有计数数组中的值, 对于减到>0的位置, 需要用原有计数值-当前值作为下一次用的值*/
        
        vector<int> count(26, 0);
        for (int i = 0; i < words[0].length(); i++)
        {
            count[words[0][i] - 'a']++;
        }

        vector<string> output;

        if (words.size() == 1) {
            // 如果words只有一个单词, 处理方式与其他有些不同
            for (int i = 0; i < count.size(); i++)
            {
                if (count[i] != 0) {
                    string str = "";
                    str += ('a' + i);
                    output.push_back(str);
                }
            }
        }

        else {
            for (int i = 1; i < words.size(); i++)
            {
                vector<int> count_copy = count;
                for (int j = 0; j < words[i].length(); j++)
                {
                    count_copy[words[i][j] - 'a']--;
                }

                for (int k = 0; k < count.size(); k++)
                {
                    if (count_copy[k] <= 0) {   
                        continue;     // 说明这个字母减掉的更多了, 保留原始计数中的数量
                    }
                    else {
                        count[k] = count[k] - count_copy[k];    // 留下来的值为非共有个数, 所以更新为原有数值 - 现有数值 = 公共个数
                    }
                }
            }

            for (int i = 0; i < count.size(); i++)
            {
                while (count[i] != 0)
                {
                    string str = "";
                    str += ('a' + i);
                    output.push_back(str);
                    count[i]--;
                }
            }
        }

        return output;
    }
};

int main() 
{
    vector<string> words = { "bella", "label", "roller"};
    Solution solution;
    vector<string> output = solution.commonChars(words);
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << std::endl;
    }
    return 0;
}

/*
* 运行时间8ms, 击败68.48％ c++用户
* 消耗内存9.59M, 击败33.77% c++用户
*/
