#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*为了实现将字符串按照 Z 字形排列并按行输出，我们可以采用以下方法：


同时使用 direction 变量来控制当前字符向上或向下移动。
遍历字符串 s，根据当前行数和方向将字符放入相应的行中。
构建输出字符串：

遍历 rows 数组，按行将字符拼接起来形成最终的输出字符串。*/

class Solution {
public:
    string convert(string s, int numRows) {
        //当 numRows 为 1 时，直接返回原始字符串，因为无需变换。
        if (numRows == 1)
        {
            return s;
        }
        //我们可以使用一个数组 rows，其中每个元素代表 Z 字形中的一行。
        vector<string>rows(min(numRows, int(s.size())));// 创建 numRows 行的字符串数组
        int currentRow = 0;//当前行
        bool goingDown = false;// 控制方向，初始为向上
        for (char c:s)
        {
            rows[currentRow] += c;// 把当前字符加入当前行
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;// 到达 Z 字形的拐点时，改变方向
            }
            currentRow += goingDown ? 1 : -1;// 根据方向移动到下一行
        }
        string result;
        for (string row:rows)
        {
            result += row; // 把每一行拼接起来
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