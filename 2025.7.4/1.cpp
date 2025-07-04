#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++) {
        auto it = mp.find(target-nums[i]);
        if(it != mp.end() && it->second != i) return {i,it->second};  //不能和自己相加
    }
    return {};
}

int main () {
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> ans = twoSum(nums,target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}