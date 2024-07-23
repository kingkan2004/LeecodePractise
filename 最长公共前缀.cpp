#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        //假设第一个字符串就是最长公共子串
        string Same = strs[0];
        //遍历字符串数组
        for (int i = 0; i < strs.size(); i++) {
            //不断缩小范围
            while (strs[i].find(Same) != 0) {
                Same = Same.substr(0, Same.length() - 1);
                if (Same.empty()) {
                    return "";
                }
            }
        }
        return Same;
    }
};

int main()
{
    Solution s;
    vector<string>str = { "abcd","abcf","abdd" };
    cout << s.longestCommonPrefix(str) << endl;
    return 0;
}