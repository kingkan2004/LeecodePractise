#include<iostream>
#include<deque>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(int x) {
        if (x <= 0)
        {
            return false;
        }
        deque<char>dq;
        string s = intToString(x); // 手动实现整数转字符串

        for (char c: s) {
            dq.push_back(c);
        }
        while (dq.size() > 1)
        {
            if (dq.front() != dq.back())
            {
                return false;
            }
            dq.pop_front();
            dq.pop_back();
        }
        return true;
    }
private:
    string intToString(int x) {
        string s;
        while (x > 0)
        {
            s.insert(s.begin(), '0' + x % 10);
            x /= 10;
        }
        return s.empty() ? "0" : s;
    }
};

int main()
{
    Solution su;
    int num;
    cin >> num;
    bool result = su.isPalindrome(num);
    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
  
    return 0;
}