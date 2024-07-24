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
		map<char, int>data;//当前元素，当前元素下标
		for (int start = 0, end = 0; end < s.size(); end++)
		{
			auto iter = data.find(s[end]);//找到当前元素
			if (iter != data.end())
			{
				start = max(start, data[s[end]] + 1);
			}
			//没有找到
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