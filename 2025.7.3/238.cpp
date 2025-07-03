#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left(nums.size(),1);
    vector<int> right(nums.size(),1);
    vector<int> result(nums.size());
    for(int i = 1 ; i < nums.size(); i++) {
        left[i] = left[i-1]*nums[i-1];
        right[nums.size()-1-i] = right[nums.size()-i]*nums[nums.size()-i];
    }
    for(int i = 0; i < nums.size(); i++) {
        result[i] = left[i]*right[i];
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}