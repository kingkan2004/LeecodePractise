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

        // dp[i][j] ��ʾ�ַ��� s �д����� i �� j ���Ӵ��Ƿ��ǻ��Ĵ�
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int start = 0; // ������Ӵ�����ʼλ��
        int maxLen = 1; // ������Ӵ��ĳ��ȣ�����Ϊ1�������ַ��������

        // ��ʼ�������г���Ϊ1���Ӵ����ǻ��Ĵ�
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // ��鳤��Ϊ2���Ӵ�
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1]) 
            {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // ��鳤�ȴ���2���Ӵ�
        for (int len = 3; len <= n; len++)// len ���Ӵ��ĳ���
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;// j ���Ӵ��Ľ�������
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