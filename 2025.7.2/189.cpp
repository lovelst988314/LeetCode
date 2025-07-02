#include<iostream>
#include<vector>

using namespace std;
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    vector<int> temp(k,0);
    for(int i = 0; i < k; i++) {
        temp[i] = nums[nums.size()-k+i];
    }
    for(int i = 0; i < nums.size()-k; i++) {
        nums[nums.size()-1-i] = nums[nums.size()-k-1-i];
    }
    for(int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}