    #include<iostream>
    #include<vector>

    using namespace std;
    
int getkmin(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size(), len2 = nums2.size();
    int index1 = 0, index2 = 0;
    while(true) {
        if(index1 == len1) return nums2[index2+k-1];
        if(index2 == len2) return nums1[index1+k-1];
        if(k == 1) return min(nums1[index1], nums2[index2]);

        int newindex1 = min(index1 + k/2-1, len1-1);
        int newindex2 = min(index2 + k/2-1, len2-1);
        int num1 = nums1[newindex1], num2 = nums2[newindex2];
        if(num1 <= num2) {
            k -= newindex1-index1+1;
            index1 = newindex1+1;
        } else {
            k -= newindex2-index2+1;
            index2 = newindex2+1;
        }
    }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    if((len1+len2)%2 == 1) {
        return getkmin(nums1, nums2, (len1+len2+1)/2);
    }
    return (getkmin(nums1, nums2, (len1+len2)/2)+getkmin(nums1, nums2, (len1+len2)/2+1))/2.0;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9,10,11,12,13,14,15,16,17};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}