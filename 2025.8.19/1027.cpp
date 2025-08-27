#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    unordered_map<int, int> dp;
    int result = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = 0; j < nums[i]; ++j) {
            dp[nums[i]] = max(dp[nums[i]], dp[nums[i]-j]+1);
        }
        result = max(dp[nums[i]], result);

    }
    return result;
}

int main() {
    vector<int> nums = {83,20,17,43,52,78,68,45};
    cout << longestArithSeqLength(nums) << endl; // 输出最长等差数列长度
    return 0;
}

// 没解决