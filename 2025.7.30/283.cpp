#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] != 0) {
                    swap(nums[i],nums[j]);
                    break;
                }
            } 
        }
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    return 0;
}