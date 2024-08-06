#include<iostream>
#include<string>
#include<sstream>//stringstream 定义于头文件 <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        stringstream stream(s);
        //stringstream 是 C++  提供的专门用于处理字符串的 输入输出 流类
        //在C++中，将数据从一个对象到另一个对象的流动抽象为“流”
        int result = 0;
        stream >> result;
        return result;

    }
};

int main()
{
    string m = " 1234-Hello world";
    Solution s;
    cout << s.myAtoi(m) << endl;
    return 0;
}