#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*Ϊ��ʵ�ֽ��ַ������� Z �������в�������������ǿ��Բ������·�����


ͬʱʹ�� direction ���������Ƶ�ǰ�ַ����ϻ������ƶ���
�����ַ��� s�����ݵ�ǰ�����ͷ����ַ�������Ӧ�����С�
��������ַ�����

���� rows ���飬���н��ַ�ƴ�������γ����յ�����ַ�����*/

class Solution {
public:
    string convert(string s, int numRows) {
        //�� numRows Ϊ 1 ʱ��ֱ�ӷ���ԭʼ�ַ�������Ϊ����任��
        if (numRows == 1)
        {
            return s;
        }
        //���ǿ���ʹ��һ������ rows������ÿ��Ԫ�ش��� Z �����е�һ�С�
        vector<string>rows(min(numRows, int(s.size())));// ���� numRows �е��ַ�������
        int currentRow = 0;//��ǰ��
        bool goingDown = false;// ���Ʒ��򣬳�ʼΪ����
        for (char c:s)
        {
            rows[currentRow] += c;// �ѵ�ǰ�ַ����뵱ǰ��
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;// ���� Z ���εĹյ�ʱ���ı䷽��
            }
            currentRow += goingDown ? 1 : -1;// ���ݷ����ƶ�����һ��
        }
        string result;
        for (string row:rows)
        {
            result += row; // ��ÿһ��ƴ������
        }
        return result;
    }
};

int main()
{
    Solution so;
    string s = "abcdefg";
    cout << so.convert(s, 3) << endl;
    return 0;
}