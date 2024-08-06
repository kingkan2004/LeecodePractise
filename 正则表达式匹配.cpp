#include<iostream>
#include<string>
#include<regex>

using namespace std;

//方案一：直接调用c++正则匹配——头文件：regex
// 
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        return regex_match(s, regex(p));
//    }
//};

//方案二：递归
class Solution {
public:
    bool isMatch(string s, string p) {
       //先判断是否为空
        if (p.empty())
        {
            return s.empty();//字符规律为空——不返回任何字符串
        }
        bool first_match = !s.empty() && (p[0] == s[0] || p[0] == '.');
        //不为空且要么规律的第一个字符与字符串第一个字符相同，要么为'.'，表示全部

        if (p.size() > 2 && p[1] == '*')//在p长度大于2且第二个字符为'*'表示全部情况下
        {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
            //递归 返回去掉p前两个字符继续  或者 first_match成立且递归返回s去掉一个字符继续
        }
        return first_match && isMatch(s.substr(1), p.substr(1));
        //不满足p长度大于2或第2个字符不为'*',返回first_match成立且递归返回s去掉一个字符，p去掉一个字符继续
    }
};

int main()
{
    Solution sl;
    string s = "aa";
    string p = "a*";
    int result = sl.isMatch(s, p);
    if (result = 0)
    {
        cout << "faulse" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
    return 0;
}