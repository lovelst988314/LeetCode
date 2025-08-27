#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> dp;
    int result = 0;
    for(int i = 0; i < arr.size(); ++i) {
        dp[arr[i]] = max(dp[arr[i]], dp[arr[i]-difference]+1);
        result = max(result, dp[arr[i]]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int difference = 2;
    cout << longestSubsequence(arr, difference) << endl; // 输出最长子序列长度
    return 0;
}

// 没解决