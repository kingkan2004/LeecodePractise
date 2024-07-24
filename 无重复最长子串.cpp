#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution 
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int sum = 0;
		if (s.empty())
		{
			return 0;
		}
		map<char, int>data;//��ǰԪ�أ���ǰԪ���±�
		for (int start = 0, end = 0; end < s.size(); end++)
		{
			auto iter = data.find(s[end]);//�ҵ���ǰԪ��
			if (iter != data.end())
			{
				start = max(start, data[s[end]] + 1);
			}
			//û���ҵ�
			data[s[end]] = end;
			sum = max(sum, end - start + 1);
		}
		return sum;
	}
};

int main()
{
    Solution s;
	string str = "abcdefg";
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}