#include<iostream>
#include<string>
#include<sstream>//stringstream ������ͷ�ļ� <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        stringstream stream(s);
        //stringstream �� C++  �ṩ��ר�����ڴ����ַ����� ������� ����
        //��C++�У������ݴ�һ��������һ���������������Ϊ������
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