#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
1.合并两个有序序列
2.找中位数
*/



//1.先合并再排序


//class Solution
//{
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//    {
//        //合并得到一个有序序列
//        vector<int> result;
//        for (auto& v:nums1)
//        {
//            result.push_back(v);
//        }
//        for (auto& v : nums2)
//        {
//            result.push_back(v);
//        }
//        sort(result.begin(), result.end());//sort要有头文件
//
//        //分为奇数和偶数的情况输出中位数 
//        int len = result.size();
//        //奇数
//        if ((len + 1) % 2 == 0)
//        {
//            return result[len / 2];
//        }
//        //偶数
//        else
//        {
//            int pos = len / 2;
//            return (double)(result[pos - 1] + result[pos]) / 2;
//        }
//    }
//};



//2.归并排序


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result(nums1.size() + nums2.size());
        if (nums1.size() == 0)
        {
            copy(nums2.begin(), nums2.end(), result.begin());
        }
        else if (nums2.size() == 0)
        {
            copy(nums1.begin(), nums1.end(), result.begin());
        }
        else
        {
            merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),result.begin());//归并排序
        }
        int pos = result.size() / 2;
        return pos != 0 && result.size() % 2 == 0 ? (double)(result[pos - 1] + result[pos]) / 2 : result[pos];
    }
};

int main()
{
    Solution s;
    vector<int>nums1 = {1,2,3};
    vector<int>nums2 = { 6,8,10 };
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}