/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。


示例1:
    输入: temperatures = [73,74,75,71,69,72,76,73]
    输出: [1,1,4,2,1,1,0,0]

示例2:
    输入: temperatures = [30,40,50,60]
    输出: [1,1,1,0]

示例3:
    输入: temperatures = [30,60,90]
    输出: [1,1,0]

1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*用两层for循环可暴力解, 但这种求某元素左边或右边第一个大于或小于它的元素时, 可以使用O(n)的单调栈*/
        vector<int> results(temperatures.size(), 0);
        
        stack<int> st;
        st.push(0);   // 初始化, 将元素下标存入到栈中

        for (int i = 1; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) 
            {
                // 如果当前温度超过单调栈的栈顶
                results[st.top()] = i - st.top();
                st.pop();
            }

            // 其他情况, 入栈, 这样能保证栈顶是小的
            st.push(i);
        }

        return results;
    }
};


int main()
{   
    Solution solution;

    return 0;
} 

/*
* 执行时间125ms, 击败84.29%c++用户
* 内存消耗102.84M, 击败31.80%c++用户
*/