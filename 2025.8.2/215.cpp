#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int onetime(vector<int> &nums, int l, int r) {
//     int temp = l;
//     int num = nums[l];
//     while(l+1 <= r) {
//         while(l+1 <= r && nums[l+1] <= num) l++;
//         while(l+1 <= r && nums[r] > num) r--;

//         if(l+1 <= r) {
//             swap(nums[l+1], nums[r]);
//         }
//     }  
//     swap(nums[l], nums[temp]);
//     return l;
// }

// int findKthLargest(vector<int> &nums, int k) {
//     int l = 0, r = nums.size()-1;
//     int mid = onetime(nums,l,r);
//     while(mid != nums.size()-k) {
//         if(mid > nums.size()-k) {
//             r = mid-1;
//             mid = onetime(nums,l,mid-1);
//         } else {
//             l = mid+1;
//             mid = onetime(nums,mid+1,r);
//         }
//     }
//     return nums[mid];
// }
int quickselect(vector<int> &nums, int l, int r, int k) {
        int i = l+1;
        int j = r;
        int num = nums[l];
        while(i <= j) {
            while(i <= j && nums[i] <= num) ++i;
            while(i <= j && nums[j] > num) --j;
            if(i <= j) swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i-1]);
        if(i-1 >  k) return quickselect(nums,l,i-2,k);
        else if(i-1 < k) return quickselect(nums,i,r,k);
        else return nums[i-1];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,0,nums.size()-1,nums.size()-k);
    }

int main() {
    vector<int> result{99,99};
    cout << findKthLargest(result, 1) << endl;
    return 0;
}