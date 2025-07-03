#include<iostream>
#include<vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] <= 0) nums[i] = nums.size()+2;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(abs(nums[i]) <= nums.size()) nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
    }
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) return i+1;
    }
    return nums.size()+1;
}

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << firstMissingPositive(nums);
}