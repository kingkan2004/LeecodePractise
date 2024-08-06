#include<iostream>
#include<string>
#include<regex>

using namespace std;

//����һ��ֱ�ӵ���c++����ƥ�䡪��ͷ�ļ���regex
// 
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        return regex_match(s, regex(p));
//    }
//};

//���������ݹ�
class Solution {
public:
    bool isMatch(string s, string p) {
       //���ж��Ƿ�Ϊ��
        if (p.empty())
        {
            return s.empty();//�ַ�����Ϊ�ա����������κ��ַ���
        }
        bool first_match = !s.empty() && (p[0] == s[0] || p[0] == '.');
        //��Ϊ����Ҫô���ɵĵ�һ���ַ����ַ�����һ���ַ���ͬ��ҪôΪ'.'����ʾȫ��

        if (p.size() > 2 && p[1] == '*')//��p���ȴ���2�ҵڶ����ַ�Ϊ'*'��ʾȫ�������
        {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
            //�ݹ� ����ȥ��pǰ�����ַ�����  ���� first_match�����ҵݹ鷵��sȥ��һ���ַ�����
        }
        return first_match && isMatch(s.substr(1), p.substr(1));
        //������p���ȴ���2���2���ַ���Ϊ'*',����first_match�����ҵݹ鷵��sȥ��һ���ַ���pȥ��һ���ַ�����
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