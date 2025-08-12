#include<iostream>
#include<vector>

using namespace std;
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left <= right) {
        int mid = (right-left)/2+left;
        if(nums[mid] >= nums[left]) {  //左边有序
            if(nums[mid] == target) return mid;
            if(target > nums[mid] || target < nums[left]) left = mid+1;
            else right = mid-1;
        } else {  // 右边有序
            if(nums[mid] == target) return mid;
            if(target < nums[mid] || target > nums[right]) right = mid-1;
            else left = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;  // Output: 4
    return 0;
}