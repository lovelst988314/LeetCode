#include<iostream>
#include<vector>

using namespace std;

//动态规划
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
    }
    int result = INT_MIN;
    for(int i = 0; i < dp.size(); ++i) {
        result = max(result, dp[i]);
    }
    return result;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;  // Output: 6
    return 0;
}