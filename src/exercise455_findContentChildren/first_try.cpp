class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g是孩子胃口, s是饼干
        sort(g.begin(), g.end());    // 默认从小到大排序
        sort(s.begin(), s.end());

        int count = 0;
        while (!g.empty() && !s.empty())
        {
            int g_value = g.back();
            int s_value = s.back();
            if (s_value >= g_value) {    // 因为已经经过排序, 所以这是当前最大胃口的孩子和最大的饼干, 这样做不会浪费
                s.pop_back();
                g.pop_back();
                count++;
            }
            else {
                g.pop_back();
            }
        }

        return count;
    }
};