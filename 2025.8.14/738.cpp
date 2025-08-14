#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool ismin(vector<int> nums, int index, int left, int right) {
    int num = nums[index];
    for(int i = left; i <= right; i++) {
        if(i == index) continue;
        if(nums[i] < num) return false; 
    }
    return true;
}
// 高位到低位 递增
int monotoneIncreasingDigits(int n) {
    vector<int> nums;
    while(n > 0) {
        nums.push_back(n%10);
        n /= 10;
    }
    // 高位到地位
    reverse(nums.begin(), nums.end());
    vector<int> result;
    for(int i = 0; i < nums.size(); ++i) {
        if(ismin(nums, i, i, nums.size()-1)) result.push_back(nums[i]);
        else {
            result.push_back(nums[i]-1);
            break;
        }
    }
    if(result.size() != nums.size()) {
        while(result.size() != nums.size()) result.push_back(9);
    }
    int ans = 0;
    for(int i = 0; i < result.size(); ++i) {
        if(result[i] != 0) ans = ans*10 + result[i];
    }
    return ans;
}

int main() {
    int n = 120;
    cout << monotoneIncreasingDigits(n) << endl; // Output: 99
    return 0;
}