#include<iostream>
#include<vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(auto num : nums) {
        sum += num;
    }
    if(sum%2 == 1) return false;
    vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1,0));
    for(int i = 0; i <= sum/2; i++) {
        if(i >= nums[0]) dp[0][i] = nums[0];
    }

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 1; j <= sum/2; j++) {
            if(j < nums[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]]+nums[i]);
        }
    }

    return dp[nums.size()-1][sum/2] == sum/2 ? true : false;
}

int main () {
    vector<int> nums = {1,5,11,5};
    cout << static_cast<bool>(canPartition(nums)) << endl;
    return 0;
}