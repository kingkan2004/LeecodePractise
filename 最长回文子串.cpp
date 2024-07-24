#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        // dp[i][j] 表示字符串 s 中从索引 i 到 j 的子串是否是回文串
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int start = 0; // 最长回文子串的起始位置
        int maxLen = 1; // 最长回文子串的长度，至少为1（单个字符的情况）

        // 初始化：所有长度为1的子串都是回文串
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // 检查长度为2的子串
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1]) 
            {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // 检查长度大于2的子串
        for (int len = 3; len <= n; len++)// len 是子串的长度
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;// j 是子串的结束索引
                if (s[i]==s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    Solution s;
    string str = "ccc";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}