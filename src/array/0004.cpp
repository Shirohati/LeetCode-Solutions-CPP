/*
题目：给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
要点：根据中位数的定义——中位数左边的所有数小于中位数，中位数右边的所有数大于中位数，且左右两边个数相等（在这里是相等或左边多1）
算法思路：通过在两个数组中分别建立一个边界，记为mid1，mid2，边界左边的最大值小于边界右边的最大值，通过二分法调整边界；
    因为要维持个数相等，对mid1移动n个单位就要对mid2反向移动n个单位，所以在较短数组上操作即可，方便确立边界，防止移动越界
难点：边界的处理
时间复杂度：O(log(min(m,n)))
*/

#include<iostream>
#include<stack>
#include <cstdlib> 
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())swap(nums1,nums2);//保证在较小数组上进行操作
        int n1,n2;
        n1=nums1.size();
        n2=nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.insert(nums2.begin(), INT_MIN);
        nums2.push_back(INT_MAX);
        // 设置初始mid值，保证左边与右边相等或多1；
        int mid1 = 0, mid2 = 0;
        int left1 = 1, right1 = n1;
        mid1 = (left1 + right1) / 2;
        if ((n1 + n2) % 2 == 0) {
            mid2 = (n1 + n2) / 2 - mid1;
        } else {
            mid2 = (n1 + n2 + 1) / 2 - mid1;
        }
        cout << fixed << setprecision(5);
        double num;
        while (1) {
            // 二分法移动边界；
            if (nums1[mid1] > nums2[mid2 + 1]) {
                right1 = mid1 - 1;
                int temp = (left1 + right1) / 2;
                mid2 += (mid1 - temp);
                mid1 = temp;
            } else if (nums2[mid2] > nums1[mid1 + 1]) {
                left1 = mid1 + 1;
                int temp = (left1 + right1) / 2;
                mid2 -= (temp - mid1);
                mid1 = temp;
            } else {
                if ((n1 + n2) % 2 == 0) {
                    int left = 0, right = 0;
                    if (nums1[mid1] > nums2[mid2])
                        left = nums1[mid1];
                    else
                        left = nums2[mid2];
                    if (nums1[mid1 + 1] < nums2[mid2 + 1])
                        right = nums1[mid1 + 1];
                    else
                        right = nums2[mid2 + 1];
                    num = (left + right) / 2.0;
                } else {
                    if (nums1[mid1] > nums2[mid2])
                        num=nums1[mid1]*1.0;
                    else
                        num=nums2[mid2] * 1.0;
                }
                break;
            }
        }
        return num;
    }
};

int main()
{
    vector<int> a,b;
    int m,n;
    cin>>m>>n;
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        b.push_back(x);
    }
    double num;
    Solution sol;
    num=sol.findMedianSortedArrays(a,b);
    cout<<"中位数是："<<num;
    return 0;
}