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
        //�����һ���ַ�������������Ӵ�
        string Same = strs[0];
        //�����ַ�������
        for (int i = 0; i < strs.size(); i++) {
            //������С��Χ
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