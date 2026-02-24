class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())swap(nums1,nums2);
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
